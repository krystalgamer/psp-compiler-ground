/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_00101B98;
extern unsigned char D_00101BB8;
extern unsigned char D_00101BD4;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101B98);

int SoundGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_00101BB8, &D_00101B98, 0x10, "SoundGetNum", &D_00101BD4);
    }
    return M2C_FIELD(arg0, int *, 0x88);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BD4);

extern unsigned char D_00101BEC, D_00101C14;
int SoundSetTask(void *s, int idx, int task)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x13C) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x88)) {
			M2C_FIELD(s, int **, 0x13C)[idx] = task;
			return 1;
		}
		consPrintf(&D_00101C14, "SoundSetTask", idx);
		return 0;
	}
	consPrintf(&D_00101BEC, "SoundSetTask", idx);
	__asm__ volatile("sync\n\tbreak");
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101BEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/sound", D_00101C14);

extern unsigned char D_00101BEC, D_00101C14;
int SoundGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x13C) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x88))
			return M2C_FIELD(s, int **, 0x13C)[idx];
		consPrintf(&D_00101C14, "SoundGetTask", idx);
		return 0;
	}
	consPrintf(&D_00101BEC, "SoundGetTask", idx);
	return 0;
}

// return return keep
void *_memAllocZero(int, const void *, int);
int _memFree(void *, const void *, int);
int taskKill(void *, int, int);
int taskProc(void *, int, void *, int);
int taskDefaultMsg(void *, int, int, int);
void *resGetDatLocal(int, int);
void *resGetPtrTable(int, int);
int resGetSizeTable(int, int);
int scxPlay(void *, int, int);
int scxVolume(int, int, int);
int scxStop(int, int);
int scxState(int);
int gameGetGameMode(void);
int gameGetEntry(void);
typedef struct { int dat; int a; int b; int c; } StEnt;
typedef struct { int res; int idx; char pad8[0x20 - 8]; unsigned char prio; } StScr;
typedef struct { char pad[0x30]; StScr *scr; } StProg;
typedef struct {
	char pad0[0x10];
	StProg *prog;
	char pad14[0x24 - 0x14];
	unsigned char f24;
	char pad25[3];
	int f28;
	int f2C;
	StScr *scr;
	void *swork;
	void *dat;
	char pad3C[0x40 - 0x3C];
	int f40;
	int hdl;
} StTask;
#define cassert(e, l) if (!(e)) consPrintf(&D_00101BB8, &D_00101B98, l, "SoundTask", #e)
int SoundTask(StTask *Tp, unsigned int msg, int a, unsigned int arg)
{
	int ret = 0;
	StProg *Pp;
	StScr *Sp;
	void *SWp;
	int *tbl;
	StEnt *e;
	int r, n, h, m, k;
	int *p;
	void *d;
	switch (msg) {
	case 0:
		cassert(Tp, 0x58);
		Pp = Tp->prog;
		cassert(Pp, 0x5C);
		Tp->f28 = -1;
		Tp->f2C = 0x21;
		Tp->f40 = arg;
		Sp = Pp->scr;
		SWp = _memAllocZero(0x20, &D_00101B98, 0x65);
		cassert(SWp, 0x66);
		Tp->f24 = Sp->prio;
		Tp->swork = SWp;
		Tp->scr = Sp;
		SoundSetTask(Sp, arg, (int)Tp);
		r = Sp->res;
		tbl = resGetPtrTable(r, Sp->idx);
		n = (resGetSizeTable(r, tbl[5]) + 3) >> 2;
		if (arg < n) {
			p = resGetPtrTable(r, tbl[5]);
			k = arg * 4;
		} else {
			p = resGetPtrTable(0, 0);
			k = (arg - n) * 4;
			r = 0;
		}
		e = (StEnt *)(k * 4 + (int)p);
		d = resGetDatLocal(r, e->dat);
		h = scxPlay(d, e->a, e->b);
		Tp->dat = d;
		Tp->hdl = h;
		if (h < 0) {
			taskKill(Tp, 0, 0);
			return 0;
		}
		m = gameGetGameMode();
		if (m == 1 && gameGetEntry() == m && e->c == 0)
			scxVolume(h, 0, 0);
		return (int)Tp;
	case 4:
		taskProc(Tp, 0x8003, 0, 0);
		{
			int hh = Tp->hdl;
			Tp->hdl = -1;
			if (hh >= 0)
				scxStop(hh, 0);
		}
		SoundSetTask(Tp->scr, Tp->f40, 0);
		return (int)Tp;
	case 1:
		{
			void *w = Tp->swork;
			Tp->swork = NULL;
			_memFree(w, &D_00101B98, 0xA9);
		}
		return 0;
	case 2:
		r = taskProc(Tp, 0x8003, 0, 0);
		if (((r >> 4) & 1) | !r)
			taskKill(Tp, 0, 0);
		return 0;
	case 3:
		return 0;
	case 5:
		return 0;
	case 0x8003:
		if (Tp->hdl < 0) {
			return 0;
		}
		{
			int s = scxState(Tp->hdl);
			if (((s >> 4) & 1) | !s)
				Tp->hdl = -1;
			return s;
		}
	default:
		return taskDefaultMsg(Tp, msg, a, arg);
	}
	return ret;
}
