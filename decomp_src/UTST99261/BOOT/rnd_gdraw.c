/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct {
    u8 unk0[0x38];
    int unk38;
} RGGEOM;

typedef struct {
    u8 unk0[0x20];
    RGGEOM *geom;
} RGBOX;

int GUI_createContentView();
int GUI_ScrollPane_setVScrollbarMode();
int GUI_ScrollPane_setHScrollbarMode();
int GUI_TextField_getSelectedText();
int GUI_TextArea_getSelectedText();
int GUI_TextArea_setSelection();
int GUI_TextArea_insert();
int GUI_TextArea_selectAll();
int GUI_List_select();
int GUI_List_deselect();
int getStringsExtents();
int strlen();
void rnd_drawRepaintCallback(void);
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


int color2rgb(int *rgb, int c) {
    rgb[0] = ((unsigned int)c >> 16) & 0xFF;
    rgb[1] = (c & 0xFF00) >> 8;
    rgb[2] = c & 0xFF;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void esp_colorValueToRGB(int *rgb, int c) {
    color2rgb(rgb, c);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_drawRepaintCallback(void) {
    rnd_drawRepaint();
}

int rnd_gdrawCreateView(int parent, RGBOX *box) {
    int w;

    w = GUI_createContentView(parent, rnd_drawRepaintCallback, box->geom->unk38);
    if (w == 0) {
        return 0;
    }
    GUI_ScrollPane_setVScrollbarMode(w, 1);
    GUI_ScrollPane_setHScrollbarMode(w, 1);
    return w;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_gdrawGetViewClientSize(void) {
    GUI_ScrollPane_getViewportSize();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateTextline);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextlineExtents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextlineString);

int rnd_gdrawGetTextlineSelectionString(int w, char **out) {
    char *s;
    int n;

    s = (char *)GUI_TextField_getSelectedText(w);
    if (s == NULL) {
        return 0;
    }
    n = strlen(s);
    *out = s;
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateTextbox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextboxExtents);

int rnd_gdrawReplaceTextboxString(int w, char *s, int start, int end) {
    GUI_TextArea_setSelection(w, start, end);
    GUI_TextArea_insert(w, s);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetTextboxString);

void rnd_gdrawSelectTextbox(int w, int on) {
    if (on == 1) {
        GUI_TextArea_selectAll(w);
    } else {
        GUI_TextArea_setSelection(w, 0, 0);
    }
}

int rnd_gdrawGetTextboxSelectionString(int w, char **out) {
    char *s;
    int n;

    s = (char *)GUI_TextArea_getSelectedText(w);
    if (s == NULL) {
        *out = NULL;
        return 0;
    }
    n = strlen(s);
    *out = s;
    return n;
}

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

int rnd_gdrawGetButtonExtents(int a, int b, int c, int *w, int *h) {
    getStringsExtents(a, b, c, w, h);
    *w += 4;
    *h += 4;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreatePulldown);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetPulldownExtents);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawCreateList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetListExtents);

void rnd_gdrawSetListState(int w, int index, int state) {
    if (state == 1) {
        GUI_List_select(w, index);
    } else {
        GUI_List_deselect(w, index);
    }
}

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
