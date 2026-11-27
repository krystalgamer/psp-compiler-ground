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
extern char D_0013F114[];
int getLegendTextWidth(BOX *box);
void initLinePosition(BOX *box);
void moveBoxPosition(BOX *box, int dx, int dy);
int strcmp(const char *a, const char *b);
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", createFileRefButton);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_FORM);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_INPUT);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_SELECT);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_OPTION_after);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_form", html_TEXTAREA);

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
        if (strcmp(a, D_0013F114) == 0 && (dx = fs->width - w - 16) > 0)
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
