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

typedef unsigned int    u_int32;
typedef unsigned short  u_short16;
extern u_short16 pix_tex_pf5650[32768];
extern u_int32 pix_tex_pf8888[32768];
extern void * vramptr[6];
extern u_int32 pix_tex_pfidx8[8192];
extern u_short16 pix_tex_pf4444[32768];
extern u_short16 pix_fast_pf5551[32768];
extern u_int32 clut_tex_pfidx8[128];
extern u_int32 pix_fast_pf8888[32768];
extern u_short16 pix_tex_pf5551[32768];
extern u_short16 pix_fast_pf4444[32768];
extern u_int32 clut_tex_pfidx4[8];
extern u_int32 pix_tex_pfidx4[4096];
extern u_short16 pix_fast_pf5650[32768];
#define SCEGU_PFIDX4                       4
#define SCEGU_PFIDX8                       5
#define SCEGU_TEXBUF_NORMAL                0
#define SCEGU_PF5551                       1
#define SCEGU_PF5650                       0
#define SCEGU_PF4444                       2
#define SCEGU_PF8888                       3
#define SCEGU_SINGLE_CLUT                  0
#define SCEGU_TEXBUF_FAST                  1
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#define SCEGU_VRAM_WIDTH      512
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)

static void set_texture(int mode)
{
	switch (mode) {
	
	case TEX_PFIDX4:
		sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
		sceGuClutLoad(1, (void *)clut_tex_pfidx4);
		sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_tex_pfidx4);
		break;
	case TEX_PFIDX8:
		sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
		sceGuClutLoad(16, (void *)clut_tex_pfidx8);
		sceGuTexMode(SCEGU_PFIDX8, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_tex_pfidx8);
		break;
	case TEX_PF5551:
		sceGuTexMode(SCEGU_PF5551, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_tex_pf5551);
		break;
	case TEX_PF5650:
		sceGuTexMode(SCEGU_PF5650, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_tex_pf5650);
		break;
	case TEX_PF4444:
		sceGuTexMode(SCEGU_PF4444, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_tex_pf4444);
		break;
	case TEX_PF8888:
		sceGuTexMode(SCEGU_PF8888, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_tex_pf8888);
		break;
	
	case TEX_PFIDX4_VRAM:
		sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
		sceGuClutLoad(1, (void *)vramptr[0]);
		sceGuTexMode(SCEGU_PFIDX4, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)((u_int32)vramptr[0]+sizeof(clut_tex_pfidx4)));
		break;
	case TEX_PFIDX8_VRAM:
		sceGuClutMode(SCEGU_PF5551, 0, 0xff, 0);
		sceGuClutLoad(16, (void *)vramptr[1]);
		sceGuTexMode(SCEGU_PFIDX8, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)((u_int32)vramptr[1]+sizeof(clut_tex_pfidx8)));
		break;
	case TEX_PF5551_VRAM:
		sceGuTexMode(SCEGU_PF5551, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)vramptr[2]);
		break;
	case TEX_PF5650_VRAM:
		sceGuTexMode(SCEGU_PF5650, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)vramptr[3]);
		break;
	case TEX_PF4444_VRAM:
		sceGuTexMode(SCEGU_PF4444, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)vramptr[4]);
		break;
	case TEX_PF8888_VRAM:
		sceGuTexMode(SCEGU_PF8888, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_NORMAL);
		sceGuTexImage(0, 256, 128, 256, (void *)vramptr[5]);
		break;
	
	case TEX_PF5551_FAST:
		sceGuTexMode(SCEGU_PF5551, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_FAST);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_fast_pf5551);
		break;
	case TEX_PF5650_FAST:
		sceGuTexMode(SCEGU_PF5650, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_FAST);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_fast_pf5650);
		break;
	case TEX_PF4444_FAST:
		sceGuTexMode(SCEGU_PF4444, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_FAST);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_fast_pf4444);
		break;
	case TEX_PF8888_FAST:
		sceGuTexMode(SCEGU_PF8888, 0, SCEGU_SINGLE_CLUT, SCEGU_TEXBUF_FAST);
		sceGuTexImage(0, 256, 128, 256, (void *)pix_fast_pf8888);
		break;
	}
}

typedef unsigned char   u_char8;
static void set_vram_texture(void)
{
	u_char8 *vramaddr=(u_char8 *)sceGeEdramGetAddr();
	int		size;

	vramaddr+=SCEGU_VRAM_BUFSIZE32*2+SCEGU_VRAM_BUFSIZE;

	vramptr[0]=vramaddr;
	size=sizeof(clut_tex_pfidx4);
	memcpy(vramaddr,clut_tex_pfidx4,size);
	vramaddr+=size;
	size=sizeof(pix_tex_pfidx4);
	memcpy(vramaddr,pix_tex_pfidx4,size);
	vramaddr+=size;

	vramptr[1]=vramaddr;
	size=sizeof(clut_tex_pfidx8);
	memcpy(vramaddr,clut_tex_pfidx8,size);
	vramaddr+=size;
	size=sizeof(pix_tex_pfidx8);
	memcpy(vramaddr,pix_tex_pfidx8,size);
	vramaddr+=size;

	vramptr[2]=vramaddr;
	size=sizeof(pix_tex_pf5551);
	memcpy(vramaddr,pix_tex_pf5551,size);
	vramaddr+=size;

	vramptr[3]=vramaddr;
	size=sizeof(pix_tex_pf5650);
	memcpy(vramaddr,pix_tex_pf5650,size);
	vramaddr+=size;

	vramptr[4]=vramaddr;
	size=sizeof(pix_tex_pf4444);
	memcpy(vramaddr,pix_tex_pf4444,size);
	vramaddr+=size;

	vramptr[5]=vramaddr;
	size=sizeof(pix_tex_pf8888);
	memcpy(vramaddr,pix_tex_pf8888,size);
	vramaddr+=size;
}

#define SIGN ((rand()%2)?-1.0f:1.0f)
#define RANGERAND(b,u,r) (b+u*(float)(rand()%r))
static void init_cloud(int n)
{
	CLOUDDAT	*p;

	p=&cloud[n];
	p->mode=texture_mode;
	p->pos.x=RANGERAND(14.0f, 0.1f, 10)*SIGN;
	p->pos.y=RANGERAND(0.0f, 0.01f, 200)*SIGN;
	p->pos.z=(rand()%10)<6?RANGERAND(3.0f, 0.1f, 80):-1.0f;

	if (p->pos.z>0.0f)	{
		if (p->pos.x<0.0f)	p->pos.x+=2.0f;
		else				p->pos.x-=2.0f;
	}

	if (p->pos.x<0.0f)	p->dir= 1.0f;
	else				p->dir=-1.0f;

	p->d=RANGERAND(0.015f, 0.001f, 50)*p->dir;
}

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

extern float model[];
extern int index_cloud[];
typedef struct ScePspFVector3 { float x, y, z; } ScePspFVector3;
void sceGumTranslate(const ScePspFVector3 *v);
#define SCEGU_TEXTURE                      9
#define SCEGU_TEX_MODULATE                 0
#define SCEGU_RGBA                         1
#define SCEGU_UV_MAP                       0
#define SCEGU_REPEAT                       0
#define SCEGU_LINEAR                       1
#define SCEGU_PRIM_TRIANGLE_STRIP          4
#define SCEGU_TEXTURE_FLOAT      ( 3 <<  0 )
#define SCEGU_NORMAL_FLOAT       ( 3 <<  5 )
#define SCEGU_VERTEX_FLOAT       ( 3 <<  7 )

void draw_clouds(void)
{
	CLOUDDAT	*p;
	int			i;

	sceGuEnable(SCEGU_TEXTURE);
	sceGuTexFunc(SCEGU_TEX_MODULATE, SCEGU_RGBA);
	sceGuTexMapMode(SCEGU_UV_MAP, 0, 0);
	sceGuTexWrap(SCEGU_REPEAT, SCEGU_REPEAT);
	sceGuTexFilter(SCEGU_LINEAR, SCEGU_LINEAR);

	sort_cloud();
	for (i=0; i<MAX_CLOUD; i++) {
		p=&cloud[index_cloud[i]];
		sceGumPushMatrix();
		sceGumTranslate(&p->pos);

		set_texture(p->mode);

		sceGuColor(0xffffffff);
		sceGumDrawArray(SCEGU_PRIM_TRIANGLE_STRIP,
					SCEGU_TEXTURE_FLOAT|SCEGU_NORMAL_FLOAT|SCEGU_VERTEX_FLOAT,
					4, 0, (void *)model);

		sceGumPopMatrix();
	}
}

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
