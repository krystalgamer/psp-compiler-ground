/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon2;
struct _anon2 { /* size 0x4 */
    short int u;
    short int v;
};
typedef struct _anon2 geTEXCOORD2D;
struct _anon3;
typedef short unsigned int ushort;
typedef unsigned int uint;
struct _anon3 { /* size 0x10 */
    ushort u;
    ushort v;
    uint c;
    short int p[3];
};
typedef struct _anon3 ge2DV16TC;
struct _anon1 { /* size 0x44 */
    int x;
    int y;
    int w;
    int h;
    int pri;
    int col;
    int tex;
    geTEXCOORD2D tex_uv[2];
    ge2DV16TC model[2];
};
typedef struct _anon1 geSPRITE;

extern geSPRITE geSprite[1024];

int geSpriteSet(int n, geSPRITE *sp);
int geSpriteParam(int n, int param, geSPRITE *sp);
int geSpriteGet(int n, geSPRITE *sp);
int geSpriteDraw(int n);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);

/* module functions defined in other units */
int geTexSend(int n);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_sprite", geSpriteSet);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_sprite", geSpriteParam);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_sprite", geSpriteGet);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_sprite", geSpriteDraw);
