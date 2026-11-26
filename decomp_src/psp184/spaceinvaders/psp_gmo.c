/* cflags: -O2 */
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

typedef struct { int used; void *model; } GMO_FILE;
typedef struct {
	int used, f4, f8, fc;
	u8 _p10[0x44 - 0x10];
	int anime, motion, f4c;
	float speed;
	void *model;
	int effect[4];
} GMO_W;
#define GMO ((GMO_W *)&gmo)
#define GMO_FILE_W ((GMO_FILE *)&gmo_file)
int sceGmoModelDelete(void *model);
int sceGmoModelSetCurrentMotion(void *model, int motion, float speed);
int gmo_unload(int no)
{
	GMO_W *g;
	int ret = 0;

	if ((unsigned int)no < 255) {
		g = &GMO[no];
		if (g->used != 0) {
			sceGmoModelDelete(g->model);
			ret = 1;
			g->used = 0;
			g->model = 0;
			gmo_max--;
		}
	}
	return ret;
}

void gmo_all_unload(void)
{
	int i;

	for (i = 0; i < 255; i++)
		gmo_unload(i);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_anime_start);

int gmo_anime_direct(int no, int motion, float speed)
{
	GMO_W *g;
	int ret = 0;

	if ((unsigned int)no < 255) {
		g = &GMO[no];
		if (g->used != 0) {
			g->anime = 2;
			g->motion = motion;
			g->speed = speed;
			sceGmoModelSetCurrentMotion(g->model, motion, 0);
			ret = 1;
		}
	}
	return ret;
}

int gmo_anime_stop(int no)
{
	GMO_W *g;
	int ret = 0;

	if ((unsigned int)no < 255) {
		g = &GMO[no];
		if (g->used != 0) {
			g->speed = 0;
			g->motion = -1;
			g->anime = 0;
			sceGmoModelSetCurrentMotion(g->model, -1, g->speed);
			ret = 1;
		}
	}
	return ret;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_effect);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_gmo", gmo_disp);
