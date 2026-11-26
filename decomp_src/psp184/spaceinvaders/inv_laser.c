/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern unsigned char inv_laser;
extern int gmo_max;
extern int laser_pri_no;
extern int laser_tex_no;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);



typedef struct { int f0; int f4; int f8; int fC; int f10; u8 pad[0xE8 - 0x14]; } LZ_W;

void inv_laser_all_init(void) {
    memset(&inv_laser, 0, 0x1D00U);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_laser_priset(void) {
    laser_pri_no = gmo_max;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_laser_priget(void) {
    return laser_pri_no;
}

typedef struct { float x, y, z; } LZV;
typedef struct {
	int used, f4, type, fC, f10, f14;
	u8 _p18[0x88 - 0x18];
	LZV v[4];
	u8 _pb8[0xE8 - 0xB8];
} LZ_S;
void inv_laser_texupdate(LZ_S *l);
int inv_laser_start(int type, int a1)
{
	LZ_S *l = (LZ_S *)&inv_laser;
	int i;

	for (i = 0; i < 32; i++, l++) {
		if (l->used == 0) {
			l->used = 1;
			l->type = type;
			l->f10 = -1;
			l->f14 = a1;
			l->f4 = 0;
			l->fC = 0;
			l->v[0].x = 0;
			l->v[0].y = 0;
			l->v[0].z = 0;
			l->v[1].x = 0;
			l->v[1].y = 0;
			l->v[1].z = 0;
			l->v[2].x = 0;
			l->v[2].y = 0;
			l->v[2].z = 0;
			{ LZV z = {0, 0, 0}; l->v[3] = z; }
			inv_laser_texupdate(l);
			return i;
		}
	}
	return -1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_laser", inv_laser_texupdate);

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_laser_anime(unsigned int arg0, int arg1) {
    void *temp_v0;

    if (arg0 < 0x20U) {
        temp_v0 = (arg0 * 0xE8) + &inv_laser;
        M2C_FIELD(temp_v0, int *, 0xC) = (int) (M2C_FIELD(temp_v0, int *, 0xC) + arg1);
    }
}

int inv_laser_end(unsigned int no)
{
	if (no >= 32)
		return 0;
	*(int *)((u8 *)&inv_laser + no * 0xE8) = 0;
	return 1;
}

int inv_laser_fadeout(unsigned int no)
{
	if (no < 32) {
		((LZ_W *)&inv_laser)[no].f10 = 8;
		return 1;
	}
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_laser_texno(int arg0) {
    laser_tex_no = arg0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_laser", inv_laser_disp);
