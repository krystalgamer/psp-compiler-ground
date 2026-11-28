/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct NetTypeBroadcastSchedule {
	int f0;
	int _4[2];
	unsigned char fC;
};
struct NetObjectFieldInfo {
	int _0[4];
} __attribute__((aligned(16)));

struct HostSeed {
	unsigned int lo;
	unsigned int hi;
};
struct HostData {
	HostSeed seed[2];
	int f10;
};
struct HostObject {
	char _0[0x1C];
	HostData *data;
};

extern "C" {
void randSetSeed(int ch, unsigned long long seed);
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
int NetObjectField(NetObjectFieldInfo *f, int ofs, int size, int type, int a, NetTypeBroadcastSchedule *s);
extern const char D_001079B4[];
extern const char D_001079BC[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_001079BC, 23); }
	static void operator delete(void *p) { _memFree(p, D_001079BC, 25); }
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
class Object : public Net::Object {
public:
};
}

namespace SaruNetLib {
class _Class_Host : public Net::ObjectClass {
public:
	static int _class_id;
	virtual int Get_ClassID() const;
	virtual int Set_ClassID(int id);
};

class Class_Host : public _Class_Host {
public:
	virtual int Get_Size() const;
	virtual const char *Get_Name() const;
	virtual void *Get_RemoteCreateCallback_p() const;
	virtual void Register_Field(NetTypeBroadcastSchedule &s);
};

class Host : public SaruNet::Object {
public:
	virtual ~Host();
	unsigned long long Get_Seed(int i) { HostSeed &s = ((HostObject *)net_object_p)->data->seed[i]; return ((unsigned long long)s.hi << 32) | s.lo; }
	Host *Init();
	Host *Init(int cls, int idx);
	static void gCallback_RemoteCreate(int cls, int idx);
};

int _Class_Host::Get_ClassID() const
{
	return _class_id;
}

int _Class_Host::Set_ClassID(int id)
{
	return _class_id = id;
}

int Class_Host::Get_Size() const
{
	return 0x14;
}

const char *Class_Host::Get_Name() const
{
	return D_001079B4;
}

void *Class_Host::Get_RemoteCreateCallback_p() const
{
	return (void *)Host::gCallback_RemoteCreate;
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZN10SaruNetLib10Class_Host14Register_FieldER24NetTypeBroadcastSchedule); }

namespace SaruNetLib {

Host::~Host()
{
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZN10SaruNetLib4Host4InitEv); }

namespace SaruNetLib {

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZN10SaruNetLib4Host4InitEii); }

namespace SaruNetLib {

void Host::gCallback_RemoteCreate(int cls, int idx)
{
	(new Host)->Init(cls, idx);
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", D_001079B4); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", D_001079BC); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTVN10SaruNetLib4HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", D_001079D8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTVN10SaruNetLib10Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", D_001079F0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTVN10SaruNetLib11_Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTIN10SaruNetLib11_Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTIN10SaruNetLib10Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTIN10SaruNetLib4HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTSN10SaruNetLib4HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTSN10SaruNetLib10Class_HostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_netlib_host", _ZTSN10SaruNetLib11_Class_HostE); }
