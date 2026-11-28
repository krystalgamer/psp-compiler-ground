#include "common.h"
#include "m2c_macros.h"

M2C_UNK SpriteInit();                               /* extern */
M2C_UNK SpriteKick();                               /* extern */
M2C_UNK PzlLoadFiles();                             /* extern */
M2C_UNK SpriteAllFreeImage();                       /* extern */
M2C_UNK SpriteSetFader(float);                        /* extern */
M2C_UNK bgm_play(M2C_UNK);                          /* extern */
M2C_UNK load_title_gim();                           /* extern */
M2C_UNK LoadGimFile(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK MsLoad();                                   /* extern */
M2C_UNK se_play(M2C_UNK);                           /* extern */
extern int MsAccessFlag;
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
	static int isLoad;
    SpriteAllFreeImage();
    load_title_gim();
    if (isLoad == 0) {
        isLoad = 1;
        PzlLoadFiles();
    }
    bgm_play(0);
    SpriteSetFader(1.0f);
    return 0;
}

#ifdef NON_MATCHING
/* Close: %hi(D_00152960) and %hi(1.0f) swap saved registers, and the rotation
 * argument is computed before the zero stack arguments are stored. */
void disp_title_bg(int alpha);
void SetSpriteColorRGBA(int r, int g, int b, int a);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);

int TitleDisp(void)
{
	static int count;
	static int fade;
	int ret = 0;
	float fade_l;
	int a;

	SpriteInit();
	if (fade < 30) {
		fade++;
		fade_l = fade / 30;
	} else if (fade < 60) {
		fade_l = 1.0f;
		if (GetKeyHit() & 0x2008) {
			se_play(1);
			ret = 5;
		}
	} else {
		fade++;
		fade_l = (180 - fade) / 120.0f;
		if (fade >= 180) {
			ret = 2;
			fade = 0;
			count = 0;
		}
	}
	SpriteSetFader(fade_l);
	disp_title_bg(255);
	DrawSpriteEz(1.0f, 108.0f, 0.0f, 264.0f, 256.0f, 0.0f, 0.0f, 5);
	DrawSpriteEz(1.0f, 84.0f, 240.0f, 312.0f, 24.0f, 0.0f, 0.0f, 4);
	count = (count + 1) % 180;
	a = count * 2 - 180;
	if (a < 0)
		a = -a;
	SetSpriteColorRGBA(255, 255, 255, a + 75);
	DrawSpriteEx(3, 1.0f, 38.0f, 16.4f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (float)-count * 3.14f / 90.0f, 1.0f, 0);
	SpriteKick();
	return ret;
}
#else
/* STAND-IN: TitleDisp is still asm.  Its statics, in its place and numbered as in
 * the original (count.1, fade.2); initialized ones only keep the numbering (their .data stays asm). */
static void __attribute__((section(".pbskip"), unused)) TitleDisp_statics(void)
{
	static int count;
	static int fade;
}
__asm__("D_00152960 = count.1\n"
	"D_00152964 = fade.2");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/Title", TitleDisp);
#endif

int SigInit(void) {
	static int InitLoadFlag;
    SpriteAllFreeImage();
    LoadGimFile(0, 0x2AB);
    if (InitLoadFlag == 0) {
        MsLoad();
        InitLoadFlag = 1;
    }
    SpriteSetFader(1.0f);
    return 0;
}

int SigMain(void)
{
	static int count;
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
	count++;
	if (count < 60)
		c = count * 255 / 60;
	else if (count < 241)
		c = 255;
	else
		c = (300 - count) * 255 / 60;
	if (count >= 300) {
		count = 0;
		ret = 1;
	}
	if (GetKeyHit() & 0x2008) {
		count = 0;
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
	static int count;
	static int wait;
	int ret = 0;
	int c;

	SpriteInit();
	if (count < 60) {
		count++;
		c = count * 255 / 60;
		wait = 0;
	} else if (count >= 120) {
		count++;
		c = (180 - count) * 255 / 60;
		if (count >= 180)
			c = 0;
		if (count >= 200) {
			ret = 4;
			count = 0;
			wait = 0;
		}
	} else {
		wait++;
		if (wait > 1800)
			count = 120;
		if (GetKeyHit() & 0x2008)
			count = 120;
		c = 255;
	}
	SpriteSetColorRGBA(c, c, c, 255);
	DrawSpriteEz(2.0f, 0, 0, 240, 272, 0, 0, 0);
	DrawSpriteEz(2.0f, 240, 0, 240, 272, 240, 0, 0);
	SpriteKick();
	return ret;
}
