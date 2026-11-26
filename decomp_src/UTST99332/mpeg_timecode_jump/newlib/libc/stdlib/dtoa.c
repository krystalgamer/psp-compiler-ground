/* upstream: newlib-1.12.0/newlib/libc/stdlib/dtoa.c (unmodified) */
/* cflags: -O2 -fno-builtin */
/* data-align: 8 */
/* rodata of the data-only object linked before */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/newlib/libc/stdlib/dtoa", _ctype_b);
INCLUDE_RODATA("tmp/asm/UTST99332/mpeg_timecode_jump/nonmatchings/newlib/libc/stdlib/dtoa", D_00010BC0);
#undef INCLUDE_RODATA
#include "libc/stdlib/dtoa.c"
