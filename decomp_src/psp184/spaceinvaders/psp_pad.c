/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int D_00287344;
extern int pad;
extern int D_00287348;
extern int D_0028734C;
extern int D_00287350;
extern int D_00287354;


extern int D_00287388;

int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlSetSamplingMode(int mode);
int sceUtilityGetSystemParamInt(int id, int *value);
void *memset(void *, int, unsigned int);

int sceCtrlSetSamplingCycle(int cycle);
int sceCtrlSetSamplingMode(int mode);
int sceUtilityGetSystemParamInt(int id, int *value);
void *memset(void *, int, unsigned int);
void pad_init(void)
{
	int val;
	u8 *p;

	sceCtrlSetSamplingCycle(0);
	sceCtrlSetSamplingMode(1);
	p = (u8 *)&pad;
	memset(p, 0, 0x4C);
	if (sceUtilityGetSystemParamInt(9, &val) == 0) {
		if (val == 0)
			*(int *)(p + 0x48) = 0;
		else
			*(int *)(p + 0x48) = 1;
	}
}

typedef struct { unsigned int TimeStamp; unsigned int Buttons; unsigned char Lx, Ly; unsigned char Rsrv[6]; } PADBUF;
typedef struct {
	int tr, rp, rp1, rp2;
	int x, y;
	int d_now, d_trg, d_rep, d_rep2, d_cnt, d_old;
	int b_now, b_trg, b_rep, b_rep2, b_cnt, b_old;
	int sys;
} PAD_T;
int sceCtrlReadBufferPositive(PADBUF *, int);
#define p ((PAD_T *)&pad)
void pad_read(void)
{
	PADBUF buf;
	unsigned int b, d, old, old2, bt;

	sceCtrlReadBufferPositive(&buf, 1);
	bt = buf.Buttons;
	p->x = buf.Lx - 128;
	p->y = buf.Ly - 128;
	if (bt & 0x30000) {
		p->x = 0;
		p->y = 0;
	}
	b = bt;
	if (p->x > -48 && p->x < 48)
		p->x = 0;
	if (p->y > -48 && p->y < 48)
		p->y = 0;
	if (!(b & 0xF000F0)) {
		if (p->x < -89)
			b |= 0x400000;
		if (p->x >= 90)
			b |= 0x800000;
		if (p->y < -89)
			b |= 0x100000;
		if (p->y >= 90)
			b |= 0x200000;
	}
	old = p->d_old;
	d = b & 0xF000F0;
	p->d_trg = b & (b ^ old) & 0xF000F0;
	p->d_now = d;
	if (old != d) {
		p->d_cnt = 0;
		p->d_rep = d;
		p->d_rep2 = d;
	} else {
		p->d_rep = 0;
		p->d_cnt++;
		p->d_rep2 = 0;
		if (p->d_cnt >= 20) {
			p->d_rep = old;
			p->d_cnt = 15;
		}
		if (p->d_cnt >= 15)
			p->d_rep2 = p->d_now;
	}
	old2 = p->b_old;
	p->d_old = p->d_now;
	p->b_trg = b & (b ^ old2) & 0xFFF0F;
	p->b_now = b & 0xFFF0F;
	if (old2 != p->b_now) {
		p->b_cnt = 0;
		p->b_rep = p->b_now;
		p->b_rep2 = p->b_now;
	} else {
		p->b_rep = 0;
		p->b_cnt++;
		p->b_rep2 = 0;
		if (p->b_cnt >= 20) {
			p->b_rep = old2;
			p->b_cnt = 15;
		}
		if (p->b_cnt >= 15)
			p->b_rep2 = p->b_now;
	}
	p->b_old = p->b_now;
	p->rp = p->d_trg | p->b_trg;
	p->tr = p->d_now | p->b_now;
	p->rp1 = p->d_rep | p->b_rep;
	p->rp2 = p->d_rep2 | p->b_rep2;
}
#undef p

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
