/* cflags: -O1 */
#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", READINT32);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", PaethPredictor);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", do_scanline);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", do_filter_sub);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", do_filter_up);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", do_filter_average);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", do_filter_paeth);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001326F0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001326F8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132700);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132708);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132710);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132718);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132720);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", srow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", scol);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", irow);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", icol);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", bheight);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", bwidth);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_IDAT);

#ifndef NULL
#define NULL ((void *)0)
#endif
int handle_IEND(void) {
    return 1;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_IHDR);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_PLTE);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_gAMA);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_pHYs);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", handle_tRNS);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", png_readNextChunk);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132788);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_0013278C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132790);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132794);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_00132798);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_0013279C);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327A0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327A4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327A8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327AC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327B0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", D_001327B4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/png_chunk", length_tab);
