/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FF3AC;
extern unsigned char D_000FF3CC;
extern unsigned char D_000FF3E8;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3AC);

int EventGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF3CC, &D_000FF3AC, 0xF, "EventGetNum", &D_000FF3E8);
    }
    return M2C_FIELD(arg0, int *, 0x54);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF3E8);

extern unsigned char D_000FF400, D_000FF428;
int EventSetTask(void *s, int idx, int task)
{
	if (s == NULL || M2C_FIELD(s, int **, 0x134) == NULL) {
		consPrintf(&D_000FF400, "EventSetTask", idx);
		return 0;
	}
	if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x54)) {
		M2C_FIELD(s, int **, 0x134)[idx] = task;
		return 1;
	}
	consPrintf(&D_000FF428, "EventSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF400);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/event", D_000FF428);

extern unsigned char D_000FF400, D_000FF428;
int EventGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x134) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x54))
			return M2C_FIELD(s, int **, 0x134)[idx];
		consPrintf(&D_000FF428, "EventGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FF400, "EventGetTask", idx);
	return 0;
}

void *_memAllocZero(int, const void *, int);
int _memFree(void *, const void *, int);
int taskKill(void *, int, int);
int taskProc(void *, int, int, int);
int taskDefaultMsg(void *, unsigned int, int, int);
int sceKernelGetGPI();
void drawPrintf(const char *, ...);
int SequenceExec(void *, int, unsigned int, float);
typedef struct { int a; int b; } EvSeq;
typedef struct { char pad0[0x10]; unsigned char prio; char pad11[0x4C - 0x11]; EvSeq *seq; } EvScr;
typedef struct { char pad[0x30]; EvScr *scr; } EvProg;
typedef struct {
	char pad0[0x10];
	EvProg *prog;
	char pad14[0x24 - 0x14];
	unsigned char f24;
	char pad25[3];
	int f28;
	int f2C;
	EvScr *scr;
	int *swork;
	char pad38[0x40 - 0x38];
	union { int arg; struct { unsigned short evt; short actor; } s; } u;
} EvTask;
#define cassert(e, l) if (!(e)) consPrintf(&D_000FF3CC, &D_000FF3AC, l, "EventTask", #e)
int EventTask(EvTask *Tp, unsigned int msg, int a, int arg)
{
	EvProg *Pp;
	EvScr *Sp;
	int *SWp;
	switch (msg) {
	case 0:
	{
		unsigned short ev;
		cassert(Tp, 0x51);
		Pp = Tp->prog;
		cassert(Pp, 0x57);
		Tp->f28 = -1;
		Tp->u.arg = arg;
		ev = arg;
		Tp->f2C = 0x21;
		Sp = Pp->scr;
		SWp = _memAllocZero(0x20, &D_000FF3AC, 0x63);
		cassert(SWp, 0x64);
		Tp->f24 = Sp->prio;
		Tp->swork = SWp;
		Tp->scr = Sp;
		EventSetTask(Sp, ev, (int)Tp);
		return (int)Tp;
	}
	case 4:
		EventSetTask(Tp->scr, Tp->u.s.evt, 0);
		return (int)Tp;
	case 1:
		{
			void *w = Tp->swork;
			Tp->swork = NULL;
			_memFree(w, &D_000FF3AC, 0x7E);
		}
		return 0;
	case 2:
		{
		int evt, actor;
		float t;
		int *SWp;
		EvScr *Sc;
		evt = Tp->u.s.evt;
		actor = Tp->u.s.actor;
		SWp = Tp->swork;
		if ((signed char)sceKernelGetGPI() < 0)
			drawPrintf("%s : Event %d : Actor %d : ", "EventTask", evt, actor);
		if (SWp[3] != 0 || SWp[4] != 0) {
			if ((signed char)sceKernelGetGPI() < 0)
				drawPrintf("w\n");
			return 0;
		}
		if (SWp[0] == 0) {
			Sc = Tp->scr;
			SWp[5] = 0;
			t = *(float *)&SWp[5];
			SequenceExec(Tp, Sc->seq[evt].a, actor, t);
			if (*(float *)&SWp[5] != t) {
				SWp[0] = Sc->seq[evt].b;
				if ((signed char)sceKernelGetGPI() < 0)
					drawPrintf("o\n");
			} else {
				if ((signed char)sceKernelGetGPI() < 0)
					drawPrintf("x\n");
				return 0;
			}
		} else {
			if ((signed char)sceKernelGetGPI() < 0)
				drawPrintf("-\n");
		}
		SWp[0] = SequenceExec(Tp, SWp[0], actor, 0.0f);
		}
		return 0;
	case 3:
		return 0;
	case 5:
		return 0;
	case 8:
		{
		int *w = Tp->swork;
		if (w[3] != 0 && w[3] == a) {
			w[3] = 0;
			taskProc(Tp, 2, 0, 0);
		}
		}
		return 0;
	default:
		{
		int *w = Tp->swork;
		if (w[3] != 0 && w[3] == a && w[4] != 0 && w[4] == msg) {
			w[3] = 0;
			w[4] = 0;
			taskProc(Tp, 2, 0, 0);
			return 0;
		}
		}
		break;
	case 0x62:
		if (arg == Tp->u.s.actor)
			taskKill(Tp, 0, 0);
		return 0;
	}
	return taskDefaultMsg(Tp, msg, a, arg);
}
