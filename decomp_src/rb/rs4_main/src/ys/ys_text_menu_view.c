/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
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
float bxAnmGetFrame(bxAnm *a);
float bxAnmGetEndFrame(bxAnm *a);
}

namespace Ys {
namespace Cop {
struct Matrix4x4 {
	float m[4][4];
};
}

class TaskState;

class Task {
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
};

class TaskState {
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

class TextMenuView : public MenuView {
public:
	short loop;
	short open_anim;
	short close_anim;
	short unfocus_anim;
	const short *select_anim;
	tagTtrFontCntx *const *font;
	char _24[0xC];
	Anim2D anim;
	static TaskState *_state_table_p;
	TextMenuView *Init(Task *parent, int n, int sel, int lp, int op, int cl, int uf, const short *tbl, tagTtrFontCntx *const *f);
	virtual void Open(int n);
	virtual void Close();
	bool Set_Focus(bool f);
	int ForceSet_Select(int n);
	virtual int Set_Select(int n);
	void Run_Common();
	virtual void Receive_RunMessage(::Task *t, void *p, unsigned int n);
	virtual void Receive_DrawMessage(::Task *t, void *p, unsigned int n);
};

namespace TextMenuViewState {
class Open : public TaskState {
public:
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
};
class Close : public TaskState {
public:
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
};
class Unfocus : public TaskState {
public:
	virtual void Run(Task &t, ::Task *p, void *q, unsigned int n);
};
}

TextMenuView *TextMenuView::Init(Task *parent, int n, int sel, int lp, int op, int cl, int uf, const short *tbl, tagTtrFontCntx *const *f)
{
	select_anim = tbl;
	font = f;
	loop = lp;
	open_anim = op;
	close_anim = cl;
	unfocus_anim = uf;
	MenuView::Init(parent, n, sel);
	return this;
}

void TextMenuView::Open(int n)
{
	int op = open_anim;
	active = op < 0;
	if (!active) {
		anim.Load(op, loop);
		state_p = &_state_table_p[0];
	} else {
		state_p = _default_state_p;
	}
	task_p->f28 = -1;
	anim.visible = 1;
	select = n - 1;
	Set_Select(n);
}

void TextMenuView::Close()
{
	Anim2D *a = &anim;
	if (close_anim >= 0) {
		a->Load(close_anim, loop);
		state_p = &_state_table_p[1];
	} else {
		task_p->f28 = 0;
		a->visible = 0;
		state_p = _sleep_state_p;
	}
	active = 0;
}

bool TextMenuView::Set_Focus(bool f)
{
	if ((state_p != &_state_table_p[2]) != f) {
		active = f;
		if (f) {
			ForceSet_Select(select);
			state_p = _default_state_p;
		} else {
			if (unfocus_anim >= 0)
				anim.Load(unfocus_anim, loop);
			state_p = &_state_table_p[2];
		}
	}
	return f;
}

int TextMenuView::ForceSet_Select(int n)
{
	anim.Load(select_anim[n], loop);
	return select = n;
}

int TextMenuView::Set_Select(int n)
{
	if (select == n)
		return n;
	if (active)
		return ForceSet_Select(n);
	return select = n;
}

void TextMenuView::Run_Common()
{
	int n = count;
	for (int i = 0; i < n; i++)
		ttrFontUpdate(font[i], &task_p->mD0.y, task_p->attr);
}

void TextMenuView::Receive_RunMessage(::Task *t, void *p, unsigned int n)
{
	Run_Common();
	if (task_p->f28)
		anim.Exec();
}

void TextMenuView::Receive_DrawMessage(::Task *t, void *p, unsigned int n)
{
	anim.Draw(*(Cop::Matrix4x4 *)&task_p->mD0);
}

void TextMenuViewState::Open::Run(Task &t, ::Task *p, void *q, unsigned int n)
{
	TextMenuView &v = (TextMenuView &)t;
	v.Run_Common();
	Anim2D *a = &v.anim;
	a->Exec();
	if (bxAnmGetFrame(a->anm) >= bxAnmGetEndFrame(a->anm) - 1.0f) {
		v.active = 1;
		v.ForceSet_Select(v.select);
		v.state_p = Task::_default_state_p;
	}
}

void TextMenuViewState::Close::Run(Task &t, ::Task *p, void *q, unsigned int n)
{
	TextMenuView &v = (TextMenuView &)t;
	v.Run_Common();
	Anim2D *a = &v.anim;
	a->Exec();
	if (bxAnmGetFrame(a->anm) >= bxAnmGetEndFrame(a->anm) - 1.0f) {
		v.task_p->f28 = 0;
		a->visible = 0;
		v.state_p = Task::_sleep_state_p;
	}
}

void TextMenuViewState::Unfocus::Run(Task &t, ::Task *p, void *q, unsigned int n)
{
	((TextMenuView &)t).Run_Common();
}

}


extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys17TextMenuViewState4OpenD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys17TextMenuViewState4OpenD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys17TextMenuViewState5CloseD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys17TextMenuViewState5CloseD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys17TextMenuViewState7UnfocusD0Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys17TextMenuViewState7UnfocusD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys12TextMenuViewD1Ev); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZN2Ys12TextMenuViewD0Ev); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTVN2Ys17TextMenuViewState7UnfocusE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", D_00105398); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTVN2Ys17TextMenuViewState5CloseE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", D_001053C0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTVN2Ys17TextMenuViewState4OpenE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", D_001053E8); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTVN2Ys12TextMenuViewE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", D_00105410); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", D_00105440); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTIN2Ys17TextMenuViewState4OpenE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTIN2Ys17TextMenuViewState5CloseE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTIN2Ys17TextMenuViewState7UnfocusE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTIN2Ys12TextMenuViewE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTSN2Ys12TextMenuViewE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTSN2Ys17TextMenuViewState7UnfocusE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTSN2Ys17TextMenuViewState5CloseE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_text_menu_view", _ZTSN2Ys17TextMenuViewState4OpenE); }
