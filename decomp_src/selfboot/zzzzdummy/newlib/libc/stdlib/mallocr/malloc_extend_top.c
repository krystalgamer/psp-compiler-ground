/* upstream: newlib-1.12.0/newlib/libc/stdlib/mallocr.c (Sony's psp-newlib build: 16-byte MALLOC_ALIGNMENT) */
/* cflags: -O2 -fno-builtin -fdata-sections */
#define INTERNAL_NEWLIB
#define DEFINE_MALLOC
#define MALLOC_ALIGNMENT 16
#include "libc/stdlib/mallocr.c"

/* The module's .data/.bss (asm) define these: -fdata-sections puts the C
   copies into .data.* sections the linker script discards, and they are
   made weak in the assembler only (#pragma weak would change the code). */
__asm__(".weak __malloc_av_\n.weak __malloc_trim_threshold\n.weak __malloc_top_pad\n"
        ".weak __malloc_sbrk_base\n.weak __malloc_max_sbrked_mem\n"
        ".weak __malloc_max_total_mem\n.weak __malloc_current_mallinfo");
