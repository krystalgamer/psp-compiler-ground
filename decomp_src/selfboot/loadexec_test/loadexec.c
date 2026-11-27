/* cflags: -O0 */
#include "common.h"

/* Data (module info, sce_newlib_heap_kb_size, gArgp, gVshArgp) stays in the module's asm. */
typedef unsigned int SceSize;

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

int main(void)
{
	SceKernelLoadExecParam param;

	printf("Activate...\n");
	sceUmdActivate(1, "disc0:");
	printf("WaitDriveStat...\n");
	sceUmdWaitDriveStat(0x20);
	param.size = sizeof(param);
	param.args = 0;
	param.argp = NULL;
	param.key = NULL;
	sceKernelLoadExec("disc0:/PSP_GAME/SYSDIR/BOOT.BIN", &param);
	return 0;
}
