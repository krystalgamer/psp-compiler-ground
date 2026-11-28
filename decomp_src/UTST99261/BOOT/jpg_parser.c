/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"

typedef struct {
    u8 *cur;                    /* 0x0 */
    u8 *base;                   /* 0x4 */
    u8 *end;                    /* 0x8 */
    int unkC;
    int bit;                    /* 0x10 */
    int unk14;
    int valid;                  /* 0x18 */
} JBS;

typedef struct {
    JBS *bs;                    /* 0x0 */
    u8 unk4[0xC4];
    u16 lines;                  /* 0xC8 */
    u8 unkCA[0xA];
    u8 jfif;                    /* 0xD4 */
} JCTX;

extern int (*markerTable[])(JCTX *ctx);
int getWord(JBS *bs, int n);
int skipByte(JBS *bs, int n);
void nextByte(JBS *bs);
int getByte(JBS *bs);
int getMarker(JCTX *ctx);
int readMarker(JCTX *ctx);
extern const u8 kBitMaskTLSB[];
extern const u8 kBitMaskTMSB[];

typedef struct {
    u8 unk0[0x10];
    int width;
    int height;
    u8 unk18[0x20];
    int hasTrans;               /* 0x38 */
    u8 unk3C[0xC];
    void *image;                /* 0x48 */
    void *unk4C;
} JPNGCTX;

typedef struct {
    int width;
    int height;
    int alpha;
    int unkC;
    void *image;
    void *unk14;
} JIMGINFO;

int png_decode(JPNGCTX *ctx);
int png_readHeader(JPNGCTX *ctx);
M2C_UNK *ESP_malloc(M2C_UNK);                       /* extern */

M2C_UNK sortImage();                                /* extern */
int png_createContext();                            /* extern */
int png_destroyContext();                           /* extern */
int png_initializeContext();                        /* extern */
int png_setBuffer();                                /* extern */


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memcpy(void *, const void *, unsigned int);
int mrkRES(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkTEM(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkERR(void) {
    return -1;
}

int mrkDNL(JCTX *ctx) {
    int ret;

    if (getWord(ctx->bs, 1) != 4) {
        ret = -1;
    } else {
        ctx->lines = getWord(ctx->bs, 1);
        ret = ctx->lines ? 1 : -1;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", mrkSOF0);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF1(void) {
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", mrkSOF2);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF3(void) {
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", mrkDHT);

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF5(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF6(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF7(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF9(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF10(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF11(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkDAC(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF13(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF14(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOF15(void) {
    return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST0(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST1(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST2(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST3(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST4(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST5(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST6(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkRST7(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkSOI(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkEOI(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", mrkSOS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", mrkDQT);

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkDRI(void *arg0) {
    skipByte(M2C_FIELD(arg0, int *, 0), 2);
    M2C_FIELD(arg0, int *, 0x690) = getWord(M2C_FIELD(arg0, int *, 0), 1);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkDHP(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkEXP(void) {
    return 1;
}

int copyByte(JBS *bs, void *dst, int n);
int strncmp(const char *a, const char *b, unsigned int n);

int mrkAPP0(JCTX *ctx) {
    char buf[5];
    u16 len;

    len = getWord(ctx->bs, 1);
    if (len < 2) {
        return -1;
    }
    copyByte(ctx->bs, buf, 5);
    if (strncmp("JFIF", buf, 4) == 0) {
        ctx->jfif = 1;
        goto ok;
    }
    if (strncmp("JFXX", buf, 4) == 0) {
        ctx->jfif = 2;
        goto ok;
    }
    ctx->jfif = 0;
    return -1;
ok:
    skipByte(ctx->bs, len - 7);
    return 1;
}

const char D_001326CC[] = "";

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP1(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP2(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP3(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP4(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP5(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP6(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP7(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP8(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP9(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP10(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP11(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP12(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP13(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkAPP14(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkAPP15(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG0(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG1(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG2(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG3(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG4(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG5(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG6(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG7(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG8(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG9(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG10(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG11(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG12(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int mrkJPG13(void) {
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int mrkCOM(int *arg0) {
    skipByte(*arg0, getWord(*arg0, 1) - 2);
    return 1;
}

int readMarker(JCTX *ctx) {
    int m;

    m = getMarker(ctx);
    if (m != -1 && markerTable[m](ctx) != -1) {
        return m;
    }
    return -1;
}

int getMarker(JCTX *ctx) {
    int c;

    for (;;) {
        if (!ctx->bs->valid) {
            return -1;
        }
        if (getByte(ctx->bs) != 0xFF) {
            continue;
        }
        c = getByte(ctx->bs);
        if (c != 0) {
            return c;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", analysisMarker);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", analysisScans);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

int createJpgContext(M2C_UNK **arg0) {
    M2C_UNK *temp_v0;
    M2C_UNK *temp_v0_2;

    temp_v0 = ESP_malloc(0x6A4);
    if ((temp_v0 == NULL) || (memset(temp_v0, 0, 0x6A4U), temp_v0_2 = ESP_malloc(0x1C), (temp_v0_2 == NULL))) {
        *arg0 = NULL;
        return -2;
    }
    M2C_FIELD(temp_v0_2, M2C_UNK **, 0) = NULL;
    M2C_FIELD(temp_v0_2, int *, 4) = 0;
    M2C_FIELD(temp_v0_2, int *, 8) = 0;
    M2C_FIELD(temp_v0_2, int *, 0xC) = 0;
    M2C_FIELD(temp_v0_2, int *, 0x14) = 0;
    M2C_FIELD(temp_v0_2, int *, 0x18) = 0;
    *temp_v0 = temp_v0_2;
    M2C_FIELD(temp_v0_2, int *, 0x10) = 7;
    M2C_FIELD(*temp_v0, int *, 0x14) = 1;
    M2C_FIELD(*temp_v0, int *, 0x18) = 1;
    *arg0 = temp_v0;
    return 1;
}

typedef struct {
    int unk0;
    void *len;
    void *code;
    void *val;
} JHUFF;

typedef struct {
    void *bs;                   /* 0x0 */
    void *image;                /* 0x4 */
    void *buf[3];               /* 0x8 */
    u8 unk14[0x8];
    void *unk1C;                /* 0x1C */
    u8 unk20[0x80];
    void *dc[3];                /* 0xA0 */
    void *ac[3];                /* 0xAC */
    u8 unkB8[0x12];
    u8 ncomp;                   /* 0xCA */
    u8 unkCB[0x41];
    JHUFF huff[2][4];           /* 0x10C */
} JFULLCTX;

void ESP_free(void *p);

int initializeJpgContext(JFULLCTX *c) {
    int i;
    int j;
    JBS *bs;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            if (c->huff[i][j].len != NULL) {
                ESP_free(c->huff[i][j].len);
            }
            if (c->huff[i][j].code != NULL) {
                ESP_free(c->huff[i][j].code);
            }
            if (c->huff[i][j].val != NULL) {
                ESP_free(c->huff[i][j].val);
            }
        }
    }
    if (c->image != NULL) {
        ESP_free(c->image);
        c->image = NULL;
    }
    if (c->unk1C != NULL) {
        ESP_free(c->unk1C);
        c->unk1C = NULL;
    }
    for (i = 0; i < c->ncomp; i++) {
        if (c->dc[i] != NULL) {
            ESP_free(c->dc[i]);
            c->dc[i] = NULL;
        }
        if (c->ac[i] != NULL) {
            ESP_free(c->ac[i]);
            c->ac[i] = NULL;
        }
    }
    for (i = 0; i < c->ncomp; i++) {
        if (c->buf[i] != NULL) {
            ESP_free(c->buf[i]);
            c->buf[i] = NULL;
        }
    }
    bs = c->bs;
    memset(c, 0, 0x6A4);
    c->bs = bs;
    bs->bit = 7;
    ((JBS *)c->bs)->unk14 = 1;
    ((JBS *)c->bs)->valid = 1;
    return 1;
}

int deleteJpgContext(JFULLCTX *c) {
    int i;
    int j;

    if (c == NULL) {
        return -1;
    }
    if (c->bs != NULL) {
        ESP_free(c->bs);
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            if (c->huff[i][j].len != NULL) {
                ESP_free(c->huff[i][j].len);
            }
            if (c->huff[i][j].code != NULL) {
                ESP_free(c->huff[i][j].code);
            }
            if (c->huff[i][j].val != NULL) {
                ESP_free(c->huff[i][j].val);
            }
        }
    }
    if (c->image != NULL) {
        ESP_free(c->image);
    }
    if (c->unk1C != NULL) {
        ESP_free(c->unk1C);
    }
    for (i = 0; i < c->ncomp; i++) {
        if (c->dc[i] != NULL) {
            ESP_free(c->dc[i]);
        }
        if (c->ac[i] != NULL) {
            ESP_free(c->ac[i]);
        }
    }
    for (i = 0; i < c->ncomp; i++) {
        if (c->buf[i] != NULL) {
            ESP_free(c->buf[i]);
        }
    }
    ESP_free(c);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int setJpgBuffer(void **arg0, int arg1, int arg2) {
    void *temp_v0;
    void *temp_v1;
    void *temp_v1_2;

    if (arg0 != NULL) {
        temp_v0 = *arg0;
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_v0, int *, 0) = arg1;
            M2C_FIELD(*arg0, int *, 0xC) = arg2;
            temp_v1 = *arg0;
            M2C_FIELD(temp_v1, int *, 8) = (int) (M2C_FIELD(temp_v1, int *, 0) + M2C_FIELD(temp_v1, int *, 0xC));
            temp_v1_2 = *arg0;
            M2C_FIELD(temp_v1_2, int *, 4) = (int) M2C_FIELD(temp_v1_2, int *, 0);
            return 1;
        }
    }
    return -1;
}

void nextByte(JBS *bs) {
    if (bs->cur + 1 >= bs->end) {
        bs->valid = 0;
    } else {
        bs->cur++;
    }
}

int getByte(JBS *bs) {
    int c;

    if (!bs->valid) {
        return 0;
    }
    if (bs->bit != 7) {
        nextByte(bs);
        bs->bit = 7;
    }
    if (!bs->valid) {
        return 0;
    }
    c = *bs->cur;
    nextByte(bs);
    bs->unk14 = 1;
    return c;
}

int getWord(JBS *bs, int be) {
    int v;

    if (!bs->valid) {
        return 0;
    }
    if (bs->bit != 7) {
        nextByte(bs);
        bs->bit = 7;
    }
    if (be) {
        v = *bs->cur << 8;
        nextByte(bs);
        v |= *bs->cur;
    } else {
        v = *bs->cur;
        nextByte(bs);
        v |= *bs->cur << 8;
    }
    nextByte(bs);
    return v;
}

int getLong(JBS *bs, int be) {
    int v;

    if (!bs->valid) {
        return 0;
    }
    if (bs->bit != 7) {
        nextByte(bs);
        bs->bit = 7;
    }
    if (be) {
        v = *bs->cur << 24;
        nextByte(bs);
        v |= *bs->cur << 16;
        nextByte(bs);
        v |= *bs->cur << 8;
        nextByte(bs);
        v |= *bs->cur;
    } else {
        v = *bs->cur;
        nextByte(bs);
        v |= *bs->cur << 8;
        nextByte(bs);
        v |= *bs->cur << 16;
        nextByte(bs);
        v |= *bs->cur << 24;
    }
    nextByte(bs);
    return v;
}

int copyByte(JBS *bs, void *dst, int n) {
    if (bs->bit != 7) {
        nextByte(bs);
        bs->bit = 7;
    }
    if (bs->end < bs->cur + n) {
        return -1;
    }
    memcpy(dst, bs->cur, n);
    bs->cur += n;
    if (bs->cur >= bs->end) {
        bs->valid = 0;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", getBits);

int getOneBit(JBS *bs, int lsb) {
    int v;

    v = 0;
    if (bs->bit < 0) {
        bs->bit = 7;
        nextByte(bs);
    }
    v <<= 1;
    if (lsb <= 0) {
        v |= (*bs->cur & kBitMaskTMSB[bs->bit--]) != 0;
    } else {
        v |= (*bs->cur & kBitMaskTLSB[bs->bit--]) != 0;
    }
    return v;
}

int skipByte(JBS *bs, int n) {
    if (bs->end < bs->cur + n) {
        return -1;
    }
    bs->cur += n;
    if (bs->cur >= bs->end) {
        bs->valid = 0;
    }
    return 0;
}

u8 *getNextAddress(JBS *bs) {
    if (bs->bit == 7) {
        return bs->cur;
    }
    if (bs->cur < bs->end) {
        return bs->cur + 1;
    }
    return NULL;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int getCurrentOffset(void *arg0) {
    return M2C_FIELD(arg0, int *, 0) - M2C_FIELD(arg0, int *, 4);
}

int goNextOffset(JBS *bs, int off) {
    if (bs->end < bs->base + off) {
        return -1;
    }
    bs->valid = 1;
    bs->cur = bs->base + off;
    if (bs->cur >= bs->end) {
        bs->valid = 0;
    }
    return 0;
}

void fillBits(JBS *bs) {
    if (bs->bit != 7) {
        bs->bit = 7;
        nextByte(bs);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_sortImage(void) {
    sortImage();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int IMG_pngCreateContext(void) {
    return png_createContext() == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int IMG_pngDestroyContext(void) {
    return png_destroyContext() == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int IMG_pngFinalizeContext(void) {
    return png_initializeContext() == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int IMG_pngInputData(void) {
    return png_setBuffer() == 0;
}

int IMG_pngGetImageData(JPNGCTX *ctx, JIMGINFO *info) {
    if (png_decode(ctx) != 0) {
        return 0;
    }
    info->width = ctx->width;
    info->height = ctx->height;
    info->alpha = ctx->hasTrans;
    info->unkC = ctx->height;
    info->image = ctx->image;
    info->unk14 = ctx->unk4C;
    return 1;
}

int IMG_pngReadHeader(JPNGCTX *ctx, JIMGINFO *info) {
    if (png_readHeader(ctx) != 0) {
        return 0;
    }
    info->width = ctx->width;
    info->height = ctx->height;
    info->alpha = ctx->hasTrans;
    info->unkC = 0;
    info->image = NULL;
    info->unk14 = NULL;
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", D_001326D0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", D_001326D4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", kBitMaskTMSB);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/jpg_parser", kBitMaskTLSB);
