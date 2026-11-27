/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
M2C_UNK partCusConvExt(int, unsigned short);                   /* extern */
int sceKernelGetGPI();                              /* extern */
extern unsigned char D_000FDD64;
extern unsigned char D_000FDD7C;
extern unsigned char D_000FDD8C;
extern unsigned char D_000FDDB4;

M2C_UNK _memFree(void **, M2C_UNK *, M2C_UNK);      /* extern */
M2C_UNK elmTerm(void *);                            /* extern */
M2C_UNK partFreeEnvCntx(int);extern int g_nInst;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", D_000FDD64);

void partAsm(void *arg0, int arg1) {
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FDD64, "partAsm");
    }
    partCusConvExt(arg1, M2C_FIELD(arg0, unsigned short *, 0x1A));
}

int partRelease(void) {
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FDD64, "partRelease");
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", D_000FDD7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", D_000FDD8C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", partInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", D_000FDDB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", D_000FDDBC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", D_000FDDC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", D_000FDDCC);

int partSetDrawMat(void *arg0, int arg1) {
    if (arg0 == NULL) {
        consPrintf(&D_000FDD8C, &D_000FDD7C, 0x5D, "partSetDrawMat", &D_000FDDB4);
    }
    if (arg1 == 0) {
        consPrintf(&D_000FDD8C, &D_000FDD7C, 0x5E, "partSetDrawMat", "pMat");
    }
    M2C_FIELD(arg0, int *, 0x18) = arg1;
    return 1;
}

                       /* extern */

int partTerm(void **arg0) {
    int var_s0;
    int var_s0_2;
    void **temp_v1;
    void **temp_v1_2;
    void **var_s1;
    void **var_s1_2;
    void *temp_v0;
    void *temp_v0_2;

    partFreeEmitCntx(M2C_FIELD(arg0, void **, 8));
    partFreeEnvCntx(M2C_FIELD(arg0, int *, 4));
    temp_v1 = M2C_FIELD(arg0, void ***, 0xC);
    if (temp_v1 != NULL) {
        var_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), int *, 4);
        var_s1 = temp_v1;
        if (var_s0 != 0) {
            do {
                temp_v0 = *var_s1;
                var_s0 -= 1;
                var_s1 += 1;
                if (temp_v0 != NULL) {
                    partFree2DCntx(temp_v0);
                }
            } while (var_s0 != 0);
        }
        _memFree(M2C_FIELD(arg0, void ***, 0xC), &D_000FDD7C, 0x75);
    }
    temp_v1_2 = M2C_FIELD(arg0, void ***, 0x10);
    if (temp_v1_2 != NULL) {
        var_s0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x14), int *, 4);
        var_s1_2 = temp_v1_2;
        if (var_s0_2 != 0) {
            do {
                temp_v0_2 = *var_s1_2;
                var_s0_2 -= 1;
                var_s1_2 += 1;
                if (temp_v0_2 != NULL) {
                    partFree3DCntx(temp_v0_2);
                }
            } while (var_s0_2 != 0);
        }
        _memFree(M2C_FIELD(arg0, void ***, 0x10), &D_000FDD7C, 0x7E);
    }
    elmTerm(M2C_FIELD(arg0, void **, 0x14));
    _memFree(arg0, &D_000FDD7C, 0x83);
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", partAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", partDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", _partDrawPart2D);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/part", _partDrawPart3D);

void partSetInst(int arg0) {
    g_nInst = arg0;
}
