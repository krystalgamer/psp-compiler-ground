/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

enum NetOwnershipStatus { NET_OWN_0 };
enum NetObjectLifespan { NET_LIFE_0 };
enum NetErrorCode { NetErrorNone };

extern "C" {
void consPrintf(const char *fmt, ...);
int NetRegisterObjectStart(void);
int NetRegisterStructure(int *cls, const char *name, int size);
int NetRegisterRemoteObjectCallback(int cls, void *create, void *update, void *remove);
int NetCreateObject(int *idx, NetOwnershipStatus own, NetObjectLifespan life, unsigned int a, int b, int c, bool d, void *e, const unsigned char *f, int cls);
int NetGetObject(void **p, int idx);
int NetFreeObject(int idx);
}

#ifndef NULL
#define NULL 0
#endif
#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/net/network_object.cc", __LINE__, __FUNCTION__, #e)

extern "C" void _memFree(void *p, const char *file, int line);

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};
}

namespace Net {

class Network {
public:
	char _0[0x10];
	int error;
	static Network *_instance_p;
	int Set_Error(int e) { return error = e; }
};

class Object;

class ObjectDaemon {
public:
	int _0[2];
	Object **object_p;
	static ObjectDaemon *_instance_p;
	void Add_Object(int idx, Object &o);
	void Remove_Object(Object &o);
};

class ObjectClass {
public:
	virtual int Get_ClassID() const;
	virtual int Set_ClassID(int id);
	virtual int Get_Size() const;
	virtual const char *Get_Name() const;
	virtual void *Get_RemoteCreateCallback_p() const;
	virtual void Register_Field();
	int Register();
};

class Object : public Ys::Object {
public:
	int class_id;
	int object_index;
	int _c;
	bool owner;
	void *net_object_p;
	static int Register(ObjectClass &c);
	Object *Init(ObjectClass &cls, NetOwnershipStatus own, NetObjectLifespan life, unsigned int a, int b, int c, bool d, void *e, const unsigned char *f);
	Object *Init(ObjectClass &cls, int object_index);
	virtual ~Object();
	virtual void Callback_Update(int a, int idx, int c);
	static void gCallback_Update(int a, int idx, int c);
	virtual void Callback_Remove(int a, int idx);
	static void gCallback_Remove(int a, int idx);
};

int ObjectClass::Get_ClassID() const
{
	return 0;
}

int ObjectClass::Set_ClassID(int id)
{
	return id;
}

int ObjectClass::Get_Size() const
{
	return 0;
}

const char *ObjectClass::Get_Name() const
{
	return "Anonymous";
}

void *ObjectClass::Get_RemoteCreateCallback_p() const
{
	return 0;
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", _ZN3Net11ObjectClass8RegisterEv); }

namespace Net {

void ObjectClass::Register_Field()
{
}

int Object::Register(ObjectClass &c)
{
	return c.Register();
}

Object *Object::Init(ObjectClass &cls, NetOwnershipStatus own, NetObjectLifespan life, unsigned int a, int b, int c, bool d, void *e, const unsigned char *f)
{
	owner = 1;
	object_index = -1;
	int idx = -1;
	Network &network = *Network::_instance_p;
	class_id = cls.Get_ClassID();
	if (network.Set_Error(NetCreateObject(&idx, own, life, a, b, c, d, e, f, class_id)) != NetErrorNone) {
		consPrintf("network object : can't create. - %d\n", network.error);
		return this;
	}
	object_index = idx;
	void *net_object_p;
	if (network.Set_Error(NetGetObject(&net_object_p, idx)) != NetErrorNone) {
		consPrintf("network object : can't create. - %d\n", network.error);
		return this;
	}
#line 217
	cassert(net_object_p != NULL);
	this->net_object_p = net_object_p;
	ObjectDaemon::_instance_p->Add_Object(idx, *this);
	return this;
}

Object *Object::Init(ObjectClass &cls, int object_index)
{
	owner = 0;
	Network &network = *Network::_instance_p;
	class_id = cls.Get_ClassID();
	this->object_index = -1;
	void *net_object_p;
#line 249
	cassert(network.Set_Error(NetGetObject(&net_object_p, object_index)) == NetErrorNone);
	cassert(net_object_p != NULL);
	this->object_index = object_index;
	this->net_object_p = net_object_p;
	ObjectDaemon::_instance_p->Add_Object(object_index, *this);
	return this;
}

Object::~Object()
{
	int idx = object_index;
	if (idx >= 0) {
		object_index = -1;
		if (ObjectDaemon::_instance_p)
			ObjectDaemon::_instance_p->Remove_Object(*this);
		Network::_instance_p->error = NetFreeObject(idx);
	}
}

void Object::Callback_Update(int a, int idx, int c)
{
}

void Object::gCallback_Update(int a, int idx, int c)
{
	Object *o = ObjectDaemon::_instance_p->object_p[idx];
	if (o)
		o->Callback_Update(a, idx, c);
}

void Object::Callback_Remove(int a, int idx)
{
}

void Object::gCallback_Remove(int a, int idx)
{
	consPrintf("remove object : %d %d.\n", a, idx);
	Object *o = ObjectDaemon::_instance_p->object_p[idx];
	if (o) {
		o->Callback_Remove(a, idx);
		delete o;
	}
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", _ZTVN3Net6ObjectE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", D_00106F80); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", _ZTVN3Net11ObjectClassE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", _ZTIN3Net11ObjectClassE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", _ZTIN3Net6ObjectE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", _ZTSN3Net6ObjectE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object", _ZTSN3Net11ObjectClassE); }
