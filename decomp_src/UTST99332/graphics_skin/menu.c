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



void menuInit(void);
void menuTerm(int cat, int num);

/* SDK functions (tools/sdk_protos.h) */
int sceKernelDelayThreadCB(unsigned int delay);
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);
void sceKernelExitGame(void);


int ExitFunction(int count, int arg_impose, void *arg_self) {
    sceKernelExitGame();
    return 0;
}

extern signed char D_00011BD0;

void check_exit(unsigned int arglen, void *arg) {
    sceKernelRegisterExitCallback(sceKernelCreateCallback(&D_00011BD0, ExitFunction, NULL));
loop_1:
    sceKernelDelayThreadCB(0x2710U);
    goto loop_1;
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/menu", menuInit);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_skin/nonmatchings/menu", menuTerm);

int menuGetDevice(void) {
    return 0;
}
