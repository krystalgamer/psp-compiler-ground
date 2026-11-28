/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
/* #pragma interface: the state vtables stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { if (p) _memFree(p, "src/ys/ys_object.h", 25); }
};

class Task {
public:
	static void Create_State();
	static void Delete_State();
};

class TaskState {
public:
	virtual ~TaskState();
};

namespace TextMenuViewState {
class Open : public TaskState {
};
class Close : public TaskState {
};
class Unfocus : public TaskState {
};
}

class TextMenuView {
public:
	struct StateTable {
		TextMenuViewState::Open open;
		TextMenuViewState::Close close;
		TextMenuViewState::Unfocus unfocus;
		static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 31); }
		static void operator delete(void *p) { if (p) _memFree(p, "src/ys/ys_object.h", 34); }
	};
	static StateTable *_state_table_p;
};

class ScreenPanelDaemon : public Object {
	int _d;
public:
	static ScreenPanelDaemon *_instance_p;
	ScreenPanelDaemon();
	~ScreenPanelDaemon();
};
}

namespace Tgs {
class ResidentData : public Ys::Object {
	int _d;
public:
	static ResidentData *_instance_p;
	void Reset();
};
}

namespace SaruNet {
class ResidentData {
public:
	static ResidentData *Get_Instance_p();
	void Reset();
};
}

extern "C" void ysGlobalObject__Create(void)
{
	Ys::Task::Create_State();
	SaruNet::ResidentData::Get_Instance_p()->Reset();
	Ys::TextMenuView::_state_table_p = new Ys::TextMenuView::StateTable;
	new Ys::ScreenPanelDaemon;
	Tgs::ResidentData::_instance_p = new Tgs::ResidentData;
	Tgs::ResidentData::_instance_p->Reset();
}

extern "C" void ysGlobalObject__Destroy(void)
{
	delete Tgs::ResidentData::_instance_p;
	delete Ys::ScreenPanelDaemon::_instance_p;
	delete Ys::TextMenuView::_state_table_p;
	Ys::Task::Delete_State();
}
