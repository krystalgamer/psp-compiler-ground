#ifndef NFLAYOUT_H
#define NFLAYOUT_H
/* browser layout engine (layoutMain, lo_*): only the fields used so far */

typedef struct {
    int x;
    int y;
    u8 unk8[0x38];
    int unk40;
} BOXGEOM;

typedef struct {
    u8 unk0[0x14];
    unsigned int flags;         /* 0x14: bits 2-3 height type */
} BOXSTYLE;

typedef struct BOX {
    struct BOX *parent;         /* 0x0 */
    u8 unk4[0x1C];
    BOXGEOM *geom;              /* 0x20 */
    BOXSTYLE *style;            /* 0x24 */
    u8 unk28[0x8];
    void *region;               /* 0x30 */
    u8 unk34[0x4];
    s16 content;                /* 0x38: 1 body, 2 frameset, 4 table, 5 tr, 6 td, 8 list, 17 ... */
    s16 html;                   /* 0x3A */
    s16 display;                /* 0x3C */
} BOX;

#endif
