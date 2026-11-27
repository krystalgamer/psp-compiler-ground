/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
extern const char D_00108DC0[];
}

struct Task;

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00108DC0, 23); }
	static void operator delete(void *p) { _memFree(p, D_00108DC0, 25); }
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

namespace Ys {
class ScreenPanelDaemon {
public:
	static ScreenPanelDaemon *_instance_p;
	void Remove_Panel();
};
}

namespace SaruNetLib {
class ControllerSetTask : public Ys::Task {
public:
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	void Start();
};
class ControllerSet {
public:
	char _4[0x24];
	short count;
	short _2a;
	virtual ~ControllerSet();
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
	char _4[0x30];
	static Game *_instance_p;
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
	void To_DelayError();
	virtual ~NetworkTask();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Start_Game();
	virtual void Quit();
	virtual void ErrorQuit();
	virtual int Activate_Game();
	virtual void Quit_Module();
};

namespace PetitGame {
class NetworkTask;
}
}

struct SaruNet_PetitGame_NetworkTask_Callback {
	void (*func)(SaruNet::PetitGame::NetworkTask *t, void *arg);
	void *arg;
	void Copy(const SaruNet_PetitGame_NetworkTask_Callback &c) { func = c.func; arg = c.arg; }
	void Reset() { func = 0; arg = 0; }
};

struct SaruNet_PetitGame_NetworkTask_Info {
	int _0[14];
};

struct SaruNet_PetitGame_NetworkTask_CallbackSet {
	SaruNet_PetitGame_NetworkTask_Callback start_game;
	SaruNet_PetitGame_NetworkTask_Callback quit;
	SaruNet_PetitGame_NetworkTask_Callback error;
};

typedef void (*SaruNet_PetitGame_NetworkTask_CallbackFunc)(SaruNet::PetitGame::NetworkTask *t, void *arg);

struct SaruNet_PetitGame_NetworkTask_CreateParam {
	int f0;
	SaruNet_PetitGame_NetworkTask_CallbackFunc start_game_func;
	void *start_game_arg;
	SaruNet_PetitGame_NetworkTask_CallbackFunc quit_func;
	void *quit_arg;
	SaruNet_PetitGame_NetworkTask_CallbackFunc error_func;
	void *error_arg;
	SaruNet_PetitGame_NetworkTask_Info info;
};

namespace SaruNet {
namespace PetitGame {

class ControllerSet : public SaruNetLib::ControllerSetTask, public SaruNetLib::ControllerSet {
};

class NetworkGame : public SaruNet::Game {
public:
	NetworkTask *task_p;
	void *player_p;
	void *remote_player_p;
	ControllerSet *controller_set_p;
	void *host_p;
	NetworkGame *Init(NetworkTask &t);
	static NetworkGame &Get_Instance() { return *(NetworkGame *)SaruNet::Game::_instance_p; }
};

class NetworkTask : public SaruNet::NetworkTask {
public:
	SaruNet_PetitGame_NetworkTask_CallbackSet callback;
	SaruNet_PetitGame_NetworkTask_Info info;
	virtual ~NetworkTask();
	NetworkTask *Init(int a, int b, int c, SaruNet_PetitGame_NetworkTask_CreateParam *p);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Start_Game();
	virtual void Quit();
	virtual void ErrorQuit();
};

}
}

namespace SaruNet {
namespace PetitGame {
NetworkTask::~NetworkTask()
{
	Ys::ScreenPanelDaemon *d = Ys::ScreenPanelDaemon::_instance_p;
	d->Remove_Panel();
	if (!quit && !error)
		Quit();
}
}
}

namespace SaruNet {
namespace PetitGame {

NetworkTask *NetworkTask::Init(int a, int b, int c, SaruNet_PetitGame_NetworkTask_CreateParam *p)
{
	SaruNet::NetworkTask::Init(b, a * 2 + 1, c);
	ResidentData::Get_Instance_p()->Get_WaiWaiData().error_petit_game = 0;
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
	sp.f8 = a;
	g->Set_StartupParam(sp);
	return this;
}

void NetworkTask::Start_Game()
{
	ResidentData::Get_Instance_p()->Get_WaiWaiData().error_petit_game = 0;
	NetworkGame::Get_Instance().controller_set_p->Start();
	if (callback.start_game.func)
		callback.start_game.func(this, callback.start_game.arg);
	SaruNet::NetworkTask::Start_Game();
}

void NetworkTask::Quit()
{
	if (callback.quit.func)
		callback.quit.func(this, callback.quit.arg);
	SaruNet::NetworkTask::Quit();
}

void NetworkTask::ErrorQuit()
{
	ResidentData::Get_Instance_p()->Get_WaiWaiData().error_petit_game = 1;
	if (callback.error.func)
		callback.error.func(this, callback.error.arg);
	SaruNet::NetworkTask::ErrorQuit();
}

void NetworkTask::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	SaruNet::NetworkTask::Receive_RunMessage(t, p, n);
	if (!delay_error) {
		if (NetworkGame::Get_Instance().controller_set_p->count <= 0) {
			To_DelayError();
			Net::Network::_instance_p->Inactivate();
		}
	}
}

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task", D_00108DC0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task", _ZTVN7SaruNet9PetitGame11NetworkTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task", D_00108DE0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task", _ZTIN7SaruNet9PetitGame11NetworkTaskE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_task", _ZTSN7SaruNet9PetitGame11NetworkTaskE); }
