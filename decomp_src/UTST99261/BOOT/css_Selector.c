/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", _getOneSelectorText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", _getSelectorText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_getCssText);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getLength(void *arg0) {
    void *temp_v0;

    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 9) || (temp_v0 = M2C_FIELD(arg0, void **, 4), (temp_v0 == NULL))) {
        return 0;
    }
    return M2C_FIELD(temp_v0, int *, 8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_Selector", CSSSelector_item);

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getName(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 9)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x24);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
short CSSSelector_getType(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 9)) {
        return -1;
    }
    return M2C_FIELD(arg0, short *, 0x1C);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getCombine(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 9)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0x20);
}

void *CSSSelector_getClass(s16 *s) {
    if (s != NULL) {
        if (*s == 9) {
            return (char *)s + 0x28;
        }
    }
    return NULL;
}

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

void *CSSSelector_getId(s16 *s) {
    if (s != NULL) {
        if (*s == 9) {
            return (char *)s + 0x30;
        }
    }
    return NULL;
}

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

void *CSSSelector_getPseudo(s16 *s) {
    if (s != NULL) {
        if (*s == 9) {
            return (char *)s + 0x38;
        }
    }
    return NULL;
}

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

void *CSSSelector_getAttribute(s16 *s) {
    if (s != NULL) {
        if (*s == 9) {
            return (char *)s + 0x40;
        }
    }
    return NULL;
}

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

#ifndef NULL
#define NULL ((void *)0)
#endif
int CSSSelector_getCssStyleDeclarations(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0) != 9)) {
        return 0;
    }
    return M2C_FIELD(arg0, int *, 0xC);
}

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
