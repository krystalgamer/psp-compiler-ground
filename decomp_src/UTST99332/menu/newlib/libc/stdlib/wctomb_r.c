/* upstream: newlib-1.12.0/newlib/libc/stdlib/wctomb_r.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libc/stdlib/wctomb_r.c"

/* ctype_.o (const data only), linked between wctomb_r.o and dtoa.o */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/newlib/libc/stdlib/dtoa", _ctype_b);
INCLUDE_RODATA("tmp/asm/UTST99332/menu/nonmatchings/newlib/libc/stdlib/dtoa", D_00195A24);
