#!/usr/bin/env python3
"""compiler.py TARGET MODULE UNIT: the cc1 version that builds UNIT."""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LIBS = ("newlib/", "libgcc/", "gcc-3.3.3/")


def table(path):
    out = {}
    for line in path.read_text().splitlines():
        p = line.split()
        if p and not line.startswith("#"):
            out[p[0]] = p[1:]
    return out


def entry(target, module, unit):
    units = table(ROOT / "config" / target / f"units.{module}.txt")
    comp = table(ROOT / "config" / "compilers.txt")
    ver = units[unit][0] if unit in units else "1.6.1"
    # per-module additions for one version: `@TARGET/MODULE VERSION OPT...`
    # (a game's own build, e.g. its link order)
    extra = comp.get(f"@{target}/{module}", [])
    return comp[ver] + (extra[1:] if extra[:1] == [ver] else [])


def is_cxx(target, module, unit):
    """The unit is written in C++ (a `/* lang: c++ */` comment): built by
    cc1plus.  Units of C++ originals written as C (mangled names) stay C."""
    return unit_marker(target, module, unit, "lang: c++")


def program(target, module, unit):
    """cc1 or cc1plus binary name in tmp/toolchains/bin for the unit."""
    return ("cc1plus-" if is_cxx(target, module, unit) else "cc1-") + compiler(target, module, unit)


def compiler(target, module, unit):
    """cc1 name (tmp/toolchains/bin/cc1-NAME) for a unit."""
    return entry(target, module, unit)[0]


def driver_flags(target, module, unit):
    """cc1 options the unit's psp-gcc driver adds."""
    fl = []
    for f in entry(target, module, unit)[1:]:
        if f.startswith("lib:"):
            if unit.startswith(LIBS):
                fl.append(f[4:])
        elif f == "newlib:locfix":
            if unit.startswith("newlib/"):
                fl.append("-g")
        elif f.startswith("mixed:"):
            # only while the unit still has asm functions or rodata
            src = ROOT / "decomp_src" / target / module / f"{unit}.c"
            if src.exists() and "INCLUDE_" in src.read_text():
                fl.append(f[6:])
        elif f == "locfix":
            fl.append("-g")
        elif not f.startswith(("as:", "objorder")):
            fl.append(f)
    if "-g" not in fl and unit_marker(target, module, unit, "locfix"):
        fl.append("-g")
    return " ".join(fl)


def object_order(target, module, unit):
    """True if the unit's .rodata and .rodata.cst* link in the order the
    object has them (its assembler created them as first used) rather than
    .rodata first."""
    return "objorder" in entry(target, module, unit)[1:] and not unit.startswith(LIBS)


def unit_marker(target, module, unit, marker):
    src = ROOT / "decomp_src" / target / module / f"{unit}.c"
    return src.exists() and f"/* {marker} */" in src.read_text(errors="replace")


def locfix(target, module, unit):
    """True if the unit was built with -g and assembled by a psp-as that
    does not move an instruction into a branch delay slot across a source
    line change (tools/locfix.py).  A unit can ask for it with a
    `/* locfix */` comment."""
    return any(f == "locfix" or (f == "newlib:locfix" and unit.startswith("newlib/"))
               for f in entry(target, module, unit)[1:]) or unit_marker(target, module, unit, "locfix")


def as_flags(target, module, unit):
    """psp-as options standing in for that version's assembler."""
    return " ".join(f[3:] for f in entry(target, module, unit)[1:] if f.startswith("as:"))


if __name__ == "__main__":
    if sys.argv[1] == "--flags":
        print(driver_flags(*sys.argv[2:5]))
    elif sys.argv[1] == "--as-flags":
        print(as_flags(*sys.argv[2:5]))
    elif sys.argv[1] == "--prog":
        print(program(*sys.argv[2:5]))
    elif sys.argv[1] == "--cppflags":
        print("-x c++ -D__cplusplus" if is_cxx(*sys.argv[2:5]) else "")
    elif sys.argv[1] == "--locfix":
        print("1" if locfix(*sys.argv[2:5]) else "")
    else:
        print(compiler(*sys.argv[1:4]))
