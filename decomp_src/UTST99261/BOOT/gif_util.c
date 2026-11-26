/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK createJpgContext();                         /* extern */
M2C_UNK deleteJpgContext();                         /* extern */
M2C_UNK initializeJpgContext();                     /* extern */
M2C_UNK setJpgBuffer();                             /* extern */

typedef struct {
    int unk0;
    void *unk4;
    u8 unk8[0xBE];
    u16 width;                  /* 0xC6 */
    u16 height;                 /* 0xC8 */
    u8 unkCA[0x8];
    u16 ncomp;                  /* 0xD2 */
    u8 unkD4[0x5B9];
    u8 progressive;             /* 0x68D */
    u8 unk68E[0xA];
    int unk698;
} GJCTX;

typedef struct {
    int width;
    int height;
    int ncomp;
    int size;
    s8 progressive;
    void *data;                 /* 0x14 */
} GJINFO;

int analysisMarker(GJCTX *ctx);
int decodeJPG(GJCTX *ctx, int n);
int decodeProgressiveJPG(GJCTX *ctx, int n);


u8 *moveByte(u8 *p, u8 *base, int size, int n, int *err) {
    if (size < p - base + n) {
        *err = -1;
        return NULL;
    }
    *err = 1;
    return p + n;
}

u8 *skipDataSubBlocks(u8 *p, u8 *base, int size, int *err) {
    int e;
    int n;

    n = *p + 1;
    for (;;) {
        p = moveByte(p, base, size, n, &e);
        if (e == -1 || p == NULL) {
            goto error;
        }
        n = *p;
        if (n == 0) {
            break;
        }
        n++;
    }
    *err = 1;
    return p;
error:
    *err = -1;
    return NULL;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", glanceDataBlock);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", getFrameNumber);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", isCompletedImage);

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgCreateContext(void) {
    createJpgContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgDestroyContext(void) {
    deleteJpgContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgFinalizeContext(void) {
    initializeJpgContext();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void IMG_jpgInputData(void) {
    setJpgBuffer();
}

int IMG_jpgReadHeader(GJCTX *ctx, GJINFO *info) {
    int r;

    r = analysisMarker(ctx);
    info->width = ctx->width;
    info->height = ctx->height;
    info->ncomp = ctx->ncomp;
    info->size = ctx->ncomp * ctx->unk698 * 8;
    info->progressive = ctx->progressive;
    info->data = NULL;
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_util", IMG_jpgScanLines);

int IMG_jpgGetImageData(GJCTX *ctx, GJINFO *info) {
    int r;

    if (info->progressive == 0) {
        r = decodeJPG(ctx, ctx->ncomp);
    } else {
        r = decodeProgressiveJPG(ctx, ctx->ncomp);
    }
    info->width = ctx->width;
    info->height = ctx->height;
    info->ncomp = ctx->ncomp;
    info->size = ctx->ncomp * ctx->unk698 * 8;
    info->progressive = ctx->progressive;
    info->data = ctx->unk4;
    return r;
}
