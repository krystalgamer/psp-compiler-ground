#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_tga", sceGimPictureLoadTga);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_tga", read_header_9A29C);

void *read_char( void *src, unsigned char *val )
{
	*val = *(unsigned char *)src ;
	return (unsigned char *)src + 1 ;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_tga", read_short_9A360);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_tga", copy_pixels_9A390);
