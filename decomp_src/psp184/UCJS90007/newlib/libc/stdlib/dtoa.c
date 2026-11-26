/* upstream: newlib-1.12.0/newlib/libc/stdlib/dtoa.c (Sony's 1.8.x psp-newlib build: _REENT is __getreent()) */
/* cflags: -O2 -fno-builtin */
/* data-align: 8 */

/* objects without code: their rodata */
__asm__(".include \"include/labels.inc\"");
#define CTYPE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
/* ctype_.o's _ctype_ table precedes dtoa.o's rodata */
CTYPE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/newlib/libc/stdlib/dtoa", _ctype_b);
CTYPE_RODATA("tmp/asm/psp184/UCJS90007/nonmatchings/newlib/libc/stdlib/dtoa", D_000304E0);

#define __DYNAMIC_REENT__
#include "libc/stdlib/dtoa.c"
