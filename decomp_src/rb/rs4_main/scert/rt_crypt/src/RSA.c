#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", RSAEncryptBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", RSADecryptBlock);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", RSAEncrypt);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", RSADecrypt);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", rcsid_10D4E0);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/RSA", header_rcsid_10D538);
