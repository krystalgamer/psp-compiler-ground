/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-merge-constants -fno-exceptions */
/* #pragma interface: the vtables, typeinfo and implicit destructors stay in the module's asm */
#pragma interface "rodata"
#include "common.h"

struct Task;
struct InstDat;
struct tagTtrFontCntx;
struct TCardAttr;

extern "C" {
void _memFree(void *p, const char *file, int line);
void *memset(void *, int, unsigned long);
Task *taskMake(Task *parent, void *func, void *arg, unsigned int n);
int taskProc(Task *t, int msg, void *p, void *q);
void cardanmTask();
void *cardanmGetCard2Ref(TCardAttr *a);
void ttrFontTerm(tagTtrFontCntx *f);
tagTtrFontCntx *ttrFontInit(InstDat *res, InstDat *inst, char *s, int n, unsigned int **pp);
InstDat *resGetDatLocal(int a, int b);
void consPrintf(const char *fmt, ...);
}

#define cassert(e) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/ys/ys_card_anim.cc", __LINE__, __FUNCTION__, #e)

namespace Ys {
class Object {
public:
	static void operator delete(void *p) { _memFree(p, "src/ys/ys_object.h", 25); }
};

class Task {
public:
	::Task *task_p;
};

struct CardAnimArg {
	tagTtrFontCntx *font;
	void *ref;
	int _8;
	int b;
	int _10;
};

class CardAnim : public Object {
public:
	::Task *task_p;
	tagTtrFontCntx *font_p;
	void *ref;
	bool dead;
	CardAnim(TCardAttr &attr, int a, tagTtrFontCntx *f, int b, Task *parent);
	virtual ~CardAnim();
	bool Destroy();
	static tagTtrFontCntx *Create_TextContext(InstDat &d, char *s, int n, unsigned int **pp);
};

}

extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_card_anim", _ZN2Ys8CardAnimC2ER9TCardAttriP14tagTtrFontCntxiPNS_4TaskE); }
extern "C" { INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_card_anim", _ZN2Ys8CardAnimC1ER9TCardAttriP14tagTtrFontCntxiPNS_4TaskE); }

namespace Ys {

CardAnim::~CardAnim()
{
	dead = 1;
	if (task_p) {
		int result = taskProc(task_p, 0x61, 0, ref);
#line 78
		cassert(result);
	}
	if (font_p)
		ttrFontTerm(font_p);
}

bool CardAnim::Destroy()
{
	bool r = taskProc(task_p, 0x61, 0, ref) != 0;
	if (r) {
		task_p = 0;
		delete this;
	}
	return r;
}

tagTtrFontCntx *CardAnim::Create_TextContext(InstDat &d, char *s, int n, unsigned int **pp)
{
	return ttrFontInit(resGetDatLocal(1, 0x56), &d, s, n, pp);
}

}


extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_card_anim", _ZTVN2Ys8CardAnimE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_card_anim", D_00104BF0); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_card_anim", _ZTIN2Ys8CardAnimE); }
extern "C" { INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_card_anim", _ZTSN2Ys8CardAnimE); }
