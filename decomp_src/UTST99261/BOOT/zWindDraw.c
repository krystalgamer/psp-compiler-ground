/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
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
M2C_UNK zWindLineBox2(short, short, short, short, M2C_UNK, M2C_UNK); /* extern */



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDraw);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindFontSet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindLocateSet);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindLocateGet);

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
    _zWindDrawTexClipWidth = M2C_FIELD(&s_windsystem_init, int *, 0xC);
    _zWindDrawTexClipHeight = M2C_FIELD(&s_windsystem_init, int *, 0x10);
    _zWindDrawTexClipX2 = M2C_FIELD(&s_windsystem_init, int *, 0xC);
    _zWindDrawTexClipY2 = M2C_FIELD(&s_windsystem_init, int *, 0x10);
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawBoxP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawLineW);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindDrawLineH);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindLineBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindLineBoxP);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindLineBox2);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindChangeFont);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindSetFontClip);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventCheckbox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventRadiobox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventList);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventChoice);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindChoiceButton);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventTextField);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEventTextArea);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/zWindDraw", zWindExcEvent);
