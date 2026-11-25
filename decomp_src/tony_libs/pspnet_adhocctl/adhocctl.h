#ifndef ADHOCCTL_H
#define ADHOCCTL_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef int SceUID;
typedef unsigned int SceUInt;
typedef unsigned int SceSize;
typedef unsigned long long SceUInt64;

/* libc (static copies inside the module) */
#define toupper func_00004D64
#define tolower func_00004D90
#define __ctype_flags func_00004DBC
#define __ctype_ptr func_00004DD0
#define memchr func_00004DDC
#define memmove func_00004E14
#define memcmp func_00004E88
#define memset func_00004EFC
#define bcmp func_00004F28
#define bcopy func_00004F68
#define bzero func_00004F8C
#define strcmp func_00004FB4
#define index func_00005034
#define strrchr func_00005064
#define strncmp func_000050AC
#define strncpy func_00005144
#define strchr func_000051C0
#define strcpy func_000051F0
#define strlen func_00005228

extern const char D_00006810[];
#define _ctype_ D_00006810
#define _U 01
#define _L 02
#define _N 04
#define isalnum(c) ((_ctype_ + 1)[(unsigned char)(c)] & (_U | _L | _N))

void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
void *func_00004EC8(void *dst, const void *src, int n) __asm__("memcpy");
#define memcpy __builtin_memcpy
void *memset(void *dst, int c, int n);
int bcmp(const void *a, const void *b, int n);
void bcopy(const void *src, void *dst, int n);
void bzero(void *p, int n);
int strcmp(const char *s1, const char *s2);
char *index(const char *s, char c);
char *strchr(const char *s, char c);
int strncmp(const char *s1, const char *s2, int n);
char *strncpy(char *dst, const char *src, int n);
char *strrchr(const char *s, char c);
char *strcpy(char *dst, const char *src);
int strlen(const char *s);
char toupper(char c);
char tolower(char c);
char __ctype_flags(int c);
const char *__ctype_ptr(void);

#endif
