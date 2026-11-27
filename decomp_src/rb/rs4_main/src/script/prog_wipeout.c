/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

void consPrintf(const char *, ...);
void *_memAllocZero(int, const char *, int);
int _memFree(void *, const char *, int);
void copUnitMat(void *);
void copInitAttr(void *);
void copLetMat(void *, void *);
int taskKill(void *, int, int);
int taskDefaultMsg(void *, int, void *, int);
void *resGetDatLocal(int, int);
void *bxAnmInit(void *);
void bxAnmSetLoop(void *, int);
void bxAnmTerm(void *);
int bxAnmExec(void *);
void bxAnmDraw(void *, void *, void *);

typedef struct { void *anm; } WipeWork;
typedef struct {
	char pad0[0x10];
	void *prog;
	char pad14[0x24 - 0x14];
	signed char f24;
	char pad25[3];
	int f28;
	int f2C;
	WipeWork *work;
	char pad34[0x40 - 0x34];
	int f40;
	char pad44[0x60 - 0x44];
	char attr[0x30];
	char m0[0x40];
	char m1[0x40];
} WipeTask;

#define cassert(e, l) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/script/prog_wipeout.c", l, "ProgWipeOut", #e)

int ProgWipeOut(WipeTask *Tp, int msg, void *a, int arg)
{
	WipeWork *Wp;
	void *Pp;
	switch (msg) {
	case 0:
		cassert(Tp, 0x27);
		Pp = Tp->prog;
		cassert(Pp, 0x2D);
		Tp->f28 = -1;
		Tp->f24 = -0x40;
		Tp->f2C = 0x21;
		Tp->f40 = arg;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(Tp->attr);
		Wp = _memAllocZero(4, "src/script/prog_wipeout.c", 0x3C);
		cassert(Wp, 0x3D);
		Tp->work = Wp;
		Wp->anm = bxAnmInit(resGetDatLocal(2, 0x7E));
		bxAnmSetLoop(Wp->anm, 0);
		return (int)Tp;
	case 4:
		return (int)Tp;
	case 1:
		Wp = Tp->work;
		Tp->work = NULL;
		if (Wp->anm) bxAnmTerm(Wp->anm);
		_memFree(Wp, "src/script/prog_wipeout.c", 0x56);
		return 0;
	case 2:
		if (bxAnmExec(Tp->work->anm)) taskKill(Tp, 0, 0);
		copLetMat(Tp->m0, Tp->m1);
		return 0;
	case 3:
		bxAnmDraw(Tp->work->anm, Tp->m1, Tp->attr);
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
