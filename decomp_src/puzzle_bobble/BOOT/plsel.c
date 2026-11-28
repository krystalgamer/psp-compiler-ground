/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"

void LoadFileList(int no, int *list);
typedef struct {
	int active;
	int x, y;
	int tx, ty;
} SEL_WORK;
typedef struct {
	int idx;
	int x, y;
	int tx, ty;
} SEL_INIT;
extern SEL_WORK SelWork[5];
extern int chr_list_pl[];
extern int chr_list_pl2[];
extern int D_0101C3BC;
extern int SelectPlayer;
extern int SelPlAngle;
extern int OldError;
extern const SEL_INIT mode_int[3];
extern int mode_gim[];
extern int mode_gims2[];
extern int Round;
extern int D_0101C3B8;
extern int RsFlag;


void load_title_gim(void) {
    LoadFileList(0, mode_gim);
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", mode_gim);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", mode_gims2);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", face_u);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", face_v);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", sel_chr);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", name_u);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", name_v);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", atk_u);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", atk_v);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", mode_stop);

const SEL_INIT mode_int[3] = {
	{ 2, 108, 0, 108, -300 },
	{ 0, 88, 272, 88, 168 },
	{ 1, 0, -80, 0, -40 },
};

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F3B8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", r_num_u);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", r_num_v);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", r_keta);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F428);

void SetSpriteColorRGBA(int r, int g, int b, int a);
int DrawSpriteEz(float z, float x, float y, float w, float h, float u, float v, int no);
int SpriteDraw(int no, int color, float z, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3);

void disp_title_bg(int alpha)
{
	SetSpriteColorRGBA(255, 255, 255, alpha);
	DrawSpriteEz(4.0f, 0.0f, 0.0f, 240.0f, 272.0f, 0.0f, 0.0f, 0);
	DrawSpriteEz(4.0f, 240.0f, 0.0f, 240.0f, 272.0f, 240.0f, 0.0f, 0);
	DrawSpriteEz(2.0f, 0.0f, 112.0f, 240.0f, 160.0f, 0.0f, 0.0f, 1);
	SpriteDraw(1, -1, 2.0f, 240.0f, 112.0f, 239.0f, 0.0f, 479.0f, 112.0f, 0.0f, 0.0f,
		   240.0f, 271.0f, 239.0f, 159.0f, 479.0f, 271.0f, 0.0f, 159.0f);
	DrawSpriteEz(2.0f, 0.0f, 112.0f, 124.0f, 160.0f, 0.0f, 0.0f, 2);
	DrawSpriteEz(2.0f, 356.0f, 112.0f, 124.0f, 160.0f, 124.0f, 0.0f, 2);
}

void sel_obj_move(void)
{
	int i;

	for (i = 0; i < 5; i++) {
		if (SelWork[i].active > 0) {
			if (SelWork[i].x > SelWork[i].tx)
				SelWork[i].x--;
			if (SelWork[i].x < SelWork[i].tx)
				SelWork[i].x++;
			if (SelWork[i].y > SelWork[i].ty)
				SelWork[i].y--;
			if (SelWork[i].y < SelWork[i].ty)
				SelWork[i].y++;
		}
	}
}

void sel_obj_move2(int i)
{
	if (SelWork[i].active > 0) {
		if (SelWork[i].x > SelWork[i].tx)
			SelWork[i].x--;
		if (SelWork[i].x < SelWork[i].tx)
			SelWork[i].x++;
		if (SelWork[i].y > SelWork[i].ty)
			SelWork[i].y--;
		if (SelWork[i].y < SelWork[i].ty)
			SelWork[i].y++;
	}
}

int PlSelInit(void)
{
	if (D_0101C3BC == 0)
		LoadFileList(12, chr_list_pl);
	else
		LoadFileList(12, chr_list_pl2);
	SelectPlayer = 0;
	SelPlAngle = 0;
	return 0;
}

#ifdef NON_MATCHING
/* Rough (15 instructions short): logic complete, but the original keeps ret in a stack
 * slot, tests NowMode as 1, <2, 2, 3 and allocates the face_u/face_v pointers and the
 * 128.0 double differently.  The double literals are the unit's cst8 rodata. */
extern int D_00154010;
extern int D_00154014;
extern int D_00154018;
extern int D_000408D4;
extern int SelectModeFlag;
extern int NowMode;
extern const int face_u[];
extern const int face_v[];
extern const int sel_chr[];
extern const int name_u[];
extern const int name_v[];
extern const int atk_u[];
extern const int atk_v[];
extern const double D_0002F648;
extern const double D_0002F650;
extern const double D_0002F658;
extern const double D_0002F660;
extern const double D_0002F668;
double cos(double);
double sin(double);
int GetKeyHit(void);
void SpriteInit(void);
void SpriteKick(void);
int se_play(int no);
void bgm_stop(void);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);
int PlayerSelect(void)
{
	int ret;
	int i, a, x, y, k, o, r;
	double ang;

	SpriteInit();
	DrawSpriteEz(4.0f, 0.0f, 0.0f, 240.0f, 272.0f, 0.0f, 0.0f, 0);
	DrawSpriteEz(4.0f, 240.0f, 0.0f, 240.0f, 272.0f, 240.0f, 0.0f, 0);
	DrawSpriteEz(2.0f, 0.0f, 112.0f, 240.0f, 160.0f, 0.0f, 0.0f, 1);
	ret = 0;
	SpriteDraw(1, -1, 2.0f, 240.0f, 112.0f, 239.0f, 0.0f, 479.0f, 112.0f, 0.0f, 0.0f, 240.0f, 271.0f, 239.0f, 159.0f, 479.0f, 271.0f, 0.0f, 159.0f);
	DrawSpriteEz(2.0f, 0.0f, 208.0f, 200.0f, 40.0f, 0.0f, 0.0f, 13);
	DrawSpriteEz(2.0f, 200.0f, 208.0f, 200.0f, 40.0f, 0.0f, 40.0f, 13);
	DrawSpriteEz(2.0f, 328.0f, 0.0f, 304.0f, 304.0f, 0.0f, 0.0f, 4);
	D_00154014++;
	if (D_000408D4 < 30) {
		D_000408D4++;
	} else if (D_000408D4 >= 60) {
		D_000408D4 += 2;
		if (D_000408D4 >= 180) {
			D_00154010 = 0;
			D_000408D4 = 0;
			SelectModeFlag = NowMode;
			switch (NowMode) {
			case 1:
				ret = 10;
				break;
			case 2:
				ret = 9;
				break;
			case 3:
				ret = 11;
				break;
			default:
				ret = 2;
				break;
			}
		}
	} else {
		if (GetKeyHit() & 0x2008) {
			if (D_0101C3BC == 0 && SelectPlayer == 5)
				a = 2;
			else {
				D_000408D4 = 60;
				bgm_stop();
				a = 0;
			}
			se_play(a);
		} else if (GetKeyHit() & 0x4000) {
			ret = 6 - (NowMode != 0);
			se_play(3);
		}
		if (GetKeyHit() & 0xC0) {
			se_play(4);
			D_00154018 = 2;
			if (++SelectPlayer >= 6)
				SelectPlayer = 0;
		}
		if (GetKeyHit() & 0x30) {
			se_play(4);
			D_00154018 = -2;
			if (--SelectPlayer < 0)
				SelectPlayer = 5;
		}
		if (SelPlAngle != SelectPlayer * 30) {
			SelPlAngle += D_00154018;
			if (SelPlAngle < 0)
				SelPlAngle += 180;
			if (SelPlAngle >= 180)
				SelPlAngle -= 180;
		}
		for (i = 0; i < 6; i++) {
			ang = (float)(i * 30 - SelPlAngle + 265) * 3.14f / 90.0f;
			x = cos(ang) * D_0002F648 + D_0002F650 - D_0002F658;
			y = sin(ang) * D_0002F648 + D_0002F660 - D_0002F668;
			DrawSpriteEz(2.0f, x, y, 72.0f, 72.0f, face_u[i], face_v[i], i == SelectPlayer ? 15 : 14);
		}
		DrawSpriteEz(2.0f, 10.0f, 50.0f, 232.0f, 232.0f, 0.0f, 0.0f, sel_chr[SelectPlayer]);
		DrawSpriteEz(2.0f, 216.0f, 200.0f, 128.0f, 48.0f, name_u[SelectPlayer], name_v[SelectPlayer], 21);
		if (NowMode == 2 || NowMode == 3) {
			r = SelectPlayer / 3;
			k = SelectPlayer % 3;
			if (D_00154014 & 8)
				k += 3;
			o = (D_00154014 >> 3) & 7;
			if (r == 0)
				o = -o;
			DrawSpriteEz(2.0f, 232.0f, 240.0f, 120.0f, 32.0f, atk_u[k], atk_v[k], 12);
			DrawSpriteEz(2.0f, 232.0f, o + 240, 120.0f, 32.0f, 120.0f, r * 32 + 32, 12);
		}
		D_00154010 = (D_00154010 + 4) % 180;
		if (D_00154010 < 0)
			D_00154010 += 180;
		SetSpriteColorRGBA(191, 191, 191, 255);
		DrawSpriteEx(10, 2.0f, 29.0f, -4.0f, 96.0f, 96.0f, 0, 0, 0, 0, 0, 0, 0, 0, (float)D_00154010 * 3.14f / 90.0f, 1.0f, 0);
	}
	SetSpriteColorRGBA(255, 255, 255, 255);
	DrawSpriteEz(2.0f, 40.0f, 8.0f, 400.0f, 48.0f, 0.0f, 192.0f, 7);
	DrawSpriteEz(2.0f, 208.0f, 52.0f, 272.0f, 32.0f, 0.0f, 64.0f, 5);
	DrawSpriteEz(2.0f, 280.0f, 80.0f, 184.0f, 24.0f, 0.0f, 0.0f, 8);
	SpriteKick();
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", PlayerSelect);
#endif

int ModeSelInt(void)
{
	int i;

	LoadFileList(3, mode_gims2);
	for (i = 0; i < 5; i++)
		SelWork[i].active = 0;
	for (i = 0; i < 3; i++) {
		SelWork[mode_int[i].idx].active = 1;
		SelWork[mode_int[i].idx].x = mode_int[i].x;
		SelWork[mode_int[i].idx].y = mode_int[i].y;
		SelWork[mode_int[i].idx].tx = mode_int[i].tx;
		SelWork[mode_int[i].idx].ty = mode_int[i].ty;
	}
	OldError = 0;
	return 0;
}

#ifdef NON_MATCHING
/* One instruction long: %hi(D_00154020) and %hi(SelWork) swap s2/s3, and in the key & 0x20
 * branch the delay slot gets an extra reload of D_00154020 instead of the lui.  The 64
 * unused bytes of frame are reproduced by buf[64]. */
extern int MsAccessFlag;
extern int D_0015401C;
extern int D_00154020;
extern int D_00154024;
extern int SelectModeFlag;
extern int NowMode;
extern const int mode_stop[];
int GetKeyHit(void);
void SpriteInit(void);
void SpriteKick(void);
void SpriteSetFader(float);
int se_play(int no);
void sel_obj_move(void);
void sel_obj_move2(int i);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);
int ModeSelect(void)
{
	int ret = 0;
	int key;
	char buf[64];

	SpriteInit();
	if (MsAccessFlag) {
		key = 0;
		SpriteSetFader(0.5f);
	} else {
		key = GetKeyHit();
		SpriteSetFader(1.0f);
		if (key & 0x20) {
			se_play(4);
			D_00154024 = -2;
			D_00154020--;
		}
	}
	if (D_00154020 < 0)
		D_00154020 = 4;
	if (key & 0x80) {
		se_play(4);
		D_00154024 = 2;
		D_00154020++;
	}
	if (D_00154020 >= 5)
		D_00154020 = 0;
	if (key & 0x2008) {
		se_play(1);
		SelectModeFlag = NowMode;
		switch (D_00154020) {
		case 0:
			ret = 6;
			NowMode = 0;
			break;
		case 1:
			ret = 7;
			NowMode = 1;
			break;
		case 2:
			ret = 7;
			NowMode = 2;
			break;
		case 3:
			ret = 7;
			NowMode = 3;
			break;
		case 4:
			ret = 8;
			break;
		}
	}
	sel_obj_move();
	sel_obj_move2(0);
	disp_title_bg(255);
	DrawSpriteEz(3.0f, SelWork[0].x, SelWork[0].y, 304.0f, 304.0f, 0.0f, 0.0f, 4);
	if (D_0015401C != mode_stop[D_00154020])
		D_0015401C += D_00154024;
	else
		DrawSpriteEz(3.0f, 120.0f, 200.0f, 240.0f, 32.0f, 0.0f, D_00154020 * 48 + 10, 6);
	D_0015401C %= 180;
	if (D_0015401C < 0)
		D_0015401C += 180;
	SetSpriteColorRGBA(255, 255, 255, 255);
	DrawSpriteEx(3, 3.0f, SelWork[1].x, SelWork[1].y, 424.0f, 424.0f, 0, 0, 0, 0, 0, 0, 0, 0, (float)D_0015401C * 3.14f / 90.0f, 1.0f, 0);
	DrawSpriteEz(2.0f, 40.0f, 8.0f, 400.0f, 48.0f, 0.0f, 48.0f, 7);
	DrawSpriteEz(2.0f, 104.0f, 56.0f, 272.0f, 32.0f, 0.0f, 0.0f, 5);
	DrawSpriteEz(2.0f, 148.0f, 248.0f, 184.0f, 24.0f, 0.0f, 0.0f, 8);
	SpriteKick();
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", ModeSelect);
#endif

int GetRound(void) {
    return Round;
}

int RselInt(void) {
    if (Round < D_0101C3B8) {
        Round = D_0101C3B8;
    }
    RsFlag = 0;
    return 0;
}

extern int D_000408E4;
extern const double D_0002F670;	/* 23.5: a cst8 literal, kept in the unit's rodata */
extern int D_00154028;
extern int SelectModeFlag;
extern const int r_num_u[];
extern const int r_num_v[];
int GetKeyHit(void);
void SpriteInit(void);
void SpriteKick(void);
int se_play(int no);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);
int RoundSelect(void)
{
	int ret = 0;
	int d100, d10, d1, a;

	SpriteInit();
	disp_title_bg(255);
	DrawSpriteEz(2.0f, 40.0f, 8.0f, 400.0f, 48.0f, 0.0f, 0.0f, 7);
	DrawSpriteEz(2.0f, 104.0f, 56.0f, 272.0f, 32.0f, 0.0f, 32.0f, 5);
	DrawSpriteEz(2.0f, 148.0f, 248.0f, 184.0f, 24.0f, 0.0f, 0.0f, 8);
	DrawSpriteEz(3.0f, 88.0f, 168.0f, 304.0f, 304.0f, 0.0f, 0.0f, 4);
	DrawSpriteEz(1.0f, 120.0f, 200.0f, 240.0f, 32.0f, 0.0f, 10.0f, 6);
	if (RsFlag < 48) {
		RsFlag++;
		SpriteDraw(9, -1, 2.0f, 128 - RsFlag, 144 - RsFlag, 0, 0, 128 + RsFlag, 144 - RsFlag, 95, 0, 128 - RsFlag, 144 + RsFlag, 0, 95, 128 + RsFlag, 144 + RsFlag, 95, 95);
		SpriteDraw(9, -1, 2.0f, 240 - RsFlag, 144 - RsFlag, 0, 0, 240 + RsFlag, 144 - RsFlag, 95, 0, 240 - RsFlag, 144 + RsFlag, 0, 95, 240 + RsFlag, 144 + RsFlag, 95, 95);
		SpriteDraw(9, -1, 2.0f, 352 - RsFlag, 144 - RsFlag, 0, 0, 352 + RsFlag, 144 - RsFlag, 95, 0, 352 - RsFlag, 144 + RsFlag, 0, 95, 352 + RsFlag, 144 + RsFlag, 95, 95);
	} else {
		if (GetKeyHit() & 0x20) {
			se_play(5);
			if (D_000408E4 > 0)
				D_000408E4--;
		}
		if (GetKeyHit() & 0x80) {
			se_play(5);
			if (D_000408E4 < 2)
				D_000408E4++;
		}
		d100 = Round / 100;
		d10 = Round % 100 / 10;
		d1 = Round % 10;
		if (GetKeyHit() & 0x10) {
			se_play(4);
			switch (D_000408E4) {
			case 0:
				if (d1 < 9) {
					d1++;
					Round += 1;
				} else {
					d1 -= 9;
					Round -= 9;
				}
				break;
			case 1:
				if (d10 < 9) {
					d10++;
					Round += 10;
				} else {
					d10 -= 9;
					Round -= 90;
				}
				break;
			case 2:
				if (d100 < 5) {
					d100++;
					Round += 100;
				} else {
					d100 -= 5;
					Round -= 500;
				}
				break;
			}
		}
		if (GetKeyHit() & 0x40) {
			se_play(4);
			switch (D_000408E4) {
			case 0:
				if (d1 > 0 && Round > 0) {
					Round -= 1;
					d1--;
				} else {
					d1 += 9;
					Round += 9;
				}
				break;
			case 1:
				if (d10 > 0) {
					d10--;
					Round -= 10;
				} else {
					d10 += 9;
					Round += 90;
				}
				break;
			case 2:
				if (d100 > 0) {
					d100--;
					Round -= 100;
				} else {
					d100 += 5;
					Round += 500;
				}
				break;
			}
		}
		DrawSpriteEz(2.0f, 80.0f, 96.0f, 96.0f, 96.0f, 0.0f, 0.0f, 9);
		DrawSpriteEz(2.0f, 192.0f, 96.0f, 96.0f, 96.0f, 0.0f, 0.0f, 9);
		DrawSpriteEz(2.0f, 304.0f, 96.0f, 96.0f, 96.0f, 0.0f, 0.0f, 9);
		DrawSpriteEz(2.0f, 80.0f, 96.0f, 96.0f, 96.0f, r_num_u[d100], r_num_v[d100], 11);
		DrawSpriteEz(2.0f, 192.0f, 96.0f, 96.0f, 96.0f, r_num_u[d10], r_num_v[d10], 11);
		DrawSpriteEz(2.0f, 304.0f, 96.0f, 96.0f, 96.0f, r_num_u[d1], r_num_v[d1], 11);
		D_00154028 = (D_00154028 + 4) % 180;
		if (D_00154028 < 0)
			D_00154028 += 180;
		SetSpriteColorRGBA(255, 255, 255, 255);
		DrawSpriteEx(10, 2.0f, D_0002F670 - D_000408E4 * D_0002F670, -1.5f, 96.0f, 96.0f, 0, 0, 0, 0, 0, 0, 0, 0, (float)D_00154028 * 3.14f / 90.0f, 1.0f, 0);
		if (GetKeyHit() & 0x2008) {
			if (Round >= 501)
				se_play(2);
			else if (Round >= D_0101C3B8 + 1)
				se_play(2);
			else if (Round <= 0)
				se_play(2);
			else {
				ret = 7;
				SelectModeFlag = 2;
				se_play(1);
			}
		} else if (GetKeyHit() & 0x4000) {
			ret = 5;
			se_play(3);
		}
	}
	SpriteKick();
	return ret;
}

#ifdef NON_MATCHING
/* Close (one insn): the original computes num / 10 into a temporary and copies it to a saved register. */
void write_op_num(int x, int y, int num)
{
	if (num >= 10000)
		num = 9999;
	DrawSpriteEz(2.0f, x, y, 24.0f, 24.0f, num % 10 * 24, 0.0f, 13);
	if (num < 10)
		return;
	DrawSpriteEz(2.0f, x - 20, y, 24.0f, 24.0f, num / 10 % 10 * 24, 0.0f, 13);
	if (num < 100)
		return;
	DrawSpriteEz(2.0f, x - 40, y, 24.0f, 24.0f, num / 100 % 10 * 24, 0.0f, 13);
	if (num < 1000)
		return;
	DrawSpriteEz(2.0f, x - 60, y, 24.0f, 24.0f, num / 1000 % 10 * 24, 0.0f, 13);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", write_op_num);
#endif

int OptionInit(void) {
    return 0;
}

#ifdef NON_MATCHING
/* Byte-matches (fntest) but cannot be installed while the unit is mixed: its switch's
 * jump table must sit at D_0002F428, before the float literals of the C functions that
 * precede it.  Each two-way alpha/u choice is two separate calls (crossjumped). */
typedef struct {
	int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
} SaveData;
extern SaveData SaveDataBuf;
extern int D_0015402C;
extern int D_00154030;
extern int D_00154034;
extern int D_00154038;
extern int MsAccessFlag;
extern const int option_ch_x[];
extern const int option_ch_y[];
extern const int option_ch_w[];
extern const int option_ch_u[];
extern const int option_ch_v[];
int GetKeyHit(void);
void SpriteInit(void);
void SpriteKick(void);
void SpriteSetFader(float);
int se_play(int no);
int MsLoad2(void);
int MsSave2(void);
void write_op_num(int x, int y, int num);
int OptionMode(void)
{
	int ret;
	int key;
	int i;

	if (MsAccessFlag) {
		key = 0;
		SpriteSetFader(0.5f);
	} else {
		key = GetKeyHit();
		SpriteSetFader(1.0f);
	}
	SpriteInit();
	ret = 0;
	if (D_00154038)
		disp_title_bg(127);
	else
		disp_title_bg(255);
	DrawSpriteEz(2.0f, 140.0f, 8.0f, 200.0f, 48.0f, 0.0f, 96.0f, 7);
	DrawSpriteEz(2.0f, 148.0f, 248.0f, 184.0f, 24.0f, 0.0f, 0.0f, 8);
	if (D_00154030 == 0) {
		for (i = 0; i < 4; i++) {
			if (D_0015402C == i)
				SetSpriteColorRGBA(255, 255, 255, 255);
			else
				SetSpriteColorRGBA(255, 255, 255, 127);
			DrawSpriteEz(2.0f, option_ch_x[i], option_ch_y[i], option_ch_w[i], 32.0f, option_ch_u[i], option_ch_v[i], 12);
		}
		if (key & 0x40) {
			se_play(4);
			if (++D_0015402C >= 4)
				D_0015402C = 0;
		}
		if (key & 0x10) {
			se_play(4);
			if (--D_0015402C < 0)
				D_0015402C = 3;
		}
		SetSpriteColorRGBA(255, 255, 255, 255);
		switch (D_0015402C) {
		case 0:
			if (GetKeyHit() & 0x20A0) {
				SaveDataBuf.unk10 = 1 - SaveDataBuf.unk10;
				se_play(4);
			}
			if (SaveDataBuf.unk10 == 1)
				DrawSpriteEz(2.0f, 288.0f, 77.0f, 40.0f, 24.0f, 0.0f, 24.0f, 13);
			else
				DrawSpriteEz(2.0f, 288.0f, 77.0f, 40.0f, 24.0f, 40.0f, 24.0f, 13);
			break;
		case 1:
			if (GetKeyHit() & 0x2008) {
				se_play(4);
				D_00154030 = 1;
			}
			break;
		case 2:
			if (key & 0x2008)
				MsLoad2();
			break;
		case 3:
			if (GetKeyHit() & 0x2008) {
				se_play(4);
				MsSave2();
				D_0015402C = 4;
			}
			break;
		case 4:
			if (MsAccessFlag == 0) {
				ret = 5;
				D_0015402C = 3;
			}
			break;
		}
	} else {
		for (i = 4; i < 10; i++)
			DrawSpriteEz(2.0f, option_ch_x[i], option_ch_y[i], option_ch_w[i], 32.0f, option_ch_u[i], option_ch_v[i], 12);
		write_op_num(318, 84, SaveDataBuf.unk14);
		write_op_num(318, 112, SaveDataBuf.unk18);
		write_op_num(318, 140, SaveDataBuf.unk1C);
		SetSpriteColorRGBA(255, 255, 255, 127);
		if (D_00154034 == 0) {
			DrawSpriteEz(2.0f, 168.0f, 180.0f, 144.0f, 32.0f, 0.0f, 0.0f, 14);
			SetSpriteColorRGBA(255, 255, 255, 255);
			DrawSpriteEz(2.0f, 205.0f, 208.0f, 70.0f, 32.0f, 136.0f, 0.0f, 12);
		} else {
			DrawSpriteEz(2.0f, 205.0f, 208.0f, 70.0f, 32.0f, 136.0f, 0.0f, 12);
			SetSpriteColorRGBA(255, 255, 255, 255);
			DrawSpriteEz(2.0f, 168.0f, 180.0f, 144.0f, 32.0f, 0.0f, 0.0f, 14);
		}
		if (D_00154038 == 1) {
			DrawSpriteEz(0.0f, 0.0f, 100.0f, 240.0f, 104.0f, 0.0f, 0.0f, 15);
			DrawSpriteEz(0.0f, 240.0f, 100.0f, 240.0f, 104.0f, 240.0f, 0.0f, 15);
			if (GetKeyHit() & 0x2008) {
				SaveDataBuf.unk14 = 0;
				SaveDataBuf.unk18 = 0;
				SaveDataBuf.unk1C = 0;
				se_play(1);
				D_00154038 = 0;
			}
			if (GetKeyHit() & 0x4000) {
				se_play(3);
				D_00154038 = 0;
			}
		} else {
			if (GetKeyHit() & 0x50) {
				D_00154034 = 1 - D_00154034;
				se_play(4);
			}
			if (GetKeyHit() & 0x2008) {
				se_play(4);
				if (D_00154034 == 0)
					D_00154030 = 0;
				else
					D_00154038 = 1;
			}
		}
	}
	SpriteKick();
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", OptionMode);
#endif

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F648);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F64C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F650);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F654);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F658);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F65C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F660);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F664);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F668);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F66C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F670);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F674);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F678);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F68C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F69C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F6D0);
