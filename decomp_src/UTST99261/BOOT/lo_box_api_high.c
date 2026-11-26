/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *getBoxByContent(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;

    var_a0 = arg0;
    if ((var_a0 != NULL) && (M2C_FIELD(var_a0, short *, 0x38) != arg1)) {
loop_2:
        var_a0 = *var_a0;
        if (var_a0 != NULL) {
            if (M2C_FIELD(var_a0, short *, 0x38) != arg1) {
                goto loop_2;
            }
        }
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getRootBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getBodyBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getListBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getFramesetBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getTableBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getTrBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getTdBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getParentBlockBox);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *getBoxByHTML(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;

    var_a0 = arg0;
    if ((var_a0 != NULL) && (M2C_FIELD(var_a0, short *, 0x3A) != arg1)) {
loop_2:
        var_a0 = *var_a0;
        if (var_a0 != NULL) {
            if (M2C_FIELD(var_a0, short *, 0x3A) != arg1) {
                goto loop_2;
            }
        }
    }
    return var_a0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getBoxByHTML_intd);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getBodyAbsolutePos);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", checkBoxValidity);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getContainingBlockWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getPageRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", calcBoxMinWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", calcBoxMaxWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getFixedHeightBox);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_height);
