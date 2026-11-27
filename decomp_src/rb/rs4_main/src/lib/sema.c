/* cflags: -Os -fno-strength-reduce */
#include "common.h"
void consPrintf(const char *, ...);
extern unsigned char D_000FB2C8, D_000FB2D4, D_000FB2F0, D_000FB300;
#define SEMA_ASSERT(line, fn) consPrintf(&D_000FB2D4, &D_000FB2F0, line, fn, &D_000FB300)

int sceKernelCreateSema(const char *, int, int, int, void *);
int semaInit(const char *name)
{
	int ret;
	consPrintf(&D_000FB2C8, "semaInit", name);
	ret = sceKernelCreateSema(name, 0, 1, 1, 0);
	switch (ret) {
	default:
		if (ret > 0)
			return ret;
		SEMA_ASSERT(0x19, "semaInit");
		break;
	case 0x80020190:
		SEMA_ASSERT(0x1C, "semaInit");
		break;
	case 0x80020191:
		SEMA_ASSERT(0x1D, "semaInit");
		break;
	case 0x80020064:
		SEMA_ASSERT(0x1E, "semaInit");
		break;
	}
	return 0x80020001;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sema", D_000FB2C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sema", D_000FB2D4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sema", D_000FB2F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sema", D_000FB300);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/sema", D_000FB308);

typedef struct { int size; char name[32]; int attr, init, cur, max, wait; } SemaInfo;
extern const SemaInfo D_000FB308;
int sceKernelReferSemaStatus(int, SemaInfo *);
int sceKernelDeleteSema(int);
int semaTerm(int id)
{
	SemaInfo info = D_000FB308;
	int ret;
	sceKernelReferSemaStatus(id, &info);
	consPrintf(&D_000FB2C8, "semaTerm", info.name);
	ret = sceKernelDeleteSema(id);
	switch (ret) {
	case 0:
		return 1;
	default:
		SEMA_ASSERT(0x39, "semaTerm");
		break;
	case 0x80020064:
		SEMA_ASSERT(0x3A, "semaTerm");
		break;
	case 0x80020199:
		SEMA_ASSERT(0x3B, "semaTerm");
		break;
	}
	return 0;
}

int sceKernelWaitSema(int, int, void *);
void semaLock(int id)
{
	int ret = sceKernelWaitSema(id, 1, 0);
	switch (ret) {
	case 0:
		break;
	default:
		SEMA_ASSERT(0x4C, "semaLock");
		break;
	case 0x80020064:
		SEMA_ASSERT(0x4D, "semaLock");
		break;
	case 0x800201BD:
		SEMA_ASSERT(0x4E, "semaLock");
		break;
	case 0x80020199:
		SEMA_ASSERT(0x4F, "semaLock");
		break;
	case 0x800201AD:
		SEMA_ASSERT(0x50, "semaLock");
		break;
	case 0x800201A9:
		SEMA_ASSERT(0x51, "semaLock");
		break;
	case 0x800201AA:
		SEMA_ASSERT(0x52, "semaLock");
		break;
	case 0x800201A7:
		SEMA_ASSERT(0x53, "semaLock");
		break;
	case 0x800201B5:
		SEMA_ASSERT(0x54, "semaLock");
		break;
	case 0x800201A8:
		SEMA_ASSERT(0x55, "semaLock");
		break;
	}
}

int sceKernelSignalSema(int, int);
void semaUnlock(int id)
{
	int ret = sceKernelSignalSema(id, 1);
	switch (ret) {
	case 0:
		break;
	case 0x800201AE:
		break;
	default:
		SEMA_ASSERT(0x65, "semaUnlock");
		break;
	case 0x80020199:
		SEMA_ASSERT(0x66, "semaUnlock");
		break;
	}
}
