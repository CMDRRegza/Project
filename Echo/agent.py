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

def execute_action(proposal_json_or_obj, user_text: str = "") -> Tuple[str, str | None]:
    """
    Strictly validate & coerce to the tool_spec.
    Returns (chat_text, tool_result_or_None).
    """
    clean = _validate_and_coerce(_strict_parse(proposal_json_or_obj), user_text=user_text)

    chat = clean["chat"]
    name = clean["action"]["name"]
    args = clean["action"]["args"]

    if name == "none":
        return chat, None

    if name in ("write", "mkdir") and not ALLOW_WRITES:
        return chat, "[blocked] tool writes are disabled"

    try:
        if name == "ls":
            return chat, (a_ls(args["path"]) or "(empty)")
        if name == "read":
            return chat, (a_read(args["path"]) or "(empty)")
        if name == "write":
            out = a_write(args["path"], args["text"])
            return chat, out or f"Wrote {len(args['text'])} chars to {args['path']}"
        if name == "mkdir":
            out = a_mkdir(args["path"])
            return chat, out or f"Created folder {args['path']}"
        return chat, None
    except Exception as e:
        return chat, f"[tool-error] {e}"
