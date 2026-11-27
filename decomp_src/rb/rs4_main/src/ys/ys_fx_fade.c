/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
#pragma interface "rodata"
#include "common.h"

namespace Ys {
class Tile {
public:
	float x, y;
	short w, h;
	unsigned int color;
	void Reset();
	void Draw();
};

namespace Effect {
class Fade {
public:
	bool busy : 1;
	bool visible : 1;
	unsigned int _f : 30;
	float speed;
	float level;
	float delta;
	unsigned char r, g, b, a;
	Fade *Init(float time, unsigned char r_, unsigned char g_, unsigned char b_);
	float Set_Time(float time);
	int Run();
	void Draw();
	void Start_Fade(bool in, float to);
};

Fade *Fade::Init(float time, unsigned char r_, unsigned char g_, unsigned char b_)
{
	*(unsigned int *)this = 0;
	Set_Time(time);
	r = r_;
	g = g_;
	b = b_;
	a = 0xFF;
	level = 0.0f;
	return this;
}

float Fade::Set_Time(float time)
{
	speed = 1.0f / (time * 59.94f);
	return time;
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade", _ZN2Ys6Effect4Fade3RunEv);
}

void Fade::Draw()
{
	if (visible) {
		Tile t;
		t.Reset();
		t.w = 480;
		t.h = 272;
		t.color = *(unsigned int *)&r;
		t.Draw();
	}
}

}
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade", _ZN2Ys6Effect4Fade10Start_FadeEbf);
}
