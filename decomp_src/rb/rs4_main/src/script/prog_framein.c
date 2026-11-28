/* cflags: -Os -fno-strength-reduce */
#include "common.h"

#ifndef NULL
#define NULL ((void *)0)
#endif
#ifndef FALSE
#define FALSE 0
#endif
void consPrintf(const char *, ...);
int _memFree(void *, const char *, int);
void copUnitMat(void *);
void copInitAttr(void *);
void copLetMat(void *, void *);
int taskMake(void *, int (*)(), int, int);
int taskKill(void *, int, int);
int taskDefaultMsg(void *, int, void *, int);
int taskHeadAlive(void);
void *rsvNextAlive(void *);
void bxAnmTerm(void *);
int bxAnmExec(void *);
void bxAnmDraw(void *, void *, void *);
int gameGetGameMode(void);
typedef struct { char pad[0x38]; int mode; } PfiGame;
PfiGame *gameGetCntx(void);
void *SaruNet_PetitGame_NetworkTask__Get_Instance_p(void);
int i3dTask_EzDraw();
int Script_Net();
typedef struct { void *anm0; void *anm1; void *anm2; } PfiWork;
PfiWork *_ProgFrameIn_InitGame(void);
PfiWork *_ProgFrameIn_InitTgs(void);
typedef struct { char pad[8]; int (*func)(); } PfiAlive;
typedef struct {
	char pad0[0x10];
	void *prog;
	char pad14[0x24 - 0x14];
	signed char f24;
	char pad25[3];
	int f28;
	int f2C;
	PfiWork *work;
	void *net;
	char pad38[0x40 - 0x38];
	int f40;
	int st;
	int cnt;
	char pad4C[0x60 - 0x4C];
	char attr[0x30];
	char m0[0x40];
	char m1[0x40];
} PfiTask;

#define cassert(e, l) if (!(e)) consPrintf("cassert : %s %d : %s : %s\n", "src/script/prog_framein.c", l, "ProgFrameIn", #e)

int ProgFrameIn(PfiTask *Tp, unsigned int msg, void *a, int arg)
{
	PfiWork *Wp;
	void *Pp;
	PfiAlive *t;
	switch (msg) {
	case 0:
		cassert(Tp, 0x33);
		Pp = Tp->prog;
		cassert(Pp, 0x39);
		Tp->f28 = -1;
		Tp->f24 = -0x40;
		Tp->f2C = 0x21;
		Tp->f40 = arg;
		Tp->st = 0;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(Tp->attr);
		for (t = (PfiAlive *)taskHeadAlive(); t; t = rsvNextAlive(t))
			if (t->func == i3dTask_EzDraw)
				break;
		if (t == NULL)
			taskMake(Tp, i3dTask_EzDraw, 0, 0);
		if (gameGetCntx()->mode != 9)
			Wp = _ProgFrameIn_InitGame();
		else
			Wp = _ProgFrameIn_InitTgs();
		cassert(Wp, 0x60);
		Tp->work = Wp;
		return (int)Tp;
	case 4:
		return (int)Tp;
	case 1:
		{
			PfiWork *w = Tp->work;
			Tp->work = NULL;
			if (w->anm0) bxAnmTerm(w->anm0);
			if (w->anm1) bxAnmTerm(w->anm1);
			if (w->anm2) bxAnmTerm(w->anm2);
			_memFree(w, "src/script/prog_framein.c", 0x74);
		}
		return 0;
	case 2:
		switch (Tp->st) {
		default:
			cassert(FALSE, 0x7C);
			break;
		case 0:
			{
				PfiWork *w = Tp->work;
				if (bxAnmExec(w->anm1)) {
					if (gameGetGameMode() == 2) {
						Tp->cnt = 5;
						Tp->st = 1;
						Tp->f28 = 0;
					} else
						taskKill(Tp, 0, 0);
				} else {
					bxAnmExec(w->anm2);
					bxAnmExec(w->anm0);
					copLetMat(Tp->m0, Tp->m1);
				}
			}
			break;
		case 1:
			if (--Tp->cnt == 0) {
				Tp->st = 2;
				taskMake(Tp, Script_Net, 0, 0x8000);
			}
			break;
		case 2:
			break;
		case 3:
			taskKill(Tp, 0, 0);
			break;
		}
		return 0;
	case 3:
		{
			PfiWork *w = Tp->work;
			bxAnmDraw(w->anm1, Tp->m1, Tp->attr);
			bxAnmDraw(w->anm2, Tp->m1, Tp->attr);
			bxAnmDraw(w->anm0, Tp->m1, Tp->attr);
		}
		return 0;
	case 0x8000:
		Tp->net = SaruNet_PetitGame_NetworkTask__Get_Instance_p();
		Tp->st = 3;
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
