/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct SceNetEtherAddr {
	unsigned char data[6];
};
struct NetAddress {
	int type;
	SceNetEtherAddr ether;
	char _a[10];
	int port;
};
struct NetLANFindCallbackDataArgs {
	int _0;
	int status;
	char _8[0x1C];
	NetAddress address;
	char _3c[0x78];
	void *user;
};
struct NetCompletionData {
	int status;
	void *user;
};
struct NetHostPeerToPeerInParams {
	int _0;
	int f4;
	int f8;
	int _c[2];
	int f14;
	int f18;
	int f1C;
	int f20;
	int _24[2];
	int f2C;
	char _30[0x74];
	int fA4;
	char _a8[0x18];
};
struct NetHostPeerToPeerOutParams {
	int _0[2];
	int f8;
};

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
void *memset(void *, int, unsigned long);
void consPrintf(const char *fmt, ...);
int NetSetDefaultHostPeerToPeerParams(NetHostPeerToPeerInParams *p);
int NetHostPeerToPeer(NetHostPeerToPeerInParams *in, NetHostPeerToPeerOutParams *out);
extern const char D_001060D0[];
extern unsigned char _server_find_status;
extern NetAddress _connect_server_address;
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_001060D0, 23); }
	static void operator delete(void *p) { _memFree(p, D_001060D0, 25); }
};
}

namespace Net {
class Network;

namespace Param {
class GameStartup : public Ys::Object {
public:
	int f0;
	int f4;
	int f8;
	int fC;
	int f10;
	int _14[2];
	int f1C;
	int f20;
	int f24;
	int f28;
	signed char f2C;
	char _2d[3];
	int f30;
	int f34;
	void (*callback)(NetCompletionData *d);
	void *callback_arg;
	char _40[0x24];
	bool server;
	char _65[8];
	GameStartup() { Reset(); }
	~GameStartup() {}
	void Reset();
};
}

class Network {
public:
	char _0[0x10];
	int error;
	char _14[4];
	int f18;
	static Network *_instance_p;
};

static inline void Copy_Address(NetAddress &d, const NetAddress &s)
{
	d = s;
}

class Game : public Ys::Object {
public:
	Param::GameStartup *param_p;
	int f8;
	int fC;
	union {
		unsigned int flags;
		struct {
			bool server : 1;
			bool started : 1;
			bool joined : 1;
		};
	};
	NetAddress server_address;
	Game *Init();
	virtual ~Game();
	void Reset_ServerAddress();
	const NetAddress &Set_ServerAddress(const NetAddress &a);
	const SceNetEtherAddr &Set_ServerAddress(const SceNetEtherAddr &a);
	const Param::GameStartup &Set_StartupParam(const Param::GameStartup &p);
	int Startup_Server(Network &net, Param::GameStartup &p);
	static void gCallback_FindServer(const NetLANFindCallbackDataArgs *a);
	int Connect_Server(Network &net, Param::GameStartup &p);
	static void gCallback_LocalJoin(NetCompletionData *d);
	int Join_Game(Network &net, Param::GameStartup &p);
	virtual int Startup();
	virtual int Shutdown();
	virtual int Register_NetStructure(Network &net);
	virtual int FindServerCallback(const NetLANFindCallbackDataArgs &a, NetAddress &out);
};

Game *Game::Init()
{
	param_p = new Param::GameStartup;
	fC = -1;
	f8 = 0;
	flags = 0;
	return this;
}

Game::~Game()
{
	Shutdown();
	delete param_p;
}

void Game::Reset_ServerAddress()
{
	memset(&server_address, 0, sizeof(server_address));
}

const NetAddress &Game::Set_ServerAddress(const NetAddress &a)
{
	Copy_Address(server_address, a);
	return a;
}

const SceNetEtherAddr &Game::Set_ServerAddress(const SceNetEtherAddr &a)
{
	Reset_ServerAddress();
	server_address.type = 2;
	server_address.ether = a;
	server_address.port = Network::_instance_p->f18;
	return a;
}

const Param::GameStartup &Game::Set_StartupParam(const Param::GameStartup &p)
{
	*param_p = p;
	return p;
}

}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", D_001060D0); }

namespace Net {

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", _ZN3Net4Game14Startup_ServerERNS_7NetworkERNS_5Param11GameStartupE); }

namespace Net {

int Game::FindServerCallback(const NetLANFindCallbackDataArgs &a, NetAddress &out)
{
	if (a.status == 0)
		out = a.address;
	return 1;
}

void Game::gCallback_FindServer(const NetLANFindCallbackDataArgs *a)
{
	_server_find_status = ((Game *)a->user)->FindServerCallback(*a, _connect_server_address);
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", _ZN3Net4Game14Connect_ServerERNS_7NetworkERNS_5Param11GameStartupE); }

namespace Net {

void Game::gCallback_LocalJoin(NetCompletionData *d)
{
	consPrintf("network : local join.\n");
	Game *g = (Game *)d->user;
	g->joined = 1;
	Param::GameStartup *p = g->param_p;
	d->status = 0;
	d->user = p->callback_arg;
	p->callback(d);
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", _ZN3Net4Game9Join_GameERNS_7NetworkERNS_5Param11GameStartupE); }

namespace Net {

class ObjectDaemon : public Ys::Object {
public:
	int _4[2];
	virtual ~ObjectDaemon();
	ObjectDaemon *Init(int n);
};

int Game::Startup()
{
	if (started)
		return 1;
	started = 1;
	Network *net = Network::_instance_p;
	Register_NetStructure(*net);
	Param::GameStartup *p = param_p;
	int n = p->f8 * p->f30;
	(new ObjectDaemon)->Init(n);
	if (p->server) {
		if (!Startup_Server(*net, *p))
			return 0;
		server = 1;
	} else {
		if (!Connect_Server(*net, *p))
			return 0;
		server = 0;
	}
	return Join_Game(*net, *p);
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", _ZN3Net4Game8ShutdownEv); }

namespace Net {

int Game::Register_NetStructure(Network &net)
{
	return 0;
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", _ZTVN3Net4GameE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", D_00106330); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", _ZTIN3Net4GameE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_game", _ZTSN3Net4GameE); }
