/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#include "common.h"

struct Task {
	char _0[0x24];
	unsigned char f24;
};

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
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
class Game {
public:
	char _0[0x40];
	void *controller_set_p;
	static Game *_instance_p;
};

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


namespace SaruNet {
namespace PetitGame {

ControllerSet::~ControllerSet()
{
	SaruNet::Game::_instance_p->controller_set_p = 0;
}

ControllerSet *ControllerSet::Init(NetworkTask &t)
{
	SaruNetLib::ControllerSetTask::Init(t.task_p->f24, &t);
	return this;
}

}
}


