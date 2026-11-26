/* cflags: -O1 */
#include "common.h"
#include "lo_box.h"
#include "m2c_macros.h"
#include "lo_focus.h"
BOX *lo_getActiveFrameBodybox(void *ctx);
void *MEM_malloc(int pool, unsigned int size);
void *lo_getFocusNavi(void *node);
FOCUSLIST *getNext2DFocusLeft(void *frame, void *a1, FOCUSLIST *l);
FOCUSLIST *getNext2DFocusRight(void *frame, void *a1, FOCUSLIST *l);
FOCUSLIST *getNextNaviFocus(void *frame, void *a1, FOCUSLIST *l, void *navi);
void scrollToCurrent2DFocusPosition(void *frame, FOCUSLIST *l);
FOCUSLIST *scrollToNextPosition(void *frame, void *a1, FOCUSLIST *l, int dir);
FOCUSLIST *getNext2DFocusDown(void *frame, void *a1, FOCUSLIST *l, void *obj);
FOCUSLIST *getNext2DFocusUp(void *frame, void *a1, FOCUSLIST *l, void *obj);
void *getBodyBox(void *box);
void drawObject(BOX *box);
int checkBoxValidity(void *box);
extern void *gESPRIT_LO_GLOBAL_NDA;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
extern void *ui_global;



#ifndef NULL
#define NULL ((void *)0)
#endif

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
    *(s16 *)&f->x10 = 0;
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getRealPositionOfAnchor);

void getRealFocusMaxBounds(FOCUSLIST *f, int *x, int *y, int *w, int *h) {
    if (M2C_FIELD(f->obj, s16 *, 0x3A) == 1) {
        getRealPositionOfAnchor(f->obj, x, y, w, h);
    } else {
        getFocusRegionInfo(f, x, y, w, h);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getNext2DFocusUp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getNext2DFocusDown);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getNext2DFocusLeft);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getNext2DFocusRight);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getNextNaviFocus);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", scrollToNextPosition);

FOCUSLIST *act2DMoveFocusUp(void *frame, void *a1, FOCUSLIST *cur) {
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

FOCUSLIST *act2DMoveFocusDown(void *frame, void *a1, FOCUSLIST *cur) {
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

FOCUSLIST *act2DMoveFocusLeft(void *frame, void *a1, FOCUSLIST *cur) {
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

FOCUSLIST *act2DMoveFocusRight(void *frame, void *a1, FOCUSLIST *cur) {
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", lo_getFocusNavi);
