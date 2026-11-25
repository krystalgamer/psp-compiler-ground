#!/usr/bin/env python3
"""stripmerge.py TARGET MODULE CFILE [--test-only] [--cc1 V]

Work file -> units for modules whose units were split by address
(config/TARGET/files.MODULE.txt), e.g. the stripped tony_libs modules.

CFILE holds declarations (or #includes) and function definitions in any
order.  The definitions are split by address into one test file per unit
(declarations + that unit's functions in address order, so that gcc's
const/pure detection sees exactly what the real object saw), each is
compiled and compared (tools/fntest.py, flags from CFILE's `cflags:`
line), and, unless --test-only, every matching function replaces its
INCLUDE_ASM line (or its older C) in decomp_src/TARGET/MODULE/UNIT.c.
The module is then rebuilt; if it no longer matches, the units are
restored.  Non-definition text of CFILE goes between
`/* --- declarations --- */` markers at the top of each touched unit.
"""
import argparse
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEF = re.compile(r'^(?!static\b)[A-Za-z_][\w \*]*?\b(\w+)\([^;{]*\)\n\{\n.*?^\}\n', re.M | re.S)
MARK0, MARK1 = '/* --- declarations --- */', '/* --- end declarations --- */'


def units(t, m):
    ents = []
    for line in (ROOT / "config" / t / f"files.{m}.txt").read_text().splitlines():
        f = line.split("#")[0].split()
        if f and f[0] != "rodata":
            ents.append((int(f[0], 16), f[1]))
    return sorted(ents)


def addrs(t, m):
    out = {}
    for line in (ROOT / "config" / t / f"symbol_addrs.{m}.txt").read_text().splitlines():
        mm = re.match(r"(\w+) = 0x([0-9A-F]+);", line)
        if mm:
            out[mm[1]] = int(mm[2], 16)
    return out


def merge_unit(path, pre, bodies, cflags):
    u = path.read_text()
    n = 0
    for name, body in bodies:
        new, k = re.subn(r'^INCLUDE_ASM\("[^"]+", ' + name + r'\);\n', lambda _: body, u, flags=re.M)
        if k:
            u, n = new, n + 1
            continue
        mm = re.search(r'^(?!static\b)[A-Za-z_][\w \*]*?\b' + name + r'\([^;{]*\)\n\{\n.*?^\}\n', u, re.M | re.S)
        if mm:
            u = u[:mm.start()] + body + u[mm.end():]
    if pre.strip():
        if MARK0 in u:
            a, b = u.index(MARK0), u.index(MARK1)
            u = u[:a] + MARK0 + "\n" + pre + "\n" + u[b:]
        else:
            i = u.index('#include "common.h"\n') + len('#include "common.h"\n')
            u = u[:i] + "\n" + MARK0 + "\n" + pre + "\n" + MARK1 + "\n" + u[i:]
    if cflags and "cflags:" not in u.split("\n", 1)[0]:
        u = f"/* cflags: {cflags} */\n" + u
    elif cflags:
        u = f"/* cflags: {cflags} */\n" + u.split("\n", 1)[1]
    path.write_text(u)
    return n


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("cfile")
    ap.add_argument("--test-only", action="store_true")
    ap.add_argument("--cc1", default="1.5.1")
    a = ap.parse_args()
    t, m = a.target, a.module
    src = Path(a.cfile).read_text()
    cf = re.search(r"cflags: ([^*]*?)\s*\*/", src)
    cflags = cf[1].strip() if cf else "-O2"
    defs = list(DEF.finditer(src))
    pre = src
    for d in defs:
        pre = pre.replace(d[0], "")
    pre = re.sub(r"^/\* cflags:.*\n", "", pre, flags=re.M)
    pre = re.sub(r"\n{3,}", "\n\n", pre).strip("\n")
    us = units(t, m)
    ad = addrs(t, m)

    def addr(n):
        if re.fullmatch(r"func_[0-9A-F]{8}", n):
            return int(n[5:], 16)
        return ad.get(n)

    per = {}
    for d in defs:
        x = addr(d[1])
        if x is None:
            print(f"? {d[1]}: no address", file=sys.stderr)
            continue
        u = [name for start, name in us if start <= x][-1]
        per.setdefault(u, []).append((x, d[1], d[0]))
    work = ROOT / "tmp" / "strip" / m
    work.mkdir(parents=True, exist_ok=True)
    good = {}
    for u, fs in per.items():
        fs.sort()
        p = work / f"{u}.c"
        p.write_text(f"/* cflags: {cflags} */\n" + pre + "\n\n" + "\n".join(b for _, _, b in fs))
        r = subprocess.run([sys.executable, str(ROOT / "tools/fntest.py"), t, m, str(p), "--cc1", a.cc1,
                            "--inc", str(Path(a.cfile).resolve().parent)],
                           capture_output=True, text=True).stdout.strip().splitlines()
        line = r[-1] if r else "error"
        bad = set(re.findall(r"(\w+):", line)) if "error" not in line else {n for _, n, _ in fs}
        good[u] = [(n, b) for _, n, b in fs if n not in bad]
        print(f"{u:24} {line.split(None, 1)[1] if ' ' in line else line}")
    if a.test_only:
        return
    unit_dir = ROOT / "decomp_src" / t / m
    backup = {p: p.read_text() for p in unit_dir.glob("*.c")}
    merged = 0
    for u, items in good.items():
        if items:
            merged += merge_unit(unit_dir / f"{u}.c", pre, items, cflags + " -fno-merge-constants"
                                 if "-fno-merge-constants" not in cflags else cflags)
    r = subprocess.run(["make", f"TARGET={t}", f"MODULE={m}"], cwd=ROOT, capture_output=True, text=True)
    last = (r.stdout.strip().splitlines() or ["?"])[-1]
    if not last.endswith(": OK"):
        for p, s in backup.items():
            p.write_text(s)
        subprocess.run(["make", f"TARGET={t}", f"MODULE={m}"], cwd=ROOT, capture_output=True, text=True)
        print(f"BUILD FAILED ({last}); units restored", file=sys.stderr)
        sys.exit(1)
    print(f"merged {merged} new functions; build OK")


if __name__ == "__main__":
    main()
