/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK semaLock(int);                              /* extern */
extern int SemaMod;
M2C_UNK semaUnlock(int);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", modInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA398);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA3DC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA404);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA42C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA45C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA484);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", modTerm);

void modLock(void) {
    if (SemaMod > 0) {
        semaLock(SemaMod);
    }
}

void modUnlock(void) {
    if (SemaMod > 0) {
        semaUnlock(SemaMod);
    }
}

int fileReady();                                    /* extern */
int sceKernelLoadModule(int, M2C_UNK, M2C_UNK);     /* extern */
int sceKernelStartModule(int, M2C_UNK, M2C_UNK, M2C_UNK *, void *); /* extern */
extern unsigned char D_000FA3A4;
extern unsigned char D_000FA3C0;
extern unsigned char D_000FA4C8;

int modLoad(int arg0) {
    int sp20;
    int opt[5];
    M2C_UNK *temp_v0;
    int var_s2;

    var_s2 = 0;
    if (arg0 == 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0xC6, "modLoad", "pName");
    }
    while (var_s2 <= 0) {
        if (fileReady() == 1) {
            fileLock();
            var_s2 = sceKernelLoadModule(arg0, 0, 0);
            fileUnlock();
        }
        if (var_s2 > 0) break;
        sceKernelDelayThreadCB(0x3E8U);
    }
    temp_v0 = "modLoad";
    consPrintf("%s : 0x%08x : %s\n", temp_v0, var_s2, arg0);
    if (var_s2 <= 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0xDE, temp_v0, "UID > 0");
    }
    modLock();
    memset(opt, 0, 0x14U);
    opt[0] = sizeof(opt);
    if (sceKernelStartModule(var_s2, 0, 0, &sp20, opt) < 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0xEE, temp_v0, &D_000FA4C8);
    }
    modUnlock();
    return var_s2;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA4C8);

int sceKernelStopModule(int, M2C_UNK, M2C_UNK, M2C_UNK *, void *); /* extern */
int sceKernelUnloadModule(int);                     /* extern */
extern unsigned char D_000FA3A4;
extern unsigned char D_000FA3C0;
extern unsigned char D_000FA4C8;

int modUnload(int arg0) {
    int sp20;
    int opt[5];
    M2C_UNK *temp_v0;

    temp_v0 = "modUnload";
    consPrintf("%s : 0x%08x\n", temp_v0, arg0);
    modLock();
    memset(opt, 0, 0x14U);
    opt[0] = sizeof(opt);
    if (sceKernelStopModule(arg0, 0, 0, &sp20, opt) != 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0x10B, temp_v0, "Ret == SCE_KERNEL_ERROR_OK");
    }
    if (sceKernelUnloadModule(arg0) < 0) {
        consPrintf(&D_000FA3A4, &D_000FA3C0, 0x110, temp_v0, &D_000FA4C8);
    }
    modUnlock();
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/mod", D_000FA50C);
