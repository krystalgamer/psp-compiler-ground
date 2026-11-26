/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK taskDefaultMsg();                           /* extern */


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumCalcKinds);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumCalcKindsContainLostCard);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_00103854);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_00103870);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumGetCardDupBySaveID);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_001038A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", D_001038B0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumGetCardDup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumCalcCardNumBySaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumCalcCardNum);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumClearNewFlagBySaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumClearNewFlag);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumTouchCardBySaveID);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumTouchCard);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/salbum", salbumGetAll);

#ifndef NULL
#define NULL ((void *)0)
#endif

void menuSaveTask(void) {
    taskDefaultMsg();
}
