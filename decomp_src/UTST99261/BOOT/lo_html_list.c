/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
BOX *createBox(void *ctx, int type);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initLiContent(BOX *box, void *ctx);
BOX *getParentBlockBox(BOX *box);
int getContainingBlockWidth(BOX *box);
void GUI_Graphics_getStringSize(int font, char *s, int n, int *w, int *h);
extern char D_0013F088[];
BOX *getBoxByHTML(BOX *box, int html);
typedef struct UICOLORS { int color[4][7]; int unk70; int unk74; } UICOLORS;
#define TEXTCOLOR(b) ((b)->style->unk64 = ((UICOLORS *)ui_global)->color[(b)->style->unk6A][(b)->style->fontSize])
BOX *createInlineBox(void *ctx, BOX *parent, BOX *prev);
BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev);
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */
extern void *ui_global;



extern unsigned char _DOMstart;
BOX *createListBox(void *node, BOX *parent, BOX *prev, int html);
char *getDOMAttributeValue(void *node, void *name);
int atoi(const char *s);
int getTypeAtAttr(void *node);
void initBoxList(void *l);
void MEM_free(void *pool, void *p);
extern unsigned char _DOMtype;
extern char D_0013F070[];
extern char D_0013F078[];
extern char D_0013F080[];
int strcasecmp(const char *a, const char *b);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", getLINumber);

BOX *createLIBox_li(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    BOX *cb;
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 0;
    box->html = 0x38;
    initLiContent(box, node);
    initBoxProperty(box);
    cb = getParentBlockBox(box);
    if (cb != NULL) {
        box->width = getContainingBlockWidth(cb);
    }
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", createLIBox_head);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", getTypeAtAttr);

BOX *html_DL(void *node, BOX *parent, BOX *prev) {
    int w;
    int h;
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x1D;
    initBoxProperty(box);
    GUI_Graphics_getStringSize(box->style->unk64, D_0013F088, 1, &w, &h);
    box->style->unk20 = h;
    box->style->unk24 = h;
    if (getBoxByHTML(parent, 0x1D) != NULL) {
        box->style->unk26 = ((UICOLORS *)ui_global)->unk74 * 4;
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_DT(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x1E;
    initBoxProperty(box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_DD(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x18;
    initBoxProperty(box);
    box->style->unk26 = ((UICOLORS *)ui_global)->unk74 * 4;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_OL(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    int w, h;
    int start;
    char *s;
    int t;

    box = createListBox(node, parent, prev, 0x43);
    if (box == NULL)
        return NULL;
    box->style->unk26 = ((UICOLORS *)ui_global)->unk74 * 4;
    GUI_Graphics_getStringSize(box->style->unk64, D_0013F088, 1, &w, &h);
    M2C_FIELD(box->style, s16 *, 0x20) = h;
    M2C_FIELD(box->style, s16 *, 0x24) = h;
    start = 0;
    s = getDOMAttributeValue(node, &_DOMstart);
    if (s != NULL) {
        start = atoi(s);
        start = start < 0 ? 0 : start;
        MEM_free(0, s);
    }
    M2C_FIELD(box->geom, int *, 0) = start;
    t = getTypeAtAttr(node);
    if (t == 3)
        M2C_FIELD(box->geom, int *, 4) = 11;
    else
        M2C_FIELD(box->geom, int *, 4) = t;
    initBoxList((char *)box->geom + 8);
    applyCSSExtStyleSheetToBox((int)node, box);
    applyCSSInlinePropertyToBox((int)node, box);
    return box;
}

BOX *html_UL(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    BOX *ul;
    int w, h;
    int t;
    char *s;

    box = createListBox(node, parent, prev, 0x60);
    if (box == NULL)
        return NULL;
    box->style->unk26 = ((UICOLORS *)ui_global)->unk74 * 4;
    GUI_Graphics_getStringSize(box->style->unk64, D_0013F088, 1, &w, &h);
    M2C_FIELD(box->style, s16 *, 0x20) = h;
    M2C_FIELD(box->style, s16 *, 0x24) = h;
    t = 0;
    ul = getBoxByHTML(box->parent, 0x60);
    if (ul != NULL) {
        t = M2C_FIELD(ul->geom, int *, 4) + 1;
        if (t >= 3)
            t = 0;
    }
    s = getDOMAttributeValue(node, &_DOMtype);
    if (s != NULL) {
        if (strcasecmp(s, D_0013F070) == 0)
            t = 1;
        else if (strcasecmp(s, D_0013F078) == 0)
            t = 2;
        else if (strcasecmp(s, D_0013F080) == 0)
            t = 0;
        MEM_free(0, s);
    }
    M2C_FIELD(box->geom, int *, 4) = t;
    applyCSSExtStyleSheetToBox((int)node, box);
    applyCSSInlinePropertyToBox((int)node, box);
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_LI);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_APPLET_inner);

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_APPLET(void) {
    return 0;
}

BOX *html_B(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x7;
    box->style->unk6A |= 1;
    TEXTCOLOR(box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_BIG(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0xC;
    if (box->style->fontSize < 6) {
        box->style->fontSize++;
        TEXTCOLOR(box);
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_HR);

BOX *html_I(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x2F;
    box->style->unk6A |= 2;
    TEXTCOLOR(box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_SMALL(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x4E;
    if (box->style->fontSize > 0) {
        box->style->fontSize--;
        TEXTCOLOR(box);
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_SUB(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x53;
    box->style->unk70[0] = 1;
    if (box->style->fontSize > 0) {
        box->style->fontSize--;
        TEXTCOLOR(box);
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_SUP(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x54;
    box->style->unk70[0] = 2;
    if (box->style->fontSize > 0) {
        box->style->fontSize--;
        TEXTCOLOR(box);
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_TT(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x5E;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_DEL(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x19;
    box->style->unk6C[0] |= 4;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_INS(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x33;
    box->style->unk6C[0] |= 2;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_BDO(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0xA;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}
