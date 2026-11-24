#!/usr/bin/env python3
"""m2c.py TARGET MODULE UNIT FUNC [m2c args...]: m2c draft of a function.

The unit's DWARF declarations (tools/dwarf2c.py) are the context, so m2c
knows the real types, globals and prototypes.  INCLUDE_ASM files use
numeric registers (for old psp-as); m2c wants ABI names.
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
# PSP EABI: $8-$11 are argument registers, which m2c's mipsee names a4-a7
ABI = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
       "a4", "a5", "a6", "a7", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
       "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]


def draft(target, module, unit, func, extra=()):
    asm = ROOT / "tmp/asm" / target / module / "nonmatchings" / unit / f"{func}.s"
    text = re.sub(r"\$(\d+)\b", lambda m: "$" + ABI[int(m[1])] if int(m[1]) < 32 else m[0], asm.read_text())
    ctx = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), target, module, unit],
                         capture_output=True, text=True, check=True).stdout
    with tempfile.TemporaryDirectory() as td:
        (Path(td) / "f.s").write_text(text)
        (Path(td) / "ctx.c").write_text(ctx)
        r = subprocess.run([sys.executable, str(ROOT / "tools/m2c_allegrex.py"), "-t", "mipsee-gcc-c",
                            "--context", str(Path(td) / "ctx.c"), *extra, str(Path(td) / "f.s")],
                           capture_output=True, text=True)
    return r.stdout if r.returncode == 0 else None, r.stderr


if __name__ == "__main__":
    out, err = draft(*sys.argv[1:5], sys.argv[5:])
    sys.stdout.write(out or "")
    sys.stderr.write(err)
