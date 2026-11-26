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

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", mode_int);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F3B8);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", r_num_u);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", r_num_v);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", r_keta);

INCLUDE_RODATA("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", D_0002F428);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", disp_title_bg);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", PlayerSelect);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", ModeSelInt);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", ModeSelect);

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

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", RoundSelect);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", write_op_num);

int OptionInit(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/plsel", OptionMode);

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
