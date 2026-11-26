/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK rnd_gdrawImageDecode();                     /* extern */
M2C_UNK rnd_gdrawImageDecodeByGifFile();            /* extern */
M2C_UNK rnd_gdrawImageProperty();                   /* extern */
M2C_UNK rnd_gdrawImageDelete();                     /* extern */
M2C_UNK rnd_updateAnimBoxnode();                    /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawEachFrame);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawPaint);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawObject);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawObjectWithArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawScroll);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawRemoveChild);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", drawDelete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", getViewPort);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", getViewClientSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", getViewVirtualSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", setFocus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", setFocusImageMap);

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDecode(void) {
    rnd_gdrawImageDecode();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDecodeByGifFile(void) {
    rnd_gdrawImageDecodeByGifFile();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageProperty(void) {
    rnd_gdrawImageProperty();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDelete(void) {
    rnd_gdrawImageDelete();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void drawAnimation(void) {
    rnd_updateAnimBoxnode();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", startBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", moveBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", deleteBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", addSelectList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", destroySelectList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", delSelectListBySID);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", getSelectListFromGadget);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawAllBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawBoxnode);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *rnd_findParentBoxnode(M2C_UNK *arg0, int arg1) {
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_prevRadioBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawBasicBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawBoxnodeBackground);
