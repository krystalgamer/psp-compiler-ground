/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "m2c_macros.h"
void *getSessionSaveData(int id);
void getViewPort(BOX *box, int *x, int *y);
void drawDelete(BOX *box);


int checkTableHierarchy(BOX *box, BOX **table) {
    while (box != NULL) {
        if (box->content == 6) {
            return 1;
        }
        if (box->content == 4) {
            *table = box->parent;
            return 0;
        }
        box = box->parent;
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createBlockBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createInlineBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", createListBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", linkBox);

#ifndef NULL
#define NULL ((void *)0)
#endif
void linkBoxNoTableCheck(void *arg0, void *arg1, void *arg2) {
    if ((arg1 != NULL) && (M2C_FIELD(arg1, void **, 4) == NULL)) {
        M2C_FIELD(arg1, void **, 4) = arg0;
    }
    M2C_FIELD(arg0, void **, 0) = arg1;
    M2C_FIELD(arg0, void **, 8) = arg2;
    if (arg2 != NULL) {
        M2C_FIELD(arg2, void **, 0xC) = arg0;
    }
}

void insLinkBox(BOX *box, BOX *parent, BOX *prev) {
    BOX *next;
    if (parent == NULL) {
        return;
    }
    if (parent->child == NULL) {
        parent->child = box;
        box->parent = parent;
    } else if (prev == NULL) {
        box->next = parent->child;
        parent->child = box;
        box->parent = parent;
    } else {
        next = prev->next;
        prev->next = box;
        if (next == NULL) {
            box->prev = prev;
            box->parent = parent;
        } else {
            next->prev = box;
            box->prev = prev;
            box->next = next;
            box->parent = parent;
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void delLinkBox(void *arg0) {
    void **temp_a3;
    void *temp_a1;
    void *temp_a2;
    void *temp_v1;

    temp_a2 = M2C_FIELD(arg0, void **, 0);
    temp_a1 = M2C_FIELD(arg0, void **, 0xC);
    temp_v1 = M2C_FIELD(arg0, void **, 8);
    temp_a3 = M2C_FIELD(arg0, void ***, 4);
    if ((temp_a2 != NULL) && (M2C_FIELD(temp_a2, void **, 4) == arg0)) {
        M2C_FIELD(temp_a2, void **, 4) = temp_a1;
    }
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, void **, 0xC) = temp_a1;
    }
    if (temp_a1 != NULL) {
        M2C_FIELD(temp_a1, void **, 8) = temp_v1;
    }
    if (temp_a3 != NULL) {
        *temp_a3 = temp_a2;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int getChildBox(void *arg0) {
    return M2C_FIELD(arg0, int *, 4);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int getBrotherBox(void *arg0) {
    return M2C_FIELD(arg0, int *, 0xC);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeBoxPre);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", reinitBodyBox);

void freeDrawObject(BOX *box) {
    int *sd;
    if (box->content == 1) {
        sd = getSessionSaveData(*(int *)((char *)box->geom + 0x38));
        if (sd != NULL) {
            getViewPort(box, sd + 1, sd + 2);
        }
        drawDelete(box);
        *(int *)((char *)box + 0x2C) = 0;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeBoxTree);
