/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables and typeinfo stay in the module's asm .rodata */
#pragma interface "rodata"
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);
extern "C" void *memset(void *, int, unsigned long);
extern "C" int memcmp(const void *, const void *, unsigned long);
extern const char D_00106D9C[];

struct SceNetEtherAddr {
	unsigned char data[6];
};

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, D_00106D9C, 23); }
	static void operator delete(void *p) { _memFree(p, D_00106D9C, 25); }
	static void *operator new[](unsigned int size) { return _memAllocMBL(size, D_00106D9C, 32); }
	static void operator delete[](void *p) { if (p) _memFree(p, D_00106D9C, 37); }
};
}

namespace Net {
struct EtherAddress {
	unsigned char data[6];
};

static inline bool Is_Equal(const EtherAddress &a, SceNetEtherAddr b)
{
	return memcmp(&a, &b, sizeof(b)) == 0;
}

class LobbyTerminalInfo : public Ys::Object {
public:
	LobbyTerminalInfo *next;
	short used;
	short capacity;
	int size;
	EtherAddress addr;
	char *data;

	LobbyTerminalInfo() { memset(&addr, 0, sizeof(addr)); Init(0); }
	virtual ~LobbyTerminalInfo();
	LobbyTerminalInfo &Init(int n);
	void Reset();
};

LobbyTerminalInfo::~LobbyTerminalInfo()
{
	operator delete[](data);
}

LobbyTerminalInfo &LobbyTerminalInfo::Init(int n)
{
	Reset();
	capacity = n;
	data = n > 0 ? (char *)operator new[](n) : 0;
	return *this;
}

void LobbyTerminalInfo::Reset()
{
	next = 0;
	size = 0;
	used = 0;
	memset(&addr, 0, sizeof(addr));
}

class LobbyTerminalListBuilder : public Ys::Object {
public:
	virtual ~LobbyTerminalListBuilder();
	virtual LobbyTerminalInfo *Create_InfoTable(int n);
	virtual int Get_InfoOffsetSize() const;
};

LobbyTerminalListBuilder::~LobbyTerminalListBuilder()
{
}

LobbyTerminalInfo *LobbyTerminalListBuilder::Create_InfoTable(int n)
{
	return new LobbyTerminalInfo[n];
}

int LobbyTerminalListBuilder::Get_InfoOffsetSize() const
{
	return sizeof(LobbyTerminalInfo);
}

class LobbyTerminalList : public Ys::Object {
public:
	LobbyTerminalInfo *table;
	LobbyTerminalInfo *valid;
	signed char count;
	short info_size;

	virtual ~LobbyTerminalList();
	LobbyTerminalList &Init(LobbyTerminalListBuilder &b);
	void Reset();
	LobbyTerminalInfo *Get_ValidInfo_p(int n);
	LobbyTerminalInfo *Find_Info(const SceNetEtherAddr &mac);
	LobbyTerminalInfo *Alloc_Info();
	void Free_Info(LobbyTerminalInfo &info);
	LobbyTerminalInfo *Get_Info(int i) { return (LobbyTerminalInfo *)((char *)table + info_size * i); }
};

LobbyTerminalList::~LobbyTerminalList()
{
	delete[] table;
}

LobbyTerminalList &LobbyTerminalList::Init(LobbyTerminalListBuilder &b)
{
	table = b.Create_InfoTable(16);
	info_size = b.Get_InfoOffsetSize();
	Reset();
	return *this;
}

void LobbyTerminalList::Reset()
{
	valid = 0;
	count = 0;
	for (int i = 0; i < 16; i++)
		Get_Info(i)->Reset();
}

LobbyTerminalInfo *LobbyTerminalList::Get_ValidInfo_p(int n)
{
	LobbyTerminalInfo *r = 0;

	if (n < count) {
		LobbyTerminalInfo *p = valid;
		if (n > 0) {
			do {
				p = p->next;
			} while (--n);
		}
		r = p;
	}
	return r;
}

LobbyTerminalInfo *LobbyTerminalList::Find_Info(const SceNetEtherAddr &mac)
{
	LobbyTerminalInfo *r = 0;
	LobbyTerminalInfo *p;

	for (p = valid; p; p = p->next) {
		if (Is_Equal(p->addr, mac)) {
			r = p;
			break;
		}
	}
	return r;
}

extern "C" {
LobbyTerminalInfo *LobbyTerminalList::Alloc_Info()
{
	if (16 - count <= 0)
		return 0;
	LobbyTerminalInfo *r = 0;
	for (int i = 0; i < 16; i++) {
		LobbyTerminalInfo *info = Get_Info(i);
		if (!info->used) {
			info->next = 0;
			r = info;
			info->used = 1;
			int c = count;
			count = c + 1;
			LobbyTerminalInfo *p = valid;
			if (p) {
				while (p->next)
					p = p->next;
				p->next = info;
			} else {
				valid = info;
			}
			break;
		}
	}
	return r;
}
}

void LobbyTerminalList::Free_Info(LobbyTerminalInfo &info)
{
	LobbyTerminalInfo *prev = 0;
	LobbyTerminalInfo *p = valid;

	while (p) {
		LobbyTerminalInfo *next = p->next;
		if (p == &info) {
			if (prev)
				prev->next = next;
			else
				valid = next;
			info.used = 0;
			info.next = 0;
			int c = count;
			count = c - 1;
			return;
		}
		prev = p;
		p = next;
	}
}
}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", D_00106D9C);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTVN3Net17LobbyTerminalListE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", D_00106DB8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTVN3Net24LobbyTerminalListBuilderE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", D_00106DC8);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTVN3Net17LobbyTerminalInfoE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", D_00106DE0);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTIN3Net17LobbyTerminalInfoE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTIN3Net24LobbyTerminalListBuilderE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTIN3Net17LobbyTerminalListE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTSN3Net17LobbyTerminalListE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTSN3Net24LobbyTerminalListBuilderE);
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_lobby_terminal_list", _ZTSN3Net17LobbyTerminalInfoE);
}
