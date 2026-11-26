#include "common.h"
#include "m2c_macros.h"
extern unsigned char inv_ring;
extern int gmo_max;
extern int ring_pri_no;
extern int ring_tex_no;


#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void inv_ring_all_init(void) {
    memset(&inv_ring, 0, 0x6F00U);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_ring_priset(void) {
    ring_pri_no = gmo_max;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int inv_ring_priget(void) {
    return ring_pri_no;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void inv_ring_texno(int arg0) {
    ring_tex_no = arg0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_ring", inv_ring_start);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_ring", inv_ring_end);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_ring", inv_ring_control);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_ring", inv_ring_disp);
