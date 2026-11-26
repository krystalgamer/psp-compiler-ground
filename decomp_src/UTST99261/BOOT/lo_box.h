#ifndef LO_BOX_H
#define LO_BOX_H
/* layout boxes (types only; nflayout.h has the globals and prototypes) */

typedef struct {
    int x;
    int y;
    u8 unk8[0x38];
    int unk40;
} BOXGEOM;

typedef struct {
    u8 unk0[0x14];
    unsigned int flags;         /* 0x14: bits 2-3 height type */
    int width;                  /* 0x18 */
    int height;                 /* 0x1C */
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    s16 unk32;
    s16 unk34;
    s16 unk36;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    int unk54;
    u8 unk58[0xC];
    int unk64;                  /* 0x64: text color */
    s16 fontSize;               /* 0x68 */
    s16 unk6A;                  /* 0x6A: font style bits */
    u8 unk6C[0x3];
    u8 unk6F;
    u8 unk70[0x3];
    u8 unk73;
} BOXSTYLE;

typedef struct BOX {
    struct BOX *parent;         /* 0x0 */
    struct BOX *child;          /* 0x4: first child */
    struct BOX *prev;           /* 0x8: previous sibling */
    struct BOX *next;           /* 0xC: next sibling */
    int x;                      /* 0x10 */
    int y;                      /* 0x14 */
    int width;                  /* 0x18 */
    int height;                 /* 0x1C */
    BOXGEOM *geom;              /* 0x20 */
    BOXSTYLE *style;            /* 0x24 */
    u8 unk28[0x8];
    void *region;               /* 0x30 */
    u8 unk34[0x4];
    s16 content;                /* 0x38: 1 body, 2 frameset, 4 table, 5 tr, 6 td, 8 list, 17 ... */
    s16 html;                   /* 0x3A */
    s16 display;                /* 0x3C */
} BOX;

typedef struct LISTNODE {
    struct LISTNODE *next;
    struct LISTNODE *prev;
    void *data;
} LISTNODE;

typedef struct {
    LISTNODE *head;
    LISTNODE *tail;
    int count;
} LIST;

#endif
