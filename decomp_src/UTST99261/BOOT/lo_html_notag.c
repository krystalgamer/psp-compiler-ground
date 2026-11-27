/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "nflayout.h"

BOX *createBox(void *node, int type);
void linkBox(BOX *b, BOX *parent, BOX *prev);
void initTextContent(BOX *b, void *node, int f);
void initBoxProperty(BOX *b);
void initTextBoxSize(BOX *b);
BOX *normal_text(void *node, BOX *parent, BOX *prev) {
    BOX *src;
    BOX *b;

    src = parent;
    if (parent->display != 1) {
        for (src = prev; src != NULL; src = src->prev) {
            if (src->content == 9 && src->html != 0x66)
                break;
        }
    }
    b = createBox(node, src == NULL);
    if (b == NULL)
        return NULL;
    linkBox(b, parent, prev);
    b->display = 1;
    b->html = 0x65;
    initTextContent(b, node, 0);
    if (src != NULL) {
        b->style = src->style;
    } else {
        initBoxProperty(b);
        b->style->unk30 = 0;
        M2C_FIELD(b->style, s16 *, 0x32) = 0;
        b->style->unk34 = 0;
        M2C_FIELD(b->style, s16 *, 0x36) = 0;
    }
    M2C_FIELD(b->geom, u8 *, 0x10) = M2C_FIELD(b->style, u8 *, 0x68);
    initTextBoxSize(b);
    return b;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", normalizeText);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", pre_text);

BOX *getSpecialBehaviorParent(BOX *box) {
    s16 h;
    while (box != NULL) {
        h = box->html;
        if (h == 0x45 || h == 0x4D || h == 0x58) {
            return box;
        }
        box = box->parent;
    }
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_notag", html_NOTAG);
