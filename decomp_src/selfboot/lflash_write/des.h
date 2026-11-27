#ifndef DES_H
#define DES_H

#include "common.h"

typedef struct DesCbc {
	unsigned char unk0[0x10];
	unsigned char ks[128];
	unsigned char iv[8];
} DesCbc;

typedef struct Des3Cbc {
	unsigned char unk0[0x20];
	unsigned char ks1[128];
	unsigned char ks2[128];
	unsigned char ks3[128];
	unsigned char iv[8];
} Des3Cbc;


void func_00001728(u64 v, u64 *out, void *ks);
void func_00002424(u64 v, u64 *out, void *ks);
void func_0000314C(u64 key, void *ks);
void func_0000349C(const unsigned char *key, void *ks);
void func_000035B4(const unsigned char *in, void *ks, unsigned char *out);
void func_00003500(const unsigned char *in, void *ks, unsigned char *out);
void func_0000397C(const unsigned char *in, void *k1, void *k2, void *k3, unsigned char *out);
void func_00003A74(const unsigned char *in, void *k1, void *k2, void *k3, unsigned char *out);
void func_00003B64(const unsigned char *in, void *k1, void *k2, unsigned char *out);
void func_00003B84(const unsigned char *in, void *k1, void *k2, unsigned char *out);
int func_0000489C(DesCbc *ctx, const unsigned char *in, unsigned char *out, unsigned int n);
int func_00004BA8(Des3Cbc *ctx, const unsigned char *src, unsigned char *dst, unsigned int count);
int func_000049E8(DesCbc *ctx, const unsigned char *src, unsigned char *dst, unsigned int count);
int func_00004D20(Des3Cbc *ctx, const unsigned char *src, unsigned char *dst, unsigned int count);

#endif
