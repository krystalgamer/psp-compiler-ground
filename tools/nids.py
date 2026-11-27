#!/usr/bin/env python3
"""Name the exports and import stubs of a stripped module from their NIDs.

Usage: tools/nids.py TARGET MODULE [--write] [--pool DIR...]

Firmware NIDs of this era are the first 4 bytes (little-endian) of the
SHA-1 of the function name, so a name is accepted only when it hashes to
the NID.  Candidate names come from config/nids.txt (names already
resolved) and, with --pool, from every identifier in the given source
trees (e.g. pspsdk, uOFW, PPSSPP's HLE tables).  Resolved names are added
to config/nids.txt; --write puts them into config/TARGET/symbol_addrs.MODULE.txt.
"""
import argparse
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
DB = ROOT / "config" / "nids.txt"

# module (syslib) exports have fixed NIDs, not hashes
SYSLIB = {
    0xD632ACDB: "module_start", 0xCEE8593C: "module_stop", 0xF01D73A7: "module_info",
    0x0F7C276C: "module_start_thread_parameter", 0xCF0CC697: "module_stop_thread_parameter",
    0x11B97506: "module_sdk_version", 0x2F064FA6: "module_reboot_before",
    0xADF12745: "module_reboot_phase", 0xD3744BE0: "module_bootstart",
}


def nid(name):
    return struct.unpack("<I", hashlib.sha1(name.encode()).digest()[:4])[0]


def load_db():
    db = {}
    if DB.exists():
        for line in DB.read_text().splitlines():
            if line and not line.startswith("#"):
                n, name = line.split()
                db[int(n, 16)] = name
    return db


def pool_names(dirs):
    names = set()
    for d in dirs:
        for p in Path(d).rglob("*"):
            if p.is_file() and p.suffix.lower() in (".c", ".h", ".cpp", ".s", ".S", ".exp", ".txt", ".xml", ".py", ".hpp"):
                try:
                    names.update(re.findall(r"\b[A-Za-z_]\w{3,}\b", p.read_text(errors="ignore")))
                except OSError:
                    pass
    return names


def tables(data):
    """(exports, imports): lists of (library, nid, address, is_var)."""
    elf = ELFFile(io.BytesIO(data))
    s0 = prxinfo.load_segments(elf)[0]
    base = s0["p_offset"]
    w = lambda va: struct.unpack_from("<I", data, base + va)[0]
    mi = prxinfo.module_info_addr(elf, data)
    if mi is None:
        mi = (s0["p_paddr"] & 0x7FFFFFFF) - base
    cstr = lambda va: data[base + va:data.index(b"\0", base + va)].decode() if va else ""
    ent_top, ent_end, stub_top, stub_end = struct.unpack_from("<4I", data, base + mi + 0x24)
    exports, imports = [], []
    va = ent_top
    while va < ent_end:
        lib = cstr(w(va))
        size = data[base + va + 8]
        nvar = data[base + va + 9]
        nfunc = struct.unpack_from("<H", data, base + va + 10)[0]
        tab = w(va + 12)
        n = nfunc + nvar
        for i in range(n):
            exports.append((lib, w(tab + 4 * i), w(tab + 4 * (n + i)), i >= nfunc))
        va += 4 * size
    va = stub_top
    while va < stub_end:
        lib = cstr(w(va))
        size = data[base + va + 8]
        nfunc = struct.unpack_from("<H", data, base + va + 10)[0]
        nids, stubs = w(va + 12), w(va + 16)
        for i in range(nfunc):
            imports.append((lib, w(nids + 4 * i), stubs + 8 * i, False))
        va += 4 * size
    return exports, imports


def name_module(target, m, db, used, write, verbose=False):
    exports, imports = tables(modules.read(target, m))
    lines, missing = [], 0
    for kind, ents in (("export", exports), ("import", imports)):
        for lib, n, addr, var in ents:
            name = SYSLIB.get(n) if not lib else db.get(n)
            if name is None:
                missing += 1
                name = f"{lib or 'syslib'}_{n:08X}"
            elif lib:
                used[n] = name
            lines.append(f"{name} = 0x{addr:08X};" + ("" if var else " // type:func"))
            if verbose:
                print(f"{m:20} {kind} {lib or 'syslib':28} {n:08X} {addr:08X} {name}")
    if verbose:
        print(f"# {m}: {len(exports)} exports, {len(imports)} imports, {missing} unresolved", file=sys.stderr)
    if write:
        p = ROOT / "config" / target / f"symbol_addrs.{m}.txt"
        old = [l for l in p.read_text().splitlines() if l.strip()] if p.exists() else []
        # an unresolved NID's placeholder (LIB_NID) doesn't replace a name
        # already given to its address by hand
        named = {l.split("=")[1].split(";")[0].strip() for l in old}
        lines = [l for l in lines if not (re.match(r"\w+_[0-9A-F]{8} =", l)
                                          and l.split("=")[1].split(";")[0].strip() in named)]
        names = {l.split("=")[0].strip() for l in lines}
        addrs = {l.split("=")[1].split(";")[0].strip() for l in lines}
        keep = [l for l in old if l.split("=")[0].strip() not in names
                and l.split("=")[1].split(";")[0].strip() not in addrs]
        # a function exported twice keeps its first name
        seen, out = set(), []
        for l in keep + lines:
            a = l.split("=")[1].split(";")[0].strip()
            if a not in seen:
                seen.add(a)
                out.append(l)
        p.write_text("\n".join(out) + "\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module", nargs="?")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--pool", nargs="*", default=[])
    args = ap.parse_args()
    mods = [args.module] if args.module else list(modules.targets()[args.target])

    db = load_db()
    if args.pool:
        for name in pool_names(args.pool):
            db.setdefault(nid(name), name)
    used = {}
    for m in mods:
        name_module(args.target, m, db, used, args.write, verbose=True)
    if used:
        db0 = load_db()
        db0.update(used)
        DB.write_text("# NID -> name, verified by SHA-1 (tools/nids.py)\n"
                      + "".join(f"{n:08X} {name}\n" for n, name in sorted(db0.items())))


if __name__ == "__main__":
    main()
