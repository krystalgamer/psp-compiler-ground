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

int geTexSet(int n, geTEXTURE *tex)
{
	geTEXTURE *p;
	int i;
	int ret = 0;

	if (n < 128) {
		if (n >= 0) {
			p = &geTexture[n];

			p->tpf = tex->tpf;
			p->mode_lod = tex->mode_lod;
			p->mode_mc = tex->mode_mc;
			p->mode_hsm = tex->mode_hsm;

			for (i = 0; i < p->mode_lod + 1; i++) {
				p->tex[i].tbp = tex->tex[i].tbp;
				p->tex[i].w = tex->tex[i].w;
				p->tex[i].h = tex->tex[i].h;
				p->tex[i].bw = tex->tex[i].bw;
			}

			p->cpf = tex->cpf;
			p->clut.cbp = tex->clut.cbp;
			p->clut.np = tex->clut.np;
			p->clut.shift = tex->clut.shift;
			p->clut.mask = tex->clut.mask;
			p->clut.csa = tex->clut.csa;

			p->fil_min = 1;
			p->fil_mag = 1;
			p->func_mode = 0;
			p->func_comp = 1;
			p->wrapu = 0;
			p->wrapv = 0;
			p->level_mode = 0;
			p->level_offset = 0.0f;
			p->map_mode = 0;
			p->map_lu = 0;
			p->map_lv = 0;
			p->su = 1.0f;
			p->sv = 1.0f;
			p->tu = 0.0f;
			p->tv = 0.0f;
			p->col = 0;

			ret = 1;
		}
	}

	return ret;
}

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

struct _ctx4;
struct _ctx4 { /* size 0xc */
    float zs;
    float ze;
    uint col;
};
typedef struct _ctx4 geFOG;
struct _ctx5;
struct _ctx5 { /* size 0xc */
    int func;
    int aref;
    int amsk;
};
typedef struct _ctx5 geALPHA;
struct _ctx6;
struct _ctx6 { /* size 0x14 */
    int equ;
    int asel;
    int bsel;
    int afix;
    int bfix;
};
typedef struct _ctx6 geBLEND;
struct _ctx3 { /* size 0x80 */
    int vramdepth;
    int offset_x;
    int offset_y;
    int depth_min;
    int depth_max;
    uint col_clear;
    uint col_ambient;
    uint col_model;
    int depth_test;
    int shade_mode;
    int front_face;
    int clip_plane;
    int normal_patch;
    int normal_prim;
    int cull_face;
    int dither;
    int col_material;
    float specular;
    int fog;
    geFOG fog_param;
    int alpha;
    geALPHA alpha_param;
    int blend;
    geBLEND blend_param;
};
typedef struct _ctx3 geCONTEXT;
void geGetContext(geCONTEXT *context);

int geTexSend(int n)
{
	geTEXTURE *p;
	geCONTEXT ctx;
	int i;
	int ret = 0;

	if (n < 128) {
		if (n >= 0) {
			p = &geTexture[n];

			sceGuBlendFunc(0, 2, 3, 0, 0);

			sceGuEnable(4);
			sceGuEnable(9);

			sceGuTexFunc(p->func_mode, p->func_comp);
			sceGuTexFilter(p->fil_min, p->fil_mag);
			sceGuTexWrap(p->wrapu, p->wrapv);

			sceGuTexLevelMode(p->level_mode, p->level_offset);
			sceGuTexMapMode(p->map_mode, p->map_lu, p->map_lv);
			sceGuTexScale(p->su, p->sv);
			sceGuTexOffset(p->tu, p->tv);
			sceGuTexEnvColor(p->col);

			sceGuTexMode(p->tpf, p->mode_lod, p->mode_mc, p->mode_hsm);
			for (i = 0; i < p->mode_lod + 1; i++) {
				sceGuTexImage(i, p->tex[i].w, p->tex[i].h, p->tex[i].bw, p->tex[i].tbp);
			}

			if (p->tpf >= 4) {
				sceGuClutMode(p->cpf, p->clut.shift, p->clut.mask, p->clut.csa);
				sceGuClutLoad(p->clut.np, p->clut.cbp);
			}

			geGetContext(&ctx);
			if (ctx.blend != -1) {
				sceGuEnable(4);
				sceGuBlendFunc(ctx.blend_param.equ, ctx.blend_param.asel, ctx.blend_param.bsel, ctx.blend_param.afix, ctx.blend_param.bfix);
			} else {
				sceGuDisable(4);
			}

			ret = 1;
		}
	}

	return ret;
}

int geTexCombine(int a, int b) {
    return 1;
}
