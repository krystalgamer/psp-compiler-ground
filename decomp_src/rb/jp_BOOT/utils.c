#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0xa */
    short unsigned int u;
    short unsigned int v;
    short int x;
    short int y;
    short int z;
};
typedef struct _anon1 VTypeSprite;
struct _anon2;
struct _anon2 { /* size 0x10 */
    short unsigned int u;
    short unsigned int v;
    float x;
    float y;
    float z;
};
typedef struct _anon2 VTypeSpriteF;
struct _anon3;
struct _anon3 { /* size 0x10 */
    int sw;
    int sh;
    int dw;
    int dh;
};
typedef struct _anon3 F_SPRT;

extern F_SPRT sprite;

void UtilsSpriteMode(int sw, int sh, int dw, int dh);
void UtilsDrawSprite(int x, int y, int z, int u, int v, int flip, int rotate);
void UtilsDrawSpriteF(float x, float y, float z, int u, int v, int flip, int rotate);


extern F_SPRT sprite;
void UtilsSpriteMode(int sw, int sh, int dw, int dh)
{
	sprite.sw = sw;
	sprite.dw = dw;
	sprite.dh = dh;
	sprite.sh = sh;
}

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/utils", UtilsDrawSprite);

INCLUDE_ASM("tmp/asm/rb/jp_BOOT/nonmatchings/utils", UtilsDrawSpriteF);
