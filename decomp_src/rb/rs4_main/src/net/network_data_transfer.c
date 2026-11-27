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
extern const char D_00105934[];
extern const char D_00105948[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00105934, 23); }
	static void operator delete(void *p) { _memFree(p, D_00105934, 25); }
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

TransferThread::TransferThread(const char *name, int stack, int prio, unsigned int attr)
	: MetaMagic::Thread(name, stack, prio, attr)
{
	semaphore = new MetaMagic::Semaphore(D_00105948, 1, 1, 0);
	Lock();
	state = 0;
	Unlock();
}

TransferThread::~TransferThread()
{
	delete semaphore;
}

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer", D_00105934); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer", D_00105948); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer", _ZTVN3Net12DataTransfer14TransferThreadE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer", D_00105970); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer", _ZTIN3Net12DataTransfer14TransferThreadE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer", _ZTSN3Net12DataTransfer14TransferThreadE); }
