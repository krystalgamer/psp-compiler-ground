/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"
unsigned char getByte(int);                                    /* extern */
short getWord(int, M2C_UNK);                          /* extern */
M2C_UNK skipByte(int, M2C_UNK);                     /* extern */
void *ESP_malloc(M2C_UNK);                          /* extern */
void ESP_free(void *);                           /* extern */
void *memset(void *p, int c, unsigned int n);
int memcmp(const void *a, const void *b, unsigned int n);
int copyByte(int bs, void *dst, int n);

typedef struct GIFDESC { /* size 0x2C */
    struct GIFDESC *next;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    void *unk24;
    void *unk28;
} GIFDESC;

typedef struct {
    int bs;                     /* 0x0 */
    s16 width;                  /* 0x4 */
    s16 height;
    u8 bg;                      /* 0x8 */
    s8 gct;                     /* 0x9 */
    u16 gctCount;               /* 0xA */
    u8 *gpal;                   /* 0xC */
    s8 lct;                     /* 0x10 */
    u8 unk11;
    u16 gctSize;                /* 0x12 */
    u8 *pal;                    /* 0x14 */
    int loop;                   /* 0x18 */
    u8 unk1C[0x8];
    int trans;                  /* 0x24 */
    u8 tr;                      /* 0x28 */
    u8 tg;
    u8 tb;
    u8 transIdx;                /* 0x2B */
    u8 unk2C[0x8];
    int *rows;                  /* 0x34 */
    int rowIdx;                 /* 0x38 */
    int offset;                 /* 0x3C */
    int x;                      /* 0x40 */
    unsigned int line;          /* 0x44 */
    int step;                   /* 0x48 */
    int pass;                   /* 0x4C */
    u8 unk50[4];
    GIFDESC *cur;               /* 0x54 */
    GIFDESC *list;              /* 0x58 */
    u8 unk5C[0x10];
    int unk6C;
    int unk70;
    int unk74;
    u8 unk78[8];
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    u8 unk90[0x100];
    int unk190;
    u8 unk194[0xC198 - 0x194];
    int unkC198;
} GIFP;

typedef struct {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
} GIFBS;

typedef struct {
    void *next;
    s16 left;
    s16 top;
    u16 width;                  /* 0x8 */
    u16 height;
    u8 unkC[4];
    int hasTrans;               /* 0x10 */
    u8 tc[3];                   /* 0x14 */
    u8 unk17[0x11];
    u8 *buf;                    /* 0x28 */
} GIFIMG;

#define CURIMG(c) ((GIFIMG *)(c)->cur)


extern int D_001F3FC4[];
extern unsigned int D_001F3FD8[];
int setTransparentColor(GIFP *ctx) {
    int found;
    u8 r;
    u8 g;
    u8 b;
    int tries;
    int i;
    u8 *p;

    found = 0;
    b = 9;
    g = 9;
    r = 9;
    if (ctx->lct != 0) {
        if (ctx->transIdx >= ctx->gctSize) {
            return -1;
        }
        for (tries = 0; tries < ctx->gctSize * 2; tries++) {
            found = 0;
            for (i = 0; i < ctx->gctSize; i++) {
                p = &ctx->pal[i * 3];
                if ((p[0] & 0xF8) == (r & 0xF8) && (p[1] & 0xF8) == (g & 0xF8) && (p[2] & 0xF8) == (b & 0xF8)) {
                    found = 1;
                    break;
                }
            }
            if (found == 1) {
                if (r < 0xF9) {
                    r += 8;
                } else {
                    r = 9;
                    g += 8;
                }
            }
            if (found == 0) {
                break;
            }
        }
        if (found) {
            return -1;
        }
        ctx->pal[ctx->transIdx * 3] = r;
        ctx->pal[ctx->transIdx * 3 + 1] = g;
        ctx->pal[ctx->transIdx * 3 + 2] = b;
    } else {
        if (ctx->transIdx >= ctx->gctCount) {
            return -1;
        }
        for (tries = 0; tries < ctx->gctCount * 2; tries++) {
            found = 0;
            for (i = 0; i < ctx->gctCount; i++) {
                p = &ctx->gpal[i * 3];
                if ((p[0] & 0xF8) == (r & 0xF8) && (p[1] & 0xF8) == (g & 0xF8) && (p[2] & 0xF8) == (b & 0xF8)) {
                    found = 1;
                    break;
                }
            }
            if (found == 1) {
                if (r < 0xF9) {
                    r += 8;
                } else {
                    r = 9;
                    g += 8;
                }
            }
            if (found == 0) {
                break;
            }
        }
        if (found) {
            return -1;
        }
        ctx->tr = ctx->gpal[ctx->transIdx * 3];
        ctx->tg = ctx->gpal[ctx->transIdx * 3 + 1];
        ctx->tb = ctx->gpal[ctx->transIdx * 3 + 2];
        ctx->trans = 1;
        ctx->gpal[ctx->transIdx * 3] = r;
        ctx->gpal[ctx->transIdx * 3 + 1] = g;
        ctx->gpal[ctx->transIdx * 3 + 2] = b;
    }
    ((u8 *)ctx->cur)[0x14] = r;
    ((u8 *)ctx->cur)[0x15] = g;
    ((u8 *)ctx->cur)[0x16] = b;
    return 1;
}

int storePixel(GIFP *ctx, int c) {
    GIFIMG *img;

    if (c < ctx->gctSize && c >= 0 && ctx->pal != NULL && ctx->lct != 0) {
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset] = ctx->pal[c * 3];
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 1] = ctx->pal[c * 3 + 1];
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 2] = ctx->pal[c * 3 + 2];
    } else if (ctx->gct != 0 && ctx->gpal != NULL && c < ctx->gctCount && c >= 0) {
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset] = ctx->gpal[c * 3];
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 1] = ctx->gpal[c * 3 + 1];
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 2] = ctx->gpal[c * 3 + 2];
    } else if (CURIMG(ctx)->hasTrans != 0) {
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset] = CURIMG(ctx)->tc[0];
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 1] = CURIMG(ctx)->tc[1];
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 2] = CURIMG(ctx)->tc[2];
    } else {
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset] = 0;
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 1] = 0;
        CURIMG(ctx)->buf[ctx->x * 3 + ctx->offset + 2] = 0;
    }
    ctx->x++;
    img = CURIMG(ctx);
    if (ctx->x == img->width) {
        ctx->x = 0;
        ctx->line += ctx->step;
        ctx->offset += img->width * ctx->step * 3;
        while (ctx->line >= img->height) {
            ctx->pass++;
            ctx->step = D_001F3FC4[ctx->pass];
            ctx->line = D_001F3FD8[ctx->pass];
            ctx->offset = img->width * ctx->line * 3;
        }
    }
    return 1;
}

int readColorTable(GIFP *ctx, int flag) {
    u8 rgb[4];
    int i;

    if (ctx->pal != NULL) {
        ESP_free(ctx->pal);
        ctx->pal = NULL;
    }
    if (flag == 1 && ctx->gpal != NULL) {
        ESP_free(ctx->gpal);
        ctx->gpal = NULL;
    }
    ctx->pal = ESP_malloc(ctx->gctSize * 3);
    if (ctx->pal == NULL) {
        return -2;
    }
    if (flag == 1) {
        ctx->gpal = ESP_malloc(ctx->gctCount * 3);
        if (ctx->gpal == NULL) {
            return -2;
        }
    }
    for (i = 0; i < ctx->gctSize; i++) {
        copyByte(ctx->bs, rgb, 3);
        ctx->pal[i * 3] = rgb[0];
        ctx->pal[i * 3 + 1] = rgb[1];
        ctx->pal[i * 3 + 2] = rgb[2];
        if (flag == 1) {
            ctx->gpal[i * 3] = rgb[0];
            ctx->gpal[i * 3 + 1] = rgb[1];
            ctx->gpal[i * 3 + 2] = rgb[2];
        }
    }
    return 1;
}

int readHeader(GIFP *ctx) {
    char sig[0x100];
    unsigned int c;

    memset(sig, 0, 0x100);
    copyByte(ctx->bs, sig, 6);
    if (memcmp(sig, "GIF87a", 6) != 0 || memcmp(sig, "GIF89a", 6) != 0) {
    }
    ctx->width = getWord(ctx->bs, 0);
    ctx->height = getWord(ctx->bs, 0);
    c = getByte(ctx->bs);
    ctx->gct = (c & 0x80) >> 7;
    ctx->gctSize = 2 << (c & 7);
    if (ctx->gct) {
        ctx->gctCount = ctx->gctSize;
    } else {
        ctx->gctCount = 0;
    }
    ctx->bg = getByte(ctx->bs);
    skipByte(ctx->bs, 1);
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int readGraphicControlExtension(void *arg0) {
    unsigned char temp_v0;

    skipByte(M2C_FIELD(arg0, int *, 0), 1);
    temp_v0 = getByte(M2C_FIELD(arg0, int *, 0));
    M2C_FIELD(arg0, signed char *, 0x20) = (signed char) (temp_v0 & 1);
    M2C_FIELD(arg0, int *, 0x2C) = (int) ((temp_v0 >> 2) & 7);
    M2C_FIELD(arg0, short *, 0x30) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    M2C_FIELD(arg0, unsigned char *, 0x2B) = getByte(M2C_FIELD(arg0, int *, 0));
    return -(getByte(M2C_FIELD(arg0, int *, 0)) != 0) | 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int readImageDescriptor(void *arg0) {
    int temp_v0;
    unsigned int temp_v1;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;

    temp_s0 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0, short *, 4) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    temp_s0_2 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0_2, short *, 6) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    temp_s0_3 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0_3, short *, 8) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    temp_s0_4 = M2C_FIELD(arg0, void **, 0x54);
    M2C_FIELD(temp_s0_4, short *, 0xA) = getWord(M2C_FIELD(arg0, int *, 0), 0);
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x54), unsigned short *, 0x1C) = (unsigned short) M2C_FIELD(arg0, unsigned short *, 0x30);
    temp_v0 = getByte(M2C_FIELD(arg0, int *, 0));
    temp_v1 = (unsigned int) (temp_v0 & 0x80) >> 7;
    M2C_FIELD(arg0, signed char *, 0x10) = (signed char) temp_v1;
    M2C_FIELD(arg0, signed char *, 0x32) = (signed char) ((unsigned int) (temp_v0 & 0x40) >> 6);
    if (temp_v1 != 0) {
        M2C_FIELD(arg0, short *, 0x12) = (short) (2 << (temp_v0 & 7));
    }
    return 1;
}

int readApplicationExtension(GIFP *ctx) {
    u8 n;

    n = getByte(ctx->bs);
    skipByte(ctx->bs, n);
    while ((n = getByte(ctx->bs)) != 0) {
        switch (n) {
        case 3:
            skipByte(ctx->bs, 1);
            ctx->loop = getWord(ctx->bs, 0);
            if (ctx->loop == 0) {
                ctx->loop = -1;
            }
            break;
        case 5:
            skipByte(ctx->bs, 5);
            break;
        }
    }
    return 1;
}

int readOtherExtension(GIFP *ctx) {
    u8 n;

    while ((n = getByte(ctx->bs)) != 0) {
        skipByte(ctx->bs, n);
    }
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", readImageBlock);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", storePixelInterlace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", getGifScanLinesInterlace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", getGifScanLines);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", GIFParser);

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

int createGifContext(void **arg0) {
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = ESP_malloc(0xC19C);
    if ((temp_v0 == NULL) || (memset(temp_v0, 0, 0xC19CU), temp_v0_2 = ESP_malloc(0x1C), (temp_v0_2 == NULL))) {
        *arg0 = NULL;
        return -2;
    }
    M2C_FIELD(temp_v0_2, int *, 0) = 0;
    M2C_FIELD(temp_v0_2, int *, 4) = 0;
    M2C_FIELD(temp_v0_2, int *, 8) = 0;
    M2C_FIELD(temp_v0_2, int *, 0xC) = 0;
    M2C_FIELD(temp_v0_2, int *, 0x14) = 0;
    M2C_FIELD(temp_v0_2, int *, 0x18) = 0;
    M2C_FIELD(temp_v0, void **, 0) = temp_v0_2;
    M2C_FIELD(temp_v0_2, int *, 0x10) = 7;
    M2C_FIELD(M2C_FIELD(temp_v0, void **, 0), int *, 0x14) = 1;
    M2C_FIELD(M2C_FIELD(temp_v0, void **, 0), int *, 0x18) = 1;
    M2C_FIELD(temp_v0, int *, 0x6C) = -1;
    M2C_FIELD(temp_v0, int *, 0x70) = 0;
    M2C_FIELD(temp_v0, int *, 0x74) = 0;
    M2C_FIELD(temp_v0, int *, 0x80) = 0;
    M2C_FIELD(temp_v0, int *, 0x84) = 0;
    M2C_FIELD(temp_v0, int *, 0x88) = 0;
    M2C_FIELD(temp_v0, int *, 0x8C) = -2;
    M2C_FIELD(temp_v0, int *, 0x190) = 0;
    *arg0 = temp_v0;
    return 1;
}

int initializeGifContext(GIFP *ctx) {
    GIFBS *b;
    GIFDESC *d;
    GIFDESC *n;

    b = (GIFBS *)ctx->bs;
    b->unk0 = 0;
    b->unk4 = 0;
    b->unk8 = 0;
    b->unkC = 0;
    b->unk10 = 0;
    b->unk14 = 0;
    b->unk18 = 0;
    ((GIFBS *)ctx->bs)->unk10 = 7;
    ((GIFBS *)ctx->bs)->unk14 = 1;
    ((GIFBS *)ctx->bs)->unk18 = 1;
    ctx->unk6C = -1;
    ctx->unk70 = 0;
    ctx->unk74 = 0;
    ctx->unk80 = 0;
    ctx->unk84 = 0;
    ctx->unk88 = 0;
    ctx->unk8C = -2;
    ctx->unk190 = 0;
    if (ctx->pal != NULL) {
        ESP_free(ctx->pal);
        ctx->pal = NULL;
    }
    if (ctx->gpal != NULL) {
        ESP_free(ctx->gpal);
        ctx->gpal = NULL;
    }
    for (d = ctx->list; d != NULL; d = n) {
        n = d->next;
        if (d->unk28 != NULL) {
            ESP_free(d->unk28);
        }
        if (d->unk24 != NULL) {
            ESP_free(d->unk24);
        }
        ESP_free(d);
    }
    ctx->cur = NULL;
    ctx->list = NULL;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int deleteGifContext(void *arg0) {
    int var_v0;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_a0_5;
    void *temp_s1;
    void *var_s0;

    var_v0 = -1;
    if (arg0 != NULL) {
        temp_a0 = M2C_FIELD(arg0, void **, 0);
        if (temp_a0 != NULL) {
            ESP_free(temp_a0);
        }
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x14);
        if (temp_a0_2 != NULL) {
            ESP_free(temp_a0_2);
        }
        temp_a0_3 = M2C_FIELD(arg0, void **, 0xC);
        if (temp_a0_3 != NULL) {
            ESP_free(temp_a0_3);
        }
        var_s0 = M2C_FIELD(arg0, void **, 0x58);
        if (var_s0 != NULL) {
            do {
                temp_a0_4 = M2C_FIELD(var_s0, void **, 0x28);
                temp_s1 = M2C_FIELD(var_s0, void **, 0);
                if (temp_a0_4 != NULL) {
                    ESP_free(temp_a0_4);
                }
                temp_a0_5 = M2C_FIELD(var_s0, void **, 0x24);
                if (temp_a0_5 != NULL) {
                    ESP_free(temp_a0_5);
                }
                ESP_free(var_s0);
                var_s0 = temp_s1;
            } while (temp_s1 != NULL);
        }
        ESP_free(arg0);
        var_v0 = 1;
    }
    return var_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int setGifBuffer(void **arg0, int arg1, int arg2) {
    void *temp_v1;
    void *temp_v1_2;

    M2C_FIELD(*arg0, int *, 0) = arg1;
    M2C_FIELD(*arg0, int *, 0xC) = arg2;
    temp_v1 = *arg0;
    M2C_FIELD(temp_v1, int *, 8) = (int) (M2C_FIELD(temp_v1, int *, 0) + M2C_FIELD(temp_v1, int *, 0xC));
    temp_v1_2 = *arg0;
    M2C_FIELD(temp_v1_2, int *, 4) = (int) M2C_FIELD(temp_v1_2, int *, 0);
    return 1;
}

int createImageDescriptor(GIFP *ctx) {
    GIFDESC *d;
    GIFDESC *p;
    GIFDESC *prev;

    d = ESP_malloc(sizeof(GIFDESC));
    if (d == NULL) {
        return -2;
    }
    d->next = NULL;
    d->unk4 = 0;
    d->unk8 = 0;
    d->unkC = 0;
    d->unk10 = 0;
    d->unk14 = 0;
    d->unk18 = 0;
    d->unk1C = 0;
    d->unk20 = 0;
    d->unk24 = 0;
    d->unk28 = 0;
    if (ctx->list != NULL) {
        prev = ctx->list;
        for (p = prev->next; p != NULL; p = p->next) {
            prev = p;
        }
        prev->next = d;
    } else {
        ctx->list = d;
    }
    ctx->cur = d;
    return 1;
}

int createInterlaceOrder(GIFP *ctx, int lines) {
    int *idx[4];
    int *pos[4];
    int cnt[4];
    int n;
    int i;
    int j;
    int height;
    int line;
    int *order;
    int p1;
    int start;
    int p2;
    int p3;
    int m;

    n = 0;
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    height = CURIMG(ctx)->height;
    start = ctx->unkC198;
    for (i = 0; i < 4; i++) {
        idx[i] = ESP_malloc((lines / 2) * 4 + 4);
        if (idx[i] == NULL) {
            return -2;
        }
    }
    for (i = 0; i < 4; i++) {
        pos[i] = ESP_malloc((lines / 2) * 4 + 4);
        if (pos[i] == NULL) {
            return -2;
        }
    }
    order = ESP_malloc(lines * 8);
    if (order == NULL) {
        return -2;
    }
    line = start;
    p1 = (height - 1) / 8 + 1;
    p2 = (height + 3) / 8;
    p3 = (height + 1) / 2;
    for (i = 0; i < lines; i++, line++) {
        m = line % 8;
        switch (m) {
        case 0:
            idx[0][cnt[0]] = i;
            pos[0][cnt[0]] = line / 8;
            cnt[0]++;
            break;
        case 4:
            idx[1][cnt[1]] = i;
            pos[1][cnt[1]] = p1 + line / 8;
            cnt[1]++;
            break;
        case 2:
        case 6:
            idx[2][cnt[2]] = i;
            pos[2][cnt[2]] = p1 + p2 + line / 4;
            cnt[2]++;
            break;
        default:
            idx[3][cnt[3]] = i;
            pos[3][cnt[3]] = p3 + (line - 1) / 2;
            cnt[3]++;
            break;
        }
    }
    for (j = 0; j < 4; j++) {
        for (i = 0; i < cnt[j]; i++) {
            order[n++] = idx[j][i];
            order[n++] = pos[j][i];
        }
    }
    for (i = 0; i < 4; i++) {
        ESP_free(idx[i]);
    }
    for (i = 0; i < 4; i++) {
        ESP_free(pos[i]);
    }
    ctx->rows = order;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int deleteInterlaceOrder(void *arg0) {
    int temp_a0;

    temp_a0 = M2C_FIELD(arg0, int *, 0x34);
    if (temp_a0 != 0) {
        ESP_free(temp_a0);
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", zigzag_order);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/gif_parser", natural_order);
