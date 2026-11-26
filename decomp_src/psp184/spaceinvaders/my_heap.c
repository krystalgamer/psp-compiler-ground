/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int g_addr;
extern int g_size;
extern int myHeap_freesize;
extern int myHeap_size;


void myHeapInit(int addr, int size)
{
	g_size = size;
	myHeap_size = 0;
	g_addr = addr;
	myHeap_freesize = size;
}

#ifndef NULL
#define NULL ((void *)0)
#endif

void myHeapTerm(void) {
    g_addr = 0;
    g_size = 0;
    myHeap_size = 0;
    myHeap_freesize = 0;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/my_heap", myHeapAlloc);

void myHeapFree(void) {
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/my_heap", myHeapAlloc16);

void myHeapFree16(void) {
}
