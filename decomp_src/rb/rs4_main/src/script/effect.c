/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FF2BC;
extern unsigned char D_000FF2E0;
extern unsigned char D_000FF2FC;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2BC);

int EffectGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF2E0, &D_000FF2BC, 0x22, "EffectGetNum", &D_000FF2FC);
    }
    return M2C_FIELD(arg0, int *, 0x8C);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF2FC);

extern unsigned char D_000FF314, D_000FF33C;
int EffectSetTask(void *s, int idx, int task)
{
	if (s == NULL || M2C_FIELD(s, int **, 0x140) == NULL) {
		consPrintf(&D_000FF314, "EffectSetTask", idx);
		return 0;
	}
	if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x8C)) {
		M2C_FIELD(s, int **, 0x140)[idx] = task;
		return 1;
	}
	consPrintf(&D_000FF33C, "EffectSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF314);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/effect", D_000FF33C);

extern unsigned char D_000FF314, D_000FF33C;
int EffectGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x140) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x8C))
			return M2C_FIELD(s, int **, 0x140)[idx];
		consPrintf(&D_000FF33C, "EffectGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FF314, "EffectGetTask", idx);
	return 0;
}

void *_memAllocZero(int, const void *, int);
void *_memAlloc(int, const void *, int);
int _memFree(void *, const void *, int);
void copUnitMat(void *);
void copInitAttr(void *);
int taskKill(void *, int, int);
int taskDefaultMsg(void *, int, int, int);
void *resGetDatLocal(int, int);
void *resGetPtrTable(int, int);
void *bxAnmInit(void *);
void bxAnmTerm(void *);
int bxAnmExec(void *);
void bxAnmDraw(void *, void *, void *);
typedef struct { int res; int idx; char pad8[0x60 - 8]; unsigned char prio; } EtScr;
typedef struct { char pad[0x30]; EtScr *scr; } EtProg;
typedef struct { void *anm; } EtWork;
typedef struct {
	char pad0[0x10];
	EtProg *prog;
	char pad14[0x24 - 0x14];
	unsigned char f24;
	char pad25[3];
	int f28;
	int f2C;
	EtScr *scr;
	void *swork;
	void *work;
	char pad3C[0x40 - 0x3C];
	int f40;
	char pad44[0x60 - 0x44];
	char attr[0x30];
	char m0[0x40];
	char m1[0x40];
} EtTask;
#define cassert(e, l) if (!(e)) consPrintf(&D_000FF2E0, &D_000FF2BC, l, "EffectTask", #e)
int EffectTask(EtTask *Tp, unsigned int msg, int a, int arg)
{
	EtProg *Pp;
	EtScr *Sp;
	void *SWp;
	EtWork *EWp;
	void *pAnm;
	int r;
	switch (msg) {
	case 0:
		cassert(Tp, 0x5C);
		Pp = Tp->prog;
		cassert(Pp, 0x60);
		Tp->f28 = -1;
		Tp->f2C = 0x21;
		Tp->f40 = arg;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(Tp->attr);
		Sp = Pp->scr;
		SWp = _memAllocZero(0x20, &D_000FF2BC, 0x6F);
		cassert(SWp, 0x70);
		Tp->f24 = Sp->prio + 13;
		Tp->swork = SWp;
		Tp->scr = Sp;
		EffectSetTask(Sp, arg, (int)Tp);
		EWp = _memAlloc(4, &D_000FF2BC, 0x7A);
		cassert(EWp, 0x7B);
		Tp->work = EWp;
		r = Sp->res;
		pAnm = bxAnmInit(resGetDatLocal(r, ((int *)resGetPtrTable(r, ((int *)resGetPtrTable(r, Sp->idx))[6]))[arg]));
		cassert(pAnm, 0x84);
		EWp->anm = pAnm;
		return (int)Tp;
	case 4:
		EffectSetTask(Tp->scr, Tp->f40, 0);
		return (int)Tp;
	case 1:
		{
			void *w = Tp->swork;
			Tp->swork = NULL;
			_memFree(w, &D_000FF2BC, 0x99);
		}
		{
			EtWork *e = (EtWork *)Tp->work;
			void *m;
			m = e->anm;
			Tp->work = NULL;
			e->anm = NULL;
			bxAnmTerm(m);
			_memFree(e, &D_000FF2BC, 0xA4);
		}
		return 0;
	case 2:
		if (bxAnmExec(((EtWork *)Tp->work)->anm))
			taskKill(Tp, 0, 0);
		return 0;
	case 3:
		bxAnmDraw(((EtWork *)Tp->work)->anm, Tp->m1, Tp->attr);
		return 0;
	case 5:
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
