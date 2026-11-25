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

int module_start(void)
{
	D_000028E0 = sceKernelCreateSema("SceMemab", 0, 1, 1, 0);
	return D_000028E0 < 1;
}

int module_stop(void)
{
	sceKernelDeleteSema(D_000028E0);
	return 0;
}

int sceMemab_driver_01FD1BA0(void)
{
	int ret = -0x109;

	if (sceKernelWaitSema(D_000028E0, 1, 0) != 0)
		goto end;
	ret = 0;
	if (D_00002880 != 0)
		goto end;
	D_00002888 = 0;
	ret = -0x100;
	if (sceUtilsBufferCopyWithRange(D_000028C0, 0x14, 0, 0, 0xE) != 0)
		goto end;
	D_00002880 = 1;
	ret = 0;
end:
	if (sceKernelSignalSema(D_000028E0, 1) != 0)
		ret = -0x109;
	return ret;
}

int sceMemab_driver_0C134D3F(void)
{
	int ret = -0x109;

	if (sceKernelWaitSema(D_000028E0, 1, 0) != 0)
		goto end;
	ret = 0;
	if (D_00002880 == 0)
		goto end;
	MEMSET(D_000028C0, 0, 0x20);
	D_00002880 = 0;
	ret = 0;
	D_00002888 = 0;
end:
	if (sceKernelSignalSema(D_000028E0, 1) != 0)
		ret = -0x109;
	return ret;
}

int sceMemab_driver_A4720EED(u8 *arg0, u8 *out)
{
	int ret = -0x109;

	if (sceKernelWaitSema(D_000028E0, 1, 0) != 0)
		goto end;
	ret = -0x200;
	if (D_00002880 == 0)
		goto end;
	ret = func_0000026C(D_00002940);
	if (ret != 0)
		goto end;
	ret = -0x100;
	if (sceUtilsBufferCopyWithRange(D_00002900, 0x3C, 0, 0, 0xC) != 0)
		goto end;
	func_00000000(arg0, D_00002900, 0x3C, D_00002940, 0x10, 0, 0, 0, 0);
	ret = func_000002F8((KirkHeader *)D_00002B80, 2, D_00002900 + 0x14, 0x28, D_00002940, 0x60, 0, 0, 0, 0, 0, 0, 0, 0);
	if (ret != 0)
		goto end;
	MEMCPY(out, D_00002874 + 0x14, 0xA0);
	ret = 0;
end:
	if (sceKernelSignalSema(D_000028E0, 1) != 0)
		ret = -0x109;
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_DC598EF3);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_8DAC2343);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_DAE8A629);

INCLUDE_ASM("tmp/asm/tony_libs/memab/nonmatchings/memab", sceMemab_driver_CF49BCBB);

int sceMemab_driver_E6D3ACE2(u8 *obj, u32 *data, u32 size, u8 *hdr, int encrypt)
{
	int ret = -0x109;
	u64 ctr;

	if (sceKernelWaitSema(D_000028E0, 1, 0) != 0)
		goto end;
	ret = -0x200;
	if (D_00002880 == 0)
		goto end;
	ret = -0x400;
	if (size & 0xF)
		goto end;
	ret = -0x401;
	if (size > 0x910)
		goto end;
	ctr = BYTES_TO_U64(obj + 0x3C);
	ret = func_000006BC(D_00002874, data, size, &ctr, obj, hdr, encrypt);
	if (ret != 0)
		goto end;
	U64_TO_BYTES(obj + 0x3C, ctr);
end:
	if (sceKernelSignalSema(D_000028E0, 1) != 0)
		ret = -0x109;
	return ret;
}

int sceMemab_driver_B54E1AA7(u8 *obj, u32 *data, u32 size, u8 *hdr, int decrypt, int check)
{
	int ret = -0x109;
	u64 ctr, min;

	if (sceKernelWaitSema(D_000028E0, 1, 0) != 0)
		goto end;
	ret = -0x200;
	if (D_00002880 == 0)
		goto end;
	ret = -0x400;
	if (size & 0xF)
		goto end;
	ret = -0x401;
	if (size > 0x910)
		goto end;
	min = BYTES_TO_U64(obj + 0x44);
	ctr = BYTES_TO_U64(hdr);
	ret = func_00000878(D_00002874, data, size, &ctr, &min, obj, hdr, decrypt, check);
	if (ret != 0)
		goto end;
	if (check)
		U64_TO_BYTES(obj + 0x44, ctr);
end:
	if (sceKernelSignalSema(D_000028E0, 1) != 0)
		ret = -0x109;
	return ret;
}

int sceMemab_driver_F1D2B9B0(u32 *data, u32 size, u8 *hdr, int encrypt)
{
	int ret = -0x109;
	u64 ctr;

	if (sceKernelWaitSema(D_000028E0, 1, 0) != 0)
		goto end;
	ret = -0x200;
	if (D_00002880 == 0)
		goto end;
	ret = -0x400;
	if (size & 0xF)
		goto end;
	ret = -0x401;
	if (size > 0x910)
		goto end;
	ctr = D_00002888;
	ret = func_000006BC(D_00002874, data, size, &ctr, D_000028C0, hdr, encrypt);
	if (ret != 0)
		goto end;
	D_00002888 = ctr;
end:
	if (sceKernelSignalSema(D_000028E0, 1) != 0)
		ret = -0x109;
	return ret;
}

int sceMemab_driver_4DF566D3(u8 *obj, u32 *data, u32 size, u8 *hdr, int decrypt, int check)
{
	int ret = -0x109;
	u64 ctr, min;

	if (sceKernelWaitSema(D_000028E0, 1, 0) != 0)
		goto end;
	ret = -0x200;
	if (D_00002880 == 0)
		goto end;
	ret = -0x400;
	if (size & 0xF)
		goto end;
	ret = -0x401;
	if (size > 0x910)
		goto end;
	min = BYTES_TO_U64(obj + 0x34);
	ctr = BYTES_TO_U64(hdr);
	ret = func_00000878(D_00002874, data, size, &ctr, &min, obj + 0x14, hdr, decrypt, check);
	if (ret != 0)
		goto end;
	if (check)
		U64_TO_BYTES(obj + 0x34, ctr);
end:
	if (sceKernelSignalSema(D_000028E0, 1) != 0)
		ret = -0x109;
	return ret;
}
