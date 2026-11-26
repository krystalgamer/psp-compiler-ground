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
    u8 id;
    u8 h;                       /* 0x1 */
    u8 v;                       /* 0x2 */
    u8 unk3[9];
} JCOMP;

typedef struct {
    void *bs;                   /* 0x0 */
    u8 *rgb;                    /* 0x4 */
    s16 *out[3];                /* 0x8 */
    s16 pred[4];                /* 0x14 */
    s16 *block;                 /* 0x1C */
    s16 idct[64];               /* 0x20 */
    u8 unkA0[0x26];
    u16 width;                  /* 0xC6 */
    u8 unkC8[2];
    u8 ncomp;                   /* 0xCA */
    u8 unkCB[0x5];
    u16 mcux;                   /* 0xD0 */
    u8 unkD2[0xA];
    JCOMP comps[3];             /* 0xDC */
    JCOMPSEL comp[4];           /* 0x100 */
    JHTAB huff[2][4];           /* 0x10C */
    u8 unk18C[0x502];
    u8 hmax;                    /* 0x68E */
    u8 vmax;                    /* 0x68F */
    unsigned int restart;       /* 0x690 */
    unsigned int rcount;        /* 0x694 */
    int lines;                  /* 0x698 */
} JDCTX;

int getBits(void *bs, int n);
extern const int natural_order[];


int decodeHuffmanCode_2FCA4(JDCTX *ctx, int cls, int comp) {
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeHuffmanBlock);

#ifndef NULL
#define NULL ((void *)0)
#endif
int reviseValue_30008(int arg0) {
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

typedef struct { u8 r; u8 g; u8 b; } RGB3;

#define RIGHT_SHIFT(x, n) ((shift_temp = (x)) < 0 ? (shift_temp >> (n)) | (~0 << (32 - (n))) : shift_temp >> (n))

int translateRGB_30028(JDCTX *ctx, int bx, int by) {
    s16 *yp;
    s16 *cb;
    s16 *cr;
    RGB3 *base;
    int x0;
    int w;
    int h;
    int y;
    int x;
    int idx;
    int skip;
    int shift_temp;
    u8 c;

    yp = ctx->out[0];
    cb = ctx->out[1];
    cr = ctx->out[2];
    base = (RGB3 *)ctx->rgb + ((by * ctx->vmax << 3) * ctx->width + (x0 = bx * ctx->hmax * 8));
    w = ctx->hmax * 8;
    h = ctx->vmax * 8;
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
            c = reviseValue_30008(*yp + RIGHT_SHIFT(*cr * 0x2CDD - 0x165E80, 13));
            base[idx].r = c;
            c = reviseValue_30008(*yp - RIGHT_SHIFT(*cb * 0xB03 - 0x57180, 13) - RIGHT_SHIFT(*cr * 0x16DA - 0xB6D00, 13));
            base[idx].g = c;
            c = reviseValue_30008(*yp + RIGHT_SHIFT(*cb * 0x38B4 - 0x1C4A00, 13));
            yp++;
            base[idx].b = c;
            cb++;
            cr++;
        }
    }
    return 1;
}

void inverseDCT(JDCTX *ctx, int comp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeMCU);

void *ESP_malloc(int n);
void ESP_free(void *p);
void *memset(void *d, int c, unsigned int n);
int getMarker(JDCTX *ctx);

int decodeJPG(JDCTX *ctx, int n) {
    int size;
    int blk;
    int i;
    int bx;
    int by;

    if (n == 0) {
        return -1;
    }
    size = ctx->mcux * ctx->hmax * n * ctx->vmax * 64;
    if (ctx->rgb != NULL) {
        ESP_free(ctx->rgb);
    }
    ctx->rgb = ESP_malloc(size * 3);
    if (ctx->rgb == NULL) {
        return -2;
    }
    memset(ctx->rgb, 0xFF, size * 3);
    blk = ctx->hmax * ctx->vmax * 64;
    ctx->out[0] = ESP_malloc(blk * 2);
    if (ctx->out[0] == NULL) {
        return -2;
    }
    memset(ctx->out[0], 0, blk * 2);
    ctx->out[1] = ESP_malloc(blk * 2);
    if (ctx->out[1] == NULL) {
        return -2;
    }
    i = blk;
    while (i-- != 0) {
        ctx->out[1][i] = 0x80;
    }
    ctx->out[2] = ESP_malloc(blk * 2);
    if (ctx->out[2] == NULL) {
        return -2;
    }
    i = blk;
    while (i-- != 0) {
        ctx->out[2][i] = 0x80;
    }
    ctx->block = ESP_malloc(0x80);
    if (ctx->block == NULL) {
        return -2;
    }
    if (ctx->lines == 0) {
        ctx->pred[0] = 0;
        ctx->pred[1] = 0;
        ctx->pred[2] = 0;
        ctx->rcount = 0;
    }
    for (by = 0; by < n; by++) {
        for (bx = 0; bx < ctx->mcux; bx++) {
            if (decodeMCU(ctx) == -1) {
                goto out;
            }
            translateRGB_30028(ctx, bx, by);
            if (ctx->restart != 0) {
                if (++ctx->rcount >= ctx->restart) {
                    ctx->rcount = 0;
                    if ((unsigned int)(getMarker(ctx) - 0xD0) < 8) {
                        ctx->pred[0] = 0;
                        ctx->pred[1] = 0;
                        ctx->pred[2] = 0;
                    }
                }
            }
        }
    }
out:
    ctx->lines += n;
    ESP_free(ctx->out[0]);
    ESP_free(ctx->out[1]);
    ESP_free(ctx->out[2]);
    ESP_free(ctx->block);
    ctx->out[0] = NULL;
    ctx->out[1] = NULL;
    ctx->out[2] = NULL;
    ctx->block = NULL;
    return 1;
}
