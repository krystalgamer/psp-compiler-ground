#include "common.h"
#include "m2c_macros.h"


INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", DomStringToUtf8);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", checkAtributeByName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", getTagName);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", getRawTextFromDomNode);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", getRawTextFromDomTree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", getTextFromDomTree);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", getDOMDocument);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initBodyContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initFramesetContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initFrameBorderContent);

#ifndef NULL
#define NULL ((void *)0)
#endif
void initNoneContent(void *arg0) {
    M2C_FIELD(arg0, short *, 0x38) = 0;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initTextContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initPreTextContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initImageContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initTableContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initTrContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initTdContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initColContent);

#ifndef NULL
#define NULL ((void *)0)
#endif
void initHlineContent(void *arg0) {
    M2C_FIELD(arg0, short *, 0x38) = 0xB;
}

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initButtonContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initBlockButtonContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initTextFieldContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initPasswordContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initTextAreaContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initCheckContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initRadioContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initSelectContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initMarqueeContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initListContent);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/lo_domApi", initLiContent);
