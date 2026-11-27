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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", html_TD_inner);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", html_CAPTION);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", html_TABLE);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_html_table", html_TR);

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
