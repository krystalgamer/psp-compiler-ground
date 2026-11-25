#!/usr/bin/env python3
"""firstdiff.py TARGET MODULE [N]: where the built module differs from the
original: the first N differing ranges with the nearest preceding symbol."""
import bisect
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
t, m = sys.argv[1:3]
n = int(sys.argv[3]) if len(sys.argv) > 3 else 10
a = (ROOT / "tmp/baserom" / t / f"{m}.prx").read_bytes()
b = (ROOT / "tmp/build" / t / f"{m}.prx").read_bytes()
if len(a) != len(b):
    print(f"size {len(b):#x} vs original {len(a):#x}")
cfg = (ROOT / "config" / t / f"{m}.yaml").read_text()
off0 = int(re.search(r"type: code\n    start: 0x([0-9A-F]+)", cfg)[1], 16)
syms = []
for line in (ROOT / "config" / t / f"symbol_addrs.{m}.txt").read_text().splitlines():
    mm = re.match(r"(\w+) = 0x([0-9A-F]+);", line)
    if mm:
        syms.append((int(mm[2], 16), mm[1]))
syms.sort()
keys = [s[0] for s in syms]
i, shown = 0, 0
L = min(len(a), len(b))
while i < L and shown < n:
    if a[i] != b[i]:
        j = i
        while j < L and a[j] != b[j]:
            j += 1
        v = i - off0
        k = bisect.bisect_right(keys, v) - 1
        s = f"{syms[k][1]}+{v - syms[k][0]:#x}" if k >= 0 else "?"
        print(f"file {i:#x} vram {v:#x} ({s}) {j - i} bytes: ours {b[i:i+8].hex()} orig {a[i:i+8].hex()}")
        shown += 1
        i = j
    i += 1
