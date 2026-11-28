/* lang: c++ */
/* cflags: -Os -fno-merge-constants -fno-exceptions */
/* strength reduction on: Finish_Update matches only with it (address loop IV) */
#include "common.h"

extern "C" {
void *memset(void *p, int c, unsigned int n);
int memcmp(const void *a, const void *b, unsigned int n);
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
}

struct Task;

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

class Task : public Object {
public:
	::Task *task_p;
	void *state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
};

class MenuView : public Task {
public:
	short select;
	short count;
	bool active;
	virtual int Set_ItemCount(int n);
	virtual int Set_Select(int n);
	virtual void Open(int n);
	virtual void Close();
};

class Menu : public Object {
public:
	MenuView *view_p;
	signed char select;
	signed char prev_select;
	signed char count;
	signed char wait;
	unsigned int flags;
	Menu(MenuView *v, int n, int sel);
	virtual ~Menu();
	virtual int Open(int sel);
	virtual void Close();
	virtual int Reset_ItemCount(int n);
	virtual int Set_Select(int n);
	virtual int Run();
};

class LineMenu : public Menu {
public:
	unsigned short next_key;
	unsigned short prev_key;
	LineMenu(MenuView *v, unsigned short next, unsigned short prev, int n, int sel);
	virtual int Run();
};

class VerticalMenu : public LineMenu {
public:
	VerticalMenu(MenuView *v, unsigned short next, unsigned short prev, int n, int sel) : LineMenu(v, next, prev, n, sel) {}
};
}

namespace Net {
struct NetAddress {
	unsigned char data[6];
	NetAddress() { memset(data, 0, sizeof(data)); }
	void Clear() { memset(data, 0, sizeof(data)); }
	bool operator==(const NetAddress &a) const { return memcmp(data, a.data, sizeof(data)) == 0; }
	bool operator!=(const NetAddress &a) const { return memcmp(data, a.data, sizeof(data)) != 0; }
};
}

namespace SaruNet {

struct PlayerName {
	char str[0x80];
} __attribute__((aligned(4)));

class LobbyPlayerMenuView : public Ys::MenuView {
public:
	char _11[0x13];
	bool updated;
};

class LobbyPlayerMenuItem {
public:
	short active;
	unsigned short f2;
	Net::NetAddress address;
	PlayerName name;
	LobbyPlayerMenuItem();
	void Reset();
	LobbyPlayerMenuItem &Copy(LobbyPlayerMenuItem &p);
};

class LobbyPlayerMenu : public Ys::VerticalMenu {
public:
	signed char item_count;
	char _15[3];
	bool updated;
	LobbyPlayerMenuItem items[16];
	Net::NetAddress selected_address;
	LobbyPlayerMenu(LobbyPlayerMenuView *v);
	LobbyPlayerMenuView *Get_View_p() const;
	int Start_Update(int n);
	LobbyPlayerMenuItem &Add_Item(LobbyPlayerMenuItem &item);
	void Finish_Update();
};

LobbyPlayerMenuItem::LobbyPlayerMenuItem()
{
	memset(&name, 0, sizeof(name));
	active = 0;
	f2 = 0;
}

void LobbyPlayerMenuItem::Reset()
{
	active = 0;
	f2 = 0;
	address.Clear();
	memset(&name, 0, sizeof(name));
}

LobbyPlayerMenuItem &LobbyPlayerMenuItem::Copy(LobbyPlayerMenuItem &p)
{
	active = p.active != 0;
	f2 = p.f2;
	address = p.address;
	name = p.name;
	return *this;
}

LobbyPlayerMenu::LobbyPlayerMenu(LobbyPlayerMenuView *v)
	: Ys::VerticalMenu(v, 0x40, 0x10, 0, 0)
{
}

LobbyPlayerMenuView *LobbyPlayerMenu::Get_View_p() const
{
	return (LobbyPlayerMenuView *)view_p;
}

int LobbyPlayerMenu::Start_Update(int n)
{
	item_count = 0;
	int c = count;
	updated = (signed char)n != c;
	count = n;
	Net::NetAddress &a = selected_address;
	if (c > 0) {
		LobbyPlayerMenuItem &it = items[select];
		a = it.address;
	} else
		a.Clear();
	return n;
}

LobbyPlayerMenuItem &LobbyPlayerMenu::Add_Item(LobbyPlayerMenuItem &item)
{
	int i = item_count;
	if (i < count) {
		LobbyPlayerMenuItem &dst = items[i];
		if (updated || dst.address != item.address) {
			dst.Copy(item);
			updated = 1;
		}
		item_count = i + 1;
	}
	return item;
}

void LobbyPlayerMenu::Finish_Update()
{
	if (!updated)
		return;
	int n = count;
	int sel = -1;
	const Net::NetAddress &a = selected_address;
	for (int i = 0; i < n; i++) {
		if (items[i].address == a) {
			sel = i;
			break;
		}
	}
	if (sel < 0) {
		sel = select;
		if (!(sel < n))
			sel = n - 1;
	}
	if (view_p) {
		LobbyPlayerMenuView *v = Get_View_p();
		v->Set_ItemCount(n);
		v->updated = 1;
	}
	Set_Select(sel);
}

}


