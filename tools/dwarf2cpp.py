#!/usr/bin/env python3
"""dwarf2cpp.py TARGET MODULE UNIT [--probe FILE] [--symbols] : C++ declarations of a unit.

With DWARF (a C++ compile unit, DW_AT_language 4): the unit's classes and
structs with their bases, members at their DW_AT_data_member_location
offsets (gaps become padding arrays), virtual methods in vtable order, the
other methods, static members, enums, typedefs, globals and functions, in
the namespaces they belong to.  GCC 3.3 emits no DW_TAG_namespace: a type's
namespace comes from the DW_AT_MIPS_linkage_name of its methods, a
function's or variable's from its own linkage name, and otherwise from the
module's symbols.  Template instantiations (`vector<int>`) become structs
named by their demangled name with the punctuation replaced.

--probe FILE also writes a C++ file that checks every member offset and
type size (array sizes that go negative) and compiles it with cc1plus.

--symbols (and units without DWARF, such as UTST99332's main.cpp): a
skeleton from the module's symbol table instead: every function and object
of the unit's .text range, demangled, grouped into namespaces and classes;
virtual methods in the order of their vtable (_ZTV contents), base classes
from the typeinfo objects (_ZTI: __si_class_type_info = one base).
"""
import argparse
import io
import re
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import modules  # noqa: E402


def attr(d, k, default=None):
    if d is None or k not in d.attributes:
        return default
    v = d.attributes[k].value
    return v.decode(errors="replace") if isinstance(v, bytes) else v


_cache = {}


def demangle(names):
    names = [n for n in names if n not in _cache]
    if names:
        out = subprocess.run(["c++filt"], input="\n".join(names) + "\n", capture_output=True, text=True).stdout
        for n, d in zip(names, out.splitlines()):
            _cache[n] = d


def dm(name):
    demangle([name])
    return _cache[name]


# --- demangled-name parsing --------------------------------------------------

def split_top(s, sep):
    """Split s at sep outside <>, () and []."""
    out, depth, cur, i = [], 0, "", 0
    while i < len(s):
        if s.startswith("operator", i) and depth == 0:
            # operator<, operator<<, operator() ...: copy the operator token
            m = re.match(r"operator\s*(\(\)|\[\]|<<=|>>=|<<|>>|<=|>=|->\*|->|[-+*/%^&|~!=<>,]=?|\w[\w\s:*&<>]*?(?=\())", s[i:])
            if m:
                cur += m.group(0)
                i += len(m.group(0))
                continue
        c = s[i]
        if c in "<([":
            depth += 1
        elif c in ">)]":
            depth -= 1
        if depth == 0 and s.startswith(sep, i):
            out.append(cur)
            cur = ""
            i += len(sep)
            continue
        cur += c
        i += 1
    out.append(cur)
    return out


def parse_function(d):
    """'ret ns::C::f(args) const' -> (ret, [scope...], name, [args], const)"""
    const = d.endswith(" const")
    if const:
        d = d[:-6]
    if not d.endswith(")"):
        return None
    depth = 0
    for i in range(len(d) - 1, -1, -1):
        if d[i] == ")":
            depth += 1
        elif d[i] == "(":
            depth -= 1
            if depth == 0:
                break
    head, args = d[:i], d[i + 1:-1]
    # the qualified name is the last top-level space-separated token of head
    toks = split_top(head, " ")
    # re-join pieces like 'operator new' / 'unsigned int' return types
    j = len(toks) - 1
    if j > 0 and toks[j - 1].endswith("operator"):
        j -= 1
    qual = " ".join(toks[j:])
    ret = " ".join(toks[:j])
    parts = split_top(qual, "::")
    a = [x.strip() for x in split_top(args, ",")] if args.strip() not in ("", "void") else []
    return ret, parts[:-1], parts[-1], a, const


def ident(s):
    """A C++ identifier for a template instantiation's name."""
    return re.sub(r"_+", "_", re.sub(r"[^\w]", "_", s)).strip("_")


# --- DWARF mode --------------------------------------------------------------

class Unit:
    def __init__(self, cu, symnames):
        self.cu = cu
        self.off = {d.offset: d for d in cu.iter_DIEs()}
        self.symnames = symnames
        self.scope = {}       # die offset -> [namespace parts] (+ enclosing classes)
        self.anon = {}
        self.done = set()
        self.out = []
        self.probe = []
        names = [attr(d, "DW_AT_MIPS_linkage_name") for d in cu.iter_DIEs() if attr(d, "DW_AT_MIPS_linkage_name")]
        self.defs = {}
        for d in cu.get_top_DIE().iter_children():
            if d.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type") and \
                    "DW_AT_specification" in d.attributes:
                self.defs[d.attributes["DW_AT_specification"].value + cu.cu_offset] = d
        demangle(names)
        self.find_scopes()

    def ref(self, d, k="DW_AT_type"):
        if d is None or k not in d.attributes:
            return None
        return self.off.get(d.attributes[k].value + self.cu.cu_offset)

    def find_scopes(self):
        top = self.cu.get_top_DIE()
        for d in top.iter_children():
            if d.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type"):
                for m in d.iter_children():
                    ln = attr(m, "DW_AT_MIPS_linkage_name")
                    if m.tag == "DW_TAG_subprogram" and ln:
                        p = parse_function(dm(ln))
                        if p and len(p[1]) >= 1:
                            self.scope[d.offset] = p[1][:-1]
                            break
        # types named in symbols (typeinfo, vtables, functions) give namespaces too
        qual = defaultdict(set)
        for s in self.symnames:
            dd = _cache.get(s, s)
            for m in re.finditer(r"((?:\w+::)+)(\w+)", dd):
                qual[m.group(2)].add(m.group(1)[:-2])
        for d in top.iter_children():
            n = attr(d, "DW_AT_name")
            if d.offset in self.scope or not n or d.tag not in (
                    "DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type",
                    "DW_TAG_enumeration_type", "DW_TAG_typedef"):
                continue
            cands = {q for q in qual.get(n, ()) if not q.endswith(n)}
            if len(cands) == 1:
                self.scope[d.offset] = split_top(cands.pop(), "::")
        # a scope that is a class (nested types we see at the top level, such
        # as allocator<char>::rebind<char>): keep the namespaces and flatten
        # the class part into the name
        known = set()
        for d in top.iter_children():
            if d.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type") and attr(d, "DW_AT_name"):
                known.add("::".join(self.scope.get(d.offset, []) + [attr(d, "DW_AT_name")]))
        self.flat = {}
        for off, sc in list(self.scope.items()):
            for i in range(len(sc)):
                if "<" in sc[i] or "::".join(sc[:i + 1]) in known:
                    self.scope[off] = sc[:i]
                    self.flat[off] = ident("::".join(sc[i:])) + "_"
                    break

    def spec(self, t):
        """A class defined outside its parent (DW_AT_specification): the declaration."""
        while t is not None and "DW_AT_specification" in t.attributes and not attr(t, "DW_AT_name"):
            t = self.ref(t, "DW_AT_specification")
        return t

    def path(self, t):
        """Enclosing namespaces and classes of a type."""
        t = self.spec(t)
        p = t.get_parent()
        if p is None or p.tag == "DW_TAG_compile_unit":
            return [x for x in self.scope.get(t.offset, []) if x != "(anonymous namespace)"]
        return self.path(p) + [self.name(p)]

    def name(self, t):
        t = self.spec(t)
        n = attr(t, "DW_AT_name")
        if n is None or n[:1] in "$.":
            if t.offset not in self.anon:
                self.anon[t.offset] = f"_anon{len(self.anon) + 1}"
            return self.anon[t.offset]
        return self.flat.get(t.offset, "") + (ident(n) if "<" in n else n)

    def qname(self, t, elab=True):
        kw = {"DW_TAG_structure_type": "struct ", "DW_TAG_class_type": "class ", "DW_TAG_union_type": "union ",
              "DW_TAG_enumeration_type": "enum "}.get(t.tag, "")
        if not elab or kw and (attr(t, "DW_AT_name") is None or attr(t, "DW_AT_name")[:1] in "$."):
            kw = ""
        return kw + "::".join([*self.path(t), self.name(t)])

    def decl(self, t, name=""):
        """C++ declarator for an object of type t called name."""
        if t is None:
            return f"void {name}".rstrip()
        tag = t.tag
        if tag == "DW_TAG_base_type":
            return f"{attr(t, 'DW_AT_name')} {name}".rstrip()
        if tag == "DW_TAG_typedef" and t.get_parent().tag != "DW_TAG_compile_unit":
            # GCC 3.3 puts some typedefs in odd classes (std::streamoff in
            # char_traits<char>): use the type itself
            return self.decl(self.ref(t), name)
        if tag in ("DW_TAG_typedef", "DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type",
                   "DW_TAG_enumeration_type"):
            return f"{self.qname(t)} {name}".rstrip()
        if tag == "DW_TAG_const_type":
            inner = self.ref(t)
            if inner is not None and inner.tag == "DW_TAG_reference_type":
                return self.decl(inner, name)
            if inner is not None and inner.tag == "DW_TAG_pointer_type":
                return self.decl(inner, f"const {name}".rstrip())
            d = self.decl(inner, name)
            return d if d.startswith("const ") else "const " + d
        if tag == "DW_TAG_volatile_type":
            return "volatile " + self.decl(self.ref(t), name)
        if tag in ("DW_TAG_pointer_type", "DW_TAG_reference_type"):
            op = "*" if tag == "DW_TAG_pointer_type" else "&"
            inner = self.ref(t)
            if inner is not None and inner.tag in ("DW_TAG_subroutine_type", "DW_TAG_array_type"):
                return self.decl(inner, f"({op}{name})")
            return self.decl(inner, f"{op}{name}")
        if tag == "DW_TAG_ptr_to_member_type":
            cls = self.ref(t, "DW_AT_containing_type")
            inner = self.ref(t)
            n = f"{self.qname(cls, False)}::*{name}"
            if inner is not None and inner.tag == "DW_TAG_subroutine_type":
                return self.decl(inner, f"({n})")
            return self.decl(inner, n)
        if tag == "DW_TAG_array_type":
            dims = ""
            for s in t.iter_children():
                if s.tag == "DW_TAG_subrange_type":
                    ub = attr(s, "DW_AT_upper_bound")
                    dims += f"[{ub + 1}]" if isinstance(ub, int) else "[]"
            return self.decl(self.ref(t), f"{name}{dims or '[]'}")
        if tag == "DW_TAG_subroutine_type":
            ps = [p for p in t.iter_children() if p.tag == "DW_TAG_formal_parameter"]
            params = [self.decl(self.ref(p)) for p in ps]
            if any(p.tag == "DW_TAG_unspecified_parameters" for p in t.iter_children()):
                params.append("...")
            return self.decl(self.ref(t), f"{name}({', '.join(params)})")
        return f"/* {tag} */ int {name}"

    # types this one needs complete (by-value members, bases, typedef targets)
    def deps(self, t):
        """Types to emit before t: complete types it holds by value (members,
        bases, typedef targets) and typedefs it names, also through pointers
        and in method signatures (a struct behind a pointer only needs the
        forward declaration every class gets)."""
        out = []

        def walk(x, byval=True):
            while x is not None:
                if x.tag in ("DW_TAG_const_type", "DW_TAG_volatile_type", "DW_TAG_array_type"):
                    x = self.ref(x)
                elif x.tag in ("DW_TAG_pointer_type", "DW_TAG_reference_type"):
                    x, byval = self.ref(x), False
                elif x.tag == "DW_TAG_subroutine_type":
                    for p in x.iter_children():
                        if p.tag == "DW_TAG_formal_parameter":
                            walk(self.ref(p), False)
                    x, byval = self.ref(x), False
                else:
                    break
            if x is None:
                return
            if x.tag == "DW_TAG_typedef" or x.tag == "DW_TAG_enumeration_type" or byval:
                out.append(x)
        if t.tag == "DW_TAG_typedef":
            x = self.ref(t)
            walk(x, not (x is not None and x.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type")))
            return out
        for m in t.iter_children():
            if m.tag in ("DW_TAG_member", "DW_TAG_inheritance", "DW_TAG_typedef", "DW_TAG_variable"):
                walk(self.ref(m), m.tag != "DW_TAG_variable")
            elif m.tag == "DW_TAG_subprogram":
                walk(self.ref(m), False)
                for p in m.iter_children():
                    if p.tag == "DW_TAG_formal_parameter":
                        walk(self.ref(p), False)
            elif m.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type"):
                out += self.deps(self.defs.get(m.offset, m))
        return out

    def emit_type(self, t, stack=()):
        if t.offset in self.done or t.tag not in (
                "DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type",
                "DW_TAG_enumeration_type", "DW_TAG_typedef"):
            return
        if t.offset in stack:
            return
        for d in self.deps(t):
            # pointers inside a typedef'd struct only need forward declarations
            self.emit_type(d, stack + (t.offset,))
        if t.offset in self.done:
            return
        self.done.add(t.offset)
        if t.tag == "DW_TAG_typedef":
            x = self.ref(t)
            if t.get_parent().tag == "DW_TAG_compile_unit" and not (x is not None and attr(x, "DW_AT_name") == attr(t, "DW_AT_name")):
                self.put(t, f"typedef {self.decl(x, self.name(t))};")
            return
        if t.tag == "DW_TAG_enumeration_type":
            if t.get_parent().tag == "DW_TAG_compile_unit":
                self.put(t, self.enum_body(t))
            return
        if attr(t, "DW_AT_declaration") and t.offset in self.synth:
            if t.get_parent().tag == "DW_TAG_compile_unit":
                self.put(t, self.synth[t.offset])
            return
        if attr(t, "DW_AT_declaration") and not any(
                m.tag in ("DW_TAG_member", "DW_TAG_inheritance", "DW_TAG_subprogram") for m in t.iter_children()):
            return    # forward declaration only
        if t.get_parent().tag == "DW_TAG_compile_unit":
            self.put(t, self.class_body(t))

    def enum_body(self, t, ind=""):
        vals = [f"{ind}    {attr(e, 'DW_AT_name')} = {attr(e, 'DW_AT_const_value')}," for e in t.iter_children()
                if e.tag == "DW_TAG_enumerator"]
        return f"{ind}enum {self.name(t)} {{\n" + "\n".join(vals) + f"\n{ind}}};"

    def loc(self, m):
        loc = attr(m, "DW_AT_data_member_location")
        if isinstance(loc, list) and loc and loc[0] in (0x10, 0x23):    # DW_OP_constu, DW_OP_plus_uconst ULEB128
            v, sh = 0, 0
            for b in loc[1:]:
                v |= (b & 0x7F) << sh
                sh += 7
                if not b & 0x80:
                    break
            return v
        return loc if isinstance(loc, int) else None

    def method(self, m, cls):
        """Declaration of a member function DIE (None for artificial ones)."""
        if attr(m, "DW_AT_artificial"):
            return None
        n = attr(m, "DW_AT_name")
        ps = [p for p in m.iter_children() if p.tag == "DW_TAG_formal_parameter"]
        static = not (ps and attr(ps[0], "DW_AT_artificial"))
        const = False
        if not static:
            this = self.ref(ps[0])
            const = self.ref(this) is not None and self.ref(this).tag == "DW_TAG_const_type"
            ps = ps[1:]
        # constructors and destructors also take artificial __in_chrg/__vtt_parm
        ps = [p for p in ps if not attr(p, "DW_AT_artificial")]
        params = [self.decl(self.ref(p), attr(p, "DW_AT_name") or "") for p in ps]
        if any(p.tag == "DW_TAG_unspecified_parameters" for p in m.iter_children()):
            params.append("...")
        sig = f"{n}({', '.join(params)}){' const' if const else ''}"
        base = (attr(self.spec(cls), "DW_AT_name") or "").split("<")[0]
        if n in (base, "~" + base):
            # constructor or destructor (renamed with an instantiation's class)
            d = ("~" if n[0] == "~" else "") + self.name(cls) + sig[len(n):]
        elif n.startswith("operator ") and n[9:10].isalpha() and n[9:12] not in ("new", "del"):
            d = "operator " + self.decl(self.ref(m)) + sig[len(n):]    # conversion
        else:
            d = self.decl(self.ref(m), sig)
        virt = attr(m, "DW_AT_virtuality")
        pre = "static " if static else ("virtual " if virt else "")
        post = " = 0" if virt == 2 else ""
        if "<" in n and not n.startswith("operator"):
            return f"/* template member: {pre}{d}{post}; */"
        return pre + d + post + ";"

    def class_body(self, t, ind=""):
        kw = {"DW_TAG_union_type": "union", "DW_TAG_class_type": "class"}.get(t.tag, "struct")
        name = self.name(t)
        size = attr(t, "DW_AT_byte_size")
        bases, mems, meths, virt, nested = [], [], [], [], []
        pos, pad, unknown = 0, 0, False
        ln = attr(t, "DW_AT_name") or ""
        if "<" in ln:
            nested.append(f"{ind}    /* {'::'.join(self.scope.get(t.offset, []) + [ln])} */")
        for m in t.iter_children():
            if m.tag == "DW_TAG_inheritance":
                b = self.ref(m)
                o = self.loc(m)
                acc = {1: "public", 2: "protected", 3: "private"}.get(attr(m, "DW_AT_accessibility"), "public")
                v = "virtual " if attr(m, "DW_AT_virtuality") else ""
                bases.append(f"{acc} {v}{self.qname(b, False)}")
                self.probe.append((self.qname(t), None, self.qname(b), o))
                if o is not None and b is not None and attr(b, "DW_AT_byte_size"):
                    pos = max(pos, o + attr(b, "DW_AT_byte_size"))
                else:
                    unknown = True    # a base of unknown size: no padding before the next member
            elif m.tag == "DW_TAG_member":
                n = attr(m, "DW_AT_name") or f"_unnamed{len(mems)}"
                p = m.get_parent()
                while p is not None and p.tag != "DW_TAG_compile_unit":
                    if attr(p, "DW_AT_name") == n:
                        n += "_"     # C allows a member named like its struct
                    p = p.get_parent()
                o = self.loc(m)
                if n.startswith("_vptr"):
                    mems.append(f"{ind}    /* {o:#x} {n} */")
                    pos = max(pos, (o or 0) + 4)
                    continue
                if unknown and o is not None:
                    pos, unknown = max(pos, o), False
                if kw != "union" and o is not None and o > pos and not attr(m, "DW_AT_bit_size"):
                    mems.append(f"{ind}    char _pad{pad}[{o - pos:#x}];")
                    pad += 1
                bits = attr(m, "DW_AT_bit_size")
                mt = self.ref(m)
                mems.append(f"{ind}    {self.decl(mt, n)}{' : ' + str(bits) if bits else ''};"
                            + (f" /* {o:#x} */" if o is not None else ""))
                mt0 = mt
                while mt0 is not None and mt0.tag in ("DW_TAG_const_type", "DW_TAG_volatile_type"):
                    mt0 = self.ref(mt0)
                if o is not None and not bits and not (mt0 is not None and mt0.tag == "DW_TAG_reference_type"):
                    self.probe.append((self.qname(t), n, None, o))
                if o is not None:
                    sz = attr(m, "DW_AT_byte_size") if bits else self.size(mt)
                    if sz is not None:
                        pos = max(pos, o + sz)
            elif m.tag == "DW_TAG_variable":
                meths.append(f"{ind}    static {self.decl(self.ref(m), attr(m, 'DW_AT_name'))};")
            elif m.tag == "DW_TAG_subprogram":
                d = self.method(m, t)
                if d is None:
                    continue
                vl = attr(m, "DW_AT_vtable_elem_location")
                if attr(m, "DW_AT_virtuality") and isinstance(vl, list) and len(vl) >= 2:
                    virt.append((vl[1], f"{ind}    {d}"))
                elif attr(m, "DW_AT_virtuality"):
                    # GCC 3.3 gives a virtual destructor no vtable index: it
                    # fills the first two free slots (complete, deleting)
                    virt.append((None, f"{ind}    {d}"))
                else:
                    meths.append(f"{ind}    {d}")
            elif m.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type"):
                self.scope[m.offset] = self.scope.get(t.offset, []) + [name]
                m = self.defs.get(m.offset, m)
                if not attr(m, "DW_AT_declaration"):
                    nested.append(self.class_body(m, ind + "    "))
                else:
                    kw2 = {"DW_TAG_union_type": "union", "DW_TAG_class_type": "class"}.get(m.tag, "struct")
                    nested.append(f"{ind}    {kw2} {self.name(m)};")
            elif m.tag == "DW_TAG_enumeration_type":
                self.scope[m.offset] = self.scope.get(t.offset, []) + [name]
                nested.append(self.enum_body(m, ind + "    "))
            elif m.tag == "DW_TAG_typedef":
                tn = attr(m, "DW_AT_name") or ""
                if tn[:1] in "$." or (self.ref(m) is not None and self.ref(m).offset == t.offset):
                    continue    # C's `typedef struct {...} T;` and the injected class name
                self.scope[m.offset] = self.scope.get(t.offset, []) + [name]
                nested.append(f"{ind}    typedef {self.decl(self.ref(m), tn)};")
        if size is not None and kw != "union" and size > pos and pos > 0:
            mems.append(f"{ind}    char _pad{pad}[{size - pos:#x}];")
        if size is not None:
            self.probe.append((self.qname(t), None, None, size))
        head = f"{ind}{kw} {name}" + (f" : {', '.join(bases)}" if bases else "")
        body = [f"{ind}public:"] if kw == "class" else []
        used = {k for k, _ in virt if k is not None}
        k = 0
        for i, (idx, v) in enumerate(virt):
            if idx is None:
                while k in used or k + 1 in used:
                    k += 1
                virt[i] = (k, v)
                used |= {k, k + 1}
        fwdn = []
        for m in t.iter_children():
            if m.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type") and attr(m, "DW_AT_name") \
                    and attr(m, "DW_AT_name")[:1] not in "$.":
                kw2 = {"DW_TAG_union_type": "union", "DW_TAG_class_type": "class"}.get(m.tag, "struct")
                fwdn.append(f"{ind}    {kw2} {self.name(m)};")
        nested = [x for x in nested if x not in fwdn]
        body += fwdn + nested + mems + [v for _, v in sorted(virt)] + meths
        sz = f" /* size {size:#x} */" if size is not None else " /* incomplete in the DWARF */"
        return f"{head} {{{sz}\n" + "\n".join(body) + f"\n{ind}}};"

    def size(self, t):
        while t is not None:
            s = attr(t, "DW_AT_byte_size")
            if s is not None:
                return s
            if t.tag == "DW_TAG_array_type":
                n = 1
                for s in t.iter_children():
                    ub = attr(s, "DW_AT_upper_bound")
                    if s.tag == "DW_TAG_subrange_type" and isinstance(ub, int):
                        n *= ub + 1
                e = self.size(self.ref(t))
                return None if e is None else n * e
            t = self.ref(t)
        return None

    def put(self, d, text):
        self.out.append((tuple(self.scope.get(d.offset, [])), text))

    def synthesize(self, top):
        """Bases the CU only declares: as much of them as the derived classes
        show (their size up to the first member; a vptr if the derived class
        has virtual methods but no _vptr of its own)."""
        self.synth = {}
        for d in top.iter_children():
            for i in d.iter_children():
                if i.tag != "DW_TAG_inheritance":
                    continue
                b = self.ref(i)
                if b is None or not attr(b, "DW_AT_declaration") or any(
                        c.tag in ("DW_TAG_member", "DW_TAG_inheritance") for c in b.iter_children()):
                    continue
                first = min((self.loc(m) for m in d.iter_children()
                             if m.tag == "DW_TAG_member" and self.loc(m) is not None), default=attr(d, "DW_AT_byte_size"))
                virt = any(attr(m, "DW_AT_virtuality") for m in d.iter_children() if m.tag == "DW_TAG_subprogram")
                own = any((attr(m, "DW_AT_name") or "").startswith("_vptr") for m in d.iter_children())
                body = []
                n = first or 0
                if virt and not own:
                    body.append(f"    virtual ~{self.name(b)}();")
                    n -= 4
                if n > 0:
                    body.append(f"    char _pad[{n:#x}];")
                self.synth[b.offset] = (f"struct {self.name(b)} {{ /* only declared in the DWARF: "
                                        f"layout from {self.name(d)} */\n" + "\n".join(body) + "\n};")

    def run(self):
        top = self.cu.get_top_DIE()
        self.synthesize(top)
        # (the __*_type_info_pseudo types describe typeinfo objects: compiler-made)
        types = [d for d in top.iter_children() if d.tag in (
            "DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type",
            "DW_TAG_enumeration_type", "DW_TAG_typedef") and "_pseudo" not in (attr(d, "DW_AT_name") or "")
            and "DW_AT_specification" not in d.attributes]
        fwd = []
        for d in types:
            if d.tag in ("DW_TAG_structure_type", "DW_TAG_class_type", "DW_TAG_union_type") and attr(d, "DW_AT_name"):
                kw = {"DW_TAG_union_type": "union", "DW_TAG_class_type": "class"}.get(d.tag, "struct")
                fwd.append((tuple(self.scope.get(d.offset, [])), f"{kw} {self.name(d)};"))
        for d in types:
            self.emit_type(d)
        glob, funcs = [], []
        for d in top.iter_children():
            ln = attr(d, "DW_AT_MIPS_linkage_name")
            n = attr(d, "DW_AT_name")
            if d.tag == "DW_TAG_variable" and n and not attr(d, "DW_AT_specification") and not n.startswith("_ZT"):
                sc = parse_scope(dm(ln)) if ln else []
                # declared extern: the data stays in the module's asm
                how = "" if attr(d, "DW_AT_declaration") else (" /* defined here */" if attr(d, "DW_AT_external") else " /* static */")
                glob.append((tuple(sc), f"extern {self.decl(self.ref(d), n)};{how}"))
            elif d.tag == "DW_TAG_subprogram" and n and not attr(d, "DW_AT_specification"):
                p = parse_function(dm(ln)) if ln else None
                sc = p[1] if p else []
                ps = [x for x in d.iter_children() if x.tag == "DW_TAG_formal_parameter"]
                params = [self.decl(self.ref(x), attr(x, "DW_AT_name") or "") for x in ps]
                if any(x.tag == "DW_TAG_unspecified_parameters" for x in d.iter_children()):
                    params.append("...")
                st = "" if attr(d, "DW_AT_external") else "static "
                link = 'extern "C" ' if not ln and st == "" else ""
                line = f"{link}{st}{self.decl(self.ref(d), n + '(' + ', '.join(params) + ')')};"
                if "<" in n:     # a template function's instantiation
                    line = f"/* {line} */"
                funcs.append((tuple(sc), line))
        return fwd, self.out, glob, funcs


def parse_scope(d):
    return split_top(d, "::")[:-1]


def nest(items):
    """Print (scope, text) items, opening and closing namespaces as needed."""
    out, cur = [], ()
    for sc, text in items:
        sc = tuple(sc)
        k = 0
        while k < min(len(cur), len(sc)) and cur[k] == sc[k]:
            k += 1
        for _ in range(len(cur) - k):
            out.append("}")
        for n in sc[k:]:
            out.append("namespace {" if n == "(anonymous namespace)" else f"namespace {n} {{")
        cur = sc
        out.append(text)
    out += ["}"] * len(cur)
    return "\n".join(out)


def write_probe(path, probe, decls):
    lines = ["/* lang: c++ */", "#define OFFSETOF(T, m) ((unsigned)&((T *)0x100)->m - 0x100)", decls, ""]
    for i, (cls, mem, base, off) in enumerate(probe):
        if base is not None:
            lines.append(f"typedef char _probe{i}[((unsigned)(({base} *)({cls} *)0x100) - 0x100) == {off} ? 1 : -1];"
                         f" /* {cls} : {base} @ {off:#x} */")
        elif mem is not None:
            lines.append(f"typedef char _probe{i}[OFFSETOF({cls}, {mem}) == {off} ? 1 : -1]; /* {cls}::{mem} @ {off:#x} */")
        else:
            lines.append(f"typedef char _probe{i}[sizeof({cls}) == {off} ? 1 : -1]; /* sizeof {cls} */")
    Path(path).write_text("\n".join(lines) + "\n")


def check_probe(path):
    sys.path.insert(0, str(ROOT / "tools"))
    import compiler
    i = Path(path).with_suffix(".ii")
    r = subprocess.run(["cpp", *compiler.cxx_cppflags(), "-P", "-undef", "-nostdinc", str(path), "-o", str(i)],
                       capture_output=True, text=True)
    if r.returncode:
        return r.stderr
    r = subprocess.run([str(ROOT / "tmp" / "toolchains" / "bin" / "cc1plus-1.6.1"), "-quiet", "-fsyntax-only", str(i)],
                       capture_output=True, text=True)
    return r.stderr


# --- symbol mode -------------------------------------------------------------

def unit_range(target, module, unit):
    cfg = (ROOT / "config" / target / f"{module}.yaml").read_text()
    subs = [(int(m[1], 16), m[2]) for m in re.finditer(r"^\s*- \[0x([0-9A-Fa-f]+), \w+, ([^\]]+)\]", cfg, re.M)]
    subs += [(int(m[1], 16), m[2]) for m in re.finditer(r"start: 0x([0-9A-Fa-f]+), type: \w+, name: (\w+)", cfg)]
    subs.sort()
    for i, (s, n) in enumerate(subs):
        if n == unit:
            return s - 0x80, subs[i + 1][0] - 0x80
    raise SystemExit(f"no unit {unit} in {module}.yaml")


def symbols(elf):
    """name -> (vram, size, type, bind) of the module's symbols."""
    secs = [elf.get_section(i) for i in range(elf.num_sections())]
    out = []
    for s in elf.get_section_by_name(".symtab").iter_symbols():
        sh = s["st_shndx"]
        if not isinstance(sh, int) or not s.name:
            continue
        out.append((s.name, secs[sh]["sh_addr"] + s["st_value"], s["st_size"], s["st_info"]["type"],
                    s["st_info"]["bind"], secs[sh].name))
    return out


def word(elf, vram):
    for sec in elf.iter_sections():
        if sec["sh_type"] != "SHT_NOBITS" and sec["sh_addr"] <= vram < sec["sh_addr"] + sec["sh_size"] and sec.name:
            d = sec.data()
            o = vram - sec["sh_addr"]
            return int.from_bytes(d[o:o + 4], "little")
    return None


def symbol_mode(elf, target, module, unit):
    lo, hi = unit_range(target, module, unit)
    syms = symbols(elf)
    demangle([s[0] for s in syms])
    byaddr = defaultdict(list)
    for s in syms:
        if s[3] == "STT_FUNC":
            byaddr[s[1]].append(s[0])
    funcs = [s for s in syms if s[3] == "STT_FUNC" and lo <= s[1] < hi]
    funcs.sort(key=lambda s: s[1])
    classes = defaultdict(lambda: {"methods": [], "virtual": {}, "bases": [], "ns": []})
    free = []
    # vtables and typeinfo of the classes this unit defines methods of
    vt = {dm(s[0])[len("vtable for "):]: s for s in syms if s[0].startswith("_ZTV")}
    ti = {dm(s[0])[len("typeinfo for "):]: s for s in syms if s[0].startswith("_ZTI") and s[5] != ".bss"}
    seen = set()
    for name, addr, size, _, bind, _ in funcs:
        d = dm(name)
        if d in seen:
            continue    # C1/C2, D0/D1/D2 variants
        seen.add(d)
        p = parse_function(d)
        if p is None or d.startswith(("global constructors", "global destructors")) or "__static_init" in d:
            continue
        ret, scope, fn, args, const = p
        q = "::".join(scope)
        weak = bind == "STB_WEAK"
        # (the mangled name of a non-template function has no return type)
        ctor = re.match(r"^~?" + re.escape(scope[-1].split("<")[0]) + "$", fn) if scope else None
        line = f"{ret + ' ' if ret else ('' if ctor or fn.startswith('operator ') else '/*?*/ ')}{fn}({', '.join(args)}){' const' if const else ''};"
        if weak:
            line += " /* weak: inline or template */"
        if scope and (q in vt or q in ti or not scope[-1][:1].islower() or any(
                c in classes for c in [q])):
            classes[q]["methods"].append(line)
        elif scope and re.match(r"^~?" + re.escape(scope[-1].split("<")[0]) + r"$", fn.split("<")[0]):
            classes[q]["methods"].append(line)
        else:
            free.append((scope, line))
    for q in list(classes):
        if q in vt:
            _, a, size, *_ = vt[q]
            slots = []
            for k in range(2, size // 4):
                w = word(elf, a + 4 * k)
                names = byaddr.get(w, [])
                slots.append(dm(names[0]) if names else (hex(w) if w else "pure virtual / 0"))
            classes[q]["virtual"] = slots
        if q in ti:
            _, a, size, *_ = ti[q]
            if size == 12:     # __si_class_type_info: vptr, name, base
                w = word(elf, a + 8)
                b = [s[0] for s in syms if s[1] == w and s[0].startswith("_ZTI")]
                if b:
                    classes[q]["bases"].append(dm(b[0])[len("typeinfo for "):])
            elif size > 12:    # __vmi_class_type_info: vptr, name, flags, count, {base, offset_flags}...
                n = word(elf, a + 12) or 0
                for k in range(n):
                    w = word(elf, a + 16 + 8 * k)
                    of = word(elf, a + 20 + 8 * k)
                    b = [s[0] for s in syms if s[1] == w and s[0].startswith("_ZTI")]
                    acc = "public " if of & 2 else ""
                    virt = "virtual " if of & 1 else ""
                    if b:
                        classes[q]["bases"].append(f"{acc}{virt}{dm(b[0])[len('typeinfo for '):]} /* @{of >> 8:#x} */")
    # a tree of scopes: classes (with methods, a vtable or typeinfo) hold
    # their nested classes, everything else is a namespace
    tree = {"kids": {}, "lines": []}

    def node(parts):
        n = tree
        for p in parts:
            n = n["kids"].setdefault(p, {"kids": {}, "lines": []})
        return n
    for q in classes:
        node(split_top(q, "::"))
    for sc, line in free:
        node(sc)["lines"].append(line)

    def show(n, path, ind, inclass=False):
        out = []
        q = "::".join(path)
        if q in classes or inclass:
            c = classes.get(q, {"bases": [], "virtual": [], "methods": []})
            name = path[-1]
            head = f"{ind}struct {ident(name) if '<' in name else name}"
            if c["bases"]:
                head += " : " + ", ".join(b if b.startswith("public") else "public " + b for b in c["bases"])
            out.append(head + " {" + (f" /* {q} */" if "<" in name else ""))
            for k in sorted(n["kids"]):
                out += show(n["kids"][k], path + [k], ind + "    ", True)
            if c["virtual"]:
                out.append(f"{ind}    /* vtable: */")
                for k, v in enumerate(c["virtual"]):
                    out.append(f"{ind}    /* [{k}] {v} */")
            out += [f"{ind}    {m}" for m in c["methods"]]
            out += [f"{ind}    {m}" for m in n["lines"]]
            out.append(f"{ind}}};")
        else:
            if path:
                out.append(f"{ind}namespace {path[-1]} {{")
            for k in sorted(n["kids"]):
                out += show(n["kids"][k], path + [k], ind)
            out += [f"{ind}{m}" for m in n["lines"]]
            if path:
                out.append(f"{ind}}}")
        return out
    return "\n".join(show(tree, [], ""))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("target")
    ap.add_argument("module")
    ap.add_argument("unit")
    ap.add_argument("--symbols", action="store_true", help="skeleton from the symbol table")
    ap.add_argument("--probe", help="write an offset/size probe C++ file here and compile it")
    a = ap.parse_args()
    elf = ELFFile(io.BytesIO(modules.read(a.target, a.module)))
    cu = None
    if not a.symbols:
        src = None
        for line in (ROOT / "config" / a.target / f"units.{a.module}.txt").read_text().splitlines():
            p = line.split()
            if len(p) == 3 and p[0] == a.unit:
                src = p[2]
        lo, _ = unit_range(a.target, a.module, a.unit)
        text = elf.get_section_by_name(".text")["sh_addr"]
        for c in elf.get_dwarf_info().iter_CUs():
            t = c.get_top_DIE()
            if attr(t, "DW_AT_name") == src and attr(t, "DW_AT_language") == 4 and (
                    attr(t, "DW_AT_low_pc") is None or attr(t, "DW_AT_low_pc") + text == lo):
                cu = c
                break
    if cu is None:
        print(f"/* {a.unit}: no C++ DWARF; declarations from the symbol table */")
        print(symbol_mode(elf, a.target, a.module, a.unit))
        return
    syms = [s[0] for s in symbols(elf)]
    demangle(syms)
    u = Unit(cu, syms)
    fwd, types, glob, funcs = u.run()
    decls = "\n\n".join(x for x in (nest(fwd), nest(types), nest(glob), nest(funcs)) if x)
    print(decls)
    if a.probe:
        write_probe(a.probe, u.probe, decls)
        err = check_probe(a.probe)
        bad = [l for l in err.splitlines() if "error" in l]
        print(f"/* probe: {len(u.probe)} checks, {len(bad)} errors */", file=sys.stderr)
        if err:
            sys.stderr.write(err)


if __name__ == "__main__":
    main()
