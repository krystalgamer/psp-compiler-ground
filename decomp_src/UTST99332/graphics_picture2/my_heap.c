#include "common.h"

#include "common.h"
#include "common.h"
extern char *g_addr;
extern unsigned int g_size;
void myHeapInit(void *addr, unsigned int size)
{
	g_addr = addr;
	g_size = size;
}

void myHeapTerm(void)
{
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
	char *p;
	unsigned int pad;

	if (size == 0)
		return NULL;
	p = g_addr;
	pad = (16 - ((unsigned int)p & 15)) & 15;
	size = size + pad;
	if (g_size < size)
		return NULL;
	g_addr = p + size;
	g_size = g_size - size;
	return p + pad;
}

void myHeapFree16(void) {
}
