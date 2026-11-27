/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
M2C_UNK partCusConvExt(int, unsigned short);                   /* extern */
int sceKernelGetGPI();                              /* extern */
extern unsigned char D_000FDD64;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movPutCB);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movProc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeVideo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDecodeAudio);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", movAudio);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDD64);

#ifndef NULL
#define NULL ((void *)0)
#endif

void partAsm(void *arg0, int arg1) {
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FDD64, "partAsm");
    }
    partCusConvExt(arg1, M2C_FIELD(arg0, unsigned short *, 0x1A));
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int partRelease(void) {
    if (sceKernelGetGPI() & 1) {
        consPrintf(&D_000FDD64, "partRelease");
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDD7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDD8C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDBC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", D_000FDDCC);

#ifndef NULL
#define NULL ((void *)0)
#endif
extern unsigned char D_000FDD7C;
extern unsigned char D_000FDD8C;
extern unsigned char D_000FDDB4;

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partDraw);
