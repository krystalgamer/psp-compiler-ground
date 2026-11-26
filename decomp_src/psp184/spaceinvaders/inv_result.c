/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int D_004B47E0;
extern int D_004B47C8;
extern int D_004B47CC;


#ifndef NULL
#define NULL ((void *)0)
#endif

extern int inv_movie_resut;
void psp_free(void *p);

extern int inv_movie_resut;
void psp_free(void *p);

void psp_free(void *p);

void *psp_malloc(int size);
void *memset(void *, int, unsigned int);

void inv_movie_result_tex_addr(int arg0) {
    D_004B47E0 = arg0;
}

extern int inv_movie_resut;
void psp_free(void *p);
void inv_movie_result_reset(void)
{
	u8 *p = (u8 *)&inv_movie_resut;


	*(int *)(p + 0xC) = 0;
	*(int *)(p + 0x10) = 0;
	*(int *)p = 480;
	*(int *)(p + 4) = -1;
	
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_movie_result_disp_counter_set(int arg0) {
    D_004B47C8 = arg0;
}

void inv_movie_result_memset(void)
{
	u8 *r = (u8 *)&inv_movie_resut;

	*(void **)(r + 0x14) = psp_malloc(0x3800);
	*(void **)(r + 0x18) = psp_malloc(0x3800);
	if (*(void **)(r + 0x14))
		memset(*(void **)(r + 0x14), 0, 0x3800);
	if (*(void **)(r + 0x18))
		memset(*(void **)(r + 0x18), 0, 0x3800);
}

void *inv_movie_result_addr(void)
{
	u8 *p = (u8 *)&inv_movie_resut;

	*(int *)(p + 0x10) ^= 1;
	return ((void **)(p + 0x14))[*(int *)(p + 0x10)];
}

void psp_free(void *p);
void inv_movie_result_free(void)
{
	u8 *r = (u8 *)&inv_movie_resut;

	psp_free(*(void **)(r + 0x18));
	psp_free(*(void **)(r + 0x14));
	*(int *)(r + 0x18) = 0;
	*(int *)(r + 0x14) = 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_movie_result_flag(int arg0) {
    D_004B47CC = arg0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", inv_movie_result_txt_set);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", inv_movie_result_disp);

void *psp_malloc(int size);
void *memset(void *, int, unsigned int);
int inv_result_font_code(int c)
{
	if ((unsigned int)(c - 'A') < 26)
		return c - 'A';
	if ((unsigned int)(c - '0') < 10)
		return c - '0' + 26;
	if (c == ':')
		return 36;
	if (c == '-')
		return 37;
	if (c == '/')
		return 38;
	if (c == '%')
		return 39;
	return 40;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", maingame_loop);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF00);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF10);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF30);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF3C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF48);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF50);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF68);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF74);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF80);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF8C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CF94);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFA0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFAC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFB8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFC4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFCC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFD8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFE0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007CFF8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D004);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D010);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D028);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D038);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D04C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D060);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D068);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D074);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D078);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D084);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D094);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0D4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D0F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D100);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D10C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D114);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D11C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D12C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D138);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D144);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D14C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D154);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D160);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D164);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D16C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D178);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D184);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D190);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D1FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D208);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D214);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D220);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D22C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D238);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D24C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D250);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D264);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D270);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D280);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D288);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D290);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D298);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D2A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D2B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D2C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D2DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D2EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D2F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D300);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D308);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D310);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D31C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D324);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D330);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D338);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D340);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D348);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D350);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D358);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D360);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D368);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D378);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D384);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D390);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D39C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3C8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D3E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D404);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D420);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D430);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D444);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D450);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D460);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D47C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D488);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D49C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D4B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D4D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D4EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D4F8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D50C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D518);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D520);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D528);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D530);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D538);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D540);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D548);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D550);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D558);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D560);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D568);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D570);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D57C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D588);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D594);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D5A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D5B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D5C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D5D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D5E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D5F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D600);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D610);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D620);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D630);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D640);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D650);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D660);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D670);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D680);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D690);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D69C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D6A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D6B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D6C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D6D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D6D8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D6E4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D6F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D700);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D710);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D720);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D730);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D740);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D750);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D760);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D770);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D780);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D790);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D7A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D7B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D7C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D7D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D7DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D7E8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D7F4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D804);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D810);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D81C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D824);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D830);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D83C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D84C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D858);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D868);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D87C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D888);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D894);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D8A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D8B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D8C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D8D0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D8E0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D8F0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D900);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D910);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D920);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D930);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D93C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D948);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D954);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D960);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D96C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D978);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D984);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D990);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D99C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D9A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D9B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D9C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D9CC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D9DC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D9EC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007D9FC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA0C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA18);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA38);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA48);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA64);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA70);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA7C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA88);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DA94);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAA0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAAC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAB8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DABC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAC8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAD4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAE0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DAF8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB04);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB10);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB1C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB28);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB34);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB40);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB4C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB58);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB64);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_result", D_0007DB70);
