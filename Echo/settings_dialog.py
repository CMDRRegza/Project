# settings_dialog.py

from PySide6.QtCore import QSettings
from PySide6.QtWidgets import (
    QDialog, QVBoxLayout, QHBoxLayout, QLabel, QLineEdit, QCheckBox,
    QSlider, QPushButton, QWidget, QFormLayout
)
from PySide6.QtCore import Qt

ORG_NAME = "EchoProject"
APP_NAME = "EchoApp"

_DEFAULTS = {
    "prefer_gpu": True,
    "bubble_width_pct": 97,           # 50..100
    "ollama_host": "127.0.0.1",
    "ollama_port": "11434",
    "default_model": "",
    "allow_tool_writes": True,
    "autostart_brain": True,
}


def load_settings() -> dict:
    s = QSettings(ORG_NAME, APP_NAME)
    out = {}
    for k, v in _DEFAULTS.items():
        out[k] = s.value(k, v, type=type(v))
    return out


def save_settings(values: dict) -> None:
    s = QSettings(ORG_NAME, APP_NAME)
    for k, v in values.items():
        s.setValue(k, v)


class SettingsDialog(QDialog):
    def __init__(self, parent: QWidget | None = None):
        super().__init__(parent)
        self.setWindowTitle("Settings")
        self.setMinimumWidth(420)

        self._vals = load_settings()

        form = QFormLayout()

        self.chk_gpu = QCheckBox("Prefer GPU")
        self.chk_gpu.setChecked(bool(self._vals["prefer_gpu"]))
        form.addRow(self.chk_gpu)

        row_bw = QHBoxLayout()
        self.sld_bw = QSlider()
        self.sld_bw.setOrientation(Qt.Horizontal)  # 1 = Qt.Horizontal
        self.sld_bw.setMinimum(50)
        self.sld_bw.setMaximum(100)
        self.sld_bw.setValue(int(self._vals["bubble_width_pct"]))
        self.lbl_bw = QLabel(f"{self._vals['bubble_width_pct']}%")
        self.sld_bw.valueChanged.connect(lambda v: self.lbl_bw.setText(f"{v}%"))
        row_bw.addWidget(self.sld_bw, 1)
        row_bw.addWidget(self.lbl_bw)
        form.addRow(QLabel("Bubble width"), row_bw)

        self.ed_host = QLineEdit(self._vals["ollama_host"])
        form.addRow("Ollama host", self.ed_host)

        self.ed_port = QLineEdit(self._vals["ollama_port"])
        form.addRow("Ollama port", self.ed_port)

        self.ed_model = QLineEdit(self._vals["default_model"])
        form.addRow("Default model (optional)", self.ed_model)

        self.chk_writes = QCheckBox("Allow tool writes")
        self.chk_writes.setChecked(bool(self._vals["allow_tool_writes"]))
        form.addRow(self.chk_writes)

        self.chk_autostart = QCheckBox("Auto-start background brain")
        self.chk_autostart.setChecked(bool(self._vals["autostart_brain"]))
        form.addRow(self.chk_autostart)

        btns = QHBoxLayout()
        ok = QPushButton("OK"); cancel = QPushButton("Cancel")
        ok.clicked.connect(self.accept); cancel.clicked.connect(self.reject)
        btns.addStretch(1); btns.addWidget(cancel); btns.addWidget(ok)

        root = QVBoxLayout(self)
        root.addLayout(form)
        root.addLayout(btns)

    def values(self) -> dict:
        return {
            "prefer_gpu": bool(self.chk_gpu.isChecked()),
            "bubble_width_pct": int(self.sld_bw.value()),
            "ollama_host": self.ed_host.text().strip() or "127.0.0.1",
            "ollama_port": self.ed_port.text().strip() or "11434",
            "default_model": self.ed_model.text().strip(),
            "allow_tool_writes": bool(self.chk_writes.isChecked()),
            "autostart_brain": bool(self.chk_autostart.isChecked()),
        }

    def accept(self) -> None:
        save_settings(self.values())
        super().accept()
