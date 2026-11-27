/* Sony's psp-newlib libc/sys/psp/memmove.c (not in newlib 1.12.0), the older revision of the
   1.5.1.internal toolchain: the unaligned head is a byte-copy switch where the 1.6.1 one
   (sampler, UTST99332) uses lwl/swl and lwr/swr; ulw/usw expand to byte loads/stores (psp-as
   without -mulsw). */
/* cflags: -O2 -fno-builtin */
/* The original object was built with -falign-loops=64: with that flag (and
   without the NOPS() below) the same C compiles identically, the object
   being 64-byte aligned.  The cflags line cannot carry "=64" and the module
   splits keep that alignment padding as asm around this unit, so the nops
   gcc's four loop alignments produce are written out here instead. */
#define NOPS(n) __asm__ (".rept " #n "\n\tnop\n\t.endr")
#include "common.h"
#include <stddef.h>

static __inline__ __attribute__((always_inline)) void *do_rcopy(void *dst0, const void *src0, size_t len0)
{
	char *dst = dst0;
	const char *src = src0;
	long *wdst;
	const long *wsrc;
	int len = len0;
	size_t lc;

	if (len0 < 8)
		goto copy_with_byte;
	if ((((long)src ^ (long)dst) & 3) == 0) {
		int ofs = (long)src & 3;

		if (ofs) {
			switch (ofs) {
			case 3:
				*--dst = *--src;
			case 2:
				*--dst = *--src;
			case 1:
				*--dst = *--src;
			}
			len -= ofs;
		}
		lc = (size_t)len >> 4;
		wdst = (long *)dst;
		wsrc = (const long *)src;
		len &= 15;
		if (lc) {
			do {
				long tmp0, tmp1, tmp2, tmp3;

				wsrc -= 4;
				wdst -= 4;
				tmp0 = wsrc[0];
				tmp1 = wsrc[1];
				tmp2 = wsrc[2];
				tmp3 = wsrc[3];
				wdst[0] = tmp0;
				wdst[1] = tmp1;
				wdst[2] = tmp2;
				wdst[3] = tmp3;
			} while (--lc);
		}
		lc = (size_t)len >> 2;
		len &= 3;
		if (lc) {
			do {
				*--wdst = *--wsrc;
			} while (--lc);
		}
		dst = (char *)wdst;
		src = (const char *)wsrc;
	} else {
		long tmp;

		wdst = (long *)dst;
		lc = len / 4;
		len -= lc * 4;
		wsrc = (const long *)src;
		while (lc) {
			lc--;
			wsrc--;
			__asm__ ("ulw %0, %1" : "=r"(tmp) : "m"(*wsrc));
			wdst--;
			__asm__ ("usw %1, %0" : "=m"(*wdst) : "r"(tmp));
		}
		dst = (char *)wdst;
		src = (const char *)wsrc;
	}
copy_with_byte:
	if (len > 0) {
		NOPS(6);
		do {
			*--dst = *--src;
			len--;
		} while (len > 0);
	}
	return dst0;
}

static __inline__ __attribute__((always_inline)) void *do_copy(void *dst0, const void *src0, size_t len0)
{
	char *dst = dst0;
	const char *src = src0;
	long *wdst;
	const long *wsrc;
	int len = len0;
	size_t lc;

	if (len0 < 8)
		goto copy_with_byte;
	if ((((long)src ^ (long)dst) & 3) == 0) {
		int ofs = (long)src & 3;

		if (ofs) {
			int res = 4 - ofs;

			switch (res) {
			case 3:
				*dst++ = *src++;
			case 2:
				*dst++ = *src++;
			case 1:
				*dst++ = *src++;
			}
			len -= res;
		}
		lc = (size_t)len >> 4;
		wdst = (long *)dst;
		wsrc = (const long *)src;
		len &= 15;
		if (lc) {
			NOPS(12);
			do {
				long tmp0, tmp1, tmp2, tmp3;

				tmp0 = wsrc[0];
				tmp1 = wsrc[1];
				tmp2 = wsrc[2];
				tmp3 = wsrc[3];
				wdst[0] = tmp0;
				wdst[1] = tmp1;
				wdst[2] = tmp2;
				wdst[3] = tmp3;
				wsrc += 4;
				wdst += 4;
			} while (--lc);
		}
		lc = (size_t)len >> 2;
		len &= 3;
		if (lc) {
			NOPS(1);
			do {
				*wdst++ = *wsrc++;
			} while (--lc);
		}
		dst = (char *)wdst;
		src = (const char *)wsrc;
	} else {
		long tmp;

		wsrc = (const long *)src;
		lc = len / 4;
		len -= lc * 4;
		wdst = (long *)dst;
		while (lc) {
			__asm__ ("ulw %0, %1" : "=r"(tmp) : "m"(*wsrc));
			lc--;
			wsrc++;
			__asm__ ("usw %1, %0" : "=m"(*wdst) : "r"(tmp));
			wdst++;
		}
		dst = (char *)wdst;
		src = (const char *)wsrc;
	}
copy_with_byte:
	if (len > 0) {
		NOPS(6);
		do {
			*dst++ = *src++;
			len--;
		} while (len > 0);
	}
	return dst0;
}

void *memmove(void *dst, const void *src, size_t len)
{
	if (src < dst && dst < (void *)((const char *)src + len))
		return do_rcopy((char *)dst + len, (const char *)src + len, len);
	return do_copy(dst, src, len);
}
