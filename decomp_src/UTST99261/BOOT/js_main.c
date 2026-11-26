#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSStartInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSRunInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSFreeJSPtrInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSHandleEventInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSTimer);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSDestroyInternal);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", D_001339E0);

INCLUDE_RODATA("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", D_001339EC);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JS_halt);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSInitInternal);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", JSEventLoop);

INCLUDE_ASM("tmp/asm/UTST99261/BOOT/nonmatchings/js_main", esp_jsThread);
