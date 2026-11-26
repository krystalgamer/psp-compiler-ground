/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nflayout.h"
#include "m2c_macros.h"
void *HST_getHeadHistoryNode();                     /* extern */



#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *getBoxByContent(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;

    var_a0 = arg0;
    if ((var_a0 != NULL) && (M2C_FIELD(var_a0, short *, 0x38) != arg1)) {
loop_2:
        var_a0 = *var_a0;
        if (var_a0 != NULL) {
            if (M2C_FIELD(var_a0, short *, 0x38) != arg1) {
                goto loop_2;
            }
        }
    }
    return var_a0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getRootBox(void) {
    int var_v1;
    void *temp_v0;

    temp_v0 = HST_getHeadHistoryNode();
    var_v1 = 0;
    if (temp_v0 != NULL) {
        var_v1 = M2C_FIELD(temp_v0, int *, 0x6C);
    }
    return var_v1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void getBodyBox(int *arg0) {
    getBoxByContent(arg0, 1);
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
void getFramesetBox(int *arg0) {
    getBoxByContent(arg0, 2);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void getTableBox(int *arg0) {
    getBoxByContent(arg0, 4);
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
void getTdBox(int **arg0) {
    getBoxByContent(*arg0, 6);
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
M2C_UNK *getBoxByHTML(M2C_UNK *arg0, int arg1) {
    M2C_UNK *var_a0;

    var_a0 = arg0;
    if ((var_a0 != NULL) && (M2C_FIELD(var_a0, short *, 0x3A) != arg1)) {
loop_2:
        var_a0 = *var_a0;
        if (var_a0 != NULL) {
            if (M2C_FIELD(var_a0, short *, 0x3A) != arg1) {
                goto loop_2;
            }
        }
    }
    return var_a0;
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
int getContainingBlockWidth(void *arg0) {
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x24);
    return (((((M2C_FIELD(arg0, int *, 0x18) - M2C_FIELD(temp_a1, short *, 0x26)) - M2C_FIELD(temp_a1, short *, 0x36)) - M2C_FIELD(temp_a1, short *, 0x2E)) - M2C_FIELD(temp_a1, short *, 0x2A)) - M2C_FIELD(temp_a1, short *, 0x32)) - M2C_FIELD(temp_a1, short *, 0x22);
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
