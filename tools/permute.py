#!/usr/bin/env python3
"""permute.py TARGET MODULE FILE FUNC BLOCK [CC1]: try every order of the
lines in BLOCK (a file holding consecutive lines of FILE) until FUNC matches
with fntest; keeps the first matching order in FILE (else restores it)."""
import itertools
import subprocess
import sys

t, m, f, func, blockfile = sys.argv[1:6]
cc1 = sys.argv[6] if len(sys.argv) > 6 else "1.6.1"
block = open(blockfile).read().strip("\n").split("\n")
orig = open(f).read()
src = "\n".join(block) + "\n"
assert src in orig, "block not found"
for p in itertools.permutations(block):
    open(f, "w").write(orig.replace(src, "\n".join(p) + "\n"))
    r = subprocess.run([sys.executable, "tools/fntest.py", t, m, f, "--cc1", cc1],
                       capture_output=True, text=True).stdout.strip().splitlines()[-1]
    if func + ":" not in r and "error" not in r:
        print("MATCH")
        print("\n".join(p))
        break
else:
    open(f, "w").write(orig)
    print("no match")
