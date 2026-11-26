/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int D_0035AE84;


typedef struct { u8 pad[0xC]; int nearest; u8 rest[0xD0 - 0x10]; } SPRITE_W;
typedef struct { u8 pad[0x14]; int nearest; u8 rest[0x168 - 0x18]; } BILL_W;
extern SPRITE_W sprite[];
extern BILL_W billbord[];

typedef struct { int used; int f4; int f8; int type; int f10; int f14; void *p18; void *p1c; int f20; int f24; } TEX_FILE;
extern TEX_FILE tex_file[64];
extern int tex_file_max;
void *LoadFile(char *name, int *size);
void psp_free(void *p);
int bmp_addr_load(void *buf);
int bmp_addr_load_normal(void *buf);
int bmp_addr_load_alpha(void *buf);
int bmp_addr_load16(void *buf);
int bmp_addr_load16_normal(void *buf);
int bmp_addr_load16_alpha(void *buf);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", tex_init);

extern TEX_FILE tex_file[64];
extern int tex_file_max;
void *LoadFile(char *name, int *size);
void psp_free(void *p);
int bmp_addr_load(void *buf);
int bmp_addr_load_normal(void *buf);
int bmp_addr_load_alpha(void *buf);
int bmp_addr_load16(void *buf);
int bmp_addr_load16_normal(void *buf);
int bmp_addr_load16_alpha(void *buf);
int bmp_file_load(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load(buf);
	psp_free(buf);
	return ret;
}

int bmp_file_load_normal(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load_normal(buf);
	psp_free(buf);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", color_check);

int bmp_file_load_alpha(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load_alpha(buf);
	psp_free(buf);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load_alpha);

int bmp_file_load16(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load16(buf);
	psp_free(buf);
	return ret;
}

int bmp_file_load16_normal(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load16_normal(buf);
	psp_free(buf);
	return ret;
}

int bmp_file_load16_alpha(char *name)
{
	int size;
	void *buf;
	int ret;

	buf = LoadFile(name, &size);
	if (buf == 0)
		return -1;
	ret = bmp_addr_load16_alpha(buf);
	psp_free(buf);
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16_normal);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", bmp_addr_load16_alpha);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_tex", tex_make);

int bmp_file_unload(int no)
{
	TEX_FILE *t = &tex_file[no];

	if ((unsigned int)no >= 64)
		return 0;
	if (t->used == 0)
		return 0;
	if ((unsigned int)t->type < 2)
		psp_free(t->p18);
	else
		psp_free(t->p1c);
	t->used = 0;
	t->p1c = 0;
	t->p18 = 0;
	tex_file_max--;
	return 1;
}

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
