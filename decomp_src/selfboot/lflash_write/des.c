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

void func_000035B4(const unsigned char *in, void *ks, unsigned char *out)
{
	u64 v = 0;
	u64 r;
	int i;

	for (i = 0; i < 8; i++) {
		v <<= 8;
		v |= in[i];
	}
	func_00002424(v, &r, ks);
	for (i = 0; i < 8; i++) {
		out[7 - i] = r;
		r >>= 8;
	}
}

int func_00003668(const unsigned char *in, const unsigned char *key, unsigned char *out, unsigned int n)
{
	unsigned char ks[128];
	unsigned int i;

	func_0000349C(key, ks);
	for (i = 0; i < n; i++)
		func_00003500(in + i * 8, ks, out + i * 8);
	return 0;
}

int func_000036EC(const unsigned char *in, const unsigned char *key, unsigned char *out, unsigned int n)
{
	unsigned char ks[128];
	unsigned int i;

	func_0000349C(key, ks);
	for (i = 0; i < n; i++)
		func_000035B4(in + i * 8, ks, out + i * 8);
	return 0;
}

int func_00003770(const unsigned char *in, const unsigned char *key, unsigned char *out, const unsigned char *iv, unsigned int n)
{
	unsigned char tmp[8];
	unsigned char ks[128];
	unsigned int b;
	unsigned int i;

	func_0000349C(key, ks);
	for (i = 0; i < 8; i++)
		tmp[i] = in[i] ^ iv[i];
	func_00003500(tmp, ks, out);
	for (b = 1; b < n; b++) {
		for (i = 0; i < 8; i++)
			tmp[i] = in[b * 8 + i] ^ out[b * 8 + i - 8];
		func_00003500(tmp, ks, out + b * 8);
	}
	return 0;
}

int func_00003870(const unsigned char *in, const unsigned char *key, unsigned char *out, const unsigned char *iv, unsigned int n)
{
	unsigned char tmp[8];
	unsigned char ks[128];
	unsigned int b;
	unsigned int i;

	func_0000349C(key, ks);
	func_000035B4(in, ks, tmp);
	for (i = 0; i < 8; i++)
		out[i] = tmp[i] ^ iv[i];
	for (b = 1; b < n; b++) {
		func_000035B4(in + b * 8, ks, tmp);
		for (i = 0; i < 8; i++)
			out[b * 8 + i] = tmp[i] ^ in[b * 8 + i - 8];
	}
	return 0;
}

void func_0000397C(const unsigned char *in, void *k1, void *k2, void *k3, unsigned char *out)
{
	u64 v = 0;
	u64 r;
	int i;

	for (i = 0; i < 8; i++) {
		v <<= 8;
		v |= in[i];
	}
	func_00001728(v, &r, k1);
	func_00002424(r, &r, k2);
	func_00001728(r, &r, k3);
	for (i = 0; i < 8; i++) {
		out[7 - i] = r;
		r >>= 8;
	}
}

void func_00003A74(const unsigned char *in, void *k1, void *k2, void *k3, unsigned char *out)
{
	u64 v = 0;
	u64 r;
	int i;

	for (i = 0; i < 8; i++) {
		v <<= 8;
		v |= in[i];
	}
	func_00002424(v, &r, k3);
	func_00001728(r, &r, k2);
	func_00002424(r, &r, k1);
	for (i = 0; i < 8; i++) {
		out[7 - i] = r;
		r >>= 8;
	}
}

void func_00003B64(const unsigned char *a, void *k1, void *k2, unsigned char *b)
{
	func_0000397C(a, k1, k2, k1, b);
}

void func_00003B84(const unsigned char *a, void *k1, void *k2, unsigned char *b)
{
	func_00003A74(a, k1, k2, k1, b);
}

int func_00003BA4(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, const unsigned char *k3, unsigned char *out, unsigned int n)
{
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned char ks3[128];
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	func_0000349C(k3, ks3);
	for (i = 0; i < n; i++)
		func_0000397C(in + i * 8, ks1, ks2, ks3, out + i * 8);
	return 0;
}

int func_00003C74(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, const unsigned char *k3, unsigned char *out, unsigned int n)
{
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned char ks3[128];
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	func_0000349C(k3, ks3);
	for (i = 0; i < n; i++)
		func_00003A74(in + i * 8, ks1, ks2, ks3, out + i * 8);
	return 0;
}

int func_00003D44(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, unsigned char *out, unsigned int n)
{
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	for (i = 0; i < n; i++)
		func_00003B64(in + i * 8, ks1, ks2, out + i * 8);
	return 0;
}

int func_00003DEC(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, unsigned char *out, unsigned int n)
{
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	for (i = 0; i < n; i++)
		func_00003B84(in + i * 8, ks1, ks2, out + i * 8);
	return 0;
}

int func_00003E94(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, const unsigned char *k3, unsigned char *out, const unsigned char *iv, unsigned int n)
{
	unsigned char tmp[8];
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned char ks3[128];
	unsigned int b;
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	func_0000349C(k3, ks3);
	for (i = 0; i < 8; i++)
		tmp[i] = in[i] ^ iv[i];
	func_0000397C(tmp, ks1, ks2, ks3, out);
	for (b = 1; b < n; b++) {
		for (i = 0; i < 8; i++)
			tmp[i] = in[b * 8 + i] ^ out[b * 8 + i - 8];
		func_0000397C(tmp, ks1, ks2, ks3, out + b * 8);
	}
	return 0;
}

int func_00003FF0(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, const unsigned char *k3, unsigned char *out, const unsigned char *iv, unsigned int n)
{
	unsigned char tmp[8];
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned char ks3[128];
	unsigned int b;
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	func_0000349C(k3, ks3);
	func_00003A74(in, ks1, ks2, ks3, tmp);
	for (i = 0; i < 8; i++)
		out[i] = tmp[i] ^ iv[i];
	for (b = 1; b < n; b++) {
		func_00003A74(in + b * 8, ks1, ks2, ks3, tmp);
		for (i = 0; i < 8; i++)
			out[b * 8 + i] = tmp[i] ^ in[b * 8 + i - 8];
	}
	return 0;
}

int func_00004154(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, unsigned char *out, const unsigned char *iv, unsigned int n)
{
	unsigned char tmp[8];
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned int b;
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	for (i = 0; i < 8; i++)
		tmp[i] = in[i] ^ iv[i];
	func_00003B64(tmp, ks1, ks2, out);
	for (b = 1; b < n; b++) {
		for (i = 0; i < 8; i++)
			tmp[i] = in[b * 8 + i] ^ out[b * 8 + i - 8];
		func_00003B64(tmp, ks1, ks2, out + b * 8);
	}
	return 0;
}

int func_0000428C(const unsigned char *in, const unsigned char *k1, const unsigned char *k2, unsigned char *out, const unsigned char *iv, unsigned int n)
{
	unsigned char tmp[8];
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned int b;
	unsigned int i;

	if (n == 0)
		return 0;
	func_0000349C(k1, ks1);
	func_0000349C(k2, ks2);
	func_00003B84(in, ks1, ks2, tmp);
	for (i = 0; i < 8; i++)
		out[i] = tmp[i] ^ iv[i];
	for (b = 1; b < n; b++) {
		func_00003B84(in + b * 8, ks1, ks2, tmp);
		for (i = 0; i < 8; i++)
			out[b * 8 + i] = tmp[i] ^ in[b * 8 + i - 8];
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_000043C4);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00004538);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_000046FC);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_0000489C);

void func_000049C8(DesCbc *ctx, unsigned char *buf, unsigned int n)
{
	func_0000489C(ctx, buf, buf, n);
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_000049E8);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00004B88);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00004BA8);

void func_00004D00(void *a, void *k1, void *b)
{
	func_00004BA8(a, k1, k1, b);
}

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00004D20);

INCLUDE_ASM("tmp/asm/selfboot/lflash_write/nonmatchings/des", func_00004EF0);

void LflashFatfmt_B7A424A4(void) {
}
