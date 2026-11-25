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

#define TAILQ_HEAD(name, type) struct name { struct type *tqh_first; struct type **tqh_last; }
#define TAILQ_ENTRY(type) struct { struct type *tqe_next; struct type **tqe_prev; }
#define TAILQ_FIRST(head) ((head)->tqh_first)
#define TAILQ_NEXT(elm, field) ((elm)->field.tqe_next)
#define TAILQ_INIT(head) do { \
	(head)->tqh_first = NULL; \
	(head)->tqh_last = &(head)->tqh_first; \
} while (0)
#define TAILQ_INSERT_TAIL(head, elm, field) do { \
	(elm)->field.tqe_next = NULL; \
	(elm)->field.tqe_prev = (head)->tqh_last; \
	*(head)->tqh_last = (elm); \
	(head)->tqh_last = &(elm)->field.tqe_next; \
} while (0)
#define TAILQ_REMOVE(head, elm, field) do { \
	if (((elm)->field.tqe_next) != NULL) \
		(elm)->field.tqe_next->field.tqe_prev = (elm)->field.tqe_prev; \
	else \
		(head)->tqh_last = (elm)->field.tqe_prev; \
	*(elm)->field.tqe_prev = (elm)->field.tqe_next; \
} while (0)

struct callout {
	TAILQ_ENTRY(callout) c_fired;
	TAILQ_ENTRY(callout) c_pending;
	void (*c_func)(void *);
	void *c_arg;
	unsigned int c_time;
	int c_flags;
	SceUID c_alarm;
};
TAILQ_HEAD(callout_list, callout);

extern int D_0000A098;
extern int D_0000A09C;
extern struct callout_list D_0000AC08;
extern struct callout_list D_0000AC10;

int _sce_pspnet_spllock(void);
void _sce_pspnet_splunlock(int s);
void _sce_pspnet_callout_stop(struct callout *c);

/* per-thread info (thread.c) */
struct thread_info {
	TAILQ_ENTRY(thread_info) link;
	SceUID thid;
	short refcnt;
	int error;
	int unk14[4];
	struct callout co;
	int unk48;
	SceUID sema;
	short semacnt;
	char unk52[0x64 - 0x52];
};
TAILQ_HEAD(thread_list, thread_info);

extern int D_0000A094;
extern struct thread_list D_0000AC00;

void *sceNetMallocInternal(unsigned int size);
void sceNetFreeInternal(void *p);

struct thread_info *_sce_pspnet_thread_enter(void);
int _sce_pspnet_thread_leave(struct thread_info *ti, int error);
void _sce_pspnet_callout_cleanup(struct callout *c);
int _sce_pspnet_tabort(struct thread_info *ti);

static inline struct thread_info *threadinfo_lock(SceUID thid)
{
	struct thread_info *ti;

	sceKernelWaitSema(D_0000A094, 1, 0);
	for (ti = D_0000AC00.tqh_first; ti != NULL; ti = ti->link.tqe_next) {
		if (ti->thid == thid)
			break;
	}
	if (ti != NULL)
		ti->refcnt++;
	sceKernelSignalSema(D_0000A094, 1);
	return ti;
}

static inline void threadinfo_unlock(struct thread_info *ti)
{
	sceKernelWaitSema(D_0000A094, 1, 0);
	ti->refcnt--;
	sceKernelSignalSema(D_0000A094, 1);
}

static inline int thread_leave(struct thread_info *ti, int error)
{
	sceKernelWaitSema(D_0000A094, 1, 0);
	ti->error = error;
	ti->refcnt--;
	if (--ti->semacnt == 0)
		sceKernelDeleteSema(ti->sema);
	sceKernelSignalSema(D_0000A094, 1);
	return error ? -1 : 0;
}

#endif
