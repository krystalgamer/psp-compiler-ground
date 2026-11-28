/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
/* #pragma interface: the vtables live in the module's asm .rodata (network_lobby_event/_terminal_list) */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" void *memset(void *, int, unsigned int);
/* "src/ys/ys_object.h": this object has no .rodata of its own */
extern "C" const char D_00106664[];

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00106664, 23); }
	static void operator delete(void *p) { _memFree(p, D_00106664, 25); }
};
}

namespace Net {
class LobbyMessageQueueCreateParam {
	char _p[0x40];
public:
	LobbyMessageQueueCreateParam();
	~LobbyMessageQueueCreateParam();
};

class LobbyDoubleMessageQueue : public Ys::Object {
	char _p[0x14];
public:
	LobbyDoubleMessageQueue(LobbyMessageQueueCreateParam &p);
};

class LobbyTerminalListBuilder {
public:
	LobbyTerminalListBuilder() {}
	virtual ~LobbyTerminalListBuilder();
};

class LobbyTerminalList : public Ys::Object {
	int _p[3];
public:
	LobbyTerminalList() {}
	virtual ~LobbyTerminalList();
	LobbyTerminalList *Init(LobbyTerminalListBuilder &b);
};

struct Bytes8 {
	char c[8];
	void Reset() { memset(c, 0, sizeof(c)); }
};

class LobbyBuilder : public Ys::Object {
public:
	int f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
	Bytes8 f30;
	virtual ~LobbyBuilder();
	void Reset();
	virtual LobbyDoubleMessageQueue *Create_DoubleMessageQueue();
	virtual LobbyTerminalList *Create_TerminalList();
};

LobbyBuilder::~LobbyBuilder()
{
}

void LobbyBuilder::Reset()
{
	f4 = 3;
	f8 = 8;
	fC = 0x800;
	f10 = 5000000;
	f14 = 10000000;
	f18 = 3;
	f1C = 500000;
	f20 = 16;
	f24 = 0x2000;
	f28 = 16;
	f2C = 0x2000;
	f30.Reset();
}

LobbyDoubleMessageQueue *LobbyBuilder::Create_DoubleMessageQueue()
{
	LobbyMessageQueueCreateParam p;
	return new LobbyDoubleMessageQueue(p);
}

LobbyTerminalList *LobbyBuilder::Create_TerminalList()
{
	LobbyTerminalListBuilder b;
	return (new LobbyTerminalList)->Init(b);
}
}
