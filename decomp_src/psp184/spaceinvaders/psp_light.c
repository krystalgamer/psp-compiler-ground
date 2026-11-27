/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_003538BC;


INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", D_0007A844);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", D_0007A854);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", D_0007A860);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_cnt);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", light_debug_disp);

int light_timer_start(int t)
{
	int i;
	u8 *p = (u8 *)&D_003538BC;

	for (i = 0; i < 4; i++) {
		if (*(signed char *)p == 0) {
			*(int *)(p + 0x38) = t;
			*(signed char *)p = 1;
			*(int *)(p + 0x30) = 1;
			*(int *)(p + 0x34) = 0;
			return i;
		}
		p += 0x80;
	}
	return -1;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void light_timer_start_no(int arg0, int arg1) {
    void *temp_a0;

    temp_a0 = (arg0 << 7) + &D_003538BC;
    M2C_FIELD(temp_a0, int *, 0x38) = arg1;
    M2C_FIELD(temp_a0, signed char *, 0) = 1;
    M2C_FIELD(temp_a0, int *, 0x30) = 1;
    M2C_FIELD(temp_a0, int *, 0x34) = 0;
}

typedef struct { signed char on; unsigned char pad[0x23]; unsigned int col[3]; int active; int cnt; int time; unsigned int base[3]; unsigned char rest[0x80 - 0x48]; } LSUB;
void light_timer_ctl(int no)
{
	LSUB *l = &((LSUB *)&D_003538BC)[no];
	int i, n, t;
	unsigned int c;

	if (l->active != 0) {
		if (l->cnt == 0) {
			l->base[0] = l->col[0];
			l->base[1] = l->col[1];
			l->base[2] = l->col[2];
		}
		t = l->time;
		n = t - l->cnt;
		for (i = 0; i < 3; i++) {
			c = l->base[i];
			l->col[i] = ((int)(n * (c >> 24)) / t << 24) | (((int)(n * ((c >> 16) & 0xFF)) / t & 0xFF) << 16) | (((int)(n * ((c >> 8) & 0xFF)) / t & 0xFF) << 8) | ((int)(n * (c & 0xFF)) / t & 0xFF);
		}
		l->cnt++;
		if (l->cnt >= t) {
			l->active = 0;
			l->on = 0;
		}
	}
}
