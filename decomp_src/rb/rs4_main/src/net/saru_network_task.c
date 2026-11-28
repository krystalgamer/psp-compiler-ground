/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#include "common.h"

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
void *memset(void *, int, unsigned long);
void consPrintf(const char *fmt, ...);
}

struct Task {
	char _0[0x24];
	signed char f24;
	char _25[7];
	int f2C;
};

namespace Ys {
class Task;

class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

class TaskState : public Object {
public:
	virtual ~TaskState();
	virtual void Kill(class Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Free(class Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Run(class Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Draw(class Task &t, ::Task *p, void *q, unsigned int n);
	virtual void KillChild(class Task &t, ::Task *p, ::Task *c, unsigned int n);
	virtual int Unknown(class Task &t, ::Task *p, int m, void *q, unsigned int n);
};

class Task : public Object {
public:
	::Task *task_p;
	TaskState *state_p;
	static TaskState *_default_state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
	Task *Init(void *p, unsigned int n, Task *parent);
};

class Anim2D {
public:
	char _4[0x4C];
	Anim2D();
	virtual ~Anim2D();
} __attribute__((aligned(16)));

class ScreenPanel : public Task {
public:
	Anim2D anim;
	char _60[8];
	ScreenPanel() {}
	virtual ~ScreenPanel();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Open();
	virtual void Close();
	virtual void Run_Common();
};

class Cancel_ScreenPanel : public ScreenPanel {
public:
	short wait;
	unsigned short no_close;
	virtual void Open();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

class ScreenPanelDaemon {
public:
	static ScreenPanelDaemon *_instance_p;
	void Remove_Panel();
};
}

namespace Net {
struct EtherAddress {
	unsigned char data[6];
};

class Game {
public:
	char _4[0x28];
	short f2C;
	short f2E;
	bool f30_0 : 1;
	bool started : 1;
	unsigned int _f30 : 30;
	virtual ~Game();
};

class Lobby;

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
	unsigned int _c9 : 23;
	int error;
	char _14[0xC];
	EtherAddress addr;
	static Network *_instance_p;
	Network() { memset(&addr, 0, sizeof(addr)); }
	virtual ~Network();
	virtual void Update();
	virtual int Activate(Game &g);
	virtual int Activate(Lobby &l);
	virtual void Inactivate();
};

class ObjectDaemon {
public:
	int _0;
	short count;
	static ObjectDaemon *_instance_p;
};
}

namespace SaruNet {
class Network : public Net::Network {
public:
	Network *Init(int a);
};

namespace NetworkTaskState {
class StartupWait : public Ys::TaskState {
public:
	virtual void Run(Ys::Task &t, ::Task *p, void *q, unsigned int n);
};
class SetupWait : public Ys::TaskState {
public:
	virtual void Run(Ys::Task &t, ::Task *p, void *q, unsigned int n);
};
class QuitWait : public Ys::TaskState {
public:
	virtual void Run(Ys::Task &t, ::Task *p, void *q, unsigned int n);
};
class Delay_Error : public Ys::TaskState {
public:
	virtual void Run(Ys::Task &t, ::Task *p, void *q, unsigned int n);
};
}

class NetworkTask : public Ys::Task {
public:
	Net::Game *game_p;
	NetworkTaskState::StartupWait *startup_state_p;
	NetworkTaskState::SetupWait *setup_state_p;
	NetworkTaskState::QuitWait *quit_state_p;
	NetworkTaskState::Delay_Error *delay_error_state_p;
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
	static NetworkTask *_instance_p;
	void To_DelayError();
	NetworkTask *Init(int a, int b, int pri);
	virtual ~NetworkTask();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Start_Game();
	virtual void Quit();
	virtual void ErrorQuit();
	virtual int Activate_Game();
	virtual void Quit_Module();
	virtual void Run_StartupWait(::Task *t, void *p, unsigned int n);
	virtual void Run_SetupWait(::Task *t, void *p, unsigned int n);
	virtual void Run_QuitWait(::Task *t, void *p, unsigned int n);
	virtual void Run_DelayError(::Task *t, void *p, unsigned int n);
	bool Check_Error();
};

namespace ScreenPanel {
class Panel : public Ys::ScreenPanel {
public:
};
class CancelPanel : public Ys::Cancel_ScreenPanel {
public:
};
class Connecting : public Panel {
public:
	Panel *Init(Ys::Task *parent);
};
class Error : public CancelPanel {
public:
	CancelPanel *Init(Ys::Task *parent);
};
class Error_WLanOff : public CancelPanel {
public:
	CancelPanel *Init(Ys::Task *parent);
};
}


void NetworkTask::To_DelayError()
{
	if (Net::Network::_instance_p->wlan_off)
		(new ScreenPanel::Error_WLanOff)->Init(0)->Open();
	else
		(new ScreenPanel::Error)->Init(0)->Open();
	delay_error = 1;
	delay_wait = 6;
	state_p = delay_error_state_p;
}

NetworkTask *NetworkTask::Init(int a, int b, int pri)
{
	Task::Init(0, 0, 0);
	task_p->f24 = pri;
	_instance_p = this;
	task_p->f2C = 0x40;
	min_object = b;
	flags = 0;
	startup_state_p = new NetworkTaskState::StartupWait;
	setup_state_p = new NetworkTaskState::SetupWait;
	quit_state_p = new NetworkTaskState::QuitWait;
	delay_error_state_p = new NetworkTaskState::Delay_Error;
	(new SaruNet::Network)->Init(a);
	startup_wait = 20;
	delay_error = 0;
	state_p = startup_state_p;
	game_p = 0;
	(new ScreenPanel::Connecting)->Init(0)->Open();
	return this;
}

NetworkTask::~NetworkTask()
{
	Net::Network *n = Net::Network::_instance_p;
	n->Inactivate();
	delete game_p;
	game_p = 0;
	delete delay_error_state_p;
	delete quit_state_p;
	delete setup_state_p;
	delete startup_state_p;
	delete n;
	_instance_p = 0;
}

int NetworkTask::Activate_Game()
{
	int r = 0;
	if (game_p)
		r = Net::Network::_instance_p->Activate(*game_p);
	return r;
}

void NetworkTask::Start_Game()
{
	if (game_p)
		game_p->started = 1;
}

void NetworkTask::Quit()
{
	quit = 1;
}

void NetworkTask::ErrorQuit()
{
	quit = 1;
	error = 1;
	state_p = quit_state_p;
}

void NetworkTask::Quit_Module()
{
	quit = 1;
	error = 0;
	state_p = quit_state_p;
}

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_task", _ZN7SaruNet11NetworkTask11Check_ErrorEv); }

namespace SaruNet {

void NetworkTask::Run_StartupWait(::Task *t, void *p, unsigned int n)
{
	int w = startup_wait - 1;
	if (w > 0) {
		startup_wait = w;
		return;
	}
	delay_error = 0;
	if (!Activate_Game()) {
		To_DelayError();
		return;
	}
	state_p = setup_state_p;
}

void NetworkTask::Run_SetupWait(::Task *t, void *p, unsigned int n)
{
	Net::Network::_instance_p->Update();
	if (Check_Error()) {
		To_DelayError();
		return;
	}
	if (Net::ObjectDaemon::_instance_p->count < min_object)
		return;
	Ys::ScreenPanelDaemon::_instance_p->Remove_Panel();
	Start_Game();
	state_p = _default_state_p;
}

void NetworkTask::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	Net::Network::_instance_p->Update();
	if (quit) {
		Quit_Module();
		return;
	}
	if (Check_Error()) {
		To_DelayError();
	} else if (Net::ObjectDaemon::_instance_p->count < min_object) {
		consPrintf("saru network task : object removed.\n");
		To_DelayError();
	}
}

void NetworkTask::Run_QuitWait(::Task *t, void *p, unsigned int n)
{
	Net::Network::_instance_p->Update();
}

void NetworkTask::Run_DelayError(::Task *t, void *p, unsigned int n)
{
	int w = delay_wait - 1;
	if (w > 0) {
		delay_wait = w;
		return;
	}
	ErrorQuit();
}

void NetworkTaskState::StartupWait::Run(Ys::Task &t, ::Task *p, void *q, unsigned int n)
{
	((NetworkTask &)t).Run_StartupWait(p, q, n);
}

void NetworkTaskState::SetupWait::Run(Ys::Task &t, ::Task *p, void *q, unsigned int n)
{
	((NetworkTask &)t).Run_SetupWait(p, q, n);
}

void NetworkTaskState::QuitWait::Run(Ys::Task &t, ::Task *p, void *q, unsigned int n)
{
	((NetworkTask &)t).Run_QuitWait(p, q, n);
}

void NetworkTaskState::Delay_Error::Run(Ys::Task &t, ::Task *p, void *q, unsigned int n)
{
	((NetworkTask &)t).Run_DelayError(p, q, n);
}

}


