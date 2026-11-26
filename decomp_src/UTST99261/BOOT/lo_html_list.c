/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
typedef struct UICOLORS { int color[4][7]; int unk70; int unk74; } UICOLORS;
#define TEXTCOLOR(b) ((b)->style->unk64 = ((UICOLORS *)ui_global)->color[(b)->style->unk6A][(b)->style->fontSize])
BOX *createInlineBox(void *ctx, BOX *parent, BOX *prev);
BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev);
M2C_UNK applyCSSExtStyleSheetToBox(int, void *);    /* extern */
M2C_UNK applyCSSInlinePropertyToBox(int, void *);   /* extern */
M2C_UNK initBoxProperty(void *);                    /* extern */
extern void *ui_global;



INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", getLINumber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", createLIBox_li);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", createLIBox_head);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", getTypeAtAttr);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_DL);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_OL);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_list", html_UL);

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
