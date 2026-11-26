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
    u8 unk4[0x10];
    s16 pred[4];                /* 0x14 */
    s16 *block;                 /* 0x1C */
    u8 unk20[0x8C];
    int *coef[4];               /* 0xAC */
    u8 unkBC[0x14];
    u16 mcuw;                   /* 0xD0 */
    u16 mcuh;                   /* 0xD2 */
    u8 unkD4[3];
    u8 ss;                      /* 0xD7 */
    u8 se;                      /* 0xD8 */
    u8 unkD9;
    u8 al;                      /* 0xDA */
    u8 unkDB;
    JCOMPINFO ci[4];            /* 0xDC */
    u8 unk10C[0x590];
    int eobrun;                 /* 0x69C */
} JPCTX;

extern const int natural_order[];

typedef struct {
    void *bs;
    u8 unk4[0xFC];
    JCOMPSEL comp[4];           /* 0x100 */
    JHTAB huff[2][4];           /* 0x10C */
} JDCTX;

int getBits(void *bs, int n);


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", current_dct);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeHuffmanBlock_AC_first);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", translateRGB_30F74);

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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeMCU_single);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", inverseDCT_MCU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_pdecode", decodeProgressiveJPG);
