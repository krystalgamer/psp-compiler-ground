/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

struct SceNetEtherAddr {
	unsigned char data[6];
};
extern "C" void consPrintf(const char *fmt, ...);
extern "C" int sceNetAdhocMatchingCancelTarget(int id, SceNetEtherAddr *mac);

namespace Net {
struct EtherAddress {
	unsigned char data[6];
};
}

void print_debug(const char *name, int id, Net::EtherAddress &a, void *opt, int optlen)
{
}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", D_00106620);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", _ZTIN3Net5LobbyE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", _ZTSN3Net5LobbyE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", D_00106664);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", _ZTVN3Net12LobbyBuilderE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", D_00106680);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", _ZTIN3Net12LobbyBuilderE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", _ZTSN3Net12LobbyBuilderE);
}

namespace Net {
class Lobby;

class LobbyMessageNode;
class LobbyMessageQueue {
public:
	LobbyMessageNode *Add_Message(int type, int id, const EtherAddress &a, int n, const void *p);
};

class LobbyDoubleMessageQueue {
public:
	void *vtbl;
	LobbyMessageQueue *queues[2];
	void *sema;
	signed char current;

	void Lock();
	void Unlock();
};

class LobbyState {
public:
	virtual ~LobbyState();
	virtual void Run(Lobby &l);
	virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
	virtual void v1C(); virtual void v20();
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

class Network {
public:
	char _p[0xC];
	union {
		unsigned int flags;
		struct {
			unsigned int b0 : 4;
			unsigned int error : 1;
			unsigned int b5 : 4;
			unsigned int lobby_error : 1;
		} bits;
	};
	static Network *_instance_p;
	void Set_Error() { flags |= 0x210; }
};

class Lobby {
public:
	int _p4;
	LobbyState *state;
	char _pC[0xC];
	int matching_id;
	char _p1C[0xC];
	LobbyDoubleMessageQueue *queue;

	static Lobby *_instance_p;

	virtual ~Lobby();
	virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
	virtual void v1C(); virtual void v20(); virtual void v24();
	virtual void Receive_Hello(int id, EtherAddress &a, int n, void *p);
	virtual void Receive_Request(int id, EtherAddress &a, int n, void *p);
	virtual void Receive_Leave(int id, EtherAddress &a);
	virtual void Receive_Deny(int id, EtherAddress &a);
	virtual void Receive_Cancel(int id, EtherAddress &a);
	virtual void Receive_Accept(int id, EtherAddress &a, int n, void *p);
	virtual void Receive_Establish(int id, EtherAddress &a);
	virtual void Receive_Timeout(int id, EtherAddress &a);
	virtual void Receive_Error(int id, EtherAddress &a);
	virtual void Receive_Bye(int id, EtherAddress &a);

	void AdhocMatchingEventHandler(int id, int event, SceNetEtherAddr *mac, int optlen, void *opt);
	static void AdhocMatchingEventHandlerInterface(int id, int event, SceNetEtherAddr *mac, int optlen, void *opt);
	void Update_TerminalList(const SceNetEtherAddr &mac, int n, void *p);
	void Update_TerminalList();
	void Remove_TerminalInfo(const SceNetEtherAddr &mac);
};

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_event", _ZN3Net5Lobby25AdhocMatchingEventHandlerEiiP15SceNetEtherAddriPv);
}

void Lobby::AdhocMatchingEventHandlerInterface(int id, int event, SceNetEtherAddr *mac, int optlen, void *opt)
{
	Lobby *l = _instance_p;
	l->AdhocMatchingEventHandler(id, event, mac, optlen, opt);
}


void Lobby::Receive_Hello(int id, EtherAddress &a, int n, void *p)
{
	Update_TerminalList((SceNetEtherAddr &)a, n, p);
	state->Hello(*this, a, n, p);
}

void Lobby::Receive_Request(int id, EtherAddress &a, int n, void *p)
{
	state->Request(*this, a, n, p);
}

void Lobby::Receive_Leave(int id, EtherAddress &a)
{
	Remove_TerminalInfo((SceNetEtherAddr &)a);
	Update_TerminalList();
	state->Leave(*this, a);
}

void Lobby::Receive_Deny(int id, EtherAddress &a)
{
	state->Deny(*this, a);
}

void Lobby::Receive_Cancel(int id, EtherAddress &a)
{
	state->Cancel(*this, a);
}

void Lobby::Receive_Accept(int id, EtherAddress &a, int n, void *p)
{
	state->Accept(*this, a, n, p);
}

void Lobby::Receive_Establish(int id, EtherAddress &a)
{
	state->Establish(*this, a);
}

void Lobby::Receive_Timeout(int id, EtherAddress &a)
{
	Remove_TerminalInfo((SceNetEtherAddr &)a);
	Update_TerminalList();
	state->Timeout(*this, a);
}

void Lobby::Receive_Error(int id, EtherAddress &a)
{
	Network *n = Network::_instance_p;
	n->flags |= 0x210;
	state->Error(*this, a);
}

void Lobby::Receive_Bye(int id, EtherAddress &a)
{
	Remove_TerminalInfo((SceNetEtherAddr &)a);
	Update_TerminalList();
	state->Bye(*this, a);
}
}
