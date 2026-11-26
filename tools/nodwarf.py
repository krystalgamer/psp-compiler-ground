#!/usr/bin/env python3
"""nodwarf.py TARGET MODULE [--write] [--compiler V] [--only a.c,b.c]

Find the objects without DWARF in a module's .text and print (or, with
--write, store as config/TARGET/files.MODULE.txt) their start addresses for
gen_config's file_units.  They lie in the gaps the DWARF compile units leave.
Their STT_FILE symbols, in link order, name them; a function belongs to a
file if it is one of the file's local symbols or its name says so (sceGum*
-> libgum.c, a mangled name containing the file's stem, ...); anything else
belongs to the file before it.  The compiler is the module's only .comment
version, or --compiler.
"""
import argparse
import collections
import os
import re
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import gen_config  # noqa: E402

RULES = {
    "libgum.c": r"^(sceGum|__sceGum)",
    "libgu.c": r"^(sceGu(?!m)|__sceGu(?!m)|gu[A-Z])",
    "libwave.c": r"^(sceWave|__sceWave)",
    "libsas.c": r"^(sceSas|__sceSas)",
    "n2p.c": r"^(sceSsNote2Pitch|sceSsPitch2Note)$",
    "libsndp.c": r"^(?!sceSsNote2Pitch$|sceSsPitch2Note$)(sceSs|_sceSs)",
    "sdphd_i.c": r"^sdphd_",
    "scePsmf_stub.s": r"^scePsmf",
    "smf.c": r"^smf_",
    "voice.c": r"^voice_",
    "kernel_bridge.c": r"^(_(read|write|open|close|lseek|fstat|isatty|exit|kill|getpid|sbrk|stat|unlink|link|"
                       r"times|gettimeofday|rename|mkdir|sys_\w+)|isatty|sbrk)$",
}


_known = None


def known_files():
    """function name -> source basenames, from the modules split with DWARF
    (tmp/asm/T/M/nonmatchings/UNIT/FUNC.s)"""
    global _known
    if _known is None:
        _known = collections.defaultdict(set)
        for p in (ROOT / "tmp" / "asm").glob("*/*/nonmatchings/*/*.s"):
            _known[p.stem].add(p.parent.name)
    return _known


def owner_by_name(name, files, here):
    """files: all non-DWARF files; here: those with local functions in this gap.
    Callers check the result against the link order."""
    for f in files:
        r = RULES.get(os.path.basename(f))
        if r and re.search(r, name):
            return f
    units = known_files().get(name, set())
    hits = [f for f in files if os.path.splitext(os.path.basename(f))[0] in units]
    if len(hits) == 1:
        return hits[0]
    # longest stem contained in the name (inv_laser_start -> inv_laser.c)
    best = None
    for f in list(here) + [f for f in files if f not in here]:
        stem = os.path.splitext(os.path.basename(f))[0]
        if len(stem) >= 5 and stem.lower() in name.lower() and (best is None or len(stem) > len(best[1])):
            best = (f, stem)
    return best[0] if best else None


def analyse(target, module):
    elf_path = gen_config.baserom(target, module) if hasattr(gen_config, "baserom") else \
        next(p for p in (ROOT / "tmp" / "baserom" / target).glob(f"{module}.*"))
    e = ELFFile(open(elf_path, "rb"))
    text = e.get_section_by_name(".text")
    text_idx = next(i for i, sec in enumerate(e.iter_sections()) if sec.name == ".text")
    # symbol and DWARF values are relative to .text (PRX)
    t0, t1 = 0, text["sh_size"]
    cus = [(lo, hi, n) for lo, hi, n, _ in gen_config.compile_units(e)]
    cu_names = {os.path.basename(n) for _, _, n in cus}
    # FILE symbols in link order with their local functions
    files, local = [], collections.defaultdict(list)
    funcs = {}
    cur = None
    for s in e.get_section_by_name(".symtab").iter_symbols():
        ty, bind = s["st_info"]["type"], s["st_info"]["bind"]
        if ty == "STT_FILE":
            cur = s.name
            if not s.name.startswith("<") and os.path.basename(s.name) not in cu_names:
                files.append(s.name)
            continue
        in_text = s["st_shndx"] == text_idx
        if in_text and (ty == "STT_FUNC" or (ty in ("STT_NOTYPE", "STT_OBJECT") and bind == "STB_GLOBAL" and s.name)) \
                and t0 <= s["st_value"] < t1:
            funcs[s["st_value"]] = s.name
            if bind == "STB_LOCAL" and cur in files:
                local[cur].append(s["st_value"])
    covered = sorted((lo, hi) for lo, hi, _ in cus)
    # gaps of .text not covered by a compile unit, holding at least one function
    gaps, a = [], t0
    for lo, hi in covered + [(t1, t1)]:
        if lo > a:
            fs = sorted(x for x in funcs if a <= x < lo)
            if fs:
                gaps.append((a, lo, fs))
        a = max(a, hi)
    out, problems = [], []
    order = {f: i for i, f in enumerate(files)}
    for a, b, fs in gaps:
        owners = {}
        for f in files:
            # objects after it without a FILE symbol of their own add locals to it: keep its first gap
            if local[f] and a <= local[f][0] < b:
                for x in local[f]:
                    if a <= x < b:
                        owners[x] = f
        here = set(owners.values())
        named = {x: owner_by_name(funcs[x], files, here) for x in fs if x not in owners}
        # a name match must fit the link order of the local-symbol owners around it
        # (inv_classic_sound_load in inv_shima.c is not mpeg/sound.c's)
        anchors = sorted(owners)
        for x, f in sorted(named.items()):
            if not f:
                continue
            prev = [owners[y] for y in anchors if y < x]
            nxt = [owners[y] for y in anchors if y > x]
            if (not prev or order[prev[-1]] <= order[f]) and (not nxt or order[f] <= order[nxt[0]]):
                owners[x] = f
        known = sorted(owners)
        if not known:
            problems.append(f"gap 0x{a:X}-0x{b:X}: {len(fs)} functions, no file")
            continue
        gfiles = sorted({owners[x] for x in known}, key=order.get)
        # files without a function of their own between two of this gap's files
        lo_i, hi_i = order[gfiles[0]], order[gfiles[-1]]
        seq = [owners[x] for x in known]
        if any(order[p] > order[q] for p, q in zip(seq, seq[1:])):
            problems.append(f"gap 0x{a:X}: files out of order: " +
                            " ".join(f"{funcs[x]}={owners[x]}" for x in known))
            continue
        starts = {}
        for x in known:
            starts.setdefault(owners[x], x)
        # functions before the first identified one stay asm (e.g. fp-bit/dp-bit)
        for f in files[lo_i:hi_i + 1]:
            if f not in starts:
                problems.append(f"{f}: no function of its own in gap 0x{a:X}")
        for f in gfiles:
            out.append((starts[f] + text["sh_addr"], f))
    return sorted(out), problems, e


def comment_version(e):
    c = e.get_section_by_name(".comment")
    v = collections.Counter(x.decode().split("-psp-")[-1] for x in c.data().split(b"\0") if x) if c else {}
    return next(iter(v)) if len(v) == 1 else None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--compiler")
    ap.add_argument("--only", help="comma-separated source files to keep (others stay asm)")
    a = ap.parse_args()
    ents, problems, e = analyse(a.target, a.module)
    if a.only:
        keep = set(a.only.split(","))
        ents = [x for x in ents if x[1] in keep]
    ver = a.compiler or comment_version(e)
    for p in problems:
        print("#!", p, file=sys.stderr)
    if not ver:
        sys.exit("several compilers in .comment: pass --compiler")
    used = set()
    lines = ["# Objects without DWARF: start address (vram), unit, compiler, source.",
             "# Generated by tools/nodwarf.py from the STT_FILE symbols (local",
             "# functions and names) and the module's .comment version."]
    for addr, f in ents:
        u = re.sub(r"\W", "_", os.path.splitext(f)[0])
        while u in used:
            u += "_"
        used.add(u)
        lines.append(f"0x{addr:05X} {u:<15} {ver:<15} {f}")
    text = "\n".join(lines) + "\n"
    if a.write:
        (ROOT / "config" / a.target / f"files.{a.module}.txt").write_text(text)
    print(text, end="")


if __name__ == "__main__":
    main()
