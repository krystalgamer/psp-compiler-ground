#!/usr/bin/env python3
"""autodecomp.py TARGET MODULE [UNIT...] [--write]

For each function of the given (default: all non-newlib, non-libgcc C)
units, take m2c's draft, compile it with the unit's compiler at -O2 (then
-Os) and compare with the original.  Reports matches; with --write, puts
the matching functions into decomp_src (replacing their INCLUDE_ASM).
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import compiler  # noqa: E402
import fntest  # noqa: E402
import m2c as m2cdraft  # noqa: E402
import objcmp  # noqa: E402


def app_units(target, module):
    for line in (ROOT / "config" / target / f"units.{module}.txt").read_text().splitlines():
        p = line.split()
        if len(p) == 3 and not p[0].startswith(("newlib/", "libgcc/")) and p[0] != "crt0":
            yield p[0]


def clean(draft):
    out = []
    for line in draft.splitlines():
        if line.startswith("?") or re.match(r"^\w[\w\s\*]*\(.*\);\s*/\* extern \*/", line):
            continue
        out.append(line)
    t = "\n".join(out)
    t = re.sub(r"\bs64\b", "long long", t)
    t = re.sub(r"\bu64\b", "unsigned long long", t)
    t = re.sub(r"\bs32\b", "int", t)
    t = re.sub(r"\bu32\b", "unsigned int", t)
    t = re.sub(r"\bf32\b", "float", t)
    t = re.sub(r"\bf64\b", "double", t)
    t = re.sub(r"\bs16\b", "short", t)
    t = re.sub(r"\bu16\b", "unsigned short", t)
    t = re.sub(r"\bs8\b", "signed char", t)
    t = re.sub(r"\bu8\b", "unsigned char", t)
    return t


def try_func(target, module, unit, func, ctx, mod, cc1, dflags=""):
    draft, _ = m2cdraft.draft(target, module, unit, func)
    if not draft:
        return None, None
    body = clean(draft)
    src = ctx.replace(f"\n{func}(", f"\n/*proto*/ {func}(") + "\n" + body + "\n"
    # drop the DWARF prototype of the function itself (m2c's may differ)
    src = "\n".join(l for l in src.splitlines() if not re.search(rf"\b{re.escape(func)}\s*\(.*\);$", l))
    with tempfile.TemporaryDirectory() as td:
        f = Path(td) / "t.c"
        f.write_text(src)
        for flags in ("-O2", "-Os"):
            o = fntest.compile_c(f, cc1, f"{flags} {dflags}", Path(td) / "t.o")
            if o is None:
                return "error", body
            r = objcmp.compare(mod, [o]).get(func)
            if r == "same":
                return flags, body
        return r, body


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("units", nargs="*")
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args()
    mod = objcmp.module_funcs(a.target, a.module)
    units = a.units or list(app_units(a.target, a.module))
    total = ok = 0
    for u in units:
        cc1 = compiler.compiler(a.target, a.module, u)
        ctx = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), a.target, a.module, u, "--extern"],
                             capture_output=True, text=True).stdout
        cpath = ROOT / "decomp_src" / a.target / a.module / f"{u}.c"
        funcs = re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', cpath.read_text()) if cpath.exists() else []
        for fn in funcs:
            total += 1
            res, body = try_func(a.target, a.module, u, fn, ctx, mod, cc1, compiler.driver_flags(a.target, a.module, u))
            print(f"{str(res):14} {u}:{fn}", flush=True)
            if res in ("-O2", "-Os"):
                ok += 1
    print(f"# {ok}/{total} functions matched from m2c drafts")


if __name__ == "__main__":
    main()
