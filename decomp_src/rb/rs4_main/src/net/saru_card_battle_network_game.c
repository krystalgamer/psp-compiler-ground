/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
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
extern const char D_001072AC[];
}

#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/net/saru_card_battle_network_game.cc", __LINE__, __FUNCTION__, #e)

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_001072AC, 23); }
	static void operator delete(void *p) { _memFree(p, D_001072AC, 25); }
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

namespace SaruNet {
namespace CardBattle {
class NetworkTask;

class _Class_Player : public Net::ObjectClass {
public:
	static int _class_id;
};
class Class_Player : public _Class_Player {
};
class Class_Host : public SaruNetLib::Class_Host {
};

class NetworkHost : public SaruNetLib::Host {
public:
	static int Register() { Class_Host c; return Net::Object::Register(c); }
};

class NetworkPlayer : public SaruNet::Object {
public:
	NetworkPlayer *Init();
	static int Register() { Class_Player c; return Net::Object::Register(c); }
};

class NetworkGame : public SaruNet::Game {
public:
	NetworkTask *task_p;
	SaruNetLib::Host *host_p;
	NetworkPlayer *player_p;
	NetworkPlayer *remote_player_p;
	virtual ~NetworkGame();
	NetworkGame *Init(NetworkTask &t);
	virtual int Startup();
	virtual int Register_NetStructure(Net::Network &net);
	NetworkPlayer *Get_Player_p(int i) const;
};

NetworkGame::~NetworkGame()
{
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
	return this;
}

int NetworkGame::Startup()
{
	host_p = 0;
	player_p = 0;
	remote_player_p = 0;
	if (!SaruNet::Game::Startup())
		return 0;
	if (server)
		host_p = (new NetworkHost)->Init();
	player_p = (new NetworkPlayer)->Init();
	return 1;
}

int NetworkGame::Register_NetStructure(Net::Network &net)
{
#line 102
	cassert(NetworkHost::Register() == NetErrorNone);
	consPrintf("card battle network game : host registered.\n");

	cassert(NetworkPlayer::Register() == NetErrorNone);
	consPrintf("card battle network game : player registered.\n");
	return 0;
}

}
}

extern "C" const char D_001073D4[] = "";

namespace SaruNet {
namespace CardBattle {

NetworkPlayer *NetworkGame::Get_Player_p(int i) const
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

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_game", _ZTVN7SaruNet10CardBattle11NetworkGameE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_game", D_001073E0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_game", _ZTVN7SaruNet10CardBattle11NetworkHostE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_game", D_00107420); }
