/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: Init/Update_VControllers loops match only with it (pointer IV + down-counter) */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
void ctrlFlushVirtualDataAll(void);
extern const char D_001078CC[];
}

struct CtrlVirtualData {
	int f0;
	int f4;
	signed char f8;
	signed char f9;
	char _a[6];
};

extern "C" int ctrlSetVirtualData(int port, CtrlVirtualData *d, int n);

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_001078CC, 23); }
	static void operator delete(void *p) { _memFree(p, D_001078CC, 25); }
};
}

namespace SaruNetLib {
struct ControllerEntry {
	int f4;
	signed char f8;
	signed char f9;
	short fA;
};
struct ControllerData {
	short f0;
	short f2;
	ControllerEntry entry[5];
};
struct ControllerNetObject {
	char _0[0x1C];
	ControllerData *data;
};

class Controller : public Ys::Object {
public:
	int class_id;
	int object_index;
	int _c;
	bool owner;
	ControllerNetObject *net_object_p;
	signed char id;
	virtual ~Controller();
	ControllerData *Get_Data() const { return net_object_p->data; }
};

class LocalController : public Controller {
public:
	char _19[0x5D];
	short seq;
	virtual ~LocalController();
	LocalController *Init();
	void Update();
};

class ControllerSet : public Ys::Object {
public:
	Controller *controllers[8];
	LocalController *local_p;
	short wait;
	signed char count;
	static ControllerSet *_instance_p;
	virtual ~ControllerSet();
	ControllerSet *Init();
	Controller &Add_Controller(Controller &c);
	void Remove_Controller(Controller &c);
	void Sync_Controllers(LocalController &lc);
	void Update_VControllers(LocalController &lc);
	void Update();
};

ControllerSet::~ControllerSet()
{
	if (local_p) {
		LocalController *l = local_p;
		local_p = 0;
		delete l;
	}
	_instance_p = 0;
}

ControllerSet *ControllerSet::Init()
{
	_instance_p = this;
	count = 0;
	for (int i = 0; i < 8; i++)
		controllers[i] = 0;
	ctrlFlushVirtualDataAll();
	local_p = (new LocalController)->Init();
	wait = 300;
	return this;
}

Controller &ControllerSet::Add_Controller(Controller &c)
{
	int n = count;
	if (n < 8) {
		for (int i = 0; i < 8; i++) {
			if (controllers[i] == 0) {
				controllers[i] = &c;
				break;
			}
		}
		count = n + 1;
	}
	return c;
}

void ControllerSet::Remove_Controller(Controller &c)
{
	if (&c == 0)
		return;
	for (int i = 0; i < 8; i++) {
		if (controllers[i] == &c) {
			controllers[i] = 0;
			int n = count;
			count = n - 1;
			return;
		}
	}
}

void ControllerSet::Sync_Controllers(LocalController &lc)
{
	ControllerData *d = lc.Get_Data();
	short f0 = d->f0;
	short f2 = d->f2;
	if (f0 != f2)
		return;
	for (int i = 0; i < 8; i++) {
		Controller *c = controllers[i];
		if (c && c->Get_Data()->f0 != f0)
			return;
	}
	lc.seq = (f2 + 1) & 0x7FFF;
}

void ControllerSet::Update_VControllers(LocalController &lc)
{
	int w = wait - 1;
	if (w >= 0)
		wait = w;
	ControllerData *d = lc.Get_Data();
	short f0 = d->f0;
	short f2 = d->f2;
	if (f0 == f2)
		return;
	bool synced = true;
	for (int i = 0; i < 8; i++) {
		Controller *c = controllers[i];
		if (c && c->Get_Data()->f2 != f2) {
			synced = false;
			break;
		}
	}
	if (!synced)
		return;
	wait = 300;
	for (int i = 0; i < 8; i++) {
		Controller *c = controllers[i];
		if (c) {
			CtrlVirtualData buf[5];
			ControllerData *cd = c->Get_Data();
			for (int j = 0; j < 5; j++) {
				buf[j].f0 = 0;
				buf[j].f4 = cd->entry[j].f4;
				buf[j].f8 = cd->entry[j].f8;
				buf[j].f9 = cd->entry[j].f9;
			}
			if (!ctrlSetVirtualData(c->id, buf, 5))
				return;
		}
	}
	d->f0 = f2;
}

void ControllerSet::Update()
{
	LocalController *l = local_p;
	if (l && count >= 2) {
		Update_VControllers(*l);
		Sync_Controllers(*l);
		l->Update();
	}
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set", D_001078CC); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set", _ZTVN10SaruNetLib13ControllerSetE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set", D_001078E8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set", _ZTIN10SaruNetLib13ControllerSetE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller_set", _ZTSN10SaruNetLib13ControllerSetE); }
