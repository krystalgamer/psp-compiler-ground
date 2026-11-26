#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int SceSize;
typedef int SceUID;
struct SceKernelLoadExecParam;
struct SceKernelLoadExecParam { /* size 0x10 */
    SceSize size;
    SceSize args;
    const void *argp;
    const char *key;
};
typedef struct SceKernelLoadExecParam SceKernelLoadExecParam;



static int ExitFunction(int count, int arg_impose, void *arg_self);
static int check_exit(SceSize arglen, void *arg);
void menuTerm(int cat, int num);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
void sceKernelExitGame(void);


int ExitFunction_364C(void) {
    sceKernelExitGame();
    return 0;
}

int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
int sceKernelDelayThreadCB(unsigned int delay);

static int check_exit(SceSize arglen, void *arg)
{
	SceUID uid;

	uid = sceKernelCreateCallback("exit", ExitFunction_364C, NULL);
	sceKernelRegisterExitCallback(uid);

	while (1) {
		sceKernelDelayThreadCB(10000);
	}

	return 0;
}

void menuInit(void) {
    int temp_v0;

    temp_v0 = sceKernelCreateThread("CheckExitGame", check_exit, 0x10, 0x1000, 0x200000U, NULL);
    if (temp_v0 >= 0) {
        sceKernelStartThread(temp_v0, 0U, NULL);
        sceIoAssign("disc0:", "umd0:", 0, 0, 0, 0);
    }
}

int sceKernelLoadExec(const char *file, SceKernelLoadExecParam *param);
int sprintf(char *buf, const char *fmt, ...);
int sprintf(char *, const char *, ...);
int sceKernelLoadExec(const char *file, SceKernelLoadExecParam *param);
void menuTerm(int cat, int num)
{
	SceKernelLoadExecParam param;
	char arg[32];
	int len;

	len = sprintf(arg, "%d%c%d%c", cat, 0, num, 0);
	param.size = sizeof(param);
	param.args = len;
	param.argp = arg;
	param.key = NULL;
	sceKernelLoadExec("disc0:/PSP_GAME/USRDIR/PRX/menu.prx", &param);
}

int menuGetDevice(void) {
    return 0;
}
