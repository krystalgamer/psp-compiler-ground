/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
extern const char D_0010765C[];
}

struct Task;

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_0010765C, 23); }
	static void operator delete(void *p) { _memFree(p, D_0010765C, 25); }
};
class TaskState;
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
class Game;
class Lobby;
class Network : public Ys::Object {
public:
	static Network *_instance_p;
	virtual ~Network();
	virtual void Update();
	virtual int Activate(Game &g);
	virtual int Activate(Lobby &l);
	virtual void Inactivate();
};
namespace Param {
class GameStartup {
public:
	int f0, f4, f8;
	int fC[8];
	char f2C;
	int f30, f34, f38, f3C, f40, f44, f48, f4C, f50, f54;
	char f58[12];
	char f64;
	char f65[8];
	GameStartup() { Reset(); }
	void Reset();
};
}
class Game : public Ys::Object {
public:
	virtual ~Game();
};
}

namespace SaruNet {
namespace Param {
class GameStartup : public Net::Param::GameStartup {
public:
	GameStartup() { Reset(); }
	void Reset();
};
}

class WaiWaiData {
public:
	char _0[0x30C];
	unsigned int error_card_battle : 1;
	unsigned int error_petit_game : 1;
};

class ResidentData {
public:
	char _0[0x10];
	WaiWaiData waiwai;
	static ResidentData *Get_Instance_p();
	WaiWaiData &Get_WaiWaiData() { return waiwai; }
};

class Game : public Net::Game {
public:
	const Net::Param::GameStartup &Set_StartupParam(Net::Param::GameStartup &p);
};

class NetworkTask : public Ys::Task {
public:
	Net::Game *game_p;
	Ys::TaskState *startup_state_p;
	Ys::TaskState *setup_state_p;
	Ys::TaskState *quit_state_p;
	Ys::TaskState *delay_error_state_p;
	signed char startup_wait;
	signed char delay_wait;
	signed char min_object;
	union {
		unsigned int flags;
		struct {
			bool quit : 1;
			bool error : 1;
			bool delay_error : 1;
		};
	};
	NetworkTask *Init(int a, int b, int pri);
	virtual ~NetworkTask();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Start_Game();
	virtual void Quit();
	virtual void ErrorQuit();
	virtual int Activate_Game();
	virtual void Quit_Module();
};

namespace CardBattle {
class NetworkTask;
}
}

struct SaruNet_CardBattle_NetworkTask_Callback {
	void (*func)(SaruNet::CardBattle::NetworkTask *t, void *arg);
	void *arg;
	void Copy(const SaruNet_CardBattle_NetworkTask_Callback &c) { func = c.func; arg = c.arg; }
	void Reset() { func = 0; arg = 0; }
};

struct SaruNet_CardBattle_NetworkTask_Info {
	int _0[14];
};

struct SaruNet_CardBattle_NetworkTask_CallbackSet {
	SaruNet_CardBattle_NetworkTask_Callback start_game;
	SaruNet_CardBattle_NetworkTask_Callback quit;
	SaruNet_CardBattle_NetworkTask_Callback error;
};

typedef void (*SaruNet_CardBattle_NetworkTask_CallbackFunc)(SaruNet::CardBattle::NetworkTask *t, void *arg);

struct SaruNet_CardBattle_NetworkTask_CreateParam {
	int f0;
	SaruNet_CardBattle_NetworkTask_CallbackFunc start_game_func;
	void *start_game_arg;
	SaruNet_CardBattle_NetworkTask_CallbackFunc quit_func;
	void *quit_arg;
	SaruNet_CardBattle_NetworkTask_CallbackFunc error_func;
	void *error_arg;
	SaruNet_CardBattle_NetworkTask_Info info;
};

namespace SaruNet {
namespace CardBattle {

class NetworkGame : public SaruNet::Game {
public:
	char _4[0x40];
	NetworkGame *Init(NetworkTask &t);
};

class NetworkTask : public SaruNet::NetworkTask {
public:
	SaruNet_CardBattle_NetworkTask_CallbackSet callback;
	SaruNet_CardBattle_NetworkTask_Info info;
	virtual ~NetworkTask();
	NetworkTask *Init(int pri, SaruNet_CardBattle_NetworkTask_CreateParam *p);
	virtual void Start_Game();
	virtual void Quit();
	virtual void ErrorQuit();
	virtual void Quit_Module();
};

NetworkTask::~NetworkTask()
{
	if (!quit && !error)
		Quit();
}

NetworkTask *NetworkTask::Init(int pri, SaruNet_CardBattle_NetworkTask_CreateParam *p)
{
	SaruNet::NetworkTask::Init(0x2225, 3, pri);
	ResidentData::Get_Instance_p()->Get_WaiWaiData().error_card_battle = 0;
	if (p) {
		callback.start_game.func = p->start_game_func;
		callback.start_game.arg = p->start_game_arg;
		callback.quit.func = p->quit_func;
		callback.quit.arg = p->quit_arg;
		callback.error.func = p->error_func;
		callback.error.arg = p->error_arg;
	} else {
		callback.start_game.func = 0;
		callback.start_game.arg = 0;
		callback.quit.func = 0;
		callback.quit.arg = 0;
		callback.error.func = 0;
		callback.error.arg = 0;
	}
	info = p->info;
	NetworkGame *g = (new NetworkGame)->Init(*this);
	game_p = g;
	SaruNet::Param::GameStartup sp;
	sp.f8 = 2;
	g->Set_StartupParam(sp);
	return this;
}

void NetworkTask::Start_Game()
{
	ResidentData::Get_Instance_p()->Get_WaiWaiData().error_card_battle = 0;
	if (callback.start_game.func)
		callback.start_game.func(this, callback.start_game.arg);
	SaruNet::NetworkTask::Start_Game();
}

void NetworkTask::Quit()
{
	if (callback.quit.func)
		callback.quit.func(this, callback.quit.arg);
	SaruNet::NetworkTask::Quit();
	Quit_Module();
}

void NetworkTask::ErrorQuit()
{
	ResidentData::Get_Instance_p()->Get_WaiWaiData().error_card_battle = 1;
	if (callback.error.func)
		callback.error.func(this, callback.error.arg);
	quit = 1;
	error = 1;
	state_p = quit_state_p;
	Net::Network::_instance_p->Inactivate();
}

void NetworkTask::Quit_Module()
{
	quit = 1;
	error = 0;
	state_p = quit_state_p;
	Net::Network::_instance_p->Inactivate();
}

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task", D_0010765C); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task", _ZTVN7SaruNet10CardBattle11NetworkTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task", D_00107678); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task", _ZTIN7SaruNet10CardBattle11NetworkTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_task", _ZTSN7SaruNet10CardBattle11NetworkTaskE); }
