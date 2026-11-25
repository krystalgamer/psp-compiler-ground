#ifndef MPEG_H
#define MPEG_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned int size_t;

extern const char D_00007B20[];
#define _CTYPE(c) ((D_00007B20 + 1)[(int)(c)])

#define abs func_000071CC
#define toupper func_000071E0
#define tolower func_0000720C
#define __ctype_flags func_00007238
#define __ctype_ptr func_0000724C
#define memchr func_0000647C
#define memmove func_000064B4
#define memcmp func_00006528
#define memcpy func_00006568
#define memset func_0000659C
#define bcmp func_000065C8
#define bcopy func_00006608
#define bzero func_0000662C
#define strcat func_00006654
#define strchr func_000066F4
#define strcmp func_00006724
#define strcasecmp func_000067A4
#define strcspn func_0000684C
#define index func_000068B8
#define strrchr func_000068E8
#define strlen func_00006930
#define strncat func_00006964
#define strncmp func_000069CC
#define strncasecmp func_00006A64
#define strncpy func_00006B28
#define strpbrk func_00006BA4
#define rindex func_00006BFC
#define strspn func_00006C44
#define strstr func_00006CB0
#define strtok_r func_00006D14
#define strtol func_00006DE8
#define strtoul func_00006FB8
#define strcpy func_00007140
#define strtok func_00007178

/* libc */
int abs(int x);
char toupper(char c);
char tolower(char c);
char __ctype_flags(int c);
const char *__ctype_ptr(void);
void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
void *memcpy(void *dst, const void *src, int n);
void *memset(void *dst, int c, int n);
int bcmp(const void *a, const void *b, int n);
void bcopy(const void *src, void *dst, int n);
void bzero(void *p, int n);
char *strcat(char *dst, const char *src);
char *strchr(const char *s, char c);
int strcmp(const char *s1, const char *s2);
int strcasecmp(const char *s1, const char *s2);
int strcspn(const char *s, const char *reject);
char *index(const char *s, char c);
char *strrchr(const char *s, char c);
int strlen(const char *s);
char *strncat(char *dst, const char *src, int n);
int strncmp(const char *s1, const char *s2, int n);
int strncasecmp(const char *s1, const char *s2, int n);
char *strncpy(char *dst, const char *src, int n);
char *strpbrk(const char *s, const char *accept);
char *rindex(const char *s, char c);
int strspn(const char *s, const char *accept);
char *strstr(const char *s, const char *find);
char *strtok_r(char *s, const char *delim, char **last);
long strtol(const char *s, char **endptr, int base);
unsigned long strtoul(const char *s, char **endptr, int base);
char *strcpy(char *dst, const char *src);
char *strtok(char *s, const char *delim);


#endif
