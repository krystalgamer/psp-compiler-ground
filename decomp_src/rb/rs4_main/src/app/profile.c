/* cflags: -Os -fno-strength-reduce */
#include "common.h"
#include "m2c_macros.h"
#include "../minmax.h"
unsigned int cccTtrToUcs4(void *, int, M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
void consPrintf(const char *, ...);
int resGetDatLocal(M2C_UNK, M2C_UNK);               /* extern */
extern unsigned char D_000FE318;
extern unsigned char D_000FE334;

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", profileDefaultNameSet);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE318);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE334);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/app/profile", D_000FE348);

void profileDefaultParamSet(void *arg0) {
    M2C_FIELD(arg0, short *, 0x206) = 0x3E8;
    M2C_FIELD(arg0, int *, 0x208) = 0x3E8;
    M2C_FIELD(arg0, short *, 0x202) = 0;
    M2C_FIELD(arg0, int *, 0x20C) = 0;
    M2C_FIELD(arg0, int *, 0x210) = 0;
    M2C_FIELD(arg0, int *, 0x214) = 0;
    M2C_FIELD(arg0, int *, 0x218) = 0;
    M2C_FIELD(arg0, int *, 0x21C) = 0;
    M2C_FIELD(arg0, int *, 0x220) = 0;
    if (cccTtrToUcs4(arg0 + 0x80, resGetDatLocal(1, 0x53), "SINGLE_93", 0, 0) >= 0x20U) {
        consPrintf(&D_000FE318, &D_000FE334, 0x50, "profileDefaultParamSet", "Len < (Profile_TextByte/sizeof(ucs4))");
    }
    if (cccTtrToUcs4(arg0 + 0x100, resGetDatLocal(1, 0x53), "SINGLE_94", 0, 0) >= 0x20U) {
        consPrintf(&D_000FE318, &D_000FE334, 0x52, "profileDefaultParamSet", "Len < (Profile_TextByte/sizeof(ucs4))");
    }
    if (cccTtrToUcs4(arg0 + 0x180, resGetDatLocal(1, 0x53), "SINGLE_95", 0, 0) >= 0x20U) {
        consPrintf(&D_000FE318, &D_000FE334, 0x54, "profileDefaultParamSet", "Len < (Profile_TextByte/sizeof(ucs4))");
    }
    M2C_FIELD(arg0, short *, 0x200) = 1;
}

int profileGetRankingTtrStr(char *buf, int n)
{
	sprintf(buf, "MENU_TEXT_%d", amin(amax(n, 0), 24) + 59);
	return 1;
}

int profileGetRankingTtrStr2(char *buf, int n)
{
	sprintf(buf, "ENUM_RANKING_%d", amin(amax(n, 0), 24) + 1);
	return 1;
}

/* STAND-IN: int-to-float with the conversion in place (mtc1 rX,fN; cvt.s.w fN,fN) in all three ratio
   functions; casts pick a second FPR here.  Maybe Sony's helper is inline asm like the cvt.w.s one
   (cardlistCpyTtr2Int32); the original spelling is unknown. */
static inline float profI2F(int i)
{
	float f;
	__asm__ volatile ("cvt.s.w %0, %0" : "=f"(f) : "0"(i));
	return f;
}

float profileGetPerOfWins(void *arg0)
{
	int w = M2C_FIELD(arg0, int *, 0x20C);
	float t = profI2F(w + M2C_FIELD(arg0, int *, 0x210) + M2C_FIELD(arg0, int *, 0x214));
	if (t == 0.0f)
		return 0.0f;
	return profI2F(w) / t;
}

float profileGetPerOfSuccess(void *arg0)
{
	int s = M2C_FIELD(arg0, int *, 0x224);
	float t = profI2F(s + M2C_FIELD(arg0, int *, 0x228));
	if (t == 0.0f)
		return 0.0f;
	return profI2F(s) / t;
}

float profileGetPerOfJanken(void *arg0, int k)
{
	int v;
	if (k == 0)
		v = M2C_FIELD(arg0, int *, 0x218);
	else
		v = M2C_FIELD(arg0, int *, 0x21C);
	if (k == 2)
		v = M2C_FIELD(arg0, int *, 0x220);
	{
		int a = M2C_FIELD(arg0, int *, 0x218);
		int b = M2C_FIELD(arg0, int *, 0x21C);
		int c = M2C_FIELD(arg0, int *, 0x220);
		float t = profI2F(a + b + c);
		if (t == 0.0f)
			return 0.0f;
		return profI2F(v) / t;
	}
}
