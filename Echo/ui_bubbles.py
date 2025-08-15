# ui_bubbles.py
from PySide6.QtCore import Qt, QTimer
from PySide6.QtWidgets import QFrame, QLabel, QVBoxLayout, QWidget, QHBoxLayout

class Bubble(QFrame):
    def __init__(self, role: str, max_width_provider):
        super().__init__()
        self.setObjectName("Bubble")
        self.role = role
        self.max_width_provider = max_width_provider
        self.setFrameShape(QFrame.NoFrame)
        lay = QVBoxLayout(self); lay.setContentsMargins(12, 8, 12, 8)
        self.label = QLabel(""); self.label.setWordWrap(True)
        self.label.setTextInteractionFlags(Qt.TextSelectableByMouse)
        if role == "you":
            self.label.setStyleSheet("font-size:14px; color:#e5e7eb; background:#2563eb; padding:12px; border-radius:16px;")
        else:
            self.label.setStyleSheet("font-size:14px; color:#e5e7eb; background:#111827; padding:12px; border-radius:16px; border:1px solid #1f2937;")
        lay.addWidget(self.label)

    def setText(self, text: str):
        self.label.setText(text)
        self.refreshWidth()

    def refreshWidth(self):
        mw = int(self.max_width_provider() or 640)
        self.label.setMaximumWidth(mw)
        self.label.adjustSize()

def make_row(widget: QWidget, align: str) -> QWidget:
    row = QWidget()
    h = QHBoxLayout(row)
    h.setContentsMargins(4, 8, 4, 8)  # was (0, 6, 0, 6)
    if align == "right":
        h.addStretch(1)
        h.addWidget(widget, 0)
    else:
        h.addWidget(widget, 0)
        h.addStretch(1)
    return row


def tool_card(text: str, max_width_provider) -> QWidget:
    card = QFrame(); card.setObjectName("ToolCard")
    lay = QVBoxLayout(card); lay.setContentsMargins(12, 10, 12, 10)
    lbl = QLabel(text.strip()); lbl.setWordWrap(True); lbl.setTextInteractionFlags(Qt.TextSelectableByMouse)
    lay.addWidget(lbl)
    lbl.setMaximumWidth(int(max_width_provider() or 640)); lbl.adjustSize()
    return make_row(card, "left")

def start_dots(label: QLabel):
    timer = QTimer(label)
    state = {"n": 0}
    def tick():
        state["n"] = (state["n"] + 1) % 4
        label.setText("Thinking" + "." * state["n"])
    timer.timeout.connect(tick); timer.start(350)
    return timer

def typewriter(bubble: Bubble, full_text: str):
    if not full_text:
        bubble.setText("(no response)"); return None
    bubble.setText("")
    idx = {"i": 0}
    timer = QTimer(bubble)
    def step():
        i = idx["i"]
        i += max(1, len(full_text)//200)
        if i >= len(full_text):
            bubble.setText(full_text); timer.stop()
        else:
            bubble.setText(full_text[:i]); idx["i"] = i
    timer.timeout.connect(step); timer.start(18)
    return timer
