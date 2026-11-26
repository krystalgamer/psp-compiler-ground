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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_laser", inv_laser_start);

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
