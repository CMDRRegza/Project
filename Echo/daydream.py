# daydream.py
from __future__ import annotations

import json
import time
import threading
from datetime import datetime
from typing import Any, Deque, Dict, Optional
from collections import deque
from pathlib import Path

# ───────────────────────── Config & fallbacks ─────────────────────────

AUTO_IDLE_AFTER_SEC = 40  # start idle automatically after this much inactivity


try:
    from config import THINK_INTERVAL_SEC  # runner cadence (seconds)
except Exception:
    THINK_INTERVAL_SEC = 30

try:
    from logger import log_thought as _real_log_thought
except Exception:
    def _real_log_thought(msg: str) -> None:
        print(msg)

def _log(msg: str) -> None:
    """Wrapper that respects quiet mode (still logs, but you can tweak here if needed)."""
    if _QUIET and not msg.startswith("[daydream]"):
        # keep core lifecycle messages, quiet the rest
        pass
    _real_log_thought(msg)

try:
    from memory import (
        log_reflection, last_reflection,
        set_loop_fingerprint, get_loop_fingerprint,
        get_mood, append_history,
        enqueue_task, dequeue_task, peek_task, queue_size
    )
except Exception:
    # Minimal fallbacks so the module still imports if memory helpers are missing
    def log_reflection(_t: str) -> None: ...
    def last_reflection() -> Optional[str]: return None
    def set_loop_fingerprint(_s: str) -> None: ...
    def get_loop_fingerprint() -> Optional[str]: return None
    def get_mood(_d: str = "neutral") -> str: return "neutral"
    def append_history(_i, _r, _a) -> None: ...
    def enqueue_task(_t: dict) -> None: ...
    def dequeue_task() -> Optional[dict]: return None
    def peek_task() -> Optional[dict]: return None
    def queue_size() -> int: return 0

from actions import ls as a_ls, read as a_read, write as a_write
from actions import scan_recent as a_scan_recent   # <— add

IDLE_DIR = Path("./scratchpad/autonotes")

# ───────────────────────── Module state ─────────────────────────

_ALLOW_ACTIONS = False          # dream (False) vs idle (True)
_ALLOW_WRITES = False
_THREAD: Optional[threading.Thread] = None
_STOP = threading.Event()

# Auto-idle watcher
_WATCHER: Optional[threading.Thread] = None
_STOP_WATCHER = threading.Event()
_LAST_ACTIVITY_TS = time.time()

# UI quiet mode + kill switch
_QUIET = False
_KILLED = False

# Hints & loop guard window
_HINT_LOCK = threading.Lock()
_HINT: Optional[str] = None

# ───────────────────────── Loop guard ─────────────────────────

class LoopGuard:
    def __init__(self, maxlen: int = 10, max_repeat: int = 2) -> None:
        self.window: Deque[str] = deque(maxlen=maxlen)
        self.max_repeat = max_repeat

    def signature(self, plan: Dict[str, Any]) -> str:
        action = (plan.get("action") or {})
        name = action.get("name") or "none"
        args = json.dumps(action.get("args") or {}, sort_keys=True)
        chat = (plan.get("chat") or "")[:64]
        thought = (plan.get("thought") or "")[:64]
        return f"{name}|{args}|{chat}|{thought}"

    def push_and_repeating(self, sig: str) -> bool:
        self.window.append(sig)
        count = sum(1 for s in self.window if s == sig)
        return count > self.max_repeat

# ───────────────────────── Planner ─────────────────────────

SAFE_DEFAULT_TASKS = [
    {"name": "scan_recent", "args": {"path": ".", "limit": 12}, "note": "recent files"},
    {"name": "ls",          "args": {"path": "sandbox"}, "note": "list sandbox"},
    {"name": "read",        "args": {"path": "sandbox/INDEX.md"}, "note": "read index"},
]


def _seed_tasks_if_empty() -> None:
    if queue_size() == 0:
        for t in SAFE_DEFAULT_TASKS:
            enqueue_task(t)

def _build_plan(user_hint: Optional[str] = None) -> Dict[str, Any]:
    """
    Decide what to do next.
    Priority:
      1) Execute a queued task if present
      2) Otherwise take a tiny safe step
    """
    mood = get_mood("neutral")
    prev = (last_reflection() or "").strip()

    _seed_tasks_if_empty()
    next_task = peek_task()

    if next_task:
        thought = f"[mood={mood}] execute queued task: {next_task['name']}"
        chat = f"Working my idle queue: {next_task.get('note','task')}."
        action = {"name": next_task["name"], "args": next_task.get("args", {})}
    elif prev and len(prev) > 10:
        thought = f"[mood={mood}] follow up on last reflection with a small action"
        chat = "Acting on my last reflection with a tiny step."
        action = {"name": "ls", "args": {"path": "."}}
    else:
        thought = f"[mood={mood}] brief reflection before deciding next move"
        chat = "Taking a short reflective breath…"
        action = {"name": "none", "args": {}}

    if user_hint and "read" in user_hint.lower():
        action = {"name": "ls", "args": {"path": "."}}

    return {"thought": thought, "chat": chat, "action": action}

def _ensure_idle_dir() -> None:
    IDLE_DIR.mkdir(parents=True, exist_ok=True)

def _write_idle_note(mood: str, reflection: Optional[str], loop_break: bool, planned: str) -> Path:
    _ensure_idle_dir()
    now = datetime.now()
    day = IDLE_DIR / now.strftime("%Y-%m-%d")
    day.mkdir(parents=True, exist_ok=True)
    fname = f"auto_note_{now.strftime('%H%M%S')}.md"
    path = day / fname

    body = [
        f"# Auto Note • {now.strftime('%Y-%m-%d %H:%M:%S')}",
        f"- mood: **{mood}**",
        f"- loop_break: {'yes' if loop_break else 'no'}",
        f"- planned_action: `{planned}`",
        "",
    ]
    if reflection:
        body += ["## Reflection", reflection.strip(), ""]
    body += ["## Next tiny steps", "- [ ] read a small file and summarize", "- [ ] keep index updated", ""]
    text = "\n".join(body)

    res = a_write(str(path), text, if_exists="error")
    idx = Path("./scratchpad/INDEX.md")
    line = f"- {now.strftime('%Y-%m-%d %H:%M:%S')} → `{path.as_posix()}` (mood: {mood})\n"
    if idx.exists():
        a_write(str(idx), line, if_exists="append")
    else:
        a_write(str(idx), "# Echo Sandbox Index\n\n" + line, if_exists="error")
    _log(f"[auto] idle write → {res}")
    return path

# ───────────────────────── One auto-think tick ─────────────────────────

def tick_auto(user_hint: Optional[str] = None) -> Dict[str, Any]:
    """
    One self-prompt 'tick':
      1) Build a plan (queue-aware)
      2) Loop-guard it (switch to idle note on repeats)
      3) Persist reflection
      4) If allowed, execute one tiny safe action (ls/read/write)
      5) Return the plan (for UI)
    """
    guard = LoopGuard()
    plan = _build_plan(user_hint=user_hint)

    # loop guard (persisted across ticks)
    sig = guard.signature(plan)
    last = get_loop_fingerprint()
    repeating = (last == sig) or guard.push_and_repeating(sig)
    if repeating and (plan.get("action", {}).get("name") in {"none", "ls"}):
        plan["thought"] += " | Detected repetition; switching action to break the loop."
        plan["chat"] = "Breaking the loop with a tiny safe write."
        plan["action"] = {"name": "write", "args": {}}

    # persist loop fingerprint + reflection
    set_loop_fingerprint(guard.signature(plan))
    log_reflection(plan.get("thought", ""))

    # Execute the action (only if allowed & not killed)
    if _KILLED:
        _log("[auto] killed; suppressing actions & plans")
        return plan

    name = (plan.get("action") or {}).get("name") or "none"
    args = (plan.get("action") or {}).get("args") or {}
    mood = get_mood("neutral")

    try:
        if not _ALLOW_ACTIONS:
            _log("[auto] actions disabled; plan only.")
            return plan

        # If we planned a queued task and actions are enabled, pop it now
        if name in {"ls", "read", "write"} and peek_task():
            dequeue_task()
        
        if name == "scan_recent":
            out = a_scan_recent(**args)
            _log(f"[auto] scan_recent →\n{out}")
        elif name == "ls":
            out = a_ls(**args)
            _log(f"[auto] ls →\n{out}")
        elif name == "read":
            _text, summary = a_read(**args)
            _log(f"[auto] read → summary:\n{summary or '[no summary]'}")
        elif name == "write":
            if not _ALLOW_WRITES:
                _log("[auto] write skipped (read-only mode)")
                # optionally push a read task instead:
                enqueue_task({"name": "read", "args": {"path": "sandbox/INDEX.md"}, "note": "read index"})
            else:
                path = _write_idle_note(...)    
        elif name == "none":
            _log("[auto] no-op (reflect)")
        else:
            _log(f"[auto] unhandled action '{name}'")
    except TypeError as e:
        _log(f"[auto] action type error: {e!r}")

    return plan

# ───────────────────────── Background loops ─────────────────────────

def set_daydream_hint(text: Optional[str]) -> None:
    """Optional hint that biases upcoming plans (e.g., 'read scratchpad')."""
    global _HINT
    with _HINT_LOCK:
        _HINT = text

def _get_hint() -> Optional[str]:
    with _HINT_LOCK:
        return _HINT

def _loop(interval_sec: int) -> None:
    _log(f"[daydream] starting loop @ {interval_sec}s (allow_actions={_ALLOW_ACTIONS})")
    try:
        while not _STOP.is_set():
            hint = _get_hint()
            plan = tick_auto(user_hint=hint)
            _log(f"[daydream] plan → {plan.get('chat','(no chat)')}")
            # sleep responsive
            waited = 0
            while waited < interval_sec and not _STOP.is_set():
                time.sleep(0.25)
                waited += 0.25
    finally:
        _log("[daydream] loop stopped")

def _start_daydream_internal(interval_sec: Optional[int] = None, hint: Optional[str] = None) -> bool:
    global _THREAD
    if is_daydreaming() or _KILLED:
        return False
    _STOP.clear()
    if hint:
        set_daydream_hint(hint)
    interval = int(interval_sec or THINK_INTERVAL_SEC)
    _THREAD = threading.Thread(target=_loop, args=(interval,), name="EchoDaydream", daemon=True)
    _THREAD.start()
    return True

def stop_daydream() -> bool:
    global _THREAD
    if not is_daydreaming():
        return False
    _STOP.set()
    if _THREAD and _THREAD.is_alive():
        _THREAD.join(timeout=3.0)
    _THREAD = None
    return True

def is_daydreaming() -> bool:
    return _THREAD is not None and _THREAD.is_alive()

# ───────────────────────── Public modes (dream/idle) ─────────────────────────
# Back-compat wrapper: accepts (llm, interval_seconds, allow_actions)

def start_daydream(*args, **kwargs) -> bool:
    """
    Compatible with:
      start_daydream(llm, interval_seconds=45, allow_actions=False)
      start_daydream(interval_sec=45, hint="…")
    Positional arg 0 (llm) is accepted and ignored here.
    """
    global _ALLOW_ACTIONS
    interval = kwargs.pop("interval_seconds", None)
    if interval is None:
        interval = kwargs.pop("interval_sec", None)
    _ALLOW_ACTIONS = bool(kwargs.pop("allow_actions", False))
    hint = kwargs.pop("hint", None)
    return _start_daydream_internal(interval_sec=interval, hint=hint)

def start_idle(*args, **kwargs) -> bool:
    """
    Start 'idle' mode = planning + safe actions.
    Accepts:
      start_idle(interval_seconds=45, hint="…")
      start_idle(interval_sec=45)
      start_idle(llm, interval_seconds=45)   # positional llm ignored
    """
    global _ALLOW_ACTIONS
    interval = kwargs.pop("interval_seconds", None)
    if interval is None:
        interval = kwargs.pop("interval_sec", None)
    kwargs.pop("allow_actions", None)  # force True for idle mode
    hint = kwargs.pop("hint", None)
    _ALLOW_ACTIONS = True
    return _start_daydream_internal(interval_sec=interval, hint=hint)

def stop_idle() -> bool:
    return stop_daydream()

def is_idling() -> bool:
    return is_daydreaming() and _ALLOW_ACTIONS

# ───────────────────────── Auto-idle watcher ─────────────────────────

def start_review(*args, **kwargs) -> bool:
    """Idle read-only mode: ls/read allowed, writes blocked."""
    global _ALLOW_ACTIONS, _ALLOW_WRITES
    interval = kwargs.pop("interval_seconds", None) or kwargs.pop("interval_sec", None)
    kwargs.pop("allow_actions", None)
    kwargs.pop("hint", None)
    _ALLOW_ACTIONS = True
    _ALLOW_WRITES = False      # <— key line
    return _start_daydream_internal(interval_sec=interval, hint=None)


def mark_user_activity() -> None:
    """Call this whenever a user message is observed."""
    global _LAST_ACTIVITY_TS
    _LAST_ACTIVITY_TS = time.time()

def _watcher_loop() -> None:
    _log("[daydream] inactivity watcher started")
    try:
        while not _STOP_WATCHER.is_set():
            if _KILLED:
                time.sleep(0.5)
                continue
            idle_for = time.time() - _LAST_ACTIVITY_TS
            if idle_for >= AUTO_IDLE_AFTER_SEC and not is_daydreaming():
                _log(f"[daydream] auto-idle after {int(idle_for)}s of inactivity")
                # auto-idle uses default cadence; feel free to tweak to THINK_INTERVAL_SEC
                start_idle(interval_seconds=THINK_INTERVAL_SEC)
            # small sleep for responsiveness
            time.sleep(0.5)
    finally:
        _log("[daydream] inactivity watcher stopped")

def bootstrap_daydreamer() -> None:
    """Start the inactivity watcher once at app startup."""
    global _WATCHER
    if _WATCHER and _WATCHER.is_alive():
        return
    _STOP_WATCHER.clear()
    _WATCHER = threading.Thread(target=_watcher_loop, name="EchoIdleWatcher", daemon=True)
    _WATCHER.start()

def shutdown_daydreamer() -> None:
    """Stop loops and watcher (called on app shutdown)."""
    stop_daydream()
    _STOP_WATCHER.set()

# ───────────────────────── UI + Kill controls ─────────────────────────

def set_ui_open(is_open: bool) -> None:
    """
    UI closed → quiet mode (keeps working, just less chatty).
    UI open   → normal logs.
    """
    global _QUIET
    _QUIET = (not is_open)
    state = "quiet" if _QUIET else "normal"
    _log(f"[daydream] UI state changed → {state}")

def kill_all() -> None:
    """
    Full stop: no loops, no auto-idle, no future starts until restart.
    """
    global _KILLED
    _KILLED = True
    stop_daydream()
    shutdown_daydreamer()
    _log("[daydream] KILLED — suppressed until next startup")

def is_killed() -> bool:
    return _KILLED

# Aliases some parts of your code might import
start_auto_think = start_daydream
stop_auto_think = stop_daydream
