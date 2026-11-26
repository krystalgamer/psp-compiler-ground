/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"


float sinf(float x);
float atan2f(float y, float x);
#define PI 3.1415927f
int rot2pos_x(int len, int rot)
{
	return sinf(rot / 180.0f * PI) * len;
}

int rot2pos_y(int len, int rot)
{
	return -sinf((rot + 90.0f) / 180.0f * PI) * len;
}

float rot2posf_x(float len, float rot)
{
	return sinf(rot / 180.0f * PI) * len;
}

float rot2posf_y(float len, float rot)
{
	return -sinf((rot + 90.0f) / 180.0f * PI) * len;
}

int pos2rot(int x, int y)
{
	int rot;

	rot = atan2f(y, x) * 180.0f / PI;
	rot += 90;
	while (rot < 0) {
		rot += 360;
	}
	while (rot >= 360) {
		rot -= 360;
	}
	return rot;
}

float pos2rotf(float x, float y)
{
	float rot;

	rot = atan2f(y, x) * 180.0f / PI;
	rot += 90.0f;
	while (rot < 0.0f) {
		rot += 360.0f;
	}
	while (rot > 359.0f) {
		rot -= 360.0f;
	}
	return rot;
}

int pos_length_check(int x, int y, int len)
{
	if (pos_fast_length_check(x, y, len) == 1) {
		if (vec_length(x, y) <= len) {
			return 1;
		}
	}
	return 0;
}

int pos_fast_length_check(int x, int y, int len)
{
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	if (x < y) x = y;
	if (x > len) return 0;
	return 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", pos_fast_length_xyz_check);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", math_truncated);

int vec_length(int x, int y)
{
	return sqrtf((float)(x * x) + (float)(y * y));
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int vec_length_fast(int arg0, int arg1) {
    return (arg0 * arg0) + (arg1 * arg1);
}

extern char num2str_dat[];
void *memset(void *s, int c, unsigned int n);
char *num2str(int num, int digits)
{
	char *tbl[13] = { "\x82\x4f", "\x82\x50", "\x82\x51", "\x82\x52", "\x82\x53", "\x82\x54", "\x82\x55",
			  "\x82\x56", "\x82\x57", "\x82\x58", "\x81\x40", "\x81\x5b", "" };
	char *s;
	int pos, i, k, p, d;
	char nz;

	memset(num2str_dat, 0, 256);
	pos = 0;
	i = digits;
	if (num < 0) {
		pos = 2;
		num = -num;
		s = tbl[11];
		num2str_dat[0] = s[0];
		num2str_dat[1] = s[1];
	}
	nz = 0;
	for (; i > 0; i--) {
		p = 1;
		for (k = 0; k < i - 1; k++)
			p *= 10;
		d = (num / p) % 10;
		if (d != 0)
			nz = 1;
		if (i == 1)
			nz = 1;
		if (d == 0 && nz == 0)
			s = tbl[10];
		else
			s = tbl[d];
		num2str_dat[pos] = s[0];
		num2str_dat[pos + 1] = s[1];
		pos += 2;
	}
	return num2str_dat;
}

#ifndef NULL
#define NULL ((void *)0)
#endif
int sjis_check(void *arg0) {
    return (unsigned int) ((M2C_FIELD(arg0, signed char *, 1) + (M2C_FIELD(arg0, signed char *, 0) << 8)) & 0xFFFF) > 0x813FU;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num_digit_get0);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num_digit_get);

int addr_to_int(unsigned char *p)
{
	int v;

	v = *p++;
	v += *p++ << 8;
	v += *p << 16;
	v += p[1] << 24;
	return v;
}

