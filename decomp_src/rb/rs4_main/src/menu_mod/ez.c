/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include <stdarg.h>
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
int resGetDatLocal(int, int);                       /* extern */
int **ttrFontInitEx(int, int, void *, int, int, void *); /* extern */
extern unsigned char D_00102A88;
extern unsigned char D_00102AA4;
extern unsigned char D_00102E5C;

void taskKill();

int ttrFontTerm(int **arg0);
int AnmIsSuicide(void *arg0) {
    return (M2C_FIELD(arg0, int *, 0x40) & 3) == 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102A88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AA4);

extern unsigned char D_00102AC4;
void copUnitMat(void *);
void copInitAttr(void *);
void copLetMat(void *, void *);
int taskDefaultMsg(void *, int, void *, int);
void *bxAnmInitEx(void *, int);
void bxAnmTerm(void *);
int bxAnmExec(void *);
void bxAnmDraw(void *, void *, void *);
void bxAnmSetFrame(void *, float);
void bxAnmSetSpeed(void *, float);
float bxAnmGetEndFrame(void *);
void bxAnmSetLoop(void *, int);
typedef struct {
	int prio;
	int local;
	unsigned int f0 : 4;
	unsigned int res : 4;
	unsigned int pri : 8;
	unsigned int loop : 1;
	unsigned int stop : 1;
	unsigned int blend : 1;
	unsigned int add : 1;
	unsigned int pic : 1;
	unsigned int f21 : 11;
} EaArg;
typedef struct {
	char pad0[0x24];
	unsigned int f0 : 8;
	unsigned int blend : 2;
	unsigned int f10 : 22;
	char pad28[0x30 - 0x28];
} EaAttr;
typedef struct {
	char pad0[0x24];
	signed char f24;
	char pad25[3];
	int f28;
	int f2C;
	void *anm;
	char pad34[0x40 - 0x34];
	int flag;
	char pad44[0x60 - 0x44];
	EaAttr attr;
	char m0[0x40];
	char m1[0x40];
} EaTask;
int AnmIsSuicide(void *);
int ezAnmTask(EaTask *Tp, unsigned int msg, EaArg *p, int arg)
{
	void *a;
	switch (msg) {
	case 0:
		if (Tp == NULL)
			consPrintf(&D_00102A88, &D_00102AA4, 0x4C, "ezAnmTask", &D_00102AC4);
		Tp->f28 = -1;
		Tp->f24 = p ? p->pri : 0;
		Tp->f2C = p ? p->prio : 0;
		copUnitMat(Tp->m0);
		copUnitMat(Tp->m1);
		copInitAttr(&Tp->attr);
		Tp->attr.blend = p ? p->blend : 0;
		Tp->attr.blend = (p && p->add) ? 2 : Tp->attr.blend;
		Tp->anm = bxAnmInitEx((void *)resGetDatLocal(p ? p->res : 0, p ? p->local : 0), p ? p->pic : 0);
		Tp->flag = (p ? p->stop : 0) | (p ? p->loop : 0);
		return (int)Tp;
	case 4:
		bxAnmTerm(Tp->anm);
		Tp->anm = NULL;
		return (int)Tp;
	case 2:
		a = Tp->anm;
		if (bxAnmExec(a)) {
			if (AnmIsSuicide(Tp)) {
				taskKill(Tp, 0, 0);
				break;
			}
			if (Tp->flag & 2) {
				bxAnmSetFrame(a, bxAnmGetEndFrame(a));
				bxAnmSetSpeed(a, 0.0f);
				bxAnmSetLoop(a, 0);
				bxAnmExec(a);
			}
		}
		copLetMat(Tp->m0, Tp->m1);
		return 0;
	case 3:
		bxAnmDraw(Tp->anm, Tp->m1, &Tp->attr);
		return 0;
	case 0x5C:
		Tp->f28 = 0;
		return 0;
	case 0x5D:
		Tp->f28 = -1;
		return 0;
	case 0x5E:
		if (AnmIsSuicide(Tp)) {
			taskKill(Tp, 0, 0);
			return 1;
		}
		return 0;
	case 1:
		return 0;
	}
	return taskDefaultMsg(Tp, msg, p, arg);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AC4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezGimTask);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezMenuTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AE0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AF4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezScxTask);

int vsprintf(char *, const char *, va_list);
int *textASCIItoUCS4(char *);
int *ezSprintfAllocUCS4(const char *fmt, ...)
{
	char buf[0x200];
	va_list ap;
	int *r, *p;
	if (fmt == NULL)
		return NULL;
	memset(buf, 0, 0x200);
	va_start(ap, fmt);
	buf[0x1FF] = 0;
	vsprintf(buf, fmt, ap);
	r = textASCIItoUCS4(buf);
	for (p = r; *p != -1; p++)
		;
	*p = 0;
	return r;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezTtrWrite);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102E5C);

void ezTtrWrite2(void *arg0) {
    int **temp_v0;
    int temp_s1;

    temp_s1 = resGetDatLocal(M2C_FIELD(arg0, int *, 0), M2C_FIELD(arg0, int *, 4));
    temp_v0 = ttrFontInitEx(temp_s1, resGetDatLocal(M2C_FIELD(arg0, int *, 8), M2C_FIELD(arg0, int *, 0xC)), arg0 + 0x10, M2C_FIELD(arg0, int *, 0x54), M2C_FIELD(arg0, int *, 0x58), arg0 + 0x5C);
    if (temp_v0 == NULL) {
        consPrintf(&D_00102A88, &D_00102AA4, 0x2A9, "ezTtrWrite2", &D_00102E5C);
    }
    ttrFontTerm(temp_v0);
}

typedef struct {
	int f0;
	int f4;
	unsigned lo:4;
	unsigned prio:4;
	int pri:8;
	unsigned b16:1;
	unsigned b17:1;
	unsigned b18:1;
	unsigned b19:1;
	unsigned ent:1;
	unsigned rest:11;
	int fC, f10, f14, f18;
} AnmPrm;
int taskMake(int, void (*)(), void *, int);
int gameGetEntry(void);
int ezAnmTask();
void ezTtrWrite(int, int, unsigned char *, int);
void ezInfoWinInit(int parent, int *pt, unsigned char *name, int x, int pri)
{
	AnmPrm q;
	AnmPrm p;
	int t = pt != NULL ? *pt : 0;
	if (t != 0)
		taskKill(t, 0, 0);
	ezTtrWrite(1, 0x56, name, x);
	memset(&p, 0, sizeof(p));
	p.prio = 1;
	p.f4 = 0x5A;
	p.pri = pri;
	p.b16 = 1;
	p.ent = gameGetEntry();
	q = p;
	t = taskMake(parent, ezAnmTask, &q, 0);
	if (pt != NULL)
		*pt = t;
}

void ezInfoWinTerm(int a, int *p)
{
	if (p) {
		int t = *p;
		*p = 0;
		if (t)
			taskKill(t, 0, 0);
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezWriteCardResultEfc);
