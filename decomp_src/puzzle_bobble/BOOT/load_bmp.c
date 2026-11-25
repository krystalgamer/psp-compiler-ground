#include "common.h"

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_bmp", sceGimPictureLoadBmp);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_bmp", read_header_17940);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_bmp", read_short_17A1C);

static const void *read_int(const void *src, int *val)
{
	if ((int)src & 3) {
		const unsigned char *cp = src;

		*val = (cp[3] << 24) | (cp[2] << 16) | (cp[1] << 8) | cp[0];
	} else {
		*val = *(const int *)src;
	}
	return (const char *)src + 4;
}

static void copy_idx4(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	width = (width + 1) / 2;
	pitch = (width + 15) & ~15;
	pitch2 = (width + 3) & ~3;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					int s = *(const unsigned char *)sp2++;

					*dp2++ = (s << 4) | (s >> 4);
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_idx8(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	pitch = (width + 15) & ~15;
	pitch2 = (width + 3) & ~3;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++)
					*dp2++ = *sp2++;
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_5551(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const short int *sp;
	short int *dp;

	pitch = (width + 7) & ~7;
	pitch2 = (width + 1) & ~1;
	sp = src;
	dp = (short int *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const short int *sp2 = sp;
			short int *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					int s = *sp2++;
					int r = (s & 0x7c00) >> 10;
					int b = s & 0x001f;

					*dp2++ = (s & 0x03e0) | r | (b << 10) | 0x8000;
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_5650(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const short int *sp;
	short int *dp;

	pitch = (width + 7) & ~7;
	pitch2 = (width + 1) & ~1;
	sp = src;
	dp = (short int *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const short int *sp2 = sp;
			short int *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					int s = *sp2++;
					int r = (s & 0xf800) >> 11;
					int b = s & 0x001f;

					*dp2++ = r | (s & 0x07e0) | (b << 11);
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_8880(void *dst, const void *src, int width, int height)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	pitch = (width * 4 + 15) & ~15;
	pitch2 = (width * 3 + 3) & ~3;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					dp2[0] = sp2[2];
					dp2[1] = sp2[1];
					dp2[2] = sp2[0];
					dp2[3] = 0xff;
					sp2 += 3;
					dp2 += 4;
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

static void copy_8888(void *dst, const void *src, int width, int height, int alpha)
{
	int pitch;
	int pitch2;
	const char *sp;
	char *dp;

	pitch = (width * 4 + 15) & ~15;
	pitch2 = width * 4;
	sp = src;
	dp = (char *)dst + pitch * (height - 1);
	{
		int i;

		for (i = 0; i < height; i++) {
			const char *sp2 = sp;
			char *dp2 = dp;
			{
				int j;

				for (j = 0; j < width; j++) {
					dp2[0] = sp2[2];
					dp2[1] = sp2[1];
					dp2[2] = sp2[0];
					dp2[3] = sp2[3] | alpha;
					sp2 += 4;
					dp2 += 4;
				}
			}
			sp += pitch2;
			dp -= pitch;
		}
	}
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_bmp", copy_rle4);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_bmp", copy_rle8);
