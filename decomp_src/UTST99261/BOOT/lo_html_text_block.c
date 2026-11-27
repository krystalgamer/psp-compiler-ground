/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
typedef struct UICOLORS { int color[4][7]; int unk70; int unk74; } UICOLORS;
#define TEXTCOLOR(b) ((b)->style->unk64 = ((UICOLORS *)ui_global)->color[(b)->style->unk6A][(b)->style->fontSize])
BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev);
void GUI_Graphics_getStringSize(int font, char *s, int n, int *w, int *h);
extern char D_0013F040[];
extern void *ui_global;
void html_Heading_inner(void *a0, void *a1, void *a2, int tag);
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
M2C_UNK attr_ALIGN_text_block(int, void *);         /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */


INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_block", D_0013F040);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_text_block", html_Heading_inner);

BOX *html_ADDRESS(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x4;
    initBoxProperty(box);
    box->style->unk6A |= 2;
    TEXTCOLOR(box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_BLOCKQUOTE(void *node, BOX *parent, BOX *prev) {
    int w;
    int h;
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0xE;
    initBoxProperty(box);
    box->style->unk26 = ((UICOLORS *)ui_global)->unk74 * 4;
    box->style->unk22 = ((UICOLORS *)ui_global)->unk74 * 4;
    GUI_Graphics_getStringSize(box->style->unk64, D_0013F040, 1, &w, &h);
    box->style->unk20 = h;
    box->style->unk24 = h;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_DIV(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x1C;
    initBoxProperty(box);
    attr_ALIGN_text_block(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

void html_H1(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x26);
}

void html_H2(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x27);
}

void html_H3(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x28);
}

void html_H4(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x29);
}

void html_H5(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x2A);
}

void html_H6(void *a0, void *a1, void *a2) {
    html_Heading_inner(a0, a1, a2, 0x2B);
}

BOX *html_P(void *node, BOX *parent, BOX *prev) {
    int w;
    int h;
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x46;
    initBoxProperty(box);
    GUI_Graphics_getStringSize(box->style->unk64, D_0013F040, 1, &w, &h);
    box->style->unk20 = h;
    box->style->unk24 = h;
    attr_ALIGN_text_block(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_PRE(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x48;
    initBoxProperty(box);
    box->style->unk74 = 1;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}
