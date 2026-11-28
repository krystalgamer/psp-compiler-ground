/* cflags: -O2 -fno-strict-aliasing */
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

typedef struct { int start, end, num, cur; } VoRange_;
typedef struct { char pad[0xC]; VoRange_ dev[8]; VoRange_ cat[8][16]; } VoWorkR_;
int sgxVoSetDeviceRange(unsigned int dev, int start, int num)
{
	VoRange_ r;
	int end = start + num - 1;
	int i;
	if (dev >= 8 || end < start) return 0;
	r.start = start;
	r.end = end;
	r.num = end - start + 1;
	r.cur = start;
	((VoWorkR_ *)&gWork_11FF60)->dev[dev] = r;
	for (i = 0; i < 16; i++)
		((VoWorkR_ *)&gWork_11FF60)->cat[dev][i] = r;
	return num;
}

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

extern int gSgxDebugFlags;
extern int gSgxPrefErr;
extern const char D_0010AEE4[];
int sgxPrintfPref(int, const void *, int, const char *, ...);
void sgxCategorySetVoiceRange(unsigned int cat, unsigned int dev, int ofs, int end)
{
	int lo, hi, s, e, n;
	if (cat >= 16 || dev >= 3 || end < ofs) goto err;
	lo = ((VoWorkR_ *)&gWork_11FF60)->dev[dev].start;
	hi = ((VoWorkR_ *)&gWork_11FF60)->dev[dev].end;
	s = lo + ofs;
	e = lo + end;
	if (s < lo || hi < s) goto err;
	if (e < lo || hi < e) goto err;
	n = e - s + 1;
	((VoWorkR_ *)&gWork_11FF60)->cat[dev][cat].end = e;
	((VoWorkR_ *)&gWork_11FF60)->cat[dev][cat].num = n;
	((VoWorkR_ *)&gWork_11FF60)->cat[dev][cat].start = s;
	((VoWorkR_ *)&gWork_11FF60)->cat[dev][cat].cur = s;
	return;
err:
	if (gSgxDebugFlags & 1) sgxPrintfPref(gSgxPrefErr, D_0010AEE4, 0xB2, "invalid category range (%d,%d,%d,%d)\n", cat, dev, ofs, end);
}

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
