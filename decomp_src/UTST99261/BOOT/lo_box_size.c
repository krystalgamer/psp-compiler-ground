/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "m2c_macros.h"
M2C_UNK box_setTableHeight(void *);                 /* extern */


extern int e_icon_image_width;
extern int e_icon_image_height;
unsigned int strlen(const char *);
void getStringsExtents(int font, char *s, int len, int *w, int *h);
int lfm_getHeight(void *region);
void adjustLineHposition(void *ctx, void *line);
int adjustLineVposition(void *ctx, BOX *box, void *line);
void calcInLineBoxSize(void *ctx, BOX *box);
void calcBlockBoxSize(void *ctx, BOX *box, int f);
void calcBlockButtonBoxSize(void *ctx, BOX *box);
void calcTdBoxSize(void *ctx, BOX *box);
void getTextlineExtents(int font, int cols, int *w, int *h);
void GUI_Component_setFont(void *c, int font);
void getButtonExtents(int font, char *s, int len, int *w, int *h);
typedef struct SELOPT { struct SELOPT *next; int x4; char *text; } SELOPT;
void getPulldownExtents(int font, char *s, int n, int *w, int *h);
void getListExtents(int font, char *s, int n, int *w, int *h);
int lineFeedProc(void *ctx, BOX *box);
#define LBS_MIN(a, b) ((a) < (b) ? (a) : (b))
#define LBS_MAX(a, b) ((a) < (b) ? (b) : (a))
void getBaseBlockPosition(void *ctx, int *x, int *y);
BOX *getFixedHeightBox(BOX *box);
void lfm_addFloat(void *page, void *box, int y, int w, int h, int side, int *dx, int *dy);
void moveBoxPosition(BOX *box, int dx, int dy);
void moveBoxPositionChild(BOX *box, int dx, int dy);
void turnupContent(void *ctx, BOX *box);
#define LBS_HTYPE(b) (((b)->style->flags & 0xC) >> 2)
void calcInLineBoxSize(void *ctx, BOX *box)
{
    BOX *b;
    int x0, y0, x1, y1;

    if (box->html == 1) {
        x1 = -1;
        x0 = -1;
        y1 = -1;
        b = box->child;
        y0 = -1;
        if (b != NULL && b->html != 1) {
            do {
                if (x0 == -1) {
                    x0 = b->x;
                    x1 = x0 + b->width;
                    y0 = b->y;
                    y1 = y0 + b->height;
                }
                x0 = LBS_MIN(x0, b->x);
                x1 = LBS_MAX(x1, b->x + b->width);
                y0 = LBS_MIN(y0, b->y);
                y1 = LBS_MAX(y1, b->y + b->height);
                if (b->child != NULL) {
                    b = b->child;
                } else if (b->next != NULL) {
                    b = b->next;
                } else {
                    b = b->parent;
                    while (b != box && b->next == NULL)
                        b = b->parent;
                    if (b == box)
                        break;
                    b = b->next;
                }
            } while (b != NULL && b->html != 1);
        }
        if (y0 != -1) {
            box->x = x0;
            box->y = y0;
            box->width = x1 - x0;
            box->height = y1 - y0;
        }
    } else if (box->content == 0) {
        x1 = -1;
        x0 = -1;
        y1 = -1;
        b = box->child;
        y0 = -1;
        for (; b != NULL; b = b->next) {
            if (x0 == -1) {
                x0 = b->x;
                x1 = x0 + b->width;
                y0 = b->y;
                y1 = y0 + b->height;
            }
            x0 = LBS_MIN(x0, b->x);
            x1 = LBS_MAX(x1, b->x + b->width);
            y0 = LBS_MIN(y0, b->y);
            y1 = LBS_MAX(y1, b->y + b->height);
        }
        if (y0 != -1) {
            box->x = x0;
            box->y = y0;
            box->width = x1 - x0;
            box->height = y1 - y0;
        }
    }
    if (box->next != NULL && box->next->display == 0) {
        int lf = lineFeedProc(ctx, box);
        M2C_FIELD(M2C_FIELD(ctx, void **, 4), int *, 0x34) += lf;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcBlockBoxSize);

void calcBodyBoxSize(void *ctx, BOX *box) {
    int h;

    adjustLineHposition(ctx, M2C_FIELD(ctx, void **, 0xC));
    M2C_FIELD(box, int *, 0x34) += adjustLineVposition(ctx, box, M2C_FIELD(ctx, void **, 0xC));
    h = lfm_getHeight(box->region);
    h = h > M2C_FIELD(box, int *, 0x34) ? h : M2C_FIELD(box, int *, 0x34);
    box->height = h + box->style->unk30 + box->style->unk28 + box->style->unk2C + box->style->unk34;
    if (M2C_FIELD(box->geom, int *, 0x44) == 0) {
        if (M2C_FIELD(box->geom, int *, 0x14) < box->height)
            M2C_FIELD(box->geom, int *, 0x14) = box->height;
    } else {
        box->width = M2C_FIELD(box->geom, int *, 8);
        box->height = M2C_FIELD(box->geom, int *, 0xC);
        M2C_FIELD(box->geom, int *, 0x10) = box->width;
        M2C_FIELD(box->geom, int *, 0x14) = box->height;
    }
}

void calcBlockButtonBoxSize(void *ctx, BOX *box)
{
    int x, y;
    int dx, dy;
    int pad;
    int h;
    BOX *fb;
    int side;
    int ox, oy;
    int nx, ny;
    BOXGEOM *g;

    getBaseBlockPosition(ctx, &x, &y);
    pad = box->style->unk30 + box->style->unk28 + box->style->unk2C + box->style->unk34;
    if (LBS_HTYPE(box) == 1) {
        h = box->style->height - pad;
        if (M2C_FIELD(box, int *, 0x34) < h)
            M2C_FIELD(box, int *, 0x34) = h;
    } else if (LBS_HTYPE(box) == 2) {
        fb = getFixedHeightBox(box);
        if (fb != NULL) {
            int fh = fb->content == 1 ? M2C_FIELD(fb->geom, int *, 0xC) : fb->style->height;
            int h2;
            h = box->style->height;
            h2 = fh * h / 100 - pad;
            if (M2C_FIELD(box, int *, 0x34) < h2)
                M2C_FIELD(box, int *, 0x34) = h2;
        }
    }
    { int m = lfm_getHeight(box->region);
    box->height = (m < M2C_FIELD(box, int *, 0x34) ? M2C_FIELD(box, int *, 0x34) : m) + box->style->unk20 + box->style->unk30 + box->style->unk28 + box->style->unk2C + box->style->unk34 + box->style->unk24; }
    side = M2C_FIELD(box->style, s8 *, 0x71);
    if (side != 0) {
        ox = box->x;
        oy = box->y;
        lfm_addFloat(M2C_FIELD(ctx, void **, 0x10), M2C_FIELD(ctx, void **, 4), oy - y, box->width, box->height, side == 1 ? 1 : 3, &dx, &dy);
        if (x + dx != ox || y + dy != oy) {
            box->x = x + dx;
            box->y = y + dy;
            moveBoxPositionChild(box, box->x - ox, box->y - oy);
        }
    } else if (box->style->unk72 < 2) {
        addBoxList(M2C_FIELD(ctx, LIST **, 0xC), box);
        turnupContent(ctx, box);
    } else {
        getBaseBlockPosition(ctx, &x, &y);
        nx = x + box->style->unk52;
        ny = y + box->style->unk50;
        if (nx != box->x || ny != box->y)
            moveBoxPosition(box, nx - box->x, ny - box->y);
        ny = box->y + box->height;
        g = M2C_FIELD(ctx, BOX **, 0)->geom;
        if (M2C_FIELD(g, int *, 0x14) < ny)
            M2C_FIELD(g, int *, 0x14) = ny;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void calcTableBoxSize(void *arg0, void *arg1) {
    if (!(M2C_FIELD(arg1, unsigned short *, 0x40) & 2)) {
        box_setTableHeight(arg1);
    } else {
        M2C_FIELD(arg1, unsigned short *, 0x40) = (unsigned short) (M2C_FIELD(arg1, unsigned short *, 0x40) & 0xFFFD);
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x34) = (int) (M2C_FIELD(M2C_FIELD(arg0, void **, 4), int *, 0x34) + M2C_FIELD(arg1, int *, 0x1C));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_box_size", calcTdBoxSize);

int getPreferredFontSize(BOX *box) {
    int size = box->style->fontSize;
    int d = ui_global->font - 3;
    if (size + d < 0) {
        size = 0;
    } else if (size + d >= 7) {
        size = 6;
    } else {
        size += d;
    }
    return size;
}

void initTextBoxSize(BOX *box) {
    int size = getPreferredFontSize(box);
    int w, h;
    char *s;

    box->style->unk64 = ui_global->color[box->style->unk6A][size];
    s = *(char **)box->geom;
    getStringsExtents(box->style->unk64, s, strlen(s), &w, &h);
    if (h > 0)
        h += 2;
    setBoxSize(box, w, h);
}

void initImageBoxSize(BOX *box, int width, int height) {
    int size = getPreferredFontSize(box);
    int w, h;

    box->style->unk64 = ui_global->color[box->style->unk6A][size];
    w = width;
    if (width < 0)
        w = e_icon_image_width + 6;
    h = height;
    if (height < 0)
        h = e_icon_image_height + 6;
    box->geom->y = w;
    M2C_FIELD(box->geom, int *, 8) = h;
    setBoxSize(box, w, h);
}

void initButtonBoxSize(BOX *box) {
    int size = getPreferredFontSize(box);
    int w, h;
    char *s;

    box->style->unk64 = ui_global->color[box->style->unk6A][size];
    s = M2C_FIELD(box->geom, char **, 8);
    if (s != NULL) {
        getButtonExtents(box->style->unk64, s, strlen(s), &w, &h);
    } else {
        w = ui_global->unk74 * 2;
        h = ui_global->unk74 * 2;
    }
    if ((box->style->flags & 3) == 1)
        w = box->style->width;
    if (((box->style->flags & 0xC) >> 2) == 1)
        h = box->style->height;
    if (M2C_FIELD(box, void **, 0x2C) != NULL)
        GUI_Component_setFont(M2C_FIELD(box, void **, 0x2C), box->style->unk64);
    setBoxSize(box, w, h);
}

void initCheckBoxSize(BOX *box) {
    int w = ui_global->unk74 * 2;
    int h = w;
    if ((box->style->flags & 3) == 1) {
        w = box->style->width;
    }
    if (((box->style->flags & 0xC) >> 2) == 1) {
        h = box->style->height;
    }
    setBoxSize(box, w, h);
}

void initRadioBoxSize(BOX *box) {
    int w = ui_global->unk74 * 2;
    int h = w;
    if ((box->style->flags & 3) == 1) {
        w = box->style->width;
    }
    if (((box->style->flags & 0xC) >> 2) == 1) {
        h = box->style->height;
    }
    setBoxSize(box, w, h);
}

void initTextFieldBoxSize(BOX *box, int cols) {
    int size = getPreferredFontSize(box);
    int w, h;

    box->style->unk64 = ui_global->color[box->style->unk6A][size];
    if (cols <= 0)
        cols = 10;
    getTextlineExtents(box->style->unk64, cols, &w, &h);
    if ((box->style->flags & 3) == 1)
        w = box->style->width;
    if (((box->style->flags & 0xC) >> 2) == 1)
        h = box->style->height;
    if (M2C_FIELD(box, void **, 0x2C) != NULL)
        GUI_Component_setFont(M2C_FIELD(box, void **, 0x2C), box->style->unk64);
    setBoxSize(box, w, h);
}

void initTextAreaBoxSize(BOX *box, int cols, int rows) {
    int size = getPreferredFontSize(box);
    int w, h;

    box->style->unk64 = ui_global->color[box->style->unk6A][size];
    if (cols <= 0)
        cols = 10;
    if (rows <= 0)
        rows = 2;
    getTextboxExtents(box->style->unk64, rows, cols, &w, &h);
    if ((box->style->flags & 3) == 1)
        w = box->style->width;
    if (((box->style->flags & 0xC) >> 2) == 1)
        h = box->style->height;
    if (M2C_FIELD(box, void **, 0x2C) != NULL)
        GUI_Component_setFont(M2C_FIELD(box, void **, 0x2C), box->style->unk64);
    setBoxSize(box, w, h);
}

void initSelectBoxSize(BOX *box) {
    int size;
    int w = 0;
    int h = 0;
    int ew, eh;
    SELOPT *o;

    size = getPreferredFontSize(box);
    box->style->unk64 = ui_global->color[box->style->unk6A][size];
    for (o = M2C_FIELD(box->geom, SELOPT **, 8); o != NULL && o->text != NULL; o = o->next) {
        if (M2C_FIELD(box->geom, int *, 4) == 1 && M2C_FIELD(box->geom, int *, 0) != 1)
            getPulldownExtents(box->style->unk64, o->text, 1, &ew, &eh);
        else
            getListExtents(box->style->unk64, o->text, M2C_FIELD(box->geom, int *, 4), &ew, &eh);
        w = w > ew ? w : ew;
        h = h > eh ? h : eh;
    }
    if ((box->style->flags & 3) == 1)
        w = box->style->width;
    if (((box->style->flags & 0xC) >> 2) == 1)
        h = box->style->height;
    if (M2C_FIELD(box, void **, 0x2C) != NULL)
        GUI_Component_setFont(M2C_FIELD(box, void **, 0x2C), box->style->unk64);
    setBoxSize(box, w, h);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void setBoxSize(void *arg0, int arg1, int arg2) {
    int temp_a1;
    int temp_a1_2;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;
    int temp_v0_4;
    int temp_v1;
    int temp_v1_2;
    int temp_v1_3;
    int temp_v1_4;
    void *temp_a3;

    M2C_FIELD(arg0, int *, 0x18) = arg1;
    temp_a3 = M2C_FIELD(arg0, void **, 0x24);
    temp_v0 = M2C_FIELD(temp_a3, short *, 0x22) + arg1;
    M2C_FIELD(arg0, int *, 0x18) = temp_v0;
    temp_v1 = M2C_FIELD(temp_a3, short *, 0x26) + temp_v0;
    M2C_FIELD(arg0, int *, 0x18) = temp_v1;
    temp_v0_2 = M2C_FIELD(temp_a3, short *, 0x2A) + temp_v1;
    M2C_FIELD(arg0, int *, 0x18) = temp_v0_2;
    temp_v1_2 = M2C_FIELD(temp_a3, short *, 0x2E) + temp_v0_2;
    M2C_FIELD(arg0, int *, 0x18) = temp_v1_2;
    temp_a1 = M2C_FIELD(temp_a3, short *, 0x32) + temp_v1_2;
    M2C_FIELD(arg0, int *, 0x18) = temp_a1;
    M2C_FIELD(arg0, int *, 0x18) = (int) (M2C_FIELD(temp_a3, short *, 0x36) + temp_a1);
    M2C_FIELD(arg0, int *, 0x1C) = arg2;
    temp_v0_3 = M2C_FIELD(temp_a3, short *, 0x20) + arg2;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v0_3;
    temp_v1_3 = M2C_FIELD(temp_a3, short *, 0x24) + temp_v0_3;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v1_3;
    temp_v0_4 = M2C_FIELD(temp_a3, short *, 0x28) + temp_v1_3;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v0_4;
    temp_v1_4 = M2C_FIELD(temp_a3, short *, 0x2C) + temp_v0_4;
    M2C_FIELD(arg0, int *, 0x1C) = temp_v1_4;
    temp_a1_2 = M2C_FIELD(temp_a3, short *, 0x30) + temp_v1_4;
    M2C_FIELD(arg0, int *, 0x1C) = temp_a1_2;
    M2C_FIELD(arg0, int *, 0x1C) = (int) (M2C_FIELD(temp_a3, short *, 0x34) + temp_a1_2);
}

void calcBoxSize(void *ctx, BOX *box) {
    switch (box->content) {
    case 1:
        calcBodyBoxSize(ctx, box);
        break;
    case 0:
    case 8:
    case 11:
    case 12:
    case 19:
    case 21:
        switch (box->display) {
        case 0:
        case 3:
            calcBlockBoxSize(ctx, box, 0);
            break;
        case 1:
        case 2:
            calcInLineBoxSize(ctx, box);
            break;
        }
        break;
    case 9:
        calcInLineBoxSize(ctx, box);
        break;
    case 17:
        calcBlockButtonBoxSize(ctx, box);
        break;
    case 4:
        calcTableBoxSize(ctx, box);
        break;
    case 6:
        calcTdBoxSize(ctx, box);
        break;
    case 2:
    case 3:
    case 5:
    case 7:
    case 10:
    case 13:
    case 14:
    case 15:
    case 16:
    case 18:
    case 20:
        break;
    }
}
