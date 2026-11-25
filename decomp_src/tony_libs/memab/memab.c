/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "memab.h"
/* --- end declarations --- */

void func_00000000(u8 *dst, const u8 *a, u32 alen, const u8 *b, u32 blen, const u8 *c, u32 clen, const u8 *d, u32 dlen)
{
	u8 *p = dst;

	MEMCPY(p, a, alen);
	p += alen;
	MEMCPY(p, b, blen);
	p += blen;
	MEMCPY(p, c, clen);
	p += clen;
	MEMCPY(p, d, dlen);
	p += dlen;
	MEMSET(p, 0, 0xC0 - (alen + blen + clen + dlen));
}

int func_000000E4(u8 *buf, const u8 *a, u32 alen, const u8 *b, u32 blen, const u8 *c, u32 clen)
{
	u8 *p;

	*(u32 *)buf = alen + blen + clen;
	p = buf + 4;
	MEMCPY(p, a, alen);
	p += alen;
	MEMCPY(p, b, blen);
	p += blen;
	MEMCPY(p, c, clen);
	if (sceUtilsBufferCopyWithRange(buf, MAX(alen + blen + clen + 4, 0x14), buf, MAX(alen + blen + clen + 4, 0x14), 0xB) != 0)
		return -0x102;
	return 0;
}

int func_000001C4(u8 *buf, const u8 *a, const u8 *b, const u8 *c)
{
	u8 *p = buf;

	MEMCPY(p, a, 0x28);
	p += 0x28;
	MEMCPY(p, b, 0x14);
	p += 0x14;
	MEMCPY(p, c, 0x28);
	if (sceUtilsBufferCopyWithRange(0, 0, buf, 0x64, 0x11) != 0)
		return -0x10C;
	return 0;
}

int func_0000026C(u8 *buf)
{
	if (sceIdStorageLookup(0x100, 0xF0, buf, 0xB8) < 0
	    && sceIdStorageLookup(0x120, 0xF0, buf, 0xB8) < 0)
		return -0x10D;
	if (sceUtilsBufferCopyWithRange(0, 0, buf, 0xB8, 0x12) != 0)
		return -0x106;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", func_000002F8);

int func_00000558(KirkHeader *buf, int size, int keyseed)
{
	buf->keyseed = keyseed;
	buf->mode = 5;
	buf->unk4 = 0;
	buf->unk8 = 0;
	buf->size = size;
	if (sceUtilsBufferCopyWithRange(buf, size + 0x14, buf, size + 0x14, 7) != 0)
		return -0x10A;
	return 0;
}

int func_000005AC(KirkHeader *buf, int keyseed, const u8 *data, u32 size)
{
	MEMCPY((u8 *)buf + 0x14, data, size);
	return func_00000558(buf, size, keyseed);
}

int func_000005FC(u8 *buf, u32 size, u64 *ctr, u64 *key)
{
	u32 i;
	Q64 *q;
	Q64 *k1 = (Q64 *)&key[1];

	for (i = 0x14; i < size + 0x14; i += 16) {
		q = (Q64 *)(buf + i);
		*q = *(Q64 *)ctr;
		if (*ctr % 2 == 0) {
			q++;
			*q = *(Q64 *)&key[0];
		} else {
			q++;
			*q = *k1;
		}
		(*ctr)++;
	}
	return func_00000558((KirkHeader *)buf, size, 0x44);
}

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", func_000006BC);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", func_00000878);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", module_start);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", module_stop);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_01FD1BA0);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_0C134D3F);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_A4720EED);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_DC598EF3);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_8DAC2343);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_DAE8A629);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_CF49BCBB);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_E6D3ACE2);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_B54E1AA7);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_F1D2B9B0);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_4DF566D3);
