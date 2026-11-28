/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *, ...);
M2C_UNK thrDelete(void *);                          /* extern */
extern unsigned char D_000FB638;
typedef struct ThrCntx { int Thid; int pad[3]; struct ThrCntx *pPrev; struct ThrCntx *pNext; int pad2; int Prio; int pad3[4]; char Name[16]; } ThrCntx;
extern ThrCntx *pThrEntry;
extern unsigned char D_000FB64C, D_000FB680, D_000FB690;
#ifndef THR_ASSERT
#define THR_ASSERT(line, fn) consPrintf(&D_000FB64C, &D_000FB680, line, fn, &D_000FB690)
#endif

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB638);

void thrInit(void) {
    consPrintf(&D_000FB638, "thrInit");
    pThrEntry = 0;
}

void thrTerm(void) {
    void *var_s0;

    consPrintf(&D_000FB638, "thrTerm");
    var_s0 = pThrEntry;
    if (var_s0 != NULL) {
        do {
            thrDelete(var_s0);
            var_s0 = M2C_FIELD(var_s0, void **, 0x14);
        } while (var_s0 != NULL);
    }
    pThrEntry = NULL;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB64C);

int sceKernelCreateThread(const char *name, void *entry, int prio, int stack, unsigned int attr, void *opt);
int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int);
void *memcpy(void *, const void *, unsigned int);
int thrProc();
void thrMake(ThrCntx *pCntx, int Prio, char *pName)
{
	int Thid;
	int intr;

	Thid = sceKernelCreateThread(pName, thrProc, Prio, 0x4000, 0x4000, NULL);
	switch (Thid) {
	default:
		pCntx->Thid = Thid;
		pCntx->Prio = Prio;
		memcpy(pCntx->Name, pName, 16);
		pCntx->Name[15] = 0;
		intr = sceKernelCpuSuspendIntr();
		{
			ThrCntx *n = pThrEntry;
			pCntx->pPrev = NULL;
			pCntx->pNext = n;
			pThrEntry = pCntx;
			if (n != NULL)
				n->pPrev = pCntx;
		}
		sceKernelCpuResumeIntr(intr);
		consPrintf("%s : %3d : %s\n", "thrMake", Prio, pName);
		break;
	case 0x80020190:
		THR_ASSERT(0x67, "thrMake");
		break;
	case 0x80020191:
		THR_ASSERT(0x68, "thrMake");
		break;
	case 0x80020194:
		THR_ASSERT(0x69, "thrMake");
		break;
	case 0x80020064:
		THR_ASSERT(0x6A, "thrMake");
		break;
	case 0x80020193:
		THR_ASSERT(0x6B, "thrMake");
		break;
	case 0x80020192:
		THR_ASSERT(0x6C, "thrMake");
		break;
	case 0x800201B9:
		THR_ASSERT(0x6D, "thrMake");
		break;
	}
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB680);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB690);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", D_000FB698);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrState);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrEntry);

int sceKernelSleepThreadCB(void);
void thrChange(void)
{
	int ret = sceKernelSleepThreadCB();
	switch (ret) {
	case 0:
		break;
	default:
		THR_ASSERT(0xCB, "thrChange");
		break;
	case 0x800201AA:
		THR_ASSERT(0xCC, "thrChange");
		break;
	case 0x800201A7:
		THR_ASSERT(0xCD, "thrChange");
		break;
	case 0x80020064:
		THR_ASSERT(0xCE, "thrChange");
		break;
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrDelete);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrVSync);
