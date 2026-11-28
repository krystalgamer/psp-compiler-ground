/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
extern unsigned char D_000FEA94;
extern unsigned char D_000FEAB4;
extern unsigned char D_000FEAD0;

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEA94);

int ActorGetNum(void *arg0) {
    if (arg0 == NULL) {
        consPrintf(&D_000FEAB4, &D_000FEA94, 0x85, "ActorGetNum", &D_000FEAD0);
    }
    return M2C_FIELD(arg0, int *, 0x80);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEAB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEAD0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEAD8);

extern unsigned char D_000FEAD8, D_000FEB10;
unsigned int sceKernelGetGPI(void);
int ActorSetTask(void *s, int idx, int task)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x128) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x80)) {
			M2C_FIELD(s, int **, 0x128)[idx] = task;
			return 1;
		}
		if (sceKernelGetGPI() & 8)
			consPrintf(&D_000FEB10, "ActorSetTask", idx);
		return 0;
	}
	consPrintf(&D_000FEAD8, "ActorSetTask", idx);
	return 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB10);

extern unsigned char D_000FEAD8, D_000FEB10;
unsigned int sceKernelGetGPI(void);
int ActorGetTask(void *s, int idx)
{
	if (s != NULL && M2C_FIELD(s, int **, 0x128) != NULL) {
		if (idx >= 0 && idx < M2C_FIELD(s, int *, 0x80))
			return M2C_FIELD(s, int **, 0x128)[idx];
		if (sceKernelGetGPI() & 8)
			consPrintf(&D_000FEB10, "ActorGetTask", idx);
		return 0;
	}
	consPrintf(&D_000FEAD8, "ActorGetTask", idx);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorGetVariable);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB58);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEB74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEC48);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorSetVariable);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorRecvMotion);

int SequenceExec(void *, int, unsigned int, float);
int ActorScriptRun(char *t)
{
	int *w = *(int **)(t + 0x34);
	int r = 0;
	if (w[3] == 0 && w[4] == 0) {
		w[0] = SequenceExec(t, w[0], *(unsigned short *)(t + 0x40), 0.0f);
		r = 1;
	}
	return r;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FED88);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FED90);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FED98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDAC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorCameraMove);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDDC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDE8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEDF4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE00);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorLightInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE50);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE58);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorLightMove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorMotionMove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorAttachProc);

extern int D_001123C8[];
void *ActorGetAvatar(int n)
{
	if (((int *)gameGetCntx())[0x38 / 4] == 9)
		return resGetDatLocal(2, ((int *)resGetPtrTable(2, 5))[n]);
	return resGetDatLocal(2, D_001123C8[n]);
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE80);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", ActorTask);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE98);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEE9C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEA0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEA8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEAC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEB4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEC0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEC8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEED4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEEF0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF08);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF10);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF18);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF3C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF48);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF60);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF64);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF68);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF74);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF78);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEF8C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEFA4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FEFB8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF158);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF16C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF18C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF1AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF1CC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF1EC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF20C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF22C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF230);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF234);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF238);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF23C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF240);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF244);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF248);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF24C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF250);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF254);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF258);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF25C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF260);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF264);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF268);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF26C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF270);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF274);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF278);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF27C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF280);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF284);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF288);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF28C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF290);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF294);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF298);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF29C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2A4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2A8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2AC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2B0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2B4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/script/actor", D_000FF2B8);
