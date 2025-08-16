# actions.py
from __future__ import annotations

import os
from pathlib import Path
from typing import Optional, Tuple
from datetime import datetime

# --- sandbox root (defaults to ./scratchpad inside the repo) ---
ROOT_DIR = Path(__file__).resolve().parent
SANDBOX_DIR = Path(os.environ.get("ECHO_SANDBOX_DIR", ROOT_DIR / "scratchpad")).resolve()
SANDBOX_DIR.mkdir(parents=True, exist_ok=True)

# Keep both names unified so nothing points outside
SANDBOX_ROOT = SANDBOX_DIR

MAX_READ_BYTES = 2_000_000  # 2 MB safety cap


# -------------------------
# recent file scanner
# -------------------------
def scan_recent(path: str = ".", limit: int = 10) -> str:
    """List recent files (by mtime) under sandbox, read-only."""
    root = (SANDBOX_ROOT / path).resolve()
    if not root.exists():
        return f"[scan_recent] not found: {root}"
    files = []
    for p in root.rglob("*"):
        if p.is_file():
            try:
                files.append((p, p.stat().st_mtime))
            except Exception:
                pass
    files.sort(key=lambda t: t[1], reverse=True)
    lines = []
    for p, mt in files[:limit]:
        ts = datetime.fromtimestamp(mt).strftime("%Y-%m-%d %H:%M:%S")
        lines.append(f"{ts}  {p.relative_to(SANDBOX_ROOT).as_posix()}")
    return "\n".join(lines) or "[scan_recent] no files"


# -------------------------
# sandbox path resolver
# -------------------------
def _resolve(path: str | os.PathLike) -> Path:
    """
    Map any user path into the sandbox.
    - Relative paths → <SANDBOX_DIR>/<path>
    - Absolute paths outside the sandbox → remap to <SANDBOX_DIR>/<basename>
    - Absolute paths already under sandbox → allowed
    """
    p = Path(path)
    if not p.is_absolute():
        return (SANDBOX_DIR / p).resolve()

    try:
        p_res = p.resolve()
    except Exception:
        # On weird paths, fall back to a safe filename inside the sandbox
        return (SANDBOX_DIR / p.name).resolve()

    # If already under SANDBOX_DIR, allow as-is
    try:
        p_res.relative_to(SANDBOX_DIR)
        return p_res
    except ValueError:
        # Outside sandbox → remap to sandbox by basename
        return (SANDBOX_DIR / p_res.name).resolve()


# -------------------------
# list directory
# -------------------------
def ls(path: str = ".") -> str:
    p = _resolve(path)
    if not p.exists():
        return f"[ERROR] Path not found: {p}"
    if p.is_file():
        return f"[FILE] {p.name}"
    rows = []
    for item in sorted(p.iterdir(), key=lambda x: (not x.is_dir(), x.name.lower())):
        kind = "DIR " if item.is_dir() else "FILE"
        rows.append(f"[{kind}] {item.name}")
    return "\n".join(rows)


# -------------------------
# read file
# -------------------------
def read(path: str, max_bytes: int = MAX_READ_BYTES) -> Tuple[str, Optional[str]]:
    """
    Returns (text, summary). Truncates large files to max_bytes.
    """
    p = _resolve(path)
    if not p.exists() or not p.is_file():
        return f"[ERROR] File not found: {p}", None

    data = p.read_bytes()
    truncated = False
    if len(data) > max_bytes:
        data = data[:max_bytes]
        truncated = True

    try:
        text = data.decode("utf-8", errors="replace")
    except Exception:
        return "[ERROR] Could not decode as UTF-8.", None

    # lightweight preview
    lines = [ln.strip() for ln in text.splitlines() if ln.strip()]
    head = "\n".join(lines[:12])
    tail = "\n".join(lines[-3:]) if len(lines) > 15 else ""
    summary = "[Summary] " + (f"{len(text):,} chars" if not truncated else f"{len(text):,} chars (TRUNCATED)")
    if head:
        summary += "\n— Begin —\n" + head
    if tail:
        summary += "\n— … —\n" + tail + "\n— End —"
    if truncated:
        summary += "\n[NOTE] Truncated for safety."
    return text, summary


# -------------------------
# write file
# -------------------------
def write(path: str, text: str, overwrite: bool = False, if_exists: str = "append") -> str:
    """
    Safer writes within the sandbox:
      - overwrite=False (default) prevents clobbering.
      - if_exists: 'append' (default), 'skip', 'overwrite', 'error'
    """
    p = _resolve(path)
    p.parent.mkdir(parents=True, exist_ok=True)

    if p.exists():
        choice = ("overwrite" if overwrite else if_exists).lower()
        if choice == "skip":
            return f"[SKIP] {p.name} already exists."
        if choice == "error":
            return f"[ERROR] {p.name} already exists."
        if choice == "overwrite":
            p.write_text(text, encoding="utf-8")
            return f"[OK] Overwrote {p.name}"
        # append by default
        with p.open("a", encoding="utf-8") as f:
            if text and not text.endswith("\n"):
                text = text + "\n"
            f.write(text)
        return f"[OK] Appended to {p.name}"
    else:
        p.write_text(text, encoding="utf-8")
        return f"[OK] Wrote {len(text)} chars to {p.name}"


# -------------------------
# mkdir
# -------------------------
def mkdir(path: str, exist_ok: bool = True) -> str:
    p = _resolve(path)
    p.mkdir(parents=True, exist_ok=exist_ok)
    return f"[OK] Created directory {p}"
