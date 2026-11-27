#include "common.h"

#include <stdarg.h>
int vsprintf(char *, const char *, va_list);
int printf(const char *, ...);
int fflush(void *);
void *__getreent(void);
int I3dTtyPrintf(const char *fmt, ...)
{
	char buf[0x400];
	va_list ap;
	va_start(ap, fmt);
	vsprintf(buf, fmt, ap);
	printf(buf);
	fflush(*(void **)((char *)__getreent() + 8));
	return 0;
}
