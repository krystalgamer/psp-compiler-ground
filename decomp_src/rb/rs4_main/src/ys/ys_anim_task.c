/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on in this object: its three loops (Init, Receive_Run/DrawMessage) match only with it */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
extern const char D_00104B34[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00104B34, 23); }
	static void operator delete(void *p) { _memFree(p, D_00104B34, 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, D_00104B34, 32); }
	static void operator delete[](void *p) { if (p) _memFree(p, D_00104B34, 37); }
};

namespace Cop {
class Matrix4x4 {
public:
	float m[4][4];
} __attribute__((aligned(16)));
class DrawAttribute {
public:
	float f[12];
} __attribute__((aligned(16)));
}
}

struct Task {
	char _0[0x28];
	int f28;
	int f2C;
	char _30[0x60];
	Ys::Cop::Matrix4x4 m90;
	Ys::Cop::Matrix4x4 mD0;
};

namespace Ys {
class Task : public Object {
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

struct Anim2D_LoadParam {
	short group;
	short id;
};

class Anim2D : public Object {
public:
	Cop::DrawAttribute attr;
	void *anm;
	signed char entry;
	signed char group;
	short id;
	signed char visible;
	Anim2D();
	virtual ~Anim2D();
	void Load(int id_, int group_);
	int Exec();
	void Draw(Cop::Matrix4x4 &m);
};

class AnimTask : public Task {
public:
	signed char count;
	Anim2D *anim_p;
	virtual ~AnimTask();
	AnimTask *Init(int n, Anim2D_LoadParam *param, Task *parent);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
};

AnimTask::~AnimTask()
{
	Anim2D *a = anim_p;
	delete[] a;
}

AnimTask *AnimTask::Init(int n, Anim2D_LoadParam *param, Task *parent)
{
	Task::Init(0, 0, parent);
	count = n;
	Anim2D *a = new Anim2D[n];
	anim_p = a;
	for (int i = 0; i < n; i++)
		a[i].Load(param[i].id, param[i].group);
	task_p->f28 = 0;
	return this;
}

void AnimTask::Receive_RunMessage(::Task *t, void *p, unsigned int n_)
{
	int n = count;
	for (int i = 0; i < n; i++)
		anim_p[i].Exec();
}

void AnimTask::Receive_DrawMessage(::Task *t, void *p, unsigned int n_)
{
	Cop::Matrix4x4 &m = task_p->m90;
	int n = count;
	for (int i = 0; i < n; i++)
		anim_p[i].Draw(m);
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim_task", D_00104B34); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim_task", _ZTVN2Ys8AnimTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim_task", D_00104B50); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim_task", _ZTIN2Ys8AnimTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_anim_task", _ZTSN2Ys8AnimTaskE); }
