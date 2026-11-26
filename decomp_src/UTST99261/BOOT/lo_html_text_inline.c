/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_inline", html_A);
