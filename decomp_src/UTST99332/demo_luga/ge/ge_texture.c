/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon2;
struct _anon2 { /* size 0x10 */
    void *tbp;
    int w;
    int h;
    int bw;
};
typedef struct _anon2 geTEXIMAGE;
struct _anon3;
struct _anon3 { /* size 0x14 */
    void *cbp;
    int np;
    int shift;
    int mask;
    int csa;
};
typedef struct _anon3 geCLUT;
typedef unsigned int uint;
struct _anon1 { /* size 0xe8 */
    int tpf;
    int cpf;
    int mode_lod;
    int mode_mc;
    int mode_hsm;
    geTEXIMAGE tex[8];
    geCLUT clut;
    int func_mode;
    int func_comp;
    int fil_min;
    int fil_mag;
    int wrapu;
    int wrapv;
    int level_mode;
    float level_offset;
    int map_mode;
    int map_lu;
    int map_lv;
    float su;
    float sv;
    float tu;
    float tv;
    uint col;
};
typedef struct _anon1 geTEXTURE;

extern geTEXTURE geTexture[128];

int geTexSet(int n, geTEXTURE *tex);
int geTexOption(int n, int param, geTEXTURE *tex);
int geTexGet(int n, geTEXTURE *tex);
int geTexSend(int n);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGuTexEnvColor(unsigned int color);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexOffset(float u, float v);
void sceGuTexScale(float u, float v);
void sceGuTexWrap(int u, int v);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexSet);

int geTexOption(int n, int param, geTEXTURE *tex)
{
	geTEXTURE *p;
	int ret = 0;

	if (n < 128) {
		if (n >= 0) {
			p = &geTexture[n];

			if (param & 1) {
				p->fil_min = tex->fil_min;
				p->fil_mag = tex->fil_mag;
			}
			if (param & 2) {
				p->func_mode = tex->func_mode;
				p->func_comp = tex->func_comp;
			}
			if (param & 4) {
				p->wrapu = tex->wrapu;
				p->wrapv = tex->wrapv;
			}
			if (param & 8) {
				p->level_mode = tex->level_mode;
				p->level_offset = tex->level_offset;
			}
			if (param & 0x10) {
				p->su = tex->su;
				p->sv = tex->sv;
			}
			if (param & 0x20) {
				p->tu = tex->tu;
				p->tv = tex->tv;
			}
			if (param & 0x40) {
				p->col = tex->col;
			}
			if (param & 0x80) {
				p->map_mode = tex->map_mode;
				p->map_lu = tex->map_lu;
				p->map_lv = tex->map_lv;
			}
			ret = 1;
		}
	}

	return ret;
}

int geTexGet(int n, geTEXTURE *tex)
{
	geTEXTURE *p;
	int ret = 0;

	if (n < 128) {
		if (n >= 0) {
			p = &geTexture[n];

			tex->fil_min = p->fil_min;
			tex->fil_mag = p->fil_mag;
			tex->func_mode = p->func_mode;
			tex->func_comp = p->func_comp;
			tex->wrapu = p->wrapu;
			tex->wrapv = p->wrapv;
			tex->level_mode = p->level_mode;
			tex->level_offset = p->level_offset;
			tex->su = p->su;
			tex->sv = p->sv;
			tex->tu = p->tu;
			tex->tv = p->tv;
			tex->col = p->col;
			tex->map_mode = p->map_mode;
			tex->map_lu = p->map_lu;
			tex->map_lv = p->map_lv;

			ret = 1;
		}
	}

	return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/ge_texture", geTexSend);

int geTexCombine(int a, int b) {
    return 1;
}
