/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct SceNetAdhocctlGroupName {
	unsigned char data[8];
};
struct SceNetEtherAddr {
	unsigned char data[6];
};

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void *_memReallocMBL(void *p, unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
void *memset(void *, int, unsigned long);
void consPrintf(const char *fmt, ...);
int sceNetAdhocctlAddHandler(void *h, void *arg);
int sceNetAdhocctlDelHandler(int id);
int sceNetAdhocctlScan(void);
int sceNetAdhocctlConnect(SceNetAdhocctlGroupName *g);
int sceNetAdhocctlDisconnect(void);
int sceNetGetLocalEtherAddr(SceNetEtherAddr *a);
int sceKernelDelayThread(unsigned int us);
void NetUseDme(void);
void NetUseCommAdhoc(void);
int NetSetDefaultNetUseObjectsInParams(void *p);
int NetUseObjects(void *p);
void NetClose(void);
int NetSetDefaultNetUsePeerToPeerInParams(void *p);
int NetUsePeerToPeer(void *p);
int NetSetDefaultMemoryCallbackParams(void *p);
int NetRegisterMemoryCallbacks(void *p);
int NetInitialize(void *p, void *q);
void NetUpdate(void);
extern const char D_00105504[];
extern const char D_00105518[];
extern const char D_00105534[];
extern const char D_00105550[];
extern const char D_001055DC[];
extern const char D_001055FC[];
}

#define cassert_x(e, s) if (!(e)) consPrintf(D_00105534, D_00105504, __LINE__, __FUNCTION__, s)
#define cassert(e) if (!(e)) consPrintf(D_00105534, D_00105504, __LINE__, __FUNCTION__, #e)

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00105518, 23); }
	static void operator delete(void *p) { _memFree(p, D_00105518, 25); }
};
}

namespace Net {
struct EtherAddress {
	SceNetEtherAddr addr;
	SceNetEtherAddr &Get_SceAddress() { return addr; }
};

class System : public Ys::Object {
public:
	~System();
	System *Init();
};

}
enum NetConnectivityType { NET_CT_0, NET_CT_1, NET_CT_ADHOC };
namespace Net {
namespace Param {
struct GameParam {
	char _0[0x65];
	SceNetAdhocctlGroupName group;
};
class NetworkCreate {
public:
	int f0;
	char _4[0xC];
	int f10;
	char _14[0x5C];
	NetworkCreate(int a, unsigned int b, NetConnectivityType type);
};
}

class Game {
public:
	Param::GameParam *param_p;
	virtual ~Game();
	virtual int Start();
	virtual void Stop();
};

class Lobby {
public:
	static Lobby *_instance_p;
	virtual ~Lobby();
	virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
	virtual int Start();
	virtual void Stop();
};

struct UseObjectsParam {
	char _0[0x20];
};
struct UseP2PParam {
	int f0;
	char _4[0xC];
};
struct MemoryCallbackParam {
	void *(*malloc_f)(unsigned int);
	void *(*realloc_f)(void *, unsigned int);
	void (*free_f)(void *);
	int _c;
};

class Network : public Ys::Object {
public:
	System *system_p;
	Game *game_p;
	union {
		unsigned int flags;
		struct {
			bool use_connect : 1;
			bool active : 1;
			bool scert : 1;
			bool lobby : 1;
			bool fail : 1;
			bool connected : 1;
			bool disconnected : 1;
			bool scanned : 1;
			bool wlan_off : 1;
		};
	};
	int error;
	int f14;
	int f18;
	int handler_id;
	EtherAddress _address;
	static Network *_instance_p;
	static void *malloc(unsigned int size);
	static void free(void *p);
	static void *realloc(void *p, unsigned int size);
	int Set_AdhocctlEventHandlerID(int id) { return handler_id = id; }
	virtual ~Network();
	Network *Init(const Param::NetworkCreate &p, int b);
	int Scan_IBSS();
	int Connect_IBSS_UseConnect(SceNetAdhocctlGroupName &g);
	int Connect_IBSS(SceNetAdhocctlGroupName &g);
	int Disconnect_IBSS();
	virtual void Update();
	virtual int Activate(Game &g);
	virtual int Activate(Lobby &l);
	virtual int Inactivate();
	void AdhocctlEventHandler(int ev, int err, void *arg);
	static void AdhocctlEventHandlerInterface(int ev, int err, void *arg);
};

void *Network::malloc(unsigned int size)
{
	return _memAllocMBL(size, D_00105504, 42);
}

void Network::free(void *p)
{
	_memFree(p, D_00105504, 59);
}

void *Network::realloc(void *p, unsigned int size)
{
	return _memReallocMBL(p, size, D_00105504, 77);
}

Network::~Network()
{
	Inactivate();
	if (handler_id >= 0)
		sceNetAdhocctlDelHandler(handler_id);
	delete system_p;
	_instance_p = 0;
}

}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", D_00105504);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", D_00105518);
}

namespace Net {

Network *Network::Init(const Param::NetworkCreate &p, int b)
{
	_instance_p = this;
	flags = 0;
	f14 = p.f10;
	f18 = p.f0;
	use_connect = !b;
	handler_id = -1;
	system_p = (new System)->Init();
	game_p = 0;
#line 141
	cassert_x(Set_AdhocctlEventHandlerID(sceNetAdhocctlAddHandler((void *)Network::AdhocctlEventHandlerInterface, 0)) >= 0, D_00105550);
	return this;
}

int Network::Scan_IBSS()
{
	scanned = 0;
	return sceNetAdhocctlScan();
}

}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", D_00105534);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", D_00105550);
}

namespace Net {

int Network::Connect_IBSS_UseConnect(SceNetAdhocctlGroupName &g)
{
	if (sceNetAdhocctlConnect(&g) != 0) {
		consPrintf(D_001055DC);
		fail = 1;
		return 0;
	}
	consPrintf("network : ibss connect start..\n");
	for (;;) {
		if (connected)
			break;
		if (fail) {
			consPrintf(D_001055DC);
			return 0;
		}
		sceKernelDelayThread(100000);
	}
	consPrintf(D_001055FC);
	return 1;
}

}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", D_001055DC);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", D_001055FC);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", _ZN3Net7Network12Connect_IBSSER23SceNetAdhocctlGroupName);
}

namespace Net {

int Network::Disconnect_IBSS()
{
	sceKernelDelayThread(2000000);
	if (!disconnected && connected) {
		for (;;) {
			int r = sceNetAdhocctlDisconnect();
			if (r == 0)
				break;
			consPrintf("network : ibss disconnect error - %x\n", r);
			sceKernelDelayThread(100000);
		}
		consPrintf("network : ibss disconnect start..\n");
		for (;;) {
			if (disconnected)
				break;
			sceKernelDelayThread(100000);
		}
		consPrintf("network : ibss disconnected.\n");
	}
	return 1;
}

int Network::Activate(Game &g)
{
	if (active)
		return 1;
	bool uc = use_connect;
	flags = 0;
	use_connect = uc;
	if (!Connect_IBSS(g.param_p->group))
		return 0;
	scert = 0;
	NetUseDme();
	NetUseCommAdhoc();
	UseObjectsParam obj;
	int r;
	if ((r = NetSetDefaultNetUseObjectsInParams(&obj)) != 0) {
		consPrintf("network : can't initialize use object parameter - %d\n", r);
		NetClose();
		return 0;
	}
	if ((r = NetUseObjects(&obj)) != 0) {
		consPrintf("network : can't use network object - %d\n", r);
		NetClose();
		return 0;
	}
	UseP2PParam p2p;
	if ((r = NetSetDefaultNetUsePeerToPeerInParams(&p2p)) != 0) {
		consPrintf("network : can't initialize use p2p parameter - %d\n", r);
		NetClose();
		return 0;
	}
	p2p.f0 = f18;
	if ((r = NetUsePeerToPeer(&p2p)) != 0) {
		consPrintf("network : can't use p2p - %d\n", r);
		NetClose();
		return 0;
	}
	MemoryCallbackParam mc;
	if ((r = NetSetDefaultMemoryCallbackParams(&mc)) != 0) {
		consPrintf("network : can't initialize memory callback parameter - %d\n", r);
		NetClose();
		return 0;
	}
	mc.malloc_f = malloc;
	mc.realloc_f = realloc;
	mc.free_f = free;
	if ((r = NetRegisterMemoryCallbacks(&mc)) != 0) {
		consPrintf("network : can't register memory callback parameter - %d\n", r);
		NetClose();
		return 0;
	}
	Param::NetworkCreate nc(f14, f18, NET_CT_ADHOC);
	char x[0x18];
	memset(x, 0, sizeof(x));
	if ((error = NetInitialize(&nc._4, x)) != 0) {
		consPrintf("network : scert can't initialize.\n");
		return 0;
	}
	scert = 1;
#line 449
	cassert(sceNetGetLocalEtherAddr(&(_address.Get_SceAddress())) == 0);
	game_p = &g;
	if (!g.Start()) {
		active = 1;
		Inactivate();
		return 0;
	}
	active = 1;
	return 1;
}

int Network::Activate(Lobby &l)
{
	if (active)
		return 1;
	bool uc = use_connect;
	flags = 0;
	use_connect = uc;
	active = 1;
	lobby = 1;
	if (l.Start())
		return 1;
	Inactivate();
	return 0;
}

int Network::Inactivate()
{
	if (active) {
		if (!lobby) {
			if (game_p) {
				game_p->Stop();
				game_p = 0;
			}
		} else {
			if (Lobby::_instance_p)
				Lobby::_instance_p->Stop();
			lobby = 0;
		}
		if (scert) {
			NetClose();
			consPrintf("network : scert close.\n");
			scert = 0;
		}
		Disconnect_IBSS();
		active = 0;
	}
	return 1;
}

void Network::Update()
{
	if (scert)
		NetUpdate();
}

}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", _ZN3Net7Network20AdhocctlEventHandlerEiiPv);
}

namespace Net {

void Network::AdhocctlEventHandlerInterface(int ev, int err, void *arg)
{
	Network *n = _instance_p;
	n->AdhocctlEventHandler(ev, err, arg);
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", _ZTVN3Net7NetworkE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", D_00105900); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", _ZTIN3Net7NetworkE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network", _ZTSN3Net7NetworkE); }
