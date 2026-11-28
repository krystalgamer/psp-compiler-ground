/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#include "common.h"


struct Task;
struct InstDat;

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
Task *taskMake(Task *parent, void *func, void *arg, unsigned int n);
void taskKill(Task *t, int a, int b);
int taskDefaultMsg(Task *t, int msg, void *p, unsigned int n);
void consPrintf(const char *fmt, ...);
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

class Task;

namespace Cop {
class DrawAttribute {
public:
	char _0[0x30];
	void Reset();
};
class Matrix4x4 {
public:
	float m[4][4];
	void Set_Unit();
};
}
}

#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/ys/ys_task.cc", __LINE__, __FUNCTION__, #e)

struct Task {
	char _0[0x28];
	int f28;
	int f2C;
	char _30[0xC];
	void *owner;
	char _40[0x20];
	Ys::Cop::DrawAttribute attr;
	Ys::Cop::Matrix4x4 m90;
	Ys::Cop::Matrix4x4 mD0;
};

namespace Ys {
class TaskState;

class Task : public Object {
public:
	::Task *task_p;
	TaskState *state_p;
	static TaskState *_default_state_p;
	static class TaskStateSleep *_sleep_state_p;
	static void Create_State();
	static void Delete_State();
	Task *Init(void *p, unsigned int n, Task *parent);
	void Free();
	virtual ~Task();
	static ::Task *MessageReceiver(::Task *t, unsigned int msg, void *p, unsigned int n);
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
};

class TaskState : public Object {
public:
	virtual ~TaskState();
	virtual void Kill(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Free(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Draw(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void KillChild(Task &t, ::Task *p, ::Task *c, unsigned int n);
	virtual int Unknown(Task &t, ::Task *p, int m, void *q, unsigned int n);
};

class TaskStateSleep : public TaskState {
public:
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Draw(Task &t, ::Task *p, void *q, unsigned int n);
};

struct TaskInitArg {
	Task *task_p;
	void *p;
};

void Task::Create_State()
{
	_default_state_p = new TaskState;
	_sleep_state_p = new TaskStateSleep;
}

void Task::Delete_State()
{
	delete _default_state_p;
	delete _sleep_state_p;
}

Task *Task::Init(void *p, unsigned int n, Task *parent)
{
	TaskInitArg arg;
	state_p = _default_state_p;
	arg.p = p;
	arg.task_p = this;
	task_p = taskMake(parent ? parent->task_p : 0, (void *)MessageReceiver, &arg, n);
	return this;
}

void Task::Free()
{
	if (task_p) {
		::Task *t = task_p;
		task_p = 0;
		t->owner = 0;
		taskKill(t, 0, 0);
	}
}

Task::~Task()
{
	state_p = _default_state_p;
	Free();
}

::Task *Task::MessageReceiver(::Task *task_p, unsigned int msg, void *p, unsigned int n)
{
	Task *self = msg ? (Task *)task_p->owner : ((TaskInitArg *)p)->task_p;
	if (!self)
		return task_p;
	TaskState *s = self->state_p;
	::Task *ret = 0;
	switch (msg) {
	case 0:
		/* the original cassert is at src/ys/ys_task.cc line 160 */
#line 160
		cassert(task_p);
		task_p->owner = self;
		self->task_p = task_p;
		ret = task_p;
		self->Receive_InitMessage(task_p, ((TaskInitArg *)p)->p, n);
		break;
	case 4:
		s->Kill(*self, task_p, p, n);
		ret = task_p;
		break;
	case 1:
		s->Free(*self, task_p, p, n);
		break;
	case 2:
		s->Run(*self, task_p, p, n);
		break;
	case 3:
		s->Draw(*self, task_p, p, n);
		break;
	case 8:
		s->KillChild(*self, task_p, (::Task *)p, n);
		break;
	default:
		ret = (::Task *)s->Unknown(*self, task_p, msg, p, n);
		break;
	}
	return ret;
}

void Task::Receive_InitMessage(::Task *t, void *p, unsigned int n)
{
	task_p->f2C = 0x41;
	t->attr.Reset();
	t->m90.Set_Unit();
	t->mD0.Set_Unit();
	task_p->f28 = -1;
}

void Task::Receive_KillMessage(::Task *t, void *p, unsigned int n)
{
}

void Task::Receive_FreeMessage(::Task *t, void *p, unsigned int n)
{
	if (task_p) {
		task_p = 0;
		delete this;
	}
}

void Task::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
}

void Task::Receive_DrawMessage(::Task *t, void *p, unsigned int n)
{
}

void Task::Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n)
{
}

TaskState::~TaskState()
{
}

void TaskState::Kill(Task &t, ::Task *p, void *q, unsigned int n)
{
	t.Receive_KillMessage(p, q, n);
}

void TaskState::Free(Task &t, ::Task *p, void *q, unsigned int n)
{
	t.Receive_FreeMessage(p, q, n);
}

void TaskState::Run(Task &t, ::Task *p, void *q, unsigned int n)
{
	t.Receive_RunMessage(p, q, n);
}

void TaskState::Draw(Task &t, ::Task *p, void *q, unsigned int n)
{
	t.Receive_DrawMessage(p, q, n);
}

void TaskState::KillChild(Task &t, ::Task *p, ::Task *c, unsigned int n)
{
	t.Receive_KillChildMessage(p, c, n);
}

int TaskState::Unknown(Task &t, ::Task *p, int m, void *q, unsigned int n)
{
	return taskDefaultMsg(p, m, q, n);
}

void TaskStateSleep::Run(Task &t, ::Task *p, void *q, unsigned int n)
{
}

void TaskStateSleep::Draw(Task &t, ::Task *p, void *q, unsigned int n)
{
}

}


