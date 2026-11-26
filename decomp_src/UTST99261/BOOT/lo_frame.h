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
} FRAMESIZES;

typedef struct FRAMEDATA {
    u8 unk0[0x24];
    int x24;
    u8 unk28[0x6C];
    int x94;
    int x98;
    u8 unk9C[0xC];
    int xA8;
} FRAMEDATA;

#define FFRAMED(b) (*(FRAMEDATA **)&(b)->geom)

void setFrameSizeToFramesetBox(void *a, void *b, BOX *frameset, int v);

#endif
