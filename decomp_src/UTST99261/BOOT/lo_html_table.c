/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "m2c_macros.h"
#include "lo_box.h"
BOX *createBox(void *ctx, int type);
BOX *getTableBox(BOX *box);
int getContainingBlockWidth(BOX *box);
void linkBoxNoTableCheck(BOX *box, BOX *parent, BOX *prev);
void initNoneContent(BOX *box, void *ctx);
void initTdContent(BOX *box, void *ctx);
void initBoxProperty(BOX *box);
void attr_ALIGN_trgroup(void *node, BOX *box);
void attr_VALIGN_trgroup(void *node, BOX *box);
void applyCSSExtStyleSheetToBox(void *node, BOX *box);
void applyCSSInlinePropertyToBox(void *node, BOX *box);
void *lfm_createPageRegion(BOX *box, int width);
BOX *html_TD_inner(void *node, BOX *tr, BOX *last, BOX *box);
void *Node_getParentNode(void *node);
BOX *Node_getBox(void *node);

typedef struct COLGEOM { int x; int w; int span; signed char fixed; } COLGEOM;
typedef struct COLLIST { void *x0; void *x4; BOX *box; } COLLIST;
void initColContent(BOX *box, void *node, int type);
void attr_SPAN(void *node, BOX *box);
void attr_WIDTH_col(void *node, BOX *box);
typedef struct TBLGEOM { u8 pad[0x14]; unsigned short cap; unsigned short nrows; unsigned short ncols; u8 pad2[0xA]; int *cells; } TBLGEOM;
BOX *getTrGroupBoxFromDOM(void *node);
void initTrContent(BOX *box, void *node);
void attr_BGCOLOR(void *node, BOX *box);
void attr_ALIGN_tr(void *node, BOX *box);
void attr_VALIGN_tr(void *node, BOX *box);
void attr_HEIGHT_tr(void *node, BOX *box);
void delLinkBox(BOX *box);
void freeBox(BOX *box, int all);
void *MEM_realloc(void *pool, void *p, unsigned int size);
void *memset(void *, int, unsigned int);
BOX *createBlockBox(void *node);
void initTableContent(BOX *box, void *node);
void attr_FRAME(void *node, BOX *box);
void attr_BORDER_table(void *node, BOX *box);
void attr_BORDERCOLOR(void *node, BOX *box);
void attr_CELLPADDING(void *node, BOX *box);
void attr_CELLSPACING(void *node, BOX *box);
void attr_WIDTH_table(void *node, BOX *box);
void attr_HEIGHT_table(void *node, BOX *box);
void attr_BACKGROUND(void *node, BOX *box);
void attr_ALIGN_table(void *node, BOX *box);
int colorValue(char *s);
typedef struct TDGEOM { u8 pad[0x10]; unsigned short row; unsigned short col; unsigned short colspan; unsigned short rowspan; } TDGEOM;
void *MEM_calloc(void *pool, unsigned int size);
void *memcpy(void *, const void *, unsigned int);
void *getDOMAttributeValue(void *node, void *name);
extern char _DOMbordercolor[];
BOX *getTrBox(BOX *box);
BOX *box_getColBoxAt(BOX *table, unsigned short col);
void attr_COLSPAN(void *node, BOX *box);
void attr_ROWSPAN(void *node, BOX *box);
void attr_WIDTH_td(void *node, BOX *box);
void attr_HEIGHT_td(void *node, BOX *box);
void attr_NOWRAP_td(void *node, BOX *box);
void attr_ALIGN_td(void *node, BOX *box);
void attr_VALIGN_td(void *node, BOX *box);
void linkBox(BOX *box, BOX *parent, BOX *prev);
BOX *getTableBoxFromDOM(void *node) {
    BOX *box;
    for (node = Node_getParentNode(node); node != NULL; node = Node_getParentNode(node)) {
        box = Node_getBox(node);
        if (box != NULL) {
            if (box->content == 4) {
                return box;
            }
            if (box->content == 6 || box->content == 1) {
                return NULL;
            }
        }
    }
    return NULL;
}

BOX *getTrBoxFromDOM(void *node) {
    BOX *box;
    for (node = Node_getParentNode(node); node != NULL; node = Node_getParentNode(node)) {
        box = Node_getBox(node);
        if (box != NULL) {
            if (box->content == 5) {
                return box;
            }
            if (box->content == 4 || box->content == 1) {
                return NULL;
            }
        }
    }
    return NULL;
}

BOX *getTrGroupBoxFromDOM(void *node) {
    BOX *box;
    for (node = Node_getParentNode(node); node != NULL; node = Node_getParentNode(node)) {
        box = Node_getBox(node);
        if (box != NULL) {
            if (box->content == 4 || box->html == 0x56 || box->html == 0x5B || box->html == 0x59) {
                return box;
            }
            if (box->content == 6 || box->content == 1) {
                return NULL;
            }
        }
    }
    return NULL;
}

BOX *getColGroupBoxFromDOM(void *node) {
    BOX *box;
    for (node = Node_getParentNode(node); node != NULL; node = Node_getParentNode(node)) {
        box = Node_getBox(node);
        if (box != NULL) {
            if (box->content == 4 || box->html == 0x17) {
                return box;
            }
            if (box->content == 6 || box->content == 1) {
                return NULL;
            }
        }
    }
    return NULL;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393C4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393CC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393EC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001393FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139400);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139404);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139408);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013940C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139418);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139420);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139428);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139430);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013943C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139440);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139444);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139448);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013944C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139450);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139454);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013945C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139460);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139468);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013946C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139474);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139478);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139480);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139484);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013948C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139490);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139498);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394C0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394C8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394E8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001394F4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139500);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139508);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013950C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139514);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139518);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013951C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139520);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139528);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139530);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139538);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139540);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139548);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139550);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139558);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139560);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139564);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139568);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139570);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139578);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013957C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139588);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139590);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_00139594);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_0013959C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001395A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001395A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001395AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001395B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001395B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001395B8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", D_001395BC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", jt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", jt_after);

BOX *html_TD_inner(void *node, BOX *tr, BOX *last, BOX *box) {
    BOX *table;
    TBLGEOM *tg;
    BOX *row;
    BOX *col;
    void *v;
    int rowspan;
    int colspan;
    int c;
    int i;
    int j;
    int need;
    int *p;
    int bc;
    int bw;

    table = getTableBox(box);
    tg = (TBLGEOM *)table->geom;
    row = getTrBox(box);
    if (row == NULL)
        return NULL;
    if (M2C_FIELD(table->geom, int *, 0) & 0x20) {
        box->style->unk30 = 1;
        box->style->unk32 = 1;
        box->style->unk34 = 1;
        box->style->unk36 = 1;
        box->style->unk48 = 1;
        box->style->unk4A = 1;
        box->style->unk4C = 1;
        box->style->unk4E = 1;
    }
    box->style->unk38 = colorValue("#777777");
    box->style->unk3C = colorValue("#dddddd");
    box->style->unk40 = colorValue("#dddddd");
    box->style->unk44 = colorValue("#777777");
    v = getDOMAttributeValue(M2C_FIELD(table, void **, 0x28), _DOMbordercolor);
    if (v != NULL) {
        bc = table->style->unk38;
        box->style->unk38 = bc;
        box->style->unk3C = bc;
        box->style->unk40 = bc;
        box->style->unk44 = bc;
        MEM_free(0, v);
    }
    bw = M2C_FIELD(table->geom, int *, 4);
    box->style->unk28 = bw;
    box->style->unk2A = bw;
    box->style->unk2C = bw;
    box->style->unk2E = bw;
    M2C_FIELD(box->style, int *, 0) = M2C_FIELD(row->style, int *, 0);
    if (M2C_FIELD(row->geom, int *, 0) != 0)
        M2C_FIELD(box->style, s8 *, 0x10) = 1;
    attr_BGCOLOR(node, box);
    attr_BACKGROUND(node, box);
    attr_COLSPAN(node, box);
    attr_ROWSPAN(node, box);
    attr_WIDTH_td(node, box);
    if (row->style->flags & 0xC) {
        box->style->flags &= ~0xC;
        box->style->flags |= row->style->flags & 0xC;
        box->style->height = row->style->height;
    }
    attr_HEIGHT_td(node, box);
    box->style->unk74 = 0;
    attr_NOWRAP_td(node, box);
    rowspan = ((TDGEOM *)box->geom)->rowspan ? ((TDGEOM *)box->geom)->rowspan : 1;
    colspan = ((TDGEOM *)box->geom)->colspan ? ((TDGEOM *)box->geom)->colspan : 1;
    for (c = 0; c < tg->ncols; c++) {
        if (tg->cells[tg->nrows * tg->ncols + c] == 0)
            break;
    }
    need = c + colspan;
    if (tg->ncols < need) {
        p = MEM_calloc(0, tg->cap * (c + colspan) * 4);
        for (i = 0; i < tg->cap; i++)
            memcpy(p + i * (c + colspan), tg->cells + i * tg->ncols, tg->ncols * 4);
        tg->ncols = c + colspan;
        MEM_free(0, tg->cells);
        tg->cells = p;
    }
    if (tg->nrows + rowspan > tg->cap) {
        p = MEM_calloc(0, tg->ncols * (tg->nrows + rowspan) * 4);
        memcpy(p, tg->cells, tg->ncols * tg->cap * 4);
        tg->cap = tg->nrows + rowspan;
        MEM_free(0, tg->cells);
        tg->cells = p;
    }
    ((TDGEOM *)box->geom)->row = tg->nrows;
    ((TDGEOM *)box->geom)->col = c;
    for (i = 0; i < rowspan; i++)
        for (j = 0; j < colspan; j++)
            tg->cells[(tg->nrows + i) * tg->ncols + c + j] = (int)box;
    attr_ALIGN_td(node, box);
    attr_VALIGN_td(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    if (M2C_FIELD(box->style, s8 *, 0x10) == 0) {
        col = box_getColBoxAt(table, ((TDGEOM *)box->geom)->col);
        if (col != NULL && M2C_FIELD(col->style, s8 *, 0x10) != 0) {
            M2C_FIELD(box->style, int *, 0) = M2C_FIELD(col->style, int *, 0);
            M2C_FIELD(box->style, s8 *, 0x10) = 1;
        }
    }
    return box;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", html_CAPTION);

BOX *html_TABLE(void *node) {
    BOX *outer;
    BOX *box;

    outer = createBlockBox(node);
    if (outer == NULL) {
        return NULL;
    }
    outer->html = 0x68;
    initBoxProperty(outer);
    outer->style->unk30 = 0;
    outer->style->unk32 = 0;
    outer->style->unk34 = 0;
    outer->style->unk36 = 0;
    outer->style->fontSize = 2;
    outer->style->unk6A = 0;
    outer->style->unk64 = ui_global->color[outer->style->unk6A][outer->style->fontSize];
    box = createBox(node, 1);
    if (box == NULL) {
        delLinkBox(outer);
        freeBox(outer, 0);
        return NULL;
    }
    linkBox(box, outer, NULL);
    box->display = 0;
    box->html = 0x55;
    initTableContent(box, node);
    initBoxProperty(box);
    initBoxList((LIST *)((char *)box->geom + 0x30));
    attr_FRAME(node, box);
    attr_BORDER_table(node, box);
    box->style->unk38 = colorValue("#bbbbbb");
    box->style->unk3C = colorValue("#999999");
    box->style->unk40 = colorValue("#999999");
    box->style->unk44 = colorValue("#bbbbbb");
    attr_BORDERCOLOR(node, box);
    attr_CELLPADDING(node, box);
    attr_CELLSPACING(node, box);
    attr_WIDTH_table(node, box);
    attr_HEIGHT_table(node, box);
    attr_BGCOLOR(node, box);
    attr_BACKGROUND(node, box);
    attr_ALIGN_table(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_TD(void *node) {
    BOX *tr;
    BOX *last;
    BOX *c;
    BOX *box;
    tr = getTrBoxFromDOM(node);
    if (tr == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = tr->child; c != NULL; c = c->next) {
        last = c;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, tr, last);
    box->display = 0;
    box->html = 0x57;
    initTdContent(box, node);
    initBoxProperty(box);
    box->region = lfm_createPageRegion(box, box->width);
    return html_TD_inner(node, tr, last, box);
}

BOX *html_TH(void *node) {
    BOX *tr;
    BOX *last;
    BOX *c;
    BOX *box;
    tr = getTrBoxFromDOM(node);
    if (tr == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = tr->child; c != NULL; c = c->next) {
        last = c;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, tr, last);
    box->display = 0;
    box->html = 0x5A;
    initTdContent(box, node);
    initBoxProperty(box);
    box->style->unk6A |= 1;
    box->style->unk64 = ui_global->color[box->style->unk6A][box->style->fontSize];
    box->region = lfm_createPageRegion(box, box->width);
    html_TD_inner(node, tr, last, box);
    return box;
}

BOX *html_TR(void *node) {
    BOX *group;
    BOX *last;
    BOX *c;
    BOX *box;
    BOX *table;
    TBLGEOM *tg;
    BOXSTYLE *st;

    group = getTrGroupBoxFromDOM(node);
    if (group == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = group->child; c != NULL; c = c->next) {
        last = c;
    }
    table = getTableBox(group);
    if (table == NULL) {
        return NULL;
    }
    tg = (TBLGEOM *)table->geom;
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, group, last);
    box->display = 0;
    box->html = 0x5D;
    initTrContent(box, node);
    initBoxProperty(box);
    attr_BGCOLOR(node, box);
    attr_ALIGN_tr(node, box);
    attr_VALIGN_tr(node, box);
    attr_HEIGHT_tr(node, box);
    tg->nrows++;
    M2C_FIELD(box->geom, short *, 4) = tg->nrows;
    if (tg->cap < tg->nrows + 1) {
        tg->cap = tg->nrows + 1;
        if (tg->cells == NULL)
            tg->cells = MEM_malloc(0, 4);
        else
            tg->cells = MEM_realloc(0, tg->cells, tg->ncols * tg->cap * 4);
        if (tg->cells == NULL) {
            delLinkBox(box);
            freeBox(box, 0);
            return NULL;
        }
        memset(tg->cells + (tg->cap - 1) * tg->ncols, 0, tg->ncols * 4);
    }
    addBoxList((LIST *)((char *)table->geom + 0x30), box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    st = box->style;
    if (M2C_FIELD(st, s8 *, 0x10) != 0) {
        M2C_FIELD(box->geom, int *, 0) = 1;
    } else if (group->content == 0 && M2C_FIELD(group->style, s8 *, 0x10) != 0) {
        M2C_FIELD(st, int *, 0) = M2C_FIELD(group->style, int *, 0);
        M2C_FIELD(box->geom, int *, 0) = 1;
    }
    M2C_FIELD(box->style, s8 *, 0x10) = 0;
    return box;
}

BOX *html_COL(void *node) {
    BOX *group;
    BOX *last;
    BOX *c;
    BOX *box;
    BOX *p;
    COLLIST *l;
    COLGEOM *g;

    group = getColGroupBoxFromDOM(node);
    if (group == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = group->child; c != NULL; c = c->next) {
        last = c;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, group, last);
    box->display = 1;
    box->html = 0x16;
    initColContent(box, node, 0);
    attr_SPAN(node, box);
    attr_ALIGN_trgroup(node, box);
    attr_VALIGN_trgroup(node, box);
    attr_WIDTH_col(node, box);
    for (p = group; p != NULL; p = p->parent) {
        if (p->html == 0x17) {
            l = M2C_FIELD(p->geom, COLLIST **, 0x14);
            if (l != NULL) {
                g = (COLGEOM *)l->box->geom;
                M2C_FIELD(box->geom, int *, 0) = g->x + g->w;
            } else
                M2C_FIELD(box->geom, int *, 0) = M2C_FIELD(p->geom, int *, 0);
            addBoxList((LIST *)((char *)p->geom + 0x10), box);
            M2C_FIELD(p->geom, int *, 8) += M2C_FIELD(box->geom, int *, 4);
            break;
        }
        if (p->html == 0x55) {
            l = M2C_FIELD(p->geom, COLLIST **, 0x40);
            if (l != NULL) {
                g = (COLGEOM *)l->box->geom;
                if (g->fixed != 0 && g->span > 0)
                    M2C_FIELD(box->geom, int *, 0) = g->x + g->span;
                else
                    M2C_FIELD(box->geom, int *, 0) = g->x + g->w;
            }
            addBoxList((LIST *)((char *)p->geom + 0x3C), box);
            break;
        }
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_COLGROUP(void *node) {
    BOX *table;
    BOX *last;
    BOX *c;
    BOX *box;
    BOX *tbl;
    COLLIST *l;
    COLGEOM *g;

    table = getTableBoxFromDOM(node);
    if (table == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = table->child; c != NULL; c = c->next) {
        last = c;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, table, last);
    box->display = 1;
    box->html = 0x17;
    initColContent(box, node, 1);
    attr_SPAN(node, box);
    attr_ALIGN_trgroup(node, box);
    attr_VALIGN_trgroup(node, box);
    attr_WIDTH_col(node, box);
    tbl = getTableBox(table);
    if (tbl != NULL) {
        l = M2C_FIELD(tbl->geom, COLLIST **, 0x40);
        if (l != NULL) {
            g = (COLGEOM *)l->box->geom;
            if (g->fixed != 0 && g->span > 0)
                M2C_FIELD(box->geom, int *, 0) = g->x + g->span;
            else
                M2C_FIELD(box->geom, int *, 0) = g->x + g->w;
        }
        addBoxList((LIST *)((char *)tbl->geom + 0x3C), box);
    }
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_TBODY(void *node) {
    BOX *table;
    BOX *last;
    BOX *c;
    BOX *box;
    table = getTableBoxFromDOM(node);
    if (table == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = table->child; c != NULL; c = c->next) {
        last = c;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, table, last);
    box->display = 1;
    box->html = 0x56;
    initNoneContent(box, node);
    initBoxProperty(box);
    attr_ALIGN_trgroup(node, box);
    attr_VALIGN_trgroup(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_THEAD(void *node) {
    BOX *table;
    BOX *last;
    BOX *c;
    BOX *box;
    table = getTableBoxFromDOM(node);
    if (table == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = table->child; c != NULL; c = c->next) {
        last = c;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, table, last);
    box->display = 1;
    box->html = 0x5B;
    initNoneContent(box, node);
    initBoxProperty(box);
    attr_ALIGN_trgroup(node, box);
    attr_VALIGN_trgroup(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}

BOX *html_TFOOT(void *node) {
    BOX *table;
    BOX *last;
    BOX *c;
    BOX *box;
    table = getTableBoxFromDOM(node);
    if (table == NULL) {
        return NULL;
    }
    last = NULL;
    for (c = table->child; c != NULL; c = c->next) {
        last = c;
    }
    box = createBox(node, 1);
    if (box == NULL) {
        return NULL;
    }
    linkBoxNoTableCheck(box, table, last);
    box->display = 1;
    box->html = 0x59;
    initNoneContent(box, node);
    initBoxProperty(box);
    attr_ALIGN_trgroup(node, box);
    attr_VALIGN_trgroup(node, box);
    applyCSSExtStyleSheetToBox(node, box);
    applyCSSInlinePropertyToBox(node, box);
    return box;
}
