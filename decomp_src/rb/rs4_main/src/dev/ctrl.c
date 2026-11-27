/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C6C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9C7C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlTerm);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlLock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlUnlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlSuspend);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlSetVirtualType);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlFlushCtrlData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlFlushCtrlDataAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlFlushVirtualData);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlFlushVirtualDataAll);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlSetVirtualData);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", ctrlMakeV);

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

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", _ctrlSetTrg);

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
