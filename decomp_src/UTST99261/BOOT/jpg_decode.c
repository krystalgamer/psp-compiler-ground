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
    void *bs;                   /* 0x0 */
    u8 unk4[0x10];
    s16 pred[4];                /* 0x14 */
    s16 *block;                 /* 0x1C */
    u8 unk20[0xE0];
    JCOMPSEL comp[4];           /* 0x100 */
    JHTAB huff[2][4];           /* 0x10C */
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

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", translateRGB_30028);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeMCU);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_decode", decodeJPG);
