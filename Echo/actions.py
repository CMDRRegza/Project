from pathlib import Path
from typing import Tuple
from config import ALLOWED_ROOT

class SandboxError(Exception):
    pass

def _resolve(path_str: str) -> Path:
    """
    Resolve a user-supplied path inside the sandbox.
    Blocks traversal and absolute escapes.
    """
    if not path_str:
        p = ALLOWED_ROOT
    else:
        # Treat input as relative to sandbox
        p = (ALLOWED_ROOT / path_str).resolve()
    # Enforce containment
    if ALLOWED_ROOT not in p.parents and p != ALLOWED_ROOT:
        raise SandboxError("Path escapes sandbox.")
    return p

def ls(path_str: str = "") -> str:
    p = _resolve(path_str)
    if not p.exists():
        return "Not found."
    if p.is_file():
        return f"[FILE] {p.relative_to(ALLOWED_ROOT)}"
    items = sorted(p.iterdir(), key=lambda x: (x.is_file(), x.name.lower()))
    if not items:
        return "(empty)"
    lines = []
    for it in items:
        kind = "DIR " if it.is_dir() else "FILE"
        lines.append(f"[{kind}] {it.relative_to(ALLOWED_ROOT)}")
    return "\n".join(lines)

def read(path_str: str) -> str:
    p = _resolve(path_str)
    if not p.exists() or not p.is_file():
        return "Not a file."
    try:
        return p.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        return "(binary or non-utf8 file)"

def write(path_str: str, content: str) -> str:
    p = _resolve(path_str)
    if p.exists() and p.is_dir():
        return "Cannot write to a directory."
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(content, encoding="utf-8")
    return f"Wrote {len(content)} chars to {p.relative_to(ALLOWED_ROOT)}"

def mkdir(path_str: str) -> str:
    p = _resolve(path_str)
    if p.exists():
        return "Already exists."
    p.mkdir(parents=True, exist_ok=True)
    return f"Created folder {p.relative_to(ALLOWED_ROOT)}"
