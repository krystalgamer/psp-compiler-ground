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

void rnd_gdrawFillrectangle(int g, int color, int x, int y, int w, int h);
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

void verticalBorder(void *g, int x, int y, int h, int w, int dy0, int dy1, int c0, int c1)
{
    TRAPEZOID a;
    TRAPEZOID b;
    int n;
    int half;
    int i;

    initTrapezoidPoint(&a, x, y, x + w, y + dy0);
    initTrapezoidPoint(&b, x, y + h - 1, x + w, y + h - dy1 - 1);
    n = w;
    if (n < 0)
        n = -n;
    half = n / 2;
    i = n - half;
    while (i-- > 0) {
        rnd_gdrawFillrectangle(g, c0, a.x, a.y, 1, b.y - a.y + 1);
        incrementTrapezoidPoint(&a, &a.x);
        incrementTrapezoidPoint(&b, &b.x);
    }
    while (half-- > 0) {
        rnd_gdrawFillrectangle(g, c1, a.x, a.y, 1, b.y - a.y + 1);
        incrementTrapezoidPoint(&a, &a.x);
        incrementTrapezoidPoint(&b, &b.x);
    }
}

void horizontalBorder(void *g, int x, int y, int w, int h, int dx0, int dx1, int c0, int c1)
{
    TRAPEZOID a;
    TRAPEZOID b;
    int n;
    int half;
    int i;

    initTrapezoidPoint(&a, x, y, x + dx0, y + h);
    initTrapezoidPoint(&b, x + w - 1, y, x + w - dx1 - 1, y + h);
    n = h;
    if (n < 0)
        n = -n;
    half = n / 2;
    i = n - half;
    while (i-- > 0) {
        rnd_gdrawFillrectangle(g, c0, a.x, a.y, b.x - a.x + 1, 1);
        incrementTrapezoidPoint(&a, &a.y);
        incrementTrapezoidPoint(&b, &b.y);
    }
    while (half-- > 0) {
        rnd_gdrawFillrectangle(g, c1, a.x, a.y, b.x - a.x + 1, 1);
        incrementTrapezoidPoint(&a, &a.y);
        incrementTrapezoidPoint(&b, &b.y);
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/rnd_boxnode", rnd_drawBoxnodeBorder);
