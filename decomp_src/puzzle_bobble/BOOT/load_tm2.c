#include "common.h"

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_tm2", sceGimPictureLoadTm2);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/load_tm2", copy_pixels_18874);

static void sort_clut(void *clut, int format, int width)
{
	int *ptr;

	if (width != 256)
		return;
	ptr = clut;
	if (format == 1) {
		int i;

		for (i = 0; i < 8; i++) {
			int j;

			for (j = 0; j < 4; j++) {
				int tmp = ptr[j + 4];

				ptr[j + 4] = ptr[j + 8];
				ptr[j + 8] = tmp;
			}
			ptr += 16;
		}
	} else if (format == 3) {
		int i;

		for (i = 0; i < 8; i++) {
			int j;

			for (j = 0; j < 8; j++) {
				int tmp = ptr[j + 8];

				ptr[j + 8] = ptr[j + 16];
				ptr[j + 16] = tmp;
			}
			ptr += 32;
		}
	}
}
