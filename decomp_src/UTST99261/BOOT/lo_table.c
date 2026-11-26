/* cflags: -O1 */
#include "common.h"

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


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableColumnSpec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableCellMinWidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_table", getTableCellMaxWidth);

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
