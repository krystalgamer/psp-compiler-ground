/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char inv_particle;
extern int inv_particle_max;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);



void inv_particle_all_init(void) {
    memset(&inv_particle, 0, 0xFDC00U);
    inv_particle_max = 0;
}

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEE8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEEC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEF0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", D_0007CEF4);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", inv_particle_start);

int inv_particle_check(unsigned int no)
{
	if (no >= 256)
		return 1;
	return *(int *)((u8 *)&inv_particle + no * 0xFDC) != 1;
}

typedef struct {
	int f0[7];
	int cnt, end;
	float x, y, z, vx, vy, vz;
	float rx, ry, rz, vrx, vry, vrz;
	int f54[6];
} PTC1;
typedef struct { PTC1 p[16]; u8 pad[0xFDC - 16 * 0x6C]; } PTC;

typedef struct { int used, f4, pri; u8 pad[0xFDC - 12]; } PS;
extern int par_co[], par_pri_co[];
void inv_particle_control(void)
{
	PTC *g;
	PTC1 *p;
	int i, j, n;

	for (i = 0; i < 0x100; i++) {
		g = &((PTC *)&inv_particle)[i];
		n = 0;
		if (g->p[0].f0[0] != 1)
			continue;
		p = g->p;
		for (j = 0; j < 16; j++, p++) {
			if (++p->cnt >= p->end) {
				n++;
			} else {
				p->x += p->vx;
				p->y += p->vy;
				p->z += p->vz;
				p->rx += p->vrx;
				p->ry += p->vry;
				p->rz += p->vrz;
			}
		}
		if (n >= 16) {
			g->p[0].f0[0] = 0;
			inv_particle_max--;
			if (inv_particle_max < 0)
				inv_particle_max = 0;
		}
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_particle", inv_particle_disp);

void inv_particle_syncsort(void)
{
	int i, j, k, n, key, no, m;

	n = 0;
	if (inv_particle_max <= 0)
		return;
	for (i = 0; i < 256; i++) {
		if (n >= inv_particle_max)
			break;
		if (((PS *)&inv_particle)[i].used == 1) {
			par_co[n] = i;
			par_pri_co[n] = ((PS *)&inv_particle)[i].pri;
			n++;
		}
	}
	if (n <= 0)
		return;
	for (k = 1; k < n; k++) {
		no = par_co[k];
		key = par_pri_co[k];
		for (j = k - 1; j >= 0 && par_pri_co[j] >= key; j--) {
			par_co[j + 1] = par_co[j];
			par_pri_co[j + 1] = par_pri_co[j];
		}
		par_co[j + 1] = no;
		par_pri_co[j + 1] = key;
	}
}
