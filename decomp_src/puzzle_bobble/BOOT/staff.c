#include "common.h"
#include "game.h"

typedef struct {
	int timer;
	int pad;
	int y;
	int data;
} STAFF_LIST;

extern const STAFF_LIST StaffList[];
extern int StaffObject[4];
extern int StaffCounter;
extern int StaffGim;
extern int StaffTimer;
extern float MsgMag;
extern int D_00559074;
extern int MsAccessFlag;

typedef struct {
	int u, v, w, h;
} STAFF_DATA;

extern const STAFF_DATA StaffData[];
void SpriteInit(void);
void SpriteKick(void);
void SpriteSetFader(float);
void disp_game_bg(void);
void bgm_stop(void);
int puts(const char *);

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
	MsgMag = 32.0f;
	return 0;
}

int staff_roll(void)
{
	int ret = 0;
	int mode;
	int i;
	int idx;
	int x;
	const STAFF_LIST *l;
	const STAFF_DATA *d;

	SpriteInit();
	if (D_00559074 > 0) {
		D_00559074--;
		SpriteSetFader(D_00559074 / 60.0f);
		PollShutter(0);
		if (D_00559074 == 0)
			ret = 4;
	} else {
		mode = PollShutter(0);
		if (MsAccessFlag == 0 && StaffTimer > 300) {
			if (MsgMag > 0)
				MsgMag = MsgMag - 0.5;
			DrawSpriteEx(StaffGim + 1, 0, 0, 0, 352, 88, 0, 0, 352, 88, 0, 0, 0, 0, 0, MsgMag, 0);
		}
		if (StaffTimer == 300)
			PollShutter(7);
		for (i = 0; i < 4; i++) {
			idx = StaffObject[i];
			if (idx >= 0) {
				l = &StaffList[idx];
				d = &StaffData[l->data];
				x = 240 - (d->w >> 1);
				DrawSpriteEz(2.0f, StaffGim, x, l->y, d->w, d->h, d->u, d->v);
			}
		}
		if (MsAccessFlag == 0) {
			if (StaffTimer < 0) {
				if (mode == 1) {
					if (get_next_name() < 0) {
						bgm_stop();
						D_00559074 = 60;
					} else {
						PollShutter(7);
					}
				}
			} else if (mode == 1) {
				puts("Shutter Open!");
				PollShutter(7);
			} else if (mode == 2 || mode == 0) {
				if (--StaffTimer < 0) {
					PollShutter(6);
					puts("Shutter Close");
				}
			}
		}
	}
	disp_game_bg();
	SpriteKick();
	return ret;
}
