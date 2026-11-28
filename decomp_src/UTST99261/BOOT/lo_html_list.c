/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
extern char lo_global[];
BOX *createBox(void *ctx, int type);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initLiContent(BOX *box, void *ctx);
BOX *getParentBlockBox(BOX *box);
int getContainingBlockWidth(BOX *box);
void GUI_Graphics_getStringSize(int font, char *s, int n, int *w, int *h);
BOX *getBoxByHTML(BOX *box, int html);
typedef struct UICOLORS { int color[4][7]; int unk70; int unk74; } UICOLORS;
#define TEXTCOLOR(b) ((b)->style->unk64 = ((UICOLORS *)ui_global)->color[(b)->style->unk6A][(b)->style->fontSize])
BOX *createInlineBox(void *ctx, BOX *parent, BOX *prev);
BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev);
void applyCSSExtStyleSheetToBox(int, void *);    /* extern */
void applyCSSInlinePropertyToBox(int, void *);   /* extern */
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
int strcasecmp(const char *a, const char *b);
int strcmp(const char *a, const char *b);
extern unsigned char _DOMvalue;
BOX *getListBox(BOX *b);
void addBoxList(void *l, BOX *b);
signed char *getListNumChar(int n, int type);
void *createLIBox_head(void *node, BOX *li, signed char *str, int type);
void delLinkBox(BOX *b);
void freeBox(BOX *b, int f);
void initTextContent(BOX *b, void *node, signed char *s);
void initImageContent(BOX *b, void *node);
void initTextBoxSize(BOX *b);
void initImageBoxSize(BOX *b, int w, int h);
typedef struct LIENT { struct LIENT *next; int x4; BOX *box; } LIENT;
void attr_HSPACE(void *node, BOX *box);
void attr_VSPACE(void *node, BOX *box);
void attr_ALIGN_image(void *node, BOX *box);
BOX *getBodyBox(BOX *box);
char *strchr(const char *s, int c);
void setBoxSize(BOX *box, int w, int h);
extern unsigned char _DOMwidth;
extern unsigned char _DOMheight;
int getLINumber(BOX *box, BOX *li) {
    int n;
    LIENT *e;

    n = 1;
    if (box->html == 0x43) {
        n = 0;
        for (e = M2C_FIELD(box->geom, LIENT **, 8); e != NULL && e->box != li; e = e->next)
            n = M2C_FIELD(e->box->geom, int *, 0);
        if (n == 0) {
            if (M2C_FIELD(box->geom, int *, 0) != 0)
                n = M2C_FIELD(box->geom, int *, 0);
            else
                n++;
        } else
            n++;
    }
    return n;
}

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

void *createLIBox_head(void *node, BOX *li, signed char *str, int type) {
    BOX *b;
    int w, h;
    int img;

    b = createBox(NULL, 1);
    if (b == NULL)
        return NULL;
    linkBox(b, li, NULL);
    b->display = 1;
    b->html = 0x66;
    if (str != NULL) {
        initTextContent(b, node, str);
        initBoxProperty(b);
        M2C_FIELD(b->style, s16 *, 0x22) = ((UICOLORS *)ui_global)->unk74;
        M2C_FIELD(b->style, s16 *, 0x30) = 0;
        M2C_FIELD(b->style, s16 *, 0x34) = 0;
        M2C_FIELD(b->style, s16 *, 0x32) = 0;
        M2C_FIELD(b->style, s16 *, 0x36) = 0;
        M2C_FIELD(b->geom, u8 *, 0x10) = M2C_FIELD(b->style, u8 *, 0x68);
        initTextBoxSize(b);
        return b;
    }
    initImageContent(b, node);
    initBoxProperty(b);
    M2C_FIELD(b->style, s16 *, 0x22) = ((UICOLORS *)ui_global)->unk74;
    GUI_Graphics_getStringSize(b->style->unk64, "A", 1, &w, &h);
    switch (type) {
    case 1:
        M2C_FIELD(b->geom, int *, 0) = (*(int *)(lo_global + 0x28));
        break;
    case 2:
        M2C_FIELD(b->geom, int *, 0) = (*(int *)(lo_global + 0x2C));
        break;
    case 0:
        M2C_FIELD(b->geom, int *, 0) = (*(int *)(lo_global + 0x24));
        break;
    default:
        M2C_FIELD(b->geom, int *, 0) = (*(int *)(lo_global + 0x24));
        break;
    }
    initImageBoxSize(b, h, h);
    M2C_FIELD(b->geom, int *, 0x14) = 1;
    return b;
}

int getTypeAtAttr(void *node) {
    int t;
    char *s;

    t = 3;
    s = getDOMAttributeValue(node, &_DOMtype);
    if (s == NULL)
        return 3;
    if (strcmp(s, "A") == 0)
        t = 12;
    else if (strcmp(s, "a") == 0)
        t = 13;
    else if (strcmp(s, "I") == 0)
        t = 14;
    else if (strcmp(s, "i") == 0)
        t = 15;
    else if (strcmp(s, "1") == 0)
        t = 11;
    else if (strcasecmp(s, "CIRCLE") == 0)
        t = 1;
    else if (strcasecmp(s, "SQUARE") == 0)
        t = 2;
    else if (strcasecmp(s, "DISC") == 0)
        t = 0;
    MEM_free(0, s);
    return t;
}

BOX *html_DL(void *node, BOX *parent, BOX *prev) {
    int w;
    int h;
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x1D;
    initBoxProperty(box);
    GUI_Graphics_getStringSize(box->style->unk64, "m", 1, &w, &h);
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
    GUI_Graphics_getStringSize(box->style->unk64, "m", 1, &w, &h);
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
    GUI_Graphics_getStringSize(box->style->unk64, "m", 1, &w, &h);
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
        if (strcasecmp(s, "CIRCLE") == 0)
            t = 1;
        else if (strcasecmp(s, "SQUARE") == 0)
            t = 2;
        else if (strcasecmp(s, "DISC") == 0)
            t = 0;
        MEM_free(0, s);
    }
    M2C_FIELD(box->geom, int *, 4) = t;
    applyCSSExtStyleSheetToBox((int)node, box);
    applyCSSInlinePropertyToBox((int)node, box);
    return box;
}

BOX *html_LI(void *node, BOX *parent, BOX *prev) {
    BOX *li;
    BOX *list;
    int type;
    int val;
    int num;
    int ltype;
    char *s;
    signed char *str;

    ltype = 0;
    li = createLIBox_li(node, parent, prev);
    if (li == NULL)
        return NULL;
    list = getListBox(li);
    if (list != NULL)
        addBoxList((char *)list->geom + 8, li);
    type = getTypeAtAttr(node);
    val = 0;
    s = getDOMAttributeValue(node, &_DOMvalue);
    if (s != NULL) {
        val = atoi(s);
        val = val < 0 ? 0 : val;
        MEM_free(0, s);
    }
    if (list != NULL) {
        if (list->html == 0x43) {
            num = val;
            if (num == 0)
                num = getLINumber(list, li);
            M2C_FIELD(li->geom, int *, 0) = num;
            if (type == 3)
                ltype = M2C_FIELD(list->geom, int *, 4);
            else
                ltype = type;
            str = getListNumChar(num, ltype);
        } else {
            if (type == 3)
                ltype = M2C_FIELD(list->geom, int *, 4);
            else
                ltype = type;
            str = NULL;
        }
    } else {
        str = NULL;
    }
    if (createLIBox_head(node, li, str, ltype) == NULL) {
        delLinkBox(li);
        freeBox(li, 0);
        return NULL;
    }
    applyCSSExtStyleSheetToBox((int)node, li);
    applyCSSInlinePropertyToBox((int)node, li);
    return li;
}

void html_APPLET_inner(void *node, BOX *parent, BOX *prev, BOX *box) {
    BOX *body;
    char *s;
    int w;
    int h;

    initBoxProperty(box);
    attr_HSPACE(node, box);
    attr_VSPACE(node, box);
    attr_ALIGN_image(node, box);
    if (M2C_FIELD(box->style, s8 *, 0x71)) {
        box->display = 2;
    }
    body = getBodyBox(box);
    h = 100;
    w = 100;
    s = getDOMAttributeValue(node, &_DOMwidth);
    if (s != NULL) {
        w = atoi(s);
        w = w < 1 ? 1 : w;
        if (strchr(s, '%')) {
            w = w * M2C_FIELD(body->geom, int *, 8) / 100;
        }
        MEM_free(0, s);
    }
    s = getDOMAttributeValue(node, &_DOMheight);
    if (s != NULL) {
        h = atoi(s);
        h = h < 1 ? 1 : h;
        if (strchr(s, '%')) {
            h = h * M2C_FIELD(body->geom, int *, 0xC) / 100;
        }
        MEM_free(0, s);
    }
    setBoxSize(box, w, h);
}

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
