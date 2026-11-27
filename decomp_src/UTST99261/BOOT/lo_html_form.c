/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
BOX *getBoxByHTML(BOX *box, int html);
BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev);
void *Node_getOwnerDocument(void *node);
BOX *Node_getBox(void *node);
void addMapList(BOX *box, char *name);
extern unsigned char _DOMname;
int html_IMG_inner(void *node, BOX *box);
BOX *getBodyBox(BOX *box);
void addBoxList(void *list, BOX *box);
BOX *createBox(void *ctx, int type);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void initBoxProperty(BOX *box);
void applyCSSExtStyleSheetToBox(void *node, BOX *box);
void applyCSSInlinePropertyToBox(void *node, BOX *box);
extern unsigned char _DOMtabindex;
char *getDOMAttributeValue(void *node, void *name);
M2C_UNK MEM_free(M2C_UNK, int);                     /* extern */
int getRawTextFromDomTree(int);                     /* extern */
int getSessionSaveData(int);                        /* extern */

M2C_UNK processArea();                              /* extern */


typedef struct SelOpt { struct SelOpt *next; int pad[4]; int selected; } SelOpt;
typedef struct SelInfo { int pad[2]; SelOpt *opts; int *sel; } SelInfo;
void initSelectBoxSize(BOX *box);
extern unsigned char _DOMalign;
int getLegendTextWidth(BOX *box);
void initLinePosition(BOX *box);
void moveBoxPosition(BOX *box, int dx, int dy);
int strcmp(const char *a, const char *b);
void GUI_Graphics_getStringSize(int font, char *s, int n, int *w, int *h);
void addFormList(BOX *body, void *node);
void *MEM_malloc(int pool, unsigned int size);
int colorValue(char *s);
int sjisToUtf8(char *dst, char *src, int len);
void initButtonContent(BOX *box, void *node);
void initButtonBoxSize(BOX *box);
typedef struct { int color; } STYLE0;
extern char D_0013F0A4[];
extern char D_0013F0AC[];
extern char D_0013F0B4[];
void initSelectContent(BOX *box, void *node);
int Element_hasAttribute(void *node, void *name);
void attr_FOCUSCOLOR(void *node, BOX *box);
void addFocusList(void *ctx, int kind, void *node, short tabindex, void *info);
void addFormElementList(BOX *body, int a, void *node);
void addSelectList(BOX *box);
extern unsigned char _DOMdisabled;
extern char D_0013F0D0[];
int atoi(const char *s);
void initTextAreaContent(BOX *box, void *node);
void initTextAreaBoxSize(BOX *box, int cols, int rows);
extern unsigned char _DOMcols;
extern unsigned char _DOMrows;
typedef struct OptN { struct OptN *next; struct OptN *prev; char *text; char *value; void *node; int selected; int x18; } OptN;
typedef struct { int pad[2]; OptN *opts; void *sel; } SelI;
char *getTextFromDomTree(void *node);
void *MEM_calloc(int pool, unsigned int size);
extern unsigned char _DOMvalue;
extern unsigned char _DOMselected;
extern unsigned char _DOMmultiple;
int getTabindex(void *node) {
    char *s;
    s16 n = 0;
    s = getDOMAttributeValue(node, &_DOMtabindex);
    if (s != NULL) {
        n = strtol(s, NULL, 10);
        if (n < 0) {
            n = 0;
        }
        MEM_free(0, s);
    }
    return n;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", D_0013F0A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", D_0013F0AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", D_0013F0B4);

BOX *createFileRefButton(void *node, BOX *parent, BOX *prev) {
    char *s;
    BOX *box;

    s = MEM_malloc(0, 0xD);
    if (s == NULL) {
        return NULL;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        MEM_free(0, (int)s);
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x32;
    initButtonContent(box, node);
    *box->style = *prev->style;
    box->style->unk54 = colorValue(D_0013F0A4);
    ((STYLE0 *)box->style)->color = colorValue(D_0013F0AC);
    box->style->unk74 = 2;
    s[sjisToUtf8(s, D_0013F0B4, 4)] = 0;
    if (M2C_FIELD(box->geom, char **, 8) != NULL) {
        MEM_free(0, M2C_FIELD(box->geom, int *, 8));
    }
    M2C_FIELD(box->geom, char **, 8) = s;
    initButtonBoxSize(box);
    return box;
}

BOX *html_OPTION_sub(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    if (getBoxByHTML(parent, 0x4D) == NULL) {
        return NULL;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x45;
    initNoneContent(box, node);
    initBoxProperty(box);
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", getLegendTextWidth);

BOX *html_FORM(void *node, BOX *parent, BOX *prev) {
    int w;
    int h;
    BOX *box;

    if (getBoxByHTML(parent, 0x11) != NULL) {
        return NULL;
    }
    box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x23;
    initBoxProperty(box);
    GUI_Graphics_getStringSize(box->style->unk64, "m", 1, &w, &h);
    box->style->unk20 = h;
    box->style->unk24 = h;
    addFormList(getBodyBox(box), node);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    if (parent != box->parent) {
        box->style->unk20 = 0;
        box->style->unk22 = 0;
        box->style->unk24 = 0;
        box->style->unk26 = 0;
        box->style->unk30 = 0;
        box->style->unk32 = 0;
        box->style->unk34 = 0;
        box->style->unk36 = 0;
        box->style->unk28 = 0;
        box->style->unk2A = 0;
        box->style->unk2C = 0;
        box->style->unk2E = 0;
    }
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_INPUT);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", D_0013F0D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", D_0013F0D8);


BOX *html_SELECT(void *node, BOX *parent, BOX *prev) {
    BOX *box;

    if (getBoxByHTML(parent, 0x11) != NULL) {
        return NULL;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x4D;
    initSelectContent(box, node);
    initBoxProperty(box);
    box->style->unk20 = 2;
    box->style->unk22 = 2;
    box->style->unk24 = 2;
    box->style->unk26 = 2;
    box->style->unk54 = colorValue(D_0013F0A4);
    ((STYLE0 *)box->style)->color = colorValue(D_0013F0D0);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    initSelectBoxSize(box);
    if (Element_hasAttribute(node, &_DOMdisabled) == 1) {
        M2C_FIELD(box, s16 *, 0x3E) = 1;
    } else {
        attr_FOCUSCOLOR(node, box);
        addFocusList(Node_getBox(Node_getOwnerDocument(node)), 0, box, getTabindex(node), 0);
    }
    addFormElementList(getBodyBox(box), 0, node);
    addSelectList(box);
    return box;
}

void html_SELECT_after(void *node, BOX *box) {
    SelInfo *si = (SelInfo *)box->geom;
    int *sel;
    SelOpt *o;
    int i, k;

    if (si->sel != NULL) {
        sel = si->sel;
        i = 0;
        k = 0;
        for (o = si->opts; o != NULL && i < sel[0]; o = o->next, k++) {
            if (sel[i + 1] == k) {
                o->selected = 1;
                i++;
            }
        }
    }
    initSelectBoxSize(box);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_OPTION(void *node, BOX *parent, BOX *prev) {
    return html_OPTION_sub(node, parent, prev);
}

void html_OPTION_after(void *node, BOX *box) {
    BOX *b;
    SelI *si;
    OptN *o;
    OptN *n;
    OptN *p;
    int found;

    for (b = box->parent; b != NULL; b = b->parent) {
        if (b->content == 0x12) {
            break;
        }
    }
    if (b == NULL) {
        return;
    }
    si = (SelI *)b->geom;
    o = si->opts;
    if (o != NULL) {
        while (o->next != NULL) {
            o = o->next;
        }
        if (o->node == node) {
            if (si->opts == o) {
                si->opts = NULL;
            } else {
                o->prev->next = NULL;
            }
            if (o->text != NULL) {
                MEM_free(0, (int)o->text);
            }
            if (o->value != NULL) {
                MEM_free(0, (int)o->value);
            }
            MEM_free(0, (int)o);
        }
    }
    n = MEM_malloc(0, sizeof(OptN));
    if (n == NULL) {
        return;
    }
    n->next = NULL;
    n->prev = NULL;
    n->text = NULL;
    n->value = NULL;
    n->selected = 0;
    n->x18 = 0;
    n->node = node;
    n->text = getTextFromDomTree(node);
    if (n->text == NULL) {
        n->text = MEM_calloc(0, 1);
        if (n->text == NULL) {
            goto fail;
        }
    }
    n->value = getDOMAttributeValue(n->node, &_DOMvalue);
    if (n->value == NULL && !Element_hasAttribute(n->node, &_DOMvalue)) {
        n->value = getTextFromDomTree(node);
        if (n->value == NULL) {
            n->value = MEM_calloc(0, 1);
            if (n->value == NULL) {
                MEM_free(0, (int)n->text);
fail:
                MEM_free(0, (int)n);
                return;
            }
        }
    }
    if (si->sel == NULL && Element_hasAttribute(n->node, &_DOMselected)) {
        if (!Element_hasAttribute(M2C_FIELD(b, void **, 0x28), &_DOMmultiple)) {
            found = 0;
            for (o = si->opts; o != NULL; o = o->next) {
                if (o->selected) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                n->selected = 1;
            }
        } else {
            n->selected = 1;
        }
    }
    if (si->opts == NULL) {
        si->opts = n;
    } else {
        p = si->opts;
        for (;;) {
            if (p->next == NULL) {
                break;
            }
            p = p->next;
        }
        p->next = n;
        n->prev = p;
    }
}

BOX *html_TEXTAREA(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    char *s;
    int cols;
    int rows;

    if (getBoxByHTML(parent, 0x11) != NULL) {
        return NULL;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x58;
    initTextAreaContent(box, node);
    initBoxProperty(box);
    box->style->unk20 = 2;
    box->style->unk22 = 2;
    box->style->unk24 = 2;
    box->style->unk26 = 2;
    box->style->unk54 = colorValue(D_0013F0A4);
    ((STYLE0 *)box->style)->color = colorValue(D_0013F0D0);
    rows = 0;
    cols = 0;
    s = getDOMAttributeValue(node, &_DOMcols);
    if (s != NULL) {
        cols = atoi(s);
        MEM_free(0, (int)s);
    }
    s = getDOMAttributeValue(node, &_DOMrows);
    if (s != NULL) {
        rows = atoi(s);
        MEM_free(0, (int)s);
    }
    M2C_FIELD(box->geom, int *, 4) = cols;
    M2C_FIELD(box->geom, int *, 8) = rows;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    initTextAreaBoxSize(box, cols, rows);
    if (Element_hasAttribute(node, &_DOMdisabled) == 1) {
        M2C_FIELD(box, s16 *, 0x3E) = 1;
    } else {
        attr_FOCUSCOLOR(node, box);
        addFocusList(Node_getBox(Node_getOwnerDocument(node)), 0, box, getTabindex(node), 0);
    }
    addFormElementList(getBodyBox(box), 0, node);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void html_TEXTAREA_after(int arg0, void *arg1) {
    int temp_a1;
    int temp_v0;

    if (getSessionSaveData(HST_getSessionID(M2C_FIELD(M2C_FIELD(getBodyBox(arg1), void **, 0x20), void **, 0x20))) == 0) {
        temp_a1 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), int *, 0x14);
        if (temp_a1 != 0) {
            MEM_free(0, temp_a1);
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), int *, 0x14) = 0;
        }
        temp_v0 = getRawTextFromDomTree(arg0);
        if (temp_v0 != 0) {
            M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), int *, 0x14) = temp_v0;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_BUTTON);

BOX *html_FIELDSET(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    if (getBoxByHTML(parent, 0x11) != NULL) {
        return NULL;
    }
    box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x21;
    initBoxProperty(box);
    box->style->unk30 = 2;
    box->style->unk32 = 2;
    box->style->unk34 = 2;
    box->style->unk36 = 2;
    box->style->unk48 = 3;
    box->style->unk4A = 3;
    box->style->unk4C = 3;
    box->style->unk4E = 3;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_LABEL(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    if (getBoxByHTML(parent, 0x11) != NULL) {
        return NULL;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x36;
    initNoneContent(box, node);
    initBoxProperty(box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_LEGEND(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x37;
    initNoneContent(box, node);
    initBoxProperty(box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

void html_LEGEND_after(void *node, BOX *box) {
    BOX *fs;
    int w;
    int h;
    int dx;
    char *a;

    fs = getBoxByHTML(box, 0x21);
    if (fs == NULL)
        return;
    w = getLegendTextWidth(box);
    moveBoxPosition(fs, 0, box->height / 2);
    h = box->height / 2;
    a = getDOMAttributeValue(M2C_FIELD(box, void **, 0x28), &_DOMalign);
    if (a == NULL) {
        moveBoxPosition(box, 8, -h);
    } else {
        if (strcmp(a, "RIGHT") == 0 && (dx = fs->width - w - 16) > 0)
            moveBoxPosition(box, dx, -h);
        else
            moveBoxPosition(box, 8, -h);
        MEM_free(0, a);
    }
    M2C_FIELD(box->style, u8 *, 0x10) = 1;
    initLinePosition(box);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_OPTGROUP(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_IMG_inner);

BOX *html_IMG(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    BOX *body;
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x31;
    if (html_IMG_inner(node, box) == 1) {
        body = getBodyBox(box);
        if (body != NULL && box != NULL) {
            addBoxList((char *)body->geom + 0xA8, box);
        }
    }
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", processArea);

#ifndef NULL
#define NULL ((void *)0)
#endif

int html_AREA(void) {
    processArea();
    return 0;
}

BOX *html_MAP(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    char *name;
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x3B;
    initNoneContent(box, node);
    initBoxProperty(box);
    name = getDOMAttributeValue(node, &_DOMname);
    if (name != NULL) {
        addMapList(Node_getBox(Node_getOwnerDocument(node)), name);
        MEM_free(0, name);
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}
