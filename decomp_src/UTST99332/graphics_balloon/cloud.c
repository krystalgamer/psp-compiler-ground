#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void *memcpy(void *d, const void *s, unsigned int n);
int rand(void);
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuClutMode(unsigned int cpsm, unsigned int shift, unsigned int mask, unsigned int a3);
void sceGuColor(unsigned int color);
void sceGuEnable(int state);
void sceGuTexFilter(int min, int mag);
void sceGuTexFunc(int tfx, int tcc);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuTexMode(int tpsm, int maxmips, int a2, int swizzle);
void sceGuTexWrap(int u, int v);
void sceGumDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGumPopMatrix(void);
void sceGumPushMatrix(void);

#define MAX_CLOUD	10

enum {
	MODE_IN,
	MODE_FLOAT,
	MODE_OUT
};

enum {
	TEX_PFIDX4,
	TEX_PFIDX8,
	TEX_PF5551,
	TEX_PF5650,
	TEX_PF4444,
	TEX_PF8888,
	TEX_PFIDX4_VRAM,
	TEX_PFIDX8_VRAM,
	TEX_PF5551_VRAM,
	TEX_PF5650_VRAM,
	TEX_PF4444_VRAM,
	TEX_PF8888_VRAM,
	TEX_PF5551_FAST,
	TEX_PF5650_FAST,
	TEX_PF4444_FAST,
	TEX_PF8888_FAST,
	MAX_TEX_PF
};

typedef struct {
	int mode;
	struct { float x, y, z; } pos;
	float dir;
	float d;
} CLOUDDAT;

extern CLOUDDAT cloud[10];
extern int texture_mode;

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", set_texture);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", set_vram_texture);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", init_cloud);

void init_cloud(int i);
void set_vram_texture(void);

void init_clouds(void)
{
	int i;

	for (i = 0; i < 10; i++) {
		init_cloud(i);
	}

	set_vram_texture();
}

int check_clouds(void)
{
	int i;
	int mode;
	CLOUDDAT *p;

	mode = cloud[0].mode;
	if (mode != texture_mode) {
		return 0;
	}

	for (i = 1; i < 10; i++) {
		p = &cloud[i];
		if (p->mode != mode) {
			return 0;
		}
	}

	return 1;
}

extern int index_cloud[];
static void sort_cloud(void)
{
	CLOUDDAT	*p0, *p1;
	int			tmp;
	int			i, j;

	for (i=0; i<MAX_CLOUD; i++)
		index_cloud[i]=i;

	for (i=0; i<MAX_CLOUD-1; i++) {
		for (j=i+1; j<MAX_CLOUD; j++) {
			p0=&cloud[index_cloud[i]];
			p1=&cloud[index_cloud[j]];
			if (p0->pos.z>p1->pos.z) {
				tmp=index_cloud[j];
				index_cloud[j]=index_cloud[i];
				index_cloud[i]=tmp;
			}
		}
	}
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", draw_clouds);

void proc_clouds(void)
{
	int			i;
	CLOUDDAT	*p;

	for (i=0; i<MAX_CLOUD; i++) {
		p=&cloud[i];

		if (p->mode!=texture_mode)
			p->pos.x+=(0.15f*p->dir);
		else
			p->pos.x+=p->d;
		if (p->dir<0.0f) {
			if (p->pos.x<-14.0f)
				init_cloud(i);
		}
		else {
			if (p->pos.x>14.0f)
				init_cloud(i);
		}
	}
}
