# agent.py
import json
from typing import Tuple
from actions import ls as a_ls, read as a_read, write as a_write, mkdir as a_mkdir

ALLOWED_TOOLS = {"ls", "read", "write", "mkdir", "none"}

def execute_action(proposal: dict) -> Tuple[str, str]:
    """
    Executes the model's single action proposal.
    Returns (say_text, tool_result_text).
    - say_text: what to print to user
    - tool_result_text: result of tool execution (empty if none)
    """
    # minimal schema checks
    if not isinstance(proposal, dict):
        return ("I couldn't parse that.", "")
    say = proposal.get("say", "")
    action = proposal.get("action", {})
    if not isinstance(action, dict):
        return (say or "No action.", "")
    name = action.get("name", "none")
    if name not in ALLOWED_TOOLS:
        return (f"Tool '{name}' not allowed.", "")

    args = action.get("args", {}) or {}
    # Execute
    if name == "none":
        return (say or "Okay.", "")
    if name == "ls":
        return (say or "Listing…", a_ls(args.get("path", "")))
    if name == "read":
        path = args.get("path")
        if not path:
            return ("Use: read <path>", "")
        return (say or f"Reading {path}…", a_read(path))
    if name == "write":
        path = args.get("path")
        text = args.get("text", "")
        if not path:
            return ("Use: write <path> <text>", "")
        return (say or f"Writing {path}…", a_write(path, text))
    if name == "mkdir":
        path = args.get("path")
        if not path:
            return ("Use: mkdir <path>", "")
        return (say or f"Creating folder {path}…", a_mkdir(path))

    return ("Unhandled tool.", "")
