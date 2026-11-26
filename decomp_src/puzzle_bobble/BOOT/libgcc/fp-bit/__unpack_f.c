/* upstream: libgcc fp-bit.c (_unpack_sf.o), tree: 1.6.1 */
/* cflags: -O2 */
#define FINE_GRAINED_LIBRARIES
#define L_unpack_sf
#include "fp-bit.c"

/* _thenan_df.o's __thenan_df, split into this object's rodata */
__asm__(".pushsection .rodata\n.align 3\n.globl __thenan_df\n__thenan_df:\n.space 24\n.popsection");
