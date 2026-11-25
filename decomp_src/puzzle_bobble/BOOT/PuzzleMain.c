#include "common.h"
#include "m2c_macros.h"

extern int ssTimes;
M2C_UNK DrawSpriteEz(int, float, float, float, float, float, float, float); /* extern */
M2C_UNK PzlDataGetWidth();                          /* extern */
int GetKeyHit();                                    /* extern */
int PollShutter(M2C_UNK);                           /* extern */
extern int PauseFlag;
extern unsigned char PauseOk;


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SysTimeIncrement);

int GetSysTime(void) {
    return ssTimes;
}

void ClearSysTime(void) {
    ssTimes = 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetCharacters);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoCharacters);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetMonitor);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", InitBubCrush);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBubCrush);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBubCrushEz);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PuzzleMain);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSModeInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvivlaModeInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SurvivalInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", VSMain);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressModeInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressInit);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", EndressMain);

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

void GetMapWidth(void) {
    PzlDataGetWidth();
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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", TermChain);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckOneColorAll);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckRoundClear);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallGuide);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckBallGuideVS);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", CheckGuideLine);

void DriveBub(void) {
}

void DriveReadyGo(void) {
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", GetBallLine);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PutNumeric);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", PutTime);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", Get2Dim);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", DoBubStat);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/PuzzleMain", SetBubStat);

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
