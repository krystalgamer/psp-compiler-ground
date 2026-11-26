#include "common.h"
#include "m2c_macros.h"

extern unsigned int g_addr;
extern unsigned int g_size;


void myHeapInit(int arg0, int arg1) {
    g_addr = arg0;
    g_size = arg1;
}

void myHeapTerm(void) {
    g_addr = 0;
    g_size = 0;
}

void *myHeapAlloc(unsigned int size)
{
	char *p;

	if (size == 0)
		return NULL;
	if (g_size < size)
		return NULL;
	p = g_addr;
	g_addr = p + size;
	g_size = g_size - size;
	return p;
}

void myHeapFree(void) {
}

void *myHeapAlloc16(unsigned int size)
{
	void *p = 0;
	unsigned int pad;

	if (size != 0) {
		pad = (16 - (g_addr & 15)) & 15;
		size += pad;
		if (size <= g_size) {
			p = (void *)(g_addr + pad);
			g_addr += size;
			g_size -= size;
		}
	}
	return p;
}

void myHeapFree16(void) {
}
