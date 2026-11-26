/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
#include "PuzzleMain.h"

extern int ssTimes;
int DrawSpriteEz(float z, float x, float y, float w, float h, float u, float v, int no);
int PzlDataGetWidth(int no);
int GetKeyHit();                                    /* extern */
int PollShutter(M2C_UNK);                           /* extern */
extern int PauseFlag;
extern unsigned char PauseOk;
extern int StageNum;
extern int gim_bg_endress;
extern int ColorRndMaxVS;
extern int frame_anim[];
int SpriteDrawZoom(int no, int color, float z, float x, float y, float w, float h, float u, float v, float cx, float cy, float sx, float sy);
extern int ColorTableVS[];
extern int D_0014E92C;
int CvtBallPos2MapPos(PZL_STAT *st, int x, int y);
int CheckBallAround(PZL_STAT *st, int x, int y);
int CheckOneColorAll(PZL_STAT *st);
int GetBallMapAddr(PZL_STAT *st, int x, int y, int dir);
extern int gim_bg_puzzle[];
extern int gim_bg_vs[];
extern const u16 BallXPos[];
void SetPlayStatus(PZL_STAT *st, int a1, int no);
int CheckBallAroundRainbow(PZL_STAT *st, int x, int y, int n);
int CheckBallAroundRainbowTerm(PZL_STAT *st, int n);
typedef struct {
	int u, v, w, h, no;
} PARTZ;
typedef struct {
	int u, v, w, h, no, flag;
} SPRDATA;
extern const SPRDATA SCORE_NUMERIC_PARTZ[];
extern const SPRDATA NUMERIC_PARTZ[];
extern const SPRDATA D_0002DEB4[];
extern const SPRDATA D_0002E0F4[];
extern const SPRDATA LIGHT_PARTZ[];
extern int D_00038A8C[];
int GetRound(void);
void GameValueInit(int pl, int stage, int flag);
void dsGMInit(int mode, int a1);
extern PARTZ ChrData_ClearMes[];
void DrawCharcter(int z, int x, int y, PARTZ *tbl, int idx);
void DrawCharcter2(int z, int x, int y, PARTZ *tbl, int idx);
void SetSpriteColorRGBA(int r, int g, int b, int a);
int se_play(int no);
void PutNumeric(int z, int x, int y, int num, int digits);
int Get2Dim(int x, int a, int b, int c, int d);
int SpriteDraw(int no, float z, int color, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3);
int DrawSpritePt4(int no, float z, int color, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3);
int SpriteDrawC(float z, int x, int y, const SPRDATA *p);
int EndressValueInit(int, int, int);
void SpriteSetFader(float);
int LoadGimFile(int no, int file);
int bgm_play(int no);
int SpriteDrawEz(int no, float z, int color, float x, float y, float w, float h, float u, float v);
int GetBallNext(PZL_STAT *st, int flag);
extern int isSurvival;
extern int SurvCont;
extern int SelectPlayer;
extern int gimfile_main[];
extern int gimfile_bubble[];
extern const int mx[];
extern const int my[];
extern int D_0014E86C;
extern int D_0014E870;
extern int D_0014E874;
extern int D_0014E878;
extern int D_0014E87C;
extern int D_0014E880;
extern int D_0014E884;
void LoadFileList(int no, int *list);
void SpriteAllFreeImage(void);
void VSModeInit(int);
void SurvivlaModeInit(int);
void EndressModeInit(void);
void VSInit(void);
void InitBubCrush(void);
void SetMonitor(PZL_STAT *st, int mon);
int CvtBallPos2MapPosLocal(PZL_STAT *st, int x, int y);
int CheckNext(PZL_STAT *st);
int rand(void);


int SysTimeIncrement(void)
{
	if (PauseFlag == 0)
		ssTimes++;
}

int GetSysTime(void) {
    return ssTimes;
}

void ClearSysTime(void) {
    ssTimes = 0;
}

void SetCharacters(PZL_STAT *st, int chara, int which)
{
	if (which == 0 && st->chara != chara) {
		st->chara = chara;
		st->chara_anim = 0;
	}
	if (which == 1)
		st->chara2 = chara;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoCharacters);

void SetMonitor(PZL_STAT *st, int mon)
{
	if (mon == 12) {
		if (st->monitor >= 15 && st->monitor <= 17)
			return;
		if (st->monitor == 14)
			return;
	}
	st->monitor = mon;
	st->monitor_anim = 0;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", ChNamePos);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", mx);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", my);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", MapXBeginPos);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", BallXPos);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PAUSE_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SAVE_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", NEW_RECORD_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PUZZLE_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002DE0C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002DE9C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002DEB4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002DFD4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", NUMERIC_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E0F4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", ATTACK_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E124);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", WINLOSE_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E16C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SCORE_NUMERIC_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GAMEMODE_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E28C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E2A4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E2BC);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", LIGHT_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E334);

extern SPRDATA D_00038A30;
void DoMonitor(PZL_STAT *st)
{
	int tbl[6] = { 0, 3, 4, 1, 2, 5 };
	int pat = 3;
	int next = GetBallLine(st) < 8 ? 0 : 18;

	switch (st->monitor) {
	case 0:
		pat = 0;
		if (++st->monitor_anim >= 7) {
			st->monitor_anim = 0;
			if (rand() % 30 == 0)
				st->monitor = 3;
			else
				st->monitor = 1;
		}
		break;
	case 1:
		pat = 1;
		if (++st->monitor_anim >= 7) {
			st->monitor = 2;
			st->monitor_anim = 0;
		}
		break;
	case 2:
		pat = 2;
		if (++st->monitor_anim >= 7) {
			st->monitor = next;
			st->monitor_anim = 0;
		}
		break;
	case 3:
		pat = tbl[st->player] * 5 + 4;
		if (++st->monitor_anim >= 26) {
			st->monitor = next;
			st->monitor_anim = 0;
		}
		break;
	case 4:
		if (++st->monitor_anim >= 31) {
			st->monitor++;
			st->monitor_anim = 0;
		}
	case 5:
	case 6:
		pat = st->monitor + 1;
		if (++st->monitor_anim >= 5) {
			st->monitor++;
			st->monitor_anim = 0;
		}
		break;
	case 7:
		pat = 8;
		break;
	case 8:
		pat = 13;
		if (--st->monitor_anim < 0) {
			int r = rand();

			st->monitor_anim = 4;
			st->monitor = r % 3 + 9;
		}
		break;
	case 9:
	case 10:
		pat = st->monitor + 1;
		if (--st->monitor_anim < 0) {
			st->monitor++;
			st->monitor_anim = 4;
		}
		break;
	case 11:
		pat = st->monitor + 1;
		if (--st->monitor_anim < 0) {
			st->monitor = 8;
			st->monitor_anim = rand() % 60 + 30;
		}
		break;
	case 12:
	case 13:
		pat = st->monitor + 3;
		if (++st->monitor_anim >= 5) {
			st->monitor++;
			st->monitor_anim = 0;
		}
		break;
	case 14:
		pat = 17;
		if (++st->monitor_anim >= 46) {
			st->monitor = next;
			st->monitor_anim = 0;
		}
		break;
	case 15:
	case 16:
		pat = st->monitor + 5;
		if (++st->monitor_anim >= 5) {
			st->monitor++;
			st->monitor_anim = 0;
		}
		break;
	case 17:
		pat = 22;
		if (++st->monitor_anim >= 46) {
			st->monitor = next;
			st->monitor_anim = 0;
		}
		break;
	case 18:
		pat = 25;
		if (++st->monitor_anim >= 5) {
			st->monitor = 19;
			st->monitor_anim = 0;
		}
		break;
	case 19:
		pat = 26;
		if (++st->monitor_anim >= 5) {
			st->monitor = 20;
			st->monitor_anim = 0;
		}
		break;
	case 20:
		pat = 27;
		if (++st->monitor_anim >= 5) {
			st->monitor = next;
			st->monitor_anim = 0;
		}
		break;
	case 21:
	case 22:
		pat = st->monitor + 9;
		if (++st->monitor_anim >= 7) {
			st->monitor++;
			st->monitor_anim = 0;
		}
		break;
	case 23:
		pat = 32;
		if (++st->monitor_anim >= 31) {
			st->monitor = next;
			st->monitor_anim = 0;
		}
		break;
	case 24:
		pat = tbl[st->player] * 5 + 4;
		break;
	}
	D_00038A30.u = (pat % 5) * 88;
	D_00038A30.v = (pat / 5) * 64;
	if (st->mapsub < 2)
		SpriteDrawC(0.0f, 50, 241, &D_00038A30);
	else
		SpriteDrawC(0.0f, 430, 241, &D_00038A30);
}

void DoReadyGo(PZL_STAT *st)
{
	int x;

	if (st->unk430 == 4) {
		se_play(26);
		if (st->chara == 5)
			SetCharacters(st, 0, 0);
		SetMonitor(st, 0);
	}
	if (st->unk430 == 61) {
		PollShutter(2);
		se_play(27);
		ClearSysTime();
	}
	if ((unsigned int)st->unk430 < 90) {
		x = Get2Dim(st->unk430, 5, 25, 45, 65);
		DrawCharcter(0, x + 72, 116, ChrData_ClearMes, 1);
	}
	if ((unsigned int)st->unk430 - 41 < 79) {
		x = Get2Dim(st->unk430, 50, 62, 85, 100);
		DrawCharcter(0, x + 152, 112, ChrData_ClearMes, 2);
	}
}

int DoContinue(int t, int flag)
{
	int r;
	PARTZ *tbl;

	r = Get2Dim(t, 0, 20, 100, 100);
	tbl = ChrData_ClearMes;
	DrawCharcter(0, r + 40, 60, tbl, 4);
	r = Get2Dim(t, 12, 32, 100, 100);
	if (flag) {
		SetSpriteColorRGBA(255, 255, 255, 111);
		DrawCharcter2(0, r + 112, 120, tbl, 5);
		SetSpriteColorRGBA(255, 255, 255, 255);
	} else {
		SetSpriteColorRGBA(255, 255, 255, 255);
		DrawCharcter2(0, r + 112, 120, tbl, 5);
		SetSpriteColorRGBA(255, 255, 255, 111);
	}
	t++;
	DrawCharcter2(0, r + 272, 120, tbl, 6);
	SetSpriteColorRGBA(255, 255, 255, 255);
	if (t > 60)
		t = 60;
	return t;
}

void InitBubCrush(void)
{
	int i;

	for (i = 0; i < 1024; i++) {
		bubx[i] = 0;
		buby[i] = 0;
		bubcnt[i] = 0;
		bubcol[i] = 0;
	}
}

void SetBubCrush(int x, int y, int col)
{
	int i;

	for (i = 0; i < 1024; i++) {
		if (bubcnt[i] == 0) {
			bubx[i] = x;
			buby[i] = y;
			bubcol[i] = col;
			bubcnt[i] = 16;
			return;
		}
	}
}

void SetBubCrushEz(PZL_STAT *st, int x, int y, int col)
{
	SetBubCrush(x + MapXBeginPos[st->mapno * 3 + st->mapsub] - 8, y + st->ofs_y + st->scroll * 14 + 32, col);
}



INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", bgmsort);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", BallCollisionPosition);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E508);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E5AC);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E5C8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E5DC);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E5F0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E694);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SHUTTER_PARTZ);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E750);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoBubCrush);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PuzzleInit);

int PuzzleMain(void)
{
	int ret = 0;
	int r;
	int i;
	PZL_SND *snd;

	SysTimeIncrement();
	SpriteInit();
	Stat[1].snd.se = -1;
	Stat[0].snd.se = -1;
	r = PuzzleBody();
	if (r != 0) {
		ret = r;
		bgm_stop();
	}
	for (i = 0, snd = &Stat[0].snd; i < 3; i++, snd = (void *)((u8 *)snd + sizeof(PZL_STAT))) {
		if (snd->se > 0) {
			se_play(snd->se);
			snd->se = -1;
		}
	}
	SpriteKick();
	return ret;
}

#ifdef NON_MATCHING
/* Close: the two (x + 3) % 6 temporaries get a3/t0 swapped. */
void VSValueInit(int pl, int a1, int flag);
extern const int bgmsort[];
void VSModeInit(int cont)
{
	int enemy = Stat[2].player;
	int n;
	s8 sel;

	if (cont) {
		enemy++;
		enemy %= 6;
	}
	VSValueInit(1, 0, 0);
	VSValueInit(2, 0, 0);
	SpriteSetFader(1.0f);
	sel = *(s8 *)&SelectPlayer;
	Stat[1].snd.unk2 = (sel + 3) % 6;
	Stat[2].snd.unk2 = ((s8)enemy + 3) % 6;
	Stat[1].player = sel;
	Stat[2].player = enemy;
	Stat[1].cur = GetBallNext(&Stat[1], 0);
	n = GetBallNext(&Stat[1], 0);
	Stat[2].cur = Stat[1].cur;
	Stat[1].next = n;
	Stat[2].next = n;
	LoadGimFile(0, gim_bg_vs[isSurvival * 6 + Stat[2].player]);
	bgm_play(bgmsort[Stat[2].player % 6]);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSModeInit);
#endif

void VSInit(void)
{
	isSurvival = 0;
	StageNum = 0;
	SpriteAllFreeImage();
	LoadFileList(1, gimfile_main);
	LoadFileList(50, gimfile_bubble);
	VSModeInit(0);
	PollShutter(3);
	Stat[1].player = SelectPlayer;
	Stat[2].player = 0;
	InitBubCrush();
}

#ifdef NON_MATCHING
/* Close: the Stat base and enemy get swapped callee-saved registers. */
void SurvValueInit(void);
void VSValueInit(int pl, int a1, int flag);
extern const int bgmsort[];
void SurvivlaModeInit(int cont)
{
	int enemy = Stat[2].player;
	int n;
	s8 sel;

	if (cont)
		enemy = (enemy + 1) % 6;
	SurvValueInit();
	VSValueInit(2, 0, 0);
	SpriteSetFader(1.0f);
	Stat[1].cur = GetBallNext(&Stat[1], 0);
	n = GetBallNext(&Stat[1], 0);
	Stat[2].cur = Stat[1].cur;
	sel = *(s8 *)&SelectPlayer;
	Stat[1].snd.unk2 = (sel + 3) % 6;
	Stat[2].snd.unk2 = ((s8)enemy + 3) % 6;
	Stat[1].player = sel;
	Stat[2].player = enemy;
	Stat[1].next = n;
	Stat[2].next = n;
	LoadGimFile(0, gim_bg_vs[6 + (s8)enemy]);
	bgm_play(bgmsort[Stat[2].player % 6]);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvivlaModeInit);
#endif

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvivalInit);

int VSMain(void)
{
	int ret = 0;
	int r;
	int i;
	PZL_SND *snd;

	SysTimeIncrement();
	SpriteInit();
	Stat[1].snd.se = -1;
	Stat[0].snd.se = -1;
	VSModeBody(2);
	r = VSModeBody(1);
	if (r != 0) {
		ret = r;
		bgm_stop();
	}
	for (i = 0, snd = &Stat[0].snd; i < 3; i++, snd = (void *)((u8 *)snd + sizeof(PZL_STAT))) {
		if (snd->se > 0) {
			se_play(snd->se);
			snd->se = -1;
		}
	}
	SpriteKick();
	return ret;
}

void EndressModeInit(void)
{
	EndressValueInit(1, 0, 0);
	SpriteSetFader(1.0f);
	Stat[1].cur = GetBallNext(&Stat[1], 0);
	Stat[1].next = GetBallNext(&Stat[1], 0);
	Stat[1].player = SelectPlayer;
	LoadGimFile(0, gim_bg_endress);
	bgm_play(4);
	SetMonitor(&Stat[2], 8);
}

void EndressInit(void)
{
	SpriteAllFreeImage();
	LoadFileList(1, gimfile_main);
	LoadFileList(50, gimfile_bubble);
	EndressModeInit();
	PollShutter(3);
	Stat[1].player = SelectPlayer;
	SetMonitor(&Stat[2], 8);
	InitBubCrush();
}

int EndressMain(void)
{
	int ret = 0;
	int r;
	int i;
	PZL_SND *snd;

	SysTimeIncrement();
	SpriteInit();
	Stat[1].snd.se = -1;
	Stat[0].snd.se = -1;
	r = EndressBody(0);
	if (r != 0) {
		ret = r;
		bgm_stop();
	}
	for (i = 0, snd = &Stat[0].snd; i < 3; i++, snd = (void *)((u8 *)snd + sizeof(PZL_STAT))) {
		if (snd->se > 0) {
			se_play(snd->se);
			snd->se = -1;
		}
	}
	SpriteKick();
	return ret;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawBubble);

void DrawCharcter(int z, int x, int y, PARTZ *tbl, int idx)
{
	PARTZ *p = (PARTZ *)(idx * sizeof(PARTZ) + (int)tbl);

	DrawSpriteEz(z, x, y, p->w, p->h, p->u, p->v, p->no);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawCharcterFlip);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawCharcter2);

void DrawAnk(int z, int x, int y, int num)
{
	int i;

	for (i = 0; i < 4; i++) {
		SpriteDrawEz(num % 10 + 28, z, -1, x + 19 - i * 19, y - 16, 24.0f, 32.0f, 0, 0);
		num /= 10;
	}
}

void DrawScore(int z, int x, int y, int num)
{
	int i;

	for (i = 0; i < 9; i++) {
		SpriteDrawC(z, x + 35 - i * 10, y - 6, &SCORE_NUMERIC_PARTZ[num % 10]);
		num /= 10;
	}
}

void DrawCount(int z, int x, int y, int num)
{
	int i;

	for (i = 0; i < 3; i++) {
		SpriteDrawC(z, x + 5 - i * 10, y - 6, &SCORE_NUMERIC_PARTZ[num % 10]);
		num /= 10;
	}
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", Sin);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", Cos);

void ZeroMemory(void *p, int size)
{
	int i;

	for (i = 0; i < size; i++)
		((s8 *)p)[i] = 0;
}

int GetMapWidth(int no)
{
	return PzlDataGetWidth(no);
}

int GetMapLeft(int no)
{
	return 160 - GetMapWidth(no) * 8;
}

int GetMapRight(int no)
{
	return GetMapWidth(no) * 8 + 160;
}


#ifdef NON_MATCHING
/* Close: the SelectPlayer and BallXPos loads come out in the opposite order. */
void GameValueInit(int pl, int stage, int flag)
{
	PZL_STAT *st;
	u8 save428;
	int save434;

	if ((unsigned int)pl > 1)
		pl = 0;
	st = &Stat[pl];
	save428 = st->unk428;
	ZeroMemory(st, sizeof(PZL_STAT));
	st->scroll = -18;
	st->unk00E = 600;
	st->player = SelectPlayer;
	st->bx = BallXPos[pl];
	st->by = 0x1CC;
	st->unk45F = 0;
	st->unk454 = 0;
	st->unk023 = 0;
	st->unk027 = 8;
	st->unk026 = 8;
	st->unk430 = 0;
	save434 = st->unk434;
	if (flag < 0)
		st->unk428 = save428;
	else
		st->unk428 = flag != 0;
	if (stage >= 0)
		StageNum = stage;
	st->unk434 = save434;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GameValueInit);
#endif

extern int OjamaStock[3];
extern int WinStack[3];
extern int OjamaCnt[3];
extern int OjamaPos[3][8];
extern int OjamaCol[3][8];

void VSValueInit(int pl, int a1, int flag)
{
	PZL_STAT *st;
	u8 save428;
	int save434;
	int i, j;

	if (pl < 1 || pl > 2)
		pl = 1;
	st = &Stat[pl];
	save428 = st->unk428;
	save434 = st->unk434;
	ZeroMemory(st, sizeof(PZL_STAT));
	st->unk45F = 1;
	st->scroll = -5;
	st->bx = BallXPos[pl];
	st->by = 0x116;
	st->unk00E = 600;
	st->unk454 = 0;
	st->unk023 = 0;
	st->unk027 = 8;
	st->unk026 = 8;
	st->unk430 = 0;
	if (flag < 0)
		st->unk428 = save428;
	else
		st->unk428 = flag != 0;
	st->unk434 = save434;
	dsGMInit(pl, StageNum);
	for (i = 0; i < 3; i++) {
		OjamaStock[i] = 0;
		WinStack[i] = 0;
		OjamaCnt[i] = 0;
		for (j = 0; j < 8; j++) {
			OjamaPos[i][j] = 0;
			OjamaCol[i][j] = 0;
		}
	}
}

void SurvValueInit(void)
{
	int pl = 1;
	PZL_STAT *st = &Stat[pl];
	PZL_STAT tmp;
	int i, j;

	st->unk428 = 0;
	tmp = *st;
	ZeroMemory(st, sizeof(PZL_STAT));
	st->scroll = tmp.scroll;
	for (i = 0; i < MAP_SIZE; i++)
		st->mp.map[i] = tmp.mp.map[i];
	st->unk45F = 1;
	st->by = 0xD0 - st->scroll * 14;
	st->unk00E = 600;
	st->unk430 = 0;
	st->unk454 = 0;
	st->unk023 = 0;
	st->unk027 = 8;
	st->unk026 = 8;
	st->bx = BallXPos[1];
	for (i = 0; i < 3; i++) {
		OjamaStock[i] = 0;
		WinStack[i] = 0;
		OjamaCnt[i] = 0;
		for (j = 0; j < 8; j++) {
			OjamaPos[i][j] = 0;
			OjamaCol[i][j] = 0;
		}
	}
}

extern int ColorTable[];
extern int ColorRndMax;
/* int with no return value: callers were built against an int (implicit) declaration */
int EndressValueInit(int pl, int stage, int flag)
{
	PZL_STAT *st;
	u8 save428;
	int save434;
	int i, j, k;

	if (pl < 1 || pl > 2)
		pl = 1;
	st = &Stat[pl];
	save428 = st->unk428;
	save434 = st->unk434;
	ZeroMemory(st, sizeof(PZL_STAT));
	st->scroll = -5;
	st->bx = 160;
	st->by = 0x116;
	st->unk00E = 600;
	st->unk45F = 0;
	st->unk454 = 0;
	st->unk023 = 0;
	st->unk027 = 8;
	st->unk026 = 8;
	st->unk430 = 0;
	if (flag < 0)
		st->unk428 = save428;
	else
		st->unk428 = flag != 0;
	if (stage >= 0)
		StageNum = stage;
	st->unk434 = save434;
	dsGMInit(pl, StageNum);
	for (i = 0; i < 242; i++)
		st->mp.map[i] = 0;
	st->mp.map[33] = 13;
	for (i = 0; i < 11; i++) {
		st->mp.map[44 + i] = 12;
		st->mp.map[66 + i] = ColorTable[rand() % ColorRndMax];
	}
	for (i = 0; i < 10; i++) {
		st->mp.map[55 + i] = ColorTable[rand() % ColorRndMax];
		st->mp.map[77 + i] = ColorTable[rand() % ColorRndMax];
	}
	st->scroll = -5;
	for (k = 0; k < 3; k++) {
		OjamaStock[k] = 0;
		WinStack[k] = 0;
		OjamaCnt[k] = 0;
		for (j = 0; j < 8; j++) {
			OjamaPos[k][j] = 0;
			OjamaCol[k][j] = 0;
		}
	}
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawMapData);

#ifdef NON_MATCHING
/* Close: operand order of the row address. */
void SetBallMapReverse(PZL_STAT *dst, PZL_STAT *src)
{
	int x, y;
	u8 *sm = src->mp.map;
	u8 *dm = dst->mp.map;

	for (y = 0; y < 18; y++) {
		for (x = 0; x < 8; x++) {
			dm[y / 2 * 2 - y + y * 8 + 7 - x] = sm[y * 8 + x];
			if ((y & 1) && x == 6)
				break;
		}
	}
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBallMapReverse);
#endif

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBallMap);

void SetBallMapReverse(PZL_STAT *dst, PZL_STAT *src);
int PzlDataExist(int no);
u8 *PzlDataExtract(int no);
u8 *GetMapTable(int no);
int SetBallMap(u8 *map, u8 *data);
void SetPlayStatus(PZL_STAT *st, int stage, int pl)
{
	int i;
	u8 *data;

	st->ofs_y = 32;
	st->unk454 = 256;
	if (pl == 0) {
		if (PzlDataExist(stage))
			data = PzlDataExtract(stage);
		else
			data = GetMapTable(stage);
		st->mapno = SetBallMap(st->mp.map, data);
		st->mapsub = 0;
		return;
	}
	if (!isSurvival || SurvCont) {
		if (pl == 1) {
			st->mapsub = pl;
			st->mapno = 0;
			for (i = 0; i < 176; i++)
				st->mp.map[i] = 0;
			st->mp.map[16] = 13;
			for (i = 0; i < 7; i++) {
				st->mp.map[24 + i] = 12;
				st->mp.map[40 + i] = ColorTableVS[rand() % ColorRndMaxVS];
			}
			for (i = 0; i < 8; i++) {
				st->mp.map[32 + i] = 12;
				st->mp.map[48 + i] = ColorTableVS[rand() % ColorRndMaxVS];
			}
			st->scroll = -5;
		} else {
			SetBallMapReverse(st, &Stat[1]);
			st->mapsub = 2;
		}
	} else if (pl == 1) {
		st->mapsub = pl;
	} else {
		st->mapno = 0;
		st->mapsub = 2;
		for (i = 0; i < 176; i++)
			st->mp.map[i] = 0;
		st->mp.map[16] = 13;
		for (i = 0; i < 7; i++) {
			st->mp.map[24 + i] = 12;
			st->mp.map[40 + i] = ColorTableVS[rand() % ColorRndMaxVS];
		}
		for (i = 0; i < 8; i++) {
			st->mp.map[32 + i] = 12;
			st->mp.map[48 + i] = ColorTableVS[rand() % ColorRndMaxVS];
		}
		st->scroll = -5;
	}
}

void dsGMInit(int mode, int a1)
{
	PZL_STAT *st;
	int i;

	if (mode == 0) {
		st = &Stat[0];
		SetPlayStatus(st, a1, 0);
		LoadGimFile(0, gim_bg_puzzle[StageNum / 10]);
	} else {
		st = &Stat[1];
		SetPlayStatus(st, a1, 1);
		st++;
		SetPlayStatus(st, a1, 2);
		LoadGimFile(0, gim_bg_vs[isSurvival * 6 + st->player]);
	}
	st->unk458 = 0;
	for (i = 0; i < 192; i++)
		st->ent[i].flag = 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetBallNext);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallTouch);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallCollision);

int CvtBallPos2MapPos(PZL_STAT *st, int x, int y)
{
	int lx = (st->bx - MapXBeginPos[st->mapno * 3 + st->mapsub]) + x;
	int ly = (st->by - st->ofs_y) + y;
	return CvtBallPos2MapPosLocal(st, lx, ly);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CvtBallPos2MapPosLocal);

int GetBallMapAddr(PZL_STAT *st, int x, int y, int dir)
{
	D_0014E878 = GetMapWidth(st->mapno) * 16;
	if (dir < 0)
		dir = 0;
	else if (dir >= 7)
		dir = 6;
	D_0014E870 = x + mx[dir];
	D_0014E874 = y + my[dir];
	if (D_0014E870 < 0 || D_0014E874 < 0 || D_0014E870 >= D_0014E878)
		D_0014E86C = -1;
	else
		D_0014E86C = CvtBallPos2MapPosLocal(st, D_0014E870, D_0014E874);
	return D_0014E86C;
}

void GetBallCoordinate(PZL_STAT *st, int idx, int *x, int *y)
{
	int line;

	D_0014E880 = GetMapWidth(st->mapno);
	D_0014E87C = idx % (D_0014E880 * 2);
	line = idx / (D_0014E880 * 2);
	*y = (line * 2 + D_0014E87C / D_0014E880 - D_0014E884) * 14;
	*x = (D_0014E87C < D_0014E880) ? D_0014E87C * 16 : (D_0014E87C - D_0014E880) * 16 + 8;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallAround);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallAroundRainbow);

int CheckBallAroundRainbowTerm(PZL_STAT *st, int n)
{
	int i, dir, a;
	int cnt = 0;
	int ret = 0;
	int x, y;
	u8 col;

	for (i = 0; i < 0x22E; i++) {
		GetBallCoordinate(st, i, &x, &y);
		if (st->attr[i] != 0) {
			st->rainbow[i] = 0;
			cnt++;
			st->unk434++;
			col = st->mp.map[i];
			st->mp.map[i] = 0;
			for (dir = 1; dir < 7; dir++) {
				a = GetBallMapAddr(st, x, y, dir);
				if (st->mp.map[a] == 13) {
					st->mp.map[a] = col;
					ret++;
					st->rainbow[a] = 1;
					st->drop.unk1 = 1;
					st->snd.se = 24;
				}
			}
		}
	}
	st->unk429 = cnt == 3;
	return ret;
}

int CheckBallRainbow(PZL_STAT *st)
{
	int i, j;
	int n;
	int x, y;

	st->drop.unk1 = 0;
	for (j = 0; j < 0x22E; j++)
		st->attr[j] = 0;
	n = 0;
	for (i = 0; i < 0x22E; i++) {
		if (st->rainbow[i] != 0 && (u8)(st->mp.map[i] - 1) < 8) {
			GetBallCoordinate(st, i, &x, &y);
			n = CheckBallAroundRainbow(st, x, y, n);
		}
	}
	if (n >= 3) {
		CheckBallAroundRainbowTerm(st, n);
		return n;
	}
	return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckNext);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallDrop);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckChain);


void TermChain(PZL_STAT *st)
{
	int i;

	for (i = 0; i < MAP_SIZE; i++) {
		if (st->mp.map[i] == 0x68)
			st->mp.map[i] = 0;
	}
}

#ifdef NON_MATCHING
/* Close: the original addresses the drop entry as st + n * 6 + 0x480 with offsets from 4. */
int CheckOneColorAll(PZL_STAT *st)
{
	int n = 0;
	int i;
	u8 col = st->color;
	int x, y;
	PZL_DROP *d;

	st->unk429 = 0;
	if (col >= 1 && col <= 9) {
		for (i = 0; i < 0x22E; i++) {
			if (st->mp.map[i] == col || st->attr[i] == 2) {
				n++;
				GetBallCoordinate(st, i, &x, &y);
				d = &st->drop.d[st->ndrop];
				d->x = x;
				d->flag = 0;
				d->y = y;
				d->col = col;
				st->mp.map[i] = 0;
				st->ndrop++;
			}
		}
	}
	return n;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckOneColorAll);
#endif

int CheckRoundClear(PZL_STAT *st)
{
	int i, ret, found;

	ret = 0;
	i = 0;
	found = 0;
	do {
		if ((st->mp.map[i] >= 1 && st->mp.map[i] <= 9) || st->mp.map[i] == 13) {
			found = 1;
			break;
		}
		i++;
	} while (i < 0x22E);
	if (!found)
		ret = 1;
	return ret;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallGuide);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallGuideVS);

extern int D_0014E8B4;
int CheckGuideLine(PZL_STAT *st)
{
	int key;
	int ret;
	int done = 0;
	s16 a;

	if (st->unk006 != 0x18) {
		key = st->key;
		if (key & 0x40) {
			if (st->unk454 < 256)
				key |= 0x80;
			else
				key |= 0x20;
		}
		if (key & 0x10) {
			if (st->unk454 >= 252 && st->unk454 <= 260) {
				st->unk454 = 256;
				st->unk47F = 1;
				st->drop.unk2 = 0;
			} else if (st->unk454 < 252) {
				st->unk454 += 4;
				st->unk47F = 1;
				st->drop.unk2 = 0;
			} else if (st->unk454 > 260) {
				st->unk454 -= 4;
				st->unk47F = 1;
				st->drop.unk2 = 0;
			}
			done = 1;
		} else if (key & 0x20) {
			st->unk454 += 4;
			if (st->unk454 >= 500)
				st->unk454 = 500;
			else
				st->unk47F = 1;
			st->drop.unk2 = 0;
			done = 1;
		} else if (key & 0x80) {
			st->unk454 -= 4;
			if (st->unk454 < 13)
				st->unk454 = 12;
			else
				st->unk47F = 1;
			st->drop.unk2 = 0;
			done = 1;
		}
	}
	if (!done) {
		key = st->key_rep;
		if (key & 0x200) {
			st->unk454 += 1;
			if (st->unk454 >= 500)
				st->unk454 = 500;
			else
				st->unk47F = 1;
			st->drop.unk2 = 0;
		} else if (key & 0x100) {
			st->unk454 -= 1;
			if (st->unk454 < 13)
				st->unk454 = 12;
			else
				st->unk47F = 1;
			st->drop.unk2 = 0;
		} else if (st->drop.unk2 == 0) {
			st->drop.unk2 = 1;
		}
	}
	ret = 0;
	if (st->unk47F) {
		ret = 1;
		if (st->unk006 < 0x18 && D_0014E8B4 == 0) {
			se_play(21);
			D_0014E8B4 = 5;
		}
	}
	if (D_0014E8B4 > 0)
		D_0014E8B4--;
	return ret;
}

void DriveBub(void) {
}

void DriveReadyGo(void) {
}

int GetBallLine(PZL_STAT *st)
{
	int w = GetMapWidth(st->mapno);
	int line, i;

	for (line = 32; line >= 0; line--) {
		for (i = 0; i < w; i++) {
			if (st->mp.map[i + line * w] >= 1 && st->mp.map[i + line * w] <= 11)
				return line + st->scroll;
		}
	}
	return st->scroll;
}

void PutNumeric(int z, int x, int y, int num, int digits)
{
	int i;

	if (num < 0)
		num = -num;
	for (i = 0; i < digits; i++) {
		SpriteDrawC(z, x + (digits - 1) * 11 - i * 22, y, &NUMERIC_PARTZ[num % 10]);
		num /= 10;
	}
}

void PutTime(int z, int x, int y, int t)
{
	PutNumeric(z, x + 54, y, t % 60, 2);
	t /= 60;
	PutNumeric(z, x, y, t % 60, 2);
	t /= 60;
	PutNumeric(z, x - 54, y, t % 60, 2);
	SpriteDrawC(z, x + 28, y, D_0002E0F4);
	SpriteDrawC(z, x - 28, y, D_0002E0F4);
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", Get2Dim);

void DoBubStat(PZL_STAT *st, int arg)
{
	st->bubstat_arg = arg;
	st->bubstat = 1;
}

void SetBubStat(PZL_STAT *st)
{
	int line = GetBallLine(st);

	st->bubline = line < 7 ? 0 : line < 9 ? 1 : 2;
}


void DriveWarning(void) {
}

void PauseControl(void *arg0) {
    if (M2C_FIELD(arg0, unsigned char *, 3) != 2) {
        if ((unsigned char) M2C_FIELD(arg0, unsigned char *, 6) < 0x15U) {
            PauseOk = 1;
        } else {
            PauseOk = 0;
        }
        if ((unsigned char) M2C_FIELD(arg0, unsigned char *, 6) >= 2U) {

        } else {
            if (PollShutter(5) != 0) {
                PauseOk = 0;
            }
            if ((unsigned int) M2C_FIELD(arg0, unsigned int *, 0x430) < 0x3CU) {
                PauseOk = 0;
            }
        }
        if (PauseFlag == 0) {
            if (PauseOk == 0) {

            } else if (GetKeyHit() & 8) {
                PauseFlag = 1;
            }
        } else if (GetKeyHit() & 8) {
            PauseFlag = 0;
        }
    }
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PuzzleBody);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CPUThinking);

int GetOjamaPat(int mode)
{
	int pat = 13;

	switch (mode) {
	case 0:
		if (rand() % 70 >= 10) {
			pat = ColorTableVS[rand() % ColorRndMaxVS];
		} else {
			if (!(rand() & 1))
				pat = 11;
		}
		break;
	case 1:
		if (rand() % 70 < 25)
			pat = 11;
		break;
	case 2:
		pat = (rand() % 70 < 20) ? 9 : 11;
		break;
	}
	return pat;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSModeBody);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressBody);

void MonitorPut(PZL_STAT *st)
{
	if (st->mapsub < 2) {
		D_0014E92C = (D_0014E92C + 3) % 60;
		SpriteDrawC(1.0f, 50, 241, &D_0002DEB4[D_0014E92C / 20]);
		SpriteDrawC(1.0f, 430, 241, &D_0002DEB4[4 + D_0014E92C / 15]);
	}
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PollShutter);

void DrawLight(int x, int y, int col, int no)
{
	int a, b;

	D_00038A8C[no] = (D_00038A8C[no] + 1) % 48;
	a = D_00038A8C[no] / 3 % 4;
	b = D_00038A8C[no] / 6 % 4;
	SpriteDrawC(1.0f, x, y, &LIGHT_PARTZ[a + (col + 1) * 4]);
	if (!(no & 1))
		SpriteDrawC(1.0f, x, y, &LIGHT_PARTZ[b]);
}

extern const SPRDATA PUZZLE_PARTZ[];
extern const SPRDATA GAMEMODE_PARTZ[];
extern const int ChNamePos[];
extern int D_0014E93C;
extern int D_0014E940;
void DoCharacters(PZL_STAT *st);
void DoMonitor(PZL_STAT *st);
void disp_game_bg(void)
{
	PZL_STAT *st = Stat;

	DrawSpriteEz(1.0f, 0.0f, 0.0f, 480.0f, 32.0f, 0.0f, 0.0f, 0);
	SpriteDrawC(1.0f, 200, 16, GAMEMODE_PARTZ);
	DrawScore(1, 300, 22, st->unk434);
	DoCharacters(st);
	DrawLight(38, 79, 0, 0);
	DrawLight(65, 52, 0, 1);
	DrawLight(442, 79, 0, 2);
	DrawLight(415, 52, 0, 3);
	DoMonitor(st);
	DoMonitor(st + 2);
	D_0014E93C = (D_0014E93C + 1) % 50;
	SpriteDrawC(2.0f, 52, 216, &PUZZLE_PARTZ[6]);
	SpriteDrawC(2.0f, 428, 216, &PUZZLE_PARTZ[8]);
	SpriteDrawC(1.0f, 44, 28, &PUZZLE_PARTZ[2 + D_0014E93C / 25]);
	SpriteDrawC(1.0f, 436, 28, &PUZZLE_PARTZ[4 + D_0014E93C / 25]);
	SpriteDrawC(2.0f, 50, 241, &PUZZLE_PARTZ[D_0014E93C / 25]);
	SpriteDrawC(2.0f, 430, 241, &PUZZLE_PARTZ[D_0014E93C / 25]);
	SpriteDrawEz(12, 2.0f, -1, 16.0f, 190.0f, 72.0f, 16.0f, 0.0f, ChNamePos[st->player]);
	SpriteDrawEz(10, 7.0f, -1, 4.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
	SpriteDrawEz(11, 7.0f, -1, 381.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
	DrawAnk(1, 427, 136, 500);
	SpriteDrawC(6.0f, 240, 261, &PUZZLE_PARTZ[25]);
	DrawSpriteEz(8.0f, 0.0f, 0.0f, 240.0f, 136.0f, 0.0f, 0.0f, 0);
	DrawSpriteEz(8.0f, 0.0f, 136.0f, 240.0f, 136.0f, 0.0f, 136.0f, 0);
	DrawSpriteEz(8.0f, 240.0f, 0.0f, 240.0f, 136.0f, 240.0f, 0.0f, 0);
	DrawSpriteEz(8.0f, 240.0f, 136.0f, 240.0f, 136.0f, 240.0f, 136.0f, 0);
	DrawSpriteEz(9.0f, 0.0f, 0.0f, 240.0f, 272.0f, 0.0f, 0.0f, D_0014E940 + 22);
	DrawSpriteEz(9.0f, 240.0f, 0.0f, 240.0f, 272.0f, 240.0f, 0.0f, D_0014E940 + 22);
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA00);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA04);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA08);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA0C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA10);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA14);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA1C);
