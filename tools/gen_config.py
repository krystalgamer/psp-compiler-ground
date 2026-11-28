#!/usr/bin/env python3
"""Generate the splat config of a module from its ELF.

Usage: tools/gen_config.py TARGET MODULE [--force]
  TARGET  puzzle_bobble, sampler, UTST99261 or UTST99332
  MODULE  module name (BOOT, sampler, menu, graphics_cube, ...)

The modules keep their DWARF, so .text is split into one subsegment per
compile unit, named after its source file (the C file
decomp_src/TARGET/MODULE/<source>.c); the compiler that built it, from the
CU's DW_AT_producer, goes into config/TARGET/units.MODULE.txt.  Code
without debugging information (SDK libraries) stays asm, one subsegment
per run between compile units.  Symbol names come from the module's own
symbol table (config/TARGET/symbol_addrs.MODULE.txt).

Segment 0 (code + rodata) is one splat segment at vram 0; segment 1 (.data,
.bss) becomes `<name>_seg1`, linked at VMA 0 because PRX segment 1 is
relocated independently.  Gaps between sections become `prxpad`.
"""
import argparse
import collections
import hashlib
import io
import os
import re
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

sys.path.insert(0, str(Path(__file__).resolve().parent))
import modules  # noqa: E402
import prxinfo  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SPECIAL = {
    ".sceStub.text": ("asm", "sceStub"),
    ".lib.ent.top": ("rodata", "lib_ent_top"),
    ".lib.ent": ("rodata", "lib_ent"),
    ".lib.ent.btm": ("rodata", "lib_ent_btm"),
    ".lib.stub.top": ("rodata", "lib_stub_top"),
    ".lib.stub": ("rodata", "lib_stub"),
    ".lib.stub.btm": ("rodata", "lib_stub_btm"),
    ".rodata.sceModuleInfo": ("rodata", "module_info"),
    ".rodata.sceResident": ("rodata", "resident"),
    ".rodata.sceNid": ("rodata", "nid"),
}

OPTIONS = """  find_file_boundaries: false
  section_order: [".text", ".data", ".rodata", ".bss"]
  migrate_rodata_to_functions: true
  use_legacy_include_asm: false
  generate_asm_macros_files: false
  asm_function_macro: glabel
  asm_jtbl_label_macro: jlabel
  asm_data_macro: dlabel
  asm_end_label: endlabel
  string_encoding: ASCII
  data_string_encoding: ASCII
  rodata_string_guesser_level: 2
  data_string_guesser_level: 2
  gp_value: 0x7FF0
  add_set_gp_64: false
  named_regs_for_c_funcs: false
  ld_bss_is_noload: true
  emit_subalign: false
  ld_align_segment_vram_end: false
  ld_align_section_vram_end: false
  disasm_unknown: true
"""


def compile_units(elf):
    """(low_pc, high_pc, source name, compiler version) of each CU with code."""
    out = []
    if not elf.has_dwarf_info():
        return out
    for cu in elf.get_dwarf_info().iter_CUs():
        a = cu.get_top_DIE().attributes
        if "DW_AT_low_pc" not in a or "DW_AT_high_pc" not in a:
            continue
        lo, hi = a["DW_AT_low_pc"].value, a["DW_AT_high_pc"].value
        if hi <= lo:
            continue
        prod = a["DW_AT_producer"].value.decode() if "DW_AT_producer" in a else ""
        ver = prod.split("-psp-")[1].split()[0] if "-psp-" in prod else "?"
        out.append((lo, hi, a["DW_AT_name"].value.decode(), ver))
    return sorted(out)


def file_units(t, name, cus, text_end):
    """Units of code without DWARF, from config/TARGET/files.MODULE.txt
    (vram start, unit, compiler, source; see the file for how they were
    found).  Each runs to the next listed start or compile unit."""
    path = ROOT / "config" / t / f"files.{name}.txt"
    if not path.exists():
        return []
    ents = []
    for line in path.read_text().splitlines():
        line = line.split("#")[0].split()
        if line and line[0] not in ("rodata", "bss", "dataunit", "cst4", "cst8"):
            ents.append((int(line[0], 16), line[3], line[2]))
            NODWARF_UNITS.update({line[1], os.path.splitext(line[3])[0]})
    bounds = sorted([e[0] for e in ents] + [c[0] for c in cus] + [text_end])
    return [(lo, next(b for b in bounds if b > lo), src, ver) for lo, src, ver in ents]


def rodata_overrides(t, name):
    """`rodata ADDR UNIT` lines of files.MODULE.txt: .rodata from ADDR on
    belongs to UNIT (strings only a .data table points to); UNIT `-`: to
    none (stays asm)."""
    path = ROOT / "config" / t / f"files.{name}.txt"
    if not path.exists():
        return []
    out = []
    for line in path.read_text().splitlines():
        line = line.split("#")[0].split()
        if line and line[0] == "rodata" and line[1] != "blob":
            out.append((int(line[1], 16), line[2]))
    return out


def data_units(t, name):
    """`dataunit UNIT VERSION SOURCE` lines of files.MODULE.txt: units with
    data but no code (e.g. newlib's s_infconst, impure); a `rodata ADDR UNIT`
    line places their .rodata."""
    path = ROOT / "config" / t / f"files.{name}.txt"
    if not path.exists():
        return {}
    out = {}
    for line in path.read_text().splitlines():
        line = line.split("#")[0].split()
        if line and line[0] == "dataunit":
            out[line[1]] = (line[2], line[3])
    return out


def bss_overrides(t, name):
    """`bss ADDR UNIT` lines of files.MODULE.txt (opt-in): segment 1's .bss
    from ADDR (vram) on is UNIT's C object's .bss; UNIT `-`: asm again."""
    path = ROOT / "config" / t / f"files.{name}.txt"
    if not path.exists():
        return []
    out = []
    for line in path.read_text().splitlines():
        line = line.split("#")[0].split()
        if line and line[0] == "bss":
            out.append((int(line[1], 16), line[2]))
    return sorted(out)


def rodata_blob(t, name):
    """A `rodata blob` line in files.MODULE.txt: .rodata stays asm, however
    the units' references split it, except the `rodata ADDR UNIT` ranges."""
    path = ROOT / "config" / t / f"files.{name}.txt"
    return path.exists() and any(l.split("#")[0].split()[:2] == ["rodata", "blob"]
                                 for l in path.read_text().splitlines())


def unit_name(src, used):
    """decomp_src-relative stem for a CU's source file name."""
    s = src.replace("\\", "/")
    # newlib sources: ../../../../../newlib-1.12.0/newlib/libc/x/y.c
    m = re.search(r"newlib-[\d.]+/(newlib/.*)$", s)
    if m:
        s = m.group(1)
    s = re.sub(r"^(\.\./)+", "", s).lstrip("/")
    # libgcc, built by Sony with the compiler itself
    s = re.sub(r"^(gcc-[\d.]+/gcc/)?((fp|dp)-bit|libgcc2)\b", r"libgcc/\2", s)
    s = re.sub(r"\.(c|cpp|cc|s|S)$", "", s)
    s = re.sub(r"[^\w/.-]", "_", s)
    base, n = s, 2
    while s in used:
        s = f"{base}_{n}"
        n += 1
    used.add(s)
    return s


def symbols(elf):
    """The ELF's symbols, none for stripped modules."""
    st = elf.get_section_by_name(".symtab")
    return st.iter_symbols() if st is not None else []


def symbol_lines(elf, text_end):
    """symbol_addrs lines from the ELF symbol table, names made unique."""
    syms = collections.defaultdict(list)
    for sym in symbols(elf):
        t = sym["st_info"]["type"]
        if t not in ("STT_FUNC", "STT_OBJECT", "STT_NOTYPE") or not sym.name:
            continue
        if sym["st_shndx"] in ("SHN_UNDEF", "SHN_ABS"):
            continue
        if sym.name.startswith(("$", ".L", "__")) and t == "STT_NOTYPE":
            continue
        if not elf.get_section(sym["st_shndx"])["sh_flags"] & 2:
            continue
        addr = sym["st_value"] + elf.get_section(sym["st_shndx"])["sh_addr"]
        syms[sym.name].append((addr, t, sym["st_size"], sym["st_info"]["bind"] == "STB_GLOBAL"))
    by_addr = {}
    for name, ents in syms.items():
        uniq = sorted(set(ents))
        # a duplicated name stays plain for its one global definition (what
        # C elsewhere links against); the static ones get the address
        glob = [e for e in uniq if e[3]]
        for (addr, t, size, g) in uniq:
            nm = name if len(uniq) == 1 or (g and len(glob) == 1) else f"{name}_{addr:X}"
            if not re.match(r"^[A-Za-z_]\w*$", nm):
                continue
            prev = by_addr.get(addr)
            # prefer functions, then sized objects, then plain labels
            rank = {"STT_FUNC": 0, "STT_OBJECT": 1, "STT_NOTYPE": 2}[t]
            if prev is None or rank < prev[0]:
                by_addr[addr] = (rank, nm, t, size)
    out = []
    for addr in sorted(by_addr):
        rank, nm, t, size = by_addr[addr]
        extra = ""
        if t == "STT_FUNC":
            extra = " // type:func" + (f" size:0x{size:X}" if size else "")
        elif t == "STT_OBJECT" and size:
            extra = f" // size:0x{size:X}"
        out.append(f"{nm} = 0x{addr:08X};{extra}")
    return out


def sext16(x):
    return x - 0x10000 if x & 0x8000 else x


def dwarf_objects(elf, text_addr, rodata):
    """{addr: (size, CU low_pc)} for the variables DWARF places in a section
    (rodata: the section, with .name and .addr).

    DW_OP_addr values are section-relative like the symbols, so a variable
    is matched to the section's symbol with its name and value."""
    if not elf.has_dwarf_info() or rodata is None:
        return {}
    syms = {}
    ro = None
    for i, sec in enumerate(elf.iter_sections()):
        if sec.name == rodata.name:
            ro = i
    for sym in symbols(elf):
        if sym["st_shndx"] == ro and sym["st_info"]["type"] == "STT_OBJECT":
            syms[(sym.name, sym["st_value"])] = sym["st_size"]
    out = {}
    for cu in elf.get_dwarf_info().iter_CUs():
        top = cu.get_top_DIE()
        if "DW_AT_low_pc" not in top.attributes:
            continue
        lo = top.attributes["DW_AT_low_pc"].value + text_addr
        stack = [top]
        while stack:
            for d in stack.pop().iter_children():
                if d.tag == "DW_TAG_subprogram" or d.tag == "DW_TAG_lexical_block":
                    stack.append(d)
                if d.tag != "DW_TAG_variable" or "DW_AT_location" not in d.attributes:
                    continue
                loc = d.attributes["DW_AT_location"].value
                if not isinstance(loc, list) or len(loc) != 5 or loc[0] != 3:
                    continue
                v = int.from_bytes(bytes(loc[1:]), "little")
                n = d.attributes["DW_AT_name"].value.decode() if "DW_AT_name" in d.attributes else None
                if (n, v) in syms:
                    out[v + rodata.addr] = (max(syms[(n, v)], 1), lo)
    return out


NODWARF_UNITS = set()


def rodata_owners(elf, data, segs, units, rodata):
    """Split .rodata among the units by the code that references it.

    Returns [(addr, unit index or None)] boundaries, or None when the
    references don't give each unit one contiguous range in link order.
    """
    starts = [u[0] for u in units]
    import bisect

    def unit_at(a):
        i = bisect.bisect_right(starts, a) - 1
        return i if i >= 0 else None

    word = lambda off: struct.unpack_from("<I", data, off)[0]
    unit_of_lo = {u[0]: i for i, u in enumerate(units)}
    objs = dwarf_objects(elf, next(s.addr for s in prxinfo.sections(elf, data) if s.name == ".text"), rodata)
    obj_spans = sorted((a, a + sz, unit_of_lo.get(lo)) for a, (sz, lo) in objs.items())
    obj_starts = [o[0] for o in obj_spans]

    def obj_owner(a):
        i = bisect.bisect_right(obj_starts, a) - 1
        if i >= 0 and a < obj_spans[i][1]:
            return obj_spans[i]
        return None
    dsec = next((s for s in prxinfo.sections(elf, data) if s.name == ".data"), None)
    dobjs = dwarf_objects(elf, next(s.addr for s in prxinfo.sections(elf, data) if s.name == ".text"), dsec)
    dspans = sorted((a, a + sz, unit_of_lo.get(lo)) for a, (sz, lo) in dobjs.items())
    dstarts = [o[0] for o in dspans]

    def data_owner(a):
        i = bisect.bisect_right(dstarts, a) - 1
        if i >= 0 and a < dspans[i][1]:
            return dspans[i][2]
        return None
    anon_ptrs = []
    refs = collections.defaultdict(set)   # rodata addr -> units
    for a, b, u in obj_spans:
        if u is not None:
            refs[a].add(u)
    for d in prxinfo.reloc_tables(elf):
        ents = [struct.unpack_from("<II", d, i) for i in range(0, len(d), 8)]
        hi = {}
        for i, (ofs, info) in enumerate(ents):
            typ, ob, ab = info & 0xFF, (info >> 8) & 0xFF, (info >> 16) & 0xFF
            if ob >= len(segs) or ab >= len(segs):
                continue
            loc = segs[ob]["p_vaddr"] + ofs
            insn = word(segs[ob]["p_offset"] + ofs)
            if typ == 5:
                hi[ab] = insn & 0xFFFF
                continue
            if typ == 6:
                target = (hi.get(ab, 0) << 16) + sext16(insn & 0xFFFF) + segs[ab]["p_vaddr"]
                src = unit_at(loc) if loc < units[-1][0] + 0x10000000 and loc < rodata.addr else None
            elif typ == 2 and dsec is not None and dsec.addr <= loc < dsec.addr + dsec.size:
                # strings an initialized pointer in .data points to
                ptr = insn + segs[ab]["p_vaddr"]
                src = data_owner(loc)
                if src is not None and rodata.addr <= ptr < rodata.addr + rodata.size and obj_owner(ptr) is None:
                    refs[ptr].add(src)
                continue
            elif typ == 2 and rodata.addr <= loc < rodata.addr + rodata.size:
                # e.g. jump tables: owned by the unit of the code they point to
                ptr = insn + segs[ab]["p_vaddr"]
                if ptr < rodata.addr:
                    target, src = loc, unit_at(ptr)
                elif ptr < rodata.addr + rodata.size and obj_owner(loc) is not None:
                    # e.g. a const table of strings: they go with the table
                    target, src = ptr, obj_owner(loc)[2]
                    if src is not None and obj_owner(ptr) is None:
                        refs[target].add(src)
                    continue
                elif ptr < rodata.addr + rodata.size:
                    # an unnamed table (a local array's initializer): its
                    # strings go with the code that uses the table
                    anon_ptrs.append((loc, ptr))
                    continue
                else:
                    continue
            else:
                continue
            if src is not None and rodata.addr <= target < rodata.addr + rodata.size:
                o = obj_owner(target)
                if o is not None:
                    continue    # a named object: owned by the unit DWARF puts it in
                refs[target].add(src)
    starts_sorted = sorted(refs)
    for loc, ptr in anon_ptrs:
        i = bisect.bisect_right(starts_sorted, loc) - 1
        if i >= 0 and len(refs[starts_sorted[i]]) == 1 and obj_owner(ptr) is None:
            refs[ptr] |= refs[starts_sorted[i]]
    first = {}
    last = {}
    for a in sorted(refs):
        if len(refs[a]) != 1:
            continue
        u = next(iter(refs[a]))
        first.setdefault(u, a)
        last[u] = a
    order = sorted(first, key=lambda u: first[u])
    import os
    if os.environ.get("RODATA_DEBUG"):
        for u in order:
            print(f"  {u:4} {units[u][2]:40} {first[u]:#x}-{last[u]:#x} {sorted(a for a in refs if refs[a]=={u})[:6]}", file=sys.stderr)
    if order != sorted(order):
        # only for modules mixing DWARF and nodwarf units (UTST99261)
        if not NODWARF_UNITS or all(units[u][2] in NODWARF_UNITS for u in order):
            return None
        # keep the heaviest set of units whose first references are in link
        # order (DWARF units weigh more than nodwarf ones); the others get no
        # rodata of their own and stay with their neighbours
        w = [1 if units[u][2] in NODWARF_UNITS else 1000 for u in order]
        best = [0] * len(order)
        prev = [-1] * len(order)
        for i, u in enumerate(order):
            best[i] = w[i]
            for j in range(i):
                if order[j] < u and best[j] + w[i] > best[i]:
                    best[i], prev[i] = best[j] + w[i], j
        i = max(range(len(order)), key=best.__getitem__)
        keep = []
        while i >= 0:
            keep.append(order[i])
            i = prev[i]
        dropped = [units[u][2] for u in order if u not in keep]
        print(f"rodata: {len(dropped)} units out of order get no rodata: {' '.join(dropped)}", file=sys.stderr)
        order = keep[::-1]
    # ranges may overlap: the linker merges equal constants and strings
    # across objects; each unit starts at its first own reference
    out = []
    pos = rodata.addr
    for u in order:
        a = first[u] & ~3
        if a > pos and not out:
            out.append((pos, None))
        out.append((max(a, pos), u))
        pos = max(a, pos)
    if not out:
        return None
    if out[0][0] != rodata.addr:
        out.insert(0, (rodata.addr, None))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("--force", action="store_true")
    args = ap.parse_args()
    t, name = args.target, args.module

    data = modules.read(t, name)
    sha1 = hashlib.sha1(data).hexdigest()
    elf = ELFFile(io.BytesIO(data))
    segs = [p for p in elf.iter_segments() if p["p_type"] == "PT_LOAD"]
    secs = prxinfo.sections(elf, data)
    seg1 = segs[1]
    text = next(s for s in secs if s.name == ".text")
    text_end = max(s.addr + s.size for s in secs if s.executable)

    def in_seg1(s):
        return s.addr >= seg1["p_vaddr"]

    # .text subsegments: one per CU; code between CUs stays asm
    units, used = [], set()
    # DWARF and symbol values are section-relative: the modules are
    # relocatable (PRX) ELFs whose .text does not start at 0
    cus = [(lo + text.addr, hi + text.addr, src, ver) for lo, hi, src, ver in compile_units(elf)]
    cus = [c for c in cus if text.addr <= c[0] < text.addr + text.size]
    cus += file_units(t, name, cus, text.addr + text.size)
    cus.sort()
    func_at = {}
    for sym in symbols(elf):
        if sym["st_info"]["type"] == "STT_FUNC" and sym.name and isinstance(sym["st_shndx"], int):
            func_at.setdefault(sym["st_value"] + elf.get_section(sym["st_shndx"])["sh_addr"], sym.name)
    srcs = collections.Counter(c[2] for c in cus)
    pos = text.addr
    for lo, hi, src, ver in cus:
        if lo > pos:
            units.append((pos, "asm", f"asm/text_{pos:X}", None, None))
        if lo < pos:
            sys.exit(f"overlapping compile units at {lo:#x}")
        stem = src
        if srcs[src] > 1 and lo in func_at:
            # libgcc's fp-bit.c/dp-bit.c/libgcc2.c: one object per function
            stem = re.sub(r"\.(c|S|s)$", "", src) + "/" + func_at[lo] + ".c"
        units.append((lo, "c", unit_name(stem, used), ver, src))
        pos = hi
    if pos < text.addr + text.size:
        units.append((pos, "asm", f"asm/text_{pos:X}", None, None))

    out = []
    a = f"tmp/asm/{t}/{name}"
    b = f"tmp/build/{t}"
    out.append(f"name: {name} ({t})\nsha1: {sha1}\noptions:\n  basename: {name}\n"
               f"  target_path: tmp/baserom/{t}/{name}.prx\n  elf_path: {b}/{name}.elf\n"
               f"  base_path: ../..\n  platform: psp\n  compiler: GCC\n\n"
               f"  asm_path: {a}\n  src_path: decomp_src/{t}/{name}\n  build_path: {b}\n"
               f"  ld_script_path: {b}/{name}.ld\n  cache_path: {b}/.splat_cache.{name}\n"
               f"  symbol_addrs_path:\n    - config/{t}/symbol_addrs.{name}.txt\n    - {b}/prx_syms.{name}.txt\n"
               f"  reloc_addrs_path: [{b}/reloc_addrs.{name}.txt]\n  asset_path: tmp/assets/{t}/{name}\n"
               f"  extensions_path: tools/splat_ext\n"
               f"  undefined_funcs_auto_path: {b}/undefined_funcs_auto.{name}.txt\n"
               f"  undefined_syms_auto_path: {b}/undefined_syms_auto.{name}.txt\n\n")
    mi = prxinfo.module_info_addr(elf, data)
    gp_value = struct.unpack_from("<I", data, segs[0]["p_offset"] + mi + 0x20)[0] if mi is not None else 0x7FF0
    out.append(OPTIONS.replace("gp_value: 0x7FF0", f"gp_value: 0x{gp_value:X}"))
    end_vram = max(s.addr + s.size for s in secs)
    out.append(f"  global_vram_start: 0x0\n  global_vram_end: 0x{end_vram + 0x10:X}\n\n")

    out.append("segments:\n  - [0x0, bin, elf_header]\n")
    out.append(f"  - name: {name}\n    type: code\n    start: 0x{segs[0]['p_offset']:X}\n    vram: 0x0\n    subsegments:\n")
    off0 = segs[0]["p_offset"]
    prev_end, prev_kind = None, ".text"
    for s in secs:
        if in_seg1(s) or s.nobits or not s.size:
            continue
        off = s.offset
        if prev_end is not None and off > prev_end:
            out.append(f"      - {{ start: 0x{prev_end:X}, type: prxpad, order: {prev_kind} }}\n")
        if s.name == ".text":
            for addr, typ, nm, ver, src in units:
                out.append(f"      - [0x{addr + off0:X}, {typ}, {nm}]\n")
            prev_kind = ".text"
        elif s.name in SPECIAL:
            typ, nm = SPECIAL[s.name]
            out.append(f"      - {{ start: 0x{off:X}, type: {typ}, name: {nm}, linker_section: {s.name} }}\n")
            prev_kind = ".text" if typ == "asm" else ".rodata"
        elif s.name == ".rodata":
            owners = None if rodata_blob(t, name) else rodata_owners(elf, data, segs, units, s)
            overrides = rodata_overrides(t, name)
            if owners is None and overrides:
                # references out of unit order: only the hand-made split
                # (`rodata ADDR UNIT` lines), the rest stays asm
                owners = [(s.addr, None)]
            if owners is not None:
                dunits = data_units(t, name)
                for addr, uname in overrides:
                    # `rodata ADDR -`: from ADDR on the rodata belongs to no unit (stays asm)
                    ui = None if uname == "-" else uname if uname in dunits else \
                        next(i for i, u in enumerate(units) if u[2] == uname)
                    owners = sorted([o for o in owners if o[0] != addr] + [(addr, ui)])
                owners = [o for i, o in enumerate(owners) if i == 0 or o[1] is None or o[1] != owners[i - 1][1]]
            if owners is None:
                out.append(f"      - [0x{off:X}, rodata, rodata]\n")
            else:
                for addr, ui in owners:
                    if isinstance(ui, str):
                        out.append(f"      - [0x{addr - s.addr + off:X}, .rodata, {ui}]\n")
                    elif ui is not None and units[ui][1] == "c":
                        out.append(f"      - [0x{addr - s.addr + off:X}, .rodata, {units[ui][2]}]\n")
                    else:
                        out.append(f"      - [0x{addr - s.addr + off:X}, rodata, asm/rodata_{addr:X}]\n")
            prev_kind = ".rodata"
        else:
            nm = s.name.strip(".").replace(".", "_")
            typ = "asm" if s.executable else "rodata"
            out.append(f"      - {{ start: 0x{off:X}, type: {typ}, name: {nm}, linker_section: {s.name} }}\n")
            prev_kind = ".text" if typ == "asm" else ".rodata"
        prev_end = off + s.size
    seg0_end = segs[0]["p_offset"] + segs[0]["p_filesz"]
    if prev_end < seg0_end:
        out.append(f"      - {{ start: 0x{prev_end:X}, type: prxpad, order: {prev_kind} }}\n")
    if seg0_end < seg1["p_offset"]:
        # file alignment of segment 1: no memory behind it, so not part of
        # segment 0 (whose vram range would then overlap segment 1's)
        out.append(f"  - [0x{seg0_end:X}, bin, seg1_align]\n")

    base = seg1["p_vaddr"]
    s1 = [s for s in secs if in_seg1(s) and s.size]
    fpos = seg1["p_offset"]
    # kernel modules without data have nothing in segment 1
    if s1:
        out.append(f"  - name: {name}_seg1\n    type: code\n    start: 0x{seg1['p_offset']:X}\n    vram: 0x{base:X}\n")
        if any(s.nobits for s in s1):
            out.append(f"    bss_size: 0x{seg1['p_memsz'] - seg1['p_filesz']:X}\n")
        out.append("    subsegments:\n")
    bss_done = False
    for s in s1:
        if s.nobits:
            if not bss_done:
                ov = bss_overrides(t, name)
                if not ov:
                    out.append(f"      - {{ start: 0x{fpos:X}, type: bss, vram: 0x{s.addr:X} }}\n")
                else:
                    if ov[0][0] != s.addr:
                        ov = [(s.addr, "-")] + ov
                    for a, u in ov:
                        if u == "-":
                            out.append(f"      - {{ start: 0x{fpos:X}, type: bss, vram: 0x{a:X}, name: bss_{a:X} }}\n")
                        else:
                            out.append(f"      - {{ start: 0x{fpos:X}, type: .bss, vram: 0x{a:X}, name: {u} }}\n")
                bss_done = True
        else:
            out.append(f"      - [0x{s.offset:X}, data, {s.name.strip('.')}]\n")
            fpos = s.offset + s.size
    out.append(f"  - [0x{fpos:X}, bin, elf_trailer]\n  - [0x{len(data):X}]\n")

    cfg = ROOT / "config" / t / f"{name}.yaml"
    if cfg.exists() and not args.force:
        sys.exit(f"{cfg} exists (use --force)")
    cfg.parent.mkdir(parents=True, exist_ok=True)
    cfg.write_text("".join(out))
    (ROOT / "config" / t / f"{name}.sha1").write_text(f"{sha1}  tmp/baserom/{t}/{name}.prx\n")
    sym_path = ROOT / "config" / t / f"symbol_addrs.{name}.txt"
    # stripped modules: keep the names found so far (functions, renames);
    # nids.py below re-adds the exports and imports over them
    keep = [l for l in sym_path.read_text().splitlines() if l.strip()] \
        if sym_path.exists() and elf.get_section_by_name(".symtab") is None else []
    # hand-marked whole objects (`nosplit`, see tools/prx_relocs.py) survive
    if sym_path.exists() and not keep:
        keep = [l for l in sym_path.read_text().splitlines() if re.search(r"//.*\bnosplit\b", l)]
    kaddr = {m[1].upper() for m in (re.search(r"=\s*0x([0-9A-Fa-f]+)", l) for l in keep) if m}
    base = [l for l in symbol_lines(elf, text_end)
            if not (m := re.search(r"=\s*0x([0-9A-Fa-f]+)", l)) or m[1].upper() not in kaddr]
    sym_path.write_text("\n".join(base + keep) + "\n")
    if elf.get_section_by_name(".symtab") is None:
        import nids
        nids.name_module(t, name, nids.load_db(), {}, True)
    with open(ROOT / "config" / t / f"units.{name}.txt", "w") as f:
        f.write("# unit                                     compiler        source\n")
        for addr, typ, nm, ver, src in units:
            if typ == "c":
                f.write(f"{nm:44} {ver:15} {src}\n")
        for nm, (ver, src) in data_units(t, name).items():
            f.write(f"{nm:44} {ver:15} {src}\n")
    print(cfg)


if __name__ == "__main__":
    main()
