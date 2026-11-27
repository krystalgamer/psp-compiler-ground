#include "common.h"

/* SDK prototypes (tools/sdk_protos.h) */
void sceGuClutLoad(int num_blocks, const void *cbp);
void sceGuColor(unsigned int color);
void sceGuDrawArray(int prim, int vtype, int count, const void *indices, const void *vertices);
void sceGuTexImage(int mipmap, int width, int height, int tbw, const void *tbp);
void sceKernelDcacheWritebackAll(void);

typedef unsigned int u_int32;
typedef unsigned short u_short16;
#define BG_TEX_WIDTH 512
#define BG_TEX_HEIGHT 512
#define BG_WORKSIZE (BG_TEX_WIDTH*BG_TEX_HEIGHT/sizeof(int))
#define BG_TEX_BLOCK (BG_TEX_WIDTH/8)
#define SCEGU_PRIM_RECTANGLES 6
#define SCEGU_TEXTURE_USHORT (2<<0)
#define SCEGU_VERTEX_SHORT (2<<7)
#define SCEGU_THROUGH (1<<23)
typedef struct {
	u_short16	u __attribute__((aligned(2)));
	u_short16	v;
	short		p[3];
} __attribute__((packed)) Gu2dVertex16T;
typedef struct {
	u_short16		visible;
	short			x;
	short			y;
	short			w;
	short			h;
	short			cw;
	short			ch;
	short			bw;
	short			bh;
	short			scrollx;
	short			scrolly;
	short			__dummy;
	u_int32			color;
	u_short16		*map;
	u_int32			*chr;
	u_int32			*clut;
	u_int32 		*work;
	Gu2dVertex16T	model[2];
} BGDATA;
void DrawBG(BGDATA *bg)
{
	int		x, y;
	int		num;
	int		i, j, k, l;
	int		bgw, bgh;
	int		cw;
	u_int32	csize;
	u_int32	map;

	if (!bg->visible)
		return;

	bgw = BG_TEX_WIDTH /bg->cw;
	bgh = BG_TEX_HEIGHT/bg->ch;
	cw = bg->cw/8;
	csize = cw*bg->ch;

	for (i = 0; i<bgh; i++) {
		for (j = 0; j<bgw; j++) {
			x = (bg->scrollx+j);
			y = (bg->scrolly+i);

			while (1) {
				if (x >= bg->w)	x -= bg->w;
				else if (x<0)	x += bg->w;
				else			break;
			}
			while (1) {
				if (y >= bg->h)	y -= bg->h;
				else if (y<0)	y += bg->h;
				else			break;
			}

			num = y*bg->w+x;
			map = bg->map[num];

			x = j*cw;
			y = i*bg->ch;

			for (k = 0; k<bg->ch; k++) {
				for (l = 0; l<cw; l++) {
					bg->work[x+(y+k)*BG_TEX_BLOCK+l] =
						bg->chr[map*csize+k*cw+l];
				}
			}
		}
	}

	sceKernelDcacheWritebackAll();

	sceGuClutLoad(1, (void *)bg->clut);
	sceGuTexImage(0, BG_TEX_WIDTH, BG_TEX_HEIGHT, BG_TEX_WIDTH,
					(void *)bg->work);

	bg->model[0].u = 0, bg->model[0].v = 0;
	bg->model[0].p[0] = bg->x;
	bg->model[0].p[1] = bg->y;
	bg->model[0].p[2] = 0;
	bg->model[1].u = bg->bw, bg->model[1].v = bg->bh;
	bg->model[1].p[0] = bg->x + bg->bw;
	bg->model[1].p[1] = bg->y + bg->bh;
	bg->model[1].p[2] = 0;

	sceKernelDcacheWritebackAll();

	sceGuColor(bg->color);
	sceGuDrawArray(SCEGU_PRIM_RECTANGLES,
					SCEGU_TEXTURE_USHORT|SCEGU_VERTEX_SHORT|SCEGU_THROUGH,
					2, 0, (void *)bg->model);
}
