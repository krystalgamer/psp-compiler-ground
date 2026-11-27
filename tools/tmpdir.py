"""Scratch files of the tools go to the repository's tmp/ (not /tmp):
importing this sets TMPDIR (unless already set) before tempfile is used;
child processes inherit it."""
import os
from pathlib import Path

if not os.environ.get("TMPDIR"):
    d = Path(__file__).resolve().parent.parent / "tmp" / "tmpd"
    d.mkdir(parents=True, exist_ok=True)
    os.environ["TMPDIR"] = str(d)
