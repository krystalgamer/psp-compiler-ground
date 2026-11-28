/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);

typedef struct { int Ofs; int Num; short Elm[1]; } ElmCntx;

extern unsigned char D_000FAB04, D_000FAB20, D_000FAB54;

extern unsigned char D_000FAB04, D_000FAB20, D_000FAB54;
int elmTerm();

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/elm", D_000FAB04);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/elm", D_000FAB20);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/lib/elm", elmInit);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/elm", D_000FAB54);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/lib/elm", D_000FAB5C);

void _memFree(void *p, const char *file, int line);
int sceKernelGetGPI(void);
int elmTerm(void *pCntx)
{
	if (pCntx == NULL)
		consPrintf(&D_000FAB04, &D_000FAB20, 0x32, "elmTerm", &D_000FAB54);
	if (sceKernelGetGPI() & 1)
		consPrintf("%s  : 0x%08x\n", "elmTerm", pCntx);
	if (pCntx != NULL) {
		_memFree(pCntx, &D_000FAB20, 0x37);
		return 1;
	}
	consPrintf(&D_000FAB04, &D_000FAB20, 0x3A, "elmTerm", "FALSE");
	return 0;
}

short elmCall(void *arg0) {
    short var_a0;
    short *e;
    int temp_s0;

    if (arg0 == NULL) {
        consPrintf(&D_000FAB04, &D_000FAB20, 0x45, "elmCall", &D_000FAB54);
    }
    temp_s0 = M2C_FIELD(arg0, int *, 0);
    if (temp_s0 < 0) {
        consPrintf(&D_000FAB04, &D_000FAB20, 0x49, "elmCall", "Ofs >= 0");
    }
    var_a0 = -1;
    if (temp_s0 < M2C_FIELD(arg0, int *, 4)) {
        M2C_FIELD(arg0, int *, 0) = (int) (temp_s0 + 1);
        e = ((ElmCntx *)arg0)->Elm;
        var_a0 = e[temp_s0];
    }
    return var_a0;
}

int elmFree(void *arg0, short arg1) {
    int temp_s0;
    int var_v0;
    short *e;

    if (arg0 == NULL) {
        consPrintf(&D_000FAB04, &D_000FAB20, 0x61, "elmFree", &D_000FAB54);
    }
    if (arg1 < 0) {
        consPrintf(&D_000FAB04, &D_000FAB20, 0x62, "elmFree", "Elm >= 0");
    }
    if (arg1 >= M2C_FIELD(arg0, int *, 4)) {
        consPrintf(&D_000FAB04, &D_000FAB20, 0x63, "elmFree", "Elm < pCntx->Num");
    }
    temp_s0 = M2C_FIELD(arg0, int *, 0);
    if (temp_s0 <= 0) {
        consPrintf(&D_000FAB04, &D_000FAB20, 0x67, "elmFree", "Ofs > 0");
    }
    if (M2C_FIELD(arg0, int *, 4) < temp_s0) {
        consPrintf(&D_000FAB04, &D_000FAB20, 0x68, "elmFree", "Ofs <= pCntx->Num");
    }
    var_v0 = 0;
    if (temp_s0 != 0) {
        temp_s0--;
        M2C_FIELD(arg0, int *, 0) = temp_s0;
        e = ((ElmCntx *)arg0)->Elm;
        e[temp_s0] = arg1;
        var_v0 = 1;
    }
    return var_v0;
}
