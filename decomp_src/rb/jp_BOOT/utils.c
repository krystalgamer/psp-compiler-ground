#include "common.h"
#include <psptypes.h>
#include <libgu.h>

#define SLICE 64

typedef struct {
	unsigned short u, v;
	short x, y, z;
} __attribute__((packed)) VTypeSprite;

typedef struct {
	unsigned short u, v;
	float x, y, z;
} __attribute__((packed)) VTypeSpriteF;

typedef struct {
	int sw, sh;
	int dw, dh;
} F_SPRT;

extern F_SPRT sprite;

void UtilsSpriteMode(int sw, int sh, int dw, int dh)
{
	sprite.sw = sw;
	sprite.dw = dw;
	sprite.dh = dh;
	sprite.sh = sh;
}

void UtilsDrawSprite(int x, int y, int z, int u, int v, int flip, int rotate)
{
	VTypeSprite *vp;

	if (sprite.dw > SLICE) {
		int n;
		int i;

		n = (sprite.dw + SLICE - 1) / SLICE;
		vp = sceGuGetMemory(n * 2 * sizeof(VTypeSprite));
		for (i = 0; i < n * 2; i++) {
			vp[i].u = u + (i - i / 2) * ((sprite.sw * SLICE) / sprite.dw);
			vp[i].v = (i & 1) ? v + sprite.sh : v;
			vp[i].x = x + (i - i / 2) * SLICE;
			vp[i].y = (i & 1) ? y + sprite.dh : y;
			vp[i].z = z;
		}
		i--;
		if (vp[i].x > x + sprite.dw) {
			vp[i].u = sprite.sw + u;
			vp[i].x = sprite.dw + x;
		}
		sceGuDrawArray(6, 0x800102, n * 2, NULL, vp);
	} else {
		vp = sceGuGetMemory(2 * sizeof(VTypeSprite));
		vp[0].u = u;
		vp[0].v = v;
		vp[0].x = x;
		vp[0].y = y;
		vp[0].z = z;
		vp[1].u = sprite.sw + u;
		vp[1].v = sprite.sh + v;
		vp[1].x = sprite.dw + x;
		vp[1].y = sprite.dh + y;
		vp[1].z = z;
		sceGuDrawArray(6, 0x800102, 2, NULL, vp);
	}
}

void UtilsDrawSpriteF(float x, float y, float z, int u, int v, int flip, int rotate)
{
	VTypeSpriteF *vp;
	VTypeSpriteF tmp;

	vp = sceGuGetMemory(2 * sizeof(VTypeSpriteF));
	vp[0].u = u;
	vp[0].v = v;
	vp[0].x = x;
	vp[0].y = y;
	vp[0].z = z;
	vp[1].u = sprite.sw + u;
	vp[1].v = sprite.sh + v;
	vp[1].x = x + sprite.dw;
	vp[1].y = y + sprite.dh;
	vp[1].z = z;
	switch (flip) {
	case 0:
		break;
	case 1:
		tmp.u = vp[0].u;
		vp[0].u = vp[1].u;
		vp[1].u = tmp.u;
		break;
	case 2:
		tmp.v = vp[0].v;
		vp[0].v = vp[1].v;
		vp[1].v = tmp.v;
		break;
	case 3:
		tmp.u = vp[0].u;
		tmp.v = vp[0].v;
		vp[0].u = vp[1].u;
		vp[0].v = vp[1].v;
		vp[1].u = tmp.u;
		vp[1].v = tmp.v;
		break;
	}
	switch (rotate) {
	case 0:
		break;
	case 1:
		tmp.y = vp[0].y;
		vp[0].y = vp[1].y;
		vp[1].y = tmp.y;
		break;
	case 2:
		tmp.x = vp[0].x;
		tmp.y = vp[0].y;
		vp[0].x = vp[1].x;
		vp[0].y = vp[1].y;
		vp[1].x = tmp.x;
		vp[1].y = tmp.y;
		break;
	case 3:
		tmp.x = vp[0].x;
		vp[0].x = vp[1].x;
		vp[1].x = tmp.x;
		break;
	}
	sceGuDrawArray(6, 0x800182, 2, NULL, vp);
}
