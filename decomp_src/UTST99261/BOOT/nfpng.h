#ifndef NFPNG_H
#define NFPNG_H
/* browser PNG decoder (png_util.c, png_chunk.c) */

typedef struct { /* size 0x58 */
    u8 *buf;                /* 0x0 */
    int size;               /* 0x4 */
    u8 *cur;                /* 0x8 */
    int unkC;
    int width;              /* 0x10 */
    int height;             /* 0x14 */
    u8 depth;               /* 0x18 */
    u8 colorType;           /* 0x19 */
    u8 compression;         /* 0x1A */
    u8 filter;              /* 0x1B */
    u8 interlace;           /* 0x1C */
    u8 unk1D[0x3];
    unsigned int gamma;     /* 0x20 */
    unsigned int npal;      /* 0x24 */
    int physX;              /* 0x28 */
    int physY;              /* 0x2C */
    u8 unit;                /* 0x30 */
    u8 *palette;            /* 0x34: RGBA entries */
    int hasTrans;           /* 0x38 */
    u8 *gammaTable;         /* 0x3C */
    s16 trR;                /* 0x40 */
    s16 trG;
    s16 trB;
    void *image;            /* 0x48 */
    void *unk4C;
    int unk50;              /* 0x50: current pass */
    int unk54;              /* 0x54: next row */
} PNGCTX;

void *ESP_malloc(unsigned int size);
void ESP_free(void *p);
int checkSignature(void *p, unsigned int n);
int png_readNextChunk(PNGCTX *ctx, int *type);
int png_initializeContext(PNGCTX *ctx);
u32 READINT32(u8 **pp);
int PaethPredictor(u8 a, u8 b, u8 c);

#endif
