/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

static __inline__ int __strtok_find(const char *d, char c)
{
	int sc;

	while ((sc = *d++) != '\0') {
		if (sc == c)
			return sc;
	}
	return 0;
}
int __tolower_i(int c) __asm__("func_00007210");
extern const char D_000079A4[];

extern const StreamTypeInfo D_00007904[];
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_demux", func_000014F8);

int func_000018AC(BitReader *br, PackHeader *ph)
{
	unsigned int a, b, c, n, e;
	unsigned int i;

	BitFill(br, 34);
	a = br->bits >> 29;
	BitFill(br, 3);
	BitFill(br, 1);
	b = br->bits >> 17;
	BitFill(br, 15);
	BitFill(br, 1);
	c = br->bits >> 17;
	BitFill(br, 15);
	BitFill(br, 1);
	e = br->bits >> 23;
	BitFill(br, 9);
	ph->unk[0] = e;
	BitFill(br, 30);
	n = br->bits >> 29;
	BitFill(br, 3);
	ph->unk[1] = (a << 30) | (b << 15) | c;
	ph->unk[2] = a >> 2;
	for (i = 0; i < n; i++)
		BitFill(br, 8);
	if (br->bits == 0x1BB) {
		ph->unk[3] = 1;
		BitFill(br, 56);
		func_00003988(br, 40);
		while ((br->bits >> 31) == 1)
			func_00003988(br, 24);
	} else
		ph->unk[3] = 0;
	return 1;
}

INCLUDE_ASM("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_demux", func_00001F3C);

void func_00003988(BitReader *br, int n)
{
	br->bits <<= n;
	br->avail -= n;
	while (br->avail < 25) {
		br->bits |= *br->p << (24 - br->avail);
		br->p++;
		if (br->p >= br->end)
			br->p = br->start;
		br->avail += 8;
	}
	br->pos += n;
}

INCLUDE_RODATA("tmp/asm/rb/pal_mpeg/nonmatchings/mpeg_demux", D_000079CC);
