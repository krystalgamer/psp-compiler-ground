/* cflags: -O1 */
#include "common.h"
#include "nflayout.h"
#include "lo_frame.h"
#include "m2c_macros.h"
extern const double D_001391D8;
double modf(double x, double *ip);
extern char D_001391E0[];
void insertCalcSize(s8 type, int sum, int total, int flag, FRAMESIZES *buf);
BOX *createBox(void *ctx, int type);
void insLinkBox(BOX *b, BOX *parent, BOX *after);
void initFrameBorderContent(BOX *b, int type);
void initBoxProperty(BOX *b);
int colorValue(char *s);
int adjustMoveFrameBorderValue(BOX *, BOX *, int);
int getFramesetBox();                               /* extern */
int getRootBox();                                   /* extern */
void moveFrameBorderByHorizontal(BOX *, BOX *, int);
void moveFrameBorderByVertical(BOX *, BOX *, int);




void *MEM_realloc(void *, void *p, unsigned int size);
char *strchr(const char *, int);
int atoi(const char *);
unsigned int strlen(const char *);
void relayoutByFrameBorderMove(void *);
void relayoutFramesetByFrameBorderMove(void *);
int drawPaint(int arg0);
int HST_getChildHistoryNode(void *arg0);
int HST_getRequestFlag(void *arg0);
int HST_getSiblingHistoryNode(void *arg0);
int HST_getParentHistoryNode(void *arg0);
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

int insertBuffer_87F0C(char *s, int len, FRAMESIZES *b) {
    FRAMESIZE *p;
    int v;
    if (b->count >= b->cap) {
        p = MEM_realloc(0, b->items, b->cap * 2 * sizeof(FRAMESIZE));
        if (p == NULL) {
            return -1;
        }
        b->cap = b->cap * 2;
        b->items = p;
    }
    if (strchr(s, '*') != NULL) {
        b->items[b->count].type = 'a';
    } else if (strchr(s, '%') != NULL) {
        b->items[b->count].type = 'p';
    } else {
        b->items[b->count].type = 'd';
    }
    v = atoi(s);
    if (b->items[b->count].type == 'a' && v == 0) {
        b->items[b->count].size = 1;
    } else {
        b->items[b->count].size = v;
    }
    b->items[b->count].x8 = 0;
    b->count++;
    return 0;
}

int splitString(char *s, char sep, void *out) {
    int i = 0;
    int j = 0;
    char *tmp;
    char c;
    tmp = MEM_malloc(0, strlen(s) + 1);
    if (tmp == NULL) {
        return -1;
    }
    do {
        for (;;) {
            if (s[i] == sep) {
                break;
            }
            if (s[i] == 0) {
                break;
            }
            tmp[j] = s[i];
            i++;
            j++;
        }
        tmp[j] = 0;
        insertBuffer_87F0C(tmp, j, out);
        c = s[i++];
        if (c == 0) {
            break;
        }
        j = 0;
    } while (1);
    MEM_free(0, tmp);
    return 0;
}

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

void insertCalcSize(s8 type, int sum, int total, int flag, FRAMESIZES *buf) {
    int i;
    double ipart;
    double frac;
    switch (type) {
    case 'd':
        for (i = 0; i < buf->count; i++) {
            if (buf->items[i].type == type) {
                if (flag == 0) {
                    buf->items[i].x8 = buf->items[i].size;
                } else {
                    buf->items[i].x8 = buf->items[i].size * ((double)total / sum) + D_001391D8;
                }
            }
        }
        break;
    case 'p':
        for (i = 0; i < buf->count; i++) {
            if (buf->items[i].type == type) {
                if (flag == 0) {
                    buf->items[i].x8 = (double)(total * buf->items[i].size / 100) + D_001391D8;
                } else {
                    buf->items[i].x8 = buf->items[i].size * ((double)total / sum) + D_001391D8;
                }
            }
        }
        break;
    case 'a': {
        int acc = 0;
        frac = modf((double)total / sum, &ipart);
        for (i = 0; i < buf->count; i++) {
            if (buf->items[i].type == type) {
                buf->items[i].x8 = buf->items[i].size * (frac + ipart) + D_001391D8;
            }
        }
        for (i = 0; i < buf->count; i++) {
            if (buf->items[i].type == type) {
                acc += buf->items[i].x8;
            }
        }
        for (i = 0; i < buf->count; i++) {
            if (buf->items[i].type == type) {
                buf->items[i].x8 += total - acc;
                break;
            }
        }
        break;
    }
    }
}

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

int DetFrameSize(char *str, int total, int *out, int max) {
    FRAMESIZES *buf;
    int dsum;
    int psum;
    int rest;
    int sum;
    int diff;
    int i;
    int j;
    buf = newBuffer();
    if (buf == NULL) {
        return 0;
    }
    if (splitString(str, ',', buf) < 0) {
        deleteBuffer((void **)buf);
        return 0;
    }
    if ((sumInputSize('d', buf) == 0 && countSizeType('d', buf) == buf->count) || (sumInputSize('p', buf) == 0 && countSizeType('p', buf) == buf->count)) {
        for (j = 0; j < buf->count; j++) {
            buf->items[j].size = 1;
        }
    }
    dsum = sumInputSize('d', buf);
    if (dsum >= total || countSizeType('d', buf) == buf->count) {
        insertCalcSize('d', dsum, total, 1, buf);
    } else {
        insertCalcSize('d', dsum, total, 0, buf);
        psum = sumInputSize('p', buf);
        if (psum >= 100 || countSizeType('d', buf) + countSizeType('p', buf) == buf->count) {
            insertCalcSize('p', psum, total - dsum, 1, buf);
        } else {
            rest = total - dsum;
            insertCalcSize('p', psum, rest, 0, buf);
            insertCalcSize('a', sumInputSize('a', buf), rest * (100 - psum) / 100, 1, buf);
        }
    }
    sum = 0;
    if (buf->count < max - 1) {
        for (i = 0; i < buf->count; i++) {
            out[i] = buf->items[i].x8;
            sum += buf->items[i].x8;
        }
        out[buf->count] = -1;
    } else {
        for (i = 0; i < max - 1; i++) {
            out[i] = buf->items[i].x8;
            sum += buf->items[i].x8;
        }
        out[max - 1] = -1;
    }
    if (sum != total) {
        diff = sum - total;
        for (j = 0; out[j] != -1; j++) {
            if (out[j] - diff >= 0) {
                out[j] -= diff;
                break;
            }
            diff -= out[j];
            out[j] = 0;
        }
    }
    deleteBuffer((void **)buf);
    return i;
}

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

void initFrameSize(BOX *box, char *cols, char *rows) {
    int w = FSETD(box)->x94;
    int h = FSETD(box)->x98;
    int bs = FSETD(box)->borderSize;
    int *arr;
    int n;
    if (cols != NULL) {
        arr = FSETD(box)->cols;
        n = DetFrameSize(cols, w, arr, 16);
        if (n >= 2) {
            w -= bs * (n - 1);
            if (w < 0) {
                w = 0;
            }
        }
        n = DetFrameSize(cols, w, arr, 16);
        FSETD(box)->ncols = n;
    }
    if (rows != NULL) {
        arr = FSETD(box)->rows;
        n = DetFrameSize(rows, h, arr, 16);
        if (n >= 2) {
            h -= bs * (n - 1);
            if (h < 0) {
                h = 0;
            }
        }
        n = DetFrameSize(rows, h, arr, 16);
        FSETD(box)->nrows = n;
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", reinitFrameSize);

void getFrameSizeFromFramesetBox(int *w, int *h, int *x, int *y, BOX *fs, int idx) {
    int ncols = FSETD(fs)->ncols;
    int nrows = FSETD(fs)->nrows;
    int row;
    int col;
    int *rows;
    int *cols;
    int fw;
    int fh;
    int i;
    if (ncols != 0) {
        row = idx / ncols;
        col = idx % ncols;
    } else {
        row = idx;
        col = 0;
    }
    if (col < 16) {
        if (row < 16) {
            rows = FSETD(fs)->rows;
            cols = FSETD(fs)->cols;
            fw = FSETD(fs)->x94;
            fh = FSETD(fs)->x98;
            *x = FSETD(fs)->x8C;
            *y = FSETD(fs)->x90;
            if (ncols != 0) {
                if (nrows != 0) {
                    *w = cols[col];
                    *h = rows[row];
                    for (i = 0; i < col; i++) {
                        *x += cols[i] + FSETD(fs)->borderSize;
                    }
                    for (i = 0; i < row; i++) {
                        *y += rows[i] + FSETD(fs)->borderSize;
                    }
                } else {
                    *w = cols[col];
                    *h = fh;
                    for (i = 0; i < col; i++) {
                        *x += cols[i] + FSETD(fs)->borderSize;
                    }
                }
            } else if (nrows != 0) {
                *w = fw;
                *h = rows[row];
                for (i = 0; i < row; i++) {
                    *y += rows[i] + FSETD(fs)->borderSize;
                }
            } else {
                *w = 0;
                *h = 0;
            }
        }
    }
}

void setFrameSizeToFramesetBox(int w, int h, BOX *fs, int idx) {
    int ncols = FSETD(fs)->ncols;
    int nrows = FSETD(fs)->nrows;
    int row;
    int col;
    int *rows;
    int *cols;
    if (ncols != 0) {
        row = idx / ncols;
        col = idx % ncols;
    } else {
        row = idx;
        col = 0;
    }
    if (col < 16) {
        if (row < 16) {
            rows = FSETD(fs)->rows;
            cols = FSETD(fs)->cols;
            if (ncols != 0) {
                if (nrows != 0) {
                    cols[col] = w;
                    rows[row] = h;
                } else {
                    cols[col] = w;
                }
            } else if (nrows != 0) {
                rows[row] = h;
            }
        }
    }
}

int getMyColFrameBorder(BOX *box) {
    int ret = 0;
    BOX *fs;
    BOX *c;
    int idx;
    int col;
    int ncols;
    fs = getFramesetBox(box->parent);
    if (fs == NULL) {
        return 0;
    }
    idx = 0;
    switch (box->content) {
    case 1:
        idx = FFRAMED(box)->x24;
        break;
    case 2:
        idx = FSETD(box)->xA8;
        break;
    }
    ncols = FSETD(fs)->ncols;
    if (ncols == 0) {
        return 0;
    }
    col = idx % ncols;
    c = fs->child;
    for (;;) {
        if (c == NULL) {
            break;
        }
        if (c->content == 1 && FFRAMED(c)->x24 == col) {
            ret = FFRAMED(c)->x3C;
        }
        if (box->content == 2 && c->content == 2 && FSETD(c)->xA8 == col) {
            ret = FSETD(c)->xAC;
        }
        c = c->next;
    }
    return ret;
}

int getMyRowFrameBorder(BOX *box) {
    int idx = 0;
    int ret = 0;
    BOX *fs;
    BOX *c;
    int row;
    int r;
    int ncols;
    fs = getFramesetBox(box->parent);
    if (fs == NULL) {
        return 0;
    }
    switch (box->content) {
    case 1:
        idx = FFRAMED(box)->x24;
        break;
    case 2:
        idx = FSETD(box)->xA8;
        break;
    }
    ncols = FSETD(fs)->ncols;
    row = idx;
    if (ncols != 0) {
        row = idx / ncols;
    }
    if (row == 0) {
        return 0;
    }
    c = fs->child;
    for (;;) {
        if (c == NULL) {
            break;
        }
        if (c->content == 1) {
            if (ncols == 0) {
                r = FFRAMED(c)->x24;
            } else {
                r = FFRAMED(c)->x24 / ncols;
            }
            if (r == row) {
                ret = FFRAMED(c)->x3C;
                break;
            }
        }
        if (box->content == 2 && c->content == 2) {
            if (ncols == 0) {
                r = FSETD(c)->xA8;
            } else {
                r = FSETD(c)->xA8 / ncols;
            }
            if (r == row) {
                ret = FSETD(c)->xAC;
                break;
            }
        }
        c = c->next;
    }
    return ret;
}

void initFrameBorderPosition_hfull(BOX *frame, BOX *border, int *x, int *y, int *w, int *h, int size, int z) {
    border->width = FFRAMED(frame)->x94;
    border->height = size;
    border->x = *x;
    border->y = *y - size;
    *(int *)border->geom = 0;
}

void initFrameBorderPosition_vfull(BOX *frame, BOX *border, int *x, int *y, int *w, int *h, int size, int z) {
    border->width = size;
    border->height = FFRAMED(frame)->x98;
    border->x = *x - size;
    border->y = *y;
    *(int *)border->geom = 1;
}



INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391D8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391DC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/lo_frame", D_001391E0);

BOX *createFrameBorderBox_create(BOX *frame, int type, int *x, int *y, int *w, int *h, int z) {
    BOX *c;
    BOX *b;
    int size;
    c = getLastFrameBox(frame)->prev;
    for (;;) {
        if (c == NULL) {
            return NULL;
        }
        if (c->content == 1) {
            break;
        }
        if (c->content == 2) {
            break;
        }
        c = c->prev;
    }
    b = createBox(0, 1);
    if (b == NULL) {
        return NULL;
    }
    insLinkBox(b, frame, c);
    b->display = 0;
    b->html = 0;
    initFrameBorderContent(b, type);
    initBoxProperty(b);
    size = FSETD(frame)->borderSize;
    b->style->unk48 = 1;
    b->style->unk4A = 1;
    b->style->unk4C = 1;
    b->style->unk4E = 1;
    b->style->unk30 = size;
    b->style->unk32 = size;
    b->style->unk34 = size;
    b->style->unk36 = size;
    if (FSETD(frame)->borderColor == 0) {
        b->style->unk38 = colorValue("gray");
        b->style->unk3C = colorValue("gray");
        b->style->unk40 = colorValue("gray");
        b->style->unk44 = colorValue("gray");
    } else {
        b->style->unk38 = FSETD(frame)->borderColor;
        b->style->unk3C = FSETD(frame)->borderColor;
        b->style->unk40 = FSETD(frame)->borderColor;
        b->style->unk44 = FSETD(frame)->borderColor;
    }
    return b;
}

BOX *createFrameBorderBox_hfull(BOX *frame, int type, int *x, int *y, int *w, int *h, int z) {
    BOX *b = createFrameBorderBox_create(frame, type, x, y, w, h, z);
    int size;
    if (b == NULL) {
        return NULL;
    }
    size = FSETD(frame)->borderSize;
    initFrameBorderPosition_hfull(frame, b, x, y, w, h, size, z);
    return b;
}

BOX *createFrameBorderBox_vfull(BOX *frame, int type, int *x, int *y, int *w, int *h, int z) {
    BOX *b = createFrameBorderBox_create(frame, type, x, y, w, h, z);
    int size;
    if (b == NULL) {
        return NULL;
    }
    size = FSETD(frame)->borderSize;
    initFrameBorderPosition_vfull(frame, b, x, y, w, h, size, z);
    return b;
}

void createFrameBorder(BOX *box, int type, int *x, int *y, int *w, int *h) {
    BOX *fs;
    int idx;
    int ncols;
    int nrows;
    int col;
    int row;
    fs = (BOX *)getFramesetBox(box);
    if (fs == NULL) {
        return;
    }
    idx = FFRAMED(box)->x24;
    ncols = FSETD(fs)->ncols;
    nrows = FSETD(fs)->nrows;
    if (ncols != 0) {
        col = idx % ncols;
        row = idx / ncols;
        if (nrows != 0) {
            if (row != 0) {
                if (col == 0) {
                    FFRAMED(box)->x3C = (int)createFrameBorderBox_hfull(fs, type, x, y, w, h, idx);
                }
            } else if (col != 0) {
                FFRAMED(box)->x3C = (int)createFrameBorderBox_vfull(fs, type, x, y, w, h, idx);
            }
        } else if (idx != 0) {
            FFRAMED(box)->x3C = (int)createFrameBorderBox_vfull(fs, type, x, y, w, h, idx);
        }
    } else if (nrows != 0) {
        if (idx != 0) {
            FFRAMED(box)->x3C = (int)createFrameBorderBox_hfull(fs, type, x, y, w, h, idx);
        }
    }
}

void createFrameBorder_frameset(BOX *box, int type, int *x, int *y, int *w, int *h) {
    BOX *fs;
    int idx;
    int ncols;
    int nrows;
    int col;
    int row;
    fs = (BOX *)getFramesetBox(box->parent);
    if (box == NULL) {
        return;
    }
    idx = FSETD(box)->xA8;
    ncols = FSETD(fs)->ncols;
    nrows = FSETD(fs)->nrows;
    if (ncols != 0) {
        col = idx % ncols;
        row = idx / ncols;
        if (nrows != 0) {
            if (row != 0) {
                if (col == 0) {
                    FSETD(box)->xAC = (int)createFrameBorderBox_hfull(fs, type, x, y, w, h, idx);
                }
            } else if (col != 0) {
                FSETD(box)->xAC = (int)createFrameBorderBox_vfull(fs, type, x, y, w, h, idx);
            }
        } else if (idx != 0) {
            FSETD(box)->xAC = (int)createFrameBorderBox_vfull(fs, type, x, y, w, h, idx);
        }
    } else if (nrows != 0) {
        if (idx != 0) {
            FSETD(box)->xAC = (int)createFrameBorderBox_hfull(fs, type, x, y, w, h, idx);
        }
    }
}

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

void updateParentFrameset(BOX *box, int a, int b) {
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

void moveFrameBorderByVertical(BOX *b, BOX *fs, int d) {
    BOX *c;
    int w;
    int h;
    b->x += d;
    for (c = fs->child; c != NULL; c = c->next) {
        if (c->content == 1) {
            if (FFRAMED(c)->fx == b->x - d + b->width || FFRAMED(c)->fx + FFRAMED(c)->fw == b->x - d) {
                if (FFRAMED(c)->fy >= b->y && ((FFRAMED(c)->fy == 0 && b->y + b->height >= FFRAMED(c)->fh) || FFRAMED(c)->fy + FFRAMED(c)->fh <= b->y + b->height + 1)) {
                    if (FFRAMED(c)->fx == b->x - d + b->width) {
                        FFRAMED(c)->fx += d;
                        FFRAMED(c)->fw -= d;
                    } else {
                        FFRAMED(c)->fw += d;
                    }
                    if (FFRAMED(c)->fx < 0) {
                        FFRAMED(c)->fx = 0;
                    }
                    if (FFRAMED(c)->fw < 0) {
                        FFRAMED(c)->fw = 0;
                    }
                    w = FFRAMED(c)->fw;
                    h = FFRAMED(c)->fh;
                    updateParentFrameset(c, w, h);
                    relayoutByFrameBorderMove(c);
                }
            }
        } else {
            if (FSETD(c)->x8C == b->x - d + b->width || FSETD(c)->x8C + FSETD(c)->x94 == b->x - d) {
                if (FSETD(c)->x90 >= b->y && FSETD(c)->x90 + FSETD(c)->x98 <= b->y + b->height) {
                    if (FSETD(c)->x8C == b->x - d + b->width) {
                        FSETD(c)->x8C += d;
                        FSETD(c)->x94 -= d;
                    } else {
                        FSETD(c)->x94 += d;
                    }
                    if (FSETD(c)->x8C < 0) {
                        FSETD(c)->x8C = 0;
                    }
                    if (FSETD(c)->x94 < 0) {
                        FSETD(c)->x94 = 0;
                    }
                    w = FSETD(c)->x94;
                    h = FSETD(c)->x98;
                    updateParentFrameset(c, w, h);
                    relayoutFramesetByFrameBorderMove(c);
                }
            }
        }
    }
}

void moveFrameBorderByHorizontal(BOX *b, BOX *fs, int d) {
    BOX *c;
    int w;
    int h;
    b->y += d;
    for (c = fs->child; c != NULL; c = c->next) {
        if (c->content == 1) {
            if (FFRAMED(c)->fy == b->y - d + b->height || FFRAMED(c)->fy + FFRAMED(c)->fh == b->y - d) {
                if (FFRAMED(c)->fx >= b->x && ((FFRAMED(c)->fx == 0 && b->x + b->width >= FFRAMED(c)->fw) || FFRAMED(c)->fx + FFRAMED(c)->fw <= b->x + b->width + 1)) {
                    if (FFRAMED(c)->fy == b->y - d + b->height) {
                        FFRAMED(c)->fy += d;
                        FFRAMED(c)->fh -= d;
                    } else {
                        FFRAMED(c)->fh += d;
                    }
                    if (FFRAMED(c)->fy < 0) {
                        FFRAMED(c)->fy = 0;
                    }
                    if (FFRAMED(c)->fh < 0) {
                        FFRAMED(c)->fh = 0;
                    }
                    w = FFRAMED(c)->fw;
                    h = FFRAMED(c)->fh;
                    updateParentFrameset(c, w, h);
                    relayoutByFrameBorderMove(c);
                }
            }
        } else {
            if (FSETD(c)->x90 == b->y - d + b->height || FSETD(c)->x90 + FSETD(c)->x98 == b->y - d) {
                if (FSETD(c)->x8C >= b->x && FSETD(c)->x8C + FSETD(c)->x94 <= b->x + b->width) {
                    if (FSETD(c)->x90 == b->y - d + b->height) {
                        FSETD(c)->x90 += d;
                        FSETD(c)->x98 -= d;
                    } else {
                        FSETD(c)->x98 += d;
                    }
                    if (FSETD(c)->x90 < 0) {
                        FSETD(c)->x90 = 0;
                    }
                    if (FSETD(c)->x98 < 0) {
                        FSETD(c)->x98 = 0;
                    }
                    w = FSETD(c)->x94;
                    h = FSETD(c)->x98;
                    updateParentFrameset(c, w, h);
                    relayoutFramesetByFrameBorderMove(c);
                }
            }
        }
    }
}

int adjustMoveFrameBorderValue(BOX *b, BOX *fs, int d) {
    int dir = *(int *)b->geom;
    BOX *prev;
    BOX *next;
    BOX *c;
    int lim;
    for (c = fs->child, prev = NULL; c != b; c = c->next) {
        if (c->content == 3 && *(int *)c->geom == dir) {
            prev = c;
        }
    }
    for (c = b->next, next = NULL; c != NULL; c = c->next) {
        if (c->content == 3 && *(int *)c->geom == dir) {
            next = c;
            break;
        }
    }
    if (d < 0 && dir == 1) {
        if (prev != NULL) {
            lim = b->x - prev->x - prev->width;
        } else {
            lim = b->x - FSETD(fs)->x8C;
        }
        if (lim < -d) {
            d = -lim;
        }
    } else if (d >= 0 && dir == 1) {
        if (next != NULL) {
            lim = next->x - b->x - b->width;
        } else {
            lim = FSETD(fs)->x8C + FSETD(fs)->x94 - b->x - b->width;
        }
        if (lim < d) {
            d = lim;
        }
    } else if (d < 0 && dir == 0) {
        if (prev != NULL) {
            lim = b->y - prev->y - prev->height;
        } else {
            lim = b->y - FSETD(fs)->x90;
        }
        if (lim < -d) {
            d = -lim;
        }
    } else {
        if (next != NULL) {
            lim = next->y - b->y - b->height;
        } else {
            lim = FSETD(fs)->x90 + FSETD(fs)->x98 - b->y - b->height;
        }
        if (lim < d) {
            d = lim;
        }
    }
    return d;
}

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

int isLoadedAllChild(void *root) {
    void *n;
    void *c;
    void *p;
    n = HST_getChildHistoryNode(root);
    while (n != NULL) {
        if (HST_getRequestFlag(n) >= 0) {
            if (M2C_FIELD(n, void **, 0x6C) == NULL || M2C_FIELD(M2C_FIELD(M2C_FIELD(n, void **, 0x6C), void **, 0x20), int *, 0x40) != 3) {
                return 0;
            }
        }
        c = HST_getChildHistoryNode(n);
        if (c != NULL) {
            n = c;
        } else {
            c = HST_getSiblingHistoryNode(n);
            if (c != NULL) {
                n = c;
            } else {
                for (p = HST_getParentHistoryNode(n); p != NULL && p != root; p = HST_getParentHistoryNode(p)) {
                    c = HST_getSiblingHistoryNode(p);
                    if (c != NULL) {
                        n = c;
                        break;
                    }
                }
                if (p == root) {
                    return 1;
                }
            }
        }
    }
    return 1;
}
