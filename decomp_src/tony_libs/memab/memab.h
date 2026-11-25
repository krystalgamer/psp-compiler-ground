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

#endif
