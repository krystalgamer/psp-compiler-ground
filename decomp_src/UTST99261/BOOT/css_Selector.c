/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"



void *CSS_newPoolBuf(void);
void CSS_putsPoolBuf(void *pb, void *s);
void *CSS_getPoolBuf(void *pb);
void CSS_freePoolBuf(void *pb);
void *_getSelectorText(void *sel);
void *CSSStyleDeclaration_getCssText(void *decl);
void MEM_free(int pool, void *p);
void *_getOneSelectorText(void *sel);
void CSS_putSPoolBuf(void *pb, const char *s);
typedef struct CSSSelLst { struct CSSSelLst *next; void *name; } CSSSelLst;
void *_getOneSelectorText(void *sel)
{
    void *pb;
    void *s;
    void *r;
    CSSSelLst *l;

    if (sel == NULL || M2C_FIELD(sel, short *, 0) != 9)
        return NULL;
    pb = CSS_newPoolBuf();
    r = NULL;
    if (pb != NULL) {
        CSS_putsPoolBuf(pb, M2C_FIELD(sel, void **, 0x24));
        if (M2C_FIELD(sel, void **, 0x34) != NULL) {
            CSS_putSPoolBuf(pb, "#");
            CSS_putsPoolBuf(pb, M2C_FIELD(sel, void **, 0x34));
            for (l = M2C_FIELD(sel, CSSSelLst **, 0x30); l != NULL; l = l->next) {
                if (l->name != NULL) {
                    CSS_putSPoolBuf(pb, "#");
                    CSS_putsPoolBuf(pb, l->name);
                }
            }
        }
        if (M2C_FIELD(sel, void **, 0x2C) != NULL) {
            CSS_putSPoolBuf(pb, ".");
            CSS_putsPoolBuf(pb, M2C_FIELD(sel, void **, 0x2C));
            for (l = M2C_FIELD(sel, CSSSelLst **, 0x28); l != NULL; l = l->next) {
                if (l->name != NULL) {
                    CSS_putSPoolBuf(pb, ".");
                    CSS_putsPoolBuf(pb, l->name);
                }
            }
        }
        if (M2C_FIELD(sel, void **, 0x44) != NULL) {
            CSS_putSPoolBuf(pb, "[");
            CSS_putsPoolBuf(pb, M2C_FIELD(sel, void **, 0x44));
            CSS_putSPoolBuf(pb, "]");
            for (l = M2C_FIELD(sel, CSSSelLst **, 0x40); l != NULL; l = l->next) {
                if (l->name != NULL) {
                    CSS_putSPoolBuf(pb, "[");
                    CSS_putsPoolBuf(pb, l->name);
                    CSS_putSPoolBuf(pb, "]");
                }
            }
        }
        if (M2C_FIELD(sel, void **, 0x3C) != NULL) {
            CSS_putSPoolBuf(pb, ":");
            CSS_putsPoolBuf(pb, M2C_FIELD(sel, void **, 0x3C));
            for (l = M2C_FIELD(sel, CSSSelLst **, 0x38); l != NULL; l = l->next) {
                if (l->name != NULL) {
                    CSS_putSPoolBuf(pb, ":");
                    CSS_putsPoolBuf(pb, l->name);
                }
            }
        }
        s = CSS_getPoolBuf(pb);
        CSS_freePoolBuf(pb);
        r = s;
    }
    return r;
}

void *_getSelectorText(void *sel)
{
    void *pb;
    void *s;
    void *p;
    void *r;

    if (sel == NULL || M2C_FIELD(sel, short *, 0) != 9)
        return NULL;
    pb = CSS_newPoolBuf();
    r = NULL;
    if (pb != NULL) {
        if (M2C_FIELD(sel, void **, 0x20) != NULL) {
            p = M2C_FIELD(sel, void **, 0x20);
            while (M2C_FIELD(p, void **, 0x20) != NULL)
                p = M2C_FIELD(p, void **, 0x20);
            for (; p != NULL; p = M2C_FIELD(p, void **, 0x14)) {
                s = _getOneSelectorText(p);
                CSS_putsPoolBuf(pb, s);
                MEM_free(0, s);
                if (M2C_FIELD(p, u16 *, 0x1C) & 4)
                    CSS_putSPoolBuf(pb, " + ");
                else if (M2C_FIELD(p, u16 *, 0x1C) & 2)
                    CSS_putSPoolBuf(pb, " > ");
                else
                    CSS_putSPoolBuf(pb, " ");
            }
        }
        s = _getOneSelectorText(sel);
        CSS_putsPoolBuf(pb, s);
        MEM_free(0, s);
        s = CSS_getPoolBuf(pb);
        CSS_freePoolBuf(pb);
        r = s;
    }
    return r;
}

void *CSSSelector_getCssText(void *sel) {
    void *pb;
    void *s;
    void *r;

    if (sel == NULL || M2C_FIELD(sel, short *, 0) != 9)
        return NULL;
    pb = CSS_newPoolBuf();
    r = NULL;
    if (pb != NULL) {
        s = _getSelectorText(sel);
        CSS_putsPoolBuf(pb, s);
        MEM_free(0, s);
        s = CSSStyleDeclaration_getCssText(M2C_FIELD(sel, void **, 0xC));
        CSS_putsPoolBuf(pb, s);
        MEM_free(0, s);
        sel = CSS_getPoolBuf(pb);
        CSS_freePoolBuf(pb);
        r = sel;
    }
    return r;
}

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

void *CSSSelector_item(void *x, int idx) {
    void *r;
    int i;
    if (x == NULL || M2C_FIELD(x, s16 **, 4) == NULL || *M2C_FIELD(x, s16 **, 4) != 8 ||
        idx >= M2C_FIELD(M2C_FIELD(x, void **, 4), int *, 8)) {
        return NULL;
    }
    for (r = M2C_FIELD(M2C_FIELD(x, void **, 4), void **, 0xC), i = 0; r != NULL && i < idx; i++) {
        r = M2C_FIELD(r, void **, 0x18);
    }
    if (i == idx) {
        return r;
    }
    return NULL;
}

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
