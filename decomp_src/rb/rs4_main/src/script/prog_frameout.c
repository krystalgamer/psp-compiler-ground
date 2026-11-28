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
int gameGetWinner(void);
int gameGetHandicap(void);
int gameGetGameMode(void);
int gameGetEntry(void);
int scxPlay(void *, int, int);
extern int D_00112440[];
typedef struct {
	char pad0[0x24];
	unsigned int b0 : 8;
	unsigned int blend : 2;
	unsigned int b10 : 22;
	char pad28[0x30 - 0x28];
} PfoAttr;
typedef struct {
	void *anm0;
	char pad4[0xC];
	PfoAttr attr0;
	void *anm1;
	char pad44[0xC];
	PfoAttr attr1;
} PfoWork;
typedef struct {
	char pad0[0x10];
	void *prog;
	char pad14[0x24 - 0x14];
	signed char f24;
	char pad25[3];
	int f28;
	int f2C;
	PfoWork *work;
	char pad34[0x40 - 0x34];
	int f40;
	char pad44[0x60 - 0x44];
	PfoAttr attr;
	char m0[0x40];
	char m1[0x40];
} PfoTask;

#define cassert(e, l) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/script/prog_frameout.c", l, "ProgFrameOut", #e)

int ProgFrameOut(PfoTask *Tp, unsigned int msg, void *a, int arg)
{
	PfoWork *Wp;
	void *Pp;
	void *anm;
	int idx;
	int m;
	switch (msg) {
	case 0:
		cassert(Tp, 0x2F);
		Pp = Tp->prog;
		cassert(Pp, 0x35);
		Tp->f28 = -1;
		Tp->f24 = -0x40;
		Tp->f2C = 0x21;
		Tp->f40 = arg;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(&Tp->attr);
		cassert(gameGetWinner() >= 0, 0x43);
		cassert(gameGetWinner() <= 1, 0x44);
		Wp = _memAllocZero(0x80, "src/script/prog_frameout.c", 0x47);
		cassert(Wp, 0x48);
		Tp->work = Wp;
		idx = gameGetHandicap() + (gameGetWinner() == gameGetHandicap()) * 2;
		anm = bxAnmInit(resGetDatLocal(2, 0x16D));
		Wp->anm1 = bxAnmInit(resGetDatLocal(2, D_00112440[idx]));
		Wp->anm0 = anm;
		copInitAttr(&Wp->attr0);
		copInitAttr(&Wp->attr1);
		Wp->attr0.blend = 1;
		bxAnmSetLoop(anm, 0);
		m = gameGetGameMode();
		if (m != 1 || gameGetEntry() != m)
			scxPlay(resGetDatLocal(0, 2), 2, 0);
		return (int)Tp;
	case 4:
		return (int)Tp;
	case 1:
		{
			PfoWork *w = Tp->work;
			Tp->work = NULL;
			if (w->anm0) bxAnmTerm(w->anm0);
			if (w->anm1) bxAnmTerm(w->anm1);
			_memFree(w, "src/script/prog_frameout.c", 0x77);
		}
		return 0;
	case 2:
		{
			PfoWork *w = Tp->work;
			if (bxAnmExec(w->anm0)) taskKill(Tp, 0, 0);
			bxAnmExec(w->anm1);
			copLetMat(Tp->m0, Tp->m1);
		}
		return 0;
	case 3:
		{
			PfoWork *w = Tp->work;
			bxAnmDraw(w->anm0, Tp->m1, &w->attr0);
			bxAnmDraw(w->anm1, Tp->m1, &w->attr1);
		}
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
