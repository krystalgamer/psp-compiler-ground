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

int AnmIsSuicide(void *arg0) {
    return (M2C_FIELD(arg0, int *, 0x40) & 3) == 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102A88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", D_00102AA4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/ez", ezAnmTask);

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
void ezAnmTask();
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
