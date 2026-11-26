/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
int GUI_Component_getParent(int);                   /* extern */
M2C_UNK GUI_ScrollPane_add(int, int);               /* extern */
int GUI_createPanel();                              /* extern */
M2C_UNK GUI_Graphics_freeAnimationGIF(int);         /* extern */
M2C_UNK GUI_Graphics_freePixmap(int);               /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */

M2C_UNK color2rgb();                                /* extern */
M2C_UNK rnd_drawRepaint();                          /* extern */
M2C_UNK GUI_ScrollPane_getViewportSize();           /* extern */
M2C_UNK rnd_updateAnimImageBoxnode();               /* extern */
M2C_UNK rnd_updateAnimTextBoxnode();                /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", color2rgb);

#ifndef NULL
#define NULL ((void *)0)
#endif

void esp_colorValueToRGB(void) {
    color2rgb();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_drawRepaintCallback(void) {
    rnd_drawRepaint();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateView);

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_gdrawGetViewClientSize(void) {
    GUI_ScrollPane_getViewportSize();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateTextline);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextlineExtents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextlineString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextlineSelectionString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateTextbox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextboxExtents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawReplaceTextboxString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextboxString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawSelectTextbox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextboxSelectionString);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateCheckbox);

#ifndef NULL
#define NULL ((void *)0)
#endif
int rnd_gdrawGetCheckboxExtents(int *arg0, int *arg1) {
    *arg0 = 4;
    *arg1 = 4;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateRadiobutton);

#ifndef NULL
#define NULL ((void *)0)
#endif
int rnd_gdrawGetRadiobuttonExtents(int *arg0, int *arg1) {
    *arg0 = 4;
    *arg1 = 4;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetButtonExtents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreatePulldown);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetPulldownExtents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetListExtents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawSetListState);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_drawFrameCallback);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateBorder);

#ifndef NULL
#define NULL ((void *)0)
#endif

int rnd_gdrawCreatePanel(int arg0) {
    int temp_v0;
    int var_v0;

    temp_v0 = GUI_createPanel();
    var_v0 = 0;
    if (temp_v0 != 0) {
        GUI_ScrollPane_add(GUI_Component_getParent(arg0), temp_v0);
        var_v0 = temp_v0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawRectangle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawFillrectangle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawMaskFillrectangle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawDashedHline);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawDashedVline);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawDottedHline);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawDottedVline);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawStrings);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetStringsVisibleLength);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", D_00133564);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImageDecode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImageDecodeByGifFile);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImageProperty);

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_gdrawImageDelete(void *arg0) {
    int temp_a0;

    if (arg0 != NULL) {
        if (M2C_FIELD(arg0, int *, 0) == 2) {
            GUI_Graphics_freeAnimationGIF(M2C_FIELD(arg0, int *, 8));
            M2C_FIELD(arg0, int *, 4) = 0;
        }
        temp_a0 = M2C_FIELD(arg0, int *, 4);
        if (temp_a0 != 0) {
            GUI_Graphics_freePixmap(temp_a0);
            M2C_FIELD(arg0, int *, 4) = 0;
        }
        MEM_free(0, arg0);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImageUpdate);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImageReset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_drawImageBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_updateAnimImageBoxnode);

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_resetAnimImageBoxnode(void) {
    rnd_updateAnimImageBoxnode();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_relayoutWidgets);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_drawRepaint);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_drawTextBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_updateAnimTextBoxnode);

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_resetAnimTextBoxnode(void) {
    rnd_updateAnimTextBoxnode();
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", D_001335E0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", lo_sendHalt);
