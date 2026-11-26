/* cflags: -O2 -fno-merge-constants */
#include "common.h"

extern int x;
extern int y;
extern int w;
extern int h;
static void testinit(void)
{
	y = 0;
	x = 0;
	h = 64;
	w = 64;
}

extern int x;
extern int y;
extern int w;
extern int h;

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_nettest", test);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_nettest", net_labo);

int hato(int cur, int target, int shift)
{
	int d;

	d = (target - cur) >> shift;
	if (d == 0) {
		if (cur != target)
			cur++;
	} else {
		cur += d;
	}
	return cur;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_nettest", dis2d);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_nettest", inv_labo);
