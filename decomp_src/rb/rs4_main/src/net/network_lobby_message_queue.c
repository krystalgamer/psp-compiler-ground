/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: the destructor/constructor loops walk pointers with a count-down register (-fno-strength-reduce indexes them) */
/* #pragma interface: the vtables and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" void consPrintf(const char *fmt, ...);
extern "C" int sceKernelWaitSema(int id, int n, unsigned int *timeout);
extern "C" int sceKernelSignalSema(int id, int n);

extern const char D_00106B44[], D_00106B6C[], D_00106B80[], D_00106B9C[], D_00106BC4[];
extern const char QueueC1_FUNCTION[] __asm__("_ZZN3Net17LobbyMessageQueueC1ERKNS_28LobbyMessageQueueCreateParamEE12__FUNCTION__");
#define cassert(e) if (!(e)) consPrintf(D_00106B80, D_00106B9C, __LINE__, QueueC1_FUNCTION, D_00106B6C)

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00106B44, 23); }
	static void operator delete(void *p) { _memFree(p, D_00106B44, 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, D_00106B44, 32); }
	static void operator delete[](void *p) { if (p) _memFree(p, D_00106B44, 37); }
};
}

namespace MetaMagic {
class Semaphore : public Ys::Object {
public:
	int id;
	Semaphore(const char *name, int init, int max, unsigned int attr);
	virtual ~Semaphore();
};
}

namespace Net {
class Lobby;
struct EtherAddress {
	unsigned char data[6];
};

class LobbyMessage : public Ys::Object {
public:
	int id;
	short capacity;
	short size;
	char *data;
	EtherAddress addr;

	LobbyMessage(int n = 0);
	virtual ~LobbyMessage();
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
	bool Set_OptionData(int n, const void *p);
	LobbyMessage &Copy(const LobbyMessage &m);
};

class LobbyMessageNode : public Ys::Object {
public:
	bool used;
	LobbyMessageNode *next;
	LobbyMessage *message;

	LobbyMessageNode();
	virtual ~LobbyMessageNode();
};

LobbyMessageNode::LobbyMessageNode()
{
	message = 0;
	next = 0;
	used = false;
}

LobbyMessageNode::~LobbyMessageNode()
{
}

class LobbyMessageTable : public Ys::Object {
public:
	int num;
	LobbyMessage *messages;
	LobbyMessageNode *nodes;

	LobbyMessageTable(int n, const LobbyMessage &m);
	virtual ~LobbyMessageTable();
	LobbyMessageNode *Alloc_MessageNode();
	void Free_AllMessageNode();
};

LobbyMessageTable::LobbyMessageTable(int n, const LobbyMessage &m)
{
	num = n;
	messages = m.Create_Array(n);
	LobbyMessage *msgs = messages;
	for (int i = 0; i < n; i++)
		msgs[i].Copy(m);
	nodes = new LobbyMessageNode[n];
	LobbyMessageNode *nd = nodes;
	for (int i = 0; i < n; i++)
		nd[i].message = &msgs[i];
}

LobbyMessageTable::~LobbyMessageTable()
{
	LobbyMessageNode *nd = nodes;
	delete[] nd;
	LobbyMessage *msgs = messages;
	delete[] msgs;
}

LobbyMessageNode *LobbyMessageTable::Alloc_MessageNode()
{
	LobbyMessageNode *r = 0;
	int i;

	for (i = 0; i < num; i++) {
		LobbyMessageNode *n = &nodes[i];
		if (!n->used) {
			n->used = true;
			n->next = 0;
			r = n;
			break;
		}
	}
	return r;
}

void LobbyMessageTable::Free_AllMessageNode()
{
	int i;

	for (i = 0; i < num; i++) {
		LobbyMessageNode *n = &nodes[i];
		n->next = 0;
		n->used = false;
	}
}

class LobbyMessageQueueCreateParam : public Ys::Object {
public:
	LobbyMessage *messages[10];
	short num0;
	short num2;
	short num9;
	short num7;
	short num8;

	LobbyMessageQueueCreateParam();
	virtual ~LobbyMessageQueueCreateParam();
};

LobbyMessageQueueCreateParam::LobbyMessageQueueCreateParam()
{
	int i;

	for (i = 0; i < 10; i++)
		messages[i] = 0;
	num0 = 32;
	num2 = 32;
	num9 = 32;
	num8 = 4;
}

LobbyMessageQueueCreateParam::~LobbyMessageQueueCreateParam()
{
}

class LobbyMessageQueue : public Ys::Object {
public:
	LobbyMessageTable *tables[10];
	LobbyMessageNode *head;
	LobbyMessageNode *tail;

	LobbyMessageQueue(const LobbyMessageQueueCreateParam &p);
	virtual ~LobbyMessageQueue();
	void Reset();
	LobbyMessageNode *Add_Message(int type, int id, const EtherAddress &a, int n, const void *p);
	void Run(Lobby &l);
};

LobbyMessageQueue::LobbyMessageQueue(const LobbyMessageQueueCreateParam &p)
{
	int num[10];

	for (int i = 0; i < 10; i++)
		num[i] = 1;
	num[0] = p.num0;
	num[2] = p.num2;
	num[9] = p.num9;
	num[7] = p.num7;
	num[8] = p.num8;
	for (int i = 0; i < 10; i++) {
		LobbyMessage *message_p = p.messages[i];
#line 222
		cassert(message_p != NULL);
		LobbyMessageTable *t = new LobbyMessageTable(num[i], *message_p);
		tables[i] = t;
	}
	head = 0;
	tail = 0;
}

LobbyMessageQueue::~LobbyMessageQueue()
{
	int i;

	for (i = 0; i < 10; i++)
		delete tables[i];
}

void LobbyMessageQueue::Reset()
{
	int i;

	for (i = 0; i < 10; i++)
		tables[i]->Free_AllMessageNode();
	head = 0;
	tail = 0;
}

LobbyMessageNode *LobbyMessageQueue::Add_Message(int type, int id, const EtherAddress &a, int n, const void *p)
{
	LobbyMessageNode *node = tables[type]->Alloc_MessageNode();
	if (node == 0)
		return 0;
	LobbyMessage *m = node->message;
	if (!m->Set_OptionData(n, p)) {
		node->used = false;
		return 0;
	}
	m->id = id;
	m->addr = a;
	if (head == 0)
		head = node;
	else
		tail->next = node;
	tail = node;
	return node;
}

void LobbyMessageQueue::Run(Lobby &l)
{
	LobbyMessageNode *n;

	for (n = head; n; n = n->next)
		n->message->Run(l);
	Reset();
}

class LobbyDoubleMessageQueue : public Ys::Object {
public:
	LobbyMessageQueue *queues[2];
	MetaMagic::Semaphore *sema;
	signed char current;

	LobbyDoubleMessageQueue(LobbyMessageQueueCreateParam &p);
	virtual ~LobbyDoubleMessageQueue();
	void Reset();
	void Lock();
	void Unlock();
	void Swap();
	LobbyMessageQueue *Get_BackQueue() { return queues[1 - current]; }
};

LobbyDoubleMessageQueue::LobbyDoubleMessageQueue(LobbyMessageQueueCreateParam &p)
{
	int i;

	for (i = 0; i < 2; i++)
		queues[i] = new LobbyMessageQueue(p);
	sema = new MetaMagic::Semaphore(D_00106BC4, 1, 1, 0);
	current = 0;
}

LobbyDoubleMessageQueue::~LobbyDoubleMessageQueue()
{
	int i;

	delete sema;
	for (i = 0; i < 2; i++)
		delete queues[i];
}

void LobbyDoubleMessageQueue::Reset()
{
	int i;

	Lock();
	for (i = 0; i < 2; i++)
		queues[i]->Reset();
	current = 0;
	Unlock();
}

void LobbyDoubleMessageQueue::Lock()
{
	sceKernelWaitSema(sema->id, 1, 0);
}

void LobbyDoubleMessageQueue::Unlock()
{
	sceKernelSignalSema(sema->id, 1);
}

void LobbyDoubleMessageQueue::Swap()
{
	Lock();
	int next = 1 - current;
	LobbyMessageQueue *q = queues[1 - (signed char)next];
	current = next;
	q->Reset();
	Unlock();
}
}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106B44);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZZN3Net17LobbyMessageQueueC1ERKNS_28LobbyMessageQueueCreateParamEE12__FUNCTION__);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106B6C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106B80);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106B9C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106BC4);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTVN3Net23LobbyDoubleMessageQueueE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106BE8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTVN3Net17LobbyMessageQueueE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106BF8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTVN3Net28LobbyMessageQueueCreateParamE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106C08);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTVN3Net17LobbyMessageTableE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106C18);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTVN3Net16LobbyMessageNodeE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", D_00106C28);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTIN3Net16LobbyMessageNodeE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTIN3Net17LobbyMessageTableE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTIN3Net17LobbyMessageQueueE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTIN3Net28LobbyMessageQueueCreateParamE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTIN3Net23LobbyDoubleMessageQueueE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTSN3Net23LobbyDoubleMessageQueueE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTSN3Net28LobbyMessageQueueCreateParamE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTSN3Net17LobbyMessageQueueE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTSN3Net17LobbyMessageTableE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message_queue", _ZTSN3Net16LobbyMessageNodeE);
}
