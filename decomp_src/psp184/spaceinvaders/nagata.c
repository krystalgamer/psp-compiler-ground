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

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num2str);

#ifndef NULL
#define NULL ((void *)0)
#endif
int sjis_check(void *arg0) {
    return (unsigned int) ((M2C_FIELD(arg0, signed char *, 1) + (M2C_FIELD(arg0, signed char *, 0) << 8)) & 0xFFFF) > 0x813FU;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num_digit_get0);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", num_digit_get);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", addr_to_int);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A594);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A598);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A59C);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5A0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5A4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5A8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5AC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5B0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5B4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5B8);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5BC);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5C0);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5C4);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/nagata", D_0007A5C8);
