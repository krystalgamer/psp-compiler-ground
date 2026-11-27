/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char D_003538BC;


typedef struct { unsigned int c[4]; } COL4_T;
typedef struct { float x, y, z; } LV3_T;
const COL4_T D_0007A844 = { { 0xFF00FFFF, 0xFF0000FF, 0xFF00FF00, 0xFFFFFF00 } };

const LV3_T D_0007A854 = { -5.0f, 10.0f, 5.0f };

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_light", D_0007A860);

typedef struct {
	signed char on; unsigned char f1; unsigned char type; unsigned char f3;
	LV3_T pos;
	unsigned char pad10[0x24 - 0x10];
	unsigned int col[3];
	int active, cnt, time;
	unsigned int base[3];
	unsigned int c48; int f4C; int f50; float f54; float f58; float f5C; int f60;
	unsigned int c64; int f68; int f6C; float f70; float f74; float f78; int f7C;
} LSUB2;
typedef struct { unsigned char on, f1; unsigned char pad[2]; unsigned int ambient; float f8; LSUB2 sub[4]; } LIGHT_T;
extern LIGHT_T light;
void *memset(void *s, int c, unsigned int n);
void light_init(void)
{
	COL4_T col = D_0007A844;
	LV3_T pos;
	LSUB2 *s;
	int i;

	memset(&light, 0, sizeof(light));
	light.on = 1;
	light.f1 = 0;
	light.ambient = 0xFF222222;
	light.f8 = 60.0f;
	light.sub[0].on = 1;
	light.sub[0].f1 = 0;
	light.sub[0].type = 6;
	pos = D_0007A854;
	light.sub[0].pos = pos;
	light.sub[0].col[0] = 0xFF000000;
	light.sub[0].col[1] = 0xFFFFFF;
	light.sub[0].col[2] = 0xFFFFFF;
	for (i = 0; i < 4; i++) {
		s = &light.sub[i];
		s->c48 = col.c[i];
		s->f4C = 0;
		s->f50 = 0;
		s->f54 = 1.0f;
		s->c64 = col.c[i];
		s->f68 = 0;
		s->f6C = 0;
		s->f70 = 1.0f;
		s->f58 = -0.5f;
		s->f5C = -0.5f;
		s->f60 = 0;
		s->f74 = 0.5f;
		s->f78 = 0.5f;
		s->f7C = 0;
	}
}

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
