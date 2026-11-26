/* cflags: -O1 */
#include "common.h"
#include "css_types.h"
#include "m2c_macros.h"
CSSVALUE *newCSSValue();
void addCSSValue(void *decl, CSSVALUE *v);
void freeCSSValue(CSSVALUE *v);
u16 *CSS_SkipProperty(u16 *p);
u16 *CSS_SkipBlanksAndComments(u16 *p);
u16 *ParseUNIT(s16 *out, u16 *p);
u16 *ParseIDENT(s16 *out, u16 *p, int k);
u16 *ParseURL(s16 *out, u16 *p);
u16 *ParseCOLOR(s16 *out, u16 *p);
u16 *ParseRECT(s16 *out, u16 *p);
u16 *ParseCOUNTER(s16 *out, u16 *p);
u16 *ParseATTR(s16 *out, u16 *p);
u16 *CSS_string(u16 *p, u16 **out);


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseUNIT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseIDENT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseURL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCOLOR);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseRECT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCOUNTER);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseATTR);

u16 *ParseCSSIdent(CSSVALUE *v, u16 *p, int k) {
    u16 *r;
    if (v == NULL) {
        return NULL;
    }
    r = ParseIDENT(&v->unit, p, k);
    if (r != NULL) {
        if (k == 0x4D) {
            v->type = 1;
        } else {
            v->type = 2;
        }
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseCSSUnit(CSSVALUE *v, u16 *p) {
    u16 *r;
    if (v == NULL) {
        return NULL;
    }
    r = ParseUNIT(&v->unit, p);
    if (r != NULL) {
        v->type = 2;
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseCSSURL(CSSVALUE *v, u16 *p) {
    u16 *r;
    if (v == NULL) {
        return NULL;
    }
    r = ParseURL(&v->unit, p);
    if (r != NULL) {
        v->type = 2;
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseCSSRECT(CSSVALUE *v, u16 *p) {
    u16 *r;
    if (v == NULL) {
        return NULL;
    }
    r = ParseRECT(&v->unit, p);
    if (r != NULL) {
        v->type = 2;
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseCSSCounter(CSSVALUE *v, u16 *p) {
    u16 *r;
    if (v == NULL) {
        return NULL;
    }
    r = ParseCOUNTER(&v->unit, p);
    if (r != NULL) {
        v->type = 2;
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseCSSATTR(CSSVALUE *v, u16 *p) {
    u16 *r;
    if (v == NULL) {
        return NULL;
    }
    r = ParseATTR(&v->unit, p);
    if (r != NULL) {
        v->type = 2;
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseCSSColor(CSSVALUE *v, u16 *p) {
    u16 *r;
    if (v == NULL) {
        return NULL;
    }
    r = ParseCOLOR(&v->unit, p);
    if (r != NULL) {
        v->type = 2;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSString);

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseBackgroundAttachment(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x94)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x41)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

u16 *ParseBackgroundColor(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xBA)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        r = ParseCSSColor(v, p);
    }
    return r;
}

u16 *ParseBackgroundImage(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSURL(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x79)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseBackgroundPosition);

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseBackgroundRepeat(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x88)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x89)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x8A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x78)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBackground);

u16 *ParseCSSBackgroundAttachment(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBackgroundAttachment(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBackgroundColor(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBackgroundColor(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBackgroundImage(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBackgroundImage(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBackgroundPosition(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBackgroundPosition(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBackgroundRepeat(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBackgroundRepeat(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseBorderColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseBorderStyle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseBorderWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBorderBottom);

u16 *ParseCSSBorderBottomColor(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBorderColor(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBorderBottomStyle(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBorderStyle(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBorderBottomWidth(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBorderWidth(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBorderCollapse(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x24)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x98)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBorderColor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBorderSpacing);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBorderStyle);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBorderWidth);

u16 *ParseCSSBottom(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSCaptionSide(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xB9)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x19)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x5A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x8D)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSClear(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x79)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x5A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x8D)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x18)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSClip(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSRECT(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSForeground(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) == NULL &&
        (r = ParseCSSColor(v, p)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSCounterIncrement);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSCounterReset);

u16 *ParseCSSDirection(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x69)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x90)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSDisplay(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4E)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x15)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x60)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x91)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x25)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x6B)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xAB)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4F)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB3)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB1)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB0)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB2)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xAF)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xAE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xAD)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xAC)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x79)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSEmptyCells(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x9A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x47)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSFloat(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x5A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x8D)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x79)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseFontStyle(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x53)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x7D)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseFontVariant(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x9F)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseFontWeight);

u16 *ParseFontSize(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xD0)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xCD)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x9E)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x6C)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x58)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xC9)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xCF)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x59)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xA1)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

u16 *ParseLineHeight(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x7A)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseFontFamily);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSFont);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSFontFamily);

u16 *ParseCSSFontSize(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseFontSize(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSFontSizeAdjust(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x79)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSFontStretch(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xC6)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x74)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xBB)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x39)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x26)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x96)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x97)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x38)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x3A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xBC)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSFontStyle(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseFontStyle(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSFontVariant(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseFontVariant(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSFontWeight(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseFontWeight(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSLetterSpacing(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSLineHeight(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseListStyleImage(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSURL(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x79)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseListStylePosition(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x51)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x81)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

u16 *ParseListStyleType(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x79)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x33)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x20)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xA5)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x2F)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x30)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x67)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xC0)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x65)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x64)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x66)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xBE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xBF)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x44)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xC)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x42)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x21)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x55)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4B)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x56)) == NULL) {
        r = ParseCSSIdent(v, p, 0x4D);
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSListStyle);

u16 *ParseCSSListStyleImage(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseListStyleImage(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSListStylePosition(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseListStylePosition(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSListStyleType(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseListStyleType(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSMarginWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSMargin);

u16 *ParseCSSMarginTop(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        p = CSS_SkipBlanksAndComments(p);
        r = ParseCSSMarginWidth(v, p);
        if (r != NULL) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

u16 *ParseCSSMarkerOffset(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSMarks);

u16 *ParseCSSMaxHeight(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x79)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSMinHeight(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSOrphans(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSOutline);

u16 *ParseCSSOutlineColor(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x52)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL &&
        (r = ParseCSSColor(v, p)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSOutlineStyle);

u16 *ParseCSSOverflow(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xC3)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x46)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x94)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSPaddingTop(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSPadding);

u16 *ParseCSSPageBreakAfter(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xF)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x5A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x8D)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSPageBreakInside(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xF)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSPosition(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xA6)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x87)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xA)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x41)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSQuotes);

u16 *ParseCSSTableLayout(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x41)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSTextAlign(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x5A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x8D)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x1C)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x54)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL &&
        (r = ParseCSSString(v, p)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSTextDecoration);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSTextShadow);

u16 *ParseCSSTextTransform(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x1A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xC1)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x68)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x79)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSUnicodeBidi(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x37)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x13)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSVerticalAlign(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x10)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x6F)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xA8)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xA9)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB6)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB5)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xB9)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x19)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSVisibility(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xC3)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x46)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x24)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSWhiteSpace(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x85)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x7B)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSWordSpacing(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x7A)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSZIndex(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) == NULL &&
        (r = ParseCSSIdent(v, p, 0xE)) == NULL &&
        (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
    addCSSValue(decl, v);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", find_Property);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSDeclaration);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", CSSUnitNames);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", CSSPropertyNames);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", CSSPropertyIndexTable);
