/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: Update_TerminalList() matches only with it (down-counter + pointer IV) */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct SceNetEtherAddr {
	unsigned char data[6];
};
struct SceNetAdhocctlGroupName {
	unsigned char data[8];
};

extern "C" {
void _memFree(void *p, const char *file, int line);
void *memset(void *p, int c, unsigned long n);
void *memcpy(void *d, const void *s, unsigned long n);
int snprintf(char *s, unsigned long n, const char *fmt, ...);
void consPrintf(const char *fmt, ...);
int sceNetGetLocalEtherAddr(SceNetEtherAddr *a);
int sceNetAdhocMatchingInit(int size);
int sceNetAdhocMatchingTerm(void);
int sceNetAdhocMatchingCreate(int mode, int max, unsigned short port, int buf, unsigned int hello, unsigned int ping, int init, unsigned int msg, void (*handler)(int, int, SceNetEtherAddr *, int, void *));
int sceNetAdhocMatchingStart(int id, int evthpri, int evthstack, int inthpri, int inthstack, int optlen, void *opt);
int sceNetAdhocMatchingStop(int id);
int sceNetAdhocMatchingDelete(int id);
int sceRtcGetCurrentTick(unsigned long long *tick);
extern const char D_00106360[];
extern const char D_001063B8[];
extern const char D_001063D4[];
extern const char D_001063F0[];
}

inline void operator delete[](void *p) { _memFree(p, D_00106360, 37); }

#define MATCHING_POOL_SIZE 0x8000
#define cassert(e) if (!(e)) consPrintf(D_001063B8, D_001063D4, __LINE__, __FUNCTION__, #e)

struct Task {
	char _0[0x24];
	signed char f24;
	char _25[7];
	int f2C;
};

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, D_00106360, 25); }
};
class Task;
class TaskState : public Object {
public:
	virtual ~TaskState();
	virtual void Kill(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Free(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Draw(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void KillChild(Task &t, ::Task *p, ::Task *c, unsigned int n);
	virtual void Unknown(Task &t, ::Task *p, int m, void *q, unsigned int n);
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
	Task *Init(void *p, unsigned int n, Task *parent);
};
}

namespace Net {
class Lobby;

class Network : public Ys::Object {
public:
	char _4[0x14];
	unsigned short port;
	static Network *_instance_p;
	virtual ~Network();
	int Connect_IBSS_UseConnect(SceNetAdhocctlGroupName &name);
};

class LobbyMessageQueue {
public:
	void Run(Lobby &l);
};

class LobbyDoubleMessageQueue : public Ys::Object {
public:
	LobbyMessageQueue *queue[2];
	char _c[4];
	signed char index;
	virtual ~LobbyDoubleMessageQueue();
	void Reset();
	void Swap();
};

struct LobbyTerminalInfo {
	char _0[0xA];
	short data_size;
	unsigned int time;
	SceNetEtherAddr address;
	char _16[2];
	void *data;
};

class LobbyTerminalList : public Ys::Object {
public:
	LobbyTerminalInfo *table;
	LobbyTerminalInfo *valid;
	signed char count;
	virtual ~LobbyTerminalList();
	void Reset();
	LobbyTerminalInfo *Get_ValidInfo_p(int n);
	LobbyTerminalInfo *Find_Info(const SceNetEtherAddr &mac);
	LobbyTerminalInfo *Alloc_Info();
	void Free_Info(LobbyTerminalInfo &info);
};

class LobbyBuilder : public Ys::Object {
public:
	int mode;
	int max_terminal;
	int buffer_size;
	int _10;
	int hello_interval;
	int ping_interval;
	int init_count;
	int event_handler_thread_priority;
	int event_handler_thread_stack_size;
	int message_receive_thread_priority;
	int message_receive_thread_stack_size;
	SceNetAdhocctlGroupName group_name;
	virtual ~LobbyBuilder();
	virtual void Reset();
	virtual LobbyDoubleMessageQueue *Create_DoubleMessageQueue();
	virtual LobbyTerminalList *Create_TerminalList();
	int Get_Mode() const { return mode; }
	int Get_MaxTerminal() const { return max_terminal; }
	int Get_BufferSize() const { return buffer_size; }
	int Get_Timeout() const { return _10; }
	int Get_HelloInterval() const { return hello_interval; }
	int Get_PingInterval() const { return ping_interval; }
	int Get_InitCount() const { return init_count; }
	int Get_EventHandlerThreadPriority() const { return event_handler_thread_priority; }
	int Get_EventHandlerThreadStackSize() const { return event_handler_thread_stack_size; }
	int Get_MessageReceiveThreadPriority() const { return message_receive_thread_priority; }
	int Get_MessageReceiveThreadStackSize() const { return message_receive_thread_stack_size; }
};

namespace LobbyState {
class Sleep : public Ys::TaskState {
public:
	virtual void Run(Lobby &l);
};
}

class Lobby : public Ys::Task {
public:
	LobbyBuilder *builder_p;
	union {
		unsigned int flags;
		struct {
			bool started : 1;
		};
	};
	int _14;
	int matching_id;
	unsigned int timeout;
	short hello_option_size;
	char *hello_option_p;
	LobbyDoubleMessageQueue *message_queue_p;
	LobbyTerminalList *terminal_list_p;
	int _30;
	LobbyState::Sleep sleep_state;
	LobbyState::Sleep error_state;
	static Lobby *_instance_p;
	Lobby *Init(LobbyBuilder &b);
	virtual ~Lobby();
	static SceNetAdhocctlGroupName &Create_GameIBssGroupName(SceNetAdhocctlGroupName &g);
	virtual int Startup();
	void Shutdown();
	LobbyTerminalInfo *Update_TerminalList(const SceNetEtherAddr &addr, int size, void *data);
	void Update_TerminalList();
	void Remove_TerminalInfo(const SceNetEtherAddr &addr);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	static void AdhocMatchingEventHandlerInterface(int id, int event, SceNetEtherAddr *addr, int size, void *data);
};

Lobby *Lobby::Init(LobbyBuilder &b)
{
	Ys::Task::Init(0, 0, 0);
	task_p->f24 = 0;
	_instance_p = this;
	task_p->f2C = 0;
	flags = 0;
	matching_id = -1;
	builder_p = &b;
	timeout = b.Get_Timeout();
	hello_option_size = 0;
	hello_option_p = 0;
	message_queue_p = b.Create_DoubleMessageQueue();
	terminal_list_p = b.Create_TerminalList();
	state_p = &sleep_state;
	return this;
}

Lobby::~Lobby()
{
	Shutdown();
	delete[] hello_option_p;
	delete terminal_list_p;
	delete message_queue_p;
	delete builder_p;
	_instance_p = 0;
}

}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby", D_00106360); }

namespace Net {

SceNetAdhocctlGroupName &Lobby::Create_GameIBssGroupName(SceNetAdhocctlGroupName &g)
{
	SceNetEtherAddr address;
#line 111
	cassert(sceNetGetLocalEtherAddr(&address) == 0);
	char name[9];
	memset(name, 0, sizeof(name));
	snprintf(name, sizeof(name), D_001063F0, address.data[2], address.data[3], address.data[4], address.data[5]);
	g = *(SceNetAdhocctlGroupName *)name;
	return g;
}

}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby", D_001063B8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby", D_001063D4); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby", D_001063F0); }

namespace Net {

}
namespace Net {
int Lobby::Startup()
{
	if (started)
		return 1;
	matching_id = -1;
	flags = 0;
	message_queue_p->Reset();
	terminal_list_p->Reset();
	LobbyBuilder &builder = *builder_p;
	Network &network = *Network::_instance_p;
	if (!network.Connect_IBSS_UseConnect(builder.group_name))
		return 0;
#line 153
	cassert(sceNetAdhocMatchingInit(MATCHING_POOL_SIZE) == 0);
	consPrintf("network lobby : matching initialized.\n");
	int context_id = sceNetAdhocMatchingCreate(builder.Get_Mode(), builder.Get_MaxTerminal(), network.port, builder.Get_BufferSize(), timeout, builder.Get_HelloInterval(), builder.Get_PingInterval(), builder.Get_InitCount(), AdhocMatchingEventHandlerInterface);
#line 165
	cassert(context_id >= 0);
	matching_id = context_id;
	consPrintf("network lobby : matching context created. - %d\n", context_id);
	int hello_option_size = this->hello_option_size;
	char *hello_option_p = this->hello_option_p;
	consPrintf("network lobby : priority : %d\n", builder.Get_EventHandlerThreadPriority());
#line 180
	cassert(sceNetAdhocMatchingStart( context_id, builder.Get_EventHandlerThreadPriority(), builder.Get_EventHandlerThreadStackSize(), builder.Get_MessageReceiveThreadPriority(), builder.Get_MessageReceiveThreadStackSize(), hello_option_size, hello_option_p) == 0);
	started = 1;
	state_p = &sleep_state;
	return 1;
}
}
namespace Net {


void Lobby::Shutdown()
{
	if (!started)
		return;
	int id = matching_id;
	if (id >= 0) {
		sceNetAdhocMatchingStop(id);
		sceNetAdhocMatchingDelete(id);
		matching_id = -1;
	}
#line 209
	cassert(sceNetAdhocMatchingTerm() == 0);
	started = 0;
}

}

unsigned int get__current_time()
{
	unsigned long long tick;
	sceRtcGetCurrentTick(&tick);
	return tick / 1000;
}

namespace Net {

}
namespace Net {
LobbyTerminalInfo *Lobby::Update_TerminalList(const SceNetEtherAddr &addr, int size, void *data)
{
	unsigned int now = get__current_time();
	LobbyTerminalList *list = terminal_list_p;
	LobbyTerminalInfo *info = list->Find_Info(addr);
	if (info) {
		info->time = now;
	} else if (16 - list->count > 0) {
		LobbyTerminalInfo *n = list->Alloc_Info();
		n->time = now;
		n->address = addr;
		if (n->data)
			memcpy(n->data, data, n->data_size);
		info = n;
	}
	return info;
}
}
namespace Net {


void Lobby::Update_TerminalList()
{
	unsigned int now = get__current_time();
	int limit = (int)timeout / 500;
	LobbyTerminalList *list = terminal_list_p;
	int n = list->count;
	LobbyTerminalInfo *infos[16];
	for (int i = 0; i < n; i++)
		infos[i] = list->Get_ValidInfo_p(i);
	for (int i = 0; i < n; i++) {
		if (limit < (int)(now - infos[i]->time))
			list->Free_Info(*infos[i]);
	}
}

void Lobby::Remove_TerminalInfo(const SceNetEtherAddr &addr)
{
	LobbyTerminalList *list = terminal_list_p;
	LobbyTerminalInfo *info = list->Find_Info(addr);
	if (info)
		list->Free_Info(*info);
}

void Lobby::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	LobbyDoubleMessageQueue *q = message_queue_p;
	q->Swap();
	q->queue[q->index]->Run(*this);
	((LobbyState::Sleep *)state_p)->Run(*this);
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby", _ZTVN3Net5LobbyE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby", D_001065F8); }
