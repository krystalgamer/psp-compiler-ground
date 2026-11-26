/* cflags: -O1 */
#include "common.h"
#include "UTST99261/BOOT/nfpng.h"


u32 READINT32(u8 **pp) {
    u8 *p;
    u32 v;

    p = *pp;
    v = *p++ << 24;
    v |= *p++ << 16;
    v |= *p++ << 8;
    v |= *p++;
    *pp += 4;
    return v;
}

int PaethPredictor(u8 a, u8 b, u8 c) {
    int p;
    int pa;
    int pb;
    int pc;

    p = a + b - c;
    pa = p - a;
    if (pa < 0) {
        pa = a - p;
    }
    pb = p - b;
    if (pb < 0) {
        pb = b - p;
    }
    pc = p - c;
    if (pc < 0) {
        pc = c - p;
    }
    if (pa <= pb && pa <= pc) {
        return a;
    }
    if (pb <= pc) {
        return b;
    }
    return c;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", do_scanline);

void do_filter_sub(PNGCTX *ctx, u8 *row, u8 *prior, int len, int bpp) {
    u8 *p;
    u8 left;
    int i;

    p = row;
    left = 0;
    for (i = 0; i < len; i++) {
        if (p - bpp >= row) {
            left = *(p - bpp);
        }
        *p += left;
        p++;
    }
}

void do_filter_up(PNGCTX *ctx, u8 *row, u8 *prior, int len) {
    int i;

    if (prior == NULL) {
        return;
    }
    for (i = 0; i < len; i++) {
        *row += *prior;
        row++;
        prior++;
    }
}

void do_filter_average(PNGCTX *ctx, u8 *row, u8 *prior, int len, int bpp) {
    u8 *p;
    u8 left;
    int i;

    p = row;
    if (prior != NULL) {
        left = 0;
        for (i = 0; i < len; i++) {
            if (p - bpp >= row) {
                left = *(p - bpp);
            }
            *p += (left + *prior) / 2;
            p++;
            prior++;
        }
    } else {
        left = 0;
        for (i = 0; i < len; i++) {
            if (p - bpp >= row) {
                left = *(p - bpp);
            }
            *p += left >> 1;
            p++;
        }
    }
}

void do_filter_paeth(PNGCTX *ctx, u8 *row, u8 *prior, int len, int bpp) {
    u8 *p;
    u8 *q;
    u8 left;
    u8 upleft;
    int i;

    if (prior != NULL) {
        p = row;
        q = prior;
        left = 0;
        upleft = 0;
        for (i = 0; i < len; i++) {
            if (p - bpp >= row) {
                left = *(p - bpp);
                upleft = *(q - bpp);
            }
            *p = PaethPredictor(left, *q, upleft) + *p;
            p++;
            q++;
        }
    } else {
        p = row;
        left = 0;
        for (i = 0; i < len; i++) {
            if (p - bpp >= row) {
                left = *(p - bpp);
            }
            *p = PaethPredictor(left, 0, 0) + *p;
            p++;
        }
    }
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001326F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001326F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132700);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132708);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132710);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132718);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132720);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", srow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", scol);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", irow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", icol);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", bheight);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", bwidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_IDAT);

#ifndef NULL
#define NULL ((void *)0)
#endif
int handle_IEND(void) {
    return 1;
}

int handle_IHDR(PNGCTX *ctx, u8 *data, int len) {
    u8 *p;

    if (len != 13) {
        return -1;
    }
    p = data;
    ctx->width = READINT32(&p);
    ctx->height = READINT32(&p);
    ctx->depth = *p++;
    ctx->colorType = *p++;
    ctx->compression = *p++;
    ctx->filter = *p++;
    ctx->interlace = *p++;
    if (ctx->depth != 1 && ctx->depth != 2 && ctx->depth != 4 && ctx->depth != 8 && ctx->depth != 16) {
        return -1;
    }
    switch (ctx->colorType) {
    case 2:
    case 4:
    case 6:
        if (ctx->depth != 8 && ctx->depth != 16) {
            return -1;
        }
        break;
    case 3:
        if (ctx->depth == 16) {
            return -1;
        }
        break;
    default:
        return -1;
    case 0:
        break;
    }
    if (ctx->colorType & 4) {
        ctx->hasTrans = 1;
    }
    return 0;
}

int handle_PLTE(PNGCTX *ctx, u8 *data, int len) {
    u8 *pal;
    unsigned int i;

    if (len % 3 != 0) {
        return -1;
    }
    ctx->npal = len / 3;
    if (ctx->colorType == 0 || ctx->colorType == 4) {
        return -1;
    }
    if (ctx->colorType == 3 && (1 << ctx->depth) < ctx->npal) {
        return -1;
    }
    if (ctx->palette != NULL) {
        return -1;
    }
    ctx->palette = ESP_malloc(ctx->npal * 4);
    if (ctx->palette == NULL) {
        return -1;
    }
    pal = ctx->palette;
    for (i = 0; i < ctx->npal; i++) {
        pal[1] = *data++;
        pal[2] = *data++;
        pal[3] = *data++;
        pal[0] = 0xFF;
        pal += 4;
    }
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_gAMA);

int handle_pHYs(PNGCTX *ctx, u8 *data, int len) {
    if (len < 9) {
        return -1;
    }
    ctx->physX = READINT32(&data);
    ctx->physY = READINT32(&data);
    ctx->unit = *data++;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_tRNS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", png_readNextChunk);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132788);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_0013278C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132790);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132798);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_0013279C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", length_tab);
