# --- keep your existing imports at top ---
import json
import os
from typing import Any, Dict, List, Tuple, Optional
import requests
from requests.adapters import HTTPAdapter
from urllib3.util.retry import Retry

BASE_URL = f"http://{os.environ.get('OLLAMA_HOST', '127.0.0.1')}:{os.environ.get('OLLAMA_PORT', '11434')}"


class LLM:
    def __init__(self, model: str, prefer_gpu: bool = True):
        self.model = model
        self.prefer_gpu = prefer_gpu
        self.last_device: str = "unknown"   # <— record the device used
        self._did_warmup: bool = False
        self._session = requests.Session()

        retries = Retry(
            total=2,
            backoff_factor=0.5,
            status_forcelist=(502, 503, 504),
            allowed_methods=frozenset(["GET", "POST"]),
        )
        self._session.mount("http://", HTTPAdapter(max_retries=retries))
        self._session.mount("https://", HTTPAdapter(max_retries=retries))

    def cancel(self) -> None:
        try:
            self._session.close()
        except Exception:
            pass
        self._session = requests.Session()

    # ---------- internals ----------

    def _post_json(self, url: str, payload: Dict[str, Any], timeout: Tuple[int, int] = (5, 120)) -> str:
        resp = self._session.post(url, json=payload, timeout=timeout)
        resp.raise_for_status()
        return resp.text

    def _to_prompt(self, system: str, messages: List[Dict[str, str]]) -> str:
        parts: List[str] = []
        if system:
            parts.append(f"[SYSTEM]\n{system}\n")
        for m in messages:
            role = m.get("role", "user").upper()
            parts.append(f"[{role}]\n{m.get('content', '')}\n")
        return "\n".join(parts)
    
    def chat_json(self, system: str, messages: list[dict]) -> dict:
        import json
        url = f"{BASE_URL}/api/generate"
        sys_txt = (system or "").strip()
        usr_txt = (messages[-1].get("content","") if messages else "").strip()

        payload = {
            "model": self.model,
            "prompt": f"{sys_txt}\n\nUser: {usr_txt}",
            "stream": False,
            "format": "json",  # enforce JSON mode
            "options": {
                "temperature": 0.2,
                "top_p": 0.9,
                "num_predict": 512,
            },
        }

        raw = self._generate_with_fallback(payload)

        try:
            return json.loads(raw)
        except Exception:
            # NO auto-repair; make the model fix itself next turn
            snippet = (raw or "").replace("\n", " ")[:200]
            raise RuntimeError(f"No JSON object found in: {snippet}")




    def _generate_with_fallback(self, base_payload: Dict[str, Any]) -> str:
        url = f"{BASE_URL}/api/generate"

        def attempt(payload: Dict[str, Any]) -> str:
            resp = self._session.post(url, json=payload, timeout=(5, 180))
            resp.raise_for_status()
            return resp.text

        # keep outputs reasonable for 8GB VRAM
        opts = {
            "num_predict": min(512, int(base_payload.get("options", {}).get("num_predict", 512))),
        }
        payload0 = {**base_payload, "options": {**base_payload.get("options", {}), **opts}}

        attempts: List[Tuple[str, Dict[str, Any]]] = []

        # GPU first — offload as many layers as possible
        if self.prefer_gpu:
            gpu_payload = {**payload0, "options": {**payload0["options"], "num_gpu": -1}}
            attempts.append(("gpu", gpu_payload))

        # CPU fallback — cap threads so it doesn't peg the machine
        cores = os.cpu_count() or 4
        cpu_threads = max(2, min(4, cores // 2))
        cpu_payload = {**payload0, "options": {**payload0["options"], "num_gpu": 0, "num_thread": cpu_threads}}
        attempts.append(("cpu", cpu_payload))

        last_err: Optional[Exception] = None

        # try current model: GPU → CPU
        for mode, pay in attempts:
            try:
                raw = attempt(pay)
                self.last_device = "gpu" if mode == "gpu" else "cpu"
                return raw
            except Exception as e:
                last_err = e

        # model fallback (smaller), GPU first then CPU
        fb_model = os.environ.get("ECHO_FALLBACK_MODEL", "llama3:8b").strip()
        if fb_model and fb_model != base_payload.get("model"):
            fb0 = {**payload0, "model": fb_model}
            try:
                raw = attempt({**fb0, "options": {**fb0["options"], "num_gpu": -1}})
                self.last_device = "gpu"
                return raw
            except Exception:
                try:
                    raw = attempt({**fb0, "options": {**fb0["options"], "num_gpu": 0, "num_thread": cpu_threads}})
                    self.last_device = "cpu"
                    return raw
                except Exception as e2:
                    last_err = e2

        raise RuntimeError(f"Model error: {last_err}")

    
    # ---------- public API ----------

    def chat_json(self, system: str, messages: List[Dict[str, str]]) -> Dict[str, Any]:
        import json
        payload = {
            "model": self.model,
            "prompt": self._to_prompt(system, messages),
            "stream": False,
            "format": "json",  # enforce JSON-only payload from the model
            "options": {
                "temperature": 0.2,
                "top_p": 0.9,
                "num_predict": 512,
            },
        }
        try:
            raw = self._generate_with_fallback(payload)
        except Exception as e:
            raise RuntimeError(f"Model error: {e}")

        # Ollama /api/generate returns an envelope JSON where 'response' is a STRING.
        # We must parse that string to get the actual tool-spec object.
        try:
            outer = json.loads(raw)
        except json.JSONDecodeError as je:
            snippet = (raw or "").replace("\n", " ")[:200]
            raise RuntimeError(f"No JSON object found in model response: {snippet}") from je

        # Prefer 'response' (generate API). If absent, try chat-like shapes.
        if isinstance(outer, dict) and isinstance(outer.get("response"), str):
            inner_str = outer["response"]
            try:
                inner = json.loads(inner_str)
            except json.JSONDecodeError as je2:
                snippet = (inner_str or "").replace("\n", " ")[:200]
                raise RuntimeError(f"Model returned non-JSON 'response': {snippet}") from je2
            if not isinstance(inner, dict):
                raise RuntimeError("Model 'response' did not decode to an object.")
            return inner

        # Some variants may return {'message': {'content': '<json string>'}}
        msg = outer.get("message") if isinstance(outer, dict) else None
        if isinstance(msg, dict) and isinstance(msg.get("content"), str):
            try:
                inner = json.loads(msg["content"])
            except json.JSONDecodeError as je3:
                snippet = (msg["content"] or "").replace("\n", " ")[:200]
                raise RuntimeError(f"Model returned non-JSON 'message.content': {snippet}") from je3
            if not isinstance(inner, dict):
                raise RuntimeError("Model 'message.content' did not decode to an object.")
            return inner

        # If we get here, we didn’t get a usable JSON tool-spec
        raise RuntimeError("Model did not return a JSON tool-spec object.")


