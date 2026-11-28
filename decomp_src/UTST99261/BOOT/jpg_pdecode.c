/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct {
    unsigned int count;
    int *len;                   /* 0x4 */
    int *code;                  /* 0x8 */
    int *val;                   /* 0xC */
} JHTAB;

typedef struct {
    u8 unk0;
    u8 dc;                      /* 0x1 */
    u8 ac;                      /* 0x2 */
} JCOMPSEL;

typedef struct {
    u8 unk0;
    u8 h;                       /* 0x1 */
    u8 v;                       /* 0x2 */
    u8 unk3[9];
} JCOMPINFO;

typedef struct {
    void *bs;                   /* 0x0 */
    u8 *rgb;                    /* 0x4 */
    s16 *out[3];                /* 0x8 */
    s16 pred[4];                /* 0x14 */
    s16 *block;                 /* 0x1C */
    s16 idct[64];               /* 0x20 */
    u8 unkA0[0xC];
    int *coef[4];               /* 0xAC */
    u8 unkBC[0xA];
    u16 width;                  /* 0xC6 */
    u8 unkC8[0x2];
    u8 ncomp;                   /* 0xCA */
    u8 unkCB[0x5];
    u16 mcuw;                   /* 0xD0 */
    u16 mcuh;                   /* 0xD2 */
    u8 unkD4[3];
    u8 ss;                      /* 0xD7 */
    u8 se;                      /* 0xD8 */
    u8 unkD9;
    u8 al;                      /* 0xDA */
    u8 unkDB;
    JCOMPINFO ci[4];            /* 0xDC */
    u8 unk10C[0x582];
    u8 hmax;                    /* 0x68E */
    u8 vmax;                    /* 0x68F */
    u8 unk690[0xC];
    int eobrun;                 /* 0x69C */
    u8 marker;                  /* 0x6A0 */
} JPCTX;

extern const int natural_order[];

typedef struct {
    void *bs;
    u8 unk4[0xFC];
    JCOMPSEL comp[4];           /* 0x100 */
    JHTAB huff[2][4];           /* 0x10C */
} JDCTX;

int getBits(void *bs, int n);


int decodeHuffmanBlock_AC_first();
int current_dct(JPCTX *ctx, int c, int mx, int my, int bx, int by) {
    int *coef = ctx->coef[c];
    u8 h = ctx->ci[c].h;
    u8 v = ctx->ci[c].v;
    int hv;

    if (mx >= ctx->mcuw || my >= ctx->mcuh || by >= v || bx >= h)
        return 0;
    hv = h * v;
    mx *= hv;
    my *= ctx->mcuw * hv;
    coef += my + mx;
    by *= h;
    coef += by + bx;
    return *coef;
}

int decodeHuffmanCode_307A4(JDCTX *ctx, int cls, int comp) {
    JHTAB *t;
    unsigned int code;
    unsigned int len;
    unsigned int i;
    int b;
    int id;

    code = 0;
    len = 0;
    i = 0;
    if (cls != 0) {
        id = ctx->comp[comp].ac;
    } else {
        id = ctx->comp[comp].dc;
    }
    t = &ctx->huff[cls][id];
    while (i < t->count && len < 16) {
        len++;
        code <<= 1;
        b = getBits(ctx->bs, 1);
        if (b < 0) {
            return b;
        }
        code |= b;
        while (t->len[i] == len) {
            if (t->code[i] == code) {
                return t->val[i];
            }
            i++;
            if (i >= t->count) {
                break;
            }
        }
    }
    return -1;
}

int decodeHuffmanBlock_DC_first(JPCTX *ctx, int c, int tbl) {
    s16 v;
    int s;

    v = 0;
    s = decodeHuffmanCode_307A4((JDCTX *)ctx, 0, tbl);
    if (s > 0) {
        v = getBits(ctx->bs, s);
        if (v < 0) {
            return -1;
        }
        if (((v >> (s - 1)) & 1) == 0) {
            v = v - (1 << s) + 1;
        }
    } else if (s < 0) {
        return -1;
    }
    v += ctx->pred[c];
    ctx->pred[c] = v;
    v <<= ctx->al;
    ctx->block[0] = v;
    return 1;
}

int decodeHuffmanBlock_DC_subsequent(JPCTX *ctx) {
    int b;

    b = getBits(ctx->bs, 1);
    if (b < 0) {
        return -1;
    }
    if (b != 0) {
        ctx->block[0] |= 1 << ctx->al;
    }
    return 1;
}

int decodeHuffmanBlock_AC_first(JPCTX *ctx, int c, int tbl) {
    s16 *blk = ctx->block;
    int ss = ctx->ss;
    int se = ctx->se;
    int al = ctx->al;
    int rs;
    int k;
    int pos;
    int r;
    int s;
    int v;

    if (ctx->eobrun != 0) {
        ctx->eobrun--;
        return 1;
    }
    for (k = ss; k <= se; k++) {
        rs = decodeHuffmanCode_307A4((JDCTX *)ctx, 1, tbl);
        if (rs == 0)
            goto ok;
        if (rs < 0)
            goto err;
        r = rs >> 4;
        s = rs & 0xF;
        v = 0;
        if (s != 0) {
            v = getBits(ctx->bs, s);
            if (v < 0)
                goto err;
            if (((v >> (s - 1)) & 1) == 0)
                v = v - (1 << s) + 1;
            v <<= al;
        } else if (r != 15) {
            v = getBits(ctx->bs, r);
            if (v < 0)
                goto err;
            r = (1 << r) + v;
            ctx->eobrun = r - 1;
            goto ok;
        }
        pos = r + k;
        if (pos >= 64)
            goto err;
        blk[natural_order[pos]] = v;
        k = pos;
    }
ok:
    return 1;
err:
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_AC_subsequent);

#ifndef NULL
#define NULL ((void *)0)
#endif
int reviseValue_30F54(int arg0) {
    int var_v1;

    var_v1 = 0;
    if (arg0 >= 0) {
        var_v1 = 0xFF;
        if (arg0 < 0x100) {
            var_v1 = arg0 & 0xFF;
        }
    }
    return var_v1;
}

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} RGB3;

#define RIGHT_SHIFT(x, n) ((shift_temp = (x)) < 0 ? (shift_temp >> (n)) | (~0 << (32 - (n))) : shift_temp >> (n))

int translateRGB_30F74(JPCTX *ctx, int bx, int by) {
    s16 *yp;
    s16 *cb;
    s16 *cr;
    RGB3 *base;
    int w;
    int h;
    int x0;
    int y;
    int x;
    int idx;
    int skip;
    int shift_temp;
    u8 c;

    yp = ctx->out[0];
    cb = ctx->out[1];
    cr = ctx->out[2];
    w = ctx->hmax * 8;
    h = ctx->vmax * 8;
    base = (RGB3 *)ctx->rgb + (by * h * ctx->width + (x0 = bx * w));
    for (y = 0; y < h; y++) {
        for (x = 0; x < w; x++) {
            if (x + x0 >= ctx->width) {
                skip = w - x;
                yp += skip;
                cb += skip;
                cr += skip;
                break;
            }
            idx = y * ctx->width + x;
            c = reviseValue_30F54(*yp + RIGHT_SHIFT(*cr * 0x2CDD - 0x165E80, 13));
            base[idx].r = c;
            c = reviseValue_30F54(*yp - RIGHT_SHIFT(*cb * 0xB03 - 0x57180, 13) - RIGHT_SHIFT(*cr * 0x16DA - 0xB6D00, 13));
            base[idx].g = c;
            c = reviseValue_30F54(*yp + RIGHT_SHIFT(*cb * 0x38B4 - 0x1C4A00, 13));
            yp++;
            base[idx].b = c;
            cb++;
            cr++;
        }
    }
    return 1;
}

int decodeMCU_multi(JPCTX *ctx) {
    int (*fn)();
    int i;
    int x;
    int y;
    u8 h;
    u8 v;

    if (ctx->unkD9 == 0) {
        fn = decodeHuffmanBlock_DC_first;
    } else {
        fn = decodeHuffmanBlock_DC_subsequent;
    }
    for (i = 0; i < ((u8 *)ctx)[0xCA]; i++) {
        v = ctx->ci[i].v;
        h = ctx->ci[i].h;
        for (y = 0; y < v; y++) {
            for (x = 0; x < h; x++) {
                ctx->block = (s16 *)*((int **)((u8 *)ctx + 0xB8))[i]++;
                if (fn(ctx, i, i) == -1) {
                    return -1;
                }
            }
        }
    }
    return 1;
}

int decodeHuffmanBlock_AC_subsequent();

int decodeMCU_single(JPCTX *ctx, int x, int y) {
    int (*fn)();
    int c;
    int ret;
    u8 h;
    u8 v;
    int mx, my, bx, by;

    if (ctx->ss == 0) {
        if (ctx->unkD9 == 0)
            fn = decodeHuffmanBlock_DC_first;
        else
            fn = decodeHuffmanBlock_DC_subsequent;
    } else {
        if (ctx->unkD9 == 0)
            fn = decodeHuffmanBlock_AC_first;
        else
            fn = decodeHuffmanBlock_AC_subsequent;
    }
    if (ctx->ci[0].unk0 != 0)
        c = M2C_FIELD(ctx, u8 *, 0x100) - 1;
    else
        c = M2C_FIELD(ctx, u8 *, 0x100);
    v = ctx->ci[c].v;
    h = ctx->ci[c].h;
    my = y / v;
    mx = x / h;
    by = y % v;
    bx = x % h;
    ctx->block = (s16 *)current_dct(ctx, c, mx, my, bx, by);
    if (ctx->block == NULL)
        return -1;
    if (fn(ctx, c, 0) == -1)
        return -1;
    return 1;
}

void inverseDCT(JPCTX *ctx, int c);

int inverseDCT_MCU(JPCTX *ctx) {
    int stride;
    int v;
    int c;
    int h;
    int sy;
    int sx;
    int by;
    int bx;
    int y;
    int x;
    s16 *out;
    int ys;
    int xs;
    int r;
    int yo;

    stride = ctx->hmax * 8;
    for (c = 0; c < ctx->ncomp; c++) {
        v = ctx->ci[c].v;
        h = ctx->ci[c].h;
        sy = ctx->vmax / v;
        sx = ctx->hmax / h;
        ys = sy * 8;
        xs = sx * 8;
        for (by = 0; by < v; by++) {
            for (bx = 0; bx < h; bx++) {
                ctx->block = (s16 *)*((int **)((u8 *)ctx + 0xB8))[c]++;
                inverseDCT(ctx, c);
                out = ctx->out[c] + (by * stride + bx) * 8;
                for (y = 0; y < ys; y++) {
                    yo = y * stride;
                    r = (y / sy) * 8;
                    for (x = 0; x < xs; x++) {
                        out[yo + x] = ctx->idct[r + x / sx];
                    }
                }
            }
        }
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeProgressiveJPG);
