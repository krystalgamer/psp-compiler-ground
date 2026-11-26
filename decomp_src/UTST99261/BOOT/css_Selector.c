#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", _getOneSelectorText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", _getSelectorText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getCssText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getLength);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_item);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getCombine);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getClass);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getClassName(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getNextClass(int *arg0) {
    return *arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getId);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getIdName(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getNextId(int *arg0) {
    return *arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getPseudo);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getPseudoName(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getNextPseudo(int *arg0) {
    return *arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getAttribute);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getAttributeName(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getNextAttribute(int *arg0) {
    return *arg0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getCssStyleDeclarations);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_CDO);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_CDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_PLS);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_GT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_SP);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_ASTERISK);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_EQUALS);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_INCLUDES);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_DASHMATCH);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_important);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_charset);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_media);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_import);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_page);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_font_face);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_all);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_screen);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_tty);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_tv);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_projection);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_handheld);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_print);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_braille);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_embossed);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_aural);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_pt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_pc);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_cm);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_mm);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_in);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_px);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_em);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSTR_ex);
