/* upstream: libgcc dp-bit.c (_pack_df.o), tree: 1.5.1 */
/* cflags: -O2 */
#define FINE_GRAINED_LIBRARIES
#define L_pack_df
#include "dp-bit.c"

/* _thenan_df.o's __thenan_df and _clz.o's __clz_tab (objects without code) */
__asm__(".include \"include/labels.inc\"");
#define INCLUDE_RODATA(FOLDER, NAME) \
    __asm__(".section .rodata\n.include \"" FOLDER "/" #NAME ".s\"\n.section .text")
INCLUDE_RODATA("tmp/asm/selfboot/zzzzdummy/nonmatchings/libgcc/dp-bit/__pack_d", __thenan_df);
INCLUDE_RODATA("tmp/asm/selfboot/zzzzdummy/nonmatchings/libgcc/dp-bit/__pack_d", __clz_tab);
