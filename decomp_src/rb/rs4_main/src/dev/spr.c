/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
int _memAlloc(M2C_UNK, M2C_UNK *, M2C_UNK);         /* extern */
extern signed char D_000FA6F4;
extern unsigned char D_000FA6F8;
extern signed char D_000FA708;
extern unsigned char D_000FA724;
extern unsigned char D_000FA734;
extern int SprRsv;
extern int SprWorkEnd;
extern int SprWorkTop;
extern int pSprBuf;
M2C_UNK _memFree(int, M2C_UNK *, M2C_UNK);          /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *fmt, ...);
int sprInit(void) {
    M2C_UNK *temp_v0;
    int temp_v0_2;

    temp_v0 = "sprInit";
    consPrintf(&D_000FA6F4, temp_v0);
    if (pSprBuf != 0) {
        consPrintf(&D_000FA708, &D_000FA724, 0x26, temp_v0, &D_000FA6F8);
    }
    temp_v0_2 = _memAlloc(0x4000, &D_000FA724, 0x28);
    pSprBuf = temp_v0_2;
    if (temp_v0_2 == 0) {
        consPrintf(&D_000FA708, &D_000FA724, 0x29, temp_v0, &D_000FA734);
    }
    SprWorkEnd = pSprBuf + 0x4000;
    SprRsv = 0xFF;
    SprWorkTop = pSprBuf;
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA6F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA6F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA708);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA724);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA734);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sprTerm(void) {
    M2C_UNK *temp_s0;

    temp_s0 = "sprTerm";
    consPrintf(&D_000FA6F4, temp_s0);
    if (pSprBuf == 0) {
        consPrintf(&D_000FA708, &D_000FA724, 0x3A, temp_s0, &D_000FA734);
    }
    _memFree(pSprBuf, &D_000FA724, 0x3C);
    pSprBuf = 0;
    SprRsv = 0;
    return 1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", sprCall);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", sprFree);

int sprGetSize(void) {
    return 0x800;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA7B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/spr", D_000FA7C0);
