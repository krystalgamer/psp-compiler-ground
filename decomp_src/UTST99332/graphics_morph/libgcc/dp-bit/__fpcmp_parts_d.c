/* upstream: libgcc dp-bit.c (_fpcmp_parts_df.o), tree: 1.6.1 */
/* cflags: -O2 */
#define FINE_GRAINED_LIBRARIES
#define L_fpcmp_parts_df
#include "dp-bit.c"

/* objects without code: their rodata */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/libgcc/dp-bit/__fpcmp_parts_d", __thenan_df);
INCLUDE_RODATA("tmp/asm/UTST99332/graphics_morph/nonmatchings/libgcc/dp-bit/__fpcmp_parts_d", __clz_tab);
