/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#include "common.h"

struct NetAddress {
	int type;
	unsigned char ether[6];
	char _a[10];
	int port;
};

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
void consPrintf(const char *fmt, ...);
}

#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/net/saru_petit_network_game.cc", __LINE__, __FUNCTION__, #e)

struct NetLANFindCallbackDataArgs;
struct NetTypeConnectCallbackData;
struct NetTypeClientConnectCallbackData;
struct NetCompletionData;
struct NetRemoteClientEventData;
struct NetPeerToPeerHostChangeData;
struct NetSMChangeData;

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};
}

enum { NetErrorNone = 0 };

namespace Net {
class Network;

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
	virtual ~Object();
	virtual void Callback_Update(int a, int idx, int c);
	virtual void Callback_Remove(int a, int idx);
	static int Register(ObjectClass &c);
};

class Game : public Ys::Object {
public:
	void *param_p;
	int f8;
	int fC;
	bool server : 1;
	unsigned int _f10 : 31;
	NetAddress server_address;
	virtual ~Game();
	virtual int Startup();
	virtual int Shutdown();
	virtual int Register_NetStructure(Network &net);
	virtual int FindServerCallback(const NetLANFindCallbackDataArgs &a, NetAddress &out);
};
}

namespace SaruNet {
class Object : public Net::Object {
};

class Game : public Net::Game {
public:
	short max_player;
	short player;
	unsigned int flags;
	virtual int Startup();
	Game *Init();
	virtual int Shutdown();
	virtual int FindServerCallback(const NetLANFindCallbackDataArgs &a, NetAddress &out);
	virtual void Callback_LocalConnect(NetTypeConnectCallbackData *d);
	virtual void Callback_LocalDisconnect(NetTypeConnectCallbackData *d);
	virtual void Callback_RemoteClientConnect(NetTypeClientConnectCallbackData *d);
	virtual void Callback_RemoteClientDisconnect(NetTypeClientConnectCallbackData *d);
	virtual void Callback_LocalJoin(NetCompletionData *d);
	virtual void Callback_RemoteClientEvent(NetRemoteClientEventData *d);
	virtual void Callback_P2PHostChange(NetPeerToPeerHostChangeData *d);
	virtual void Callback_SessionMasterChange(NetSMChangeData *d);
};
}

namespace SaruNetLib {
class _Class_Host : public Net::ObjectClass {
public:
	static int _class_id;
};
class Class_Host : public _Class_Host {
};
class Host : public SaruNet::Object {
public:
	virtual ~Host();
	Host *Init();
	static int Register() { Class_Host c; return Net::Object::Register(c); }
};
}

struct Task;

namespace Ys {
class Task : public Object {
public:
	::Task *task_p;
	void *state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
};
}

namespace SaruNetLib {
class LocalController {
public:
	void Reset();
};
class _Class_Controller : public Net::ObjectClass {
public:
	static int _class_id;
};
class Class_Controller : public _Class_Controller {
};
class ControllerSetTask : public Ys::Task {
public:
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};
class ControllerSet {
public:
	char _4[0x20];
	LocalController *local_p;
	char _28[4];
	virtual ~ControllerSet();
};
}

namespace SaruNet {
namespace PetitGame {
class NetworkTask;

class _Class_CardBattlePlayer : public Net::ObjectClass {
public:
	static int _class_id;
};
class Class_CardBattlePlayer : public _Class_CardBattlePlayer {
};

class CardBattlePlayer : public SaruNet::Object {
public:
	CardBattlePlayer *Init();
	static int Register() { Class_CardBattlePlayer c; return Net::Object::Register(c); }
};

class ControllerSet : public SaruNetLib::ControllerSetTask, public SaruNetLib::ControllerSet {
public:
	ControllerSet *Init(NetworkTask &t);
	static int Register() { SaruNetLib::Class_Controller c; return Net::Object::Register(c); }
};

class NetworkGame : public SaruNet::Game {
public:
	NetworkTask *task_p;
	CardBattlePlayer *player_p;
	CardBattlePlayer *remote_player_p;
	ControllerSet *controller_set_p;
	SaruNetLib::Host *host_p;
	virtual ~NetworkGame();
	NetworkGame *Init(NetworkTask &t);
	virtual int Startup();
	virtual int Register_NetStructure(Net::Network &net);
	CardBattlePlayer *Get_CardBattlePlayer_p(int i) const;
	void Reset_LocalController();
};

class Class_Host : public SaruNetLib::Class_Host {
public:
	virtual void *Get_RemoteCreateCallback_p() const;
};

class NetworkHost : public SaruNetLib::Host {
public:
	static int Register() { Class_Host c; return Net::Object::Register(c); }
};

NetworkGame::~NetworkGame()
{
	delete controller_set_p;
	controller_set_p = 0;
	remote_player_p = 0;
	player_p = 0;
	host_p = 0;
}

NetworkGame *NetworkGame::Init(NetworkTask &t)
{
	SaruNet::Game::Init();
	task_p = &t;
	host_p = 0;
	player_p = 0;
	remote_player_p = 0;
	controller_set_p = 0;
	return this;
}

int NetworkGame::Startup()
{
	host_p = 0;
	player_p = 0;
	remote_player_p = 0;
	controller_set_p = 0;
	if (!SaruNet::Game::Startup())
		return 0;
	if (server)
		host_p = (new NetworkHost)->Init();
	player_p = (new CardBattlePlayer)->Init();
	NetworkTask &t = *task_p;
	controller_set_p = (new ControllerSet)->Init(t);
	return 1;
}

int NetworkGame::Register_NetStructure(Net::Network &net)
{
#line 110
	cassert(NetworkHost::Register() == NetErrorNone);
	consPrintf("petit network game : host registered.\n");

	cassert(CardBattlePlayer::Register() == NetErrorNone);
	consPrintf("petit network game : card battle player registered.\n");

	cassert(ControllerSet::Register() == NetErrorNone);
	consPrintf("petit network game : controllers registered.\n");
	return 0;
}

CardBattlePlayer *NetworkGame::Get_CardBattlePlayer_p(int i) const
{
	if (server) {
		if (i == 0)
			return player_p;
		return remote_player_p;
	}
	if (i == 0)
		return remote_player_p;
	return player_p;
}

void NetworkGame::Reset_LocalController()
{
	SaruNetLib::LocalController *c = controller_set_p->local_p;
	if (c)
		c->Reset();
}

}
}


