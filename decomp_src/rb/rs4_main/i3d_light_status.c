/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"

void I3dLightStatus__Clear(int *p)
{
	__asm__ volatile("sv.q C720.q,0(%0)\n" : : "r"(p) : "memory");
	p[4] = 0;
	p[5] = 0;
	p[6] = 0;
	p[7] = 0;
	p[8] = 0;
	p[9] = 0;
	p[10] = 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_light_status", I3dRender__CreateLightStatus);
