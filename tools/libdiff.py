#!/usr/bin/env python3
"""libdiff.py TARGET MODULE UNIT [--cc1 NAME] [--func FN] [--as OPTS]: compile a newlib
or libgcc unit from its original source as tools/libsrc.py does (optionally
with another cc1) and print each function's result, with the side-by-side
disassembly of the first differing function (or of FN)."""
import argparse
import re
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import compiler  # noqa: E402
import libsrc  # noqa: E402
import objcmp  # noqa: E402

ap = argparse.ArgumentParser()
ap.add_argument("target")
ap.add_argument("module")
ap.add_argument("unit")
ap.add_argument("--cc1")
ap.add_argument("--func")
ap.add_argument("--locfix", action="store_true",
                help="compile with -g; no delay-slot swap across a .loc (tmp/x18/locfix.py)")
ap.add_argument("--as", dest="asf", default="", help="extra psp-as options")
a = ap.parse_args()
if a.asf or a.locfix:
    _run = libsrc.subprocess.run

    def run(cmd, *k, **kw):
        if str(cmd[0]).endswith("psp-as"):
            if a.locfix:
                _run([sys.executable, str(libsrc.ROOT / "tmp/x18/locfix.py"), cmd[-1], cmd[-1]])
            cmd = [cmd[0], *a.asf.split(), *cmd[1:]]
        elif "/cc1-" in str(cmd[0]) and a.locfix:
            cmd = [cmd[0], "-g", *cmd[1:]]
        return _run(cmd, *k, **kw)
    libsrc.subprocess.run = run
if a.cc1:
    compiler.compiler = lambda *_: a.cc1
    libsrc.compiler.compiler = compiler.compiler
units = compiler.table(libsrc.ROOT / "config" / a.target / f"units.{a.module}.txt")
src = units[a.unit][1]
f = libsrc.ROOT / "decomp_src" / a.target / a.module / f"{a.unit}.c"
want = set(re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', f.read_text()))
if a.unit.startswith("libgcc/"):
    rel, base = None, libsrc.libgcc_wrapper(a.target, a.module, a.unit, want)
else:
    rel, base = src.split("newlib-1.12.0/newlib/")[1], None
    if "/mallocr/" in a.unit and not rel.endswith("mallocr.c"):
        rel = str(Path(rel).parent / "mallocr.c")
text = libsrc.wrapper(rel, a.unit, base=base)
with tempfile.TemporaryDirectory(dir=libsrc.ROOT / "tmp") as td:
    o = libsrc.build(a.target, a.module, a.unit, text, td)
    if o is None:
        sys.exit("build failed")
    res = objcmp.compare(objcmp.module_funcs(a.target, a.module), [o], a.func or True)
for fn in sorted(res):
    print(f"{res[fn]:14} {fn}")
