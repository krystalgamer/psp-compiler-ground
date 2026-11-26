/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
int scePowerRegisterCallback(M2C_UNK, int);         /* extern */
extern unsigned char D_000FA67C;
extern unsigned char D_000FA68C;
extern unsigned char D_000FA6A8;
extern unsigned char D_000FA6B8;
extern int PowerUID;
extern unsigned char powerProc;
int sceKernelDeleteCallback(int);                   /* extern */
int scePowerUnregisterCallback(M2C_UNK);            /* extern */
extern int PowerState;
int sceUmdActivate(M2C_UNK, int);                   /* extern */
extern unsigned char D_000FA7FC;
extern unsigned char D_000FA818;
extern unsigned char D_000FA870;
extern int UmdName_Alias;
extern int UmdStandby;



#ifndef NULL
#define NULL ((void *)0)
#endif
int sceKernelCreateCallback(const char *name, void *func, void *arg);

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

#ifndef NULL
#define NULL ((void *)0)
#endif

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", powerProc);

#ifndef NULL
#define NULL ((void *)0)
#endif

int powerState(void) {
    return PowerState;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA6F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA708);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA724);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA734);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprCall);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", sprFree);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sprGetSize(void) {
    return 0x800;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7C0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", umdInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA7FC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA828);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA848);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA85C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA864);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA870);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA88C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA898);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", umdTerm);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/power", D_000FA8A4);

#ifndef NULL
#define NULL ((void *)0)
#endif

void umdActive(void) {
    if ((UmdStandby == 1) && (sceUmdActivate(1, UmdName_Alias) != 0)) {
        consPrintf(&D_000FA7FC, &D_000FA818, 0x8C, "umdActive", &D_000FA870);
    }
}
