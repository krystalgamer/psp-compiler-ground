#!/usr/bin/env python3
"""nltest.py TARGET MODULE CC1 [CC1...] [--flags "-O2 -g"] [-v]

Compile every newlib unit of a module from the newlib 1.12.0 sources with
each given cc1 (names in tmp/toolchains/bin) and compare its functions with
the module's.  Prints a summary per cc1, and with -v each function that is
not identical under all of them.
"""
import argparse
import re
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import objcmp  # noqa: E402

NL = ROOT / "tmp" / "src" / "newlib-1.12.0"


def units(target, module):
    for line in (ROOT / "config" / target / f"units.{module}.txt").read_text().splitlines():
        p = line.split()
        if len(p) == 3 and "newlib-1.12.0/" in p[2]:
            yield p[0], p[1], NL / p[2].split("newlib-1.12.0/")[1]


def build(cc1, unit, src, flags):
    out = ROOT / "tmp" / "nl" / cc1 / (unit + ".o")
    out.parent.mkdir(parents=True, exist_ok=True)
    r = subprocess.run([str(ROOT / "tools" / "nlcc.sh"), str(ROOT / "tmp/toolchains/bin" / f"cc1-{cc1}"),
                        str(out), str(src)] + flags.split(), capture_output=True, text=True)
    return out if r.returncode == 0 and out.exists() else None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("cc1", nargs="+")
    ap.add_argument("--flags", default="-O2 -g")
    ap.add_argument("-v", action="store_true")
    a = ap.parse_args()
    mod = objcmp.module_funcs(a.target, a.module)
    us = list(units(a.target, a.module))
    table = {}
    for cc1 in a.cc1:
        with ThreadPoolExecutor(4) as ex:
            objs = list(ex.map(lambda u: (u[0], build(cc1, u[0], u[2], a.flags)), us))
        fails = [u for u, o in objs if o is None]
        res = {}
        for u, o in objs:
            if o:
                for fn, r in objcmp.compare(mod, [o]).items():
                    res[fn] = (u, r)
        table[cc1] = res
        same = sum(1 for u, r in res.values() if r == "same")
        print(f"{cc1:12} {same}/{len(res)} functions identical; {len(fails)} units failed to build")
    if a.v:
        fns = sorted(set().union(*[set(r) for r in table.values()]))
        for fn in fns:
            rs = [table[c].get(fn, ("", "-"))[1] for c in a.cc1]
            if any(r != "same" for r in rs):
                unit = next(table[c][fn][0] for c in a.cc1 if fn in table[c])
                print("  " + " ".join(f"{r:14}" for r in rs) + f" {fn}  ({unit})")


if __name__ == "__main__":
    main()
