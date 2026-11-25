#!/usr/bin/env python3
"""variants.py TARGET MODULE FILE FUNC VARIANTS [CC1]: VARIANTS is a Python
file defining V = {name: body}; each body replaces FUNC's body in FILE and
is tested with fntest.  The first matching body is kept (else FILE is
restored)."""
import re
import subprocess
import sys

t, m, f, func, vf = sys.argv[1:6]
cc1 = sys.argv[6] if len(sys.argv) > 6 else "1.6.1"
orig = open(f).read()
mm = re.search(r"^[^\n]*\b" + func + r"\([^)]*\)\n\{.*?^\}\n", orig, re.S | re.M)
assert mm, "function not found"
ns = {}
exec(open(vf).read(), ns)
hdr = mm.group(0).split("\n{", 1)[0]
keep = None
for k, v in ns["V"].items():
    s = orig[:mm.start()] + hdr + "\n{\n" + v.strip("\n") + "\n}\n" + orig[mm.end():]
    open(f, "w").write(s)
    r = subprocess.run([sys.executable, "tools/fntest.py", t, m, f, "--cc1", cc1],
                       capture_output=True, text=True).stdout.strip().splitlines()[-1]
    ok = func + ":" not in r and "error" not in r
    print(k, "MATCH" if ok else r)
    if ok and keep is None:
        keep = s
open(f, "w").write(keep or orig)
