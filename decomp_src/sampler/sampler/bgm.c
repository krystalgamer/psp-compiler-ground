#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <thread.h>
#include "at3plus.h"

extern SceUID thid;
extern SceUChar8 aucReadBuf0[1048578];

#ifdef NON_MATCHING
/* the original keeps status in v1 throughout and shares one printf */
int BgmInit(void)
{
	ScePlayArg playArg0;
	SceInt32 status;

	status = init_atrac3plus("disc0:/PSP_GAME/USRDIR/SOUND/menu.at3", aucReadBuf0, 0x100000, 1, &playArg0);
	if (status < 0) {
		printf("init_atrac3plus error :0x%08X\n", status);
		return -1;
	}
	status = thid = sceKernelCreateThread("at3pplay", play_atrac3plus, 0x3D, 0x10000, 0, NULL);
	if (status < 0) {
		printf("sceKernelCreateThread:0x%08X\n", status);
		return -1;
	}
	status = sceKernelStartThread(thid, sizeof(playArg0), &playArg0);
	if (status != 0) {
		printf("sceKernelStartThread:0x%08X\n", status);
		return -1;
	}
	return 0;
}
#else
INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/bgm", BgmInit);
#endif

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
