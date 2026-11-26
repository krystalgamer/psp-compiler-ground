/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct {
    int kind;
    int unk4;
    int unk8;
} RGEOM;

typedef struct {
    u8 unk0[0x64];
    int unk64;
    s16 unk68;
    s16 unk6A;
} RSTYLE;

typedef struct RBOX {
    struct RBOX *parent;
    struct RBOX *child;         /* 0x4 */
    struct RBOX *unk8;
    struct RBOX *next;          /* 0xC */
    u8 unk10[0x10];
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

#define SAVELIST ((SAVEDATA *)D_00584CD8)
typedef struct {
    u8 unk0[0x68];
    int unk68;
    int unk6C;
} RLOGLOBAL;

extern RLOGLOBAL lo_global;
extern void *ui_global;
SAVEDATA *getSessionSaveData(int id);
void MEM_free(int pool, void *p);
int adjustLineVposition();
int getLineHeight(void **);                         /* extern */
extern void *D_00584CD8;
M2C_UNK HST_flushHistoryGarbageList();              /* extern */
void *HST_getHistoryGarbageList();                  /* extern */


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", restoreSpaceText);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", terminateLiBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_body);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_body2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_frameset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", repositionBox_frameborder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutProc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutProcAfter);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutBoxTreeLoop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutBoxTreeLoopBodyOnly);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", resizeTextSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", resizeImageSize);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutAtBody);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", relayoutFramesetByFrameBorderMove);

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
    D_00584CD8 = temp_v0;
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
    D_00584CD8 = NULL;
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_relayout", getSessionSaveData);

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
