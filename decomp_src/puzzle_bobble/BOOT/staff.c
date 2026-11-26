#include "common.h"
#include "game.h"

typedef struct {
	int timer;
	int pad[3];
} STAFF_LIST;

extern const STAFF_LIST StaffList[];
extern int StaffObject[4];
extern int StaffCounter;
extern int StaffGim;
extern int StaffTimer;
extern float MsgMag;
/* 32.0f in .rodata.cst4; staff_roll's constants follow it (staff_roll is still asm) */
extern const float D_0002FFE0;

int printf(const char *, ...);
void bgm_play(int no);
int PollShutter(int);
int get_next_name(void);

int get_next_name(void)
{
	int i;

	for (i = 0; i < 4; i++)
		StaffObject[i] = -1;
	i = 0;
	do {
		StaffTimer = StaffList[StaffCounter].timer;
		if (StaffTimer < 0)
			return -1;
		StaffObject[i++] = StaffCounter++;
	} while (StaffTimer == 0);
	return 0;
}

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", StaffData);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", StaffList);

int staff_init(void)
{
	bgm_play(6);
	StaffCounter = 0;
	StaffGim = 0;
	do {
		if (get_gims(StaffGim) == 0)
			break;
		StaffGim++;
	} while (StaffGim < 128);
	if (StaffGim >= 127)
		StaffGim = 126;
	printf("STAFF GIM=%d\n", StaffGim);
	PollShutter(3);
	get_next_name();
	LoadGimFile(StaffGim, 700);
	LoadGimFile(StaffGim + 1, 0x70);
	MsgMag = D_0002FFE0;
	return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", staff_roll);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", D_0002FFE0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", D_0002FFE4);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", D_0002FFE8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", D_0002FFEC);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", D_0002FFF0);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", D_0002FFF8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", D_0002FFFC);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/staff", __psp_libinfo___30000);
