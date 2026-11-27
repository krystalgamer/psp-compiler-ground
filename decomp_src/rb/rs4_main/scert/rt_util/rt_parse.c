#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
void rt_parse_update(void);
M2C_UNK rt_parse_timeout_frag_msg();                /* extern */

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_initialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_shutdown);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_register);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_reg_parser);

extern unsigned char gbInitialized_135B94;
extern void *gpfAppParser;
int rt_parse_reg_app_parser(void *f)
{
    if (gbInitialized_135B94 != 1) return 5;
    gpfAppParser = f;
    return 0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_update_parser);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_execute);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_execute_ext);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_get_callback);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_zero_execution_counts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_get_execution_counts);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_fragment_message);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_timeout_frag_msg);

void rt_parse_update(void) {
    rt_parse_timeout_frag_msg();
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_find_frag_msg);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rt_parse_fragment_handler);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", rcsid_10EE44);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_parse", headerfile_rcsid_10EEA0);
