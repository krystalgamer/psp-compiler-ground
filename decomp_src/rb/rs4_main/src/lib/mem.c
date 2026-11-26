/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
void *_memAlloc();                                  /* extern */
extern int MemBreak;


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memUnlock);

#ifndef NULL
#define NULL ((void *)0)
#endif
int memGetCntxSize(void) {
    return 0x40;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int memGetAlignSize(void) {
    return 0x40;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memLog);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memAlloc);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FADE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FAE0C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memFree);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memRealloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memReallocMBL);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void *_memAllocZero(unsigned int arg0) {
    void *temp_v0;

    temp_v0 = _memAlloc();
    if (temp_v0 != NULL) {
        memset(temp_v0, 0, arg0);
    }
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memAllocMBL);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void *_memAllocZeroMBL(unsigned int arg0) {
    void *temp_v0;

    temp_v0 = _memAlloc();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, signed char *, -0x2F) = 1;
        memset(temp_v0, 0, arg0);
    }
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", _memDiag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memDiag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memSnap);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB0D8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB0F0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memClean);

#ifndef NULL
#define NULL ((void *)0)
#endif

void memBreak(int arg0) {
    MemBreak = arg0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", memList);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB180);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB19C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB1C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB1D0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvHeadAlive);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", D_000FB210);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvNextAlive);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvCall);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvKill);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/mem", rsvFree);
