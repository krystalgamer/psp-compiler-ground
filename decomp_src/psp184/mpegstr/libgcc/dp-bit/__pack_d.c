/* upstream: libgcc dp-bit.c (_pack_df.o), tree: 1.6.1 */
/* cflags: -O2 */
#define FINE_GRAINED_LIBRARIES
#define L_pack_df
#include "dp-bit.c"

/* _thenan_df.o and _clz.o (no .text): their __thenan_df and __clz_tab land in this unit */
__asm__(".include \"include/labels.inc\"\n.pushsection .rodata\n"
        ".include \"tmp/asm/psp184/mpegstr/nonmatchings/libgcc/dp-bit/__pack_d/__thenan_df.s\"\n"
        ".include \"tmp/asm/psp184/mpegstr/nonmatchings/libgcc/dp-bit/__pack_d/__clz_tab.s\"\n.popsection");
