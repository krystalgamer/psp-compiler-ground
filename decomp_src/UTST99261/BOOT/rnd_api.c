/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct BLIST {
    struct BLIST *next;
    int unk4;
    void *data;
} BLIST;

typedef struct {
    u8 unk0[0x1C];
    s8 unk1C;
    int unk20;
    u8 unk24[0x24];
    BLIST *frames;              /* 0x48 */
} BSUB;

typedef struct {
    u8 unk0[0x60];
    int unk60;                  /* 0x60 */
    u8 unk64[0x9];
    s8 unk6D;
    s8 unk6E;
    u8 unk6F[4];
    s8 unk73;                   /* 0x73 */
} BSTYLE;

typedef struct BNODE {
    struct BNODE *next;
    u8 unk4[0xC];
    int x;                      /* 0x10 */
    int y;
    int w;
    int h;
    BSUB *sub;                  /* 0x20 */
    BSTYLE *style;              /* 0x24 */
    int unk28;
    int widget;                 /* 0x2C */
    u8 unk30[0x8];
    s16 type;                   /* 0x38 */
    s16 unk3A;
    s16 unk3C;                  /* 0x3C */
} BNODE;

typedef struct SELLIST {
    int unk0;
    BNODE *node;
    struct SELLIST *next;
} SELLIST;

extern SELLIST *sellist;
int rnd_gdrawCreateBorder();
void rnd_drawTextBoxnode(void *ctx, BNODE *n, int ox, int oy);
void rnd_drawImageBoxnode(void *ctx, BNODE *n, int ox, int oy);
void rnd_drawBasicBoxnode(void *ctx, BNODE *n, int ox, int oy);
void rnd_drawBoxnodeBackground(void *ctx, BNODE *n, int ox, int oy);
void rnd_drawBoxnodeBorder(void *ctx, BNODE *n, int ox, int oy);
void rnd_gdrawMaskFillrectangle(void *ctx, int c, int x, int y, int w, int h);
int drawObject(BNODE *node);
void drawEachFrame(BNODE *node);
int GUI_ScrollPane_remove();
void rnd_gdrawGetViewClientSize();
int GUI_Component_requestFocus(int w, int self);
int GUI_Component_getLocation(int w, int *x, int *y);
int GUI_Component_setLocation(int w, int x, int y);
void MEM_free(void *pool, void *p);
int rnd_relayoutWidgets(int, int);                  /* extern */
extern void *ui_global;
M2C_UNK GUI_Component_update(int, int, int, int, int); /* extern */
M2C_UNK GUI_Component_remove(int);                  /* extern */
M2C_UNK rnd_deleteAnimBoxnode();                    /* extern */
M2C_UNK GUI_ScrollPane_getScrollPosition();
M2C_UNK GUI_ScrollPane_getContentSize();
int GUI_ScrollPane_setScrollPosition();
M2C_UNK GUI_Component_getParent();                  /* extern */

M2C_UNK rnd_gdrawImageDecode();                     /* extern */
M2C_UNK rnd_gdrawImageDecodeByGifFile();            /* extern */
M2C_UNK rnd_gdrawImageProperty();                   /* extern */
void rnd_gdrawImageDelete();                     /* extern */
void rnd_updateAnimBoxnode();                    /* extern */


void GUI_Toolkit_mutexLock(void);
void GUI_Toolkit_mutexUnlock(void);
M2C_UNK *rnd_findParentBoxnode(M2C_UNK *arg0, int arg1);
void *MEM_malloc(void *, unsigned int size);
int strcmp(const char *, const char *);
void drawEachFrame(BNODE *node) {
    BLIST *l;

    if (node->type == 1) {
        for (l = node->sub->frames; l != NULL; l = l->next) {
            drawObject(l->data);
            drawEachFrame(l->data);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int drawPaint(int arg0) {
    int temp_v0;

    if (arg0 != 0) {
        GUI_Toolkit_mutexLock();
        temp_v0 = rnd_relayoutWidgets(M2C_FIELD(ui_global, int *, 0x90), arg0);
        if (temp_v0 < 0) {
            GUI_Toolkit_mutexUnlock();
            return temp_v0;
        }
        GUI_Toolkit_mutexUnlock();
        drawEachFrame(arg0);
        drawObject(arg0);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}

int drawObject(BNODE *node) {
    BNODE *p;

    p = rnd_findParentBoxnode(node, 1);
    if (p == NULL) {
        return -100;
    }
    if (node == p) {
        GUI_Component_update(node->widget, 0, 0, 0, 0);
    } else {
        GUI_Component_update(p->widget, node->x, node->y, node->w, node->h);
    }
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int drawObjectWithArea(int *arg0, int arg1, int arg2, int arg3, int arg4) {
    int *temp_v0;
    int var_v0;
    void *temp_v1;

    temp_v0 = rnd_findParentBoxnode(arg0, 1);
    var_v0 = -0x64;
    if (temp_v0 != NULL) {
        temp_v1 = M2C_FIELD(arg0, void **, 0x24);
        GUI_Component_update(M2C_FIELD(temp_v0, int *, 0x2C), M2C_FIELD(temp_v1, short *, 0x26) + M2C_FIELD(arg0, int *, 0x10) + M2C_FIELD(temp_v1, short *, 0x36) + M2C_FIELD(temp_v1, short *, 0x2E) + arg1, M2C_FIELD(temp_v1, short *, 0x20) + M2C_FIELD(arg0, int *, 0x14) + M2C_FIELD(temp_v1, short *, 0x30) + M2C_FIELD(temp_v1, short *, 0x28) + arg2, arg3, arg4);
        var_v0 = 0;
    }
    return var_v0;
}

int drawScroll(BNODE *node, int x, int y) {
    int sx;
    int sy;
    int cw;
    int ch;
    int vw;
    int vh;

    if (node == NULL || node->type != 1) {
        return -100;
    }
    GUI_ScrollPane_getScrollPosition(node->widget, &sx, &sy);
    GUI_ScrollPane_getContentSize(node->widget, &cw, &ch);
    rnd_gdrawGetViewClientSize(node->widget, &vw, &vh);
    x += sx;
    if (x < 0) {
        x = 0;
    } else if (cw < x + vw) {
        x = cw - vw;
    }
    y += sy;
    if (y < 0) {
        y = 0;
    } else if (ch < y + vh) {
        y = ch - vh;
    }
    if (x < 0) {
        x = 0;
    }
    if (y < 0) {
        y = 0;
    }
    if (x != sx || y != sy) {
        GUI_ScrollPane_setScrollPosition(node->widget, x, y);
    }
    return 0;
}

void drawRemoveChild(BNODE *parent, BNODE *child) {
    GUI_ScrollPane_remove(parent->widget, child->widget);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void drawDelete(int *arg0) {
    int *temp_v0;
    int temp_a0;

    rnd_deleteAnimBoxnode();
    temp_v0 = rnd_findParentBoxnode(arg0, 1);
    if (temp_v0 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0, int *, 0x2C);
        if (temp_a0 != 0) {
            GUI_Component_remove(temp_a0);
        }
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getViewPort(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0x38) != 1)) {
        return -0x64;
    }
    GUI_ScrollPane_getScrollPosition(M2C_FIELD(arg0, int *, 0x2C));
    return 0;
}

int getViewClientSize(BNODE *node, int *w, int *h) {
    if (node == NULL || node->type != 1) {
        return -100;
    }
    rnd_gdrawGetViewClientSize(node->widget, w, h);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int getViewVirtualSize(void *arg0) {
    if ((arg0 == NULL) || (M2C_FIELD(arg0, short *, 0x38) != 1)) {
        return -0x64;
    }
    GUI_ScrollPane_getContentSize(M2C_FIELD(arg0, int *, 0x2C));
    return 0;
}

void setFocus(BNODE *node, BNODE *t, int on) {
    BSTYLE *style;
    int w;

    style = t->style;
    if (style->unk6E != 1) {
        style->unk6D = on;
    }
    w = t->widget;
    if (w == 0 || t->type == 19) {
        if (on == 0) {
            return;
        }
        w = node->widget;
    }
    GUI_Component_requestFocus(w, on);
}

void setFocusImageMap(BNODE *node, BNODE *t, int id, int area, int on) {
    BSUB *sub;

    if (on == 1) {
        t->sub->unk1C = id;
        t->sub->unk20 = area;
    } else {
        sub = t->sub;
        if (sub->unk1C == id) {
            sub->unk1C = 0;
        }
    }
    if (on != 0) {
        GUI_Component_requestFocus(node->widget, 1);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDecode(void) {
    rnd_gdrawImageDecode();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDecodeByGifFile(void) {
    rnd_gdrawImageDecodeByGifFile();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageProperty(void) {
    rnd_gdrawImageProperty();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void imageDelete(void) {
    rnd_gdrawImageDelete();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void drawAnimation(void) {
    rnd_updateAnimBoxnode();
}

int startBorder(BNODE *n) {
    BNODE *p;

    if (n == NULL || n->type != 3) {
        return 0;
    }
    p = (BNODE *)rnd_findParentBoxnode((void *)n, 1);
    if (p == NULL) {
        return 0;
    }
    return rnd_gdrawCreateBorder(p->widget, n->x, n->y, n->w, n->h, 0x80B4FF, 0x202020, 1);
}

int moveBorder(int w, int dx, int dy) {
    int x;
    int y;

    if (w == 0) {
        return -100;
    }
    GUI_Component_getLocation(w, &x, &y);
    GUI_Component_setLocation(w, dx + x, dy + y);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int deleteBorder(int arg0) {
    int var_v0;

    var_v0 = -0x64;
    if (arg0 != 0) {
        GUI_Component_getParent();
        GUI_Component_remove(arg0);
        var_v0 = 0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void addSelectList(int *arg0) {
    int temp_v0;
    int var_s1;
    void *temp_v0_2;

    if (sellist == 0) {
        temp_v0 = MEM_malloc(0, 0xC);
        sellist = temp_v0;
        M2C_FIELD(temp_v0, int *, 0) = 0;
        M2C_FIELD(temp_v0, int *, 4) = 0;
        M2C_FIELD(temp_v0, int *, 8) = 0;
    }
    var_s1 = sellist;
    if (M2C_FIELD(var_s1, int *, 8) != 0) {
        do {
            var_s1 = M2C_FIELD(var_s1, int *, 8);
        } while (M2C_FIELD(var_s1, int *, 8) != 0);
    }
    temp_v0_2 = MEM_malloc(0, 0xC);
    M2C_FIELD(temp_v0_2, int **, 4) = arg0;
    M2C_FIELD(temp_v0_2, int *, 0) = (int) M2C_FIELD(M2C_FIELD(getBodyBox(arg0), void **, 0x20), int *, 0x38);
    M2C_FIELD(temp_v0_2, int *, 8) = 0;
    M2C_FIELD(var_s1, void **, 8) = temp_v0_2;
}

void destroySelectList(void) {
    SELLIST *n;
    SELLIST *next;

    for (n = sellist; n != NULL; n = next) {
        next = n->next;
        MEM_free(NULL, n);
    }
    sellist = NULL;
}

void delSelectListBySID(int sid) {
    SELLIST *prev;
    SELLIST *p;

    if (sellist == NULL) {
        return;
    }
    prev = sellist;
    p = sellist->next;
    while (p != NULL) {
        if (sid == 0 || (int)p->unk0 == sid) {
            prev->next = p->next;
            MEM_free(NULL, p);
            p = prev->next;
        } else {
            prev = p;
            p = p->next;
        }
    }
}

BNODE *getSelectListFromGadget(int gadget) {
    SELLIST *n;

    if (sellist == NULL || gadget == 0) {
        return NULL;
    }
    for (n = sellist->next; n != NULL; n = n->next) {
        if (n->node->widget == gadget) {
            return n->node;
        }
    }
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawAllBoxnode);

void rnd_drawBoxnode(void *ctx, BNODE *n, int ox, int oy) {
    if (n->type == 0 && n->unk3C == 1) {
        return;
    }
    if (n->style->unk73 == 1) {
        return;
    }
    switch (n->type) {
    case 9:
        rnd_drawTextBoxnode(ctx, n, ox, oy);
        break;
    case 10:
        rnd_drawImageBoxnode(ctx, n, ox, oy);
        break;
    default:
        rnd_drawBasicBoxnode(ctx, n, ox, oy);
        break;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK *rnd_findParentBoxnode(M2C_UNK *arg0, int arg1) {
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

typedef struct RITEM {
    struct RITEM *prev;
    struct RITEM *next;
    BNODE *node;
} RITEM;

typedef struct RGROUP {
    int unk0;
    struct RGROUP *next;
    RITEM *items;
    char *name;
} RGROUP;

BNODE *rnd_prevRadioBoxnode(BNODE *node) {
    char *name;
    RGROUP *g;
    RITEM *p;

    name = *(char **)node->sub;
    if (name == NULL) {
        return NULL;
    }
    g = *(RGROUP **)((u8 *)((BNODE *)getBodyBox())->sub + 0x80);
    for (; g != NULL; g = g->next) {
        if (strcmp(g->name, name) == 0) {
            p = g->items;
            while (p != NULL && p->node != node) {
                p = p->next;
            }
            if (p != NULL && p->prev != NULL) {
                return p->prev->node;
            }
            if (p != NULL && p->prev == NULL) {
                return NULL;
            }
        }
    }
    return NULL;
}

void rnd_drawBasicBoxnode(void *ctx, BNODE *n, int ox, int oy) {
    int c;

    rnd_drawBoxnodeBackground(ctx, n, ox, oy);
    rnd_drawBoxnodeBorder(ctx, n, ox, oy);
    c = n->style->unk60;
    if (n->style->unk6D != 0 && n->type == 0x11) {
        rnd_gdrawMaskFillrectangle(ctx, c, ox + n->x, oy + n->y, n->w, n->h);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_api", rnd_drawBoxnodeBackground);
