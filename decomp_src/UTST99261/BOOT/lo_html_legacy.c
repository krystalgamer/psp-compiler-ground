/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
BOX *createInlineBox(void *ctx, BOX *parent, BOX *prev);
BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev);
BOX *createBox(void *ctx, int type);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void font_attr(void *node, BOX *box);
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", font_attr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", html_BASEFONT);

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_CENTER(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBlockBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x13;
    initBoxProperty(box);
    box->style->unk6F = 2;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_FONT(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x22;
    font_attr(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int html_ISINDEX(void) {
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_S(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x50;
    box->style->unk6C[0] |= 4;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_STRIKE(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x50;
    box->style->unk6C[0] |= 4;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *html_U(void *node, BOX *parent, BOX *prev) {
    BOX *box = createInlineBox(node, parent, prev);
    if (box == NULL) {
        return NULL;
    }
    box->html = 0x5F;
    box->style->unk6C[0] |= 2;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_BLINK(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    initNoneContent(box, node);
    box->display = 1;
    box->html = 0xD;
    initBoxProperty(box);
    box->style->unk6C[0] |= 8;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_legacy", html_MARQUEE);

BOX *html_NOBR(void *node, BOX *parent, BOX *prev) {
    BOX *box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    box->html = 0x3F;
    initNoneContent(box, node);
    initBoxProperty(box);
    box->style->unk74 = 2;
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}
