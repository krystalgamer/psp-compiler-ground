/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" const char D_00108114[];

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00108114, 23); }
	static void operator delete(void *p) { _memFree(p, D_00108114, 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, D_00108114, 32); }
	static void operator delete[](void *p) { if (p) _memFree(p, D_00108114, 34); }
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
};

class LobbyHelloMessage : public LobbyMessage {
public:
	LobbyHelloMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyRequestMessage : public LobbyMessage {
public:
	LobbyRequestMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyLeaveMessage : public LobbyMessage {
public:
	LobbyLeaveMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyDenyMessage : public LobbyMessage {
public:
	LobbyDenyMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyCancelMessage : public LobbyMessage {
public:
	LobbyCancelMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyAcceptMessage : public LobbyMessage {
public:
	LobbyAcceptMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyEstablishMessage : public LobbyMessage {
public:
	LobbyEstablishMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyTimeoutMessage : public LobbyMessage {
public:
	LobbyTimeoutMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyErrorMessage : public LobbyMessage {
public:
	LobbyErrorMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

class LobbyByeMessage : public LobbyMessage {
public:
	LobbyByeMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};
}

namespace SaruNet {

class LobbyHelloMessage : public Net::LobbyHelloMessage {
public:
	LobbyHelloMessage();
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

LobbyHelloMessage::LobbyHelloMessage() : Net::LobbyHelloMessage(0x84)
{
}

Net::LobbyMessage *LobbyHelloMessage::Create_Array(int n) const
{
	return new LobbyHelloMessage[n];
}

class LobbyRequestMessage : public Net::LobbyRequestMessage {
public:
	LobbyRequestMessage();
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

LobbyRequestMessage::LobbyRequestMessage() : Net::LobbyRequestMessage(0x310)
{
}

Net::LobbyMessage *LobbyRequestMessage::Create_Array(int n) const
{
	return new LobbyRequestMessage[n];
}

class LobbyLeaveMessage : public Net::LobbyLeaveMessage {
public:
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

Net::LobbyMessage *LobbyLeaveMessage::Create_Array(int n) const
{
	return new LobbyLeaveMessage[n];
}

class LobbyDenyMessage : public Net::LobbyDenyMessage {
public:
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

Net::LobbyMessage *LobbyDenyMessage::Create_Array(int n) const
{
	return new LobbyDenyMessage[n];
}

class LobbyCancelMessage : public Net::LobbyCancelMessage {
public:
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

Net::LobbyMessage *LobbyCancelMessage::Create_Array(int n) const
{
	return new LobbyCancelMessage[n];
}

class LobbyAcceptMessage : public Net::LobbyAcceptMessage {
public:
	LobbyAcceptMessage();
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

LobbyAcceptMessage::LobbyAcceptMessage() : Net::LobbyAcceptMessage(0x310)
{
}

Net::LobbyMessage *LobbyAcceptMessage::Create_Array(int n) const
{
	return new LobbyAcceptMessage[n];
}

class LobbyEstablishMessage : public Net::LobbyEstablishMessage {
public:
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

Net::LobbyMessage *LobbyEstablishMessage::Create_Array(int n) const
{
	return new LobbyEstablishMessage[n];
}

class LobbyTimeoutMessage : public Net::LobbyTimeoutMessage {
public:
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

Net::LobbyMessage *LobbyTimeoutMessage::Create_Array(int n) const
{
	return new LobbyTimeoutMessage[n];
}

class LobbyErrorMessage : public Net::LobbyErrorMessage {
public:
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

Net::LobbyMessage *LobbyErrorMessage::Create_Array(int n) const
{
	return new LobbyErrorMessage[n];
}

class LobbyByeMessage : public Net::LobbyByeMessage {
public:
	virtual Net::LobbyMessage *Create_Array(int n) const;
};

Net::LobbyMessage *LobbyByeMessage::Create_Array(int n) const
{
	return new LobbyByeMessage[n];
}
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet17LobbyHelloMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet17LobbyHelloMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet19LobbyRequestMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet19LobbyRequestMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet17LobbyLeaveMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet17LobbyLeaveMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet16LobbyDenyMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet16LobbyDenyMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet18LobbyCancelMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet18LobbyCancelMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet18LobbyAcceptMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet18LobbyAcceptMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet21LobbyEstablishMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet21LobbyEstablishMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet19LobbyTimeoutMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet19LobbyTimeoutMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet17LobbyErrorMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet17LobbyErrorMessageD0Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet15LobbyByeMessageD1Ev);
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZN7SaruNet15LobbyByeMessageD0Ev);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_00108114);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet15LobbyByeMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_00108130);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet17LobbyErrorMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_00108148);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet19LobbyTimeoutMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_00108160);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet21LobbyEstablishMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_00108178);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet18LobbyAcceptMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_00108190);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet18LobbyCancelMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_001081A8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet16LobbyDenyMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_001081C0);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet17LobbyLeaveMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_001081D8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet19LobbyRequestMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_001081F0);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTVN7SaruNet17LobbyHelloMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", D_00108208);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet17LobbyHelloMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet19LobbyRequestMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet17LobbyLeaveMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet16LobbyDenyMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet18LobbyCancelMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet18LobbyAcceptMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet21LobbyEstablishMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet19LobbyTimeoutMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet17LobbyErrorMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTIN7SaruNet15LobbyByeMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet15LobbyByeMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet17LobbyErrorMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet19LobbyTimeoutMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet21LobbyEstablishMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet18LobbyAcceptMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet18LobbyCancelMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet16LobbyDenyMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet17LobbyLeaveMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet19LobbyRequestMessageE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message", _ZTSN7SaruNet17LobbyHelloMessageE);
}
