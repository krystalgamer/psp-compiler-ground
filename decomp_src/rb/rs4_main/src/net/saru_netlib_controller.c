/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on in this object: LocalController::Init/Reset match only with it */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct NetTypeBroadcastSchedule {
	int f0;
	int f4;
	float f8;
	unsigned char fC;
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
}

namespace Net {
class ObjectClass {
public:
	virtual int Get_ClassID() const;
	virtual int Set_ClassID(int id);
	virtual int Get_Size() const;
	virtual const char *Get_Name() const;
	virtual void *Get_RemoteCreateCallback_p() const;
	virtual void Register_Field();
};

class Object : public Ys::Object {
public:
	int class_id;
	int object_index;
	int _c;
	bool owner;
	void *net_object_p;
	Object *Init(ObjectClass &cls, int object_index);
	virtual ~Object();
	virtual void Callback_Update(int a, int idx, int c);
	virtual void Callback_Remove(int a, int idx);
};
}

namespace SaruNet {
class ObjectClass : public Net::ObjectClass {
public:
	virtual void Register_Field(NetTypeBroadcastSchedule &s);
};

class Object : public Net::Object {
public:
	Object *Init(Net::ObjectClass &cls, bool owner, void *p, const unsigned char *name);
};

class Game {
public:
	char _0[0xC];
	int fC;
	static Game *_instance_p;
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

class Controller;
class LocalController;

class ControllerSet {
public:
	char _0[0x24];
	LocalController *local_p;
	static ControllerSet *_instance_p;
	static ControllerSet *Get_Instance_p() { return _instance_p; }
	void Add_Controller(Controller &c);
	void Remove_Controller(Controller &c);
};

class _Class_Controller : public SaruNet::ObjectClass {
public:
	static int _class_id;
	virtual int Get_ClassID() const;
	virtual int Set_ClassID(int id);
};

class Class_Controller : public _Class_Controller {
public:
	virtual int Get_Size() const;
	virtual const char *Get_Name() const;
	virtual void *Get_RemoteCreateCallback_p() const;
	virtual void Register_Field(NetTypeBroadcastSchedule &s);
};

class Controller : public SaruNet::Object {
public:
	signed char id;
	virtual ~Controller();
	void InitCommon(int id_);
	Controller *Init();
	Controller *Init(int cls, int idx);
	static void gCallback_RemoteCreate(int cls, int idx);
};

struct ControllerBuffer {
	signed char count;
	ControllerEntry entry[5];
};

class LocalController : public Controller {
public:
	ControllerBuffer buffer[2];
	signed char active;
	signed char send;
	short seq;
	virtual ~LocalController();
	LocalController *Init();
	void Reset();
	int Update_ActiveBuffer();
	int Update_SendBuffer();
	void Update();
};

class RemoteController : public Controller {
public:
	virtual ~RemoteController();
	RemoteController *Init(int cls, int idx);
};

int _Class_Controller::Get_ClassID() const
{
	return _class_id;
}

int _Class_Controller::Set_ClassID(int id)
{
	return _class_id = id;
}

int Class_Controller::Get_Size() const
{
	return sizeof(ControllerData);
}

const char *Class_Controller::Get_Name() const
{
	return "controller";
}

void *Class_Controller::Get_RemoteCreateCallback_p() const
{
	return (void *)Controller::gCallback_RemoteCreate;
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZN10SaruNetLib16Class_Controller14Register_FieldER24NetTypeBroadcastSchedule); }

namespace SaruNetLib {

Controller::~Controller()
{
	ControllerSet *s = ControllerSet::Get_Instance_p();
	if (s)
		s->Remove_Controller(*this);
}

void Controller::InitCommon(int id_)
{
	id = id_;
	if (ControllerSet::_instance_p)
		ControllerSet::_instance_p->Add_Controller(*this);
}

Controller *Controller::Init()
{
	static const ControllerData init_param = {
		-1, -1,
		{ { 0, -0x80, -0x80, 0 }, { 0, -0x80, -0x80, 0 }, { 0, -0x80, -0x80, 0 }, { 0, -0x80, -0x80, 0 }, { 0, -0x80, -0x80, 0 } }
	};
	Class_Controller cls;
	SaruNet::Object::Init(cls, true, (void *)&init_param, (const unsigned char *)"controller");
	InitCommon(SaruNet::Game::_instance_p->fC);
	return this;
}

Controller *Controller::Init(int cls_id, int idx)
{
	Class_Controller cls;
	Net::Object::Init(cls, idx);
	InitCommon(cls_id);
	return this;
}

void Controller::gCallback_RemoteCreate(int cls, int idx)
{
	(new RemoteController)->Init(cls, idx);
}

LocalController::~LocalController()
{
	ControllerSet *s = ControllerSet::Get_Instance_p();
	if (s)
		s->local_p = 0;
}

LocalController *LocalController::Init()
{
	Controller::Init();
	for (int i = 0; i < 2; i++)
		buffer[i].count = 0;
	seq = -1;
	active = 0;
	send = 0;
	return this;
}

void LocalController::Reset()
{
	ControllerData *d = (ControllerData *)((int *)net_object_p)[7];
	d->f2 = -1;
	d->f0 = -1;
	for (int i = 0; i < 5; i++) {
		d->entry[i].f4 = 0;
		d->entry[i].f9 = -0x80;
		d->entry[i].f8 = -0x80;
		d->entry[i].fA = 0;
	}
	for (int i = 0; i < 2; i++)
		buffer[i].count = 0;
	seq = -1;
	send = 0;
	active = 0;
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZN10SaruNetLib15LocalController19Update_ActiveBufferEv); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZN10SaruNetLib15LocalController17Update_SendBufferEv); }

namespace SaruNetLib {

void LocalController::Update()
{
	Update_ActiveBuffer();
	Update_SendBuffer();
}

RemoteController::~RemoteController()
{
}

RemoteController *RemoteController::Init(int cls, int idx)
{
	Controller::Init(cls, idx);
	return this;
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTVN10SaruNetLib16RemoteControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", D_00107758); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTVN10SaruNetLib15LocalControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", D_00107770); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTVN10SaruNetLib10ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", D_00107788); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTVN10SaruNetLib16Class_ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", D_001077A0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTVN10SaruNetLib17_Class_ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTIN10SaruNetLib17_Class_ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTIN10SaruNetLib16Class_ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTIN10SaruNetLib10ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTIN10SaruNetLib15LocalControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTIN10SaruNetLib16RemoteControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTSN10SaruNetLib16RemoteControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTSN10SaruNetLib15LocalControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTSN10SaruNetLib10ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTSN10SaruNetLib16Class_ControllerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_controller", _ZTSN10SaruNetLib17_Class_ControllerE); }
