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



void menuTerm(int cat, int num);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelCreateThread(const char *name, void *entry, int prio, int stacksize, unsigned int attr, void *option);
int sceKernelStartThread(int thid, unsigned int arglen, void *argp);
int sceKernelDelayThreadCB(unsigned int delay);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
void sceKernelExitGame(void);


int ExitFunction(int count, int arg_impose, void *arg_self) {
    sceKernelExitGame();
    return 0;
}

void check_exit(unsigned int arglen, void *arg) {
    sceKernelRegisterExitCallback(sceKernelCreateCallback("exit", ExitFunction, NULL));
loop_1:
    sceKernelDelayThreadCB(0x2710U);
    goto loop_1;
}

void menuInit(void) {
    int temp_v0;

    temp_v0 = sceKernelCreateThread("CheckExitGame", check_exit, 0x10, 0x1000, 0x200000U, NULL);
    if (temp_v0 >= 0) {
        sceKernelStartThread(temp_v0, 0U, NULL);
        sceIoAssign("disc0:", "umd0:", 0, 0, 0, 0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_simple/nonmatchings/menu", menuTerm);

int menuGetDevice(void) {
    return 0;
}
