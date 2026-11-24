#!/usr/bin/env python3
"""drafts.py TARGET MODULE UNIT: write tmp/work/TARGET/MODULE/UNIT.c, the
unit's DWARF context followed by m2c's draft of each function, as a start."""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp  # noqa: E402
import m2c as m2cdraft  # noqa: E402

t, m, u = sys.argv[1:4]
ctx = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), t, m, u, "--extern", "--locals"],
                     capture_output=True, text=True, check=True).stdout
src = (ROOT / "decomp_src" / t / m / f"{u}.c").read_text()
funcs = re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', src)
out = ['#include "common.h"', "", ctx, ""]
for f in funcs:
    d, err = m2cdraft.draft(t, m, u, f)
    out.append(autodecomp.clean(d) if d else f"/* m2c failed for {f}: {err.strip()[:200]} */")
    out.append("")
p = ROOT / "tmp" / "work" / t / m / f"{u}.c"
p.parent.mkdir(parents=True, exist_ok=True)
p.write_text("\n".join(out))
print(p)
