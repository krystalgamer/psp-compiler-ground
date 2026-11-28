/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct {
    int unk0;
    void *focus;                /* 0x4 */
    int unk8;
    int flags;                  /* 0xC */
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int mode;                   /* 0x20 */
    void *target;               /* 0x24 */
    int view;                   /* 0x28 */
} ZWINDDATA;

typedef struct {
    void *image;
    int unk4;
    int unk8;
    int width;
    int height;
} ZINIT;

typedef struct {
    u8 unk0[0x54];
    u16 editable;               /* 0x54 */
} ZWIDGET;

typedef struct {
    int unk0;
    void *target;               /* 0x4 */
    u16 key;                    /* 0x8 */
    u16 unkA;
    u16 button;                 /* 0xC */
} ZEVENT;

typedef struct ZFONT {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 height;                 /* 0x6 */
} ZFONT;

typedef struct ZW {
    s8 type;
    struct ZW *parent;          /* 0x4 */
    struct ZW *child;
    struct ZW *next;
    ZFONT *font;                /* 0x10 */
    unsigned int flags;         /* 0x14 */
    int fg[3];
    int bg[3];
    s16 fg15;                   /* 0x30 */
    s16 bg15;                   /* 0x32 */
    s16 focus15;                /* 0x34 */
    s16 px;                     /* 0x36 */
    s16 py;                     /* 0x38 */
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    s16 dirty[4];
    void (*draw)();             /* 0x4C */
    void *arg;                  /* 0x50 */
    union {
        int state;              /* 0x54 */
        struct {
            s16 unk54;
            s16 pressed;        /* 0x56 */
        } b;
    } u;
} ZW;

extern ZWINDDATA s_windsystem_data;
extern int _i_windsystemOn;
extern int D_00584BCC;
extern void *_zWindFontImage;
extern int _zWindFontWidth;
extern int _zWindFontHeight;
int GUI_ScrollPane_getScrollPosition();
void zWindDrawBox(int x, int y, int w, int h, short color);
extern int _zWindDrawTexClipHeight;
extern int _zWindDrawTexClipWidth;
extern int _zWindDrawTexClipX;
extern int _zWindDrawTexClipX2;
extern int _zWindDrawTexClipY;
extern int _zWindDrawTexClipY2;
extern int _zWindDrawTexHeight;
extern int _zWindDrawTexWidth;
extern int _zWindDrawTexdata;
extern unsigned char s_windsystem_init;
extern int _zWindDrawTexClipHeightT;
extern int _zWindDrawTexClipWidthT;
extern int _zWindDrawTexClipXT;
extern int _zWindDrawTexClipYT;
extern int _zWindDrawTexHeightT;
extern int _zWindDrawTexWidthT;
extern int _zWindDrawTexdataT;
extern int _zwindPop;
void zWindDrawLineW(int x, int y, int len, short color);
void zWindDrawParts(int x, int y, int n, short color);
void zWindLineBox(int x, int y, int w, int h, short color);
void zWindLineBox2(int x, int y, int w, int h, short c1, short c2);
typedef struct {
    s8 type;
    s16 w;                      /* 0x2 */
    s16 unk4;
    s16 h;                      /* 0x6 */
} ZGFONT;
void zWindFontDraw(void *font, int x, int y, char *s, short color, int len);
void zWindFontDrawPassword(ZGFONT *font, int x, int y, char *s, short color, int len);
typedef struct {
    u8 unk0[0x4C];
    char *text;                 /* 0x4C */
    s16 len;                    /* 0x50 */
} ZTEXTW;
typedef struct ZITEM {
    int unk0;
    struct ZITEM *next;         /* 0x4 */
    char *text;                 /* 0x8 */
    s16 len;                    /* 0xC */
} ZITEM;
void zWindDrawClipSet(int x, int y, int w, int h);
extern int _iZwindPartsSize;
typedef struct {
    int font[4];
    s16 w;                      /* 0x10 */
    s16 h;
    s16 bpp;
    s16 wbytes;                 /* 0x16 */
    s16 hbytes;
    u16 flags;                  /* 0x1A */
} ZCHAR;
extern ZCHAR s_windsystemChar;
extern s8 *zdata_ImageRadioOff;
extern s8 *zdata_ImageRadioOn;
extern s8 *zdata_ImageChoiceOff;
extern s8 *zdata_ImageChoiceOn;
extern s8 *zdata_ImageScrollV1;
extern s8 *zdata_ImageScrollV2;
extern s8 zdata_ImageRadioOff_12[];
extern s8 zdata_ImageRadioOn_12[];
extern s8 zdata_ImageChoiceOff_12[];
extern s8 zdata_ImageChoiceOn_12[];
extern s8 zdata_ImageScrollV1_12[];
extern s8 zdata_ImageScrollV2_12[];
extern s8 zdata_ImageRadioOff_14[];
extern s8 zdata_ImageRadioOn_14[];
extern s8 zdata_ImageChoiceOff_14[];
extern s8 zdata_ImageChoiceOn_14[];
extern s8 zdata_ImageScrollV1_14[];
extern s8 zdata_ImageScrollV2_14[];
extern s8 zdata_ImageRadioOff_16[];
extern s8 zdata_ImageRadioOn_16[];
extern s8 zdata_ImageChoiceOff_16[];
extern s8 zdata_ImageChoiceOn_16[];
extern s8 zdata_ImageScrollV1_16[];
extern s8 zdata_ImageScrollV2_16[];
extern int D_00584BC8;
void zWindDrawImage(int x, int y, int w, int h, u16 *data, int flag);
int GUI_Component_update(ZW *w, int x, int y, int width, int height);
extern int _zWindDrawTexClipOffAX;
extern int _zWindDrawTexClipOffAY;
int GUI_Checkbox_getState(ZW *w);
int GUI_Checkbox_setState(ZW *w, int s);
ZW *GUI_RadioButton_getGroup(ZW *w);
int GUI_RadioButton_setState(void *w, int s);
int GUI_ScrollPane_getContentSize(int pane, int *w, int *h);
int GUI_ScrollPane_setScrollPosition(int pane, int x, int y);
void zWindDrawLineH(int x, int y, int len, short color);
extern int _zWindDrawTexClipOffX;
extern int _zWindDrawTexClipOffY;



int GUI_Choice_select(ZW *w, int idx);
typedef struct { u8 unk0[0x4C]; char *text; s16 len; s16 scroll; s16 lines; s16 unk56; int bar; } ZTEXTAREA;
int zWindFontDrawArea(void *font, int x, int y, char *s, short color, int w, int len, int bottom);
typedef struct { u16 code; u16 base; } KJTBL;
extern KJTBL kanji_0_table_1F2FD4[];
extern KJTBL kanji_1_table_1F3020[];
extern KJTBL kanji_2_table[];
int GUI_List_isIndexSelected(void *, int idx);
int GUI_List_deselect(void *, int idx);
int GUI_List_select(void *, int idx);
int zWindDraw(void) {
    int r;

    r = 0;
    if (_i_windsystemOn) {
        s_windsystem_data.flags |= 1;
        r = 1;
    }
    return r;
}

void zWindFontSet(int type, s16 w, s16 h, s16 bpp, void *f0, void *f1, void *f2, void *f3) {
    s_windsystemChar.flags = type;
    s_windsystemChar.font[0] = 0;
    s_windsystemChar.font[1] = 0;
    s_windsystemChar.font[2] = 0;
    s_windsystemChar.font[3] = 0;
    switch (type) {
    case 1:
        if (f0) {
            s_windsystemChar.flags |= 0x8000;
            s_windsystemChar.font[0] = (int)f0;
        }
        if (f1) {
            s_windsystemChar.flags |= 0x4000;
            s_windsystemChar.font[1] = (int)f1;
        }
        if (f2) {
            s_windsystemChar.flags |= 0x2000;
            s_windsystemChar.font[2] = (int)f2;
        }
        if (f3) {
            s_windsystemChar.flags |= 0x1000;
            s_windsystemChar.font[3] = (int)f3;
        }
        break;
    case 8:
        if (f0) {
            s_windsystemChar.flags |= 0x8000;
            s_windsystemChar.font[0] = (int)f0;
        }
        if (f1) {
            s_windsystemChar.flags |= 0x4000;
            s_windsystemChar.font[1] = (int)f1;
        }
        break;
    default:
        return;
    }
    s_windsystemChar.w = w;
    s_windsystemChar.h = h;
    s_windsystemChar.bpp = bpp;
    s_windsystemChar.wbytes = (w * bpp + 7) / 8;
    s_windsystemChar.hbytes = (h * bpp + 7) / 8;
}

int zWindLocateSet(int x, int y) {
    int w;
    int h;

    if (s_windsystem_data.flags & 4) {
        return 0;
    }
    if (s_windsystem_data.view == 0) {
        return 0;
    }
    if (GUI_ScrollPane_getContentSize(s_windsystem_data.view, &w, &h) == -1) {
        return 0;
    }
    w -= ((ZINIT *)&s_windsystem_init)->width;
    h -= ((ZINIT *)&s_windsystem_init)->height;
    if (x > w) {
        x = w;
    }
    if (y > h) {
        y = h;
    }
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (GUI_ScrollPane_setScrollPosition(s_windsystem_data.view, x, y) == -1) {
        return 0;
    }
    zWindDraw();
    return 0;
}

int zWindLocateGet(int *x, int *y) {
    *x = 0;
    *y = 0;
    if (s_windsystem_data.flags & 4) {
        return 0;
    }
    if (s_windsystem_data.view == 0) {
        return 0;
    }
    GUI_ScrollPane_getScrollPosition(s_windsystem_data.view, x, y);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int zWindSetSetFocusCallback(void) {
    return 0;
}

void zWindPartsSet(int size) {
    if (size < 14) {
        zdata_ImageRadioOff = zdata_ImageRadioOff_12;
        zdata_ImageRadioOn = zdata_ImageRadioOn_12;
        zdata_ImageChoiceOff = zdata_ImageChoiceOff_12;
        zdata_ImageChoiceOn = zdata_ImageChoiceOn_12;
        zdata_ImageScrollV1 = zdata_ImageScrollV1_12;
        zdata_ImageScrollV2 = zdata_ImageScrollV2_12;
        _iZwindPartsSize = 12;
    } else if (size >= 16) {
        zdata_ImageRadioOff = zdata_ImageRadioOff_16;
        zdata_ImageRadioOn = zdata_ImageRadioOn_16;
        zdata_ImageChoiceOff = zdata_ImageChoiceOff_16;
        zdata_ImageChoiceOn = zdata_ImageChoiceOn_16;
        zdata_ImageScrollV1 = zdata_ImageScrollV1_16;
        zdata_ImageScrollV2 = zdata_ImageScrollV2_16;
        _iZwindPartsSize = 16;
    } else {
        zdata_ImageRadioOff = zdata_ImageRadioOff_14;
        zdata_ImageRadioOn = zdata_ImageRadioOn_14;
        zdata_ImageChoiceOff = zdata_ImageChoiceOff_14;
        zdata_ImageChoiceOn = zdata_ImageChoiceOn_14;
        zdata_ImageScrollV1 = zdata_ImageScrollV1_14;
        zdata_ImageScrollV2 = zdata_ImageScrollV2_14;
        _iZwindPartsSize = 14;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void zWindDrawCls(void) {
    _zWindDrawTexdata = M2C_FIELD(&s_windsystem_init, int *, 0);
    _zWindDrawTexWidth = M2C_FIELD(&s_windsystem_init, int *, 0xC);
    _zWindDrawTexHeight = M2C_FIELD(&s_windsystem_init, int *, 0x10);
    _zWindDrawTexClipX = 0;
    _zWindDrawTexClipY = 0;
    _zWindDrawTexClipWidth = ((ZINIT *)&s_windsystem_init)->width;
    _zWindDrawTexClipHeight = ((ZINIT *)&s_windsystem_init)->height;
    _zWindDrawTexClipX2 = ((ZINIT *)&s_windsystem_init)->width;
    _zWindDrawTexClipY2 = ((ZINIT *)&s_windsystem_init)->height;
}

void zWindDrawClipSet(int x, int y, int w, int h) {
    if (x > _zWindDrawTexWidth || x + w < 0 || y > _zWindDrawTexHeight || y + h < 0) {
        return;
    }
    if (x < 0) {
        w = x + w;
        x = 0;
    }
    if (x + w > _zWindDrawTexWidth) {
        w = _zWindDrawTexWidth - x;
    }
    if (y < 0) {
        h = h + y;
        y = 0;
    }
    if (y + h > _zWindDrawTexHeight) {
        h = _zWindDrawTexHeight - y;
    }
    _zWindDrawTexClipX = x;
    _zWindDrawTexClipY = y;
    _zWindDrawTexClipWidth = w;
    _zWindDrawTexClipHeight = h;
    _zWindDrawTexClipX2 = x + w;
    _zWindDrawTexClipY2 = y + h;
}

void zWindDrawClipSetTex(int tex, int x, int y, int w, int h, int texw, int texh) {
    _zWindDrawTexdata = tex;
    _zWindDrawTexWidth = texw;
    _zWindDrawTexHeight = texh;
    if (x > texw || x + w < 0) {
        return;
    }
    if (y > texh || y + h < 0) {
        return;
    }
    if (x < 0) {
        w = x + w;
        x = 0;
    }
    if (x + w > _zWindDrawTexWidth) {
        w = _zWindDrawTexWidth - x;
    }
    if (y < 0) {
        h = h + y;
        y = 0;
    }
    if (y + h > _zWindDrawTexHeight) {
        h = _zWindDrawTexHeight - y;
    }
    _zWindDrawTexClipX = x;
    _zWindDrawTexClipY = y;
    _zWindDrawTexClipWidth = w;
    _zWindDrawTexClipHeight = h;
    _zWindDrawTexClipX2 = x + w;
    _zWindDrawTexClipY2 = y + h;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int puts(const char *s);

void zWindDrawClipPush(void) {
    int temp_v0;

    temp_v0 = _zwindPop + 1;
    _zwindPop = temp_v0;
    if (temp_v0 >= 2) {
        puts("[X]zwindpop EROOR");
    }
    _zWindDrawTexdataT = _zWindDrawTexdata;
    _zWindDrawTexWidthT = _zWindDrawTexWidth;
    _zWindDrawTexHeightT = _zWindDrawTexHeight;
    _zWindDrawTexClipXT = _zWindDrawTexClipX;
    _zWindDrawTexClipYT = _zWindDrawTexClipY;
    _zWindDrawTexClipWidthT = _zWindDrawTexClipWidth;
    _zWindDrawTexClipHeightT = _zWindDrawTexClipHeight;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void zWindDrawClipPop(void) {
    _zwindPop -= 1;
    _zWindDrawTexdata = _zWindDrawTexdataT;
    _zWindDrawTexWidth = _zWindDrawTexWidthT;
    _zWindDrawTexHeight = _zWindDrawTexHeightT;
    _zWindDrawTexClipX = _zWindDrawTexClipXT;
    _zWindDrawTexClipY = _zWindDrawTexClipYT;
    _zWindDrawTexClipWidth = _zWindDrawTexClipWidthT;
    _zWindDrawTexClipHeight = _zWindDrawTexClipHeightT;
    _zWindDrawTexClipX2 = _zWindDrawTexClipXT + _zWindDrawTexClipWidthT;
    _zWindDrawTexClipY2 = _zWindDrawTexClipYT + _zWindDrawTexClipHeightT;
}

void zWindDrawBox(int x, int y, int w, int h, short color) {
    u16 *p;
    int x2;
    int y2;
    int i;
    int skip;

    x -= _zWindDrawTexClipOffX;
    y -= _zWindDrawTexClipOffY;
    if (x > _zWindDrawTexClipX2 || x + w < _zWindDrawTexClipX || y > _zWindDrawTexClipY2 || y + h < _zWindDrawTexClipY) {
        return;
    }
    if (x < _zWindDrawTexClipX) {
        w -= _zWindDrawTexClipX - x;
        x = _zWindDrawTexClipX;
    }
    if (x + w > _zWindDrawTexClipX2) {
        w = _zWindDrawTexClipX2 - x;
    }
    if (y < _zWindDrawTexClipY) {
        h -= _zWindDrawTexClipY - y;
        y = _zWindDrawTexClipY;
    }
    if (y + h > _zWindDrawTexClipY2) {
        h = _zWindDrawTexClipY2 - y;
    }
    x2 = x + w;
    y2 = y + h;
    p = (u16 *)_zWindDrawTexdata;
    p += x + y * _zWindDrawTexWidth;
    color |= 0x8000;
    skip = _zWindDrawTexWidth - w;
    for (; y < y2; y++) {
        for (i = x; i < x2; i++) {
            *p++ = color;
        }
        p += skip;
    }
}

void zWindDrawBoxP(int x1, int y1, int x2, int y2, s16 color) {
    int t;

    if (x2 < x1) {
        t = x1;
        x1 = x2;
        x2 = t;
    }
    if (y2 < y1) {
        t = y1;
        y1 = y2;
        y2 = t;
    }
    zWindDrawBox(x1, y1, x2 - x1, y2 - y1, color);
}

void zWindDrawLineW(int x, int y, int len, short color) {
    u16 *p;
    int x2;

    if (x > _zWindDrawTexClipX2 || x + len <= _zWindDrawTexClipX || y < _zWindDrawTexClipY || y >= _zWindDrawTexClipY2) {
        return;
    }
    if (x < _zWindDrawTexClipX) {
        len -= _zWindDrawTexClipX - x;
        x = _zWindDrawTexClipX;
    }
    if (x + len >= _zWindDrawTexClipX2) {
        len = _zWindDrawTexClipX2 - x - 1;
    }
    x2 = x + len;
    p = (u16 *)_zWindDrawTexdata;
    p += x + y * _zWindDrawTexWidth;
    color |= 0x8000;
    for (; x <= x2; x++) {
        *p++ = color;
    }
}

void zWindDrawLineH(int x, int y, int len, short color) {
    u16 *p;
    int y2;
    int w;

    if (y > _zWindDrawTexClipY2 || y + len <= _zWindDrawTexClipY || x < _zWindDrawTexClipX || x >= _zWindDrawTexClipX2) {
        return;
    }
    if (y < _zWindDrawTexClipY) {
        len -= _zWindDrawTexClipY - y;
        y = _zWindDrawTexClipY;
    }
    if (y + len >= _zWindDrawTexClipY2) {
        len = _zWindDrawTexClipY2 - y - 1;
    }
    y2 = y + len;
    p = (u16 *)_zWindDrawTexdata;
    p += x + y * _zWindDrawTexWidth;
    w = _zWindDrawTexWidth;
    color |= 0x8000;
    for (; y <= y2; y++) {
        *p = color;
        p += w;
    }
}

void zWindLineBox(int x, int y, int w, int h, short color) {
    x -= _zWindDrawTexClipOffX;
    y -= _zWindDrawTexClipOffY;
    zWindDrawLineW(x, y, w, color);
    zWindDrawLineW(x, y + h, w, color);
    zWindDrawLineH(x, y, h, color);
    zWindDrawLineH(x + w, y, h, color);
}

void zWindLineBoxP(int x1, int y1, int x2, int y2, s16 color) {
    int t;

    if (x2 < x1) {
        t = x1;
        x1 = x2;
        x2 = t;
    }
    if (y2 < y1) {
        t = y1;
        y1 = y2;
        y2 = t;
    }
    zWindDrawBox(x1, y1, x2 - x1, y2 - y1, color);
}

void zWindLineBox2(int x, int y, int w, int h, short c1, short c2) {
    zWindDrawLineW(x, y, w, c1);
    zWindDrawLineH(x, y, h, c1);
    zWindDrawLineW(x, y + h, w, c2);
    zWindDrawLineH(x + w, y, h, c2);
}

void zWindDrawImage(int x, int y, int w, int h, u16 *src, int mode) {
    u16 *p;
    int cw;
    int i;
    int d;
    int dskip;
    int sskip;
    s16 c;

    cw = w;
    x -= _zWindDrawTexClipOffX;
    y -= _zWindDrawTexClipOffY;
    if (x > _zWindDrawTexClipX2 || x + w < _zWindDrawTexClipX || y > _zWindDrawTexClipY2 || y + h < _zWindDrawTexClipY) {
        return;
    }
    if (x < _zWindDrawTexClipX) {
        d = _zWindDrawTexClipX - x;
        cw = w - d;
        src += d;
        x = _zWindDrawTexClipX;
    }
    if (x + cw > _zWindDrawTexClipX2) {
        cw = _zWindDrawTexClipX2 - x;
    }
    if (y < _zWindDrawTexClipY) {
        d = _zWindDrawTexClipY - y;
        h -= d;
        src += d * w;
        y = _zWindDrawTexClipY;
    }
    if (y + h > _zWindDrawTexClipY2) {
        h = _zWindDrawTexClipY2 - y;
    }
    p = (u16 *)_zWindDrawTexdata;
    p += x + y * _zWindDrawTexWidth;
    dskip = _zWindDrawTexWidth - cw;
    sskip = w - cw;
    if (mode == 1) {
        for (; h > 0; h--) {
            for (i = cw; i > 0; i--) {
                *p++ = *src++;
            }
            p += dskip;
            src += sskip;
        }
    } else {
        for (; h > 0; h--) {
            for (i = cw; i > 0; i--) {
                c = *src++;
                if (c != 0) {
                    *p = c;
                }
                p++;
            }
            p += dskip;
            src += sskip;
        }
    }
}

void zWindDrawImageScl(int x, int y, int sw, int sh, int dw, int dh, u16 *src, int mode) {
    u16 *p;
    int cw = dw;
    int ch = dh;
    int ox = 0;
    int oy = 0;
    int i;
    int j;
    int skip;
    s16 c;

    x -= _zWindDrawTexClipOffX;
    y -= _zWindDrawTexClipOffY;
    if (x > _zWindDrawTexClipX2 || x + dw < _zWindDrawTexClipX || y > _zWindDrawTexClipY2 || y + dh < _zWindDrawTexClipY) {
        return;
    }
    if (x < _zWindDrawTexClipX) {
        ox = _zWindDrawTexClipX - x;
        if (ox < 0) {
            return;
        }
        if (dw < ox) {
            return;
        }
        cw = dw - ox;
        x = _zWindDrawTexClipX;
    }
    if (x + cw > _zWindDrawTexClipX2) {
        cw = _zWindDrawTexClipX2 - x;
    }
    if (y < _zWindDrawTexClipY) {
        oy = _zWindDrawTexClipY - y;
        if (oy < 0) {
            return;
        }
        if (dh < oy) {
            return;
        }
        ch -= oy;
        y = _zWindDrawTexClipY;
    }
    if (y + ch > _zWindDrawTexClipY2) {
        ch = _zWindDrawTexClipY2 - y;
    }
    ox = ox * sw / dw;
    oy = oy * sh / dh;
    p = (u16 *)_zWindDrawTexdata;
    p += x + y * _zWindDrawTexWidth;
    skip = _zWindDrawTexWidth - cw;
    if (mode == 1) {
        for (j = 0; j < ch; j++) {
            for (i = 0; i < cw; i++) {
                *p++ = src[i * sw / dw + ox + (j * sh / dh + oy) * sw];
            }
            p += skip;
        }
    } else {
        for (j = 0; j < ch; j++) {
            for (i = 0; i < cw; i++) {
                c = src[i * sw / dw + ox + (j * sh / dh + oy) * sw];
                if (c != 0) {
                    *p = c;
                }
                p++;
            }
            p += skip;
        }
    }
}

void zWindDrawParts(int x, int y, int n, short color) {
    u16 buf[0x100];
    u16 pal[5];
    s8 *src;
    int i;

    pal[0] = 0;
    pal[1] = 0xFFFF;
    pal[2] = 0xC210;
    pal[3] = 0x8000;
    pal[4] = color | 0x8000;
    switch (n) {
    case 0:
        src = zdata_ImageRadioOff;
        break;
    case 1:
        src = zdata_ImageRadioOn;
        break;
    case 2:
        src = zdata_ImageChoiceOff;
        break;
    case 3:
        src = zdata_ImageChoiceOn;
        break;
    case 4:
        src = zdata_ImageScrollV1;
        break;
    case 5:
        src = zdata_ImageScrollV2;
        break;
    default:
        return;
    }
    for (i = 0; i < _iZwindPartsSize * _iZwindPartsSize; i++) {
        buf[i] = pal[*src++];
    }
    zWindDrawImage(x, y, _iZwindPartsSize, _iZwindPartsSize, buf, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void zWindWidgetFrameDraw(void *arg0) {
    zWindLineBox2(M2C_FIELD(arg0, short *, 0x36), M2C_FIELD(arg0, short *, 0x38), M2C_FIELD(arg0, short *, 0x3E), M2C_FIELD(arg0, short *, 0x40), 0, 0x7FFF);
}

typedef struct {
    u8 unk0[0x4C];
    int kind;                   /* 0x4C */
    char *text;                 /* 0x50 */
    s16 len;                    /* 0x54 */
    s16 pressed;                /* 0x56 */
    struct {
        s16 unk0;
        s16 w;
        s16 h;
        s16 unk6;
        int unk8;
        u16 *data;              /* 0xC */
    } *image;                   /* 0x58 */
} ZBUTTON;
int GUI_Graphics_getStringSize();

void zWindWidgetButtonDraw(ZW *w) {
    int tw;
    int th;
    s16 x;
    s16 y;
    s16 wd;
    s16 h;
    int off;
    int c;
    s16 iw;
    s16 ih;

    x = w->px;
    y = w->py;
    wd = w->w;
    h = w->h;
    zWindDrawBox(x, y, wd, h, w->bg15);
    off = 0;
    if ((ZW *)s_windsystem_data.focus == w && w->focus15 != 0) {
        zWindLineBox(x, y, wd - 1, h - 1, w->focus15);
        if (((ZBUTTON *)w)->pressed != 0) {
            off = 2;
        }
    } else {
        zWindLineBox2(x, y, wd - 1, h - 1, 0x7FFF, 0);
    }
    zWindDrawClipSet(x + 2, y + 2, wd - 3, h - 3);
    switch (((ZBUTTON *)w)->kind) {
    case 0:
        if (((ZBUTTON *)w)->len != 0) {
            GUI_Graphics_getStringSize(w->font, ((ZBUTTON *)w)->text, ((ZBUTTON *)w)->len, &tw, &th);
            c = w->fg15;
            if (w->flags & 0x40000000) {
                c = 0x318C;
            }
            zWindFontDraw(w->font, x + (wd - tw) / 2 + off, y + (h - th) / 2 + off, ((ZBUTTON *)w)->text, c, ((ZBUTTON *)w)->len);
        }
        break;
    case 1:
        iw = ((ZBUTTON *)w)->image->w;
        ih = ((ZBUTTON *)w)->image->h;
        zWindDrawImage((wd - iw) / 2 + x + off, (h - ih) / 2 + y + off, iw, ih, ((ZBUTTON *)w)->image->data, 0);
        break;
    }
    zWindDrawClipSet(0, 0, ((ZINIT *)&s_windsystem_init)->width, ((ZINIT *)&s_windsystem_init)->height);
}

void zWindWidgetCheckboxDraw(ZW *w) {
    int x;
    int y;

    x = w->px;
    y = w->py;
    if (w->u.state == 1) {
        zWindDrawParts(x, y, 1, w->bg15);
    } else {
        zWindDrawParts(x, y, 0, w->bg15);
    }
    if (s_windsystem_data.focus == w && w->focus15 != 0) {
        zWindLineBox(x, y, _iZwindPartsSize - 1, _iZwindPartsSize - 1, w->focus15);
    }
}

void zWindWidgetRadioboxDraw(ZW *w) {
    int x;
    int y;

    x = w->px;
    y = w->py;
    if (w->u.state == 1) {
        zWindDrawParts(x, y, 3, w->bg15);
    } else {
        zWindDrawParts(x, y, 2, w->bg15);
    }
    if (s_windsystem_data.focus == w && w->focus15 != 0) {
        zWindLineBox(x, y, _iZwindPartsSize - 1, _iZwindPartsSize - 1, w->focus15);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetListDraw);

void zWindWidgetChoiceDraw(ZW *w) {
    int x;
    int y;
    int wd;
    int h;
    ZITEM *it;
    int i;
    int ps;
    int sel;

    x = w->px;
    y = w->py;
    wd = w->w;
    ps = _iZwindPartsSize;
    h = ps + 4;
    zWindDrawBox(x, y, wd, h, w->bg15);
    if (s_windsystem_data.focus == w && w->focus15 != 0) {
        zWindLineBox(x, y, wd - 1, ps + 3, w->focus15);
    } else {
        zWindLineBox2(x, y, wd - 1, h - 1, 0, 0x7FFF);
    }
    zWindLineBox(x + 1, y + 1, wd - 3, h - 3, 0x294A);
    zWindDrawParts(x + wd - _iZwindPartsSize - 2, y + 2, 5, -1);
    zWindDrawClipSet(x + 2, y + 2, wd - _iZwindPartsSize - 2, h - 4);
    sel = w->u.b.unk54;
    for (i = 0, it = (ZITEM *)((ZTEXTW *)w)->text; it != NULL; i++, it = it->next) {
        if (i == sel) {
            zWindFontDraw(w->font, x + 2, y + 2, it->text, w->fg15, it->len);
            break;
        }
    }
    zWindDrawClipSet(0, 0, ((ZINIT *)&s_windsystem_init)->width, ((ZINIT *)&s_windsystem_init)->height);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetChoiceListDraw);

void zWindWidgetChoiceListDelete(ZW *w) {
    int fh;
    int x;
    int y;
    int wd;
    int h;

    s_windsystem_data.mode = 0;
    s_windsystem_data.target = NULL;
    if (w == NULL) {
        return;
    }
    x = 0;
    y = 0;
    if (s_windsystem_data.view != 0) {
        GUI_ScrollPane_getScrollPosition(s_windsystem_data.view, &x, &y);
    }
    fh = w->font->height;
    x += w->px;
    wd = w->w;
    h = fh * 5 + 4;
    if (w->py < D_00584BC8 / 2) {
        y += w->py + w->h;
    } else {
        y += w->py - h;
    }
    GUI_Component_update(w->parent, x, y, wd + 1, h + 1);
}

void zWindWidgetTextAreaDraw(ZW *w) {
    s16 x;
    s16 y;
    s16 wd;
    s16 h;
    int c;
    int n;
    int pos;
    int th;

    x = w->px;
    y = w->py;
    wd = w->w;
    h = w->h;
    zWindDrawBox(x, y, wd - 1, h - 1, w->bg15);
    if (s_windsystem_data.focus == w && w->focus15 != 0) {
        zWindLineBox(x, y, wd - 1, h - 1, w->focus15);
    } else {
        zWindLineBox2(x, y, wd - 1, h - 1, 0, 0x7FFF);
    }
    zWindLineBox(x + 1, y + 1, wd - 3, h - 3, 0x294A);
    if (((ZTEXTAREA *)w)->len == 0) {
        return;
    }
    if (((ZTEXTAREA *)w)->bar == -1) {
        zWindDrawClipSet(x + 2, y + 2, wd - 4, h - 4);
        c = w->fg15;
        if (w->flags & 0x40000000) {
            c = 0x318C;
        }
        n = zWindFontDrawArea(w->font, x + 2, y - ((ZTEXTAREA *)w)->scroll * w->font->height + 2, ((ZTEXTAREA *)w)->text, c, wd - 4, ((ZTEXTAREA *)w)->len, y + h - 2);
        ((ZTEXTAREA *)w)->lines = n - h / w->font->height + 1;
        zWindDrawClipSet(0, 0, ((ZINIT *)&s_windsystem_init)->width, ((ZINIT *)&s_windsystem_init)->height);
    } else {
        zWindDrawClipSet(x + 2, y + 2, wd - _iZwindPartsSize - 4, h - 4);
        c = w->fg15;
        if (w->flags & 0x40000000) {
            c = 0x318C;
        }
        n = zWindFontDrawArea(w->font, x + 2, y - ((ZTEXTAREA *)w)->scroll * w->font->height + 2, ((ZTEXTAREA *)w)->text, c, wd - _iZwindPartsSize - 4, ((ZTEXTAREA *)w)->len, y + h - 2);
        ((ZTEXTAREA *)w)->lines = n - h / w->font->height;
        zWindDrawClipSet(0, 0, ((ZINIT *)&s_windsystem_init)->width, ((ZINIT *)&s_windsystem_init)->height);
        zWindDrawBox(x - _iZwindPartsSize + wd - 2, y + _iZwindPartsSize + 2, _iZwindPartsSize, h - _iZwindPartsSize - _iZwindPartsSize - 4, 0x294A);
        zWindDrawParts(x + wd - _iZwindPartsSize - 2, y + 2, 4, -1);
        zWindDrawParts(x - _iZwindPartsSize + wd - 2, y - _iZwindPartsSize + h - 2, 5, -1);
        th = n * w->font->height;
        if (th < h - 4) {
            c = h - _iZwindPartsSize * 2 - 4;
        } else {
            c = (h - _iZwindPartsSize * 2 - 4) * (h - 4) / th;
        }
        pos = (h - _iZwindPartsSize * 2 - c - 4) * ((ZTEXTAREA *)w)->scroll / ((ZTEXTAREA *)w)->lines;
        zWindDrawBox(x - _iZwindPartsSize + wd - 2, y + _iZwindPartsSize + pos + 2, _iZwindPartsSize, c, 0x4210);
        zWindLineBox2(x - _iZwindPartsSize + wd - 2, y + _iZwindPartsSize + pos + 2, _iZwindPartsSize, c, 0x7FFF, 0);
    }
    if (((ZTEXTAREA *)w)->lines < 0) {
        ((ZTEXTAREA *)w)->lines = 0;
    }
}

void zWindWidgetTextFieldDraw(ZW *w) {
    int x;
    int y;
    int wd;
    int h;
    int c;

    x = w->px;
    y = w->py;
    wd = w->w;
    h = w->h;
    zWindDrawBox(x, y, wd - 1, h - 1, w->bg15);
    if (s_windsystem_data.focus == w && w->focus15 != 0) {
        zWindLineBox(x, y, wd - 1, h - 1, w->focus15);
    } else {
        zWindLineBox2(x, y, wd - 1, h - 1, 0, 0x7FFF);
    }
    zWindLineBox(x + 1, y + 1, wd - 3, h - 3, 0x294A);
    if (((ZTEXTW *)w)->len != 0) {
        zWindDrawClipSet(x + 2, y + 2, wd - 4, h - 4);
        c = w->fg15;
        if (w->flags & 0x40000000) {
            c = 0x318C;
        }
        if (!(w->u.state & 0x10000)) {
            zWindFontDraw(w->font, x + 2, y + 2, ((ZTEXTW *)w)->text, c, ((ZTEXTW *)w)->len);
        } else {
            zWindFontDrawPassword(w->font, x + 2, y + 2, ((ZTEXTW *)w)->text, c, ((ZTEXTW *)w)->len);
        }
        zWindDrawClipSet(0, 0, ((ZINIT *)&s_windsystem_init)->width, ((ZINIT *)&s_windsystem_init)->height);
    }
}

void zWindWidgetContentviewDraw() {
}

void zWindWidgetButtonDraw(ZW *w);
void zWindWidgetListDraw(ZW *w);
void zWindWidgetTextAreaDraw(ZW *w);
void zWindDrawUpdate(ZW *w, int x, int y, int wd, int h);

void zWindWidgetDraw(ZW *w, int x, int y) {
    int sx;
    int sy;

    _zWindDrawTexClipOffX = 0;
    _zWindDrawTexClipOffY = 0;
    if (w == NULL) {
        return;
    }
    if (w->type != 1) {
        return;
    }
    w->px = x + w->x;
    w->py = y + w->y;
    if (w->flags & 0x800000) {
        zWindDrawUpdate(w, w->dirty[0], w->dirty[1], w->dirty[2], w->dirty[3]);
        w->flags &= ~0x800000;
    }
    switch (w->flags & 0xF) {
    case 1:
        zWindWidgetFrameDraw(w);
        break;
    case 3:
        zWindWidgetButtonDraw(w);
        break;
    case 4:
        zWindWidgetCheckboxDraw(w);
        break;
    case 6:
        zWindWidgetRadioboxDraw(w);
        break;
    case 8:
        zWindWidgetListDraw(w);
        break;
    case 9:
        zWindWidgetChoiceDraw(w);
        break;
    case 10:
        zWindWidgetTextFieldDraw(w);
        break;
    case 11:
        zWindWidgetTextAreaDraw(w);
        break;
    case 12:
        zWindWidgetContentviewDraw(w);
        break;
    }
    if ((w->flags & 0xF) == 12) {
        if (w->child != NULL) {
            GUI_ScrollPane_getScrollPosition(w, &sx, &sy);
            zWindWidgetDraw(w->child, x + w->x - sx, y + w->y - sy);
        }
    } else if (w->child != NULL) {
        zWindWidgetDraw(w->child, x + w->x, y + w->y);
    }
    if (w->next != NULL) {
        zWindWidgetDraw(w->next, x, y);
    }
}

extern ZGFONT *D_00584B68;
extern u8 D_00584BB6;
void zWindFontDrawHF(ZGFONT *f, int x, int y, int c, short color);
void zWindFontDrawZE(ZGFONT *f, int x, int y, int c, int color);
int pspBrowserUtf8ToSjis();

void zWindFontDrawHF(ZGFONT *f, int x, int y, int c, short color) {
    u16 buf[128];
    u16 *d;
    s8 *p;
    int n;
    s8 b;

    if (*(s16 *)&D_00584BB6 >= 0) {
        return;
    }
    d = buf;
    if (c < 0x20) {
        return;
    }
    if (c >= 0x80) {
        if (c < 0xA2) {
            return;
        }
        c -= 0x22;
    }
    p = (s8 *)s_windsystemChar.font[0];
    p += (c - 0x20) * s_windsystemChar.hbytes;
    for (n = s_windsystemChar.bpp; n > 0; n--) {
        b = *p++;
        *d++ = (b & 0x80) ? color : 0;
        *d++ = (b & 0x40) ? color : 0;
        *d++ = (b & 0x20) ? color : 0;
        *d++ = (b & 0x10) ? color : 0;
        *d++ = (b & 0x08) ? color : 0;
        *d++ = (b & 0x04) ? color : 0;
        *d++ = (b & 0x02) ? color : 0;
        *d++ = (b & 0x01) ? color : 0;
    }
    zWindDrawImage(x, y, s_windsystemChar.h, s_windsystemChar.bpp, buf, 0);
}

int zWindFontDrawZE_K(ZGFONT *f, int x, int y, int c, short color) {
    u16 buf[256];
    u16 *d;
    s8 *p;
    int n;
    s8 b;

    if (c <= 0xABFF) {
        return -1;
    }
    if (c > 0xD7A3) {
        return -1;
    }
    if (!(*(u16 *)&D_00584BB6 & 0x4000)) {
        return -1;
    }
    d = buf;
    p = (s8 *)s_windsystemChar.font[1];
    p += (c - 0xAC00) * s_windsystemChar.wbytes;
    for (n = s_windsystemChar.wbytes; n > 0; n--) {
        b = *p++;
        *d++ = (b & 0x80) ? color : 0;
        *d++ = (b & 0x40) ? color : 0;
        *d++ = (b & 0x20) ? color : 0;
        *d++ = (b & 0x10) ? color : 0;
        *d++ = (b & 0x08) ? color : 0;
        *d++ = (b & 0x04) ? color : 0;
        *d++ = (b & 0x02) ? color : 0;
        *d++ = (b & 0x01) ? color : 0;
    }
    zWindDrawImage(x, y, s_windsystemChar.w, s_windsystemChar.bpp, buf, 0);
    return 0;
}

void zWindFontDrawZE(ZGFONT *f, int x, int y, int c, int color) {
    u16 buf[256];
    u16 *d;
    s8 *p;
    int idx;
    int i;
    int lo;
    int hi;
    KJTBL *e;
    int n;
    s8 b;
    ZCHAR *ch;
    int k;
    int t;

    color = (short)color;
    p = NULL;
    i = 0;
    idx = -1;
    lo = c & 0xFF;
    hi = (c >> 8) & 0xFF;
    if ((unsigned int)(c - 0x8140) < 0x37F) {
        if (!(s_windsystemChar.flags & 0x4000))
            return;
        switch (c & 0xFF00) {
        case 0x8100:
            if ((unsigned int)(lo - 0x40) < 0x3F)
                i = 0;
            else if ((unsigned int)(lo - 0x80) < 0x2D)
                i = 1;
            else if ((unsigned int)(lo - 0xB8) < 8)
                i = 2;
            else if ((unsigned int)(lo - 0xC8) < 7)
                i = 3;
            else if ((unsigned int)(lo - 0xDA) < 0xF)
                i = 4;
            else if ((unsigned int)(lo - 0xF0) < 8)
                i = 5;
            else if (lo == 0xFC)
                i = 6;
            else
                return;
            break;
        case 0x8200:
            if ((unsigned int)(lo - 0x4F) < 0xA)
                i = 7;
            else if ((unsigned int)(lo - 0x60) < 0x1A)
                i = 8;
            else if ((unsigned int)(lo - 0x81) < 0x1A)
                i = 9;
            else if ((unsigned int)(lo - 0x9F) < 0x53)
                i = 10;
            else
                return;
            break;
        case 0x8300:
            if ((unsigned int)(lo - 0x40) < 0x3F)
                i = 11;
            else if ((unsigned int)(lo - 0x80) < 0x17)
                i = 12;
            else if ((unsigned int)(lo - 0x9F) < 0x18)
                i = 13;
            else if ((unsigned int)(lo - 0xBF) < 0x18)
                i = 14;
            else
                return;
            break;
        case 0x8400:
            if ((unsigned int)(lo - 0x40) < 0x21)
                i = 15;
            else if ((unsigned int)(lo - 0x70) < 0xF)
                i = 16;
            else if ((unsigned int)(lo - 0x80) < 0x12)
                i = 17;
            else if ((unsigned int)(lo - 0x9F) < 0x20)
                i = 18;
            break;
        default:
            p = (s8 *)s_windsystemChar.font[1];
            goto next;
        }
        idx = c - kanji_0_table_1F2FD4[i].code + kanji_0_table_1F2FD4[i].base;
        p = (s8 *)s_windsystemChar.font[1];
    }
next:
    if ((unsigned int)(c - 0x889F) < 0xFD4) {
        ch = &s_windsystemChar;
        if (!(ch->flags & 0x2000))
            return;
        if ((unsigned int)(lo - 0x40) >= 0xBD)
            return;
        k = hi * 2 - 0x110 - (lo < 0x7F);
        e = &kanji_1_table_1F3020[k];
        idx = c - e->code + e->base;
        p = (s8 *)ch->font[2];
    }
    if ((unsigned int)(c - 0x989F) < 0x761) {
        ch = &s_windsystemChar;
        if (!(ch->flags & 0x1000))
            return;
        if ((unsigned int)(lo - 0x40) >= 0xBD)
            return;
        k = hi * 2 - 0x130 - (lo < 0x7F);
        e = &kanji_2_table[k];
        idx = c - e->code + e->base;
        p = (s8 *)ch->font[3];
    }
    if ((unsigned int)(c - 0xE040) < 0xA63) {
        if (!(s_windsystemChar.flags & 0x1000))
            return;
        if ((unsigned int)(lo - 0x40) >= 0xBD)
            return;
        k = hi * 2 - 0x1C0 + (lo >= 0x7F ? 0x10 : 0xF);
        e = &kanji_2_table[k];
        idx = c - e->code + e->base;
        p = (s8 *)s_windsystemChar.font[3];
    }
    if (idx == -1)
        return;
    d = buf;
    p += idx * s_windsystemChar.wbytes;
    for (n = s_windsystemChar.wbytes; n > 0; n--) {
        b = *p++;
        *d++ = (b & 0x80) ? color : 0;
        *d++ = (b & 0x40) ? color : 0;
        *d++ = (b & 0x20) ? color : 0;
        *d++ = (b & 0x10) ? color : 0;
        *d++ = (b & 0x08) ? color : 0;
        *d++ = (b & 0x04) ? color : 0;
        *d++ = (b & 0x02) ? color : 0;
        *d++ = (b & 0x01) ? color : 0;
    }
    zWindDrawImage(x, y, s_windsystemChar.w, s_windsystemChar.bpp, buf, 0);
}

void zWindFontDrawPassword(ZGFONT *f, int x, int y, char *s, short color, int len) {
    int i;
    int k;
    s8 c;

    if (f == NULL) {
        return;
    }
    if (f->type != 4) {
        return;
    }
    if (s == NULL) {
        return;
    }
    switch (D_00584BB6) {
    case 1:
        i = pspBrowserUtf8ToSjis(0, s, len);
        break;
    case 8:
        k = 0;
        i = 0;
        while (k < len) {
            c = s[i];
            if (c >= 0) {
                k += 1;
            } else if ((c & 0xE0) == 0xC0) {
                k += 2;
            } else if ((c & 0xF0) == 0xE0) {
                k += 3;
            } else if ((c & 0xF8) == 0xF0) {
                k += 4;
            } else if ((c & 0xFC) == 0xF8) {
                k += 5;
            } else if ((c & 0xFE) == 0xFC) {
                k += 6;
            } else {
                return;
            }
            i++;
        }
        break;
    }
    len = i < len ? i : len;
    color |= 0x8000;
    for (i = 0; i < len; i++) {
        zWindFontDrawHF(f, x + i * f->w, y, '*', color);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDraw);

void zWindFontDrawSJ(ZGFONT *f, int x, int y, u8 *s, short color, int len) {
    int i;
    s16 cw;
    int cw2;
    int c;

    if (f == NULL) {
        if (D_00584B68 == NULL) {
            return;
        }
        f = D_00584B68;
    }
    if (f->type != 4) {
        return;
    }
    if (s == NULL) {
        return;
    }
    if (y > _zWindDrawTexClipY2) {
        return;
    }
    if (y + f->h < _zWindDrawTexClipY) {
        return;
    }
    if (D_00584BB6 != 1) {
        return;
    }
    cw = f->w;
    cw2 = f->w * 2;
    color |= 0x8000;
    for (i = 0; i < len;) {
        c = s[i];
        if (c < 0x81 || (c >= 0xA0 && c <= 0xDF)) {
            if (c == 0) {
                return;
            }
            zWindFontDrawHF(f, x, y, c, color);
            i++;
            x += cw;
        } else {
            zWindFontDrawZE(f, x, y, (s[i] << 8) + s[i + 1], color);
            i += 2;
            x += cw2;
        }
        if (x > _zWindDrawTexClipX2) {
            return;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDrawArea);

void zWindDrawUpdate(ZW *w, int x, int y, int wd, int h) {
    ZW *p;

    for (p = w; p != NULL; p = p->parent) {
        if ((p->flags & 0xF) == 12) {
            GUI_ScrollPane_getScrollPosition(p, &_zWindDrawTexClipOffAX, &_zWindDrawTexClipOffAY);
            zWindDrawClipSet(x, y, wd, h);
            p->draw(w, s_windsystem_data.unk1C, p->arg, x, y, wd, h);
            zWindDrawClipSet(0, 0, ((ZINIT *)&s_windsystem_init)->width, ((ZINIT *)&s_windsystem_init)->height);
            return;
        }
    }
}

void zWindChangeFont(void) {
    if (_zWindFontWidth == 0 || _zWindFontHeight == 0) {
        return;
    }
    _zWindDrawTexdata = (int)_zWindFontImage;
    _zWindDrawTexWidth = _zWindFontWidth;
    _zWindDrawTexHeight = _zWindFontHeight;
    _zWindDrawTexClipX = 0;
    _zWindDrawTexClipY = 0;
    _zWindDrawTexClipWidth = ((ZINIT *)&s_windsystem_init)->width;
    _zWindDrawTexClipHeight = ((ZINIT *)&s_windsystem_init)->height;
    _zWindDrawTexClipX2 = ((ZINIT *)&s_windsystem_init)->width;
    _zWindDrawTexClipY2 = ((ZINIT *)&s_windsystem_init)->height;
}

void zWindSetFontClip(void *img, int w, int h) {
    _zWindFontImage = img;
    _zWindFontWidth = w;
    _zWindFontHeight = h;
    _zWindDrawTexdata = (int)img;
    _zWindDrawTexWidth = w;
    _zWindDrawTexHeight = h;
    _zWindDrawTexClipX = 0;
    _zWindDrawTexClipY = 0;
    _zWindDrawTexClipWidth = ((ZINIT *)&s_windsystem_init)->width;
    _zWindDrawTexClipHeight = ((ZINIT *)&s_windsystem_init)->height;
    _zWindDrawTexClipX2 = ((ZINIT *)&s_windsystem_init)->width;
    _zWindDrawTexClipY2 = ((ZINIT *)&s_windsystem_init)->height;
}

int zWindExcEventButton(ZW *w, int type, ZEVENT *ev) {
    switch (type) {
    case 1:
        if (ev->button != 1) {
            break;
        }
        w->u.b.pressed = 1;
        zWindDraw();
        ev->target = w;
        break;
    case 2:
        if (ev->button != 1) {
            break;
        }
        w->u.b.pressed = 0;
        zWindDraw();
        ev->target = w;
        break;
    case 7:
        if (ev->key == 0xA2) {
            w->u.b.pressed = 1;
        } else if (ev->key == 0xA3) {
            w->u.b.pressed = 0;
        } else {
            break;
        }
        zWindDraw();
        ev->target = w;
        return 0;
    }
    return -1;
}

int zWindExcEventCheckbox(ZW *w, int type, ZEVENT *ev) {
    switch (type) {
    case 7:
        if (ev->key != 0x80) {
            break;
        }
        if (GUI_Checkbox_getState(w) == 1) {
            GUI_Checkbox_setState(w, 0);
        } else {
            GUI_Checkbox_setState(w, 1);
        }
        zWindDraw();
        ev->target = w;
        break;
    case 3:
        if (ev->button != 1) {
            break;
        }
        if (GUI_Checkbox_getState(w) == 1) {
            GUI_Checkbox_setState(w, 0);
        } else {
            GUI_Checkbox_setState(w, 1);
        }
        zWindDraw();
        ev->target = w;
        break;
    }
    return -1;
}

int zWindExcEventRadiobox(ZW *w, int type, ZEVENT *ev) {
    ZW *g;

    switch (type) {
    case 7:
        if (ev->key != 0x80) {
            break;
        }
        g = GUI_RadioButton_getGroup(w);
        if (g->arg != w) {
            GUI_RadioButton_setState(g->arg, 0);
            GUI_RadioButton_setState(w, 1);
            g->arg = w;
            zWindDraw();
        }
        ev->target = w;
        break;
    case 3:
        if (ev->button != 1) {
            break;
        }
        g = GUI_RadioButton_getGroup(w);
        if (g->arg != w) {
            GUI_RadioButton_setState(g->arg, 0);
            GUI_RadioButton_setState(w, 1);
            g->arg = w;
            zWindDraw();
        }
        ev->target = w;
        break;
    }
    return -1;
}

int zWindExcEventList(ZW *w, int type, ZEVENT *ev, int x, int y);
int zWindExcEventList(ZW *w, int type, ZEVENT *ev, int x, int y) {
    int left;
    int top;
    int right;
    int bottom;
    int h;
    int i;
    int lim;

    switch (type) {
    case 7:
        if (ev->key != 0x80) {
            break;
        }
        if (!(D_00584BCC & 0x20000000)) {
            s_windsystem_data.mode = 1;
            s_windsystem_data.target = w;
        }
        return 0;
    case 3:
        if (!(D_00584BCC & 0x20000000))
            goto fail;
        left = w->px;
        top = w->py;
        right = left + w->w;
        bottom = top + w->h;
        if (x < left) {
            return -1;
        }
        if (right < x) {
            return -1;
        }
        if (y < top) {
            return -1;
        }
        if (bottom < y) {
            return -1;
        }
        h = w->font->height;
        if (right - 16 < x) {
            if (y < top + 16) {
                M2C_FIELD(w, s16 *, 0x5C) += h;
                if (M2C_FIELD(w, s16 *, 0x5C) > 0) {
                    M2C_FIELD(w, s16 *, 0x5C) = 0;
                }
                zWindDraw();
            }
            if (bottom - 16 < y) {
                y = w->h - 4;
                M2C_FIELD(w, s16 *, 0x5C) -= h;
                if (M2C_FIELD(w, s16 *, 0x5C) < y - h * M2C_FIELD(w, s16 *, 0x5A)) {
                    M2C_FIELD(w, s16 *, 0x5C) = y - h * M2C_FIELD(w, s16 *, 0x5A);
                    lim = M2C_FIELD(w, s16 *, 0x5C);
                    if (lim > 0) {
                        M2C_FIELD(w, s16 *, 0x5C) = 0;
                    }
                }
                zWindDraw();
            }
            break;
        }
        i = (y - M2C_FIELD(w, s16 *, 0x5C) - top - 2) / h;
        if (i < 0) {
            return -1;
        }
        if (i >= M2C_FIELD(w, s16 *, 0x5A)) {
            return -1;
        }
        M2C_FIELD(w, s16 *, 0x58) = i;
        if (M2C_FIELD(w, int *, 0x4C) == 1) {
            if (GUI_List_isIndexSelected(w, i) == 1) {
                GUI_List_deselect(w, i);
            } else {
                GUI_List_select(w, i);
            }
        }
        s_windsystem_data.flags |= 0x10;
        zWindDraw();
        return 0;
    }
fail:
    return -1;
}

int zWindExcEventChoice(void *w, int type, ZEVENT *ev) {
    switch (type) {
    case 7:
        if (ev->key == 0x80) {
            s_windsystem_data.mode = 2;
            s_windsystem_data.target = w;
            return 0;
        }
        break;
    case 3:
        if (D_00584BCC & 0x20000000) {
            s_windsystem_data.mode = 3;
            s_windsystem_data.target = w;
            zWindDraw();
            return 0;
        }
        break;
    }
    return -1;
}

int zWindChoiceButton(ZW *w, int x, int y) {
    int fh = w->font->height;
    int left = w->px;
    int top;
    int right;
    int bottom;
    int idx;
    int lim;
    if (w->py < D_00584BC8 / 2) {
        top = w->py + w->h;
    } else {
        top = w->py - fh * 5 - 4;
    }
    right = left + w->w;
    bottom = top + fh * 5 + 4;
    if (x < left) {
        return -1;
    }
    if (right < x) {
        return -1;
    }
    if (y < top) {
        return -1;
    }
    if (bottom < y) {
        return -1;
    }
    if (right - 16 < x) {
        if (y < top + 16) {
            M2C_FIELD(w, s16 *, 0x58) += fh;
            if (M2C_FIELD(w, s16 *, 0x58) > 0) {
                M2C_FIELD(w, s16 *, 0x58) = 0;
            }
            zWindDraw();
        }
        if (bottom - 16 < y) {
            x = fh * 5;
            M2C_FIELD(w, s16 *, 0x58) -= fh;
            if (M2C_FIELD(w, s16 *, 0x58) < x - fh * w->u.b.pressed) {
                M2C_FIELD(w, s16 *, 0x58) = x - fh * w->u.b.pressed;
                lim = M2C_FIELD(w, s16 *, 0x58);
                if (lim > 0) {
                    M2C_FIELD(w, s16 *, 0x58) = 0;
                }
            }
            zWindDraw();
        }
        return 0;
    }
    idx = (y - M2C_FIELD(w, s16 *, 0x58) - top - 2) / fh;
    if (idx < 0) {
        return 0;
    }
    if (idx >= w->u.b.pressed) {
        return 0;
    }
    GUI_Choice_select(w, idx);
    zWindWidgetChoiceListDelete(s_windsystem_data.target);
    s_windsystem_data.mode = 0;
    s_windsystem_data.target = NULL;
    return -1;
}

int zWindExcEventTextField(ZWIDGET *w, int type, ZEVENT *ev) {
    switch (type) {
    case 7:
        if (ev->key != 0x80) {
            break;
        }
        if (w->editable == 0) {
            return 0;
        }
        break;
    case 3:
        if (!(D_00584BCC & 0x20000000)) {
            break;
        }
        if (w->editable == 0) {
            return 0;
        }
        break;
    }
    return -1;
}

int zWindExcEventTextArea(ZW *w, int type, ZEVENT *ev, int x, int y);
typedef struct {
    u8 unk0[0x52];
    s16 line;                   /* 0x52 */
    s16 lines;                  /* 0x54 */
    s16 unk56;
    int editable;               /* 0x58 */
} ZTAREA;

int zWindExcEventTextArea(ZW *w, int type, ZEVENT *ev, int x, int y) {
    int left;
    int top;
    int right;
    int bottom;
    switch (type) {
    case 7:
        if (ev->key != 0x80) {
            break;
        }
        if (M2C_FIELD(w, int *, 0x58) == -1) {
            break;
        }
        s_windsystem_data.mode = 4;
        s_windsystem_data.target = w;
        return 0;
    case 3:
        if (!(D_00584BCC & 0x20000000)) {
            break;
        }
        if (M2C_FIELD(w, int *, 0x58) == -1) {
            break;
        }
        left = w->px;
        top = w->py;
        right = left + w->w;
        bottom = top + w->h;
        if (x < left) {
            return 0;
        }
        if (right < x) {
            return 0;
        }
        if (y < top) {
            return 0;
        }
        if (bottom < y) {
            return 0;
        }
        if (right - 16 < x) {
        if (y < top + 16) {
            M2C_FIELD(w, s16 *, 0x52)--;
            if (M2C_FIELD(w, s16 *, 0x52) < 0) {
                M2C_FIELD(w, s16 *, 0x52) = 0;
            } else {
                zWindDraw();
            }
        }
        if (bottom - 16 < y) {
            M2C_FIELD(w, s16 *, 0x52)++;
            if (M2C_FIELD(w, s16 *, 0x52) >= M2C_FIELD(w, s16 *, 0x54)) {
                M2C_FIELD(w, s16 *, 0x52) = M2C_FIELD(w, s16 *, 0x54);
            } else {
                zWindDraw();
            }
        }
        }
        return 0;
    }
    return -1;
}

extern void (*D_00584B60)(ZW *w, ZEVENT *ev);

void zWindExcEvent(ZW *w, int type, ZEVENT *ev, int x, int y) {
    *(s16 *)ev = type;
    ev->target = w;
    while (w != NULL) {
        if (w->type != 1) {
            puts("[X]zWindExcEvent");
            return;
        }
        if (w == (ZW *)s_windsystem_data.unk14 && s_windsystem_data.unk10 != 0) {
            ((void (*)(ZW *, ZEVENT *))s_windsystem_data.unk10)(w, ev);
            return;
        }
        switch (w->flags & 0xF) {
        case 3:
            if (zWindExcEventButton(w, type, ev) == 0) {
                return;
            }
            break;
        case 4:
            if (zWindExcEventCheckbox(w, type, ev) == 0) {
                return;
            }
            break;
        case 6:
            if (zWindExcEventRadiobox(w, type, ev) == 0) {
                return;
            }
            break;
        case 8:
            if (zWindExcEventList(w, type, ev, x, y) == 0) {
                return;
            }
            break;
        case 9:
            if (zWindExcEventChoice(w, type, ev) == 0) {
                return;
            }
            break;
        case 10:
            if (zWindExcEventTextField((ZWIDGET *)w, type, ev) == 0) {
                return;
            }
            break;
        case 11:
            if (zWindExcEventTextArea(w, type, ev, x, y) == 0) {
                return;
            }
            break;
        }
        w = w->parent;
    }
    if (D_00584B60 != NULL) {
        D_00584B60(w, ev);
    }
}
