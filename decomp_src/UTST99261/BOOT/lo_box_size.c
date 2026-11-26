/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "m2c_macros.h"
M2C_UNK box_setTableHeight(void *);                 /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcInLineBoxSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcBlockBoxSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcBodyBoxSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcBlockButtonBoxSize);

#ifndef NULL
#define NULL ((void *)0)
#endif

void calcTableBoxSize(void *arg0, void *arg1) {
    if (!(M2C_FIELD(arg1, unsigned short *, 0x40) & 2)) {
        box_setTableHeight(arg1);
    } else {
        M2C_FIELD(arg1, unsigned short *, 0x40) = (unsigned short) (M2C_FIELD(arg1, unsigned short *, 0x40) & 0xFFFD);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x34) = (int) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x34) + M2C_FIELD(arg1, int *, 0x1C));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcTdBoxSize);

int getPreferredFontSize(BOX *box) {
    int size = box->style->fontSize;
    int d = ui_global->font - 3;
    if (size + d < 0) {
        size = 0;
    } else if (size + d >= 7) {
        size = 6;
    } else {
        size += d;
    }
    return size;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", initTextBoxSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", initImageBoxSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", initButtonBoxSize);

void initCheckBoxSize(BOX *box) {
    int w = ui_global->unk74 * 2;
    int h = w;
    if ((box->style->flags & 3) == 1) {
        w = box->style->width;
    }
    if (((box->style->flags & 0xC) >> 2) == 1) {
        h = box->style->height;
    }
    setBoxSize(box, w, h);
}

void initRadioBoxSize(BOX *box) {
    int w = ui_global->unk74 * 2;
    int h = w;
    if ((box->style->flags & 3) == 1) {
        w = box->style->width;
    }
    if (((box->style->flags & 0xC) >> 2) == 1) {
        h = box->style->height;
    }
    setBoxSize(box, w, h);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", initTextFieldBoxSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", initTextAreaBoxSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", initSelectBoxSize);

#ifndef NULL
#define NULL ((void *)0)
#endif
void setBoxSize(void *arg0, int arg1, int arg2) {
    int temp_a1;
    int temp_a1_2;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    void *temp_a3;

    M2C_FIELD(arg0, int *, 0x18) = arg1;
    temp_a3 = M2C_FIELD(arg0, void **, 0x24);
    temp_v0 = M2C_FIELD(temp_a3, short *, 0x22) + arg1;
    M2C_FIELD(arg0, int *, 0x18) = temp_v0;
    temp_v1 = M2C_FIELD(temp_a3, short *, 0x26) + temp_v0;
    M2C_FIELD(arg0, int *, 0x18) = temp_v1;
    temp_v0_2 = M2C_FIELD(temp_a3, short *, 0x2A) + temp_v1;
    M2C_FIELD(arg0, int *, 0x18) = temp_v0_2;
    temp_v1_2 = M2C_FIELD(temp_a3, short *, 0x2E) + temp_v0_2;
    M2C_FIELD(arg0, int *, 0x18) = temp_v1_2;
    temp_a1 = M2C_FIELD(temp_a3, short *, 0x32) + temp_v1_2;
    M2C_FIELD(arg0, int *, 0x18) = temp_a1;
    M2C_FIELD(arg0, int *, 0x18) = (int) (M2C_FIELD(temp_a3, short *, 0x36) + temp_a1);
    M2C_FIELD(arg0, int *, 0x1C) = arg2;
    temp_v0_3 = M2C_FIELD(temp_a3, short *, 0x20) + arg2;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v0_3;
    temp_v1_3 = M2C_FIELD(temp_a3, short *, 0x24) + temp_v0_3;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v1_3;
    temp_v0_4 = M2C_FIELD(temp_a3, short *, 0x28) + temp_v1_3;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v0_4;
    temp_v1_4 = M2C_FIELD(temp_a3, short *, 0x2C) + temp_v0_4;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v1_4;
    temp_a1_2 = M2C_FIELD(temp_a3, short *, 0x30) + temp_v1_4;
    M2C_FIELD(arg0, int *, 0x1C) = temp_a1_2;
    M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(temp_a3, short *, 0x34) + temp_a1_2);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcBoxSize);
