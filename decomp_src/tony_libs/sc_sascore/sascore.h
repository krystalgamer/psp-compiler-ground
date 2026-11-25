#ifndef SASCORE_H
#define SASCORE_H

#include "common.h"

typedef struct {
	unsigned int sl;
	char pad4[0xA - 4];
	s8 state;
	char padB;
} SasEnv;

typedef struct {
	int addr;
	int end;
	u8 type;
	u8 loop;
	u16 pitch;
	int volL;
	int volR;
	int unk14;
	int height;
	char pad1C[0x2C - 0x1C];
	SasEnv env;
} SasVoice;

typedef struct {
	char pad0[0x10];
	int endFlag;
	SasVoice voice[32];
	char pad714[0xE20 - 0x714];
} SasCore;

extern int D_00001DD0;
extern void *D_00001DE0;
void *sceMeCalloc(unsigned int n, unsigned int size);
void sceMeFree(void *p);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
extern const s8 D_00001DA0[8];
extern const s8 D_00001DA8[8];

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

#define K1_USER() pspK1IsUserMode()
#define CHECK_CORE(core) (K1_USER() && (int)((unsigned int)(core) | ((unsigned int)(core) + sizeof(SasCore))) < 0)

#endif
