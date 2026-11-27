/* cflags: -O1 */
#include "common.h"
#include "css_types.h"
#include "m2c_macros.h"
u16 *CSS_nstring(u16 *p, u16 **out);
typedef struct CSSPROPNAME { u16 *name; u16 id; } CSSPROPNAME;
extern CSSPROPNAME CSSPropertyNames[];
extern int CSSPropertyIndexTable[];
int UCS_strcasecmp(u16 *a, u16 *b);
CSSVALUE *duplicateCSSValue(CSSVALUE *v);
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


typedef struct CSSUNITVAL { s16 unit; s16 pad; int x4; double val; int x10[4]; } CSSUNITVAL;
u16 *CSS_ident(u16 *s, u16 **out);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseUNIT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseIDENT);

u16 *ParseURL(s16 *out, u16 *p) {
    u16 *s;
    u16 *str;
    u16 *r;
    r = ParseIDENT(out, p, 0xC2);
    if (r == NULL) {
        return NULL;
    }
    p = CSS_SkipBlanksAndComments(r);
    if (*p == '(') {
        p = CSS_SkipBlanksAndComments(p + 1);
    }
    p = CSS_string(p, &s);
    str = s;
    if (str == NULL) {
        p = CSS_nstring(p, &s);
        str = s;
    }
    if (str != NULL) {
        out[0] = 0x14;
        *(u16 **)(out + 4) = str;
    }
    p = CSS_SkipBlanksAndComments(p);
    if (*p == ')') {
        p++;
    }
    return p;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCOLOR);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseRECT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCOUNTER);

u16 *ParseATTR(s16 *out, u16 *p) {
    u16 *s;
    u16 *str;
    u16 *r;
    r = ParseIDENT(out, p, 0xD);
    if (r == NULL) {
        return NULL;
    }
    p = CSS_SkipBlanksAndComments(r);
    if (*p == '(') {
        p++;
    }
    p = CSS_SkipBlanksAndComments(p);
    p = CSS_string(p, &s);
    str = s;
    if (str == NULL) {
        p = CSS_nstring(p, &s);
        str = s;
    }
    if (str != NULL) {
        out[0] = 0x16;
        *(u16 **)(out + 4) = str;
    }
    p = CSS_SkipBlanksAndComments(p);
    if (*p == ')') {
        p++;
    }
    return p;
}

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

u16 *ParseCSSString(CSSVALUE *v, u16 *p) {
    u16 *s;
    u16 *str;
    if (v == NULL) {
        return NULL;
    }
    p = CSS_string(p, &s);
    str = s;
    if (str == NULL) {
        return NULL;
    }
    v->type = 2;
    v->unit = 0x13;
    *(u16 **)&v->ident = str;
    return p;
}

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

u16 *ParseCSSBackground(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    int flags;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        flags = 0;
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            if (v == NULL && (v = newCSSValue()) == NULL) {
                return p;
            }
            if (!(flags & 1) && (r = ParseBackgroundImage(v, p)) != NULL) {
                flags |= 1;
            } else if (!(flags & 2) && (r = ParseBackgroundAttachment(v, p)) != NULL) {
                flags |= 2;
            } else if (!(flags & 4) && (r = ParseBackgroundRepeat(v, p)) != NULL) {
                flags |= 4;
            } else if (!(flags & 8) && (r = ParseBackgroundPosition(v, p)) != NULL) {
            } else if (!(flags & 0x10) && (r = ParseBackgroundColor(v, p)) != NULL) {
                flags |= 0x10;
            } else {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = NULL;
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
            if (flags == 0x1F) {
                break;
            }
        }
    }
    return p;
}

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

u16 *ParseBorderColor(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0xBA)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x4D)) != NULL) {
        return r;
    }
    if ((r = ParseCSSColor(v, p)) == NULL) {
        return NULL;
    }
    return r;
}

u16 *ParseBorderStyle(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x79)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0xA3)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x35)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x43)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x8C)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x50)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x80)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x2E)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x34)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x46)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        return NULL;
    }
    return r;
}

u16 *ParseBorderWidth(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0xB8)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x6C)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0xB7)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        return NULL;
    }
    return r;
}

u16 *ParseCSSBorder(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    int flags;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        flags = 0;
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            if (v == NULL && (v = newCSSValue()) == NULL) {
                return p;
            }
            if (!(flags & 1) && (r = ParseBorderWidth(v, p)) != NULL) {
                flags |= 1;
            } else if (!(flags & 2) && (r = ParseBorderStyle(v, p)) != NULL) {
                flags |= 2;
            } else if (!(flags & 4) && (r = ParseCSSColor(v, p)) != NULL) {
                flags |= 4;
            } else {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = NULL;
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
            if (flags == 7) {
                break;
            }
        }
    }
    return p;
}

u16 *ParseCSSBorderBottom(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    int flags;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        flags = 0;
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            if (v == NULL && (v = newCSSValue()) == NULL) {
                return p;
            }
            if (!(flags & 1) && (r = ParseBorderWidth(v, p)) != NULL) {
                flags |= 1;
            } else if (!(flags & 2) && (r = ParseBorderStyle(v, p)) != NULL) {
                flags |= 2;
            } else if (!(flags & 4) && (r = ParseBorderColor(v, p)) != NULL) {
                flags |= 4;
            } else {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = NULL;
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
            if (flags == 7) {
                break;
            }
        }
    }
    return p;
}

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

u16 *ParseCSSBorderColor(void *decl, u16 *p) {
    CSSVALUE *top = NULL;
    CSSVALUE *right = NULL;
    CSSVALUE *bottom = NULL;
    CSSVALUE *left = NULL;
    u16 *r;
    CSSVALUE *v;
    v = newCSSValue();
    if (v == NULL) {
        goto fail;
    }
    p = CSS_SkipBlanksAndComments(p);
    r = ParseCSSIdent(v, p, 0x4D);
    if (r != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        top = v;
        r = ParseBorderColor(v, p);
        if (r == NULL) {
            goto bad;
        }
        addCSSValue(decl, v);
        p = CSS_SkipBlanksAndComments(r);
        right = newCSSValue();
        if (right == NULL) {
            goto fail;
        }
        r = ParseBorderColor(right, p);
        if (r == NULL) {
            freeCSSValue(right);
            if ((right = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, right);
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, right);
        p = CSS_SkipBlanksAndComments(r);
        bottom = newCSSValue();
        if (bottom == NULL) {
            goto fail;
        }
        r = ParseBorderColor(bottom, p);
        if (r == NULL) {
            freeCSSValue(bottom);
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, bottom);
        p = CSS_SkipBlanksAndComments(r);
        left = newCSSValue();
        if (left == NULL) {
            goto fail;
        }
        r = ParseBorderColor(left, p);
        if (r == NULL) {
            freeCSSValue(left);
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
        } else {
            p = r;
        }
        addCSSValue(decl, left);
        goto end;
bad:
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
end:
    return p;
fail:
    freeCSSValue(top);
    freeCSSValue(right);
    freeCSSValue(bottom);
    freeCSSValue(left);
    return CSS_SkipProperty(p);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSBorderSpacing);

u16 *ParseCSSBorderStyle(void *decl, u16 *p) {
    CSSVALUE *top = NULL;
    CSSVALUE *right = NULL;
    CSSVALUE *bottom = NULL;
    CSSVALUE *left = NULL;
    u16 *r;
    CSSVALUE *v;
    v = newCSSValue();
    if (v == NULL) {
        goto fail;
    }
    p = CSS_SkipBlanksAndComments(p);
    r = ParseCSSIdent(v, p, 0x4D);
    if (r != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        top = v;
        r = ParseBorderStyle(v, p);
        if (r == NULL) {
            goto bad;
        }
        addCSSValue(decl, v);
        p = CSS_SkipBlanksAndComments(r);
        right = newCSSValue();
        if (right == NULL) {
            goto fail;
        }
        r = ParseBorderStyle(right, p);
        if (r == NULL) {
            freeCSSValue(right);
            if ((right = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, right);
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, right);
        p = CSS_SkipBlanksAndComments(r);
        bottom = newCSSValue();
        if (bottom == NULL) {
            goto fail;
        }
        r = ParseBorderStyle(bottom, p);
        if (r == NULL) {
            freeCSSValue(bottom);
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, bottom);
        p = CSS_SkipBlanksAndComments(r);
        left = newCSSValue();
        if (left == NULL) {
            goto fail;
        }
        r = ParseBorderStyle(left, p);
        if (r == NULL) {
            freeCSSValue(left);
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
        } else {
            p = r;
        }
        addCSSValue(decl, left);
        goto end;
bad:
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
end:
    return p;
fail:
    freeCSSValue(top);
    freeCSSValue(right);
    freeCSSValue(bottom);
    freeCSSValue(left);
    return CSS_SkipProperty(p);
}

u16 *ParseCSSBorderWidth(void *decl, u16 *p) {
    CSSVALUE *top = NULL;
    CSSVALUE *right = NULL;
    CSSVALUE *bottom = NULL;
    CSSVALUE *left = NULL;
    u16 *r;
    CSSVALUE *v;
    v = newCSSValue();
    if (v == NULL) {
        goto fail;
    }
    p = CSS_SkipBlanksAndComments(p);
    r = ParseCSSIdent(v, p, 0x4D);
    if (r != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        top = v;
        r = ParseBorderWidth(v, p);
        if (r == NULL) {
            goto bad;
        }
        addCSSValue(decl, v);
        p = CSS_SkipBlanksAndComments(r);
        right = newCSSValue();
        if (right == NULL) {
            goto fail;
        }
        r = ParseBorderWidth(right, p);
        if (r == NULL) {
            freeCSSValue(right);
            if ((right = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, right);
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, right);
        p = CSS_SkipBlanksAndComments(r);
        bottom = newCSSValue();
        if (bottom == NULL) {
            goto fail;
        }
        r = ParseBorderWidth(bottom, p);
        if (r == NULL) {
            freeCSSValue(bottom);
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, bottom);
        p = CSS_SkipBlanksAndComments(r);
        left = newCSSValue();
        if (left == NULL) {
            goto fail;
        }
        r = ParseBorderWidth(left, p);
        if (r == NULL) {
            freeCSSValue(left);
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
        } else {
            p = r;
        }
        addCSSValue(decl, left);
        goto end;
bad:
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
end:
    return p;
fail:
    freeCSSValue(top);
    freeCSSValue(right);
    freeCSSValue(bottom);
    freeCSSValue(left);
    return CSS_SkipProperty(p);
}

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

u16 *ParseCSSContent(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            if ((r = ParseCSSString(v, p)) == NULL && (r = ParseCSSURL(v, p)) == NULL &&
                (r = ParseCSSCounter(v, p)) == NULL && (r = ParseCSSATTR(v, p)) == NULL &&
                (r = ParseCSSIdent(v, p, 0x7F)) == NULL && (r = ParseCSSIdent(v, p, 0x22)) == NULL &&
                (r = ParseCSSIdent(v, p, 0x77)) == NULL && (r = ParseCSSIdent(v, p, 0x76)) == NULL) {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = newCSSValue();
            if (v == NULL) {
                return CSS_SkipProperty(r);
            }
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
        }
        if (v != NULL) {
            freeCSSValue(v);
        }
        return p;
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSCounterIncrement(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    CSSUNITVAL u;
    u16 *name;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x79)) == NULL && (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            p = CSS_ident(p, &name);
            if (name != NULL) {
                v->type = 6;
                *(u16 **)&v->unit = name;
                if ((r = ParseUNIT(&u.unit, p)) != NULL) {
                    *(s16 *)&v->unk24 = u.val;
                } else {
                    r = p;
                }
            } else {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = newCSSValue();
            if (v == NULL) {
                return CSS_SkipProperty(r);
            }
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
        }
        if (v != NULL) {
            freeCSSValue(v);
        }
        return p;
    }
    addCSSValue(decl, v);
    return r;
}

u16 *ParseCSSCounterReset(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    CSSUNITVAL u;
    u16 *name;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x79)) == NULL && (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            p = CSS_ident(p, &name);
            if (name != NULL) {
                v->type = 7;
                *(u16 **)&v->unit = name;
                if ((r = ParseUNIT(&u.unit, p)) != NULL) {
                    *(s16 *)&v->unk24 = u.val;
                } else {
                    r = p;
                }
            } else {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = newCSSValue();
            if (v == NULL) {
                return CSS_SkipProperty(r);
            }
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
        }
        if (v != NULL) {
            freeCSSValue(v);
        }
        return p;
    }
    addCSSValue(decl, v);
    return r;
}

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

u16 *ParseFontFamily(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x99)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x93)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x2D)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x3B)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x71)) != NULL) {
        return r;
    }
    return ParseCSSString(v, p);
}

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

u16 *ParseCSSListStyle(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    int flags;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        flags = 0;
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            if (v == NULL && (v = newCSSValue()) == NULL) {
                return CSS_SkipProperty(p);
            }
            if (!(flags & 1) && (r = ParseListStyleType(v, p)) != NULL) {
                flags |= 1;
            } else if (!(flags & 2) && (r = ParseListStylePosition(v, p)) != NULL) {
                flags |= 2;
            } else if (!(flags & 4) && (r = ParseListStyleImage(v, p)) != NULL) {
                flags |= 4;
            } else {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = NULL;
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
            if (flags == 7) {
                break;
            }
        }
    }
    return p;
}

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

u16 *ParseCSSMarginWidth(CSSVALUE *v, u16 *p) {
    u16 *r;
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSUnit(v, p)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0xE)) != NULL) {
        return r;
    }
    if ((r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        return NULL;
    }
    return r;
}

u16 *ParseCSSMargin(void *decl, u16 *p) {
    CSSVALUE *top = NULL;
    CSSVALUE *right = NULL;
    CSSVALUE *bottom = NULL;
    CSSVALUE *left = NULL;
    u16 *r;
    CSSVALUE *v;
    v = newCSSValue();
    if (v == NULL) {
        goto fail;
    }
    p = CSS_SkipBlanksAndComments(p);
    r = ParseCSSIdent(v, p, 0x4D);
    if (r != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        top = v;
        r = ParseCSSMarginWidth(v, p);
        if (r == NULL) {
            goto bad;
        }
        addCSSValue(decl, v);
        p = CSS_SkipBlanksAndComments(r);
        right = newCSSValue();
        if (right == NULL) {
            goto fail;
        }
        r = ParseCSSMarginWidth(right, p);
        if (r == NULL) {
            freeCSSValue(right);
            if ((right = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, right);
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, right);
        p = CSS_SkipBlanksAndComments(r);
        bottom = newCSSValue();
        if (bottom == NULL) {
            goto fail;
        }
        r = ParseCSSMarginWidth(bottom, p);
        if (r == NULL) {
            freeCSSValue(bottom);
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, bottom);
        p = CSS_SkipBlanksAndComments(r);
        left = newCSSValue();
        if (left == NULL) {
            goto fail;
        }
        r = ParseCSSMarginWidth(left, p);
        if (r == NULL) {
            freeCSSValue(left);
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
        } else {
            p = r;
        }
        addCSSValue(decl, left);
        goto end;
bad:
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
end:
    return p;
fail:
    freeCSSValue(top);
    freeCSSValue(right);
    freeCSSValue(bottom);
    freeCSSValue(left);
    return CSS_SkipProperty(p);
}

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

u16 *ParseCSSOutline(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    int flags;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x4D)) != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        flags = 0;
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            p = CSS_SkipBlanksAndComments(p);
            if (v == NULL && (v = newCSSValue()) == NULL) {
                return CSS_SkipProperty(p);
            }
            if (!(flags & 1) && (r = ParseBorderWidth(v, p)) != NULL) {
                flags |= 1;
            } else if (!(flags & 2) && (r = ParseBorderStyle(v, p)) != NULL && v->type == 2 && v->unit == 0x15 && v->ident != 0x46) {
                flags |= 2;
            } else if (!(flags & 4) && (r = ParseCSSIdent(v, p, 0x52)) != NULL) {
                flags |= 4;
            } else if (!(flags & 4) && (r = ParseCSSColor(v, p)) != NULL) {
                flags |= 4;
            } else {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = NULL;
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
            if (flags == 7) {
                break;
            }
        }
    }
    return p;
}

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

u16 *ParseCSSOutlineStyle(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v != NULL) {
        r = ParseBorderStyle(v, p);
        if (r != NULL && v->type == 2 && v->unit == 0x15 && v->ident != 0x46) {
            addCSSValue(decl, v);
            return r;
        }
        freeCSSValue(v);
    }
    return CSS_SkipProperty(p);
}

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

u16 *ParseCSSPadding(void *decl, u16 *p) {
    CSSVALUE *top = NULL;
    CSSVALUE *right = NULL;
    CSSVALUE *bottom = NULL;
    CSSVALUE *left = NULL;
    u16 *r;
    CSSVALUE *v;
    v = newCSSValue();
    if (v == NULL) {
        goto fail;
    }
    p = CSS_SkipBlanksAndComments(p);
    r = ParseCSSIdent(v, p, 0x4D);
    if (r != NULL) {
        addCSSValue(decl, v);
        p = r;
    } else {
        top = v;
        r = ParseCSSUnit(v, p);
        if (r == NULL) {
            goto bad;
        }
        addCSSValue(decl, v);
        p = CSS_SkipBlanksAndComments(r);
        right = newCSSValue();
        if (right == NULL) {
            goto fail;
        }
        r = ParseCSSUnit(right, p);
        if (r == NULL) {
            freeCSSValue(right);
            if ((right = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, right);
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, right);
        p = CSS_SkipBlanksAndComments(r);
        bottom = newCSSValue();
        if (bottom == NULL) {
            goto fail;
        }
        r = ParseCSSUnit(bottom, p);
        if (r == NULL) {
            freeCSSValue(bottom);
            if ((bottom = duplicateCSSValue(top)) == NULL) {
                goto fail;
            }
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
            addCSSValue(decl, bottom);
            addCSSValue(decl, left);
            return p;
        }
        addCSSValue(decl, bottom);
        p = CSS_SkipBlanksAndComments(r);
        left = newCSSValue();
        if (left == NULL) {
            goto fail;
        }
        r = ParseCSSUnit(left, p);
        if (r == NULL) {
            freeCSSValue(left);
            if ((left = duplicateCSSValue(right)) == NULL) {
                goto fail;
            }
        } else {
            p = r;
        }
        addCSSValue(decl, left);
        goto end;
bad:
        freeCSSValue(v);
        return CSS_SkipProperty(p);
    }
end:
    return p;
fail:
    freeCSSValue(top);
    freeCSSValue(right);
    freeCSSValue(bottom);
    freeCSSValue(left);
    return CSS_SkipProperty(p);
}

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

u16 *ParseCSSTextDecoration(void *decl, u16 *p) {
    CSSVALUE *v;
    u16 *r;
    v = newCSSValue();
    if (v == NULL) {
        return CSS_SkipProperty(p);
    }
    p = CSS_SkipBlanksAndComments(p);
    if ((r = ParseCSSIdent(v, p, 0x79)) == NULL && (r = ParseCSSIdent(v, p, 0x4D)) == NULL) {
        while (*p != 0 && *p != ';' && *p != '}' && *p != '!') {
            if ((r = ParseCSSIdent(v, p, 0xBD)) == NULL && (r = ParseCSSIdent(v, p, 0x82)) == NULL &&
                (r = ParseCSSIdent(v, p, 0x5F)) == NULL && (r = ParseCSSIdent(v, p, 0x14)) == NULL) {
                freeCSSValue(v);
                return CSS_SkipProperty(p);
            }
            addCSSValue(decl, v);
            v = newCSSValue();
            if (v == NULL) {
                return CSS_SkipProperty(r);
            }
            p = CSS_SkipBlanksAndComments(r);
            if (*p == ',') {
                p++;
                p = CSS_SkipBlanksAndComments(p);
            }
        }
        if (v != NULL) {
            freeCSSValue(v);
        }
        return p;
    }
    addCSSValue(decl, v);
    return r;
}

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

int find_Property(u16 *name) {
    int c;
    int lo;
    int hi = 0;
    int mid;
    int r;
    if (!((unsigned int)(name[0] - 'A') < 26) && !((unsigned int)(name[0] - 'a') < 26)) {
        return -1;
    }
    if ((u16)(name[0] - 'a') < 26) {
        c = name[0] - 'a';
    } else {
        c = name[0] - 'A';
    }
    lo = CSSPropertyIndexTable[c];
    if (lo < 0) {
        return -1;
    }
    for (c++; c < 27; c++) {
        hi = CSSPropertyIndexTable[c];
        if (hi >= 0) {
            break;
        }
    }
    while (lo < hi) {
        mid = (lo + hi) / 2;
        r = UCS_strcasecmp(CSSPropertyNames[mid].name, name);
        if (r < 0) {
            lo = mid + 1;
        } else if (r > 0) {
            hi = mid;
        } else {
            return CSSPropertyNames[mid].id;
        }
    }
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", ParseCSSDeclaration);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", CSSUnitNames);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", CSSPropertyNames);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/css_ParseProperties", CSSPropertyIndexTable);
