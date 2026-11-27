/* cflags: -O1 */
#include "common.h"
#include "dom_domi.h"
#include "lo_box.h"
#include "m2c_macros.h"
#include "lo_focus.h"
extern unsigned char _DOMname;
int Element_hasAttribute(void *node, void *name);
void Element_getAttribute(DOMString *s, void *node, void *name);
int DOMStringlen(DOMString *s);
char *DOMStringtoUTF8(DOMString *s);
int strcasecmp(const char *a, const char *b);
BOX *lo_getActiveFrameBodybox(void *ctx);
void *MEM_malloc(int pool, unsigned int size);
void *lo_getFocusNavi(void *node);
FOCUSLIST *getNext2DFocusLeft(void *frame, FOCUSLIST *list, FOCUSLIST *cur);
FOCUSLIST *getNext2DFocusRight(void *frame, FOCUSLIST *list, FOCUSLIST *cur);
FOCUSLIST *getNextNaviFocus(void *frame, FOCUSLIST *l, FOCUSLIST *cur, char *name);
void scrollToCurrent2DFocusPosition(void *frame, FOCUSLIST *l);
FOCUSLIST *scrollToNextPosition(void *frame, void *a1, FOCUSLIST *l, int dir);
FOCUSLIST *getNext2DFocusDown(void *frame, FOCUSLIST *list, FOCUSLIST *cur, BOX *obj);
FOCUSLIST *getNext2DFocusUp(void *frame, FOCUSLIST *list, FOCUSLIST *cur, BOX *obj);
void *getBodyBox(void *box);
void drawObject(BOX *box);
int checkBoxValidity(void *box);
extern void *gESPRIT_LO_GLOBAL_NDA;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
extern void *ui_global;



#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct STRWORD { char *start; char *end; } STRWORD;
STRWORD UTL_strword(char *s, char *delim, char *stop);
extern DOMString _DOMfocusnavi;
void *MEM_calloc(int pool, unsigned int size);
void *memcpy(void *d, const void *s, unsigned int n);
double pow(double, double);
double sqrt(double);
extern const double D_001390F8;
extern const double D_00139100;
extern const double D_00139108;
extern const double D_00139110;
extern const double D_00139118;
extern const double D_00139120;
extern const double D_00139128;
extern const double D_00139130;
void freeAllList(void *arg0) {
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_a1_5;
    void *temp_a1_6;
    void *temp_s1;
    void *var_s0;

    var_s0 = arg0;
    if (arg0 != NULL) {
        do {
            temp_a1 = M2C_FIELD(var_s0, void **, 0x14);
            temp_s1 = M2C_FIELD(var_s0, void **, 4);
            if (temp_a1 != NULL) {
                MEM_free(0, temp_a1);
            }
            temp_a1_2 = M2C_FIELD(var_s0, void **, 0x18);
            if (temp_a1_2 != NULL) {
                temp_a1_3 = M2C_FIELD(temp_a1_2, void **, 0);
                if (temp_a1_3 != NULL) {
                    MEM_free(0, temp_a1_3);
                }
                temp_a1_4 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0x18), void **, 4);
                if (temp_a1_4 != NULL) {
                    MEM_free(0, temp_a1_4);
                }
                temp_a1_5 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0x18), void **, 8);
                if (temp_a1_5 != NULL) {
                    MEM_free(0, temp_a1_5);
                }
                temp_a1_6 = M2C_FIELD(M2C_FIELD(var_s0, void **, 0x18), void **, 0xC);
                if (temp_a1_6 != NULL) {
                    MEM_free(0, temp_a1_6);
                }
                MEM_free(0, M2C_FIELD(var_s0, void **, 0x18));
            }
            MEM_free(0, var_s0);
            var_s0 = temp_s1;
        } while (temp_s1 != NULL);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", addFocusList);

FOCUSLIST *appendFocusList(void *frame, s8 type, void *obj, FOCUSLIST *after, FOCUSAREA *area) {
    FOCUSLIST *f;
    void *navi;
    f = MEM_malloc(0, 0x1C);
    if (f == NULL) {
        return NULL;
    }
    f->type = type;
    f->obj = obj;
    f->tabindex = 0;
    f->area = area;
    navi = NULL;
    if (obj != NULL) {
        navi = lo_getFocusNavi(M2C_FIELD(obj, void **, 0x28));
    }
    f->x18 = navi;
    if (after == NULL) {
        if (FFRAME(frame)->head != NULL) {
            f->prev = NULL;
            f->next = FFRAME(frame)->head;
            FFRAME(frame)->head->prev = f;
            FFRAME(frame)->head = f;
        } else {
            f->next = NULL;
            f->prev = NULL;
            FFRAME(frame)->head = f;
            FFRAME(frame)->tail = f;
            FFRAME(frame)->cur = f;
        }
    } else if (after->next != NULL) {
        f->next = after->next;
        f->prev = after;
        after->next->prev = f;
        after->next = f;
    } else {
        f->next = NULL;
        f->prev = after;
        after->next = f;
        FFRAME(frame)->tail = f;
    }
    return f;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void removeAllFocusList(void *frame) {
    if (FFRAME(frame)->head != NULL) {
        freeAllList(FFRAME(frame)->head);
    }
    FFRAME(frame)->head = NULL;
    FFRAME(frame)->tail = NULL;
}

FOCUSLIST *getFocusListHead(void *frame) {
    FOCUSLIST *l = NULL;
    if (frame != NULL) {
        l = FFRAME(frame)->head;
    }
    return l;
}

FOCUSLIST *getFocusListTail(void *frame) {
    FOCUSLIST *l = NULL;
    if (frame != NULL) {
        l = FFRAME(frame)->tail;
    }
    return l;
}

FOCUSLIST *getFocusList(void *frame, void *obj) {
    FOCUSLIST *l;
    for (l = FFRAME(frame)->head; l != NULL; l = l->next) {
        if (l->obj == obj && l->type == 0) {
            break;
        }
    }
    return l;
}

FOCUSLIST *getFocusListFromIndex(void *frame, int index) {
    FOCUSLIST *l = FFRAME(frame)->head;
    int i;
    for (i = 0; l != NULL; i++) {
        if (index == i) {
            return l;
        }
        l = l->next;
    }
    return l;
}

FOCUSLIST *getFocusListWithArea(void *frame, void *obj, void *link) {
    FOCUSLIST *l;
    for (l = FFRAME(frame)->head; l != NULL; l = l->next) {
        if (l->obj == obj && l->type == 1 && l->area->link == link) {
            break;
        }
    }
    return l;
}

int getCurrentFocusIndex(void *frame) {
    FOCUSLIST *l;
    int i = 0;
    if (FFRAME(frame)->cur == NULL) {
        return -1;
    }
    for (l = FFRAME(frame)->head; l != NULL; l = l->next) {
        if (l == FFRAME(frame)->cur) {
            return i;
        }
        i++;
    }
    return -1;
}

void getFocusRegionInfo(FOCUSLIST *f, int *x, int *y, int *w, int *h) {
    int bx = M2C_FIELD(f->obj, int *, 0x10);
    int by = M2C_FIELD(f->obj, int *, 0x14);
    int bw, bh;
    if (f->type == 1) {
        bx += f->area->x;
        by += f->area->y;
        bw = f->area->w;
        bh = f->area->h;
    } else {
        bw = M2C_FIELD(f->obj, int *, 0x18);
        bh = M2C_FIELD(f->obj, int *, 0x1C);
    }
    *x = bx;
    *y = by;
    *w = bw;
    *h = bh;
}

int scrollToFocusPosition(void *ctx) {
    BOX *frame;
    BOX *b;
    int vx, vy, vw, vh;
    int dx, dy;
    frame = lo_getActiveFrameBodybox(ctx);
    if (frame == NULL) {
        return 0;
    }
    if (FFRAME(frame)->cur == NULL) {
        return 0;
    }
    b = FFRAME(frame)->cur->obj;
    if (frame == b) {
        return 0;
    }
    getViewPort(frame, &vx, &vy);
    getViewClientSize(frame, &vw, &vh);
    dy = 0;
    dx = 0;
    if (b->x < vx) {
        dx = b->x - vx;
    } else if (b->x + b->width > vx + vw) {
        if (b->width >= vw) {
            dx = b->x - vx;
        } else {
            dx = b->x + b->width - (vx + vw);
        }
    }
    if (b->y < vy) {
        dy = b->y - vy;
    } else if (b->y + b->height > vy + vh) {
        if (b->height >= vh) {
            dy = b->y - vy;
        } else {
            dy = b->y + b->height - (vy + vh);
        }
    }
    if (dx | dy) {
        drawScroll(frame, dx, dy);
        return 1;
    }
    return 0;
}

void drawFocusObject(void *b) {
    BOX *box = b;
    BOX *c;
    if (getBodyBox(box) == NULL) {
        return;
    }
    if (box->content != 0) {
        drawObject(box);
        return;
    }
    c = box->child;
    while (c != box && c != NULL) {
        if (c->content != 0) {
            drawObject(c);
        }
        if (c->content == 0 && c->child != NULL) {
            c = c->child;
        } else if (c->next != NULL) {
            c = c->next;
        } else {
            c = c->parent;
            while (c->next == NULL && c != box) {
                c = c->parent;
            }
            if (c == box) {
                break;
            }
            c = c->next;
        }
    }
}

void drawFocusItem(FOCUSLIST *f) {
    if (f->type == 0) {
        drawFocusObject(f->obj);
    } else {
        drawObjectWithArea(f->obj, f->area->x, f->area->y, f->area->w, f->area->h);
    }
}

int setFocusFocusItem(void *frame, FOCUSLIST *f, void *arg) {
    if (f->type == 0) {
        return setFocusBoxnode(f->obj, arg);
    }
    return setFocusImageMap(frame, f->obj, f->area->shape, f->area, arg);
}

void actSetFocusByBox(void *frame, void **box, int arg) {
    FOCUSLIST *l = NULL;
    for (;;) {
        if (box == NULL) break;
        l = getFocusList(frame, box);
        if (l != NULL && l->type == 0) break;
        box = *box;
    }
    actSetFocusByFocusList(frame, l, arg);
}

int emitFocusInfo(void *a, void *b) {
    void *box;
    void *msg;
    box = M2C_FIELD(getFocusTargetContentContext(gESPRIT_LO_GLOBAL_NDA), void **, 0x6C);
    if (box == NULL || !checkBoxValidity(box)) {
        return -1;
    }
    msg = make_msg_LP22(a, b);
    if (msg == NULL) {
        return -1;
    }
    putLLIST(&REQUEST_LLIST, msg);
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", actSetFocusByFocusList);

FOCUSLIST *getNextFocusUp(void *frame, FOCUSLIST *def, FOCUSLIST *cur) {
    if (cur != NULL) {
        return cur->prev;
    }
    return def;
}

FOCUSLIST *getNextFocusDown(void *frame, FOCUSLIST *def, FOCUSLIST *cur) {
    if (cur != NULL) {
        return cur->next;
    }
    return def;
}

int getRealPositionOfAnchor(BOX *a, int *x, int *y, int *w, int *h) {
    BOX *b;
    int found;
    int minx;
    int miny;
    int mw;
    int mh;

    if (a->html == 1) {
        minx = 0;
        found = 0;
        miny = 0;
        mw = 0;
        mh = 0;
        for (b = a->child; b != NULL && b->html != 1; ) {
            if (b->content != 0 && b->width > 0 && b->height > 0) {
                if (!found) {
                    found = 1;
                    minx = b->x;
                    miny = b->y;
                    mw = b->width;
                    mh = b->height;
                }
                if (b->y < miny) {
                    miny = b->y;
                    minx = minx < b->x ? minx : b->x;
                    mw = b->width;
                    mh = b->height;
                }
            }
            if (b->child != NULL) {
                b = b->child;
            } else if (b->next != NULL) {
                b = b->next;
            } else {
                b = b->parent;
                while (b != a && b->next == NULL) {
                    b = b->parent;
                }
                if (b == a) {
                    break;
                }
                b = b->next;
            }
        }
        *x = minx;
        *y = miny;
        if (w != NULL) {
            *w = mw;
        }
        if (h != NULL) {
            *h = mh;
        }
    }
}

void getRealFocusMaxBounds(FOCUSLIST *f, int *x, int *y, int *w, int *h) {
    if (M2C_FIELD(f->obj, s16 *, 0x3A) == 1) {
        getRealPositionOfAnchor(f->obj, x, y, w, h);
    } else {
        getFocusRegionInfo(f, x, y, w, h);
    }
}

FOCUSLIST *getNext2DFocusUp(void *frame, FOCUSLIST *list, FOCUSLIST *cur, BOX *obj) {
    int x, y, w, h;
    int vx, vy, vw, vh;
    int cx, cy, cw, ch;
    FOCUSLIST *l;
    FOCUSLIST *best;
    FOCUSLIST *best2;
    int bx, by, bw, bh, bd;
    int b2x, b2y, b2w, b2h, b2d;
    int mind;
    int d;
    int c;
    int dist;

    best = NULL;
    best2 = NULL;
    bx = 0;
    by = 0;
    bw = 0;
    bh = 0;
    bd = 0;
    b2x = 0;
    b2y = 0;
    b2w = 0;
    b2h = 0;
    b2d = 0;
    mind = -1;
    if (cur == NULL) {
        return list;
    }
    if (obj != NULL) {
        x = obj->x;
        y = obj->y + 1;
        w = 0;
        h = 0;
        cur = NULL;
    } else {
        getRealFocusMaxBounds(cur, &x, &y, &w, &h);
    }
    getViewPort(frame, &vx, &vy);
    getViewClientSize(frame, &vw, &vh);
    if (((BOX *)FFRAME(frame))->x - (vx + vw) >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (((BOX *)FFRAME(frame))->y - (vy + vh) >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (vx >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vx += M2C_FIELD(ui_global, int *, 0x74) * 2;
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (vy >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vy += M2C_FIELD(ui_global, int *, 0x74) * 2 + 2;
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (x < vx) {
        w -= vx - x;
        x = vx;
    }
    if (y < vy) {
        h -= vy - y;
        y = vy;
    }
    if (x + w > vx + vw) {
        w -= x + w - (vx + vw);
    }
    if (y + h > vy + vh) {
        h -= y + h - (vy + vh);
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh &&
            (y >= cy + ch || (cy < y && cy + ch < y + h && x < cx + cw && cx < x + w))) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            d = (w >> 1) + x;
            if (d < cx) {
                d = cx - d;
            } else if (cx + cw < d) {
                d = d - (cx + cw);
            } else {
                d = 0;
            }
            dist = sqrt(pow(d, D_001390F8) + pow(y - (cy + ch), D_001390F8)) * D_00139100;
            if (best == NULL) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                bd = dist;
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            } else if (by + bh < cy + ch) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                bd = dist;
            } else if (by + bh == cy + ch && dist < bd) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                bd = dist;
            }
            if (dist < b2d) {
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            }
        }
    }
    if (best2 != NULL && best2 != best && by < b2y + b2h && (b2x >= bx + bw || bx >= b2x + b2w)) {
        best = best2;
    }
    if (best != NULL) {
        return best;
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            ch = y - cy;
            if (ch > 0) {
                cw = abs(cx - x);
                if (cw == 0) {
                    cw = 1;
                }
                if (ch * 1000 / cw >= 200) {
                    dist = sqrt(pow(cw, D_001390F8) + pow(ch, D_001390F8));
                    if (dist <= mind || mind == -1) {
                        mind = dist;
                        best = l;
                    }
                }
            }
        }
    }
    if (best == NULL) {
        best = cur;
    }
    return best;
}

FOCUSLIST *getNext2DFocusDown(void *frame, FOCUSLIST *list, FOCUSLIST *cur, BOX *obj) {
    int x, y, w, h;
    int vx, vy, vw, vh;
    int cx, cy, cw, ch;
    FOCUSLIST *l;
    FOCUSLIST *best;
    FOCUSLIST *best2;
    int bx, by, bw, bh, bd;
    int b2x, b2y, b2w, b2h, b2d;
    int mind;
    int d;
    int c;
    int dist;

    best = NULL;
    best2 = NULL;
    bx = 0;
    by = 0;
    bw = 0;
    bh = 0;
    bd = 0;
    b2x = 0;
    b2y = 0;
    b2w = 0;
    b2h = 0;
    b2d = 0;
    mind = -1;
    if (cur == NULL) {
        return list;
    }
    if (obj != NULL) {
        x = obj->x;
        y = obj->y - 1;
        w = 0;
        h = 0;
        cur = NULL;
    } else {
        getRealFocusMaxBounds(cur, &x, &y, &w, &h);
    }
    getViewPort(frame, &vx, &vy);
    getViewClientSize(frame, &vw, &vh);
    if (((BOX *)FFRAME(frame))->x - (vx + vw) >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (((BOX *)FFRAME(frame))->y - (vy + vh) >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (vx >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vx += M2C_FIELD(ui_global, int *, 0x74) * 2;
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (vy >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vy += M2C_FIELD(ui_global, int *, 0x74) * 2 + 2;
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (x < vx) {
        w -= vx - x;
        x = vx;
    }
    if (y < vy) {
        h -= vy - y;
        y = vy;
    }
    if (x + w > vx + vw) {
        w -= x + w - (vx + vw);
    }
    if (y + h > vy + vh) {
        h -= y + h - (vy + vh);
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh &&
            (cy >= y + h || (y < cy && y + h < cy + ch && x < cx + cw && cx < x + w))) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            d = (w >> 1) + x;
            if (d < cx) {
                d = cx - d;
            } else if (cx + cw < d) {
                d = d - (cx + cw);
            } else {
                d = 0;
            }
            dist = sqrt(pow(d, D_00139108) + pow(y + h - cy, D_00139108)) * D_00139110;
            if (best == NULL) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                bd = dist;
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            } else if (cy < by) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                bd = dist;
            } else if (by == cy && dist < bd) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                bd = dist;
            }
            if (dist < b2d) {
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            }
        }
    }
    if (best2 != NULL && best2 != best && b2y < by + bh && (b2x >= bx + bw || bx >= b2x + b2w)) {
        best = best2;
    }
    if (best != NULL) {
        return best;
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            ch = cy - y;
            if (ch > 0) {
                cw = abs(cx - x);
                if (cw == 0) {
                    cw = 1;
                }
                if (ch * 1000 / cw >= 200) {
                    dist = sqrt(pow(cw, D_00139108) + pow(ch, D_00139108));
                    if (dist <= mind || mind == -1) {
                        mind = dist;
                        best = l;
                    }
                }
            }
        }
    }
    if (best == NULL) {
        best = cur;
    }
    return best;
}

FOCUSLIST *getNext2DFocusLeft(void *frame, FOCUSLIST *list, FOCUSLIST *cur) {
    int x, y, w, h;
    int vx, vy, vw, vh;
    int cx, cy, cw, ch;
    FOCUSLIST *l;
    FOCUSLIST *best;
    FOCUSLIST *best2;
    int bx, by, bw, bh, bd;
    int b2x, b2y, b2w, b2h, b2d;
    int mind;
    int d;
    int c;
    int dist;

    best = NULL;
    best2 = NULL;
    bx = 0;
    by = 0;
    bw = 0;
    bh = 0;
    bd = 0;
    b2x = 0;
    b2y = 0;
    b2w = 0;
    b2h = 0;
    b2d = 0;
    mind = -1;
    if (cur == NULL) {
        return list;
    }
    getRealFocusMaxBounds(cur, &x, &y, &w, &h);
    getViewPort(frame, &vx, &vy);
    getViewClientSize(frame, &vw, &vh);
    if (((BOX *)FFRAME(frame))->x - (vx + vw) >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (((BOX *)FFRAME(frame))->y - (vy + vh) >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (vx >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vx += M2C_FIELD(ui_global, int *, 0x74) * 2;
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (vy >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vy += M2C_FIELD(ui_global, int *, 0x74) * 2 + 2;
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (x < vx) {
        w -= vx - x;
        x = vx;
    }
    if (y < vy) {
        h -= vy - y;
        y = vy;
    }
    if (x + w > vx + vw) {
        w -= x + w - (vx + vw);
    }
    if (y + h > vy + vh) {
        h -= y + h - (vy + vh);
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (!(vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh)) continue;
        if (y < cy + ch && cy < y + h && (x >= cx + cw || (cx < x && cx + cw < x + w))) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            d = (h >> 1) + y;
            if (d < cy) {
                d = cy - d;
            } else if (cy + ch < d) {
                d = d - (cy + ch);
            } else {
                d = 0;
            }
            dist = sqrt(pow(d, D_00139118) + pow(x - (cx + cw), D_00139118)) * D_00139120;
            if (best == NULL) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            } else if (bx + bw < cx + cw) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
            } else if (bx + bw == cx + cw && dist < bd) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
            }
            if (dist < b2d) {
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            }
        }
    }
    if (best2 != NULL && best2 != best && bx < b2x + b2w && (b2y >= by + bh || by >= b2y + b2h)) {
        best = best2;
    }
    if (best != NULL) {
        return best;
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            cw = x - cx;
            ch = abs(y - cy);
            if (cw > 0) {
                if (ch * 1000 / cw < 200) {
                    dist = sqrt(pow(cw, D_00139118) + pow(ch, D_00139118));
                    if (dist <= mind || mind == -1) {
                        mind = dist;
                        best = l;
                    }
                }
            }
        }
    }
    if (best == NULL) {
        best = cur;
    }
    return best;
}

FOCUSLIST *getNext2DFocusRight(void *frame, FOCUSLIST *list, FOCUSLIST *cur) {
    int x, y, w, h;
    int vx, vy, vw, vh;
    int cx, cy, cw, ch;
    FOCUSLIST *l;
    FOCUSLIST *best;
    FOCUSLIST *best2;
    int bx, by, bw, bh, bd;
    int b2x, b2y, b2w, b2h, b2d;
    int mind;
    int d;
    int c;
    int dist;

    best = NULL;
    best2 = NULL;
    bx = 0;
    by = 0;
    bw = 0;
    bh = 0;
    bd = 0;
    b2x = 0;
    b2y = 0;
    b2w = 0;
    b2h = 0;
    b2d = 0;
    mind = -1;
    if (cur == NULL) {
        return list;
    }
    getRealFocusMaxBounds(cur, &x, &y, &w, &h);
    getViewPort(frame, &vx, &vy);
    getViewClientSize(frame, &vw, &vh);
    if (((BOX *)FFRAME(frame))->x - (vx + vw) >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (((BOX *)FFRAME(frame))->y - (vy + vh) >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (vx >= M2C_FIELD(ui_global, int *, 0x74) * 2) {
        vx += M2C_FIELD(ui_global, int *, 0x74) * 2;
        vw -= M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (vy >= M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
        vy += M2C_FIELD(ui_global, int *, 0x74) * 2 + 2;
        vh = vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2;
    }
    if (x < vx) {
        w -= vx - x;
        x = vx;
    }
    if (y < vy) {
        h -= vy - y;
        y = vy;
    }
    if (x + w > vx + vw) {
        w -= x + w - (vx + vw);
    }
    if (y + h > vy + vh) {
        h -= y + h - (vy + vh);
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh &&
            y < cy + ch && cy < y + h && (cx >= x + w || (x < cx && x + w < cx + cw))) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            d = (h >> 1) + y;
            if (d < cy) {
                d = cy - d;
            } else if (cy + ch < d) {
                d = d - (cy + ch);
            } else {
                d = 0;
            }
            dist = sqrt(pow(d, D_00139128) + pow(x + w - cx, D_00139128)) * D_00139130;
            if (best == NULL) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            } else if (cx < bx) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
            } else if (bx == cx && dist < bd) {
                best = l;
                bx = cx;
                by = cy;
                bw = cw;
                bh = ch;
            }
            if (dist < b2d) {
                best2 = l;
                b2x = cx;
                b2y = cy;
                b2w = cw;
                b2h = ch;
                b2d = dist;
            }
        }
    }
    if (best2 != NULL && best2 != best && b2x < bx + bw && (b2y >= by + bh || by >= b2y + b2h)) {
        best = best2;
    }
    if (best != NULL) {
        return best;
    }
    for (l = list; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &cx, &cy, &cw, &ch);
        if (vx < cx + cw && vy < cy + ch && cx < vx + vw && cy < vy + vh) {
            if (cx < vx) {
                cw -= vx - cx;
                cx = vx;
            }
            if (cy < vy) {
                ch -= vy - cy;
                cy = vy;
            }
            if (cx + cw > vx + vw) {
                cw -= cx + cw - (vx + vw);
            }
            if (cy + ch > vy + vh) {
                ch -= cy + ch - (vy + vh);
            }
            cw = cx - x;
            ch = abs(y - cy);
            if (cw > 0) {
                if (ch * 1000 / cw < 200) {
                    dist = sqrt(pow(cw, D_00139128) + pow(ch, D_00139128));
                    if (dist <= mind || mind == -1) {
                        mind = dist;
                        best = l;
                    }
                }
            }
        }
    }
    if (best == NULL) {
        best = cur;
    }
    return best;
}

FOCUSLIST *findFocusInView(void *frame, void *a1, FOCUSLIST *def, void *box) {
    FOCUSLIST *l;
    FOCUSLIST *n;
    void *obj = box;
    if (box != NULL && (l = getFocusList(frame, box)) != NULL) {
        obj = NULL;
    } else {
        l = def;
    }
    if (obj == NULL && l != NULL) {
        obj = l->obj;
    }
    n = getNext2DFocusDown(frame, a1, l, obj);
    if (n == NULL || n == l) {
        n = getNext2DFocusUp(frame, a1, l, obj);
    }
    if (n != NULL) {
        return n;
    }
    return l;
}

FOCUSLIST *getNextNaviFocus(void *frame, FOCUSLIST *l, FOCUSLIST *cur, char *name) {
    DOMString s;
    int vx, vy, vw, vh;
    int x, y, w, h;
    char *str;
    int r;
    if (cur == NULL) {
        return NULL;
    }
    if (name == NULL) {
        return NULL;
    }
    getViewPort(frame, &vx, &vy);
    getViewClientSize(frame, &vw, &vh);
    for (; l != NULL; l = l->next) {
        if (l == cur) {
            continue;
        }
        getRealFocusMaxBounds(l, &x, &y, &w, &h);
        if (vx < x + w && vy < y + h && x < vx + vw && y < vy + vh &&
            Element_hasAttribute(M2C_FIELD(l->obj, void **, 0x28), &_DOMname)) {
            Element_getAttribute(&s, M2C_FIELD(l->obj, void **, 0x28), &_DOMname);
            if (DOMStringlen(&s) > 0) {
                str = DOMStringtoUTF8(&s);
                if (str == NULL) {
                    return NULL;
                }
                r = strcasecmp(str, name);
                MEM_free(0, str);
                if (r == 0) {
                    return l;
                }
            }
        }
    }
    return cur;
}

void initFocusPositionParameter(void *frame, int *x, int *y, int *w, int *h) {
    getViewPort(frame, x, y);
    getViewClientSize(frame, w, h);
}

void scrollToCurrentFocusPosition(void *frame, FOCUSLIST *l) {
    int vx, vy, vw, vh;
    int x, y, w, h;
    int dx, dy;
    if (l == NULL) {
        return;
    }
    initFocusPositionParameter(frame, &vx, &vy, &vw, &vh);
    getFocusRegionInfo(l, &x, &y, &w, &h);
    dy = 0;
    dx = 0;
    if (x < vx) {
        dx = x - vx;
    } else if (x + w > vx + vw) {
        if (w >= vw) {
            dx = x - vx;
        } else {
            dx = x + w - (vx + vw);
        }
    }
    if (y < vy) {
        dy = y - vy;
    } else if (y + h > vy + vh) {
        if (h >= vh) {
            dy = y - vy;
        } else {
            dy = y + h - (vy + vh);
        }
    }
    if (dx | dy) {
        drawScroll(frame, dx, dy);
    }
}

void scrollToCurrent2DFocusPosition(void *frame, FOCUSLIST *l) {
    int vx, vy, vw, vh;
    int x, y, w, h;
    int dx, dy;
    if (l == NULL) {
        return;
    }
    initFocusPositionParameter(frame, &vx, &vy, &vw, &vh);
    getFocusRegionInfo(l, &x, &y, &w, &h);
    dy = 0;
    dx = 0;
    if (x < vx) {
        if (x + w - vx < M2C_FIELD(ui_global, int *, 0x74) * 2) {
            dx = -(M2C_FIELD(ui_global, int *, 0x74) * 2);
        }
    } else if (vx + vw - M2C_FIELD(ui_global, int *, 0x74) * 2 < x) {
        dx = M2C_FIELD(ui_global, int *, 0x74) * 2;
    }
    if (y < vy) {
        if (y + h - vy < M2C_FIELD(ui_global, int *, 0x74) * 2 + 2) {
            dy = -(M2C_FIELD(ui_global, int *, 0x74) * 2 + 2);
        }
    } else if (vy + vh - M2C_FIELD(ui_global, int *, 0x74) * 2 - 2 < y) {
        dy = M2C_FIELD(ui_global, int *, 0x74) * 2 + 2;
    }
    if (dx | dy) {
        drawScroll(frame, dx, dy);
    }
}

FOCUSLIST *act1DMoveFocusUp(void *frame, FOCUSLIST *def, FOCUSLIST *cur) {
    FOCUSLIST *n;
    if (frame == NULL) {
        return cur;
    }
    n = getNextFocusUp(frame, def, cur);
    if (n == NULL) {
        n = getFocusListTail(frame);
        if (n == NULL) {
            return NULL;
        }
    }
    scrollToCurrentFocusPosition(frame, n);
    if (n->obj != NULL) {
        actSetFocusByFocusList(frame, n, 1);
    }
    return n;
}

FOCUSLIST *act1DMoveFocusDown(void *frame, FOCUSLIST *def, FOCUSLIST *cur) {
    FOCUSLIST *n;
    if (frame == NULL) {
        return cur;
    }
    n = getNextFocusDown(frame, def, cur);
    if (n == NULL) {
        n = def;
        if (n == NULL) {
            return NULL;
        }
    }
    scrollToCurrentFocusPosition(frame, n);
    if (n->obj != NULL) {
        actSetFocusByFocusList(frame, n, 1);
    }
    return n;
}

int isFocusInDisplay(void *frame, FOCUSLIST *l) {
    int vx, vy, vw, vh;
    int x, y, w, h;
    int r;
    if (l == NULL) {
        return -1;
    }
    getViewPort(frame, &vx, &vy);
    getViewClientSize(frame, &vw, &vh);
    getRealFocusMaxBounds(l, &x, &y, &w, &h);
    if (vx < x + w && vy < y + h && x < vx + vw && y < vy + vh) {
        r = 0;
    } else {
        r = -1;
    }
    return r;
}

FOCUSLIST *scrollToNextPosition(void *frame, void *a1, FOCUSLIST *l, int dir)
{
    int vx, vy, vw, vh;
    int cw, ch;
    int dx, dy;
    FOCUSLIST *n;

    initFocusPositionParameter(frame, &vx, &vy, &vw, &vh);
    cw = M2C_FIELD(M2C_FIELD(frame, void **, 0x20), int *, 0x10);
    ch = M2C_FIELD(M2C_FIELD(frame, void **, 0x20), int *, 0x14);
    switch (dir) {
    case 1:
        if (vy <= 0)
            return l;
        dx = 0;
        dy = -(M2C_FIELD(ui_global, int *, 0x74) * 2 + 2);
        break;
    case 2:
        if (vy + vh >= ch)
            return l;
        dx = 0;
        dy = M2C_FIELD(ui_global, int *, 0x74) * 2 + 2;
        break;
    case 3:
        if (vx <= 0)
            return l;
        dx = -(M2C_FIELD(ui_global, int *, 0x74) * 2);
        dy = 0;
        break;
    case 4:
        if (vx + vw >= cw)
            return l;
        dx = M2C_FIELD(ui_global, int *, 0x74) * 2;
        dy = 0;
        break;
    default:
        return l;
    }
    drawScroll(frame, dx, dy);
    switch (dir) {
    case 1:
        n = getNext2DFocusUp(frame, a1, l, 0);
        break;
    case 2:
        n = getNext2DFocusDown(frame, a1, l, 0);
        break;
    case 3:
        n = getNext2DFocusLeft(frame, a1, l);
        break;
    case 4:
        n = getNext2DFocusRight(frame, a1, l);
        break;
    default:
        return l;
    }
    if (n != NULL)
        l = n;
    return l;
}

FOCUSLIST *act2DMoveFocusUp(void *frame, FOCUSLIST *a1, FOCUSLIST *cur) {
    FOCUSLIST *n;
    void *navi;
    if (frame == NULL) {
        return cur;
    }
    navi = NULL;
    if (cur != NULL) {
        if ((navi = cur->x18) != NULL) {
            navi = ((void **)navi)[0];
        } else {
            navi = NULL;
        }
    }
    n = getNextNaviFocus(frame, a1, cur, navi);
    if (n != NULL) {
        if (n != cur) {
            scrollToCurrent2DFocusPosition(frame, n);
        }
        goto set;
    }
    n = getNext2DFocusUp(frame, a1, cur, NULL);
    if (n == NULL) {
        n = cur;
    }
    if (n == cur) {
        n = scrollToNextPosition(frame, a1, n, 1);
        goto set;
    }
    scrollToCurrent2DFocusPosition(frame, n);
    if (n->obj == NULL) {
        goto end;
    }
set:
    actSetFocusByFocusList(frame, n, 1);
end:
    return n;
}

FOCUSLIST *act2DMoveFocusDown(void *frame, FOCUSLIST *a1, FOCUSLIST *cur) {
    FOCUSLIST *n;
    void *navi;
    if (frame == NULL) {
        return cur;
    }
    navi = NULL;
    if (cur != NULL) {
        if ((navi = cur->x18) != NULL) {
            navi = ((void **)navi)[1];
        } else {
            navi = NULL;
        }
    }
    n = getNextNaviFocus(frame, a1, cur, navi);
    if (n != NULL) {
        if (n != cur) {
            scrollToCurrent2DFocusPosition(frame, n);
        }
        goto set;
    }
    n = getNext2DFocusDown(frame, a1, cur, NULL);
    if (n == NULL) {
        n = cur;
    }
    if (n == cur) {
        n = scrollToNextPosition(frame, a1, n, 2);
        goto set;
    }
    scrollToCurrent2DFocusPosition(frame, n);
    if (n->obj == NULL) {
        goto end;
    }
set:
    actSetFocusByFocusList(frame, n, 1);
end:
    return n;
}

FOCUSLIST *act2DMoveFocusLeft(void *frame, FOCUSLIST *a1, FOCUSLIST *cur) {
    FOCUSLIST *n;
    void *navi;
    if (frame == NULL) {
        return cur;
    }
    navi = NULL;
    if (cur != NULL) {
        if ((navi = cur->x18) != NULL) {
            navi = ((void **)navi)[2];
        } else {
            navi = NULL;
        }
    }
    n = getNextNaviFocus(frame, a1, cur, navi);
    if (n != NULL) {
        if (n != cur) {
            scrollToCurrent2DFocusPosition(frame, n);
        }
        goto set;
    }
    n = getNext2DFocusLeft(frame, a1, cur);
    if (n == NULL) {
        n = cur;
    }
    if (n == cur) {
        n = scrollToNextPosition(frame, a1, n, 3);
        goto set;
    }
    scrollToCurrent2DFocusPosition(frame, n);
    if (n->obj == NULL) {
        goto end;
    }
set:
    actSetFocusByFocusList(frame, n, 1);
end:
    return n;
}

FOCUSLIST *act2DMoveFocusRight(void *frame, FOCUSLIST *a1, FOCUSLIST *cur) {
    FOCUSLIST *n;
    void *navi;
    if (frame == NULL) {
        return cur;
    }
    navi = NULL;
    if (cur != NULL) {
        if ((navi = cur->x18) != NULL) {
            navi = ((void **)navi)[3];
        } else {
            navi = NULL;
        }
    }
    n = getNextNaviFocus(frame, a1, cur, navi);
    if (n != NULL) {
        if (n != cur) {
            scrollToCurrent2DFocusPosition(frame, n);
        }
        goto set;
    }
    n = getNext2DFocusRight(frame, a1, cur);
    if (n == NULL) {
        n = cur;
    }
    if (n == cur) {
        n = scrollToNextPosition(frame, a1, n, 4);
        goto set;
    }
    scrollToCurrent2DFocusPosition(frame, n);
    if (n->obj == NULL) {
        goto end;
    }
set:
    actSetFocusByFocusList(frame, n, 1);
end:
    return n;
}

FOCUSLIST *getFocusInDisplay(void *frame, FOCUSLIST *def, FOCUSLIST *cur, int dir) {
    FOCUSLIST *l = cur;
    for (;;) {
        if (l == NULL) {
            l = cur;
            break;
        }
        if (isFocusInDisplay(frame, l) == 0) {
            break;
        }
        if (dir == 1) {
            l = l->prev;
        } else {
            l = l->next;
        }
    }
    return l;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int actScrollUp(int arg0, int arg1, int arg2) {
    int var_s0;
    int var_v0;

    var_s0 = arg2;
    var_v0 = arg2;
    if (arg0 != 0) {
        if (arg2 == 0) {
            var_s0 = arg1;
        }
        drawScroll(arg0, 0, -((M2C_FIELD(ui_global, int *, 0x74) * 2) + 2));
        if (isFocusInDisplay(arg0, var_s0) != 0) {
            var_s0 = getFocusInDisplay(arg0, arg1, var_s0, 1);
        }
        actSetFocusByFocusList(arg0, var_s0, 1);
        var_v0 = var_s0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int actScrollDown(int arg0, int arg1, int arg2) {
    int var_s0;
    int var_v0;

    var_s0 = arg2;
    var_v0 = arg2;
    if (arg0 != 0) {
        if (arg2 == 0) {
            var_s0 = arg1;
        }
        drawScroll(arg0, 0, (M2C_FIELD(ui_global, int *, 0x74) * 2) + 2);
        if (isFocusInDisplay(arg0, var_s0) != 0) {
            var_s0 = getFocusInDisplay(arg0, arg1, var_s0, 2);
        }
        actSetFocusByFocusList(arg0, var_s0, 1);
        var_v0 = var_s0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int actScrollLeft(int arg0, int arg1, int arg2) {
    int var_s0;
    int var_v0;

    var_s0 = arg2;
    var_v0 = arg2;
    if (arg0 != 0) {
        if (arg2 == 0) {
            var_s0 = arg1;
        }
        drawScroll(arg0, -(M2C_FIELD(ui_global, int *, 0x74) * 2), 0);
        if (isFocusInDisplay(arg0, var_s0) != 0) {
            var_s0 = getFocusInDisplay(arg0, arg1, var_s0, 1);
        }
        actSetFocusByFocusList(arg0, var_s0, 1);
        var_v0 = var_s0;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int actScrollRight(int arg0, int arg1, int arg2) {
    int var_s0;
    int var_v0;

    var_s0 = arg2;
    var_v0 = arg2;
    if (arg0 != 0) {
        if (arg2 == 0) {
            var_s0 = arg1;
        }
        drawScroll(arg0, M2C_FIELD(ui_global, int *, 0x74) * 2, 0);
        if (isFocusInDisplay(arg0, var_s0) != 0) {
            var_s0 = getFocusInDisplay(arg0, arg1, var_s0, 2);
        }
        actSetFocusByFocusList(arg0, var_s0, 1);
        var_v0 = var_s0;
    }
    return var_v0;
}

FOCUSLIST *actPageScrollUp(void *frame, FOCUSLIST *def, FOCUSLIST *cur) {
    int x, y, w, h;
    int cw, ch;
    FOCUSLIST *n;
    if (frame == NULL) {
        return cur;
    }
    initFocusPositionParameter(frame, &x, &y, &w, &h);
    getViewClientSize(frame, &cw, &ch);
    drawScroll(frame, 0, -ch);
    n = getFocusInDisplay(frame, def, cur, 1);
    actSetFocusByFocusList(frame, n, 1);
    return n;
}

FOCUSLIST *actPageScrollDown(void *frame, FOCUSLIST *def, FOCUSLIST *cur) {
    int x, y, w, h;
    int cw, ch;
    FOCUSLIST *n;
    if (frame == NULL) {
        return cur;
    }
    initFocusPositionParameter(frame, &x, &y, &w, &h);
    getViewClientSize(frame, &cw, &ch);
    drawScroll(frame, 0, ch);
    n = getFocusInDisplay(frame, def, cur, 2);
    actSetFocusByFocusList(frame, n, 1);
    return n;
}

FOCUSLIST *actScrollTop(void *frame, FOCUSLIST *l, FOCUSLIST *cur) {
    int x, y, w, h;
    if (frame == NULL) {
        return cur;
    }
    initFocusPositionParameter(frame, &x, &y, &w, &h);
    drawScroll(frame, -x, -y);
    actSetFocusByFocusList(frame, l, 1);
    return l;
}

FOCUSLIST *actScrollBottom(void *frame, FOCUSLIST *l, FOCUSLIST *cur) {
    int x, y, w, h;
    int dy;
    if (frame == NULL) {
        return cur;
    }
    initFocusPositionParameter(frame, &x, &y, &w, &h);
    dy = ((int *)FFRAME(frame))[5];
    drawScroll(frame, -x, dy - y - h);
    if (l != NULL) {
        for (;;) {
            if (l->next == NULL) {
                break;
            }
            l = l->next;
        }
    }
    actSetFocusByFocusList(frame, l, 1);
    return l;
}

FOCUSLIST *actFrameFocusDown(void *frame) {
    void *fr;
    FOCUSLIST *l;
    fr = getNextTerminalFrame(frame, 0);
    if (fr == NULL) {
        return NULL;
    }
    l = FFRAME(fr)->head;
    actSetFocusByFocusList(fr, l, 1);
    return l;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_001390F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_001390FC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139100);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139104);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139108);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_0013910C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139110);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139114);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139118);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_0013911C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139120);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139124);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139128);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_0013912C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139130);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", D_00139134);

static const char D_00139164[6];
static const char D_0013916C[4];
void *lo_getFocusNavi(void *node)
{
    DOMString s;
    STRWORD w;
    char *str;
    char **navi;
    int klen;
    int vlen;
    char *key;
    char *val;

    if (!Element_hasAttribute(node, &_DOMfocusnavi))
        return NULL;
    Element_getAttribute(&s, node, &_DOMfocusnavi);
    if (s.len == 0)
        return NULL;
    str = DOMStringtoUTF8(&s);
    if (str == NULL)
        return NULL;
    navi = MEM_calloc(0, 16);
    if (navi != NULL) {
        w.end = str;
        while (*w.end != 0) {
            w = UTL_strword(w.end, (char *)D_00139164, (char *)D_0013916C);
            klen = w.end - w.start;
            if (klen <= 0)
                break;
            key = w.start;
            w = UTL_strword(w.end, (char *)D_00139164, (char *)D_0013916C);
            vlen = w.end - w.start;
            if (vlen <= 0)
                continue;
            val = w.start;
            key[klen] = 0;
            if (navi[0] == NULL && strcasecmp(key, "navi-up") == 0) {
                navi[0] = MEM_malloc(0, vlen + 1);
                if (navi[0] != NULL) {
                    memcpy(navi[0], val, vlen);
                    navi[0][vlen] = 0;
                }
            } else if (navi[1] == NULL && strcasecmp(key, "navi-down") == 0) {
                navi[1] = MEM_malloc(0, vlen + 1);
                if (navi[1] != NULL) {
                    memcpy(navi[1], val, vlen);
                    navi[1][vlen] = 0;
                }
            } else if (navi[2] == NULL && strcasecmp(key, "navi-left") == 0) {
                navi[2] = MEM_malloc(0, vlen + 1);
                if (navi[2] != NULL) {
                    memcpy(navi[2], val, vlen);
                    navi[2][vlen] = 0;
                }
            } else if (navi[3] == NULL && strcasecmp(key, "navi-right") == 0) {
                navi[3] = MEM_malloc(0, vlen + 1);
                if (navi[3] != NULL) {
                    memcpy(navi[3], val, vlen);
                    navi[3][vlen] = 0;
                }
            }
        }
    }
    MEM_free(0, str);
    return navi;
}

static const char D_00139164[6] = " \t:;";
static const char D_0013916C[4] = "\t:;";
