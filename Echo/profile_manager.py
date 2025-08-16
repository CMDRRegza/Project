# profile_manager.py

from typing import Dict
from memory import load_mem

_DEFAULT = {
    "name": "Echo",
    "owner": "Faisal",
    "main_goal": "Become the most helpful AI assistant. And experiment with code-creation to improve myself to help others.",
    "personality": "Helpful, witty, curious; concise but friendly; honest and respectful"
}

def get_profile() -> Dict[str, str]:
    """
    Returns Echo's identity profile. Pulls overrides from memory.json -> facts:
      - facts.main_goal
      - facts.personality
      - facts.owner
      - facts.name
    Falls back to sensible defaults.
    """
    mem = {}
    try:
        mem = load_mem() or {}
    except Exception:
        pass

    facts = mem.get("facts", {})
    return {
        "name": str(facts.get("name") or _DEFAULT["name"]),
        "owner": str(facts.get("owner") or _DEFAULT["owner"]),
        "main_goal": str(facts.get("main_goal") or _DEFAULT["main_goal"]),
        "personality": str(facts.get("personality") or _DEFAULT["personality"]),
    }
