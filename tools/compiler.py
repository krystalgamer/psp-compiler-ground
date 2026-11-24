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


def compiler(target, module, unit):
    units = table(ROOT / "config" / target / f"units.{module}.txt")
    comp = table(ROOT / "config" / "compilers.txt")
    ver = units[unit][0] if unit in units else "1.6.1"
    return comp[ver][0]


if __name__ == "__main__":
    print(compiler(*sys.argv[1:4]))
