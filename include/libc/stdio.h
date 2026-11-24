#ifndef _STDIO_H
#define _STDIO_H
#include <stddef.h>
typedef struct __sFILE FILE;
int printf(const char *, ...);
int sprintf(char *, const char *, ...);
int puts(const char *);
#endif
