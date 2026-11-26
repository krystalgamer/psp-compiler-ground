/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct {
    u8 unk0[0xC];
    int flags;                  /* 0xC */
    u8 unk10[0x10];
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
    u8 unk0[0x8];
    u16 key;                    /* 0x8 */
} ZEVENT;

extern ZWINDDATA s_windsystem_data;
extern int _i_windsystemOn;
extern int D_00584BCC;
extern void *_zWindFontImage;
extern int _zWindFontWidth;
extern int _zWindFontHeight;
int GUI_ScrollPane_getScrollPosition();
void zWindDrawBox();
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
void zWindDrawLineH(int x, int y, int len, short color);
extern int _zWindDrawTexClipOffX;
extern int _zWindDrawTexClipOffY;



int zWindDraw(void) {
    int r;

    r = 0;
    if (_i_windsystemOn) {
        s_windsystem_data.flags |= 1;
        r = 1;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontSet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindLocateSet);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindPartsSet);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawClipSet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawClipSetTex);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawBox);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawLineW);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawLineH);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawImage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawImageScl);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawParts);

#ifndef NULL
#define NULL ((void *)0)
#endif

void zWindWidgetFrameDraw(void *arg0) {
    zWindLineBox2(M2C_FIELD(arg0, short *, 0x36), M2C_FIELD(arg0, short *, 0x38), M2C_FIELD(arg0, short *, 0x3E), M2C_FIELD(arg0, short *, 0x40), 0, 0x7FFF);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetButtonDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetCheckboxDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetRadioboxDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetListDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetChoiceDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetChoiceListDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetChoiceListDelete);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetTextAreaDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetTextFieldDraw);

void zWindWidgetContentviewDraw(void) {
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindWidgetDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDrawHF);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDrawZE_K);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDrawZE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDrawPassword);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDrawSJ);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontDrawArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawUpdate);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventCheckbox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventRadiobox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventList);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindChoiceButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventTextField);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventTextArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEvent);
