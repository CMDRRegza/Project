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
from actions import _resolve as _sandbox_resolve
from config import ALLOWED_ROOT
from memory import append_history
from profile_manager import get_profile
from mood import get_mood

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
        if not name:
            return "No model specified."
        self.model_name = name
        self.llm = LLM(model=self.model_name)
        write_active_model(name)
        return f"Switched model → {name}"

    # --- helpers ---

    def _normalize_chat(self, text: str) -> str:
        t = (text or "").strip()
        if len(t) < 12:
            return "Hello! How can I help you today?"
        return t

    def _run_ai(self, text: str) -> str:
        # --- inject Echo identity + mood before tool spec ---
        prof = {}
        try:
            prof = get_profile() or {}
        except Exception:
            prof = {}

        try:
            mood = get_mood()
        except Exception:
            mood = {"state": "neutral", "valence": 0.0, "relax": False}

        identity = (
            f"Your name is {prof.get('name','Echo')}. You assist {prof.get('owner','the user')}.\n"
            f"Main goal: {prof.get('main_goal','Help the user effectively')}.\n"
            f"Personality: {prof.get('personality','Helpful and concise')}.\n"
            f"Current mood: {mood.get('state','neutral')} (valence={mood.get('valence',0.0)}; relax={mood.get('relax',False)})."
        )

        # Stronger system message: identity first, then tools
        system_content = f"{identity}\n\n{TOOL_PROMPT}"
        system_msg = {"role": "system", "content": system_content}
        user_msg = {"role": "user", "content": text}

        try:
            proposal = self.llm.chat_json(system=system_content, messages=[system_msg, user_msg])
        except Exception as e:
            proposal = {
                "thought": "error",
                "chat": f"Model error: {e}",
                "action": {"name": "none", "args": {}}
            }

        # Log the raw model proposal (minified JSON)
        try:
            _min = json.dumps(proposal, separators=(',', ':'))
            log_thought(f"planned_reply -> {_min}")
        except Exception:
            pass

        # Execute the proposed action (respecting your strict agent rules)
        chat_text, tool_result = execute_action(proposal)

        # Normalize chat text length just in case
        chat_text = self._normalize_chat(chat_text)

        result = {
            "thought": proposal.get("thought", ""),
            "chat": chat_text,
            "action": proposal.get("action", {"name": "none", "args": {}})
        }
        if tool_result:
            result["tool_result"] = tool_result

        return json.dumps(result, ensure_ascii=False)


    def process_input(self, user_text: str):
        from agent import handle_command
        cmd_result = handle_command(user_text)
        if cmd_result is not None:
            try:
                _min = json.dumps(cmd_result, separators=(',', ':'))
                log_thought(f"planned_reply -> {_min}")
            except Exception:
                pass
            return json.dumps(cmd_result, ensure_ascii=False)

        return self._run_ai(user_text)
    
    # --- command router (only called when input starts with "/") ---

    def handle_command(self, cmd: str) -> str:
        parts = cmd.split(maxsplit=1)
        head = parts[0].lower()
        tail = parts[1] if len(parts) > 1 else ""

        if head == "remember":
            if "=" not in tail:
                return "Use: remember key=value"
            k, v = [s.strip() for s in tail.split("=", 1)]
            self.mem["facts"][k] = v
            save_mem(self.mem)
            return f"Noted. I’ll remember {k} = {v}."

        if head == "recall":
            from memory import recall_history
            hist = recall_history(5)  # get last 5
            if not hist:
                return "No recent memories."
            return "\n".join(
                f"[{h['time']}] You: {h['input']} → Echo: {h['reply']} (action={h['action']['name']})"
                for h in hist
            )
            
        if head == "dream":
            if tail.lower() in ("on", "start"):
                from daydream import start_daydream
                start_daydream(self.llm, interval_seconds=45, allow_actions=False)
                return "Daydreaming started."
            if tail.lower() in ("off", "stop"):
                from daydream import stop_daydream
                stop_daydream()
                return "Daydreaming stopped."
            return "Usage: /dream on|off"
        
        if head == "diag":
            try:
                self.llm.warmup()
            except Exception:
                pass
            dev = getattr(self.llm, "last_device", "unknown")
            return f"Diagnostics: device={dev}, model={self.llm.model}\nSandbox: {ALLOWED_ROOT}"
        
        if head == "where":
            try:
                p = _sandbox_resolve(tail or "")
                loc = f"{p}"
                rel = f"{p.relative_to(ALLOWED_ROOT)}" if p != ALLOWED_ROOT else "."
                exists = ("exists" if p.exists() else "missing")
                kind = ("dir" if p.is_dir() else "file" if p.is_file() else "unknown")
                return f"{rel} -> {loc}\nStatus: {exists}, {kind}"
            except Exception as e:
                return f"Resolve error: {e}"



        if head == "goal":
            if not tail:
                return "Use: goal <text>"
            self.mem["goals"].append(tail)
            save_mem(self.mem)
            return f"Goal added: “{tail}”"

        if head == "goals":
            return "\n".join(f"- {g}" for g in self.mem["goals"]) or "No goals yet."

        if head == "history":
            if not self.session:
                return "No session messages yet."
            return "\n".join(self.session[-10:])

        if head == "clearlog":
            clear_thoughts()
            return "Thinking log cleared."

        if head == "ls":
            return a_ls(tail)

        if head == "read":
            return a_read(tail) if tail else "Use: read <path>"

        if head == "write":
            if not tail or " " not in tail:
                return "Use: write <path> <text...>"
            p, t = tail.split(" ", 1)
            return a_write(p, t)

        if head == "mkdir":
            return a_mkdir(tail) if tail else "Use: mkdir <path>"

        if head == "ai":
            if not tail:
                return "Use: /ai <your request>"
            return self._run_ai(tail)

        # Unknown slash command → show help
        return "Unknown command. Try /help, /ls, /read, /write, /mkdir, /diag."

    # --- unified entry point for UI/console ---

    def process(self, observed_input: str):
        """
        Main loop: send user input + context to LLM, log reply, and save to memory.
        """
        from logger import log_thought
        from memory import append_history
        import json

        # log observed input
        log_thought(f"observed_input -> {observed_input}")

        # check if user typed a slash-command like /recall
        if observed_input.strip().startswith("/"):
            cmd_result = self.handle_command(observed_input[1:])
            log_thought(f"planned_reply -> {cmd_result}")
            append_history(
                user_input=observed_input,
                reply=str(cmd_result),
                action={"name": "command", "args": {}},
            )
            return json.dumps({
                "thought": "command",
                "chat": cmd_result,
                "action": {"name": "none", "args": {}}
            }, ensure_ascii=False)

        # run LLM to get planned reply
        planned_reply = self._run_ai(observed_input)

        # log planned reply
        log_thought(f"planned_reply -> {planned_reply}")

        # parse the reply to extract the action
        try:
            reply_data = json.loads(planned_reply)
            action = reply_data.get("action", {"name": "none", "args": {}})
        except Exception:
            action = {"name": "none", "args": {}}

        # record to memory.json (short-term history)
        append_history(
            user_input=observed_input,
            reply=str(planned_reply),
            action=action,
        )

        return planned_reply



