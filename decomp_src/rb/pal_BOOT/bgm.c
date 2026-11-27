#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
typedef int SceInt32;
struct _anon1 { /* size 0xc */
    SceInt32 atracId;
    SceInt32 fd;
    SceInt32 outputChannel;
};
typedef struct _anon1 ScePlayArg;
typedef int SceUID;
typedef unsigned char SceUChar8;

extern SceUID thid;
extern SceUChar8 aucReadBuf0[1048578];

int BgmInit(void);
int BgmTerm(void);
int BgmStart(void);
int BgmEnd(void);


INCLUDE_ASM("tmp/asm/rb/pal_BOOT/nonmatchings/bgm", BgmInit);

int sceKernelDeleteThread(int thid);
int printf(const char *fmt, ...);
int BgmTerm(void)
{
	SceInt32 thread_status;
	SceInt32 status;
	int ret;

	ret = 0;
	status = sceKernelWaitThreadEnd(thid, NULL);
	if (status != 0) {
		printf("sceKernelWaitThread: 0x%08X\n", status);
		ret = -1;
	}
	status = sceKernelDeleteThread(thid);
	if (status != 0) {
		printf("sceKernelDeleteThread: 0x%08X\n", status);
		ret = -1;
	}
	return ret;
}

int sceKernelWakeupThread(int thid);
int sceKernelChangeThreadPriority(int thid, int prio);
int BgmStart(void)
{
	sceKernelWakeupThread(thid);
	sceKernelChangeThreadPriority(thid, 16);
	at3plus_setfade(1);
	return 0;
}

int BgmEnd(void)
{
	sceKernelChangeThreadPriority(thid, 16);
	at3plus_setfade(2);
	return 0;
}
