/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
int scePowerRegisterCallback(M2C_UNK, int);         /* extern */
extern unsigned char D_000FA67C;
extern unsigned char D_000FA68C;
extern unsigned char D_000FA6A8;
extern unsigned char D_000FA6B8;
extern int PowerUID;
int powerProc(int a, int state);
int sceKernelDeleteCallback(int);                   /* extern */
int scePowerUnregisterCallback(M2C_UNK);            /* extern */
extern int PowerState;
int sceKernelCreateCallback(const char *name, void *func, void *arg);

extern int PowerState;

int powerInit(void) {
    int temp_v0;

    temp_v0 = sceKernelCreateCallback("powerProc", &powerProc, NULL);
    PowerUID = temp_v0;
    if (temp_v0 <= 0) {
        consPrintf(&D_000FA68C, &D_000FA6A8, 0x28, "powerInit", &D_000FA67C);
    }
    if (scePowerRegisterCallback(0, PowerUID) != 0) {
        consPrintf(&D_000FA68C, &D_000FA6A8, 0x2D, "powerInit", &D_000FA6B8);
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA67C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA68C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6B8);

int powerTerm(void) {
    if (PowerUID <= 0) {
        consPrintf(&D_000FA68C, &D_000FA6A8, 0x39, "powerTerm", &D_000FA67C);
    }
    if (scePowerUnregisterCallback(0) != 0) {
        consPrintf(&D_000FA68C, &D_000FA6A8, 0x3D, "powerTerm", &D_000FA6B8);
    }
    if (sceKernelDeleteCallback(PowerUID) != 0) {
        consPrintf(&D_000FA68C, &D_000FA6A8, 0x42, "powerTerm", "Ret == SCE_KERNEL_ERROR_OK");
    }
    PowerUID = -1;
    return 1;
}

int powerProc(int a, int state)
{
	PowerState = state;
	return 0;
}

int powerState(void) {
    return PowerState;
}
