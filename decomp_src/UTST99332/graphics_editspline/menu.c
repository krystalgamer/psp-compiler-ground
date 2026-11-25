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


int ExitFunction(int count, int arg_impose, void *arg_self) {
    sceKernelExitGame();
    return 0;
}

void check_exit(unsigned int arglen, void *arg) {
    sceKernelRegisterExitCallback(sceKernelCreateCallback("exit", ExitFunction, 0));
loop_1:
    sceKernelDelayThreadCB(0x2710);
    goto loop_1;
}

void menuInit(void) {
    int temp_v0;

    temp_v0 = sceKernelCreateThread("CheckExitGame", check_exit, 0x10, 0x1000, 0x200000, 0);
    if (temp_v0 >= 0) {
        sceKernelStartThread(temp_v0, 0, 0);
        sceIoAssign("disc0:", "umd0:", 0, 0, 0, 0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_editspline/nonmatchings/menu", menuTerm);

int menuGetDevice(void) {
    return 0;
}
