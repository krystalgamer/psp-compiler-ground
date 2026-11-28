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

int glanceDataBlock(u8 *p, u8 *base, int size, int *count, int *end)
{
    int err;
    u8 c;
    int n;

    c = *p;
    while (c != 0) {
        switch (c) {
        case 0x21:
            p = moveByte(p, base, size, 1, &err);
            if ((err == -1) | (p == NULL))
                goto fail;
            c = *p;
            switch (c) {
            case 0xF9:
                p = moveByte(p, base, size, 7, &err);
                if ((err == -1) | (p == NULL))
                    goto fail;
                c = *p;
                continue;
            case 0x01:
                p = moveByte(p, base, size, 0xE, &err);
                break;
            case 0xFE:
                p = moveByte(p, base, size, 1, &err);
                break;
            case 0xFF:
                p = moveByte(p, base, size, 0xD, &err);
                break;
            default:
                goto fail;
            }
            if ((err == -1) | (p == NULL))
                goto fail;
            p = skipDataSubBlocks(p, base, size, &err);
            if (err == -1)
                goto fail;
            break;
        case 0x2C:
            p = moveByte(p, base, size, 9, &err);
            if ((err == -1) | (p == NULL))
                goto fail;
            c = *p;
            p = moveByte(p, base, size, 1, &err);
            if ((err == -1) | (p == NULL))
                goto fail;
            if (c > 0x80)
                p = moveByte(p, base, size, (3 << ((c & 7) + 1)) + 1, &err);
            else
                p = moveByte(p, base, size, 1, &err);
            if ((err == -1) | (p == NULL))
                goto fail;
            p = skipDataSubBlocks(p, base, size, &err);
            if (err != 1) {
                (*count)++;
                goto fail;
            }
            (*count)++;
            break;
        case 0x3B:
            goto done;
        default:
            goto fail;
        }
        p = moveByte(p, base, size, 1, &err);
        if ((err == -1) | (p == NULL))
            goto fail;
        c = *p;
        continue;
    done: /* STAND-IN: the 0x3B case placed at the loop end via a label (matches the block order) */
        *end = 1;
        return 1;
    }
fail:
    return -1;
}

int getFrameNumber(u8 *p, int size)
{
    u8 *data;
    int err;
    int n;
    int x;

    data = p;
    n = 0;
    x = -1;
    p = skipDataSubBlocks(p, data, size, &err);
    if (err != 1) {
        n++;
    } else {
        n++;
        p = moveByte(p, data, size, 1, &err);
        if ((err == -1) | (p == NULL))
            return n;
        glanceDataBlock(p, data, size, &n, &x);
    }
    return n;
}

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
