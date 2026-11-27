/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: Get_Data/Quit loops match only with it (pointer IV + down-counter) */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
void *memset(void *p, int c, unsigned int n);
int sceKernelWaitSema(int id, int count, unsigned int *timeout);
int sceKernelSignalSema(int id, int count);
int sceNetAdhocPtpClose(int id, int flag);
extern const char D_001059B8[];
extern const char D_001059CC[];
}

inline void *operator new[](unsigned int size) { return _memAllocMBL(size, D_001059CC, 32); }
inline void operator delete[](void *p) { _memFree(p, D_001059CC, 37); }

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_001059CC, 23); }
	static void operator delete(void *p) { _memFree(p, D_001059CC, 25); }
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

struct NetAddress {
	unsigned char data[6];
	NetAddress() { memset(data, 0, sizeof(data)); }
	void Clear() { memset(data, 0, sizeof(data)); }
};

namespace DataTransfer {

class TransferThread : public MetaMagic::Thread {
public:
	int state;
	MetaMagic::Semaphore *semaphore;
	TransferThread(const char *name, int stack, int prio, unsigned int attr);
	virtual ~TransferThread();
	void Lock() const { semaphore->Wait(); }
	void Unlock() const { semaphore->Signal(); }
};

struct ClientRequest {
	int f0;
	int f4;
	char *buffer;
};

struct ClientGetParam {
	ClientRequest *request;
	short request_count;
	unsigned short port;
	int timeout;
	NetAddress address;
	ClientGetParam() { Reset(); }
	void Reset();
	ClientGetParam &Copy(const ClientGetParam &p);
	void Set(ClientRequest *r, int n, int pt, int t, const NetAddress &a) { request = r; request_count = n; port = pt; timeout = t; address = a; }
};

class Client : public TransferThread {
public:
	ClientGetParam param;
	int socket;
	bool busy : 1;
	bool allocated : 1;
	unsigned _f : 30;
	Client(int prio);
	virtual ~Client();
	virtual int Run(int argSize, const void *argp);
	bool Is_Busy() const;
	int Get_Data(const ClientGetParam &p);
	int Quit();
};

void ClientGetParam::Reset()
{
	request = 0;
	request_count = 0;
	port = 0x8AD;
	timeout = 0x5A40;
	address.Clear();
}

ClientGetParam &ClientGetParam::Copy(const ClientGetParam &p)
{
	Set(p.request, p.request_count, p.port, p.timeout, p.address);
	return *this;
}

}
}
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", _ZN3Net12DataTransfer6ClientC2Ei); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", _ZN3Net12DataTransfer6ClientC1Ei); }
namespace Net {
namespace DataTransfer {


Client::~Client()
{
	if (socket >= 0)
		sceNetAdhocPtpClose(socket, 0);
}

bool Client::Is_Busy() const
{
	Lock();
	bool b = busy;
	Unlock();
	return b;
}

int Client::Get_Data(const ClientGetParam &p)
{
	Lock();
	if (busy) {
		Unlock();
		return -1;
	}
	ClientGetParam &q = param.Copy(p);
	ClientRequest *r = q.request;
	for (int i = 0; i < q.request_count; i++)
		r[i].buffer = 0;
	socket = -1;
	busy = 1;
	allocated = 1;
	Unlock();
	return Start(0, 0);
}

}
}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", D_001059B8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", D_001059CC); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", _ZN3Net12DataTransfer6Client3RunEiPKv); }

namespace Net {
namespace DataTransfer {

int Client::Quit()
{
	if (allocated) {
		int n = param.request_count;
		ClientRequest *r = param.request;
		for (int i = 0; i < n; i++)
			delete[] r[i].buffer;
	}
	int s = socket;
	socket = -1;
	if (s >= 0)
		sceNetAdhocPtpClose(s, 0);
	Lock();
	busy = 0;
	allocated = 0;
	Unlock();
	Term();
	return 0;
}

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", _ZTVN3Net12DataTransfer6ClientE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", D_00105C90); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", _ZTIN3Net12DataTransfer6ClientE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_client", _ZTSN3Net12DataTransfer6ClientE); }
