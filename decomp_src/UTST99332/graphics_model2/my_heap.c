#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/my_heap", myHeapInit);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/my_heap", myHeapTerm);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/my_heap", myHeapAlloc);

void myHeapFree(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/graphics_model2/nonmatchings/my_heap", myHeapAlloc16);

void myHeapFree16(void) {
}
