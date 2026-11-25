/* cflags: -O3 -fno-merge-constants */
#include "common.h"
#include "inetlib.h"

#define ADDCARRY(x)  (x > 65535 ? x -= 65535 : x)
#define REDUCE {l_util.l = sum; sum = l_util.s[0] + l_util.s[1]; ADDCARRY(sum);}

int
in_cksum(struct mbuf *m, int len)
{
	u_int16_t *w;
	int sum = 0;
	int mlen = 0;
	int byte_swapped = 0;
	union {
		u_int8_t  c[2];
		u_int16_t s;
	} s_util;
	union {
		u_int16_t s[2];
		u_int32_t l;
	} l_util;

	for (;m && len; m = m->m_next) {
		if (m->m_len == 0)
			continue;
		w = mtod(m, u_int16_t *);
		if (mlen == -1) {
			s_util.c[1] = *(u_int8_t *)w;
			sum += s_util.s;
			w = (u_int16_t *)((u_int8_t *)w + 1);
			mlen = m->m_len - 1;
			len--;
		} else
			mlen = m->m_len;
		if (len < mlen)
			mlen = len;
		len -= mlen;
		if ((1 & (long) w) && (mlen > 0)) {
			REDUCE;
			sum <<= 8;
			s_util.c[0] = *(u_int8_t *)w;
			w = (u_int16_t *)((int8_t *)w + 1);
			mlen--;
			byte_swapped = 1;
		}
		while ((mlen -= 32) >= 0) {
			sum += w[0]; sum += w[1]; sum += w[2]; sum += w[3];
			sum += w[4]; sum += w[5]; sum += w[6]; sum += w[7];
			sum += w[8]; sum += w[9]; sum += w[10]; sum += w[11];
			sum += w[12]; sum += w[13]; sum += w[14]; sum += w[15];
			w += 16;
		}
		mlen += 32;
		while ((mlen -= 8) >= 0) {
			sum += w[0]; sum += w[1]; sum += w[2]; sum += w[3];
			w += 4;
		}
		mlen += 8;
		if (mlen == 0 && byte_swapped == 0)
			continue;
		REDUCE;
		while ((mlen -= 2) >= 0) {
			sum += *w++;
		}
		if (byte_swapped) {
			REDUCE;
			sum <<= 8;
			byte_swapped = 0;
			if (mlen == -1) {
				s_util.c[1] = *(u_int8_t *)w;
				sum += s_util.s;
				mlen = 0;
			} else
				mlen = -1;
		} else if (mlen == -1)
			s_util.c[0] = *(u_int8_t *)w;
	}
	if (mlen == -1) {
		s_util.c[1] = 0;
		sum += s_util.s;
	}
	REDUCE;
	return (~sum & 0xffff);
}
