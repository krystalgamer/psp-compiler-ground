#include "common.h"
#include "m2c_macros.h"
M2C_UNK GuiwidgetAllOpening();                      /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guiwidget", GuiwidgetInit);

#ifndef NULL
#define NULL ((void *)0)
#endif

int GuiwidgetExit(void) {
    GuiwidgetAllOpening();
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guiwidget", GuiwidgetCreate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guiwidget", GuiwidgetClear);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guiwidget", _guiwidgetPurge);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guiwidget", _GuiwidgetDelete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guiwidget", GuiwidgetDelete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/guiwidget", GuiwidgetAllOpening);
