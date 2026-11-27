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
extern const char D_00108960[];
extern const char D_00108974[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
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

namespace PetitGame {
class CardBattlePlayer;
}

class Game {
public:
	char _0[0x34];
	char *player_data;
	char _38[4];
	PetitGame::CardBattlePlayer *remote_player;
	static Game *_instance_p;
};

namespace PetitGame {
class _Class_CardBattlePlayer : public SaruNet::ObjectClass {
public:
	static int _class_id;
	virtual int Get_ClassID() const;
	virtual int Set_ClassID(int id);
};

class Class_CardBattlePlayer : public _Class_CardBattlePlayer {
public:
	virtual int Get_Size() const;
	virtual const char *Get_Name() const;
	virtual void *Get_RemoteCreateCallback_p() const;
	virtual void Register_Field(NetTypeBroadcastSchedule &s);
};

class CardBattlePlayer : public SaruNet::Object {
public:
	virtual ~CardBattlePlayer();
	CardBattlePlayer *Init();
	CardBattlePlayer *Init(int cls, int idx);
	static void gCallback_RemoteCreate(int cls, int idx);
};

int _Class_CardBattlePlayer::Get_ClassID() const
{
	return _class_id;
}

int _Class_CardBattlePlayer::Set_ClassID(int id)
{
	return _class_id = id;
}

int Class_CardBattlePlayer::Get_Size() const
{
	return 0x38;
}

const char *Class_CardBattlePlayer::Get_Name() const
{
	return "card_battle_player";
}

void *Class_CardBattlePlayer::Get_RemoteCreateCallback_p() const
{
	return (void *)CardBattlePlayer::gCallback_RemoteCreate;
}

}
}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZN7SaruNet9PetitGame22Class_CardBattlePlayer14Register_FieldER24NetTypeBroadcastSchedule); }

namespace SaruNet {
namespace PetitGame {

CardBattlePlayer::~CardBattlePlayer()
{
}

CardBattlePlayer *CardBattlePlayer::Init()
{
	Class_CardBattlePlayer cls;
	SaruNet::Object::Init(cls, true, Game::_instance_p->player_data + 0x40, (const unsigned char *)"card_battle_player");
	return this;
}

CardBattlePlayer *CardBattlePlayer::Init(int cls_id, int idx)
{
	Class_CardBattlePlayer cls;
	Net::Object::Init(cls, idx);
	return this;
}

void CardBattlePlayer::gCallback_RemoteCreate(int cls, int idx)
{
	Game *g = Game::_instance_p;
	g->remote_player = (new CardBattlePlayer)->Init(cls, idx);
}

}
}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTVN7SaruNet9PetitGame16CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", D_00108990); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTVN7SaruNet9PetitGame22Class_CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", D_001089A8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTVN7SaruNet9PetitGame23_Class_CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTIN7SaruNet9PetitGame23_Class_CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTIN7SaruNet9PetitGame22Class_CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTIN7SaruNet9PetitGame16CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTSN7SaruNet9PetitGame16CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTSN7SaruNet9PetitGame22Class_CardBattlePlayerE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_petit_network_card_battle_player", _ZTSN7SaruNet9PetitGame23_Class_CardBattlePlayerE); }
