/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
extern const char D_001083D0[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_001083D0, 23); }
	static void operator delete(void *p) { _memFree(p, D_001083D0, 25); }
};
}

namespace Net {
class LobbyMessage : public Ys::Object {
public:
	char _4[0x14];
	LobbyMessage(int n);
	virtual ~LobbyMessage();
};

class LobbyMessageQueueCreateParam : public Ys::Object {
public:
	LobbyMessage *hello_p;
	LobbyMessage *request_p;
	LobbyMessage *leave_p;
	LobbyMessage *deny_p;
	LobbyMessage *cancel_p;
	LobbyMessage *accept_p;
	LobbyMessage *establish_p;
	LobbyMessage *timeout_p;
	LobbyMessage *error_p;
	LobbyMessage *bye_p;
	LobbyMessageQueueCreateParam();
	virtual ~LobbyMessageQueueCreateParam();
};
}

namespace SaruNet {
class LobbyHelloMessage : public Net::LobbyMessage {
public:
	LobbyHelloMessage();
};
class LobbyRequestMessage : public Net::LobbyMessage {
public:
	LobbyRequestMessage();
};
class LobbyLeaveMessage : public Net::LobbyMessage {
public:
	LobbyLeaveMessage() : Net::LobbyMessage(0) {}
};
class LobbyDenyMessage : public Net::LobbyMessage {
public:
	LobbyDenyMessage() : Net::LobbyMessage(0) {}
};
class LobbyCancelMessage : public Net::LobbyMessage {
public:
	LobbyCancelMessage() : Net::LobbyMessage(0) {}
};
class LobbyAcceptMessage : public Net::LobbyMessage {
public:
	LobbyAcceptMessage();
};
class LobbyEstablishMessage : public Net::LobbyMessage {
public:
	LobbyEstablishMessage() : Net::LobbyMessage(0) {}
};
class LobbyTimeoutMessage : public Net::LobbyMessage {
public:
	LobbyTimeoutMessage() : Net::LobbyMessage(0) {}
};
class LobbyErrorMessage : public Net::LobbyMessage {
public:
	LobbyErrorMessage() : Net::LobbyMessage(0) {}
};
class LobbyByeMessage : public Net::LobbyMessage {
public:
	LobbyByeMessage() : Net::LobbyMessage(0) {}
};

class LobbyMessageQueueCreateParam : public Net::LobbyMessageQueueCreateParam {
public:
	LobbyMessageQueueCreateParam();
	virtual ~LobbyMessageQueueCreateParam();
};

LobbyMessageQueueCreateParam::LobbyMessageQueueCreateParam()
{
	hello_p = new LobbyHelloMessage;
	request_p = new LobbyRequestMessage;
	leave_p = new LobbyLeaveMessage;
	deny_p = new LobbyDenyMessage;
	cancel_p = new LobbyCancelMessage;
	accept_p = new LobbyAcceptMessage;
	establish_p = new LobbyEstablishMessage;
	timeout_p = new LobbyTimeoutMessage;
	error_p = new LobbyErrorMessage;
	bye_p = new LobbyByeMessage;
}

LobbyMessageQueueCreateParam::~LobbyMessageQueueCreateParam()
{
	delete bye_p;
	delete error_p;
	delete timeout_p;
	delete establish_p;
	delete accept_p;
	delete cancel_p;
	delete deny_p;
	delete leave_p;
	delete request_p;
	delete hello_p;
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", D_001083D0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", _ZTVN7SaruNet28LobbyMessageQueueCreateParamE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", D_001083F0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", _ZTIN7SaruNet28LobbyMessageQueueCreateParamE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", _ZTSN7SaruNet28LobbyMessageQueueCreateParamE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", D_00108430); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", _ZTVN7SaruNet11ObjectClassE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", _ZTIN7SaruNet11ObjectClassE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_message_queue", _ZTSN7SaruNet11ObjectClassE); }
