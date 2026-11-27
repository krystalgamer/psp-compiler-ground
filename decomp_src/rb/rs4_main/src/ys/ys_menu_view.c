/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct Task {
	char _0[0x28];
	int f28;
};

namespace Ys {
class TaskState;

class Task {
public:
	::Task *task_p;
	TaskState *state_p;
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

class MenuView : public Task {
public:
	short select;
	short count;
	bool active;
	MenuView *Init(Task *parent, int n, int sel);
	virtual int Set_ItemCount(int n);
	virtual int Set_Select(int n);
	virtual void Open(int n);
	virtual void Close();
};

MenuView *MenuView::Init(Task *parent, int n, int sel)
{
	Task::Init(0, 0, parent);
	active = 0;
	Set_ItemCount(n);
	Set_Select(sel);
	state_p = _sleep_state_p;
	task_p->f28 = 0;
	return this;
}

int MenuView::Set_ItemCount(int n)
{
	return count = n;
}

int MenuView::Set_Select(int n)
{
	return select = n;
}

void MenuView::Open(int n)
{
	task_p->f28 = -1;
	active = 1;
	Set_Select(n);
}

void MenuView::Close()
{
	active = 0;
	task_p->f28 = 0;
}

}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_menu_view", _ZN2Ys8MenuViewD1Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_menu_view", D_00104ED4); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_menu_view", _ZN2Ys8MenuViewD0Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_menu_view", _ZTIN2Ys8MenuViewE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_menu_view", _ZTSN2Ys8MenuViewE); }
