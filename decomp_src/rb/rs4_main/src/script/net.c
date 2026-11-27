/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
void consPrintf(const char *, ...);
M2C_UNK ctrlSetVirtualType(M2C_UNK);                /* extern */
M2C_UNK ctrlSuspend(M2C_UNK);                       /* extern */
extern unsigned char D_000FF4B4;

extern unsigned char D_000FF4CC, D_000FF4E8, D_000FF4FC;
void ctrlFlushVirtualDataAll(void);
int taskProc();
void Script_NetStartCB(int a, char *w)
{
	void *t, *p;
	consPrintf(&D_000FF4B4, "Script_NetStartCB", a, w);
	*(int *)(w + 0x40) = 1;
	*(int *)(w + 0x44) = 1;
	ctrlSuspend(0);
	ctrlFlushVirtualDataAll();
	ctrlSetVirtualType(3);
	t = *(void **)(w + 0x10);
	if (t != 0) {
		p = *(void **)(w + 0x48);
		if (!p)
			consPrintf(&D_000FF4CC, &D_000FF4E8, 0x33, "Script_NetStartCB", &D_000FF4FC);
		taskProc(t, p, 0, 0);
	}
	return;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4E8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", D_000FF4FC);

void Script_NetTermCB(int arg0, int arg1) {
    consPrintf(&D_000FF4B4, "Script_NetTermCB", arg0, arg1);
    ctrlSuspend(0);
    ctrlSetVirtualType(0);
}

void Script_NetErrCB(int arg0, void *arg1) {
    consPrintf(&D_000FF4B4, "Script_NetErrCB", arg0, arg1);
    M2C_FIELD(arg1, int *, 0x44) = 0;
    ctrlSuspend(0);
    ctrlSetVirtualType(0);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/net", Script_Net);
