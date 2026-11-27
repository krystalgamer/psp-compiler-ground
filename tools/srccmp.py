#!/usr/bin/env python3
"""srccmp.py TARGET MODULE --files A.c[:FLAGS][:locfix],... [--src DIR]
          [--objs X.o,Y.a] [--cc1 A,B] [--flags F] [-D X]... [-I DIR]...
          [-v FUNC]... [-q] [--gaps] [--locfix] [--asm]

Compile known (upstream) sources with each cc1 and compare every function
with a module that has no symbols: a compiled function is found by exact
search of its relocation-masked words in the module's code; the others are
placed by export NID, after the previous function of their object, or at
the most similar module function of about their size.  Prints per cc1 the
exact/total count and every other function's `diff N` / `size A/B`;
--gaps lists the module code that no exact match covers, with the most
similar unmatched compiled function.  Sources are preprocessed with the
1.3.1 release's newlib and gcc headers (__DYNAMIC_REENT__, as Sony's newer
newlib); a file's own FLAGS replace --flags when they start with -O.
"""
import argparse
import hashlib
import io
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import tmpdir  # noqa: E402,F401  (scratch files in tmp/)
import objcmp  # noqa: E402
import prxinfo  # noqa: E402
from elftools.elf.elffile import ELFFile  # noqa: E402

T = ROOT / "tmp" / "toolchains" / "bin"
CACHE = ROOT / "tmp" / "srccmp"
G131 = ROOT / "tmp" / "toolchains" / "psp-gcc-1.3.1"
SYSINC = [G131 / "psp" / "include", next((G131 / "lib" / "gcc-lib" / "psp").glob("*/include"))]
NOEXT = {"1.8.4", "1.8.3", "1.7.1-orig", "184ins", "1.6.1", "1.5.1", "1.3.1-orig"}
CPPDEFS = ["__GNUC__=3", "__GNUC_MINOR__=3", "__GNUC_PATCHLEVEL__=6", "__mips__", "__mips=1", "__MIPSEL__",
           "_MIPSEL", "MIPSEL", "__MIPSEL", "__psp__", "__SCE__", "__mips_hard_float", "__mips_single_float",
           "_MIPS_SZINT=32", "_MIPS_SZLONG=32", "_MIPS_SZPTR=32", "__SIZE_TYPE__=unsigned int",
           "__PTRDIFF_TYPE__=int", "__WCHAR_TYPE__=int", "__WINT_TYPE__=unsigned int", "__CHAR_BIT__=8",
           "__INT_MAX__=2147483647", "__LONG_MAX__=2147483647L", "__SCHAR_MAX__=127", "__SHRT_MAX__=32767",
           "__LONG_LONG_MAX__=9223372036854775807LL", "__OPTIMIZE__", "__ELF__", "__USER_LABEL_PREFIX__=",
           "__REGISTER_PREFIX__=", "_LANGUAGE_C", "__LANGUAGE_C", "__LANGUAGE_C__", "_mips", "mips",
           "__mips_fpr=32", "_MIPS_ISA=_MIPS_ISA_MIPS2", "_MIPS_SIM=_MIPS_SIM_ABI32", "_ABIO32=1",
           "__STDC_HOSTED__=1", "__DYNAMIC_REENT__"]


class Module:
    def __init__(self, target, name):
        self.name = name
        data = (ROOT / "tmp" / "baserom" / target / f"{name}.prx").read_bytes()
        self.data = data
        elf = ELFFile(io.BytesIO(data))
        segs = prxinfo.load_segments(elf)
        self.base = segs[0]["p_offset"]
        rel = {}
        for d in prxinfo.reloc_tables(elf):
            for i in range(0, len(d), 8):
                ofs, info = struct.unpack_from("<II", d, i)
                ob = (info >> 8) & 0xFF
                if ob < len(segs):
                    rel[segs[ob]["p_vaddr"] + ofs] = info & 0xFF
        self.rel = rel
        secs = prxinfo.sections(elf, data)
        stubs = [s for s in secs if s.name.startswith(".sceStub.text")]
        self.stub = (min(s.addr for s in stubs), max(s.addr + s.size for s in stubs))
        self.end = self.stub[0]
        self.words = []
        self.raw = []
        for a in range(0, self.end, 4):
            w = self.w(a)
            self.raw.append(w)
            self.words.append(objcmp.mask(w, rel[a]) if a in rel else w)
        self.blob = b"".join(struct.pack("<I", w) for w in self.words)
        # imports: stub address -> NID; exports: address -> NID
        self.imports, self.exports = {}, {}
        sec = {s.name: s for s in secs}
        st = sec[".lib.stub"]
        va = st.addr
        while va < st.addr + st.size:
            size = data[self.base + va + 8]
            nf = struct.unpack_from("<H", data, self.base + va + 10)[0]
            nids, funcs = self.w(va + 12), self.w(va + 16)
            for i in range(nf):
                self.imports[funcs + 8 * i] = self.w(nids + 4 * i)
            va += size * 4
        en = sec[".lib.ent"]
        va = en.addr
        while va < en.addr + en.size:
            size = data[self.base + va + 8]
            nv = data[self.base + va + 9]
            nf = struct.unpack_from("<H", data, self.base + va + 10)[0]
            tab = self.w(va + 12)
            n = nf + nv
            for i in range(nf):
                self.exports[self.w(tab + 4 * (n + i))] = self.w(tab + 4 * i)
            va += size * 4
        # jal targets
        self.calls = {}
        self.jaltargets = set()
        for i, w in enumerate(self.raw):
            a = 4 * i
            if (w >> 26) == 3 and self.rel.get(a) == 4:
                t = (w & 0x3FFFFFF) << 2
                self.calls[a] = t
                self.jaltargets.add(t)
        self.names = {}

    def w(self, va):
        return struct.unpack_from("<I", self.data, self.base + va)[0]

    def find(self, words):
        b = b"".join(struct.pack("<I", w) for w in words)
        out, i = [], self.blob.find(b)
        while i >= 0:
            if i % 4 == 0:
                out.append(i)
            i = self.blob.find(b, i + 1)
        return out

    def starts(self):
        """likely function starts: jal targets, exports, words after the
        delay slot of a `jr ra` that begin with a frame setup"""
        s = {t for t in self.jaltargets if t < self.end} | {a for a in self.exports if a < self.end}
        for i, w in enumerate(self.raw):
            if w == 0x03E00008 and 4 * i + 8 < self.end:
                nxt = self.raw[i + 2]
                if (nxt >> 16) == 0x27BD and (nxt & 0x8000):
                    s.add(4 * i + 8)
        return sorted(s)


def nid(name):
    return struct.unpack("<I", hashlib.sha1(name.encode()).digest()[:4])[0]


def resolver(dirs):
    """NID -> name for every identifier in the given source trees and the
    newlib headers (import and export names)"""
    ids = set()
    for d in [*dirs, SYSINC[0]]:
        for f in Path(d).rglob("*"):
            if f.suffix in (".c", ".h"):
                ids |= set(re.findall(r"[A-Za-z_]\w+", f.read_text(errors="replace")))
    return {nid(i): i for i in ids}


def compile_c(src, cc1, flags, defs, incs, asm=False, locfix=False):
    """compile src with cc1; return object bytes (cached)"""
    CACHE.mkdir(parents=True, exist_ok=True)
    cflags, asflags = ("", "-mulsw") if cc1 in NOEXT else ("-mext", "-mulsw")
    cmd = ["cpp", "-undef", "-nostdinc", *[f"-I{d}" for d in incs], *[f"-I{d}" for d in SYSINC],
           *[f"-D{d}" for d in CPPDEFS], *[f"-D{d}" for d in defs], str(src)]
    i = subprocess.run(cmd, capture_output=True, text=True)
    if i.returncode:
        sys.stderr.write(i.stderr[-2000:])
        return None
    ccmd = ["-quiet", "-G0", *cflags.split(), *flags.split()] + (["-g"] if locfix else [])
    binf = T / f"cc1-{cc1}.bin"
    stamp = str(binf.stat().st_mtime) if binf.exists() else ""
    key = hashlib.sha1((i.stdout + cc1 + stamp + os.environ.get("LOOPX", "") + ("locfix" if locfix else "") + " ".join(ccmd) + asflags).encode()).hexdigest()[:20]
    o = CACHE / f"{Path(src).stem}-{key}.o"
    s = o.with_suffix(".s")
    if not o.exists():
        ii = o.with_suffix(".i")
        ii.write_text(i.stdout)
        r = subprocess.run([str(T / f"cc1-{cc1}"), *ccmd, str(ii), "-o", str(s)], capture_output=True, text=True)
        ii.unlink()
        if r.returncode:
            sys.stderr.write(r.stderr[-2000:])
            return None
        if locfix:
            subprocess.run([sys.executable, str(ROOT / "tools" / "locfix.py"), str(s)], check=True)
        subprocess.run([str(T / "psp-as"), "-G0", *asflags.split(), "-o", str(o), str(s)], check=True)
    if asm:
        print(s)
    return o.read_bytes()


def obj_funcs_ordered(data):
    """[(name, words)] in address order; objcmp.OBJCALLS filled"""
    f = objcmp.obj_funcs(data)
    elf = ELFFile(io.BytesIO(data))
    addr = {s.name: s["st_value"] for s in elf.get_section_by_name(".symtab").iter_symbols()
            if s["st_info"]["type"] == "STT_FUNC"}
    return sorted(f.items(), key=lambda kv: addr[kv[0]])


def ndiff(a, b):
    return sum(x != y for x, y in zip(a, b)) + abs(len(a) - len(b))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("--src", default=".")
    ap.add_argument("--files", default="")
    ap.add_argument("--objs", default="", help="prebuilt .o/.a files instead of sources")
    ap.add_argument("--cc1", default="1.9.2")
    ap.add_argument("--flags", default="-O2")
    ap.add_argument("-D", dest="defs", action="append", default=[])
    ap.add_argument("-I", dest="incs", action="append", default=[])
    ap.add_argument("-v", dest="verbose", action="append", default=[])
    ap.add_argument("--asm", action="store_true")
    ap.add_argument("--locfix", action="store_true", help="-g and no delay-slot fill across lines (tools/locfix.py)")
    ap.add_argument("--quiet", "-q", action="store_true")
    ap.add_argument("--gaps", action="store_true", help="list module code no exact match covers")
    a = ap.parse_args()
    mod = Module(a.target, a.module)
    src = Path(a.src)
    if a.gaps:
        r = resolver([src, *a.incs])
        mod.impnames = {ad: r.get(n, hex(n)) for ad, n in mod.imports.items()}
    files = [f for f in a.files.split(",") if f]
    pre = [(n, d) for o in a.objs.split(",") if o for n, d in objcmp.members(o)]
    incs = [src, *a.incs]
    for cc1 in a.cc1.split(","):
        same = tot = 0
        bad = []
        allf = []
        covered = []
        for f in files + pre:
            if isinstance(f, tuple):
                fname, data = f
            else:
                fl = f.split(":")
                fname, fflags = fl[0], " ".join(x for x in fl[1:] if x != "locfix")
                data = compile_c(src / fname, cc1, (fflags if fflags.startswith("-O") else a.flags + " " + fflags),
                                 a.defs, incs, a.asm, a.locfix or "locfix" in fl[1:])
            if data is None:
                bad.append(f"{fname}:ERROR")
                continue
            funcs = obj_funcs_ordered(data)
            for fn, w in funcs:
                allf.append((fname, fn, w, dict(objcmp.OBJCALLS.get(fn, {}))))
            # exact hits first, then the rest by position from the previous hit
            hits = {fn: mod.find(w) for fn, w in funcs}
            out = []
            uniq = {k: hits[fn][0] for k, (fn, w) in enumerate(funcs) if len(hits[fn]) == 1}
            for k, (fn, w) in enumerate(funcs):
                h = hits[fn]
                if not h:
                    out.append((fn, None, None))
                    continue
                if len(h) > 1 and uniq:
                    # nearest unique neighbour (by function index) anchors the choice
                    j = min(uniq, key=lambda j: abs(j - k))
                    h = [min(h, key=lambda x: abs(x - uniq[j]))]
                out.append((fn, h[0], "same"))
            # locate non-exact ones: exported names, else after the previous function
            starts = set(mod.starts())
            for k, (fn, pa, st) in enumerate(out):
                if st:
                    starts.add(pa)
                    starts.add(pa + 4 * len(funcs[k][1]))
            starts = sorted(starts)
            exp = {n: a for a, n in mod.exports.items()}
            for k, (fn, pa, st) in enumerate(out):
                if st:
                    continue
                w = funcs[k][1]
                best = exp.get(nid(fn))
                if best is None:
                    prv = out[k - 1] if k else None
                    if prv is None or prv[1] is None:
                        # anywhere: the module function of about this size that differs least
                        n = 4 * len(w)
                        sizes = [(x, y) for x, y in zip(starts, starts[1:] + [mod.end]) if abs((y - x) - n) <= 16]
                        if not sizes:
                            out[k] = (fn, None, "missing")
                            continue
                        x, y = min(sizes, key=lambda t: (ndiff(w, mod.words[t[0] // 4:t[1] // 4]), abs((t[1] - t[0]) - n)))
                        if ndiff(w, mod.words[x // 4:y // 4]) > len(w) // 2:
                            out[k] = (fn, None, "missing")
                            continue
                        best = x
                    else:
                        best = prv[3] if len(prv) > 3 else prv[1] + 4 * len(funcs[k - 1][1])
                nx = [s for s in starts if s > best]
                end = nx[0] if nx else best + 4 * len(w)
                mw = mod.words[best // 4:end // 4]
                if len(mw) != len(w):
                    stt = f"size {4*len(w):#x}/{4*len(mw):#x}"
                else:
                    stt = f"diff {ndiff(w, mw)}"
                out[k] = (fn, best, stt, end)
            for k, o in enumerate(out):
                fn, addr, stt = o[0], o[1], o[2]
                tot += 1
                if stt == "same":
                    same += 1
                    covered.append((addr, addr + 4 * len(funcs[k][1]), fn))
                else:
                    bad.append(f"{fn}:{stt.replace(' ', '')}@{addr:#x}" if addr is not None else f"{fn}:{stt}")
                if not a.quiet:
                    print(f"  {cc1:10} {fname:14} {fn:32} {('%#07x' % addr) if addr is not None else '-':8} {stt}")
                if fn in a.verbose and addr is not None:
                    w = funcs[k][1]
                    end = o[3] if len(o) > 3 else addr + 4 * len(w)
                    print(f"--- {fn}: ours | original @{addr:#x}")
                    objcmp.side_by_side(w, mod.words[addr // 4:end // 4])
        print(f"{cc1:11} {same}/{tot}  " + " ".join(bad))
        if a.gaps:
            gaps(mod, covered, allf)


def gaps(mod, covered, allf):
    """module functions outside every exact match, with the most similar
    unmatched compiled function (callees, then size)"""
    cov = sorted(set(covered))
    byaddr = {a: fn for a, _, fn in cov}
    imp = getattr(mod, "impnames", {})
    done = {fn for _, _, fn in cov}
    starts = set(mod.starts()) | {a for a, _, _ in cov} | {b for _, b, _ in cov}
    starts = sorted(x for x in starts if x < mod.end)
    regions, pos = [], 0
    for a, b, fn in cov + [(mod.end, mod.end, None)]:
        if a > pos:
            ss = [x for x in starts if pos <= x < a] or [pos]
            if ss[0] != pos:
                ss = [pos] + ss
            for i, x in enumerate(ss):
                regions.append((x, ss[i + 1] if i + 1 < len(ss) else a))
        pos = max(pos, b)
    exp = {n: a for a, n in mod.exports.items()}
    cand = [(f, fn, w, c) for f, fn, w, c in allf if fn not in done]

    def mcalls(x, y):
        return sorted(byaddr.get(mod.calls[k], imp.get(mod.calls[k], hex(mod.calls[k])))
                      for k in range(x, y, 4) if k in mod.calls)
    for x, y in regions:
        mc = mcalls(x, y)
        name = next((fn for f, fn, w, c in cand if exp.get(nid(fn)) == x), None)

        def score(t):
            f, fn, w, c = t
            oc = sorted(str(v) for v in c.values() if not isinstance(v, tuple))
            common = len(set(oc) & set(map(str, mc)))
            return (-(fn == name), -common, abs(len(w) - (y - x) // 4))
        best = sorted(cand, key=score)[:2]
        desc = " | ".join(f"{fn}({f}) {4*len(w):#x}" + (f" diff {ndiff(w, mod.words[x//4:y//4])}" if 4 * len(w) == y - x else "")
                          for f, fn, w, c in best)
        print(f"GAP {x:#07x}-{y:#07x} {y-x:#6x} calls={','.join(map(str, mc[:6]))}  ~ {desc}")


if __name__ == "__main__":
    main()
