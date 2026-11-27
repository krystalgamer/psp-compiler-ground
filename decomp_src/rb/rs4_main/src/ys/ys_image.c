/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct InstDat {
	char _0[0x10];
	unsigned int pic;
};
struct I3dPicture;

extern "C" {
InstDat *resGetDatLocal(int a, int b);
int I3dPicture__Get_wPixel(I3dPicture *p, int lv);
int I3dPicture__Get_hPixel(I3dPicture *p, int lv);
void i3dDrawImg(InstDat *d, void *a, void *b, void *c);
}

namespace Ys {
namespace Cop {
class Vector4 {
public:
	float x, y, z, w;
	Vector4() {}
};
class Matrix4x4 {
public:
	Vector4 r[4];
	Matrix4x4() { Set_Unit(); }
	void Set_Unit();
};
class DrawAttribute {
public:
	float sx, sy;
	float f[10];
	void Reset();
};
}

class Image {
public:
	InstDat *dat;
	short w;
	short h;
	int _8[2];
	Cop::Matrix4x4 mtx;
	Cop::Vector4 pos;
	Cop::DrawAttribute attr;
	Image();
	void Set_Image(int id, int group);
	void Draw();
};

Image::Image()
{
	attr.Reset();
	pos.x = 240.0f;
	pos.y = 136.0f;
	dat = 0;
	w = 0;
	h = 0;
}

void Image::Set_Image(int id, int group)
{
	dat = resGetDatLocal(group, id);
	I3dPicture *pic = (I3dPicture *)(((dat->pic + 15) & ~15) + 16);
	w = I3dPicture__Get_wPixel(pic, 0);
	h = I3dPicture__Get_hPixel(pic, 0);
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_image", _ZN2Ys5Image4DrawEv); }

namespace Ys {

}


