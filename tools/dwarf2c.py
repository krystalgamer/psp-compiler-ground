#!/usr/bin/env python3
"""dwarf2c.py TARGET MODULE UNIT [--funcs] : C declarations from a unit's DWARF.

Prints the types (typedefs, structs, unions, enums), global variables and
function prototypes of a compile unit as C, for m2c context and as the start
of the decompiled file.  With --locals, each function's parameters and
local variables (with their types) follow as comments.
"""
import argparse
import io
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import modules  # noqa: E402


def attr(d, k, default=None):
    if k not in d.attributes:
        return default
    v = d.attributes[k].value
    return v.decode(errors="replace") if isinstance(v, bytes) else v


class C:
    def __init__(self, cu):
        self.cu = cu
        self.off = {d.offset: d for d in cu.iter_DIEs()}
        self.names = {}
        self.emitted = set()
        self.out = []
        self.anon = 0

    def ref(self, d, k="DW_AT_type"):
        if k not in d.attributes:
            return None
        return self.off.get(d.attributes[k].value + self.cu.cu_offset)

    def tag_name(self, t):
        n = attr(t, "DW_AT_name")
        kw = {"DW_TAG_structure_type": "struct", "DW_TAG_union_type": "union",
              "DW_TAG_enumeration_type": "enum"}[t.tag]
        if n is None:
            if t.offset not in self.names:
                self.anon += 1
                self.names[t.offset] = f"_anon{self.anon}"
            n = self.names[t.offset]
        return f"{kw} {n}"

    def decl(self, t, name):
        """C declarator for an object of type t called name."""
        if t is None:
            return f"void {name}".rstrip()
        tag = t.tag
        if tag in ("DW_TAG_base_type", "DW_TAG_typedef"):
            if tag == "DW_TAG_typedef":
                self.need(t)
            return f"{attr(t, 'DW_AT_name')} {name}".rstrip()
        if tag in ("DW_TAG_structure_type", "DW_TAG_union_type", "DW_TAG_enumeration_type"):
            self.need(t)
            return f"{self.tag_name(t)} {name}".rstrip()
        if tag == "DW_TAG_const_type":
            inner = self.ref(t)
            if inner is not None and inner.tag == "DW_TAG_pointer_type":
                return self.decl(inner, f"const {name}".rstrip())
            d = self.decl(inner, name)
            return d if d.startswith("const ") else "const " + d
        if tag == "DW_TAG_volatile_type":
            return "volatile " + self.decl(self.ref(t), name)
        if tag == "DW_TAG_pointer_type":
            inner = self.ref(t)
            if inner is not None and inner.tag in ("DW_TAG_subroutine_type", "DW_TAG_array_type"):
                return self.decl(inner, f"(*{name})")
            return self.decl(inner, f"*{name}")
        if tag == "DW_TAG_array_type":
            dims = ""
            for s in t.iter_children():
                if s.tag == "DW_TAG_subrange_type":
                    ub = attr(s, "DW_AT_upper_bound")
                    dims += f"[{ub + 1}]" if isinstance(ub, int) else "[]"
            return self.decl(self.ref(t), f"{name}{dims}")
        if tag == "DW_TAG_subroutine_type":
            params = [self.decl(self.ref(p), "") for p in t.iter_children() if p.tag == "DW_TAG_formal_parameter"]
            if attr(t, "DW_AT_prototyped") and not params:
                params = ["void"]
            if any(p.tag == "DW_TAG_unspecified_parameters" for p in t.iter_children()):
                params.append("...")
            return self.decl(self.ref(t), f"{name}({', '.join(params)})")
        return f"/* {tag} */ int {name}"

    def need(self, t):
        if t.offset in self.emitted:
            return
        self.emitted.add(t.offset)
        if t.tag == "DW_TAG_typedef":
            inner = self.ref(t)
            if (inner is not None and inner.tag in ("DW_TAG_structure_type", "DW_TAG_union_type")
                    and attr(inner, "DW_AT_name") and inner.offset not in self.emitted):
                # typedef first so a self-referencing body can use it
                self.out.append(f"typedef {self.tag_name(inner)} {attr(t, 'DW_AT_name')};")
                self.need(inner)
                return
            # tag types referenced only through a typedef: define them first
            line = f"typedef {self.decl(inner, attr(t, 'DW_AT_name'))};"
            self.out.append(line)
            return
        if t.tag == "DW_TAG_enumeration_type":
            vals = [f"    {attr(e, 'DW_AT_name')} = {attr(e, 'DW_AT_const_value')}," for e in t.iter_children()
                    if e.tag == "DW_TAG_enumerator"]
            self.out.append(f"{self.tag_name(t)} {{\n" + "\n".join(vals) + "\n};")
            return
        if t.tag in ("DW_TAG_structure_type", "DW_TAG_union_type"):
            if attr(t, "DW_AT_declaration"):
                self.out.append(f"{self.tag_name(t)};")
                return
            head = self.tag_name(t)
            self.out.append(f"{head};")
            mark = len(self.out)
            mem = []
            for m in t.iter_children():
                if m.tag != "DW_TAG_member":
                    continue
                n = attr(m, "DW_AT_name") or f"_unnamed{len(mem)}"
                bits = attr(m, "DW_AT_bit_size")
                loc = attr(m, "DW_AT_data_member_location")
                if isinstance(loc, list) and len(loc) >= 2 and loc[0] == 0x23:
                    loc = loc[1] if len(loc) == 2 else int.from_bytes(bytes(loc[1:]), "little")
                d = self.decl(self.ref(m), n)
                mem.append(f"    {d}{' : ' + str(bits) if bits else ''}; /* {loc:#x} */" if isinstance(loc, int)
                           else f"    {d}{' : ' + str(bits) if bits else ''};")
            size = attr(t, "DW_AT_byte_size")
            self.out.append(f"{head} {{ /* size {size:#x} */\n" + "\n".join(mem) + "\n};" if size is not None
                            else f"{head} {{\n" + "\n".join(mem) + "\n};")


def find_cu(elf, src):
    for cu in elf.get_dwarf_info().iter_CUs():
        if attr(cu.get_top_DIE(), "DW_AT_name") == src:
            yield cu


def unit_source(target, module, unit):
    for line in (ROOT / "config" / target / f"units.{module}.txt").read_text().splitlines():
        p = line.split()
        if len(p) == 3 and p[0] == unit:
            return p[2]
    raise SystemExit(f"no unit {unit}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("unit")
    ap.add_argument("--locals", action="store_true")
    ap.add_argument("--extern", action="store_true",
                    help="declare every variable extern (the data stays in the asm)")
    a = ap.parse_args()
    elf = ELFFile(io.BytesIO(modules.read(a.target, a.module)))
    text_addr = elf.get_section_by_name(".text")["sh_addr"]
    src = unit_source(a.target, a.module, a.unit)
    lines = (ROOT / "config" / a.target / f"units.{a.module}.txt").read_text().splitlines()
    # several CUs can share a source name (libgcc); pick the one at the unit's address
    cfg = (ROOT / "config" / a.target / f"{a.module}.yaml").read_text()
    import re
    m = re.search(r"\[0x([0-9A-F]+), c, " + re.escape(a.unit) + r"\]", cfg)
    start = int(m[1], 16) - next(p for p in elf.iter_segments() if p["p_type"] == "PT_LOAD")["p_offset"]
    cu = next((c for c in find_cu(elf, src) if attr(c.get_top_DIE(), "DW_AT_low_pc", -1) + text_addr == start), None)
    if cu is None:
        files = ROOT / "config" / a.target / f"files.{a.module}.txt"
        if files.exists() and any(l.split()[3:4] == [src] for l in files.read_text().splitlines()
                                  if l.strip() and not l.startswith("#")):
            return    # code without DWARF (config/TARGET/files.MODULE.txt): no declarations
        raise SystemExit("compile unit not found")
    c = C(cu)
    top = cu.get_top_DIE()
    globs, funcs = [], []
    for d in top.iter_children():
        if d.tag == "DW_TAG_variable" and attr(d, "DW_AT_name"):
            static = "" if attr(d, "DW_AT_external") else "static "
            ext = "extern " if attr(d, "DW_AT_declaration") or a.extern else static
            globs.append(f"{ext}{c.decl(c.ref(d), attr(d, 'DW_AT_name'))};")
        elif d.tag == "DW_TAG_subprogram" and attr(d, "DW_AT_name"):
            params = [c.decl(c.ref(p), attr(p, "DW_AT_name") or "") for p in d.iter_children()
                      if p.tag == "DW_TAG_formal_parameter"]
            if attr(d, "DW_AT_prototyped") and not params:
                params = ["void"]
            if any(p.tag == "DW_TAG_unspecified_parameters" for p in d.iter_children()):
                params.append("...")
            static = "" if attr(d, "DW_AT_external") else "static "
            proto = f"{static}{c.decl(c.ref(d), attr(d, 'DW_AT_name') + '(' + ', '.join(params) + ')')};"
            funcs.append(proto)
            if "DW_AT_low_pc" in d.attributes:
                loc = []

                def walk(die, depth):
                    for v in die.iter_children():
                        if v.tag == "DW_TAG_variable" and attr(v, "DW_AT_name"):
                            l = attr(v, "DW_AT_location")
                            static = "static " if isinstance(l, list) and l[:1] == [0x03] else ""
                            loc.append("  " * depth + static + c.decl(c.ref(v), attr(v, "DW_AT_name")) + ";")
                        elif v.tag == "DW_TAG_lexical_block":
                            loc.append("  " * depth + "{")
                            walk(v, depth + 1)
                            loc.append("  " * depth + "}")
                walk(d, 1)
                if loc and a.locals:
                    funcs.append(f"/* locals of {attr(d, 'DW_AT_name')}:\n" + "\n".join(loc) + "\n*/")
    print("\n".join(c.out))
    print()
    print("\n".join(globs))
    print()
    print("\n".join(funcs))


if __name__ == "__main__":
    main()
