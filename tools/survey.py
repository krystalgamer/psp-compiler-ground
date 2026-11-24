#!/usr/bin/env python3
"""survey.py ELF...: list each DWARF compile unit (compiler version, .text range,
function count, source name) and the .comment compiler sequence of PSP modules."""
import sys, collections
from elftools.elf.elffile import ELFFile

def cus(path):
    f = ELFFile(open(path, 'rb'))
    out = []
    if not f.has_dwarf_info():
        return f, out
    for cu in f.get_dwarf_info().iter_CUs():
        a = cu.get_top_DIE().attributes
        def g(k):
            if k not in a: return None
            v = a[k].value
            return v.decode(errors='replace') if isinstance(v, bytes) else v
        prod = g('DW_AT_producer') or ''
        ver = prod.split('psp-')[-1].split()[0] if 'psp-' in prod else prod
        nf = sum(1 for c in cu.get_top_DIE().iter_children()
                 if c.tag == 'DW_TAG_subprogram' and 'DW_AT_low_pc' in c.attributes)
        out.append(dict(ver=ver, lo=g('DW_AT_low_pc') or 0, hi=g('DW_AT_high_pc') or 0,
                        nfunc=nf, name=g('DW_AT_name'), dir=g('DW_AT_comp_dir') or ''))
    return f, out

def comments(f):
    s = f.get_section_by_name('.comment')
    if not s: return []
    return [x.decode() for x in s.data().split(b'\0') if x]

def kind(cu):
    d = cu['dir'] + '/' + (cu['name'] or '')
    if 'newlib' in d: return 'newlib'
    if 'crt0' in d: return 'crt0'
    return 'app'

if __name__ == '__main__':
    verbose = '-v' in sys.argv
    for p in [a for a in sys.argv[1:] if a != '-v']:
        f, cl = cus(p)
        byk = collections.Counter((kind(c), c['ver']) for c in cl)
        code = collections.Counter()
        for c in cl: code[(kind(c), c['ver'])] += max(0, c['hi'] - c['lo'])
        cm = collections.Counter(x.split('psp-')[-1] for x in comments(f))
        print('== %s: %d CUs; .comment %s' % (p, len(cl), dict(cm)))
        for k in sorted(byk): print('   %-7s %-16s %4d CUs %7d bytes' % (k[0], k[1], byk[k], code[k]))
        if verbose:
            for c in cl: print('     %-16s %6x-%6x %3d %s' % (c['ver'], c['lo'], c['hi'], c['nfunc'], c['name']))
