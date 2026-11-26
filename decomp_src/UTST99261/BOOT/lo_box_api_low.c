#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", checkTableHierarchy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createBlockBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createInlineBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createListBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", linkBox);

#ifndef NULL
#define NULL ((void *)0)
#endif
void linkBoxNoTableCheck(void *arg0, void *arg1, void *arg2) {
    if ((arg1 != NULL) && (M2C_FIELD(arg1, void **, 4) == NULL)) {
        M2C_FIELD(arg1, void **, 4) = arg0;
    }
    M2C_FIELD(arg0, void **, 0) = arg1;
    M2C_FIELD(arg0, void **, 8) = arg2;
    if (arg2 != NULL) {
        M2C_FIELD(arg2, void **, 0xC) = arg0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", insLinkBox);

#ifndef NULL
#define NULL ((void *)0)
#endif
void delLinkBox(void *arg0) {
    void **temp_a3;
    void *temp_a1;
    void *temp_a2;
    void *temp_v1;

    temp_a2 = M2C_FIELD(arg0, void **, 0);
    temp_a1 = M2C_FIELD(arg0, void **, 0xC);
    temp_v1 = M2C_FIELD(arg0, void **, 8);
    temp_a3 = M2C_FIELD(arg0, void ***, 4);
    if ((temp_a2 != NULL) && (M2C_FIELD(temp_a2, void **, 4) == arg0)) {
        M2C_FIELD(temp_a2, void **, 4) = temp_a1;
    }
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, void **, 0xC) = temp_a1;
    }
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_a1, void **, 8) = temp_v1;
    }
    if (temp_a3 != NULL) {
        *temp_a3 = temp_a2;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int getChildBox(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int getBrotherBox(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xC);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeBoxPre);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", reinitBodyBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeDrawObject);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeBoxTree);
