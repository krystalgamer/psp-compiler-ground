/* lang: c++ */
/* cflags: -Os -fno-exceptions */
/* strength reduction on: Update matches only with it (menu item pointer IV) */
#include "common.h"

struct tagTtrFontCntx;
struct bxAnm;
struct Vec4 {
	float x, y, z, w;
};
struct Mtx4 {
	Vec4 x, y, z, w;
};
struct Task {
	char _0[0x28];
	int f28;
	int f2C;
	char _30[0x30];
	char attr[0x30];
	Mtx4 m90;
	Mtx4 mD0;
};

extern "C" {
void ttrFontUpdate(tagTtrFontCntx *f, void *a, void *b);
void ttrFontTerm(tagTtrFontCntx *f);
tagTtrFontCntx *ttrFontInit(void *font, void *dat, const char *name, int a, void *param);
void *resGetDatLocal(int a, int b);
void _memFree(void *p, const char *file, int line);
void *_memAllocMBL(unsigned int size, const char *file, int line);
void profileGetRankingTtrStr(void *dst, unsigned short rank);

float bxAnmGetFrame(bxAnm *a);
float bxAnmGetEndFrame(bxAnm *a);
}

namespace Ys {
namespace Cop {
struct Matrix4x4 {
	float m[4][4];
};
struct DrawAttribute;
}

class TaskState;

class Task {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
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
};

class TaskState {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
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
	char _44[4];
	unsigned char visible;
	char _49[7];
	~Anim2D();
	void Load(int id, int loop);
	void Exec();
	void Draw(Cop::Matrix4x4 &m);
};

class MenuView : public Task {
public:
	short select;
	short count;
	bool active;
	MenuView *Init(Task *parent, int n, int sel);
	virtual int Set_ItemCount(int n);
	virtual int Set_Select(int n);
	virtual void Open(int n);
	virtual void Close();
};


}

inline void *operator new[](unsigned int size) { return _memAllocMBL(size, "src/ys/ys_object.h", 32); }
inline void operator delete[](void *p) { if (p) _memFree(p, "src/ys/ys_object.h", 37); }

extern unsigned int Reset_ItemTexture_void_text[] __asm__("_ZZN7SaruNet19LobbyPlayerMenuView17Reset_ItemTextureEiE9void_text");

namespace SaruNet {

struct LobbyPlayerMenuItem {
	short active;
	unsigned short rank;
	char address[6];
	char _a[2];
	unsigned int name[0x20];
};

struct LobbyPlayerMenu {
	char _0[0x1C];
	LobbyPlayerMenuItem items[16];
};

class LobbyPlayerMenuView_ItemTextContext {
public:
	tagTtrFontCntx *font[2];
	LobbyPlayerMenuView_ItemTextContext() { font[0] = 0; font[1] = 0; }
	~LobbyPlayerMenuView_ItemTextContext();
	void Remove_Context();
	void Update(Ys::Cop::Matrix4x4 &m, Ys::Cop::DrawAttribute &a);
};

namespace LobbyPlayerMenuViewState {
class Open : public Ys::TaskState {
public:
	virtual void Run(Ys::Task &t, ::Task *p, void *q, unsigned int n);
};
class Close : public Ys::TaskState {
public:
	virtual void Run(Ys::Task &t, ::Task *p, void *q, unsigned int n);
};
}

class LobbyPlayerMenuView : public Ys::MenuView {
public:
	struct ItemTextureResource {
		short id[2];
	};
	LobbyPlayerMenuView_ItemTextContext *context_p;
	short view_count;
	short res_group;
	short select_anim;
	short open_anim;
	short close_anim;
	short top;
	bool updated;
	const short *select_tbl;
	const ItemTextureResource *res_p;
	LobbyPlayerMenu *menu_p;
	char _34[0xC];
	Ys::Anim2D anim;
	Ys::Anim2D up_anim;
	Ys::Anim2D down_anim;
	LobbyPlayerMenuViewState::Open open_state;
	LobbyPlayerMenuViewState::Close close_state;
	virtual ~LobbyPlayerMenuView();
	LobbyPlayerMenuView *Init(Ys::Task *parent, int n, int group, const ItemTextureResource *res, const short *tbl, int sel_anim, int op, int cl, int loop, int up, int down);
	int Reset_ItemTexture(int i);
	void Update();
	virtual int Set_Select(int n);
	virtual void Open(int n);
	virtual void Close();
	void Run_Common();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
};

LobbyPlayerMenuView_ItemTextContext::~LobbyPlayerMenuView_ItemTextContext()
{
	Remove_Context();
}

void LobbyPlayerMenuView_ItemTextContext::Remove_Context()
{
	if (font[0]) {
		ttrFontTerm(font[0]);
		font[0] = 0;
	}
	if (font[1]) {
		ttrFontTerm(font[1]);
		font[1] = 0;
	}
}

void LobbyPlayerMenuView_ItemTextContext::Update(Ys::Cop::Matrix4x4 &m, Ys::Cop::DrawAttribute &a)
{
	if (font[0])
		ttrFontUpdate(font[0], m.m[1], &a);
	if (font[1])
		ttrFontUpdate(font[1], m.m[1], &a);
}

LobbyPlayerMenuView::~LobbyPlayerMenuView()
{
	LobbyPlayerMenuView_ItemTextContext *p = context_p;
	delete[] p;
}

LobbyPlayerMenuView *LobbyPlayerMenuView::Init(Ys::Task *parent, int n, int group, const ItemTextureResource *res, const short *tbl, int sel_anim, int op, int cl, int loop, int up, int down)
{
	res_group = group;
	res_p = res;
	select_tbl = tbl;
	select_anim = sel_anim;
	open_anim = op;
	close_anim = cl;
	view_count = n;
	menu_p = 0;
	updated = 0;
	top = 0;
	if (up >= 0)
		up_anim.Load(up, loop);
	if (down >= 0)
		down_anim.Load(down, loop);
	context_p = new LobbyPlayerMenuView_ItemTextContext[n];
	MenuView::Init(parent, 0, 0);
	state_p = _sleep_state_p;
	return this;
}

int LobbyPlayerMenuView::Reset_ItemTexture(int i)
{
	LobbyPlayerMenuView_ItemTextContext &c = context_p[i];
	int group = res_group;
	void *param[1];
	param[0] = Reset_ItemTexture_void_text;
	c.Remove_Context();
	const ItemTextureResource &r = res_p[i];
	c.font[0] = ttrFontInit(resGetDatLocal(group, r.id[0]), resGetDatLocal(1, 5), "MENU_TEXT_56", 1, param);
	c.font[1] = ttrFontInit(resGetDatLocal(group, r.id[1]), resGetDatLocal(1, 5), "MENU_TEXT_56", 1, param);
	return i;
}

}


namespace SaruNet {

void LobbyPlayerMenuView::Update()
{
	int total = count;
	int rows = view_count;
	int group = res_group;
	if (total <= 0) {
		anim.Load(select_anim, group);
		top = 0;
		select = 0;
		for (int i = 0; i < rows; i++)
			Reset_ItemTexture(i);
		return;
	}
	int sel = select;
	int t = top;
	int d = sel - t;
	if (d > 0) {
		if (rows - 2 < d)
			t = sel - rows + 2;
	} else {
		t = sel - 1;
	}
	if (!(t + rows < total))
		t = total - rows;
	if (t < 0)
		t = 0;
	top = t;
	anim.Load(select_tbl[sel - t], group);
	LobbyPlayerMenu *menu = menu_p;
	if (menu) {
		for (int i = 0; i < rows; i++) {
			if (i < total) {
				LobbyPlayerMenuView_ItemTextContext &c = context_p[i];
				c.Remove_Context();
				const ItemTextureResource &r = res_p[i];
				LobbyPlayerMenuItem &item = menu->items[t + i];
				unsigned int buf[0x14];
				void *param[1];
				param[0] = item.name;
				c.font[0] = ttrFontInit(resGetDatLocal(group, r.id[0]), resGetDatLocal(1, 5), "MENU_TEXT_56", 1, param);
				profileGetRankingTtrStr(buf, item.rank);
				c.font[1] = ttrFontInit(resGetDatLocal(group, r.id[1]), resGetDatLocal(1, 5), (const char *)buf, 0, 0);
			} else {
				Reset_ItemTexture(i);
			}
		}
	} else {
		for (int i = 0; i < rows; i++)
			Reset_ItemTexture(i);
	}
}

}

namespace SaruNet {

int LobbyPlayerMenuView::Set_Select(int n)
{
	int s = n < 0 ? 0 : n;
	if (select == s)
		return n;
	if (active)
		updated = 1;
	return select = s;
}

void LobbyPlayerMenuView::Open(int n)
{
	int op = open_anim;
	active = op < 0;
	if (!active) {
		anim.Load(op, res_group);
		state_p = &open_state;
	} else {
		state_p = _default_state_p;
	}
	task_p->f28 = -1;
	select = n - 1;
	top = 0;
	Set_Select(n);
}

void LobbyPlayerMenuView::Close()
{
	if (close_anim >= 0) {
		anim.Load(close_anim, res_group);
		state_p = &close_state;
	} else {
		state_p = _sleep_state_p;
		task_p->f28 = 0;
	}
	active = 0;
}

void LobbyPlayerMenuView::Run_Common()
{
	anim.Exec();
	up_anim.Exec();
	down_anim.Exec();
	::Task *t = task_p;
	int n = view_count;
	Ys::Cop::Matrix4x4 &m = *(Ys::Cop::Matrix4x4 *)&t->mD0;
	Ys::Cop::DrawAttribute &a = *(Ys::Cop::DrawAttribute *)t->attr;
	for (int i = 0; i < n; i++)
		context_p[i].Update(m, a);
}

void LobbyPlayerMenuView::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	if (updated) {
		Update();
		updated = 0;
	}
	Run_Common();
}

void LobbyPlayerMenuView::Receive_DrawMessage(::Task *t, void *p, unsigned int n)
{
	Run_Common();
	Ys::Cop::Matrix4x4 &m = *(Ys::Cop::Matrix4x4 *)&task_p->mD0;
	anim.Draw(m);
	int t_ = top;
	if (t_ > 0)
		up_anim.Draw(m);
	if (t_ + view_count < count)
		down_anim.Draw(m);
}

void LobbyPlayerMenuViewState::Open::Run(Ys::Task &t, ::Task *p, void *q, unsigned int n)
{
	LobbyPlayerMenuView &v = (LobbyPlayerMenuView &)t;
	v.Run_Common();
	Ys::Anim2D *a = &v.anim;
	if (bxAnmGetFrame(a->anm) >= bxAnmGetEndFrame(a->anm) - 1.0f) {
		v.active = 1;
		v.updated = 1;
		v.state_p = Ys::Task::_default_state_p;
	}
}

void LobbyPlayerMenuViewState::Close::Run(Ys::Task &t, ::Task *p, void *q, unsigned int n)
{
	LobbyPlayerMenuView &v = (LobbyPlayerMenuView &)t;
	v.Run_Common();
	Ys::Anim2D *a = &v.anim;
	if (bxAnmGetFrame(a->anm) >= bxAnmGetEndFrame(a->anm) - 1.0f) {
		v.task_p->f28 = 0;
		v.state_p = Ys::Task::_sleep_state_p;
	}
}

}


