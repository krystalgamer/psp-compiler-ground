#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", newRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", freeRegionList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", insertRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", addRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", removeRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", overlayRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_createPageRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_destroyPageRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_resetPageRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_addFloat);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_getHorizontalArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_getVerticalPosition);

#ifndef NULL
#define NULL ((void *)0)
#endif
int lfm_getHeight(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", getNextTerminalFrame);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", setFocusBoxnode);
