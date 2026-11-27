#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RC4_asm", RCInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RC4_asm", RCSaltyInitialize);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RC4_asm", RCEncrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RC4_asm", RCDecrypt);
