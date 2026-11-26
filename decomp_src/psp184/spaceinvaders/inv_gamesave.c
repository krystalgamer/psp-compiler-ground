/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char save_data;


void *memset(void *s, int c, unsigned int n);
int sprintf(char *s, const char *fmt, ...);
void ms_init(void);
#define SDI(o) (*(int *)(&save_data + (o)))
#define SDS(o) ((char *)(&save_data + (o)))
void inv_save_data_init(void)
{
	memset(&save_data, 0, 0x460);
	SDI(0x8) = 100;
	SDI(0xC) = 80;
	SDI(0x10) = 60;
	SDI(0x14) = 40;
	SDI(0x18) = 20;
	SDI(0x70) = 0;
	SDI(0x74) = 3;
	SDI(0x7C) = 1;
	SDI(0x78) = 1;
	sprintf(SDS(0x1C), "SPACE");
	sprintf(SDS(0x25), "INVADERS");
	sprintf(SDS(0x2E), "GALAXY");
	sprintf(SDS(0x37), "BEAT");
	sprintf(SDS(0x40), "CLASSIC");
	SDI(0x80) = 10000;
	SDI(0x84) = 8000;
	SDI(0x88) = 6000;
	SDI(0x8C) = 4000;
	SDI(0x90) = 2000;
	SDI(0xCC) = 1;
	SDI(0xF8) = 1;
	sprintf(SDS(0x94), "SPACE");
	sprintf(SDS(0x9D), "INVADERS");
	sprintf(SDS(0xA6), "Galaxy");
	sprintf(SDS(0xAF), "beat");
	sprintf(SDS(0xB8), "FUTURE");
	SDI(0xD4) = 1;
	SDI(0xD8) = 2;
	SDI(0xE0) = 10;
	SDI(0xE4) = 32;
	SDI(0) = 0;
	ms_init();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_save_data_sum_check(void) {
    int var_a1;
    int var_v1;
    unsigned char *var_a0;
    unsigned char temp_v0;

    var_a0 = &save_data;
    var_a1 = 0;
    var_v1 = 0x45F;
    do {
        temp_v0 = *var_a0;
        var_v1 -= 1;
        var_a0 += 1;
        var_a1 += temp_v0;
    } while (var_v1 >= 0);
    return var_a1;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E8E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E8F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E900);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E90C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E918);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E924);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E930);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E93C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E948);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E94C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E95C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E96C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E980);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E994);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_gamesave", D_0007E9A8);
