#ifndef _STDIO_H
#define _STDIO_H
#include <stddef.h>
typedef struct __sFILE FILE;
/* newlib: only the head of struct _reent is needed */
struct _reent {
	int _errno;
	FILE *_stdin, *_stdout, *_stderr;
};
extern struct _reent *_impure_ptr;
#define stdin	(_impure_ptr->_stdin)
#define stdout	(_impure_ptr->_stdout)
#define stderr	(_impure_ptr->_stderr)
int fprintf(FILE *, const char *, ...);
int printf(const char *, ...);
int sprintf(char *, const char *, ...);
int puts(const char *);
#include <stdarg.h>
int vsprintf(char *, const char *, __gnuc_va_list);
#endif
