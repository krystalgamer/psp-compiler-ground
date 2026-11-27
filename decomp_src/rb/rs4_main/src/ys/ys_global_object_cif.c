/* lang: c++ */
/* cflags: -Os */
#include "common.h"
extern "C" {

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_global_object_cif", ysGlobalObject__Create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_global_object_cif", ysGlobalObject__Destroy);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/ys/ys_global_object_cif", D_00104D68);

} /* extern "C": m2c drafts with mangled names, kept as C linkage */
