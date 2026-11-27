/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct Task {
	char _0[0x24];
	signed char f24;
};

namespace Ys {
class Task {
public:
	::Task *task_p;
	void *state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
	Task *Init(void *p, unsigned int n, Task *parent);
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
	int Run();
	void Draw();
};

class FadeTask : public Task {
public:
	Fade fade;
	bool auto_delete;
	FadeTask *Init(int pri, float time, unsigned char r, unsigned char g, unsigned char b);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
};

FadeTask *FadeTask::Init(int pri, float time, unsigned char r, unsigned char g, unsigned char b)
{
	Task::Init(0, 0, 0);
	task_p->f24 = pri;
	fade.Init(time, r, g, b);
	auto_delete = 0;
	return this;
}

void FadeTask::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	fade.Run();
	if (auto_delete && !fade.busy)
		delete this;
}

void FadeTask::Receive_DrawMessage(::Task *t, void *p, unsigned int n)
{
	fade.Draw();
}

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task", D_00104C54); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task", _ZN2Ys6Effect8FadeTaskD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task", _ZN2Ys6Effect8FadeTaskD1Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task", _ZTIN2Ys6Effect8FadeTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_fx_fade_task", _ZTSN2Ys6Effect8FadeTaskE); }
