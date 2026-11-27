/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

extern "C" {
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
extern const char D_00107DD8[];
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00107DD8, 23); }
	static void operator delete(void *p) { _memFree(p, D_00107DD8, 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, D_00107DD8, 32); }
	static void operator delete[](void *p) { _memFree(p, D_00107DD8, 37); }
};
}

namespace Net {
class LobbyMessageQueueCreateParam : public Ys::Object {
public:
	void *message[10];
	int _2c[4];
	virtual ~LobbyMessageQueueCreateParam();
};

class LobbyDoubleMessageQueue : public Ys::Object {
public:
	char _4[0x10];
	LobbyDoubleMessageQueue(LobbyMessageQueueCreateParam &p);
	virtual ~LobbyDoubleMessageQueue();
};

class LobbyTerminalInfo : public Ys::Object {
public:
	char _4[0x18];
	virtual ~LobbyTerminalInfo();
};

class LobbyTerminalListBuilder {
public:
	virtual ~LobbyTerminalListBuilder();
	virtual LobbyTerminalInfo *Create_InfoTable(int n) = 0;
	virtual int Get_InfoOffsetSize() const = 0;
};

template <class T> class T_LobbyTerminalListBuilder : public LobbyTerminalListBuilder {
public:
	virtual LobbyTerminalInfo *Create_InfoTable(int n);
	virtual int Get_InfoOffsetSize() const;
};

class LobbyTerminalList : public Ys::Object {
public:
	char _4[0xC];
	virtual ~LobbyTerminalList();
	LobbyTerminalList &Init(LobbyTerminalListBuilder &b);
};

class LobbyBuilder : public Ys::Object {
public:
	int _4[7];
	int event_handler_thread_priority;
	LobbyBuilder() { Reset(); }
	virtual ~LobbyBuilder();
	virtual void Reset();
	virtual LobbyDoubleMessageQueue *Create_DoubleMessageQueue();
	virtual LobbyTerminalList *Create_TerminalList();
};
}

namespace SaruNet {
class LobbyTerminalInfo : public Net::LobbyTerminalInfo {
};

class LobbyMessageQueueCreateParam : public Net::LobbyMessageQueueCreateParam {
public:
	LobbyMessageQueueCreateParam();
	virtual ~LobbyMessageQueueCreateParam();
};

class LobbyDoubleMessageQueue : public Net::LobbyDoubleMessageQueue {
public:
	LobbyDoubleMessageQueue(Net::LobbyMessageQueueCreateParam &p) : Net::LobbyDoubleMessageQueue(p) {}
};

class LobbyTerminalList : public Net::LobbyTerminalList {
};

class LobbyBuilder : public Net::LobbyBuilder {
public:
	LobbyBuilder();
	virtual void Reset();
	virtual Net::LobbyDoubleMessageQueue *Create_DoubleMessageQueue();
	virtual Net::LobbyTerminalList *Create_TerminalList();
};
}

extern template class Net::T_LobbyTerminalListBuilder<SaruNet::LobbyTerminalInfo>;

namespace SaruNet {

LobbyBuilder::LobbyBuilder()
{
	event_handler_thread_priority = 0x15;
}

void LobbyBuilder::Reset()
{
	Net::LobbyBuilder::Reset();
	event_handler_thread_priority = 0x15;
}

Net::LobbyDoubleMessageQueue *LobbyBuilder::Create_DoubleMessageQueue()
{
	LobbyMessageQueueCreateParam param;
	return new LobbyDoubleMessageQueue(param);
}

Net::LobbyTerminalList *LobbyBuilder::Create_TerminalList()
{
	Net::T_LobbyTerminalListBuilder<LobbyTerminalInfo> builder;
	LobbyTerminalList *l = new LobbyTerminalList;
	l->Init(builder);
	return l;
}

}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet12LobbyBuilderD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet12LobbyBuilderD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet23LobbyDoubleMessageQueueD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet23LobbyDoubleMessageQueueD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet17LobbyTerminalListD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet17LobbyTerminalListD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN3Net26T_LobbyTerminalListBuilderIN7SaruNet17LobbyTerminalInfoEED0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN3Net26T_LobbyTerminalListBuilderIN7SaruNet17LobbyTerminalInfoEED1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN3Net26T_LobbyTerminalListBuilderIN7SaruNet17LobbyTerminalInfoEE16Create_InfoTableEi); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZNK3Net26T_LobbyTerminalListBuilderIN7SaruNet17LobbyTerminalInfoEE18Get_InfoOffsetSizeEv); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet17LobbyTerminalInfoD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZN7SaruNet17LobbyTerminalInfoD0Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", D_00107DD8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTVN3Net26T_LobbyTerminalListBuilderIN7SaruNet17LobbyTerminalInfoEEE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", D_00107DF8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTVN7SaruNet12LobbyBuilderE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", D_00107E10); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTVN7SaruNet17LobbyTerminalListE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", D_00107E30); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTVN7SaruNet23LobbyDoubleMessageQueueE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", D_00107E40); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTIN7SaruNet12LobbyBuilderE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTIN7SaruNet23LobbyDoubleMessageQueueE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTIN7SaruNet17LobbyTerminalListE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTIN3Net26T_LobbyTerminalListBuilderIN7SaruNet17LobbyTerminalInfoEEE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTSN3Net26T_LobbyTerminalListBuilderIN7SaruNet17LobbyTerminalInfoEEE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTSN7SaruNet17LobbyTerminalListE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTSN7SaruNet23LobbyDoubleMessageQueueE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTSN7SaruNet12LobbyBuilderE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTVN7SaruNet17LobbyTerminalInfoE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", D_00107F28); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTIN7SaruNet17LobbyTerminalInfoE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTSN7SaruNet17LobbyTerminalInfoE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/saru_network_lobby_builder", _ZTVN7SaruNet15LobbyPlayerMenuE); }
