/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
#include "nflayout.h"
#include "lo_css.h"
#include "m2c_macros.h"
typedef struct {
    char *start;
    char *end;
} STRWORD;
STRWORD UTL_strword(char *s, char *delim, char *stop);
extern char D_00139BEC[];
char *lo_fullUrl(BOX *box, char *s);
void requestImageData(BOX *box, char *url, int x);
int strncasecmp(const char *a, const char *b, unsigned int n);
void OS_thread_mutex_destroy(int m);
int iom_preferenceCookie(void);
void iom_updateCookie(void);
int iom_addCookie(char *url, char *hdr, int x);
void iom_freeCookie(void *c);
void innerCSSSetIntParam(CSSVALUE *val, int *out, BOX *parent, int fontSize, int inherit);
extern int *gCOOKIE_IDX_GLOBAL;
extern int D_00585114[];
extern char D_00139C00[];
void UTL_initqueue(void *q);
int OS_thread_mutex_create(void);
int OS_thread_mutex_init(int m, int a);
int iom_loadCookie(void);
char *iom_getCookie();
void *iom_malloc(int size);
int iom_mfree(void *p);
unsigned int strlen(const char *s);
int sprintf(char *buf, const char *fmt, ...);
#define CSS_TOUPPER(c) ((c) - (((u16)((c) - 'a') < 26) << 5))
extern char D_00139A8C[];
void GUI_Graphics_getStringSize(int font, char *s, int n, int *w, int *h);
extern int *iomCookie;
void *UTL_peekqueue(void *q, int a1);
void iom_deleteCookie(void *c);
int iom_saveCookie(void);
int OS_thread_mutex_lock(int m);
int OS_thread_mutex_unlock(int m);



void cssFontSize(void *ctx, BOX *box, CSSVALUE *val, int n);
void cssBackgroundColor(void *ctx, BOX *box, CSSVALUE *val, int n);
typedef void (*CSSFUNC)(void *ctx, BOX *box, void *val, int n);
extern CSSFUNC CSSFuncTable[];
extern unsigned char _DOMstyle;
int Element_getAttribute(DOMString *s, void *node, void *name);
void *CSS2_AttributeParse(int a, u16 *s);
void CSS2_freeCSSAttribute(void *a);
void *CSSStyleDeclaration_getValue(void *d);
void *memcpy(void *d, const void *s, unsigned int n);
typedef struct CSSDECLNODE { s16 type; s16 x2; int x4; int x8; int xC; int x10; int x14; struct CSSDECLNODE *next; s16 prop; } CSSDECLNODE;
extern const char _ctype_[];
#define LO_CT(c) ((_ctype_ + 1)[(int)(c)])
#define LO_TOLOWER(c) ({ int __x = (c); (LO_CT(__x) & 1) ? __x - 'A' + 'a' : __x; })
typedef struct CSSCHAINV { void *next; u16 *str; } CSSCHAINV;
typedef struct CSSSELM { u8 x0[0x1C]; u16 flags; u16 x1E; int x20; u16 *tag; CSSCHAINV cls; CSSCHAINV id; CSSCHAINV pseudo; } CSSSELM;
extern unsigned char _DOMclass, _DOMid;
extern DOMString _DOMlink;
int Element_getTagName(DOMString *s, void *node);
int cssDStrCmp(u16 *s, void *ds);
int cssDStrContains(u16 *word, void *ds);
void *Node_getParentNode(void *n);
void *Node_getPreviousSibling(void *n);
int Node_getNodeType(void *n);
typedef struct CSSSLNODE { u8 x0[0xC]; CSSDECLNODE *decl; u8 x10[8]; struct CSSSLNODE *next; u8 x1C[4]; struct CSSSLNODE *prev; } CSSSLNODE;
typedef struct CSSRULENODE { s16 type; u8 x2[0xA]; CSSSLNODE *sl; u8 x10[8]; struct CSSRULENODE *next; u16 *tag; } CSSRULENODE;
typedef struct CSSRULELIST { u8 x0[0xC]; CSSRULENODE *first; } CSSRULELIST;
typedef struct CSSSHEET { s16 type; u8 x2[0xA]; CSSRULELIST *rules; u8 x10[0x10]; struct CSSSHEET *next; } CSSSHEET;
typedef struct CSSSIDEFUNCS { CSSFUNC top; CSSFUNC bottom; CSSFUNC left; CSSFUNC right; } CSSSIDEFUNCS;
extern CSSSIDEFUNCS allSidesFuncTable[];
typedef struct CSSBORDERFUNCS { CSSFUNC color; CSSFUNC width; CSSFUNC style; } CSSBORDERFUNCS;
extern CSSBORDERFUNCS BorderFuncTable[];
extern const double D_00139B88;
extern const double D_00139B90;
int colorValue(int c);
int CToc(int s);
typedef struct CSSNUMPV { s16 type; s16 pad; int x4; double d; } CSSNUMPV;
extern const double D_00139B98;
extern const double D_00139BA0;
extern const double D_00139B78;
extern const double D_00139B80;
typedef struct BGSTYLE { int color; u8 x4[0xC]; u8 set; } BGSTYLE;
int UCS_strlen(void *);
void *UCS_strncpy(void *, void *, int n);
void *UCS_strstr(void *, void *);
INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139910);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139914);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetShortIntParam);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetIntParam);

void innerCSSCallFunc(void *ctx, BOX *box, CSSVALUE *val, int n, int kind) {
    CSSVALUE *v = val;
    switch (n) {
    case 1:
        allSidesFuncTable[kind].top(ctx, box, v, n);
        allSidesFuncTable[kind].bottom(ctx, box, v, n);
        allSidesFuncTable[kind].right(ctx, box, v, n);
        allSidesFuncTable[kind].left(ctx, box, v, n);
        break;
    case 2:
        allSidesFuncTable[kind].top(ctx, box, v, n);
        allSidesFuncTable[kind].bottom(ctx, box, v, n);
        v = v->next;
        allSidesFuncTable[kind].right(ctx, box, v, n);
        allSidesFuncTable[kind].left(ctx, box, v, n);
        break;
    case 3:
        allSidesFuncTable[kind].top(ctx, box, v, n);
        v = v->next;
        allSidesFuncTable[kind].right(ctx, box, v, n);
        allSidesFuncTable[kind].left(ctx, box, v, n);
        v = v->next;
        allSidesFuncTable[kind].bottom(ctx, box, v, n);
        break;
    case 4:
        allSidesFuncTable[kind].top(ctx, box, v, n);
        v = v->next;
        allSidesFuncTable[kind].right(ctx, box, v, n);
        v = v->next;
        allSidesFuncTable[kind].bottom(ctx, box, v, n);
        v = v->next;
        allSidesFuncTable[kind].left(ctx, box, v, n);
        break;
    }
}

void innerCSSSetBorder(void *ctx, BOX *box, CSSVALUE *val, int n, int side) {
    CSSVALUE *v = val;
    for (; v != NULL; v = v->next) {
        switch (v->unit) {
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            BorderFuncTable[side].width(ctx, box, v, n);
            break;
        case 0x19:
        case 0x1A:
            BorderFuncTable[side].color(ctx, box, v, n);
            break;
        case 0x15:
            switch (v->ident) {
            case 0x2E:
            case 0x34:
            case 0x35:
            case 0x43:
            case 0x50:
            case 0x80:
            case 0x8C:
            case 0xA3:
                BorderFuncTable[side].style(ctx, box, v, n);
                break;
            case 0x6C:
            case 0xB7:
            case 0xB8:
                BorderFuncTable[side].width(ctx, box, v, n);
                break;
            case 0xBA:
                BorderFuncTable[side].color(ctx, box, v, n);
                break;
            case 0x4D:
                BorderFuncTable[side].width(ctx, box, v, n);
                BorderFuncTable[side].style(ctx, box, v, n);
                BorderFuncTable[side].color(ctx, box, v, n);
                break;
            }
            break;
        }
    }
}

void innerCSSSetBorderStyle(int ident, s16 *width, s16 *style, s16 inherit) {
    switch (ident) {
    case 0xA3:
        *style = 1;
        break;
    case 0x35:
        *style = 2;
        break;
    case 0x43:
        *style = 3;
        break;
    case 0x8C:
        *style = 4;
        break;
    case 0x50:
        *style = 5;
        break;
    case 0x80:
        *style = 6;
        break;
    case 0x34:
        *style = 7;
        break;
    case 0x2E:
        *style = 8;
        break;
    case 0x79:
        *style = 0;
        break;
    case 0x4D:
        *style = inherit;
        break;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", innerCSSSetBorderWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssDStrCmp);

int cssDStrContains(u16 *word, void *ds) {
    int found = 0;
    int wlen;
    int n;
    u16 *buf;
    u16 *p;
    u16 *q;
    wlen = UCS_strlen(word);
    n = M2C_FIELD(ds, int *, 4);
    buf = MEM_malloc(0, n * 2 + 2);
    if (buf == NULL) {
        return 0;
    }
    UCS_strncpy(buf, M2C_FIELD(ds, u16 **, 8), n);
    buf[n] = 0;
    p = buf;
    while (n > 0 && (q = UCS_strstr(p, word)) != NULL) {
        if (p < q) {
            n -= q - p;
            if (q[-1] == ' ') {
                if (wlen >= n || q[wlen] == ' ') {
                    found = 1;
                    break;
                }
            }
        } else {
            if (wlen >= n || q[wlen] == ' ') {
                found = 1;
                break;
            }
        }
        p = q + 1;
        n--;
    }
    MEM_free(0, buf);
    return found;
}

void cssBackgroundAttachment() {
}

void cssBackgroundColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    int r;
    int g;
    int b;
    CSSNUMPV *pv;
    switch (val->unit) {
    case 0x19:
        ((BGSTYLE *)box->style)->set = 1;
        pv = (CSSNUMPV *)val->ident;
        if (pv->type == 1) {
            r = pv->d;
        } else if (pv->type == 2) {
            r = pv->d * D_00139B78 / D_00139B80;
        } else {
            r = 0;
        }
        pv = *(CSSNUMPV **)(val + 1);
        if (pv->type == 1) {
            g = pv->d;
        } else if (pv->type == 2) {
            g = pv->d * D_00139B78 / D_00139B80;
        } else {
            g = 0;
        }
        pv = ((CSSNUMPV **)(val + 1))[1];
        if (pv->type == 1) {
            b = pv->d;
        } else if (pv->type == 2) {
            b = pv->d * D_00139B78 / D_00139B80;
        } else {
            b = 0;
        }
        ((BGSTYLE *)box->style)->color = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
        break;
    case 0x1A:
        ((BGSTYLE *)box->style)->set = 1;
        ((BGSTYLE *)box->style)->color = colorValue(CToc(val->ident));
        break;
    case 0x15:
        if (val->ident == 0x4D) {
            if (box->parent != NULL) {
                ((BGSTYLE *)box->style)->set = ((BGSTYLE *)box->parent->style)->set;
                ((BGSTYLE *)box->style)->color = ((BGSTYLE *)box->parent->style)->color;
            } else {
                ((BGSTYLE *)box->style)->set = 0;
                ((BGSTYLE *)box->style)->color = 0;
            }
        }
        break;
    }
}

void cssBackgroundImage(void *ctx, BOX *box, CSSVALUE *val, int n) {
    int len = 0;
    char *s;
    char *url;
    int i;
    if (val->unit == 0x14 && box->display == 0) {
        while (((u16 *)val->ident)[len] != 0) {
            len++;
        }
        s = MEM_malloc(0, len + 1);
        for (i = 0; i < len; i++) {
            s[i] = ((u16 *)val->ident)[i];
        }
        s[len] = 0;
        url = lo_fullUrl(box, s);
        if (url != NULL) {
            requestImageData(box, url, M2C_FIELD(getBodyBox(box)->geom, int *, 0x38));
            MEM_free(0, url);
        }
    }
}

void cssBackgroundRepeat(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x88:
        box->style->unk12 = 0;
        break;
    case 0x89:
        box->style->unk12 = 1;
        break;
    case 0x8A:
        box->style->unk12 = 2;
        break;
    case 0x78:
        box->style->unk12 = 3;
        break;
    case 0x4D:
        box->style->unk12 = box->parent != NULL ? box->parent->style->unk12 : 0;
        break;
    }
}

void cssBackground(void *ctx, BOX *box, CSSVALUE *val, int n) {
    CSSVALUE *v = val;
    for (; v != NULL; v = v->next) {
        switch (v->unit) {
        case 0x19:
        case 0x1A:
            cssBackgroundColor(ctx, box, v, n);
            break;
        case 0x15:
            switch (v->ident) {
            case 0x41:
            case 0x94:
                cssBackgroundAttachment(ctx, box, v, n);
                break;
            case 0x4D:
                cssBackgroundColor(ctx, box, v, n);
                cssBackgroundRepeat(ctx, box, v, n);
                break;
            case 0x78:
            case 0x88:
            case 0x89:
            case 0x8A:
                cssBackgroundRepeat(ctx, box, v, n);
                break;
            }
            break;
        case 0x14:
            cssBackgroundImage(ctx, box, v, n);
            break;
        }
    }
}

void cssBorderBottomStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk34, &box->style->unk4C,
                               parent != NULL ? parent->style->unk4C : 0);
    }
}

void cssBorderBottomWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk34;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk34 : 0);
        if (w >= 0) {
            box->style->unk34 = w;
        }
    }
}

void innerCSSSetBorderColor(CSSVALUE *val, s16 *width, int *color, int inherit) {
    int r;
    int g;
    int b;
    CSSNUMPV *pv;
    switch (val->unit) {
    case 0x19:
        pv = (CSSNUMPV *)val->ident;
        if (pv->type == 1) {
            r = pv->d;
        } else if (pv->type == 2) {
            r = pv->d * D_00139B88 / D_00139B90;
        } else {
            r = 0;
        }
        pv = *(CSSNUMPV **)(val + 1);
        if (pv->type == 1) {
            g = pv->d;
        } else if (pv->type == 2) {
            g = pv->d * D_00139B88 / D_00139B90;
        } else {
            g = 0;
        }
        pv = ((CSSNUMPV **)(val + 1))[1];
        if (pv->type == 1) {
            b = pv->d;
        } else if (pv->type == 2) {
            b = pv->d * D_00139B88 / D_00139B90;
        } else {
            b = 0;
        }
        *color = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
        break;
    case 0x1A:
        *color = colorValue(CToc(val->ident));
        break;
    case 0x15:
        if (val->ident == 0x4D) {
            *color = inherit;
        }
        break;
    }
}

void cssBorderTopColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk30, &box->style->unk38,
                           parent != NULL ? parent->style->unk38 : box->style->unk54);
}

void cssBorderRightColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk32, &box->style->unk3C,
                           parent != NULL ? parent->style->unk3C : box->style->unk54);
}

void cssBorderBottomColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk34, &box->style->unk40,
                           parent != NULL ? parent->style->unk40 : box->style->unk54);
}

void cssBorderLeftColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetBorderColor(val, &box->style->unk36, &box->style->unk44,
                           parent != NULL ? parent->style->unk44 : box->style->unk54);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void setBoxArea0(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTopColor(ctx, box, val, n);
    cssBorderRightColor(ctx, box, val, n);
    cssBorderBottomColor(ctx, box, val, n);
    cssBorderLeftColor(ctx, box, val, n);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void setBoxArea1(void *ctx, BOX *box, CSSVALUE *val, int n) {
    CSSVALUE *v;
    cssBorderTopColor(ctx, box, val, n);
    cssBorderBottomColor(ctx, box, val, n);
    v = val->next;
    cssBorderRightColor(ctx, box, v, n);
    cssBorderLeftColor(ctx, box, v, n);
}

void setBoxArea2(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTopColor(ctx, box, val, n);
    val = val->next;
    cssBorderRightColor(ctx, box, val, n);
    cssBorderLeftColor(ctx, box, val, n);
    val = val->next;
    cssBorderBottomColor(ctx, box, val, n);
}

void setBoxArea3(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTopColor(ctx, box, val, n);
    val = val->next;
    cssBorderRightColor(ctx, box, val, n);
    val = val->next;
    cssBorderBottomColor(ctx, box, val, n);
    val = val->next;
    cssBorderLeftColor(ctx, box, val, n);
}

void cssBorderColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (n) {
    case 1:
        setBoxArea0(ctx, box, val, n);
        break;
    case 2:
        setBoxArea1(ctx, box, val, n);
        break;
    case 3:
        setBoxArea2(ctx, box, val, n);
        break;
    case 4:
        setBoxArea3(ctx, box, val, n);
        break;
    }
}

void cssBorderLeftStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk36, &box->style->unk4E,
                               parent != NULL ? parent->style->unk4E : 0);
    }
}

void cssBorderLeftWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk36;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk36 : 0);
        if (w >= 0) {
            box->style->unk36 = w;
        }
    }
}

void cssBorderRightStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk32, &box->style->unk4A,
                               parent != NULL ? parent->style->unk4A : 0);
    }
}

void cssBorderRightWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk32;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk32 : 0);
        if (w >= 0) {
            box->style->unk32 = w;
        }
    }
}

void cssBorderTopStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 5) {
        innerCSSSetBorderStyle(val->ident, &box->style->unk30, &box->style->unk48,
                               parent != NULL ? parent->style->unk48 : 0);
    }
}

void cssBorderStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 0);
}

void cssBorderTopWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk30;
    if (box->content != 5) {
        innerCSSSetBorderWidth(parent, val, &w, box->style->fontSize,
                               parent != NULL ? parent->style->unk30 : 0);
        if (w >= 0) {
            box->style->unk30 = w;
        }
    }
}

void cssBorderWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 1);
}

void cssBorderBottom(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk4C = 0;
    innerCSSSetBorder(ctx, box, val, n, 1);
}

void cssBorderRight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk4A = 0;
    innerCSSSetBorder(ctx, box, val, n, 3);
}

void cssBorderLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk4E = 0;
    innerCSSSetBorder(ctx, box, val, n, 2);
}

void cssBorderTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    box->style->unk48 = 0;
    innerCSSSetBorder(ctx, box, val, n, 0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cssBorder(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssBorderTop(ctx, box, val, n);
    cssBorderRight(ctx, box, val, n);
    cssBorderLeft(ctx, box, val, n);
    cssBorderBottom(ctx, box, val, n);
}

void cssColor(void *ctx, BOX *box, CSSVALUE *val, int n) {
    int r;
    int g;
    int b;
    CSSNUMPV *pv;
    switch (val->unit) {
    case 0x19:
        pv = (CSSNUMPV *)val->ident;
        if (pv->type == 1) {
            r = pv->d;
        } else if (pv->type == 2) {
            r = pv->d * D_00139B98 / D_00139BA0;
        } else {
            r = 0;
        }
        pv = *(CSSNUMPV **)(val + 1);
        if (pv->type == 1) {
            g = pv->d;
        } else if (pv->type == 2) {
            g = pv->d * D_00139B98 / D_00139BA0;
        } else {
            g = 0;
        }
        pv = ((CSSNUMPV **)(val + 1))[1];
        if (pv->type == 1) {
            b = pv->d;
        } else if (pv->type == 2) {
            b = pv->d * D_00139B98 / D_00139BA0;
        } else {
            b = 0;
        }
        box->style->unk54 = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
        break;
    case 0x1A:
        box->style->unk54 = colorValue(CToc(val->ident));
        break;
    }
}

void cssFont(void *ctx, BOX *box, CSSVALUE *val, int n) {
    CSSVALUE *v = val;
    box->style->unk6A = 0;
    box->style->fontSize = 2;
    for (; v != NULL; v = v->next) {
        if (v->unit == 0x15) {
            switch ((unsigned int)v->ident) {
            case 0x53:
            case 0x7D:
                box->style->unk6A |= 2;
                continue;
            case 5:
            case 6:
            case 7:
            case 8:
            case 0x16:
            case 0x17:
                box->style->unk6A |= 1;
                continue;
            }
        }
        cssFontSize(ctx, box, v, n);
    }
    box->style->unk64 = ui_global->color[box->style->unk6A][box->style->fontSize];
}

int transFontSize(int h) {
    int i;
    int w;
    int hh;
    for (i = 6; i >= 0; i--) {
        GUI_Graphics_getStringSize(ui_global->color[0][i], "A", 1, &w, &hh);
        if (h >= hh) {
            break;
        }
    }
    if (i < 0) {
        i = 0;
    }
    return i;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", cssFontSize);

void cssFontStyle(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x53:
    case 0x7D:
        box->style->unk6A |= 2;
        break;
    case 0x7A:
        box->style->unk6A &= ~2;
        break;
    }
    box->style->unk64 = ui_global->color[box->style->unk6A][box->style->fontSize];
}

void cssFontWeight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 0x16:
    case 0x17:
        box->style->unk6A |= 1;
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x5E:
    case 0x7A:
        box->style->unk6A &= ~1;
        break;
    }
    box->style->unk64 = ui_global->color[box->style->unk6A][box->style->fontSize];
}

void cssHeight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    int h = box->style->height;
    if (box->content == 0 && box->display != 0 && box->display != 3) {
        return;
    }
    if (val->unit == 0x15 && val->ident == 0xE) {
        return;
    }
    innerCSSSetIntParam(val, &h, box->parent, box->style->fontSize, parent != NULL ? parent->height : 0);
    if (h >= 0) {
        box->style->height = h;
        if (val->unit == 2) {
            box->style->flags &= ~0xC;
            box->style->flags |= 8;
        } else {
            box->style->flags &= ~0xC;
            box->style->flags |= 4;
        }
    }
}

void cssLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetShortIntParam(val, &box->style->unk52, parent, box->style->fontSize,
                             parent != NULL ? parent->style->unk52 : 0);
}

void cssMarginBottom(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk24, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk24 : 0);
    }
}

void cssMarginLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk26, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk26 : 0);
    }
}

void cssMarginRight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk22, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk22 : 0);
    }
}

void cssMarginTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    if (box->content != 6) {
        innerCSSSetShortIntParam(val, &box->style->unk20, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk20 : 0);
    }
}

void cssMargin(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void cssMarkerOffset(void *ctx, BOX *box, CSSVALUE *val, int n) {
    cssMargin(ctx, box, val, n);
}

void cssPaddingBottom(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk2C;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk2C : 0);
        if (w >= 0) {
            box->style->unk2C = w;
        }
    }
}

void cssPaddingLeft(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk2E;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk2E : 0);
        if (w >= 0) {
            box->style->unk2E = w;
        }
    }
}

void cssPaddingRight(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk2A;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk2A : 0);
        if (w >= 0) {
            box->style->unk2A = w;
        }
    }
}

void cssPaddingTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    s16 w = box->style->unk28;
    if (box->content != 4) {
        innerCSSSetShortIntParam(val, &w, parent, box->style->fontSize,
                                 parent != NULL ? parent->style->unk28 : 0);
        if (w >= 0) {
            box->style->unk28 = w;
        }
    }
}

void cssPadding(void *ctx, BOX *box, CSSVALUE *val, int n) {
    innerCSSCallFunc(ctx, box, val, n, 3);
}

void cssPosition(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0xA6:
        box->style->unk72 = 0;
        break;
    case 0x87:
        box->style->unk72 = 1;
        break;
    case 0xA:
        box->style->unk72 = 2;
        break;
    case 0x41:
        box->style->unk72 = 3;
        break;
    case 0x4D:
        box->style->unk72 = box->parent != NULL ? box->parent->style->unk72 : 0;
        break;
    }
}

void cssTextAlign(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x54:
        box->style->unk6F = 1;
        break;
    case 0x8D:
        box->style->unk6F = 3;
        break;
    case 0x1C:
        box->style->unk6F = 2;
        break;
    case 0x5A:
        box->style->unk6F = 1;
        break;
    }
}

void cssTextDecoration(void *ctx, BOX *box, CSSVALUE *val, int n) {
    for (; val != NULL; val = val->next) {
        switch (val->ident) {
        case 0x79:
            box->style->unk6C[0] = 0;
            break;
        case 0x82:
            box->style->unk6C[0] |= 1;
            break;
        case 0xBD:
            box->style->unk6C[0] |= 2;
            break;
        case 0x5F:
            box->style->unk6C[0] |= 4;
            break;
        case 0x14:
            box->style->unk6C[0] |= 8;
            break;
        case 0x4D:
            box->style->unk6C[0] = box->parent != NULL ? box->parent->style->unk6C[0] : 0;
            break;
        }
    }
}

void cssTop(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    innerCSSSetShortIntParam(val, &box->style->unk50, parent, box->style->fontSize,
                             parent != NULL ? parent->style->unk50 : 0);
}

void cssVerticalAlign(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x10:
        box->style->unk70[0] = 0;
        break;
    case 0xA8:
        box->style->unk70[0] = 1;
        break;
    case 0xA9:
        box->style->unk70[0] = 2;
        break;
    case 0xB9:
        box->style->unk70[0] = 3;
        break;
    case 0xB6:
        box->style->unk70[0] = 4;
        break;
    case 0x6F:
        box->style->unk70[0] = 5;
        break;
    case 0x19:
        box->style->unk70[0] = 6;
        break;
    case 0xB5:
        box->style->unk70[0] = 7;
        break;
    case 0x4D:
        box->style->unk70[0] = box->parent != NULL ? box->parent->style->unk70[0] : 0;
        break;
    }
}

void cssVisibility(void *ctx, BOX *box, CSSVALUE *val, int n) {
    switch (val->ident) {
    case 0x46:
        box->style->unk73 = 1;
        break;
    case 0xC3:
        box->style->unk73 = 0;
        break;
    case 0x4D:
        box->style->unk73 = box->parent != NULL ? box->parent->style->unk73 : 0;
        break;
    }
}

void cssWidth(void *ctx, BOX *box, CSSVALUE *val, int n) {
    BOX *parent = box->parent;
    int w = box->style->width;
    if (box->content == 0 && box->display != 0 && box->display != 3) {
        return;
    }
    if (val->unit == 0x15 && val->ident == 0xE) {
        return;
    }
    innerCSSSetIntParam(val, &w, box->parent, box->style->fontSize, parent != NULL ? parent->width : 0);
    if (w >= 0) {
        box->style->width = w;
        if (val->unit == 2) {
            box->style->flags &= ~3;
            box->style->flags |= 2;
        } else {
            box->style->flags &= ~3;
            box->style->flags |= 1;
        }
    }
}

int matchesNode(CSSSELM *sel, void *node) {
    DOMString tag;
    DOMString cls;
    DOMString id;
    CSSCHAINV ch;
    int ret = 1;
    unsigned int i;
    Element_getTagName(&tag, node);
    if (sel->tag[0] != '*' && cssDStrCmp(sel->tag, &tag) != 0) {
        return 0;
    }
    if (sel->flags & 0x10) {
        Element_getAttribute(&cls, node, &_DOMclass);
        if (cls.len != 0) {
            for (i = 0; i < cls.len; i++) {
                if (LO_CT(cls.str[i]) & 3) {
                    cls.str[i] = LO_TOLOWER(cls.str[i]);
                }
            }
            ch = sel->cls;
            if (!cssDStrContains(ch.str, &cls)) {
                ret = 0;
            }
        } else {
            ret = 0;
        }
    }
    if (sel->flags & 0x20) {
        Element_getAttribute(&id, node, &_DOMid);
        if (id.len != 0) {
            for (i = 0; i < id.len; i++) {
                if (LO_CT(id.str[i]) & 3) {
                    id.str[i] = LO_TOLOWER(id.str[i]);
                }
            }
            ch = sel->id;
            if (cssDStrCmp(ch.str, &id) != 0) {
                ret = 0;
            }
        } else {
            ret = 0;
        }
    }
    if (sel->flags & 0x40) {
        ch = sel->pseudo;
        if (cssDStrCmp(ch.str, &_DOMlink) != 0 || ch.next != NULL) {
            ret = 0;
        }
    }
    return ret;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void applyCSSpostAction(void *arg0) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;

    temp_a1 = M2C_FIELD(arg0, void **, 0x24);
    if (M2C_FIELD(temp_a1, short *, 0x48) == 0) {
        M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(arg0, int *, 0x1C) - M2C_FIELD(temp_a1, short *, 0x30));
        M2C_FIELD(temp_a1, short *, 0x30) = 0;
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), short *, 0x4A) == 0) {
        M2C_FIELD(arg0, int *, 0x18) = (int) (M2C_FIELD(arg0, int *, 0x18) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), short *, 0x32));
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), short *, 0x32) = 0;
    }
    temp_a1_2 = M2C_FIELD(arg0, void **, 0x24);
    if (M2C_FIELD(temp_a1_2, short *, 0x4C) == 0) {
        M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(arg0, int *, 0x1C) - M2C_FIELD(temp_a1_2, short *, 0x34));
        M2C_FIELD(temp_a1_2, short *, 0x34) = 0;
    }
    temp_a1_3 = M2C_FIELD(arg0, void **, 0x24);
    if (M2C_FIELD(temp_a1_3, short *, 0x4E) == 0) {
        M2C_FIELD(arg0, int *, 0x18) = (int) (M2C_FIELD(arg0, int *, 0x18) - M2C_FIELD(temp_a1_3, short *, 0x36));
        M2C_FIELD(temp_a1_3, short *, 0x36) = 0;
    }
}

void applyCSSExtStyleSheetToBox(void *node, BOX *box) {
    CSSSHEET *ss;
    CSSRULENODE *rule;
    CSSSLNODE *sl;
    CSSSLNODE *sel;
    CSSDECLNODE *d;
    void *cur;
    void *p;
    int match;
    DOMString tag;
    ss = M2C_FIELD(M2C_FIELD(getBodyBox(box)->geom, void **, 0x20), CSSSHEET **, 0x70);
    if (ss == NULL || ss->type != 0) {
        applyCSSpostAction(box);
        return;
    }
    for (; ss != NULL; ss = ss->next) {
        if (ss->rules == NULL) {
            continue;
        }
        for (rule = ss->rules->first; rule != NULL; rule = rule->next) {
            if (rule->type != 8) {
                continue;
            }
            match = 0;
            Element_getTagName(&tag, node);
            if (rule->tag[0] == '*') {
                match = 1;
            } else if (cssDStrCmp(rule->tag, &tag) == 0) {
                match = 1;
            }
            if (!match) {
                continue;
            }
            for (sl = rule->sl; sl != NULL; sl = sl->next) {
                match = 1;
                cur = node;
                for (sel = sl; match && sel != NULL; sel = sel->prev) {
                    if (((CSSSELM *)sel)->flags & 1) {
                        for (p = Node_getParentNode(cur); p != NULL; p = Node_getParentNode(p)) {
                            if (matchesNode((CSSSELM *)sel, p)) {
                                break;
                            }
                        }
                        if (p == NULL) {
                            match = 0;
                        } else {
                            cur = p;
                        }
                    } else if (((CSSSELM *)sel)->flags & 2) {
                        p = Node_getParentNode(cur);
                        if (p == NULL || !matchesNode((CSSSELM *)sel, p)) {
                            match = 0;
                        } else {
                            cur = p;
                        }
                    } else if (((CSSSELM *)sel)->flags & 4) {
                        for (p = Node_getPreviousSibling(cur); p != NULL && Node_getNodeType(p) != 1; p = Node_getPreviousSibling(p)) {
                        }
                        if (p == NULL || !matchesNode((CSSSELM *)sel, p)) {
                            match = 0;
                        } else {
                            cur = p;
                        }
                    } else {
                        match = matchesNode((CSSSELM *)sel, cur);
                    }
                }
                if (match) {
                    for (d = sl->decl; d != NULL; d = d->next) {
                        if (d->type == 10 && CSSFuncTable[d->prop] != NULL) {
                            CSSFuncTable[d->prop](node, box, CSSStyleDeclaration_getValue(d), d->x8);
                        }
                    }
                }
            }
        }
    }
    applyCSSpostAction(box);
}

void applyCSSInlinePropertyToBox(void *node, BOX *box) {
    DOMString s;
    u16 *buf;
    CSSDECLNODE *attr;
    CSSDECLNODE *d;
    Element_getAttribute(&s, node, &_DOMstyle);
    if (s.str == NULL) {
        return;
    }
    buf = MEM_malloc(0, s.len * 2 + 2);
    memcpy(buf, s.str, s.len * 2);
    buf[s.len] = 0;
    attr = CSS2_AttributeParse(0, buf);
    MEM_free(0, buf);
    for (d = attr; d != NULL; d = d->next) {
        if (d->type == 10 && CSSFuncTable[d->prop] != NULL) {
            CSSFuncTable[d->prop](node, box, CSSStyleDeclaration_getValue(d), d->x8);
        }
    }
    applyCSSpostAction(box);
    CSS2_freeCSSAttribute(attr);
}

int iom_attachCookie(void) {
    int r;
    int *p;
    iomCookie = D_00585114;
    UTL_initqueue(iomCookie + 1);
    UTL_initqueue(iomCookie + 3);
    p = iomCookie;
    p[5] = OS_thread_mutex_create();
    if (OS_thread_mutex_init(iomCookie[5], 0) != 0) {
        r = -0x12C;
    } else {
        OS_thread_mutex_lock(iomCookie[5]);
        gCOOKIE_IDX_GLOBAL = iomCookie;
        iomCookie[0] = 0;
        r = iom_loadCookie();
        iom_saveCookie();
        OS_thread_mutex_unlock(iomCookie[5]);
    }
    return r;
}

int iom_detachCookie(void) {
    int r = 0;
    void **e;
    OS_thread_mutex_lock(iomCookie[5]);
    iom_updateCookie();
    if (iomCookie[0] != 0) {
        r = iom_saveCookie();
    }
    while ((e = UTL_peekqueue(&iomCookie[1], 0)) != NULL) {
        if (M2C_FIELD(e[2], int *, 0x10) == -1) {
            iom_deleteCookie(e[2]);
        } else {
            iom_freeCookie(e[2]);
        }
    }
    gCOOKIE_IDX_GLOBAL = NULL;
    OS_thread_mutex_unlock(iomCookie[5]);
    OS_thread_mutex_destroy(iomCookie[5]);
    iomCookie = NULL;
    return r;
}

int iom_setCookie(char *url, char *hdr, int x) {
    int r;
    OS_thread_mutex_lock(iomCookie[5]);
    if (url == NULL || hdr == NULL) {
        OS_thread_mutex_unlock(iomCookie[5]);
        return 0;
    }
    if (iom_preferenceCookie() == 0) {
        OS_thread_mutex_unlock(iomCookie[5]);
        return 0;
    }
    iom_updateCookie();
    r = iom_addCookie(url, hdr, x);
    if (iomCookie[0] != 0) {
        iom_saveCookie();
    }
    OS_thread_mutex_unlock(iomCookie[5]);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", iom_getCookie);

void iom_destroyCookie(void) {
    void *e;
    OS_thread_mutex_lock(iomCookie[5]);
    while ((e = UTL_peekqueue(iomCookie + 1, 0)) != NULL) {
        iom_deleteCookie(M2C_FIELD(e, void **, 8));
    }
    if (iomCookie[0] != 0) {
        iom_saveCookie();
    }
    OS_thread_mutex_unlock(iomCookie[5]);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AE8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AF0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AF4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139AFC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B00);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B04);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B08);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B0C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B10);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B14);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B18);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B1C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B20);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B24);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B28);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B2C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B30);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B34);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B38);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B3C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B40);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B44);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B48);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B4C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B50);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B54);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B58);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B5C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B60);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B64);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B68);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B6C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B70);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B74);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B78);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B7C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B80);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B84);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B88);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B8C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B90);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B94);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B98);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139B9C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BA0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BA4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BA8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BAC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BB0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BB4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BB8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BBC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BC0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BC4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BC8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BCC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BD0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BD4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BD8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BDC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BE0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BE4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_CSS", D_00139BEC);

int set_cookie(void *x, char *hdr) {
    STRWORD w;
    w = UTL_strword(hdr, D_00139BEC, " \t:");
    if (w.end - w.start == 10 && strncasecmp(w.start, "Set-Cookie", 10) == 0) {
        hdr = w.end;
        while (*hdr == ' ' || *hdr == '\t' || *hdr == ':') {
            hdr++;
        }
    }
    iomCookie = gCOOKIE_IDX_GLOBAL;
    if (iomCookie == NULL) {
        return -1;
    }
    return iom_setCookie(x, hdr, 0) < 0 ? -1 : 1;
}

char *get_cookie(void *url) {
    char *c;
    char *buf;
    iomCookie = gCOOKIE_IDX_GLOBAL;
    if (iomCookie == NULL) {
        return NULL;
    }
    c = iom_getCookie(url);
    if (c == NULL) {
        return NULL;
    }
    buf = iom_malloc(strlen(c) + 9);
    if (buf == NULL) {
        iom_mfree(c);
        return NULL;
    }
    sprintf(buf, "Cookie: %s", c);
    iom_mfree(c);
    return buf;
}
