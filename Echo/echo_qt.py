# echo_qt.py
# A sleek ChatGPT-style desktop UI for Echo (PySide6).
# Works with your existing modules: config.py, memory.py, logger.py, actions.py, tool_spec.py, llm.py, agent.py

import sys, subprocess, json, http.client, threading
from pathlib import Path

from PySide6.QtCore import Qt, QTimer
from PySide6.QtWidgets import (
    QApplication, QMainWindow, QWidget, QSplitter, QVBoxLayout, QHBoxLayout,
    QLabel, QLineEdit, QPushButton, QTextEdit, QScrollArea, QComboBox, QFrame
)
from PySide6.QtGui import QTextCursor



# optional dark theme
try:
    import qdarktheme
except Exception:
    qdarktheme = None

# ---- Echo brain pieces you already have ----
from config import (
    ECHO_NAME, THINK_LOG, CURRENT_MODEL_FILE, DEFAULT_MODEL, MEM_PATH
)
from memory import load_mem, save_mem
from logger import log_thought, clear_thoughts
from actions import ls as a_ls, read as a_read, write as a_write, mkdir as a_mkdir
from tool_spec import TOOL_PROMPT
from llm import LLM
from agent import execute_action
DARK_QSS = """
* { font-family: 'Segoe UI', Arial, sans-serif; font-size: 14px; }
QMainWindow, QWidget { background-color: #0b0f14; color: #e5e7eb; }
QLabel { color: #d1d5db; }
QLineEdit, QTextEdit, QComboBox, QScrollArea {
    background-color: #0f1720; color: #e5e7eb;
    border: 1px solid #1f2937; border-radius: 10px; padding: 8px;
}
QPushButton {
    background-color: #1f2a37; color: #e5e7eb;
    border: 1px solid #2b3645; border-radius: 10px; padding: 8px 12px;
}
QPushButton:hover { background-color: #233042; }
QPushButton:pressed { background-color: #1b2431; }
QComboBox QAbstractItemView {
    background: #0f1720; color: #e5e7eb; selection-background-color: #334155;
    border: 1px solid #1f2937; outline: 0;
}
QScrollBar:vertical {
    background: #0f1720; width: 10px; margin: 0;
}
QScrollBar::handle:vertical {
    background: #263241; min-height: 24px; border-radius: 5px;
}
"""



# --------------------- tiny helpers ---------------------

def read_current_model() -> str:
    try:
        return CURRENT_MODEL_FILE.read_text(encoding="utf-8").strip()
    except Exception:
        return DEFAULT_MODEL

def write_active_model(name: str):
    CURRENT_MODEL_FILE.write_text(name.strip(), encoding="utf-8")

def get_installed_models():
    """Query Ollama for installed model tags."""
    try:
        conn = http.client.HTTPConnection("127.0.0.1", 11434, timeout=5)
        conn.request("GET", "/api/tags")
        resp = conn.getresponse()
        data = resp.read()
        conn.close()
        if resp.status != 200:
            return []
        payload = json.loads(data)
        return [m.get("name","").strip() for m in payload.get("models", []) if m.get("name")]
    except Exception:
        return []


# --------------------- brain wrapper ---------------------

class EchoBrain:
    """Holds mem/session/model and reproduces your handle_command + logging."""
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

    # your command handler (same logic as main.py)
    def handle_command(self, cmd: str) -> str:
        parts = cmd.split(maxsplit=1)
        head = parts[0].lower()
        tail = parts[1] if len(parts) > 1 else ""

        # memory / goals
        if head == "remember":
            if "=" not in tail:
                return "Use: remember key=value"
            k, v = [s.strip() for s in tail.split("=", 1)]
            self.mem["facts"][k] = v
            save_mem(self.mem)
            return f"Noted. I’ll remember {k} = {v}."
        if head == "recall":
            if not self.mem["facts"]:
                return "I don't have any facts yet."
            items = ", ".join(f"{k}={v}" for k, v in self.mem["facts"].items())
            return "I remember: " + items
        if head == "goal":
            if not tail:
                return "Use: goal <text>"
            self.mem["goals"].append(tail)
            save_mem(self.mem)
            return f"Goal added: “{tail}”"
        if head == "goals":
            return "\n".join(f"- {g}" for g in self.mem["goals"]) or "No goals yet."

        # thinking log
        if head == "history":
            if not self.session:
                return "No session messages yet."
            return "\n".join(self.session[-10:])
        if head == "clearlog":
            clear_thoughts()
            return "Thinking log cleared."

        # sandboxed actions
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

        # LLM tool-use (same as your main.py)
        if head == "ai":
            if not tail:
                return "Use: ai <your request>"
            system_msg = {"role": "system", "content": TOOL_PROMPT}
            user_msg = {"role": "user", "content": tail}
            try:
                proposal = self.llm.chat_json(system=TOOL_PROMPT, messages=[system_msg, user_msg])
            except Exception as e:
                return f"Model error: {e}"

            say_text, tool_result = execute_action(proposal)
            out = say_text
            if tool_result:
                out += f"\n\n[tool]\n{tool_result}"
            return out

        # exit (not used in GUI)
        if head in ("quit", "exit"):
            return "Use the window close button."

        # default small-talk
        fact_hint = ""
        if self.mem["facts"]:
            k, v = next(iter(self.mem["facts"].items()))
            fact_hint = f" (btw I still remember {k}={v})"
        return f"I’m thinking about: “{cmd}”.{fact_hint}"

    def process(self, user_text: str) -> str:
        """Add logs, call handler, add reply logs; return reply."""
        u = user_text.strip()
        if not u:
            return ""
        # log input (skip clearlog logging)
        if u.lower() != "clearlog":
            self.session.append(f"YOU: {u}")
            log_thought(f"observed_input -> {u}")
        else:
            self.session.append(f"YOU: {u}")

        reply = self.handle_command(u)

        self.session.append(f"ECHO: {reply}")
        if u.lower() != "clearlog":
            log_thought(f"planned_reply -> {reply}")
        return reply


# --------------------- UI ---------------------

def bubble(text: str, role: str) -> QWidget:
    """Simple chat bubble (Echo vs You)."""
    box = QFrame()
    box.setFrameShape(QFrame.NoFrame)
    lay = QVBoxLayout(box)
    lay.setContentsMargins(12, 8, 12, 8)

    label = QLabel(text)
    label.setWordWrap(True)
    label.setTextInteractionFlags(Qt.TextSelectableByMouse)

    if role == "you":
        label.setStyleSheet(
            "font-size:14px; color:#e5e7eb; background:#2563eb; "
            "padding:12px; border-radius:16px;"
        )
        lay.setAlignment(Qt.AlignRight)
    else:
        label.setStyleSheet(
            "font-size:14px; color:#e5e7eb; background:#111827; "
            "padding:12px; border-radius:16px; border:1px solid #1f2937;"
        )
        lay.setAlignment(Qt.AlignLeft)

    lay.addWidget(label)
    return box

class EchoWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Echo — Chat")
        self.resize(1000, 680)

        # brain
        self.brain = EchoBrain()

        # root splitter
        splitter = QSplitter(Qt.Horizontal)
        self.setCentralWidget(splitter)

        # ---- left: chat
        left = QWidget()
        lv = QVBoxLayout(left); lv.setContentsMargins(12,12,12,12); lv.setSpacing(8)

        # top controls (model picker + refresh + set + pull)
        top_row = QHBoxLayout(); lv.addLayout(top_row)

        self.model_combo = QComboBox()
        self.refresh_models()
        self.model_combo.setEditable(False)
        self.model_combo.setSizeAdjustPolicy(QComboBox.AdjustToContents)
        top_row.addWidget(QLabel("Model"))
        top_row.addWidget(self.model_combo, 1)

        refresh_btn = QPushButton("Refresh")
        refresh_btn.clicked.connect(self.refresh_models)
        top_row.addWidget(refresh_btn)

        set_btn = QPushButton("Set Active")
        set_btn.clicked.connect(self.set_active_model)
        top_row.addWidget(set_btn)

        # optional pull box
        self.pull_edit = QLineEdit()
        self.pull_edit.setPlaceholderText("Pull model (e.g., llama3:8b)")
        pull_btn = QPushButton("Pull")
        pull_btn.clicked.connect(self.pull_model_clicked)
        top_row2 = QHBoxLayout(); lv.addLayout(top_row2)
        top_row2.addWidget(self.pull_edit, 1)
        top_row2.addWidget(pull_btn)

        # chat scroller
        self.scroll_area = QScrollArea()
        self.scroll_area.setWidgetResizable(True)
        self.chat_holder = QWidget()
        self.chat_layout = QVBoxLayout(self.chat_holder)
        self.chat_layout.addStretch(1)
        self.scroll_area.setWidget(self.chat_holder)
        lv.addWidget(self.scroll_area, 1)

        # input row
        in_row = QHBoxLayout()
        self.input = QLineEdit()
        self.input.setPlaceholderText("Type a message…  (tip: prefix with 'ai ' to use the model)")
        send_btn = QPushButton("Send")
        send_btn.clicked.connect(self.on_send)
        self.input.returnPressed.connect(self.on_send)
        in_row.addWidget(self.input, 1)
        in_row.addWidget(send_btn)
        lv.addLayout(in_row)

        splitter.addWidget(left)

        # ---- right: thinking tail
        right = QWidget()
        rv = QVBoxLayout(right); rv.setContentsMargins(12,12,12,12)
        rv.addWidget(QLabel("Thinking (live tail)"))
        self.tail = QTextEdit(); self.tail.setReadOnly(True)
        self.tail.setLineWrapMode(QTextEdit.NoWrap)
        rv.addWidget(self.tail, 1)
        splitter.addWidget(right)

        splitter.setSizes([650, 350])

        # timers
        self.tail_timer = QTimer(self)
        self.tail_timer.timeout.connect(self.refresh_tail)
        self.tail_timer.start(700)

        # greet
        self.append_echo(f"Hello, I’m {ECHO_NAME}. Persistent memory: {MEM_PATH.name}\nActive model: {self.brain.model_name}")

    # ---- UI helpers ----
    def append_you(self, text: str):
        self.chat_layout.insertWidget(self.chat_layout.count()-1, bubble(text, "you"))
        QTimer.singleShot(0, lambda: self.scroll_area.verticalScrollBar().setValue(self.scroll_area.verticalScrollBar().maximum()))

    def append_echo(self, text: str):
        self.chat_layout.insertWidget(self.chat_layout.count()-1, bubble(text, "echo"))
        QTimer.singleShot(0, lambda: self.scroll_area.verticalScrollBar().setValue(self.scroll_area.verticalScrollBar().maximum()))

    def on_send(self):
        text = self.input.text().strip()
        if not text:
            return
        self.input.clear()
        self.append_you(text)
        reply = self.brain.process(text)
        if reply:
            self.append_echo(reply)

    def refresh_tail(self):
        try:
            raw = THINK_LOG.read_text(encoding="utf-8")
        except FileNotFoundError:
            raw = "(no thinking yet)"

        text = raw[-12000:]

        # only update if changed to avoid flicker
        if getattr(self, "_last_tail", None) == text:
            return
        self._last_tail = text

        self.tail.setPlainText(text)
        self.tail.moveCursor(QTextCursor.End)

    def refresh_models(self):
        names = get_installed_models()
        self.model_combo.clear()
        if not names:
            self.model_combo.addItem("(no models found)")
        else:
            for n in names:
                self.model_combo.addItem(n)
            # try select current
            idx = self.model_combo.findText(self.brain.model_name)
            if idx >= 0:
                self.model_combo.setCurrentIndex(idx)

    def set_active_model(self):
        name = self.model_combo.currentText().strip()
        if not name or name.startswith("("):
            self.append_echo("No installed models found. Try pulling one.")
            return
        msg = self.brain.switch_model(name)
        self.append_echo(msg)

    def pull_model_clicked(self):
        name = self.pull_edit.text().strip()
        if not name:
            self.append_echo("Enter a model tag to pull, e.g., llama3:8b")
            return
        self.append_echo(f"Pulling {name}… this may take a while.")
        threading.Thread(target=self._pull_worker, args=(name,), daemon=True).start()

    def _pull_worker(self, name: str):
        try:
            # Use shell=True on Windows so 'ollama' is found in PATH
            proc = subprocess.Popen(["ollama", "pull", name], stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, shell=True)
            for line in proc.stdout:
                self.append_echo(line.rstrip("\n"))
            code = proc.wait()
            if code == 0:
                self.append_echo(f"Pull complete: {name}")
                self.refresh_models()
            else:
                self.append_echo(f"Pull failed (exit {code}) for {name}")
        except FileNotFoundError:
            self.append_echo("'ollama' not found in PATH")
        except Exception as e:
            self.append_echo(f"Pull error: {e}")


def main():
    app = QApplication(sys.argv)
    app.setStyleSheet(DARK_QSS)
    win = EchoWindow()
    win.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
