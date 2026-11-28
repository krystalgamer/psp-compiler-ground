/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/lo_box.h"

int getTableColumnSpec();

typedef struct TNODE {
    struct TNODE *next;
    struct TNODE *prev;
    struct TBOX *box;
} TNODE;

typedef struct {
    int start;                  /* 0x0 */
    int span;                   /* 0x4 */
    int nsub;                   /* 0x8 */
    s8 hasSub;                  /* 0xC */
    TNODE *sub;                 /* 0x10 */
    u8 unk14[0x28];
    TNODE *cols;                /* 0x3C */
} TGEOM;

typedef struct TBOX {
    u8 unk0[0x20];
    TGEOM *geom;                /* 0x20 */
} TBOX;


#define CBPAD(s) ((s)->unk26 + (s)->unk36 + (s)->unk2E + (s)->unk2A + (s)->unk32 + (s)->unk22)
int calcBoxMinWidth();
int calcBoxMaxWidth();
int getTableCellMaxWidth(int ctx, BOX *root, int cbw);
INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableColumnSpec);

int getTableCellMinWidth(int ctx, BOX *root, int cbw)
{
    int w;
    int vis;
    int mx;
    int ofs;
    int fixed;
    int line;
    int m;
    int p;
    int len;
    int k;
    char *str;
    int font;
    BOX *n;
    BOXSTYLE *st;

    mx = 0;
    ofs = 0;
    fixed = 0;
    line = 0;
    getBodyBox(root);
    if (root->content == 6 && (root->style->flags & 3) != 0)
        fixed = 1;
    n = root->child;
    while (n != NULL && n != root) {
        w = 0;
        if (n->content == 4) {
            getTableColumnSpec(ctx, n, &w, 0, 0, cbw);
            st = n->style;
            m = st->unk26 + st->unk22;
            if ((st->flags & 3) == 1 && w - m < st->width)
                w = m + st->width;
            w = ofs + w;
            mx = mx < w ? w : mx;
            line = 0;
            goto next;
        } else if (n->content == 9) {
            resizeTextSize(n);
            len = ((int *)n->geom)[3];
            str = ((char **)n->geom)[0];
            font = n->style->unk64;
            while (len > 0) {
                vis = 0;
                k = getStringsVisibleLength(font, str, len, 0, 0, &vis);
                len -= k;
                str += k;
                if (w < vis)
                    w = vis;
            }
            w = ofs + w;
            line = 0;
        } else if (n->content == 11) {
            if ((n->style->flags & 3) == 1)
                w = ofs + n->style->width;
            line = 0;
        } else if (n->content != 0 && (n->html != 0x66 || getListBox(n) == NULL) && (unsigned short)(n->display - 1) < 2) {
            if (n->content == 10)
                resizeImageSize(n);
            else if (n->content == 0x10)
                resizeButtonSize(n);
            else if (n->content == 0xD)
                resizeTextFieldSize(n);
            else if (n->content == 0x12)
                resizeSelectSize(n);
            if (fixed == 0) {
                line += n->width;
                w = line + ofs;
            } else
                w = ofs + n->width;
        } else if (n->display == 3) {
            w = calcBoxMinWidth(ctx, n);
            if (mx < w)
                mx = w;
            goto next;
        } else if (n->display == 0) {
            st = n->style;
            p = CBPAD(st);
            ofs += p;
            if ((st->flags & 3) == 1)
                w = p + st->width;
            line = 0;
        } else if (n->display == 1) {
            if ((s8)n->style->unk74 != 0) {
                w = getTableCellMaxWidth(ctx, n, cbw) + ofs;
                if (mx < w)
                    mx = w;
                goto next;
            }
            if (n->html == 0x10)
                line = 0;
        }
        mx = mx < w ? w : mx;
        if (n->child != NULL) {
            n = n->child;
            continue;
        }
    next:
        if (n->next != NULL) {
            n = n->next;
            continue;
        }
        for (n = n->parent; n != NULL && n != root; n = n->parent) {
            if (n->display == 0) {
                line = 0;
                if (n->content == 0 || n->content == 8)
                    ofs -= CBPAD(n->style);
            }
            if (n->next != NULL) {
                n = n->next;
                break;
            }
        }
    }
    st = root->style;
    mx += st->unk36 + st->unk2E + st->unk2A + st->unk32;
    if (root->content == 6 && (((u16 *)root->geom)[0x18 / 2] & 1)) {
        w = getTableCellMaxWidth(ctx, root, cbw);
        mx = mx < w ? w : mx;
    }
    return mx;
}

int getTableCellMaxWidth(int ctx, BOX *root, int cbw)
{
    int mn;
    int line;
    int mx;
    int ofs;
    int m;
    int p;
    BOX *n;
    BOXSTYLE *st;

    line = 0;
    mx = 0;
    ofs = 0;
    if (root->content == 6 && (root->style->flags & 3) == 1)
        return root->style->width;
    n = root->child;
    while (n != NULL && n != root) {
        if (n->content == 4) {
            mx = mx < ofs + line ? ofs + line : mx;
            getTableColumnSpec(ctx, n, &mn, &line, 0, cbw);
            st = n->style;
            m = st->unk26 + st->unk22;
            if ((st->flags & 3) == 1) {
                if (st->width >= mn - m)
                    line = m + st->width;
                else
                    line = mn;
            }
            mx = mx < ofs + line ? ofs + line : mx;
            line = 0;
            goto next;
        } else if (n->content == 11) {
            mx = mx < ofs + line ? ofs + line : mx;
            line = 0;
            if ((n->style->flags & 3) == 1 && mx < ofs + n->style->width)
                mx = ofs + n->style->width;
        } else if (n->display == 0) {
                mx = mx < ofs + line ? ofs + line : mx;
                line = 0;
                st = n->style;
                p = CBPAD(st);
                ofs += p;
                if ((st->flags & 3) == 1 && mx < p + st->width) {
                    mx = n->width;
                    goto next;
                }
        } else if (n->display == 3) {
                line += calcBoxMaxWidth(ctx, n);
                goto next;
        } else {
                if (n->content != 0 && (n->html != 0x66 || getListBox(n) == NULL)) {
                    if (n->content == 10)
                        resizeImageSize(n);
                    else if (n->content == 9)
                        resizeTextSize(n);
                    else if (n->content == 0x10)
                        resizeButtonSize(n);
                    else if (n->content == 0xD)
                        resizeTextFieldSize(n);
                    else if (n->content == 0x12)
                        resizeSelectSize(n);
                    line += n->width;
                } else if (n->html == 0x10) {
                    mx = mx < ofs + line ? ofs + line : mx;
                    line = 0;
                }
        }
        if (n->child != NULL) {
            n = n->child;
            continue;
        }
    next:
        if (n->next != NULL) {
            n = n->next;
            continue;
        }
        for (n = n->parent; n != NULL && n != root; n = n->parent) {
            if (n->display == 0 && (n->content == 0 || n->content == 8)) {
                mx = mx < ofs + line ? ofs + line : mx;
                line = 0;
                ofs -= CBPAD(n->style);
            }
            if (n->next != NULL) {
                n = n->next;
                break;
            }
        }
    }
    mx = mx < line ? line : mx;
    st = root->style;
    return mx + (st->unk36 + st->unk2E + st->unk2A + st->unk32);
}

typedef struct {
    u8 unk0[0x10];
    int width;                  /* 0x10 */
} COLSPEC;

typedef struct {
    u8 unk0[0x10];
    u16 row;                    /* 0x10 */
    u16 col;                    /* 0x12 */
    u16 colspan;                /* 0x14 */
} CELLGEOM;

typedef struct {
    u8 unk0[0x18];
    int width;                  /* 0x18 */
    int unk1C;
    CELLGEOM *geom;             /* 0x20 */
} CELLBOX;

typedef struct {
    u8 unk0[0x8];
    int spacing;                /* 0x8 */
    u8 unkC[0x8];
    u16 rows;                   /* 0x14 */
    u8 unk16[0x2];
    u16 cols;                   /* 0x18 */
    u8 unk1A[0x6];
    COLSPEC *colspec;           /* 0x20 */
    CELLBOX **cells;            /* 0x24 */
} TABGEOM;

void setCellWidth(TBOX *table) {
    TABGEOM *g;
    COLSPEC *cs;
    CELLBOX *cell;
    int r;
    int c;
    int k;

    g = (TABGEOM *)table->geom;
    cs = g->colspec;
    for (r = 0; r < g->rows; r++) {
        for (c = 0; c < g->cols; c++) {
            cell = g->cells[r * g->cols + c];
            if (cell == NULL) {
                continue;
            }
            if (cell->geom->row != r || cell->geom->col != c) {
                continue;
            }
            if (cell->geom->colspan < 2) {
                cell->width = cs[c].width;
            } else {
                cell->width = cs[c].width;
                for (k = 1; k < cell->geom->colspan; k++) {
                    cell->width += cs[c + k].width;
                }
                cell->width = (cell->geom->colspan - 1) * g->spacing + cell->width;
            }
        }
    }
}

int box_calcTableWidth(int a, int b, int c, int d, int e) {
    return getTableColumnSpec(a, b, c, d, 0, e);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_setTableWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_setTableHeight);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", box_getColBoxAt);
