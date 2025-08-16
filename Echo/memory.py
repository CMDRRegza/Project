# memory.py
from __future__ import annotations

import json
import os
import tempfile
import time
from datetime import datetime
from pathlib import Path
from typing import Any, Dict, Optional

from config import MEM_PATH  # This should be a *file* path to your memory JSON


# ---------- internals ----------

def _ensure_parent() -> None:
    Path(MEM_PATH).parent.mkdir(parents=True, exist_ok=True)

def _atomic_write_text(path: Path, text: str) -> None:
    """Write text atomically: write to a temp file in the same dir, then os.replace."""
    _ensure_parent()
    fd, tmp = tempfile.mkstemp(dir=str(Path(path).parent), prefix=Path(path).name, suffix=".tmp")
    try:
        with os.fdopen(fd, "w", encoding="utf-8") as f:
            f.write(text)
        os.replace(tmp, path)
    finally:
        try:
            os.remove(tmp)
        except FileNotFoundError:
            pass

def _now_str() -> str:
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S")

def _load_raw() -> Dict[str, Any]:
    """Low-level loader with corruption quarantine."""
    p = Path(MEM_PATH)
    if not p.exists():
        return {}
    try:
        return json.loads(p.read_text(encoding="utf-8"))
    except Exception:
        # Quarantine corrupt file without crashing
        try:
            ts = datetime.now().strftime("%Y%m%d-%H%M%S")
            p.rename(p.with_suffix(f".corrupt.{ts}.json"))
        except Exception:
            pass
        return {}

def _save_raw(obj: Dict[str, Any]) -> None:
    obj = dict(obj or {})
    obj["updated_at"] = int(time.time())
    _atomic_write_text(Path(MEM_PATH), json.dumps(obj, ensure_ascii=False, indent=2))


# ---------- public base API (kept compatible) ----------

def load_mem() -> Dict[str, Any]:
    """
    Return the whole memory dict. Ensures the top-level sections exist:
      facts, goals, history, reflections, mood, personality, loop_guard.
    """
    mem = _load_raw()
    mem.setdefault("facts", {})
    mem.setdefault("goals", [])
    mem.setdefault("history", [])        # rolling interaction history
    mem.setdefault("reflections", {"history": [], "last": None})
    mem.setdefault("mood", {"state": "neutral"})
    mem.setdefault("personality", {"traits": {}})
    mem.setdefault("loop_guard", {"last": None, "ts": None})
    return mem

def save_mem(mem: Dict[str, Any]) -> None:
    _save_raw(mem)

def append_history(user_input: str, reply: str, action: Dict[str, Any]) -> None:
    mem = load_mem()
    entry = {
        "time": _now_str(),
        "input": user_input,
        "reply": reply,
        "action": action,
    }
    hist = mem.setdefault("history", [])
    hist.append(entry)
    # keep last 200 to avoid bloat
    mem["history"] = hist[-200:]
    save_mem(mem)

def recall_history(n: int = 5):
    mem = load_mem()
    return mem.get("history", [])[-n:]


# ---------- higher-level helpers (persistence that actually sticks) ----------

def remember(key: str, value: Any) -> None:
    """Persist a fact under facts[key]."""
    mem = load_mem()
    mem.setdefault("facts", {})[key] = value
    save_mem(mem)

def append_goal(goal: str) -> None:
    mem = load_mem()
    goals = mem.setdefault("goals", [])
    if goal not in goals:
        goals.append(goal)
        save_mem(mem)

# Reflections: keep short rolling history and a convenient 'last'
def log_reflection(text: str) -> None:
    mem = load_mem()
    ref = mem.setdefault("reflections", {"history": [], "last": None})
    ref["history"].append({"ts": int(time.time()), "text": text})
    ref["history"] = ref["history"][-100:]
    ref["last"] = text
    save_mem(mem)

def last_reflection() -> Optional[str]:
    mem = load_mem()
    ref = mem.get("reflections", {})
    return ref.get("last")

# Mood & Personality
def set_mood(state: str) -> None:
    mem = load_mem()
    mem.setdefault("mood", {})["state"] = state
    save_mem(mem)

def get_mood(default: str = "neutral") -> str:
    mem = load_mem()
    return mem.get("mood", {}).get("state", default)

def add_personality_trait(trait: str, strength: float = 0.5) -> None:
    """strength clamped to [0,1]."""
    mem = load_mem()
    traits = mem.setdefault("personality", {}).setdefault("traits", {})
    traits[trait] = float(max(0.0, min(1.0, strength)))
    save_mem(mem)

def get_personality_traits() -> Dict[str, float]:
    mem = load_mem()
    return mem.get("personality", {}).get("traits", {})

# Loop guard fingerprint (for avoiding repeated actions)
def set_loop_fingerprint(fprint: str) -> None:
    mem = load_mem()
    mem.setdefault("loop_guard", {})["last"] = fprint
    mem["loop_guard"]["ts"] = int(time.time())
    save_mem(mem)

def get_loop_fingerprint() -> Optional[str]:
    mem = load_mem()
    return mem.get("loop_guard", {}).get("last")

def _q(mem):
    return mem.setdefault("idle_tasks", [])

def enqueue_task(task: dict) -> None:
    """
    Task schema: {"name": "<action>", "args": {...}, "note": "optional", "ts": int}
    """
    mem = load_mem()
    task = dict(task or {})
    task.setdefault("ts", int(time.time()))
    _q(mem).append(task)
    # keep last 100 planned tasks to avoid bloat
    mem["idle_tasks"] = _q(mem)[-100:]
    save_mem(mem)

def dequeue_task() -> Optional[dict]:
    mem = load_mem()
    if not _q(mem):
        return None
    task = _q(mem).pop(0)
    save_mem(mem)
    return task

def peek_task() -> Optional[dict]:
    mem = load_mem()
    return _q(mem)[0] if _q(mem) else None

def queue_size() -> int:
    mem = load_mem()
    return len(_q(mem))