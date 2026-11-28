#ifndef NETLIB_H
#define NETLIB_H

#include <stdarg.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned int size_t;
struct bpf_if;
struct bpf_d;
struct bpf_insn;
struct ifreq;
struct ifnet;
struct mbuf;
struct sockaddr;
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
void *func_00007C74(void *dst, const void *src, int n) __asm__("memcpy");
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
void _sce_pspnet_schednetintr(int isr);
void sceNetMAdj(struct mbuf *m, int len);
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
extern struct slpque { struct thread_info *tqh_first; struct thread_info **tqh_last; } slpque[128];
#define SLPQUE(wchan) (&slpque[((unsigned int)(wchan) >> 8) & 127])

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

int func_00004410(int unit, int events, struct thread_info *ti);
int func_000042AC(u_int unit);
int func_00004318(int fd);
int func_000037D4(int fd, struct uio *uio);
int func_00003940(int fd, struct uio *uio);
int func_00003B20(int unit, u_long cmd, void *addr);
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
	struct mbuf *aux;
	int unk20;
	int unk24;
	int unk28;
	int unk2C;
};

struct m_ext {
	char *ext_buf;
	void (*ext_free)(char *, unsigned int, void *);
	void *ext_arg;
	unsigned int ext_size;
	int ext_type;
	struct mbuf *ext_nextref;
	struct mbuf *ext_prevref;
};

#define MSIZE 256
#define MLEN (MSIZE - sizeof(struct m_hdr))
#define MHLEN (MLEN - sizeof(struct pkthdr))

struct mbuf {
	struct m_hdr m_hdr;
	union {
		struct {
			struct pkthdr MH_pkthdr;
			union {
				struct m_ext MH_ext;
				char MH_databuf[MHLEN];
			} MH_dat;
		} MH;
		char M_databuf[MLEN];
	} M_dat;
};

#define m_pkthdr M_dat.MH.MH_pkthdr
#define m_ext M_dat.MH.MH_dat.MH_ext
#define m_pktdat M_dat.MH.MH_dat.MH_databuf
#define m_dat M_dat.M_databuf

#define m_next m_hdr.mh_next
#define m_len m_hdr.mh_len
#define m_data m_hdr.mh_data
#define m_type m_hdr.mh_type
#define m_flags m_hdr.mh_flags
#define m_nextpkt m_hdr.mh_nextpkt
#define mtod(m, t) ((t)((m)->m_data))

struct ifevent {
	TAILQ_ENTRY(ifevent) link;
	int a;
	int b;
};

struct ifqueue {
	struct mbuf *ifq_head;
	struct mbuf *ifq_tail;
	int ifq_len;
	int ifq_maxlen;
	int ifq_drops;
};

struct sockaddr {
	u_char sa_len;
	u_char sa_family;
	char sa_data[14];
};

struct ifnet;

struct ifaddr {
	struct sockaddr *ifa_addr;
	struct sockaddr *ifa_dstaddr;
	struct sockaddr *ifa_netmask;
	struct ifnet *ifa_ifp;
	TAILQ_ENTRY(ifaddr) ifa_list;
	char unk18[0x28 - 0x18];
	void (*ifa_rtrequest)(int, void *, void *);
	int unk2C;
	int ifa_refcnt;
	int unk34;
};

struct sockaddr_dl {
	u_char sdl_len;
	u_char sdl_family;
	u_short sdl_index;
	u_char sdl_type;
	u_char sdl_nlen;
	u_char sdl_alen;
	u_char sdl_slen;
	char sdl_data[12];
};

struct if_data {
	u_char ifi_type;
	u_char ifi_addrlen;
	u_char ifi_hdrlen;
	int ifi_link_state;
	unsigned long long ifi_mtu;
	unsigned long long ifi_metric;
	unsigned long long ifi_baudrate;
	char unk58[0x80 - 0x58];
	unsigned long long ifi_ibytes;
	unsigned long long ifi_obytes;
	unsigned long long ifi_imcasts;
	char unk98[0xB0 - 0x98];
};

#define if_type if_data.ifi_type
#define if_addrlen if_data.ifi_addrlen
#define if_hdrlen if_data.ifi_hdrlen
#define if_link_state if_data.ifi_link_state
#define if_mtu if_data.ifi_mtu
#define if_metric if_data.ifi_metric
#define if_baudrate if_data.ifi_baudrate
#define if_obytes if_data.ifi_obytes
#define if_ibytes if_data.ifi_ibytes
#define if_imcasts if_data.ifi_imcasts

struct ifnet {
	void *if_softc;
	TAILQ_ENTRY(ifnet) if_list;
	TAILQ_HEAD(, ifaddr) if_addrlist;
	char if_xname[16];
	int if_pcount;
	void *if_bpf;
	u_short if_index;
	short if_timer;
	short if_flags;
	char unk32[0x38 - 0x32];
	struct if_data if_data;
	int (*if_output)(struct ifnet *, struct mbuf *, void *, void *);
	void (*if_input)(struct ifnet *, struct mbuf *);
	void (*if_start)(struct ifnet *);
	int (*if_ioctl)(struct ifnet *, u_long, void *);
	int (*if_init)(struct ifnet *);
	void (*if_watchdog)(struct ifnet *);
	void (*if_drain)(struct ifnet *);
	struct ifqueue if_snd;
	struct sockaddr_dl *if_sadl;
	void *if_unkE4;
	char unkE8[0xEC - 0xE8];
	u_char if_lladdr[6];
	char unkF2[0xF4 - 0xF2];
	int (*if_up)(struct ifnet *);
	int (*if_down)(struct ifnet *);
	int (*if_ioctl2)(struct ifnet *, int, void *);
	SceUID if_iosema;
	SceUID if_iosema2;
	int if_iopending;
	int if_iostatus;
	TAILQ_HEAD(, ifevent) if_evq;
	int if_evmask_a;
	int if_evmask_b;
	char unk120[0x128 - 0x120];
	struct ether_multi *ec_multiaddrs;
	int ec_multicnt;
};

struct ether_multi {
	u_char enm_addrlo[6];
	u_char enm_addrhi[6];
	void *enm_ec;
	int enm_refcount;
	struct ether_multi *enm_next;
	struct ether_multi **enm_prev;
};
TAILQ_HEAD(ifnet_head, ifnet);

extern int D_0000B068;
extern void (*D_0000B030)(int, void *, void *);
extern void (*D_0000B034)(void);
extern void (*D_0000B038)(struct ifnet *);
extern void (*D_0000B03C)(struct ifaddr *);
extern void (*D_0000B040)(struct ifnet *, int);
extern void (*D_0000B044)(struct ifnet *);
extern void (*D_0000B048)(struct ifnet *);
extern int (*D_0000B058)(u_long, void *, struct ifreq *, int *);
extern int (*D_0000B05C)(void *, int *);
extern int (*D_0000B060)(void *, u_long, void *, struct ifnet *);
extern struct callout if_slowtimo_ch;
int sceNetIfhandlePollSema(SceUID sema, int n);
void _sce_pspnet_callout_reset(struct callout *c, unsigned int ticks, void (*func)(void *), void *arg);
void func_00005A78(void *arg);
extern void (*D_0000B04C)(struct ifnet *);
extern void (*D_0000B050)(struct ifnet *);
extern void (*D_0000B054)(struct ifnet *);
extern int if_index;
extern struct ifaddr **ifnet_addrs;
extern struct ifnet **ifindex2ifnet;
extern struct ifnet_head ifnet;
void func_00005404(struct ifqueue *ifq);
void sceNetMFreem(struct mbuf *m);

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
void func_000044C0(struct bpf_if *bp, struct mbuf *m);
void func_00004160(struct ifnet *ifp);
void func_00006B10(struct ifnet *ifp);
void _sce_pspnet_if_detach(struct ifnet *ifp);
void _sce_pspnet_if_attach(struct ifnet *ifp);
void func_00006A40(struct ifnet *ifp, const u_char *lla);
void func_00004594(struct bpf_if **driverp, struct ifnet *ifp, u_int dlt, u_int hdrlen);
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

int _sce_pspnet_ifioctl(void *so, u_long cmd, void *data, int wait);
int func_0000610C(void *so, u_long cmd, void *data);
int func_00005614(u_long cmd, void *data);
int func_00006654(struct ifreq *ifr, struct ifnet *ec);
int func_00006844(struct ifreq *ifr, struct ifnet *ec);
int sceNetIfhandleWaitSema(SceUID sema, int n, SceUInt *timeout);
struct ifnet *_sce_pspnet_ifunit(const char *name);

struct ifreq {
	char ifr_name[16];
	union {
		struct sockaddr ifru_addr;
		short ifru_flags;
		int ifru_int;
		void *ifru_data;
		char ifru_pad[16];
	} ifr_ifru;
};

struct ifconf {
	int ifc_len;
	struct ifreq *ifc_req;
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

int _sce_pspnet_if_nulloutput(struct ifnet *ifp, struct mbuf *m, void *dst, void *rt);

static inline struct ifnet *if_find(const char *name)
{
	struct ifnet *ifp;
	int s;

	s = _sce_pspnet_spllock();
	for (ifp = ifnet.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (ifp->if_output == _sce_pspnet_if_nulloutput)
			continue;
		if (strcmp(ifp->if_xname, name) == 0) {
			_sce_pspnet_splunlock(s);
			return ifp;
		}
	}
	_sce_pspnet_splunlock(s);
	return NULL;
}

void _sce_pspnet_link_rtrequest(int cmd, void *rt, void *info);

extern int ifqmaxlen;

extern int D_0000B06C;
extern void (*D_0000B064)(void);
extern struct ifnet *D_0000BB04[8];
extern struct ifaddr *D_0000BAE4[8];
void _sce_pspnet_callout_init(struct callout *c);
void _sce_pspnet_if_down(struct ifnet *ifp);

static inline void if_slowtimo_body(void)
{
	struct ifnet *ifp;
	int s;

	s = _sce_pspnet_spllock();
	for (ifp = ifnet.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (ifp->if_timer == 0 || --ifp->if_timer)
			continue;
		if (ifp->if_watchdog)
			(*ifp->if_watchdog)(ifp);
	}
	_sce_pspnet_splunlock(s);
	_sce_pspnet_callout_reset(&if_slowtimo_ch, 100, func_00005A78, NULL);
}

struct bpf_if {
	struct bpf_if *bif_next;
	struct bpf_d *bif_dlist;
	struct bpf_if **bif_driverp;
	u_int bif_dlt;
	u_int bif_hdrlen;
	struct ifnet *bif_ifp;
};

struct bpf_d {
	struct bpf_d *bd_next;
	char *bd_sbuf;
	char *bd_hbuf;
	char *bd_fbuf;
	int bd_slen;
	int bd_hlen;
	int bd_bufsize;
	struct bpf_if *bd_bif;
	u_int bd_rtout;
	void *bd_filter;
	u_long bd_rcount;
	u_long bd_dcount;
	u_char bd_promisc;
	u_char bd_state;
	u_char bd_immediate;
	int bd_hdrcmplt;
	struct selinfo bd_sel;
	int bd_unk3C;
};

extern int bpf_bufsize;
extern struct bpf_if *bpf_iflist;
extern struct bpf_d bpf_dtab[8];
void _sce_pspnet_selrecord(struct thread_info *selector, struct selinfo *sip);


static inline u_int umin(u_int a, u_int b)
{
	return a < b ? a : b;
}

u_int func_000047EC(struct bpf_insn *pc, u_char *p, u_int wirelen, u_int buflen);
int func_00004DD8(struct mbuf *m, int k, int *err);
int func_00004EEC(struct mbuf *m, int k, int *err);
void func_000046A0(struct bpf_d *d, u_char *pkt, u_int pktlen, u_int snaplen, void *(*cpfn)(void *, const void *, u_int));
void *func_00004618(void *dst_arg, const void *src_arg, u_int len);

static inline void bpf_detachd(struct bpf_d *d)
{
	struct bpf_d **p;
	struct bpf_if *bp;

	bp = d->bd_bif;
	p = &bp->bif_dlist;
	while (*p != d)
		p = &(*p)->bd_next;
	*p = (*p)->bd_next;
	if (bp->bif_dlist == NULL)
		*bp->bif_driverp = NULL;
	d->bd_bif = NULL;
}

struct bpf_program {
	u_int bf_len;
	void *bf_insns;
};

struct bpf_hdr {
	struct timeval bh_tstamp;
	u_int bh_caplen;
	u_int bh_datalen;
	u_short bh_hdrlen;
};

int func_00004CC8(struct bpf_insn *f, int len);
void _sce_pspnet_microtime(struct timeval *tv);
void _sce_pspnet_selwakeup(struct selinfo *sip);

static inline void bpf_reset_d(struct bpf_d *d)
{
	if (d->bd_hbuf) {
		d->bd_fbuf = d->bd_hbuf;
		d->bd_hbuf = NULL;
	}
	d->bd_slen = 0;
	d->bd_hlen = 0;
	d->bd_rcount = 0;
	d->bd_dcount = 0;
}

int func_000040FC(struct bpf_d *d);
int _sce_pspnet_uiomove(char *cp, int n, struct uio *uio);

#define ROTATE_BUFFERS(d) do { \
	(d)->bd_hbuf = (d)->bd_sbuf; \
	(d)->bd_hlen = (d)->bd_slen; \
	(d)->bd_sbuf = (d)->bd_fbuf; \
	(d)->bd_slen = 0; \
	(d)->bd_fbuf = 0; \
} while (0)

extern char D_0000A0B8[];
extern char D_0000B098[];
extern int D_0000B090;
extern int D_0000B094;
extern int (*D_0000B07C)(struct ifnet *, struct mbuf *, void *, void *);
extern void *D_0000B080;
extern void *D_0000B084;
extern void *D_0000B088;
extern void *D_0000B08C;

extern u_char etherbroadcastaddr[6];
extern void *D_0000B0AC;
extern int D_0000B0B0;
void func_00006E34(struct ifnet *ifp, struct mbuf *m);
int func_000071C8(struct ifnet *ifp, struct mbuf *m, void *dst, void *rt);
int sceNetIfhandleIfStart(struct ifnet *ifp, struct mbuf *m);

struct bpf_insn {
	u_short code;
	u_char jt;
	u_char jf;
	int k;
};

#define EXTRACT_SHORT(p) ((u_short)((u_short)*((u_char *)p + 0) << 8 | (u_short)*((u_char *)p + 1) << 0))
#define EXTRACT_LONG(p) \
	((u_int)*((u_char *)p + 0) << 24 | (u_int)*((u_char *)p + 1) << 16 | \
	 (u_int)*((u_char *)p + 2) << 8 | (u_int)*((u_char *)p + 3) << 0)

#define MINDEX(len, m, k) \
{ \
	len = m->m_len; \
	while (k >= len) { \
		k -= len; \
		m = m->m_next; \
		if (m == 0) \
			return 0; \
		len = m->m_len; \
	} \
}

struct bpf_stat {
	u_int bs_recv;
	u_int bs_drop;
};

struct bpf_version {
	u_short bv_major;
	u_short bv_minor;
};

int func_00003E80(struct bpf_d *d, struct bpf_program *fp);
int func_00003FA4(struct bpf_d *d, struct ifreq *ifr);

static inline int ether_multiaddr_i(struct sockaddr *sa, u_char *addrlo, u_char *addrhi)
{
	int handled;
	int ret;

	if (D_0000B090 > 0) {
		handled = 0;
		ret = ((int (*)(struct sockaddr *, u_char *, u_char *, int *))D_0000B088)(sa, addrlo, addrhi, &handled);
		if (handled > 0)
			return ret;
	}
	if (sa->sa_family != 0)
		return 0x6A;
	bcopy(sa->sa_data, addrlo, 6);
	bcopy(addrlo, addrhi, 6);
	return 0;
}

#define ETHER_LOOKUP_MULTI(addrlo, addrhi, ec, enm) \
{ \
	for ((enm) = (ec)->ec_multiaddrs; \
	    (enm) != NULL && \
	    (bcmp((enm)->enm_addrlo, (addrlo), 6) != 0 || \
	     bcmp((enm)->enm_addrhi, (addrhi), 6) != 0); \
		(enm) = (enm)->enm_next); \
}

#endif
