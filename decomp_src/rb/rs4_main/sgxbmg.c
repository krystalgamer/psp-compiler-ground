#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxBmgAllocEx(M2C_UNK, int, int, int);      /* extern */
extern int D_0011FC34;
M2C_UNK sgxListEnumID(M2C_UNK *, M2C_UNK);          /* extern */
extern unsigned char D_0011FC20;
extern unsigned char D_0011FC10;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", D_00109F94);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", SlotGetAt_7A70C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgInit);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgAllocEx);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxBmgAlloc(int arg0, int arg1, int arg2) {
    sgxBmgAllocEx(-1, arg0, arg1, arg2);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgAllocSub);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgAlignBuf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetBuf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetSize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetRefCount);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgIncBuf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgDecBuf);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetHead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetTail);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetHeadOfs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetTailOfs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetLinearFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetLeft);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetLinearLeft);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgGetLinearLeftOfs);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", D_0010A10C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgWrite);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgRead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgWriteTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgIsFinished);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", sgxBmgSetLowBufCallback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxbmg", CheckLowBuf);

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxBmgGetMaxSlotCount(void) {
    return D_0011FC34;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxBmgGetFreeSlotCount(void) {
    sgxListEnumID(&D_0011FC20, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void sgxBmgEnumUseID(int arg0) {
    sgxListEnumID(&D_0011FC10, arg0);
}
