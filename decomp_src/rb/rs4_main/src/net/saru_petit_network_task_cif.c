/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
/* #pragma interface: NetworkTask's vtable stays in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" void *memset(void *, int, unsigned int);

struct SaruNet_PetitGame_NetworkTask_CreateParam {
	short port;
	short port2;
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
class NetworkTask {
public:
	static NetworkTask *_instance_p;
};
namespace PetitGame {
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
	Player *Get_CardBattlePlayer_p(int i) const;
	void Reset_LocalController();
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
	NetworkTask *Init(int mode, int port, int port2, SaruNet_PetitGame_NetworkTask_CreateParam *p);
};
}
}

using SaruNet::PetitGame::NetworkTask;

extern "C" {

SaruNet_PetitGame_NetworkTask_CreateParam *SaruNet_PetitGame_NetworkTask_CreateParam__Reset(SaruNet_PetitGame_NetworkTask_CreateParam *p)
{
	p->port = 0x2227;
	p->port2 = 0;
	p->f14 = 0;
	p->fC = 0;
	p->f4 = 0;
	p->f18 = 0;
	p->f10 = 0;
	p->f8 = 0;
	memset(p->f1C, 0, sizeof(p->f1C));
	return p;
}

NetworkTask *SaruNet_PetitGame_NetworkTask__Create(SaruNet_PetitGame_NetworkTask_CreateParam *p)
{
	int port = p->port;
	int port2 = p->port2;
	return (new NetworkTask)->Init(2, port, port2, p);
}

void SaruNet_PetitGame_NetworkTask__Destroy(NetworkTask *t)
{
	delete t;
}

bool SaruNet_PetitGame_NetworkTask__Startup_Game(NetworkTask *t)
{
	return true;
}

void SaruNet_PetitGame_NetworkTask__Terminate_Game(NetworkTask *t)
{
}

SaruNet::NetworkTask *SaruNet_PetitGame_NetworkTask__Get_Instance_p(void)
{
	return SaruNet::NetworkTask::_instance_p;
}

int SaruNet_PetitGame_NetworkTask__Is_Error_AtQuit(NetworkTask *t)
{
	return t->error_at_quit;
}

void SaruNet_PetitGame_NetworkTask__Reset_LocalController(NetworkTask *t)
{
	t->game->Reset_LocalController();
}

void *SaruNet_PetitGame_NetworkTask__Get_CardBattlePlayerContext_p(NetworkTask *t, int i)
{
	return t->game->Get_CardBattlePlayer_p(i)->entry->context;
}

void SaruNet_PetitGame_NetworkTask__Update(NetworkTask *t)
{
	Net::Network::_instance_p->Update();
}

}
