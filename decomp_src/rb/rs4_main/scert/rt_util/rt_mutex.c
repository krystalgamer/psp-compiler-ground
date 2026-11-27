#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", rt_mutex_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", rt_mutex_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", rt_mutex_lock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", rt_mutex_lock_no_block);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", rt_mutex_unlock);

#ifndef NULL
#define NULL ((void *)0)
#endif
M2C_UNK rt_mutex_platform_begin_critical_section(); /* extern */

void rt_mutex_begin_critical_section(void) {
    rt_mutex_platform_begin_critical_section();
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void rt_mutex_end_critical_section(void) {
    rt_mutex_platform_begin_critical_section();
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", rcsid_10EBFC);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_mutex", header_rcsid_10EC54);
