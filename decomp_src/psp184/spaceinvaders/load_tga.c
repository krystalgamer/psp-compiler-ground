#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/load_tga", sceGimPictureLoadTga);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/load_tga", read_header_63878);

void *read_char( void *src, unsigned char *val )
{
 *val = *(unsigned char *)src ;
 return (unsigned char *)src + 1 ;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/load_tga", read_short_6393C);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/load_tga", copy_pixels_6396C);
