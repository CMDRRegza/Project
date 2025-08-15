from datetime import datetime
from config import THINK_LOG


def _stamp():
    return datetime.now().strftime("%Y-%m-%d %H:%M:%S")

def log_thought(text: str):
    THINK_LOG.parent.mkdir(exist_ok=True)
    with THINK_LOG.open("a", encoding="utf-8") as f:
        f.write(f"[{_stamp()}] {text}\n")

def tail_thoughts(n=6):
    if not THINK_LOG.exists():
        return []
    return THINK_LOG.read_text(encoding="utf-8").splitlines()[-n:]

def clear_thoughts():
    THINK_LOG.unlink(missing_ok=True)
