#!/usr/bin/env python3
"""inventory.py: app (non-newlib/libgcc) units of every module, deduplicated.

Units whose functions are byte-identical (relocated fields masked) across
modules are the same object; they need decompiling once.  Writes
tmp/inventory.txt: hash  #copies  bytes  version  target/module:unit ...
"""
import collections
import hashlib
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import modules  # noqa: E402
import objcmp  # noqa: E402

groups = collections.defaultdict(list)
for t, mods in modules.targets().items():
    for m in mods:
        funcs = objcmp.module_funcs(t, m)
        for line in (ROOT / "config" / t / f"units.{m}.txt").read_text().splitlines():
            p = line.split()
            if len(p) != 3 or p[0].startswith(("#", "newlib/", "libgcc/")):
                continue
            u, ver = p[0], p[1]
            c = ROOT / "decomp_src" / t / m / f"{u}.c"
            fns = re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', c.read_text()) if c.exists() else []
            h = hashlib.sha1()
            size = 0
            for f in fns:
                w = funcs.get(f, [])
                size += 4 * len(w)
                h.update(f.encode() + b"".join(x.to_bytes(4, "little") for x in w))
            groups[(h.hexdigest()[:12], ver)].append((f"{t}/{m}:{u}", size, len(fns)))
with open(ROOT / "tmp" / "inventory.txt", "w") as f:
    for (h, ver), lst in sorted(groups.items(), key=lambda kv: -kv[1][0][1]):
        f.write(f"{h} {len(lst):3} {lst[0][1]:7} {lst[0][2]:4} {ver:15} " + " ".join(x[0] for x in lst) + "\n")
tot = collections.Counter()
for (h, ver), lst in groups.items():
    tot[ver, "units"] += 1
    tot[ver, "bytes"] += lst[0][1]
    tot[ver, "funcs"] += lst[0][2]
for k in sorted(tot):
    print(k, tot[k])
