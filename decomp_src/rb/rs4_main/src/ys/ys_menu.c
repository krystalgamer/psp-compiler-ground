/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#include "common.h"

struct CtrlState {
	unsigned int hold;
	unsigned int trg;
	char _8[8];
	unsigned int rep;
};

extern "C" {
void _memFree(void *p, const char *file, int line);
CtrlState *ctrlState(int port);
CtrlState *ctrlStateV(int entry);
int gameGetEntry(void);
}

struct Task;

namespace Ys {
class Object {
public:
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
	virtual ~MenuView();
	virtual void Set_ItemCount(int n);
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
	union {
		unsigned int flags;
		struct {
			bool closed : 1;
			bool cancel : 1;
			bool repeat : 1;
			bool loop : 1;
			bool lock : 1;
			bool vpad : 1;
		};
	};
	Menu(MenuView *v, int n, int sel);
	virtual ~Menu();
	virtual int Open(int sel);
	virtual void Close();
	virtual int Reset_ItemCount(int n);
	virtual int Set_Select(int n);
	unsigned int &Get_DirectVirtualPadTrigger() const;
	unsigned int &Get_RepeatVirtualPadTrigger() const;
	unsigned int &Get_PadTrigger() const;
	virtual int Run();
	int Get_Select() const { return select; }
};

class LineMenu : public Menu {
public:
	unsigned short next_key;
	unsigned short prev_key;
	LineMenu(MenuView *v, unsigned short next, unsigned short prev, int n, int sel);
	virtual int Run();
};

/* STAND-IN: some header code deletes a LineMenu (its D0 is emitted before D1 in the original); this
   never-emitted inline only reproduces that mark-used order. */
inline void Delete_LineMenu(LineMenu *m) { delete m; }

class TableMenu : public Menu {
public:
	signed char cols;
	signed char rows;
	signed char col;
	signed char row;
	TableMenu(MenuView *v, int c, int n, int sel);
	int Set_Pos(int n);
	int Conv_PosToSelect(int x, int y);
	virtual int Set_Select(int n);
	virtual int Run();
};

Menu::Menu(MenuView *v, int n, int sel)
{
	view_p = v;
	count = n;
	flags = 0;
	Menu::Set_Select(sel);
	prev_select = -1;
	closed = 1;
}

Menu::~Menu()
{
	delete view_p;
}

int Menu::Open(int sel)
{
	if (view_p)
		view_p->Open(sel);
	closed = 0;
	select = sel;
	wait = 4;
	return select;
}

void Menu::Close()
{
	closed = 1;
	if (view_p)
		view_p->Close();
}

int Menu::Reset_ItemCount(int n)
{
	if (select >= n)
		Set_Select(n > 0 ? n - 1 : 0);
	return count = n;
}

int Menu::Set_Select(int n)
{
	if (view_p)
		view_p->Set_Select(n);
	return select = n;
}

unsigned int &Menu::Get_DirectVirtualPadTrigger() const
{
	return ctrlStateV(gameGetEntry())->trg;
}

unsigned int &Menu::Get_RepeatVirtualPadTrigger() const
{
	return ctrlStateV(gameGetEntry())->rep;
}

unsigned int &Menu::Get_PadTrigger() const
{
	if (!vpad) {
		if (repeat)
			return ctrlState(0)->rep;
		return ctrlState(0)->trg;
	}
	if (repeat)
		return Get_RepeatVirtualPadTrigger();
	return Get_DirectVirtualPadTrigger();
}

int Menu::Run()
{
	prev_select = Get_Select();
	if (closed)
		return 1;
	if (lock)
		return 0;
	if (view_p && !view_p->active)
		return 0;
	int w = wait - 1;
	if (w > 0) {
		wait = w;
		return 0;
	}
	int ret = 0;
	unsigned int t = !vpad ? ctrlState(0)->trg : Get_DirectVirtualPadTrigger();
	if ((t & 0x10000) && count > 0) {
		ret = 1;
		closed = 1;
		cancel = 0;
	} else if (t & 0x20000) {
		ret = 1;
		closed = 1;
		cancel = 1;
	}
	return ret;
}

LineMenu::LineMenu(MenuView *v, unsigned short next, unsigned short prev, int n, int sel) : Menu(v, n, sel)
{
	next_key = next;
	prev_key = prev;
}

int LineMenu::Run()
{
	if (Menu::Run())
		return 1;
	if (view_p && !view_p->active)
		return 0;
	unsigned int t = Get_PadTrigger();
	int sel = select;
	bool lp = loop;
	int n = count;
	if (t & prev_key) {
		if (sel > 0)
			sel--;
		else if (lp)
			sel = n - 1;
	} else if (t & next_key) {
		if (sel < n - 1)
			sel++;
		else if (lp)
			sel = 0;
	}
	Set_Select(sel);
	return 0;
}

TableMenu::TableMenu(MenuView *v, int c, int n, int sel) : Menu(v, n, sel)
{
	cols = c;
	rows = (n + c - 1) / c;
	TableMenu::Set_Select(sel);
}

int TableMenu::Set_Pos(int n)
{
	row = n / cols;
	col = n % cols;
	return n;
}

int TableMenu::Conv_PosToSelect(int x, int y)
{
	return y * cols + x;
}

int TableMenu::Set_Select(int n)
{
	return Set_Pos(Menu::Set_Select(n));
}

int TableMenu::Run()
{
	if (Menu::Run())
		return 1;
	if (view_p && !view_p->active)
		return 0;
	unsigned int &t = Get_PadTrigger();
	int r = rows;
	int c = cols;
	int n = count;
	bool lp = loop;
	int last = r > 0 ? n - c * (r - 1) : 0;
	int y = row;
	int w = y < r - 1 ? c : last;
	int x = col;
	if (t & 0x80) {
		if (x > 0)
			x--;
		else if (lp)
			x = w - 1;
	} else if (t & 0x20) {
		if (x < w - 1)
			x++;
		else if (lp)
			x = 0;
	} else if (t & 0x10) {
		if (y > 0)
			y--;
		else if (lp)
			y = x < last ? r - 1 : r - 2;
	} else if (t & 0x40) {
		if (Conv_PosToSelect(x, y + 1) < n)
			y++;
		else if (lp)
			y = 0;
	}
	Set_Select(Conv_PosToSelect(x, y));
	return 0;
}

}


