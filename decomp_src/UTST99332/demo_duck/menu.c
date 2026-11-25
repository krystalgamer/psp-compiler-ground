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



static int check_exit(SceSize arglen, void *arg);
void menuInit(void);
void menuTerm(int cat, int num);


int ExitFunction(int count, int arg_impose, void *arg_self) {
    sceKernelExitGame();
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/menu", check_exit);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/menu", menuInit);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/menu", menuTerm);

int menuGetDevice(void) {
    return 0;
}
