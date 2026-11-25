#!/usr/bin/env python3
"""linestyle.py ELF [-v]: how each DWARF compile unit's line table moves
the address: SET (a DW_LNE_set_address for every row, as the psp-as that
assembled psp-gcc 1.6.1's newlib wrote it) or ADV (address advances, as
every other psp-as and the 1.3.1 one do).  Counts per (version, lib/app,
style); -v lists the units."""
import collections
import sys

from elftools.elf.elffile import ELFFile

e = ELFFile(open(sys.argv[1], "rb"))
d = e.get_dwarf_info(relocate_dwarf_sections=False)
out = collections.Counter()
for cu in d.iter_CUs():
    top = cu.get_top_DIE()
    nm = top.attributes.get("DW_AT_name")
    nm = nm.value.decode() if nm else "?"
    pr = top.attributes.get("DW_AT_producer")
    pr = pr.value.decode().split("psp-")[-1].split()[0] if pr else "?"
    lp = d.line_program_for_CU(cu)
    sets = adv = 0
    for ent in lp.get_entries():
        if ent.command is None:
            continue
        if ent.is_extended and ent.command == 2:
            sets += 1
        elif not ent.is_extended and (ent.command in (2, 9) or ent.command >= lp.header["opcode_base"]):
            adv += 1
    kind = "lib" if ("newlib" in nm or "bit.c" in nm or "libgcc" in nm) else "app"
    style = "SET" if sets > adv else "ADV"
    out[(pr, kind, style)] += 1
    if "-v" in sys.argv:
        print(pr, kind, style, sets, adv, nm)
for k, v in sorted(out.items()):
    print(v, *k)
