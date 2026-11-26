/* upstream: libgcc dp-bit.c (_fpcmp_parts_df.o), tree: 1.6.1 */
/* cflags: -O2 */
#define FINE_GRAINED_LIBRARIES
#define L_fpcmp_parts_df
#include "dp-bit.c"

/* _clz.o (no .text): its __clz_tab lands in this unit */
__asm__(".include \"include/labels.inc\"\n.pushsection .rodata\n.include \"decomp_src/psp184/spaceinvaders/libgcc/dp-bit/data/__clz_tab.s\"\n.popsection");
