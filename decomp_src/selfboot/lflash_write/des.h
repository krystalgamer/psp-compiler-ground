#ifndef DES_H
#define DES_H

#include "common.h"


void func_00001728(u64 v, u64 *out, void *ks);
void func_00002424(u64 v, u64 *out, void *ks);
void func_0000314C(u64 key, void *ks);
void func_0000349C(const unsigned char *key, void *ks);
void func_000035B4(const unsigned char *in, void *ks, unsigned char *out);
void func_0000397C(const unsigned char *in, void *k1, void *k2, void *k3, unsigned char *out);
void func_00003A74(void *a, void *k1, void *k2, void *k3, void *b);
void func_0000489C(void *a, void *k1, void *k2, void *b);
void func_00004BA8(void *a, void *k1, void *k2, void *b);

#endif
