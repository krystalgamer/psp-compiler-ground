/* cflags: -O2 -frename-registers -fno-strict-aliasing -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", func_000016E4);

int func_00001D94(Guid *a, Guid *b)
{
	int ret = 0;

	if (a->d1 == b->d1 && a->d2 == b->d2 && func_00001F04(a->d4, b->d4, 8) == 0)
		ret = 1;
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", func_00001DFC);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", func_00001E8C);

int func_00001F04(const unsigned char *a, const unsigned char *b, unsigned int size)
{
	long long n = size;

	for (; n > 0; n--) {
		if (*a != *b)
			return *a < *b ? -1 : 1;
		a++;
		b++;
	}
	return 0;
}

INCLUDE_RODATA("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", D_00003834);

INCLUDE_RODATA("tmp/asm/tony_libs/libatrac3plus/nonmatchings/header", D_00003844);
