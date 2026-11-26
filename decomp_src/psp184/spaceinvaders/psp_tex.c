#include "common.h"
#include "m2c_macros.h"
extern int D_0035AE84;


typedef struct { u8 pad[0xC]; int nearest; u8 rest[0xD0 - 0x10]; } SPRITE_W;
typedef struct { u8 pad[0x14]; int nearest; u8 rest[0x168 - 0x18]; } BILL_W;
extern SPRITE_W sprite[];
extern BILL_W billbord[];
int bmp_file_unload(int no);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", tex_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_load_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", color_check);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_load_alpha);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load_alpha);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_load16);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_load16_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_load16_alpha);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16_alpha);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", tex_make);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_unload);

void bmp_file_all_unload(void)
{
	int i;

	for (i = 0; i < 64; i++)
		bmp_file_unload(i);
}

int bmp_file_copy_addrset(int no, int addr);
int bmp_file_copy(int no)
{
	return bmp_file_copy_addrset(no, 0);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_file_copy_addrset);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", screen_capture);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_center_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_gt4_set);

void sprite_nearest(unsigned int no)
{
	if (no < 345)
		sprite[no].nearest = 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", poly_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", poly_g4_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set_3d);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set_3d_efc);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_set_3d_efc_rot);

void sprite_3d_nearest(unsigned int no)
{
	if (no < 512)
		billbord[no].nearest = 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_bg_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_scr_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_3d_disp);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", set_texture);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", set_packet_scr);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", set_packet_3d);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_screencopy_disp);

#ifndef NULL
#define NULL ((void *)0)
#endif

void sprite_screencopy_pri_set(int arg0) {
    D_0035AE84 = arg0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sprite_screencopy_pri_get(void) {
    return D_0035AE84;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", sprite_syncsort);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", D_0007A91C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", D_0007A94C);
