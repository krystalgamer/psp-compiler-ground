/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct NetTypeBroadcastSchedule {
	int f0;
	int f4;
	float f8;
	unsigned char fC;
};

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
extern const char D_00107508[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00107508, 23); }
	static void operator delete(void *p) { _memFree(p, D_00107508, 25); }
};
}

namespace Net {
class ObjectClass {
public:
	virtual int Get_ClassID() const;
	virtual int Set_ClassID(int id);
	virtual int Get_Size() const;
	virtual const char *Get_Name() const;
	virtual void *Get_RemoteCreateCallback_p() const;
	virtual void Register_Field();
};

class Object : public Ys::Object {
public:
	int class_id;
	int object_index;
	int _c;
	bool owner;
	void *net_object_p;
	Object *Init(ObjectClass &cls, int object_index);
	virtual ~Object();
	virtual void Callback_Update(int a, int idx, int c);
	virtual void Callback_Remove(int a, int idx);
};
}

namespace SaruNet {
class ObjectClass : public Net::ObjectClass {
public:
	virtual void Register_Field(NetTypeBroadcastSchedule &s);
};

class Object : public Net::Object {
public:
	Object *Init(Net::ObjectClass &cls, bool owner, void *p, const unsigned char *name);
};

namespace CardBattle {
class NetworkPlayer;
}

class Game {
public:
	char _0[0x34];
	char *player_data;
	char _38[8];
	CardBattle::NetworkPlayer *remote_player;
	static Game *_instance_p;
};

namespace CardBattle {
class _Class_Player : public SaruNet::ObjectClass {
public:
	static int _class_id;
	virtual int Get_ClassID() const;
	virtual int Set_ClassID(int id);
};

class Class_Player : public _Class_Player {
public:
	virtual int Get_Size() const;
	virtual const char *Get_Name() const;
	virtual void *Get_RemoteCreateCallback_p() const;
	virtual void Register_Field(NetTypeBroadcastSchedule &s);
};

class NetworkPlayer : public SaruNet::Object {
public:
	virtual ~NetworkPlayer();
	NetworkPlayer *Init();
	NetworkPlayer *Init(int cls, int idx);
	static void gCallback_RemoteCreate(int cls, int idx);
};

int _Class_Player::Get_ClassID() const
{
	return _class_id;
}

int _Class_Player::Set_ClassID(int id)
{
	return _class_id = id;
}

int Class_Player::Get_Size() const
{
	return 0x38;
}

const char *Class_Player::Get_Name() const
{
	return "player";
}

void *Class_Player::Get_RemoteCreateCallback_p() const
{
	return (void *)NetworkPlayer::gCallback_RemoteCreate;
}

}
}

extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", D_00107508); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZN7SaruNet10CardBattle12Class_Player14Register_FieldER24NetTypeBroadcastSchedule); }

namespace SaruNet {
namespace CardBattle {

NetworkPlayer::~NetworkPlayer()
{
}

NetworkPlayer *NetworkPlayer::Init()
{
	Class_Player cls;
	SaruNet::Object::Init(cls, true, Game::_instance_p->player_data + 0x40, (const unsigned char *)"player");
	return this;
}

NetworkPlayer *NetworkPlayer::Init(int cls_id, int idx)
{
	Class_Player cls;
	Net::Object::Init(cls, idx);
	return this;
}

void NetworkPlayer::gCallback_RemoteCreate(int cls, int idx)
{
	Game *g = Game::_instance_p;
	g->remote_player = (new NetworkPlayer)->Init(cls, idx);
}

}
}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZN7SaruNet6ObjectD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZN7SaruNet6ObjectD1Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTVN7SaruNet10CardBattle13NetworkPlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", D_00107528); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTVN7SaruNet10CardBattle12Class_PlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", D_00107540); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTVN7SaruNet10CardBattle13_Class_PlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTVN7SaruNet6ObjectE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", D_00107590); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTIN7SaruNet6ObjectE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTIN7SaruNet10CardBattle13_Class_PlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTIN7SaruNet10CardBattle12Class_PlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTIN7SaruNet10CardBattle13NetworkPlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTSN7SaruNet10CardBattle13NetworkPlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTSN7SaruNet10CardBattle12Class_PlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTSN7SaruNet10CardBattle13_Class_PlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_card_battle_network_player", _ZTSN7SaruNet6ObjectE); }
