#ifndef NETLIB_H
#define NETLIB_H

#include <stdarg.h>

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
void _sce_pspnet_callout_reset_usec(struct callout *c, unsigned int usec, void (*func)(void *), void *arg);
struct thread_info *_sce_pspnet_get_threadinfo(SceUID thid);
int sceNet_lib_6DC71518(void);
void func_000030A8(void *arg);
void _sce_pspnet_tiwakeup(SceUID thid, void *wchan);
int _sce_pspnet_tsleep_usec(void *wchan, unsigned int usec);
int _sce_pspnet_tsleep(void *wchan, unsigned int ticks);
void _sce_pspnet_wakeup(void *wchan);

extern int D_0000A0A4;
extern int D_0000B02C;

extern int D_0000A0A0;
extern void (*D_0000AC18)(struct thread_info *);
extern void (*D_0000AC1C)(void *, void *);
extern void (*D_0000AC20)(void *);
extern int D_0000AC24;
extern int D_0000AC28;
extern struct slpque { struct thread_info *tqh_first; struct thread_info **tqh_last; } D_0000AC2C[128];
#define SLPQUE(wchan) (&D_0000AC2C[((unsigned int)(wchan) >> 8) & 127])

/* per-thread info (thread.c) */
struct thread_info {
	TAILQ_ENTRY(thread_info) link;
	SceUID thid;
	short refcnt;
	int error;
	int unk14;
	TAILQ_ENTRY(thread_info) slpq;
	void *wchan;
	struct callout co;
	int slpflags;
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

struct timeval {
	long tv_sec;
	long tv_usec;
};

struct iovec {
	char *iov_base;
	unsigned int iov_len;
};

struct uio {
	struct iovec *uio_iov;
	int uio_iovcnt;
	long uio_offset;
	int uio_resid;
	int uio_rw;
	int uio_unk14;
	int uio_unk18;
	int uio_unk1C;
};

struct selinfo {
	SceUID si_pid;
};

extern int D_0000B8DC;

int func_00004410(void *fds, int nfds, struct thread_info *ti);
int func_000042AC(int unit);
int func_00004318(int fd);
int func_000037D4(int fd, struct uio *uio);
int func_00003940(int fd, struct uio *uio);
int func_00003B20(int fd, unsigned int cmd, void *data);
extern int D_0000B8DC;

struct mbuf;

struct m_hdr {
	struct mbuf *mh_next;
	struct mbuf *mh_nextpkt;
	char *mh_data;
	int mh_len;
	short mh_type;
	short mh_flags;
};

struct pkthdr {
	struct ifnet *rcvif;
	int len;
};

struct mbuf {
	struct m_hdr m_hdr;
	struct pkthdr m_pkthdr;
};

#define m_next m_hdr.mh_next
#define m_len m_hdr.mh_len
#define m_data m_hdr.mh_data
#define m_type m_hdr.mh_type
#define m_flags m_hdr.mh_flags
#define m_nextpkt m_hdr.mh_nextpkt

struct ifevent {
	TAILQ_ENTRY(ifevent) link;
};

struct ifnet {
	void *if_softc;
	char unk04[0x14 - 0x04];
	char if_xname[16];
	int if_pcount;
	void *if_bpf;
	u_short if_index;
	short if_timer;
	short if_flags;
	char unk32[0xB4 - 0x32];
	void (*if_input)(struct ifnet *, struct mbuf *);
	void (*if_start)(struct ifnet *);
	int (*if_ioctl)(struct ifnet *, u_long, void *);
	char unkC0[0xE0 - 0xC0];
	void *if_sadl;
	char unkE4[0xEC - 0xE4];
	u_char if_lladdr[6];
	char unkF2[0xF4 - 0xF2];
	int (*if_up)(struct ifnet *);
	int (*if_down)(struct ifnet *);
	int (*if_ioctl2)(struct ifnet *, int, void *);
	char unk100[0x110 - 0x100];
	TAILQ_HEAD(, ifevent) if_evq;
};

extern int D_0000A090;
extern int D_0000ABD0;
extern int D_0000ABD4;
extern int D_0000ABD8;
extern int D_0000ABDC;
extern void (*D_0000ABE0)(void);
extern void (*D_0000ABE4)(void);
extern void (*D_0000ABE8)(void);
extern void (*D_0000ABEC)(void);
extern void (*D_0000ABF0)(void);
extern void (*D_0000ABF4)(struct ifnet *);
extern u_int D_0000ABF8;
extern SceUID D_0000ABFC;

int sceNetIfhandle_lib_B8188F96(struct ifnet **ifp, SceUID *sema);
int sceNetIfhandle_lib_4FB43BCE(struct ifnet **ifp, SceUID *sema);
struct mbuf *sceNetIfhandleIfDequeue(void);
int sceNetIfhandleSignalSema(SceUID sema, int n);
int sceNetIfhandleIfUp(struct ifnet *ifp);
int sceNetIfhandleIfDown(struct ifnet *ifp);
int sceNetIfhandleIfIoctl(struct ifnet *ifp, int cmd, void *data);
int sceNetIfhandleInit(SceUID evf);
int sceNetIfhandleTerm(void);
void func_000044C0(void *bpf, struct mbuf *m);
void func_00004160(struct ifnet *ifp);
void func_00006B10(struct ifnet *ifp);
void _sce_pspnet_if_detach(struct ifnet *ifp);
void _sce_pspnet_if_attach(struct ifnet *ifp);
void func_00006A40(struct ifnet *ifp, u_char *lla);
void func_00004594(void **bpf, struct ifnet *ifp, int dlt, int hdrlen);
void func_00007680(struct ifnet *ifp);
int func_000071FC(struct ifnet *ifp, u_long cmd, void *data);
int func_000016BC(SceSize args, void *argp);


extern unsigned int D_0000B0B4[521];
extern int D_0000B8D8;

static inline void rnd521_refresh(void)
{
	int i;

	for (i = 0; i < 32; i++)
		D_0000B0B4[i] ^= D_0000B0B4[i + 489];
	for (i = 32; i < 521; i++)
		D_0000B0B4[i] ^= D_0000B0B4[i - 32];
}

int sceNetIfhandle_lib_0C391E9F(int poolsize);
int sceNetIfhandle_lib_29ED84C5(void);
void sceNetIfhandle_lib_0FB8AE0D(void);
void func_00007798(unsigned int seed);
int func_00007738(int poolsize);
int func_00007778(void);
int func_00001A00(int prio, int stack);
void func_00001B7C(void);
int func_00001F0C(void);
void func_00002300(void);
int func_00002B34(int prio, int stack);
void func_000028D0(void);
int func_00002FC4(void);
void func_00003028(void);
int func_00003438(void);
void func_0000348C(void);
void func_000057D8(void);
void func_0000426C(int n);

void func_0000877C(char **pp, int c);
int func_00008054(void (*put)(char **, int), char **arg, const char *fmt, va_list ap);

int _sce_pspnet_ifioctl(void *so, u_long cmd, void *data, void *p);
struct ifnet *_sce_pspnet_ifunit(const char *name);

struct ifreq {
	char ifr_name[16];
	union {
		short ifru_flags;
		int ifru_int;
		void *ifru_data;
		char ifru_pad[16];
	} ifr_ifru;
};

struct ifreq_1 {
	char name[16];
	int v0;
};

struct ifreq_2 {
	char name[16];
	int v0;
	int v1;
};

struct ifreq_3 {
	char name[16];
	int v0;
	int v1;
	int v2;
};

struct ifreq_4 {
	char name[16];
	int v0;
	int v1;
	int v2;
	int v3;
};

struct ifevreq {
	int a;
	int b;
};

struct ifinfo_req {
	char name[16];
	u_char a;
	u_char b;
	u_short c;
	u_short d;
	u_char e;
};

#endif
