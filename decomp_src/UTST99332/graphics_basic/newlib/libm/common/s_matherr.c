/* upstream: newlib-1.12.0/newlib/libm/common/s_matherr.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libm/common/s_matherr.c"

/* objects without code: their rodata */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/UTST99332/graphics_basic/nonmatchings/newlib/libm/common/s_matherr", __fdlib_version);
