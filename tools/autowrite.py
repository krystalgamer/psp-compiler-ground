#!/usr/bin/env python3
"""autowrite.py TARGET MODULE [UNIT...]: write matching m2c drafts into units
that are still pure splat stubs.

For every function autodecomp.try_func reproduces exactly, the INCLUDE_ASM
line is replaced by the draft; the unit gets the DWARF declarations
(dwarf2c --extern) as its context.  The unit is then compiled again and the
module rebuilt; anything that no longer matches is reverted.
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp  # noqa: E402
import compiler  # noqa: E402
import objcmp  # noqa: E402

STUB = re.compile(r'^(#include "common.h"|INCLUDE_ASM\(.*\);|INCLUDE_RODATA\(.*\);|)$')


def build_ok(target, module):
    r = subprocess.run(["make", "-j3", f"TARGET={target}", f"MODULE={module}"], cwd=ROOT,
                       capture_output=True, text=True)
    return r.stdout.strip().endswith(": OK")


def unit_test(target, module, path):
    r = subprocess.run([sys.executable, str(ROOT / "tools/fntest.py"), target, module, str(path),
                        "--cc1", compiler.compiler(target, module, unit_of(target, module, path))],
                       capture_output=True, text=True, cwd=ROOT).stdout.strip().splitlines()
    m = re.match(r"\S+\s+\S+\s+(\d+)/(\d+)", r[-1]) if r else None
    return m and m.group(1) == m.group(2)


def unit_of(target, module, path):
    rel = path.relative_to(ROOT / "decomp_src" / target / module).with_suffix("")
    return str(rel)


def main():
    target, module = sys.argv[1:3]
    units = sys.argv[3:] or list(autodecomp.app_units(target, module))
    mod = objcmp.module_funcs(target, module)
    total = 0
    for u in units:
        path = ROOT / "decomp_src" / target / module / f"{u}.c"
        if not path.exists():
            continue
        text = path.read_text()
        if not all(STUB.match(l) for l in text.splitlines()):
            continue
        funcs = re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', text)
        cc1 = compiler.compiler(target, module, u)
        ctx = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), target, module, u, "--extern"],
                             capture_output=True, text=True).stdout
        bodies = {}
        for fn in funcs:
            res, body = autodecomp.try_func(target, module, u, fn, ctx, mod, cc1,
                                            compiler.driver_flags(target, module, u))
            if res in ("-O2",):
                bodies[fn] = body
        if not bodies:
            continue
        protos = set(bodies)
        ctxl = [l for l in ctx.splitlines()
                if not any(re.search(rf"\b{re.escape(f)}\s*\(.*\);$", l) for f in protos)]
        out = ['#include "common.h"', "", "/* declarations recovered from DWARF */"] + ctxl + [""]
        for line in text.splitlines()[1:]:
            m = re.match(r'INCLUDE_ASM\("[^"]+", (\w+)\);', line)
            if m and m.group(1) in bodies:
                out.append(bodies[m.group(1)].strip("\n"))
            else:
                out.append(line)
        path.write_text("\n".join(out).rstrip("\n") + "\n")
        if unit_test(target, module, path) and build_ok(target, module):
            total += len(bodies)
            print(f"{u}: wrote {len(bodies)}/{len(funcs)}", flush=True)
        else:
            path.write_text(text)
            print(f"{u}: reverted", flush=True)
    build_ok(target, module)
    print(f"# {module}: {total} functions written")


if __name__ == "__main__":
    main()
