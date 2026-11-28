/* lang: c++ */
/* cflags: -Os */
/* #pragma interface: the vtable and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

struct SceKernelSemaInfo { int size; char _[0x34]; };
extern "C" int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
extern "C" int sceKernelDeleteSema(int id);
extern "C" int sceKernelReferSemaStatus(int id, SceKernelSemaInfo *info);
extern "C" void consPrintf(const char *fmt, ...);
extern "C" void _memFree(void *p, const char *file, int line);

extern const char D_0010473C[], D_00104758[], D_00104774[], D_0010477C[];
extern const char Semaphore_FUNCTION[] __asm__("_ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__");

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, D_0010477C, 25); }
};
}

namespace MetaMagic {
class Semaphore : public Ys::Object {
	int id;
public:
	Semaphore(const char *name, int init, int max, unsigned int attr);
	virtual ~Semaphore();
	void Get_Status(SceKernelSemaInfo &info) const;
};

Semaphore::Semaphore(const char *name, int init, int max, unsigned int attr)
{
	id = sceKernelCreateSema(name, attr, init, max, 0);
	if (!(id >= 0))
		consPrintf(D_0010473C, D_00104758, 34, Semaphore_FUNCTION, D_00104774);
}

Semaphore::~Semaphore()
{
	if (id >= 0)
		sceKernelDeleteSema(id);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZZN9MetaMagic9SemaphoreC1EPKciijE12__FUNCTION__);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_0010473C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_00104758);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_00104774);
/* ys_object.h's __FILE__ (Ys::Object::operator delete); the split keeps it in the D0 dtor's asm */
__asm__(".section .rodata\n\t.align 2\nD_0010477C:\n\t.asciz \"src/ys/ys_object.h\"\n\t.align 2\n\t.previous");

void Semaphore::Get_Status(SceKernelSemaInfo &info) const
{
	info.size = sizeof(SceKernelSemaInfo);
	int tid = id;
	sceKernelReferSemaStatus(tid, &info);
}
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTVN9MetaMagic9SemaphoreE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", D_00104798);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTIN9MetaMagic9SemaphoreE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTSN9MetaMagic9SemaphoreE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTIN2Ys6ObjectE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/libmm_semaphore", _ZTSN2Ys6ObjectE);
