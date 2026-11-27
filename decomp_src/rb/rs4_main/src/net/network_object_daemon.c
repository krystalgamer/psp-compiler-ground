/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: Init's clear loop matches only with it (pointer IV + down-counter) */
/* #pragma interface: the vtable and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object_daemon", D_00106FEC);
}
extern "C" const char D_00106FEC[];

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00106FEC, 23); }
	static void operator delete(void *p) { _memFree(p, D_00106FEC, 25); }
};
template <class T> inline T *New_Array(int n) { return (T *)_memAllocMBL(n * sizeof(T), D_00106FEC, 32); }
template <class T> inline void Delete_Array(T *p) { if (p) _memFree(p, D_00106FEC, 37); }
}

namespace Net {
class Object {
public:
	virtual ~Object();
	char _p[0xC];
	bool is_local;
};

class ObjectDaemon : public Ys::Object {
public:
	short count;
	short max;
	int Get_Count() const { return count; }
	int Get_Max() const { return max; }
	Net::Object **objs;
	static ObjectDaemon *_instance_p;
	virtual ~ObjectDaemon();
	ObjectDaemon *Init(int n);
	Net::Object *Add_Object(int i, Net::Object &o);
	void Remove_Object(Net::Object &o);
	void Remove_AllLocalObject();
};

ObjectDaemon::~ObjectDaemon()
{
	Ys::Delete_Array(objs);
	_instance_p = 0;
}

}
extern "C" {
namespace Net {
ObjectDaemon *ObjectDaemon::Init(int n)
{
	count = 0;
	max = n;
	_instance_p = this;
	Net::Object **p = Ys::New_Array<Net::Object *>(n);
	objs = p;
	for (int i = 0; i < n; i++)
		p[i] = 0;
	return this;
}
}
}
namespace Net {

Net::Object *ObjectDaemon::Add_Object(int i, Net::Object &o)
{
	if (objs[i] == 0)
		count = Get_Count() + 1;
	objs[i] = &o;
	return &o;
}

void ObjectDaemon::Remove_Object(Net::Object &o)
{
	int i;
	int n = Get_Max();
	for (i = 0; i < n; i++) {
		if (objs[i] == &o) {
			objs[i] = 0;
			count = Get_Count() - 1;
			return;
		}
	}
}

void ObjectDaemon::Remove_AllLocalObject()
{
	int i;
	int n = Get_Max();
	for (i = 0; i < n; i++) {
		Net::Object *p = objs[i];
		if (p && p->is_local) {
			objs[i] = 0;
			delete p;
			count = Get_Count() - 1;
		}
	}
}
}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object_daemon", _ZTVN3Net12ObjectDaemonE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object_daemon", D_00107008);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object_daemon", _ZTIN3Net12ObjectDaemonE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_object_daemon", _ZTSN3Net12ObjectDaemonE);
}
