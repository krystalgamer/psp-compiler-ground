/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
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
	void *_0;
	::Task *task_p;
};

struct CardAnimArg {
	int a;
	void *ref;
	int _8;
	void *b;
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

namespace Ys {
CardAnim::CardAnim(TCardAttr &attr, int a, tagTtrFontCntx *f, int b, Task *parent)
{
	font_p = f;
	dead = 0;
	CardAnimArg arg;
	memset(&arg, 0, sizeof(arg));
	arg.a = a;
	arg.ref = ref = cardanmGetCard2Ref(&attr);
	arg.b = (void *)b;
	arg._10 = 0;
	task_p = taskMake(parent ? parent->task_p : 0, (void *)cardanmTask, &arg, 0);
}
}

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


