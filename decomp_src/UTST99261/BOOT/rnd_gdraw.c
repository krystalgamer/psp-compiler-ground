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
void getStringsExtents();
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
void GUI_Graphics_getAnimationGIFFrameProperty();
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
void GUI_Graphics_freeAnimationGIF(int);         /* extern */
void GUI_Graphics_freePixmap(int);               /* extern */
void MEM_free(M2C_UNK, void *);                  /* extern */

int GUI_createCheckbox();
int GUI_createList();
int GUI_Graphics_setFont();
int GUI_Graphics_getStringSize();
int GUI_Graphics_drawString();
int FIO_fopen();
int FIO_fseek();
int FIO_ftell();
int FIO_fread();
int FIO_fclose();
int GUI_Graphics_getImage();
int OS_clock_gettime();
void *MEM_malloc();
typedef struct {
    int sec;
    int nsec;
} RTIME;
int GUI_createTextField();
int GUI_createTextArea();
int GUI_TextField_setText();
int GUI_TextArea_setText();
int GUI_TextField_setEchoChar();
int GUI_TextField_setEditable();
int GUI_TextArea_setEditable();
int GUI_TextField_setMaxlength();
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
void rnd_drawRepaint();
extern void *gESPRIT_LO_GLOBAL_NDA;
int GUI_Graphics_createPixmap();
int GUI_Graphics_getGraphics();
int GUI_Graphics_freeGraphics();
int rnd_drawAllBoxnode();
void lo_sendHalt(void);
typedef struct {
    u8 unk0[0x6C];
    void *body;                 /* 0x6C */
} RHIST;
RHIST *HST_searchSessionIDHistoryNode(int id);
typedef struct {
    int x;
    int y;
    int w;
    int h;
} RRECT;
M2C_UNK GUI_ScrollPane_getViewportSize();           /* extern */
int rnd_updateAnimImageBoxnode();
int rnd_updateAnimTextBoxnode();
typedef struct {
    u8 unk0[0x6C];
    u8 flags;                   /* 0x6C */
} RBSTYLE;
typedef struct {
    RGIMAGE *img;
} RBSUB;
typedef struct RBN {
    struct RBN *next;
    u8 unk4[0xC];
    int x;                      /* 0x10 */
    int y;
    int w;
    int h;
    RBSUB *sub;                 /* 0x20 */
    RBSTYLE *style;             /* 0x24 */
    int unk28;
    int widget;                 /* 0x2C */
} RBN;
RBN *rnd_findParentBoxnode(RBN *n, int type);
void rnd_gdrawGetViewClientSize();
int GUI_ScrollPane_getScrollPosition();


int GUI_Graphics_getImageProperty();
int GUI_Graphics_createAnimationGIF();
typedef struct DIBSTYLE { u8 pad0[0x20]; s16 mt, mr, mb, ml, bt, br, bb, bl, pt, pr, pb, pl; u8 pad38[0x1C]; int color; u8 pad58[8]; int bg; int font; u8 pad68[5]; s8 mask; } DIBSTYLE;
#define DS ((DIBSTYLE *)box->style)
#define DSUB(t, o) M2C_FIELD(box->sub, t, o)
typedef struct { int f0; int x; int y; int w; int h; } DIBRECT;
extern const int e_icon_image_width;
extern const int e_icon_image_height;
extern RGIMAGE *D_00584CAC;
void rnd_drawBasicBoxnode();
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

void rnd_gdrawGetViewClientSize() {
    GUI_ScrollPane_getViewportSize();
}

int rnd_gdrawCreateTextline(int parent, int fgc, int bgc, int fcc, int font, int text, int password, int readonly,
                            int disabled, int maxlen) {
    int fg[3];
    int bg[3];
    int fc[3];
    int w;
    int sp;

    w = GUI_createTextField(parent);
    if (w == 0) {
        return 0;
    }
    sp = GUI_Component_getParent(parent);
    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_setColor(w, fg, bg);
    color2rgb(fc, fcc);
    GUI_Component_setFocusColor(w, fc);
    GUI_TextField_setText(w, text);
    GUI_Component_setFont(w, font);
    if (password) {
        GUI_TextField_setEchoChar(w);
    }
    if (disabled) {
        GUI_Component_setEnabled(w, 0);
    }
    if (readonly) {
        GUI_TextField_setEditable(w, 0);
    }
    if (maxlen >= 0) {
        GUI_TextField_setMaxlength(w, maxlen);
    }
    GUI_ScrollPane_add(sp, w);
    return w;
}

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

int rnd_gdrawCreateTextbox(int parent, int fgc, int bgc, int fcc, int font, int text, int readonly, int disabled) {
    int fg[3];
    int bg[3];
    int fc[3];
    int w;

    w = GUI_createTextArea(parent);
    if (w == 0) {
        return 0;
    }
    color2rgb(fg, fgc);
    color2rgb(bg, bgc);
    GUI_Component_setColor(w, fg, bg);
    color2rgb(fc, fcc);
    GUI_Component_setFocusColor(w, fc);
    GUI_ScrollPane_add(GUI_Component_getParent(parent), w);
    GUI_TextArea_setText(w, text);
    GUI_Component_setFont(w, font);
    if (disabled) {
        GUI_Component_setEnabled(w, 0);
    }
    if (readonly) {
        GUI_TextArea_setEditable(w, 0);
    }
    return w;
}

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

void rnd_gdrawMaskFillrectangle(int g, int color, int x, int y, int w, int h) {
    int c1[3];
    int c2[3];
    int p;
    int b;

    b = 3;
    color2rgb(c1, 0xFFFFFF);
    color2rgb(c2, color);
    p = GUI_Graphics_getMaskPattern(c1, c2);
    if (p == 0) {
        return;
    }
    if (w < 3 || h < 3) {
        b = w < h ? w : h;
    }
    GUI_Graphics_drawTiledPixmap(g, p, x, y, b, h, 0, 0);
    GUI_Graphics_drawTiledPixmap(g, p, x + w - b, y, b, h, 0, 0);
    GUI_Graphics_drawTiledPixmap(g, p, x, y, w, b, 0, 0);
    GUI_Graphics_drawTiledPixmap(g, p, x, y + h - b, w, b, 0, 0);
    GUI_Graphics_freePixmap(p);
}

void rnd_gdrawImage(int g, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int pixmap, int type) {
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

int rnd_gdrawStrings(int g, int font, int color, int x, int y, char *str, int len, int deco) {
    int rgb[3];
    int w;
    int h;

    if (len == 0) {
        return 0;
    }
    color2rgb(rgb, color);
    GUI_Graphics_setColor(g, rgb);
    GUI_Graphics_setFont(g, font);
    GUI_Graphics_getStringSize(font, str, len, &w, &h);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        len--;
    }
    GUI_Graphics_drawString(g, str, len, x, y);
    if (deco & 1) {
        GUI_Graphics_fillRect(g, x, y, w, 1);
    }
    if (deco & 2) {
        GUI_Graphics_fillRect(g, x, y + h, w, 1);
    }
    if (deco & 4) {
        GUI_Graphics_fillRect(g, x, y + h / 2, w, 1);
    }
    return w;
}

int rnd_gdrawGetStringsVisibleLength(int font, char *str, int len, int maxw, int limit, int *outw)
{
    int w;
    int h;
    char *p;
    char *start;
    char *prev;
    int total;
    int width;
    int n;
    unsigned short c;

    p = str;
    start = str;
    width = maxw;
    total = 0;
    w = 0;
    while (len > 0) {
        prev = p;
        if (*p >= 0) {
            c = *p;
            p++;
            len--;
        } else if (((*p & 0xE0) == 0xC0) & (len >= 2)) {
            c = (*p & 0x1F) << 6;
            p++;
            c += *p & 0x3F;
            p++;
            len -= 2;
        } else if (((*p & 0xF0) == 0xE0) & (len >= 3)) {
            c = (*p & 0xF) << 12;
            p++;
            c += (*p & 0x3F) << 6;
            p++;
            c += *p & 0x3F;
            p++;
            len -= 3;
        } else
            break;
        if (c == ' ' || c == '-' || (c >= 0x4E00 && c <= 0x9FAF) || (c >= 0x31F0 && c <= 0x4DBF)
            || (c >= 0xAC00 && c <= 0xD7AF) || (c >= 0x1100 && c <= 0x11FF) || (c >= 0x2E80 && c <= 0x31BF)
            || (c >= 0xF900 && c <= 0xFAFF) || (c >= 0xFE30 && c <= 0xFE4F) || (c >= 0xFF00 && c <= 0xFFEF)) {
            if (c != '-' && prev - start > 0) {
                GUI_Graphics_getStringSize(font, start, prev - start, &w, &h);
                if (width < w) {
                    p = prev;
                    break;
                }
                total += prev - start;
                width -= w;
                start = prev;
            }
            n = p - start;
            GUI_Graphics_getStringSize(font, start, n, &w, &h);
            if (width < w)
                break;
            total += n;
            width -= w;
            start = p;
            w = 0;
        }
    }
    if ((w == 0) & (p != start)) {
        n = p - start;
        GUI_Graphics_getStringSize(font, start, n, &w, &h);
        if (width >= w)
            total += n;
    }
    if (total == 0) {
        if (outw != NULL)
            *outw = w;
        if (limit >= 0 && limit < w)
            return p - start;
    }
    return total;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", D_00133564);

RGIMAGE *rnd_gdrawImageDecode(void *data, int size, int a2, int a3, int *maxpix) {
    RTIME delay;
    int w;
    int h;
    int bpp;
    int fx;
    int fy;
    int fw;
    int fh;
    int fd;
    int anim;
    RGIMAGE *r;
    int type;
    int pm;
    int loop;
    int n;

    anim = 0;
    r = NULL;
    delay.sec = 0;
    delay.nsec = 0;
    loop = 0;
    type = GUI_Graphics_getImageProperty(data, size, &w, &h, &bpp);
    if (maxpix != NULL) {
        if (*maxpix < w * h * bpp)
            goto out;
        *maxpix = w * h * bpp;
    }
    switch (type) {
    case 1:
    case 3:
    case 4:
    case 6:
        pm = GUI_Graphics_getImage(data, size, type);
        if (pm == 0)
            goto out;
        break;
    case 2:
        anim = GUI_Graphics_createAnimationGIF(data, size);
        if (anim == 0)
            goto out;
        pm = GUI_Graphics_getAnimationGIFNextFrame(anim, 0);
        GUI_Graphics_getAnimationGIFFrameProperty(anim, &fx, &fy, &fw, &fh, &fd);
        if (fd < 0)
            loop = 1;
        delay.sec = fd / 100;
        delay.nsec = (fd % 100) * 10000000;
        break;
    default:
        goto out;
    }
    r = MEM_malloc(0, 0x20);
    if (r == NULL)
        goto out;
    r->type = type;
    r->pixmap = pm;
    r->anim = anim;
    r->unkC = delay.sec;
    r->unk10 = delay.nsec;
    OS_clock_gettime(0, &r->x);
    r->unk1C = loop;
out:
    return r;
}

RGIMAGE *rnd_gdrawImageDecodeByGifFile(char *name) {
    int fp;
    int size;
    void *buf;
    int img;
    RGIMAGE *r;
    RTIME tm;

    fp = FIO_fopen(name, "r");
    if (fp == 0) {
        return NULL;
    }
    FIO_fseek(fp, 0, 2);
    size = FIO_ftell(fp);
    if (size == 0) {
        goto fail;
    }
    FIO_fseek(fp, 0, 0);
    buf = MEM_malloc(0, size);
    if (buf == NULL) {
fail:
        FIO_fclose(fp);
        return NULL;
    }
    FIO_fread(buf, size, 1, fp);
    FIO_fclose(fp);
    img = GUI_Graphics_getImage(buf, size, 1);
    MEM_free(0, buf);
    if (img == 0) {
        return NULL;
    }
    r = MEM_malloc(0, sizeof(RGIMAGE));
    if (r == NULL) {
        return NULL;
    }
    r->type = 1;
    r->pixmap = img;
    OS_clock_gettime(0, &tm);
    r->x = tm.sec;
    r->y = tm.nsec;
    r->unk1C = 0;
    return r;
}

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

int rnd_gdrawImageUpdate(RGIMAGE *img, RTIME *now) {
    RTIME t;
    RTIME d;
    int a;
    int b;
    int c;
    int e;
    int fd;
    RTIME *p;

    t = *now;
    p = &t;
    if (img->type != 2 || img->unk1C == 1)
        return 0;
    if (p->nsec >= img->y) {
        d.sec = p->sec - img->x;
        d.nsec = p->nsec - img->y;
    } else {
        d.sec = p->sec - img->x - 1;
        d.nsec = p->nsec - img->y + 1000000000;
    }
    if (d.sec > img->unkC || (d.sec == img->unkC && d.nsec >= img->unk10)) {
        img->pixmap = GUI_Graphics_getAnimationGIFNextFrame(img->anim, 0);
        GUI_Graphics_getAnimationGIFFrameProperty(img->anim, &a, &b, &c, &e, &fd);
        if (fd < 0)
            img->unk1C = 1;
        img->unkC = fd / 100;
        img->unk10 = (fd % 100) * 10000000;
        img->x = p->sec;
        img->y = p->nsec;
        return 1;
    }
    return 0;
}

int rnd_gdrawImageReset(RGIMAGE *img, RTIME *now) {
    RTIME t;

    t = *now;
    if (img->type != 2 || img->unk1C == 1)
        return 0;
    img->x = t.sec;
    img->y = t.nsec;
    GUI_Graphics_getAnimationGIFNextFrame(img->anim, 1);
    return 1;
}

void rnd_drawImageBoxnode(int g, RBN *box, int ox, int oy)
{
    RGIMAGE *img;
    int x;
    int y;
    int w;
    int h;
    char *alt;
    int len;
    int tw;
    int th;
    int off;
    int line;
    int n;
    int color;
    DIBRECT *r;

    rnd_drawBasicBoxnode(g, box, ox, oy);
    img = box->sub->img;
    if (img == NULL)
        return;
    x = box->x + DS->ml + DS->pl + DS->bl + ox;
    y = box->y + DS->mt + DS->pt + DS->bt + oy;
    w = box->w - DS->br - DS->bl - DS->mr - DS->ml - DS->pr - DS->pl;
    h = box->h - DS->bt - DS->bb - DS->mt - DS->mb - DS->pt - DS->pb;
    if (DSUB(int *, 0x14) != 1 || (M2C_FIELD(box, u16 *, 0x40) & 4)) {
        if (w >= e_icon_image_width + 6 && h >= e_icon_image_height + 6) {
            rnd_gdrawRectangle(g, ~M2C_FIELD(((RBN *)getBodyBox(box))->style, int *, 0), x, y, w, h);
            if (M2C_FIELD(box, u16 *, 0x40) & 4)
                img = D_00584CAC;
            rnd_gdrawImage(g, x + 3, y + 3, e_icon_image_width, e_icon_image_height, 0, 0, 0, 0, img->pixmap, img->type);
            alt = DSUB(char **, 0x18);
            if (alt != NULL) {
                len = strlen(alt);
                GUI_Graphics_getStringSize(DS->font, alt, len, &tw, &th);
                off = 0;
                line = 1;
                while (h - 6 >= line * th && len > 0) {
                    n = rnd_gdrawGetStringsVisibleLength(DS->font, alt + off, len, w - e_icon_image_width - 6, -1, 0);
                    rnd_gdrawStrings(g, DS->font, DS->color, x + e_icon_image_width + 6, y + (line - 1) * th + 3, alt + off, n, 0);
                    line++;
                    len -= n;
                    off += n;
                }
            }
        }
    } else {
        if (img->pixmap != 0 && w != 0 && h != 0)
            rnd_gdrawImage(g, x, y, w, h, 0, 0, 0, 0, img->pixmap, img->type);
    }
    color = DS->bg;
    if (DS->mask != 0)
        rnd_gdrawMaskFillrectangle(g, color, x, y, w, h);
    if (DSUB(s8 *, 0x1C) > 0) {
        r = DSUB(DIBRECT **, 0x20);
        rnd_gdrawMaskFillrectangle(g, color, x + r->x, y + r->y, r->w, r->h);
    }
}

int rnd_updateAnimImageBoxnode(n)
    RBN *n;
{
    RBN *p;
    int px;
    int py;
    int sw;
    int sh;
    int ret;

    if (n->sub->img == NULL || n->sub->img->type != 2 || (p = rnd_findParentBoxnode(n, 1)) == NULL) {
        return 0;
    }
    GUI_ScrollPane_getScrollPosition(p->widget, &px, &py);
    rnd_gdrawGetViewClientSize(p->widget, &sw, &sh);
    rnd_findParentBoxnode(n, 0x13);
    ret = 0;
    if (px < n->x + n->w && n->x < px + sw && py < n->y + n->h && n->y < py + sh) {
        ret = 1;
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_resetAnimImageBoxnode(void) {
    rnd_updateAnimImageBoxnode();
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_relayoutWidgets);

void rnd_drawRepaint(int w, int g, int sid, int x, int y, int wd, int h) {
    RRECT rect;
    int white[3] = { 0xFF, 0xFF, 0xFF };
    RHIST *hn;
    void *body;
    int pm;
    int gr;

    hn = HST_searchSessionIDHistoryNode(sid);
    if (hn == NULL) {
        return;
    }
    body = hn->body;
    if (body == NULL) {
        return;
    }
    if (gESPRIT_LO_GLOBAL_NDA == NULL) {
        return;
    }
    rect.x = x;
    rect.y = y;
    rect.w = wd;
    rect.h = h;
    if (wd <= 0) {
        return;
    }
    if (h <= 0) {
        return;
    }
    pm = GUI_Graphics_createPixmap(wd, h);
    if (pm == 0) {
        lo_sendHalt();
        return;
    }
    gr = GUI_Graphics_getGraphics(0, pm);
    if (gr == 0) {
        lo_sendHalt();
    } else {
        GUI_Graphics_setColor(gr, white);
        GUI_Graphics_fillRect(gr, 0, 0, rect.w, rect.h);
        rnd_drawAllBoxnode(gr, &rect, body, -rect.x, -rect.y);
        GUI_Graphics_freeGraphics(gr);
        GUI_Graphics_drawPixmap(g, pm, rect.x, rect.y, 0, 0, 0, 0, 0, 0);
    }
    GUI_Graphics_freePixmap(pm);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_gdraw", rnd_drawTextBoxnode);

int rnd_updateAnimTextBoxnode(n)
    RBN *n;
{
    RBN *p;
    int px;
    int py;
    int sw;
    int sh;
    int ret;

    if (!(n->style->flags & 8) || (p = rnd_findParentBoxnode(n, 1)) == NULL) {
        return 0;
    }
    GUI_ScrollPane_getScrollPosition(p->widget, &px, &py);
    rnd_gdrawGetViewClientSize(p->widget, &sw, &sh);
    rnd_findParentBoxnode(n, 0x13);
    ret = 0;
    if (px < n->x + n->w && n->x < px + sw && py < n->y + n->h && n->y < py + sh) {
        ret = 1;
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rnd_resetAnimTextBoxnode(void) {
    rnd_updateAnimTextBoxnode();
}


typedef struct {
    int code;
    char *msg;
} RHALTDATA;

typedef struct {
    int type;
    int unk4;
    int unk8;
    int code;                   /* 0xC */
    u8 unk10[0xC];
    RHALTDATA *data;            /* 0x1C */
} RHALTBODY;

typedef struct {
    int unk0;
    RHALTBODY body;             /* 0x4 */
} RHALTMSG;

typedef struct {
    u8 unk0[0x4C];
    RHALTMSG *haltMsg;          /* 0x4C */
    u8 unk50[0x40];
    int mq;                     /* 0x90 */
} RLOGLOBAL;

extern RLOGLOBAL lo_global;
int OS_mq_send(int mq, void *msg, int size, int flag);

void lo_sendHalt(void) {
    RHALTBODY *b;

    if (lo_global.haltMsg != NULL) {
        b = &lo_global.haltMsg->body;
        b->type = 4;
        b->code = 0xFFFF;
        b->data->code = -1;
        b->data->msg = "AllocationError(Layout)";
        OS_mq_send(lo_global.mq, lo_global.haltMsg, 0x24, 0);
        lo_global.haltMsg = NULL;
    }
}

static const char D_00133604[] = "";
