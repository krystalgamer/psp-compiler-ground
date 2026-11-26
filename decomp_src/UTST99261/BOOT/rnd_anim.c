#include "common.h"
#include "m2c_macros.h"
M2C_UNK clearSearchStrings();                       /* extern */
M2C_UNK searchStrings();                            /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
int checkParentBox(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;
    int var_v0;

    var_a0 = arg0;
    var_v0 = 1;
    if (var_a0 != arg1) {
        var_v0 = 0;
        if (var_a0 != NULL) {
loop_2:
            var_a0 = *var_a0;
            var_v0 = 1;
            if (var_a0 != arg1) {
                if (var_a0 == NULL) {
                    var_v0 = 0;
                } else {
                    goto loop_2;
                }
            }
        }
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_deleteAnimBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_addUpdateWidgetList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_clearUpdateWidgetList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_updateUpdateWidgetList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_updateAnimBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_resetAnimBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_newMarquee);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_updateAnimMarqueeBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", rnd_resetAnimMarqueeBoxnode);

#ifndef NULL
#define NULL ((void *)0)
#endif

void actClearSearchString(void) {
    clearSearchStrings();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void actSearchString(void) {
    searchStrings();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", freeScrollStart);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", freeScroll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", searchDestinationAnchor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", getAncestorLink);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", D_00139028);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", actLinkJumpInner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_anim", actLinkJump);
