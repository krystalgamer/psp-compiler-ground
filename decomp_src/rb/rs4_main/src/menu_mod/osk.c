/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void consPrintf(const char *, ...);
M2C_UNK getOskUtilityTextResult();                  /* extern */
extern void *l_ptCntx;
extern int sample_type_11A910;

M2C_UNK gameCtrlLock();                             /* extern */
M2C_UNK gameDisSoftReset();                         /* extern */
M2C_UNK gameCtrlUnlock();
extern int osk_param;
int setOskUtilityParam();
int sceUtilityOskInitStart();

int UtilityLink();
int utility_update_osk();
extern unsigned char D_00103130, D_00103158, D_00103168, D_001031E4, D_001031F4, D_001031F8, D_00103228, D_00103258;
void *_memAlloc(int, void *, int);
int _memFree();
typedef struct { char pad[0x28]; unsigned short *text; unsigned int result; char pad2[0x34 - 0x30]; } OskData;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", setOskUtilityPraram);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103130);

unsigned short *textUcs4toUcs2Alloc(int *src, unsigned int n)
{
	unsigned short *buf = _memAlloc(n * 2, &D_00103130, 0xD4);
	unsigned short *d = buf;
	consPrintf(&D_00103158, "textUcs4toUcs2Alloc", src, buf, n);
	while (*src != 0 && n > 1) {
		consPrintf(&D_00103168, "textUcs4toUcs2Alloc", n, *src);
		*d++ = *src++;
		n--;
	}
	*d = 0;
	return buf;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103158);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103168);

int textUcs2toUcs4Free(unsigned short *src, int *dst, unsigned int n)
{
	unsigned short *s = src;
	consPrintf(&D_00103158, "textUcs2toUcs4Free", src, dst, n);
	if (dst != NULL) {
		while (*src != 0 && n > 1) {
			consPrintf(&D_00103168, "textUcs2toUcs4Free", n, *src);
			*dst++ = *src++;
			n--;
		}
		*dst = 0;
	}
	_memFree(s, &D_00103130, 0xF0);
	return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", setOskUtilityParam);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031A0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031B8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", getOskUtilityTextResult);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031E4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031F4);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_001031F8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103228);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", D_00103258);

void dumpOskUtilityTextResult(int n, OskData *d)
{
	int i;
	OskData *e;
	unsigned short *p;
	for (i = 0; i < n; i++) {
		consPrintf(&D_001031E4, i);
		e = (OskData *)(i * 52 + (int)d);
		switch (e->result) {
		case 0:
			consPrintf(&D_001031F4, &D_00103228);
			break;
		case 1:
			consPrintf(&D_001031F4, &D_001031F8);
			break;
		case 2:
			consPrintf(&D_001031F4, &D_00103258);
			consPrintf(" [");
			for (p = e->text; *p; p++)
				consPrintf("0x%4.4x ", *p);
			consPrintf("]\n");
			break;
		}
	}
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/menu_mod/osk", utility_update_osk);

void OnPush_OSK(int a) {
    int temp_v0;

    sample_type_11A910 = 1;
    setOskUtilityParam(a, &osk_param);
    temp_v0 = sceUtilityOskInitStart(&osk_param);
    if (temp_v0 != 0) {
        consPrintf("sceUtilityOskInitStart failed - %d\n", temp_v0);
    }
}

void Lock(int arg0) {
    int *temp_v0;

    gameDisSoftReset();
    gameCtrlLock();
    temp_v0 = gameGetCntx();
    M2C_FIELD(temp_v0, int *, 4) = (int) (M2C_FIELD(temp_v0, int *, 4) | (arg0 != 0));
}

void Unlock(int arg0) {
    int *temp_v0;

    temp_v0 = gameGetCntx();
    M2C_FIELD(temp_v0, int *, 8) = (int) (M2C_FIELD(temp_v0, int *, 8) | (arg0 != 0));
    gameCtrlUnlock();
    gameEnSoftReset();
}

int OskStart(int *p)
{
	consPrintf("OskStart : \n");
	Lock(p[2] & 1);
	if (UtilityLink(utility_update_osk)) {
		OnPush_OSK(p);
		return 1;
	}
	Unlock(p[2] & 1);
	return 0;
}

void OskEnd(void) {
    int temp_s0;

    if (l_ptCntx != NULL) {
        temp_s0 = M2C_FIELD(l_ptCntx, int *, 8);
        getOskUtilityTextResult();
        UtilityUnlink();
        Unlock(temp_s0 & 1);
        consPrintf("OskEnd\n");
    }
}

int OskState(void) {
    return sample_type_11A910 == 1;
}
