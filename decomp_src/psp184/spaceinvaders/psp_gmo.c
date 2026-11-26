/* cflags: -O2 -fno-merge-constants */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char gmo;
extern unsigned char gmo_file;
extern int gmo_file_max;
extern int gmo_max;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

int gmo_file_unload(int no);
int gmo_unload(int no);

void gmo_init(void) {
    memset(&gmo_file, 0, 0x190U);
    memset(&gmo, 0, 0x6798U);
    gmo_file_max = 0;
    gmo_max = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_file_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_addr_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_file_unload);

int gmo_file_unload(int no);
int gmo_unload(int no);
void gmo_file_all_unload(void)
{
	int i;

	for (i = 0; i < 50; i++)
		gmo_file_unload(i);
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", D_0007A8A4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_load);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_unload);

void gmo_all_unload(void)
{
	int i;

	for (i = 0; i < 255; i++)
		gmo_unload(i);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_anime_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_anime_direct);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_anime_stop);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_effect);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_disp);
