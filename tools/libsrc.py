#!/usr/bin/env python3
"""libsrc.py TARGET MODULE [--write] [-v]

Compile each newlib unit of a module that is still asm from the original
newlib 1.12.0 source (tools/nlcpp.sh, the unit's own cc1 and flags) and,
with --write, replace its decomp_src file with an #include of that source
when every function is identical and the source defines no .data/.bss of
its own (a module's data stays in its asm data blob).  Sony's modified
functions stay asm.
"""
import argparse
import io
import re
import subprocess
import sys
import tempfile
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import compiler  # noqa: E402
import objcmp  # noqa: E402
from nltest import MALLOCR  # noqa: E402

T = ROOT / "tmp" / "toolchains" / "bin"


def wrapper(rel, unit, equ=(), align=4):
    s = f"/* upstream: newlib-1.12.0/newlib/{rel} (unmodified) */\n/* cflags: -O2 -fno-builtin */\n"
    if align > 4:
        s += f"/* data-align: {align} */\n"
    if "/mallocr/" in unit:
        s += "#define INTERNAL_NEWLIB\n#define DEFINE_" + MALLOCR.get(unit.rsplit("/", 1)[1], "MALLOC") + "\n"
    s += f'#include "{rel}"\n'
    if equ:
        s += "\n/* labels the rest of the module's asm uses */\n"
        s += "".join(f'__asm__("{n} = 0x{v:08X}");\n' for n, v in sorted(equ.items(), key=lambda x: x[1]))
    return s


def build(target, module, unit, text, td):
    c = Path(td) / "u.c"
    c.write_text(text)
    i = subprocess.run([str(ROOT / "tools/nlcpp.sh"), str(c)], capture_output=True, text=True)
    if i.returncode:
        return None
    cc1 = T / f"cc1-{compiler.compiler(target, module, unit)}"
    flags = compiler.driver_flags(target, module, unit).split()
    s = Path(td) / "u.s"
    r = subprocess.run([str(cc1), "-O2", "-fno-builtin", *flags, "-G0", "-quiet", "-o", str(s)],
                       input=i.stdout, capture_output=True, text=True)
    if r.returncode:
        return None
    o = Path(td) / "u.o"
    asf = subprocess.run([sys.executable, str(ROOT / "tools/compiler.py"), "--as-flags", target, module, unit],
                         capture_output=True, text=True).stdout.split()
    r = subprocess.run([str(T / "psp-as"), *asf, "-EL", "-G0", "-o", str(o), str(s)], capture_output=True)
    return o if r.returncode == 0 else None


def rodata_ranges(target, module):
    """unit -> (rom start, rom end) of its .rodata entry in the splat config"""
    ents = [(int(m[1], 16), m[2], m[3]) for m in
            re.finditer(r"- \[0x([0-9A-F]+), (\.?\w+), ([\w/.]+)\]", (ROOT / "config" / target / f"{module}.yaml").read_text())]
    out = {}
    for i, (st, kind, name) in enumerate(ents):
        if kind == ".rodata" and i + 1 < len(ents):
            out[name] = (st, ents[i + 1][0])
    return out


def old_labels(target, module, unit):
    """labels the asm stub of a unit defines: name -> vram"""
    out = {}
    d = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit
    for f in d.glob("*.s"):
        t = f.read_text()
        for m in re.finditer(r"^(?:glabel|dlabel|jlabel|alabel)\s+(\w+)\s*\n(?:\s*\n)*\s*/\* [0-9A-F]+ ([0-9A-F]{8})", t, re.M):
            out[m[1]] = int(m[2], 16)
    return out


_words = {}


def used_elsewhere(target, module, unit):
    """symbol names the module's asm outside UNIT's stub refers to"""
    if (target, module) not in _words:
        idx = {}
        for f in (ROOT / "tmp" / "asm" / target / module).rglob("*.s"):
            for w in set(re.findall(r"\b[A-Za-z_]\w*", f.read_text())):
                idx.setdefault(w, set()).add(f.parent)
        _words[(target, module)] = idx
    own = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit
    return {w for w, ds in _words[(target, module)].items() if ds - {own}}


def rodata_ok(o, target, module, unit, ranges):
    e = ELFFile(io.BytesIO(o.read_bytes()))
    new = b""
    for sec in e.iter_sections():
        if sec.name.startswith(".rodata"):
            al = max(sec["sh_addralign"], 1)
            new += b"\0" * (-len(new) % al) + sec.data()
    if unit not in ranges:
        return not new
    st, en = ranges[unit]
    rom = __import__("modules").read(target, module)
    old = rom[st:en]
    if len(new) > len(old) or any(old[len(new):]):
        return False
    relocs = set()
    for sec in e.iter_sections():
        if sec.name.startswith(".rel.rodata"):
            for r in sec.iter_relocations():
                relocs.add(r["r_offset"])
    return all(new[i:i + 4] == old[i:i + 4] or i in relocs for i in range(0, len(new) - len(new) % 4, 4))


def own_data(o):
    e = ELFFile(io.BytesIO(o.read_bytes()))
    return sum(s["sh_size"] for s in e.iter_sections()
               if s.name.startswith((".data", ".sdata", ".bss", ".sbss")))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("-v", action="store_true")
    a = ap.parse_args()
    mod = objcmp.module_funcs(a.target, a.module)
    done = total = 0
    ranges = rodata_ranges(a.target, a.module)
    for line in (ROOT / "config" / a.target / f"units.{a.module}.txt").read_text().splitlines():
        p = line.split()
        if len(p) != 3 or "newlib-1.12.0/newlib/" not in p[2]:
            continue
        unit, rel = p[0], p[2].split("newlib-1.12.0/newlib/")[1]
        if "/mallocr/" in unit:
            rel = str(Path(rel).parent / "mallocr.c") if not rel.endswith("mallocr.c") else rel
        f = ROOT / "decomp_src" / a.target / a.module / f"{unit}.c"
        if not f.exists() or "INCLUDE_ASM" not in f.read_text():
            continue
        total += 1
        want = set(re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', f.read_text()))
        text = wrapper(rel, unit)
        with tempfile.TemporaryDirectory() as td:
            o = build(a.target, a.module, unit, text, td)
            if o is None:
                why = "build failed"
            else:
                res = objcmp.compare(mod, [o])
                bad = {k: v for k, v in res.items() if v != "same"}
                if bad:
                    why = " ".join(f"{k}:{v}" for k, v in bad.items())
                elif not want <= set(res):
                    why = "missing " + " ".join(sorted(want - set(res)))
                elif own_data(o):
                    why = "defines data"
                elif not rodata_ok(o, a.target, a.module, unit, ranges):
                    why = "rodata differs"
                else:
                    why = None
                    e = ELFFile(io.BytesIO(o.read_bytes()))
                    defined = {sy.name for sy in e.get_section_by_name(".symtab").iter_symbols()
                               if sy["st_shndx"] != "SHN_UNDEF"}
                    text = wrapper(rel, unit, {n: v for n, v in old_labels(a.target, a.module, unit).items()
                                               if n not in defined and n in used_elsewhere(a.target, a.module, unit)},
                                   max([4] + [sec["sh_addralign"] for sec in e.iter_sections() if sec.name.startswith(".rodata")]))
        if why is None:
            done += 1
            if a.write:
                f.write_text(text)
        if a.v or why is None:
            print(f"{'ok' if why is None else 'NO':3} {unit}" + (f"  ({why})" if why else ""))
    print(f"# {done}/{total} newlib units reproduced from source")


if __name__ == "__main__":
    main()
