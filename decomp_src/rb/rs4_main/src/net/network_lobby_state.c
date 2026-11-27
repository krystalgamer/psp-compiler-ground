/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtable, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" int sceNetAdhocMatchingCancelTarget(int id, void *mac);

namespace Net {
struct EtherAddress {
	unsigned char data[6];
};

class Lobby {
public:
	char _p[0x18];
	int matching_id;
	void Update_TerminalList();
};

namespace LobbyState {
class Sleep {
public:
	virtual ~Sleep();
	virtual void Run(Lobby &l);
	virtual void Hello(Lobby &l, EtherAddress &a, int n, void *p);
	virtual void Request(Lobby &l, EtherAddress &a, int n, void *p);
	virtual void Leave(Lobby &l, EtherAddress &a);
	virtual void Deny(Lobby &l, EtherAddress &a);
	virtual void Cancel(Lobby &l, EtherAddress &a);
	virtual void Accept(Lobby &l, EtherAddress &a, int n, void *p);
	virtual void Establish(Lobby &l, EtherAddress &a);
	virtual void Timeout(Lobby &l, EtherAddress &a);
	virtual void Error(Lobby &l, EtherAddress &a);
	virtual void Bye(Lobby &l, EtherAddress &a);
};

void Sleep::Hello(Lobby &l, EtherAddress &a, int n, void *p)
{
}

void Sleep::Request(Lobby &l, EtherAddress &a, int n, void *p)
{
	sceNetAdhocMatchingCancelTarget(l.matching_id, &a);
}

void Sleep::Leave(Lobby &l, EtherAddress &a)
{
}

void Sleep::Deny(Lobby &l, EtherAddress &a)
{
}

void Sleep::Cancel(Lobby &l, EtherAddress &a)
{
}

void Sleep::Accept(Lobby &l, EtherAddress &a, int n, void *p)
{
	sceNetAdhocMatchingCancelTarget(l.matching_id, &a);
}

void Sleep::Establish(Lobby &l, EtherAddress &a)
{
	sceNetAdhocMatchingCancelTarget(l.matching_id, &a);
}

void Sleep::Timeout(Lobby &l, EtherAddress &a)
{
}

void Sleep::Error(Lobby &l, EtherAddress &a)
{
}

void Sleep::Bye(Lobby &l, EtherAddress &a)
{
}

void Sleep::Run(Lobby &l)
{
	l.Update_TerminalList();
}
}
}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_state", D_00106D14);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_state", _ZN3Net10LobbyState5SleepD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_state", _ZN3Net10LobbyState5SleepD1Ev);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_state", _ZTIN3Net10LobbyState5SleepE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_state", _ZTSN3Net10LobbyState5SleepE);
}
