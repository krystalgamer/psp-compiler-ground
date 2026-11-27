#!/usr/bin/env python3
"""cc1name.py NAME CC1 ARGS...: run CC1 on the preprocessed source read from
stdin as if it were the file NAME (a unit's `/* srcname: NAME */`).

cc1 names things after its input file: a C++ object with no public symbol
gets its static constructor named `_GLOBAL__I_<file><random>`.  Piped input
is `<stdin>`, so the text is written to NAME (relative, as on the original
command line, e.g. ../lib/glutils/Query.cpp) under a scratch directory and
cc1 runs from there."""
import os
import subprocess
import sys
import tempfile
from pathlib import Path

name, cmd = sys.argv[1], sys.argv[2:]
# output paths are relative to the caller's directory
cmd = [os.path.abspath(cmd[0]) if "/" in cmd[0] else cmd[0]] + [os.path.abspath(a) if p == "-o" else a for p, a in zip(cmd, cmd[1:])]
up = sum(1 for part in Path(name).parts if part == "..")
with tempfile.TemporaryDirectory(dir=os.environ.get("TMPDIR")) as td:
    cwd = Path(td, *(["w"] * up))
    cwd.mkdir(parents=True, exist_ok=True)
    src = Path(os.path.normpath(cwd / name))
    src.parent.mkdir(parents=True, exist_ok=True)
    src.write_bytes(sys.stdin.buffer.read())
    sys.exit(subprocess.run(cmd + ["-fpreprocessed", name], cwd=cwd).returncode)
