/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nflayout.h"



#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getBoxByContent(BOX *box, int content) {
    while (box != NULL && box->content != content) {
        box = box->parent;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

BOX *getRootBox(void) {
    HISTNODE *h;
    BOX *box;

    h = HST_getHeadHistoryNode();
    box = NULL;
    if (h != NULL) {
        box = h->body;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getBodyBox(BOX *box) {
    return getBoxByContent(box, 1);
}

BOX *getListBox(BOX *box) {
    while (box != NULL && box->content != 8) {
        if (box->content == 17) {
            return NULL;
        }
        box = box->parent;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getFramesetBox(BOX *box) {
    return getBoxByContent(box, 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getTableBox(BOX *box) {
    return getBoxByContent(box, 4);
}

BOX *getTrBox(BOX *box) {
    while (box != NULL && box->content != 5) {
        if (box->content == 4) {
            box = NULL;
            break;
        }
        box = box->parent;
    }
    return box;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getTdBox(BOX *box) {
    return getBoxByContent(box->parent, 6);
}

BOX *getParentBlockBox(BOX *box) {
    BOX *b;

    b = box->parent;
    while (b != NULL && b->display != 0 && b->display != 3) {
        b = b->parent;
    }
    return b;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
BOX *getBoxByHTML(BOX *box, int html) {
    while (box != NULL && box->html != html) {
        box = box->parent;
    }
    return box;
}

BOX *getBoxByHTML_intd(BOX *box, BOX *stop, int html) {
    while (box != NULL && box->html != html) {
        if (box == stop) {
            box = NULL;
            break;
        }
        box = box->parent;
    }
    return box;
}

void getBodyAbsolutePos(BOX *box, int *px, int *py) {
    int x;
    int y;
    BOX *b;

    x = box->geom->x;
    y = box->geom->y;
    for (b = box->parent; b != NULL; b = b->parent) {
        if (b->content == 1) {
            x += b->geom->x;
            y += b->geom->y;
        }
    }
    *px = x;
    *py = y;
}

int checkBoxValidity(BOX *box) {
    for (; box != NULL; box = box->parent) {
        if (box->content == 1 && box->geom->unk40 == 4) {
            return 0;
        }
    }
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int getContainingBlockWidth(BOX *box) {
    BOXSTYLE *s;

    s = box->style;
    return box->width - s->unk26 - s->unk36 - s->unk2E - s->unk2A - s->unk32 - s->unk22;
}

void *getPageRegion(BOX *box) {
    for (; box != NULL; box = box->parent) {
        if (box->region != NULL) {
            return box->region;
        }
    }
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", calcBoxMinWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", calcBoxMaxWidth);

BOX *getFixedHeightBox(BOX *box) {
    BOX *b;

    for (b = box->parent; b != NULL; b = b->parent) {
        if (b->content == 4 || b->display == 3) {
            return NULL;
        }
        if (((b->style->flags & 0xC) >> 2) == 1 || b->content == 1) {
            return b;
        }
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_width);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_high", e_icon_image_height);
