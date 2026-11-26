/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
void *HST_getHeadHistoryNode();                     /* extern */



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

#ifndef NULL
#define NULL ((void *)0)
#endif

int getRootBox(void) {
    int var_v1;
    void *temp_v0;

    temp_v0 = HST_getHeadHistoryNode();
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, int *, 0x6C);
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void getBodyBox(int *arg0) {
    getBoxByContent(arg0, 1);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getListBox);

#ifndef NULL
#define NULL ((void *)0)
#endif
void getFramesetBox(int *arg0) {
    getBoxByContent(arg0, 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void getTableBox(int *arg0) {
    getBoxByContent(arg0, 4);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getTrBox);

#ifndef NULL
#define NULL ((void *)0)
#endif
void getTdBox(int **arg0) {
    getBoxByContent(*arg0, 6);
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int getContainingBlockWidth(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x24);
    return (((((M2C_FIELD(arg0, int *, 0x18) - M2C_FIELD(temp_a1, short *, 0x26)) - M2C_FIELD(temp_a1, short *, 0x36)) - M2C_FIELD(temp_a1, short *, 0x2E)) - M2C_FIELD(temp_a1, short *, 0x2A)) - M2C_FIELD(temp_a1, short *, 0x32)) - M2C_FIELD(temp_a1, short *, 0x22);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getPageRegion);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", calcBoxMinWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", calcBoxMaxWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", getFixedHeightBox);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_height);
