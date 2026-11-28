/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
extern signed char D_000FA21C;
extern signed char D_000FA220;
extern unsigned char D_000FA22C;
extern unsigned char D_000FA23C;
extern signed char D_000FA248;
extern unsigned char D_000FA264;
extern int HomeUID;
extern unsigned char homeProc;
int sceKernelDeleteCallback(int);                   /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateCallback(const char *name, void *func, void *arg);
int sceKernelRegisterExitCallback(int cbid);

void consPrintf(const char *fmt, ...);
int homeInit(void) {
    M2C_UNK *temp_v0;
    int temp_v0_2;

    temp_v0 = "homeInit";
    consPrintf(&D_000FA21C, temp_v0);
    temp_v0_2 = sceKernelCreateCallback(&D_000FA220, &homeProc, NULL);
    HomeUID = temp_v0_2;
    if (temp_v0_2 <= 0) {
        consPrintf(&D_000FA248, &D_000FA22C, 0x21, temp_v0, &D_000FA23C);
    }
    if (sceKernelRegisterExitCallback(HomeUID) != 0) {
        consPrintf(&D_000FA248, &D_000FA22C, 0x26, temp_v0, &D_000FA264);
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA21C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA220);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA22C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA23C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA248);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA264);

#ifndef NULL
#define NULL ((void *)0)
#endif

int homeTerm(void) {
    M2C_UNK *temp_v0;

    temp_v0 = "homeTerm";
    consPrintf(&D_000FA21C, temp_v0);
    if (HomeUID <= 0) {
        consPrintf(&D_000FA248, &D_000FA22C, 0x32, temp_v0, &D_000FA23C);
    }
    if (sceKernelDeleteCallback(HomeUID) != 0) {
        consPrintf(&D_000FA248, &D_000FA22C, 0x36, temp_v0, &D_000FA264);
    }
    HomeUID = -1;
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", homeProc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA350);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA364);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/home", D_000FA37C);
