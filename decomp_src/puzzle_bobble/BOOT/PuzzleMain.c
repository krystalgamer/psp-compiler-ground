/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
#include "PuzzleMain.h"

extern int ssTimes;
M2C_UNK DrawSpriteEz(int, float, float, float, float, float, float, float); /* extern */
int PzlDataGetWidth(int no);
int GetKeyHit();                                    /* extern */
int PollShutter(M2C_UNK);                           /* extern */
extern int PauseFlag;
extern unsigned char PauseOk;
extern int StageNum;
extern int gim_bg_endress;
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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoReadyGo);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoContinue);

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

void DrawCharcter(int arg0, int arg1, int arg2, int arg3, int arg4) {
    void *temp_v0;

    temp_v0 = (arg4 * 0x14) + arg3;
    DrawSpriteEz(M2C_FIELD(temp_v0, int *, 0x10), (float) arg0, (float) arg1, (float) arg2, (float) M2C_FIELD(temp_v0, int *, 8), (float) M2C_FIELD(temp_v0, int *, 0xC), (float) M2C_FIELD(temp_v0, int *, 0), (float) M2C_FIELD(temp_v0, int *, 4));
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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawScore);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawCount);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", Sin);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", Cos);

void ZeroMemory(int arg0, int arg1) {
    int var_a2;
    signed char *temp_v1;

    var_a2 = 0;
    if (arg1 > 0) {
        do {
            temp_v1 = arg0 + var_a2;
            var_a2 += 1;
            *temp_v1 = 0;
        } while (var_a2 < arg1);
    }
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
	u8 *sm = src->map;
	u8 *dm = dst->map;

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", dsGMInit);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallAroundRainbowTerm);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallRainbow);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckNext);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallDrop);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckChain);


void TermChain(PZL_STAT *st)
{
	int i;

	for (i = 0; i < MAP_SIZE; i++) {
		if (st->map[i] == 0x68)
			st->map[i] = 0;
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
			if (st->map[i] == col || st->attr[i] == 2) {
				n++;
				GetBallCoordinate(st, i, &x, &y);
				d = &st->drop.d[st->ndrop];
				d->x = x;
				d->flag = 0;
				d->y = y;
				d->col = col;
				st->map[i] = 0;
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
		if ((st->map[i] >= 1 && st->map[i] <= 9) || st->map[i] == 13) {
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
			if (st->map[i + line * w] >= 1 && st->map[i + line * w] <= 11)
				return line + st->scroll;
		}
	}
	return st->scroll;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PutNumeric);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PutTime);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", MonitorPut);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PollShutter);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawLight);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", disp_game_bg);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA00);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA04);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA08);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA0C);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA10);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA14);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA18);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", D_0002EA1C);
