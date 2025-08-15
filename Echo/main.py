from pathlib import Path

from config import ECHO_NAME, MEM_PATH, CURRENT_MODEL_FILE, DEFAULT_MODEL
from memory import load_mem, save_mem
from logger import log_thought, tail_thoughts, clear_thoughts
from actions import ls as a_ls, read as a_read, write as a_write, mkdir as a_mkdir
from tool_spec import TOOL_PROMPT
from llm import LLM
from agent import execute_action


# ---- LLM helpers ----
def build_llm(name: str) -> LLM:
    return LLM(model=name)

def read_current_model() -> str:
    try:
        return CURRENT_MODEL_FILE.read_text(encoding="utf-8").strip()
    except Exception:
        return DEFAULT_MODEL


# ---- command handler ----
def handle_command(cmd: str, mem: dict, session: list[str], llm):
    parts = cmd.split(maxsplit=1)
    head = parts[0].lower()
    tail = parts[1] if len(parts) > 1 else ""

    # ----- memory / goals -----
    if head == "remember":
        if "=" not in tail:
            return "Use: remember key=value"
        k, v = [s.strip() for s in tail.split("=", 1)]
        mem["facts"][k] = v
        save_mem(mem)
        return f"Noted. I’ll remember {k} = {v}."

    if head == "recall":
        if not mem["facts"]:
            return "I don't have any facts yet."
        items = ", ".join(f"{k}={v}" for k, v in mem["facts"].items())
        return "I remember: " + items

    if head == "goal":
        if not tail:
            return "Use: goal <text>"
        mem["goals"].append(tail)
        save_mem(mem)
        return f"Goal added: “{tail}”"

    if head == "goals":
        return "\n".join(f"- {g}" for g in mem["goals"]) or "No goals yet."

    # ----- thinking log -----
    if head == "history":
        if not session:
            return "No session messages yet."
        return "\n".join(session[-10:])

    if head == "clearlog":
        clear_thoughts()
        return "Thinking log cleared."

    # ----- sandboxed actions -----
    if head == "ls":
        return a_ls(tail)

    if head == "read":
        if not tail:
            return "Use: read <path>"
        return a_read(tail)

    if head == "write":
        if not tail or " " not in tail:
            return "Use: write <path> <text...>"
        path, text = tail.split(" ", 1)
        return a_write(path, text)

    if head == "mkdir":
        if not tail:
            return "Use: mkdir <path>"
        return a_mkdir(tail)

    # ----- LLM tool-use -----
    if head == "ai":
        if not tail:
            return "Use: ai <your request>"
        system_msg = {"role": "system", "content": TOOL_PROMPT}
        user_msg = {"role": "user", "content": tail}
        try:
            proposal = llm.chat_json(system=TOOL_PROMPT, messages=[system_msg, user_msg])
        except Exception as e:
            return f"Model error: {e}"

        say_text, tool_result = execute_action(proposal)
        out = say_text
        if tool_result:
            out += f"\n\n[tool]\n{tool_result}"
        return out

    # ----- exit -----
    if head in ("quit", "exit"):
        return "__QUIT__"

    # default small-talk
    fact_hint = ""
    if mem["facts"]:
        k, v = next(iter(mem["facts"].items()))
        fact_hint = f" (btw I still remember {k}={v})"
    return f"I’m thinking about: “{cmd}”.{fact_hint}"


def main():
    # initial model (read from file so the UI can change it)
    model_name = read_current_model()
    llm = build_llm(model_name)
    try:
        model_mtime = CURRENT_MODEL_FILE.stat().st_mtime
    except FileNotFoundError:
        model_mtime = 0.0

    mem = load_mem()
    session: list[str] = []

    print(f"Hello, I’m {ECHO_NAME}. Persistent memory online: {MEM_PATH.name}")
    print("Sandbox ready. Commands: ls, read, write, mkdir, remember, recall, goal, goals, history, clearlog, quit")
    print(f"Model: {model_name}  (change it from the UI)")

    while True:
        user = input("> ").strip()
        if not user:
            # still allow hot-reload even if user pressed Enter
            try:
                cur_mtime = CURRENT_MODEL_FILE.stat().st_mtime
                if cur_mtime != model_mtime:
                    model_mtime = cur_mtime
                    new_name = read_current_model()
                    if new_name != model_name:
                        model_name = new_name
                        llm = build_llm(model_name)
                        print(f"[echo] Switched model → {model_name}")
            except FileNotFoundError:
                pass
            continue

        # --- hot reload model if UI changed file ---
        try:
            cur_mtime = CURRENT_MODEL_FILE.stat().st_mtime
            if cur_mtime != model_mtime:
                model_mtime = cur_mtime
                new_name = read_current_model()
                if new_name != model_name:
                    model_name = new_name
                    llm = build_llm(model_name)
                    print(f"[echo] Switched model → {model_name}")
        except FileNotFoundError:
            pass

        # session memory + thought log (skip logging for clearlog to keep it pristine)
        if user.lower() != "clearlog":
            session.append(f"YOU: {user}")
            log_thought(f"observed_input -> {user}")
        else:
            session.append(f"YOU: {user}")

        reply = handle_command(user, mem, session, llm)

        if reply == "__QUIT__":
            print("Shutting down. See you next time.")
            log_thought("system -> shutdown")
            break

        session.append(f"ECHO: {reply}")
        if user.lower() != "clearlog":
            log_thought(f"planned_reply -> {reply}")
        print(reply)

        # small peek at recent “thoughts”
        preview = tail_thoughts(4)
        if preview:
            print("\n--- thinking (recent) ---")
            for line in preview:
                print(line)
            print("-------------------------")

if __name__ == "__main__":
    main()
