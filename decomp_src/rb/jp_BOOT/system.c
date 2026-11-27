#include "common.h"
#include <psptypes.h>
#include <kerneltypes.h>
#include <stdio.h>
#include <thread.h>
#include <modulemgr.h>
#include <loadexec.h>
#include <ctrlsvc.h>
#include <libgu.h>
#include <libwave.h>
#include "strfile.h"

typedef struct {
	char name[16];
	char path[64];
	SceUID mid;
	int mode;
} MOD_INFO;

int BgmInit(void);
int BgmTerm(void);

#define strFile strFile_279EDC

extern MOD_INFO minfo[5];
extern StrFile strFile;
extern SceUID th_id;

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/system", load_module);

static int unload_module(void)
{
	SceInt32 mresult;
	int ret;
	int i;

	ret = 0;
	for (i = 4; i >= 0; i--) {
		if (sceKernelStopModule(minfo[i].mid, 0, NULL, &mresult, NULL) < 0) {
			printf("Error: Stop Module(%s)\n", minfo[i].name);
			ret = -1;
		}
		if (sceKernelUnloadModule(minfo[i].mid) < 0) {
			printf("Error: Unload Module(%s)\n", minfo[i].name);
			ret = -1;
		}
	}
	return ret;
}

static int exit_cb(int count, int arg1, void *arg2)
{
	printf("** %s() **\n", __FUNCTION__);
	sceKernelExitGame();
	return 0;
}

static int check_exit(SceSize arglen, void *arg)
{
	SceUID cbid;

	cbid = sceKernelCreateCallback("DemoDisc", (SceKernelCallbackFunction)exit_cb, NULL);
	sceKernelRegisterExitCallback(cbid);
	for (;;)
		sceKernelDelayThreadCB(10000);
	return 0;
}

int SystemInit(void)
{
	{
		SceUID th_id;

		th_id = sceKernelCreateThread("CheckExitGame", (SceKernelThreadEntry)check_exit, 0x3E, 0x1000, 0x200000, NULL);
		if (th_id < 0)
			return th_id;
		sceKernelStartThread(th_id, 0, NULL);
	}
	strFileAssign(&strFile, "disc0", 1);
	if (load_module() < 0)
		return -1;
	sceCtrlSetSamplingMode(0);
	sceGuInit();
	sceWaveInit();
	BgmInit();
	return 0;
}

int SystemTerm(void)
{
	BgmTerm();
	sceWaveExit();
	sceGuSync(0, 0);
	sceGuTerm();
	if (unload_module() < 0)
		return -1;
	strFileUnassign(&strFile);
	sceKernelWaitThreadEnd(th_id, NULL);
	return 0;
}
