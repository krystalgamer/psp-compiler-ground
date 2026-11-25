#ifndef SASCORE_H
#define SASCORE_H

#include "common.h"

typedef struct {
	unsigned int sl;
	union {
		unsigned int w;
		u8 b[4];
	} mode;
	u8 unk8;
	u8 unk9;
	s8 state;
	char padB;
} SasEnv;

typedef union {
	int pack;
	s16 lr[2];
} SasVol;

typedef struct {
	int addr;
	int end;
	u8 type;
	u8 loop;
	u16 pitch;
	SasVol vol;
	SasVol evol;
	u8 *buf;
	int height;
	unsigned int ar;
	unsigned int dr;
	unsigned int sr;
	unsigned int rr;
	SasEnv env;
} SasVoice;

typedef struct {
	int unk0;
	union {
		unsigned int w;
		u8 b[4];
	} rev;
	u8 unk8;
	u8 unk9;
	u8 von;
	s8 busy;
	s16 evolL;
	s16 evolR;
	int endFlag;
	SasVoice voice[32];
	SasVoice voice2[32];
	int unkE14;
	u8 vonCopy;
	u8 padE19;
	s16 evolLCopy;
	s16 evolRCopy;
	char padE1E[0xE20 - 0xE1E];
} SasCore;

extern int D_00001DD0;
extern void *D_00001DE0;
void *sceMeCalloc(unsigned int n, unsigned int size);
void sceMeFree(void *p);
void sceKernelDcacheWritebackInvalidateAll(void);
void sceKernelDcacheWritebackInvalidateRange(const void *p, unsigned int size);
void sceKernelDcacheInvalidateRange(const void *p, unsigned int size);
int sceMeCore_driver_3D5F109C(int cmd, ...);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
extern const s8 D_00001DA0[8];
extern const s8 D_00001DA8[8];
extern const s16 D_00001DB0[8];

int sceKernelWaitSema(int sema, int n, void *timeout);
int sceKernelSignalSema(int sema, int n);

static inline unsigned int pspShiftK1(void)
{
	unsigned int k1;

	asm volatile(".set noreorder\n\tmove %0, $27\n\tsrl $27, $27, 16\n\t.set reorder" : "=r"(k1));
	return k1;
}

static inline void pspSetK1(unsigned int k1)
{
	asm volatile("move $27, %0" : : "r"(k1));
}

static inline int pspK1IsUserMode(void)
{
	int r;

	asm volatile("andi %0, $27, 0x18" : "=r"(r));
	return r;
}

static inline int pspRetK1(int ret, unsigned int k1)
{
	asm volatile("move $27, %0" : : "r"(k1));
	return ret;
}

#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define K1_USER() pspK1IsUserMode()

static inline int ptrOk(unsigned int addr)
{
	return (addr >> 31) ^ 1;
}

static inline int staBufOk(unsigned int addr, unsigned int size)
{
	return ((addr | (addr + size)) >> 31) ^ 1;
}

static inline int dynBufOk(unsigned int addr, unsigned int size)
{
	return ((addr | size | (addr + size)) >> 31) ^ 1;
}

static inline int ptrBad(unsigned int addr)
{
	if (K1_USER() && !ptrOk(addr))
		return 1;
	return 0;
}

static inline int staBufBad(unsigned int addr, unsigned int size)
{
	if (K1_USER() && !staBufOk(addr, size))
		return 1;
	return 0;
}

static inline int dynBufBad(unsigned int addr, unsigned int size)
{
	if (K1_USER() && !dynBufOk(addr, size))
		return 1;
	return 0;
}
#define CHECK_CORE(core) (K1_USER() && (int)((unsigned int)(core) | ((unsigned int)(core) + sizeof(SasCore))) < 0)

#endif
