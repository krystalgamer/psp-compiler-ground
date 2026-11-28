#!/usr/bin/env python3
"""propagate.py TARGET [MODULE...] [--write] [--from TARGET2...]

Many functions exist in several modules (SDK samples sharing source files,
menu.c, the mpeg player in UTST99261 and UTST99332).  For every function
that is still INCLUDE_ASM, try each C definition of a function with the same
name already in decomp_src (outside NON_MATCHING blocks) in place of it,
with the unit's own context, and keep the first one that compiles to the
original (tools/fntest.py's comparison, the unit's cc1 and flags).
"""
import argparse
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
import tmpdir  # noqa: E402,F401  (scratch files in tmp/)
sys.path.insert(0, str(ROOT / "tools"))
import compiler  # noqa: E402
import m2c as m2cdraft  # noqa: E402
import objcmp  # noqa: E402
from fntest import compile_c  # noqa: E402

DEF = re.compile(r"^(?:static\s+)?[A-Za-z_][\w \t\*]*?\b(\w+)\s*\(((?:[^;{}()]|\((?:[^;{}()]|\([^;{}()]*\))*\))*)\)\s*\n?\{", re.M)


def strip_nonmatching(text):
    return re.sub(r"^#ifdef NON_MATCHING\n.*?^#else\n(.*?)^#endif\n", r"\1", text, flags=re.S | re.M)


def definitions(path):
    """name -> source of each C function defined in a file (brace matched)"""
    text = strip_nonmatching(path.read_text())
    out = {}
    for m in DEF.finditer(text):
        name = m.group(1)
        if name in ("if", "while", "for", "switch", "return"):
            continue
        i, depth = m.end() - 1, 0
        while i < len(text):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    break
            i += 1
        # declarations right above the definition (prototypes, #include,
        # #define of a static's label) travel with it
        pre = text[:m.start()].split("\n")[:-1]
        k = len(pre)
        while k > 0 and (re.match(r"^(#(include|define|undef)\b|extern |[A-Za-z_][^(){}]*\(.*\);$)", pre[k - 1])
                         or (pre[k - 1] == "" and k > 1 and pre[k - 2] != "" and not pre[k - 2].startswith(("}", "INCLUDE")))):
            k -= 1
        head = "\n".join(l for l in pre[k:] if l and not l.startswith("INCLUDE"))
        out[name] = (head + "\n" if head else "") + text[m.start():i + 1] + "\n"
    return out


SUFFIX = re.compile(r"_[0-9A-F]{4,8}$")


def base(name):
    """splat's name for a static that exists more than once: NAME_ADDR"""
    return SUFFIX.sub("", name)


def suffixes(target, module, unit, body):
    """rename NAME_ADDR (the source module's statics) after the target's"""
    d = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit
    stems = {f.stem for f in d.glob("*.s")}
    names = {base(n): n for n in stems if base(n) != n and not n.startswith("D_")}
    return re.sub(r"\b([A-Za-z_]\w*?)_[0-9A-F]{4,8}\b",
                  lambda m: m[0] if m[0] in stems else names.get(m[1], m[0]), body)


def library(targets):
    lib = {}
    for t in targets:
        for f in sorted((ROOT / "decomp_src" / t).rglob("*.c")):
            if "/newlib/" in str(f) or "/libgcc/" in str(f):
                continue
            for name, body in definitions(f).items():
                lib.setdefault(name, [])
                if body not in [b for b, _ in lib[name]]:
                    lib[name].append((body, f))
    return lib


_labels = {}


def module_labels(target, module):
    if (target, module) not in _labels:
        found = set()
        for f in (ROOT / "tmp" / "asm" / target / module).rglob("*.s"):
            found |= set(re.findall(r"^\s*(?:glabel|dlabel)\s+(D_[0-9A-F]{8})", f.read_text(), re.M))
        _labels[(target, module)] = found
    return _labels[(target, module)]


def asm_refs(target, module, unit, func):
    f = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit / f"{func}.s"
    return re.findall(r"%(?:hi|lo)\(([A-Za-z_]\w*)\)|\bjal\s+([A-Za-z_]\w*)", f.read_text()) if f.exists() else None


def map_labels(body, src, target, module, unit, func):
    """D_ labels are per module: rename those of the module the body comes
    from after the target's asm of the same function (same reference order)"""
    rel = src.relative_to(ROOT / "decomp_src").parts
    a = asm_refs(rel[0], rel[1], str(Path(*rel[2:]))[:-2], func)
    b = asm_refs(target, module, unit, func)
    a = a and [x or y for x, y in a]
    b = b and [x or y for x, y in b]
    words = set(re.findall(r"\b[A-Za-z_]\w*\b", body))
    # symbols the source module's asm calls differently from the target's
    labs = {x for x in words & set(a or []) if x not in set(b or [])}
    labs |= set(re.findall(r"\bD_[0-9A-F]{8}\b", body)) - module_labels(target, module)
    if not labs:
        return body
    if not a or not b or len(a) != len(b):
        return None
    pairs = dict(zip(a, b))
    if any(pairs.get(x, y) != y for x, y in zip(a, b)) or not labs <= set(pairs):
        return None
    # a body that names the symbol (not a #define'd label) keeps its name via a #define
    out = re.sub(r"\bD_[0-9A-F]{8}\b", lambda m: pairs.get(m[0], m[0]), body)
    named = sorted(x for x in labs if not x.startswith("D_"))
    if named:
        out = ("".join(f"extern __typeof__({x}) {pairs[x]};\n#define {x} {pairs[x]}\n" for x in named)
               + out + "".join(f"#undef {x}\n" for x in named))
    return out


STUB = re.compile(r'^(#include "common.h"|/\*.*\*/|INCLUDE_ASM\(.*\);|INCLUDE_RODATA\(.*\);|)$')
_ctx = {}


def unit_text(target, module, unit, path):
    """The unit's source; a stub (only INCLUDE_ASMs) gets the DWARF
    declarations (dwarf2c --extern) so bodies can compile in it."""
    text = path.read_text()
    if not all(STUB.match(l) for l in text.splitlines()):
        return text
    key = (target, module, unit)
    if key not in _ctx:
        _ctx[key] = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), "--extern", target, module, unit],
                                   capture_output=True, text=True).stdout
    ctx = _ctx[key]
    if not ctx.strip():
        return text
    lines = text.splitlines(keepends=True)
    i = next((k + 1 for k, l in enumerate(lines) if l.startswith("#include")), 0)
    return "".join(lines[:i]) + "\n/* declarations recovered from DWARF */\n" + ctx + "\n" + "".join(lines[i:])


def drop_jump_tables(target, module, unit, func, text):
    """The C now emits FUNC's jump tables itself: drop their INCLUDE_RODATA.
    None if a table shares its rodata file with other data (can't install)."""
    d = ROOT / "tmp" / "asm" / target / module / "nonmatchings" / unit
    f = d / f"{func}.s"
    if not f.exists():
        return text
    # splat writes local labels as `jlabel .L...` or `.L...:`
    labels = {a or b for a, b in re.findall(r"^\s*(?:jlabel (\.L\w+)|(\.L\w+):)", f.read_text(), re.M)}
    if not labels:
        return text
    bad = []

    def keep(m):
        r = d / f"{m.group(1)}.s"
        if not r.exists():
            return m.group(0)
        rt = r.read_text()
        # `.word .L...` or numeric `.word 0x... # .L...`
        words = [c or v for v, c in re.findall(r"^\s*(?:/\*.*?\*/\s*)?\.word (\S+)(?:\s*# (\.L\w+))?", rt, re.M)]
        if not any(w in labels for w in words):
            return m.group(0)
        other = re.search(r"^\s*(?:/\*.*?\*/\s*)?\.(?:asciz|ascii|byte|half|short|float|double|space)\b", rt, re.M)
        if other or not all(w in labels for w in words):
            bad.append(m.group(1))
            return m.group(0)
        return ""
    text = re.sub(r'^INCLUDE_RODATA\("[^"]+", (\w+)\);\n?', keep, text, flags=re.M)
    return None if bad else text


_mprotos = {}


def module_protos(target, module):
    """name -> prototype of the non-static functions defined in the module's C units"""
    key = (target, module)
    if key not in _mprotos:
        out = {}
        for f in sorted((ROOT / "decomp_src" / target / module).rglob("*.c")):
            for line in f.read_text(errors="replace").splitlines():
                m = re.match(r"^(?!static|extern|typedef|#|\s|return)([\w \*]+?\b(\w+)\s*\((?:[^;{}()]|\([^()]*\))*\))\s*\{?\s*$", line)
                if m and m[2] not in out and m[2] not in ("if", "while", "for", "switch"):
                    out[m[2]] = m[1] + ";"
        _mprotos[key] = out
    return _mprotos[key]


def try_body(target, module, unit, func, body, mod):
    # with the module's prototypes first; without them if their types are unknown here
    return try_body1(target, module, unit, func, body, mod, True) or \
        try_body1(target, module, unit, func, body, mod, False)


def try_body1(target, module, unit, func, body, mod, protos):
    path = ROOT / "decomp_src" / target / module / f"{unit}.c"
    text = unit_text(target, module, unit, path)
    inc = r'INCLUDE_ASM\("[^"]+", ' + re.escape(func) + r"\);"
    # a NON_MATCHING draft block goes as a whole (its #else holds the INCLUDE_ASM)
    pat = re.compile(r"^#ifdef NON_MATCHING\n(?:(?!#endif\b|#ifdef NON_MATCHING\n).*\n)*?#else\n"
                     + inc + r"\n#endif$|^(?<!#else\n)" + inc + "$", re.M)
    sdk = m2cdraft.sdk_protos(text)
    # SDK prototypes of the functions the body calls (not FUNC itself, nor ones the unit has)
    decl = "\n".join(v for k, v in sdk.items() if k != func and re.search(rf"\b{k}\(", body)
                     and not re.search(rf"^[^\n;(]*\b{k}\s*\([^;{{]*\)\s*;", text, re.M))
    # the module's own functions the body calls without a declaration in the unit:
    # implicit int returns and double-promoted float arguments change the code
    mp = module_protos(target, module) if protos else {}
    extra = [mp[n] for n in sorted(set(re.findall(r"\b(\w+)\s*\(", body)) - {func})
             if n in mp and n not in sdk and not re.search(rf"^[^\n;(]*\b{n}\s*\([^;{{]*\)\s*[;{{]", text, re.M)]
    decl = "\n".join(x for x in [decl] + extra if x)
    new = pat.sub(lambda _: (decl + "\n" if decl else "") + body.rstrip("\n"), text, count=1)
    if new == text:
        return None
    new = drop_jump_tables(target, module, unit, func, new)
    if new is None:
        return None
    m = re.search(r"cflags: (-O[0-9s](?: +-(?:[fm][\w-]+|std)(?:=[\w.:]+)?)*)", text)
    flags = (m.group(1) if m else "-O2") + " " + compiler.driver_flags(target, module, unit)
    with tempfile.TemporaryDirectory() as td:
        c = Path(td) / "t.c"
        c.write_text(new)
        try:
            o = compile_c(c, compiler.compiler(target, module, unit), flags, Path(td) / "t.o",
                          [path.parent, ROOT / "decomp_src" / target / module])
        except subprocess.CalledProcessError:
            return None
        if o is None:
            return None
        if objcmp.compare(mod, [o]).get(func) == "same":
            return new
    return None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("modules", nargs="*")
    ap.add_argument("--write", action="store_true")
    ap.add_argument("--only", action="append", help="only these units")
    ap.add_argument("--from", dest="sources", nargs="*", default=["UTST99261", "UTST99332", "sampler", "puzzle_bobble"])
    a = ap.parse_args()
    lib = library(a.sources)
    modules = a.modules or sorted(p.name for p in (ROOT / "decomp_src" / a.target).iterdir() if p.is_dir())
    total = 0
    for module in modules:
        mod = None
        for path in sorted((ROOT / "decomp_src" / a.target / module).rglob("*.c")):
            unit = str(path.relative_to(ROOT / "decomp_src" / a.target / module))[:-2]
            if unit.startswith(("newlib/", "libgcc/", "gcc-3.3.3/")) or unit == "crt0" or (a.only and unit not in a.only):
                continue
            for func in re.findall(r'^INCLUDE_ASM\("[^"]+", (\w+)\);$', path.read_text(), re.M):
                cands = [(b, f) for b, f in (lib.get(func) or lib.get(base(func), [])) if f != path]
                if not cands:
                    continue
                mod = mod or objcmp.module_funcs(a.target, module)
                for body, src in cands:
                    body = suffixes(a.target, module, unit, body)
                    body = map_labels(body, src, a.target, module, unit, func)
                    if body is None:
                        continue
                    new = try_body(a.target, module, unit, func, body, mod)
                    if new:
                        total += 1
                        print(f"{module}/{unit}:{func}  <- {src.relative_to(ROOT / 'decomp_src')}", flush=True)
                        if a.write:
                            if "INCLUDE_ASM" not in new:
                                # all C now: it emits the unit's rodata itself
                                new = re.sub(r'^INCLUDE_RODATA\("[^"]+", \w+\);\n', "", new, flags=re.M)
                            path.write_text(new)
                        break
    print(f"# {total} functions propagated")


if __name__ == "__main__":
    main()
