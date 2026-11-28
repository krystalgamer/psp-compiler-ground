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

extern unsigned char save_data;
extern int music_libtbl[];
#define SD_MUSIC (*(int *)(&save_data + 0x4c))
extern int music_sw;
void inv_classic_musicdisp_init()
{
	music_sw = 0;
	inv_classic_sound_free();
	if (SD_MUSIC != 0)
		inv_classic_sound_load(music_libtbl[SD_MUSIC]);
}

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

typedef struct { u8 p[0x4c]; int music; } SD_MUSIC_T;
#define SDM_MUSIC ((*(SD_MUSIC_T *)&save_data).music)
extern int music_sw;
extern int D_0039AEA8;
extern char *musictbl2[];
int hato(int v, int target, int step);
int sound_start(int no);
int sprite_set(int tex, int x, int y, int w, int h, int u, int v, int sw, int sh, int a9, int a10, int r, int g, int b, int a, int pri, int mode, int a17, int alpha);
void ASC_SetStringRGBA(int font, char *str, int x, int y, int r, int g, int b, int a);
void inv_classic_music_disp(void)
{
	if (SDM_MUSIC == 0)
		return;
	if (D_0039AEA8 == 0) {
		sprite_set(classic_tex_28FB7C, 16, 264, 8, 8, 32, 176, 100, 100, 0, 0, 255, 255, 255, 255, 60, 2, 1, music_alpha);
		ASC_SetStringRGBA(1, musictbl2[SDM_MUSIC], 32, 264, 255, 255, 255, music_alpha);
	}
	if (music_sw == 0) {
		music_alpha = hato(music_alpha, 255, 4);
		if (music_alpha < 255)
			return;
		sound_start(0);
		music_sw++;
	} else if (music_sw > 120)
		music_alpha = hato(music_alpha, 0, 4);
	else
		music_sw++;
}

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

extern int nx, ny, nret, ntbl, nnanm, nc, nnanmcnt;
extern unsigned char Name[];
void ASC_SetString(const char *s, int x, int y);
void classic_inv_name_entry_cur(int x, int y);
void classic_inv_name_entry_cur_erase(int x, int y);
void spr_boxfill(unsigned char *buf, int x, int y, int w, int h, int col);
int inv_classic_name_entry(int no, unsigned char *buf)
{
	char tbl[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.";
	int ret;

	ret = 0;
	spr_boxfill(buf, 0x48, 0xD0, 0x80, 0x10, 0);
	ASC_SetString("HI-SCORER REGISTRATION", 0x18, 0x40);
	ASC_SetString("A B C D E F G H I J K", 0x18, 0x68);
	ASC_SetString("L M N O P Q R S T U V", 0x18, 0x78);
	ASC_SetString("W X Y Z . ", 0x18, 0x88);
	if (pad_sw() & 0x100010) {
		classic_inv_name_entry_cur_erase(nx, ny);
		ny -= 16;
		if (ntbl == 28) {
			ntbl = 19;
			nx = 0x98;
		} else if (ntbl == 27) {
			ntbl = 17;
			nx = 0x78;
		} else
			ntbl -= 11;
		if (ny < 0x70) {
			ntbl += 11;
			ny = 0x70;
		}
	} else if (pad_sw() & 0x200040) {
		classic_inv_name_entry_cur_erase(nx, ny);
		ny += 16;
		if (ntbl < 16)
			ntbl += 11;
		else if (ntbl >= 16 && ntbl < 22) {
			ntbl = 22;
			nx = 0x18;
			ny = 0x90;
		} else if (ntbl >= 22)
			ny = 0x90;
		if (ny > 0x90) {
			ntbl -= 11;
			ny = 0x90;
		}
	} else if (pad_sw() & 0x400080) {
		classic_inv_name_entry_cur_erase(nx, ny);
		nx -= 16;
		ntbl -= 1;
		if (ntbl == 26) {
			nx = 0x58;
			ny = 0x90;
		} else if (ntbl == 27) {
			nx = 0x78;
			ny = 0x90;
		}
		if (nx < 0x18) {
			nx = 0x18;
			ntbl += 1;
		}
	} else if (pad_sw() & 0x800020) {
		classic_inv_name_entry_cur_erase(nx, ny);
		ntbl += 1;
		nx += 16;
		if (ntbl >= 29)
			ntbl = 28;
		if (ntbl == 28) {
			nx = 0x90;
			ny = 0x90;
		} else if (ntbl == 27) {
			nx = 0x78;
			ny = 0x90;
		} else if (nx > 0xB8) {
			ntbl -= 1;
			nx = 0xB8;
		}
	} else if (pad_sw() & pad_ret_button()) {
		if (ntbl == 28) {
			__builtin_memcpy(((SD_HISCORE *)&save_data)->name[no], Name, 8);
			classic_inv_name_entry_cur(0x48, 0xE0);
			ret = 1;
		} else if (ntbl == 27) {
			Name[nret] = 0;
			spr_boxfill(buf, nret * 8 + 0x48, 0xC0, 8, 8, 0);
			nret--;
			if (nret < 0)
				nret = 0;
		} else {
			Name[nret] = tbl[ntbl];
			nret++;
			if (nret >= 8) {
				__builtin_memcpy(((SD_HISCORE *)&save_data)->name[no], Name, 8);
				classic_inv_name_entry_cur(0x48, 0xE0);
				ret = 1;
			}
		}
	} else if (pad_sw() & pad_cansel_button()) {
		Name[nret] = 0;
		spr_boxfill(buf, nret * 8 + 0x48, 0xC0, 8, 8, 0);
		nret--;
		if (nret < 0)
			nret = 0;
	}
	if (nret != 0)
		ASC_SetString(Name, 0x48, 0xC0);
	classic_inv_name_entry_cur(nx, ny);
	if ((nnanmcnt & 3) == 0) {
		if (nnanm != 0)
			nnanm = 0;
		else
			nnanm = 1;
	}
	if (nnanm != 0)
		ASC_SetString("NAME '~~~~~~~~'", 0x18, 0xC8);
	else {
		switch (nret) {
		case 0: ASC_SetString("NAME ' ~~~~~~~'", 0x18, 0xC8); break;
		case 1: ASC_SetString("NAME '~ ~~~~~~'", 0x18, 0xC8); break;
		case 2: ASC_SetString("NAME '~~ ~~~~~'", 0x18, 0xC8); break;
		case 3: ASC_SetString("NAME '~~~ ~~~~'", 0x18, 0xC8); break;
		case 4: ASC_SetString("NAME '~~~~ ~~~'", 0x18, 0xC8); break;
		case 5: ASC_SetString("NAME '~~~~~ ~~'", 0x18, 0xC8); break;
		case 6: ASC_SetString("NAME '~~~~~~ ~'", 0x18, 0xC8); break;
		case 7: ASC_SetString("NAME '~~~~~~~ '", 0x18, 0xC8); break;
		}
	}
	nc = 0;
	nnanmcnt++;
	return ret;
}

void ASC_SetString(const char *s, int x, int y);
void classic_inv_name_entry_cur(int x, int y);
void classic_inv_name_entry_cur_erase(int x, int y);
void spr_boxfill(unsigned char *buf, int x, int y, int w, int h, int col);
int inv_classic_name_entry2(int arg0, unsigned char *buf)
{
	ASC_SetString("REGISTRATION OK?", 0x48, 0xD0);
	ASC_SetString("YES / NO", 0x48, 0xD8);
	ASC_SetString("NAME '~~~~~~~~'", 0x18, 0xC8);
	if (pad_sw() & 0x400080) {
		nc = 0;
		classic_inv_name_entry_cur_erase(0x78, 0xE0);
		classic_inv_name_entry_cur(0x48, 0xE0);
	} else if (pad_sw() & 0x800020) {
		nc = 1;
		classic_inv_name_entry_cur_erase(0x48, 0xE0);
		classic_inv_name_entry_cur(0x78, 0xE0);
	} else if (pad_sw() & pad_ret_button()) {
		if (nc == 0)
			return 1;
		classic_inv_name_entry_cur_erase(0x48, 0xE0);
		classic_inv_name_entry_cur_erase(0x78, 0xE0);
		if (nret != 0) {
			Name[nret] = 0;
			spr_boxfill(buf, nret * 8 + 0x48, 0xC0, 8, 8, 0);
			nret--;
		}
		return 2;
	}
	return 0;
}
