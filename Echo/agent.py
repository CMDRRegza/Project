from pathlib import Path
from actions import ls, read, write, mkdir, SANDBOX_ROOT
from daydream import stop_idle

# Align SAFE_ROOT with sandbox
SAFE_ROOT = SANDBOX_ROOT

def _safe_rel_path(path: str) -> Path:
    if not path:
        raise ValueError("Empty path")
    p = (SAFE_ROOT / path).resolve()
    if not str(p).startswith(str(SAFE_ROOT)):
        raise ValueError("Unsafe path outside sandbox")
    return p

def execute_action(proposal: dict):
    """Execute an action dictionary proposed by the LLM planner."""
    if not proposal or "action" not in proposal:
        return proposal.get("chat", ""), None

    act = proposal["action"]
    name = act.get("name", "")
    args = act.get("args", {})

    try:
        if name == "ls":
            return proposal.get("chat", ""), ls(args.get("path", ""))

        if name == "read":
            return proposal.get("chat", ""), read(args.get("path", ""))

        if name == "write":
            return proposal.get("chat", ""), write(args.get("path", ""), args.get("text", ""))

        if name == "mkdir":
            return proposal.get("chat", ""), mkdir(args.get("path", ""))

        if name == "none":
            return proposal.get("chat", ""), None

        # new kill handler
        if name == "kill":
            stop_idle()
            return "Echo silenced until restart.", None

        return f"[unknown action: {name}]", None

    except Exception as e:
        return f"[action error: {e}]", None
