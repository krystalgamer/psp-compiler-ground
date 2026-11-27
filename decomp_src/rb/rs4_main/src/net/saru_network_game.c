/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct SceNetEtherAddr {
	unsigned char data[6];
};

extern "C" void *memset(void *, int, unsigned long);

namespace Net {
struct EtherAddress {
	SceNetEtherAddr addr;
	EtherAddress() { __builtin_memset(this, 0, sizeof(*this)); }
};
}
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
};
struct NetCompletionData {
	int status;
	void *user;
};
struct NetTypeConnectCallbackData {
	int f0;
	int _4[3];
	void *user;
};
struct NetTypeClientConnectCallbackData {
	int _0;
	int f4;
	int _8[3];
	void *user;
};
struct NetRemoteClientEventData {
	int f0;
	int _4;
	int f8;
	void *user;
};
struct NetPeerToPeerHostChangeData {
	int _0[2];
	void *user;
};
struct NetSMChangeData {
	int _0[2];
	void *user;
};

extern "C" {
void *memset(void *, int, unsigned long);
int memcmp(const void *, const void *, unsigned long);
void consPrintf(const char *fmt, ...);
int NetGetLocalTime(int *t);
int sceDisplayWaitVblankStart(void);
extern const char D_00107B00[];
extern const char D_00107B2C[];
extern const char D_00107B48[];
extern const char D_00107B60[];
extern const char D_00107B8C[];
extern const char D_00107BB0[];
extern const char D_00107BD8[];
extern const char D_00107BFC[];
extern const char D_00107C24[];
extern const char D_00107C40[];
extern const char D_00107C6C[];
extern const char D_00107C90[];
extern const char D_00107CB8[];
}

namespace Net {
class Network {
public:
	unsigned int _4[2];
	bool _c0 : 1;
	bool _c1 : 1;
	bool _c2 : 1;
	bool _c3 : 1;
	bool fail : 1;
	unsigned int _c5 : 27;
	static Network *_instance_p;
	virtual ~Network();
	virtual void Update();
};

namespace Param {
class GameStartup {
public:
	int f0;
	int f4;
	int f8;
	void (*cb_local_connect)(NetTypeConnectCallbackData *);
	void *arg_local_connect;
	void (*cb_local_disconnect)(NetTypeConnectCallbackData *);
	void *arg_local_disconnect;
	void (*cb_remote_connect)(NetTypeClientConnectCallbackData *);
	void *arg_remote_connect;
	void (*cb_remote_disconnect)(NetTypeClientConnectCallbackData *);
	void *arg_remote_disconnect;
	int _2c[3];
	void (*cb_local_join)(NetCompletionData *);
	void *arg_local_join;
	void (*cb_remote_event)(NetRemoteClientEventData *);
	void *arg_remote_event;
	void (*cb_host_change)(NetPeerToPeerHostChangeData *);
	void *arg_host_change;
	void (*cb_sm_change)(NetSMChangeData *);
	void *arg_sm_change;
};
}

class Game {
public:
	Param::GameStartup *param_p;
	int f8;
	int fC;
	bool server : 1;
	bool started : 1;
	bool joined : 1;
	bool use_address : 1;
	unsigned int _f10 : 28;
	NetAddress server_address;
	Game *Init();
	virtual ~Game();
	const SceNetEtherAddr &Set_ServerAddress(const SceNetEtherAddr &a);
	const Param::GameStartup &Set_StartupParam(const Param::GameStartup &p);
	virtual int Startup();
	virtual int Shutdown();
	virtual void Register_NetStructure(Network &net);
	virtual int FindServerCallback(const NetLANFindCallbackDataArgs &a, NetAddress &out);
};
}

namespace SaruNet {
class ResidentData {
public:
	int _0[2];
	SceNetEtherAddr address;
	static ResidentData *Get_Instance_p();
};

class Game : public Net::Game {
public:
	short max_player;
	short player;
	union {
		unsigned int flags;
		struct {
			bool error : 1;
		};
	};
	static Game *_instance_p;
	void Set_MaxPlayer(int n) { max_player = n; }
	void Set_Player(int n) { player = n; }
	int Get_Player() const { return player; }
	Game *Init();
	const Net::Param::GameStartup &Set_StartupParam(Net::Param::GameStartup &p);
	virtual int Startup();
	virtual int Shutdown();
	virtual int FindServerCallback(const NetLANFindCallbackDataArgs &a, NetAddress &out);
	static void gCallback_LocalConnect(NetTypeConnectCallbackData *d);
	virtual void Callback_LocalConnect(NetTypeConnectCallbackData *d);
	static void gCallback_LocalDisconnect(NetTypeConnectCallbackData *d);
	virtual void Callback_LocalDisconnect(NetTypeConnectCallbackData *d);
	static void gCallback_RemoteClientConnect(NetTypeClientConnectCallbackData *d);
	virtual void Callback_RemoteClientConnect(NetTypeClientConnectCallbackData *d);
	static void gCallback_RemoteClientDisconnect(NetTypeClientConnectCallbackData *d);
	virtual void Callback_RemoteClientDisconnect(NetTypeClientConnectCallbackData *d);
	static void gCallback_LocalJoin(NetCompletionData *d);
	virtual void Callback_LocalJoin(NetCompletionData *d);
	static void gCallback_RemoteClientEvent(NetRemoteClientEventData *d);
	virtual void Callback_RemoteClientEvent(NetRemoteClientEventData *d);
	static void gCallback_P2PHostChange(NetPeerToPeerHostChangeData *d);
	virtual void Callback_P2PHostChange(NetPeerToPeerHostChangeData *d);
	static void gCallback_SessionMasterChange(NetSMChangeData *d);
	virtual void Callback_SessionMasterChange(NetSMChangeData *d);
};

Game *Game::Init()
{
	Net::Game::Init();
	_instance_p = this;
	max_player = 2;
	flags = 0;
	player = 0;
	return this;
}

const Net::Param::GameStartup &Game::Set_StartupParam(Net::Param::GameStartup &p)
{
	Set_MaxPlayer(p.f8);
	p.cb_local_connect = gCallback_LocalConnect;
	p.cb_local_disconnect = gCallback_LocalDisconnect;
	p.cb_remote_connect = gCallback_RemoteClientConnect;
	p.cb_remote_disconnect = gCallback_RemoteClientDisconnect;
	p.cb_local_join = gCallback_LocalJoin;
	p.cb_remote_event = gCallback_RemoteClientEvent;
	p.cb_host_change = gCallback_P2PHostChange;
	p.cb_sm_change = gCallback_SessionMasterChange;
	p.arg_local_connect = this;
	p.arg_local_disconnect = this;
	p.arg_remote_connect = this;
	p.arg_remote_disconnect = this;
	p.arg_local_join = this;
	p.arg_remote_event = this;
	p.arg_host_change = this;
	p.arg_sm_change = this;
	return Net::Game::Set_StartupParam(p);
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_game", _ZN7SaruNet4Game7StartupEv); }

namespace SaruNet {

int Game::Shutdown()
{
	return Net::Game::Shutdown();
}

void Game::gCallback_LocalConnect(NetTypeConnectCallbackData *d)
{
	((Game *)d->user)->Callback_LocalConnect(d);
}

void Game::Callback_LocalConnect(NetTypeConnectCallbackData *d)
{
	consPrintf(D_00107B8C, d->f0);
}

void Game::gCallback_LocalDisconnect(NetTypeConnectCallbackData *d)
{
	((Game *)d->user)->Callback_LocalDisconnect(d);
}

void Game::Callback_LocalDisconnect(NetTypeConnectCallbackData *d)
{
	consPrintf(D_00107BB0, d->f0);
	error = 1;
}

void Game::gCallback_RemoteClientConnect(NetTypeClientConnectCallbackData *d)
{
	((Game *)d->user)->Callback_RemoteClientConnect(d);
}

void Game::Callback_RemoteClientConnect(NetTypeClientConnectCallbackData *d)
{
	consPrintf(D_00107BD8, d->f4);
	Set_Player(player + 1);
}

void Game::gCallback_RemoteClientDisconnect(NetTypeClientConnectCallbackData *d)
{
	((Game *)d->user)->Callback_RemoteClientDisconnect(d);
}

void Game::Callback_RemoteClientDisconnect(NetTypeClientConnectCallbackData *d)
{
	consPrintf(D_00107BFC, d->f4);
	Set_Player(player - 1);
	error = 1;
}

void Game::gCallback_LocalJoin(NetCompletionData *d)
{
	((Game *)d->user)->Callback_LocalJoin(d);
}

void Game::Callback_LocalJoin(NetCompletionData *d)
{
	consPrintf(D_00107C24);
}

void Game::gCallback_RemoteClientEvent(NetRemoteClientEventData *d)
{
	((Game *)d->user)->Callback_RemoteClientEvent(d);
}

void Game::Callback_RemoteClientEvent(NetRemoteClientEventData *d)
{
	consPrintf(D_00107C40, d->f8, d->f0);
}

void Game::gCallback_P2PHostChange(NetPeerToPeerHostChangeData *d)
{
	((Game *)d->user)->Callback_P2PHostChange(d);
}

void Game::Callback_P2PHostChange(NetPeerToPeerHostChangeData *d)
{
	consPrintf(D_00107C6C);
	Net::Network::_instance_p->fail = 1;
}

void Game::gCallback_SessionMasterChange(NetSMChangeData *d)
{
	((Game *)d->user)->Callback_SessionMasterChange(d);
}

void Game::Callback_SessionMasterChange(NetSMChangeData *d)
{
	consPrintf(D_00107C90);
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_game", _ZN7SaruNet4Game18FindServerCallbackERK26NetLANFindCallbackDataArgsR10NetAddress); }

namespace SaruNet {

}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_game", _ZN7SaruNet4GameD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_game", _ZN7SaruNet4GameD0Ev); }
