# ui.py
import json
import subprocess
import threading
import time
import http.client
import tkinter as tk
from tkinter import ttk, messagebox
from pathlib import Path

from config import THINK_LOG, CURRENT_MODEL_FILE, DEFAULT_MODEL, APP_DIR

OLLAMA_HOST = ("127.0.0.1", 11434)

def get_installed_models():
    # GET /api/tags (Ollama)
    try:
        conn = http.client.HTTPConnection(*OLLAMA_HOST, timeout=5)
        conn.request("GET", "/api/tags")
        resp = conn.getresponse()
        data = resp.read()
        conn.close()
        if resp.status != 200:
            return []
        payload = json.loads(data)
        # payload: {"models":[{"name":"llama3:8b", ...}, ...]}
        return [m.get("name","").strip() for m in payload.get("models", []) if m.get("name")]
    except Exception:
        return []

def pull_model(name: str, on_line):
    """
    Streams 'ollama pull <name>' output to on_line callback.
    """
    if not name:
        on_line("[pull] enter a model name (e.g., llama3:8b)")
        return
    try:
        # Use shell=True on Windows so 'ollama' is found in PATH
        cmd = ["ollama", "pull", name]
        proc = subprocess.Popen(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True, shell=True)
        for line in proc.stdout:
            on_line(line.rstrip("\n"))
        code = proc.wait()
        if code == 0:
            on_line(f"[pull] done: {name}")
        else:
            on_line(f"[pull] failed (exit {code}) for {name}")
    except FileNotFoundError:
        on_line("[pull] 'ollama' not found in PATH")
    except Exception as e:
        on_line(f"[pull] error: {e}")

def write_active_model(name: str):
    CURRENT_MODEL_FILE.write_text(name.strip(), encoding="utf-8")

class EchoUI(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Echo Control Panel")
        self.geometry("820x520")
        self.minsize(760, 480)

        # ---- left: model box ----
        left = ttk.Frame(self, padding=10)
        left.pack(side=tk.LEFT, fill=tk.Y)

        ttk.Label(left, text="Installed models").pack(anchor="w")
        self.models_var = tk.StringVar(value=[])
        self.listbox = tk.Listbox(left, listvariable=self.models_var, height=12, width=28)
        self.listbox.pack(fill=tk.Y, expand=False)

        btnrow = ttk.Frame(left); btnrow.pack(fill=tk.X, pady=(6,0))
        ttk.Button(btnrow, text="Refresh", command=self.refresh_models).pack(side=tk.LEFT)
        ttk.Button(btnrow, text="Set Active", command=self.set_active_from_list).pack(side=tk.LEFT, padx=6)

        # pull area
        ttk.Separator(left, orient=tk.HORIZONTAL).pack(fill=tk.X, pady=10)
        ttk.Label(left, text="Pull model (e.g., llama3:8b)").pack(anchor="w")
        self.pull_entry = ttk.Entry(left, width=25)
        self.pull_entry.pack(anchor="w")
        ttk.Button(left, text="Pull", command=self.on_pull_clicked).pack(anchor="w", pady=4)

        # active model status
        self.active_var = tk.StringVar(value=f"Active: {self.read_active_model()}")
        ttk.Label(left, textvariable=self.active_var, font=("Segoe UI", 10, "bold")).pack(anchor="w", pady=(10,0))

        # pull output
        ttk.Label(left, text="Pull output").pack(anchor="w", pady=(10,0))
        self.pull_out = tk.Text(left, height=12, width=32)
        self.pull_out.pack(fill=tk.BOTH, expand=True)

        # ---- right: thinking log ----
        right = ttk.Frame(self, padding=10)
        right.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        ttk.Label(right, text="Thinking (tail)").pack(anchor="w")
        self.log_view = tk.Text(right, state=tk.DISABLED)
        self.log_view.pack(fill=tk.BOTH, expand=True)

        # start timers
        self.refresh_models()
        self.after(800, self.refresh_tail)

    # helpers
    def read_active_model(self) -> str:
        try:
            return CURRENT_MODEL_FILE.read_text(encoding="utf-8").strip()
        except Exception:
            return DEFAULT_MODEL

    def refresh_models(self):
        names = get_installed_models()
        if not names:
            names = ["(no models found)"]
        self.models_var.set(names)

    def set_active_from_list(self):
        sel = self.listbox.curselection()
        if not sel:
            messagebox.showinfo("Echo", "Pick a model from the list.")
            return
        name = self.listbox.get(sel[0])
        if name.startswith("("):
            return
        write_active_model(name)
        self.active_var.set(f"Active: {name}")

    def on_pull_clicked(self):
        name = self.pull_entry.get().strip()
        if not name:
            messagebox.showinfo("Echo", "Enter a model name to pull (e.g., llama3:8b).")
            return
        threading.Thread(target=pull_model, args=(name, self.append_pull_line), daemon=True).start()

    def append_pull_line(self, line: str):
        self.pull_out.insert(tk.END, line + "\n")
        self.pull_out.see(tk.END)

    def refresh_tail(self):
        try:
            text = THINK_LOG.read_text(encoding="utf-8")
        except FileNotFoundError:
            text = "(no thinking yet)"
        self.log_view.config(state=tk.NORMAL)
        self.log_view.delete("1.0", tk.END)
        self.log_view.insert(tk.END, text[-8000:])  # last ~8KB
        self.log_view.config(state=tk.DISABLED)
        self.after(800, self.refresh_tail)

if __name__ == "__main__":
    # Make sure app dir exists
    APP_DIR.mkdir(exist_ok=True)
    EchoUI().mainloop()
