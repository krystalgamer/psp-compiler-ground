#include "common.h"
#include "m2c_macros.h"

extern int g_addr;
extern int g_size;


void myHeapInit(int arg0, int arg1) {
    g_addr = arg0;
    g_size = arg1;
}

void myHeapTerm(void) {
    g_addr = 0;
    g_size = 0;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/my_heap", myHeapAlloc);

void myHeapFree(void) {
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/my_heap", myHeapAlloc16);

void myHeapFree16(void) {
}
