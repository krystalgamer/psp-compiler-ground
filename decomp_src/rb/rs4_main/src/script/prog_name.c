/* cflags: -Os -fno-strength-reduce */
#include "common.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
int _memFree(void *, const char *, int);
void copUnitMat(void *);
void copInitAttr(void *);
void copLetMat(void *, void *);
int taskDefaultMsg(void *, int, void *, int);
void bxAnmTerm(void *);
int bxAnmExec(void *);
void bxAnmDraw(void *, void *, void *);
typedef struct { char pad[0x38]; int mode; } PnGame;
PnGame *gameGetCntx(void);
typedef struct { char pad[0xD0]; char m1[0x40]; } PnActor;
typedef struct { PnActor *actor; void *anm; } PnWork;
typedef struct {
	char pad0[0x10];
	void *prog;
	char pad14[0x24 - 0x14];
	signed char f24;
	char pad25[3];
	int f28;
	int f2C;
	PnWork *work;
	char pad34[0x40 - 0x34];
	int f40;
	char pad44[0x50 - 0x44];
	float x;
	float y;
	char pad58[0x60 - 0x58];
	char attr[0x24];
	unsigned int f84;
	char pad88[0x90 - 0x88];
	char m0[0x40];
	float m1[4][4];
} PnTask;
PnWork *_ProgName_InitGame(PnTask *, void *, int);
PnWork *_ProgName_InitTgs(PnTask *, void *, int);

#define cassert(e, l) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/script/prog_name.c", l, "ProgName", #e)

int ProgName(PnTask *Tp, unsigned int msg, void *a, int arg)
{
	PnWork *Wp;
	void *Pp;
	switch (msg) {
	case 0:
		cassert(Tp, 0x30);
		Pp = Tp->prog;
		cassert(Pp, 0x36);
		Tp->f28 = -1;
		Tp->f24 = -0x80;
		Tp->f2C = 0x21;
		Tp->f40 = arg;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(Tp->attr);
		Tp->f84 |= 0x400;
		if (gameGetCntx()->mode != 9)
			Wp = _ProgName_InitGame(Tp, a, arg);
		else
			Wp = _ProgName_InitTgs(Tp, a, arg);
		cassert(Wp, 0x55);
		Tp->work = Wp;
		return (int)Tp;
	case 4:
		return (int)Tp;
	case 1:
		{
			PnWork *w = Tp->work;
			Tp->work = NULL;
			if (w->anm) bxAnmTerm(w->anm);
			_memFree(w, "src/script/prog_name.c", 0x67);
		}
		return 0;
	case 2:
		{
			PnWork *w = Tp->work;
			bxAnmExec(w->anm);
			copLetMat(w->actor->m1, Tp->m1);
		}
		Tp->m1[3][1] += Tp->x;
		Tp->m1[3][2] += Tp->y;
		return 0;
	case 3:
		bxAnmDraw(Tp->work->anm, Tp->m1, Tp->attr);
		return 0;
	case 0x8001:
		Tp->x = (unsigned int)arg;
		return 0;
	case 0x8002:
		Tp->y = (unsigned int)arg;
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
