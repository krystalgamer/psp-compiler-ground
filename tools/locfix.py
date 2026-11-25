#!/usr/bin/env python3
"""locfix.py FILE.s [OUT.s]: make the 1.3.1 psp-as fill branch delay slots
like the assembler of psp-gcc 1.6.1 and later did for code built with -g.

In .set reorder mode psp-as moves the instruction before a branch into its
delay slot.  The later assembler does not do this when a .loc directive (a
new source line) lies between the two: there the slot keeps its nop.  A
label on the branch stops the 1.3.1 psp-as from swapping in the same way,
so one is put before every such branch (local $L labels make no symbols).
"""
import re
import sys

BRANCH = re.compile(r"\s+(b[a-z0-9.]*|j|jal|jalr|jr)\s")


def fix(text):
    out, reorder, pending, n = [], True, False, 0
    for ln in text.splitlines(keepends=True):
        s = ln.strip()
        if re.match(r"\.set\s+noreorder\b", s):
            reorder = False
        elif re.match(r"\.set\s+reorder\b", s):
            reorder = True
        if s.startswith(".loc"):
            pending = True
        elif s and not s.startswith((".", "#")) and not s.endswith(":"):
            if pending and reorder and BRANCH.match(ln) and not s.startswith("break"):
                out.append(f"$Lloc{n}:\n")
                n += 1
            pending = False
        out.append(ln)
    return "".join(out)


if __name__ == "__main__":
    src = sys.argv[1]
    dst = sys.argv[2] if len(sys.argv) > 2 else src
    t = fix(open(src).read())
    open(dst, "w").write(t)
