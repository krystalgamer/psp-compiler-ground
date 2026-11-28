#include "common.h"
/* text-align: 16 */
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md5_asm", md5Transform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md5_asm", md5Encode);
