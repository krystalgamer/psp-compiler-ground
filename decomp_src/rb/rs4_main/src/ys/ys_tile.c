/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void *i3dGetRender(void);
short *I3dRender__OpenTrash(void *r);
void I3dRender__CloseTrash(void *r, void *end);
void *i3dGetStage(void);
void *I3dRenderStage__GetCurrentPacketEntry(void *s);
void *I3dRenderStage__OpenPacket(void *s, float z);
void I3dRenderStage__ClosePacket(void *s, void *p);
void *xuDepthFunc(void *p, int f);
void *xuDisable(void *p, int s);
void *xuEnable(void *p, int s);
void *xuBlendFunc(void *p, int op, int src, int dst, unsigned int fix_a, unsigned int fix_b);
void *xuColor(void *p, unsigned int c);
void *xuDrawArray(void *p, int prim, int vtype, int count, const void *idx, const void *vtx);
}

namespace Ys {
class Tile {
public:
	float x, y;
	short w, h;
	unsigned int color;
	void Reset();
	void Draw();
};

void Tile::Reset()
{
	x = 240.0f;
	y = 136.0f;
	w = 0;
	h = 0;
	color = 0;
}

void Tile::Draw()
{
	void *r = i3dGetRender();
	short *v = I3dRender__OpenTrash(r);
	void *p;
	int ww = w, hh = h;
	int x0 = (int)x - ww / 2;
	int y0 = (int)y - hh / 2;
	v[0] = x0;
	v[1] = y0;
	v[2] = 0;
	v[3] = x0 + ww;
	v[4] = y0 + hh;
	v[5] = 0;
	I3dRender__CloseTrash(r, v + 6);
	r = i3dGetStage();
	I3dRenderStage__GetCurrentPacketEntry(r);
	p = I3dRenderStage__OpenPacket(r, 0.0f);
	p = xuDepthFunc(p, 1);
	p = xuDisable(p, 9);
	p = xuBlendFunc(p, 0, 2, 3, 0, 0);
	p = xuEnable(p, 4);
	p = xuColor(p, color);
	p = xuDrawArray(p, 6, 0x800100, 2, 0, v);
	I3dRenderStage__ClosePacket(r, p);
}
}
