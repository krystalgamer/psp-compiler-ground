/* upstream: newlib-1.12.0/newlib/libm/common/s_matherr.c (unmodified) */
/* cflags: -O2 -fno-builtin */
#include "libm/common/s_matherr.c"

/* s_lib_ver.o's __fdlib_version, split into this object's rodata */
__asm__(".pushsection .rodata\n.align 2\n.globl __fdlib_version\n__fdlib_version:\n.word 1\n.popsection");
