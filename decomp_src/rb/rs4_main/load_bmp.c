#include "common.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", sceGimPictureLoadBmp);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", read_header_996A0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", read_short_9977C);

void *read_int( void *src, int *val )
{
	{if ( 3 & (int)src ) {{
		unsigned char *cp = (unsigned char *)src ;
		*val = ( cp[ 3 ] << 24 ) | ( cp[ 2 ] << 16 ) | ( cp[ 1 ] << 8 ) | cp[ 0 ] ;
	}} else {{
		*val = *(int *)src ;
	}}}
	return (int *)src + 1 ;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_idx4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_idx8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_5551);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_5650);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_8880);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_8888);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_rle4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/load_bmp", copy_rle8);
