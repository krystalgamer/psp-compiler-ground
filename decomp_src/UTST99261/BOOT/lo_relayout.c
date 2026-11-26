/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int getLineHeight(void **);                         /* extern */
extern void *D_00584CD8;
M2C_UNK HST_flushHistoryGarbageList();              /* extern */
void *HST_getHistoryGarbageList();                  /* extern */
M2C_UNK removeSessionSaveData(int);                 /* extern */


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

#ifndef NULL
#define NULL ((void *)0)
#endif

void updateLiFirstLineList(void *arg0) {
    int *temp_v0;

    temp_v0 = getBoxByHTML(M2C_FIELD(arg0, int **, 4), 0x38);
    if (temp_v0 != NULL) {
        if ((M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x20), int *, 4) == 0) && (getLineHeight(M2C_FIELD(arg0, void ***, 0xC)) > 0)) {
            copyBoxList((int) (M2C_FIELD(temp_v0, void **, 0x20) + 4), M2C_FIELD(arg0, void ***, 0xC));
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutAtBody);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutAtBodyOnly);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutByFrameBorderMove);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutFramesetByFrameBorderMove);

#ifndef NULL
#define NULL ((void *)0)
#endif

void initSessionSaveDataList(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x1C);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    D_00584CD8 = temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", freeSessionSaveDataList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", addSessionSaveData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", removeSessionSaveData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", getSessionSaveData);

#ifndef NULL
#define NULL ((void *)0)
#endif

void collectSessionGarbage(int arg0) {
    int temp_a0;
    void *temp_v0;
    void *var_s0;

    temp_v0 = HST_getHistoryGarbageList();
    var_s0 = temp_v0;
    if (temp_v0 != NULL) {
        do {
            temp_a0 = M2C_FIELD(var_s0, int *, 0);
            if (arg0 != temp_a0) {
                removeSessionSaveData(temp_a0);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 4);
        } while (var_s0 != NULL);
    }
    HST_flushHistoryGarbageList();
}
