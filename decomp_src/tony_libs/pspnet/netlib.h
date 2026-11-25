#ifndef NETLIB_H
#define NETLIB_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned int size_t;
typedef int SceUID;
typedef unsigned int SceUInt;
typedef unsigned int SceSize;
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;
typedef unsigned long long SceUInt64;

typedef struct {
	unsigned int low;
	unsigned int hi;
} SceKernelSysClock;

/* libc (static copies inside the module) */
#define memchr func_00007B88
#define memmove func_00007BC0
#define memcmp func_00007C34
#define memcpy func_00007C74
#define memset func_00007CA8
#define bcmp func_00007CD4
#define bcopy func_00007D14
#define bzero func_00007D38
#define strcmp func_00007D60
#define index func_00007DE0
#define strrchr func_00007E10
#define strncmp func_00007E58
#define strncpy func_00007EF0
#define strchr func_00007F6C
#define strcpy func_00007F9C
#define strlen func_00007FD4
#define sprintf func_00008008
#define vsnprintf func_00008054
#define toupper func_000087A4
#define tolower func_000087D0
#define __ctype_flags func_000087FC
#define __ctype_ptr func_00008810

extern const char D_0000A0CC[];

void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
void *memcpy(void *dst, const void *src, int n);
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
int sprintf(char *buf, const char *fmt, ...);
char toupper(char c);
char tolower(char c);
char __ctype_flags(int c);
const char *__ctype_ptr(void);

/* kernel imports */
int sceKernelCpuSuspendIntr(void);
void sceKernelCpuResumeIntr(int intr);
SceUID sceKernelCreateThread(const char *name, void *entry, int prio, int stack, SceUInt attr, void *opt);
int sceKernelDeleteThread(SceUID thid);
int sceKernelStartThread(SceUID thid, SceSize arglen, void *argp);
int sceKernelTerminateThread(SceUID thid);
SceUID sceKernelGetThreadId(void);
int sceKernelDelayThread(SceUInt delay);
SceUID sceKernelCreateSema(const char *name, SceUInt attr, int init, int max, void *opt);
int sceKernelDeleteSema(SceUID semaid);
int sceKernelSignalSema(SceUID semaid, int signal);
int sceKernelWaitSema(SceUID semaid, int signal, SceUInt *timeout);
SceUID sceKernelCreateEventFlag(const char *name, int attr, int bits, void *opt);
int sceKernelDeleteEventFlag(int evid);
int sceKernelSetEventFlag(SceUID evid, u_int bits);
int sceKernelWaitEventFlag(int evid, u_int bits, u_int wait, u_int *outBits, SceUInt *timeout);
int sceKernelSysClock2USec(SceKernelSysClock *clock, int *low, int *high);
int sceKernelGetSystemTime(SceKernelSysClock *time);
SceUInt64 sceKernelGetSystemTimeWide(void);
unsigned int sceKernelGetSystemTimeLow(void);
SceUID sceKernelSetAlarm(SceUInt clock, void *handler, void *common);
int sceKernelCancelAlarm(SceUID alarmid);

/* ifhandle imports */
int sceNetIfhandle_lib_4C2886CB(void *stat);

#endif
