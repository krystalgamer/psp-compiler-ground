#include "common.h"
#include "m2c_macros.h"
extern int _iZwindDizF;


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_setFont);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_setColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_getColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_getParent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_remove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_setLocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_getLocation);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_setSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_getSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_getPrefSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_getMinimumSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_requestFocus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_setEnabled);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_setVisible);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_update);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", GUI_Component_setFocusColor);

#ifndef NULL
#define NULL ((void *)0)
#endif

void zWindSetDiz(int arg0) {
    _iZwindDizF = arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", make_dither_matrix);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", dizInit);

#ifndef NULL
#define NULL ((void *)0)
#endif
int MAX(int arg0, int arg1) {
    return __builtin_allegrex_max(arg0, arg1);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int MIN(int arg0, int arg1) {
    return __builtin_allegrex_min(arg0, arg1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", dizCg);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gui_Component", D_00130A20);
