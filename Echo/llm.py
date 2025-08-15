# llm.py
import json
import http.client
from typing import List, Dict

def _extract_json(text: str) -> dict:
    """
    Try to pull the first top-level JSON object from text.
    Handles cases where the model adds prose or code fences.
    """
    if not text:
        raise ValueError("Empty assistant content.")
    # strip code fences if present
    if "```" in text:
        parts = text.split("```")
        # pick the largest chunk (usually the code block)
        text = max(parts, key=len)
    # bracket matching to find first {...}
    start = text.find("{")
    if start == -1:
        raise ValueError(f"No JSON object found in: {text[:120]}")
    depth = 0
    for i in range(start, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                candidate = text[start:i+1]
                return json.loads(candidate)
    raise ValueError("Unbalanced JSON braces in assistant output.")

class LLM:
    def __init__(self, model: str = "llama3.1"):
        self.model = model

    def chat_json(self, system: str, messages: List[Dict]) -> dict:
        """
        Call Ollama /api/chat with stream disabled; parse a single JSON object
        from assistant content, with a robust sanitizer.
        """
        body = {
            "model": self.model,
            "messages": messages,
            "options": {"temperature": 0.2},   # make JSON more consistent
            "stream": False                     # <-- crucial
        }
        conn = http.client.HTTPConnection("127.0.0.1", 11434, timeout=90)
        conn.request("POST", "/api/chat",
                     body=json.dumps(body),
                     headers={"Content-Type": "application/json"})
        resp = conn.getresponse()
        data = resp.read()
        conn.close()

        if resp.status != 200:
            raise ValueError(f"Ollama HTTP {resp.status}: {data[:200]!r}")

        payload = json.loads(data)
        content = payload.get("message", {}).get("content", "").strip()
        try:
            return json.loads(content)  # ideal case: pure JSON
        except Exception:
            # fall back to extraction if model added extra text
            return _extract_json(content)
