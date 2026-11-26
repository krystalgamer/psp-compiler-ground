/* cflags: -O1 */
#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", restoreSpaceText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", terminateBlockBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", terminateLiBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_body);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_body2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_frameset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_frameborder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutProc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutProcAfter);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutProcBodyOnly);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutBoxTreeLoop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutBoxTreeLoopBodyOnly);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", resizeTextSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", resizeImageSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", resizeButtonSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", resizeTextFieldSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", resizeSelectSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", updateLiFirstLineList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutAtBody);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutAtBodyOnly);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutByFrameBorderMove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutFramesetByFrameBorderMove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", initSessionSaveDataList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", freeSessionSaveDataList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", addSessionSaveData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", removeSessionSaveData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", getSessionSaveData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", collectSessionGarbage);
