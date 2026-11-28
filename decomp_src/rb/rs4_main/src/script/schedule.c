/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FF8F0;
extern unsigned char D_000FF918;
extern unsigned char D_000FF934;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FF8F0);

int ScheduleGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF918, &D_000FF8F0, 0xF, "ScheduleGetNum", &D_000FF934);
    }
    return M2C_FIELD(arg0, int *, 0x48);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FF918);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FF934);

extern unsigned char D_000FF94C, D_000FF974;
int ScheduleSetTask(void *s, int idx, int task)
{
	if (s == NULL || M2C_FIELD(s, int **, 0x138) == NULL) {
		consPrintf(&D_000FF94C, "ScheduleSetTask", idx);
		return 0;
	}
	if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x48)) {
		M2C_FIELD(s, int **, 0x138)[idx] = task;
		return 1;
	}
	consPrintf(&D_000FF974, "ScheduleSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FF94C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FF974);

extern unsigned char D_000FF94C, D_000FF974;
int ScheduleGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x138) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x48))
			return M2C_FIELD(s, int **, 0x138)[idx];
		consPrintf(&D_000FF974, "ScheduleGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FF94C, "ScheduleGetTask", idx);
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
extern const float D_000FF9EC;
typedef struct {
	unsigned int w0a : 16;
	unsigned int ref : 1;
	unsigned int w0b : 15;
	unsigned int w1a : 5;
	unsigned int idx : 5;
	int ofs : 10;
	int ofs2 : 10;
	unsigned int w1b : 2;
} ScVar;
float SequenceGetVariableFlt(void *, int, ScVar *, int);
typedef union {
	float time;
	struct {
		unsigned int idx : 5;
		int ofs : 10;
		int ofs2 : 10;
		unsigned int pad : 6;
		int var : 1;
	} v;
	int w;
} ScTime;
typedef struct { ScTime t; int seq; } ScItem;
typedef struct { ScItem *items; int n; } ScList;
typedef struct { char pad0[0x1C]; unsigned char prio; char pad1D[0x40 - 0x1D]; ScList *list; } ScScr;
typedef struct { char pad[0x30]; ScScr *scr; } ScProg;
typedef struct { int seq; int f4; int f8; int fC; int f10; int f14; float time; int idx; } ScWork;
typedef struct {
	char pad0[0x10];
	ScProg *prog;
	char pad14[0x24 - 0x14];
	unsigned char f24;
	char pad25[3];
	int f28;
	int f2C;
	ScScr *scr;
	ScWork *swork;
	char pad38[0x40 - 0x38];
	union { int arg; struct { unsigned short sched; short actor; } s; } u;
} ScTask;
#define cassert(e, l) if (!(e)) consPrintf(&D_000FF918, &D_000FF8F0, l, "ScheduleTask", #e)
int ScheduleTask(ScTask *Tp, unsigned int msg, int a, int arg)
{
	ScProg *Pp;
	ScScr *Sp;
	ScWork *SWp;
	switch (msg) {
	case 0:
	{
		unsigned short ev;
		cassert(Tp, 0x52);
		Pp = Tp->prog;
		cassert(Pp, 0x58);
		Tp->f28 = -1;
		Tp->u.arg = arg;
		ev = arg;
		Tp->f2C = 0x21;
		Sp = Pp->scr;
		SWp = _memAllocZero(0x20, &D_000FF8F0, 0x64);
		cassert(SWp, 0x65);
		Tp->f24 = Sp->prio;
		Tp->swork = SWp;
		Tp->scr = Sp;
		ScheduleSetTask(Sp, ev, (int)Tp);
		return (int)Tp;
	}
	case 4:
		ScheduleSetTask(Tp->scr, Tp->u.s.sched, 0);
		return (int)Tp;
	case 1:
		{
			void *w = Tp->swork;
			Tp->swork = NULL;
			_memFree(w, &D_000FF8F0, 0x7F);
		}
		return 0;
	case 2:
		{
		int sched, actor;
		ScWork *SWp;
		ScList *l;
		SWp = Tp->swork;
		sched = Tp->u.s.sched;
		actor = Tp->u.s.actor;
		SWp->time += D_000FF9EC;
		if (sceKernelGetGPI() & 0x20)
			drawPrintf("%s : Schedule %d : Actor %d : Time %f\n", "ScheduleTask", sched, actor, SWp->time);
		if (SWp->fC != 0)
			return 0;
		if (SWp->f10 != 0)
			return 0;
		l = &Tp->scr->list[sched];
		if (SWp->seq != 0)
			goto exec;
		do {
			ScItem *it;
			float t;
			if (SWp->idx >= l->n)
				break;
			it = &l->items[SWp->idx];
			if (it->t.v.var) {
				ScVar var;
				var.ref = 0;
				var.idx = it->t.v.idx;
				var.ofs = it->t.v.ofs;
				var.ofs2 = it->t.v.ofs2;
				t = SequenceGetVariableFlt(Tp, 0, &var, 0);
			} else {
				t = it->t.time;
			}
			if (!(t <= SWp->time))
				return 0;
			SWp->seq = it->seq;
			SWp->idx++;
		exec:
			SWp->seq = SequenceExec(Tp, SWp->seq, actor, SWp->time);
			if (SWp->seq == 0 && SWp->idx >= l->n) {
				taskKill(Tp, 0, 0);
				return 0;
			}
		} while (SWp->seq == 0);
		}
		return 0;
	case 3:
		return 0;
	case 5:
		return 0;
	case 8:
		{
		ScWork *w = Tp->swork;
		if (w->fC != 0 && w->fC == a) {
			w->fC = 0;
			taskProc(Tp, 2, 0, 0);
		}
		}
		return 0;
	default:
		{
		ScWork *w = Tp->swork;
		if (w->fC != 0 && w->fC == a && w->f10 != 0 && w->f10 == msg) {
			w->fC = 0;
			w->f10 = 0;
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

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FF9EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FF9F0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA00);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA0C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA34);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA70);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFA98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFABC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFACC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAD4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFADC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFAFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB20);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB28);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB70);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB80);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFB9C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBBC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBC4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBD0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBD4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBDC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC04);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC0C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC24);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC34);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC84);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFC9C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCB0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCBC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCD0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCD8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFCF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD0C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD7C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD84);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFD9C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFDA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFDB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFDC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFDDC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFDF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE80);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFE98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFEA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFEB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFEC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFEDC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFEF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFF08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFF1C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFF30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFF48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFF60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFF74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFF88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFFA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFFB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFFCC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFFE4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFFEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_000FFFF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_0010000C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_00100020);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_00100034);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_00100048);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_0010005C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_00100064);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_0010006C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_00100074);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_0010007C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_00100088);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_00100098);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_001000A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_001000B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_001000B8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_001000C0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_001000C8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_001000D0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/schedule", D_001000D8);
