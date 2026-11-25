#!/usr/bin/env python3
"""libsrc.py TARGET MODULE [--write] [-v]

Compile each newlib or libgcc unit of a module that is still asm from the
original source (newlib 1.12.0, tools/nlcpp.sh; libgcc of the gcc tree as
its libgcc build compiles it, tools/libgcccpp.sh) with the unit's own cc1
and flags, and,
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


def wrapper(rel, unit, equ=(), align=4, base=None):
    if base is None:
        s = f"/* upstream: newlib-1.12.0/newlib/{rel} (unmodified) */\n/* cflags: -O2 -fno-builtin */\n"
        if "/mallocr/" in unit:
            s += "#define INTERNAL_NEWLIB\n#define DEFINE_" + MALLOCR.get(unit.rsplit("/", 1)[1], "MALLOC") + "\n"
        s += f'#include "{rel}"\n'
    else:
        s = base
    if align > 4:
        s = re.sub(r"(cflags: [^\n]*\n)", rf"\1/* data-align: {align} */\n", s, count=1)
    if equ:
        s += "\n/* labels the rest of the module's asm uses */\n"
        s += "".join((f'__asm__(".globl {n}\\n{n} = 0x{v:08X}");\n' if g else f'__asm__("{n} = 0x{v:08X}");\n')
                     for n, (v, g) in sorted(equ.items(), key=lambda x: x[1]))
    return s


def build(target, module, unit, text, td):
    c = Path(td) / "u.c"
    c.write_text(text)
    cpp = "nlcpp.sh" if "upstream: newlib" in text else "libgcccpp.sh"
    i = subprocess.run([str(ROOT / "tools" / cpp), str(c)], capture_output=True, text=True)
    if i.returncode:
        return None
    cc1 = T / f"cc1-{compiler.compiler(target, module, unit)}"
    flags = re.search(r"cflags: (.*?) \*/", text)[1].split() + compiler.driver_flags(target, module, unit).split()
    s = Path(td) / "u.s"
    r = subprocess.run([str(cc1), *flags, "-G0", "-quiet", "-o", str(s)],
                       input=i.stdout, capture_output=True, text=True)
    if r.returncode:
        return None
    o = Path(td) / "u.o"
    asf = subprocess.run([sys.executable, str(ROOT / "tools/compiler.py"), "--as-flags", target, module, unit],
                         capture_output=True, text=True).stdout.split()
    if compiler.locfix(target, module, unit):
        subprocess.run([sys.executable, str(ROOT / "tools/locfix.py"), str(s)], check=True)
    r = subprocess.run([str(T / "psp-as"), *asf, "-EL", "-G0", "-o", str(o), str(s)], capture_output=True)
    return o if r.returncode == 0 else None


def rodata_ranges(target, module):
    """unit -> (rom start, rom end) of its .rodata entry in the splat config"""
    ents = [(int(m[1], 16), m[2], m[3]) for m in
            re.finditer(r"- \[0x([0-9A-F]+), (\.?\w+), ([\w/.-]+)\]", (ROOT / "config" / target / f"{module}.yaml").read_text())]
    out = {}
    for i, (st, kind, name) in enumerate(ents):
        if kind == ".rodata" and i + 1 < len(ents):
            out[name] = (st, ents[i + 1][0])
    return out


def old_labels(target, module, unit, rom=False):
    """labels the asm stub of a unit defines: name -> vram (or (rom, vram))"""
    out = {}
    d = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit
    for f in d.glob("*.s"):
        t = f.read_text()
        for m in re.finditer(r"^(?:glabel|dlabel|jlabel|alabel)\s+(\w+)\s*\n(?:\s*\n)*\s*/\* ([0-9A-F]+) ([0-9A-F]{8})", t, re.M):
            out[m[1]] = (int(m[2], 16), int(m[3], 16)) if rom else int(m[3], 16)
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
    if unit is None:
        return set(_words[(target, module)])
    own = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit
    return {w for w, ds in _words[(target, module)].items() if ds - {own}}


def paired_undefined(o, target, module, unit):
    """undefined symbols of the new object that the module's asm knows only by
    an address label (D_XXXXXXXX): name -> address, from the label the old asm
    of the same function uses at the same instruction"""
    e = ELFFile(io.BytesIO(o.read_bytes()))
    symtab = e.get_section_by_name(".symtab")
    syms = list(symtab.iter_symbols())
    known = used_elsewhere(target, module, None)
    funcs = sorted((sy["st_value"], sy.name) for sy in syms
                   if sy["st_info"]["type"] == "STT_FUNC" and sy["st_shndx"] != "SHN_UNDEF")
    rel = e.get_section_by_name(".rel.text")
    out = {}
    if rel is None:
        return out
    d = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit
    for r in rel.iter_relocations():
        sy = syms[r["r_info_sym"]]
        if sy["st_shndx"] != "SHN_UNDEF" or sy.name in known or sy.name in out:
            continue
        fa, fn = max((f for f in funcs if f[0] <= r["r_offset"]), default=(None, None))
        f = d / f"{fn}.s"
        if fn is None or not f.exists():
            continue
        ins = re.findall(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/[^\n]*?%(?:hi|lo)\((D_([0-9A-F]{8}))\)", f.read_text())
        if not ins:
            continue
        base = min(int(v, 16) for v, _, _ in re.findall(r"/\* [0-9A-F]+ ([0-9A-F]{8}) [0-9A-F]{8} \*/()()", f.read_text()))
        for v, _, addr in ins:
            if int(v, 16) - base == r["r_offset"] - fa:
                out[sy.name] = int(addr, 16)
    return out


def rodata_ok(o, target, module, unit, ranges):
    e = ELFFile(io.BytesIO(o.read_bytes()))
    new = b""
    for sec in e.iter_sections():
        if sec.name.startswith(".rodata"):
            al = max(sec["sh_addralign"], 1)
            new += b"\0" * (-len(new) % al) + sec.data()
    if unit not in ranges:
        return not new, 0
    st, en = ranges[unit]
    rom = __import__("modules").read(target, module)
    old = rom[st:en]
    if len(new) > len(old) or any(old[len(new):]):
        return False, 0
    # labels of the stub past the new bytes belong to objects without code
    if any(st + len(new) <= r < en for r, _ in old_labels(target, module, unit, rom=True).values()):
        return False, 0
    relocs = set()
    for sec in e.iter_sections():
        if sec.name.startswith(".rel.rodata"):
            for r in sec.iter_relocations():
                relocs.add(r["r_offset"])
    ok = all(new[i:i + 4] == old[i:i + 4] or i in relocs for i in range(0, len(new) - len(new) % 4, 4))
    return ok, len(new)


def next_rodata(target, module, unit):
    """the yaml entry after UNIT's .rodata: (kind, name, rom start)"""
    ents = [(int(m[1], 16), m[2], m[3]) for m in
            re.finditer(r"- \[0x([0-9A-F]+), (\.?\w+), ([\w/.-]+)\]", (ROOT / "config" / target / f"{module}.yaml").read_text())]
    for i, (st, kind, name) in enumerate(ents):
        if kind == ".rodata" and name == unit and i + 1 < len(ents):
            return ents[i + 1][1], ents[i + 1][2], ents[i + 1][0]
    return None


def fix_gap(target, module, unit, ranges, newlen, write):
    """The old stub's rodata ended in padding that the original's next object
    aligned away; give that next object (still a stub) its alignment back.
    Returns False when that cannot be done."""
    st, en = ranges[unit]
    if newlen == en - st:
        return True
    nx = next_rodata(target, module, unit)
    if not nx or nx[0] != ".rodata":
        return False
    a = next((a for a in (8, 16) if -(-(st + newlen) // a) * a == en), None)
    f = ROOT / "decomp_src" / target / module / f"{nx[1]}.c"
    if a is None or not f.exists():
        return False
    t = f.read_text()
    m = re.search(r"data-align: (\d+)", t)
    if "upstream:" in t:
        return bool(m) and int(m[1]) >= a
    if write and not (m and int(m[1]) >= a):
        t = re.sub(r"/\* data-align: \d+ \*/\n", "", t)
        f.write_text(f"/* data-align: {a} */\n" + t)
    return True


_libgcc = {}


def libgcc_objects(tree):
    """object of tree's libgcc.a -> (source, [defines], functions)"""
    if tree not in _libgcc:
        b = ROOT / "tmp" / "gccbuild" / tree / "gcc-bin"
        cmds = {}
        for m in re.finditer(r"((?: -D\S+)+) -c (\S+)((?: -f\S+)*) -o libgcc/\./(\S+)\.o", (b / "make-all.log").read_text()):
            defs = [d[2:] for d in m[1].split() if d.startswith("-DL_") or d.startswith("-DFINE")]
            cmds[m[4]] = (m[2].split("gcc-3.3.3/gcc/")[-1], defs, m[3].strip())
        out = {}
        for n, data in objcmp.members(b / "gcc" / "libgcc.a"):
            n = n[:-2]
            if n in cmds:
                out[n] = (*cmds[n], set(objcmp.obj_funcs(data)))
        _libgcc[tree] = out
    return _libgcc[tree]


def libgcc_wrapper(target, module, unit, funcs):
    cc = compiler.compiler(target, module, unit)
    tree = cc if cc in ("1.5.1", "1.6.1") else "1.6.1"
    for n, (src, defs, fl, fns) in libgcc_objects(tree).items():
        if fns == funcs:
            return (f"/* upstream: libgcc {src} ({n}.o), tree: {tree} */\n/* cflags: {' '.join(['-O2', *fl.split()])} */\n" +
                    "".join(f"#define {d.replace('=', ' ', 1)}\n" for d in defs) + f'#include "{src}"\n')
    return None


def own_data(o):
    e = ELFFile(io.BytesIO(o.read_bytes()))
    return sum(s["sh_size"] for s in e.iter_sections()
               if s.name.startswith((".data", ".sdata", ".bss", ".sbss", ".gcc_except_table")))


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
        if len(p) != 3 or not ("newlib-1.12.0/newlib/" in p[2] or p[0].startswith("libgcc/")):
            continue
        unit = p[0]
        f = ROOT / "decomp_src" / a.target / a.module / f"{unit}.c"
        if not f.exists() or "INCLUDE_ASM" not in f.read_text():
            continue
        total += 1
        want = set(re.findall(r'INCLUDE_ASM\("[^"]+", (\w+)\);', f.read_text()))
        if unit.startswith("libgcc/"):
            rel, base = None, libgcc_wrapper(a.target, a.module, unit, want)
            if base is None:
                if a.v:
                    print(f"NO  {unit}  (no libgcc object with these functions)")
                continue
        else:
            rel, base = p[2].split("newlib-1.12.0/newlib/")[1], None
            if "/mallocr/" in unit:
                rel = str(Path(rel).parent / "mallocr.c") if not rel.endswith("mallocr.c") else rel
        text = wrapper(rel, unit, base=base)
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
                elif not (ro := rodata_ok(o, a.target, a.module, unit, ranges))[0]:
                    why = "rodata differs"
                elif unit in ranges and not fix_gap(a.target, a.module, unit, ranges, ro[1], a.write):
                    why = "rodata padding before asm"
                else:
                    why = None
                    e = ELFFile(io.BytesIO(o.read_bytes()))
                    defined = {sy.name for sy in e.get_section_by_name(".symtab").iter_symbols()
                               if sy["st_shndx"] != "SHN_UNDEF"}
                    equ = {n: (v, True) for n, v in old_labels(a.target, a.module, unit).items()
                           if n not in defined and n in used_elsewhere(a.target, a.module, unit)}
                    equ.update({n: (v, False) for n, v in paired_undefined(o, a.target, a.module, unit).items()})
                    text = wrapper(rel, unit, equ,
                                   max([4] + [sec["sh_addralign"] for sec in e.iter_sections() if sec.name.startswith(".rodata")]),
                                   base)
        if why is None:
            done += 1
            if a.write:
                f.write_text(text)
        if a.v or why is None:
            print(f"{'ok' if why is None else 'NO':3} {unit}" + (f"  ({why})" if why else ""))
    print(f"# {done}/{total} newlib/libgcc units reproduced from source")


if __name__ == "__main__":
    main()
