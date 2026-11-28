/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#include "common.h"

struct tagTtrFontCntx;
struct InstDat;
struct bxAnm;
struct CtrlState {
	unsigned int hold;
	unsigned int trg;
};
struct GameCntx {
	int _0;
	unsigned int f4;
	unsigned int f8;
};
struct Vec4 {
	float x, y, z, w;
};
struct Mtx4 {
	Vec4 x, y, z, w;
};
struct Task {
	char _0[0x24];
	signed char f24;
	char _25[3];
	int f28;
	int f2C;
	char _30[0x30];
	char attr[0x30];
	Mtx4 m90;
	Mtx4 mD0;
};

extern "C" {
void *_memAllocMBL(unsigned int size, const char *file, int line);
void _memFree(void *p, const char *file, int line);
void ttrFontTerm(tagTtrFontCntx *f);
tagTtrFontCntx *ttrFontInit(InstDat *res, InstDat *inst, char *s, int n, unsigned int **pp);
tagTtrFontCntx *ttrFontInitEx(InstDat *res, InstDat *inst, char *s, int m, int n, unsigned int **pp);
void ttrFontUpdate(tagTtrFontCntx *f, void *a, void *b);
InstDat *resGetDatLocal(int a, int b);
GameCntx *gameGetCntx(void);
CtrlState *ctrlState(int port);
float bxAnmGetFrame(bxAnm *a);
float bxAnmGetEndFrame(bxAnm *a);
}

namespace Ys {
class Object {
public:
	static void *operator new(unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 23); }
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

namespace Cop {
struct Matrix4x4 {
	float m[4][4];
};
}

class TaskState;

class Task : public Object {
public:
	::Task *task_p;
	TaskState *state_p;
	static TaskState *_default_state_p;
	static TaskState *_sleep_state_p;
	virtual ~Task();
	virtual void Receive_InitMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_FreeMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_KillChildMessage(::Task *t, ::Task *c, unsigned int n);
	Task *Init(void *p, unsigned int n, Task *parent);
};

class TaskState : public Object {
public:
	virtual ~TaskState();
	virtual void Kill(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Free(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void Draw(Task &t, ::Task *p, void *q, unsigned int n);
	virtual void KillChild(Task &t, ::Task *p, ::Task *c, unsigned int n);
	virtual void Unknown(Task &t, ::Task *p, int m, void *q, unsigned int n);
};

class Anim2D {
public:
	char _0[0x40];
	bxAnm *anm;
	char _44[0xC];
	~Anim2D();
	void Load(int id, int loop);
	void Exec();
	void Draw(Cop::Matrix4x4 &m);
};

class Sound {
public:
	static Sound *_instance_p;
	void Play(int id);
	static void Play_SE(int id) { if (id >= 0) _instance_p->Play(id); }
};

class MenuView : public Task {
public:
	short select;
	short count;
	bool active;
	MenuView *Init(Task *parent, int a, int b);
	virtual void Set_ItemCount(int n);
	virtual int Set_Select(int n) { select = n; return select; }
	virtual void Open(int n);
	virtual void Close();
};

class Menu : public Object {
public:
	MenuView *view_p;
	signed char select;
	signed char prev_select;
	char _a[2];
	unsigned int _b0 : 1;
	unsigned int cancel : 1;
	unsigned int _b2 : 1;
	unsigned int vertical : 1;
	virtual ~Menu();
	virtual void Open(int n);
	virtual void Close();
	virtual void Reset_ItemCount(int n);
	virtual void Set_Select(int n);
	virtual int Run();
	bool Is_Change() const { return select != prev_select; }
};

class LineMenu : public Menu {
public:
	int _10;
	LineMenu(MenuView *v, unsigned short a, unsigned short b, int c, int d);
	virtual int Run();
};

class VerticalMenu;

class ScreenPanel;

class ScreenPanelDaemon {
public:
	ScreenPanel *panel_p;
	static ScreenPanelDaemon *_instance_p;
	ScreenPanelDaemon();
	~ScreenPanelDaemon();
	ScreenPanel &Add_Panel(ScreenPanel &p);
	void Remove_Panel();
	ScreenPanel *Get_Panel_p() const { return panel_p; }
	ScreenPanel &Get_Panel() const { return *panel_p; }
	bool Is_Panel() const { return panel_p != 0; }
	void Remove_SelfPanel__From_PanelDestructor(ScreenPanel &p);
};

class ScreenPanel : public Task {
public:
	int _c;
	Anim2D anim;
	tagTtrFontCntx *font_p;
	bool opened : 1;
	bool suspend : 1;
	unsigned int _flags : 30;
	virtual ~ScreenPanel();
	ScreenPanel *Init(tagTtrFontCntx &f, Task *parent);
	static tagTtrFontCntx *Create_TextContext(InstDat &d, char *s, int n, unsigned int **pp);
	static tagTtrFontCntx *Create_MultiTextContext(int m, InstDat &d, char *s, int n, unsigned int **pp);
	void Suspend_NormalTask();
	void Wakeup_NormalTask();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
	virtual void Open();
	virtual void Close();
	virtual void Run_Common();
};

class Cancel_ScreenPanel : public ScreenPanel {
public:
	short wait;
	unsigned short no_close;
	Cancel_ScreenPanel *Init(tagTtrFontCntx &f, bool b, Task *parent);
	virtual void Open();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

class MenuScreenPanel2;

class MenuScreenPanel2_View;

class MenuScreenPanel2 : public ScreenPanel {
public:
	class OpenState : public TaskState {
	public:
		virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
	};
	VerticalMenu *menu_p;
	int se;
	tagTtrFontCntx *item_p[2];
	OpenState open_state;
	virtual ~MenuScreenPanel2();
	MenuScreenPanel2 *Init(tagTtrFontCntx &f, tagTtrFontCntx &f0, tagTtrFontCntx &f1, int se, Task *parent);
	static tagTtrFontCntx *Create_ItemContext0(InstDat &d, char *s, int n, unsigned int **pp);
	static tagTtrFontCntx *Create_ItemContext1(InstDat &d, char *s, int n, unsigned int **pp);
	bool Is_Cancel() const;
	bool Is_Change() const;
	void Open(int n);
	MenuView *Get_View_p() const;
	int Get_SelectItem() const;
	int Set_SelectItem(int n);
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
};

class MenuScreenPanel2_View : public MenuView {
public:
	MenuScreenPanel2 *panel_p;
	MenuScreenPanel2_View *Init(MenuScreenPanel2 &p);
	virtual int Set_Select(int n);
	virtual void Open(int n);
	virtual void Close();
};

class VerticalMenu : public LineMenu {
public:
	VerticalMenu(MenuView *v, unsigned short a, unsigned short b, int c, int d) : LineMenu(v, a, b, c, d) {}
	void Set_Vertical() { vertical = 1; }
};

class YesNo_ScreenPanel : public MenuScreenPanel2 {
public:
	YesNo_ScreenPanel *Init(tagTtrFontCntx &f, int se, Task *parent);
};


ScreenPanelDaemon::ScreenPanelDaemon()
{
	_instance_p = this;
	panel_p = 0;
}

ScreenPanelDaemon::~ScreenPanelDaemon()
{
	Remove_Panel();
	_instance_p = 0;
}

ScreenPanel &ScreenPanelDaemon::Add_Panel(ScreenPanel &p)
{
	Remove_Panel();
	panel_p = &p;
	return p;
}

void ScreenPanelDaemon::Remove_Panel()
{
	if (Is_Panel())
		delete panel_p;
	panel_p = 0;
}

void ScreenPanelDaemon::Remove_SelfPanel__From_PanelDestructor(ScreenPanel &p)
{
	if (panel_p == &p)
		panel_p = 0;
}

ScreenPanel::~ScreenPanel()
{
	Wakeup_NormalTask();
	ScreenPanelDaemon::_instance_p->Remove_SelfPanel__From_PanelDestructor(*this);
	if (font_p)
		ttrFontTerm(font_p);
}

ScreenPanel *ScreenPanel::Init(tagTtrFontCntx &f, Task *parent)
{
	Task::Init(0, 0, parent);
	task_p->f24 = -1;
	state_p = _sleep_state_p;
	font_p = &f;
	task_p->f2C = 0;
	*(unsigned int *)((char *)&font_p + 4) = 2;
	task_p->f28 = 0;
	return this;
}

tagTtrFontCntx *ScreenPanel::Create_TextContext(InstDat &d, char *s, int n, unsigned int **pp)
{
	return ttrFontInit(resGetDatLocal(1, 0x56), &d, s, n, pp);
}

tagTtrFontCntx *ScreenPanel::Create_MultiTextContext(int m, InstDat &d, char *s, int n, unsigned int **pp)
{
	return ttrFontInitEx(resGetDatLocal(1, 0x56), &d, s, m, n, pp);
}

void ScreenPanel::Suspend_NormalTask()
{
	if (suspend) {
		GameCntx *g = gameGetCntx();
		g->f8 &= ~0x40;
		g->f4 |= 0x40;
	}
}

void ScreenPanel::Wakeup_NormalTask()
{
	if (suspend) {
		GameCntx *g = gameGetCntx();
		g->f4 &= ~0x40;
		g->f8 |= 0x40;
	}
}

void ScreenPanel::Open()
{
	task_p->f28 = -1;
	opened = 1;
	state_p = _default_state_p;
	anim.Load(0x5A, 1);
	Suspend_NormalTask();
}

void ScreenPanel::Close()
{
	Wakeup_NormalTask();
	task_p->f28 = 0;
	state_p = _sleep_state_p;
	opened = 0;
}

void ScreenPanel::Run_Common()
{
	if (font_p)
		ttrFontUpdate(font_p, &task_p->mD0.y, task_p->attr);
	anim.Exec();
}

void ScreenPanel::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	Run_Common();
}

void ScreenPanel::Receive_DrawMessage(::Task *t, void *p, unsigned int n)
{
	anim.Draw(*(Cop::Matrix4x4 *)&task_p->mD0);
}

Cancel_ScreenPanel *Cancel_ScreenPanel::Init(tagTtrFontCntx &f, bool b, Task *parent)
{
	ScreenPanel::Init(f, parent);
	no_close = b;
	return this;
}

void Cancel_ScreenPanel::Open()
{
	ScreenPanel::Open();
	wait = 30;
}

void Cancel_ScreenPanel::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	Run_Common();
	int w = wait - 1;
	if (w > 0) {
		wait = w;
		return;
	}
	if (ctrlState(0)->trg & 0x20000) {
		if (!no_close)
			Close();
		else
			state_p = _sleep_state_p;
	}
}

MenuScreenPanel2_View *MenuScreenPanel2_View::Init(MenuScreenPanel2 &p)
{
	MenuView::Init(0, 2, 0);
	panel_p = &p;
	return this;
}

int MenuScreenPanel2_View::Set_Select(int n)
{
	if (active)
		panel_p->Set_SelectItem(n);
	return MenuView::Set_Select(n);
}

void MenuScreenPanel2_View::Open(int n)
{
	active = 0;
	Set_Select(n);
}

void MenuScreenPanel2_View::Close()
{
	active = 0;
}

MenuScreenPanel2::~MenuScreenPanel2()
{
	for (int i = 0; i < 2; i++) {
		tagTtrFontCntx *&f = item_p[i];
		ttrFontTerm(f);
	}
	delete menu_p;
}

MenuScreenPanel2 *MenuScreenPanel2::Init(tagTtrFontCntx &f, tagTtrFontCntx &f0, tagTtrFontCntx &f1, int se_, Task *parent)
{
	ScreenPanel::Init(f, parent);
	se = se_;
	menu_p = new VerticalMenu((new MenuScreenPanel2_View)->Init(*this), 0x40, 0x10, 2, 0);
	menu_p->vertical = 1;
	item_p[0] = &f0;
	item_p[1] = &f1;
	return this;
}

tagTtrFontCntx *MenuScreenPanel2::Create_ItemContext0(InstDat &d, char *s, int n, unsigned int **pp)
{
	return ttrFontInit(resGetDatLocal(1, 0x57), &d, s, n, pp);
}

tagTtrFontCntx *MenuScreenPanel2::Create_ItemContext1(InstDat &d, char *s, int n, unsigned int **pp)
{
	return ttrFontInit(resGetDatLocal(1, 0x58), &d, s, n, pp);
}

bool MenuScreenPanel2::Is_Cancel() const
{
	return menu_p->cancel;
}

bool MenuScreenPanel2::Is_Change() const
{
	return menu_p->select != menu_p->prev_select;
}

void MenuScreenPanel2::Open(int n)
{
	task_p->f28 = -1;
	state_p = &open_state;
	opened = 1;
	anim.Load(0x5B, 1);
	gameGetCntx()->f4 |= 0x40;
	menu_p->Open(n);
}

MenuView *MenuScreenPanel2::Get_View_p() const
{
	return menu_p->view_p;
}

int MenuScreenPanel2::Get_SelectItem() const
{
	return menu_p->select;
}

int MenuScreenPanel2::Set_SelectItem(int n)
{
	anim.Load(n == 0 ? 0x5C : 0x5D, 1);
	return n;
}

extern "C" {
INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_screen_panel", _ZN2Ys16MenuScreenPanel218Receive_RunMessageEP4TaskPvj);
}


void MenuScreenPanel2::OpenState::Run(Task &t, ::Task *p, void *q, unsigned int n)
{
	MenuScreenPanel2 &s = (MenuScreenPanel2 &)t;
	s.Run_Common();
	Anim2D *a = &s.anim;
	if (bxAnmGetFrame(a->anm) >= bxAnmGetEndFrame(a->anm) - 1.0f) {
		VerticalMenu *m = s.menu_p;
		m->view_p->active = 1;
		a->Load(m->select == 0 ? 0x5C : 0x5D, 1);
		s.state_p = _default_state_p;
	}
}

YesNo_ScreenPanel *YesNo_ScreenPanel::Init(tagTtrFontCntx &f, int se, Task *parent)
{
	tagTtrFontCntx *a = Create_ItemContext0(*resGetDatLocal(1, 5), "MENU_TEXT_08", 0, 0);
	tagTtrFontCntx *b = Create_ItemContext1(*resGetDatLocal(1, 5), "MENU_TEXT_09", 0, 0);
	MenuScreenPanel2::Init(f, *a, *b, se, parent);
	return this;
}

}

