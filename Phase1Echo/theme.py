# theme.py
from PySide6.QtGui import QFont

DARK_QSS = """
* { font-family: 'Inter', 'Segoe UI', Arial, sans-serif; font-size: 14px; }
QMainWindow, QWidget { background-color: #0b0f14; color: #e5e7eb; }
QLabel { color: #d1d5db; }
QFrame#Bubble { background-color: #111827; border: 1px solid #1f2937; border-radius: 16px; }
QFrame#ToolCard { background-color: #0f1720; border: 1px dashed #334155; border-radius: 12px; }
QLineEdit, QComboBox, QScrollArea {
  background-color: #0f1720; color: #e5e7eb;
  border: 1px solid #1f2937; border-radius: 10px; padding: 10px;
}
QToolButton#Media { background: #0f0f12; color: #e5e7eb; border-radius: 28px; border: 1px solid #2b2f3a; font-weight: 700; }
QToolButton#Media:hover { background: #161922; }
QToolButton#Media:pressed { background: #0d0f15; }
QComboBox QAbstractItemView { background: #0f1720; color: #e5e7eb; selection-background-color: #334155; border: 1px solid #1f2937; outline: 0; }
QScrollBar:vertical { background: #0f1720; width: 10px; margin: 0; }
QScrollBar::handle:vertical { background: #263241; min-height: 24px; border-radius: 5px; }
"""

def default_font():
    return QFont("Inter", 11)
