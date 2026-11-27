/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
int sceKernelWaitSema(int id, int count, unsigned int *timeout);
int sceKernelSignalSema(int id, int count);
int sceNetAdhocPtpClose(int id, int flag);
extern const char D_00105CC8[];
extern const char D_00105CDC[];
extern const char D_00105E54[];
extern const char D_00105E70[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00105CDC, 23); }
	static void operator delete(void *p) { _memFree(p, D_00105CDC, 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, D_00105CDC, 32); }
	static void operator delete[](void *p) { _memFree(p, D_00105CDC, 37); }
};
}

namespace MetaMagic {
class Semaphore : public Ys::Object {
public:
	int id;
	Semaphore(const char *name, int init, int max, unsigned int attr);
	virtual ~Semaphore();
	void Wait() { sceKernelWaitSema(id, 1, 0); }
	void Signal() { sceKernelSignalSema(id, 1); }
};

class Thread : public Ys::Object {
	int id;
	int priority;
public:
	Thread(const char *name, int stack, int prio, unsigned int attr);
	virtual ~Thread();
	virtual int Run(int argSize, const void *argp);
	int Start(int argSize, const void *argp);
	void Term();
};
}

namespace Net {
namespace DataTransfer {

class TransferThread : public MetaMagic::Thread {
public:
	int state;
	MetaMagic::Semaphore *semaphore;
	TransferThread(const char *name, int stack, int prio, unsigned int attr);
	virtual ~TransferThread();
	void Lock() { semaphore->Wait(); }
	void Unlock() { semaphore->Signal(); }
};

struct ServerStartupParam {
	int f0;
	short f4;
	unsigned short port;
	short max_session;
	short session_count;
	int fC;
	void Reset();
	ServerStartupParam &Copy(const ServerStartupParam &p);
	int Get_F0() const { return f0; }
	int Get_F4() const { return f4; }
	int Get_Port() const { return port; }
	int Get_MaxSession() const { return max_session; }
	int Get_SessionCount() const { return session_count; }
	void Set(int a, int b, int c, int d, int e, int f) { f0 = a; f4 = b; port = c; max_session = d; session_count = e; fC = f; }
};

struct ServerStatus {
	int f0;
	short f4;
	short f6;
	short max_session;
	short session_count;
	unsigned short port;
	short running;
	int state;
	void Reset();
	void Set(int a, int b, int c, int d, int e, int g, int h, int i) { f0 = a; f4 = b; f6 = c; max_session = d; session_count = e; port = g; state = h; running = i; }
};

class Server;

class ServerSession : public MetaMagic::Thread {
public:
	Server *server;
	MetaMagic::Semaphore *semaphore;
	int socket;
	bool active;
	ServerSession(Server &s, int prio);
	virtual ~ServerSession();
	virtual int Run(int argSize, const void *argp);
	void Start(int socket);
	void Lock() { semaphore->Wait(); }
	void Unlock() { semaphore->Signal(); }
	bool Is_Active() { Lock(); bool r = active; Unlock(); return r; }
};

class Server : public TransferThread {
public:
	short f14;
	short f16;
	short session_priority;
	int socket;
	union {
		unsigned int flags;
		struct {
			unsigned running : 1;
		};
	};
	ServerStartupParam param;
	ServerSession **sessions;
	Server(int prio, int session_prio);
	virtual ~Server();
	virtual int Run(int argSize, const void *argp);
	ServerStatus &Get_Status(ServerStatus &st);
	void Start(const ServerStartupParam &p);
	void Stop();
	int Get_F14() const { return f14; }
	int Get_F16() const { return f16; }
	ServerSession *Find_FreeSession();
	void Remove_SessionList();
	int Get_ActiveSessionCount();
	void Close_Socket()
	{
		Lock();
		int s = socket;
		socket = -1;
		Unlock();
		if (s >= 0)
			sceNetAdhocPtpClose(s, 0);
	}
	void Clear_Running()
	{
		Lock();
		running = 0;
		Unlock();
	}
};

void ServerStartupParam::Reset()
{
	f0 = 0;
	f4 = 0;
	port = 0x8AD;
	max_session = 0;
	session_count = 1;
	fC = 0x5A40;
}

ServerStartupParam &ServerStartupParam::Copy(const ServerStartupParam &p)
{
	Set(p.f0, p.f4, p.port, p.max_session, p.session_count, p.fC);
	return *this;
}

void ServerStatus::Reset()
{
	f0 = 0;
	f4 = 0;
	f6 = 0;
	max_session = 0;
	session_count = 1;
	port = 0x8AD;
	running = 0;
	state = 0;
}

Server::Server(int prio, int session_prio)
	: TransferThread(D_00105CC8, 0x4000, prio, 0)
{
	param.Reset();
	session_priority = session_prio;
	socket = -1;
	sessions = 0;
	flags = 0;
}

Server::~Server()
{
	Remove_SessionList();
}

}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer6Server10Get_StatusERNS0_12ServerStatusE); }
namespace Net {
namespace DataTransfer {


void Server::Start(const ServerStartupParam &sp)
{
	ServerStartupParam &p = param;
	Lock();
	p.Copy(sp);
	f14 = 0;
	f16 = 0;
	flags = 0;
	socket = -1;
	state = 0;
	short n = p.session_count;
	short prio = session_priority;
	sessions = (ServerSession **)Ys::Object::operator new[](n * sizeof(ServerSession *));
	for (int i = 0; i < n; i++) {
		ServerSession *s = new ServerSession(*this, prio);
		sessions[i] = s;
	}
	Unlock();
	MetaMagic::Thread::Start(0, 0);
}

void Server::Stop()
{
	Close_Socket();
	Remove_SessionList();
	Clear_Running();
	Term();
}

ServerSession *Server::Find_FreeSession()
{
	ServerSession *r = 0;
	short n = param.session_count;
	for (int i = 0; i < n; i++) {
		ServerSession *s = sessions[i];
		if (!s->Is_Active()) {
			r = s;
			break;
		}
	}
	return r;
}

void Server::Remove_SessionList()
{
	if (sessions) {
		short n = param.session_count;
		for (int i = 0; i < n; i++)
			delete sessions[i];
		sessions = 0;
	}
}

int Server::Get_ActiveSessionCount()
{
	int count = 0;
	short n = param.session_count;
	Lock();
	for (int i = 0; i < n; i++)
		if (sessions[i]->Is_Active())
			count++;
	Unlock();
	return count;
}

}
}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", D_00105CC8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", D_00105CDC); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer6Server3RunEiPKv); }

namespace Net {
namespace DataTransfer {

}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer13ServerSessionC2ERNS0_6ServerEi); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer13ServerSessionC1ERNS0_6ServerEi); }
namespace Net {
namespace DataTransfer {


}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer13ServerSessionD2Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer13ServerSessionD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer13ServerSessionD0Ev); }
namespace Net {
namespace DataTransfer {


void ServerSession::Start(int sock)
{
	Lock();
	socket = sock;
	active = true;
	Unlock();
	MetaMagic::Thread::Start(0, 0);
}

}
}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", D_00105E54); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", D_00105E70); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZN3Net12DataTransfer13ServerSession3RunEiPKv); }


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZTVN3Net12DataTransfer13ServerSessionE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", D_00106050); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZTVN3Net12DataTransfer6ServerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", D_00106068); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZTIN3Net12DataTransfer6ServerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZTIN3Net12DataTransfer13ServerSessionE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZTSN3Net12DataTransfer13ServerSessionE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_server", _ZTSN3Net12DataTransfer6ServerE); }
