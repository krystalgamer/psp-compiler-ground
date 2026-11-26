#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _keywrap_encrypt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _keywrap_decrypt);

#ifndef NULL
#define NULL ((void *)0)
#endif
void aeskw_xor64(void *arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg2, signed char *, 0) = (signed char) (M2C_FIELD(arg0, unsigned char *, 0) ^ M2C_FIELD(arg1, unsigned char *, 0));
    M2C_FIELD(arg2, signed char *, 1) = (signed char) (M2C_FIELD(arg0, unsigned char *, 1) ^ M2C_FIELD(arg1, unsigned char *, 1));
    M2C_FIELD(arg2, signed char *, 2) = (signed char) (M2C_FIELD(arg0, unsigned char *, 2) ^ M2C_FIELD(arg1, unsigned char *, 2));
    M2C_FIELD(arg2, signed char *, 3) = (signed char) (M2C_FIELD(arg0, unsigned char *, 3) ^ M2C_FIELD(arg1, unsigned char *, 3));
    M2C_FIELD(arg2, signed char *, 4) = (signed char) (M2C_FIELD(arg0, unsigned char *, 4) ^ M2C_FIELD(arg1, unsigned char *, 4));
    M2C_FIELD(arg2, signed char *, 5) = (signed char) (M2C_FIELD(arg0, unsigned char *, 5) ^ M2C_FIELD(arg1, unsigned char *, 5));
    M2C_FIELD(arg2, signed char *, 6) = (signed char) (M2C_FIELD(arg0, unsigned char *, 6) ^ M2C_FIELD(arg1, unsigned char *, 6));
    M2C_FIELD(arg2, signed char *, 7) = (signed char) (M2C_FIELD(arg0, unsigned char *, 7) ^ M2C_FIELD(arg1, unsigned char *, 7));
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _rijndaelKeySetupEnc);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _rijndaelKeySetupDec);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _rijndaelEncrypt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _rijndaelDecrypt);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Te0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Te1);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Te2);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Te3);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Te4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Td0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Td1);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Td2);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Td3);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", Td4);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", rcon);
