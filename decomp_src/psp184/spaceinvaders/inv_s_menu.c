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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_hiscore);

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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_option);

void inv_classic_menu_free(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_music_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_menu", inv_classic_name_entry_init);

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
