import json
from typing import Any, Dict, List

import requests
from requests.adapters import HTTPAdapter
from urllib3.util.retry import Retry


class LLM:
    def __init__(self, model: str):
        self.model = model
        self._session = requests.Session()

        retries = Retry(
            total=2,                   # 1 retry after first attempt
            backoff_factor=0.5,        # 0.5s, 1.0s
            status_forcelist=(502, 503, 504),
            allowed_methods=frozenset(["GET", "POST"])
        )
        self._session.mount("http://", HTTPAdapter(max_retries=retries))
        self._session.mount("https://", HTTPAdapter(max_retries=retries))

    def cancel(self) -> None:
        """Best-effort: abort in-flight reads by closing the session."""
        try:
            self._session.close()
        except Exception:
            pass
        self._session = requests.Session()

    def _post_json(self, url: str, payload: Dict[str, Any], timeout=(5, 120)) -> str:
        resp = self._session.post(url, json=payload, timeout=timeout)
        resp.raise_for_status()
        return resp.text

    def chat_json(self, system: str, messages: List[Dict[str, str]]) -> Dict[str, Any]:
        """
        Request a JSON reply. If the model returns plain text, coerce to:
        {"thought":"", "chat": <text>, "action":{"name":"none","args":{}}}
        so the UI never shows 'No JSON...' and can proceed normally.
        """
        # NOTE: change URL/payload to match your backend if different.
        url = "http://127.0.0.1:11434/api/generate"
        payload = {
            "model": self.model,
            "prompt": self._to_prompt(system, messages),
            "stream": False
        }

        try:
            raw = self._post_json(url, payload, timeout=(5, 120))
        except requests.exceptions.ReadTimeout:
            # one longer retry for heavy prompts
            raw = self._post_json(url, payload, timeout=(5, 180))
        except Exception as e:
            raise RuntimeError(f"Model error: {e}")

        # Try JSON first
        try:
            data = json.loads(raw)

            # If backend already returned our schema, pass it through.
            if isinstance(data, dict) and (
                "chat" in data or "action" in data or "say" in data
            ):
                return data

            # Some servers return {"response": "..."} envelopes.
            if isinstance(data, dict) and isinstance(data.get("response"), str):
                return {
                    "thought": "",
                    "chat": data["response"],
                    "action": {"name": "none", "args": {}}
                }

        except json.JSONDecodeError:
            # fall through to treat raw as plain text
            pass

        # Plain text fallback (or unknown envelope)
        if isinstance(raw, str):
            text = raw.strip()
        else:
            text = "(no response)"

        return {
            "thought": "",
            "chat": text,
            "action": {"name": "none", "args": {}}
        }

    def _to_prompt(self, system: str, messages: List[Dict[str, str]]) -> str:
        parts: List[str] = []
        if system:
            parts.append(f"[SYSTEM]\n{system}\n")
        for m in messages:
            role = m.get("role", "user").upper()
            parts.append(f"[{role}]\n{m.get('content','')}\n")
        return "\n".join(parts)
