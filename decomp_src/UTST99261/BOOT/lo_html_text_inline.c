/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
extern char lo_global[];
BOX *createInlineBox(void *ctx, BOX *parent, BOX *prev);
typedef struct UICOLORS { int color[4][7]; } UICOLORS;
extern void *ui_global;
#define TEXTCOLOR(b) ((b)->style->unk64 = ((UICOLORS *)ui_global)->color[(b)->style->unk6A][(b)->style->fontSize])
BOX *commonProc_html_text_inline(void *node, BOX *parent, BOX *prev, s16 tag);
BOX *createBox(void *ctx, int type);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void initBoxProperty(BOX *box);
void applyCSSExtStyleSheetToBox(void *node, BOX *box);
void applyCSSInlinePropertyToBox(void *node, BOX *box);

BOX *getBoxByHTML(BOX *box, int html);
char *getDOMAttributeValue(void *node, void *name);
int Element_hasAttribute(void *node, void *name);
void *Node_getOwnerDocument(void *node);
void *Node_getBox(void *doc);
void addFocusList(void *ctx, int kind, void *node, short tabindex, void *info);
void attr_FOCUSCOLOR(void *node, BOX *box);
char *lo_fullUrl(BOX *box, char *s);
int searchUrlList(LIST *list, char *url);
void processArea(void *node);
long strtol(const char *s, char **end, int base);
void *MEM_malloc(void *pool, unsigned int size);
void MEM_free(void *pool, void *p);
extern unsigned char _DOMtabindex;
extern unsigned char _DOMhref;
BOX *commonProc_html_text_inline(void *node, BOX *parent, BOX *prev, s16 tag) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = tag;
    switch (tag) {
    case 0x14:
    case 0x1A:
    case 0x1F:
    case 0x61:
        box->style->unk6A |= 2;
        TEXTCOLOR(box);
        break;
    case 0x51:
        box->style->unk6A |= 1;
        TEXTCOLOR(box);
        break;
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_ABBR(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x2);
}

BOX *html_ACRONYM(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x3);
}

BOX *html_BR(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x10;
    initNoneContent(box, node);
    initBoxProperty(box);
    return box;
}

BOX *html_CITE(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x14);
}

BOX *html_CODE(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x15);
}

BOX *html_DFN(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x1A);
}

BOX *html_EM(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x1F);
}

BOX *html_KBD(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x35);
}

BOX *html_Q(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x49);
}

BOX *html_SAMP(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x4B);
}

BOX *html_SPAN(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x4F);
}

BOX *html_STRONG(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x51);
}

BOX *html_VAR(void *a0, BOX *a1, BOX *a2) {
    return commonProc_html_text_inline(a0, a1, a2, 0x61);
}

BOX *html_A(void *node, BOX *parent, BOX *prev) {
    BOX *box;
    char *s;
    char *href;
    char *url;
    short tab = 0;

    if (getBoxByHTML(parent, 0x11) != NULL) {
        return NULL;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 1;
    initNoneContent(box, node);
    initBoxProperty(box);
    s = getDOMAttributeValue(node, &_DOMtabindex);
    if (s != NULL) {
        tab = strtol(s, NULL, 10);
        tab = tab < 0 ? 0 : tab;
        MEM_free(0, s);
    }
    if (Element_hasAttribute(node, &_DOMhref)) {
        addFocusList(Node_getBox(Node_getOwnerDocument(node)), 0, box, tab, 0);
        href = getDOMAttributeValue(node, &_DOMhref);
        if (href == NULL) {
            href = MEM_malloc(0, 1);
            *href = 0;
        }
        attr_FOCUSCOLOR(node, box);
        url = lo_fullUrl(box, href);
        if (url != NULL) {
            if (searchUrlList(&(*(LIST *)(lo_global + 0x58)), url) == 1) {
                box->style->unk54 = M2C_FIELD(box->style, int *, 0x5C);
            } else {
                box->style->unk54 = M2C_FIELD(box->style, int *, 0x58);
            }
            box->style->unk38 = box->style->unk54;
            box->style->unk3C = box->style->unk54;
            box->style->unk40 = box->style->unk54;
            box->style->unk44 = box->style->unk54;
            MEM_free(0, url);
        }
        box->style->unk6C[0] |= 2;
    }
    processArea(node);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}
