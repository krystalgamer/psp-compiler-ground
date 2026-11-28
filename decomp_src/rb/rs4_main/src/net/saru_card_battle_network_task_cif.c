/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
/* #pragma interface: NetworkTask's vtable stays in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" void *memset(void *, int, unsigned int);

struct SaruNet_CardBattle_NetworkTask_CreateParam {
	short port;
	int f4, f8, fC, f10, f14, f18;
	char f1C[0x38];
};

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { if (p) _memFree(p, "src/ys/ys_object.h", 25); }
};
}

namespace Net {
class Network {
public:
	static Network *_instance_p;
	virtual ~Network();
	virtual void Update();
};
}

namespace SaruNet {
namespace CardBattle {
struct PlayerEntry {
	char _p[0x1C];
	void *context;
};
struct Player {
	char _p[0x14];
	PlayerEntry *entry;
};
class NetworkGame {
public:
	Player *Get_Player_p(int i) const;
};
class NetworkTask : public Ys::Object {
public:
	int _t[2];
	NetworkGame *game;
	char _p[0x14];
	unsigned int f24_0 : 1;
	unsigned int error_at_quit : 1;
	char _q[0x50];
	NetworkTask() {}
	virtual ~NetworkTask();
	NetworkTask *Init(int port, SaruNet_CardBattle_NetworkTask_CreateParam *p);
};
}
}

using SaruNet::CardBattle::NetworkTask;

extern "C" {

SaruNet_CardBattle_NetworkTask_CreateParam *SaruNet_CardBattle_NetworkTask_CreateParam__Reset(SaruNet_CardBattle_NetworkTask_CreateParam *p)
{
	p->port = 0;
	p->f14 = 0;
	p->fC = 0;
	p->f4 = 0;
	p->f18 = 0;
	p->f10 = 0;
	p->f8 = 0;
	memset(p->f1C, 0, sizeof(p->f1C));
	return p;
}

NetworkTask *SaruNet_CardBattle_NetworkTask__Create(SaruNet_CardBattle_NetworkTask_CreateParam *p)
{
	int port = p->port;
	return (new NetworkTask)->Init(port, p);
}

void SaruNet_CardBattle_NetworkTask__Destroy(NetworkTask *t)
{
	delete t;
}

bool SaruNet_CardBattle_NetworkTask__Startup_Game(NetworkTask *t)
{
	return true;
}

void SaruNet_CardBattle_NetworkTask__Terminate_Game(NetworkTask *t)
{
}

int SaruNet_CardBattle_NetworkTask__Is_Error_AtQuit(NetworkTask *t)
{
	return t->error_at_quit;
}

void *SaruNet_CardBattle_NetworkTask__Get_PlayerContext_p(NetworkTask *t, int i)
{
	return t->game->Get_Player_p(i)->entry->context;
}

void SaruNet_CardBattle_NetworkTask__Update(NetworkTask *t)
{
	Net::Network::_instance_p->Update();
}

}
