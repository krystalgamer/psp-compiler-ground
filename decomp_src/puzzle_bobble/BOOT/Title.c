#include "common.h"
#include "m2c_macros.h"

M2C_UNK SpriteInit();                               /* extern */
M2C_UNK SpriteKick();                               /* extern */
M2C_UNK PzlLoadFiles();                             /* extern */
M2C_UNK SpriteAllFreeImage();                       /* extern */
M2C_UNK SpriteSetFader(float);                        /* extern */
M2C_UNK bgm_play(M2C_UNK);                          /* extern */
M2C_UNK load_title_gim();                           /* extern */
extern int D_0015295C;
M2C_UNK LoadGimFile(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK MsLoad();                                   /* extern */
extern int D_00152968;
M2C_UNK se_play(M2C_UNK);                           /* extern */
extern int MsAccessFlag;
extern int D_0015296C;
extern int D_00152970;
extern int D_00152974;
int GetKeyHit(void);
void SpriteSetColorRGBA(int r, int g, int b, int a);
int DrawSpriteEz(float z, float x, float y, float w, float h, float u, float v, int no);

/* cflags: -O2 -fno-merge-constants */
/* (while TitleDisp is asm: its constants are in .rodata, so the C ones go there too) */

int LogoDisp(void) {
    SpriteInit();
    SpriteKick();
    return 4;
}

int TitleInit(void) {
    SpriteAllFreeImage();
    load_title_gim();
    if (D_0015295C == 0) {
        D_0015295C = 1;
        PzlLoadFiles();
    }
    bgm_play(0);
    SpriteSetFader(1.0f);
    return 0;
}

#ifdef NON_MATCHING
/* Close: %hi(D_00152960) and %hi(1.0f) swap saved registers, and the rotation
 * argument is computed before the zero stack arguments are stored. */
extern int D_00152960;
extern int D_00152964;
void disp_title_bg(int alpha);
void SetSpriteColorRGBA(int r, int g, int b, int a);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);

int TitleDisp(void)
{
	int ret = 0;
	float fade;
	int a;

	SpriteInit();
	if (D_00152964 < 30) {
		D_00152964++;
		fade = D_00152964 / 30;
	} else if (D_00152964 < 60) {
		fade = 1.0f;
		if (GetKeyHit() & 0x2008) {
			se_play(1);
			ret = 5;
		}
	} else {
		D_00152964++;
		fade = (180 - D_00152964) / 120.0f;
		if (D_00152964 >= 180) {
			ret = 2;
			D_00152964 = 0;
			D_00152960 = 0;
		}
	}
	SpriteSetFader(fade);
	disp_title_bg(255);
	DrawSpriteEz(1.0f, 108.0f, 0.0f, 264.0f, 256.0f, 0.0f, 0.0f, 5);
	DrawSpriteEz(1.0f, 84.0f, 240.0f, 312.0f, 24.0f, 0.0f, 0.0f, 4);
	D_00152960 = (D_00152960 + 1) % 180;
	a = D_00152960 * 2 - 180;
	if (a < 0)
		a = -a;
	SetSpriteColorRGBA(255, 255, 255, a + 75);
	DrawSpriteEx(3, 1.0f, 38.0f, 16.4f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (float)-D_00152960 * 3.14f / 90.0f, 1.0f, 0);
	SpriteKick();
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/Title", TitleDisp);
#endif

int SigInit(void) {
    SpriteAllFreeImage();
    LoadGimFile(0, 0x2AB);
    if (D_00152968 == 0) {
        MsLoad();
        D_00152968 = 1;
    }
    SpriteSetFader(1.0f);
    return 0;
}

int SigMain(void)
{
	int ret = 0;
	int c;

	if (MsAccessFlag) {
		SpriteInit();
		SpriteSetColorRGBA(0, 0, 0, 255);
		DrawSpriteEz(2.0f, 0, 0, 240, 272, 0, 0, 0);
		DrawSpriteEz(2.0f, 240, 0, 240, 272, 240, 0, 0);
		SpriteKick();
		return 0;
	}
	SpriteInit();
	D_0015296C++;
	if (D_0015296C < 60)
		c = D_0015296C * 255 / 60;
	else if (D_0015296C < 241)
		c = 255;
	else
		c = (300 - D_0015296C) * 255 / 60;
	if (D_0015296C >= 300) {
		D_0015296C = 0;
		ret = 1;
	}
	if (GetKeyHit() & 0x2008) {
		D_0015296C = 0;
		ret = 1;
	}
	SpriteSetColorRGBA(c, c, c, 255);
	DrawSpriteEz(2.0f, 0, 0, 240, 272, 0, 0, 0);
	DrawSpriteEz(2.0f, 240, 0, 240, 272, 240, 0, 0);
	SpriteKick();
	return ret;
}

int EndCreditInit(void) {
    SpriteAllFreeImage();
    se_play(0xA);
    return 0;
}

int EndCreditMain(void)
{
	int ret = 0;
	int c;

	SpriteInit();
	if (D_00152970 < 60) {
		D_00152970++;
		c = D_00152970 * 255 / 60;
		D_00152974 = 0;
	} else if (D_00152970 >= 120) {
		D_00152970++;
		c = (180 - D_00152970) * 255 / 60;
		if (D_00152970 >= 180)
			c = 0;
		if (D_00152970 >= 200) {
			ret = 4;
			D_00152970 = 0;
			D_00152974 = 0;
		}
	} else {
		D_00152974++;
		if (D_00152974 > 1800)
			D_00152970 = 120;
		if (GetKeyHit() & 0x2008)
			D_00152970 = 120;
		c = 255;
	}
	SpriteSetColorRGBA(c, c, c, 255);
	DrawSpriteEz(2.0f, 0, 0, 240, 272, 0, 0, 0);
	DrawSpriteEz(2.0f, 240, 0, 240, 272, 240, 0, 0);
	SpriteKick();
	return ret;
}
