#!/usr/bin/env python3
"""dwarfhdr.py TARGET MODULE HEADER: what DWARF says a header declared.

Collects, from every compile unit of the module, the types and extern
variables whose DW_AT_decl_file is HEADER (a file name such as
pspBrowser.h), and prints them as C ordered by declaration line.  Function
prototypes are not in DWARF and have to be added by hand.
"""
import io
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import modules  # noqa: E402
from dwarf2c import C, attr  # noqa: E402

TYPES = ("DW_TAG_typedef", "DW_TAG_structure_type", "DW_TAG_union_type", "DW_TAG_enumeration_type")


def main():
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("header")
    ap.add_argument("--cu", action="append", help="only these compile units (source names, substring match)")
    a = ap.parse_args()
    t, m, hdr = a.target, a.module, a.header
    elf = ELFFile(io.BytesIO(modules.read(t, m)))
    dw = elf.get_dwarf_info()
    found = {}   # (decl_line, text) -> text
    seen = set()
    for cu in dw.iter_CUs():
        if a.cu and not any(s in attr(cu.get_top_DIE(), "DW_AT_name") for s in a.cu):
            continue
        lp = dw.line_program_for_CU(cu)
        idx = {i + 1 for i, f in enumerate(lp["file_entry"]) if f.name.decode() == hdr}
        if not idx:
            continue
        c = C(cu)
        typedefd = {c.ref(d).offset for d in cu.get_top_DIE().iter_children()
                    if d.tag == "DW_TAG_typedef" and c.ref(d) is not None}
        for d in cu.get_top_DIE().iter_children():
            if attr(d, "DW_AT_decl_file") not in idx:
                continue
            line = attr(d, "DW_AT_decl_line")
            if d.tag in TYPES:
                inner = c.ref(d) if d.tag == "DW_TAG_typedef" else None
                if d.tag != "DW_TAG_typedef" and attr(d, "DW_AT_name") is None and d.offset in typedefd:
                    continue    # emitted with its typedef
                # need() emits what the type refers to first; keep only its own text
                c.out, c.emitted = [], set()
                if inner is not None and inner.tag in TYPES[1:] and attr(inner, "DW_AT_name") is None:
                    c.need(inner)
                    body = c.out[-1].rstrip(";")
                    body = body.replace(c.tag_name(inner), c.tag_name(inner).split()[0], 1)
                    text = f"typedef {body} {attr(d, 'DW_AT_name')};"
                else:
                    c.need(d)
                    text = c.out[-1].replace(c.tag_name(d) + " {", c.tag_name(d).split()[0] + " {", 1) \
                        if attr(d, "DW_AT_name") is None else c.out[-1]
            elif d.tag == "DW_TAG_variable" and attr(d, "DW_AT_name"):
                text = f"extern {c.decl(c.ref(d), attr(d, 'DW_AT_name'))};"
            else:
                continue
            if text not in seen:
                seen.add(text)
                found.setdefault((line, text), f"/* line {line} */\n{text}")
    for line in sorted(found):
        print(found[line])


if __name__ == "__main__":
    main()
