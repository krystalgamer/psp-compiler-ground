/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "dom_domi.h"
#include "m2c_macros.h"
BOX *getTableBox(BOX *box);
BOX *getTrBox(BOX *box);
BOX *box_getColBoxAt(BOX *table, int col);
extern unsigned char _DOMvalign;
extern unsigned char _DOMtop;
extern unsigned char _DOMbottom;
extern unsigned char _DOMbaseline;
BOX *getBoxByHTML(BOX *box, int html);
extern unsigned char _DOMwidth;
extern unsigned char _DOMheight;
extern unsigned char _DOMmiddle;
int atoi(const char *s);
char *strchr(const char *s, int c);
extern unsigned char _DOMcolspan;
extern unsigned char _DOMrowspan;
extern unsigned char _DOMalign;
extern unsigned char _DOMleft;
extern unsigned char _DOMright;
extern unsigned char _DOMcenter;
extern unsigned char _DOMborder;
char *getDOMAttributeValue(void *node, void *name);
long strtol(const char *s, char **end, int base);
int Element_getAttribute(DOMString *s, void *node, void *name);
int DOMStringcasecmpFast(DOMString *s, void *str);
void *createBox(void *ctx, int type);
void linkBox(void *box, void *parent, void *prev);
void initNoneContent(void *box, void *ctx);
int checkAtributeByName(void *node, char *name);
extern unsigned char _DOMcellpadding;
extern unsigned char _DOMcellspacing;
extern unsigned char _DOMhspace;
extern unsigned char _DOMmarginheight;
extern unsigned char _DOMmarginwidth;
extern unsigned char _DOMspan;
extern unsigned char _DOMvspace;
void MEM_free(M2C_UNK, void *);                  /* extern */
void *getBodyBox(int);                              /* extern */
int lo_fullUrl(int, signed char *);                          /* extern */
M2C_UNK requestImageData(int, int, int);            /* extern */
extern unsigned char _DOMbackground;
extern void *ui_global;
int colorValue(signed char *);                               /* extern */
extern unsigned char _DOMbgcolor;
extern unsigned char _DOMlink;
extern unsigned char _DOMtext;
extern unsigned char _DOMvlink;
extern unsigned char _DOMbordercolor;
extern unsigned char _DOMfocuscolor;



typedef struct SelTgt { struct SelTgt *next; struct SelTgt *prev; BOX *box; } SelTgt;
typedef struct { SelTgt *head; SelTgt *tail; } SelList;
void *MEM_malloc(void *pool, unsigned int size);
void *lfm_createPageRegion(BOX *box, int w);
void lfm_resetPageRegion(void *r, int w);
extern unsigned char _DOMframe;
extern unsigned char _DOMvoid;
extern unsigned char _DOMabove;
extern unsigned char _DOMbelow;
extern unsigned char _DOMhsides;
extern unsigned char _DOMlhs;
extern unsigned char _DOMrhs;
extern unsigned char _DOMvsides;
extern unsigned char _DOMbox;
int equalsChar(char a, char b, int cs);
int getDOMAttributeValue_PositiveNum(void *elem, void *name);
void applyCSSExtStyleSheetToBox(void *node, BOX *box);
void applyCSSInlinePropertyToBox(void *node, BOX *box);
int addSelectionTarget(SelList *l, BOX *box, int a, int b) {
    SelTgt *t;
    int s, e;

    s = a;
    e = b;
    if (a == b)
        return 0;
    if (b < a) {
        s = b;
        e = a;
    }
    t = MEM_malloc(0, 0xC);
    if (t == NULL)
        return -0x64;
    t->next = NULL;
    t->prev = l->tail;
    t->box = box;
    box->geom->y = s;
    M2C_FIELD(box->geom, int *, 8) = e;
    if (l->head == NULL)
        l->head = t;
    else
        l->tail->next = t;
    l->tail = t;
    return 0;
}

int insertSelectionTarget(SelList *l, BOX *box, int a, int b) {
    SelTgt *t;
    int s, e;

    s = a;
    e = b;
    if (a == b)
        return 0;
    if (b < a) {
        s = b;
        e = a;
    }
    t = MEM_malloc(0, 0xC);
    if (t == NULL)
        return -0x64;
    t->next = l->head;
    t->prev = NULL;
    t->box = box;
    box->geom->y = s;
    M2C_FIELD(box->geom, int *, 8) = e;
    if (l->tail == NULL)
        l->tail = t;
    else
        l->head->prev = t;
    l->head = t;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void clearSelectionTarget(void *arg0) {
    void *temp_s0;
    void *var_a1;

    var_a1 = M2C_FIELD(arg0, void **, 0);
    if (var_a1 != NULL) {
        do {
            temp_s0 = M2C_FIELD(var_a1, void **, 0);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(var_a1, void **, 8), void **, 0x20), int *, 4) = 0;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(var_a1, void **, 8), void **, 0x20), int *, 8) = 0;
            MEM_free(0, var_a1);
            var_a1 = temp_s0;
        } while (temp_s0 != NULL);
    }
    M2C_FIELD(arg0, void **, 0) = NULL;
    M2C_FIELD(arg0, int *, 4) = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", forwardSearchTarget);

int backwardSearchTarget(SelList *l, BOX *root, BOX *box, int start, char *pat, int cs) {
    int len;
    int matched;
    int pos;

    len = strlen(pat);
    matched = 0;
    pos = start;
    while (box != NULL) {
        if (box->content == 9) {
            matched = backwardStrings(l, box, pos, pat, len, matched, cs);
            if (matched < 0) {
                return matched;
            }
            if (matched == len) {
                return 1;
            }
        } else {
            matched = 0;
            clearSelectionTarget(l);
        }
        if ((root == box || box->content != 1) && box->child != NULL) {
            matched = 0;
            clearSelectionTarget(l);
            box = box->child;
            while (box->next != NULL) {
                box = box->next;
            }
        } else if (root == box) {
            goto out;
        } else if (box->prev != NULL) {
            box = box->prev;
        } else {
            matched = 0;
            if (root != box) {
                clearSelectionTarget(l);
                box = box->parent;
                while (box != NULL && box != root && box->prev == NULL) {
                    box = box->parent;
                }
                box = (box != NULL && box != root) ? box->prev : NULL;
            } else {
            out:
                clearSelectionTarget(l);
                break;
            }
        }
        if (box != NULL && box->content == 9) {
            pos = M2C_FIELD(box->geom, int *, 0xC);
        }
    }
    clearSelectionTarget(l);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", forwardStrings);

int backwardStrings(SelList *l, BOX *box, int start, char *pat, int patlen, int matched, int cs) {
    char *p = M2C_FIELD(box->geom, char **, 0) + start - 1;
    int len = start;
    int i;
    int r;

    for (; len > 0; len--, p--) {
        for (i = 0; (matched + i < patlen) & (i < len); i++) {
            if (!equalsChar(*(p - i), pat[patlen - (matched + i) - 1], cs)) {
                break;
            }
        }
        if ((matched + i >= patlen) | (i >= len)) {
            r = insertSelectionTarget(l, box, len - i, len);
            if (r < 0) {
                return r;
            }
            return matched + i;
        }
        if (matched != 0) {
            return 0;
        }
    }
    return 0;
}

int equalsChar(char a, char b, int cs) {
    if (cs) {
        return a == b;
    }
    if ((unsigned)(a - 'a') < 26) {
        a -= 0x20;
    }
    if ((unsigned)(b - 'a') < 26) {
        b -= 0x20;
    }
    return a == b;
}

void attr_ALIGN_text_block(void *node, void *box) {
    DOMString str;
    Element_getAttribute(&str, node, &_DOMalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMcenter) == 0) {
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), u8 *, 0x6F) = 2;
        } else if (DOMStringcasecmpFast(&str, &_DOMright) == 0) {
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), u8 *, 0x6F) = 3;
        } else {
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), u8 *, 0x6F) = 1;
        }
    }
}

void attr_ALIGN_hr(void *node, void *box) {
    DOMString str;
    Element_getAttribute(&str, node, &_DOMalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMleft) == 0) {
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), u8 *, 0x6F) = 1;
        } else if (DOMStringcasecmpFast(&str, &_DOMright) == 0) {
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), u8 *, 0x6F) = 3;
        } else {
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), u8 *, 0x6F) = 2;
        }
    }
}

void attr_ALIGN_image(void *node, BOX *box) {
    DOMString str;
    Element_getAttribute(&str, node, &_DOMalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMleft) == 0) {
            box->style->unk70[1] = 1;
        } else if (DOMStringcasecmpFast(&str, &_DOMright) == 0) {
            box->style->unk70[1] = 2;
        } else if (DOMStringcasecmpFast(&str, &_DOMtop) == 0) {
            box->style->unk70[0] = 3;
        } else if (DOMStringcasecmpFast(&str, &_DOMmiddle) == 0 || DOMStringcasecmpFast(&str, &_DOMcenter) == 0) {
            box->style->unk70[0] = 5;
        } else {
            box->style->unk70[0] = 6;
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_BACKGROUND(void *arg0, int arg1) {
    int temp_v0_2;
    signed char *temp_v0;
    void *temp_s2;

    temp_s2 = getBodyBox(arg1);
    if (M2C_FIELD(ui_global, int *, 0x98) == 0) {
        temp_v0 = getDOMAttributeValue(arg0, &_DOMbackground);
        if (temp_v0 != NULL) {
            temp_v0_2 = lo_fullUrl(arg1, temp_v0);
            if (temp_v0_2 != 0) {
                requestImageData(arg1, temp_v0_2, M2C_FIELD(M2C_FIELD(temp_s2, void **, 0x20), int *, 0x38));
                MEM_free(0, temp_v0_2);
            }
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_BGCOLOR(void *arg0, void *arg1) {
    int *temp_s0;
    signed char *temp_v0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMbgcolor);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, int **, 0x24);
        M2C_FIELD(temp_s0, int *, 0) = colorValue(temp_v0);
        M2C_FIELD(M2C_FIELD(arg1, int **, 0x24), signed char *, 0x10) = 1;
        MEM_free(0, temp_v0);
    }
}

void attr_BORDER_image(void *node, void *box) {
    int n = getDOMAttributeValue_PositiveNum(node, &_DOMborder);
    if (n >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x30) = n;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x32) = n;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x34) = n;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x36) = n;
        if (n > 0) {
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x48) = 1;
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x4A) = 1;
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x4C) = 1;
            M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x4E) = 1;
        }
    }
}

void attr_WIDTH_image(void *node, BOX *box) {
    char *s;
    int n;
    s = getDOMAttributeValue(node, &_DOMwidth);
    if (s != NULL) {
        n = atoi(s);
        if (n < 0) {
            n = 0;
        }
        if (strchr(s, '%') == NULL) {
            box->style->flags &= ~0x3;
            box->style->flags |= 0x1;
        } else {
            box->style->flags &= ~0x3;
            box->style->flags |= 0x2;
        }
        box->style->width = n;
        MEM_free(0, s);
    }
}

void attr_HEIGHT_image(void *node, BOX *box) {
    char *s;
    int n;
    s = getDOMAttributeValue(node, &_DOMheight);
    if (s != NULL) {
        n = atoi(s);
        if (n < 0) {
            n = 0;
        }
        if (strchr(s, '%') == NULL) {
            box->style->flags &= ~0xC;
            box->style->flags |= 0x4;
        } else {
            box->style->flags &= ~0xC;
            box->style->flags |= 0x8;
        }
        box->style->height = n;
        MEM_free(0, s);
    }
}

void attr_HSPACE(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMhspace);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x26) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x22) = v;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_LINK(void *arg0, void *arg1) {
    signed char *temp_v0;
    void *temp_s0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMlink);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, void **, 0x24);
        M2C_FIELD(temp_s0, int *, 0x58) = colorValue(temp_v0);
        MEM_free(0, temp_v0);
    }
}

void attr_MARGINHEIGHT(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMmarginheight);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x28) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2C) = v;
    }
}

void attr_MARGINWIDTH(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMmarginwidth);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2E) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x2A) = v;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_TEXT(void *arg0, void *arg1) {
    signed char *temp_v0;
    void *temp_s0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMtext);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, void **, 0x24);
        M2C_FIELD(temp_s0, int *, 0x54) = colorValue(temp_v0);
        MEM_free(0, temp_v0);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_VLINK(void *arg0, void *arg1) {
    signed char *temp_v0;
    void *temp_s0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMvlink);
    if (temp_v0 != NULL) {
        temp_s0 = M2C_FIELD(arg1, void **, 0x24);
        M2C_FIELD(temp_s0, int *, 0x5C) = colorValue(temp_v0);
        MEM_free(0, temp_v0);
    }
}

void attr_VSPACE(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMvspace);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x20) = v;
        M2C_FIELD(M2C_FIELD(box, void **, 0x24), s16 *, 0x24) = v;
    }
}

void attr_ALIGN_table(void *node, BOX *box) {
    DOMString str;
    Element_getAttribute(&str, node, &_DOMalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMleft) == 0) {
            box->parent->style->unk70[1] = 1;
            box->style->unk70[1] = 1;
        } else if (DOMStringcasecmpFast(&str, &_DOMright) == 0) {
            box->parent->style->unk70[1] = 2;
            box->style->unk70[1] = 2;
        } else if (DOMStringcasecmpFast(&str, &_DOMcenter) == 0 || DOMStringcasecmpFast(&str, &_DOMmiddle) == 0) {
            box->style->unk6F = 2;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_ALIGN_td);

void attr_ALIGN_tr(void *node, BOX *box) {
    DOMString str;
    BOX *g;
    box->style->unk6F = 0;
    if ((g = getBoxByHTML(box, 0x56)) != NULL || (g = getBoxByHTML(box, 0x5B)) != NULL || (g = getBoxByHTML(box, 0x59)) != NULL) {
        box->style->unk6F = g->style->unk6F;
    }
    Element_getAttribute(&str, node, &_DOMalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMcenter) == 0 || DOMStringcasecmpFast(&str, &_DOMmiddle) == 0) {
            box->style->unk6F = 2;
        } else if (DOMStringcasecmpFast(&str, &_DOMright) == 0) {
            box->style->unk6F = 3;
        } else {
            box->style->unk6F = 1;
        }
    }
}

void attr_ALIGN_trgroup(void *node, BOX *box) {
    DOMString str;
    box->style->unk6F = 0;
    if (box->html == 0x16 && box->parent->html == 0x17) {
        box->style->unk6F = box->parent->style->unk6F;
    }
    Element_getAttribute(&str, node, &_DOMalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMcenter) == 0 || DOMStringcasecmpFast(&str, &_DOMmiddle) == 0) {
            box->style->unk6F = 2;
        } else if (DOMStringcasecmpFast(&str, &_DOMright) == 0) {
            box->style->unk6F = 3;
        } else {
            box->style->unk6F = 1;
        }
    }
}

void attr_BORDER_table(void *node, BOX *box) {
    int w;
    signed char *v;
    signed char *end;
    int frame;

    w = 1;
    box->style->unk30 = 0;
    box->style->unk32 = 0;
    box->style->unk34 = 0;
    box->style->unk36 = 0;
    v = getDOMAttributeValue(node, &_DOMborder);
    if (v != NULL || checkAtributeByName(node, "BORDER") == 0) {
        if (v != NULL) {
            w = strtol(v, &end, 10);
            if (end == v)
                w = 1;
        }
        if (w < 0)
            w = 1;
        frame = M2C_FIELD(box->geom, int *, 0);
        if (frame & 0x10) {
            if (frame & 1)
                box->style->unk30 = w;
            if (M2C_FIELD(box->geom, int *, 0) & 2)
                box->style->unk32 = w;
            if (M2C_FIELD(box->geom, int *, 0) & 4)
                box->style->unk34 = w;
            if (M2C_FIELD(box->geom, int *, 0) & 8)
                box->style->unk36 = w;
        } else {
            box->style->unk30 = w;
            box->style->unk32 = w;
            box->style->unk34 = w;
            box->style->unk36 = w;
        }
        if (w == 0)
            M2C_FIELD(box->geom, int *, 0) &= ~0x20;
        else
            M2C_FIELD(box->geom, int *, 0) |= 0x20;
        if (v != NULL)
            MEM_free(0, v);
    } else {
        frame = M2C_FIELD(box->geom, int *, 0);
        if (frame & 0x10) {
            if (frame & 1)
                box->style->unk30 = 1;
            if (M2C_FIELD(box->geom, int *, 0) & 2)
                box->style->unk32 = 1;
            if (M2C_FIELD(box->geom, int *, 0) & 4)
                box->style->unk34 = 1;
            if (M2C_FIELD(box->geom, int *, 0) & 8)
                box->style->unk36 = 1;
        }
    }
    box->style->unk48 = 6;
    box->style->unk4A = 6;
    box->style->unk4C = 6;
    box->style->unk4E = 6;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_BORDERCOLOR(void *arg0, void *arg1) {
    int temp_v0_2;
    signed char *temp_v0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMbordercolor);
    if (temp_v0 != NULL) {
        temp_v0_2 = colorValue(temp_v0);
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x38) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x3C) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x40) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x44) = temp_v0_2;
        MEM_free(0, temp_v0);
    }
}

void attr_CELLPADDING(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMcellpadding);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 0x4) = v;
    }
}

void attr_CELLSPACING(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMcellspacing);
    if (v >= 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 0x8) = v;
    }
}

void attr_COLSPAN(void *node, void *box) {
    char *str;
    char *end;
    int n;
    str = getDOMAttributeValue(node, &_DOMcolspan);
    if (str != NULL) {
        n = strtol(str, &end, 10);
        if (n < 0 || end == str) {
            n = 1;
        }
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), s16 *, 0x14) = n;
        MEM_free(0, str);
    } else {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), s16 *, 0x14) = 1;
    }
}

void attr_FRAME(void *node, BOX *box) {
    DOMString str;
    Element_getAttribute(&str, node, &_DOMframe);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMvoid) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x30;
        } else if (DOMStringcasecmpFast(&str, &_DOMabove) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x31;
        } else if (DOMStringcasecmpFast(&str, &_DOMbelow) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x34;
        } else if (DOMStringcasecmpFast(&str, &_DOMhsides) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x35;
        } else if (DOMStringcasecmpFast(&str, &_DOMlhs) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x38;
        } else if (DOMStringcasecmpFast(&str, &_DOMrhs) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x32;
        } else if (DOMStringcasecmpFast(&str, &_DOMvsides) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x3A;
        } else if (DOMStringcasecmpFast(&str, &_DOMbox) == 0 || DOMStringcasecmpFast(&str, &_DOMborder) == 0) {
            M2C_FIELD(box->geom, int *, 0) = 0x3F;
        } else {
            M2C_FIELD(box->geom, int *, 0) = 0;
        }
    } else {
        M2C_FIELD(box->geom, int *, 0) = 0;
    }
}

void attr_HEIGHT_table(void *node, BOX *box) {
    char *s;
    int n;
    box->style->flags &= ~0xC;
    s = getDOMAttributeValue(node, &_DOMheight);
    if (s != NULL) {
        n = atoi(s);
        if (n > 0) {
            if (strchr(s, '%') == NULL) {
                box->style->flags &= ~0xC;
                box->style->flags |= 0x4;
            } else {
                box->style->flags &= ~0xC;
                box->style->flags |= 0x8;
            }
            box->style->height = n;
        }
        MEM_free(0, s);
    }
}

void attr_HEIGHT_tr(void *node, BOX *box) {
    char *s;
    int n;
    box->style->flags &= ~0xC;
    s = getDOMAttributeValue(node, &_DOMheight);
    if (s != NULL) {
        n = atoi(s);
        if (n > 0) {
            if (strchr(s, '%') == NULL) {
                box->style->flags &= ~0xC;
                box->style->flags |= 0x4;
            } else {
                box->style->flags &= ~0xC;
                box->style->flags |= 0x8;
            }
            box->style->height = n;
        }
        MEM_free(0, s);
    }
}

void attr_HEIGHT_td(void *node, BOX *box) {
    char *s;
    int n;
    box->style->flags &= ~0xC;
    s = getDOMAttributeValue(node, &_DOMheight);
    if (s != NULL) {
        n = atoi(s);
        if (n > 0) {
            if (strchr(s, '%') == NULL) {
                box->style->flags &= ~0xC;
                box->style->flags |= 0x4;
            } else {
                box->style->flags &= ~0xC;
                box->style->flags |= 0x8;
            }
            box->style->height = n;
        }
        MEM_free(0, s);
    }
}

void attr_NOWRAP_td(void *node, void *box) {
    if (M2C_FIELD(box, s16 *, 0x38) == 6) {
        if (checkAtributeByName(node, "NOWRAP") == 0) {
            M2C_FIELD(M2C_FIELD(box, void **, 0x20), u16 *, 0x18) |= 1;
        } else {
            M2C_FIELD(M2C_FIELD(box, void **, 0x20), u16 *, 0x18) &= ~1;
        }
    }
}

void attr_ROWSPAN(void *node, void *box) {
    char *str;
    char *end;
    int n;
    str = getDOMAttributeValue(node, &_DOMrowspan);
    if (str != NULL) {
        n = strtol(str, &end, 10);
        if (n < 0 || end == str) {
            n = 1;
        }
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), s16 *, 0x16) = n;
        MEM_free(0, str);
    } else {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), s16 *, 0x16) = 1;
    }
}

void attr_SPAN(void *node, void *box) {
    int v = getDOMAttributeValue_PositiveNum(node, &_DOMspan);
    if (v > 0) {
        M2C_FIELD(M2C_FIELD(box, void **, 0x20), int *, 0x4) = v;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/act_selection", attr_VALIGN_td);

void attr_VALIGN_tr(void *node, BOX *box) {
    DOMString str;
    BOX *g;
    u8 a;
    if ((g = getBoxByHTML(box, 0x56)) != NULL || (g = getBoxByHTML(box, 0x5B)) != NULL || (g = getBoxByHTML(box, 0x59)) != NULL) {
        a = g->style->unk70[0];
        if (a != 0) {
            box->style->unk70[0] = a;
        }
    }
    Element_getAttribute(&str, node, &_DOMvalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMtop) == 0) {
            box->style->unk70[0] = 3;
        } else if (DOMStringcasecmpFast(&str, &_DOMmiddle) == 0 || DOMStringcasecmpFast(&str, &_DOMcenter) == 0) {
            box->style->unk70[0] = 5;
        } else if (DOMStringcasecmpFast(&str, &_DOMbottom) == 0 || DOMStringcasecmpFast(&str, &_DOMbaseline) == 0) {
            box->style->unk70[0] = 6;
        }
    }
}

void attr_VALIGN_trgroup(void *node, BOX *box) {
    DOMString str;
    if (box->html == 0x16 && box->parent->html == 0x17) {
        box->style->unk70[0] = box->parent->style->unk70[0];
    }
    Element_getAttribute(&str, node, &_DOMvalign);
    if (str.len != 0) {
        if (DOMStringcasecmpFast(&str, &_DOMtop) == 0) {
            box->style->unk70[0] = 3;
        } else if (DOMStringcasecmpFast(&str, &_DOMmiddle) == 0 || DOMStringcasecmpFast(&str, &_DOMcenter) == 0) {
            box->style->unk70[0] = 5;
        } else if (DOMStringcasecmpFast(&str, &_DOMbottom) == 0 || DOMStringcasecmpFast(&str, &_DOMbaseline) == 0) {
            box->style->unk70[0] = 6;
        }
    }
}

void attr_WIDTH_col(void *node, BOX *box) {
    char *s;
    int n;
    BOX *p = box->parent;

    if (p->html == 0x17) {
        box->style->flags &= ~0x3;
        box->style->flags |= p->style->flags & 3;
        box->style->width = p->style->width;
    }
    s = getDOMAttributeValue(node, &_DOMwidth);
    if (s != NULL) {
        n = atoi(s);
        if (n > 0) {
            if (strchr(s, '%') == NULL) {
                box->style->flags &= ~0x3;
                box->style->flags |= 0x1;
            } else {
                box->style->flags &= ~0x3;
                box->style->flags |= 0x2;
            }
            box->style->width = n;
        }
        MEM_free(0, s);
    }
}

void attr_WIDTH_table(void *node, BOX *box) {
    char *s;
    int n;
    box->style->flags &= ~0x3;
    s = getDOMAttributeValue(node, &_DOMwidth);
    if (s != NULL) {
        n = atoi(s);
        if (n > 0) {
            if (strchr(s, '%') == NULL) {
                box->style->flags &= ~0x3;
                box->style->flags |= 0x1;
            } else {
                box->style->flags &= ~0x3;
                box->style->flags |= 0x2;
            }
            box->style->width = n;
        }
        MEM_free(0, s);
    }
}

void attr_WIDTH_td(void *node, BOX *box) {
    char *s;
    int n;
    box->style->flags &= ~0x3;
    s = getDOMAttributeValue(node, &_DOMwidth);
    if (s != NULL) {
        n = atoi(s);
        if (n > 0) {
            if (strchr(s, '%') == NULL) {
                box->style->flags &= ~0x3;
                box->style->flags |= 0x1;
            } else {
                box->style->flags &= ~0x3;
                box->style->flags |= 0x2;
            }
            box->style->width = n;
        }
        MEM_free(0, s);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void attr_FOCUSCOLOR(void *arg0, void *arg1) {
    int temp_v0_2;
    signed char *temp_v0;

    temp_v0 = getDOMAttributeValue(arg0, &_DOMfocuscolor);
    if (temp_v0 != NULL) {
        temp_v0_2 = colorValue(temp_v0);
        if (temp_v0_2 != 0) {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x60) = temp_v0_2;
        } else {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), int *, 0x60) = 0;
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x24), signed char *, 0x6E) = 1;
        }
        MEM_free(0, temp_v0);
    }
}

int html_BODY(void *node, int parent) {
    BOX *box;

    box = getBodyBox(parent);
    if (box == NULL)
        return 0;
    attr_MARGINWIDTH(node, box);
    attr_MARGINHEIGHT(node, box);
    attr_BGCOLOR(node, box);
    attr_BACKGROUND(node, box);
    attr_TEXT(node, box);
    attr_LINK(node, box);
    attr_VLINK(node, box);
    M2C_FIELD(box->style, u8 *, 0x10) = 1;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    if (box->region == NULL)
        box->region = lfm_createPageRegion(box, M2C_FIELD(box->geom, int *, 8));
    else
        lfm_resetPageRegion(box->region, M2C_FIELD(box->geom, int *, 8));
    return 0;
}

void *html_HEAD(void *node, void *parent, void *prev) {
    void *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    M2C_FIELD(box, s16 *, 0x3C) = 0;
    M2C_FIELD(box, s16 *, 0x3A) = 0x2C;
    initNoneContent(box, node);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_HTML(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_TITLE(void) {
    return 0;
}
