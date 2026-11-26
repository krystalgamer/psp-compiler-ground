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
int GUI_Graphics_drawPixmap();
int strlen();
int GUI_TextField_getText();
int GUI_TextArea_getText();
void *memcpy(void *d, const void *s, unsigned int n);
char *strncpy(char *d, const char *s, unsigned int n);
int GUI_Graphics_setColor();
int GUI_Graphics_drawRect();
int GUI_Graphics_fillRect();
int GUI_Graphics_getPixmapSize();
int GUI_Graphics_getAnimationGIFFrameProperty();
int GUI_Graphics_getAnimationGIFNextFrame();
int GUI_Graphics_getBrokenLinePattern();
int GUI_Graphics_drawTiledPixmap();

extern char D_00133564[];  /* "x" */

typedef struct {
    int x;
    int y;
} RGPOINT;

typedef struct {
    int type;
    int pixmap;
    int anim;
    int unkC;
    int unk10;
    int x;
    int y;
    int unk1C;
} RGIMAGE;
void rnd_drawRepaintCallback(void);
int GUI_Component_getParent(int);                   /* extern */
M2C_UNK GUI_ScrollPane_add(int, int);               /* extern */
int GUI_createPanel();                              /* extern */
M2C_UNK GUI_Graphics_freeAnimationGIF(int);         /* extern */
M2C_UNK GUI_Graphics_freePixmap(int);               /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */

int GUI_createCheckbox();
int GUI_createList();
int GUI_createChoice();
int GUI_createButton();
int GUI_createRadioboxGroup();
int GUI_RadioButton_getGroup();
int GUI_createRadiobox();
int GUI_Component_remove();
int GUI_createFrameBorder();
int GUI_Component_setColor();
int GUI_Component_setFocusColor();
int GUI_Component_setEnabled();
int GUI_Component_setFont();
int GUI_Component_getSize();
int GUI_Component_setLocation();
int GUI_Component_setSize();
int GUI_Component_setVisible();
int GUI_Graphics_getMaskPattern();
void rnd_drawFrameCallback();
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

int rnd_gdrawGetTextlineExtents(int font, int n, int *w, int *h) {
    getStringsExtents(font, D_00133564, 1, w, h);
    *w = n * *w + 4;
    *h += 4;
    return 0;
}

int rnd_gdrawGetTextlineString(int w, char *buf, int size) {
    char *s;
    int n;

    s = (char *)GUI_TextField_getText(w);
    if (s == NULL) {
        return 0;
    }
    n = strlen(s);
    if (buf != NULL) {
        n = n < size ? n : size;
        memcpy(buf, s, n);
        buf[n] = 0;
    }
    MEM_free(0, s);
    return n;
}

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

int rnd_gdrawGetTextboxExtents(int font, int rows, int cols, int *w, int *h) {
    getStringsExtents(font, D_00133564, 1, w, h);
    *w = cols * *w + 4;
    *h = rows * *h + 4;
    return 0;
}

int rnd_gdrawReplaceTextboxString(int w, char *s, int start, int end) {
    GUI_TextArea_setSelection(w, start, end);
    GUI_TextArea_insert(w, s);
    return 0;
}

int rnd_gdrawGetTextboxString(int w, char *buf, int size) {
    char *s;
    int n;

    s = (char *)GUI_TextArea_getText(w);
    if (s == NULL) {
        if (size > 0) {
            *buf = 0;
        }
        return 0;
    }
    n = strlen(s);
    if (buf != NULL) {
        n = size < n ? size : n;
        strncpy(buf, s, n);
        buf[n] = 0;
    }
    MEM_free(0, s);
    return n;
}

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

int rnd_gdrawCreateCheckbox(int parent, int fgc, int bgc, int fcc, int disabled) {
    int fg[3];
    int bg[3];
    int fc[3];
    int w;

    w = GUI_createCheckbox(parent, 0);
    if (w == 0) {
        return 0;
    }
    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_setColor(w, fg, bg);
    color2rgb(fc, fcc);
    GUI_Component_setFocusColor(w, fc);
    GUI_ScrollPane_add(GUI_Component_getParent(parent), w);
    if (disabled) {
        GUI_Component_setEnabled(w, 0);
    }
    return w;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int rnd_gdrawGetCheckboxExtents(int *arg0, int *arg1) {
    *arg0 = 4;
    *arg1 = 4;
    return 0;
}

int rnd_gdrawCreateRadiobutton(int parent, int group, int fgc, int bgc, int fcc, int disabled) {
    int fg[3];
    int bg[3];
    int fc[3];
    int w;
    int g;

    if (group == 0) {
        g = GUI_createRadioboxGroup(parent);
    } else {
        g = GUI_RadioButton_getGroup(group);
    }
    if (g == 0) {
        return 0;
    }
    w = GUI_createRadiobox(g, 0);
    if (w == 0) {
        GUI_Component_remove(g);
        return 0;
    }
    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_setColor(w, fg, bg);
    color2rgb(fc, fcc);
    GUI_Component_setFocusColor(w, fc);
    GUI_ScrollPane_add(GUI_Component_getParent(parent), w);
    if (disabled) {
        GUI_Component_setEnabled(w, 0);
    }
    return w;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int rnd_gdrawGetRadiobuttonExtents(int *arg0, int *arg1) {
    *arg0 = 4;
    *arg1 = 4;
    return 0;
}

int rnd_gdrawCreateButton(int parent, int fgc, int bgc, int fcc, int font, int label, int disabled) {
    int fg[3];
    int bg[3];
    int fc[3];
    int w;
    int sp;

    sp = GUI_Component_getParent(parent);
    w = GUI_createButton(parent, label, 0, 0);
    if (w == 0) {
        return 0;
    }
    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_setColor(w, fg, bg);
    color2rgb(fc, fcc);
    GUI_Component_setFocusColor(w, fc);
    if (disabled) {
        GUI_Component_setEnabled(w, 0);
    }
    GUI_Component_setFont(w, font);
    GUI_ScrollPane_add(sp, w);
    return w;
}

int rnd_gdrawGetButtonExtents(int a, int b, int c, int *w, int *h) {
    getStringsExtents(a, b, c, w, h);
    *w += 4;
    *h += 4;
    return 0;
}

int rnd_gdrawCreatePulldown(int parent, int fgc, int bgc, int fcc, int font, int disabled) {
    int fg[3];
    int bg[3];
    int fc[3];
    int w;
    int sp;

    sp = GUI_Component_getParent(parent);
    w = GUI_createChoice(parent);
    if (w == 0) {
        return 0;
    }
    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_setColor(w, fg, bg);
    color2rgb(fc, fcc);
    GUI_Component_setFocusColor(w, fc);
    GUI_Component_setFont(w, font);
    if (disabled) {
        GUI_Component_setEnabled(w, 0);
    }
    GUI_ScrollPane_add(sp, w);
    return w;
}

int rnd_gdrawGetPulldownExtents(int font, char *s, int n2, int *w, int *h) {
    int n;

    n = strlen(s);
    if (n == 0) {
        getStringsExtents(font, D_00133564, 1, w, h);
    } else {
        getStringsExtents(font, s, n, w, h);
    }
    *w = n2 * *w + 26;
    *h += 4;
    return 0;
}

int rnd_gdrawCreateList(int parent, int fgc, int bgc, int fcc, int font, int multi, int disabled) {
    int fg[3];
    int bg[3];
    int fc[3];
    int w;

    w = GUI_createList(parent, multi != 0);
    if (w == 0) {
        return 0;
    }
    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_setColor(w, fg, bg);
    color2rgb(fc, fcc);
    GUI_Component_setFocusColor(w, fc);
    GUI_ScrollPane_add(GUI_Component_getParent(parent), w);
    GUI_Component_setFont(w, font);
    if (disabled) {
        GUI_Component_setEnabled(w, 0);
    }
    return w;
}

int rnd_gdrawGetListExtents(int font, char *s, int rows, int *w, int *h) {
    int n;

    n = strlen(s);
    if (n == 0) {
        getStringsExtents(font, D_00133564, 1, w, h);
    } else {
        getStringsExtents(font, s, n, w, h);
    }
    *w += 20;
    *h = rows * *h + 4;
    return 0;
}

void rnd_gdrawSetListState(int w, int index, int state) {
    if (state == 1) {
        GUI_List_select(w, index);
    } else {
        GUI_List_deselect(w, index);
    }
}

void rnd_drawFrameCallback(int w, int g, int fgc, int bgc) {
    int fg[3];
    int bg[3];
    int wd;
    int h;
    int p;

    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_getSize(w, &wd, &h);
    p = GUI_Graphics_getMaskPattern(fg, bg);
    if (p != 0) {
        GUI_Graphics_drawTiledPixmap(g, p, 0, 0, wd, h, 0, 0);
        GUI_Graphics_freePixmap(p);
    }
}

int rnd_gdrawCreateBorder(int parent, int x, int y, int w, int h, int fgc, int bgc, int visible) {
    int b;

    b = GUI_createFrameBorder(parent, rnd_drawFrameCallback, fgc, bgc);
    if (b == 0) {
        return 0;
    }
    GUI_Component_setLocation(b, x, y);
    GUI_Component_setSize(b, w, h);
    if (visible == 1) {
        GUI_Component_setVisible(b);
    }
    return b;
}

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

void rnd_gdrawRectangle(int g, int color, int x, int y, int w, int h) {
    int rgb[3];

    color2rgb(rgb, color);
    GUI_Graphics_setColor(g, rgb);
    GUI_Graphics_drawRect(g, x, y, w, h);
}

void rnd_gdrawFillrectangle(int g, int color, int x, int y, int w, int h) {
    int rgb[3];

    color2rgb(rgb, color);
    GUI_Graphics_setColor(g, rgb);
    GUI_Graphics_fillRect(g, x, y, w, h);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawMaskFillrectangle);

void rnd_gdrawImage(int g, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int pixmap) {
    GUI_Graphics_drawPixmap(g, pixmap, a1, a2, a3, a4, a5, a6, a7, a8);
}

void rnd_gdrawDashedHline(int g, int color, int x, int y, int w, int h) {
    int rgb[3];
    int p;

    color2rgb(rgb, color);
    p = GUI_Graphics_getBrokenLinePattern(rgb, 16, 1, 8, 1);
    if (p != 0) {
        GUI_Graphics_drawTiledPixmap(g, p, x, y, w, h, 0, 0);
        GUI_Graphics_freePixmap(p);
    }
}

void rnd_gdrawDashedVline(int g, int color, int x, int y, int w, int h) {
    int rgb[3];
    int p;

    color2rgb(rgb, color);
    p = GUI_Graphics_getBrokenLinePattern(rgb, 1, 16, 1, 8);
    if (p != 0) {
        GUI_Graphics_drawTiledPixmap(g, p, x, y, w, h, 0, 0);
        GUI_Graphics_freePixmap(p);
    }
}

void rnd_gdrawDottedHline(int g, int color, int x, int y, int w, int h) {
    int rgb[3];
    int p;

    color2rgb(rgb, color);
    p = GUI_Graphics_getBrokenLinePattern(rgb, 8, 1, 4, 1);
    if (p != 0) {
        GUI_Graphics_drawTiledPixmap(g, p, x, y, w, h, 0, 0);
        GUI_Graphics_freePixmap(p);
    }
}

void rnd_gdrawDottedVline(int g, int color, int x, int y, int w, int h) {
    int rgb[3];
    int p;

    color2rgb(rgb, color);
    p = GUI_Graphics_getBrokenLinePattern(rgb, 1, 8, 1, 4);
    if (p != 0) {
        GUI_Graphics_drawTiledPixmap(g, p, x, y, w, h, 0, 0);
        GUI_Graphics_freePixmap(p);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawStrings);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawGetStringsVisibleLength);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", D_00133564);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImageDecode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_gdrawImageDecodeByGifFile);

int rnd_gdrawImageProperty(RGIMAGE *img, int *w, int *h) {
    int a;
    int b;
    int c;

    if (img == NULL) {
        return 0;
    }
    if (img->type != 2) {
        GUI_Graphics_getPixmapSize(img->pixmap, w, h);
    } else {
        GUI_Graphics_getAnimationGIFFrameProperty(img->anim, &a, &b, w, h, &c);
    }
    return img->type == 2;
}

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
