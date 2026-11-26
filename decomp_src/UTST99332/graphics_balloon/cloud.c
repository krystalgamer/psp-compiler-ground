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

typedef struct {
	int mode;
	struct { float x, y, z; } pos;
	float dir;
	float d;
} CLOUDDAT;

extern CLOUDDAT cloud[10];
extern int texture_mode;

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

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", sort_cloud);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_balloon/nonmatchings/cloud", draw_clouds);

#define MAX_CLOUD	10

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
