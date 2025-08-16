from pathlib import Path

APP_DIR = Path(__file__).parent
ALLOWED_ROOT = (APP_DIR / "sandbox").resolve()
ALLOWED_ROOT.mkdir(exist_ok=True)

MEM_PATH = APP_DIR / "memory.json"
THINK_LOG = APP_DIR / "thinking.log"
ECHO_NAME = "Echo"

# ---- model selection (UI writes to this) ----
CURRENT_MODEL_FILE = APP_DIR / "current_model.txt"
DEFAULT_FAST  = "llama3:8b"      # choose any small model you’ll pull
DEFAULT_SMART = "gpt-oss:20b"    # your installed big model
DEFAULT_MODEL = DEFAULT_SMART    # start with this if file missing

if not CURRENT_MODEL_FILE.exists():
    CURRENT_MODEL_FILE.write_text(DEFAULT_MODEL, encoding="utf-8")
