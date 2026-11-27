/* cflags: -O0 */
#include "common.h"

/* Data (module info, sce_newlib_heap_kb_size, gArgp, gLoadExecThreadId) stays in the module's asm. */
typedef unsigned int SceSize;
typedef int SceUID;
typedef int (*SceKernelThreadEntry)(SceSize args, void *argp);

typedef struct SceKernelLoadExecParam {
	SceSize size;
	SceSize args;
	void *argp;
	const char *key;
} SceKernelLoadExecParam;

int printf(const char *fmt, ...);
int sceUmdActivate(int mode, const char *aliasname);
int sceUmdWaitDriveStat(int stat);
int sceKernelLoadExec(const char *file, SceKernelLoadExecParam *param);
SceUID sceKernelCreateThread(const char *name, SceKernelThreadEntry entry, int initPriority,
			     int stackSize, unsigned int attr, void *option);
int sceKernelStartThread(SceUID thid, SceSize arglen, void *argp);
int sceKernelWaitThreadEnd(SceUID thid, unsigned int *timeout);

extern int gLoadExecThreadId;

int LoadExecThread(SceSize argc, void *argv)
{
	SceKernelLoadExecParam param;

	printf("Activate...\n");
	sceUmdActivate(1, "disc0:");
	printf("WaitDriveStat...\n");
	sceUmdWaitDriveStat(0x20);
	printf("done...\n");
	param.size = sizeof(param);
	param.args = 0;
	param.argp = NULL;
	param.key = NULL;
	sceKernelLoadExec("disc0:/PSP_GAME/SYSDIR/BOOT.BIN", &param);
	return 0;
}

int main(void)
{
	int ret;

	printf("create thread\n");
	ret = sceKernelCreateThread("LOADEXEC_SAMPLE", LoadExecThread, 0x32, 0x800, 0, NULL);
	if (ret < 0) {
		printf("ERROR: sceKernelCreateThread(%x)\n", ret);
		return ret;
	}
	if (ret >= 0)
		gLoadExecThreadId = ret;
	printf("start thread\n");
	sceKernelStartThread(gLoadExecThreadId, 0, NULL);
	sceKernelWaitThreadEnd(gLoadExecThreadId, NULL);
}
