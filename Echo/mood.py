# mood.py

from __future__ import annotations
from typing import Dict

# Simple in-process mood store (persist later if you like)
_state = {
    "state": "neutral",  # neutral / curious / focused / relaxed / bored
    "valence": 0.0,      # [-1.0 .. +1.0]
    "relax": False
}

def get_mood() -> Dict[str, float | str | bool]:
    """Return current mood snapshot."""
    return dict(_state)

def nudge(valence: float) -> None:
    """
    Nudge mood valence up/down and derive coarse state.
    Positive valence -> curious/focused; negative -> bored.
    """
    v = float(_state.get("valence", 0.0)) + float(valence)
    v = max(-1.0, min(1.0, v))
    _state["valence"] = v
    if _state["relax"]:
        _state["state"] = "relaxed"
    else:
        if v > 0.25:
            _state["state"] = "curious"
        elif v < -0.25:
            _state["state"] = "bored"
        else:
            _state["state"] = "neutral"

def relax(on: bool) -> None:
    """Toggle relaxation mode."""
    _state["relax"] = bool(on)
    if on:
        _state["state"] = "relaxed"
