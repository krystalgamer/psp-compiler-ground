/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK sound_relece();                             /* extern */
M2C_UNK sound_stop();                               /* extern */
extern int soundflg;
extern int option_return;
extern int ret;
extern int se_tmp;


extern unsigned char save_data;
extern int music_libtbl[];
#define SD_MUSIC (*(int *)(&save_data + 0x4c))
void sound_load(int no);

void inv_classic_musicdisp_init();

extern int kido, classic_tex_28FB7C, sw, music_alpha;
void inv_classic_sound_load()
{
	if (soundflg == 0) {
		sound_load(music_libtbl[SD_MUSIC]);
		soundflg = 1;
	}
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_classic_sound_free(void) {
    if (soundflg != 0) {
        sound_stop();
        sound_relece();
        soundflg = 0;
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_classic_soundflg_init(void) {
    soundflg = 0;
}

void inv_classic_sound_init(void)
{
	if (SD_MUSIC != 0)
		inv_classic_sound_load(music_libtbl[SD_MUSIC]);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_musicdisp_init);

void inv_classic_menu_init(int a0)
{
	kido = 0x80;
	classic_tex_28FB7C = a0;
	ret = 0;
	sw = 0;
	music_alpha = 0;
	inv_classic_musicdisp_init();
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_menu);

int sceUtilityGetSystemParamInt(int id, int *value);
int inv_classic_hiscoreinit(void)
{
	int v;

	sceUtilityGetSystemParamInt(4, &v);
	return 0;
}

typedef struct { u8 pad[8]; int score[5]; char name[5][9]; } SD_HISCORE;
typedef struct { int f0; char name[5][10]; int score[5]; } HISCORE_DISP;
int pad_sw(void);
int pad_ret_button(void);
int pad_cansel_button(void);
void se_start(int no);
char *strcpy(char *, const char *);
void inv_hiscore_disp(HISCORE_DISP *d);
int inv_classic_hiscore(void)
{
	HISCORE_DISP d;
	SD_HISCORE *s;

	if (pad_sw() & (pad_ret_button() | pad_cansel_button())) {
		se_start(1);
		return 1;
	}
	s = (SD_HISCORE *)&save_data;
	d.f0 = 0;
	d.score[0] = s->score[0];
	d.score[1] = s->score[1];
	d.score[2] = s->score[2];
	d.score[3] = s->score[3];
	d.score[4] = s->score[4];
	strcpy(d.name[0], s->name[0]);
	strcpy(d.name[1], s->name[1]);
	strcpy(d.name[2], s->name[2]);
	strcpy(d.name[3], s->name[3]);
	strcpy(d.name[4], s->name[4]);
	inv_hiscore_disp(&d);
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_classic_optioninit(int arg0) {
    option_return = arg0;
    ret = 0;
    se_tmp = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007C9F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA00);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA0C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_option_sub);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_option_pause);

int inv_classic_option_pause();
int inv_classic_option_sub();
int inv_classic_option(void)
{
	int r;

	if (option_return == 14)
		r = inv_classic_option_sub();
	else if (option_return == 16)
		r = inv_classic_option_pause();
	return r;
}

void inv_classic_menu_free(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_music_disp);

extern int nx, ny, nret, ntbl, nnanm, nc, nnanmcnt;
extern unsigned char Name[];
void inv_classic_name_entry_init(void)
{
	nx = 0x18;
	ny = 0x70;
	nret = 0;
	ntbl = 0;
	nnanm = 0;
	nc = 0;
	nnanmcnt = 0;
	Name[0] = 0;
	Name[1] = 0;
	Name[2] = 0;
	Name[3] = 0;
	Name[4] = 0;
	Name[5] = 0;
	Name[6] = 0;
	Name[7] = 0;
	Name[8] = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA20);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA30);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA38);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA48);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA50);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA5C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA70);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA74);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA7C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA88);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CA90);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CAAC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CAC8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CADC);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_name_entry);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB78);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB88);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CB98);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBA8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBB8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBC8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBD8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", D_0007CBF8);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_name_entry2);
