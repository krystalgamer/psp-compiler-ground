/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
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

int Fade::Run()
{
	if (!busy)
		return 0;
	float d = delta;
	float l = level;
	if (d >= 0.0f && l >= 1.0f) {
		level = 1.0f;
		busy = false;
		a = 255;
		return 0;
	}
	if (d < 0.0f && l <= 0.0f) {
		level = 0.0f;
		busy = false;
		a = 0;
		return 0;
	}
	l += d;
	if (d >= 0.0f) {
		if (l >= 1.0f)
			l = 1.0f;
	} else {
		if (l <= 0.0f)
			l = 0.0f;
	}
	level = l;
	a = (unsigned char)(l * 255.0f);
	return 1;
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

void Fade::Start_Fade(bool in, float to)
{
	if (in)
		level = to;
	float d;
	if (to == 0.0f)
		d = speed;
	else
		d = -speed;
	delta = d;
	busy = true;
	visible = true;
}

}
}
