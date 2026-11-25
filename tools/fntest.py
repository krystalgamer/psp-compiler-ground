#!/usr/bin/env python3
"""fntest.py TARGET MODULE FILE.c [--cc1 A,B] [--flags "-O2" ...] [-v]

Compile a C file with each cc1 and flag set and compare every function it
defines with the module's function of the same name (tools/objcmp.py).
Default cc1s: the unit's own version, 1.3.1-orig and 1.7.1-orig; default
flags: -O2.  With -v, prints the side-by-side disassembly of the first
non-identical function for the first cc1.
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import objcmp  # noqa: E402

T = ROOT / "tmp" / "toolchains" / "bin"
# what each cc1's psp-gcc driver adds (cc1 options, psp-as options)
DRIVER = {"1.5.1": ("-mno-ulsw", ""), "1.3.1-orig": ("-mno-ulsw", ""),
          "1.6.1": ("", "-mulsw"), "1.7.1-orig": ("", "-mulsw"),
          "1.8.3": ("", "-mulsw"), "1.8.4": ("", "-mulsw")}


def compile_c(src, cc1, flags, out, incs=(), defs=()):
    i = out.with_suffix(".i")
    subprocess.run(["cpp", "-P", "-undef", "-nostdinc", f"-I{ROOT/'include'}", f"-I{ROOT/'include/sdk'}", f"-I{ROOT/'include/libc'}", f"-I{ROOT/'decomp_src'}", *[f"-I{d}" for d in incs],
                    "-D__GNUC__=3", "-D_LANGUAGE_C", "-D__psp__", "-D__mips__", "-DM2CTX", *[f"-D{d}" for d in defs], str(src), "-o", str(i)],
                   check=True)
    cflags, asflags = DRIVER.get(cc1, ("", ""))
    r = subprocess.run([str(T / f"cc1-{cc1}"), "-quiet", "-G0", *cflags.split(), *flags.split(), str(i), "-o", str(out.with_suffix(".s"))],
                       capture_output=True, text=True)
    if r.returncode:
        sys.stderr.write(r.stderr)
        return None
    subprocess.run([str(T / "psp-as"), "-G0", *asflags.split(), "-o", str(out), str(out.with_suffix(".s"))], check=True)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("file")
    ap.add_argument("--cc1")
    ap.add_argument("--flags", action="append")
    ap.add_argument("-v", action="store_true")
    ap.add_argument("--func", help="with -v: show this function")
    ap.add_argument("--inc", action="append", default=[], help="extra include directory")
    ap.add_argument("-D", dest="defs", action="append", default=[], help="preprocessor define")
    a = ap.parse_args()
    mod = objcmp.module_funcs(a.target, a.module)
    cc1s = a.cc1.split(",") if a.cc1 else ["1.5.1", "1.6.1", "1.3.1-orig", "1.7.1-orig"]
    m = re.search(r"cflags: (-O[0-3s](?: -[fm][\w-]+)*)", Path(a.file).read_text())
    flags = a.flags or [m.group(1) if m else "-O2"]
    with tempfile.TemporaryDirectory() as td:
        for c in cc1s:
            for f in flags:
                o = compile_c(Path(a.file), c, f, Path(td) / f"{c}.o", [ROOT / "decomp_src" / a.target / a.module, Path(a.file).resolve().parent, *a.inc], a.defs)
                if o is None:
                    print(f"{c:11} {f:12} compile error")
                    continue
                res = objcmp.compare(mod, [o], verbose=(a.func or True) if a.v and c == cc1s[0] else False)
                same = [k for k, v in res.items() if v == "same"]
                bad = {k: v for k, v in res.items() if v != "same"}
                print(f"{c:11} {f:12} {len(same)}/{len(res)}  " + " ".join(f"{k}:{v.replace(' ', '')}" for k, v in sorted(bad.items())))


if __name__ == "__main__":
    main()
