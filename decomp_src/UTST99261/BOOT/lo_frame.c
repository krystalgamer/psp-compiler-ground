/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "lo_frame.h"
#include "m2c_macros.h"
int adjustMoveFrameBorderValue(void *, int, int);   /* extern */
int getFramesetBox();                               /* extern */
int getRootBox();                                   /* extern */
M2C_UNK moveFrameBorderByHorizontal(void *, int, int); /* extern */
M2C_UNK moveFrameBorderByVertical(void *, int, int); /* extern */




void *newBuffer(void) {
    void **b = MEM_malloc(0, 0xC);
    if (b == NULL) {
        return NULL;
    }
    ((int *)b)[1] = 0;
    ((int *)b)[2] = 5;
    b[0] = MEM_malloc(0, 0x3C);
    if (b[0] == NULL) {
        MEM_free(0, b);
        return NULL;
    }
    return b;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void deleteBuffer(void **buf) {
    MEM_free(0, *buf);
    MEM_free(0, buf);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", insertBuffer_87F0C);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", splitString);

int sumInputSize(s8 type, FRAMESIZES *a) {
    int i;
    int sum = 0;
    for (i = 0; i < a->count; i++) {
        if (a->items[i].type == type) {
            sum += a->items[i].size;
        }
    }
    return sum;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", insertCalcSize);

int countSizeType(s8 type, FRAMESIZES *a) {
    int i;
    int n = 0;
    for (i = 0; i < a->count; i++) {
        if (a->items[i].type == type) {
            n++;
        }
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", DetFrameSize);

BOX *getLastFrameBox(BOX *box) {
    BOX *c;
    BOX *last;
    c = box->child;
    last = NULL;
    for (;;) {
        if (c == NULL) break;
        if (c->content == 1) {
            last = c;
        } else if (c->content == 2) {
            last = c;
        }
        c = c->next;
    }
    return last;
}

int getFramenum(BOX *box) {
    BOX *c;
    int n;
    c = box->child;
    n = 0;
    for (;;) {
        if (c == NULL) break;
        if (c->content == 1) {
            n++;
        } else if (c->content == 2) {
            n++;
        }
        c = c->next;
    }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", initFrameSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", reinitFrameSize);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getFrameSizeFromFramesetBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", setFrameSizeToFramesetBox);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getMyColFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", getMyRowFrameBorder);

void initFrameBorderPosition_hfull(BOX *frame, BOX *border, int *x, int *y, int *w, int *h, int size) {
    border->width = FFRAMED(frame)->x94;
    border->height = size;
    border->x = *x;
    border->y = *y - size;
    *(int *)border->geom = 0;
}

void initFrameBorderPosition_vfull(BOX *frame, BOX *border, int *x, int *y, int *w, int *h, int size) {
    border->width = size;
    border->height = FFRAMED(frame)->x98;
    border->x = *x - size;
    border->y = *y;
    *(int *)border->geom = 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391E0);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorderBox_create);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorderBox_hfull);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorderBox_vfull);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", createFrameBorder_frameset);

void drawFrameBorderLoop(BOX *box) {
    BOX *c;
    for (c = box->child; c != NULL; c = c->next) {
        drawFrameBorderLoop(c);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void drawFrameBorder(BOX *box) {
    drawFrameBorderLoop(box);
}

void updateParentFrameset(BOX *box, void *a, void *b) {
    BOX *parent = box->parent;
    int v;
    if (parent != NULL && parent->content == 2) {
        if (box->content == 1) {
            v = FFRAMED(box)->x24;
        } else {
            v = FFRAMED(box)->xA8;
        }
        setFrameSizeToFramesetBox(a, b, parent, v);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", moveFrameBorderByVertical);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", moveFrameBorderByHorizontal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", adjustMoveFrameBorderValue);

#ifndef NULL
#define NULL ((void *)0)
#endif

void moveFrameBorder(void *arg0, int arg1) {
    int temp_s0;
    int temp_v0;
    int temp_v0_2;
    int temp_v0_3;

    temp_v0 = getFramesetBox();
    if (temp_v0 != 0) {
        temp_s0 = *M2C_FIELD(arg0, int **, 0x20);
        temp_v0_2 = adjustMoveFrameBorderValue(arg0, temp_v0, arg1);
        if (temp_s0 == 0) {
            moveFrameBorderByHorizontal(arg0, temp_v0, temp_v0_2);
        } else {
            moveFrameBorderByVertical(arg0, temp_v0, temp_v0_2);
        }
        temp_v0_3 = getRootBox();
        if (temp_v0_3 != 0) {
            drawPaint(temp_v0_3);
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", isLoadedAllChild);
