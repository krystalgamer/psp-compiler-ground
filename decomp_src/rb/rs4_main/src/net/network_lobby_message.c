/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" void *memset(void *, int, unsigned long);
extern "C" void *memcpy(void *, const void *, unsigned long);

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
struct EtherAddress {
	unsigned char data[6];
};

class Lobby {
public:
	virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
	virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
	virtual void Hello(int id, EtherAddress &a, int n, void *p);
	virtual void Request(int id, EtherAddress &a, int n, void *p);
	virtual void Leave(int id, EtherAddress &a);
	virtual void Deny(int id, EtherAddress &a);
	virtual void Cancel(int id, EtherAddress &a);
	virtual void Accept(int id, EtherAddress &a, int n, void *p);
	virtual void Establish(int id, EtherAddress &a);
	virtual void Timeout(int id, EtherAddress &a);
	virtual void Error(int id, EtherAddress &a);
	virtual void Bye(int id, EtherAddress &a);
};

class LobbyMessage : public Ys::Object {
public:
	int id;
	short capacity;
	short size;
	char *data;
	EtherAddress addr;

	LobbyMessage(int n = 0);
	LobbyMessage(const LobbyMessage &m);
	virtual ~LobbyMessage();
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
	bool Set_OptionData(int n, const void *p);
	LobbyMessage &Copy(const LobbyMessage &m);
	int Get_Id() const { return id; }
	int Get_Size() const { return size; }
	void *Get_Data() const { return data; }
	EtherAddress &Get_Address() { return addr; }
};

LobbyMessage::LobbyMessage(int n)
{
	memset(&addr, 0, sizeof(addr));
	capacity = n;
	data = n > 0 ? (char *)operator new[](n) : 0;
}

LobbyMessage::LobbyMessage(const LobbyMessage &m)
{
	memset(&addr, 0, sizeof(addr));
	data = 0;
	Copy(m);
}

LobbyMessage::~LobbyMessage()
{
	operator delete[](data);
}

LobbyMessage *LobbyMessage::Create_Array(int n) const
{
	return new LobbyMessage[n];
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_message", _ZN3Net12LobbyMessage14Set_OptionDataEiPKv);
}

LobbyMessage &LobbyMessage::Copy(const LobbyMessage &m)
{
	operator delete[](data);
	capacity = m.capacity;
	int n = capacity;
	data = n > 0 ? (char *)operator new[](n) : 0;
	if (n > 0)
		memcpy(data, m.data, n);
	id = m.id;
	size = m.Get_Size();
	addr = m.addr;
	return *this;
}

void LobbyMessage::Run(Lobby &l)
{
}

class LobbyHelloMessage : public LobbyMessage {
public:
	LobbyHelloMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyHelloMessage::Create_Array(int n) const
{
	return new LobbyHelloMessage[n];
}

void LobbyHelloMessage::Run(Lobby &l)
{
	l.Hello(Get_Id(), Get_Address(), Get_Size(), Get_Data());
}

class LobbyRequestMessage : public LobbyMessage {
public:
	LobbyRequestMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyRequestMessage::Create_Array(int n) const
{
	return new LobbyRequestMessage[n];
}

void LobbyRequestMessage::Run(Lobby &l)
{
	l.Request(Get_Id(), Get_Address(), Get_Size(), Get_Data());
}

class LobbyLeaveMessage : public LobbyMessage {
public:
	LobbyLeaveMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyLeaveMessage::Create_Array(int n) const
{
	return new LobbyLeaveMessage[n];
}

void LobbyLeaveMessage::Run(Lobby &l)
{
	l.Leave(Get_Id(), Get_Address());
}

class LobbyDenyMessage : public LobbyMessage {
public:
	LobbyDenyMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyDenyMessage::Create_Array(int n) const
{
	return new LobbyDenyMessage[n];
}

void LobbyDenyMessage::Run(Lobby &l)
{
	l.Deny(Get_Id(), Get_Address());
}

class LobbyCancelMessage : public LobbyMessage {
public:
	LobbyCancelMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyCancelMessage::Create_Array(int n) const
{
	return new LobbyCancelMessage[n];
}

void LobbyCancelMessage::Run(Lobby &l)
{
	l.Cancel(Get_Id(), Get_Address());
}

class LobbyAcceptMessage : public LobbyMessage {
public:
	LobbyAcceptMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyAcceptMessage::Create_Array(int n) const
{
	return new LobbyAcceptMessage[n];
}

void LobbyAcceptMessage::Run(Lobby &l)
{
	l.Accept(Get_Id(), Get_Address(), Get_Size(), Get_Data());
}

class LobbyEstablishMessage : public LobbyMessage {
public:
	LobbyEstablishMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyEstablishMessage::Create_Array(int n) const
{
	return new LobbyEstablishMessage[n];
}

void LobbyEstablishMessage::Run(Lobby &l)
{
	l.Establish(Get_Id(), Get_Address());
}

class LobbyTimeoutMessage : public LobbyMessage {
public:
	LobbyTimeoutMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyTimeoutMessage::Create_Array(int n) const
{
	return new LobbyTimeoutMessage[n];
}

void LobbyTimeoutMessage::Run(Lobby &l)
{
	l.Timeout(Get_Id(), Get_Address());
}

class LobbyErrorMessage : public LobbyMessage {
public:
	LobbyErrorMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyErrorMessage::Create_Array(int n) const
{
	return new LobbyErrorMessage[n];
}

void LobbyErrorMessage::Run(Lobby &l)
{
	l.Error(Get_Id(), Get_Address());
}

class LobbyByeMessage : public LobbyMessage {
public:
	LobbyByeMessage(int n = 0) : LobbyMessage(n) {}
	virtual LobbyMessage *Create_Array(int n) const;
	virtual void Run(Lobby &l);
};

LobbyMessage *LobbyByeMessage::Create_Array(int n) const
{
	return new LobbyByeMessage[n];
}

void LobbyByeMessage::Run(Lobby &l)
{
	l.Bye(Get_Id(), Get_Address());
}
}

extern "C" {
}
