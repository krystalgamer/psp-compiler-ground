/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

u_int func_000047EC(struct bpf_insn *pc, u_char *p, u_int wirelen, u_int buflen)
{
	u_int A, X;
	int k;
	int mem[16];

	if (pc == 0)
		return (u_int)-1;
	A = 0;
	X = 0;
	--pc;
	while (1) {
		++pc;
		switch (pc->code) {
		default:
			return 0;
		case 0x06:
			return (u_int)pc->k;
		case 0x16:
			return (u_int)A;
		case 0x20:
			k = pc->k;
			if (k + sizeof(int) > buflen) {
				int merr;

				if (buflen != 0)
					return 0;
				A = func_00004DD8((struct mbuf *)p, k, &merr);
				if (merr != 0)
					return 0;
				continue;
			}
			A = EXTRACT_LONG(&p[k]);
			continue;
		case 0x28:
			k = pc->k;
			if (k + sizeof(short) > buflen) {
				int merr;

				if (buflen != 0)
					return 0;
				A = func_00004EEC((struct mbuf *)p, k, &merr);
				continue;
			}
			A = EXTRACT_SHORT(&p[k]);
			continue;
		case 0x30:
			k = pc->k;
			if (k >= buflen) {
				struct mbuf *m;
				int len;

				if (buflen != 0)
					return 0;
				m = (struct mbuf *)p;
				MINDEX(len, m, k);
				A = mtod(m, u_char *)[k];
				continue;
			}
			A = p[k];
			continue;
		case 0x80:
			A = wirelen;
			continue;
		case 0x81:
			X = wirelen;
			continue;
		case 0x40:
			k = X + pc->k;
			if (k + sizeof(int) > buflen) {
				int merr;

				if (buflen != 0)
					return 0;
				A = func_00004DD8((struct mbuf *)p, k, &merr);
				if (merr != 0)
					return 0;
				continue;
			}
			A = EXTRACT_LONG(&p[k]);
			continue;
		case 0x48:
			k = X + pc->k;
			if (k + sizeof(short) > buflen) {
				int merr;

				if (buflen != 0)
					return 0;
				A = func_00004EEC((struct mbuf *)p, k, &merr);
				if (merr != 0)
					return 0;
				continue;
			}
			A = EXTRACT_SHORT(&p[k]);
			continue;
		case 0x50:
			k = X + pc->k;
			if (k >= buflen) {
				struct mbuf *m;
				int len;

				if (buflen != 0)
					return 0;
				m = (struct mbuf *)p;
				MINDEX(len, m, k);
				A = mtod(m, u_char *)[k];
				continue;
			}
			A = p[k];
			continue;
		case 0xB1:
			k = pc->k;
			if (k >= buflen) {
				struct mbuf *m;
				int len;

				if (buflen != 0)
					return 0;
				m = (struct mbuf *)p;
				MINDEX(len, m, k);
				X = (mtod(m, char *)[k] & 0xf) << 2;
				continue;
			}
			X = (p[pc->k] & 0xf) << 2;
			continue;
		case 0x00:
			A = pc->k;
			continue;
		case 0x01:
			X = pc->k;
			continue;
		case 0x60:
			A = mem[pc->k];
			continue;
		case 0x61:
			X = mem[pc->k];
			continue;
		case 0x02:
			mem[pc->k] = A;
			continue;
		case 0x03:
			mem[pc->k] = X;
			continue;
		case 0x05:
			pc += pc->k;
			continue;
		case 0x25:
			pc += (A > pc->k) ? pc->jt : pc->jf;
			continue;
		case 0x35:
			pc += (A >= pc->k) ? pc->jt : pc->jf;
			continue;
		case 0x15:
			pc += (A == pc->k) ? pc->jt : pc->jf;
			continue;
		case 0x45:
			pc += (A & pc->k) ? pc->jt : pc->jf;
			continue;
		case 0x2D:
			pc += (A > X) ? pc->jt : pc->jf;
			continue;
		case 0x3D:
			pc += (A >= X) ? pc->jt : pc->jf;
			continue;
		case 0x1D:
			pc += (A == X) ? pc->jt : pc->jf;
			continue;
		case 0x4D:
			pc += (A & X) ? pc->jt : pc->jf;
			continue;
		case 0x0C:
			A += X;
			continue;
		case 0x1C:
			A -= X;
			continue;
		case 0x2C:
			A *= X;
			continue;
		case 0x3C:
			if (X == 0)
				return 0;
			A /= X;
			continue;
		case 0x5C:
			A &= X;
			continue;
		case 0x4C:
			A |= X;
			continue;
		case 0x6C:
			A <<= X;
			continue;
		case 0x7C:
			A >>= X;
			continue;
		case 0x04:
			A += pc->k;
			continue;
		case 0x14:
			A -= pc->k;
			continue;
		case 0x24:
			A *= pc->k;
			continue;
		case 0x34:
			A /= pc->k;
			continue;
		case 0x54:
			A &= pc->k;
			continue;
		case 0x44:
			A |= pc->k;
			continue;
		case 0x64:
			A <<= pc->k;
			continue;
		case 0x74:
			A >>= pc->k;
			continue;
		case 0x84:
			A = -A;
			continue;
		case 0x07:
			X = A;
			continue;
		case 0x87:
			A = X;
			continue;
		}
	}
}

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
