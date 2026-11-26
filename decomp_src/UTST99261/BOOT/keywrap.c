#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _keywrap_encrypt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", _keywrap_decrypt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/keywrap", aeskw_xor64);

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
