# echo_qt.py
import sys, os, json, http.client
from pathlib import Path

from PySide6.QtCore import Qt, QTimer, QProcess, QSettings, QEvent, QObject, Signal, QRunnable, QThreadPool, QSize
from PySide6.QtWidgets import (
    QApplication, QMainWindow, QWidget, QSplitter, QVBoxLayout, QHBoxLayout,
    QLabel, QLineEdit, QScrollArea, QComboBox, QFrame, QToolButton, QTextEdit
)
from PySide6.QtGui import QTextCursor

from theme import DARK_QSS, default_font
from brain_wrapper import EchoBrain
from ui_bubbles import Bubble, make_row, tool_card, start_dots, typewriter
import json

def _extract_chat_and_tool(reply: str) -> tuple[str, str | None]:
    """
    Accepts either:
      - our combined string: "chat...\n<<TOOL_CARD>>\n<tool text>"
      - a pure JSON string: {"thought": "...", "chat": "...", "action": {...}}
      - plain text
    Returns (chat_text, tool_text_or_None)
    """
    # 1) our sentinel path
    if "\n<<TOOL_CARD>>\n" in reply:
        msg, tool_text = reply.split("\n<<TOOL_CARD>>\n", 1)
        return msg.strip(), tool_text.strip()

    # 2) JSON string from model/backend
    try:
        data = json.loads(reply)
        if isinstance(data, dict):
            chat = (data.get("chat") or data.get("say") or "").strip()
            return (chat if chat else reply.strip()), None
    except Exception:
        pass

    # 3) plain text
    return reply.strip(), None


HERE = Path(__file__).resolve().parent
MAIN_PY = HERE / "main.py"

# ---- async worker ----
class BrainTaskSignals(QObject):
    finished = Signal(str)
    failed = Signal(str)

class BrainTask(QRunnable):
    def __init__(self, brain: EchoBrain, text: str, cancel_flag: dict):
        super().__init__(); self.brain=brain; self.text=text; self.cancel_flag=cancel_flag; self.signals=BrainTaskSignals()
    def run(self):
        try:
            if self.cancel_flag.get("cancel"): return
            reply = self.brain.process(self.text)
            if self.cancel_flag.get("cancel"): return
            self.signals.finished.emit(reply)
        except Exception as e:
            self.signals.failed.emit(str(e))

# ---- main window ----
class EchoWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Echo — Chat"); self.resize(1080, 740)
        self.thread_pool = QThreadPool.globalInstance()
        self.settings = QSettings("EchoProject", "EchoQt")
        if self.settings.value("geometry"): self.restoreGeometry(self.settings.value("geometry"))
        if self.settings.value("windowState"): self.restoreState(self.settings.value("windowState"))

        # state that must exist BEFORE any bubble is added
        self._all_bubbles: list[Bubble] = []     # <-- FIX: init early
        self._running = False
        self._cancel_flag = {"cancel": False}
        self._anim_timer = None
        self._pending_bubble: Bubble | None = None
        self._type_timer = None

        self.brain = EchoBrain()

        splitter = QSplitter(Qt.Horizontal); self.setCentralWidget(splitter)

        # left column
        left = QWidget(); lv = QVBoxLayout(left); lv.setContentsMargins(12,12,12,12); lv.setSpacing(10)

        # controls
        top_row = QHBoxLayout(); lv.addLayout(top_row)
        self.model_combo = QComboBox(); self.refresh_models()
        self.model_combo.setEditable(False); self.model_combo.setSizeAdjustPolicy(QComboBox.AdjustToContents)
        top_row.addWidget(QLabel("Model")); top_row.addWidget(self.model_combo, 1)
        btn_refresh = QToolButton(); btn_refresh.setText("↻"); btn_refresh.clicked.connect(self.refresh_models); top_row.addWidget(btn_refresh)
        btn_set = QToolButton(); btn_set.setText("✓"); btn_set.clicked.connect(self.set_active_model); top_row.addWidget(btn_set)

        # pull
        self.pull_edit = QLineEdit(); self.pull_edit.setPlaceholderText("Pull model (e.g., llama3:8b)")
        btn_pull = QToolButton(); btn_pull.setText("⇣"); btn_pull.clicked.connect(self.pull_model_clicked)
        row2 = QHBoxLayout(); lv.addLayout(row2); row2.addWidget(self.pull_edit, 1); row2.addWidget(btn_pull)

        # chat area
        self.scroll_area = QScrollArea(); self.scroll_area.setWidgetResizable(True)
        self.chat_holder = QWidget()
        self.chat_layout = QVBoxLayout(self.chat_holder); self.chat_layout.setSpacing(0); self.chat_layout.addStretch(1)
        self.scroll_area.setWidget(self.chat_holder)
        lv.addWidget(self.scroll_area, 1)

        # input + media button
        in_row = QHBoxLayout()
        self.input = QLineEdit(); self.input.setPlaceholderText("Type anything… (Echo will reply and use tools automatically)")
        self.input.returnPressed.connect(self.media_clicked); self.input.installEventFilter(self)
        in_row.addWidget(self.input, 1)
        self.media_btn = QToolButton(); self.media_btn.setObjectName("Media"); self.media_btn.setFixedSize(QSize(56,56))
        self.media_btn.setText("↑"); self.media_btn.setToolTip("Send"); self.media_btn.clicked.connect(self.media_clicked)
        in_row.addWidget(self.media_btn, 0, Qt.AlignRight)
        lv.addLayout(in_row)

        splitter.addWidget(left)

        # right column (tail)
        right = QWidget(); rv = QVBoxLayout(right); rv.setContentsMargins(12,12,12,12); rv.setSpacing(10)
        rv.addWidget(QLabel("Thinking (live tail)"))
        self.tail = QTextEdit(); self.tail.setReadOnly(True); self.tail.setLineWrapMode(QTextEdit.NoWrap)
        rv.addWidget(self.tail, 1)
        splitter.addWidget(right); splitter.setSizes([720, 360])

        # timers
        self.tail_timer = QTimer(self); self.tail_timer.timeout.connect(self.refresh_tail); self.tail_timer.start(900)

        # optional greeting (static UI line). Remove if you don't want it:
        self.add_bubble("echo", "Hello! 👋 How can I help you today?")

        # start backend after state is ready
        self.start_backend_once()

    # sizing
    def bubble_max_width(self) -> int:
        vp = self.scroll_area.viewport()
        if not vp:
            return 1600
        w = int(vp.width() * 0.97)     # 97% of the viewport
        return max(600, min(1600, w))  # generous clamp


    def resizeEvent(self, e):
        super().resizeEvent(e)
        for b in self._all_bubbles: b.refreshWidth()

    # keyboard
    def eventFilter(self, obj, event):
        if obj is self.input and event.type() == QEvent.KeyPress:
            if (event.key() in (Qt.Key_Return, Qt.Key_Enter)) and (event.modifiers() & Qt.ControlModifier):
                self.media_clicked(); return True
        return super().eventFilter(obj, event)

    # bubble helpers
    def add_bubble(self, role: str, text: str) -> Bubble:
        bub = Bubble(role, self.bubble_max_width); bub.setText(text)
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
        self.scroll_area.verticalScrollBar().setValue(self.scroll_area.verticalScrollBar().maximum())

    # media button
    def set_media_state(self, running: bool):
        self._running = running
        if running: self.media_btn.setText("■"); self.media_btn.setToolTip("Stop")
        else:       self.media_btn.setText("↑"); self.media_btn.setToolTip("Send")
    def media_clicked(self):
        if self._running: self.stop_current()
        else:             self.on_send()

    # send pipeline
    def on_send(self):
        text = self.input.text().strip()
        if not text: return
        self.input.clear()
        self.add_bubble("you", text)
        self._pending_bubble = self.add_bubble("echo", "Thinking")
        self._anim_timer = start_dots(self._pending_bubble.label)
        self._cancel_flag = {"cancel": False}
        task = BrainTask(self.brain, text, self._cancel_flag)
        task.signals.finished.connect(self._on_finished)
        task.signals.failed.connect(self._on_failed)
        self.set_media_state(True)
        self.thread_pool.start(task)

    def stop_current(self):
        try:
            self.brain.llm.cancel()
        except Exception:
            pass
        if not self._running: return
        self._cancel_flag["cancel"] = True
        if self._anim_timer: self._anim_timer.stop(); self._anim_timer = None
        if self._pending_bubble: self._pending_bubble.setText("(stopped)")
        self.set_media_state(False)

    # finish handlers
    def _on_finished(self, reply: str) -> None:
        if self._cancel_flag.get("cancel"):
            return
        if self._anim_timer:
            self._anim_timer.stop()
            self._anim_timer = None
        self.set_media_state(False)

        msg, tool_text = _extract_chat_and_tool(reply)

        if self._pending_bubble:
            from ui_bubbles import typewriter
            typewriter(self._pending_bubble, msg)
        else:
            self.add_bubble("echo", msg)

        if tool_text:
            self.add_tool_card(tool_text)

    def _on_failed(self, err: str) -> None:
        if self._cancel_flag.get("cancel"):
            return
        if self._anim_timer:
            self._anim_timer.stop()
            self._anim_timer = None
        self.set_media_state(False)
        if self._pending_bubble:
            self._pending_bubble.setText(f"Error: {err}")
        else:
            self.add_bubble("echo", f"Error: {err}")

    # tail
    def refresh_tail(self):
        from config import THINK_LOG
        try:
            with THINK_LOG.open("r", encoding="utf-8", errors="ignore") as f:
                f.seek(0, os.SEEK_END); size = f.tell(); chunk = 16000
                f.seek(max(0, size - chunk)); raw = f.read()
        except FileNotFoundError:
            raw = "(no thinking yet)"
        if getattr(self, "_last_tail", None) == raw: return
        self._last_tail = raw; self.tail.setPlainText(raw); self.tail.moveCursor(QTextCursor.End)

    # model controls
    def refresh_models(self):
        from brain_wrapper import http, json as _json  # not actually needed; kept minimal
        try:
            conn = http.client.HTTPConnection("127.0.0.1", 11434, timeout=3)
            conn.request("GET", "/api/tags"); resp = conn.getresponse(); data = resp.read(); conn.close()
            names = [m.get("name","").strip() for m in _json.loads(data).get("models", []) if m.get("name")] if resp.status==200 else []
        except Exception:
            names = []
        self.model_combo.clear()
        if not names: self.model_combo.addItem("(no models found)")
        else:
            for n in names: self.model_combo.addItem(n)
            idx = self.model_combo.findText(self.brain.model_name)
            if idx >= 0: self.model_combo.setCurrentIndex(idx)

    def set_active_model(self):
        name = self.model_combo.currentText().strip()
        if not name or name.startswith("("):
            self.add_bubble("echo","No installed models found. Try pulling one."); return
        msg = self.brain.switch_model(name); self.add_bubble("echo", msg)

    # backend + pull
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
        if not name: self.add_bubble("echo","Enter a model tag to pull, e.g., llama3:8b"); return
        self.add_bubble("echo", f"Pulling {name}…")
        self.pull_proc = QProcess(self)
        self.pull_proc.setProgram("ollama"); self.pull_proc.setArguments(["pull", name])
        self.pull_proc.setProcessChannelMode(QProcess.MergedChannels)
        self.pull_proc.readyReadStandardOutput.connect(lambda: self.add_bubble("echo",
            self.pull_proc.readAllStandardOutput().data().decode("utf-8","ignore").strip()))
        self.pull_proc.finished.connect(lambda code,_: (self.add_bubble("echo", f"Pull complete: {name}") if code==0
                                                        else self.add_bubble("echo", f"Pull failed (exit {code}) for {name}")))
        try: self.pull_proc.start()
        except Exception: self.add_bubble("echo", "'ollama' not found in PATH. Install or add to PATH.")

def main():
    from theme import DARK_QSS, default_font
    app = QApplication(sys.argv)
    app.setFont(default_font())
    app.setStyleSheet(DARK_QSS)
    win = EchoWindow(); win.show()
    sys.exit(app.exec())

if __name__ == "__main__":
    main()
