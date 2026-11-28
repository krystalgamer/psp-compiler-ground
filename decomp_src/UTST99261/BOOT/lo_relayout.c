/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct {
    int kind;
    int unk4;
    int unk8;
} RGEOM;

typedef struct {
    u8 unk0[0x20];
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    u8 unk38[0x2C];
    int unk64;
    s16 unk68;
    s16 unk6A;
} RSTYLE;

typedef struct RBOX {
    struct RBOX *parent;
    struct RBOX *child;         /* 0x4 */
    struct RBOX *unk8;
    struct RBOX *next;          /* 0xC */
    int x;                      /* 0x10 */
    int y;                      /* 0x14 */
    int unk18;
    int unk1C;
    RGEOM *geom;                /* 0x20 */
    RSTYLE *style;              /* 0x24 */
    u8 unk28[0x8];
    void *region;               /* 0x30 */
    u8 unk34[0x4];
    s16 content;                /* 0x38 */
    s16 html;                   /* 0x3A */
    s16 display;                /* 0x3C */
    s16 unk3E;
    u16 flags40;                /* 0x40 */
} RBOX;

typedef struct {
    char *str;
    int unk4;
    int unk8;
    int len;                    /* 0xC */
    u8 unk10;
    s8 merge;                   /* 0x11 */
    s8 space;                   /* 0x12 */
} RTEXT;

typedef struct {
    u8 unk0[0x10];
    int x;                      /* 0x10 */
    int y;
    u8 unk18[0x7C];
    int w;                      /* 0x94 */
    int h;
} RFRAME;

#define FG(b) ((int *)(b)->geom)
int getFramesetBox();
void getFrameSizeFromFramesetBox();
RBOX *getMyRowFrameBorder();
RBOX *getMyColFrameBorder();
void setFrameSizeToFramesetBox();
void initFrameSize();
void reinitFrameSize();

#define TXT(b) ((RTEXT *)(b)->geom)
#define FRM(b) ((RFRAME *)(b)->geom)

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    void *lines;                /* 0xC */
} LOCTX;

typedef struct {
    RBOX *a;
    RBOX *b;
    RBOX *c;
    void *d;
    void *e;
    s16 f;
    s16 g;
} RLCTX;

typedef struct SAVEDATA { /* size 0x1C */
    int id;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    struct SAVEDATA *next;      /* 0x18 */
} SAVEDATA;

#define SAVELIST ((SAVEDATA *)(*(void * *)((char *)&lo_global + 0x40)))
typedef struct {
    u8 unk0[0x64];
    int unk64;
    int unk68;
    int unk6C;
} RLOGLOBAL;

extern RLOGLOBAL lo_global;
void relayoutProc(RLCTX *ctx, RBOX *b);
void relayoutProcAfter(RLCTX *ctx, RBOX *b);
void integrateTextBox(RBOX *a, RBOX *b);
void initTextBoxSize(RBOX *b);
int restoreSpaceText(RBOX *box);
extern void *ui_global;
SAVEDATA *getSessionSaveData(int id);
void MEM_free(int pool, void *p);
int adjustLineVposition();
int getLineHeight(void **);                         /* extern */
void HST_flushHistoryGarbageList();              /* extern */
void *HST_getHistoryGarbageList();                  /* extern */


int getPreferredFontSize();
void setBoxSize(RBOX *b, int w, int h);
typedef struct UIFTBL { int v[1][7]; } UIFTBL;
#define UIG(o) (((int *)ui_global)[(o) / 4])
void *MEM_malloc(void *, unsigned int size);
void *memcpy(void *, const void *, unsigned int);
void adjustLineHposition(void *ctx, void *line);
void updateLiFirstLineList(void *arg0);
void initBoxList(void *);
void initLinePosition(void *);
void lfm_resetPageRegion(void *arg0, int arg1);
void *getBodyBox(void *);
void initButtonBoxSize(void *);
void initTextAreaBoxSize(void *, int cols, int rows);
void initTextFieldBoxSize(void *, int cols);
void initSelectBoxSize(void *);
void *getBoxByHTML(void *, int html);
void copyBoxList(void *, void *);
int confirmScrollInfo(void *ev);
void actClearForm(void *f);
int restoreSpaceText(RBOX *box) {
    char *old;
    char *p;

    old = TXT(box)->str;
    p = MEM_malloc(0, TXT(box)->len + 2);
    if (p == NULL) {
        return 0;
    }
    p[0] = ' ';
    memcpy(p + 1, old, TXT(box)->len);
    p[TXT(box)->len + 1] = 0;
    MEM_free(0, old);
    TXT(box)->str = p;
    TXT(box)->len++;
    TXT(box)->space = 0;
    return 1;
}

int terminateBlockBox(LOCTX *ctx, RBOX *box) {
    int r;

    if (box->html == 0x2C) {
        return 0;
    }
    adjustLineHposition(ctx, ctx->lines);
    r = adjustLineVposition(ctx, ctx->unk4, ctx->lines);
    if (box->display == 0) {
        updateLiFirstLineList(ctx);
    }
    initBoxList(ctx->lines);
    initLinePosition(box);
    return r;
}

typedef struct RLNODE {
    struct RLNODE *next;
    struct RLNODE *prev;
    RBOX *box;
} RLNODE;

typedef struct {
    RLNODE *head;
} RLLIST;

typedef struct {
    int kind;
    RLLIST lines;
} RLIGEOM;

int getListBox();
int GUI_Graphics_getStringSize(int font, char *s, int len, int *w, int *h);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", terminateLiBox);

int GUI_ScrollPane_isVScrollbarVisible();
int GUI_ScrollPane_getVScrollbarWidth();

void repositionBox_body(RBOX *b, int mode) {
    RBOX *br;
    int fs;
    int idx;
    int x;
    int y;
    int fw;
    int fh;
    int sb;

    if (b->content != 1) {
        return;
    }
    *(int *)b->unk34 = 0;
    b->flags40 &= ~1;
    FG(b)[0x8C / 4] = 0;
    if (GUI_ScrollPane_isVScrollbarVisible(((int *)b)[0xB]) > 0) {
        sb = GUI_ScrollPane_getVScrollbarWidth(((int *)b)[0xB]);
    } else {
        sb = 0;
    }
    sb = sb > 0 ? sb : 0;
    if (b->parent == NULL) {
        FG(b)[2] = ((int *)ui_global)[0x88 / 4];
        FG(b)[3] = ((int *)ui_global)[0x8C / 4];
        FG(b)[4] = FG(b)[2];
        FG(b)[5] = FG(b)[3];
        b->unk18 = FG(b)[2];
    } else {
        fs = getFramesetBox(b->parent);
        if (fs == 0) {
            return;
        }
        idx = FG(b)[9];
        if (mode == 0) {
            getFrameSizeFromFramesetBox(&x, &y, &fw, &fh, fs, idx);
            br = getMyRowFrameBorder(b);
            if (br != NULL) {
                br->y = fh - br->unk1C;
            }
            br = getMyColFrameBorder(b);
            if (br != NULL) {
                br->x = fw - br->unk18;
            }
            FG(b)[0] = fw;
            FG(b)[1] = fh;
            FG(b)[2] = x;
            FG(b)[3] = y;
            FG(b)[4] = FG(b)[2] - sb;
            FG(b)[5] = FG(b)[3];
            b->unk18 = FG(b)[2] - sb;
        } else {
            x = FG(b)[2];
            y = FG(b)[3];
            br = getMyRowFrameBorder(b);
            if (br != NULL) {
                y += br->unk1C;
            }
            br = getMyColFrameBorder(b);
            if (br != NULL) {
                x += br->unk18;
            }
            setFrameSizeToFramesetBox(x, y, fs, idx);
        }
    }
    if (b->region != NULL) {
        lfm_resetPageRegion(b->region, b->unk18 - b->style->unk26 - b->style->unk36 - b->style->unk2E - b->style->unk2A - b->style->unk32 - b->style->unk22);
    }
    initBoxList(&FG(b)[0x90 / 4]);
}

void lfm_resetPageRegion();
void initBoxList();

void repositionBox_body2(RBOX *b, int mode, int w, int h) {
    RBOX *br;
    int fs;
    int idx;
    int x;
    int y;
    int fw;
    int fh;

    if (b->content != 1) {
        return;
    }
    *(int *)b->unk34 = 0;
    b->flags40 &= ~1;
    FG(b)[0x8C / 4] = 0;
    if (b->parent == NULL) {
        FG(b)[2] = w;
        FG(b)[3] = h;
        FG(b)[4] = w;
        FG(b)[5] = h;
        b->unk18 = FG(b)[2];
    } else {
        fs = getFramesetBox(b->parent);
        if (fs == 0) {
            return;
        }
        idx = FG(b)[9];
        if (mode == 0) {
            getFrameSizeFromFramesetBox(&x, &y, &fw, &fh, fs, idx);
            br = getMyRowFrameBorder(b);
            if (br != NULL) {
                br->y = fh - br->unk1C;
            }
            br = getMyColFrameBorder(b);
            if (br != NULL) {
                br->x = fw - br->unk18;
            }
            FG(b)[0] = fw;
            FG(b)[1] = fh;
            FG(b)[2] = x;
            FG(b)[3] = y;
            b->unk18 = FG(b)[2];
        } else {
            x = FG(b)[2];
            y = FG(b)[3];
            br = getMyRowFrameBorder(b);
            if (br != NULL) {
                y += br->unk1C;
            }
            br = getMyColFrameBorder(b);
            if (br != NULL) {
                x += br->unk18;
            }
            setFrameSizeToFramesetBox(x, y, fs, idx);
        }
    }
    if (b->region != NULL) {
        lfm_resetPageRegion(b->region, FG(b)[2] - b->style->unk26 - b->style->unk36 - b->style->unk2E - b->style->unk2A - b->style->unk32 - b->style->unk22);
    }
    initBoxList(&FG(b)[0x90 / 4]);
}

void repositionBox_frameset(RBOX *b, int mode) {
    RBOX *parent;
    RBOX *br;
    RBOX *body;
    int fs;
    int idx;
    int x;
    int y;
    int w;
    int h;

    if (b->content != 2) {
        return;
    }
    parent = b->parent;
    if (parent->content == b->content) {
        fs = getFramesetBox(parent);
        if (fs == 0) {
            return;
        }
        idx = FG(b)[0xA8 / 4];
        getFrameSizeFromFramesetBox(&x, &y, &w, &h, fs, idx);
        br = getMyRowFrameBorder(b);
        if (br != NULL) {
            br->y = h - br->unk1C;
        }
        br = getMyColFrameBorder(b);
        if (br != NULL) {
            br->x = w - br->unk18;
        }
        FG(b)[0x8C / 4] = w;
        FG(b)[0x90 / 4] = h;
        FG(b)[0x94 / 4] = x;
        FG(b)[0x98 / 4] = y;
        setFrameSizeToFramesetBox(x, y, parent, idx);
    } else {
        body = (RBOX *)getBodyBox(b);
        FG(b)[0x94 / 4] = FG(body)[2];
        FG(b)[0x98 / 4] = FG(body)[3];
    }
    getBodyBox(b);
    if (mode != 1) {
        initFrameSize(b, FG(b)[0xB0 / 4], FG(b)[0xB4 / 4]);
    } else {
        reinitFrameSize(b, FG(b)[0xB0 / 4], FG(b)[0xB4 / 4]);
    }
}

void repositionBox_frameborder(b)
RBOX *b;
{
    RBOX *fs;
    RBOX *nx;
    RBOX *pv;
    int idx;
    int cols;
    int rows;
    int m;
    int q;

    fs = (RBOX *)getFramesetBox(b);
    if (fs == NULL)
        return;
    nx = b;
    for (;;) {
        if (nx == NULL)
            break;
        if (nx->content == 1)
            break;
        if (nx->content == 2)
            break;
        nx = nx->next;
    }
    if (nx == NULL)
        return;
    if (nx->content == 1)
        idx = FG(nx)[0x24 / 4];
    else
        idx = FG(nx)[0xA8 / 4];
    pv = b;
    for (;;) {
        if (pv == NULL)
            break;
        if (pv->content == 1)
            break;
        if (pv->content == 2)
            break;
        pv = pv->unk8;
    }
    if (pv == NULL)
        return;
    cols = FG(fs)[0x88 / 4];
    rows = FG(fs)[0x44 / 4];
    if (cols >= 2) {
        q = idx / cols;
        m = idx % cols;
        if (rows >= 2) {
            if (q != 0) {
                if (m == 0)
                    b->unk18 = FG(fs)[0x94 / 4];
            } else if (m != 0) {
                b->unk1C = FG(fs)[0x98 / 4];
            }
        } else if (idx != 0) {
            b->unk1C = FG(fs)[0x98 / 4];
            b->y = FG(fs)[0x90 / 4];
            switch (pv->content) {
            case 1:
                b->x = FG(pv)[0] + FG(pv)[2];
                break;
            case 2:
                b->x = FG(pv)[0x8C / 4] + FG(pv)[0x94 / 4];
                break;
            }
        }
    } else if (rows != 0) {
        if (idx != 0) {
            b->unk18 = FG(fs)[0x94 / 4];
            b->x = FG(fs)[0x8C / 4];
            switch (pv->content) {
            case 1:
                b->y = FG(pv)[1] + FG(pv)[3];
                break;
            case 2:
                b->y = FG(pv)[0x90 / 4] + FG(pv)[0x98 / 4];
                break;
            }
        }
    }
}

void resizeTextSize(RBOX *box);
void resizeImageSize(RBOX *box);
void resizeButtonSize(RBOX *box);
void resizeTextFieldSize(RBOX *box);
void resizeSelectSize(RBOX *box);
void calcBoxPosition(RLCTX *ctx, RBOX *b);

void relayoutProc(RLCTX *ctx, RBOX *b) {
    switch (b->content) {
    case 0:
        if (b->html == 0x45) {
            break;
        }
        goto calc;
    case 1:
        ctx->a = b;
        ctx->b = b;
        ctx->c = b;
        ctx->d = (char *)b->geom + 0x90;
        ctx->e = b->region;
        repositionBox_body(b, 0);
        break;
    case 2:
        repositionBox_frameset(b, 0);
        break;
    case 3:
        repositionBox_frameborder(b);
        break;
    case 9:
        if (TXT(b)->merge == 1) {
            break;
        }
        if (b->html == 0x66) {
            goto list;
        }
        resizeTextSize(b);
        goto calc;
    case 10:
        if (b->html == 0x66) {
        list:
            if (getListBox(b) != 0) {
                break;
            }
            goto calc;
        }
        resizeImageSize(b);
        goto calc;
    case 13:
        resizeTextFieldSize(b);
        goto calc;
    case 16:
        resizeButtonSize(b);
        goto calc;
    case 18:
        resizeSelectSize(b);
    default:
    calc:
        calcBoxPosition(ctx, b);
        break;
    }
    if (b->content == 0x11) {
        ctx->c = b;
        ctx->d = (char *)b->geom + 4;
        ctx->e = b->region;
    }
    if (b->display == 0 || b->display == 3) {
        ctx->b = b;
    }
    if (b->region != NULL) {
        ctx->e = b->region;
    }
}

void *getPageRegion(RBOX *b);
RBOX *getParentBlockBox(RBOX *b);
void *getCurrentLineBox(RBOX *b);
void *getCurrentLineCB(RBOX *b);
void calcBoxSize(RLCTX *ctx, RBOX *b);

void relayoutProcAfter(RLCTX *ctx, RBOX *b) {
    RBOX *body;
    RBOX *p;
    RBOX *q;

    if (b->content != 1 && b->region != NULL) {
        ctx->e = getPageRegion(b->parent);
    }
    if (b->display == 0 || b->display == 3) {
        *(int *)b->unk34 += terminateBlockBox((LOCTX *)ctx, b);
    }
    if (b->content == 0x15) {
        terminateLiBox(b);
    }
    if (b->display == 0 || b->display == 3) {
        ctx->b = getParentBlockBox(b);
    }
    switch (b->content) {
    case 1:
        body = (RBOX *)getBodyBox(b->parent);
        ctx->a = body;
        if (body != NULL) {
            ctx->b = body;
            ctx->c = body;
            ctx->d = (char *)body->geom + 0x90;
            ctx->e = body->region;
        }
        if (b->unk18 < FG(b)[4]) {
            b->unk18 = FG(b)[4];
        }
        if (b->unk1C < FG(b)[5]) {
            b->unk1C = FG(b)[5];
        }
        break;
    case 0x11:
        ctx->c = getCurrentLineBox(b->parent);
        ctx->d = getCurrentLineCB(b->parent);
        break;
    }
    calcBoxSize(ctx, b);
    if (b->content == 1) {
        return;
    }
    if (b->content == 0 && b->display == 1) {
        return;
    }
    if (b->x + b->unk18 > FG(ctx->a)[4]) {
        for (q = b->parent; q != NULL && q->content != 1; q = q->parent) {
            if (q->html == 0x11 || q->html == 0x3C) {
                return;
            }
        }
        p = ctx->a;
        FG(p)[4] = b->x + b->unk18 + p->style->unk2A + p->style->unk32 + p->style->unk22;
    }
}

void relayoutProcBodyOnly(RBOX *box, int flag) {
    switch (box->content) {
    case 1:
        repositionBox_body(box, flag);
        break;
    case 2:
        repositionBox_frameset(box, 0);
        break;
    case 3:
        repositionBox_frameborder(box, flag);
        break;
    }
}

void relayoutBoxTreeLoop(RLCTX *ctx, RBOX *root) {
    RBOX *b;

    (*(int *)((char *)&lo_global + 0x64)) = 0;
    b = root->child;
    if (b != NULL && b != root)
    do {
        relayoutProc(ctx, b);
        if (lo_global.unk64 != 0) {
            lo_global.unk64 = 0;
        } else if (b->child != NULL) {
            b = b->child;
            continue;
        }
        if (b->next != NULL) {
            relayoutProcAfter(ctx, b);
            b = b->next;
            continue;
        }
        relayoutProcAfter(ctx, b);
        b = b->parent;
        while (b != NULL && b != root) {
            relayoutProcAfter(ctx, b);
            if (b->next != NULL) {
                b = b->next;
                break;
            }
            b = b->parent;
        }
    } while (b != NULL && b != root);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutBoxTreeLoopBodyOnly);

void resizeTextSize(RBOX *box) {
    int changed;
    RBOX *n;
    RBOX *next;

    changed = 0;
    if (TXT(box)->space != 0) {
        if (restoreSpaceText(box)) {
            changed = 1;
        }
    }
    n = box->next;
    while (n != NULL && n->content == 9 && TXT(n)->merge == 1) {
        changed = 1;
        next = n->next;
        integrateTextBox(box, n);
        box->next = next;
        n = next;
    }
    if (changed || lo_global.unk68 != lo_global.unk6C) {
        initTextBoxSize(box);
    }
    TXT(box)->merge = 0;
}

void resizeImageSize(RBOX *box) {
    int size;
    int w;
    int h;

    if (lo_global.unk68 != lo_global.unk6C) {
        size = getPreferredFontSize();
        box->style->unk64 = ((UIFTBL *)ui_global)->v[box->style->unk6A][size];
    }
    w = box->geom->unk4;
    h = box->geom->unk8;
    setBoxSize(box, w, h);
    box->flags40 &= ~4;
}

void resizeButtonSize(RBOX *box) {
    if (lo_global.unk68 != lo_global.unk6C) {
        initButtonBoxSize(box);
    }
}

void resizeTextFieldSize(RBOX *box) {
    RGEOM *g;

    if (lo_global.unk68 != lo_global.unk6C) {
        g = box->geom;
        if (g->kind == 1) {
            initTextAreaBoxSize(box, g->unk4, g->unk8);
        } else {
            initTextFieldBoxSize(box, box->geom->unk4);
        }
    }
}

void resizeSelectSize(RBOX *box) {
    if (lo_global.unk68 != lo_global.unk6C) {
        initSelectBoxSize(box);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void updateLiFirstLineList(void *arg0) {
    int *temp_v0;

    temp_v0 = getBoxByHTML(M2C_FIELD(arg0, int **, 4), 0x38);
    if (temp_v0 != NULL) {
        if ((M2C_FIELD(M2C_FIELD(temp_v0, void **, 0x20), int *, 4) == 0) && (getLineHeight(M2C_FIELD(arg0, void ***, 0xC)) > 0)) {
            copyBoxList((int) (M2C_FIELD(temp_v0, void **, 0x20) + 4), M2C_FIELD(arg0, void ***, 0xC));
        }
    }
}

void relayoutAtBody(RBOX *box, int mode)
{
    RLCTX ctx;
    int redo;
    int over;
    int bw;
    int h;
    int w;
    int sb;

    redo = 0;
    over = 0;
    if (box == NULL || box->content != 1)
        return;
    ctx.a = box;
    ctx.b = box;
    ctx.c = box;
    ctx.d = (u8 *)box->geom + 0x90;
    ctx.e = box->region;
    ctx.f = 0;
    ctx.g = mode;
    bw = FG(box)[0x10 / 4];
    h = box->unk1C;
    w = UIG(0x88);
    sb = 0;
    if ((*(int *)((char *)&lo_global + 0x54)) == 0) {
        sb = GUI_ScrollPane_getVScrollbarWidth(((int *)box)[0xB]);
        if (FG(box)[2] < bw) {
            if (FG(box)[3] - sb < h)
                over = 1;
        } else {
            if (FG(box)[3] < h)
                over = 1;
        }
        if (over == 1 && UIG(0x88) <= FG(box)[2] && UIG(0x8C) <= FG(box)[3])
            w -= sb;
    }
    repositionBox_body2(box, 1, w, UIG(0x8C));
    relayoutBoxTreeLoop(&ctx, box);
    calcBoxSize(&ctx, box);
    if (box->flags40 & 1)
        redo = 1;
    if ((*(int *)((char *)&lo_global + 0x54)) == 0 && w == UIG(0x88)) {
        if (w < FG(box)[0x10 / 4]) {
            if (UIG(0x8C) - sb < box->unk1C)
                redo = 1;
        } else {
            if (box->unk1C > UIG(0x8C))
                redo = 1;
        }
    }
    if (redo == 1) {
        ctx.a = box;
        ctx.b = box;
        ctx.c = box;
        ctx.d = (u8 *)box->geom + 0x90;
        ctx.e = box->region;
        ctx.f = 0;
        ctx.g = 0;
        repositionBox_body2(box, 1, box->unk18 - sb, UIG(0x8C));
        relayoutBoxTreeLoop(&ctx, box);
        calcBoxSize(&ctx, box);
    }
    if (box->parent == NULL)
        FG(box)[2] = UIG(0x88);
    if (box->unk18 < FG(box)[0x10 / 4])
        box->unk18 = FG(box)[0x10 / 4];
    if (box->unk1C < FG(box)[0x14 / 4])
        box->unk1C = FG(box)[0x14 / 4];
    confirmScrollInfo(FG(box)[0x38 / 4]);
}

void relayoutAtBodyOnly(RBOX *box) {
    RLCTX ctx;

    if (box != NULL && box->content == 1) {
        ctx.a = box;
        ctx.b = box;
        ctx.c = box;
        ctx.d = (u8 *)box->geom + 0x90;
        ctx.e = box->region;
        ctx.f = 0;
        relayoutBoxTreeLoopBodyOnly(&ctx, box);
        calcBoxSize(&ctx, box);
    }
}

void relayoutByFrameBorderMove(RBOX *box) {
    RLCTX ctx;

    if (box != NULL && box->content == 1) {
        ctx.a = box;
        ctx.b = box;
        ctx.c = box;
        ctx.d = (u8 *)box->geom + 0x90;
        ctx.e = box->region;
        ctx.f = 0;
        repositionBox_body(box, 0);
        relayoutBoxTreeLoop(&ctx, box);
        calcBoxSize(&ctx, box);
    }
}

void relayoutFramesetByFrameBorderMove(RBOX *box) {
    RLCTX ctx;
    RBOX *body;

    if (box != NULL && box->content == 2) {
        body = (RBOX *)getBodyBox(box);
        ctx.a = body;
        ctx.b = body;
        ctx.c = body;
        ctx.d = (u8 *)body->geom + 0x90;
        ctx.e = body->region;
        ctx.f = 0;
        body->unk18 = FRM(box)->w;
        body->unk1C = FRM(box)->h;
        FRM(body)->x = FRM(box)->w;
        FRM(body)->y = FRM(box)->h;
        repositionBox_frameset(box, 1);
        relayoutBoxTreeLoop(&ctx, box);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void initSessionSaveDataList(void) {
    void *temp_v0;

    temp_v0 = MEM_malloc(0, 0x1C);
    M2C_FIELD(temp_v0, int *, 0) = 0;
    M2C_FIELD(temp_v0, int *, 4) = 0;
    M2C_FIELD(temp_v0, int *, 8) = 0;
    M2C_FIELD(temp_v0, int *, 0xC) = 0;
    M2C_FIELD(temp_v0, int *, 0x10) = 0;
    M2C_FIELD(temp_v0, int *, 0x14) = 0;
    M2C_FIELD(temp_v0, int *, 0x18) = 0;
    (*(void * *)((char *)&lo_global + 0x40)) = temp_v0;
}

void freeSessionSaveDataList(void) {
    SAVEDATA *p;
    SAVEDATA *next;

    for (p = SAVELIST; p != NULL; p = p->next) {
        actClearForm(p->id);
    }
    for (p = SAVELIST; p != NULL; p = next) {
        next = p->next;
        MEM_free(0, p);
    }
    (*(void * *)((char *)&lo_global + 0x40)) = NULL;
}

SAVEDATA *addSessionSaveData(int id) {
    SAVEDATA *p;
    SAVEDATA *q;

    p = getSessionSaveData(id);
    if (p != NULL) {
        return p;
    }
    p = (SAVEDATA *)MEM_malloc(0, sizeof(SAVEDATA));
    p->unk4 = 0;
    p->unk8 = 0;
    p->unkC = 0;
    p->unk10 = 0;
    p->unk14 = 0;
    p->next = NULL;
    p->id = id;
    for (q = SAVELIST; q->next != NULL; q = q->next)
        ;
    q->next = p;
    return p;
}

void removeSessionSaveData(int id) {
    SAVEDATA *prev;
    SAVEDATA *p;

    actClearForm(id);
    prev = SAVELIST;
    for (p = prev->next; p != NULL; p = p->next) {
        if (p->id == id) {
            prev->next = p->next;
            MEM_free(0, p);
            return;
        }
        prev = p;
    }
}

SAVEDATA *getSessionSaveData(int id) {
    SAVEDATA *p;

    for (p = SAVELIST->next; p != NULL; p = p->next) {
        if (p->id == id) {
            return p;
        }
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void collectSessionGarbage(int arg0) {
    int temp_a0;
    void *temp_v0;
    void *var_s0;

    temp_v0 = HST_getHistoryGarbageList();
    var_s0 = temp_v0;
    if (temp_v0 != NULL) {
        do {
            temp_a0 = M2C_FIELD(var_s0, int *, 0);
            if (arg0 != temp_a0) {
                removeSessionSaveData(temp_a0);
            }
            var_s0 = M2C_FIELD(var_s0, void **, 4);
        } while (var_s0 != NULL);
    }
    HST_flushHistoryGarbageList();
}
