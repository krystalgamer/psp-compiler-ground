#!/usr/bin/env python3
"""autodecomp.py TARGET MODULE [UNIT...]

For each function of the given (default: all non-newlib, non-libgcc C)
units, take m2c's draft, compile it with the unit's compiler at -O2 (then
-Os) and compare with the original.  Reports matches only; tools/autowrite.py
installs them (and reverts what breaks the module build).
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
import tmpdir  # noqa: E402,F401  (scratch files in tmp/)
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


NODWARF_HDR = '#include "common.h"\n#include "m2c_macros.h"\n'


def guess_types(t):
    """m2c --valid-syntax output for code without DWARF: data of unknown
    type is addressed bytewise (m2c's offsets are in bytes)."""
    return re.sub(r"^extern M2C_UNK(?:8|16|32|64)? (\w+);", r"extern u8 \1;", t, flags=re.M)


def clean(draft, keep_protos=False):
    out = []
    for line in draft.splitlines():
        if not keep_protos and (line.startswith("?") or re.match(r"^\w[\w\s\*]*\(.*\);\s*/\* extern \*/", line)):
            continue
        out.append(line)
    t = "\n".join(out)
    if keep_protos:
        t = guess_types(t)
    # locals m2c could not type
    t = re.sub(r"^(\s+)\? \*(\w+);", r"\1void *\2;", t, flags=re.M)
    t = re.sub(r"^(\s+)\?(32)? (\w+);", r"\1int \3;", t, flags=re.M)
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


def ctrl_buf(body):
    """m2c leaves a SceCtrlData at sp+0 as sp/sp4/sp8/sp9: give it a name."""
    if not re.search(r"sceCtrl(Read|Peek)Buffer(Positive|Negative)\(sp, ", body) or "SceCtrlData" in body.split("{")[0]:
        return body
    b = re.sub(r"sceCtrl(\w+)Buffer(\w+)\(sp, ", r"sceCtrl\1Buffer\2(&buf, ", body)
    b = re.sub(r"\bsp4\b", "buf.Buttons", b)
    b = re.sub(r"\bsp8\b", "buf.Lx", b)
    b = re.sub(r"\bsp9\b", "buf.Ly", b)
    b = re.sub(r"\bsp0\b", "buf.TimeStamp", b)
    return re.sub(r"(^|\n)(\w[^\n]*\) \{\n)", r"\1\2    SceCtrlData buf;\n", b, count=1)


def variants(body):
    """The draft and a few rewrites of m2c idioms the original sources spell
    differently."""
    out = [body]
    b = ctrl_buf(body)
    if b != body:
        out.append(b)
    for x in list(out):
        # `return (x & n) == 0;` is usually `if (x & n) return 0; return 1;`
        y = re.sub(r"\n(\s*)return \(([^;]+) & (\w+)\) == 0;\n",
                   r"\n\1if (\2 & \3) {\n\1    return 0;\n\1}\n\1return 1;\n", x)
        if y != x:
            out.append(y)
    return out


def try_func(target, module, unit, func, ctx, mod, cc1, dflags="", optsets=("-O2", "-Os")):
    nodwarf = not ctx.strip()
    draft, _ = m2cdraft.draft(target, module, unit, func, ("--valid-syntax",) if nodwarf else ())
    if not draft:
        return None, None
    body = clean(draft, keep_protos=nodwarf)
    sdk = m2cdraft.sdk_protos(ctx)
    # m2c's guessed prototypes of SDK functions give way to the real ones
    body = "\n".join(l for l in body.splitlines()
                     if not (re.search(r"/\* extern \*/$", l) and any(re.search(rf"\b{n}\(", l) for n in sdk)))
    sdkdecl = "\n".join(["#ifndef NULL", "#define NULL ((void *)0)", "#endif"] +
                        [v for k, v in sdk.items() if re.search(rf"\b{k}\(", body)])
    first = None
    for vb in variants(body):
        src = (NODWARF_HDR if nodwarf else ctx.replace(f"\n{func}(", f"\n/*proto*/ {func}(")) + "\n" + sdkdecl + "\n" + vb + "\n"
        # drop the DWARF prototype of the function itself (m2c's may differ)
        src = "\n".join(l for l in src.splitlines() if not re.search(rf"\b{re.escape(func)}\s*\(.*\);$", l))
        with tempfile.TemporaryDirectory() as td:
            f = Path(td) / "t.c"
            f.write_text(src)
            for flags in optsets:
                o = fntest.compile_c(f, cc1, f"{flags} {dflags}", Path(td) / "t.o")
                if o is None:
                    r = "error"
                    break
                r = objcmp.compare(mod, [o]).get(func)
                if r == "same":
                    return flags, (sdkdecl + "\n" + vb if nodwarf else vb)
        if first is None or first[0] == "error":
            first = (r, vb)
    return first


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("units", nargs="*")
    ap.add_argument("--opts", action="append", help="optimization option set to try (default -O2, -Os)")
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
            res, body = try_func(a.target, a.module, u, fn, ctx, mod, cc1, compiler.driver_flags(a.target, a.module, u),
                                 tuple(a.opts or ("-O2", "-Os")))
            print(f"{str(res):14} {u}:{fn}", flush=True)
            if res in (a.opts or ("-O2", "-Os")):
                ok += 1
    print(f"# {ok}/{total} functions matched from m2c drafts")


if __name__ == "__main__":
    main()
