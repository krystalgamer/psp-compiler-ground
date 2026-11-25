/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/bpf_filter", func_000047EC);

int func_00004CC8(struct bpf_insn *f, int len)
{
	int i;
	struct bpf_insn *p;

	for (i = 0; i < len; ++i) {
		p = &f[i];
		if ((p->code & 0x07) == 0x05) {
			int from = i + 1;

			if ((p->code & 0xf0) == 0x00) {
				if ((p->k < 0) || (from + p->k >= len) || (from + p->k < 0))
					return 0;
			} else if (from + p->jt >= len || from + p->jf >= len)
				return 0;
		}
		if (((p->code & 0x07) == 0x02 || ((p->code & 0x07) == 0x00 && (p->code & 0xe0) == 0x60)) &&
		    (p->k >= 16 || p->k < 0))
			return 0;
		if (p->code == (0x04 | 0x30 | 0x00) && p->k == 0)
			return 0;
	}
	return (f[len - 1].code & 0x07) == 0x06;
}

int func_00004DD8(struct mbuf *m, int k, int *err)
{
	int len;
	u_char *cp, *np;
	struct mbuf *m0;

	MINDEX(len, m, k);
	cp = mtod(m, u_char *) + k;
	if (len - k >= 4) {
		*err = 0;
		return EXTRACT_LONG(cp);
	}
	m0 = m->m_next;
	if (m0 == 0 || m0->m_len + len - k < 4)
		goto bad;
	*err = 0;
	np = mtod(m0, u_char *);
	switch (len - k) {
	case 1:
		return (cp[0] << 24) | (np[0] << 16) | (np[1] << 8) | np[2];
	case 2:
		return (cp[0] << 24) | (cp[1] << 16) | (np[0] << 8) | np[1];
	default:
		return (cp[0] << 24) | (cp[1] << 16) | (cp[2] << 8) | np[0];
	}
bad:
	*err = 1;
	return 0;
}

int func_00004EEC(struct mbuf *m, int k, int *err)
{
	int len;
	u_char *cp;
	struct mbuf *m0;

	MINDEX(len, m, k);
	cp = mtod(m, u_char *) + k;
	if (len - k >= 2) {
		*err = 0;
		return EXTRACT_SHORT(cp);
	}
	m0 = m->m_next;
	if (m0 == 0)
		goto bad;
	*err = 0;
	return (cp[0] << 8) | mtod(m0, u_char *)[0];
bad:
	*err = 1;
	return 0;
}
