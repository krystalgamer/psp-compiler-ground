#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
int mes_navigator_java_enabled(void) {
    return 8;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", mes_navigator_get);

void mes_navigator_mark(void) {
}

void mes_navigator_free(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", mes_navigator_class_init);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", mes_navigator_new);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FABC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/mes_obj_navigator", D_0013FAF8);
