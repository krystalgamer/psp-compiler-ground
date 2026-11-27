/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "des.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00001728);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00002424);

unsigned int func_00003120(unsigned int x, int n)
{
	unsigned int r;

	if (n == 1)
		r = (x >> 27) | (x << 1);
	else
		r = (x >> 26) | (x << 2);
	return r;
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_0000314C);

void func_0000349C(const unsigned char *key, void *ks)
{
	u64 k = 0;
	int i;

	for (i = 0; i < 8; i++) {
		k <<= 8;
		k |= key[i];
	}
	func_0000314C(k, ks);
}

void func_00003500(const unsigned char *in, void *ks, unsigned char *out)
{
	u64 v = 0;
	u64 r;
	int i;

	for (i = 0; i < 8; i++) {
		v <<= 8;
		v |= in[i];
	}
	func_00001728(v, &r, ks);
	for (i = 0; i < 8; i++) {
		out[7 - i] = r;
		r >>= 8;
	}
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_000035B4);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00003668);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00003870);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_0000397C);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00003A74);

void func_00003B64(void *a, void *k1, void *k2, void *b)
{
	func_0000397C(a, k1, k2, k1, b);
}

void func_00003B84(void *a, void *k1, void *k2, void *b)
{
	func_00003A74(a, k1, k2, k1, b);
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00003BA4);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_0000489C);

void func_000049C8(void *a, void *k1, void *b)
{
	func_0000489C(a, k1, k1, b);
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_000049E8);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00004BA8);

void func_00004D00(void *a, void *k1, void *b)
{
	func_00004BA8(a, k1, k1, b);
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00004D20);

void LflashFatfmt_B7A424A4(void) {
}
