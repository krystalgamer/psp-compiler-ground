#include "common.h"
#include "m2c_macros.h"
M2C_UNK drawFrameBorderLoop();                      /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", newBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", deleteBuffer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", insertBuffer_87F0C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", splitString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", sumInputSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", insertCalcSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", countSizeType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", DetFrameSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getLastFrameBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getFramenum);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", initFrameSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", reinitFrameSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getFrameSizeFromFramesetBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", setFrameSizeToFramesetBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getMyColFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getMyRowFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", initFrameBorderPosition_hfull);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", initFrameBorderPosition_vfull);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391E0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorderBox_create);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorderBox_hfull);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorderBox_vfull);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorder_frameset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", drawFrameBorderLoop);

#ifndef NULL
#define NULL ((void *)0)
#endif

void drawFrameBorder(void) {
    drawFrameBorderLoop();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", updateParentFrameset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", moveFrameBorderByVertical);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", moveFrameBorderByHorizontal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", adjustMoveFrameBorderValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", moveFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", isLoadedAllChild);
