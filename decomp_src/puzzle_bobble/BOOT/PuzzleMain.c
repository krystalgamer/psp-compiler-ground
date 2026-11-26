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
void se_play(int no);
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

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002E454);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoMonitor);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSModeInit);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvivlaModeInit);

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


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GameValueInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSValueInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvValueInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressValueInit);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetPlayStatus);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckGuideLine);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetOjamaPat);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", disp_game_bg);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA00);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA04);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA08);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA0C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA10);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA14);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA1C);
