#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int GuipixmapInit(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GuipixmapExit(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guipixmap", GuipixmapCreate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guipixmap", GuipixmapClear);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guipixmap", GuipixmapDelete);
