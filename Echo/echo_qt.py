# echo_qt.py
# ChatGPT-style UI for Echo (PySide6).
# - ONE circular media button (Send ↔ Stop)
# - Typewriter effect for assistant replies
# - Tool result as a compact card under the message
# - No bubble cut-offs (width cap + height-for-width refresh)
# - Auto-run main.py, QProcess pull, async sends

import sys, json, http.client, os
from pathlib import Path

from PySide6.QtCore import (
    Qt, QTimer, QProcess, QSettings, QEvent, QObject, Signal, QRunnable, QThreadPool, QSize
)
from PySide6.QtWidgets import (
    QApplication, QMainWindow, QWidget, QSplitter, QVBoxLayout, QHBoxLayout,
    QLabel, QLineEdit, QScrollArea, QComboBox, QFrame, QToolButton, QTextEdit
)
from PySide6.QtGui import QFont, QTextCursor

# ---- Echo brain pieces ----
from config import (
    ECHO_NAME, THINK_LOG, CURRENT_MODEL_FILE, DEFAULT_MODEL, MEM_PATH
)
from memory import load_mem, save_mem
from logger import log_thought, clear_thoughts
from actions import ls as a_ls, read as a_read, write as a_write, mkdir as a_mkdir
from tool_spec import TOOL_PROMPT
from llm import LLM
from agent import execute_action

# --------------------- theme ---------------------
DARK_QSS = """
* { font-family: 'Inter', 'Segoe UI', Arial, sans-serif; font-size: 14px; }
QMainWindow, QWidget { background-color: #0b0f14; color: #e5e7eb; }
QLabel { color: #d1d5db; }

QFrame#Bubble {
    background-color: #111827;
    border: 1px solid #1f2937;
    border-radius: 16px;
}

QFrame#ToolCard {
    background-color: #0f1720;
    border: 1px dashed #334155;
    border-radius: 12px;
}

QLineEdit, QComboBox, QScrollArea {
    background-color: #0f1720; color: #e5e7eb;
    border: 1px solid #1f2937; border-radius: 10px; padding: 10px;
}

QToolButton#Media {
    background: #0f0f12;
    color: #e5e7eb;
    border-radius: 28px; /* 56x56 circle */
    border: 1px solid #2b2f3a;
    font-weight: 700;
}
QToolButton#Media:hover { background: #161922; }
QToolButton#Media:pressed { background: #0d0f15; }

QComboBox QAbstractItemView {
    background: #0f1720; color: #e5e7eb; selection-background-color: #334155;
    border: 1px solid #1f2937; outline: 0;
}

QScrollBar:vertical { background: #0f1720; width: 10px; margin: 0; }
QScrollBar::handle:vertical { background: #263241; min-height: 24px; border-radius: 5px; }
"""

# --------------------- tiny helpers ---------------------
HERE = Path(__file__).resolve().parent
MAIN_PY = HERE / "main.py"

def read_current_model() -> str:
    try:
        return CURRENT_MODEL_FILE.read_text(encoding="utf-8").strip()
    except Exception:
        return DEFAULT_MODEL

def write_active_model(name: str):
    CURRENT_MODEL_FILE.write_text(name.strip(), encoding="utf-8")

def get_installed_models():
    try:
        conn = http.client.HTTPConnection("127.0.0.1", 11434, timeout=3)
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
    """Routes every message through the tool prompt and returns UI-ready text."""
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

    def tool_chat(self, text: str) -> str:
        """Call model with TOOL_PROMPT; expect JSON containing 'chat' and optional 'action'."""
        try:
            proposal = self.llm.chat_json(
                system=TOOL_PROMPT,
                messages=[{"role": "user", "content": text}],
            )
        except Exception as e:
            raw = str(e)
            marker = "No JSON object found in:"
            if marker in raw:
                return raw.split(marker, 1)[1].strip()
            return f"Model error: {raw}"

        chat_text = (
            (proposal.get("chat") if isinstance(proposal, dict) else None)
            or (proposal.get("say") if isinstance(proposal, dict) else None)
            or ""
        ).strip()

        tool_out = ""
        try:
            action = (proposal.get("action") or {}) if isinstance(proposal, dict) else {}
            if isinstance(action, dict) and action.get("name", "none") != "none":
                say_text, tool_result = execute_action(proposal)
                if not chat_text and say_text:
                    chat_text = str(say_text).strip()
                if tool_result:
                    tool_out = f"{tool_result}"
        except Exception as e:
            tool_out = f"[tool-error] {e}"

        # Pack as a transport string; UI will split on our sentinel if present.
        if tool_out:
            return chat_text + "\n<<TOOL_CARD>>\n" + tool_out
        return chat_text or "(no response)"

    # legacy/direct commands still supported
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

        # direct sandbox actions (power user)
        if head == "ls":    return a_ls(tail)
        if head == "read":  return a_read(tail) if tail else "Use: read <path>"
        if head == "write":
            if not tail or " " not in tail: return "Use: write <path> <text...>"
            path, text = tail.split(" ", 1); return a_write(path, text)
        if head == "mkdir": return a_mkdir(tail) if tail else "Use: mkdir <path>"

        # everything else goes through tool+chat pipeline
        return self.tool_chat(cmd)

    def process(self, user_text: str) -> str:
        u = user_text.strip()
        if not u:
            return ""
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

# --------------------- message widgets ---------------------
class Bubble(QFrame):
    """A resizable chat bubble containing a QLabel."""
    def __init__(self, role: str, max_width_provider):
        super().__init__()
        self.setObjectName("Bubble")
        self.role = role
        self.max_width_provider = max_width_provider
        self.setFrameShape(QFrame.NoFrame)
        lay = QVBoxLayout(self)
        lay.setContentsMargins(12, 8, 12, 8)
        self.label = QLabel("")
        self.label.setWordWrap(True)
        self.label.setTextInteractionFlags(Qt.TextSelectableByMouse)
        # role style
        if role == "you":
            self.label.setStyleSheet(
                "font-size:14px; color:#e5e7eb; background:#2563eb; "
                "padding:12px; border-radius:16px;"
            )
        else:
            self.label.setStyleSheet(
                "font-size:14px; color:#e5e7eb; background:#111827; "
                "padding:12px; border-radius:16px; border:1px solid #1f2937;"
            )
        lay.addWidget(self.label)

    def setText(self, text: str):
        self.label.setText(text)
        self.refreshWidth()

    def refreshWidth(self):
        mw = int(self.max_width_provider() or 640)
        self.label.setMaximumWidth(mw)
        self.label.adjustSize()

def make_row(widget: QWidget, align: str) -> QWidget:
    """Row container to avoid cut-offs: [stretch,bubble] for 'you', [bubble,stretch] for 'echo'."""
    row = QWidget()
    h = QHBoxLayout(row)
    h.setContentsMargins(0, 6, 0, 6)
    if align == "right":  # 'you'
        h.addStretch(1)
        h.addWidget(widget, 0)
    else:                 # 'echo'
        h.addWidget(widget, 0)
        h.addStretch(1)
    return row

def tool_card(text: str, max_width_provider) -> QWidget:
    card = QFrame()
    card.setObjectName("ToolCard")
    lay = QVBoxLayout(card); lay.setContentsMargins(12, 10, 12, 10)
    lbl = QLabel(text.strip()); lbl.setWordWrap(True); lbl.setTextInteractionFlags(Qt.TextSelectableByMouse)
    lay.addWidget(lbl)
    # width cap similar to bubbles
    mw = int(max_width_provider() or 640)
    lbl.setMaximumWidth(mw)
    lbl.adjustSize()
    return make_row(card, "left")

# --------------------- async worker ---------------------
class BrainTaskSignals(QObject):
    finished = Signal(str)
    failed = Signal(str)

class BrainTask(QRunnable):
    def __init__(self, brain: EchoBrain, text: str, cancel_flag: dict):
        super().__init__()
        self.brain = brain
        self.text = text
        self.cancel_flag = cancel_flag
        self.signals = BrainTaskSignals()

    def run(self):
        try:
            if self.cancel_flag.get("cancel"):
                return
            reply = self.brain.process(self.text)
            if self.cancel_flag.get("cancel"):
                return
            self.signals.finished.emit(reply)
        except Exception as e:
            self.signals.failed.emit(str(e))

# --------------------- main window ---------------------
class EchoWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Echo — Chat")
        self.resize(1080, 740)
        self.thread_pool = QThreadPool.globalInstance()

        self.settings = QSettings("EchoProject", "EchoQt")
        if self.settings.value("geometry"):
            self.restoreGeometry(self.settings.value("geometry"))
        if self.settings.value("windowState"):
            self.restoreState(self.settings.value("windowState"))

        self.brain = EchoBrain()
        self._fresh_session = True
        self._running = False
        self._cancel_flag = {"cancel": False}
        self._anim_timer = None
        self._pending_bubble: Bubble | None = None
        self._type_timer = None

        splitter = QSplitter(Qt.Horizontal)
        self.setCentralWidget(splitter)

        # ---- left: chat ----
        left = QWidget()
        lv = QVBoxLayout(left); lv.setContentsMargins(12,12,12,12); lv.setSpacing(10)

        # top controls (model picker + refresh + set + pull)
        top_row = QHBoxLayout(); lv.addLayout(top_row)
        self.model_combo = QComboBox(); self.refresh_models()
        self.model_combo.setEditable(False)
        self.model_combo.setSizeAdjustPolicy(QComboBox.AdjustToContents)
        top_row.addWidget(QLabel("Model"))
        top_row.addWidget(self.model_combo, 1)
        refresh_btn = QToolButton(); refresh_btn.setText("↻"); refresh_btn.clicked.connect(self.refresh_models); top_row.addWidget(refresh_btn)
        set_btn = QToolButton(); set_btn.setText("✓"); set_btn.clicked.connect(self.set_active_model); top_row.addWidget(set_btn)

        # pull row
        self.pull_edit = QLineEdit(); self.pull_edit.setPlaceholderText("Pull model (e.g., llama3:8b)")
        pull_btn = QToolButton(); pull_btn.setText("⇣"); pull_btn.clicked.connect(self.pull_model_clicked)
        row2 = QHBoxLayout(); lv.addLayout(row2)
        row2.addWidget(self.pull_edit, 1); row2.addWidget(pull_btn)

        # chat scroller
        self.scroll_area = QScrollArea(); self.scroll_area.setWidgetResizable(True)
        self.chat_holder = QWidget()
        self.chat_layout = QVBoxLayout(self.chat_holder); self.chat_layout.setSpacing(0); self.chat_layout.addStretch(1)
        self.scroll_area.setWidget(self.chat_holder)
        lv.addWidget(self.scroll_area, 1)

        # input row with ONE circular media button
        in_row = QHBoxLayout()
        self.input = QLineEdit()
        self.input.setPlaceholderText("Type anything… (Echo will reply and use tools automatically)")
        self.input.returnPressed.connect(self.media_clicked)        # Enter = click media button
        self.input.installEventFilter(self)
        in_row.addWidget(self.input, 1)

        self.media_btn = QToolButton()
        self.media_btn.setObjectName("Media")
        self.media_btn.setFixedSize(QSize(56, 56))
        self.media_btn.setText("↑")          # idle = send
        self.media_btn.setToolTip("Send")
        self.media_btn.clicked.connect(self.media_clicked)
        in_row.addWidget(self.media_btn, 0, Qt.AlignRight)

        lv.addLayout(in_row)
        splitter.addWidget(left)

        # ---- right: tail ----
        right = QWidget()
        rv = QVBoxLayout(right); rv.setContentsMargins(12,12,12,12); rv.setSpacing(10)
        rv.addWidget(QLabel("Thinking (live tail)"))
        self.tail = QTextEdit(); self.tail.setReadOnly(True); self.tail.setLineWrapMode(QTextEdit.NoWrap)
        rv.addWidget(self.tail, 1)
        splitter.addWidget(right)
        splitter.setSizes([720, 360])

        # timers
        self.tail_timer = QTimer(self); self.tail_timer.timeout.connect(self.refresh_tail); self.tail_timer.start(900)
        self.start_backend_once()

        # keep track of all message bubbles to recompute widths on resize
        self._all_bubbles: list[Bubble] = []

    # ---------- sizing ----------
    def bubble_max_width(self) -> int:
        vp = self.scroll_area.viewport()
        return int(vp.width() * 0.66) if vp else 640

    def resizeEvent(self, event):
        super().resizeEvent(event)
        for b in self._all_bubbles:
            b.refreshWidth()

    # ---------- lifecycle ----------
    def closeEvent(self, event):
        self.settings.setValue("geometry", self.saveGeometry())
        self.settings.setValue("windowState", self.saveState())
        super().closeEvent(event)

    # ---------- keyboard ----------
    def eventFilter(self, obj, event):
        if obj is self.input and event.type() == QEvent.KeyPress:
            if (event.key() in (Qt.Key_Return, Qt.Key_Enter)) and (event.modifiers() & Qt.ControlModifier):
                self.media_clicked(); return True
        return super().eventFilter(obj, event)

    # ---------- message helpers ----------
    def add_bubble(self, role: str, text: str) -> Bubble:
        bub = Bubble(role, self.bubble_max_width)
        bub.setText(text)
        row = make_row(bub, "right" if role == "you" else "left")
        self.chat_layout.insertWidget(self.chat_layout.count()-1, row)
        self._all_bubbles.append(bub)
        QTimer.singleShot(0, self.scroll_to_bottom)
        return bub

    def add_tool_card(self, text: str):
        row = tool_card(text, self.bubble_max_width)
        self.chat_layout.insertWidget(self.chat_layout.count()-1, row)
        QTimer.singleShot(0, self.scroll_to_bottom)

    def scroll_to_bottom(self):
        bar = self.scroll_area.verticalScrollBar()
        bar.setValue(bar.maximum())

    # ---------- media button behavior ----------
    def set_media_state(self, running: bool):
        self._running = running
        if running:
            self.media_btn.setText("■")
            self.media_btn.setToolTip("Stop")
        else:
            self.media_btn.setText("↑")
            self.media_btn.setToolTip("Send")

    def media_clicked(self):
        if self._running:
            self.stop_current()
        else:
            self.on_send()

    # ---------- send pipeline ----------
    def on_send(self):
        text = self.input.text().strip()
        if not text:
            return
        self.input.clear()
        self.add_bubble("you", text)

        # Placeholder assistant bubble ("Thinking") that will typewriter-fill later
        self._pending_bubble = self.add_bubble("echo", "Thinking")
        self._start_thinking_animation(self._pending_bubble.label)

        # async brain call
        self._cancel_flag = {"cancel": False}
        task = BrainTask(self.brain, text, self._cancel_flag)
        task.signals.finished.connect(self._on_finished)
        task.signals.failed.connect(self._on_failed)
        self.set_media_state(True)
        self.thread_pool.start(task)

    def stop_current(self):
        if not self._running:
            return
        self._cancel_flag["cancel"] = True
        self._stop_thinking_animation()
        if self._pending_bubble:
            self._pending_bubble.setText("(stopped)")
        self.set_media_state(False)

    # ---------- thinking animation ----------
    def _start_thinking_animation(self, label: QLabel):
        self._anim_timer = QTimer(self)
        dots = {"n": 0}
        def tick():
            dots["n"] = (dots["n"] + 1) % 4
            label.setText("Thinking" + "." * dots["n"])
            self.scroll_to_bottom()
        self._anim_timer.timeout.connect(tick)
        self._anim_timer.start(350)

    def _stop_thinking_animation(self):
        if self._anim_timer:
            self._anim_timer.stop()
            self._anim_timer = None

    # ---------- finish handlers ----------
    def _on_finished(self, reply: str):
        if self._cancel_flag.get("cancel"):
            return
        self._stop_thinking_animation()
        self.set_media_state(False)

        # Split out tool card if our sentinel is present
        tool_text = None
        if "\n<<TOOL_CARD>>\n" in reply:
            msg, tool_text = reply.split("\n<<TOOL_CARD>>\n", 1)
        else:
            msg = reply

        # Typewriter effect into the pending bubble
        if not self._pending_bubble:
            self.add_bubble("echo", msg)
        else:
            self._typewriter(self._pending_bubble, msg)

        if tool_text:
            # show as separate compact card under the assistant message
            self.add_tool_card(tool_text)

    def _on_failed(self, err: str):
        if self._cancel_flag.get("cancel"):
            return
        self._stop_thinking_animation()
        self.set_media_state(False)
        if self._pending_bubble:
            self._pending_bubble.setText(f"Error: {err}")
        else:
            self.add_bubble("echo", f"Error: {err}")

    # ---------- typewriter ----------
    def _typewriter(self, bubble: Bubble, full_text: str):
        # If empty, just show blank and bail
        if not full_text:
            bubble.setText("(no response)")
            return
        bubble.setText("")  # start empty
        idx = {"i": 0}
        self._type_timer = QTimer(self)
        def step():
            i = idx["i"]
            i += max(1, len(full_text)//200)  # speed scales with length
            if i >= len(full_text):
                bubble.setText(full_text)
                self._type_timer.stop()
            else:
                bubble.setText(full_text[:i])
                idx["i"] = i
            self.scroll_to_bottom()
        self._type_timer.timeout.connect(step)
        self._type_timer.start(18)  # smooth typing

    # ---------- tail ----------
    def refresh_tail(self):
        try:
            with THINK_LOG.open("r", encoding="utf-8", errors="ignore") as f:
                f.seek(0, os.SEEK_END)
                size = f.tell()
                chunk = 16000
                f.seek(max(0, size - chunk))
                raw = f.read()
        except FileNotFoundError:
            raw = "(no thinking yet)"

        if getattr(self, "_last_tail", None) == raw:
            return
        self._last_tail = raw
        self.tail.setPlainText(raw); self.tail.moveCursor(QTextCursor.End)

    # ---------- model controls ----------
    def refresh_models(self):
        names = get_installed_models()
        self.model_combo.clear()
        if not names:
            self.model_combo.addItem("(no models found)")
        else:
            for n in names:
                self.model_combo.addItem(n)
            idx = self.model_combo.findText(self.brain.model_name)
            if idx >= 0:
                self.model_combo.setCurrentIndex(idx)

    def set_active_model(self):
        name = self.model_combo.currentText().strip()
        if not name or name.startswith("("):
            self.add_bubble("echo", "No installed models found. Try pulling one."); return
        msg = self.brain.switch_model(name); self.add_bubble("echo", msg)

    # ---------- backend + pull ----------
    def start_backend_once(self):
        if not MAIN_PY.exists():
            self.add_bubble("echo", "Note: main.py not found next to echo_qt.py; skipping auto-run."); return
        os.environ["ECHO_LAUNCHED_FROM_UI"] = "1"
        try:
            QProcess.startDetached(sys.executable, [str(MAIN_PY), "--ui"], str(HERE))
            self.add_bubble("echo", "Started background brain.")
        except Exception as e:
            self.add_bubble("echo", f"Could not start main.py automatically: {e}")

    def pull_model_clicked(self):
        name = self.pull_edit.text().strip()
        if not name:
            self.add_bubble("echo", "Enter a model tag to pull, e.g., llama3:8b"); return
        self.add_bubble("echo", f"Pulling {name}…"); self.run_pull_process(name)

    def run_pull_process(self, name: str):
        self.pull_proc = QProcess(self)
        self.pull_proc.setProgram("ollama"); self.pull_proc.setArguments(["pull", name])
        self.pull_proc.setProcessChannelMode(QProcess.MergedChannels)
        self.pull_proc.readyReadStandardOutput.connect(
            lambda: self._on_pull_output(
                self.pull_proc.readAllStandardOutput().data().decode("utf-8", "ignore")
            )
        )
        self.pull_proc.finished.connect(lambda code, _status: self._on_pull_finished(code, name))
        try:
            self.pull_proc.start()
        except Exception:
            self.add_bubble("echo", "'ollama' not found in PATH. Install or add to PATH.")

    def _on_pull_output(self, text: str):
        text = text.strip()
        if text:
            self.add_bubble("echo", text)

    def _on_pull_finished(self, code: int, name: str):
        if code == 0:
            self.add_bubble("echo", f"Pull complete: {name}"); self.refresh_models()
        else:
            self.add_bubble("echo", f"Pull failed (exit {code}) for {name}")

# --------------------- app entry ---------------------
def main():
    app = QApplication(sys.argv)
    app.setFont(QFont("Inter", 11))
    app.setStyleSheet(DARK_QSS)
    win = EchoWindow()
    win.show()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()
