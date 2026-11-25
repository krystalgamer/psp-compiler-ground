/* cflags: -O2 -frename-registers */
#include "common.h"

typedef unsigned int SceSize;

int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sceKernelCreateThread(const char *name, int (*entry)(SceSize, void *), int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, SceSize arglen, void *argp);
int sceKernelWaitThreadEnd(int thid, unsigned int *timeout);
int ThreadManForKernel_809CE29B(int status); /* sceKernelExitDeleteThread */
void *memset(void *s, int c, SceSize n);
int sceIdStorage_driver_FEFA40C2(void);
int func_00000304(unsigned char *buf);

extern int D_00000820[2]; /* semaphore, result */
extern unsigned int D_00000810;

static int func_00000410(SceSize args, void *argp);
int flashData_check_2FAE1B89(unsigned char *buf);
static int func_000005A8(unsigned char *buf);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007A4);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007AC);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007B4);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007B8);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007C0);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007C8);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007D0);

INCLUDE_RODATA("tmp/asm/umdt/flashData_check/nonmatchings/flashData_check2", D_000007D8);

int flashData_check_768B7C11(void)
{
	int thid;
	int ret;

	D_00000820[1] = 0;
	thid = sceKernelCreateThread("flashDataThread", func_00000410, 0x6F, 0x10000, 0, NULL);
	if (thid > 0) {
		ret = sceKernelStartThread(thid, 0, NULL);
		if (ret < 0)
			return ret;
		ret = sceKernelWaitSema(D_00000820[0], 1, NULL);
		if (ret < 0)
			return ret;
		sceKernelWaitThreadEnd(thid, NULL);
		sceKernelSignalSema(D_00000820[0], 1);
	}
	return D_00000820[1];
}

static int func_00000410(SceSize args, void *argp)
{
	unsigned char buf[0x8000];

	memset(buf, 0, sizeof(buf));
	sceIdStorage_driver_FEFA40C2();
	D_00000820[1] = func_000005A8(buf);
	ThreadManForKernel_809CE29B(0);
	return 0;
}

int flashData_check_2FAE1B89(unsigned char *buf)
{
	int n, i, j;
	int region;
	unsigned int c;

	n = *(int *)(buf + 0x48C) / 6 * 5;
	region = buf[0x3D] - 3;
	for (i = 1; i < n; i++) {
		u64 v = ((u64 *)(buf + 0x4B8))[i - 1];
		if (v >> 63) {
			int a = (v >> 28) & 3;
			int b = v & 0xF;
			if (a == 3)
				return -4;
			if ((unsigned int)region < 4 && b != region) {
				if (b != 15)
					return -5;
			}
		}
	}
	for (j = 0; j < 5; j++) {
		c = buf[0x3D + j * 0xB8];
		if (c >= D_00000810)
			c = D_00000810 - 1;
		if (c != region + 3 || !((unsigned int)region < 4))
			return -10;
	}
	for (i = 0; i < 0x4000; i++) {
		if (((char *)buf)[i] != ((char *)buf)[i + 0x4000])
			return -11;
	}
	return 0;
}

static int func_000005A8(unsigned char *buf)
{
	int ret;

	ret = func_00000304(buf);
	if (ret < 0)
		return ret;
	return flashData_check_2FAE1B89(buf);
}
