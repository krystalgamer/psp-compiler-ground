/* cflags: -Os */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK consPrintf(M2C_UNK *, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern unsigned char CtrlInfo;
extern unsigned char D_000F9C50;
extern unsigned char D_000F9C6C;
extern unsigned char D_000F9DDC;
extern unsigned char D_000F9DE8;
extern unsigned char CtrlInfoV;
extern unsigned char D_000F9D0C;
extern unsigned char D_000F9DF0;
extern unsigned char D_000F9DFC;
M2C_UNK semaLock(int);                              /* extern */
extern int FileSema;
M2C_UNK semaUnlock(int);                            /* extern */


typedef struct {
	unsigned int now, trg, rel, old, rpt, hold, raw;
	int cnt;
} CtrlTrg;

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

#ifndef NULL
#define NULL ((void *)0)
#endif

void *ctrlState(int arg0) {
    if (arg0 != 0) {
        consPrintf(&D_000F9C50, &D_000F9C6C, 0x2C0, &D_000F9DDC, &D_000F9DE8);
    }
    return (arg0 * 0xA0) + &CtrlInfo;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

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

extern int CtrlEnter;
int ctrlSetEnter(int key)
{
	_ctrlSetTrg(key, &CtrlEnter);
	return 1;
}

extern int CtrlCancel;
int ctrlSetCancel(int key)
{
	_ctrlSetTrg(key, &CtrlCancel);
	return 1;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E30);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E38);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E40);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E44);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", fileInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E5C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E84);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9E94);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9EB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9ED8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9EE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9EEC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9EF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9F04);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", fileTerm);

#ifndef NULL
#define NULL ((void *)0)
#endif

void fileLock(void) {
    if (FileSema > 0) {
        semaLock(FileSema);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void fileUnlock(void) {
    if (FileSema > 0) {
        semaUnlock(FileSema);
    }
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", filePref);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", filePath);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000F9F64);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", fileReady);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", fileRead);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", fileReadPath);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", fileWrite);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", homeInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000FA21C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000FA220);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000FA22C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000FA23C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000FA248);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", D_000FA264);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/dev/ctrl", homeTerm);
