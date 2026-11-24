#!/usr/bin/env python3
"""compiler.py TARGET MODULE UNIT: the cc1 version that builds UNIT."""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


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
    return comp[ver]


def compiler(target, module, unit):
    """cc1 name (tmp/toolchains/bin/cc1-NAME) for a unit."""
    return entry(target, module, unit)[0]


def driver_flags(target, module, unit):
    """cc1 options the unit's psp-gcc driver adds."""
    return " ".join(f for f in entry(target, module, unit)[1:] if not f.startswith("as:"))


def as_flags(target, module, unit):
    """psp-as options standing in for that version's assembler."""
    return " ".join(f[3:] for f in entry(target, module, unit)[1:] if f.startswith("as:"))


if __name__ == "__main__":
    if sys.argv[1] == "--flags":
        print(driver_flags(*sys.argv[2:5]))
    elif sys.argv[1] == "--as-flags":
        print(as_flags(*sys.argv[2:5]))
    else:
        print(compiler(*sys.argv[1:4]))
