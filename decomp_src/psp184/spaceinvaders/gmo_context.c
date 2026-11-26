#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextBegin);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextEnd);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetBone);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetMaterial);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetTexture);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextDefaultEnableBits);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetEnableBits);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextDefaultTexOffs);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextDefaultTexCrop);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextDefaultTexTrim);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetTexOffs);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetTexCrop);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", sceGmoContextSetTexTrim);

void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuLightMode(int mode);
void sceGuDepthMask(int mask);
void sceGuPixelMask(unsigned int mask);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
static void activate_enable_bits(int mask, int bits)
{
	if (mask & 0x01) {
		if (bits & 0x01)
			sceGuEnable(10);
		else
			sceGuDisable(10);
	}
	if (mask & 0x02) {
		if (bits & 0x02)
			sceGuEnable(7);
		else
			sceGuDisable(7);
	}
	if (mask & 0x04) {
		if (bits & 0x04)
			sceGuEnable(9);
		else
			sceGuDisable(9);
	}
	if (mask & 0x08) {
		if (bits & 0x08)
			sceGuEnable(5);
		else
			sceGuDisable(5);
	}
	if (mask & 0x10) {
		if (bits & 0x10)
			sceGuEnable(1);
		else
			sceGuDisable(1);
	}
	if (mask & 0x20) {
		int depth_mask = (bits & 0x20) ? 0 : 1;
		sceGuDepthMask(depth_mask);
	}
	if (mask & 0x40) {
		if (bits & 0x40)
			sceGuEnable(0);
		else
			sceGuDisable(0);
	}
	if (mask & 0x80) {
		unsigned int alpha_mask = (bits & 0x80) ? 0 : 0xff000000;
		sceGuPixelMask(alpha_mask);
	}
	if (mask & 0x10000) {
		if (bits & 0x10000)
			sceGuLightMode(1);
		else
			sceGuLightMode(0);
	}
	if (mask & 0x20000) {
		if (bits & 0x20000)
			sceGuTexMapMode(2, 2, 3);
		else
			sceGuTexMapMode(0, 0, 0);
	}
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", activate_tex_crop);

INCLUDE_RODATA("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_context", __psp_libinfo___7F130);
