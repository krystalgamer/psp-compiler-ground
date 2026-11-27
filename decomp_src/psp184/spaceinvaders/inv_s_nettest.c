/* cflags: -O2 */
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

extern char *AutoNetMsgTbl_80A38[];
void net_init(void);
int net_lobby(void);
int net_gamecomm_packinit(void);
void maingame_loop(int mode);
int net_errorget(void);
void sysmsg_string(char *msg, int a, int b);
int net_term();
int net_labo(void)
{
	int r;

	net_init();
	r = net_lobby();
	if (r == 1)
		return 0;
	r = net_gamecomm_packinit();
	if (r == 0) {
		maingame_loop(1);
		if (net_errorget() == 2)
			sysmsg_string(AutoNetMsgTbl_80A38[0], 3, 1);
	} else if (r == 1) {
		sysmsg_string(AutoNetMsgTbl_80A38[0], 3, 1);
	} else if (r == 2) {
		sysmsg_string(AutoNetMsgTbl_80A38[0], 3, 1);
	}
	return net_term();
}

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

float sqrtf(float);
int dis2d(int x0, int y0, int x1, int y1)
{
	int dx = x1 - x0;
	int dy = y1 - y0;

	return sqrtf(dx * dx + dy * dy);
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/inv_s_nettest", inv_labo);
