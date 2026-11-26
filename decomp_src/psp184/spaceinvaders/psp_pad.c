#include "common.h"
#include "m2c_macros.h"
extern int D_00287344;
extern int pad;
extern int D_00287348;
extern int D_0028734C;
extern int D_00287350;
extern int D_00287354;


extern int D_00287388;

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_pad", pad_init);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/psp_pad", pad_read);

extern int D_00287388;
int pad_ret_button(void)
{
	return (D_00287388 == 0) ? 0x2000 : 0x4000;
}

int pad_cansel_button(void)
{
	return (D_00287388 == 0) ? 0x4000 : 0x2000;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pad_sw(void) {
    return D_00287344;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pad_tr(void) {
    return pad;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pad_rp(void) {
    return D_00287348;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pad_rp2(void) {
    return D_0028734C;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pad_x(void) {
    return D_00287350;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int pad_y(void) {
    return D_00287354;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float pad_xf(void) {
    return (float) D_00287350 * 0.0078125f;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

float pad_yf(void) {
    return (float) D_00287354 * 0.0078125f;
}
