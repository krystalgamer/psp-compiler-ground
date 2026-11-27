/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "m2c_macros.h"
typedef struct LINEENT { struct LINEENT *next; int x4; BOX *box; } LINEENT;
typedef struct LINE { LINEENT *first; LINEENT *last; } LINE;
void moveBoxPositionChild(BOX *box, int dx, int dy);


#ifndef NULL
#define NULL ((void *)0)
#endif
int getLineHeight(LINE *line);
void lfm_addFloat(void *fm, void *blk, int h, int w, int bh, int side, int *dx, int *dy);
void calcInlineBoxPosition(void *ctx, BOX *box);
void calcTableBoxPosition(void *ctx, BOX *box);
void calcTrBoxPosition(void *ctx, BOX *box);
void calcTdBoxPosition(void *ctx, BOX *box);
void calcBlockButtonBoxPosition(void *ctx, BOX *box);
void calcBlockBoxPosition(void *ctx, BOX *box);
void calcFloatBoxPosition(void *ctx, BOX *box);
void *lfm_createPageRegion(BOX *box, int w);
BOX *getBoxByHTML(BOX *box, int html);
typedef struct { u8 pad[0x10]; int width; } TDCOL;
typedef struct { LIST l; int f; } URLL;
extern URLL D_00584CF0;
void lfm_resetPageRegion(void *r, int w);
extern char D_00139244[];
int getPrevLineHeight(void *arg0) {
    return M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x34);
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", D_00139244);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", lineProcByBR);

void getPositionParameter(void *ctx, void *unused, int *x, int *y, int *left, int *right) {
    int h;
    getBaseBlockPosition(ctx, x, y);
    h = getPrevLineHeight(ctx);
    *right = 0;
    *left = 0;
    lfm_getHorizontalArea(M2C_FIELD(ctx, void **, 0x10), M2C_FIELD(ctx, void **, 4), h, left, right);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", delSpaceText);

#ifndef NULL
#define NULL ((void *)0)
#endif
void adjustInlineBoxDimension(void *arg0) {
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int var_a2;
    int var_a3;
    int var_a4;
    int var_a5;
    void *temp_a6;
    void *var_a0;
    void *var_a1;

    var_a0 = arg0;
    temp_a6 = var_a0;
    if (var_a0 != NULL) {
        do {
            if ((M2C_FIELD(var_a0, short *, 0x3C) == 1) && (M2C_FIELD(var_a0, short *, 0x38) == 0)) {
                var_a5 = -1;
                var_a2 = -1;
                var_a4 = -1;
                var_a1 = M2C_FIELD(temp_a6, void **, 4);
                var_a3 = -1;
                if (var_a1 != NULL) {
                    do {
                        if (var_a2 == -1) {
                            var_a2 = M2C_FIELD(var_a1, int *, 0x10);
                            var_a5 = var_a2 + M2C_FIELD(var_a1, int *, 0x18);
                            var_a3 = M2C_FIELD(var_a1, int *, 0x14);
                            var_a4 = var_a3 + M2C_FIELD(var_a1, int *, 0x1C);
                        }
                        temp_v0 = M2C_FIELD(var_a1, int *, 0x10);
                        var_a2 = __builtin_allegrex_min(var_a2, temp_v0);
                        var_a5 = __builtin_allegrex_max(var_a5, temp_v0 + M2C_FIELD(var_a1, int *, 0x18));
                        temp_v0_2 = M2C_FIELD(var_a1, int *, 0x14);
                        var_a3 = __builtin_allegrex_min(var_a3, temp_v0_2);
                        temp_v0_3 = temp_v0_2 + M2C_FIELD(var_a1, int *, 0x1C);
                        var_a1 = M2C_FIELD(var_a1, void **, 0xC);
                        var_a4 = __builtin_allegrex_max(var_a4, temp_v0_3);
                    } while (var_a1 != NULL);
                }
                if (var_a3 != -1) {
                    M2C_FIELD(temp_a6, int *, 0x10) = var_a2;
                    M2C_FIELD(temp_a6, int *, 0x14) = var_a3;
                    M2C_FIELD(temp_a6, int *, 0x18) = (int) (var_a5 - var_a2);
                    M2C_FIELD(temp_a6, int *, 0x1C) = (int) (var_a4 - var_a3);
                }
            }
            var_a0 = M2C_FIELD(var_a0, void **, 0);
        } while (var_a0 != NULL);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void adjustInlineBoxDimensionLoop(int *arg0, int arg1) {
    int var_s0;

    var_s0 = *arg0;
    if ((var_s0 != 0) & (var_s0 != arg1)) {
        do {
            if ((M2C_FIELD(var_s0, short *, 0x3C) == 1) && (M2C_FIELD(var_s0, short *, 0x38) == 0)) {
                adjustInlineBoxDimension((void *) var_s0);
            }
            var_s0 = M2C_FIELD(var_s0, int *, 0);
        } while ((var_s0 != 0) & (var_s0 != arg1));
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", wordWrapProc);

void calcBlockButtonBoxPosition(void *ctx, BOX *box) {
    int x, y, left, right;
    int h;
    int lw;
    int cw;
    int pad;
    BOX *p;

    getBaseBlockPosition(ctx, &x, &y);
    h = getPrevLineHeight(ctx);
    lfm_getHorizontalArea(M2C_FIELD(ctx, void **, 0x10), M2C_FIELD(ctx, void **, 4), h, &left, &right);
    lw = getLineWidth(M2C_FIELD(ctx, void **, 0xC));
    if (box->style->unk72 < 2) {
        box->x = lw != 0 ? lw + x : x + left;
        box->y = h + y;
        cw = getContainingBlockWidth(M2C_FIELD(ctx, void **, 4));
    } else {
        p = box->parent;
        while (p->content != 1) {
            if (p->display == 0 && M2C_FIELD(p->style, s8 *, 0x72) != 0)
                break;
            p = p->parent;
        }
        x = p->style->unk26 + p->x + p->style->unk36;
        y = p->style->unk20 + p->y + p->style->unk30;
        box->x = box->style->unk52 + x;
        box->y = box->style->unk50 + y;
        cw = p->width - p->style->unk26 - p->style->unk36 - p->style->unk32 - p->style->unk22;
    }
    pad = box->style->unk26 + box->style->unk36 + box->style->unk2E + box->style->unk2A + box->style->unk32 + box->style->unk22;
    if (box->style->unk72 < 2) {
        switch (box->style->flags & 3) {
        case 1:
            box->width = box->style->unk26 + box->style->width + box->style->unk22;
            break;
        case 2:
            box->width = (right - box->style->unk26 - box->style->unk22) * box->style->width / 100 + box->style->unk26 + box->style->unk22;
            break;
        default:
            box->width = calcBoxMaxWidth(ctx, box);
            break;
        }
        box->height = 0;
    } else if (M2C_FIELD(box->style, s8 *, 0x72) == 2) {
        switch (box->style->flags & 3) {
        case 1:
            box->width = box->style->unk26 + box->style->width + box->style->unk22;
            break;
        case 2:
            box->width = (cw - box->style->unk26 - box->style->unk22) * box->style->width / 100 + box->style->unk26 + box->style->unk22;
            break;
        default:
            box->width = calcBoxMaxWidth(ctx, box) + pad;
            break;
        }
        box->height = 0;
    } else {
        box->height = 0;
    }
    M2C_FIELD(box, int *, 0x34) = 0;
    lfm_resetPageRegion(box->region, box->width);
    addBoxList(M2C_FIELD(ctx, LIST **, 0xC), box);
    turnupContent(ctx, box);
    initLinePosition(box);
}

void calcTableBoxPosition(void *ctx, BOX *box) {
    int x, y, left, right;
    int ox, oy;
    int h;
    int w;
    BOX *p;

    ox = box->x;
    oy = box->y;
    if (M2C_FIELD(M2C_FIELD(ctx, LIST **, 0xC), void **, 0) != NULL) {
        { int lf = lineFeedProc(ctx, box);
        M2C_FIELD(M2C_FIELD(ctx, void **, 4), int *, 0x34) += lf; }
    }
    getBaseBlockPosition(ctx, &x, &y);
    h = getPrevLineHeight(ctx);
    lfm_getHorizontalArea(M2C_FIELD(ctx, void **, 0x10), M2C_FIELD(ctx, void **, 4), h, &left, &right);
    if (box->style->unk72 < 2) {
        box->x = x + left;
        box->y = h + y;
        box->parent->x = x + left;
        box->parent->y = h + y;
        w = getContainingBlockWidth(M2C_FIELD(ctx, void **, 4));
    } else {
        p = box->parent;
        while (p->content != 1) {
            if (p->display == 0 && M2C_FIELD(p->style, s8 *, 0x72) != 0)
                break;
            p = p->parent;
        }
        x = p->style->unk26 + p->x + p->style->unk36;
        y = p->style->unk20 + p->y + p->style->unk30;
        box->x = box->style->unk52 + x;
        box->y = box->style->unk50 + y;
        box->parent->x = box->style->unk52 + x;
        box->parent->y = box->style->unk50 + y;
        right = p->width - p->style->unk26 - p->style->unk36 - p->style->unk32 - p->style->unk22;
        w = right;
    }
    box_setTableWidth(ctx, box, right);
    if (box->style->unk72 < 2 && M2C_FIELD(box->style, s8 *, 0x71) == 0 && right > box->width) {
        if (M2C_FIELD(box->style, s8 *, 0x6F) == 2) {
            box->x += (right - box->width) / 2;
        } else if (M2C_FIELD(box->style, s8 *, 0x6F) == 3) {
            box->x += right - box->width;
        }
    }
    if ((M2C_FIELD(box, u16 *, 0x40) & 2) && w == M2C_FIELD(box->geom, int *, 0xC) && right == M2C_FIELD(box->geom, int *, 0x10)) {
        D_00584CF0.f = 1;
        if (ox != box->x || oy != box->y)
            moveBoxPositionChild(box, box->x - ox, box->y - oy);
    } else {
        M2C_FIELD(box->geom, int *, 0xC) = w;
        M2C_FIELD(box->geom, int *, 0x10) = right;
        M2C_FIELD(box, int *, 0x34) = M2C_FIELD(box->geom, int *, 8);
        initLinePosition(box);
    }
}

void calcTrBoxPosition(void *ctx, BOX *tr) {
    BOX *t = getTableBox(tr);
    BOXGEOM *g;
    BOXSTYLE *st;
    if (t != NULL) {
        g = t->geom;
        st = t->style;
        tr->x = st->unk26 + t->x + st->unk36 + M2C_FIELD(g, int *, 8);
        tr->y = st->unk20 + t->y + st->unk30 + M2C_FIELD(t, int *, 0x34);
        tr->width = t->width - st->unk26 - st->unk36 - st->unk32 - st->unk22 - M2C_FIELD(g, int *, 8) * 2;
        M2C_FIELD(tr, int *, 0x34) = 0;
    }
}

void calcTdBoxPosition(void *ctx, BOX *td) {
    int x = 0;
    BOX *t;
    BOXGEOM *tg;
    BOXSTYLE *st;
    int i;
    int ox, oy;

    t = getTableBox(td);
    if (t != NULL) {
        tg = t->geom;
        for (i = 0; i < M2C_FIELD(td->geom, u16 *, 0x12); i++)
            x += (*(TDCOL **)((char *)tg + 0x20))[i].width;
        x += (M2C_FIELD(td->geom, u16 *, 0x12) + 1) * M2C_FIELD(tg, int *, 8);
        ox = td->x;
        oy = td->y;
        st = t->style;
        td->x = st->unk26 + t->x + st->unk36 + x;
        td->y = st->unk20 + t->y + st->unk30 + M2C_FIELD(t, int *, 0x34);
        if (M2C_FIELD(ctx, s16 *, 0x16) == 0 && !(M2C_FIELD(td, u16 *, 0x40) & 1) && td->width == M2C_FIELD(td->geom, int *, 8)) {
            D_00584CF0.f = 1;
            if (ox != td->x || oy != td->y)
                moveBoxPositionChild(td, td->x - ox, td->y - oy);
            M2C_FIELD(td, u16 *, 0x40) |= 2;
        } else {
            lfm_resetPageRegion(td->region, td->width - td->style->unk36 - td->style->unk2E - td->style->unk2A - td->style->unk32);
            M2C_FIELD(td, int *, 0x34) = 0;
            M2C_FIELD(td, u16 *, 0x40) &= ~1;
        }
        M2C_FIELD(td->geom, int *, 8) = td->width;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", calcInlineBoxPosition);

void calcBlockBoxPosition(void *ctx, BOX *box) {
    int x, y, left, right;
    int m = 0;
    int flag = 0;
    int tbl = 0;
    int h;
    BOX *prev;
    BOX *p;
    BOX *q;
    BOX *b;

    if (box->content == 1)
        return;
    if (box->html == 0x2D || box->html == 0x3C)
        flag = 1;
    box->height = 0;
    if (M2C_FIELD(M2C_FIELD(ctx, LIST **, 0xC), void **, 0) != NULL) {
        int lf = lineFeedProc(ctx, box);
        M2C_FIELD(M2C_FIELD(ctx, void **, 4), int *, 0x34) += lf;
    }
    getBaseBlockPosition(ctx, &x, &y);
    h = getPrevLineHeight(ctx);
    if (flag)
        lfm_getHorizontalArea(M2C_FIELD(ctx, void **, 0x10), M2C_FIELD(ctx, void **, 4), h, &left, &right);
    else
        left = 0;
    if (box->html != 0x2D && h == 0) {
        if (box->style->unk20 != 0)
            box->style->unk20 = 0;
    }
    prev = box->prev;
    p = box->parent;
    while (prev == NULL && p != NULL && p->display != 0 && p->display != 3) {
        prev = p->prev;
        p = p->parent;
    }
    if (prev != NULL && box->html != 0x2D && prev->html != 0x2D && (prev->display == 0 || prev->display == 3)) {
        m = box->style->unk20 > prev->style->unk24 ? prev->style->unk24 : box->style->unk20;
    }
    if (m > 0)
        M2C_FIELD(M2C_FIELD(ctx, void **, 4), int *, 0x34) -= m;
    if (box->html == 0x12 && box->prev != NULL && box->prev->content == 4)
        tbl = 1;
    if (box->style->unk72 < 2) {
        if (tbl)
            box->x = box->prev->x;
        else
            box->x = x + left;
        box->y = h + y - m;
        if (flag)
            m = right;
        else
            m = getContainingBlockWidth(M2C_FIELD(ctx, void **, 4));
    } else {
        q = box->parent;
        while (q->content != 1) {
            if (q->display == 0 && M2C_FIELD(q->style, s8 *, 0x72) != 0)
                break;
            q = q->parent;
        }
        x = q->style->unk26 + q->x + q->style->unk36;
        y = q->style->unk20 + q->y + q->style->unk30;
        box->x = box->style->unk52 + x;
        box->y = box->style->unk50 + y;
        m = q->width - q->style->unk26 - q->style->unk36 - q->style->unk32 - q->style->unk22;
    }
    h = box->style->unk26 + box->style->unk36 + box->style->unk2E + box->style->unk2A + box->style->unk32 + box->style->unk22;
    if (tbl) {
        box->width = box->prev->width;
    } else if (box->style->unk72 < 2) {
        switch (box->style->flags & 3) {
        case 1:
            box->width = box->style->unk26 + box->style->width + box->style->unk22;
            break;
        case 2:
            box->width = (m - box->style->unk26 - box->style->unk22) * box->style->width / 100 + box->style->unk26 + box->style->unk22;
            break;
        default:
            box->width = m;
            break;
        }
    } else if (M2C_FIELD(box->style, s8 *, 0x72) == 2) {
        switch (box->style->flags & 3) {
        case 1:
            box->width = box->style->unk26 + box->style->width + box->style->unk22;
            break;
        case 2:
            box->width = (m - box->style->unk26 - box->style->unk22) * box->style->width / 100 + box->style->unk26 + box->style->unk22;
            break;
        default:
            box->width = calcBoxMaxWidth(ctx, box) + h;
            if (box->x + box->width > M2C_FIELD(M2C_FIELD(*(BOX **)ctx, void **, 0x20), int *, 8))
                box->width = M2C_FIELD(M2C_FIELD(*(BOX **)ctx, void **, 0x20), int *, 8) - box->x;
            break;
        }
        if (!flag) {
            if (box->region == NULL)
                box->region = lfm_createPageRegion(box, box->width - h);
            else
                lfm_resetPageRegion(box->region, box->width - h);
        }
    }
    if (box->html == 0x2D) {
        b = getBoxByHTML(box, 0x38);
        if (b != NULL) {
            LIST *l = (LIST *)((char *)b->geom + 4);
            if (l->head == NULL)
                addBoxList(l, box);
        }
    }
    if (!tbl && box->width < m) {
        b = box->html == 0x2D ? box : box->parent;
        if (M2C_FIELD(b->style, s8 *, 0x6F) == 2)
            box->x += (m - box->width) / 2;
        else if (M2C_FIELD(b->style, s8 *, 0x6F) == 3)
            box->x += m - box->width;
    }
    if (box->width - h < 0)
        box->width = h;
    M2C_FIELD(box, int *, 0x34) = 0;
    initLinePosition(box);
}

void calcFloatBoxPosition(void *ctx, BOX *box) {
    int x, y;
    int dx, dy;
    int h;
    int w, bh, side;

    getBaseBlockPosition(ctx, &x, &y);
    h = getPrevLineHeight(ctx);
    h += getLineHeight(M2C_FIELD(ctx, void **, 0xC));
    w = box->width;
    bh = box->height;
    side = M2C_FIELD(box->style, s8 *, 0x71) == 1 ? 1 : 3;
    dy = 0;
    dx = 0;
    lfm_addFloat(M2C_FIELD(ctx, void **, 0x10), M2C_FIELD(ctx, void **, 4), h, w, bh, side, &dx, &dy);
    box->x = x + dx;
    box->y = y + dy;
}

BOX *getCurrentLineBox(BOX *box) {
    s16 c;
    while (box != NULL) {
        c = box->content;
        if (c == 17 || c == 1) {
            return box;
        }
        box = box->parent;
    }
    return NULL;
}

void *getCurrentLineCB(BOX *box) {
    while (box != NULL) {
        if (box->content == 17) {
            return (char *)box->geom + 4;
        }
        if (box->content == 1) {
            return (char *)box->geom + 0x90;
        }
        box = box->parent;
    }
    return NULL;
}

void initLinePosition(BOX *box) {
    while (box != NULL) {
        if (box->content == 17) {
            M2C_FIELD(box->geom, int *, 0x10) = 0;
            return;
        }
        if (box->content == 1) {
            M2C_FIELD(box->geom, int *, 0x8C) = 0;
            return;
        }
        box = box->parent;
    }
}

void setLinePosition(BOX *box, int pos) {
    while (box != NULL) {
        if (box->content == 17) {
            M2C_FIELD(box->geom, int *, 0x10) = pos;
            return;
        }
        if (box->content == 1) {
            M2C_FIELD(box->geom, int *, 0x8C) = pos;
            return;
        }
        box = box->parent;
    }
}

int getLinePosition(BOX *box) {
    while (box != NULL) {
        if (box->content == 17) {
            return M2C_FIELD(box->geom, int *, 0x10);
        }
        if (box->content == 1) {
            return M2C_FIELD(box->geom, int *, 0x8C);
        }
        box = box->parent;
    }
    return 0;
}

int getLineWidth(LINE *l) {
    int w = 0;
    LINEENT *f;
    LINEENT *e;
    int x;
    if (l->first == NULL) {
        return 0;
    }
    f = l->first;
    e = l->last;
    x = f->box->x;
    w = e->box->x + e->box->width - x;
    return w;
}

int getLineHeight(LINE *line) {
    LINEENT *e;
    int h;
    if (line->first == NULL) {
        h = 0;
    } else {
        h = 0;
        for (e = line->first; e != NULL && e->box != NULL; e = e->next) {
            h = h > e->box->height ? h : e->box->height;
        }
    }
    return h;
}

int lineFeedProc(void *ctx, BOX *box) {
    int r;
    adjustLineHposition(ctx, M2C_FIELD(ctx, void **, 0xC));
    r = adjustLineVposition(ctx, M2C_FIELD(ctx, void **, 4), M2C_FIELD(ctx, void **, 0xC));
    updateLiFirstLineList(ctx);
    initBoxList(M2C_FIELD(ctx, LIST **, 0xC));
    initLinePosition(box);
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", turnupContent);

void moveBoxPositionChild(BOX *box, int dx, int dy) {
    BOX *c = box->child;
    while (c != NULL && c != box) {
        c->x += dx;
        c->y += dy;
        if (c->child != NULL) {
            c = c->child;
        } else if (c->next != NULL) {
            c = c->next;
        } else {
            c = c->parent;
            while (c != NULL && c != box) {
                if (c->next != NULL) {
                    c = c->next;
                    break;
                }
                c = c->parent;
            }
        }
    }
}

void moveBoxPosition(BOX *box, int dx, int dy) {
    box->x += dx;
    box->y += dy;
    moveBoxPositionChild(box, dx, dy);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void getBaseBlockPosition(void *arg0, int *arg1, int *arg2) {
    int temp_a1;
    int temp_a3;
    int temp_v1;
    int temp_v1_2;

    *arg1 = 0;
    *arg2 = 0;
    *arg1 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x10);
    *arg2 = M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x14);
    temp_a3 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x26) + *arg1;
    *arg1 = temp_a3;
    temp_v1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x2E) + temp_a3;
    *arg1 = temp_v1;
    *arg1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x36) + temp_v1;
    temp_a1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x20) + *arg2;
    *arg2 = temp_a1;
    temp_v1_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x28) + temp_a1;
    *arg2 = temp_v1_2;
    *arg2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 4), void **, 0x24), short *, 0x30) + temp_v1_2;
}

int adjustLineVposition(void *ctx, BOX *box, LIST *line) {
    int w, h;
    int base;
    LISTNODE *n;
    LISTNODE *m;
    BOX *b;
    int top;
    int d;
    int maxh;
    int hh;

    GUI_Graphics_getStringSize(box->style->unk64, D_00139244, 1, &w, &h);
    hh = h;
    base = 0;
    maxh = 0;
    for (n = line->head; n != NULL; n = n->next) {
        b = n->data;
        top = b->y;
        switch (M2C_FIELD(b->style, s8 *, 0x70)) {
        case 5:
            d = b->height / 2 - (base - hh / 2);
            if (d > 0) {
                for (m = line->head; m != n; m = m->next) {
                    if (M2C_FIELD(((BOX *)m->data)->style, s8 *, 0x70) != 3) {
                        moveBoxPosition(m->data, 0, d);
                        adjustInlineBoxDimensionLoop(m->data, M2C_FIELD(ctx, void **, 4));
                        maxh = maxh < ((BOX *)m->data)->y - top + ((BOX *)m->data)->height ? ((BOX *)m->data)->y - top + ((BOX *)m->data)->height : maxh;
                    }
                }
                base += d;
            } else if (d < 0) {
                moveBoxPosition(b, 0, -d);
                adjustInlineBoxDimensionLoop(b, M2C_FIELD(ctx, void **, 4));
            }
            break;
        case 0:
        case 6:
            d = b->height - base;
            if (d > 0) {
                for (m = line->head; m != n; m = m->next) {
                    if (M2C_FIELD(((BOX *)m->data)->style, s8 *, 0x70) != 3) {
                        moveBoxPosition(m->data, 0, d);
                        adjustInlineBoxDimensionLoop(m->data, M2C_FIELD(ctx, void **, 4));
                        maxh = maxh < ((BOX *)m->data)->y - top + ((BOX *)m->data)->height ? ((BOX *)m->data)->y - top + ((BOX *)m->data)->height : maxh;
                    }
                }
                base = b->height;
            } else if (d < 0) {
                moveBoxPosition(b, 0, -d);
                adjustInlineBoxDimensionLoop(b, M2C_FIELD(ctx, void **, 4));
            }
            break;
        case 1:
            d = base - hh / 2;
            if (d > 0) {
                maxh = maxh < d + b->height ? d + b->height : maxh;
                moveBoxPosition(b, 0, d);
                adjustInlineBoxDimensionLoop(b, M2C_FIELD(ctx, void **, 4));
            }
            break;
        case 2:
            d = hh / 2 + b->height - base;
            if (d > 0) {
                for (m = line->head; m != n; m = m->next) {
                    if (M2C_FIELD(((BOX *)m->data)->style, s8 *, 0x70) != 3) {
                        moveBoxPosition(m->data, 0, d);
                        adjustInlineBoxDimensionLoop(m->data, M2C_FIELD(ctx, void **, 4));
                        maxh = maxh < ((BOX *)m->data)->y - top + ((BOX *)m->data)->height ? ((BOX *)m->data)->y - top + ((BOX *)m->data)->height : maxh;
                    }
                }
                base = hh / 2;
                base += b->height;
            } else if (d < 0) {
                moveBoxPosition(b, 0, -d);
                adjustInlineBoxDimensionLoop(b, M2C_FIELD(ctx, void **, 4));
            }
            break;
        case 3:
        case 4:
            break;
        }
        maxh = maxh < b->y - top + b->height ? b->y - top + b->height : maxh;
    }
    return maxh;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_position", adjustLineHposition);

void calcBoxPosition(void *ctx, BOX *box) {
    if (box->parent == NULL)
        return;
    if (box->content == 1)
        return;
    switch (box->display) {
    case 1:
        calcInlineBoxPosition(ctx, box);
        break;
    case 0:
    case 3:
        switch (box->content) {
        case 4:
            calcTableBoxPosition(ctx, box);
            break;
        case 5:
            calcTrBoxPosition(ctx, box);
            break;
        case 6:
            calcTdBoxPosition(ctx, box);
            break;
        case 17:
            calcBlockButtonBoxPosition(ctx, box);
            break;
        default:
            if (box->html != 0x2C)
                calcBlockBoxPosition(ctx, box);
            break;
        }
        break;
    case 2:
        calcFloatBoxPosition(ctx, box);
        break;
    }
}
