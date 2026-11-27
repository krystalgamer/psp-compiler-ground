/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void _memFree(void *p, const char *file, int line);
void ctrlFlushVirtualDataAll(void);
extern const char D_001079BC[];
}

struct Task {
	char _0[0x24];
	signed char f24;
	char _25[7];
	int f2C;
};

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, D_001079BC, 25); }
};
class TaskState;
class Task : public Object {
public:
	::Task *task_p;
	TaskState *state_p;
	static TaskState *_default_state_p;
	static TaskState *_sleep_state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
	Task *Init(void *p, unsigned int n, Task *parent);
};
}

namespace SaruNetLib {
class Controller;
class LocalController;

class ControllerSet : public Ys::Object {
public:
	Controller *controllers[8];
	LocalController *local_p;
	short wait;
	signed char count;
	virtual ~ControllerSet();
	ControllerSet *Init();
	void Update();
};

class ControllerSetTask : public Ys::Task, public ControllerSet {
public:
	virtual ~ControllerSetTask();
	ControllerSetTask *Init(int prio, Ys::Task *parent);
	void Start();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZN10SaruNetLib17ControllerSetTaskD2Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZN10SaruNetLib17ControllerSetTaskD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZN10SaruNetLib17ControllerSetTaskD0Ev); }

namespace SaruNetLib {

ControllerSetTask *ControllerSetTask::Init(int prio, Ys::Task *parent)
{
	Ys::Task::Init(0, 0, parent);
	task_p->f24 = prio;
	task_p->f2C = 0x40;
	ControllerSet::Init();
	state_p = Ys::Task::_sleep_state_p;
	return this;
}

void ControllerSetTask::Start()
{
	ctrlFlushVirtualDataAll();
	wait = 300;
	state_p = Ys::Task::_default_state_p;
}

void ControllerSetTask::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	Update();
}

}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZThn12_N10SaruNetLib17ControllerSetTaskD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZThn12_N10SaruNetLib17ControllerSetTaskD0Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTVN10SaruNetLib17ControllerSetTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", D_00107938); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTIN10SaruNetLib17ControllerSetTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTSN10SaruNetLib17ControllerSetTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", D_001079B4); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", D_001079BC); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTVN10SaruNetLib4HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", D_001079D8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTVN10SaruNetLib10Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", D_001079F0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTVN10SaruNetLib11_Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTIN10SaruNetLib11_Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTIN10SaruNetLib10Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTIN10SaruNetLib4HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTSN10SaruNetLib4HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTSN10SaruNetLib10Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set_task", _ZTSN10SaruNetLib11_Class_HostE); }
