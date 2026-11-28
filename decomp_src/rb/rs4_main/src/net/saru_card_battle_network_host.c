/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#include "common.h"

struct NetTypeBroadcastSchedule;

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
class Object : public Net::Object {
public:
};
}

namespace SaruNet {
class ObjectClass : public Net::ObjectClass {
public:
	virtual void Register_Field();
};
}

namespace SaruNetLib {
class _Class_Host : public SaruNet::ObjectClass {
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
	Host *Init();
	Host *Init(int cls, int idx);
	static void gCallback_RemoteCreate(int cls, int idx);
};
}

namespace SaruNet {
namespace CardBattle {
class NetworkHost;
}

class Game {
public:
	char _0[0x38];
	SaruNetLib::Host *host;
	static Game *_instance_p;
};

namespace CardBattle {
class Class_Host : public SaruNetLib::Class_Host {
public:
	virtual void *Get_RemoteCreateCallback_p() const;
};

class NetworkHost : public SaruNetLib::Host {
public:
	static void gCallback_RemoteCreate(int cls, int idx);
};

}
}


namespace SaruNet {
namespace CardBattle {

void *Class_Host::Get_RemoteCreateCallback_p() const
{
	return (void *)NetworkHost::gCallback_RemoteCreate;
}

}
}


namespace SaruNet {
namespace CardBattle {

void NetworkHost::gCallback_RemoteCreate(int cls, int idx)
{
	Game *g = Game::_instance_p;
	g->host = (new NetworkHost)->Init(cls, idx);
}

}
}

extern "C" const char D_001074A4[] = "";



