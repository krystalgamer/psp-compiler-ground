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
    them after the object's .rodata (its strings), in the object's order
    (src/net/network_lobby_message: the file name string, the 11 _ZTV, _ZTI
    and _ZTS as cc1plus emits them; Ys::Object's typeinfo only in the first
    object, libmm_semaphore).  So each C++ object also keeps the
    .gnu.linkonce.r sections of the data symbols in its own .rodata range,
    linked with its .rodata.* (rodata_order)."""
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
    created as first used too, so they link with its .rodata.*."""
    sys.path.insert(0, str(Path(__file__).parent))
    import compiler

    def rep(m):
        obj, extra = m[1], m[2]
        u = re.search(r"decomp_src/([^/]+)/" + re.escape(module) + r"/(.+)\.c\.o$", obj)
        if u and compiler.object_order(u[1], module, u[2]):
            return f"{obj}(.rodata .rodata.*{extra});"
        return f"{obj}(.rodata);\n        {obj}(.rodata.*{extra});"
    lo = r"((?: \.gnu\.linkonce\.r\.[^\s)]+)*)"
    text = re.sub(r"(\S+\.c\.o)\(\.rodata \.rodata\.\*" + lo + r"\);", r"\1(.rodata\2);", text)
    text = re.sub(r"(\S+\.c\.o)\(\.rodata\);\n\s*\1\(\.rodata\.\*" + lo + r"\);", r"\1(.rodata\2);", text)
    return re.sub(r"(\S+\.c\.o)\(\.rodata" + lo + r"\);", rep, text)


if __name__ == "__main__" and sys.argv[1:2] == ["--rodata-order"]:
    for p in sys.argv[2:]:
        Path(p).write_text(rodata_order(Path(p).read_text(), Path(p).stem))
    sys.exit(0)


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
            fix_ld_script(options.opts.ld_script_path, Path(sys.argv[-1]))
            prune_undefined_syms(options.opts.asm_path, options.opts.undefined_syms_auto_path)
