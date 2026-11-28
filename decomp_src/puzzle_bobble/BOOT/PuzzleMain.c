/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
#include "PuzzleMain.h"

/* The unit's .bss (config `bss 0x14E7FC PuzzleMain`), in the original's
 * order: these zero-initialized variables, then the function statics in
 * source order (name.N), then the tentative definitions below. */
static int isSurvival = 0;
static int SurvCont = 0;
static int PauseFlag = 0;
static int isPause = 0;
static unsigned char PauseOk = 0;
static int Cont = 0;
int BuffSize = 0;
static short mframe = 0;
static short mtick = 0;
static int frame_anim[16] = { 0 };
static u8 CpuCheckBall[8] = { 0 };
static int StageNum = 0;
static int ssTimes = 0;
static int tp;
static int TimeBonus;
static int Ti;
static int KeyStat;
static int KeyHit;
static int VKeyHit;
static int bubx[1024];
static int buby[1024];
static int bubcnt[1024];
static int bubcol[1024];

int DrawSpriteEz(float z, float x, float y, float w, float h, float u, float v, int no);
int PzlDataGetWidth(int no);
int GetKeyHit();                                    /* extern */
int PollShutter(M2C_UNK);                           /* extern */
extern int gim_bg_endress;
extern int ColorRndMaxVS;
int SpriteDrawZoom(int no, int color, float z, float x, float y, float w, float h, float u, float v, float cx, float cy, float sx, float sy, float rot);
extern int ColorTableVS[];
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
extern const SPRDATA PUZZLE_PARTZ[];
extern const SPRDATA NUMERIC_PARTZ[];
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
int SpriteDraw(int no, int color, float z, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3);
int DrawSpritePt4(int no, int color, float z, float x0, float y0, float u0, float v0, float x1, float y1, float u1, float v1, float x2, float y2, float u2, float v2, float x3, float y3, float u3, float v3);
int SpriteDrawC(float z, int x, int y, const SPRDATA *p);
int EndressValueInit(int, int, int);
void SpriteSetFader(float);
int LoadGimFile(int no, int file);
int bgm_play(int no);
int SpriteDrawEz(int no, float z, int color, float x, float y, float w, float h, float u, float v);
int GetBallNext(PZL_STAT *st, int flag);
extern int SelectPlayer;
extern int gimfile_main[];
extern int gimfile_bubble[];
extern const int mx[];
extern const int my[];
void LoadFileList(int no, int *list);
void SpriteAllFreeImage(void);
void VSModeInit(int);
void SurvivlaModeInit(int);
void EndressModeInit(void);
void VSInit(void);
void InitBubCrush(void);
void SetMonitor(PZL_STAT *st, int mon);
/* ball outline points tested against the map */
typedef struct { s16 x, y; } BCPOS;
extern const BCPOS BallCollisionPosition[8];
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

/* chara_anim goes through an int local updated in place (`a /= 6`): a plain `s8 / 6`
 * is shortened and adds a seb, `tbl[a / 6]` gives other scratch registers. */
extern int *CHRTABLES[][8];
extern SPRDATA D_00038A18;
void DoCharacters(PZL_STAT *st)
{
	/* STAND-IN: numbering only; the real `static SPRDATA PARTZBUF = { 0, 0, 64, 64, 0, 0 };`
	 * is .data, which stays asm (D_00038A18) */
	static SPRDATA PARTZBUF __attribute__((section(".pbskipd")));
	int low = GetBallLine(st) < 8;
	int m = st->mapsub;
	int *tbl;
	int c, r, a, v;

	if (!low && st->chara < 3)
		SetCharacters(st, 6, 0);
	tbl = CHRTABLES[st->player][st->chara];
	a = st->chara_anim;
	a /= 6;
	c = tbl[a];
	D_00038A18.u = (c % 8) * 64;
	D_00038A18.v = (c / 8) * 64;
	D_00038A18.no = st->player + 16;
	D_00038A18.flag = m == 2;
	SpriteDrawC(0.0f, m == 2 ? 0x1AC : 0x33, 0x86, &D_00038A18);
	a = ++st->chara_anim;
	a /= 6;
	c = tbl[a];
	if (c == -3)
		st->chara_anim--;
	if (c == -2)
		st->chara_anim = 0;
	if (c == -1) {
		st->chara = st->chara2;
		r = rand() % 10;
		if (low)
			st->chara2 = r < 6 ? 0 : r < 8 ? 1 : 2;
		else
			st->chara2 = 6;
		st->chara_anim = 0;
	}
}

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

const int ChNamePos[] = { 0, 32, 64, 16, 48, 80 };

const int mx[] = { 0, -8, 8, -16, 16, -8, 8 };

const int my[] = { 0, -14, -14, 0, 0, 14, 14 };

const s16 MapXBeginPos[] = { 104, 32, 176, 32, 0, 0, 80, 0, 0 };

const u16 BallXPos[] = { 160, 88, 232 };

const SPRDATA PAUSE_PARTZ[] = { 200, 96, 200, 48, 27, 0 };

const SPRDATA SAVE_PARTZ[] = { 0, 0, 480, 104, 49, 0 };

const SPRDATA NEW_RECORD_PARTZ[] = { 0, 0, 336, 56, 24, 0 };

const SPRDATA PUZZLE_PARTZ[] = {
	{ 0, 336, 88, 64, 2, 0 },
	{ 88, 336, 88, 64, 2, 0 },
	{ 0, 400, 88, 56, 2, 0 },
	{ 88, 400, 88, 56, 2, 0 },
	{ 0, 400, 88, 56, 2, 1 },
	{ 88, 400, 88, 56, 2, 1 },
	{ 288, 224, 104, 112, 2, 0 },
	{ 288, 224, 104, 112, 2, 1 },
	{ 184, 336, 104, 112, 2, 0 },
	{ 288, 336, 104, 112, 2, 0 },
	{ 368, 0, 16, 224, 2, 0 },
	{ 160, 224, 128, 56, 2, 0 },
	{ 0, 224, 160, 56, 2, 0 },
	{ 0, 0, 88, 64, 38, 0 },
	{ 88, 0, 88, 64, 38, 0 },
	{ 0, 64, 88, 64, 38, 0 },
	{ 88, 64, 88, 64, 38, 0 },
	{ 0, 0, 88, 64, 39, 0 },
	{ 88, 0, 88, 64, 39, 0 },
	{ 0, 64, 88, 64, 39, 0 },
	{ 88, 64, 88, 64, 39, 0 },
	{ 0, 0, 88, 64, 40, 0 },
	{ 88, 0, 88, 64, 40, 0 },
	{ 0, 64, 88, 64, 40, 0 },
	{ 88, 64, 88, 64, 40, 0 },
	{ 0, 312, 288, 24, 2, 0 },
	{ 0, 288, 192, 24, 2, 0 },
};

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", NUMERIC_PARTZ);

const SPRDATA ATTACK_PARTZ[] = {
	{ 0, 32, 16, 16, 15, 0 },
	{ 18, 32, 12, 16, 15, 0 },
};

const SPRDATA WINLOSE_PARTZ[] = {
	{ 0, 136, 176, 48, 23, 0 },
	{ 0, 72, 176, 48, 25, 0 },
	{ 0, 0, 328, 72, 25, 0 },
};

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SCORE_NUMERIC_PARTZ);

const SPRDATA GAMEMODE_PARTZ[] = {
	{ 0, 0, 112, 16, 3, 0 },
	{ 0, 16, 112, 16, 3, 0 },
	{ 0, 32, 112, 16, 3, 0 },
	{ 0, 48, 112, 16, 3, 0 },
};

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", LIGHT_PARTZ);

extern SPRDATA D_00038A30;
void DoMonitor(PZL_STAT *st)
{
	/* STAND-IN: numbering only; the real static (its .data, D_00038A30) stays asm */
	static SPRDATA MONITOR_PARTZ __attribute__((section(".pbskipd")));
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

const BCPOS BallCollisionPosition[] = { -2, -5, 2, -5, -5, -2, 6, -2, -5, 2, 6, 2, -2, 5, 2, 5 };

#ifdef NON_MATCHING
/* One instruction short: logic complete, but the original keeps x = bubx[i] + 80 in a
 * saved register and subtracts 56 in each branch, where ours keeps bubx[i] and folds
 * the offsets to +24 (every statement order tried). */
int DrawSpriteZoom(int no, int color, float z, float x, float y, float w, float h, float u, float v, float cx, float cy, float sx, float sy, float rot);
void DoBubCrush(void)
{
	int i, t, x, y, col, color, f;
	float s;

	for (i = 0; i < 1024; i++) {
		if (bubcnt[i] == 0)
			continue;
		t = 16 - bubcnt[i];
		color = ((int)(bubcnt[i] * 0.0625f * 255.0f) << 24) | 0xFFFFFF;
		x = bubx[i] + 80;
		y = buby[i] - 32;
		s = t * 0.25f + 1.0f;
		DrawSpriteZoom(bubcol[i] + 49, color, 0, x, y, 16.0f, 16.0f, 0, 0, 8.0f, 8.0f, s, s, 0);
		col = bubcol[i];
		if (col != 9 && col != 14) {
			DrawSpriteZoom(45, color, 1.0f, x - 56, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s * 0.25f, s * 0.25f, 0);
		} else if (col == 9) {
			DrawSpriteZoom(46, color, 1.0f, x - 56, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s, s, t * 0.3f * 3.14f * 0.0625f);
		} else {
			f = t * 6 / 16;
			SpriteDrawEz(47, 0, -1, x - 56, y - 56, 128.0f, 128.0f, f % 4 * 128, f / 4 * 128);
		}
		bubcnt[i]--;
	}
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoBubCrush);
#endif

int PuzzleInit(void)
{
	int r;

	SpriteAllFreeImage();
	LoadFileList(1, gimfile_main);
	LoadFileList(50, gimfile_bubble);
	GameValueInit(2, GetRound() - 1, 1);
	dsGMInit(2, GetRound() - 1);
	GameValueInit(0, GetRound() - 1, 1);
	dsGMInit(0, GetRound() - 1);
	SpriteSetFader(1.0f);
	Stat[0].cur = GetBallNext(&Stat[0], 0);
	Stat[0].next = GetBallNext(&Stat[0], 0);
	r = (GetRound() - 1) / 10 % 3;
	bgm_play(r + 1);
	PollShutter(3);
	SetMonitor(&Stat[2], 8);
	LoadGimFile(0, gim_bg_puzzle[StageNum / 10]);
	InitBubCrush();
	return 0;
}

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

void VSValueInit(int pl, int a1, int flag);
extern const int bgmsort[];
void VSModeInit(int cont)
{
	int enemy = Stat[2].player;
	int n;

	if (cont) {
		enemy++;
		enemy %= 6;
	}
	VSValueInit(1, 0, 0);
	VSValueInit(2, 0, 0);
	SpriteSetFader(1.0f);
	Stat[1].player = SelectPlayer;
	Stat[2].player = enemy;
	Stat[1].snd.unk2 = (Stat[1].player + 3) % 6;
	Stat[2].snd.unk2 = (Stat[2].player + 3) % 6;
	Stat[1].cur = GetBallNext(&Stat[1], 0);
	n = GetBallNext(&Stat[1], 0);
	Stat[2].cur = Stat[1].cur;
	Stat[1].next = n;
	Stat[2].next = n;
	LoadGimFile(0, gim_bg_vs[isSurvival * 6 + Stat[2].player]);
	bgm_play(bgmsort[Stat[2].player % 6]);
}

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

void SurvValueInit(void);
void VSValueInit(int pl, int a1, int flag);
extern const int bgmsort[];
void SurvivlaModeInit(int cont)
{
	int enemy = Stat[2].player;
	int n;

	if (cont) {
		enemy++;
		enemy %= 6;
	}
	SurvValueInit();
	VSValueInit(2, 0, 0);
	SpriteSetFader(1.0f);
	Stat[1].cur = GetBallNext(&Stat[1], 0);
	n = GetBallNext(&Stat[1], 0);
	Stat[2].cur = Stat[1].cur;
	Stat[1].player = SelectPlayer;
	Stat[2].player = enemy;
	Stat[1].snd.unk2 = (Stat[1].player + 3) % 6;
	Stat[2].snd.unk2 = (Stat[2].player + 3) % 6;
	Stat[1].next = n;
	Stat[2].next = n;
	LoadGimFile(0, gim_bg_vs[6 + Stat[2].player]);
	bgm_play(bgmsort[Stat[2].player % 6]);
}

#ifdef NON_MATCHING
/* diff 9 (best of all 120 store orders, either order of the first two stores): the
 * StageNum/SurvCont %hi registers are swapped and the isSurvival store is scheduled
 * one slot earlier.  SelectPlayer is read as a byte (s8). */
void SurvivalInit(void)
{
	s8 sel;

	StageNum = 0;
	SurvCont = 0;
	VSInit();
	SurvivlaModeInit(0);
	sel = SelectPlayer;
	Stat[1].player = sel;
	Stat[2].snd.unk2 = 3;
	Stat[2].player = 0;
	Stat[1].snd.unk2 = (sel + 3) % 6;
	isSurvival = 1;
	InitBubCrush();
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvivalInit);
#endif

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

#ifdef NON_MATCHING
/* diff 9, same size: t = (scale == 0) kept as a value and `zoom = t | (col >= 8);
 * zoom ^= 1;` (one expression gets De Morgan-folded into an and); SpriteDrawZoom has 14
 * parameters (rot = 0 stored at 12(sp), which v's 0.0f is reloaded from).  Left: the
 * 2.0f %hi is loaded first, into v1, in the original (both calls). */
void DrawBubble(float scale, int x, int y, int col, int frame)
{
	int a = frame_anim[col] / 6;
	int zoom;
	int t;

	if (a > 4)
		a = 4;
	if (col == 9)
		a = frame_anim[9] * 4 / 30;
	if (col == 10)
		a = 0;
	t = scale == 0.0f;
	zoom = t | (col >= 8);
	zoom ^= 1;
	if (scale < 1.0f && scale > 0.0f)
		zoom = 1;
	if (!zoom)
		SpriteDrawEz(col + 50, 2.0f, -1, x, y, 16.0f, 16.0f, a * 16, 0.0f);
	else
		SpriteDrawZoom(col + 50, -1, 2.0f, x, y, 16.0f, 16.0f, a * 16, 0.0f, 8.0f, 8.0f, scale, scale, 0);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawBubble);
#endif

void DrawCharcter(int z, int x, int y, PARTZ *tbl, int idx)
{
	PARTZ *p = (PARTZ *)(idx * sizeof(PARTZ) + (int)tbl);

	DrawSpriteEz(z, x, y, p->w, p->h, p->u, p->v, p->no);
}

#ifdef NON_MATCHING
/* One instruction too long with every cc1 (same as DrawCharcter2): (float)p->v, passed
 * both in $f16 and on the stack, is converted into a temp and copied with mov.s where
 * the original converts it straight into $f16.  No source variant changes this. */
void DrawCharcterFlip(int z, int x, int y, PARTZ *tbl, int idx)
{
	PARTZ *p = (PARTZ *)(idx * sizeof(PARTZ) + (int)tbl);

	SpriteDraw(p->no, -1, z, x, y, p->u + p->w, p->v, x + p->w, y, p->u, p->v, x, y + p->h, p->u + p->w, p->v + p->h, x + p->w, y + p->h, p->u, p->v + p->h);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawCharcterFlip);
#endif

#ifdef NON_MATCHING
/* Close (one extra mov.s): v is converted into a temporary instead of straight into $f16. */
void DrawCharcter2(int z, int x, int y, PARTZ *tbl, int idx)
{
	PARTZ *p = (PARTZ *)(idx * sizeof(PARTZ) + (int)tbl);

	DrawSpritePt4(p->no, -1, z, x, y, p->u, p->v, x + p->w, y, p->u + p->w, p->v, x, y + p->h, p->u, p->v + p->h, x + p->w, y + p->h, p->u + p->w, p->v + p->h);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawCharcter2);
#endif

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

double sin(double);
double cos(double);
/* the doubles are the module's .rodata.cst8 entries at the end of this unit's rodata */
extern const double D_0002EA00, D_0002EA08, D_0002EA10, D_0002EA18;

short Sin(short a)
{
	return (float)sin(a * D_0002EA00 / D_0002EA08) * 32767.0f;
}

short Cos(short a)
{
	return (float)cos(a * D_0002EA10 / D_0002EA18) * 32767.0f;
}

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
	st->bx = BallXPos[pl];
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

#ifdef NON_MATCHING
/* Close: the original runs out of saved registers in the first loop (x, mapno and w each
 * get one) and so recomputes the /6 constant per iteration; ours hoists it. */
extern short mframe;
extern short mtick;
void DrawBubble(float z, int x, int y, int col, int anim);
void DrawMapData(PZL_STAT *st)
{
	float z = 0.0f;
	int i, n, w, x, y, c, no;

	mtick = st->unk46E;
	mframe = st->unk46C;
	if (st->unk026 == 1) {
		mframe = (short)(mframe + 1) % 40;
		mtick = 0;
	} else if (st->unk026 == 0) {
		mframe = (short)(mframe + 1) % 18;
		mtick = 0;
	} else {
		mframe = 0;
		mtick = 0;
	}
	if (mframe >= 1 && mframe <= 3)
		z = 1.2f;
	if (st->unk006 != 0x18 && mframe == 2)
		se_play(18);
	if (st->mapsub < 2) {
		for (i = 0; i < 16; i++) {
			if (frame_anim[i] != 0 || i >= 8)
				frame_anim[i] = (frame_anim[i] + 1) % 30;
			else if (rand() % 150 == 0)
				frame_anim[i]++;
		}
	}
	n = GetMapWidth(st->mapno) * 32;
	for (i = 0; i < n; i++) {
		no = st->mapno;
		w = GetMapWidth(no);
		x = (i % w * 2 + i / w % 2) * 8;
		if (st->mapsub == 0)
			x += GetMapLeft(no);
		else if (st->mapsub == 1)
			x += 24;
		else
			x += 168;
		c = st->mp.map[i];
		y = (st->scroll * 7 + i / w * 7) * 2 + 32;
		if (c)
			DrawBubble(z, x + 80, y, c - 1, frame_anim[c - 1] / 6);
	}
	i = GetMapWidth(st->mapno);
	for (n = i * 2 - 1; i < n; i++) {
		w = GetMapWidth(st->mapno);
		x = (i % w * 2 + i / w % 2) * 8 + GetMapLeft(st->mapno);
		y = (st->scroll * 7 + i / w * 7) * 2 + 4;
		DrawBubble(z, x + 80, y, 11, frame_anim[11] / 6);
	}
	st->unk46C = mframe;
	st->unk46E = mtick;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawMapData);
#endif

void SetBallMapReverse(PZL_STAT *dst, PZL_STAT *src)
{
	int x, y;
	u8 *sm = src->mp.map;
	u8 *dm = dst->mp.map;

	for (y = 0; y < 18; y++) {
		u8 *d = (u8 *)((y / 2 * 2 - y) + (int)dm) + y * 8 + 7;
		u8 *s = sm + y * 8;

		for (x = 0; x < 8; x++) {
			*d-- = *s++;
			if ((y & 1) && x == 6)
				break;
		}
	}
}

#ifdef NON_MATCHING
/* diff 16: the map row indexed (map[(y + 16) * w + i], a giv set up after the w > 0
 * test, as in the original) with src still a pointer computed above the test.  Indexing
 * src too (data[y * w - y / 2 + i]) gives the original's whole row set-up after the
 * test and its s7/s8, but then data and n swap a1/a2 (one more copy, +4 bytes). */
int SetBallMap(u8 *map, u8 *data)
{
	int i, y, n, w, type;
	u8 c;
	u8 *src, *dst;

	n = 8;
	for (i = 0; i < 8; i++)
		ColorTable[i] = i + 1;
	i = data[1];
	type = data[0];
	data += 2;
	if (i) {
		n = i;
		for (i = 0; i < n; i++)
			ColorTable[i] = data[i];
		data += n;
	}
	ColorRndMax = n;
	for (i = 0; i < 0x240; i++)
		map[i] = 0;
	w = GetMapWidth(type);
	for (y = 1; y < 13; y++) {
		src = data + (y * w - y / 2);
		for (i = 0; i < w; i++) {
			c = *src++;
			if (c == 16)
				c = ColorTable[rand() % n];
			if (i == w - 1 && y % 2 == 1)
				c = 0;
			map[(y + 16) * w + i] = c;
		}
	}
	return type;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBallMap);
#endif

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

int GetBallNext(PZL_STAT *st, int flag)
{
	int r;

	if (flag && GetBallLine(st) >= 10)
		return 9;
	r = rand() % 1000;
	if (r < 15)
		return 13;
	if (r < 25)
		return 8;
	if (r < 30)
		return 9;
	r = CheckNext(st) - 1;
	if (r < 0)
		r = st->next;
	if (r < 0)
		r = 0;
	return r;
}

#ifdef NON_MATCHING
/* Right size, diff 224: logic complete (bomb 9, rainbow 13 and 8 balls); the original
 * allocates st/flag/i/hit to other saved registers and tests `p < 0` after loading cur. */
int CheckBallTouch(PZL_STAT *st, int flag)
{
	int x, y, x1, y1, x2, y2, x3, y3, x4, y4;
	int i, j, p, a, c, m;
	int hit = 0;

	st->snd.unk4 = CvtBallPos2MapPos(st, 0, 0);
	st->unk45C = 0;
	for (i = 0; i < 8; i++) {
		p = CvtBallPos2MapPos(st, BallCollisionPosition[i].x, BallCollisionPosition[i].y);
		if (flag != 0 && p < 0)
			goto touch;
		if (st->mp.map[p] == 0)
			continue;
	touch:
		c = st->cur;
		if (c == 9 && p >= 0 && (u8)(st->mp.map[p] - 11) >= 2) {
			GetBallCoordinate(st, p, &x, &y);
			SetBubCrushEz(st, x, y, st->mp.map[p]);
			if (st->mp.map[p] == 9)
				st->snd.se = 23;
			else
				st->snd.se = 15;
			st->mp.map[p] = 0;
			continue;
		}
		hit = 1;
		if (c == 13) {
			GetBallCoordinate(st, CvtBallPos2MapPos(st, 0, 0), &x1, &y1);
			st->ndrop = 0;
			st->drop.d[st->ndrop].y = y1;
			st->drop.d[st->ndrop].x = x1;
			st->drop.d[st->ndrop].col = 14;
			st->drop.d[st->ndrop].flag = 0;
			st->snd.se = 25;
			st->ndrop++;
			for (j = 1; j < 7; j++) {
				a = GetBallMapAddr(st, x1, y1, j);
				m = st->mp.map[a];
				if (m != 0 && m != 12) {
					GetBallCoordinate(st, a, &x2, &y2);
					st->drop.d[st->ndrop].x = x2;
					st->drop.d[st->ndrop].y = y2;
					st->drop.d[st->ndrop].col = st->mp.map[a];
					st->drop.d[st->ndrop].flag = 0;
					st->attr[a] = 1;
					st->ndrop++;
					st->mp.map[a] = 0;
				}
			}
			return hit;
		}
		if (c == 8) {
			m = st->mp.map[p];
			st->snd.se = 23;
			if (m < 9) {
				st->snd.unk0 = m;
				st->unk45C = 1;
			}
			st->ndrop = 0;
			GetBallCoordinate(st, CvtBallPos2MapPos(st, 0, 0), &x3, &y3);
			st->drop.d[st->ndrop].x = x3;
			st->drop.d[st->ndrop].y = y3;
			st->drop.d[st->ndrop].col = 9;
			st->drop.d[st->ndrop].flag = 0;
			st->ndrop++;
			if (st->unk45C)
				return 1;
			GetBallCoordinate(st, CvtBallPos2MapPos(st, 0, 0), &x3, &y3);
			for (j = 1; j < 7; j++) {
				a = GetBallMapAddr(st, x3, y3, j);
				m = st->mp.map[a];
				if ((u8)(m - 1) < 8) {
					GetBallCoordinate(st, a, &x4, &y4);
					st->drop.d[st->ndrop].x = x4;
					st->drop.d[st->ndrop].y = y4;
					st->drop.d[st->ndrop].col = st->mp.map[a];
					st->snd.unk0 = st->mp.map[a];
					st->drop.d[st->ndrop].flag = 0;
					st->unk45C = 1;
					st->ndrop++;
					st->mp.map[a] = 0;
					return 1;
				}
				if ((u8)m == 9) {
					GetBallCoordinate(st, a, &x4, &y4);
					st->drop.d[st->ndrop].x = x4;
					st->drop.d[st->ndrop].y = y4;
					st->drop.d[st->ndrop].col = st->mp.map[a];
					st->drop.d[st->ndrop].flag = 0;
					st->mp.map[a] = 0;
					st->ndrop++;
					return 1;
				}
			}
			continue;
		}
		m = st->mp.map[p];
		if (m < 10) {
			if (m == 9) {
				st->snd.unk0 = c + 1;
				st->snd.se = 23;
				st->unk45C = 1;
			} else if (p < 0)
				st->snd.se = 14;
			else
				st->snd.se = 13;
			return hit;
		}
	}
	return hit;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallTouch);
#endif

#ifdef NON_MATCHING
/* Close (diff 21): st and pos get s1/s0 swapped (the original gives st s0) and pos / w lands in
 * pos's register instead of a scratch one. */
int CheckBallCollision(PZL_STAT *st)
{
	int ret = 0;
	int pos, w;

	st->color = 0;
	if (st->cur + 1 > 0 && st->cur + 1 < 9) {
		pos = CvtBallPos2MapPos(st, 0, 0);
		st->mp.map[pos] = st->cur + 1;
		w = GetMapWidth(st->mapno);
		if (CheckBallAround(st, (pos % w * 2 + (pos / w & 1)) * 8, pos / w * 14) && st->color)
			ret = 1;
	}
	if (st->unk45C)
		st->color = st->snd.unk0;
	if (st->color)
		CheckOneColorAll(st);
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallCollision);
#endif

int CvtBallPos2MapPos(PZL_STAT *st, int x, int y)
{
	int lx = (st->bx - MapXBeginPos[st->mapno * 3 + st->mapsub]) + x;
	int ly = (st->by - st->ofs_y) + y;
	return CvtBallPos2MapPosLocal(st, lx, ly);
}

#ifdef NON_MATCHING
/* Close (diff 19): v0/v1 swapped in the column computations. */
int CvtBallPos2MapPosLocal(PZL_STAT *st, int x, int y)
{
	int line, col, sub, px;

	y += 6;
	if (y < 0)
		return -1;
	line = y / 14;
	px = x + ((line + 1) & 1) * 8;
	col = px / 16;
	sub = y - line * 14;
	if (sub == 12) {
		if (px - col * 16 < 3 || px - col * 16 > 12) {
			line++;
			col = (x + ((line + 1) & 1) * 8) / 16;
		}
	} else if (sub == 13) {
		if (px - col * 16 < 5 || px - col * 16 > 10) {
			line++;
			col = (x + ((line + 1) & 1) * 8) / 16;
		}
	}
	return col + line * GetMapWidth(st->mapno);
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CvtBallPos2MapPosLocal);
#endif

int GetBallMapAddr(PZL_STAT *st, int bx, int by, int dir)
{
	static int ret;
	static int x;
	static int y;
	static int maxX;

	maxX = GetMapWidth(st->mapno) * 16;
	if (dir < 0)
		dir = 0;
	else if (dir >= 7)
		dir = 6;
	x = bx + mx[dir];
	y = by + my[dir];
	if (x < 0 || y < 0 || x >= maxX)
		ret = -1;
	else
		ret = CvtBallPos2MapPosLocal(st, x, y);
	return ret;
}

void GetBallCoordinate(PZL_STAT *st, int idx, int *px, int *py)
{
	static int x;
	static int LX;
	static int LY;
	int line;

	LX = GetMapWidth(st->mapno);
	x = idx % (LX * 2);
	line = idx / (LX * 2);
	*py = (line * 2 + x / LX - LY) * 14;
	*px = (x < LX) ? x * 16 : (x - LX) * 16 + 8;
}

#ifdef NON_MATCHING
/* Rough (7 instructions short): logic complete (note the original marks attr[dir], not
 * attr[addr], for a 9 neighbour); its frame is 16 bytes bigger and col and ret live in
 * stack slots. */
int CheckBallAround(PZL_STAT *st, int x, int y)
{
	int queue[596];
	int px, py;
	int i, k, a, c, col, cnt, n9, last, ret, n;

	n9 = 0;
	cnt = 0;
	col = st->mp.map[GetBallMapAddr(st, x, y, 0)];
	st->drop.unk1 = 0;
	for (i = 1; i < 7; i++) {
		a = GetBallMapAddr(st, x, y, i);
		if (a >= 0) {
			c = st->mp.map[a];
			if (c == 9) {
				st->attr[a] = 2;
				st->color = col;
				n9++;
				st->drop.d[st->ndrop].x = mx[i] + x;
				st->drop.d[st->ndrop].y = my[i] + y;
				st->drop.d[st->ndrop].col = c;
				st->drop.d[st->ndrop].flag = 0;
				st->attr[i] = 1;
				st->ndrop++;
				st->snd.se = 23;
			}
			if (c == col) {
				last = i;
				cnt++;
			}
		}
	}
	if (n9 != 0)
		return n9;
	if (cnt == 0)
		return 0;
	if (cnt == 1) {
		cnt = 0;
		for (i = 1; i < 7; i++) {
			a = GetBallMapAddr(st, x + mx[last], y + my[last], i);
			if (a >= 0)
				cnt += st->mp.map[a] == col;
		}
		if (cnt < 2)
			return 0;
	}
	for (i = 0; i < 0x240; i++) {
		st->attr[i] = 0;
		st->rainbow[i] = 0;
	}
	i = GetBallMapAddr(st, x, y, 0);
	GetBallCoordinate(st, i, &px, &py);
	st->drop.d[st->ndrop].x = px;
	st->drop.d[st->ndrop].y = py;
	st->drop.d[st->ndrop].col = col;
	st->drop.d[st->ndrop].flag = 0;
	ret = 1;
	st->attr[i] = 1;
	st->ndrop++;
	queue[0] = i;
	cnt = 1;
	do {
		i = queue[--cnt];
		GetBallCoordinate(st, i, &px, &py);
		for (k = 1; k < 7; k++) {
			a = GetBallMapAddr(st, px, py, k);
			if (a >= 0 && st->mp.map[a] == col && st->attr[a] == 0) {
				queue[cnt++] = a;
				st->attr[a] = 1;
				st->drop.d[st->ndrop].x = px + mx[k];
				ret++;
				st->drop.d[st->ndrop].y = py + my[k];
				st->drop.d[st->ndrop].col = col;
				st->drop.d[st->ndrop].flag = 0;
				st->ndrop++;
			}
		}
	} while (cnt > 0);
	n = 0;
	for (i = 0; i < 0x240; i++) {
		GetBallCoordinate(st, i, &px, &py);
		if (st->attr[i] != 0) {
			st->mp.map[i] = 0;
			n++;
			st->unk434++;
			st->rainbow[i] = 0;
			for (k = 1; k < 7; k++) {
				a = GetBallMapAddr(st, px, py, k);
				if (st->mp.map[a] == 13) {
					st->snd.se = 24;
					st->mp.map[a] = col;
					st->rainbow[a] = 1;
					st->drop.unk1 = 1;
				}
			}
		}
	}
	st->unk429 = n == 3;
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallAround);
#endif

#ifdef NON_MATCHING
/* Right size, diff 122 (register allocation): logic complete; n/ret and the colour swap
 * saved registers and the drop-entry stores are scheduled differently. */
int CheckBallAroundRainbow(PZL_STAT *st, int x, int y, int n)
{
	int queue[596];
	int px, py;
	int i, cnt, a, col, last, ret;

	a = GetBallMapAddr(st, x, y, 0);
	if (st->attr[a] != 0)
		return n;
	col = st->mp.map[a];
	if ((unsigned int)(col - 1) >= 8)
		return n;
	cnt = 0;
	for (i = 1; i < 7; i++) {
		a = GetBallMapAddr(st, x, y, i);
		if (a >= 0 && st->mp.map[a] == col && st->attr[a] == 0) {
			cnt++;
			last = i;
		}
	}
	if (cnt == 0)
		return n;
	if (cnt == 1) {
		cnt = 0;
		for (i = 1; i < 7; i++) {
			a = GetBallMapAddr(st, x + mx[last], y + my[last], i);
			if (a >= 0 && st->mp.map[a] == col)
				cnt += st->attr[a] == 0;
		}
		if (cnt < 2)
			return n;
	}
	i = GetBallMapAddr(st, x, y, 0);
	GetBallCoordinate(st, i, &px, &py);
	ret = n + 1;
	st->drop.d[n].flag = 0;
	st->drop.d[n].col = col;
	st->drop.d[n].x = px;
	st->drop.d[n].y = py;
	st->attr[i] = 1;
	queue[0] = i;
	st->ndrop = ret;
	cnt = 1;
	do {
		i = queue[--cnt];
		GetBallCoordinate(st, i, &px, &py);
		for (i = 1; i < 7; i++) {
			a = GetBallMapAddr(st, px, py, i);
			if (a >= 0 && st->mp.map[a] == col && st->attr[a] == 0) {
				queue[cnt++] = a;
				st->attr[a] = 1;
				st->drop.d[st->ndrop].x = px + mx[i];
				ret++;
				st->drop.d[st->ndrop].y = py + my[i];
				st->drop.d[st->ndrop].col = col;
				st->drop.d[st->ndrop].flag = 0;
				st->ndrop++;
			}
		}
	} while (cnt > 0);
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallAroundRainbow);
#endif

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

#ifdef NON_MATCHING
/* Two instructions short: the original guards the whole-map colour scan with `cnt < 0x22E`
 * (slti on the candidate count, which is 0 there) and returns through the cnt register
 * (s0) on every path.  Same loop structure otherwise; one variable i is reused for
 * every loop and for the queue entry, as in the original. */
int CheckNext(PZL_STAT *st)
{
	int queue[596];
	int exist[32];
	int cand[32];
	int x, y;
	int w, i, n, cnt, c;
	unsigned int a;

	w = GetMapWidth(st->mapno) * 2;
	if (w == 0)
		w = 16;
	n = 1;
	queue[0] = 0x22E - GetMapWidth(st->mapno) / 2;
	for (i = 0; i < 0x22E; i++) {
		if (i % w == w - 1)
			st->attr[i] = -1;
		else
			st->attr[i] = 0;
	}
	for (i = 0; i < 32; i++) {
		exist[i] = 0;
		cand[i] = 0;
	}
	do {
		i = queue[--n];
		GetBallCoordinate(st, i, &x, &y);
		for (i = 1; i < 7; i++) {
			a = GetBallMapAddr(st, x, y, i);
			if (a < 0x240 && -st->scroll * GetMapWidth(st->mapno) < (int)a && st->attr[a] == 0) {
				c = st->mp.map[a];
				st->attr[a] = 1;
				if (c == 0)
					queue[n++] = a;
				else if (c >= 1 && c <= 8)
					exist[c] = 1;
			}
		}
	} while (n > 0);
	cnt = 0;
	for (i = 0; i < 32; i++) {
		if (exist[i])
			cand[cnt++] = i;
	}
	if (cnt != 0) {
		if (cnt == 1 && cand[0] == 9)
			cnt = 0;
		else {
			cnt = cand[rand() % cnt];
			if (cnt != 0)
				return cnt;
		}
	}
	for (i = 0; i < 0x22E; i++) {
		c = st->mp.map[i];
		if (c >= 1 && c <= 8)
			exist[c] = 1;
	}
	for (i = 0; i < 32; i++) {
		if (exist[i])
			cand[cnt++] = i;
	}
	if (cnt != 0)
		return cand[rand() % cnt];
	if (st->next < 8)
		return st->next + 1;
	return 1;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckNext);
#endif

#ifdef NON_MATCHING
/* One instruction long, logic complete (groups hanging from the ceiling (12), the
 * falling balls become ent[] entries, chain colours go to CheckChain); register
 * allocation of st and the loop counters differs. */
void TermChain(PZL_STAT *st);
void CheckBallDrop(PZL_STAT *st)
{
	int queue[308];
	int used[12], ent[12], ex[12], ey[12];
	int x, y, x2, y2;
	int i, k, g, cnt, ngroup, flag, sound, n, mul, a, nc;

	ngroup = 0;
	for (i = 0; i < 0x240; i++) {
		st->attr[i] = 0;
		st->group[i] = 0;
	}
	GetMapWidth(st->mapno);
	for (i = 0; i < 0x22E; i++) {
		if (st->mp.map[i] != 12 || st->attr[i] != 0)
			continue;
		ngroup++;
		st->attr[i] = 1;
		st->group[i] = ngroup;
		GetBallCoordinate(st, i, &x, &y);
		for (k = 1; k < 7; k++) {
			a = GetBallMapAddr(st, x, y, k);
			if (a >= 0 && st->mp.map[a] != 0 && st->attr[a] == 0) {
				st->attr[a] = 1;
				cnt = 1;
				queue[0] = a;
				st->group[a] = ngroup;
				do {
					GetBallCoordinate(st, queue[--cnt], &x2, &y2);
					for (g = 1; g < 7; g++) {
						a = GetBallMapAddr(st, x2, y2, g);
						if (a >= 0 && st->attr[a] == 0 && st->mp.map[a] != 0) {
							queue[cnt++] = a;
							st->attr[a] = 1;
							st->group[a] = ngroup;
						}
					}
				} while (cnt > 0);
			}
		}
	}
	if (st->mapsub == 0) {
		for (g = 1; g <= ngroup; g++) {
			flag = 0;
			for (i = 0; i < 0x22E; i++) {
				if (st->group[i] == g && st->mp.map[i] != 12)
					flag = 1;
			}
			if (flag == 0) {
				for (i = 0; i < 0x22E; i++) {
					if (st->group[i] == g && st->mp.map[i] == 12)
						st->attr[i] = 0;
				}
			}
		}
	}
	st->unk456 = 0;
	mul = 1;
	n = 0;
	for (i = 0; i < 8; i++) {
		used[i + 1] = 0;
		st->chaincol[i + 1] = 0;
	}
	sound = 0;
	for (i = 0x22D; i >= 0; i--) {
		GetBallCoordinate(st, i, &x2, &y2);
		if (st->attr[i] == 0 && st->mp.map[i] != 0) {
			st->rainbow[i] = 0;
			st->ent[st->unk458].x = x2;
			st->ent[st->unk458].y = y2;
			st->ent[st->unk458].x += MapXBeginPos[st->mapno * 3 + st->mapsub] - 8;
			st->ent[st->unk458].y += st->ofs_y + st->scroll * 14 + 32;
			st->ent[st->unk458].col = st->mp.map[i];
			st->ent[st->unk458].vy = -st->unk456;
			ey[st->mp.map[i]] = y2;
			ent[st->mp.map[i]] = st->unk458;
			used[st->mp.map[i]] = 1;
			ex[st->mp.map[i]] = x2;
			st->ent[st->unk458].flag = 1;
			st->unk456 += 2;
			st->unk458 = (st->unk458 + 1) % 192;
			DrawBubble(0.0f, x2 + MapXBeginPos[st->mapno * 3 + st->mapsub] + 72, y2 + st->ofs_y + st->scroll * 14, st->mp.map[i] - 1, 0);
			if (st->mp.map[i] != 0 && st->mp.map[i] != 12)
				sound = 1;
			n++;
			st->mp.map[i] = 0;
			if (st->unk429 * 3 + 17 >= n)
				mul *= 2;
		}
	}
	st->score += n;
	if (st->score >= 10000)
		st->score = 9999;
	if (sound)
		se_play(16);
	if (st->unk45F != 0) {
		nc = 0;
		for (i = 1; i < 9; i++) {
			if (used[i])
				st->chaincol[nc++] = i;
		}
		st->nchain = 0;
		st->unk470 = 0;
		if (nc != 0) {
			for (i = 0; i < nc; i++)
				CheckChain(st, st->chaincol[i], ent[st->chaincol[i]], ex[st->chaincol[i]], ey[st->chaincol[i]]);
			TermChain(st);
		}
	}
	if (n != 0) {
		st->unk434 += mul;
		if (st->mapsub != 1)
			Stat[1].unk476 += n * 2;
		else
			Stat[2].unk476 += n * 2;
	}
	st->unk45A = 0;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallDrop);
#endif

void CheckChain(PZL_STAT *st, int col, int n, int a, int b)
{
	int queue[596];
	int x, y, x2, y2;
	int w, i, cnt, c, cur, k, p;
	unsigned int addr;

	w = GetMapWidth(st->mapno) * 2;
	if (w == 0)
		w = 16;
	cnt = 1;
	i = 0;
	queue[0] = 0x22E - GetMapWidth(st->mapno) / 2;
	for (; i < 0x22E; i++) {
		if (i % w == w - 1)
			st->attr[i] = -1;
		else
			st->attr[i] = 0;
	}
	do {
		i = queue[--cnt];
		cur = i;
		GetBallCoordinate(st, i, &x, &y);
		for (i = 1; i < 7; i++) {
			addr = GetBallMapAddr(st, x, y, i);
			if (addr < 0x240 && -st->scroll * GetMapWidth(st->mapno) < (int)addr) {
				c = st->mp.map[addr];
				if (st->attr[addr] != 0)
					continue;
				st->attr[addr] = 1;
				if (c == 0 || c == 0x68) {
					queue[cnt++] = addr;
				} else if (c == col) {
					GetBallCoordinate(st, addr, &x2, &y2);
					for (k = 1; k < 7; k++) {
						p = GetBallMapAddr(st, x2, y2, k);
						if (st->mp.map[p] == c && st->mp.map[cur] == 0) {
							st->mp.map[cur] = 0x68;
							GetBallCoordinate(st, cur, &x2, &y2);
							st->chain[st->nchain].a = a;
							st->chain[st->nchain].b = (st->ent[n].flag = 0, b);
							st->chain[st->nchain].x = x2;
							st->chain[st->nchain].y = y2;
							st->chain[st->nchain].col = col;
							st->chain[st->nchain].pos = cur;
							st->nchain++;
							goto end;
						}
					}
				}
			}
		}
	} while (cnt > 0);
end:
	for (i = 0; i < 0x22E; i++) {
		if (i % w == w - 1)
			st->attr[i] = 0;
	}
}

void TermChain(PZL_STAT *st)
{
	int i;

	for (i = 0; i < MAP_SIZE; i++) {
		if (st->mp.map[i] == 0x68)
			st->mp.map[i] = 0;
	}
}

int CheckOneColorAll(PZL_STAT *st)
{
	int n = 0;
	int i;
	u8 col = st->color;
	int x, y;
	int k;

	st->unk429 = 0;
	if (col >= 1 && col <= 9) {
		for (i = 0; i < 0x22E; i++) {
			if (st->mp.map[i] == col || st->attr[i] == 2) {
				n++;
				GetBallCoordinate(st, i, &x, &y);
				k = st->ndrop;
				st->drop.d[k].x = x;
				st->drop.d[k].y = y;
				st->drop.d[k].col = col;
				st->drop.d[k].flag = 0;
				st->mp.map[i] = 0;
				st->ndrop++;
			}
		}
	}
	return n;
}

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

#ifdef NON_MATCHING
/* Rough (13 instructions long): logic complete (16.16 fixed-point trajectory with wall
 * bounces, dots every 4 frames into gx/gy, hit test, CPU neighbour copy); ours spills
 * more (frame 112 vs 96) and computes |vx| once per branch. */
extern u8 CpuCheckBall[];
void CheckBallGuide(PZL_STAT *st)
{
	static int X;
	static int Y;
	static int DX;
	static int DY;
	int lx, ly;
	int left, right, top, bottom;
	int end, match;
	int frame, n, anim, i, p, a, ix, iy;

	end = 0;
	match = 0;
	if (st->mapsub == 0) {
		left = (GetMapLeft(st->mapno) << 16) + 0x80000;
		right = (GetMapRight(st->mapno) << 16) - 0x90000;
	} else if (st->mapsub == 1) {
		left = 0x200000;
		right = 0x8F0000;
	} else {
		left = 0xB00000;
		right = 0x11F0000;
	}
	bottom = 0x1180000 - (st->scroll * 14 << 16);
	n = 0;
	top = 0x200000 - (st->scroll * 14 << 16);
	frame = 0;
	DX = -Cos(st->unk454);
	DY = -Sin(st->unk454);
	X = st->bx << 16;
	Y = st->by << 16;
	anim = st->guide_anim;
	while (1) {
		X += DX;
		Y += DY;
		if (X < left) {
			DX = DX < 0 ? -DX : DX;
			X = left;
		} else if (right < X) {
			DX = -(DX < 0 ? -DX : DX);
			X = right;
		}
		if (Y < top) {
			Y = top;
			DY = DY < 0 ? -DY : DY;
		}
		if (bottom < Y)
			end = 1;
		iy = Y >> 16;
		ix = *(s16 *)((char *)&X + 2);
		if ((frame & 3) == 0 && n < 256) {
			st->gx[n] = ix;
			st->gy[n] = iy + st->scroll * 14;
			n++;
		}
		ly = iy - st->ofs_y;
		lx = ix - MapXBeginPos[st->mapno * 3 + st->mapsub];
		for (i = 0; i < 8; i++) {
			p = CvtBallPos2MapPosLocal(st, lx + BallCollisionPosition[i].x, ly + BallCollisionPosition[i].y);
			if (p < 0 || st->mp.map[p] != 0) {
				GetBallCoordinate(st, GetBallMapAddr(st, lx, ly, 0), &lx, &ly);
				end = 1;
				for (i = 1; i < 7; i++) {
					a = GetBallMapAddr(st, lx, ly, i);
					if (st->mapsub == 2)
						CpuCheckBall[i - 1] = st->mp.map[a];
					if (a >= 0 && st->mp.map[a] == st->cur + 1)
						match = 1;
				}
				goto done;
			}
		}
		frame++;
		if (end)
			break;
	}
done:
	st->guide_col = match ? 2 : 1;
	if (end == 1) {
		lx = ix - MapXBeginPos[st->mapno * 3 + st->mapsub];
		ly = iy - st->ofs_y;
		GetBallCoordinate(st, CvtBallPos2MapPosLocal(st, lx, ly), &lx, &ly);
		n -= n >= 256;
		n = n / 8 * 8;
		for (i = 7; i >= 0; i--) {
			st->gx[n] = lx + MapXBeginPos[st->mapno * 3 + st->mapsub];
			st->gy[n] = ly + st->ofs_y + st->scroll * 14;
			n++;
		}
	}
	anim++;
	st->guide_anim = anim % 8;
	st->guide_n = n / 8;
}
#else
/* STAND-IN: CheckBallGuide is still asm.  Its statics, in its place and numbered as in the
 * original (X.9, Y.10, DX.11, DY.12); data ones only keep the numbering (their .data stays asm). */
static void __attribute__((section(".pbskip"), unused)) CheckBallGuide_statics(void)
{
	static int X;
	static int Y;
	static int DX;
	static int DY;
}
__asm__("D_0014E888 = X.9\nD_0014E88C = Y.10\nD_0014E890 = DX.11\nD_0014E894 = DY.12");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallGuide);
#endif

#ifdef NON_MATCHING
/* Rough (6 instructions short): CheckBallGuide with a double step that falls back to
 * single steps (restoring the previous position) at the ceiling or on a hit; most locals
 * live in stack slots in the original. */
extern u8 CpuCheckBall[];
void CheckBallGuideVS(PZL_STAT *st)
{
	static int X;
	static int Y;
	static int DX;
	static int DY;
	static int AX;
	static int AY;
	static short PushTime1;
	int lx, ly;
	int left, right, top, bottom;
	int n, frame, anim, end, match;
	int step, i, p, ix, iy;

	end = 0;
	match = 0;
	if (st->mapsub == 0) {
		left = (GetMapLeft(st->mapno) << 16) + 0x80000;
		right = (GetMapRight(st->mapno) << 16) - 0x90000;
	} else if (st->mapsub == 1) {
		left = 0x200000;
		right = 0x8F0000;
	} else {
		left = 0xB00000;
		right = 0x11F0000;
	}
	bottom = 0x1180000 - (st->scroll * 14 << 16);
	top = 0x200000 - (st->scroll * 14 << 16);
	step = 2;
	DX = -Cos(st->unk454);
	n = 0;
	frame = 0;
	DY = -Sin(st->unk454);
	X = st->bx << 16;
	Y = st->by << 16;
	anim = st->guide_anim;
	while (1) {
		AX = X;
		X += DX * step;
		AY = Y;
		Y += DY * step;
		if (X < left) {
			DX = DX < 0 ? -DX : DX;
			X = left;
		} else if (right < X) {
			DX = -(DX < 0 ? -DX : DX);
			X = right;
		}
		if (Y < top) {
			Y = top;
			if (step != 1) {
				step = 1;
				X = AX;
				Y = AY;
			} else
				end = 1;
		}
		if (bottom < Y)
			end = 1;
		iy = Y >> 16;
		ix = *(s16 *)((char *)&X + 2);
		if ((frame & 3) == 0 && n < 256) {
			n++;
			st->gx[n - 1] = ix;
			st->gy[n - 1] = iy + st->scroll * 14;
		}
		ly = iy - st->ofs_y;
		lx = ix - MapXBeginPos[st->mapno * 3 + st->mapsub];
		for (i = 0; i < 8; i++) {
			p = CvtBallPos2MapPosLocal(st, lx + BallCollisionPosition[i].x, ly + BallCollisionPosition[i].y);
			if (p < 0 || st->mp.map[p] != 0)
				break;
		}
		if (i < 8) {
			if (step != 1) {
				step = 1;
				X = AX;
				Y = AY;
			} else {
				GetBallCoordinate(st, GetBallMapAddr(st, lx, ly, 0), &lx, &ly);
				end = 1;
				for (i = 1; i < 7; i++) {
					p = GetBallMapAddr(st, lx, ly, i);
					if (st->mapsub == 2)
						CpuCheckBall[i - 1] = st->mp.map[p];
					if (p >= 0 && st->mp.map[p] == st->cur + 1)
						match = 1;
				}
				break;
			}
		}
		frame++;
		if (end)
			break;
	}
	st->guide_col = match ? 2 : 1;
	if (end == 1) {
		lx = ix - MapXBeginPos[st->mapno * 3 + st->mapsub];
		ly = iy - st->ofs_y;
		GetBallCoordinate(st, CvtBallPos2MapPosLocal(st, lx, ly), &lx, &ly);
		n -= n >= 256;
		n = n / 8 * 8;
		for (i = 7; i >= 0; i--) {
			st->gx[n] = lx + MapXBeginPos[st->mapno * 3 + st->mapsub];
			st->gy[n] = ly + st->ofs_y + st->scroll * 14;
			n++;
		}
	}
	anim++;
	st->guide_anim = anim % 8;
	st->guide_n = n / 8;
}
#else
/* STAND-IN: CheckBallGuideVS is still asm.  Its statics, in its place and numbered as in the
 * original (X.13, Y.14, DX.15, DY.16, AX.17, AY.18, PushTime1.19); data ones only keep the numbering (their .data stays asm). */
static void __attribute__((section(".pbskip"), unused)) CheckBallGuideVS_statics(void)
{
	static int X;
	static int Y;
	static int DX;
	static int DY;
	static int AX;
	static int AY;
	static short PushTime1;
}
__asm__("D_0014E898 = X.13\nD_0014E89C = Y.14\nD_0014E8A0 = DX.15\nD_0014E8A4 = DY.16\nD_0014E8A8 = AX.17\nD_0014E8AC = AY.18\nD_0014E8B0 = PushTime1.19");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallGuideVS);
#endif

int CheckGuideLine(PZL_STAT *st)
{
	static int AllowSe;
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
		if (st->unk006 < 0x18 && AllowSe == 0) {
			se_play(21);
			AllowSe = 5;
		}
	}
	if (AllowSe > 0)
		AllowSe--;
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
	SpriteDrawC(z, x + 28, y, &NUMERIC_PARTZ[10]);
	SpriteDrawC(z, x - 28, y, &NUMERIC_PARTZ[10]);
}

int Get2Dim(int x, int a, int b, int c, int d)
{
	int r = 0;

	if (a <= x && x <= b) {
		x -= b;
		r = -(x * x) * 320 / ((b - a) * (b - a));
	} else if (b <= x && x <= c)
		r = 0;
	else if (c <= x && x <= d) {
		x -= c;
		r = x * x * 320 / ((d - c) * (d - c));
	} else
		r = 960;
	return r;
}

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

#ifdef NON_MATCHING
/* Draft, logic complete; see tmp/pbbody/NOTES.md for the remaining differences. */
extern int KeyStat;
extern int KeyHit;
extern int VKeyHit;
extern int isPause;
extern int MsAccessFlag;
extern int SaveDataBuf[10];
extern int Cont;
extern int Ti;
extern int TimeBonus;
extern int minY;
extern int maxY;
extern PARTZ ChrData_Zen[];
extern PARTZ ChrData_Count[];
extern const SPRDATA PUZZLE_PARTZ[];
extern const SPRDATA GAMEMODE_PARTZ[];
extern const SPRDATA PAUSE_PARTZ[];
extern const SPRDATA WINLOSE_PARTZ[];
extern const int ChNamePos[];
int GetKeyStat(void);
void DrawBubble(float scale, int x, int y, int col, int frame);
void DrawMapData(PZL_STAT *st, int stage);
void DoCharacters(PZL_STAT *st);
void DoReadyGo(PZL_STAT *st);
void DoMonitor(PZL_STAT *st);
int CheckGuideLine(PZL_STAT *st);
void CheckBallGuide(PZL_STAT *st);
int CheckBallTouch(PZL_STAT *st, int flag);
void CheckBallDrop(PZL_STAT *st);
int CheckBallRainbow(PZL_STAT *st);
int CheckRoundClear(PZL_STAT *st);
int CheckBallCollision(PZL_STAT *st);
int GetMapLeft(int no);
int GetMapRight(int no);
short Sin(short a);
short Cos(short a);
void PauseControl(void *arg0);
void DoBubStat(PZL_STAT *st, int arg);
int DoContinue(int t, int flag);
int MsSave(void);
void PutTime(int z, int x, int y, int t);
void DrawAnk(int z, int x, int y, int num);
void DrawScore(int z, int x, int y, int num);
void DrawLight(int x, int y, int col, int no);
void DoBubCrush(void);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);
int DrawSpriteZoom(int no, int color, float z, float x, float y, float w, float h, float u, float v, float cx, float cy, float sx, float sy, float rot);
static inline void DrawPat47(int x, int y, int t)
{
	int f = t * 6 / 16;
	int u = f % 4;
	int v = f / 4;

	SpriteDrawEz(47, 0, -1, x, y, 128.0f, 128.0f, u * 128, v * 128);
}

int PuzzleBody(void)
{
	static int Ticks;
	static int X;
	static int Y;
	static float zoom = 1.0f;
	static int frame;
	static int zen;
	static int eye = 20;
	static int bgnum;
	static int LCount;
	PZL_STAT *st;
	int ret = 0;
	int light;
	int pat;
	int i;
	int k;
	short ang;
	float z;

	KeyStat = GetKeyStat();
	KeyHit = GetKeyHit();
	st = Stat;
	VKeyHit = 0;
	st->key = KeyStat;
	st->key_rep = KeyHit;
	st->unk444 = 0;
	st->unk448 = 0;
	light = GetBallLine(st) < 8 ? 0 : 2;
	PauseControl(st);
	isPause = PauseFlag;
	if (MsAccessFlag) {
		isPause = 1;
		PollShutter(0);
	}
	if (isPause == 0) {
		st->unk47F = 0;
		if (CheckGuideLine(st))
			st->unk47F = 1;
		Ticks = (Ticks + 1) % 8;
		st->unk430++;
	}
	DoCharacters(st);
	DoReadyGo(st);
	if (isPause == 0) {
		switch (st->unk006) {
		default: {

			PollShutter(0);
			if (PollShutter(5) || st->unk430 < 60) {
				PauseOk = 0;
				break;
			}
			if (st->unk00E > 0)
				st->unk00E--;
			if (st->drop.unk2 == 1) {
				st->drop.unk2 = 2;
				CheckBallGuide(st);
			}
			if (st->unk428 && SaveDataBuf[4]) {
				for (i = 0; i < 32; i++) {
					if (i < st->guide_n && st->drop.unk2 == 2) {
						if (st->guide_col == 2 && (Ticks / 2) & 1)
							k = 10;
						else {
							k = st->cur;
							k = k == 9 ? 7 : k % 8;
						}
						DrawBubble(0.3f, st->gx[i * 8 + Ticks] + 72, st->gy[i * 8 + Ticks], k, 0);
					}
				}
			}
			if ((KeyHit & 0x2000) || st->unk00E <= 0) {
				se_play(12);
				ang = st->unk454;
				st->unk00E = 600;
				st->fx = st->bx << 16;
				st->fy = st->by << 16;
				st->unk006 = 2;
				st->unk008 = 0;
				st->vx = -Cos(ang);
				st->vy = -Sin(ang);
			}
			break;
		}
		case 2: {
			int flag, left, right;

			X = st->vx;
			Y = st->vy;
			left = (GetMapLeft(st->mapno) << 16) + 0x80000;
			right = (GetMapRight(st->mapno) << 16) - 0x90000;
			minY = 0x200000 - (st->scroll * 14 << 16);
			maxY = 0x1180000 - (st->scroll * 14 << 16);
			flag = 0;
			for (i = 0; i < 12; i++) {
				st->fx += X;
				st->unk008++;
				st->fy += Y;
				if (st->fx < left) {
					X = X < 0 ? -X : X;
					st->vx = st->vx < 0 ? -st->vx : st->vx;
					st->fx = left;
					se_play(19);
				} else if (st->fx > right) {
					X = -(X < 0 ? -X : X);
					st->vx = -(st->vx < 0 ? -st->vx : st->vx);
					st->fx = right;
					se_play(19);
				}
				if (st->fy < minY) {
					Y = Y < 0 ? -Y : Y;
					st->vy = st->vy < 0 ? -st->vy : st->vy;
					st->fy = minY;
					se_play(20);
				}
				if (st->fy > maxY) {
					st->unk006 = 3;
					if (st->cur == 9)
						flag = 1;
					break;
				}
				st->bx = st->fx >> 16;
				st->by = st->fy >> 16;
				if (CheckBallTouch(st, 0)) {
					if (st->cur == 9) {
						st->bx = -64;
						st->by = -64;
					}
					flag = 1;
					break;
				}
			}
			if (flag) {
				st->unk006 = 15;
				st->snd.unk6 = st->bx;
				st->snd.unk8 = st->by;
				st->snd.unk1 = 0;
				if (st->cur == 9) {
					st->ndrop = 0;
					CheckBallDrop(st);
					st->unk006 = 10;
					st->unk024 = 0;
					st->ndrop = 0;
				}
				if (st->cur == 13) {
					st->snd.unk1 = 0;
					CheckBallDrop(st);
					st->unk006 = 16;
				}
			}
			break;
		}
		case 3:
			if (st->unk026 <= 0) {
				st->unk026 = st->unk027;
				st->unk025 = 12;
				st->unk006 = 4;
				st->scroll++;
				se_play(22);
				break;
			}
		case 4:
			if (st->unk430 < 60)
				st->unk006 = 0;
			else
				st->unk006 = 19;
			st->drop.unk2 = 1;
			st->by = 208 - st->scroll * 14;
			st->bx = 160;
			st->cur = st->next;
			st->next = GetBallNext(st, 0);
			st->unk026--;
			break;
		case 8:
			st->snd.se = 15;
			CheckBallDrop(st);
			st->unk006 = 9;
			st->unk45B = 0;
			SetCharacters(st, 4, 0);
			SetMonitor(st, 12);
		case 9: {
			int x, y, color, f;
			float s;

			light = 1;
			k = 16 - st->unk024--;
			if (st->unk024 != 0) {
				color = st->unk024 * 0.0625f * 255.0f;
				color <<= 24;
				color |= 0xFFFFFF;
				s = 1.0f;
				s += k * 0.25f;
				for (i = 0; i < st->ndrop; i++) {
					x = st->drop.d[i].x + MapXBeginPos[st->mapno * 3 + st->mapsub];
					y = st->drop.d[i].y + st->ofs_y + st->scroll * 14;
					DrawSpriteZoom(st->drop.d[i].col + 49, color, 0, x + 72, y, 16.0f, 16.0f, 0, 0, 8.0f, 8.0f, s, s, 0);
					if (st->drop.d[i].col != 9 && st->drop.d[i].col != 14) {
						DrawSpriteZoom(45, color, 1.0f, x + 16, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s * 0.25f, s * 0.25f, 0);
					} else if (st->drop.d[i].col == 9) {
						DrawSpriteZoom(46, color, 1.0f, x + 16, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s, s, k * 0.3f * 3.14f * 0.0625f);
					} else {
						DrawPat47(x + 16, y - 56, k);
					}
				}
			}
		}
		case 10:
			if (st->unk024 == 0) {
				st->unk006 = 12;
				st->ndrop = 0;
				st->unk024 = 0;
			}
			break;
		case 12:
			if (++st->unk45B >= 8) {
				st->unk45B = 8;
				st->unk006 = 13;
				st->unk024 = 0;
				st->ndrop = 0;
			}
			break;
		case 13:
			if (st->drop.unk1) {
				st->unk006 = 14;
				st->drop.unk1 = 0;
				st->ndrop = 0;
				if (CheckBallRainbow(st) > 0) {
					st->unk006 = 8;
					st->unk024 = 16;
					st->bx = -64;
					st->by = -64;
					break;
				}
			}
			st->unk024 = 0;
			st->ndrop = 0;
			if (CheckRoundClear(st)) {
				st->scroll = -18;
				st->unk42A = 1;
				st->unk006 = 29;
				se_play(8);
				PollShutter(1);
				SetCharacters(st, 5, 0);
				SetMonitor(st, 24);
			} else {
				st->unk006 = 3;
			}
			break;
		case 15: {
			int bx, by, n;

			GetBallCoordinate(st, st->snd.unk4, &bx, &by);
			bx += MapXBeginPos[st->mapno * 3 + st->mapsub];
			by += st->ofs_y;
			n = st->snd.unk1;
			st->bx = bx * n / 2 + st->snd.unk6 * (2 - n) / 2;
			st->by = by * n / 2 + st->snd.unk8 * (2 - n) / 2;
			if (++st->snd.unk1 >= 2) {
				st->unk006 = 16;
				st->snd.unk1 = 0;
				CheckBallCollision(st);
			}
			break;
		}
		case 16:
			st->bx = -64;
			st->by = -64;
			if (st->cur == 9) {
				st->unk006 = 10;
				st->unk024 = 0;
				st->ndrop = 0;
			} else if (st->ndrop == 0) {
				st->unk006 = 3;
			} else {
				st->unk006 = 8;
				st->unk024 = 16;
				st->bx = -64;
				st->by = -64;
				DoBubStat(st, 3);
			}
			break;
		case 19: {
			int w;

			k = 0;
			w = GetMapWidth(st->mapno);
			for (i = 0; i < w; i++) {
				if (st->mp.map[i + (11 - st->scroll) * w]) {
					k = 1;
					break;
				}
			}
			if (!k) {
				st->unk006 = 1;
				break;
			}
			st->unk006 = 22;
			st->unk025 = 12;
			st->unk42A = 0;
			se_play(9);
			SetCharacters(st, 7, 0);
			SetMonitor(st, 4);
			break;
		}
		case 22:
			if (++st->unk42A >= 36) {
				se_play(29);
				PollShutter(1);
				st->unk006 = 23;
			}
			break;
		case 23:
			SetCharacters(st, 7, 1);
			st->unk026 = 8;
			if (PollShutter(0)) {
				st->unk006 = 24;
				Cont = 0;
				st->unk025 = 0;
				st->unk42A = 0;
			}
			break;
		case 24:
			SetCharacters(st, 7, 1);
			PollShutter(0);
			st->unk42A = DoContinue(st->unk42A, Cont);
			if (st->unk025 == 0) {
				st->unk025 = 1;
				Cont = 0;
			}
			if (KeyHit & 0xA0) {
				Cont ^= 1;
				se_play(4);
			}
			if (st->unk42A >= 31 && (KeyHit & 0x2000)) {
				if (Cont) {
					st->unk006 = 40;
					ret = 0;
					st->unk42A = 0;
					bgm_stop();
					se_play(10);
					break;
				}
				se_play(0);
				SetCharacters(st, 3, 0);
				SetCharacters(st, 0, 1);
				SetMonitor(st, 0);
				st->unk42A = 0;
				StageNum--;
				st->unk006 = 31;
				st->unk428 = 2;
				st->unk434 = 0;
			} else {
				ret = 0;
				break;
			}
		case 31:
			st->scroll = -18;
			StageNum++;
			if (StageNum == 500)
				SaveDataBuf[9] = 1;
			if (SaveDataBuf[8] < StageNum + 1) {
				SaveDataBuf[8] = StageNum + 1;
				MsSave();
			}
			st->unk026 = st->unk027;
			st->unk00E = 600;
			st->by = 208 - st->scroll * 14;
			st->unk025 = 0;
			if (st->unk428 == 2)
				st->unk428 = 1;
			else
				st->unk428 = 0;
			st->unk430 = 0;
			if (StageNum < 500) {
				dsGMInit(0, StageNum);
				DrawMapData(st, StageNum);
				st->cur = st->next = GetBallNext(st, 1);
				if (StageNum % 10 == 0) {
					i = StageNum / 10 % 3;
					bgm_play(i + 1);
				}
				st->unk006 = 32;
			} else {
				SetCharacters(st, 0, 0);
				st->unk006 = 33;
			}
		case 32:
			if (PollShutter(0))
				st->unk006 = 3;
			break;
		case 29:
			SetCharacters(st, 0, 1);
			if (++st->unk42A >= 31) {
				st->unk42A = 1;
				st->unk006 = 30;
			}
			break;
		case 30:
			SetCharacters(st, 0, 1);
			PollShutter(0);
			if (st->unk42A == 1) {
				Ti = GetSysTime();
				if (Ti < 300)
					TimeBonus = 50000;
				else if (Ti < 2780)
					TimeBonus = 62000 - Ti * 40;
				else
					TimeBonus = 0;
				if (TimeBonus < 0)
					TimeBonus = 0;
				if (TimeBonus > 50000)
					TimeBonus = 0;
			}
			if (st->unk42A > 0)
				st->unk42A++;
			if (st->unk42A == 60)
				se_play(28);
			if (KeyHit & 0x2000) {
				if (st->unk42A >= 66 && st->unk42A < 165)
					st->unk42A = 165;
				else if (st->unk42A >= 186 && st->unk42A < 300)
					st->unk42A = 300;
			}
			if (st->unk42A == 185)
				st->unk434 += TimeBonus;
			DrawCharcter(0, Get2Dim(st->unk42A, 35, 50, 310, 320) + 64, 64, ChrData_ClearMes, 0);
			DrawCharcter(0, Get2Dim(st->unk42A, 50, 65, 165, 180) + 156, 148, ChrData_ClearMes, 7);
			PutTime(0, Get2Dim(st->unk42A, 55, 70, 170, 185) + 240, 184, Ti);
			DrawCharcter(0, Get2Dim(st->unk42A, 170, 185, 300, 315) + 156, 148, ChrData_ClearMes, 8);
			PutNumeric(0, Get2Dim(st->unk42A, 175, 190, 305, 320) + 240, 184, TimeBonus, 5);
			if (st->unk42A >= 320) {
				st->unk006 = 31;
				st->unk42A = 30;
			}
			break;
		case 33:
			PollShutter(0);
			if (MsAccessFlag == 0) {
				st->unk006 = 32;
				ret = 12;
				st->unk42A = 0;
			}
			break;
		case 40:
			SetCharacters(st, 7, 1);
			st->unk42A++;
			PollShutter(0);
			if (st->unk42A >= 46 && st->unk42A < 300 && (st->key_rep & 0x2000))
				st->unk42A = 300;
			SpriteDrawC(0, 240, (int)(Get2Dim(st->unk42A, 0, 45, 300, 345) * 0.8f) + 136, &WINLOSE_PARTZ[2]);
			if (st->unk42A > 300)
				SpriteSetFader((345 - st->unk42A) / 45.0f);
			if (st->unk42A >= 346) {
				ret = 4;
				SpriteSetFader(0);
				st->unk006 = 0;
				st->unk42A = 0;
			}
			break;
		}
		if (isPause == 0) {
			int j, n, x, y, c;
			float fl;

			for (j = 0; j < 3; j++) {
				for (i = 0; i < 192; i++) {
					if (st->ent[i].flag) {
						n = st->ent[i].vy++;
						x = st->ent[i].x;
						y = st->ent[i].y;
						x += 80;
						y -= 32;
						if (st->ent[i].col == 12) {
							fl = 64 - n;
							if (fl > 0) {
								fl *= 0.015625f;
								DrawBubble(fl, x, y, 11, 0);
							} else
								st->ent[i].flag = 0;
						} else {
							if (n > 0) {
								y += n * n / 40;
								if (y > 320)
									st->ent[i].flag = 0;
							}
							DrawBubble(0, x, y, st->ent[i].col - 1, 0);
						}
					}
				}
			}
		}
	}
	if (st->unk006 < 29 || st->unk006 == 32)
		DrawMapData(st, StageNum);
	DoBubCrush();
	i = st->unk454;
	DrawSpriteEx(1, 2.0f, 0, -15.5f, 0, 0, 0, 0, 0, 0, 0, 11.0f, 0, 0, (i - 256) * -3.14f * 0.001953125f, zoom, 0);
	if (st->unk006 != 17 && st->unk006 != 32)
		DrawBubble(0, st->bx + 72, st->by + st->scroll * 14, st->cur, 0);
	DrawBubble(0, 292, 222, st->next, 0);
	if (st->mapno == 0)
		DrawSpriteEz(3.0f, 176.0f, 184.0f, 128.0f, 8.0f, 0, 0, 7);
	else if (st->mapno == 1)
		DrawSpriteEz(3.0f, 104.0f, 184.0f, 272.0f, 8.0f, 0, 0, 7);
	else
		DrawSpriteEz(3.0f, 144.0f, 184.0f, 192.0f, 8.0f, 0, 0, 7);
	pat = 0;
	if (GetBallLine(st) >= 8) {
		if (zen != 1) {
			frame = 0;
			zen = 1;
		}
	} else if (zen == 1) {
		frame = 0;
		eye = 0;
		zen = 0;
	}
	switch (zen) {
	case 0:
		pat = 0;
		if (--eye < 0) {
			eye = rand() % 20 + 10;
			zen = 2;
		}
		break;
	case 1:
		frame = (frame + 1) % 32;
		pat = frame / 8 + 4;
		break;
	case 2:
		pat = 1;
		if (--eye < 0) {
			eye = rand() % 80 + 20;
			zen = 0;
		}
		break;
	}
	if (st->unk00E > 0 && st->unk00E < 330) {
		pat = 0;
		i = (short)(st->unk00E / 60);
		if ((short)(st->unk00E % 60) < 30) {
			DrawCharcter(2, 190, 188, ChrData_Count, i);
			pat = 2;
		}
	} else if (st->unk47F) {
		frame = (frame + 1) % 20;
		pat = frame / 5 + 8;
	}
	DrawCharcter(2, 160, 204, ChrData_Zen, pat);
	DrawSpriteEz(8.0f, 0.0f, 0.0f, 240.0f, 136.0f, 0.0f, 0.0f, 0);
	DrawSpriteEz(8.0f, 0.0f, 136.0f, 240.0f, 136.0f, 0.0f, 136.0f, 0);
	DrawSpriteEz(8.0f, 240.0f, 0.0f, 240.0f, 136.0f, 240.0f, 0.0f, 0);
	DrawSpriteEz(8.0f, 240.0f, 136.0f, 240.0f, 136.0f, 240.0f, 136.0f, 0);
	DrawSpriteEz(1.0f, 0.0f, 0.0f, 480.0f, 32.0f, 0.0f, 0.0f, 0);
	SpriteDrawC(1.0f, 200, 16, GAMEMODE_PARTZ);
	DrawScore(1, 300, 22, st->unk434);
	DrawSpriteEz(9.0f, 0.0f, 0.0f, 240.0f, 272.0f, 0.0f, 0.0f, bgnum + 22);
	DrawSpriteEz(9.0f, 240.0f, 0.0f, 240.0f, 272.0f, 240.0f, 0.0f, bgnum + 22);
	SpriteDrawC(6.0f, 240, 222, &PUZZLE_PARTZ[12]);
	z = 7.0f;
	SpriteDrawEz(10, z, -1, 4.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
	SpriteDrawEz(11, z, -1, 381.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
	DrawAnk(1, 427, 136, StageNum + 1);
	SpriteDrawC(6.0f, 240, 261, &PUZZLE_PARTZ[25]);
	LCount = (LCount + 1) % 50;
	SpriteDrawC(1.0f, 52, 216, &PUZZLE_PARTZ[6]);
	SpriteDrawC(1.0f, 428, 216, &PUZZLE_PARTZ[8]);
	SpriteDrawC(0, 44, 28, &PUZZLE_PARTZ[2 + LCount / 25]);
	SpriteDrawC(0, 436, 28, &PUZZLE_PARTZ[4 + LCount / 25]);
	SpriteDrawC(1.0f, 50, 241, &PUZZLE_PARTZ[LCount / 25]);
	SpriteDrawC(1.0f, 430, 241, &PUZZLE_PARTZ[LCount / 25]);
	SpriteDrawEz(12, 1.0f, -1, 16.0f, 190.0f, 72.0f, 16.0f, 0.0f, ChNamePos[st->player]);
	DrawLight(38, 79, light, 0);
	DrawLight(65, 52, light, 1);
	DrawLight(442, 79, light, 2);
	DrawLight(415, 52, light, 3);
	DoMonitor(st);
	DoMonitor(st + 2);
	if (st->mapno == 0) {
		DrawSpriteEz(z, 104.0f, 32.0f, 136.0f, 224.0f, 0.0f, 0.0f, 5);
		DrawSpriteEz(z, 240.0f, 32.0f, 136.0f, 224.0f, 136.0f, 0.0f, 5);
		DrawSpriteEz(z, 128.0f, 32.0f, 136.0f, 224.0f, 0.0f, 0.0f, 5);
		DrawSpriteEz(z, 216.0f, 32.0f, 136.0f, 224.0f, 136.0f, 0.0f, 5);
	}
	if (st->mapno == 2) {
		DrawSpriteEz(z, 104.0f, 32.0f, 136.0f, 224.0f, 0.0f, 0.0f, 5);
		DrawSpriteEz(z, 240.0f, 32.0f, 136.0f, 224.0f, 136.0f, 0.0f, 5);
	}
	if (PauseFlag)
		SpriteDrawC(0, 240, 136, PAUSE_PARTZ);
	return ret;
}
#else
/* STAND-IN: PuzzleBody is still asm.  Its statics, in its place and numbered as in the
 * original (Ticks.21, X.22, Y.23, zoom.24, frame.25, zen.26, eye.27, bgnum.28, LCount.29); data ones only keep the numbering (their .data stays asm). */
static void __attribute__((section(".pbskip"), unused)) PuzzleBody_statics(void)
{
	static int Ticks;
	static int X;
	static int Y;
	static float zoom __attribute__((section(".pbskipd")));
	static int frame;
	static int zen;
	static int eye __attribute__((section(".pbskipd")));
	static int bgnum;
	static int LCount;
}
__asm__("D_0014E8B8 = Ticks.21\nD_0014E8BC = X.22\nD_0014E8C0 = Y.23\nD_0014E8C4 = frame.25\nD_0014E8C8 = zen.26\nD_0014E8CC = bgnum.28\nD_0014E8D0 = LCount.29");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PuzzleBody);
#endif

extern u8 CpuCheckBall[];
extern int D_00038A50;
int CPUThinking(PZL_STAT *st)
{
	static short PushTime0;
	static short PushTime1;
	static int ArrowDir;
	static int ArrowTime;
	/* STAND-IN: numbering only; the real `static int ArrowType = 1;` is .data,
	 * which stays asm (D_00038A50) */
	static int ArrowType __attribute__((section(".pbskipd")));
	int ret = 1;
	int i, f, c;

	st->key_rep = 0;
	switch (st->cpu) {
	case 0:
	think:
		ArrowDir = D_00038A50 == -1 ? 0x80 : 0x20;
		ArrowTime = rand() % 20 + 2;
		st->cpu = 1;
	case 1:
		if (--ArrowTime == 0) {
			st->cpu = 3;
			ArrowTime = 0;
			ArrowDir = 0;
		}
		break;
	case 2:
		ArrowDir = 0;
		if (--ArrowTime <= 0)
			st->cpu = 3;
		break;
	case 3:
		ArrowDir = 0;
		f = 0;
		for (i = 0; i < 6; i++) {
			if (CpuCheckBall[i] == st->cur + 1 || CpuCheckBall[i] == 9)
				f = 1;
		}
		if (f) {
			st->key_rep = 0x2000;
			st->cpu = 6;
		} else {
			st->key_rep = 0;
			st->cpu = 0;
			goto think;
		}
		break;
	case 4:
	case 5:
		break;
	case 6:
		ret = 0;
		if (st->unk006 != 2)
			st->cpu = 0;
		break;
	}
	if (ArrowDir & 0x20) {
		PushTime0++;
		PushTime1 = 0;
		st->unk454 += 4;
		if (PushTime0 >= 5)
			PushTime0 = 4;
		if (st->unk454 >= 472) {
			D_00038A50 = -1;
			st->unk454 = 464;
		}
		st->drop.unk2 = 0;
	} else if (ArrowDir & 0x80) {
		PushTime1++;
		PushTime0 = 0;
		st->unk454 -= 4;
		if (PushTime1 >= 5)
			PushTime1 = 4;
		if (st->unk454 < 35 || st->unk454 >= 504) {
			D_00038A50 = 1;
			st->unk454 = 34;
		}
		st->drop.unk2 = 0;
	} else {
		PushTime0 = 0;
		PushTime1 = 0;
		if (st->drop.unk2 == 0)
			st->drop.unk2 = 1;
	}
	return ret;
}

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

#ifdef NON_MATCHING
/* Draft, logic complete; see tmp/pbbody/NOTES.md for the remaining differences. */
extern int KeyStat;
extern int KeyHit;
extern int VKeyHit;
extern int isPause;
extern int MsAccessFlag;
extern int SaveDataBuf[10];
extern int Cont;
extern int Ti;
extern int TimeBonus;
extern int minY;
extern int maxY;
extern int SurvPush;
extern int ColorTableVS[];
extern int ColorRndMaxVS;
extern const SPRDATA NEW_RECORD_PARTZ[];
extern const SPRDATA SAVE_PARTZ[];
extern const SPRDATA ATTACK_PARTZ[];
extern const SPRDATA WINLOSE_PARTZ[];
extern const char D_0002E5C8[];
extern const char D_0002E5DC[];
int printf(const char *fmt, ...);
void CheckBallGuideVS(PZL_STAT *st);
int CPUThinking(PZL_STAT *st);
int GetOjamaPat(int mode);
void DrawCount(int z, int x, int y, int num);
extern PARTZ ChrData_Zen[];
extern PARTZ ChrData_Count[];
extern const SPRDATA PUZZLE_PARTZ[];
extern const SPRDATA GAMEMODE_PARTZ[];
extern const SPRDATA PAUSE_PARTZ[];
extern const SPRDATA WINLOSE_PARTZ[];
extern const int ChNamePos[];
int GetKeyStat(void);
void DrawBubble(float scale, int x, int y, int col, int frame);
void DrawMapData(PZL_STAT *st, int stage);
void DoCharacters(PZL_STAT *st);
void DoReadyGo(PZL_STAT *st);
void DoMonitor(PZL_STAT *st);
int CheckGuideLine(PZL_STAT *st);
void CheckBallGuide(PZL_STAT *st);
int CheckBallTouch(PZL_STAT *st, int flag);
void CheckBallDrop(PZL_STAT *st);
int CheckBallRainbow(PZL_STAT *st);
int CheckRoundClear(PZL_STAT *st);
int CheckBallCollision(PZL_STAT *st);
int GetMapLeft(int no);
int GetMapRight(int no);
short Sin(short a);
short Cos(short a);
void PauseControl(void *arg0);
void DoBubStat(PZL_STAT *st, int arg);
int DoContinue(int t, int flag);
int MsSave(void);
void PutTime(int z, int x, int y, int t);
void DrawAnk(int z, int x, int y, int num);
void DrawScore(int z, int x, int y, int num);
void DrawLight(int x, int y, int col, int no);
void DoBubCrush(void);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);
int DrawSpriteZoom(int no, int color, float z, float x, float y, float w, float h, float u, float v, float cx, float cy, float sx, float sy, float rot);
static inline void DrawPat47(int x, int y, int t)
{
	int f = t * 6 / 16;
	int u = f % 4;
	int v = f / 4;

	SpriteDrawEz(47, 0, -1, x, y, 128.0f, 128.0f, u * 128, v * 128);
}

int VSModeBody(int pl)
{
	static int Ticks;
	static int X;
	static int Y;
	static int AtkNum;
	static int AtkPos[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
	static float zoom = 1.0f;
	static int frame[3];
	static int zen[3];
	static int eye[3] = { 20, 20, 20 };
	static int bgnum;
	static int LCount;
	PZL_STAT *st;
	int ret = 0;
	int light;
	int pat;
	int i;
	int k;
	short ang;
	int x, n;

	KeyStat = GetKeyStat();
	KeyHit = GetKeyHit();
	VKeyHit = 0;
	if (pl < 1 || pl > 2)
		pl = 1;
	st = &Stat[pl];
	st->key = KeyStat;
	st->key_rep = KeyHit;
	st->unk444 = 0;
	st->unk448 = 0;
	light = GetBallLine(st) < 8 ? 0 : 2;
	st->mapno = 0;
	if (pl == 1)
		st->mapsub = 1;
	else
		st->mapsub = 2;
	PauseControl(st);
	isPause = PauseFlag;
	if (isPause == 0) {
		st->unk47F = 0;
		if (pl == 1) {
			if (CheckGuideLine(st))
				st->unk47F = 1;
		} else if (CPUThinking(st))
			st->unk47F = 1;
		Ticks = (Ticks + 1) % 8;
		st->unk430++;
	}
	DoCharacters(st);
	if (pl == 1)
		DoReadyGo(st);
	if (isPause == 0) {
		switch (st->unk006) {
		default:
			if (pl == 1)
				PollShutter(0);
			if (PollShutter(5) || st->unk430 < 60)
				break;
			if (st->unk00E > 0)
				st->unk00E--;
			if (st->drop.unk2 == 1) {
				st->drop.unk2 = 2;
				CheckBallGuideVS(st);
			}
			if (st->unk428) {
				for (i = 0; i < 32; i++) {
					if (i < st->guide_n && st->drop.unk2 == 2) {
						if (st->guide_col == 2 && (Ticks / 2) & 1)
							k = 10;
						else {
							k = st->cur;
							k = k == 9 ? 7 : k % 8;
						}
						DrawBubble(0.3f, st->gx[i * 8 + Ticks] + 72, st->gy[i * 8 + Ticks], k, 0);
					}
				}
			}
			if ((st->key_rep & 0x2000) || st->unk00E <= 0) {
				se_play(12);
				if (st->mapsub == 1)
					st->unk00E = 600;
				else
					st->unk00E = 300;
				ang = st->unk454;
				st->unk006 = 2;
				st->fx = st->bx << 16;
				st->fy = st->by << 16;
				st->unk008 = 0;
				st->vx = -Cos(ang);
				st->vy = -Sin(ang);
			}
			break;
		case 2: {
			int flag, left, right;

			X = st->vx;
			Y = st->vy;
			if (st->mapsub == 1) {
				left = 0x200000;
				right = 0x8F0000;
			} else {
				left = 0xB00000;
				right = 0x11F0000;
			}
			minY = 0x200000 - (st->scroll * 14 << 16);
			maxY = 0x1180000 - (st->scroll * 14 << 16);
			flag = 0;
			for (i = 0; i < 12; i++) {
				st->fx += X;
				st->unk008++;
				st->fy += Y;
				if (st->fx < left) {
					X = X < 0 ? -X : X;
					st->vx = st->vx < 0 ? -st->vx : st->vx;
					st->fx = left;
					se_play(19);
				} else if (st->fx > right) {
					X = -(X < 0 ? -X : X);
					st->vx = -(st->vx < 0 ? -st->vx : st->vx);
					st->fx = right;
					se_play(19);
				}
				st->bx = st->fx >> 16;
				st->by = st->fy >> 16;
				if (CheckBallTouch(st, 1)) {
					if (st->cur == 9) {
						st->bx = -64;
						st->by = -64;
					}
					flag = 1;
					break;
				}
			}
			if (flag) {
				st->unk006 = 15;
				st->snd.unk6 = st->bx;
				st->snd.unk8 = st->by;
				st->snd.unk1 = 0;
				if (st->cur == 9) {
					st->ndrop = 0;
					CheckBallDrop(st);
					st->unk006 = 10;
					st->unk024 = 0;
					st->ndrop = 0;
				}
			}
			break;
		}
		case 3:
			if (st->unk026 <= 0) {
				st->unk026 = st->unk027;
				st->unk025 = 12;
				st->unk006 = 17;
				se_play(22);
				break;
			}
		case 4:
			st->unk006 = 5;
		case 5:
			if (st->unk430 < 60)
				st->unk006 = 0;
			else
				st->unk006 = 19;
			st->drop.unk2 = 1;
			st->bx = BallXPos[pl];
			st->by = 208 - st->scroll * 14;
			st->cur = st->next;
			st->next = GetBallNext(st, 0);
			st->unk026--;
			break;
		case 15: {
			int bx, by, n;

			GetBallCoordinate(st, st->snd.unk4, &bx, &by);
			bx += MapXBeginPos[st->mapno * 3 + st->mapsub];
			by += st->ofs_y;
			n = st->snd.unk1;
			st->bx = bx * n / 2 + st->snd.unk6 * (2 - n) / 2;
			st->by = by * n / 2 + st->snd.unk8 * (2 - n) / 2;
			if (++st->snd.unk1 >= 2) {
				st->unk006 = 16;
				st->snd.unk1 = 0;
				CheckBallCollision(st);
			}
			break;
		}
		case 6: {
			int mode;
			int pos[8];
			int x, y;

			if (st->mapsub == 1)
				mode = (u8)Stat[2].snd.unk2;
			else
				mode = (u8)Stat[1].snd.unk2;
			if (mode < 3) {
				if (st->unk474 < 7) {
					st->unk006 = 20;
					break;
				}
				st->unk474 -= 7;
				SetMonitor(st, 21);
				if (st->scroll == -4) {
					for (i = 159; i >= 0; i--)
						st->mp.map[i + 16] = st->mp.map[i];
					for (i = 0; i < 8; i++)
						st->mp.map[32 + i] = 12;
					st->mp.map[16] = 13;
					for (i = 0; i < 7; i++) {
						st->mp.map[24 + i] = 12;
						st->mp.map[40 + i] = GetOjamaPat(mode % 3);
					}
					if (mode == 2)
						st->mp.map[40 + rand() % 7] = 9;
					st->scroll = -5;
					st->by = 278;
				} else {
					for (i = 0; i < 7; i++)
						st->mp.map[24 + i] = 12;
					st->mp.map[8] = 13;
					for (i = 0; i < 8; i++) {
						st->mp.map[16 + i] = 12;
						st->mp.map[32 + i] = GetOjamaPat(mode % 3);
					}
					if (mode == 2)
						st->mp.map[40 + rand() % 7] = 9;
					st->scroll = -4;
					st->by = 264;
				}
				st->unk006 = 20;
				break;
			}
			if (st->unk474 <= 0) {
				st->unk006 = 20;
				break;
			}
			AtkNum = st->unk474 > 7 ? 7 : st->unk474;
			st->unk474 -= AtkNum;
			st->snd.unk3 = AtkNum;
			SetMonitor(st, 21);
			for (i = 0; i < 20; i++) {
				int a = rand() % 7;
				int b = rand() % 7;

				k = AtkPos[a];
				AtkPos[a] = AtkPos[b];
				AtkPos[b] = k;
			}
			for (i = 0; i < AtkNum; i++) {
				for (k = 31; k >= 0; k--) {
					if (st->mp.map[k * 8 + AtkPos[i]]) {
						k++;
						pos[i] = k;
						GetBallCoordinate(st, k * 8 + AtkPos[i], &x, &y);
						st->oj[i].y = y;
						st->oj[i].pos = AtkPos[i] + k * 8;
						st->oj[i].x = x;
						st->oj[i].t = 32 + i * 2;
						st->oj[i].col = GetOjamaPat(mode % 3);
						break;
					}
				}
			}
			st->unk006 = 7;
		}
		case 7: {
			int cnt;

			cnt = 0;
			for (i = 0; i < st->snd.unk3; i++) {
				if (--st->oj[i].t < 0) {
					st->oj[i].t = 0;
					cnt++;
				}
				k = st->oj[i].t;
				DrawBubble(0, st->oj[i].x + MapXBeginPos[st->mapno * 3 + st->mapsub] + 72, st->oj[i].y + st->ofs_y + st->scroll * 14 + k * k / 5, st->oj[i].col - 1, 0);
			}
			if (st->snd.unk3 == cnt) {
				for (i = 0; i < st->snd.unk3; i++)
					st->mp.map[st->oj[i].pos] = st->oj[i].col;
				st->unk006 = 20;
				st->snd.unk3 = 0;
			}
			break;
		}
		case 8:
			k = 0;
			for (i = 0; i < st->ndrop; i++) {
				if ((u8)(st->drop.d[i].col - 1) < 8)
					k = 1;
				if (st->drop.d[i].col == 9 || st->drop.d[i].col == 14)
					k = 1;
			}
			if (!k) {
				st->unk006 = 3;
				st->ndrop = 0;
				break;
			}
			st->snd.se = 15;
			CheckBallDrop(st);
			st->unk006 = 9;
			st->unk45B = 0;
			SetCharacters(st, 4, 0);
			SetMonitor(st, 12);
		case 9: {
			int color, x, y;
			float s;

			light = 1;
			k = 16 - st->unk024--;
			if (st->unk024 != 0) {
				color = st->unk024 * 0.0625f * 255.0f;
				color <<= 24;
				color |= 0xFFFFFF;
				s = 1.0f;
				s += k * 0.25f;
				for (i = 0; i < st->ndrop; i++) {
					if ((u8)(st->drop.d[i].col - 1) < 9 || st->drop.d[i].col == 14) {
						x = st->drop.d[i].x + MapXBeginPos[st->mapno * 3 + st->mapsub];
						y = st->drop.d[i].y + st->ofs_y + st->scroll * 14;
						DrawSpriteZoom(st->drop.d[i].col + 49, color, 0, x + 72, y, 16.0f, 16.0f, 0, 0, 8.0f, 8.0f, s, s, 0);
						if (st->drop.d[i].col != 9 && st->drop.d[i].col != 14) {
							DrawSpriteZoom(45, color, 1.0f, x + 16, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s * 0.25f, s * 0.25f, 0);
						} else if (st->drop.d[i].col == 9) {
							DrawSpriteZoom(46, color, 1.0f, x + 16, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s, s, k * 0.3f * 3.14f * 0.0625f);
						} else {
							DrawPat47(x + 16, y - 56, k);
						}
					}
				}
			}
		}
		case 10:
			if (st->unk024 == 0) {
				st->unk006 = 12;
				st->ndrop = 0;
				st->unk024 = 0;
			}
			break;
		case 12:
			if (++st->unk45B >= 8) {
				st->unk45B = 8;
				if (st->nchain == 0) {
					st->unk006 = 13;
					st->ndrop = 0;
				}
			}
			break;
		case 13:
			if (st->drop.unk1) {
				st->unk006 = 14;
				st->drop.unk1 = 0;
				st->ndrop = 0;
				if (CheckBallRainbow(st) > 0 && st->ndrop) {
					st->unk006 = 8;
					st->unk024 = 16;
					st->bx = -64;
					st->by = -64;
					break;
				}
			}
			st->unk006 = 3;
			st->unk024 = 0;
			st->ndrop = 0;
			break;
		case 16:
			st->by = -64;
			st->bx = -64;
			if (st->ndrop) {
				st->unk006 = 8;
				st->unk024 = 16;
				DoBubStat(st, 3);
			} else {
				st->unk006 = 3;
			}
			break;
		case 17:
			if (st->scroll == -4) {
				for (i = 159; i >= 0; i--)
					st->mp.map[i + 16] = st->mp.map[i];
				st->mp.map[16] = 13;
				for (i = 0; i < 7; i++) {
					st->mp.map[24 + i] = 12;
					st->mp.map[40 + i] = ColorTableVS[rand() % ColorRndMaxVS];
				}
				for (i = 0; i < 8; i++)
					st->mp.map[32 + i] = 12;
				st->scroll = -5;
			} else {
				for (i = 0; i < 7; i++)
					st->mp.map[24 + i] = 12;
				st->mp.map[8] = 13;
				for (i = 0; i < 8; i++) {
					st->mp.map[16 + i] = 12;
					st->mp.map[32 + i] = ColorTableVS[rand() % ColorRndMaxVS];
				}
				st->scroll = -4;
			}
			st->unk006 = 4;
			break;
		case 19: {
			PZL_STAT *op = st->mapsub == 1 ? &Stat[2] : &Stat[1];

			if (op->unk476 > 0) {
				op->unk474 += op->unk476;
				op->unk476 = 0;
			}
			if (st->unk474 > 0) {
				st->unk006 = 6;
				break;
			}
			st->unk006 = 20;
		}
		case 20: {
			PZL_STAT *op;
			int w;

			k = 0;
			w = GetMapWidth(st->mapno);
			for (i = 0; i < w; i++) {
				if (st->mp.map[i + (11 - st->scroll) * w]) {
					k = 1;
					break;
				}
			}
			if (!k) {
				st->unk006 = 1;
				break;
			}
			op = st->mapsub == 1 ? &Stat[2] : &Stat[1];
			st->unk47A = 1;
			st->unk006 = 22;
			st->unk025 = 12;
			op->unk006 = 22;
			op->unk47A = 0;
			SetCharacters(st, 7, 0);
			SetMonitor(st, 4);
			SetCharacters(op, 5, 0);
			SetMonitor(op, 24);
			if (pl == 1) {
				op->unk42A = 35;
				st->unk42A = 35;
				se_play(9);
			} else {
				op->unk42A = 65;
				st->unk42A = 65;
				se_play(8);
			}
			break;
		}
		case 22:
			if (pl != 1)
				break;
			if (--st->unk42A > 0)
				break;
			if (st->unk47A == 1)
				se_play(29);
			else
				se_play(28);
			PollShutter(1);
			Stat[2].unk42A = 0;
			st->unk006 = 23;
			st->unk42A = 0;
			break;
		case 23: {
			PZL_STAT *op = pl == 1 ? &Stat[2] : &Stat[1];

			st->unk026 = 8;
			op->unk026 = 8;
			if (pl != 1)
				break;
			if (PollShutter(0)) {
				st->unk006 = 28;
				st->unk025 = 0;
				st->unk026 = 8;
				op->unk006 = 28;
				op->unk025 = 0;
				op->unk026 = 8;
				st->unk42A = 0;
			}
			break;
		}
		case 24:
			st->unk006 = 25;
			Cont = 0;
			st->unk42A = 0;
			if (pl != 1)
				break;
			PollShutter(0);
			st->unk42A = 0;
			if (isSurvival) {
				if (SaveDataBuf[7] < StageNum) {
					SaveDataBuf[7] = StageNum;
					st->unk006 = 26;
				}
			} else {
				if (SaveDataBuf[6] < StageNum) {
					SaveDataBuf[6] = StageNum;
					st->unk006 = 26;
				}
			}
			break;
		case 25:
			if (pl != 1)
				break;
			PollShutter(0);
			st->unk42A = DoContinue(st->unk42A, Cont);
			if (st->unk025 == 0) {
				Cont = 0;
				st->unk025 = 1;
			}
			if (st->key_rep & 0xA0) {
				Cont ^= 1;
				se_play(4);
			}
			if (st->unk42A >= 31 && (st->key_rep & 0x2000)) {
				if (Cont) {
					st->unk006 = 40;
					st->unk42A = 0;
					ret = 0;
					bgm_stop();
					se_play(10);
				} else {
					se_play(0);
					StageNum = 0;
					st->unk006 = 0;
					st->unk428 = 0;
					st->unk42A = 0;
					SurvCont = 1;
					VSModeInit(0);
					SurvCont = 0;
					SetCharacters(st, 3, 0);
					SetCharacters(st, 0, 1);
					SetMonitor(st, 0);
				}
			} else {
				ret = 0;
			}
			break;
		case 26:
			if (pl != 1)
				break;
			PollShutter(0);
			if (++st->unk42A >= 16)
				st->unk42A = 15;
			SpriteDrawC(0, Get2Dim(st->unk42A, 0, 15, 300, 345) + 240, 54, NEW_RECORD_PARTZ);
			SpriteDrawC(0, 240, 152, SAVE_PARTZ);
			if (GetKeyHit() & 0x2000) {
				st->unk006 = 27;
				MsSave();
			}
			if (GetKeyHit() & 0x4000) {
				st->unk006 = 25;
				Cont = 0;
				st->unk42A = 0;
			}
			break;
		case 27:
			if (pl != 1)
				break;
			PollShutter(0);
			if (MsAccessFlag == 0) {
				st->unk006 = 25;
				Cont = 0;
				st->unk42A = 0;
			}
			break;
		case 28: {
			PZL_STAT *op = pl == 1 ? &Stat[2] : &Stat[1];

			if (pl == 1)
				PollShutter(0);
			st->unk42A++;
			SpriteDrawC(0, pl == 1 ? 168 : 312, (int)(Get2Dim(st->unk42A, 0, 25, 120, 145) * 0.8f) + 136, &WINLOSE_PARTZ[st->unk47A]);
			if (pl != 1)
				break;
			if (st->unk42A < 146)
				break;
			st->by = -64;
			st->bx = -64;
			st->unk006 = 24;
			op->by = -64;
			op->unk006 = 24;
			op->bx = -64;
			if (st->unk47A)
				break;
			st->unk006 = 0;
			op->unk006 = 0;
			st->unk42A = 0;
			st->unk428 = 0;
			if (++StageNum >= 1000)
				StageNum = 999;
			if (isSurvival) {
				SurvPush = st->scroll;
				SurvivlaModeInit(1);
				st->scroll = SurvPush;
				st->unk026 = st->unk027;
			} else
				VSModeInit(1);
			break;
		}
		case 40:
			st->unk42A++;
			PollShutter(0);
			if (st->unk42A >= 46 && st->unk42A < 300 && (st->key_rep & 0x2000))
				st->unk42A = 300;
			SpriteDrawC(0, 240, (int)(Get2Dim(st->unk42A, 0, 45, 300, 345) * 0.8f) + 136, &WINLOSE_PARTZ[2]);
			if (st->unk42A > 300)
				SpriteSetFader((345 - st->unk42A) / 45.0f);
			if (st->unk42A >= 346) {
				ret = 4;
				SpriteSetFader(0);
				st->unk006 = 0;
				st->unk42A = 0;
			}
			break;
		}
	}
	if (st->scroll == -4) {
		st->scroll = -4;
		st->mp.map[8] = 13;
		for (i = 0; i < 7; i++)
			st->mp.map[24 + i] = 12;
		for (i = 0; i < 8; i++)
			st->mp.map[16 + i] = 12;
		for (k = 0; k < 11; k++) {
			for (i = 0; i < 8; i++) {
				if (st->mp.map[32 + k * 8 + i] == 12) {
					st->mp.map[32 + k * 8 + i] = 0;
					printf(D_0002E5DC, k * 8 + 32 + i);
				}
			}
		}
	} else {
		st->scroll = -5;
		st->mp.map[16] = 13;
		for (i = 0; i < 7; i++)
			st->mp.map[24 + i] = 12;
		for (i = 0; i < 8; i++)
			st->mp.map[32 + i] = 12;
		for (k = 0; k < 11; k++) {
			for (i = 0; i < 8; i++) {
				if (st->mp.map[40 + k * 8 + i] == 12) {
					st->mp.map[40 + k * 8 + i] = 0;
					printf(D_0002E5C8, k * 8 + 40 + i);
				}
			}
		}
	}
	if (isPause == 0 && st->nchain) {
		int t = st->unk470;

		for (i = 0; i < st->nchain; i++) {
			x = st->chain[i].x * t / 60 + st->chain[i].a * (60 - t) / 60;
			x += MapXBeginPos[st->mapno * 3 + st->mapsub] + 72;
			n = st->chain[i].y * t / 60 + st->chain[i].b * (60 - t) / 60 - ((t - 30) * (t - 30) - 900) / 8;
			DrawBubble(0, x, n + (st->ofs_y + st->scroll * 14), st->chain[i].col - 1, 0);
		}
		if (++st->unk470 >= 60) {
			for (i = 0; i < st->nchain; i++) {
				st->mp.map[st->chain[i].pos] = st->chain[i].col;
				st->rainbow[st->chain[i].pos] = 1;
			}
			st->drop.unk1 = 1;
			st->unk470 = 0;
			st->nchain = 0;
			SetMonitor(st, 15);
		}
	}
	if (isPause == 0) {
		int j, y, c;
		float fl;

		for (j = 0; j < 3; j++) {
			for (i = 0; i < 192; i++) {
				if (st->ent[i].flag) {
					n = st->ent[i].vy++;
					x = st->ent[i].x;
					y = st->ent[i].y;
					x += 80;
					y -= 32;
					if (st->ent[i].col == 12) {
						fl = 64 - n;
						if (fl > 0) {
							fl *= 0.015625f;
							DrawBubble(fl, x, y, 11, 0);
						} else
							st->ent[i].flag = 0;
					} else {
						if (n > 0) {
							y += n * n / 40;
							if (y > 320)
								st->ent[i].flag = 0;
						}
						DrawBubble(0, x, y, st->ent[i].col - 1, 0);
					}
				}
			}
		}
	}
	if (isPause == 0) {
		int n7, r7, x, dx;

		n7 = (st->unk474 + st->unk476) / 7;
		r7 = (st->unk474 + st->unk476) % 7;
		x = 224;
		dx = -1;
		if (st->mapsub != 1) {
			x = 256;
			dx = 1;
		}
		for (i = 0; i < n7; i++) {
			SpriteDrawC(2.0f, x, 180, ATTACK_PARTZ);
			x += dx * 14;
		}
		x -= dx * 2;
		for (i = 0; i < r7; i++) {
			SpriteDrawC(2.0f, x, 180, &ATTACK_PARTZ[1]);
			x += dx * 7;
		}
	}
	if (st->unk006 < 29)
		DrawMapData(st, StageNum);
	DoBubCrush();
	DrawSpriteEx(1, 2.0f, pl == 1 ? -15.0f : 15.0f, -15.5f, 0, 0, 0, 0, 0, 0, 0, 11.0f, 0, 0, (st->unk454 - 256) * -3.14f * 0.001953125f, zoom, 0);
	if (st->unk006 != 17 && st->unk006 != 22 && st->unk006 != 23)
		DrawBubble(0, st->bx + 72, st->by + st->scroll * 14, st->cur, 0);
	DrawBubble(0, st->mapsub == 1 ? 204 : 348, 222, st->next, 0);
	DrawSpriteEz(3.0f, 104.0f, 184.0f, 272.0f, 8.0f, 0, 0, 7);
	pat = 0;
	if (GetBallLine(st) >= 8) {
		if (zen[pl] != 1) {
			zen[pl] = 1;
			frame[pl] = 0;
		}
	} else if (zen[pl] == 1) {
		frame[pl] = 0;
		zen[pl] = 0;
		eye[pl] = 0;
	}
	switch (zen[pl]) {
	case 0:
		pat = 0;
		if (--eye[pl] < 0) {
			eye[pl] = rand() % 20 + 10;
			zen[pl] = 2;
		}
		break;
	case 1:
		frame[pl] = (frame[pl] + 1) % 32;
		pat = frame[pl] / 8 + 4;
		break;
	case 2:
		pat = 1;
		if (--eye[pl] < 0) {
			eye[pl] = rand() % 80 + 20;
			zen[pl] = 0;
		}
		break;
	}
	if (st->unk00E > 0 && st->unk00E < 330 && st->mapsub == 1) {
		pat = 0;
		i = (short)(st->unk00E / 60);
		if ((short)(st->unk00E % 60) < 30) {
			DrawCharcter(2, 134, 188, ChrData_Count, i);
			pat = 2;
		}
	} else if (st->unk47F) {
		frame[pl] = (frame[pl] + 1) % 20;
		pat = frame[pl] / 5 + 8;
	}
	DrawCharcter(2, st->mapsub == 1 ? 104 : 247, 204, ChrData_Zen, pat);
	DoMonitor(st);
	if (pl == 1) {
		DrawLight(38, 79, light, 0);
		DrawLight(65, 52, light, 1);
	} else {
		DrawLight(442, 79, light, 2);
		DrawLight(415, 52, light, 3);
	}
	if (pl == 1) {
		PZL_STAT *op;

		DrawSpriteEz(8.0f, 0.0f, 0.0f, 240.0f, 136.0f, 0.0f, 0.0f, 0);
		DrawSpriteEz(8.0f, 0.0f, 136.0f, 240.0f, 136.0f, 0.0f, 136.0f, 0);
		DrawSpriteEz(8.0f, 240.0f, 0.0f, 240.0f, 136.0f, 240.0f, 0.0f, 0);
		DrawSpriteEz(8.0f, 240.0f, 136.0f, 240.0f, 136.0f, 240.0f, 136.0f, 0);
		DrawSpriteEz(1.0f, 0.0f, 0.0f, 480.0f, 32.0f, 0.0f, 0.0f, 0);
		SpriteDrawC(1.0f, 200, 16, isSurvival ? &GAMEMODE_PARTZ[3] : &GAMEMODE_PARTZ[2]);
		DrawCount(1, 300, 22, StageNum);
		DrawSpriteEz(9.0f, 0.0f, 0.0f, 240.0f, 272.0f, 0.0f, 0.0f, bgnum + 22);
		DrawSpriteEz(9.0f, 240.0f, 0.0f, 240.0f, 272.0f, 240.0f, 0.0f, bgnum + 22);
		SpriteDrawEz(10, 7.0f, -1, 4.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
		SpriteDrawEz(11, 7.0f, -1, 381.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
		SpriteDrawC(6.0f, 240, 261, &PUZZLE_PARTZ[25]);
		op = pl == 1 ? &Stat[2] : &Stat[1];
		LCount = (LCount + 1) % 50;
		SpriteDrawC(1.0f, 52, 216, &PUZZLE_PARTZ[6]);
		SpriteDrawC(1.0f, 428, 216, &PUZZLE_PARTZ[7]);
		SpriteDrawC(0, 44, 28, &PUZZLE_PARTZ[2 + LCount / 25]);
		SpriteDrawC(0, 436, 28, &PUZZLE_PARTZ[4 + LCount / 25]);
		SpriteDrawC(1.0f, 50, 241, &PUZZLE_PARTZ[LCount / 25]);
		SpriteDrawC(1.0f, 430, 241, &PUZZLE_PARTZ[LCount / 25]);
		SpriteDrawEz(12, 1.0f, -1, 16.0f, 190.0f, 72.0f, 16.0f, 0.0f, ChNamePos[st->player]);
		SpriteDrawEz(12, 1.0f, -1, 392.0f, 190.0f, 72.0f, 16.0f, 0.0f, ChNamePos[op->player]);
		SpriteDrawC(1.0f, 240, 144, &PUZZLE_PARTZ[10]);
		SpriteDrawC(6.0f, 168, 222, &PUZZLE_PARTZ[11]);
		SpriteDrawC(6.0f, 312, 222, &PUZZLE_PARTZ[11]);
	}
	if (PauseFlag)
		SpriteDrawC(0, 240, 136, PAUSE_PARTZ);
	return ret;
}
#else
/* STAND-IN: VSModeBody is still asm.  Its statics, in its place and numbered as in the
 * original (Ticks.35, X.36, Y.37, AtkNum.38, AtkPos.39, zoom.40, frame.41, zen.42, eye.43, bgnum.44, LCount.45); data ones only keep the numbering (their .data stays asm). */
static void __attribute__((section(".pbskip"), unused)) VSModeBody_statics(void)
{
	static int Ticks;
	static int X;
	static int Y;
	static int AtkNum;
	static int AtkPos[8] __attribute__((section(".pbskipd")));
	static float zoom __attribute__((section(".pbskipd")));
	static int frame[3];
	static int zen[3];
	static int eye[3] __attribute__((section(".pbskipd")));
	static int bgnum;
	static int LCount;
}
__asm__("D_0014E8E0 = Ticks.35\nD_0014E8E4 = X.36\nD_0014E8E8 = Y.37\nD_0014E8EC = AtkNum.38\nD_0014E8F0 = frame.41\nD_0014E8FC = zen.42\nD_0014E908 = bgnum.44\nD_0014E90C = LCount.45");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSModeBody);
#endif

#ifdef NON_MATCHING
/* Draft, logic complete; see tmp/pbbody/NOTES.md for the remaining differences. */
extern int KeyStat;
extern int KeyHit;
extern int VKeyHit;
extern int isPause;
extern int MsAccessFlag;
extern int SaveDataBuf[10];
extern int Cont;
extern int Ti;
extern int TimeBonus;
extern int minY;
extern int maxY;
extern int EndressColorRndMax;
extern int ColorTable[];
extern const SPRDATA NEW_RECORD_PARTZ[];
extern const SPRDATA SAVE_PARTZ[];
void CheckBallGuideVS(PZL_STAT *st);
int CPUThinking(PZL_STAT *st);
extern PARTZ ChrData_Zen[];
extern PARTZ ChrData_Count[];
extern const SPRDATA PUZZLE_PARTZ[];
extern const SPRDATA GAMEMODE_PARTZ[];
extern const SPRDATA PAUSE_PARTZ[];
extern const SPRDATA WINLOSE_PARTZ[];
extern const int ChNamePos[];
int GetKeyStat(void);
void DrawBubble(float scale, int x, int y, int col, int frame);
void DrawMapData(PZL_STAT *st, int stage);
void DoCharacters(PZL_STAT *st);
void DoReadyGo(PZL_STAT *st);
void DoMonitor(PZL_STAT *st);
int CheckGuideLine(PZL_STAT *st);
void CheckBallGuide(PZL_STAT *st);
int CheckBallTouch(PZL_STAT *st, int flag);
void CheckBallDrop(PZL_STAT *st);
int CheckBallRainbow(PZL_STAT *st);
int CheckRoundClear(PZL_STAT *st);
int CheckBallCollision(PZL_STAT *st);
int GetMapLeft(int no);
int GetMapRight(int no);
short Sin(short a);
short Cos(short a);
void PauseControl(void *arg0);
void DoBubStat(PZL_STAT *st, int arg);
int DoContinue(int t, int flag);
int MsSave(void);
void PutTime(int z, int x, int y, int t);
void DrawAnk(int z, int x, int y, int num);
void DrawScore(int z, int x, int y, int num);
void DrawLight(int x, int y, int col, int no);
void DoBubCrush(void);
int DrawSpriteEx(int no, float z, float f0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11, float f12, float f13, int flag);
int DrawSpriteZoom(int no, int color, float z, float x, float y, float w, float h, float u, float v, float cx, float cy, float sx, float sy, float rot);
static inline void DrawPat47(int x, int y, int t)
{
	int f = t * 6 / 16;
	int u = f % 4;
	int v = f / 4;

	SpriteDrawEz(47, 0, -1, x, y, 128.0f, 128.0f, u * 128, v * 128);
}

int EndressBody(int pl)
{
	static int Ticks;
	static int X;
	static int Y;
	static float zoom = 1.0f;
	static int frame;
	static int zen;
	static int eye = 20;
	static int bgnum;
	static int LCount;
	PZL_STAT *st;
	int ret = 0;
	int light;
	int i;
	int k;
	short ang;

	KeyStat = GetKeyStat();
	KeyHit = GetKeyHit();
	VKeyHit = 0;
	if (pl < 1 || pl > 2)
		pl = 1;
	st = &Stat[pl];
	st->key = KeyStat;
	st->key_rep = KeyHit;
	st->unk444 = 0;
	st->unk448 = 0;
	light = GetBallLine(st) < 8 ? 0 : 2;
	st->mapno = 2;
	st->mapsub = 0;
	PauseControl(st);
	isPause = PauseFlag;
	if (isPause == 0) {
		st->unk47F = 0;
		if (pl == 1) {
			if (CheckGuideLine(st))
				st->unk47F = 1;
		} else
			CPUThinking(st);
		Ticks = (Ticks + 1) % 8;
		st->unk430++;
	}
	DoCharacters(st);
	DoReadyGo(st);
	if (isPause == 0) {
		switch (st->unk006) {
		default:
			PollShutter(0);
			if (PollShutter(5) || st->unk430 < 60)
				break;
			if (st->unk00E > 0)
				st->unk00E--;
			if (st->drop.unk2 == 1) {
				st->drop.unk2 = 2;
				CheckBallGuideVS(st);
			}
			if (st->unk428) {
				for (i = 0; i < 32; i++) {
					if (i < st->guide_n && st->drop.unk2 == 2) {
						if (st->guide_col == 2 && (Ticks / 2) & 1)
							k = 10;
						else {
							k = st->cur;
							k = k == 9 ? 7 : k % 8;
						}
						DrawBubble(0.3f, st->gx[i * 8 + Ticks] + 72, st->gy[i * 8 + Ticks], k, 0);
					}
				}
			}
			if ((st->key_rep & 0x2000) || st->unk00E <= 0) {
				se_play(12);
				ang = st->unk454;
				st->unk00E = 600;
				st->fx = st->bx << 16;
				st->fy = st->by << 16;
				st->unk006 = 2;
				st->unk008 = 0;
				st->vx = -Cos(ang);
				st->vy = -Sin(ang);
			}
			break;
		case 2: {
			int flag, left, right;

			X = st->vx;
			Y = st->vy;
			left = (GetMapLeft(st->mapno) << 16) + 0x80000;
			right = (GetMapRight(st->mapno) << 16) - 0x90000;
			minY = 0x200000 - (st->scroll * 14 << 16);
			maxY = 0x1180000 - (st->scroll * 14 << 16);
			flag = 0;
			for (i = 0; i < 12; i++) {
				st->fx += X;
				st->unk008++;
				st->fy += Y;
				if (st->fx < left) {
					X = X < 0 ? -X : X;
					st->vx = st->vx < 0 ? -st->vx : st->vx;
					st->fx = left;
					se_play(19);
				} else if (st->fx > right) {
					X = -(X < 0 ? -X : X);
					st->vx = -(st->vx < 0 ? -st->vx : st->vx);
					st->fx = right;
					se_play(19);
				}
				st->bx = st->fx >> 16;
				st->by = st->fy >> 16;
				if (CheckBallTouch(st, 1)) {
					if (st->cur == 9) {
						st->bx = -64;
						st->by = -64;
					}
					flag = 1;
					break;
				}
			}
			if (flag) {
				st->unk006 = 15;
				st->snd.unk6 = st->bx;
				st->snd.unk8 = st->by;
				st->snd.unk1 = 0;
				if (st->cur == 9) {
					st->ndrop = 0;
					CheckBallDrop(st);
					st->unk006 = 10;
					st->unk024 = 0;
					st->ndrop = 0;
				}
			}
			break;
		}
		case 3:
			if (st->unk026 <= 0) {
				st->unk026 = st->unk027;
				st->unk025 = 12;
				st->unk006 = 17;
				se_play(22);
				break;
			}
		case 4:
			if (st->unk430 < 60)
				st->unk006 = 0;
			else
				st->unk006 = 19;
			st->drop.unk2 = 1;
			st->by = 208 - st->scroll * 14;
			st->bx = 160;
			st->cur = st->next;
			st->next = GetBallNext(st, 0);
			st->unk026--;
			break;
		case 8:
			st->snd.se = 15;
			CheckBallDrop(st);
			st->unk006 = 9;
			st->unk45B = 0;
			SetCharacters(st, 4, 0);
			SetMonitor(st, 12);
		case 9: {
			int color, x, y;
			float s;

			light = 1;
			k = 16 - st->unk024--;
			if (st->unk024 != 0) {
				color = st->unk024 * 0.0625f * 255.0f;
				color <<= 24;
				color |= 0xFFFFFF;
				s = 1.0f;
				s += k * 0.25f;
				for (i = 0; i < st->ndrop; i++) {
					x = st->drop.d[i].x + MapXBeginPos[st->mapno * 3 + st->mapsub];
					y = st->drop.d[i].y + st->ofs_y + st->scroll * 14;
					DrawSpriteZoom(st->drop.d[i].col + 49, color, 0, x + 72, y, 16.0f, 16.0f, 0, 0, 8.0f, 8.0f, s, s, 0);
					if (st->drop.d[i].col != 9 && st->drop.d[i].col != 14) {
						DrawSpriteZoom(45, color, 1.0f, x + 16, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s * 0.25f, s * 0.25f, 0);
					} else if (st->drop.d[i].col == 9) {
						DrawSpriteZoom(46, color, 1.0f, x + 16, y - 56, 128.0f, 128.0f, 0, 0, 64.0f, 64.0f, s, s, k * 0.3f * 3.14f * 0.0625f);
					} else {
						DrawPat47(x + 16, y - 56, k);
					}
				}
			}
		}
		case 10:
			if (st->unk024 == 0) {
				st->unk006 = 12;
				st->ndrop = 0;
				st->unk024 = 0;
			}
			break;
		case 12:
			if (++st->unk45B >= 8) {
				st->unk45B = 8;
				st->unk006 = 13;
				st->unk024 = 0;
				st->ndrop = 0;
			}
			break;
		case 13:
			if (st->drop.unk1) {
				st->unk006 = 14;
				st->drop.unk1 = 0;
				st->ndrop = 0;
				if (CheckBallRainbow(st) > 0 && st->ndrop) {
					st->unk006 = 8;
					st->unk024 = 16;
					st->bx = -64;
					st->by = -64;
					break;
				}
			}
			st->unk006 = 3;
			st->unk024 = 0;
			st->ndrop = 0;
			break;
		case 15: {
			int bx, by, n;

			GetBallCoordinate(st, st->snd.unk4, &bx, &by);
			bx += MapXBeginPos[st->mapno * 3 + st->mapsub];
			by += st->ofs_y;
			n = st->snd.unk1;
			st->bx = bx * n / 2 + st->snd.unk6 * (2 - n) / 2;
			st->by = by * n / 2 + st->snd.unk8 * (2 - n) / 2;
			if (++st->snd.unk1 >= 2) {
				st->unk006 = 16;
				st->snd.unk1 = 0;
				CheckBallCollision(st);
			}
			break;
		}
		case 16:
			st->bx = -64;
			st->by = -64;
			if (st->cur == 9) {
				st->unk006 = 10;
				st->unk024 = 0;
				st->ndrop = 0;
			} else if (st->ndrop) {
				st->unk006 = 8;
				st->unk024 = 16;
				st->bx = -64;
				st->by = -64;
				DoBubStat(st, 3);
			} else {
				st->unk006 = 3;
			}
			break;
		case 17:
			if (st->scroll == -4) {
				for (i = 164; i >= 0; i--)
					st->mp.map[i + 22] = st->mp.map[i];
				for (i = 0; i < 11; i++)
					st->mp.map[44 + i] = 12;
				st->mp.map[33] = 13;
				for (i = 0; i < 10; i++)
					st->mp.map[55 + i] = ColorTable[rand() % EndressColorRndMax];
				st->scroll = -5;
			} else {
				for (i = 0; i < 10; i++)
					st->mp.map[33 + i] = 12;
				st->mp.map[22] = 13;
				for (i = 0; i < 11; i++)
					st->mp.map[44 + i] = ColorTable[rand() % EndressColorRndMax];
				st->scroll = -4;
			}
			st->unk006 = 4;
			break;
		case 19: {
			int w;

			k = 0;
			w = GetMapWidth(st->mapno);
			for (i = 0; i < w; i++) {
				if (st->mp.map[i + (11 - st->scroll) * w]) {
					k = 1;
					break;
				}
			}
			if (k == 0) {
				st->unk006 = 1;
			} else {
				st->unk006 = 22;
				st->unk025 = 12;
				st->unk42A = 0;
				se_play(9);
				SetCharacters(st, 7, 0);
				SetMonitor(st, 4);
			}
			break;
		}
		case 22:
			if (++st->unk42A >= 36) {
				se_play(29);
				PollShutter(1);
				st->unk006 = 23;
			}
			break;
		case 23:
			st->unk026 = 8;
			if (PollShutter(0)) {
				st->unk006 = 24;
				st->unk025 = 0;
			}
			break;
		case 24:
			PollShutter(0);
			st->unk006 = 25;
			Cont = 0;
			st->unk42A = 0;
			if (SaveDataBuf[5] < st->score) {
				SaveDataBuf[5] = st->score;
				st->unk006 = 26;
			}
			break;
		case 25:
			PollShutter(0);
			st->unk42A = DoContinue(st->unk42A, Cont);
			if (st->unk025 == 0) {
				st->unk025 = 1;
				Cont = 0;
			}
			if (st->key_rep & 0xA0) {
				Cont ^= 1;
				se_play(4);
			}
			if (st->unk42A >= 31 && (st->key_rep & 0x2000)) {
				if (Cont) {
					st->unk006 = 40;
					ret = 0;
					st->unk42A = 0;
					bgm_stop();
					se_play(10);
				} else {
					se_play(0);
					st->unk006 = 0;
					st->unk42A = 0;
					st->unk428 = 0;
					EndressModeInit();
					ret = 0;
					SetCharacters(st, 3, 0);
					SetCharacters(st, 0, 1);
					SetMonitor(st, 0);
				}
			} else {
				ret = 0;
			}
			break;
		case 26:
			PollShutter(0);
			if (++st->unk42A >= 16)
				st->unk42A = 15;
			SpriteDrawC(0, Get2Dim(st->unk42A, 0, 15, 300, 345) + 240, 54, NEW_RECORD_PARTZ);
			SpriteDrawC(0, 240, 152, SAVE_PARTZ);
			if (GetKeyHit() & 0x2000) {
				st->unk006 = 27;
				MsSave();
			}
			if (GetKeyHit() & 0x4000) {
				st->unk006 = 25;
				Cont = 0;
				st->unk42A = 0;
			}
			break;
		case 27:
			PollShutter(0);
			if (MsAccessFlag == 0) {
				st->unk006 = 25;
				Cont = 0;
				st->unk42A = 0;
			}
			break;
		case 40:
			st->unk42A++;
			PollShutter(0);
			if (st->unk42A >= 46 && st->unk42A < 300 && (st->key_rep & 0x2000))
				st->unk42A = 300;
			SpriteDrawC(0, 240, (int)(Get2Dim(st->unk42A, 0, 45, 300, 345) * 0.8f) + 136, &WINLOSE_PARTZ[2]);
			if (st->unk42A > 300)
				SpriteSetFader((345 - st->unk42A) / 45.0f);
			if (st->unk42A >= 346) {
				ret = 4;
				SpriteSetFader(0);
				st->unk006 = 0;
				st->unk42A = 0;
			}
			break;
		}
		if (isPause == 0) {
			int j, n, x, y, c;
			float fl;

			for (j = 0; j < 3; j++) {
				for (i = 0; i < 192; i++) {
					if (st->ent[i].flag) {
						n = st->ent[i].vy++;
						x = st->ent[i].x;
						y = st->ent[i].y;
						x += 80;
						y -= 32;
						if (st->ent[i].col == 12) {
							fl = 64 - n;
							if (fl > 0) {
								fl *= 0.015625f;
								DrawBubble(fl, x, y, 11, 0);
							} else
								st->ent[i].flag = 0;
						} else {
							if (n > 0) {
								y += n * n / 40;
								if (y > 320)
									st->ent[i].flag = 0;
							}
							DrawBubble(0, x, y, st->ent[i].col - 1, 0);
						}
					}
				}
			}
		}
	}
	if (st->unk006 < 29)
		DrawMapData(st, StageNum);
	DoBubCrush();
	i = st->unk454;
	DrawSpriteEx(1, 2.0f, 0, -15.5f, 0, 0, 0, 0, 0, 0, 0, 11.0f, 0, 0, (i - 256) * -3.14f * 0.001953125f, zoom, 0);
	if (st->unk006 != 17)
		DrawBubble(0, st->bx + 72, st->by + st->scroll * 14, st->cur, 0);
	DrawBubble(0, 292, 222, st->next, 0);
	DrawSpriteEz(3.0f, 152.0f, 184.0f, 176.0f, 8.0f, 0, 0, 7);
	{
		int pat;

		if (GetBallLine(st) >= 8) {
			if (zen != 1) {
				frame = 0;
				zen = 1;
			}
		} else if (zen == 1) {
			frame = 0;
			eye = 0;
			zen = 0;
		}
		switch (zen) {
		case 0:
			pat = 0;
			if (--eye < 0) {
				eye = rand() % 20 + 10;
				zen = 2;
			}
			break;
		case 1:
			frame = (frame + 1) % 32;
			pat = frame / 8 + 4;
			break;
		case 2:
			pat = 1;
			if (--eye < 0) {
				eye = rand() % 80 + 20;
				zen = 0;
			}
			break;
		}
		if (st->unk00E > 0 && st->unk00E < 330) {
			pat = 0;
			i = (short)(st->unk00E / 60);
			if ((short)(st->unk00E % 60) < 30) {
				DrawCharcter(2, 190, 188, ChrData_Count, i);
				pat = 2;
			}
		} else if (st->unk47F) {
			frame = (frame + 1) % 20;
			pat = frame / 5 + 8;
		}
		DrawCharcter(2, 160, 204, ChrData_Zen, pat);
	}
	if (pl == 1) {
		DrawSpriteEz(8.0f, 0.0f, 0.0f, 240.0f, 136.0f, 0.0f, 0.0f, 0);
		DrawSpriteEz(8.0f, 0.0f, 136.0f, 240.0f, 136.0f, 0.0f, 136.0f, 0);
		DrawSpriteEz(8.0f, 240.0f, 0.0f, 240.0f, 136.0f, 240.0f, 0.0f, 0);
		DrawSpriteEz(8.0f, 240.0f, 136.0f, 240.0f, 136.0f, 240.0f, 136.0f, 0);
		DrawSpriteEz(1.0f, 0.0f, 0.0f, 480.0f, 32.0f, 0.0f, 0.0f, 0);
		SpriteDrawC(1.0f, 240, 16, &GAMEMODE_PARTZ[1]);
		DrawSpriteEz(9.0f, 0.0f, 0.0f, 240.0f, 272.0f, 0.0f, 0.0f, bgnum + 22);
		DrawSpriteEz(9.0f, 240.0f, 0.0f, 240.0f, 272.0f, 240.0f, 0.0f, bgnum + 22);
		SpriteDrawEz(10, 7.0f, -1, 4.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
		SpriteDrawEz(11, 7.0f, -1, 381.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
		DrawAnk(1, 427, 136, st->score);
		SpriteDrawC(6.0f, 240, 261, &PUZZLE_PARTZ[25]);
		LCount = (LCount + 1) % 50;
		SpriteDrawC(1.0f, 52, 216, &PUZZLE_PARTZ[6]);
		SpriteDrawC(1.0f, 428, 216, &PUZZLE_PARTZ[9]);
		SpriteDrawC(0, 44, 28, &PUZZLE_PARTZ[2 + LCount / 25]);
		SpriteDrawC(0, 436, 28, &PUZZLE_PARTZ[4 + LCount / 25]);
		SpriteDrawC(1.0f, 50, 241, &PUZZLE_PARTZ[LCount / 25]);
		SpriteDrawC(1.0f, 430, 241, &PUZZLE_PARTZ[LCount / 25]);
		SpriteDrawEz(12, 1.0f, -1, 16.0f, 190.0f, 72.0f, 16.0f, 0.0f, ChNamePos[st->player]);
		SpriteDrawC(6.0f, 240, 222, &PUZZLE_PARTZ[12]);
		DrawSpriteEz(7.0f, 104.0f, 32.0f, 136.0f, 224.0f, 0.0f, 0.0f, 5);
		DrawSpriteEz(7.0f, 240.0f, 32.0f, 136.0f, 224.0f, 136.0f, 0.0f, 5);
	}
	DrawLight(38, 79, light, 0);
	DrawLight(65, 52, light, 1);
	DrawLight(442, 79, light, 2);
	DrawLight(415, 52, light, 3);
	DoMonitor(st);
	DoMonitor(&Stat[2]);
	if (isPause)
		SpriteDrawC(0, 240, 136, PAUSE_PARTZ);
	return ret;
}
#else
/* STAND-IN: EndressBody is still asm.  Its statics, in its place and numbered as in the
 * original (Ticks.46, X.47, Y.48, zoom.49, frame.50, zen.51, eye.52, bgnum.53, LCount.54); data ones only keep the numbering (their .data stays asm). */
static void __attribute__((section(".pbskip"), unused)) EndressBody_statics(void)
{
	static int Ticks;
	static int X;
	static int Y;
	static float zoom __attribute__((section(".pbskipd")));
	static int frame;
	static int zen;
	static int eye __attribute__((section(".pbskipd")));
	static int bgnum;
	static int LCount;
}
__asm__("D_0014E910 = Ticks.46\nD_0014E914 = X.47\nD_0014E918 = Y.48\nD_0014E91C = frame.50\nD_0014E920 = zen.51\nD_0014E924 = bgnum.53\nD_0014E928 = LCount.54");
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressBody);
#endif

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SHUTTER_PARTZ);

void MonitorPut(PZL_STAT *st)
{
	static int Count;

	if (st->mapsub < 2) {
		Count = (Count + 3) % 60;
		SpriteDrawC(1.0f, 50, 241, &PUZZLE_PARTZ[13 + Count / 20]);
		SpriteDrawC(1.0f, 430, 241, &PUZZLE_PARTZ[13 + 4 + Count / 15]);
	}
}

/* Needs the case order below (found by search) and the frame counter re-read before
 * `% 2`: only a volatile read reproduces the reload.  STAND-IN: the volatile views. */
extern SPRDATA SHUTTER_PARTZ;
int PollShutter(int req)
{
	static int Count;
	static int Tick;
	static int Stat;
	int ret = 0;
	int i;

	if (req == 5)
		return Count;
	switch (req) {
	case 1:
		Stat = 1;
		Count = 0;
		break;
	case 6:
		Stat = 6;
		Count = 0;
		break;
	case 3:
		Stat = 0;
		Count = 19;
		ret = 1;
		break;
	case 0:
		break;
	case 2:
		Stat = 2;
		Count = 19;
		break;
	case 7:
		Stat = 7;
		Count = 19;
		break;
	case 4:
		Stat = 0;
		Count = 0;
		ret = 2;
		break;
	}
	Tick++;
	switch (Stat) {
	case 1:
		Tick = *(volatile int *)&Tick % 2;
		break;
	case 2:
		Tick = *(volatile int *)&Tick % 2;
		break;
	case 6:
		Tick = *(volatile int *)&Tick % 2;
		break;
	case 7:
		Tick = *(volatile int *)&Tick % 2;
		break;
	default:
		Tick = 1;
		break;
	}
	if (Tick == 0) {
		switch (Stat) {
		case 1:
			Count++;
			if (Count >= 20) {
				Count = 19;
				ret = 1;
				Stat = 0;
				se_play(7);
			}
			break;
		case 2:
			Count--;
			if (Count < 0) {
				Stat = 0;
				ret = 2;
				Count = 0;
				se_play(7);
			}
			break;
		case 6:
			Count++;
			if (Count >= 20) {
				Count = 19;
				ret = 1;
				Stat = 0;
			}
			break;
		case 7:
			Count--;
			if (Count < 0) {
				Stat = 0;
				ret = 2;
				Count = 0;
			}
			break;
		}
	}
	for (i = 0; i < Count; i++)
		SpriteDrawC(1.0f, 240, 28 + i * 12, &SHUTTER_PARTZ);
	return ret;
}

void DrawLight(int x, int y, int col, int no)
{
	/* STAND-IN: numbering only; the real `static int Count[4] = { 0, 8, 4, 12 };`
	 * is .data, which stays asm (D_00038A8C) */
	static int Count[4] __attribute__((section(".pbskipd")));
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
void DoCharacters(PZL_STAT *st);
void DoMonitor(PZL_STAT *st);
void disp_game_bg(void)
{
	static int LCount;
	static int bgnum;
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
	LCount = (LCount + 1) % 50;
	SpriteDrawC(2.0f, 52, 216, &PUZZLE_PARTZ[6]);
	SpriteDrawC(2.0f, 428, 216, &PUZZLE_PARTZ[8]);
	SpriteDrawC(1.0f, 44, 28, &PUZZLE_PARTZ[2 + LCount / 25]);
	SpriteDrawC(1.0f, 436, 28, &PUZZLE_PARTZ[4 + LCount / 25]);
	SpriteDrawC(2.0f, 50, 241, &PUZZLE_PARTZ[LCount / 25]);
	SpriteDrawC(2.0f, 430, 241, &PUZZLE_PARTZ[LCount / 25]);
	SpriteDrawEz(12, 2.0f, -1, 16.0f, 190.0f, 72.0f, 16.0f, 0.0f, ChNamePos[st->player]);
	SpriteDrawEz(10, 7.0f, -1, 4.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
	SpriteDrawEz(11, 7.0f, -1, 381.0f, 165.0f, 96.0f, 48.0f, 0.0f, 0.0f);
	DrawAnk(1, 427, 136, 500);
	SpriteDrawC(6.0f, 240, 261, &PUZZLE_PARTZ[25]);
	DrawSpriteEz(8.0f, 0.0f, 0.0f, 240.0f, 136.0f, 0.0f, 0.0f, 0);
	DrawSpriteEz(8.0f, 0.0f, 136.0f, 240.0f, 136.0f, 0.0f, 136.0f, 0);
	DrawSpriteEz(8.0f, 240.0f, 0.0f, 240.0f, 136.0f, 240.0f, 0.0f, 0);
	DrawSpriteEz(8.0f, 240.0f, 136.0f, 240.0f, 136.0f, 240.0f, 136.0f, 0);
	DrawSpriteEz(9.0f, 0.0f, 0.0f, 240.0f, 272.0f, 0.0f, 0.0f, bgnum + 22);
	DrawSpriteEz(9.0f, 240.0f, 0.0f, 240.0f, 272.0f, 240.0f, 0.0f, bgnum + 22);
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA00);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA04);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA08);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA0C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA10);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA14);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA1C);

/* Labels the asm (also file_sub's and plsel's) uses inside this .bss: the
 * high halves of X.9/X.13, and %lo parts splat paired with the wrong %hi
 * (their real symbols share the low 16 bits: MsAccessFlag, Stat, ...). */
__asm__("D_0014E88A = X.9 + 2\n"
	"D_0014E89A = X.13 + 2\n"
	".globl D_0014F38C\nD_0014F38C = bubx + 0xA30\n"
	".globl D_0014F390\nD_0014F390 = bubx + 0xA34\n"
	".globl D_00150868\nD_00150868 = buby + 0xF0C\n"
	".globl D_001508D4\nD_001508D4 = buby + 0xF78\n"
	".globl D_0015273C\nD_0015273C = bubcol + 0xDE0\n");
