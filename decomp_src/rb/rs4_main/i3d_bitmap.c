/* cflags: -O2 -fno-strict-aliasing */
#include "common.h"
#include "m2c_macros.h"
M2C_UNK I3dResourceTag__PurgeCache();               /* extern */


void RemapOnMemorySub(int *dst, int *a, int *b, int w) {
    int x = 0;
    unsigned int y = 0;
    int i;
    for (i = 0; i < w * 4; i += 4) {
        int *s;
        if (y < 4) s = a + (w * y + x);
        else s = b + (w * (y - 4) + x);
        y++;
        dst[i + 0] = s[0];
        dst[i + 1] = s[1];
        dst[i + 2] = s[2];
        dst[i + 3] = s[3];
        if (y >= 8) { y = 0; x += 4; }
    }
}

void RemapOnMemoryHalf(int *pix, int h, int w, int *tmp)
{
	int y;
	unsigned int j;
	for (y = 0; y < h; y += 8) {
		memcpy(tmp, pix, w * 4 * sizeof(int));
		RemapOnMemorySub(pix, tmp, pix + w * 4, w);
		for (j = 0; j < 4; j++)
			memcpy(tmp + j * w, pix + w * 4 + w / 2 + j * w, w * sizeof(int) / 2);
		RemapOnMemorySub(pix + w * 4, tmp + w / 2, tmp, w);
		pix += w * 8;
	}
}

void RemapOnMemoryFull(int *pix, int h, int w, int *tmp)
{
	int y, i, off = 0;
	for (y = 0; y < h; y += 8) {
		for (i = 0; i < w * 8; i += 4) {
			int *d = (int *)(((i % w) * 2 + i / w) * 16 + (int)tmp);
			d[0] = pix[off + i + 0];
			d[1] = pix[off + i + 1];
			d[2] = pix[off + i + 2];
			d[3] = pix[off + i + 3];
		}
		memcpy(pix + off, tmp, i * 4);
		off += i;
	}
}

void RemapOnStack(void (*fn)(int, int, int, void *), int a, int b, int c)
{
	char buf[0x2000];
	fn(a, b, c, buf);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dPicture__SetupFromTim2Sub_PSP);

int I3dPicture__SetupFromTim2Sub_PSP(void *, void *, void *, unsigned char, void *);
int I3dPicture__SetupFromTim2(void *a, void *b, void *c, unsigned char d)
{
	return I3dPicture__SetupFromTim2Sub_PSP(a, b, c, d, 0);
}

int I3dPicture__SetupFromTim2Sub_PSP(void *, void *, void *, unsigned char, void *);
int I3dPicture__SetupFromTim2_WithImageConvertBuffer_PSP(void *a, void *b, void *c, unsigned char d, void *e)
{
	return I3dPicture__SetupFromTim2Sub_PSP(a, b, c, d, e);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dClut__SetupFromTim2);

int I3dPicture__Get_wPixel(char *p, int lv)
{
	int h = *(unsigned short *)(p + 0x88) >> lv;
	int r = 1;
	if (h != 0)
		r = h;
	return r;
}

int I3dPicture__Get_hPixel(char *p, int lv)
{
	int h = *(unsigned short *)(p + 0x8A) >> lv;
	int r = 1;
	if (h != 0)
		r = h;
	return r;
}

int I3dClut__Construct(int *c)
{
	c[0] = 0; c[1] = 0; c[2] = 0; c[3] = 0; c[4] = 0;
	c[5] = 0; c[6] = 0; c[7] = 0; c[8] = 0; c[9] = 0;
	I3dResourceTag__Construct(c);
	c[4] = 0;
	c[5] = 0;
	return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

int I3dClut__Destruct(void *arg0) {
    M2C_FIELD(arg0, signed char *, 0x26) = 0;
    I3dClut__FlushCache();
    return 0;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dPicture__FlushCache(void) {
    I3dResourceTag__PurgeCache();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void I3dClut__FlushCache(void) {
    I3dResourceTag__PurgeCache();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dLzc);

void I3dVecClearA();
void I3dFogStatusParam__ClearA(int *f)
{
	I3dVecClearA(f);
	f[6] = 0;
	f[7] = 0;
	f[4] = 0;
	f[5] = 0;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", D_001090AC);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/i3d_bitmap", I3dRender__CreateFogStatusA);
