#!/usr/bin/env python3
"""libtest.py ARCHIVE SRCDIR [--cc1 A,B] [--flags F] [--inc DIR]... [-D DEF]...
           [--pspgcc HEX] [--member OBJ=SRC[:DEF,...]]... [-v FUNC]

Compile every SRCDIR/*.c whose object is a member of ARCHIVE (an SDK
library shipped with its sources) with each cc1 and compare its functions
with the member's, ignoring relocated fields (tools/objcmp.py).  Prints
per cc1 the identical/total function count and the differing functions.

--pspgcc HEX: preprocess like the psp-gcc driver: with cc1 itself, its
predefines (`__SCE__`, `__psp_gcc__=HEX`, e.g. 0x010601 for 1.6.1; SDK
headers test it), the --inc directories as -isystem and then the psp-gcc
1.3.1 release's gcc and newlib headers.
--member OBJ=SRC[:DEF,...]: OBJ is built from SRCDIR/SRC with these
defines (e.g. libgum_vfpu.o=libgum.c:USE_VFPU=1).
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
import objcmp  # noqa: E402
from fntest import DRIVER, T  # noqa: E402


REL = ROOT / "tmp" / "toolchains" / "psp-gcc-1.3.1"


def vfpu_compat(t):
    """The VFPU syntax of the 1.6.1-era psp-as (binutils allegrex-2.2.2) in
    the 1.3.1 psp-as's (2.2.1): `vcmmul D,A,B` is `vmmul D,B,A`, vctfmN and
    vchtfm4 are vtfmN and vhtfm4, and a destination prefix's W (plain
    write) is an empty field.  (Sony's sources choose them with
    `#if __psp_gcc__ > 0x010501`; both forms are the same instruction.)"""
    t = re.sub(r"\bvcmmul\.(\w)(\s+)([^,\s]+),\s*([^,\s]+),\s*([^,\s#]+)", r"vmmul.\1\2\3, \5, \4", t)
    t = re.sub(r"\bvc(h?tfm\d)", r"v\1", t)
    return re.sub(r"(?m)^(\s*v[\w.]+\s+[^,\s\[]+)\[([^\]\n]*)\]",
                  lambda m: m[1] + "[" + re.sub(r"(?<![\w:])W(?![\w:])", "", m[2]) + "]", t)


def build(src, cc1, flags, incs, defs, out, driver=False):
    i = out.with_suffix(".i")
    if driver:
        # preprocessed by cc1 itself, as psp-gcc does (its __SIZE_TYPE__ etc.;
        # -std= decides __STRICT_ANSI__), SDK headers as -isystem
        r = subprocess.run([str(T / f"cc1-{cc1}"), "-E", "-quiet", "-nostdinc", *[f"-I{d}" for d in incs[:1]],
                            *[x for d in incs[1:] for x in ("-isystem", str(d))], "-D__GNUC__=3", "-D__GNUC_MINOR__=3",
                            "-D__GNUC_PATCHLEVEL__=3", "-D__MIPSEL__", "-D__R3000__", "-D__MIPSEL", "-D__R3000",
                            "-D__psp__", *[f"-D{d}" for d in defs], *[f for f in flags.split() if f.startswith(("-std", "-O"))],
                            str(src), "-o", str(i)], capture_output=True, text=True)
    else:
        r = subprocess.run(["cpp", "-undef", "-nostdinc", *[f"-I{d}" for d in incs], "-D__GNUC__=3",
                            "-D__GNUC_MINOR__=3", "-D_LANGUAGE_C", "-D__psp__", "-D__mips__", "-D__MIPSEL__",
                            "-D__STDC_VERSION__=199901L", *[f"-D{d}" for d in defs], str(src), "-o", str(i)],
                           capture_output=True, text=True)
    if r.returncode:
        return None, r.stderr
    cflags, asflags = DRIVER.get(cc1, ("", ""))
    r = subprocess.run([str(T / f"cc1-{cc1}"), "-quiet", *cflags.split(), *flags.split(), str(i),
                        "-o", str(out.with_suffix(".s"))], capture_output=True, text=True)
    if r.returncode:
        return None, r.stderr
    s = out.with_suffix(".s")
    s.write_text(vfpu_compat(s.read_text()))
    subprocess.run([str(T / "psp-as"), *asflags.split(), "-o", str(out), str(s)], check=True)
    return out, ""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("archive")
    ap.add_argument("srcdir")
    ap.add_argument("--cc1", default="1.5.1,1.3.1-orig,1.6.1,1.7.1-orig")
    ap.add_argument("--flags", default="-O2")
    ap.add_argument("--inc", action="append", default=[])
    ap.add_argument("-D", dest="defs", action="append", default=[])
    ap.add_argument("--pspgcc")
    ap.add_argument("--member", action="append", default=[])
    ap.add_argument("-v", dest="func")
    a = ap.parse_args()
    members = {n: d for n, d in objcmp.members(a.archive)}
    special = {}
    for m in a.member:
        obj, src = m.split("=", 1)
        src, _, d = src.partition(":")
        special[obj] = (Path(a.srcdir) / src, [x for x in d.split(",") if x])
    srcs = [(p.stem + ".o", p, []) for p in sorted(Path(a.srcdir).glob("*.c")) if p.stem + ".o" in members
            and p.stem + ".o" not in special] + [(o, p, d) for o, (p, d) in special.items() if o in members]
    incs = [Path(a.srcdir), *a.inc]
    if a.pspgcc:
        gcc = next((REL / "lib" / "gcc-lib" / "psp").glob("3.3.3*")) / "include"
        incs += [gcc, REL / "psp" / "include"]
        a.defs += ["__SCE__", f"__psp_gcc__={a.pspgcc}", "_MIPSEL", "__mips_hard_float", "__mips_single_float"]
    for cc1 in a.cc1.split(","):
        same = tot = 0
        bad = []
        with tempfile.TemporaryDirectory() as td:
            for mem, s, xdefs in srcs:
                orig = objcmp.obj_funcs(members[mem])
                o, err = build(s, cc1, a.flags, incs, a.defs + xdefs, Path(td) / mem, bool(a.pspgcc))
                if o is None:
                    bad.append(f"{mem}:ERROR")
                    sys.stderr.write(err[:400])
                    tot += len(orig)
                    continue
                ours = objcmp.obj_funcs(o.read_bytes())
                for fn, w in orig.items():
                    tot += 1
                    m = ours.get(fn)
                    if m == w:
                        same += 1
                    else:
                        bad.append(f"{fn}:" + ("missing" if m is None else f"size{len(m)}/{len(w)}" if len(m) != len(w)
                                               else f"diff{sum(x != y for x, y in zip(m, w))}"))
                        if a.func == fn and m is not None and cc1 == a.cc1.split(",")[0]:
                            print(objcmp.side_by_side(m, w))
        print(f"{cc1:11} {same}/{tot}  " + " ".join(bad[:40]))


if __name__ == "__main__":
    main()
