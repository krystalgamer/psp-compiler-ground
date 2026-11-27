/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", D_00104CA8);
}
extern "C" const char D_00104CA8[];

struct Task;

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00104CA8, 23); }
	static void operator delete(void *p) { _memFree(p, D_00104CA8, 25); }
};

class Task : public Object {
	int _t[2];
public:
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
};

namespace Effect {
class Fade {
public:
	unsigned char busy : 1;
	char _pad[0xF];
	unsigned char r, g, b;
	char _pad2;
	void Start_Fade(bool in, float to);
	void Set_Color(unsigned char r_, unsigned char g_, unsigned char b_) { r = r_; g = g_; b = b_; }
};

class FadeTask : public Task {
public:
	Fade fade;
	unsigned char kill;
	FadeTask *Init(int prio, float time, unsigned char r, unsigned char g, unsigned char b);
};

class BlackFadeTask : public FadeTask {
};

class WhiteFadeTask : public FadeTask {
};
}
}

using namespace Ys::Effect;

extern "C" {

FadeTask *YsFx__FadeTask__Create(int prio, float time, unsigned char r, unsigned char g, unsigned char b)
{
	return (new FadeTask)->Init(prio, time, r, g, b);
}

void YsFx__FadeTask__Destroy(FadeTask *t)
{
	delete t;
}

int YsFx__FadeTask__Is_Busy(FadeTask *t)
{
	return t->fade.busy;
}

unsigned char YsFx__FadeTask__Get_R(FadeTask *t)
{
	return t->fade.r;
}

unsigned char YsFx__FadeTask__Get_G(FadeTask *t)
{
	return t->fade.g;
}

unsigned char YsFx__FadeTask__Get_B(FadeTask *t)
{
	return t->fade.b;
}

unsigned char YsFx__FadeTask__Set_R(FadeTask *t, unsigned char v)
{
	return t->fade.r = v;
}

unsigned char YsFx__FadeTask__Set_G(FadeTask *t, unsigned char v)
{
	return t->fade.g = v;
}

unsigned char YsFx__FadeTask__Set_B(FadeTask *t, unsigned char v)
{
	return t->fade.b = v;
}

void YsFx__FadeTask__Set_Color(FadeTask *t, unsigned char r, unsigned char g, unsigned char b)
{
	t->fade.Set_Color(r, g, b);
}

void YsFx__FadeTask__Start_FadeIn(FadeTask *t, bool in, bool kill)
{
	t->fade.Start_Fade(in, 1.0f);
	t->kill = kill;
}

void YsFx__FadeTask__Start_FadeOut(FadeTask *t, bool in, bool kill)
{
	t->fade.Start_Fade(in, 0.0f);
	t->kill = kill;
}

BlackFadeTask *YsFx__BlackFadeTask__Create(int prio, float time)
{
	return (BlackFadeTask *)(new BlackFadeTask)->Init(prio, time, 0, 0, 0);
}

void YsFx__BlackFadeTask__Destroy(BlackFadeTask *t)
{
	delete t;
}

int YsFx__BlackFadeTask__Is_Busy(BlackFadeTask *t)
{
	return t->fade.busy;
}

void YsFx__BlackFadeTask__Start_FadeIn(BlackFadeTask *t, bool in, bool kill)
{
	t->fade.Start_Fade(in, 1.0f);
	t->kill = kill;
}

void YsFx__BlackFadeTask__Start_FadeOut(BlackFadeTask *t, bool in, bool kill)
{
	t->fade.Start_Fade(in, 0.0f);
	t->kill = kill;
}

WhiteFadeTask *YsFx__WhiteFadeTask__Create(int prio, float time)
{
	return (WhiteFadeTask *)(new WhiteFadeTask)->Init(prio, time, 0xFF, 0xFF, 0xFF);
}

void YsFx__WhiteFadeTask__Destroy(WhiteFadeTask *t)
{
	delete t;
}

int YsFx__WhiteFadeTask__Is_Busy(WhiteFadeTask *t)
{
	return t->fade.busy;
}

void YsFx__WhiteFadeTask__Start_FadeIn(WhiteFadeTask *t, bool in, bool kill)
{
	t->fade.Start_Fade(in, 1.0f);
	t->kill = kill;
}

void YsFx__WhiteFadeTask__Start_FadeOut(WhiteFadeTask *t, bool in, bool kill)
{
	t->fade.Start_Fade(in, 0.0f);
	t->kill = kill;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZN2Ys6Effect13BlackFadeTaskD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZN2Ys6Effect13BlackFadeTaskD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZN2Ys6Effect13WhiteFadeTaskD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZN2Ys6Effect13WhiteFadeTaskD1Ev);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZTVN2Ys6Effect13WhiteFadeTaskE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", D_00104CD0);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZTVN2Ys6Effect13BlackFadeTaskE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", D_00104CF8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZTIN2Ys6Effect13BlackFadeTaskE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZTIN2Ys6Effect13WhiteFadeTaskE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZTSN2Ys6Effect13WhiteFadeTaskE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task_cif", _ZTSN2Ys6Effect13BlackFadeTaskE);
}
