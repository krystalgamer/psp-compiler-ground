#ifndef _STDIO_H
#define _STDIO_H
#include <stddef.h>
typedef struct __sFILE FILE;
#include <sys/reent.h>
extern struct _reent *_impure_ptr;
#define stdin	(_impure_ptr->_stdin)
#define stdout	(_impure_ptr->_stdout)
#define stderr	(_impure_ptr->_stderr)
int fprintf(FILE *, const char *, ...);
int printf(const char *, ...);
int sprintf(char *, const char *, ...);
int puts(const char *);
int putchar(int);
#include <stdarg.h>
int vsprintf(char *, const char *, __gnuc_va_list);
#endif
