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

void *I3dRender__ReserveTrashQwc(void *, int);
int I3dLightStatus__SetAmbientLight();
int I3dLightStatus__SetDirLight(int *, int, int);
int I3dLightStatus__SetPointLight(int *, int, int);
int I3dLightStatus__SetSpotLight(int *, int, int);
int *I3dRender__CreateLightStatus(void *r, char *src)
{
    int *ls = I3dRender__ReserveTrashQwc(r, 3);
    int t;
    I3dLightStatus__Clear(ls);
    *(void **)((char *)ls + 0x28) = r;
    I3dLightStatus__SetAmbientLight(ls, src);
    t = *(int *)(src + 0x14);
    if (t != 0)
        I3dLightStatus__SetDirLight(ls, *(int *)(src + 0x10), t);
    if (*(int *)(src + 0x1C) != 0)
        I3dLightStatus__SetPointLight(ls, *(int *)(src + 0x18), *(int *)(src + 0x1C));
    if (*(int *)(src + 0x24) != 0)
        I3dLightStatus__SetSpotLight(ls, *(int *)(src + 0x20), *(int *)(src + 0x24));
    return ls;
}
