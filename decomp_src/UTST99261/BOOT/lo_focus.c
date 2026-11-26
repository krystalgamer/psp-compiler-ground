/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
#include "lo_focus.h"
int checkBoxValidity(void *box);
extern void *gESPRIT_LO_GLOBAL_NDA;
M2C_UNK MEM_free(M2C_UNK, void *);                  /* extern */
int getFocusInDisplay(int, int, int, M2C_UNK);      /* extern */
int isFocusInDisplay(int, int);                     /* extern */
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", appendFocusList);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", scrollToFocusPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", drawFocusObject);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", findFocusInView);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getNextNaviFocus);

void initFocusPositionParameter(void *frame, int *x, int *y, int *w, int *h) {
    getViewPort(frame, x, y);
    getViewClientSize(frame, w, h);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", scrollToCurrentFocusPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", scrollToCurrent2DFocusPosition);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", isFocusInDisplay);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", scrollToNextPosition);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", act2DMoveFocusUp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", act2DMoveFocusDown);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", act2DMoveFocusLeft);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", act2DMoveFocusRight);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", getFocusInDisplay);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", actPageScrollUp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", actPageScrollDown);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_focus", actScrollBottom);

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
