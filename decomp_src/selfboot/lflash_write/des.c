/* cflags: -O2 -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "des.h"
/* --- end declarations --- */

#define PERM_OP(a,b,t,n,m) ((t)=((((a)>>(n))^(b))&(m)),(b)^=(t),(a)^=((t)<<(n)))
#define HPERM_OP(a,t,n,m) ((t)=((((a)<<(16-(n)))^(a))&(m)),(a)=(a)^(t)^(t>>(16-(n))))
#define D_ENCRYPT(L, R, S) \
    u = ks[(S) + 1] ^ (((R) << 29) | ((R) >> 3)); \
    t = (((R) << 1) | ((R) >> 31)) ^ ks[(S)]; \
    (L) ^= D_00005758[0][(u >> 24) & 0x3f] | D_00005758[1][(t >> 24) & 0x3f] | \
           D_00005758[2][(u >> 16) & 0x3f] | D_00005758[3][(t >> 16) & 0x3f] | \
           D_00005758[4][(u >> 8) & 0x3f] | D_00005758[5][(t >> 8) & 0x3f] | \
           D_00005758[6][u & 0x3f] | D_00005758[7][t & 0x3f]
#define IP(l, r, w) \
    PERM_OP(r, l, w, 4, 0x0f0f0f0fL); \
    PERM_OP(r, l, w, 16, 0x0000ffffL); \
    PERM_OP(l, r, w, 2, 0x33333333L); \
    PERM_OP(l, r, w, 8, 0x00ff00ffL); \
    PERM_OP(r, l, w, 1, 0x55555555L)
#define FP(l, r, w) \
    PERM_OP(l, r, w, 1, 0x55555555L); \
    PERM_OP(r, l, w, 8, 0x00ff00ffL); \
    PERM_OP(r, l, w, 2, 0x33333333L); \
    PERM_OP(l, r, w, 16, 0x0000ffffL); \
    PERM_OP(l, r, w, 4, 0x0f0f0f0fL)

extern unsigned char D_00005748[16];
extern unsigned long D_00005758[8][64];
extern unsigned long D_00005F58[8][64];

void func_00001728(u64 v, u64 *out, void *ksv)
{
	unsigned long *ks = ksv;
	unsigned long l, r, t, u;

	r = (unsigned long)(v >> 32);
	l = (unsigned long)v;
	IP(l, r, u);
	D_ENCRYPT(r, l, 0);
	D_ENCRYPT(l, r, 2);
	D_ENCRYPT(r, l, 4);
	D_ENCRYPT(l, r, 6);
	D_ENCRYPT(r, l, 8);
	D_ENCRYPT(l, r, 10);
	D_ENCRYPT(r, l, 12);
	D_ENCRYPT(l, r, 14);
	D_ENCRYPT(r, l, 16);
	D_ENCRYPT(l, r, 18);
	D_ENCRYPT(r, l, 20);
	D_ENCRYPT(l, r, 22);
	D_ENCRYPT(r, l, 24);
	D_ENCRYPT(l, r, 26);
	D_ENCRYPT(r, l, 28);
	D_ENCRYPT(l, r, 30);
	FP(l, r, u);
	*out = r | ((unsigned long long)l << 32);
}

void func_00002424(u64 v, u64 *out, void *ksv)
{
	unsigned long *ks = ksv;
	unsigned long l, r, t, u;

	r = (unsigned long)(v >> 32);
	l = (unsigned long)v;
	IP(l, r, u);
	D_ENCRYPT(r, l, 30);
	D_ENCRYPT(l, r, 28);
	D_ENCRYPT(r, l, 26);
	D_ENCRYPT(l, r, 24);
	D_ENCRYPT(r, l, 22);
	D_ENCRYPT(l, r, 20);
	D_ENCRYPT(r, l, 18);
	D_ENCRYPT(l, r, 16);
	D_ENCRYPT(r, l, 14);
	D_ENCRYPT(l, r, 12);
	D_ENCRYPT(r, l, 10);
	D_ENCRYPT(l, r, 8);
	D_ENCRYPT(r, l, 6);
	D_ENCRYPT(l, r, 4);
	D_ENCRYPT(r, l, 2);
	D_ENCRYPT(l, r, 0);
	FP(l, r, u);
	*out = r | ((unsigned long long)l << 32);
}

unsigned int func_00003120(unsigned int x, int n)
{
	unsigned int r;

	if (n == 1)
		r = (x >> 27) | (x << 1);
	else
		r = (x >> 26) | (x << 2);
	return r;
}

void func_0000314C(u64 key, void *outv)
{
	unsigned long long *out = outv;
	unsigned long c, d, s, t;
	int i;

	c = (unsigned long)(key >> 32);
	d = (unsigned long)key;
	PERM_OP(d, c, s, 4, 0x0f0f0f0fL);
	HPERM_OP(c, s, -2, 0xcccc0000L);
	HPERM_OP(d, s, -2, 0xcccc0000L);
	PERM_OP(d, c, s, 1, 0x55555555L);
	PERM_OP(c, d, s, 8, 0x00ff00ffL);
	PERM_OP(d, c, s, 1, 0x55555555L);
	HPERM_OP(c, s, 12, 0xf0f0f0f0L);
	HPERM_OP(d, s, 12, 0xf0f0f0f0L);
	d = ((d & 0x00ffffffL) << 4) | ((c >> 24) & 0x0fL);
	c = ((c & 0x000000ffL) << 20) | ((c & 0x0000ff00L) << 4) | ((c & 0x00ff0000L) >> 12)
	    | ((c & 0xf0000000L) >> 28);
	for (i = 0; i < 16; i++) {
		c = func_00003120(c, D_00005748[i]);
		d = func_00003120(d, D_00005748[i]);
		s = D_00005F58[0][(c >> 22) & 0x3f] | D_00005F58[1][((c >> 16) & 0x30) | ((c >> 15) & 0x0f)]
		    | D_00005F58[2][((c >> 9) & 0x3c) | ((c >> 8) & 0x03)]
		    | D_00005F58[3][((c >> 2) & 0x20) | ((c >> 1) & 0x18) | (c & 0x07)];
		t = D_00005F58[4][(d >> 22) & 0x3f] | D_00005F58[5][((d >> 15) & 0x30) | ((d >> 14) & 0x0f)]
		    | D_00005F58[6][(d >> 7) & 0x3f] | D_00005F58[7][((d >> 1) & 0x3c) | (d & 0x03)];
		out[i] = (((unsigned long long)s << 32) & 0xffff000000000000ULL)
		    | (((unsigned long long)t << 16) & 0x0000ffff00000000ULL)
		    | (((unsigned long long)s << 16) & 0x00000000ffff0000ULL) | (t & 0x0000ffffL);
	}
}

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
