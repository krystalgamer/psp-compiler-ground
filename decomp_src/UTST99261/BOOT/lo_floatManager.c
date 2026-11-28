/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
typedef struct REGION { u8 unk0[0x10]; struct REGION *next; } REGION;
void *MEM_malloc(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */



#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct FBX { struct FBX *parent; struct FBX *child; struct FBX *prev; struct FBX *next; char pad[0x2A]; short html; } FBX;
FBX *getBodyBox(FBX *b);
void setFocus(FBX *body, FBX *b, int f, int a);
typedef struct LFMRGN { int x; int y; int w; int h; struct LFMRGN *next; struct LFMRGN *prev; } LFMRGN;
typedef struct { u8 pad20[0x20]; s16 mt; s16 mr; s16 unk24; s16 ml; s16 bt; s16 br; s16 unk2C; s16 bl; s16 pt; s16 pr; s16 unk34; s16 pl; } LFMSTYLE;
typedef struct { u8 pad0[0x10]; int x; int y; int w; u8 pad1C[8]; LFMSTYLE *st; } LFMBOX;
typedef struct { LFMBOX *box; int w; int h; LFMRGN *head; LFMRGN *cur; } LFMPAGE;
void *newRegion(int arg0, int arg1, int arg2, int arg3) {
    void *temp_v0;
    void *var_v1;

    temp_v0 = MEM_malloc(0, 0x18);
    var_v1 = NULL;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, int *, 0x10) = 0;
        M2C_FIELD(temp_v0, int *, 0x14) = 0;
        M2C_FIELD(temp_v0, int *, 0) = arg0;
        M2C_FIELD(temp_v0, int *, 4) = arg1;
        M2C_FIELD(temp_v0, int *, 8) = arg2;
        M2C_FIELD(temp_v0, int *, 0xC) = arg3;
        var_v1 = temp_v0;
    }
    return var_v1;
}

void freeRegionList(REGION *r) {
    REGION *next;
    while (r != NULL) {
        next = r->next;
        MEM_free(0, r);
        if (next == r) {
            break;
        }
        r = next;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void insertRegion(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg2, void **, 0x10) = (void *) M2C_FIELD(arg1, void **, 0x10);
    M2C_FIELD(arg2, void **, 0x14) = arg1;
    M2C_FIELD(M2C_FIELD(arg1, void **, 0x10), void **, 0x14) = arg2;
    M2C_FIELD(arg1, void **, 0x10) = arg2;
    if (arg1 == M2C_FIELD(arg0, void **, 0x10)) {
        M2C_FIELD(arg0, void **, 0x10) = arg2;
    }
}

void addRegion(void *mgr, REGION *r) {
    insertRegion(mgr, M2C_FIELD(mgr, void **, 0x10), r);
}

#ifndef NULL
#define NULL ((void *)0)
#endif
void removeRegion(void *arg0, void *arg1) {
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg1, void **, 0x14);
    M2C_FIELD(temp_v1, void **, 0x10) = (void *) M2C_FIELD(arg1, void **, 0x10);
    M2C_FIELD(M2C_FIELD(arg1, void **, 0x10), void **, 0x14) = temp_v1;
    temp_v0 = M2C_FIELD(arg0, void **, 0x10);
    if (temp_v0 == arg1) {
        temp_v0_2 = M2C_FIELD(temp_v0, void **, 0x14);
        if (temp_v0_2 != NULL) {
            M2C_FIELD(arg0, void **, 0x10) = temp_v0_2;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", overlayRegion);

void *lfm_createPageRegion(void *box, int w) {
    void *r;
    void *n;
    void *st;

    r = MEM_malloc(0, 0x14);
    if (r == NULL)
        return NULL;
    M2C_FIELD(r, void **, 0) = box;
    st = M2C_FIELD(box, void **, 0x24);
    M2C_FIELD(r, int *, 4) = w - M2C_FIELD(st, s16 *, 0x26) - M2C_FIELD(st, s16 *, 0x36) - M2C_FIELD(st, s16 *, 0x2E) - M2C_FIELD(st, s16 *, 0x2A) - M2C_FIELD(st, s16 *, 0x32) - M2C_FIELD(st, s16 *, 0x22);
    M2C_FIELD(r, int *, 8) = 0;
    M2C_FIELD(r, void **, 0xC) = MEM_malloc(0, 0x18);
    if (M2C_FIELD(r, void **, 0xC) == NULL) {
        MEM_free(0, r);
        return NULL;
    }
    n = MEM_malloc(0, 0x18);
    if (n == NULL) {
        MEM_free(0, M2C_FIELD(r, void **, 0xC));
        MEM_free(0, r);
        return NULL;
    }
    M2C_FIELD(M2C_FIELD(r, void **, 0xC), void **, 0x10) = n;
    M2C_FIELD(M2C_FIELD(r, void **, 0xC), int *, 0x14) = 0;
    M2C_FIELD(n, void **, 0x10) = n;
    M2C_FIELD(n, void **, 0x14) = M2C_FIELD(r, void **, 0xC);
    M2C_FIELD(r, void **, 0x10) = M2C_FIELD(r, void **, 0xC);
    return r;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void lfm_destroyPageRegion(void *arg0) {
    freeRegionList(M2C_FIELD(arg0, int *, 0xC));
    MEM_free(0, arg0);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void lfm_resetPageRegion(void *arg0, int arg1) {
    void *temp_v0;
    void *temp_v0_2;

    M2C_FIELD(arg0, int *, 4) = arg1;
    M2C_FIELD(arg0, int *, 8) = 0;
    freeRegionList(M2C_FIELD(arg0, void **, 0xC));
    temp_v0 = MEM_malloc(0, 0x18);
    M2C_FIELD(arg0, void **, 0xC) = temp_v0;
    if (temp_v0 != NULL) {
        temp_v0_2 = MEM_malloc(0, 0x18);
        if (temp_v0_2 == NULL) {
            MEM_free(0, M2C_FIELD(arg0, void **, 0xC));
            return;
        }
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), void **, 0x10) = temp_v0_2;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0xC), int *, 0x14) = 0;
        M2C_FIELD(temp_v0_2, void **, 0x10) = temp_v0_2;
        M2C_FIELD(temp_v0_2, void **, 0x14) = (void *) M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(arg0, void **, 0x10) = (void *) M2C_FIELD(arg0, void **, 0xC);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_addFloat);

int lfm_getHorizontalArea(LFMPAGE *pg, LFMBOX *b, int y, int *off, int *wout) {
    int ret = 0;
    int o;
    int w;
    int x, width;
    LFMRGN *r;

    x = b->x + b->st->ml + b->st->pl + b->st->bl - pg->box->x - pg->box->st->ml - pg->box->st->pl - pg->box->st->bl;
    y += (b->y + b->st->mt + b->st->pt + b->st->bt - pg->box->y - pg->box->st->mt - pg->box->st->pt - pg->box->st->bt);
    width = b->w - b->st->ml - b->st->pl - b->st->bl - b->st->br - b->st->pr - b->st->mr;
    o = 0;
    w = width;
    if (y < pg->h) {
        r = pg->head->next;
        w = 0;
        while (r->next != r) {
            if (y >= r->y && y < r->y + r->h)
                break;
            r = r->next;
        }
        w = 0;
        if (r->next != r) {
            if (r->x >= x) {
                o = r->x - x;
                w = (x + width >= r->x + r->w) ? r->w : x + width - r->x;
            } else {
                o = 0;
                w = (x + width < r->x + r->w) ? width : r->w - (x - r->x);
            }
            ret = 1;
        }
    } else {
        ret = 1;
    }
    if (off != NULL)
        *off = o;
    if (wout != NULL)
        *wout = w;
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", lfm_getVerticalPosition);

#ifndef NULL
#define NULL ((void *)0)
#endif
int lfm_getHeight(void *arg0) {
    return M2C_FIELD(arg0, int *, 8);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_floatManager", getNextTerminalFrame);

void setFocusBoxnode(FBX *box, int f) {
    FBX *body;
    FBX *n;
    FBX *c;

    body = getBodyBox(box);
    setFocus(body, box, f, 1);
    if (body == box) {
        return;
    }
    if ((box->html == 0x11) | (box->html == 0x4D)) {
        return;
    }
    n = box->child;
    while ((n != NULL) & (n != box)) {
        setFocus(body, n, f, 0);
        c = n->child;
        if (c == NULL) {
            c = n->next;
            if (c == NULL) {
                n = n->parent;
                while ((n != NULL) & (n != box) && n->next == NULL) {
                    n = n->parent;
                }
                if ((n != NULL) & (n != box)) {
                    c = n->next;
                } else {
                    c = NULL;
                }
            }
        }
        n = c;
    }
}
