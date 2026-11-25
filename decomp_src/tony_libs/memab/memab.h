#ifndef MEMAB_H
#define MEMAB_H

#include "common.h"

typedef struct {
	u32 lo;
	u32 hi;
} Q64;


typedef struct {
	int mode;
	int unk4;
	int unk8;
	int keyseed;
	int size;
	u8 data[0];
} KirkHeader;

extern int D_00002880;
extern u64 D_00002888;
extern u8 D_000028C0[0x20];
extern int D_000028E0;
extern u8 D_00002900[0x40];
extern u8 D_00002940[0xC0];
extern u8 D_00002A00[];
extern u8 D_00002B80[];
extern u8 *D_00002870;
extern u8 *D_00002874;

int sceUtilsBufferCopyWithRange(void *out, int outsize, void *in, int insize, int cmd);
int sceIdStorageLookup(int key, int offset, void *buf, int len);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
int sceKernelSignalSema(int id, int n);
int sceKernelWaitSema(int id, int n, unsigned int *timeout);

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MEMCPY(dst, src, n) \
	do { \
		u32 _i; \
		for (_i = 0; _i < (n); _i++) \
			(dst)[_i] = (src)[_i]; \
	} while (0)

#define MEMSET(dst, c, n) \
	do { \
		u32 _i; \
		for (_i = 0; _i < (n); _i++) \
			(dst)[_i] = (c); \
	} while (0)

static inline int memab_memcmp(const s8 *a, const s8 *b, int n)
{
	int i;
	s8 c1, c2;

	for (i = 0; i < n; i++) {
		c1 = *a++;
		c2 = *b++;
		if (c1 != c2)
			return c1 - c2;
	}
	return 0;
}

#define BYTES_TO_U64(p) \
	(((u64)(p)[7] << 56) | ((u64)(p)[6] << 48) | ((u64)(p)[5] << 40) | ((u64)(p)[4] << 32) | \
	 ((u64)(p)[3] << 24) | ((u64)(p)[2] << 16) | ((u64)(p)[1] << 8) | (u64)(p)[0])

#define U64_TO_BYTES(p, v) \
	do { \
		(p)[0] = (v); \
		(p)[1] = (v) >> 8; \
		(p)[2] = (v) >> 16; \
		(p)[3] = (v) >> 24; \
		(p)[4] = (v) >> 32; \
		(p)[5] = (v) >> 40; \
		(p)[6] = (v) >> 48; \
		(p)[7] = (v) >> 56; \
	} while (0)

#endif
