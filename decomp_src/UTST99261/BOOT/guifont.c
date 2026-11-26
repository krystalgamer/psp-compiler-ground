#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int GuifontInit(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GuifontExit(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guifont", GuifontCreate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guifont", GuifontCreateOne);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/guifont", D_001304E0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guifont", GuifontClear);

#ifndef NULL
#define NULL ((void *)0)
#endif
int GuifontDelete(void) {
    return 1;
}
