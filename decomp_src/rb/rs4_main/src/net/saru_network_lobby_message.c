/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 32); }
	static void operator delete[](void *p) { if (p) _memFree(p, "src/ys/ys_object.h", 34); }
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

