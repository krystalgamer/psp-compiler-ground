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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSInit);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressModeInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressInit);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawAnk);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetMapLeft);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetMapRight);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GameValueInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSValueInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvValueInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressValueInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DrawMapData);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBallMapReverse);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBallMap);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetPlayStatus);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", dsGMInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetBallNext);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallTouch);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallCollision);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CvtBallPos2MapPos);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CvtBallPos2MapPosLocal);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetBallMapAddr);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetBallCoordinate);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckOneColorAll);

#ifdef NON_MATCHING
/* Close: i and the loop bound test swap registers. */
int CheckRoundClear(PZL_STAT *st)
{
	int i;
	int ret = 0;
	int found = 0;

	for (i = 0; i < 0x22E; i++) {
		if ((st->map[i] >= 1 && st->map[i] <= 9) || st->map[i] == 13) {
			found = 1;
			break;
		}
	}
	if (!found)
		ret = 1;
	return ret;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckRoundClear);
#endif

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

#ifdef NON_MATCHING
/* Close: the original keeps the branch; here it is if-converted to a mask. */
void SetBubStat(PZL_STAT *st)
{
	int line = GetBallLine(st);
	int stat = (line >= 9) + 1;

	if (line < 7)
		stat = 0;
	st->bubline = stat;
}
#else
INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBubStat);
#endif


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
