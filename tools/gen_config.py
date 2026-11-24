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


def symbol_lines(elf, text_end):
    """symbol_addrs lines from the ELF symbol table, names made unique."""
    syms = collections.defaultdict(list)
    for sym in elf.get_section_by_name(".symtab").iter_symbols():
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
        syms[sym.name].append((addr, t, sym["st_size"]))
    by_addr = {}
    for name, ents in syms.items():
        uniq = sorted(set(ents))
        for (addr, t, size) in uniq:
            nm = name if len(uniq) == 1 else f"{name}_{addr:X}"
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
    func_at = {}
    for sym in elf.get_section_by_name(".symtab").iter_symbols():
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
            out.append(f"      - [0x{off:X}, rodata, rodata]\n")
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
    out.append(f"  - name: {name}_seg1\n    type: code\n    start: 0x{seg1['p_offset']:X}\n    vram: 0x{base:X}\n")
    if any(s.nobits for s in s1):
        out.append(f"    bss_size: 0x{seg1['p_memsz'] - seg1['p_filesz']:X}\n")
    out.append("    subsegments:\n")
    bss_done = False
    for s in s1:
        if s.nobits:
            if not bss_done:
                out.append(f"      - {{ start: 0x{fpos:X}, type: bss, vram: 0x{s.addr:X} }}\n")
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
    (ROOT / "config" / t / f"symbol_addrs.{name}.txt").write_text("\n".join(symbol_lines(elf, text_end)) + "\n")
    with open(ROOT / "config" / t / f"units.{name}.txt", "w") as f:
        f.write("# unit                                     compiler        source\n")
        for addr, typ, nm, ver, src in units:
            if typ == "c":
                f.write(f"{nm:44} {ver:15} {src}\n")
    print(cfg)


if __name__ == "__main__":
    main()
