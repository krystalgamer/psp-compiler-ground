#ifndef LO_FRAME_H
#define LO_FRAME_H
/* frames / framesets (lo_frame) */

typedef struct FRAMESIZE {
    int size;                   /* 0x0 */
    s8 type;                    /* 0x4 */
    int x8;
} FRAMESIZE;

typedef struct FRAMESIZES {
    FRAMESIZE *items;           /* 0x0 */
    int count;                  /* 0x4 */
    int cap;                    /* 0x8 */
} FRAMESIZES;

typedef struct FRAMEDATA {
    u8 unk0[0x24];
    int x24;
    u8 unk28[0x14];
    int x3C;
    u8 unk40[0x54];
    int x94;
    int x98;
    u8 unk9C[0xC];
    int xA8;
} FRAMEDATA;

#define FFRAMED(b) (*(FRAMEDATA **)&(b)->geom)

typedef struct FRAMESETDATA {
    int unk0;
    int rows[16];               /* 0x4 */
    int nrows;                  /* 0x44 */
    int cols[16];               /* 0x48 */
    int ncols;                  /* 0x88 */
    int x8C;
    int x90;
    int x94;
    int x98;
    int x9C;
    int borderColor;            /* 0xA0 */
    int borderSize;             /* 0xA4 */
    int xA8;
    int xAC;
} FRAMESETDATA;

#define FSETD(b) (*(FRAMESETDATA **)&(b)->geom)

void setFrameSizeToFramesetBox(int w, int h, BOX *frameset, int v);

#endif
