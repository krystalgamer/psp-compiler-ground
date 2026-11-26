#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindValue);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", procMetaTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseFindMetaTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckMetaCharset);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckEncodeType);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseSetExtractedAuthData);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseTagNameCmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDSTagNameCmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseTagCountPlus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseTagCountMinus);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseNextChar);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseSkipChar);

#ifndef NULL
#define NULL ((void *)0)
#endif
int parseNextInput(void) {
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseStrnCpy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseStrcmp);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseStrEqual);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseStrEqualNoCase);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDStrEqual);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDStrnEqual);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDStrTrace);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseMBtoDScopy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseDStoMBcopy);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseConvertUTF8toUCS2);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseCheckLastTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseConvertEncode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseBackTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseWellFormedTag);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", parseAlertMessage);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", rnd_addAnimBoxnode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", rnd_removeAnimBoxnode);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00138FEC);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00138FF8);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00139004);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_00139010);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/parseStrings", D_0013901C);
