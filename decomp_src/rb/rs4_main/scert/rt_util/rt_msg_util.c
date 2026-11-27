#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int rt_msg_set_byte(signed char *arg0, signed char arg1);

int rt_msg_set_byte(signed char *arg0, signed char arg1) {
    int var_v0;

    var_v0 = 2;
    if (arg0 != NULL) {
        *arg0 = arg1;
        var_v0 = 0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_ubyte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_ubyte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_u2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_u2byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_u4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_u4byte);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_u2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_u2byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_4byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_4byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_set_u4byte_be);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rt_msg_get_u4byte_be);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", rcsid_10EA4C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_msg_util", header_rcsid_10EAA8);
