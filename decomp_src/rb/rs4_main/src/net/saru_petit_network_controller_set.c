/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct Task {
	char _0[0x24];
	unsigned char f24;
};

namespace Ys {
class Object {
};
class TaskState;
class Task : public Object {
public:
	::Task *task_p;
	TaskState *state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
};
}

namespace SaruNetLib {
class ControllerSet : public Ys::Object {
public:
	char _4[0x2C];
	virtual ~ControllerSet();
};

class ControllerSetTask : public Ys::Task, public ControllerSet {
public:
	virtual ~ControllerSetTask();
	ControllerSetTask *Init(int prio, Ys::Task *parent);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};
}

namespace SaruNet {
namespace PetitGame {
class NetworkTask : public Ys::Task {
};

class ControllerSet : public SaruNetLib::ControllerSetTask {
public:
	virtual ~ControllerSet();
	ControllerSet *Init(NetworkTask &t);
};

}
}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZN7SaruNet9PetitGame13ControllerSetD2Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZN7SaruNet9PetitGame13ControllerSetD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZN7SaruNet9PetitGame13ControllerSetD0Ev); }

namespace SaruNet {
namespace PetitGame {

ControllerSet *ControllerSet::Init(NetworkTask &t)
{
	SaruNetLib::ControllerSetTask::Init(t.task_p->f24, &t);
	return this;
}

}
}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZThn12_N7SaruNet9PetitGame13ControllerSetD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZThn12_N7SaruNet9PetitGame13ControllerSetD0Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZTVN7SaruNet9PetitGame13ControllerSetE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", D_00108AB8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZTIN7SaruNet9PetitGame13ControllerSetE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", _ZTSN7SaruNet9PetitGame13ControllerSetE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_controller_set", D_00108B18); }
