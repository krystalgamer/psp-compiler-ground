/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
/* data-align: 8 */
#include "common.h"

extern "C" void _memFree(void *p, const char *file, int line);

struct Task;

namespace Ys {
struct Anim2D_LoadParam;
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};
class Task : public Object {
public:
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
};
class AnimTask : public Task {
public:
	virtual ~AnimTask();
	AnimTask *Init(int mode, Anim2D_LoadParam *param, Task *parent);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
};
class InfoPanel : public AnimTask {
public:
	InfoPanel *Init(Anim2D_LoadParam &param, Task *parent);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

InfoPanel *InfoPanel::Init(Anim2D_LoadParam &param, Task *parent)
{
	AnimTask::Init(1, &param, parent);
	return this;
}

void InfoPanel::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	AnimTask::Receive_RunMessage(t, p, n);
}
}
