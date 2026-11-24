#!/usr/bin/env python3
"""objcmp.py TARGET MODULE OBJ_OR_ARCHIVE... [-v]

Compare the functions of compiled objects (or archive members) with the
same-named functions of a module: instruction by instruction, ignoring the
fields that relocations fill in.  Prints, per function, `same`, `diff N`
(N differing words) or `size A/B`.
"""
import io
import re
import struct
import subprocess
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = Path(__file__).resolve().parent.parent
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16 = 4, 5, 6, 7


def mask(word, rtype):
    if rtype == R_MIPS_26:
        return word & 0xFC000000
    if rtype in (R_MIPS_HI16, R_MIPS_LO16, R_MIPS_GPREL16):
        return word & 0xFFFF0000
    return 0 if rtype == 2 else word


def module_funcs(target, module):
    rom = ROOT / "tmp" / "baserom" / target / f"{module}.prx"
    data = rom.read_bytes()
    elf = ELFFile(io.BytesIO(data))
    seg0 = next(p for p in elf.iter_segments() if p["p_type"] == "PT_LOAD")
    off0 = seg0["p_offset"]
    relocs = {}
    build = ROOT / "tmp" / "build" / target
    # PRX relocation types by file offset (from the module's own tables)
    import prxinfo  # noqa
    segs = [p for p in elf.iter_segments() if p["p_type"] == "PT_LOAD"]
    for d in prxinfo.reloc_tables(elf):
        for i in range(0, len(d), 8):
            ofs, info = struct.unpack_from("<II", d, i)
            ob = (info >> 8) & 0xFF
            if ob < len(segs):
                relocs[segs[ob]["p_offset"] + ofs] = info & 0xFF
    funcs = {}
    for line in (ROOT / "config" / target / f"symbol_addrs.{module}.txt").read_text().splitlines():
        m = re.match(r"(\w+) = 0x([0-9A-F]+); // type:func(?: size:0x([0-9A-F]+))?", line)
        if m and m[3]:
            a, n = int(m[2], 16), int(m[3], 16)
            words = []
            for k in range(0, n, 4):
                o = off0 + a + k
                w = struct.unpack_from("<I", data, o)[0]
                words.append(mask(w, relocs[o]) if o in relocs else w)
            funcs[m[1]] = words
    return funcs


def obj_funcs(data):
    elf = ELFFile(io.BytesIO(data))
    out = {}
    for sec in elf.iter_sections():
        if not (sec["sh_flags"] & 4) or sec["sh_type"] != "SHT_PROGBITS":
            continue
        text = sec.data()
        rel = {}
        for rs in elf.iter_sections():
            if isinstance(rs, RelocationSection) and rs["sh_info"] == elf.get_section_index(sec.name):
                for r in rs.iter_relocations():
                    rel[r["r_offset"]] = r["r_info_type"]
        symtab = elf.get_section_by_name(".symtab")
        for s in symtab.iter_symbols():
            if s["st_info"]["type"] == "STT_FUNC" and s["st_shndx"] == elf.get_section_index(sec.name):
                a, n = s["st_value"], s["st_size"]
                words = []
                for k in range(a, a + n, 4):
                    w = struct.unpack_from("<I", text, k)[0]
                    words.append(mask(w, rel[k]) if k in rel else w)
                out[s.name] = words
    return out


def members(path):
    p = Path(path)
    if p.suffix != ".a":
        yield p.name, p.read_bytes()
        return
    names = subprocess.run(["ar", "t", str(p)], capture_output=True, text=True).stdout.split()
    for n in names:
        yield n, subprocess.run(["ar", "p", str(p), n], capture_output=True).stdout


def lookup(mod, fn, n):
    """The module function for fn: splat names duplicated statics FN_ADDR."""
    if fn in mod:
        return fn
    cands = [k for k in mod if re.fullmatch(re.escape(fn) + r"_[0-9A-F]+", k)]
    same = [k for k in cands if len(mod[k]) == n]
    return (same or cands or [None])[0]


def disasm(words):
    """objdump lines of masked words."""
    import tempfile
    with tempfile.NamedTemporaryFile(suffix=".bin") as f:
        f.write(b"".join(struct.pack("<I", w) for w in words))
        f.flush()
        out = subprocess.run([str(ROOT / "tmp/toolchains/bin/mips-objdump"), "-D", "-b", "binary", "-m", "mips:allegrex",
                              "-EL", "-M", "no-aliases", f.name], capture_output=True, text=True).stdout
    return [ln.split("\t", 2)[-1].replace("\t", " ") for ln in out.splitlines() if re.match(r"\s+[0-9a-f]+:\t", ln)]


def side_by_side(ours, orig):
    a, b = disasm(ours), disasm(orig)
    for i in range(max(len(a), len(b))):
        x = a[i] if i < len(a) else ""
        y = b[i] if i < len(b) else ""
        print(f"{'  ' if x == y else '>>'} {i*4:4x}  {x:38.38} {y}")


def compare(mod, objs, verbose=False):
    res = {}
    for path in objs:
        for name, data in members(path):
            for fn, words in obj_funcs(data).items():
                key = lookup(mod, fn, len(words))
                if key is None:
                    continue
                orig = mod[key]
                if len(orig) != len(words):
                    res[fn] = f"size {len(words)*4:#x}/{len(orig)*4:#x}"
                else:
                    nd = sum(1 for a, b in zip(words, orig) if a != b)
                    res[fn] = "same" if nd == 0 else f"diff {nd}"
                if verbose and res[fn] != "same":
                    print(f"--- {fn}: ours | original")
                    side_by_side(words, orig)
                    verbose = False
    return res


if __name__ == "__main__":
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    args = [a for a in sys.argv[1:] if not a.startswith("-")]
    target, module, objs = args[0], args[1], args[2:]
    res = compare(module_funcs(target, module), objs)
    for fn in sorted(res):
        print(f"{res[fn]:14} {fn}")
    same = sum(1 for v in res.values() if v == "same")
    print(f"# {same}/{len(res)} identical")
