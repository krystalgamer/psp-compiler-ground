/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants */
/* #pragma interface: FadeTask's vtable stays in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

namespace Effect {
class Fade : public Object {
public:
	unsigned char busy : 1;
	char _pad[0x13];
	Fade *Init(float time, unsigned char r, unsigned char g, unsigned char b);
	void Start_Fade(bool in, float to);
	void Run();
	void Draw();
};
}
}

using Ys::Effect::Fade;

extern "C" {

Fade *YsFx__BlackFade__Create(float time)
{
	return (new Fade)->Init(time, 0, 0, 0);
}

void YsFx__BlackFade__Destroy(Fade *f)
{
	if (f)
		delete f;
}

int YsFx__BlackFade__Is_Busy(Fade *f)
{
	return f->busy;
}

void YsFx__BlackFade__Start_FadeIn(Fade *f, bool b)
{
	f->Start_Fade(b, 1.0f);
}

void YsFx__BlackFade__Start_FadeOut(Fade *f, bool b)
{
	f->Start_Fade(b, 0.0f);
}

void YsFx__BlackFade__Run(Fade *f)
{
	f->Run();
}

void YsFx__BlackFade__Draw(Fade *f)
{
	f->Draw();
}

Fade *YsFx__WhiteFade__Create(float time)
{
	return (new Fade)->Init(time, 0xFF, 0xFF, 0xFF);
}

void YsFx__WhiteFade__Destroy(Fade *f)
{
	if (f)
		delete f;
}

int YsFx__WhiteFade__Is_Busy(Fade *f)
{
	return f->busy;
}

void YsFx__WhiteFade__Start_FadeIn(Fade *f, bool b)
{
	f->Start_Fade(b, 1.0f);
}

void YsFx__WhiteFade__Start_FadeOut(Fade *f, bool b)
{
	f->Start_Fade(b, 0.0f);
}

void YsFx__WhiteFade__Run(Fade *f)
{
	f->Run();
}

void YsFx__WhiteFade__Draw(Fade *f)
{
	f->Draw();
}

}
