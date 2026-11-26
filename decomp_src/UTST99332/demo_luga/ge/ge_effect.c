/* cflags: -O2 -frename-registers */
#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int uint;
struct _anon1;
struct _anon1 { /* size 0x10 */
    int state;
    int alpha;
    int step;
    uint color;
};
typedef struct _anon1 geFADE;
struct _anon2;
struct _anon2 { /* size 0x6 */
    short int p[3];
} __attribute__((packed));
typedef struct _anon2 ge2DV16;

extern geFADE geFade;
extern geFADE *pFade;
extern ge2DV16 fade_model[15][2];

void geFadeDraw(void);
void geFadeSetup(int mode, int step, uint c);
int geFadeState(void);


/* SDK prototypes (tools/sdk_protos.h) */
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
void sceGuColor(unsigned int color);
void sceGuDisable(int state);
void sceGuEnable(int state);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
int sceKernelDcacheWritebackAll(void);

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

void geFadeDraw(void)
{
	int alpha;
	geCONTEXT ctx;

	if (pFade->alpha >= 255 || pFade->state == 0) {
		pFade->state = 0;
		return;
	}

	if (pFade->state == 1) {
		alpha = pFade->alpha;
	} else {
		alpha = 255 - pFade->alpha;
	}

	sceGuEnable(4);
	sceGuBlendFunc(0, 2, 3, 0, 0);

	sceGuDisable(9);
	sceGuDisable(1);

	sceGuColor((alpha << 24) | pFade->color);

	sceGumDrawArray(6, 0x800100, 30, NULL, fade_model);

	pFade->alpha += pFade->step;

	if (pFade->alpha >= 255) {
		pFade->state = 0;
		pFade->alpha = 255;
	}

	geGetContext(&ctx);
	if (ctx.blend != -1) {
		sceGuEnable(4);
		sceGuBlendFunc(ctx.blend_param.equ, ctx.blend_param.asel, ctx.blend_param.bsel, ctx.blend_param.afix, ctx.blend_param.bfix);
	} else {
		sceGuDisable(4);
	}

	sceGuEnable(1);
}

void geFadeSetup(int mode, int step, uint c)
{
	int i;

	pFade->state = mode;
	pFade->alpha = 0;
	pFade->step = step;
	pFade->color = c & 0xffffff;

	for (i = 0; i < 15; i++) {
		fade_model[i][0].p[0] = i * 32;
		fade_model[i][0].p[1] = 0;
		fade_model[i][0].p[2] = 0;
		fade_model[i][1].p[0] = i * 32 + 32;
		fade_model[i][1].p[1] = 272;
		fade_model[i][1].p[2] = 0;
	}

	sceKernelDcacheWritebackAll();
}

int geFadeState(void) {
    return pFade->state;
}
