#!/usr/bin/env python3
"""libtest.py ARCHIVE SRCDIR [--cc1 A,B] [--flags F] [--inc DIR]... [-v FUNC]

Compile every SRCDIR/*.c whose object is a member of ARCHIVE (an SDK
library shipped with its sources) with each cc1 and compare its functions
with the member's, ignoring relocated fields (tools/objcmp.py).  Prints
per cc1 the identical/total function count and the differing functions.
"""
import argparse
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import objcmp  # noqa: E402
from fntest import DRIVER, T  # noqa: E402


def build(src, cc1, flags, incs, defs, out):
    i = out.with_suffix(".i")
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
    subprocess.run([str(T / "psp-as"), *asflags.split(), "-o", str(out), str(out.with_suffix(".s"))], check=True)
    return out, ""


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("archive")
    ap.add_argument("srcdir")
    ap.add_argument("--cc1", default="1.5.1,1.3.1-orig,1.6.1,1.7.1-orig")
    ap.add_argument("--flags", default="-O2")
    ap.add_argument("--inc", action="append", default=[])
    ap.add_argument("-D", dest="defs", action="append", default=[])
    ap.add_argument("-v", dest="func")
    a = ap.parse_args()
    members = {n: d for n, d in objcmp.members(a.archive)}
    srcs = [p for p in sorted(Path(a.srcdir).glob("*.c")) if p.stem + ".o" in members]
    incs = [Path(a.srcdir), *a.inc]
    for cc1 in a.cc1.split(","):
        same = tot = 0
        bad = []
        with tempfile.TemporaryDirectory() as td:
            for s in srcs:
                orig = objcmp.obj_funcs(members[s.stem + ".o"])
                o, err = build(s, cc1, a.flags, incs, a.defs, Path(td) / (s.stem + ".o"))
                if o is None:
                    bad.append(f"{s.name}:ERROR")
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
