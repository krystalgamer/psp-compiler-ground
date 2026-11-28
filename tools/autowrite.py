#!/usr/bin/env python3
"""autowrite.py TARGET MODULE [UNIT...]: write matching m2c drafts into units
that are still pure splat stubs.

For every function autodecomp.try_func reproduces exactly, the INCLUDE_ASM
line is replaced by the draft; the unit gets the DWARF declarations
(dwarf2c --extern) as its context.  The unit is then compiled again and the
module rebuilt; anything that no longer matches is reverted.
"""
import os
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import autodecomp  # noqa: E402
import m2c  # noqa: E402
import compiler  # noqa: E402
import objcmp  # noqa: E402

STUB = re.compile(r'^(#include "common.h"|/\*.*\*/|INCLUDE_ASM\(.*\);|INCLUDE_RODATA\(.*\);|[A-Za-z_][^;]*\) \{|\}|)$')


def build_ok(target, module):
    r = subprocess.run(["make", "-j" + os.environ.get("AW_JOBS", "1"), f"TARGET={target}", f"MODULE={module}"], cwd=ROOT,
                       capture_output=True, text=True)
    return r.stdout.strip().endswith(": OK")


def unit_test(target, module, path):
    # the unit's own flags (a `cflags: ...` comment), as the build uses them
    cf = re.search(r"cflags: (-O[0-9s](?: +-(?:[fm][\w-]+|std)(?:=[\w.:]+)?)*)", path.read_text())
    r = subprocess.run([sys.executable, str(ROOT / "tools/fntest.py"), target, module, str(path),
                        "--cc1", compiler.compiler(target, module, unit_of(target, module, path)),
                        "--flags=" + (cf.group(1) if cf else "-O2")],
                       capture_output=True, text=True, cwd=ROOT).stdout.strip().splitlines()
    m = re.search(r"\s(\d+)/(\d+)(\s|$)", r[-1]) if r else None
    return m and m.group(1) == m.group(2)


def unit_of(target, module, path):
    rel = path.relative_to(ROOT / "decomp_src" / target / module).with_suffix("")
    return str(rel)


DECL = re.compile(r"^(extern .*;|.*\);\s*/\* extern \*/)$")


def decl_name(line):
    m = re.search(r"(\w+)\s*(\(|;|\[)", line.split("/*")[0])
    return m.group(1) if m else line


def first_bad(target, module):
    r = subprocess.run([sys.executable, str(ROOT / "tools/firstdiff.py"), target, module],
                       capture_output=True, text=True, cwd=ROOT).stdout
    m = re.search(r"\((\w+)\+0x", r)
    return m.group(1) if m else None


def write_nodwarf(target, module, u, path, text, bodies):
    """Code without DWARF: each draft brings m2c's guesses for what it uses;
    the drafts go in one by one, each kept only if the unit still matches."""
    decls, done = {}, {}

    old = text.splitlines()
    if '#include "m2c_macros.h"' in old:
        i = old.index('#include "m2c_macros.h"') + 1
        head, old = old[:i], old[i:]
        have = {decl_name(l) for l in old if DECL.match(l)}
    else:
        # keep a leading `/* cflags: ... */` line
        if old and old[0].startswith("/* cflags"):
            head, old, have = [old[0]] + autodecomp.NODWARF_HDR.splitlines(), old[2:], set()
        else:
            head, old, have = autodecomp.NODWARF_HDR.splitlines(), old[1:], set()

    defined = set(re.findall(r"^[A-Za-z_][^;\n]*?(\w+)\([^;\n]*\)\s*\{", text, re.M))

    def render():
        out = head + [v for k, v in decls.items() if k not in have and k not in defined and k not in done] + [""]
        for line in old:
            m = re.match(r'INCLUDE_ASM\("[^"]+", (\w+)\);', line)
            out.append(done[m.group(1)] if m and m.group(1) in done else line)
        return "\n".join(out).rstrip("\n") + "\n"

    for fn, body in bodies.items():
        lines = body.strip("\n").splitlines()
        new = {decl_name(l): l for l in lines if DECL.match(l)}
        code = "\n".join(l for l in lines if not DECL.match(l)).strip("\n")
        saved = dict(decls)
        for k, v in new.items():
            # a typed guess beats a bytewise one
            if k not in bodies and k not in have and (k not in decls or (decls[k].startswith("extern u8 ")
                                                       and not v.startswith("extern u8 "))):
                decls[k] = v
        done[fn] = code
        path.write_text(render())
        if not unit_test(target, module, path):
            if os.environ.get("AW_DEBUG"):
                print(f"  {fn}: unit test fails", flush=True)
                (ROOT / "tmp" / f"aw_{fn}.c").write_text(render())
            del done[fn]
            decls.clear()
            decls.update(saved)
    # fntest ignores relocations: drop what the module build shows wrong
    while done:
        path.write_text(render())
        if build_ok(target, module):
            print(f"{u}: wrote {len(done)}/{len(bodies)}", flush=True)
            return len(done)
        bad = first_bad(target, module)
        if bad not in done:
            break
        del done[bad]
    if os.environ.get("AW_KEEP"):
        return 0
    path.write_text(text)
    print(f"{u}: reverted", flush=True)
    return 0


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
        # an earlier run's output: more drafts can go in
        drafted = '#include "m2c_macros.h"' in text or "/* declarations recovered from DWARF */" in text
        if not drafted and not all(STUB.match(l) for l in text.splitlines()):
            continue
        funcs = re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', text)
        cc1 = compiler.compiler(target, module, u)
        ctx = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), target, module, u, "--extern"],
                             capture_output=True, text=True).stdout
        # the unit's own flags (a `cflags: ...` comment, as propagate.py reads it)
        cf = re.search(r"cflags: (-O[0-9s](?: +-(?:[fm][\w-]+|std)(?:=[\w.:]+)?)*)", text)
        opt = cf.group(1) if cf else "-O2"
        bodies = {}
        # AW_PAR drafts tried in parallel (default 1)
        from concurrent.futures import ProcessPoolExecutor
        with ProcessPoolExecutor(int(os.environ.get("AW_PAR", "1"))) as ex:
            futs = {fn: ex.submit(autodecomp.try_func, target, module, u, fn, ctx, mod, cc1,
                                  compiler.driver_flags(target, module, u), (opt,)) for fn in funcs}
            for fn in funcs:
                res, body = futs[fn].result()
                if res == opt:
                    bodies[fn] = body
        if not bodies:
            continue
        if not ctx.strip():
            total += write_nodwarf(target, module, u, path, text, bodies)
            continue
        protos = set(bodies)
        ctxl = [l for l in ctx.splitlines()
                if not any(re.search(rf"\b{re.escape(f)}\s*\(.*\);$", l) for f in protos)]

        sdk = m2c.sdk_protos(ctx)
        allbody = "\n".join(bodies.values())
        sdkl = [v for k, v in sdk.items() if re.search(rf"\b{k}\(", allbody)]

        old = text.splitlines()[1:]
        head = ['#include "common.h"', "", "/* declarations recovered from DWARF */"] + ctxl
        if "/* declarations recovered from DWARF */" in text:
            # keep the earlier header; add the prototypes it lacks
            i = next(n for n, l in enumerate(old) if l.startswith(("INCLUDE_", "static ", "#ifdef")) or
                     re.match(r"^[A-Za-z_][^;]*\)\s*\{?$", l))
            head, old = ['#include "common.h"'] + old[:i], old[i:]
            have = "\n".join(head)
            sdkl = [l for l in sdkl if l not in have]

        def render(use=None):
            use = bodies if use is None else use
            out = head + (["", "/* SDK functions (tools/sdk_protos.h) */"] + sdkl if sdkl else []) + [""]
            for line in old:
                m = re.match(r'INCLUDE_ASM\("[^"]+", (\w+)\);', line)
                out.append(use[m.group(1)].strip("\n") if m and m.group(1) in use else line)
            return "\n".join(out).rstrip("\n") + "\n"
        ok = False
        path.write_text(render())
        if unit_test(target, module, path):
            # fntest ignores relocations: drop what the module build shows wrong
            while bodies:
                path.write_text(render())
                if build_ok(target, module):
                    ok = True
                    break
                bad = first_bad(target, module)
                if bad not in bodies:
                    break
                del bodies[bad]
        if not ok and len(bodies) > 1:
            # one bad draft spoils the batch: add them one at a time, keeping each that builds
            keep = {}
            for fn, b in list(bodies.items()):
                path.write_text(render({**keep, fn: b}))
                if unit_test(target, module, path) and build_ok(target, module):
                    keep[fn] = b
            bodies = keep
            path.write_text(render())
            ok = bool(bodies) and build_ok(target, module)
        if ok:
            total += len(bodies)
            print(f"{u}: wrote {len(bodies)}/{len(funcs)}", flush=True)
        else:
            path.write_text(text)
            print(f"{u}: reverted", flush=True)
    build_ok(target, module)
    print(f"# {module}: {total} functions written")


if __name__ == "__main__":
    main()
