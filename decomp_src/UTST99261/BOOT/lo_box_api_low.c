/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "m2c_macros.h"
void initListContent(BOX *box, void *ctx);
BOX *createBox(void *ctx, int type);
void initNoneContent(BOX *box, void *ctx);
void initBoxProperty(BOX *box);
BOX *getParentBlockBox(BOX *box);
int getContainingBlockWidth(BOX *box);
void *getSessionSaveData(int id);
int getViewPort(BOX *box, int *x, int *y);
void drawDelete(BOX *box);


void *memset(void *, int, unsigned int);
void Node_setBox(void *node, BOX *box);
void initMapList(BOX *b);
void initBoxProperty(BOX *b);
void actClearForm(void *f);
void initImageList(void *l);
void lfm_resetPageRegion(void *r, int w);
void freeDrawObject(BOX *b);
int getCurrentFocusIndex(BOX *box);
void removeAllFocusList(BOX *box);
void freeMapList(BOX *box);
void freeRadioList(BOX *box);
void freeFormList(BOX *box);
void actSaveForm(BOX *body, BOX *box);
HISTNODE *HST_getChildHistoryNode(HISTNODE *n);
HISTNODE *HST_getSiblingHistoryNode(HISTNODE *n);
int HST_getRequestFlag(HISTNODE *n);
int HST_deleteHistoryNode(HISTNODE *n);
void linkBox(BOX *box, BOX *parent, BOX *prev);
void insLinkBox(BOX *box, BOX *parent, BOX *prev);
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

BOX *createBox(void *ctx, int type) {
    unsigned int size = type != 0 ? 0xBC : 0x44;
    BOX *box = MEM_malloc(0, size);

    if (box == NULL)
        return NULL;
    memset(box, 0, size);
    M2C_FIELD(box, void **, 0x28) = ctx;
    if (type != 0)
        box->style = (BOXSTYLE *)((char *)box + 0x44);
    if (ctx != NULL)
        Node_setBox(ctx, box);
    return box;
}

BOX *createBlockBox(void *ctx, BOX *parent, BOX *prev) {
    BOX *box = createBox(ctx, 1);
    BOX *cb;
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 0;
    initNoneContent(box, ctx);
    cb = getParentBlockBox(box);
    if (cb != NULL) {
        box->width = getContainingBlockWidth(cb);
    }
    return box;
}

BOX *createInlineBox(void *ctx, BOX *parent, BOX *prev) {
    BOX *box = createBox(ctx, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 1;
    initNoneContent(box, ctx);
    box->content = 0;
    initBoxProperty(box);
    return box;
}

BOX *createListBox(void *ctx, BOX *parent, BOX *prev, int html) {
    BOX *box = createBox(ctx, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBox(box, parent, prev);
    box->display = 0;
    box->html = html;
    initListContent(box, ctx);
    initBoxProperty(box);
    box->width = getContainingBlockWidth(getParentBlockBox(box));
    return box;
}

void linkBox(BOX *box, BOX *parent, BOX *prev) {
    BOX *t;
    if (checkTableHierarchy(parent, &t) == 0) {
        insLinkBox(box, t->parent, t->prev);
        return;
    }
    if (parent != NULL && parent->child == NULL) {
        parent->child = box;
    }
    box->parent = parent;
    box->prev = prev;
    if (prev != NULL) {
        prev->next = box;
    }
}

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

void freeBoxPre(BOX *box) {
    int *sd;
    int i;
    int *g;
    HISTNODE *n;
    HISTNODE *next;

    switch (box->content) {
    case 1:
        sd = getSessionSaveData(M2C_FIELD(box->geom, int *, 0x38));
        if (sd != NULL) {
            if (M2C_FIELD(box, void **, 0x2C) != NULL)
                getViewPort(box, sd + 1, sd + 2);
            i = getCurrentFocusIndex(box);
            if (i >= 0)
                sd[3] = i;
        }
        actClearForm(M2C_FIELD(box->geom, void **, 0x38));
        removeAllFocusList(box);
        freeMapList(box);
        freeRadioList(box);
        freeFormList(box);
        g = gESPRIT_LO_GLOBAL_NDA;
        if (g[0] == 0 || g[0] == M2C_FIELD(box->geom, int *, 0x38)) {
            g[0] = 0;
            g[4] = 0;
            g[5] = 0;
            g[6] = 0;
            g[7] = 0;
            g[8] = 0;
            g[9] = 0;
            g[10] = 0;
        }
        n = HST_searchSessionIDHistoryNode(M2C_FIELD(box->geom, int *, 0x38));
        if (n != NULL) {
            for (n = HST_getChildHistoryNode(n); n != NULL; n = next) {
                next = HST_getSiblingHistoryNode(n);
                if (HST_getRequestFlag(n) == -1)
                    HST_deleteHistoryNode(n);
            }
        }
        if (M2C_FIELD(box->geom, void **, 0x30) != NULL) {
            MEM_free(0, M2C_FIELD(box->geom, void **, 0x30));
            M2C_FIELD(box->geom, void **, 0x30) = NULL;
        }
        break;
    case 13:
    case 14:
    case 15:
    case 18:
        actSaveForm(getBodyBox(box), box);
        break;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_api_low", freeBox);

void reinitBodyBox(BOX *box, int clear) {
    char *g = (char *)box->geom;

    box->child = NULL;
    box->width = 0;
    box->height = 0;
    M2C_FIELD(g, int *, 0x10) = M2C_FIELD(g, int *, 0x8);
    M2C_FIELD(g, int *, 0x14) = M2C_FIELD(g, int *, 0xC);
    M2C_FIELD(g, int *, 0x18) = 0;
    M2C_FIELD(g, int *, 0x1C) = 0;
    M2C_FIELD(g, int *, 0x68) = 0;
    M2C_FIELD(g, int *, 0x6C) = 0;
    M2C_FIELD(g, int *, 0x70) = 0;
    M2C_FIELD(g, int *, 0x74) = 0;
    M2C_FIELD(g, int *, 0x78) = 0;
    M2C_FIELD(g, int *, 0x80) = 0;
    M2C_FIELD(g, int *, 0x84) = 0;
    M2C_FIELD(g, int *, 0xB4) = 0;
    if (M2C_FIELD(g, void **, 0x28) != NULL) {
        MEM_free(0, M2C_FIELD(g, void **, 0x28));
        M2C_FIELD(g, void **, 0x28) = NULL;
    }
    initMapList(box);
    initBoxProperty(box);
    box->style->unk28 = 0;
    box->style->unk2A = 0;
    box->style->unk2C = 0;
    box->style->unk2E = 0;
    if (clear)
        actClearForm(M2C_FIELD(box->geom, void **, 0x38));
    initBoxList((LIST *)(g + 0x48));
    initBoxList((LIST *)(g + 0x9C));
    initImageList(g + 0x54);
    if (box->region != NULL)
        lfm_resetPageRegion(box->region, M2C_FIELD(g, int *, 0x8));
    if (M2C_FIELD(box, void **, 0x2C) != NULL) {
        freeDrawObject(box);
        M2C_FIELD(box, void **, 0x2C) = NULL;
    }
}

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
