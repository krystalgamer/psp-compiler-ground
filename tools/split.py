#!/usr/bin/env python3
"""Run splat with PSP-specific tweaks.

- Allegrex GCC/GAS emit `j` for intra-function jumps (they carry R_MIPS_26
  relocs), but splat's psp platform forces rabbitizer to treat `j` as a tail
  call, which produces bogus function symbols. Keep `j` as a branch instead.
- Some modules embed data (e.g. keys) inside functions. rabbitizer may decode
  those words as 64-bit/R4000 instructions that GAS rejects for allegrex, so
  rewrite such lines as raw `.word`s.
- PRX segment 1 (.bss) is relocated independently of segment 0, so the
  original HI16/LO16 immediates are relative to the segment start. Link the
  bss output section at VMA 0 to reproduce them.
"""
import re
import sys
from pathlib import Path

import rabbitizer
import spimdisasm
import splat.platforms.psp
from splat.__main__ import splat_main
from splat.util import options

UNSUPPORTED = {
    "ld", "sd", "ldl", "ldr", "sdl", "sdr", "lwu", "lld", "scd", "pref",
    "ldc1", "sdc1", "ldc2", "sdc2", "lwc2", "swc2", "daddi", "daddiu",
    "lwl", "lwr", "swl", "swr",
    # Allegrex system/debug instructions modern GAS doesn't know
    "mfie", "mtie", "sleep", "halt", "mfic", "mtic", "mfdr", "mtdr", "dbreak", "dret",
    "tgei", "tgeiu", "tlti", "tltiu", "teqi", "tnei",
    "break", "syscall", "sdbbp", "teq", "tne", "tge", "tgeu", "tlt", "tltu",
    # VFPU loads/stores, moves and branches (other VFPU ops start with "v")
    "lv.s", "lv.q", "sv.s", "sv.q", "lvl.q", "lvr.q", "svl.q", "svr.q",
    "mfv", "mtv", "mfvc", "mtvc", "bvf", "bvt", "bvfl", "bvtl",
}


def unsupported(op):
    # Every remaining VFPU mnemonic starts with "v"; base MIPS has none.
    return op in UNSUPPORTED or op.startswith("v")
DATA_WORD_RE = re.compile(
    r"^(?P<pre>\s*/\* (?P<rom>[0-9A-F]+) [0-9A-F]+ (?P<raw>[0-9A-F]{8}) \*/ )\.word (?P<val>[A-Za-z_.][\w.+\- ]*)$"
)
INSN_RE = re.compile(
    r"^(?P<pre>\s*/\* [0-9A-F]+ [0-9A-F]+ (?P<raw>[0-9A-F]{8}) \*/\s+)(?P<op>[a-z0-9.]+)\s"
)


def _psp_init(target_bytes: bytes):
    rabbitizer.config.toolchainTweaks_treatJAsUnconditionalBranch = True
    # Only emit .align when it can't move anything (PRX sections are 4-aligned
    # and jump tables/doubles there aren't necessarily 8-aligned).
    spimdisasm.common.GlobalConfig.SYMBOL_ALIGNMENT_REQUIRES_ALIGNED_SECTION = True
    # Data words only reference symbols through real relocations.
    spimdisasm.common.GlobalConfig.ALLOW_ALL_ADDENDS_ON_DATA = False
    spimdisasm.common.GlobalConfig.ALLOW_ALL_CONSTANTS_ON_DATA = False


def fix_unsupported(asm_dir: Path, reloc_roms=frozenset()):
    """Rewrite lines GAS can't take (or that would mis-assemble) as raw words.

    Besides opcodes modern GAS rejects for Allegrex, this covers %hi/%lo
    operands spimdisasm inferred at offsets without a PRX relocation: those
    are plain constants (e.g. handwritten code using $gp as a register).
    """
    for path in asm_dir.rglob("*.s"):
        text = path.read_text()
        # .L labels are local to one object: a table word is only symbolic
        # when its label is defined in the same file (a jump table split
        # off from its function, e.g. by a partial rodata carve, is not)
        defined_locals = set(re.findall(r"^\s*(?:jlabel\s+)?(\.L\w+):?\s*$", text, re.M))
        # Layout is fixed by the original addresses, so .align above 4 bytes
        # never moves anything; it only raises section alignment, which old
        # psp-as turns into end-of-section padding.
        new_text = re.sub(r"^\.align [3-9]$", ".align 2", text, flags=re.M)
        if new_text != text:
            path.write_text(new_text)
        lines = new_text.splitlines(keepends=True)
        changed = False
        for i, line in enumerate(lines):
            m = INSN_RE.match(line)
            bogus_reloc = (
                m is not None and reloc_roms is not None
                and ("%hi(" in line or "%lo(" in line or "%gp_rel(" in line or m["op"] in ("j", "jal")
                     or re.search(r"& 0xFFFF\)\(\$", line)
                     or (m["op"].startswith("b") and re.search(r",\s*D_[0-9A-F]+\s*$", line.split("/*")[-1].split("*/")[-1])))
                and int(line.split("/*", 1)[1].split()[0], 16) not in reloc_roms
            )
            dm = DATA_WORD_RE.match(line.rstrip("\n"))
            if dm and reloc_roms and (int(dm["rom"], 16) not in reloc_roms or (dm["val"].startswith(".L") and dm["val"].split()[0] not in defined_locals)):
                word = int.from_bytes(bytes.fromhex(dm["raw"]), "little")
                lines[i] = f"{dm['pre']}.word 0x{word:08X} # {dm['val']}\n"
                changed = True
                continue
            if m and (unsupported(m["op"]) or bogus_reloc):
                word = int.from_bytes(bytes.fromhex(m["raw"]), "little")
                lines[i] = f"{m['pre']}.word      0x{word:08X} # {line[m.start('op'):].strip()}\n"
                changed = True
        if changed:
            path.write_text("".join(lines))


def fix_ld_script(ld_path: Path, config_path: Path):
    """Link PRX segment 1 relative to its own base.

    `<name>_seg1` segments start at VMA 0 and their bss at its offset within
    the segment. Older configs with only a bss subsegment get bss at VMA 0.
    """
    import yaml

    cfg = yaml.safe_load(config_path.read_text())
    text = ld_path.read_text()
    for seg in cfg["segments"]:
        if not isinstance(seg, dict) or not str(seg.get("name", "")).endswith("_seg1"):
            continue
        name, base = seg["name"], seg["vram"]
        text = re.sub(rf"^(\s*\.{name}) 0x[0-9A-Fa-f]+ :", r"\1 0x0 :", text, flags=re.M)
        bss = [sub for sub in seg.get("subsegments", []) if isinstance(sub, dict) and sub.get("type") in ("bss", ".bss")]
        if bss:
            # the segment's bss starts at its first bss subsegment
            off = bss[0]["vram"] - base
            text = re.sub(rf"^(\s*\.{name}_bss)( 0x[0-9A-Fa-f]+)? \(NOLOAD\)", rf"\1 0x{off:X} (NOLOAD)", text, flags=re.M)
        for sub in bss:
            if sub["type"] == ".bss":
                # a unit's .bss given its place here (config `bss ADDR UNIT`):
                # not also in segment 0's bss, which comes first
                obj = re.escape(f"/{sub['name']}.c.o(.bss);")
                m = re.search(rf"^\s*\.{name}_bss ", text, re.M)
                head, tail = text[:m.start()], text[m.start():]
                text = re.sub(rf"^\s*\S+{obj}\n", "", head, count=1, flags=re.M) + tail
    text = re.sub(r"^(\s*\.\w+_bss) \(NOLOAD\)", r"\1 0x0 (NOLOAD)", text, flags=re.M)
    text = cxx_linkonce(text, cfg)
    # PRX parts are packed at their real file offsets (gaps are prxpad).
    text = re.sub(r"^\s*__romPos = ALIGN\(__romPos, \d+\);\n", "", text, flags=re.M)
    ld_path.write_text(rodata_order(text, ld_path.stem))


def cxx_linkonce(text, cfg):
    """C++ units (`/* lang: c++ */`): cc1plus puts template instances and
    out-of-line inline functions in .gnu.linkonce.t.* sections, which follow
    the object's .text.  Sony's link kept the first copy: in UTST99332's
    demos no instance appears twice and its holder precedes every other
    object that needs it.  ld keeps the first copy in script order, so each
    C++ object keeps the linkonce sections of the functions in its own
    address range (its copies of other objects' instances are discarded).

    Without `#pragma interface`, vtables, typeinfo and type names of classes
    with no key function go to .gnu.linkonce.r.* sections.  rb/rs4_main has
    them in the object's section order (src/net/network_lobby_message: the
    file name string, the 11 _ZTV, _ZTI and _ZTS as cc1plus emits them;
    src/net/network_lobby_state: its _ZTV before the string; Ys::Object's
    typeinfo only in the first object, libmm_semaphore).  So each C++ object
    also keeps the .gnu.linkonce.r sections of the data symbols in its own
    .rodata range, linked with its .rodata (rodata_order)."""
    funcs, data = [], []
    for path in cfg.get("options", {}).get("symbol_addrs_path", []):
        if Path(path).is_file():
            for line in Path(path).read_text().splitlines():
                m = re.match(r"(\S+) = 0x([0-9A-Fa-f]+);(.*)", line)
                if not m:
                    continue
                if re.match(r"\s*// type:func", m.group(3)):
                    funcs.append((int(m.group(2), 16), m.group(1)))
                elif not re.match(r"(D|jtbl)_[0-9A-Fa-f]+$", m.group(1)):
                    data.append((int(m.group(2), 16), m.group(1)))
    if not funcs:
        return text
    funcs.sort()
    data.sort()
    for seg in cfg["segments"]:
        if not isinstance(seg, dict) or seg.get("type") != "code":
            continue
        subs = [sub for sub in seg.get("subsegments", []) if isinstance(sub, list)]
        for k, sub in enumerate(subs):
            if sub[1] not in ("c", ".rodata"):
                continue
            src = Path(cfg["options"].get("src_path", "src")) / f"{sub[2]}.c"
            if not src.is_file() or "/* lang: c++ */" not in src.read_text(errors="replace"):
                continue
            lo = sub[0] - seg["start"] + seg["vram"]
            hi = (subs[k + 1][0] - seg["start"] + seg["vram"]) if k + 1 < len(subs) else 1 << 32
            if sub[1] == "c":
                kind, names = "t", [n for a, n in funcs if lo <= a < hi]
            else:
                kind, names = "r", [n for a, n in data if lo <= a < hi]
            sec = ".text" if kind == "t" else ".rodata"
            keep = "".join(f" .gnu.linkonce.{kind}.{n}" for n in names)
            obj = re.escape(f"/{src}.o({sec});")
            text = re.sub(rf"^(\s*\S+?){obj}$", lambda m: f"{m.group(1)}/{src}.o({sec}{keep});", text, count=1, flags=re.M)
    return text


def rodata_order(text, module):
    """cc1 puts double/float constants in .rodata.cst8/.rodata.cst4 and Sony
    links *(.rodata .rodata.*), i.e. in each object's own section order.  The
    release assemblers have .rodata first; the 1.6.1.internal toolchain's
    creates the sections as they are first used (config/compilers.txt
    objorder).  A C++ object's .gnu.linkonce.r sections (cxx_linkonce) are
    created as first used too, and so is its .rodata (before or after a
    vtable), so they link in one statement with its .rodata, before its
    .rodata.*."""
    sys.path.insert(0, str(Path(__file__).parent))
    import compiler

    def rep(m):
        obj, extra = m[1], m[2]
        u = re.search(r"decomp_src/([^/]+)/" + re.escape(module) + r"/(.+)\.c\.o$", obj)
        if u and compiler.object_order(u[1], module, u[2]):
            return f"{obj}(.rodata .rodata.*{extra});"
        if extra:
            # a C++ object's vtables/typeinfo: .rodata and .gnu.linkonce.r in
            # object-file order (rs4_main has both string-first and
            # vtable-first objects); its constants still follow
            return f"{obj}(.rodata{extra});\n        {obj}(.rodata.*);"
        return f"{obj}(.rodata);\n        {obj}(.rodata.*{extra});"
    lo = r"((?: \.gnu\.linkonce\.r\.[^\s)]+)*)"
    text = re.sub(r"(\S+\.c\.o)\(\.rodata \.rodata\.\*" + lo + r"\);", r"\1(.rodata\2);", text)
    text = re.sub(r"(\S+\.c\.o)\(\.rodata\);\n\s*\1\(\.rodata\.\*" + lo + r"\);", r"\1(.rodata\2);", text)
    return re.sub(r"(\S+\.c\.o)\(\.rodata" + lo + r"\);", rep, text)


if __name__ == "__main__" and sys.argv[1:2] == ["--rodata-order"]:
    for p in sys.argv[2:]:
        Path(p).write_text(rodata_order(Path(p).read_text(), Path(p).stem))
    sys.exit(0)


def cst_ranges(config_path: Path):
    """The `cst4|cst8 LO-HI UNIT` lines of files.MODULE.txt."""
    files = config_path.parent / f"files.{config_path.stem}.txt"
    ranges = []
    for line in files.read_text().splitlines() if files.is_file() else []:
        f = line.split("#")[0].split()
        if len(f) == 3 and f[0] in ("cst4", "cst8"):
            lo, hi = (int(x, 16) for x in f[1].split("-"))
            ranges.append((f[0], lo, hi, f[2]))
    return ranges


def _two_pool_migration(ranges):
    """spimdisasm pairs each function with one run of its unit's rodata, in
    order.  A -fmerge-constants unit has two pools (its .rodata.cst*
    constants, then its strings and jump tables), so pair them separately."""
    orig = spimdisasm.mips.FunctionRodataEntry.getAllEntriesFromSections
    Entry = spimdisasm.mips.FunctionRodataEntry

    def entries(textSection, rodataSection):
        full = rodataSection.symbolList if rodataSection is not None else []
        cst = lambda sym: any(lo <= sym.vram < hi for _, lo, hi, _ in ranges)
        if not any(map(cst, full)):
            return orig(textSection, rodataSection)
        funcs, orphans = {}, []
        try:
            for part in ([x for x in full if cst(x)], [x for x in full if not cst(x)]):
                rodataSection.symbolList = part
                for e in orig(textSection, rodataSection):
                    if e.function is None:
                        orphans.append(e)
                    elif e.function.vram in funcs:
                        funcs[e.function.vram].rodataSyms += e.rodataSyms
                        funcs[e.function.vram].lateRodataSyms += e.lateRodataSyms
                    else:
                        funcs[e.function.vram] = Entry(e.function, list(e.rodataSyms), list(e.lateRodataSyms))
        finally:
            rodataSection.symbolList = full
        return list(funcs.values()) + orphans
    spimdisasm.mips.FunctionRodataEntry.getAllEntriesFromSections = staticmethod(entries)


def cst_pools(asm_dir: Path, config_path: Path):
    """`cst4 LO-HI UNIT` (or `cst8`) lines of files.MODULE.txt: the unit was
    built with -fmerge-constants, so cc1 put its float (double) constants in
    .rodata.cst4 (.rodata.cst8), not with its strings in .rodata.  The asm
    functions' (and INCLUDE_RODATA) data the unit includes from LO to HI goes
    to that section too, so it links with the C code's constants."""
    for kind, lo, hi, unit in cst_ranges(config_path):
        sec = f'.section .rodata.{kind},"aM",@progbits,{kind[3:]}'
        for path in (asm_dir / "nonmatchings" / unit).glob("*.s"):
            lines = path.read_text().splitlines(keepends=True)
            out, block, cur, in_ro, changed = [], [], None, False, False

            def flush():
                nonlocal cur, changed
                if not block:
                    return
                vram = next((int(m[1], 16) for l in block
                             for m in [re.match(r"\s*/\* [0-9A-F]+ ([0-9A-F]{8})\b", l)] if m), None)
                want = cur if vram is None else sec if lo <= vram < hi else ".section .rodata"
                if want != cur:
                    out.append(want + "\n")
                    cur = want
                    changed = changed or want == sec
                out.extend(block)
                block.clear()

            for line in lines:
                s = line.strip()
                if s.startswith(".section") or s in (".text", ".rdata", ".data"):
                    if in_ro:
                        flush()
                    in_ro = s == ".section .rodata"
                    if in_ro:
                        cur = ".section .rodata"
                        out.append(line)
                        continue
                if not in_ro:
                    out.append(line)
                    continue
                block.append(line)
                if s.startswith("enddlabel"):
                    flush()
            if in_ro:
                flush()
            if changed:
                path.write_text("".join(out))


def prune_undefined_syms(asm_dir: Path, undef_path: Path):
    """Drop auto 'undefined' symbols that the asm defines.

    Linker-script assignments override object symbols, so a stale entry
    (seen when segment 1 starts right where segment 0 ends) would pin the
    symbol to its absolute vram instead of its segment-relative address.
    """
    if not undef_path.exists():
        return
    defined = set()
    for f in asm_dir.rglob("*.s"):
        defined.update(re.findall(r"^\s*(?:glabel|dlabel|alabel|jlabel)\s+(\w+)", f.read_text(), re.M))
    # symbols the linker script assigns (e.g. _gp past the end of the data)
    ld = Path(options.opts.ld_script_path)
    if ld.exists():
        defined.update(re.findall(r"^\s*(\w+)\s*=", ld.read_text(), re.M))
    lines = undef_path.read_text().splitlines()
    kept = [l for l in lines if l.split("=")[0].strip() not in defined]
    undef_path.write_text("\n".join(kept) + ("\n" if kept else ""))


def _no_pointer_guessing(self, word: int) -> bool:
    # PRX relocations identify every real pointer (fed in via reloc_addrs);
    # value-based guessing turns plain data that happens to look like an
    # address into bogus symbol references.
    return False


spimdisasm.mips.sections.MipsSectionBase.SectionBase.checkWordIsASymbolReference = _no_pointer_guessing

splat.platforms.psp.init = _psp_init

if __name__ == "__main__":
    _two_pool_migration(cst_ranges(Path(sys.argv[-1])))
    sys.argv[1:1] = ["split"]
    try:
        splat_main()
    finally:
        if options.opts is not None and getattr(options.opts, "asm_path", None):
            relocs = set()
            for rp in options.opts.reloc_addrs_paths:
                roms = Path(str(rp).replace("reloc_addrs.", "reloc_roms."))
                relocs.update(int(x, 16) for x in roms.read_text().split())
            fix_unsupported(options.opts.asm_path, relocs)
            cst_pools(Path(options.opts.asm_path), Path(sys.argv[-1]))
            fix_ld_script(options.opts.ld_script_path, Path(sys.argv[-1]))
            prune_undefined_syms(options.opts.asm_path, options.opts.undefined_syms_auto_path)
