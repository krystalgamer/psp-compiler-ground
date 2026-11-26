/* cflags: -O1 */
#include "common.h"

typedef struct {
    int x;
    int y;
    int dmaj;
    int dmin;
    int smaj;
    int smin;
    int err;
    int *major;
    int *minor;
} TRAPEZOID;

void initTrapezoidPoint(TRAPEZOID *t, int x0, int y0, int x1, int y1) {
    int dx;
    int dy;
    int sx;
    int sy;

    dx = x1 - x0;
    sx = 1;
    if (dx < 0) {
        dx = -dx;
        sx = -1;
    }
    dy = y1 - y0;
    sy = 1;
    if (dy < 0) {
        dy = -dy;
        sy = -1;
    }
    t->x = x0;
    t->y = y0;
    if (dx >= dy) {
        t->major = &t->x;
        t->minor = &t->y;
        t->dmaj = dx;
        t->dmin = dy;
        t->smaj = sx;
        t->smin = sy;
        t->err = dx / 2;
    } else {
        t->major = &t->y;
        t->minor = &t->x;
        t->dmaj = dy;
        t->dmin = dx;
        t->smaj = sy;
        t->smin = sx;
        t->err = dy / 2;
    }
}

void incrementTrapezoidPoint(TRAPEZOID *t, int *target) {
    int old;

    old = *target;
    do {
        *t->major += t->smaj;
        t->err += t->dmin;
        if (t->err >= t->dmaj) {
            t->err -= t->dmaj;
            *t->minor += t->smin;
        }
    } while (old == *target);
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_boxnode", verticalBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_boxnode", horizontalBorder);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_boxnode", rnd_drawBoxnodeBorder);
