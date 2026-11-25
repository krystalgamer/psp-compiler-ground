#!/usr/bin/env python3
"""discrim.py TARGET MODULE [UNIT...] [--cc1 A,B]: look for functions whose
code depends on the compiler.  Each remaining INCLUDE_ASM function's m2c
draft (and each decompiled C file as a whole) is compiled with both cc1s
and the assembly of every function compared; prints the functions where
the two differ.  Drafts need not match the original: a difference shows
that the function exercises code the two compilers treat differently."""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp  # noqa: E402
import compiler  # noqa: E402
import m2c as m2cdraft  # noqa: E402

T = ROOT / "tmp" / "toolchains" / "bin"


def funcs_asm(s_text):
    out, cur, body = {}, None, []
    for ln in s_text.splitlines():
        m = re.match(r"^(\w+):$", ln)
        if m and not ln.startswith("$"):
            cur, body = m.group(1), []
            continue
        if cur and re.match(r"\s*\.end\s+" + re.escape(cur) + r"\b", ln):
            out[cur] = body
            cur = None
            continue
        if cur:
            t = ln.strip()
            if not t or t.startswith((".loc", ".file", "#", ".ident")):
                continue
            body.append(t)
    return out


def compile_s(src, cc1, flags, td, tag):
    i = Path(td) / f"{tag}.i"
    s = Path(td) / f"{tag}.s"
    c = Path(td) / f"{tag}.c"
    c.write_text(src)
    r = subprocess.run(["cpp", "-P", "-undef", "-nostdinc", f"-I{ROOT/'include'}", f"-I{ROOT/'include/sdk'}",
                        f"-I{ROOT/'include/libc'}", f"-I{ROOT/'decomp_src'}", f"-I{src_dir}",
                        "-D__GNUC__=3", "-D_LANGUAGE_C", "-D__psp__", "-D__mips__", "-DM2CTX", str(c), "-o", str(i)],
                       capture_output=True, text=True)
    if r.returncode:
        return None
    r = subprocess.run([str(T / f"cc1-{cc1}"), "-quiet", "-G0", "-O2", *flags.split(), str(i), "-o", str(s)],
                       capture_output=True, text=True)
    if r.returncode:
        return None
    return funcs_asm(s.read_text())


def report(name, a, b, A, B):
    if a is None or b is None:
        return False
    hit = False
    for fn in sorted(set(a) & set(b)):
        if a[fn] != b[fn]:
            hit = True
            print(f"DIFF {name}:{fn} ({len(a[fn])} vs {len(b[fn])} lines)")
            import difflib
            for ln in list(difflib.unified_diff(a[fn], b[fn], A, B, n=1, lineterm=""))[2:14]:
                print("    " + ln)
    return hit


def main():
    global src_dir
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("units", nargs="*")
    ap.add_argument("--cc1", default="1.6.1,1.7.1-orig")
    ap.add_argument("--versions", default="1.6.1,1.6.1.internal")
    ap.add_argument("--libs", action="store_true", help="also newlib/libgcc/libstdc++ units")
    a = ap.parse_args()
    A, B = a.cc1.split(",")
    vers = a.versions.split(",")
    units = a.units or [p.split()[0] for p in (ROOT / "config" / a.target / f"units.{a.module}.txt").read_text().splitlines()
                        if p.strip() and not p.startswith("#") and len(p.split()) == 3 and p.split()[1] in vers
                        and (a.libs or not p.startswith(("newlib/", "libgcc/", "gcc-3.3.3/")))]
    for u in units:
        cpath = ROOT / "decomp_src" / a.target / a.module / f"{u}.c"
        if not cpath.exists():
            continue
        src_dir = cpath.parent
        flags = compiler.driver_flags(a.target, a.module, u)
        text = cpath.read_text()
        funcs = re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', text)
        with tempfile.TemporaryDirectory() as td:
            if len(funcs) < len(re.findall(r"^\w[^;]*\)\s*$", text, re.M)) + 1:
                report(u + "(C)", compile_s(text, A, flags, td, "ca"), compile_s(text, B, flags, td, "cb"), A, B)
            if not funcs:
                print(f"# done {u}", flush=True)
                continue
            ctx = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), a.target, a.module, u, "--extern"],
                                 capture_output=True, text=True).stdout
            for fn in funcs:
                draft, _ = m2cdraft.draft(a.target, a.module, u, fn)
                if not draft:
                    continue
                body = autodecomp.clean(draft)
                src = ctx + "\n" + body + "\n"
                src = "\n".join(l for l in src.splitlines() if not re.search(rf"\b{re.escape(fn)}\s*\(.*\);$", l))
                ra = compile_s(src, A, flags, td, "da")
                rb = compile_s(src, B, flags, td, "db")
                if ra is None or rb is None:
                    print(f"ERR  {u}:{fn}", flush=True)
                    continue
                report(u, {fn: ra.get(fn, [])}, {fn: rb.get(fn, [])}, A, B)
        print(f"# done {u}", flush=True)


if __name__ == "__main__":
    main()
