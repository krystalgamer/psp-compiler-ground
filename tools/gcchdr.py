#!/usr/bin/env python3
"""gcchdr.py ELF [--cu NAME] [--nth N] [--tree VERSION]

A module's libgcc compile units (libgcc2.c, dp-bit.c, fp-bit.c) were
built inside the psp-gcc tree, so their DWARF describes the compiler's
own headers: tconfig.h, config/mips/mips.h (enum cmp_type, reg_class,
mips_builtins, struct mips_args, ...) with their declaration lines.
List those declarations (tag name @file:line =value), or with --tree,
diff them against libgcc2.c (L_udivdi3) compiled with -g from
gcc<VERSION>_src (tconfig.h from tmp/gccbuild/VERSION, made if missing).
"""
import argparse
import difflib
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
import tmpdir  # noqa: E402,F401  (scratch files in tmp/)
T = ROOT / "tmp" / "toolchains"


def listing(path, sub, nth=0):
    d = ELFFile(open(path, "rb")).get_dwarf_info(relocate_dwarf_sections=False)
    k = 0
    for cu in d.iter_CUs():
        top = cu.get_top_DIE()
        nm = top.attributes.get("DW_AT_name")
        if not nm or sub not in nm.value.decode():
            continue
        if k < nth:
            k += 1
            continue
        lp = d.line_program_for_CU(cu)
        files = {i + 1: os.path.basename(f.name.decode()) for i, f in enumerate(lp["file_entry"])}
        out = []

        def walk(die, depth):
            for c in die.iter_children():
                a = c.attributes

                def g(key):
                    v = a[key].value if key in a else None
                    return v.decode() if isinstance(v, bytes) else v
                s = f"{'  ' * depth}{c.tag[7:]} {g('DW_AT_name') or ''}"
                if g("DW_AT_decl_file") is not None:
                    s += f" @{files.get(g('DW_AT_decl_file'))}:{g('DW_AT_decl_line')}"
                if g("DW_AT_const_value") is not None:
                    s += f" ={g('DW_AT_const_value')}"
                if g("DW_AT_byte_size") is not None:
                    s += f" size={g('DW_AT_byte_size')}"
                out.append(s)
                if c.has_children and depth < 2:
                    walk(c, depth + 1)
        walk(top, 0)
        return out
    sys.exit(f"no compile unit named *{sub}* in {path}")


def tree_listing(version):
    src = ROOT / f"gcc{version}_src" / "gcc"
    bld = ROOT / "tmp" / "gccbuild" / version / "gcc-bin" / "gcc"
    if not (bld / "tconfig.h").exists():
        subprocess.run([str(T / "bin" / "rh9"), "sh", "-c", f"cd {bld} && make tconfig.h"],
                       check=True, capture_output=True)
    inc = next(p for p in (ROOT / "tmp" / "gccbuild").glob("*/gcc-bin/gcc/include") if (p / "stddef.h").exists())
    with tempfile.TemporaryDirectory(dir=ROOT / "tmp") as td:
        c = Path(td) / "u.c"
        c.write_text('#define L_udivdi3\n#include "libgcc2.c"\n')
        i = subprocess.run([str(T / "bin" / "rh9"), str(T / "psp-gcc-1.3.1" / "bin" / "psp-gcc"), "-E",
                            "-isystem", str(inc), "-DIN_GCC", "-DCROSS_COMPILE", "-D_IN_GCC_LIB",
                            "-DHAVE_GTHR_DEFAULT", "-DIN_LIBGCC2", "-D__GCC_FLOAT_NOT_NEEDED", "-Dinhibit_libc",
                            f"-I{bld}", f"-I{src}", f"-I{src}/config", f"-I{src}/../include",
                            "-U__GNUC_MINOR__", "-D__GNUC_MINOR__=3", str(c)],
                           capture_output=True, text=True)
        if i.returncode:
            sys.exit(i.stderr)
        i = i.stdout
        s = Path(td) / "u.s"
        subprocess.run([str(T / "bin" / f"cc1-{version}"), "-O2", "-g", "-G0", "-quiet", "-o", str(s)],
                       input=i, text=True, check=True, capture_output=True)
        o = Path(td) / "u.o"
        subprocess.run([str(T / "bin" / "psp-as"), "-EL", "-G0", "-o", str(o), str(s)], check=True)
        return listing(o, "")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("elf")
    ap.add_argument("--cu", default="libgcc2.c")
    ap.add_argument("--nth", type=int, default=0)
    ap.add_argument("--tree")
    a = ap.parse_args()
    orig = listing(a.elf, a.cu, a.nth)
    if not a.tree:
        print("\n".join(orig))
        return
    ours = tree_listing(a.tree)
    d = list(difflib.unified_diff(orig, ours, "module", f"gcc{a.tree}_src", n=0, lineterm=""))
    print("\n".join(d) if d else "identical")


if __name__ == "__main__":
    main()
