/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "../minmax.h"
#include "m2c_macros.h"
int semaInit(M2C_UNK *);                            /* extern */
extern unsigned char CtrlInfoT;
extern unsigned char CtrlRingBuf;
extern int CtrlSema;
extern signed char D_000F9C44;
extern unsigned char D_000F9C48;
extern unsigned char D_000F9C7C;
int semaTerm(int);                                  /* extern */
M2C_UNK semaLock(int);                              /* extern */
M2C_UNK semaUnlock(int);                            /* extern */
extern int CtrlSuspend;
extern int CtrlVirtualType;
int ctrlFlushCtrlData(int);                         /* extern */
int ctrlFlushVirtualData(unsigned int);                      /* extern */

void consPrintf(const char *, ...);
extern unsigned char CtrlInfo;
extern unsigned char D_000F9C50;
extern unsigned char D_000F9C6C;
extern unsigned char D_000F9DDC;
extern unsigned char D_000F9DE8;
extern unsigned char CtrlInfoV;
extern unsigned char D_000F9D0C;
extern unsigned char D_000F9DF0;
extern unsigned char D_000F9DFC;
                            /* extern */

typedef struct {
	unsigned int now, trg, rel, old, rpt, hold, raw;
	int cnt;
} CtrlTrg;

extern int CtrlEnter;

extern int CtrlCancel;

#ifndef NULL
#define NULL ((void *)0)
#endif
int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlSetSamplingMode(int mode);
void *memset(void *s, int c, unsigned int n);
enum { CTRL_PORT_NUM = 1 };
typedef struct { char pad[8]; signed char x, y; char pad2[6]; } CtrlVEnt;
typedef struct { char hdr[16]; CtrlVEnt ent[128]; } CtrlRing;

int ctrlInit(void) {
    M2C_UNK *temp_s0;
    int temp_v0;

    temp_s0 = "ctrlInit";
    consPrintf(&D_000F9C44, temp_s0);
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(1);
    memset(&CtrlInfo, 0, 0xA0U);
    memset(&CtrlInfoV, 0, 0x140U);
    memset(&CtrlInfoT, 0, 0x140U);
    memset(&CtrlRingBuf, 0, 0x1020U);
    temp_v0 = semaInit(&D_000F9C48);
    CtrlSema = temp_v0;
    if (temp_v0 <= 0) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0x71, temp_s0, &D_000F9C7C);
    }
    return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C7C);

#ifndef NULL
#define NULL ((void *)0)
#endif

int ctrlTerm(void) {
    M2C_UNK *temp_s0;

    temp_s0 = "ctrlTerm";
    consPrintf(&D_000F9C44, temp_s0);
    if (semaTerm(CtrlSema) != 1) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0x80, temp_s0, "Ret == TRUE");
    }
    CtrlSema = -1;
    return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ctrlLock(void) {
    if (CtrlSema > 0) {
        semaLock(CtrlSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void ctrlUnlock(void) {
    if (CtrlSema > 0) {
        semaUnlock(CtrlSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ctrlSuspend(int arg0) {
    int temp_v0;

    temp_v0 = CtrlSuspend;
    CtrlSuspend = arg0;
    return temp_v0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ctrlSetVirtualType(int arg0) {
    int temp_s1;

    temp_s1 = CtrlVirtualType;
    if (arg0 < 0) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0xB4, "ctrlSetVirtualType", "Type >= CtrlVirtualType_Exclusive");
    }
    if (arg0 >= 4) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0xB5, "ctrlSetVirtualType", "Type < CtrlVirtualType_Num");
    }
    CtrlVirtualType = arg0;
    return temp_s1;
}

typedef struct { char pad[0x90]; CtrlVEnt v; } CtrlInfoEnt;
int ctrlFlushCtrlData(int n)
{
	CtrlInfoEnt *c = &((CtrlInfoEnt *)&CtrlInfo)[n];
	CtrlVEnt *v;
	memset(c, 0, sizeof(CtrlInfoEnt));
	v = &c->v;
	v->x = -128;
	v->y = -128;
	return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ctrlFlushCtrlDataAll(void)
{
	int r = 0;
	unsigned int i;
	for (i = 0; i < CTRL_PORT_NUM; i++)
		r |= ctrlFlushCtrlData(i);
	return r;
}

int ctrlFlushVirtualData(unsigned int n)
{
	CtrlRing *r;
	CtrlVEnt *e;
	unsigned int i;
	char *q;
	ctrlLock();
	r = &((CtrlRing *)&CtrlRingBuf)[n];
	memset(r, 0, sizeof(CtrlRing));
	for (i = 0; i < 128; i++) {
		q = (char *)(i * sizeof(CtrlVEnt));
		q += (int)r;
		e = ((CtrlRing *)q)->ent;
		e->x = -128;
		e->y = -128;
	}
	ctrlUnlock();
	return 1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int ctrlFlushVirtualDataAll(void) {
    int var_s1;
    unsigned int temp_a0;
    unsigned int var_s0;

    var_s1 = 0;
    var_s0 = 0;
    do {
        temp_a0 = var_s0;
        var_s0 += 1;
        var_s1 |= ctrlFlushVirtualData(temp_a0);
    } while (var_s0 < 2U);
    return var_s1;
}

typedef struct { int d[4]; } CtrlVData;
typedef struct { int top; int num; int pad[2]; CtrlVData data[128]; } CtrlVRing;
#define CtrlRingV ((CtrlVRing *)&CtrlRingBuf)
extern unsigned char D_000F9D14, D_000F9D2C, D_000F9D34;
void ctrlLock(void);
void ctrlUnlock(void);
int ctrlSetVirtualData(int port, CtrlVData *pData, int num)
{
	CtrlVRing *r;
	int top, cnt, rest, pos, i;

	if (CtrlVirtualType != 3)
		return 0;
	ctrlLock();
	if (port < 0)
		consPrintf(&D_000F9C50, &D_000F9C6C, 0x107, "ctrlSetVirtualData", &D_000F9D0C);
	if (port >= 2)
		consPrintf(&D_000F9C50, &D_000F9C6C, 0x108, "ctrlSetVirtualData", &D_000F9D14);
	if (pData == NULL)
		consPrintf(&D_000F9C50, &D_000F9C6C, 0x109, "ctrlSetVirtualData", &D_000F9D2C);
	if (num > 0) {
		r = &CtrlRingV[port];
		cnt = r->num;
		pos = r->top;
		rest = 128 - cnt;
		i = 0;
		if (rest < num) {
			consPrintf(&D_000F9D34, "ctrlSetVirtualData");
			ctrlUnlock();
			return 0;
		}
		pos += cnt;
		if (pos >= 128)
			pos -= 128;
		num = amin(num, rest);
		for (; num != 0; num--) {
			r->data[pos] = pData[i];
			pos++;
			if (pos >= 128)
				pos = 0;
			i++;
		}
		r->num = cnt + i;
	}
	ctrlUnlock();
	return 1;
}

void ctrlTrgProc(CtrlTrg *c)
{
	unsigned int now, old, chg, trg, rel, hold, rpt;
	int cnt;

	old = c->now;
	now = c->raw;
	hold = c->hold;
	cnt = c->cnt;
	trg = now ^ old;
	rel = trg & old;
	trg &= now;
	rpt = 0;
	if (rel & hold) hold = 0;
	if (trg) { hold = trg; cnt = 12; rpt = hold; } else if (hold) { if (--cnt == 0) { cnt = 2; rpt = hold; } }
	c->now = now;
	c->trg = trg;
	c->rel = rel;
	c->rpt = rpt;
	c->hold = hold;
	c->old = old;
	c->cnt = cnt;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9D0C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9D14);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9D2C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9D34);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9D6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9D78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9D80);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9DAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9DDC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9DE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9DF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9DFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E14);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlMake);

void ctrlMake();
void ctrlMakeV(void *c)
{
	((signed char *)c)[0x98] = -128;
	((signed char *)c)[0x99] = -128;
	ctrlMake(c);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlUpdate);

void *ctrlState(int arg0) {
    if (arg0 != 0) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0x2C0, &D_000F9DDC, &D_000F9DE8);
    }
    return (arg0 * 0xA0) + &CtrlInfo;
}

void *ctrlStateV(int arg0) {
    if (arg0 < 0) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0x2CA, &D_000F9DF0, &D_000F9D0C);
    }
    if ((unsigned int) arg0 >= 2U) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0x2CB, &D_000F9DF0, &D_000F9DFC);
    }
    return (arg0 * 0xA0) + &CtrlInfoV;
}

extern unsigned char D_000F9E14, D_000F9D78;
void _ctrlSetTrg(unsigned int key, unsigned int *trg)
{
	switch (key) {
	case 0x400:
		*trg = 0x100;
		break;
	default:
		consPrintf(&D_000F9C50, &D_000F9C6C, 0x2D8, &D_000F9E14, &D_000F9D78);
		break;
	case 0x800:
		*trg = 0x200;
		break;
	case 0x1:
	case 0x8:
	case 0x10:
	case 0x20:
	case 0x40:
	case 0x80:
	case 0x1000:
	case 0x2000:
	case 0x4000:
	case 0x8000:
		*trg = key;
		break;
	}
}

int ctrlSetEnter(int key)
{
	_ctrlSetTrg(key, &CtrlEnter);
	return 1;
}

int ctrlSetCancel(int key)
{
	_ctrlSetTrg(key, &CtrlCancel);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E30);
