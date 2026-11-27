/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *);           /* extern */
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partSetDrawMat);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partAnimate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/movie", partDraw);
