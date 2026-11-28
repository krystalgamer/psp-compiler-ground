/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FF7F4;
extern unsigned char D_000FF81C;
extern unsigned char D_000FF838;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF7F4);

int ProgramGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FF81C, &D_000FF7F4, 0x16, "ProgramGetNum", &D_000FF838);
    }
    return M2C_FIELD(arg0, int *, 0x94);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF81C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF838);

extern unsigned char D_000FF850, D_000FF878;
int ProgramSetTask(void *s, int idx, int task)
{
	if (s == NULL || M2C_FIELD(s, int **, 0x148) == NULL) {
		consPrintf(&D_000FF850, "ProgramSetTask", idx);
		return 0;
	}
	if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x94)) {
		M2C_FIELD(s, int **, 0x148)[idx] = task;
		return 1;
	}
	consPrintf(&D_000FF878, "ProgramSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF850);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/program", D_000FF878);

extern unsigned char D_000FF850, D_000FF878;
int ProgramGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x148) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x94))
			return M2C_FIELD(s, int **, 0x148)[idx];
		consPrintf(&D_000FF878, "ProgramGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FF850, "ProgramGetTask", idx);
	return 0;
}

#ifndef FALSE
#define FALSE 0
#endif
typedef struct { char pad[0x38]; int mode; } PtGame;
PtGame *gameGetCntx(void);
int taskMake(void *, int (*)(), int, int);
int taskKill(void *, int, int);
int taskDefaultMsg(void *, int, int, int);
void copUnitMat(void *);
void copInitAttr(void *);
void *_memAllocZero(int, const void *, int);
int _memFree(void *, const void *, int);
int ProgFrameIn(), ProgFrameOut(), ProgWipeOut(), ProgName();
typedef struct { char pad[0x30]; void *f30; } PtProg;
typedef struct {
	char pad0[0x10];
	PtProg *prog;
	char pad14[0x28 - 0x14];
	int f28;
	int f2C;
	void *f30;
	void *work;
	char pad38[0x40 - 0x38];
	int f40;
	char pad44[0x60 - 0x44];
	char attr[0x30];
	char m0[0x40];
	char m1[0x40];
} PtTask;
#define cassert(e, l) if (!(e)) consPrintf(&D_000FF81C, &D_000FF7F4, l, "ProgramTask", #e)
void *ProgramTask(PtTask *Tp, int msg, int a, int arg)
{
	PtProg *Pp;
	void *SWp;
	void *Sp;
	int (*f)();
	switch (msg) {
	case 0:
		cassert(Tp, 0x53);
		Pp = Tp->prog;
		cassert(Pp, 0x58);
		Tp->f28 = -1;
		Tp->f2C = 0x21;
		Tp->f40 = arg;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(Tp->attr);
		Sp = Pp->f30;
		SWp = _memAllocZero(0x20, &D_000FF7F4, 0x67);
		cassert(SWp, 0x68);
		Tp->work = SWp;
		Tp->f30 = Sp;
		ProgramSetTask(Sp, arg, (int)Tp);
		switch ((unsigned)arg) {
		default:
			cassert(FALSE, 0x73);
			break;
		case 0:
			taskMake(Tp, ProgFrameIn, 0, a);
			break;
		case 1:
			switch (gameGetCntx()->mode) {
			default:
				taskKill(Tp, 0, 0);
				return NULL;
			case 7:
				taskMake(Tp, ProgFrameOut, 0, a);
				break;
			case 9:
				taskMake(Tp, ProgWipeOut, 0, a);
				break;
			}
			break;
		case 2:
			taskMake(Tp, ProgName, 0, a);
			break;
		}
		return Tp;
	case 4:
		ProgramSetTask(Tp->f30, Tp->f40, 0);
		return Tp;
	case 1:
		{
			void *w = Tp->work;
			Tp->work = NULL;
			_memFree(w, &D_000FF7F4, 0xA1);
		}
		return NULL;
	case 2:
	case 3:
	case 5:
		return NULL;
	case 8:
		taskKill(Tp, a, arg);
		return NULL;
	}
	return (void *)taskDefaultMsg(Tp, msg, a, arg);
}
