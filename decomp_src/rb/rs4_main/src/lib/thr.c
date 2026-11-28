/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *, ...);
int thrDelete();
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

typedef struct { int size; char name[32]; int attr; int status; int rest[16]; } ThrInfo;
int sceKernelReferThreadStatus(int thid, ThrInfo *info);
int thrState(ThrCntx *pCntx)
{
	ThrInfo info = { sizeof(ThrInfo) };
	int ret;

	ret = sceKernelReferThreadStatus(pCntx->Thid, &info);
	switch (ret) {
	case 0:
		switch (info.status) {
		default:
			THR_ASSERT(0x7F, "thrState");
			return -1;
		case 16:
			return 0;
		case 1:
		case 2:
		case 4:
		case 8:
		case 12:
			return 1;
		}
	default:
		THR_ASSERT(0x91, "thrState");
		break;
	case 0x80020198:
		THR_ASSERT(0x92, "thrState");
		break;
	case 0x80020197:
		THR_ASSERT(0x93, "thrState");
		break;
	}
	return -1;
}

int sceKernelStartThread(int thid, int size, void *argp);
void *memcpy(void *, const void *, unsigned int);
int thrEntry(ThrCntx *pCntx, void *Func, void *pArgv, int Argc)
{
	ThrCntx *p;

	switch (thrState(pCntx)) {
	case 1:
		return 1;
	case 0:
		pCntx->pad[0] = (int)Func;
		pCntx->pad[1] = (int)((char *)pCntx + 0x40);
		pCntx->pad[2] = Argc;
		if (pArgv != NULL && Argc != 0)
			memcpy((char *)pCntx + 0x40, pArgv, Argc * 4);
		p = pCntx;
		switch (sceKernelStartThread(pCntx->Thid, 4, &p)) {
		case 0:
			return 0;
		default:
			THR_ASSERT(0xB0, "thrEntry");
			break;
		case 0x80020198:
			THR_ASSERT(0xB1, "thrEntry");
			break;
		case 0x80020197:
			THR_ASSERT(0xB2, "thrEntry");
			break;
		case 0x80020064:
			THR_ASSERT(0xB3, "thrEntry");
			break;
		case 0x800201A4:
			THR_ASSERT(0xB4, "thrEntry");
			break;
		}
	}
	return -1;
}

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

int sceKernelTerminateThread(int thid);
int sceKernelDeleteThread(int thid);
int thrDelete(ThrCntx *pCntx)
{
	int intr;
	ThrCntx *pPrev, *pNext;

	switch (sceKernelTerminateThread(pCntx->Thid)) {
	case 0:
	case 0x800201A2:
		switch (sceKernelDeleteThread(pCntx->Thid)) {
		case 0:
			intr = sceKernelCpuSuspendIntr();
			pPrev = pCntx->pPrev;
			pNext = pCntx->pNext;
			if (pPrev != NULL)
				pPrev->pNext = pNext;
			else
				pThrEntry = pNext;
			if (pNext != NULL)
				pNext->pPrev = pPrev;
			sceKernelCpuResumeIntr(intr);
			return 0;
		default:
			THR_ASSERT(0xEE, "thrDelete");
			break;
		case 0x80020198:
			THR_ASSERT(0xEF, "thrDelete");
			break;
		case 0x80020064:
			THR_ASSERT(0xF0, "thrDelete");
			break;
		case 0x800201A4:
			THR_ASSERT(0xF1, "thrDelete");
			break;
		}
		break;
	default:
		THR_ASSERT(0xF5, "thrDelete");
		break;
	case 0x80020198:
		THR_ASSERT(0xF6, "thrDelete");
		break;
	case 0x80020197:
		THR_ASSERT(0xF7, "thrDelete");
		break;
	}
	return -1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/thr", thrProc);

int sceKernelWakeupThread(int thid);
void thrVSync(void)
{
	ThrCntx *p;
	int ret;

	for (p = pThrEntry; p != NULL; p = p->pNext) {
		ThrInfo info = { sizeof(ThrInfo) };

		ret = sceKernelReferThreadStatus(p->Thid, &info);
		switch (ret) {
		case 0:
			switch (info.status) {
			case 4:
				ret = sceKernelWakeupThread(p->Thid);
				switch (ret) {
				case 0:
					p->Prio = info.rest[5];
					break;
				default:
					THR_ASSERT(0x13F, "thrVSync");
					break;
				case 0x80020198:
					THR_ASSERT(0x140, "thrVSync");
					break;
				case 0x80020064:
					THR_ASSERT(0x141, "thrVSync");
					break;
				case 0x800201A2:
					THR_ASSERT(0x142, "thrVSync");
					break;
				}
				break;
			case 1:
			case 2:
			case 8:
			case 12:
			case 16:
				break;
			}
			break;
		default:
			THR_ASSERT(0x149, "thrVSync");
			break;
		case 0x80020198:
			THR_ASSERT(0x14A, "thrVSync");
			break;
		case 0x80020197:
			THR_ASSERT(0x14B, "thrVSync");
			break;
		}
	}
}
