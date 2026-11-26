/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfpng.h"
extern u8 D_001326E8[];
int memcmp(const void *a, const void *b, unsigned int n);
void *memset(void *s, int c, unsigned int n);


#ifndef NULL
#define NULL ((void *)0)
#endif

int checkSignature(void *p, unsigned int n) {
    return memcmp(D_001326E8, p, n) == 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int png_createContext(PNGCTX **pctx) {
    PNGCTX *ctx;

    ctx = ESP_malloc(sizeof(PNGCTX));
    if (ctx == NULL) {
        return -1;
    }
    png_initializeContext(ctx);
    *pctx = ctx;
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int png_destroyContext(PNGCTX *ctx) {
    if (ctx->gammaTable != NULL) {
        ESP_free(ctx->gammaTable);
    }
    if (ctx->image != NULL) {
        ESP_free(ctx->image);
    }
    if (ctx->unk4C != NULL) {
        ESP_free(ctx->unk4C);
    }
    if (ctx->palette != NULL) {
        ESP_free(ctx->palette);
    }
    ESP_free(ctx);
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int png_initializeContext(PNGCTX *ctx) {
    memset(ctx, 0, sizeof(PNGCTX));
    ctx->unkC = 0;
    return 0;
}

int png_setBuffer(PNGCTX *ctx, u8 *buf, int size) {
    if (buf == NULL || size < 1) {
        return -1;
    }
    ctx->buf = buf;
    ctx->cur = buf;
    ctx->size = size;
    return 0;
}

int png_readHeader(PNGCTX *ctx) {
    int type;

    if (ctx->size < 8 || !checkSignature(ctx->cur, 8)) {
        return -1;
    }
    ctx->cur += 8;
    if (png_readNextChunk(ctx, &type) < 0) {
        return -1;
    }
    ctx->cur = ctx->buf;
    return 0;
}

int png_decode(PNGCTX *ctx) {
    int type;

    if (ctx->size >= 8 && checkSignature(ctx->cur, 8)) {
        ctx->cur += 8;
        while (png_readNextChunk(ctx, &type) == 0)
            ;
        if (type != 0) {
            return -1;
        }
        if (ctx->image != NULL) {
            return 0;
        }
    }
    return -1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_util", D_001326E8);
