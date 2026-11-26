/* upstream: libgcc fp-bit.c (_unpack_sf.o), tree: 1.6.1 */
/* cflags: -O2 */
#define FINE_GRAINED_LIBRARIES
#define L_unpack_sf
#include "fp-bit.c"

/* objects without code: their rodata */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/UTST99332/graphics_depthblur/nonmatchings/libgcc/fp-bit/__unpack_f", __thenan_df);
