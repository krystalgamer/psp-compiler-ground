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

void do_filter_up(PNGCTX *ctx, u8 *row, u8 *prior, int len, int bpp) {
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

double pow(double x, double y);

int handle_gAMA(PNGCTX *ctx, u8 *data, int len) {
    int i;

    if (len < 4) {
        return -1;
    }
    ctx->gamma = READINT32(&data);
    if (ctx->gammaTable != NULL) {
        return 0;
    }
    ctx->gammaTable = ESP_malloc(256);
    if (ctx->gammaTable == NULL) {
        return -1;
    }
    ctx->gammaTable[0] = 0;
    for (i = 1; i < 256; i++) {
        ctx->gammaTable[i] = pow(i / 255.0, 1.0 / (ctx->gamma / 100000.0 * 2.2)) * 255.0 + 0.5;
    }
    return 0;
}

int handle_pHYs(PNGCTX *ctx, u8 *data, int len) {
    if (len < 9) {
        return -1;
    }
    ctx->physX = READINT32(&data);
    ctx->physY = READINT32(&data);
    ctx->unit = *data++;
    return 0;
}

int handle_tRNS(PNGCTX *ctx, u8 *data, int len) {
    u8 *p;
    u8 *pal;
    int i;
    int v;

    p = data;
    switch (ctx->colorType) {
    case 0:
        if (len < 2)
            return -1;
        ctx->hasTrans = 1;
        v = (data[0] << 8) | data[1];
        ctx->trR = v;
        ctx->trG = v;
        ctx->trB = v;
        break;
    case 2:
        if (len < 6)
            return -1;
        ctx->hasTrans = 1;
        ctx->trR = (data[0] << 8) | data[1];
        p += 2;
        ctx->trG = (p[0] << 8) | p[1];
        p += 2;
        ctx->trB = (p[0] << 8) | p[1];
        break;
    case 3:
        if (ctx->palette == NULL)
            return 0;
        ctx->hasTrans = 1;
        if (ctx->npal < len)
            len = ctx->npal;
        pal = ctx->palette;
        for (i = 0; i < len; i++) {
            *pal = *p++;
            pal += 4;
        }
        break;
    }
    return 0;
}

typedef struct {
    char len[4];
    char type[4];
} CHUNKHDR;

typedef struct {
    char tag[4];
    char *name;
    int (*handler)(PNGCTX *ctx, u8 *data, unsigned int len, int more);
} CHUNKTAB;

extern CHUNKTAB name_tab[];
extern char D_001326F0[];
int memcmp(const void *a, const void *b, unsigned int n);

#define HLEN(h) (*(u32 *)(h).len)

int png_readNextChunk(PNGCTX *ctx, int *type) {
    CHUNKHDR hdr;
    CHUNKHDR next;
    CHUNKTAB *e;
    int more;
    int ret;
    u32 v;
    u8 *p;

    more = 0;
    if (type != NULL) {
        *type = 0;
    }
    if (ctx->size - (ctx->cur - ctx->buf) < 8) {
        return -1;
    }
    hdr = *(CHUNKHDR *)ctx->cur;
    ctx->cur += 8;
    v = HLEN(hdr);
    HLEN(hdr) = (v >> 24) | ((v >> 8) & 0xFF00) | ((v << 8) & 0xFF0000) | (v << 24);
    if ((u32)(ctx->size - (ctx->cur - ctx->buf)) < HLEN(hdr)) {
        HLEN(hdr) = ctx->size - (ctx->cur - ctx->buf);
    }
    for (e = name_tab; e->name != NULL; e++) {
        if (memcmp(hdr.type, e->tag, 4) == 0) {
            break;
        }
    }
    ret = 0;
    if (e->name != NULL) {
        if (memcmp(e->name, D_001326F0, 4) == 0) {
            p = ctx->cur + HLEN(hdr);
            if ((u32)(ctx->buf - p + ctx->size - 4) >= 8) {
                next = *(CHUNKHDR *)(p + 4);
                if (memcmp(next.type, D_001326F0, 4) == 0) {
                    more = 1;
                }
            }
        }
        ret = e->handler(ctx, ctx->cur, HLEN(hdr), more);
    }
    ctx->cur += HLEN(hdr) + 4;
    if ((ret < 0) & (type != NULL)) {
        *type = -1;
    }
    return ret;
}

