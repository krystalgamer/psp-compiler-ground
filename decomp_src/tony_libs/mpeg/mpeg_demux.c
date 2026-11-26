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
int __tolower_i(int c) __asm__("func_0000720C");
extern const char D_00007994[];

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_demux", func_000014F4);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_demux", func_000018A8);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_demux", func_00001F38);

void func_00003984(BitReader *br, int n)
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

INCLUDE_RODATA("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_demux", D_000079BC);
