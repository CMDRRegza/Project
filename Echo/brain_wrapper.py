# brain_wrapper.py
import json, http.client
from pathlib import Path
from config import ECHO_NAME, THINK_LOG, CURRENT_MODEL_FILE, DEFAULT_MODEL, MEM_PATH
from memory import load_mem, save_mem
from logger import log_thought, clear_thoughts
from actions import ls as a_ls, read as a_read, write as a_write, mkdir as a_mkdir
from tool_spec import TOOL_PROMPT
from llm import LLM
from agent import execute_action

def read_current_model() -> str:
    try: return CURRENT_MODEL_FILE.read_text(encoding="utf-8").strip()
    except Exception: return DEFAULT_MODEL

def write_active_model(name: str):
    CURRENT_MODEL_FILE.write_text(name.strip(), encoding="utf-8")

class EchoBrain:
    def __init__(self):
        self.model_name = read_current_model()
        self.llm = LLM(model=self.model_name)
        self.mem = load_mem()
        self.session: list[str] = []

    def switch_model(self, name: str) -> str:
        name = name.strip()
        if not name: return "No model specified."
        self.model_name = name
        self.llm = LLM(model=self.model_name)
        write_active_model(name)
        return f"Switched model → {name}"

    def tool_chat(self, text: str) -> str:
        try:
            proposal = self.llm.chat_json(system=TOOL_PROMPT, messages=[{"role":"user","content": text}])
        except Exception as e:
            raw = str(e); marker = "No JSON object found in:"
            return raw.split(marker,1)[1].strip() if marker in raw else f"Model error: {raw}"

        chat_text = ((proposal.get("chat") or proposal.get("say") or "") if isinstance(proposal, dict) else "").strip()
        tool_out = ""
        try:
            action = (proposal.get("action") or {}) if isinstance(proposal, dict) else {}
            if isinstance(action, dict) and action.get("name","none") != "none":
                say_text, tool_result = execute_action(proposal)
                if not chat_text and say_text: chat_text = str(say_text).strip()
                if tool_result: tool_out = f"{tool_result}"
        except Exception as e:
            tool_out = f"[tool-error] {e}"

        return chat_text + ("\n<<TOOL_CARD>>\n"+tool_out if tool_out else "") or "(no response)"

    def handle_command(self, cmd: str) -> str:
        parts = cmd.split(maxsplit=1)
        head = parts[0].lower()
        tail = parts[1] if len(parts) > 1 else ""

        if head == "remember":
            if "=" not in tail: return "Use: remember key=value"
            k, v = [s.strip() for s in tail.split("=",1)]
            self.mem["facts"][k] = v; save_mem(self.mem); return f"Noted. I’ll remember {k} = {v}."
        if head == "recall":
            if not self.mem["facts"]: return "I don't have any facts yet."
            items = ", ".join(f"{k}={v}" for k,v in self.mem["facts"].items()); return "I remember: " + items
        if head == "goal":
            if not tail: return "Use: goal <text>"
            self.mem["goals"].append(tail); save_mem(self.mem); return f"Goal added: “{tail}”"
        if head == "goals":
            return "\n".join(f"- {g}" for g in self.mem["goals"]) or "No goals yet."
        if head == "history":
            if not self.session: return "No session messages yet."
            return "\n".join(self.session[-10:])
        if head == "clearlog":
            clear_thoughts(); return "Thinking log cleared."
        if head == "ls":    return a_ls(tail)
        if head == "read":  return a_read(tail) if tail else "Use: read <path>"
        if head == "write":
            if not tail or " " not in tail: return "Use: write <path> <text...>"
            p, t = tail.split(" ",1); return a_write(p,t)
        if head == "mkdir": return a_mkdir(tail) if tail else "Use: mkdir <path>"
        return self.tool_chat(cmd)

    def process(self, user_text: str) -> str:
        u = user_text.strip()
        if not u: return ""
        if u.lower() != "clearlog":
            self.session.append(f"YOU: {u}"); log_thought(f"observed_input -> {u}")
        else:
            self.session.append(f"YOU: {u}")
        reply = self.handle_command(u)
        self.session.append(f"ECHO: {reply}")
        if u.lower() != "clearlog": log_thought(f"planned_reply -> {reply}")
        return reply
