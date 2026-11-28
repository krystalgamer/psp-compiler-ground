/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#include "common.h"

extern "C" void *memset(void *, int, unsigned long);
extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 32); }
	static void operator delete[](void *p) { _memFree(p, "src/ys/ys_object.h", 37); }
};
}

namespace Net {
class LobbyMessageQueueCreateParam : public Ys::Object {
public:
	void *message[10];
	int _2c[4];
	virtual ~LobbyMessageQueueCreateParam();
};

class LobbyDoubleMessageQueue : public Ys::Object {
public:
	char _4[0x10];
	LobbyDoubleMessageQueue(LobbyMessageQueueCreateParam &p);
	virtual ~LobbyDoubleMessageQueue();
};

struct EtherAddress {
	unsigned char data[6];
};

class LobbyTerminalInfo : public Ys::Object {
public:
	LobbyTerminalInfo *next;
	short used;
	short capacity;
	int size;
	EtherAddress addr;
	char *data;
	LobbyTerminalInfo() { memset(&addr, 0, sizeof(addr)); Init(0); }
	virtual ~LobbyTerminalInfo();
	LobbyTerminalInfo &Init(int n);
};

class LobbyTerminalListBuilder : public Ys::Object {
public:
	virtual ~LobbyTerminalListBuilder();
	virtual LobbyTerminalInfo *Create_InfoTable(int n);
	virtual int Get_InfoOffsetSize() const;
};

template <class T> class T_LobbyTerminalListBuilder : public LobbyTerminalListBuilder {
public:
	virtual LobbyTerminalInfo *Create_InfoTable(int n) { return new T[n]; }
	virtual int Get_InfoOffsetSize() const { return sizeof(T); }
};

class LobbyTerminalList : public Ys::Object {
public:
	char _4[0xC];
	virtual ~LobbyTerminalList();
	LobbyTerminalList &Init(LobbyTerminalListBuilder &b);
};

class LobbyBuilder : public Ys::Object {
public:
	int _4[7];
	int event_handler_thread_priority;
	LobbyBuilder() { Reset(); }
	virtual ~LobbyBuilder();
	virtual void Reset();
	virtual LobbyDoubleMessageQueue *Create_DoubleMessageQueue();
	virtual LobbyTerminalList *Create_TerminalList();
};
}

namespace SaruNet {
class LobbyTerminalInfo : public Net::LobbyTerminalInfo {
public:
	LobbyTerminalInfo() { Init(0x84); }
};

class LobbyMessageQueueCreateParam : public Net::LobbyMessageQueueCreateParam {
public:
	LobbyMessageQueueCreateParam();
	virtual ~LobbyMessageQueueCreateParam();
};

class LobbyBuilder : public Net::LobbyBuilder {
public:
	LobbyBuilder();
	virtual void Reset();
	virtual Net::LobbyDoubleMessageQueue *Create_DoubleMessageQueue();
	virtual Net::LobbyTerminalList *Create_TerminalList();
};

class LobbyDoubleMessageQueue : public Net::LobbyDoubleMessageQueue {
public:
	LobbyDoubleMessageQueue(Net::LobbyMessageQueueCreateParam &p) : Net::LobbyDoubleMessageQueue(p) {}
};

class LobbyTerminalList : public Net::LobbyTerminalList {
};

}


namespace SaruNet {

LobbyBuilder::LobbyBuilder()
{
	event_handler_thread_priority = 0x15;
}

void LobbyBuilder::Reset()
{
	Net::LobbyBuilder::Reset();
	event_handler_thread_priority = 0x15;
}

Net::LobbyDoubleMessageQueue *LobbyBuilder::Create_DoubleMessageQueue()
{
	LobbyMessageQueueCreateParam param;
	return new LobbyDoubleMessageQueue(param);
}

Net::LobbyTerminalList *LobbyBuilder::Create_TerminalList()
{
	Net::T_LobbyTerminalListBuilder<LobbyTerminalInfo> builder;
	LobbyTerminalList *l = new LobbyTerminalList;
	l->Init(builder);
	return l;
}

}


