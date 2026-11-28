/* lang: c++ */
/* cflags: -Os */
#include "common.h"

struct SceKernelThreadInfo { int size; char _[0x68]; };
extern "C" int sceKernelCreateThread(const char *name, int (*entry)(unsigned int, void *), int prio, int stack, unsigned int attr, void *opt);
extern "C" int sceKernelGetThreadId(void);
extern "C" int sceKernelExitDeleteThread(int status);
extern "C" int sceKernelTerminateDeleteThread(int id);
extern "C" int sceKernelChangeThreadPriority(int id, int prio);
extern "C" int sceKernelReferThreadStatus(int id, SceKernelThreadInfo *info);
extern "C" void consPrintf(const char *fmt, ...);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" int sceKernelExitThread(int status);
extern "C" int sceKernelTerminateThread(int id);
extern "C" int sceKernelStartThread(int id, int argSize, void *argp);
extern "C" void *memcpy(void *, const void *, unsigned int);

#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/ys/libmm_thread.cc", __LINE__, __FUNCTION__, #e)

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};
}

namespace MetaMagic {
class Thread : public Ys::Object {
	int id;
	int priority;
public:
	Thread(const char *name, int stack, int prio, unsigned int attr);
	virtual ~Thread();
	virtual int Run(int argSize, const void *argp);
	int Set_Priority(int prio);
	void Get_Status(SceKernelThreadInfo &info) const;
	int Start(int argSize, const void *argp);
	void Term();
	static int _EntryPoint(unsigned int argSize, void *argp);
};

Thread::Thread(const char *name, int stack, int prio, unsigned int attr)
{
	id = sceKernelCreateThread(name, _EntryPoint, prio, stack, attr, 0);
#line 47
	cassert(id >= 0);
	priority = prio;
}

Thread::~Thread()
{
	int current_thread_id = sceKernelGetThreadId();
#line 68
	cassert(current_thread_id >= 0);
	if (id == current_thread_id)
		sceKernelExitDeleteThread(0);
	else
		sceKernelTerminateDeleteThread(id);
}


int Thread::Set_Priority(int prio)
{
	int r = sceKernelChangeThreadPriority(id, prio);
	switch (r) {
	case 0:
	case (int)0x800201A2:
		priority = prio;
	}
	return r;
}

void Thread::Get_Status(SceKernelThreadInfo &info) const
{
	info.size = sizeof(SceKernelThreadInfo);
	int tid = id;
	sceKernelReferThreadStatus(tid, &info);
}

int Thread::Start(int argSize, const void *argp)
{
	struct Arg { int size; Thread *self; };
	int size = (argSize + 3) & ~3;
	size += sizeof(Arg);
	char buf[size];
	memcpy(buf, argp, argSize);
	/* indexes Arg units, not bytes (as the original does) */
	Arg *a = &((Arg *)buf)[size - sizeof(Arg)];
	a->size = argSize;
	a->self = this;
	int tid = id;
	return sceKernelStartThread(tid, size, buf);
}

void Thread::Term()
{
	int current_thread_id = sceKernelGetThreadId();
#line 167
	cassert(current_thread_id >= 0);
	if (id == current_thread_id)
		sceKernelExitThread(0);
	else
		sceKernelTerminateThread(id);
}

}

extern "C" const char D_0010485C[] = "";

namespace MetaMagic {

int Thread::Run(int argSize, const void *argp)
{
	return 0;
}

int Thread::_EntryPoint(unsigned int argSize, void *argp)
{
	struct Arg { int size; Thread *self; } *a = (Arg *)((char *)argp + argSize) - 1;
	return a->self->Run(a->size, argp);
}
}

