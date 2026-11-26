/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
BOX *createBox(void *ctx, int type);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void initBoxProperty(BOX *box);
void applyCSSExtStyleSheetToBox(void *node, BOX *box);
void applyCSSInlinePropertyToBox(void *node, BOX *box);
void commonProc_html_text_inline(void *a0, void *a1, void *a2, int tag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_inline", commonProc_html_text_inline);

void html_ABBR(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x2);
}

void html_ACRONYM(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x3);
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

void html_CITE(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x14);
}

void html_CODE(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x15);
}

void html_DFN(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x1A);
}

void html_EM(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x1F);
}

void html_KBD(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x35);
}

void html_Q(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x49);
}

void html_SAMP(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x4B);
}

void html_SPAN(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x4F);
}

void html_STRONG(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x51);
}

void html_VAR(void *a0, void *a1, void *a2) {
    commonProc_html_text_inline(a0, a1, a2, 0x61);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_inline", html_A);
