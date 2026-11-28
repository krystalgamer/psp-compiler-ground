#!/usr/bin/env python3
"""m2c.py TARGET MODULE [UNIT] FUNC [m2c args...]: m2c draft of a function.

The unit's DWARF declarations (tools/dwarf2c.py) are the context, so m2c
knows the real types, globals and prototypes.  INCLUDE_ASM files use
numeric registers (for old psp-as); m2c wants ABI names.
"""
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
import tmpdir  # noqa: E402,F401  (scratch files in tmp/)
# PSP EABI: $8-$11 are argument registers, which m2c's mipsee names a4-a7
ABI = ["zero", "at", "v0", "v1", "a0", "a1", "a2", "a3",
       "a4", "a5", "a6", "a7", "t4", "t5", "t6", "t7",
       "s0", "s1", "s2", "s3", "s4", "s5", "s6", "s7",
       "t8", "t9", "k0", "k1", "gp", "sp", "fp", "ra"]


KNOWN = {"void", "int", "char", "short", "long", "unsigned", "signed", "float", "double", "const",
         "static", "u8", "s8", "u16", "s16", "u32", "s32", "f32", "f64", "M2C_UNK"}


SDK = ROOT / "tools" / "sdk_protos.h"


def sdk_protos(ctx):
    """tools/sdk_protos.h minus what ctx declares itself: {name: line}."""
    out = {}
    for line in SDK.read_text().splitlines():
        m = re.search(r"(\w+)\(", line)
        if m and not line.startswith(("/*", " ")) and not re.search(rf"\b{m.group(1)}\s*\(", ctx):
            for t in set(re.findall(r"\bSce\w+", line)):
                if t != m.group(1) and not re.search(rf"(typedef [^;]*\b|}}\s*){t};", ctx):
                    line = re.sub(rf"\b{t}\b", "void", line)
            out[m.group(1)] = line
    return out


def c_prototypes(target, module):
    """Without DWARF: the prototypes of the module's functions already in C
    (so m2c sees their arguments)."""
    out = ["typedef unsigned char u8; typedef signed char s8; typedef short s16;",
           "typedef unsigned short u16; typedef int s32; typedef unsigned int u32;",
           "typedef float f32; typedef double f64; typedef int M2C_UNK;"]
    for f in sorted((ROOT / "decomp_src" / target / module).rglob("*.c")):
        try:
            text = f.read_text(errors="replace")
        except OSError:
            continue    # e.g. another process's temporary file, gone again
        for m in re.finditer(r"^(?:static )?([A-Za-z_][\w ]*?[\w*]) ?\*?\s*(\w+)\(([^;{}()]*)\)\s*\{",
                             text, re.M):
            line = m.group(0).rstrip("{").strip()
            params = [x.strip() for x in m.group(3).split(",") if x.strip()]
            if any(re.fullmatch(r"[A-Za-z_]\w*", x) and x != "void" for x in params):
                continue    # K&R definition `f(a, b)`: no prototype to give
            words = set(re.findall(r"[A-Za-z_]\w*", re.sub(r"\w+\s*(,|\)|$)", r"\1", m.group(3))))
            words |= set(re.findall(r"[A-Za-z_]\w*", m.group(1)))
            if words <= KNOWN and not line.startswith(("if", "while", "for", "switch", "return")):
                # a draft's void may hide a return value: leave it open
                out.append(re.sub(r"^void (?!\*)", "M2C_UNK ", re.sub(r"^static ", "", line)) + ";")
    return "\n".join(out) + "\n"


def fix_delay_labels(text):
    """m2c fails on a branch whose delay slot is a jump target: duplicate the
    delay instruction behind the label."""
    lines = text.split('\n')
    out = []
    n = 0
    BR = re.compile(r'^\s*(?:/\*.*?\*/)?\s*(b\w*|j|jal|jr|jalr)\s')
    i = 0
    while i < len(lines):
        l = lines[i]
        out.append(l)
        if BR.match(l) and not l.strip().startswith('.'):
            # collect labels before the delay instruction
            j = i + 1
            labs = []
            while j < len(lines) and re.match(r'^\s*\.L\w+:\s*$', lines[j]):
                labs.append(lines[j]); j += 1
            if labs and j < len(lines):
                d = lines[j]
                n += 1
                out.append(d)
                out.append('    j .Lfixd%d' % n)
                out.append('    nop')
                out.extend(labs)
                out.append(d)
                out.append('.Lfixd%d:' % n)
                i = j + 1
                continue
        i += 1
    return '\n'.join(out)


def draft(target, module, unit, func, extra=()):
    asm = ROOT / "tmp/asm" / target / module / "nonmatchings" / unit / f"{func}.s"
    src = asm.read_text()
    # jump tables live in their own rodata files: append the ones this function references
    for ref in sorted(set(re.findall(r"%(?:hi|lo)\((\w+)\)", src))):
        t = asm.parent / f"{ref}.s"
        if not t.exists() or f"dlabel {ref}" in src:
            continue
        # entries are numbers with the label in a comment (.word 0x0000AE00 # .L0000AE00)
        tt = re.sub(r"\.word\s+0x[0-9A-Fa-f]+\s*#\s*(\.L\w+)", r".word \1", t.read_text())
        if ".word .L" in tt:
            src += "\n.section .rodata\n" + tt
    text = re.sub(r"\$(\d+)\b", lambda m: "$" + ABI[int(m[1])] if int(m[1]) < 32 else m[0], src)
    # gcc's divide-by-zero checks (branch over `break 7`, emitted as .word 0x1CD) confuse m2c
    text = re.sub(r"\n[^\n]*\bb(?:eq|ne)l?\s+\$\w+, \$zero, \.L\w+\n[^\n]*\.word\s+0x000001CD[^\n]*", "", text)
    text = fix_delay_labels(text)
    # m2c finds jump tables by name
    for tbl in re.findall(r"dlabel (\w+)\n\s*(?:/\*.*?\*/)?\s*\.word\s+\.L", text):
        if not tbl.startswith("jtbl"):
            text = re.sub(r"\b%s\b" % tbl, "jtbl_" + tbl, text)
    ctx = subprocess.run([sys.executable, str(ROOT / "tools/dwarf2c.py"), target, module, unit],
                         capture_output=True, text=True, check=True).stdout
    if not ctx.strip():
        ctx = c_prototypes(target, module)
    ctx += "\n" + "\n".join(sdk_protos(ctx).values()) + "\n"
    with tempfile.TemporaryDirectory() as td:
        (Path(td) / "f.s").write_text(text)
        (Path(td) / "ctx.c").write_text(ctx)
        r = subprocess.run([sys.executable, str(ROOT / "tools/m2c_allegrex.py"), "-t", "mipsee-gcc-c",
                            "--context", str(Path(td) / "ctx.c"), *extra, str(Path(td) / "f.s")],
                           capture_output=True, text=True)
    return (r.stdout if r.returncode == 0 else None), (r.stderr if r.returncode == 0 else r.stdout + r.stderr)


def find_unit(target, module, func):
    """The unit whose nonmatchings hold FUNC's asm (None if not exactly one)."""
    base = ROOT / "tmp/asm" / target / module / "nonmatchings"
    hits = [p.parent.relative_to(base).as_posix() for p in base.rglob(f"{func}.s")]
    return hits[0] if len(hits) == 1 else None


if __name__ == "__main__":
    a = sys.argv[1:]
    if len(a) < 3:
        sys.exit("usage: m2c.py TARGET MODULE [UNIT] FUNC [m2c args...]")
    # TARGET MODULE FUNC: find the unit
    if len(a) == 3 or a[3].startswith("-"):
        unit = find_unit(a[0], a[1], a[2])
        if unit is None:
            sys.exit(f"m2c.py: no single unit with {a[2]}.s; give the unit")
        a = a[:2] + [unit] + a[2:]
    if not (ROOT / "tmp/asm" / a[0] / a[1] / "nonmatchings" / a[2] / f"{a[3]}.s").exists():
        sys.exit(f"m2c.py: no asm for {a[3]} in unit {a[2]}")
    out, err = draft(*a[:4], a[4:])
    sys.stdout.write(out or "")
    sys.stderr.write(err)
    sys.exit(0 if out else 1)
