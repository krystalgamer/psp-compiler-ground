#ifndef _STDLIB_H
#define _STDLIB_H
#include <stddef.h>
void *malloc(size_t);
void free(void *);
void *memalign(size_t, size_t);
int atoi(const char *);
#endif
