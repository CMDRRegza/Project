import json
from config import MEM_PATH


def load_mem():
    if MEM_PATH.exists():
        return json.loads(MEM_PATH.read_text(encoding="utf-8"))
    return {"facts": {}, "goals": []}

def save_mem(mem: dict):
    MEM_PATH.write_text(json.dumps(mem, ensure_ascii=False, indent=2), encoding="utf-8")
