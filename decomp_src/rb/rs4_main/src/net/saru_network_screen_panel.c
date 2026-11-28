/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct tagTtrFontCntx;
struct InstDat;

extern "C" {
InstDat *resGetDatLocal(int a, int b);
}

namespace Saru {
struct PlayerName;
}

namespace Ys {
class Task {
public:
	void *task_p;
	void *state_p;
	virtual ~Task();
};

class ScreenPanel : public Task {
public:
	char _c[0x54];
	tagTtrFontCntx *font_p;
	bool opened : 1;
	bool suspend : 1;
	unsigned int _flags : 30;
	ScreenPanel *Init(tagTtrFontCntx &f, Task *parent);
	static tagTtrFontCntx *Create_TextContext(InstDat &d, char *s, int n, unsigned int **pp);
	void Wakeup_NormalTask();
};

class Cancel_ScreenPanel : public ScreenPanel {
public:
	Cancel_ScreenPanel *Init(tagTtrFontCntx &f, bool b, Task *parent);
};

class MenuScreenPanel2 : public ScreenPanel {
public:
	MenuScreenPanel2 *Init(tagTtrFontCntx &f, tagTtrFontCntx &f0, tagTtrFontCntx &f1, int se, Task *parent);
	static tagTtrFontCntx *Create_ItemContext0(InstDat &d, char *s, int n, unsigned int **pp);
	static tagTtrFontCntx *Create_ItemContext1(InstDat &d, char *s, int n, unsigned int **pp);
};

class YesNo_ScreenPanel : public MenuScreenPanel2 {
public:
	YesNo_ScreenPanel *Init(tagTtrFontCntx &f, int se, Task *parent);
};

class ScreenPanelDaemon {
public:
	static ScreenPanelDaemon *_instance_p;
	ScreenPanel &Add_Panel(ScreenPanel &p);
};
}

namespace SaruNet {
namespace ScreenPanel {

class Panel : public Ys::ScreenPanel {
public:
	Panel *Init(tagTtrFontCntx &f, Ys::Task *parent);
	static tagTtrFontCntx *Create_TextContext(char *s, int n, unsigned int **pp);
};

class CancelPanel : public Ys::Cancel_ScreenPanel {
public:
	CancelPanel *Init(tagTtrFontCntx &f, Ys::Task *parent);
};

class MenuPanel2 : public Ys::MenuScreenPanel2 {
public:
	MenuPanel2 *Init(tagTtrFontCntx &f, tagTtrFontCntx &f0, tagTtrFontCntx &f1, int se, Ys::Task *parent);
	static tagTtrFontCntx *Create_ItemContext0(char *s, int n, unsigned int **pp);
	static tagTtrFontCntx *Create_ItemContext1(char *s, int n, unsigned int **pp);
};

class YesNo_Panel : public Ys::YesNo_ScreenPanel {
public:
	YesNo_Panel *Init(tagTtrFontCntx &f, int se, Ys::Task *parent);
};

class Connecting : public Panel {
public:
	Panel *Init(Ys::Task *parent);
};

class Error : public CancelPanel {
public:
	CancelPanel *Init(Ys::Task *parent);
};

class Error_ConfirmRetry : public YesNo_Panel {
public:
	YesNo_Panel *Init(int se, Ys::Task *parent);
};

class Error_WLanOff : public CancelPanel {
public:
	CancelPanel *Init(Ys::Task *parent);
};

class Error_WLanOff_Startup : public CancelPanel {
public:
	CancelPanel *Init(Ys::Task *parent);
};

#define CANCEL_PANEL(C) \
class C : public CancelPanel { \
public: \
	C *Init(Ys::Task *parent); \
};
#define CANCEL_PANEL_NAME(C) \
class C : public CancelPanel { \
public: \
	C *Init(Saru::PlayerName &name, Ys::Task *parent); \
};

CANCEL_PANEL(Reject_Match)
CANCEL_PANEL_NAME(Wait_ReplyRequestResult)
CANCEL_PANEL(Missing_Card)
CANCEL_PANEL(Reject_Trade)
CANCEL_PANEL_NAME(Wait_ReplyTradeRequestResult)

class Confirm_Trade_WaiWai : public YesNo_Panel {
public:
	Confirm_Trade_WaiWai *Init(Saru::PlayerName &name, Ys::Task *parent);
};

class Confirm_TradeCard_WaiWai : public YesNo_Panel {
public:
	Confirm_TradeCard_WaiWai *Init(Saru::PlayerName &name, Ys::Task *parent);
};

class Wait_FinishTrade_WaiWai : public Panel {
public:
	Wait_FinishTrade_WaiWai *Init(Saru::PlayerName &name, Ys::Task *parent);
};

Panel *Panel::Init(tagTtrFontCntx &f, Ys::Task *parent)
{
	Ys::ScreenPanel::Init(f, parent);
	Ys::ScreenPanelDaemon::_instance_p->Add_Panel(*this);
	return this;
}

tagTtrFontCntx *Panel::Create_TextContext(char *s, int n, unsigned int **pp)
{
	return Ys::ScreenPanel::Create_TextContext(*resGetDatLocal(1, 5), s, n, pp);
}

CancelPanel *CancelPanel::Init(tagTtrFontCntx &f, Ys::Task *parent)
{
	Ys::Cancel_ScreenPanel::Init(f, parent, 0);
	Ys::ScreenPanelDaemon::_instance_p->Add_Panel(*this);
	return this;
}

MenuPanel2 *MenuPanel2::Init(tagTtrFontCntx &f, tagTtrFontCntx &f0, tagTtrFontCntx &f1, int se, Ys::Task *parent)
{
	Ys::MenuScreenPanel2::Init(f, f0, f1, se, parent);
	Ys::ScreenPanelDaemon::_instance_p->Add_Panel(*this);
	return this;
}

tagTtrFontCntx *MenuPanel2::Create_ItemContext0(char *s, int n, unsigned int **pp)
{
	return Ys::MenuScreenPanel2::Create_ItemContext0(*resGetDatLocal(1, 5), s, n, pp);
}

tagTtrFontCntx *MenuPanel2::Create_ItemContext1(char *s, int n, unsigned int **pp)
{
	return Ys::MenuScreenPanel2::Create_ItemContext1(*resGetDatLocal(1, 5), s, n, pp);
}

YesNo_Panel *YesNo_Panel::Init(tagTtrFontCntx &f, int se, Ys::Task *parent)
{
	Ys::YesNo_ScreenPanel::Init(f, se, parent);
	Ys::ScreenPanelDaemon::_instance_p->Add_Panel(*this);
	return this;
}

Panel *Connecting::Init(Ys::Task *parent)
{
	Panel *p = Panel::Init(*Create_TextContext("MENU_TEXT_25", 0, 0), parent);
	suspend = 0;
	return p;
}

CancelPanel *Error::Init(Ys::Task *parent)
{
	return CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_27", 0, 0), parent);
}

YesNo_Panel *Error_ConfirmRetry::Init(int se, Ys::Task *parent)
{
	return YesNo_Panel::Init(*Panel::Create_TextContext("MENU_TEXT_26", 0, 0), se, parent);
}

CancelPanel *Error_WLanOff::Init(Ys::Task *parent)
{
	return CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_28", 0, 0), parent);
}

CancelPanel *Error_WLanOff_Startup::Init(Ys::Task *parent)
{
	return CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_30", 0, 0), parent);
}

Reject_Match *Reject_Match::Init(Ys::Task *parent)
{
	CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_39", 0, 0), parent);
	Wakeup_NormalTask();
	return this;
}

Wait_ReplyRequestResult *Wait_ReplyRequestResult::Init(Saru::PlayerName &name, Ys::Task *parent)
{
	unsigned int *arg[1] = { (unsigned int *)&name };
	CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_37", 1, arg), parent);
	Wakeup_NormalTask();
	return this;
}

Missing_Card *Missing_Card::Init(Ys::Task *parent)
{
	CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_190", 0, 0), parent);
	Wakeup_NormalTask();
	return this;
}

Reject_Trade *Reject_Trade::Init(Ys::Task *parent)
{
	CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_36", 0, 0), parent);
	Wakeup_NormalTask();
	return this;
}

Wait_ReplyTradeRequestResult *Wait_ReplyTradeRequestResult::Init(Saru::PlayerName &name, Ys::Task *parent)
{
	unsigned int *arg[1] = { (unsigned int *)&name };
	CancelPanel::Init(*Panel::Create_TextContext("MENU_TEXT_34", 1, arg), parent);
	Wakeup_NormalTask();
	return this;
}

Confirm_Trade_WaiWai *Confirm_Trade_WaiWai::Init(Saru::PlayerName &name, Ys::Task *parent)
{
	unsigned int *arg[1] = { (unsigned int *)&name };
	YesNo_Panel::Init(*Panel::Create_TextContext("MENU_TEXT_35", 1, arg), 3, parent);
	Wakeup_NormalTask();
	return this;
}

Confirm_TradeCard_WaiWai *Confirm_TradeCard_WaiWai::Init(Saru::PlayerName &name, Ys::Task *parent)
{
	unsigned int *arg[1] = { (unsigned int *)&name };
	YesNo_Panel::Init(*Panel::Create_TextContext("MENU_TEXT_54", 1, arg), 3, parent);
	Wakeup_NormalTask();
	return this;
}

Wait_FinishTrade_WaiWai *Wait_FinishTrade_WaiWai::Init(Saru::PlayerName &name, Ys::Task *parent)
{
	unsigned int *arg[1] = { (unsigned int *)&name };
	Panel::Init(*Create_TextContext("MENU_TEXT_141", 1, arg), parent);
	suspend = 0;
	return this;
}

}
}


