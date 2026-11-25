#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", vblankHandler);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_create);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_delete);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_reset);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_waitDisp);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_waitDecode);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_setCondition);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_getCondition);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_waitConditionDispStart);

INCLUDE_ASM("tmp/asm/psp184/mpegstr/nonmatchings/control", control_waitConditionSoundStart);
