/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
extern const char D_00107D4C[];
}

inline void *operator new[](unsigned int size) { return _memAllocMBL(size, D_00107D4C, 32); }
inline void operator delete[](void *p) { _memFree(p, D_00107D4C, 37); }

struct Task;

struct SaveDataProfile {
	unsigned int name[0x80];
	char _200[2];
	unsigned short f202;
};

struct SaveData {
	char _0[0x28];
	SaveDataProfile profile;
};

extern "C" SaveData *saveGetCurrentData(void);

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, D_00107D4C, 25); }
};
class TaskState : public Object {
public:
	virtual ~TaskState();
};
class Task : public Object {
public:
	::Task *task_p;
	TaskState *state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
};
}

namespace Net {
class Network : public Ys::Object {
public:
	unsigned int _4[2];
	bool _c0 : 1;
	bool connected : 1;
	bool _c2 : 1;
	bool _c3 : 1;
	bool lost : 1;
	bool _c5 : 1;
	bool _c6 : 1;
	bool _c7 : 1;
	bool wlan_off : 1;
	bool error_quit : 1;
	unsigned int _ca : 22;
	static Network *_instance_p;
	virtual ~Network();
};

class LobbyBuilder;

class Lobby : public Ys::Task {
public:
	int _c;
	union {
		unsigned int flags;
		struct {
			bool _f0 : 1;
			bool _f1 : 1;
			bool error : 1;
		};
	};
	char _14[0xC];
	short option_size;
	char *option_p;
	char _28[0x10];
	Ys::TaskState error_state;
	Lobby *Init(LobbyBuilder &b);
	virtual ~Lobby();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual int Startup();
};
}

namespace SaruNet {
namespace LobbyOption {
class Hello {
public:
	unsigned short f0;
	void Set_Name(const unsigned int *name);
};
}

class Lobby : public Net::Lobby {
public:
	virtual ~Lobby();
	Lobby *Init(Net::LobbyBuilder &b);
	virtual int Startup();
	bool Check_ErrorQuit();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

Lobby::~Lobby()
{
	delete[] option_p;
	option_p = 0;
}

Lobby *Lobby::Init(Net::LobbyBuilder &b)
{
	Net::Lobby::Init(b);
	option_size = 0x84;
	option_p = new char[0x84];
	return this;
}

int Lobby::Startup()
{
	LobbyOption::Hello *h = (LobbyOption::Hello *)option_p;
	SaveDataProfile &p = saveGetCurrentData()->profile;
	h->f0 = p.f202;
	h->Set_Name(p.name);
	return Net::Lobby::Startup();
}

bool Lobby::Check_ErrorQuit()
{
	Net::Network *n = Net::Network::_instance_p;
	bool r = false;
	if (n->lost || n->wlan_off || error) {
		error = 1;
		n->error_quit = 1;
		state_p = &error_state;
		r = true;
	}
	return r;
}

void Lobby::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	Net::Lobby::Receive_RunMessage(t, p, n);
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby", D_00107D4C); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby", _ZTVN7SaruNet5LobbyE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby", D_00107D68); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby", _ZTIN7SaruNet5LobbyE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby", _ZTSN7SaruNet5LobbyE); }
