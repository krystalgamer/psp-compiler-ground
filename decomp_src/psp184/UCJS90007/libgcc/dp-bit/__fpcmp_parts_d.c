/* upstream: libgcc dp-bit.c (_fpcmp_parts_df.o), tree: 1.6.1 */
/* cflags: -O2 */
#define FINE_GRAINED_LIBRARIES
#define L_fpcmp_parts_df
#include "dp-bit.c"

/* _thenan_df.o and _clz.o (no .text): their __thenan_df and __clz_tab land in this unit */
__asm__(".include \"include/labels.inc\"\n.pushsection .rodata\n"
        ".include \"tmp/asm/psp184/UCJS90007/nonmatchings/libgcc/dp-bit/__fpcmp_parts_d/__thenan_df.s\"\n"
        ".include \"tmp/asm/psp184/UCJS90007/nonmatchings/libgcc/dp-bit/__fpcmp_parts_d/__clz_tab.s\"\n.popsection");
