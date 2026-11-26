/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
extern int l_pfnUtil;


INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE7C4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontOpen);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE7E8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontClose);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", textGetLine);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE808);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE810);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE818);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE820);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE824);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", l_afAlign);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE838);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontPrepare);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE85C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE864);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontReplace);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE898);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontInitEx);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontDraw);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", ttrFontClear);

#ifndef NULL
#define NULL ((void *)0)
#endif

int UtilityLink(int arg0) {
    int var_v1;

    var_v1 = 0;
    if (l_pfnUtil == 0) {
        l_pfnUtil = arg0;
        var_v1 = 1;
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void UtilityUnlink(void) {
    l_pfnUtil = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", UtilityUpdate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", UtilityState);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", D_000FE900);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", _ProgFrameIn_InitGame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", _ProgFrameIn_InitTgs);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", _ProgName_InitGame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/ttrfont", _ProgName_InitTgs);
