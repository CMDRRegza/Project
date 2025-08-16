# policy.py
from pathlib import Path

# Allowed write roots (relative to your app working dir)
ALLOWED_WRITE_ROOTS = [Path("notes"), Path("tmp"), Path("scratchpad")]

# For safety; extend as needed
FORBIDDEN_EXTENSIONS = {".exe", ".bat", ".cmd", ".ps1", ".dll", ".sys", ".msi", ".scr", ".vbs", ".js"}
MAX_FILE_BYTES = 64 * 1024  # 64 KB cap for tool writes by default

# Allow/deny via env (optional)
import os
ALLOW_WRITES = os.environ.get("ECHO_ALLOW_TOOL_WRITES", "1") not in ("0", "false", "False")
