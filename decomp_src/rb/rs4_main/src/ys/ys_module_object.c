/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtable and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

/* ys_object.h's file name, then an unreferenced empty string */
__asm__(".section .rodata\n.align 2\n.globl D_00104F30\nD_00104F30: .asciz \"src/ys/ys_object.h\"\n.align 2\n.asciz \"\"\n.align 2\n.previous");
extern "C" const char D_00104F30[];

extern "C" void _memFree(void *p, const char *file, int line);

struct Task;

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, D_00104F30, 25); }
};

class Task : public Object {
	int _t[2];
public:
	virtual ~Task();
	void Init(void *a, unsigned int b, Task *parent);
};

class ModuleObject : public Task {
public:
	static ModuleObject *_instance_p;
	virtual ~ModuleObject();
	ModuleObject *Init(Task *parent);
};

ModuleObject::~ModuleObject()
{
	_instance_p = 0;
}

ModuleObject *ModuleObject::Init(Task *parent)
{
	Task::Init(0, 0, parent);
	_instance_p = this;
	return this;
}
}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_module_object", _ZTVN2Ys12ModuleObjectE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_module_object", D_00104F50);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_module_object", _ZTIN2Ys12ModuleObjectE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_module_object", _ZTSN2Ys12ModuleObjectE);
}
