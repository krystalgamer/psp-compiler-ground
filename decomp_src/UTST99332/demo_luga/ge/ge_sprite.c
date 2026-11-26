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

int geSpriteParam(int n, int param, geSPRITE *sp)
{
	geSPRITE *p;
	int ret = 0;

	if (n < 1024) {
		if (n >= 0) {
			p = &geSprite[n];

			if (param & 1) {
				p->x = sp->x;
				p->y = sp->y;
			}
			if (param & 2) {
				p->w = sp->w;
				p->h = sp->h;
			}
			if (param & 4) {
				p->pri = sp->pri;
			}
			if (param & 8) {
				p->tex = sp->tex;
				p->tex_uv[0].u = sp->tex_uv[0].u;
				p->tex_uv[0].v = sp->tex_uv[0].v;
				p->tex_uv[1].u = sp->tex_uv[1].u;
				p->tex_uv[1].v = sp->tex_uv[1].v;
			}
			if (param & 0x10) {
				p->col = sp->col;
			}
			ret = 1;
		}
	}

	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_sprite", geSpriteGet);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_sprite", geSpriteDraw);
