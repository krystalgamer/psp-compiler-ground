#include "common.h"

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", read_header_E754);

static const void *read_char(const void *src, unsigned char *val)
{
	*val = *(const unsigned char *)src;
	return (const unsigned char *)src + 1;
}

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", read_short_E818);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", copy_pixels_E848);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tga", sceGimPictureLoadTm2);
