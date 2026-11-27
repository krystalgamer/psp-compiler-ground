#include "common.h"
#include "m2c_macros.h"
M2C_UNK sgxFree(int);                               /* extern */
extern unsigned char gWork_11FF60;
extern int D_0011FF64;
extern int D_0011FF68;


typedef struct { int pad; struct { int a, b, lo, hi; } dev[8]; char pad2[0x84 - 0x84]; } VoWorkA;
typedef struct { char pad[0x84]; struct { int a, b, lo, hi; } cat[3][16]; } VoWorkB;

void *sgxMalloc(int, int);
void *memset(void *s, int c, unsigned int n);
typedef struct { int init; int slots; int num; } VoWorkS;
#define WW ((VoWorkS *)&gWork_11FF60)
int sgxVoInit(int n)
{
    int i;
    memset(WW, 0, 0x88C);
    WW->num = n;
    WW->slots = (int)sgxMalloc(n * 48, 1);
    if (WW->slots == 0) return 0;
    for (i = 0; i < WW->num; i++) *(int *)(WW->slots + i * 48) = i;
    WW->init = 1;
    return 1;
}
#undef WW

#ifndef NULL
#define NULL ((void *)0)
#endif
void *memset(void *s, int c, unsigned int n);

void sgxVoTerm(void) {
    if (M2C_FIELD(&gWork_11FF60, int *, 0) == 0) {

    } else {
        sgxFree(M2C_FIELD(&gWork_11FF60, int *, 4));
        memset(&gWork_11FF60, 0, 0x88CU);
    }
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetSlotTop(void) {
    return D_0011FF64;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetSlotNum(void) {
    return D_0011FF68;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoSetDeviceRange);

int sgxVoGetDeviceRangeLo(unsigned int d)
{
    if (d >= 8) return 0;
    return ((VoWorkA *)&gWork_11FF60)->dev[d].lo;
}

int sgxVoGetDeviceRangeHi(unsigned int d)
{
    if (d >= 8) return 0;
    return ((VoWorkA *)&gWork_11FF60)->dev[d].hi;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", D_0010AEE4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxCategorySetVoiceRange);

int sgxCategoryGetVoiceRangeLo(unsigned int c, unsigned int t)
{
    if (c >= 16) return 0;
    if (t >= 3) return 0;
    return ((VoWorkB *)&gWork_11FF60)->cat[t][c].lo;
}

int sgxCategoryGetVoiceRangeHi(unsigned int c, unsigned int t)
{
    if (c >= 16) return 0;
    if (t >= 3) return 0;
    return ((VoWorkB *)&gWork_11FF60)->cat[t][c].hi;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", FindVoNormal);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", FindVoGroup);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/sgxvo", sgxVoAllocDevice);

void sgxVoSetTakenCallback(int v, void *cb, void *arg)
{
    char *e = (char *)D_0011FF64 + v * 48;
    *(void **)(e + 0x10) = cb;
    *(void **)(e + 0x14) = arg;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

signed char sgxVoGetStatus(int arg0) {
    return M2C_FIELD(((arg0 * 0x30) + D_0011FF64), signed char *, 4);
}

long long sgxVoGetPlaySamples(int v)
{
    return *(long long *)((char *)D_0011FF64 + v * 48 + 0x20);
}

long long sgxVoGetPlayUnitSamples(int v)
{
	char *e = (char *)(v * 48 + D_0011FF64);
	return *(long long *)(e + 0x20) - *(long long *)(e + 0x28);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetDeviceID(int arg0) {
    return M2C_FIELD(((arg0 * 0x30) + D_0011FF64), int *, 0x18);
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int sgxVoGetSlotID(int arg0) {
    return M2C_FIELD(((arg0 * 0x30) + D_0011FF64), int *, 0x1C);
}
