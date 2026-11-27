#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_create_pool);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_destroy_pool);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_get_pool_used);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_create);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_destroy);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_clear);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_insert);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_set_new_head);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_remove);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_append_data);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_get_tail);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_normalize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_resize_buffer);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", pool_alloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", pool_free);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rcsid_10C164);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_list_buf", rt_list_buf_header_rcsid);
