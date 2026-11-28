/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
extern unsigned char D_00103564;
extern unsigned char D_0010357C;
typedef struct { int type; int local; int ref; int fC; int f10; } RefEnt;
typedef struct { unsigned char kind; unsigned char sub; unsigned short no; } RefCard;
extern void (*l_apfnRef2Card[])(RefCard *, int);
extern unsigned char D_001035D0, D_0010369C;
int taskMake();
int refloadReleaseTask();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_00103564);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_0010357C);

int refloadReleaseAll2(int inst, int arg, RefEnt *tbl, int n);
int refloadSetRef2CardFunc(int arg0) {
    if (arg0 >= 5) {
        consPrintf(&D_0010357C, &D_00103564, 0x1B, "refloadSetRef2CardFunc", "Inst < Inst_Num");
    }
    return 1;
}

extern unsigned char D_001035EC, D_0010362C;
int refloadReadTask();
int refloadGetLocal(int inst, int ref, RefEnt *tbl, int n)
{
	int i, t;
	RefCard card;
	if (ref < 0 || n < 1) return -4;
	t = ref & 0x83000000;
	if (t == 0x2000000 || t == 0x3000000) return -4;
	if (t == 0x1000000) return ref - t;
	for (i = 0; i < n; i++) {
		if (ref == tbl[i].ref) {
			if (tbl[i].f10) tbl[i].f10 = 0;
			return tbl[i].local;
		}
	}
	for (i = 0; i < n; i++) {
		if (tbl[i].fC == ref) return -1;
	}
	for (i = 0; i < n; i++) {
		if (tbl[i].ref == -1 && tbl[i].fC == -1 && tbl[i].f10 == 0) {
			void (*fn)(RefCard *, int) = l_apfnRef2Card[tbl[i].type];
			if (fn) {
				fn(&card, ref);
				consPrintf(&D_001035EC, "refloadGetLocal", inst, tbl, card.no, card.kind);
			}
			tbl[i].fC = ref;
			if (taskMake(inst, refloadReadTask, &tbl[i], 0) == 0) {
				consPrintf(&D_001035D0, "refloadGetLocal");
				return -4;
			}
			return -1;
		}
	}
	consPrintf(&D_0010362C, "refloadGetLocal", tbl, ref);
	return -2;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001035D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_001035EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_0010362C);

int refloadKeepLocal(int inst, int ref, RefEnt *tbl, int n)
{
	int i, t;
	if (ref < 0 || n < 1) return -4;
	t = ref & 0x83000000;
	if (t == 0x2000000 || t == 0x3000000) return -4;
	if (t == 0x1000000) return ref - t;
	for (i = 0; i < n; i++) {
		if (ref == tbl[i].ref) {
			if (tbl[i].f10) tbl[i].f10 = 0;
			return tbl[i].local;
		}
	}
	consPrintf("%s : Not found\n", "refloadKeepLocal");
	return -3;
}

int refloadReleaseRefer(int inst, int ref, RefEnt *tbl, int n)
{
	int i, t;
	RefEnt *e;
	RefCard card;
	if (ref < 0 || n < 1) return 0;
	t = ref & 0x83000000;
	if (t == 0x2000000 || t == 0x3000000) return 0;
	if (t == 0x1000000) return 0;
	for (i = 0; i < n; i++) {
		if (ref == tbl[i].ref) {
			if (tbl[i].f10 != 0) return 1;
			if (l_apfnRef2Card[tbl[i].type]) {
				l_apfnRef2Card[tbl[i].type](&card, ref);
				consPrintf(&D_0010369C, "refloadReleaseRefer", inst, tbl, card.no, card.kind);
			}
			if (taskMake(inst, refloadReleaseTask, &tbl[i], 0) == 0) {
				consPrintf(&D_001035D0, "refloadReleaseRefer");
				return -4;
			}
			return 1;
		}
		if (tbl[i].fC >= 0) {
			tbl[i].f10 = 1;
			return -1;
		}
	}
	return -3;
}

void refloadReleaseAll(int a, int b, int c)
{
	refloadReleaseAll2(a, 1, b, c);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/refload", D_0010369C);

int refloadReleaseAll2(int inst, int arg, RefEnt *tbl, int n)
{
	int i;
	int rel = 0;
	int busy = 0;
	RefCard card;
	if (n <= 0) return 0;
	for (i = 0; i < n; i++) {
		if (tbl[i].ref >= 0) {
			if (l_apfnRef2Card[tbl[i].type]) {
				l_apfnRef2Card[tbl[i].type](&card, tbl[i].ref);
				consPrintf(&D_0010369C, "refloadReleaseAll2", inst, tbl, card.no, card.kind);
			}
			if (taskMake(inst, refloadReleaseTask, &tbl[i], arg) == 0)
				consPrintf(&D_001035D0, "refloadReleaseAll2");
			else
				rel++;
		}
		if (tbl[i].fC >= 0) {
			tbl[i].f10 = 1;
			busy++;
		}
	}
	if (busy)
		consPrintf("%s :: Warning :: %d Loadings are not completed yet.\n", "refloadReleaseAll2", busy);
	consPrintf("%s : %d resources release\n", "refloadReleaseAll2", rel);
	return rel;
}

void copUnitMat(void *);
void copInitAttr(void *);
void copLetMat(void *, void *);
int taskKill(void *, int, int);
int taskProc(void *, int, int, int);
int taskDefaultMsg(void *, int, void *, int);
int resReleaseRefer(int, int);
int resReadReferThr(int, int, int, int);
int mainGetThrBack(void);
int thrState(int);
void drawPrintf(const char *, ...);
typedef struct {
	char pad0[0x28];
	int f28;
	int f2C;
	RefEnt *ent;
	char pad34[0x40 - 0x34];
	int st;
	char pad44[0x60 - 0x44];
	char attr[0x30];
	char m0[0x40];
	char m1[0x40];
} RdTask;
#define cassert(e, l) if (!(e)) consPrintf(&D_0010357C, &D_00103564, l, "refloadReadTask", #e)
int refloadReadTask(RdTask *Tp, unsigned int msg, RefEnt *a, int arg)
{
	RefEnt *e;
	switch (msg) {
	case 0:
		cassert(Tp, 0xF1);
		Tp->f28 = -1;
		Tp->f2C = 0;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(Tp->attr);
		Tp->ent = a;
		Tp->st = 0;
		taskProc(Tp, 2, 0, 0);
		return (int)Tp;
	case 4:
		{
		RefEnt *p = Tp->ent;
		if (p->fC >= 0) {
			consPrintf("%s :: Warning :: Loading is not completed yet.\n", "refloadReadTask");
			resReleaseRefer(p->type, p->local);
			p->fC = -1;
		}
		if (p->f10) {
			consPrintf("%s :: Warning :: Release is not completed yet.\n", "refloadReadTask");
			resReleaseRefer(p->type, p->local);
			p->f10 = 0;
		}
		}
		return (int)Tp;
	case 2:
		e = Tp->ent;
		switch (Tp->st) {
		case 0:
			if (resReadReferThr(mainGetThrBack(), e->type, e->fC, e->local) == 0) {
				Tp->st = 1;
				consPrintf("%s : read card start %d->%d\n", "refloadReadTask", e->fC, e->local);
			}
			break;
		case 1:
			{
				int thr = mainGetThrBack();
				drawPrintf("read card... %d->%d\n", e->fC, e->local);
				if (thrState(thr) == 0) {
					Tp->st = 2;
					return taskProc(Tp, 2, 0, 0);
				}
			}
			break;
		case 2:
			consPrintf("%s : read card success %d->%d\n", "refloadReadTask", e->fC, e->local);
			if (e->f10) {
				consPrintf("%s : load canceled\n", "refloadReadTask");
				resReleaseRefer(e->type, e->local);
				e->f10 = 0;
			} else {
				e->ref = e->fC;
			}
			e->fC = -1;
			taskKill(Tp, 0, 0);
			break;
		}
		copLetMat(Tp->m0, Tp->m1);
		return 0;
	case 1:
		return 0;
	case 3:
		return 0;
	case 5:
		return 0;
	case 0x5F:
		return 1;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}

void copUnitMat(void *);
void copInitAttr(void *);
void copLetMat(void *, void *);
int taskKill(void *, int, int);
int taskDefaultMsg(void *, int, void *, int);
int resReleaseRefer(int, int);
typedef struct {
	char pad0[0x28];
	int f28;
	int f2C;
	RefEnt *ent;
	char pad34[0x40 - 0x34];
	int st;
	int cnt;
	char pad48[0x60 - 0x48];
	char attr[0x30];
	char m0[0x40];
	char m1[0x40];
} RrTask;
int refloadReleaseTask(RrTask *Tp, unsigned int msg, RefEnt *a, int arg)
{
	RefEnt *e;
	switch (msg) {
	case 0:
		if (Tp == NULL)
			consPrintf(&D_0010357C, &D_00103564, 0x174, "refloadReleaseTask", "Tp");
		Tp->f28 = -1;
		Tp->f2C = 0;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(Tp->attr);
		Tp->cnt = 5;
		Tp->st = 0;
		Tp->ent = a;
		a->f10 = 1;
		if (arg)
			taskKill(Tp, 0, arg);
		return (int)Tp;
	case 4:
		e = Tp->ent;
		if (e->f10) {
			resReleaseRefer(e->type, e->local);
			e->f10 = 0;
			e->ref = -1;
			e->fC = -1;
		}
		return (int)Tp;
	case 2:
		if (Tp->ent->f10 == 0) {
			consPrintf("%s : Release canceled\n", "refloadReleaseTask");
			taskKill(Tp, 0, 0);
			break;
		}
		switch (Tp->st) {
		case 0:
			if (Tp->cnt > 0)
				Tp->cnt--;
			if (Tp->cnt == 0)
				Tp->st = 1;
			break;
		case 1:
			taskKill(Tp, 0, 0);
			break;
		}
		copLetMat(Tp->m0, Tp->m1);
		return 0;
	case 1:
	case 3:
	case 5:
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
