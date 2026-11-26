/* cflags: -O2 -frename-registers */
#include "common.h"

typedef unsigned int SceSize;
typedef int SceUID;

int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *option);
int sceKernelSignalSema(int semid, int signal);
int sceKernelWaitSema(int semid, int signal, unsigned int *timeout);
int sceKernelCreateThread(const char *name, int (*entry)(SceSize, void *), int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, SceSize arglen, void *argp);
int sceKernelWaitThreadEnd(int thid, unsigned int *timeout);
int ThreadManForKernel_809CE29B(int status); /* sceKernelExitDeleteThread */
void *memset(void *s, int c, SceSize n);
int sceIdStorage_driver_FEFA40C2(void);
int sceIdStorage_driver_37833CB8(void);
int sceIdStorageLookup(unsigned short key, unsigned int offset, void *buf, SceSize len);

extern int D_00000820[2]; /* semaphore, result */
extern unsigned int D_00000810;

int flashData_check_CAFC6E68(unsigned char *buf);
static int func_0000027C(unsigned char *buf);
static int func_00000284(unsigned char *buf);

int module_bootstart(SceSize args, void *argp)
{
	int ret;

	ret = sceKernelCreateSema("Flash Tool", 0, 1, 1, NULL);
	D_00000820[0] = ret;
	if (ret < 0)
		return ret;
	return 0;
}

static int func_000000F0(SceSize args, void *argp);
int flashData_check_5E793970(void)
{
	int thid;
	int ret;

	D_00000820[1] = 0;
	thid = sceKernelCreateThread("flashDataThread", func_000000F0, 0x6F, 0x10000, 0, NULL);
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

static int func_000000F0(SceSize args, void *argp)
{
	unsigned char buf[0x8000];
	int ret;

	memset(buf, 0, sizeof(buf));
	if (sceIdStorage_driver_FEFA40C2() == 0) {
		D_00000820[1] = -1;
		goto end;
	}
	ret = func_0000027C(buf);
	if (ret < 0) {
		D_00000820[1] = ret;
		goto end;
	}
	D_00000820[1] = func_00000284(buf);
end:
	ThreadManForKernel_809CE29B(0);
	return 0;
}

int flashData_check_CAFC6E68(unsigned char *buf)
{
	int n, i, j;
	unsigned int c;

	n = *(int *)(buf + 0x48C) / 6 * 5;
	for (i = 1; i < n; i++) {
		u64 v = ((u64 *)(buf + 0x4B8))[i - 1];
		if (v >> 63) {
			int t = (v >> 4) & 7;
			if (t == 1)
				return -2;
			if (t == 2)
				return -3;
		}
	}
	for (j = 0; j < 5; j++) {
		c = buf[0x3D + j * 0xB8];
		if (c >= D_00000810)
			c = D_00000810 - 1;
		if (c != 1)
			return -10;
	}
	for (i = 0; i < 0x4000; i++) {
		if (((char *)buf)[i] != ((char *)buf)[i + 0x4000])
			return -11;
	}
	return 0;
}

static int func_0000027C(unsigned char *buf)
{
	return 0;
}

static int func_00000284(unsigned char *buf)
{
	int i, ret;
	unsigned char *p = buf;

	sceIdStorage_driver_37833CB8();
	for (i = 0; i < 0x40; i++, p += 0x200) {
		ret = sceIdStorageLookup(0x100 + i, 0, p, 0x200);
		if (ret < 0)
			return ret;
	}
	return flashData_check_CAFC6E68(buf);
}

int func_00000304(unsigned char *buf)
{
	int i, ret;

	sceIdStorage_driver_37833CB8();
	for (i = 0; i < 0x40; i++, buf += 0x200) {
		ret = sceIdStorageLookup(0x100 + i, 0, buf, 0x200);
		if (ret < 0)
			break;
	}
	return ret;
}
