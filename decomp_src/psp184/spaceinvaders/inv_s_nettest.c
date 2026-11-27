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

typedef struct { int f0, f4, x, y, w, h; u8 _p[0x3F0 - 0x18]; } NETDATA;
extern NETDATA netdata[];
unsigned int pad_tr(void);
unsigned int pad_sw(void);
void net_pauseset(void);
int net_mynumget(void);
int net_errorget(void);
int net_entryget(void);
void debug_text(int x, int y, char *str);
int sprintf(char *, const char *, ...);
void test(void)
{
	char buf[64];
	int i, px, py, pw, ph;
	NETDATA *p;

	if (pad_tr() & 0x400080)
		x--;
	else if (pad_tr() & 0x800020)
		x++;
	else if (pad_tr() & 0x100010)
		y--;
	else if (pad_tr() & 0x200040)
		y++;
	else if (pad_tr() & 0x2000)
		h--;
	else if (pad_tr() & 0x4000)
		h++;
	else if (pad_tr() & 0x8000)
		w--;
	else if (pad_tr() & 0x1000)
		w++;
	else if (pad_sw() & 8)
		net_pauseset();
	netdata[net_mynumget()].x = x;
	netdata[net_mynumget()].y = y;
	netdata[net_mynumget()].w = w;
	netdata[net_mynumget()].h = h;
	p = netdata;
	for (i = 0; i < 2; i++, p++) {
		px = p->x;
		py = p->y;
		pw = p->w;
		ph = p->h;
		if (i == 0)
			poly_set(px, py, pw, ph, 0, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 2, 2, 1, 255);
		else if (i == 1)
			poly_set(px, py, pw, ph, 0, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 0, 0, 255, 255, 2, 2, 1, 255);
	}
	sprintf(buf, "net_error %d", net_errorget());
	debug_text(0, 56, buf);
	sprintf(buf, "net_entryget %d", net_entryget());
	debug_text(0, 64, buf);
}

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
