/* cflags: -O2 */
#include "common.h"
#include "m2c_macros.h"
extern int g_addr;
extern unsigned int g_size;
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

void *myHeapAlloc( unsigned int size )
{
	if ( size == 0 ) return 0 ;
	if ( g_size < size ) return 0 ;
	int addr = (int)g_addr ;
	g_addr = ( addr + size ) ;
	g_size -= size ;
	myHeap_freesize = g_size;
	myHeap_size += size;
	return (void *)( addr ) ;
}

void myHeapFree(void) {
}

void *myHeapAlloc16( unsigned int size )
{
	if ( size == 0 ) return 0 ;
	int addr = (int)g_addr ;
	int pad = 15 & ( 16 - ( 15 & addr ) ) ;
	size += pad ;
	if ( g_size < size ) return 0 ;
	g_addr = ( addr + size ) ;
	g_size -= size ;
	myHeap_freesize = g_size;
	myHeap_size += size;
	return (void *)( addr + pad ) ;
}

void myHeapFree16(void) {
}
