#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int GuigraphicsInit(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int GuigraphicsExit(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guigraphic", GuigraphicsCreate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guigraphic", GuigraphicsClear);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guigraphic", GuigraphicsDelete);
