/* lang: c++ */
/* cflags: -Os -fno-strength-reduce -fno-exceptions */
#include "common.h"

extern "C" void *_memAllocMBL(unsigned int size, const char *file, int line);
extern "C" void _memFree(void *p, const char *file, int line);

void *operator new(unsigned int size)
{
	return _memAllocMBL(size, "src/bx/new.cc", 22);
}

void *operator new[](unsigned int size)
{
	return _memAllocMBL(size, "src/bx/new.cc", 31);
}

void operator delete(void *p)
{
	_memFree(p, "src/bx/new.cc", 40);
}

void operator delete[](void *p)
{
	_memFree(p, "src/bx/new.cc", 49);
}
