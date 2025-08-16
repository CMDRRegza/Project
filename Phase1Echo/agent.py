# agent.py
import json, os, re
from typing import Tuple, Dict, Any
from pathlib import Path
from datetime import datetime

from actions import ls as a_ls, read as a_read, write as a_write, mkdir as a_mkdir
from policy import ALLOWED_WRITE_ROOTS, FORBIDDEN_EXTENSIONS, MAX_FILE_BYTES, ALLOW_WRITES

ALLOWED_TOOLS = {"ls", "read", "write", "mkdir", "none"}
SAFE_ROOT = Path(".").resolve()


# ------------ helpers ------------

def _safe_rel_path(s: str) -> str:
    s = (s or "").strip()
    if not s:
        return ""
    p = Path(s)
    if p.is_absolute():
        raise ValueError("absolute paths not allowed")
    parts = [q for q in p.parts if q not in (".", "")]
    if any(q == ".." for q in parts):
        raise ValueError("parent escapes not allowed")
    if parts and parts[-1].startswith("."):
        raise ValueError("dotfiles not allowed")
    return str(Path(*parts).as_posix())

def _inside_safe_root(p: Path) -> bool:
    try:
        rp = p.resolve()
        rp.relative_to(SAFE_ROOT)
        return True
    except Exception:
        return False

def _normalize_rel_path(raw: str) -> Path | None:
    s = (raw or "").strip()
    if not s:
        return None
    if os.path.isabs(s):
        return None
    if ".." in s.replace("\\", "/").split("/"):
        return None
    # forbid dotfiles by default
    if Path(s).name.startswith("."):
        return None
    p = (SAFE_ROOT / s).resolve()
    return p if _inside_safe_root(p) else None

def _looks_like_path(s: str) -> bool:
    s = (s or "").strip()
    return bool(re.search(r"[\\/]", s)) or bool(re.search(r"\.[a-z0-9]{1,6}$", s, re.I))

from datetime import datetime
def _fallback_secret(user_text: str) -> str:
    ts = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    if "secret" in (user_text or "").lower():
        return f"This is a small private note just for you. — {ts}"
    return f"Hello from Echo — a tiny secret thought at {ts}."


def _under_allowed_root(p: Path) -> bool:
    try:
        rel = p.relative_to(SAFE_ROOT)
    except Exception:
        return False
    first = Path(str(rel).split("/")[0])
    return any(first == root for root in ALLOWED_WRITE_ROOTS)

def _forbidden_ext(p: Path) -> bool:
    return p.suffix.lower() in FORBIDDEN_EXTENSIONS

def _strict_parse(obj_or_str: Any) -> Dict[str, Any]:
    if isinstance(obj_or_str, dict):
        return obj_or_str or {}
    raw = str(obj_or_str)

    # direct
    try:
        return json.loads(raw)
    except Exception:
        pass

    # last {...}
    depth = 0; start = -1; last = None
    for i, ch in enumerate(raw):
        if ch == "{":
            if depth == 0: start = i
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0 and start != -1:
                last = raw[start:i+1]
    if last:
        try:
            return json.loads(last)
        except Exception:
            pass

    return {"thought": "fallback_plaintext", "chat": raw.strip(), "action": {"name": "none", "args": {}}}

def _validate_and_coerce(d: Dict[str, Any], user_text: str) -> Dict[str, Any]:
    # top-level required
    thought = str(d.get("thought") or "").strip()
    chat = str((d.get("chat") or d.get("say") or "")).strip()
    action = d.get("action") or {}
    if not isinstance(action, dict):
        action = {}

    name = (action.get("name") or "none")
    if not isinstance(name, str): name = "none"
    name = name.strip().lower()
    if name not in ALLOWED_TOOLS:
        name = "none"

    args = action.get("args") or {}
    if not isinstance(args, dict):
        args = {}

    if len(chat) < 12:
        chat = "Hello! How can I help you today?"

    # tool-specific fixups
    if name in ("ls", "read", "mkdir", "write"):
        raw_path = str(args.get("path") or "").strip()
        # swap if model stuffed path in 'text'
        if not raw_path and _looks_like_path(str(args.get("text", ""))):
            raw_path = str(args.get("text", "")).strip()
            args["text"] = ""

        p = _normalize_rel_path(raw_path) if raw_path else None
        if p is None:
            # default ls to "."; others refuse
            if name == "ls":
                p = SAFE_ROOT
            else:
                return {"thought": thought,
                        "chat": chat + " (Refused unsafe or missing path.)",
                        "action": {"name": "none", "args": {}}}

        # write/mkdir must be inside allowed roots
        if name in ("write", "mkdir"):
            if not _under_allowed_root(p):
                return {"thought": thought,
                        "chat": chat + " (Refused outside allowed folders. Use notes/, tmp/, or scratchpad/.)",
                        "action": {"name": "none", "args": {}}}

        # forbid dangerous exts
        if name == "write" and _forbidden_ext(p):
            return {"thought": thought,
                    "chat": chat + " (Refused dangerous file type.)",
                    "action": {"name": "none", "args": {}}}

        # fill defaults for write
        if name == "write":
            text = args.get("text")
            text = "" if text is None else str(text)
            if not text or text.strip() == str(p.name):
                text = _fallback_secret(user_text)
            if len(text.encode("utf-8")) > MAX_FILE_BYTES:
                text = text.encode("utf-8")[:MAX_FILE_BYTES].decode("utf-8", errors="ignore")
            args = {"path": str(p.relative_to(SAFE_ROOT)), "text": text}
        else:
            args = {"path": str(p.relative_to(SAFE_ROOT))}

    else:
        args = {}

    return {"thought": thought, "chat": chat, "action": {"name": name, "args": args}}


# ------------ public API ------------

def execute_action(proposal_json_or_obj) -> Tuple[str, str | None]:
    # Accept dict or string; if string, require valid JSON
    if isinstance(proposal_json_or_obj, str):
        obj = json.loads(proposal_json_or_obj)  # let exceptions propagate
    else:
        obj = proposal_json_or_obj or {}

    # Read exact fields; do not invent defaults
    chat = (obj.get("chat") or obj.get("say") or "").strip()
    action = obj.get("action")
    if not isinstance(action, dict):
        raise ValueError("action missing or not an object")

    # HARD FAIL if model stuffed JSON into 'chat'
    try:
        _maybe = json.loads(chat)
        if isinstance(_maybe, dict):
            raise ValueError("invalid: JSON found in 'chat' (must be natural language)")
    except json.JSONDecodeError:
        pass  # normal, continue

    name = (action.get("name") or "").strip().lower()
    args = action.get("args")
    if not isinstance(args, dict):
        raise ValueError("args missing or not an object")

    if name not in {"ls","read","write","mkdir","none"}:
        raise ValueError(f"unknown tool: {name}")

    # No-op
    if name == "none":
        return chat, None

    # Validate args per tool, no auto-fixes
    if name == "ls":
        path = _safe_rel_path(args.get("path", ""))
        return chat, a_ls(path)

    if name == "read":
        path = _safe_rel_path(args.get("path", ""))
        if not path:
            raise ValueError("read requires a non-empty path")
        return chat, a_read(path)

    if name == "mkdir":
        path = _safe_rel_path(args.get("path", ""))
        if not path:
            raise ValueError("mkdir requires a non-empty path")
        return chat, a_mkdir(path)

    if name == "write":
        path = _safe_rel_path(args.get("path", ""))
        text = (args.get("text") or "")
        if not path:
            raise ValueError("write requires a non-empty path")
        if not text.strip():
            raise ValueError("write requires non-empty text")
        if text.strip() == path:
            raise ValueError("text must not equal path")
        # Do NOT mkdir here; actions.write handles sandbox dir creation
        return chat, a_write(path, text)
    # Should not reach
    return chat, None