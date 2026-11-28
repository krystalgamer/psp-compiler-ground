/* lang: c++ */
/* cflags: -Os -fno-exceptions */
#include "common.h"

struct InstDat;

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
InstDat *resGetDatLocal(int a, int b);
void scxStop(int h, int f);
int scxPlay(InstDat *d, int a, int b);
int scxState(int h);
}

struct Task;

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 32); }
	static void operator delete[](void *p) { if (p) _memFree(p, "src/ys/ys_object.h", 37); }
};

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

class SoundCreateParam {
public:
	short res;
	short id;
	short a;
	short b;
	short loop;
	short f;
	SoundCreateParam();
	void Set_Param(int r, int i, int a_, int b_, bool lp, bool f_);
	SoundCreateParam &Copy(const SoundCreateParam &p);
};

class SoundInfo : public Object {
public:
	InstDat *dat;
	short a;
	short b;
	bool loop : 1;
	bool f : 1;
	unsigned int _r : 30;
	int handle;
	SoundInfo();
};

class Sound : public Task {
public:
	SoundInfo *info_p;
	short count;
	static Sound *_instance_p;
	virtual ~Sound();
	Sound *Init(int n, const SoundCreateParam *param, Task *parent);
	int Stop(int i, bool force);
	void Stop_All();
	int Play(int i);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

SoundCreateParam::SoundCreateParam()
{
	res = 3;
	id = 0;
	a = 0;
	b = 0;
	loop = 0;
	f = 1;
}

void SoundCreateParam::Set_Param(int r, int i, int a_, int b_, bool lp, bool f_)
{
	res = r;
	id = i;
	a = a_;
	b = b_;
	loop = lp;
	f = f_;
}

SoundCreateParam &SoundCreateParam::Copy(const SoundCreateParam &p)
{
	Set_Param(p.res, p.id, p.a, p.b, p.loop, p.f);
	return *this;
}

SoundInfo::SoundInfo()
{
	handle = -1;
	loop = 0; f = 1;
	a = 0;
	b = 0;
	dat = 0;
}

Sound::~Sound()
{
	int n = count;
	for (int i = 0; i < n; i++)
		Stop(i, true);
	SoundInfo *p = info_p;
	delete[] p;
	_instance_p = 0;
}

}

namespace Ys {
Sound *Sound::Init(int n, const SoundCreateParam *param, Task *parent)
{
	Task::Init(0, 0, parent);
	count = n;
	SoundInfo *info = new SoundInfo[count];
	info_p = info;
	for (int i = 0; i < n; i++) {
		InstDat *d = resGetDatLocal(param[i].res, param[i].id);
		int a = param[i].a;
		info[i].dat = d;
		info[i].a = a;
		int b = param[i].b;
		info[i].b = b;
		info[i].loop = param[i].loop;
		info[i].f = param[i].f;
	}
	_instance_p = this;
	return this;
}
}

namespace Ys {

int Sound::Stop(int i, bool force)
{
	SoundInfo *s = &info_p[i];
	if (s->handle >= 0) {
		scxStop(s->handle, !force);
		s->handle = -1;
	}
	return i;
}

void Sound::Stop_All()
{
	int n = count;
	for (int i = 0; i < n; i++)
		Stop(i, false);
}

int Sound::Play(int i)
{
	Stop(i, false);
	SoundInfo *s = &info_p[i];
	InstDat *d = s->dat;
	s->handle = scxPlay(d, s->a, s->b);
	return i;
}

void Sound::Receive_RunMessage(::Task *t, void *p, unsigned int n_)
{
	int n = count;
	for (int i = 0; i < n; i++) {
		SoundInfo *s = &info_p[i];
		if (s->handle >= 0 && scxState(s->handle) <= 0) {
			s->handle = -1;
			if (s->loop)
				Play(i);
		}
	}
}

}


