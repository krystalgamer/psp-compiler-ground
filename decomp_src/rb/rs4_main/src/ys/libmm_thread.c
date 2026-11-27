/* lang: c++ */
/* cflags: -Os */
/* #pragma interface: the vtable and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
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

extern const char D_001047E4[], D_00104800[], D_00104818[], D_00104828[], D_00104840[];
extern const char ThreadC1_FUNCTION[] __asm__("_ZZN9MetaMagic6ThreadC1EPKciijE12__FUNCTION__");
extern const char ThreadD1_FUNCTION[] __asm__("_ZZN9MetaMagic6ThreadD1EvE12__FUNCTION__");

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, D_00104840, 25); }
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
	if (!(id >= 0))
		consPrintf(D_001047E4, D_00104800, 47, ThreadC1_FUNCTION, D_00104818);
	priority = prio;
}

Thread::~Thread()
{
	int current_thread_id = sceKernelGetThreadId();
	if (!(current_thread_id >= 0))
		consPrintf(D_001047E4, D_00104800, 68, ThreadD1_FUNCTION, D_00104828);
	if (id == current_thread_id)
		sceKernelExitDeleteThread(0);
	else
		sceKernelTerminateDeleteThread(id);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZZN9MetaMagic6ThreadC1EPKciijE12__FUNCTION__);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_001047E4);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104800);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104818);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZZN9MetaMagic6ThreadD1EvE12__FUNCTION__);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104828);
/* ys_object.h's __FILE__ (Ys::Object::operator delete); the split keeps it in the D0 dtor's asm */
__asm__(".section .rodata\n\t.align 2\nD_00104840:\n\t.asciz \"src/ys/ys_object.h\"\n\t.align 2\n\t.previous");

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZNK9MetaMagic6Thread10Get_StatusER19SceKernelThreadInfo);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZN9MetaMagic6Thread5StartEiPKv);

void Thread::Term()
{
	int current_thread_id = sceKernelGetThreadId();
	if (!(current_thread_id >= 0))
		consPrintf(D_001047E4, D_00104800, 167, __FUNCTION__, D_00104828);
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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZTVN9MetaMagic6ThreadE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", D_00104868);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZTIN9MetaMagic6ThreadE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_thread", _ZTSN9MetaMagic6ThreadE);
