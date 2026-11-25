#ifndef ADHOC_H
#define ADHOC_H

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef int SceUID;
typedef unsigned long long SceUInt64;

/* libc (static copies inside the module, libc_mem.c) */
#define memchr func_00006D6C
#define memmove func_00006DA4
#define memcmp func_00006E18
#define memcpy func_00006E58
#define memset func_00006E8C
#define bcmp func_00006EB8
#define bcopy func_00006EF8
#define bzero func_00006F1C

void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
void *memcpy(void *dst, const void *src, int n);
void *memset(void *dst, int c, int n);
int bcmp(const void *a, const void *b, int n);
void bcopy(const void *src, void *dst, int n);
void bzero(void *p, int n);

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
	void *c_link[4];
	void (*c_func)(void *);
	void *c_arg;
	unsigned int c_time;
	int c_flags;
	SceUID c_alarm;
};

struct thread_info {
	void *link[2];
	SceUID thid;
	short refcnt;
	int error;
	int unk14;
	void *slpq[2];
	void *wchan;
	struct callout co;
	int slpflags;
	SceUID sema;
	short semacnt;
	char unk52[0x58 - 0x52];
	struct adhoc_socket *polllist;
	int unk5C;
	struct thread_info *pollnext;
};

struct mbuf;

struct m_hdr {
	struct mbuf *mh_next;
	struct mbuf *mh_nextpkt;
	char *mh_data;
	int mh_len;
	short mh_type;
	u_short mh_flags;
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

struct ifqueue {
	struct mbuf *ifq_head;
	struct mbuf *ifq_tail;
	int ifq_len;
	int ifq_maxlen;
	int ifq_drops;
};

#define IF_QFULL(ifq) ((ifq)->ifq_len >= (ifq)->ifq_maxlen)
#define IF_DROP(ifq) ((ifq)->ifq_drops++)
#define IF_ENQUEUE(ifq, m) do { \
	(m)->m_nextpkt = 0; \
	if ((ifq)->ifq_tail == 0) \
		(ifq)->ifq_head = m; \
	else \
		(ifq)->ifq_tail->m_nextpkt = m; \
	(ifq)->ifq_tail = m; \
	(ifq)->ifq_len++; \
} while (0)
#define IF_DEQUEUE(ifq, m) do { \
	(m) = (ifq)->ifq_head; \
	if (m) { \
		if (((ifq)->ifq_head = (m)->m_nextpkt) == 0) \
			(ifq)->ifq_tail = 0; \
		(m)->m_nextpkt = 0; \
		(ifq)->ifq_len--; \
	} \
} while (0)

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
#define LLADDR(s) ((char *)((s)->sdl_data + (s)->sdl_nlen))

struct ifnet {
	void *if_softc;
	void *if_list[2];
	void *if_addrlist[2];
	char if_xname[16];
	int if_pcount;
	void *if_bpf;
	u_short if_index;
	short if_timer;
	u_short if_flags;
	char unk32[0x38 - 0x32];
	u_char if_type;
	u_char if_addrlen;
	u_char if_hdrlen;
	int if_link_state;
	char unk40[0x88 - 0x40];
	unsigned long long if_obytes;
	char unk90[0xB0 - 0x90];
	int (*if_output)(struct ifnet *, struct mbuf *, void *, void *);
	void (*if_input)(struct ifnet *, struct mbuf *);
	void (*if_start)(struct ifnet *);
	int (*if_ioctl)(struct ifnet *, u_int, void *);
	int (*if_init)(struct ifnet *);
	void (*if_watchdog)(struct ifnet *);
	void (*if_drain)(struct ifnet *);
	struct ifqueue if_snd;
	struct sockaddr_dl *if_sadl;
};
#define IFF_OACTIVE 0x400

struct SceNetEtherAddr {
	u_char data[6];
};

struct SceNetAdhocPollSd {
	int id;
	int events;
	int revents;
};

struct pollent {
	struct adhoc_socket *so;
	struct SceNetAdhocPollSd *sd;
};

/* adhoc socket descriptor (socket.c) */
struct adhoc_socket {
	TAILQ_ENTRY(adhoc_socket) link;
	int id;
	int flags;
	u_char type;
	char pad11[3];
	void *pcb;
	void *wchan_send;
	void *wchan_recv;
	void *wchan_poll;
	struct thread_info *pollq;
	struct adhoc_socket *pollnext;
};
TAILQ_HEAD(adhoc_socket_list, adhoc_socket);

/* imports */
int sceKernelSignalSema(SceUID semaid, int signal);
SceUInt64 sceKernelGetSystemTimeWide(void);
void *sceNetMallocInternal(unsigned int size);
void sceNetFreeInternal(void *p);
void sceNetMAdj(struct mbuf *m, int len);
void sceNetMCat(struct mbuf *m, struct mbuf *n);
void sceNetMCopydata(struct mbuf *m, int off, int len, void *cp);
struct mbuf *sceNetMFree(struct mbuf *m);
void sceNetMFreem(struct mbuf *m);
struct mbuf *sceNetMPullup(struct mbuf *m, int len);
int sceNetGetLocalEtherAddr(struct SceNetEtherAddr *addr);
unsigned int sceNetRand(void);
int sceWlanDevIsGameMode(void);
int sceWlanGPPrevEstablishActive(void *a, void *b);
int sceWlanGPSend(void *a, void *b, int c);
int sceWlanGPRecv(void *a, void *b, int c);
void _sce_pspnet_callout_init(struct callout *c);
void _sce_pspnet_callout_reset_usec(struct callout *c, unsigned int usec, void (*func)(void *), void *arg);
void _sce_pspnet_callout_stop(struct callout *c);
int _sce_pspnet_adhoc_sabort(struct adhoc_socket *so, int flag);
int _sce_pspnet_tsleep_usec(void *wchan, unsigned int usec);
void _sce_pspnet_wakeup(void *wchan);
struct thread_info *_sce_pspnet_thread_enter(void);
int _sce_pspnet_thread_leave(struct thread_info *ti, int error);
int _sce_pspnet_spllock(void);
void _sce_pspnet_splunlock(int s);
void _sce_pspnet_schednetintr_with_evf(int n);
struct ifnet *_sce_pspnet_ifplookup_lladdr(const void *addr);
int _sce_pspnet_start_of_adhoc_module_in_sched(void (*func)(struct adhoc_socket *, int));
void _sce_pspnet_stop_of_adhoc_module_in_sched(void);
int _sce_pspnet_start_of_adhoc_module_in_if_ethersubr_core(int (*func)(struct ifnet *, struct mbuf *, struct ifqueue **));
void _sce_pspnet_stop_of_adhoc_module_in_if_ethersubr_core(void);
int _sce_pspnet_start_of_adhoc_module_in_netintr(void (*intr)(void), void (*drain)(void *));
void _sce_pspnet_stop_of_adhoc_module_in_netintr(void);

/* globals */
extern int D_00007400;
extern struct ifqueue D_00007404;
extern struct adhoc_socket_list D_00007418;
extern int D_00007420;
extern int D_00007448;

/* adhoc.c */
void func_00000224(void);
void func_00000320(struct ifnet *ifp, struct mbuf *m);
int func_00000430(struct ifnet *ifp, struct mbuf *m, struct ifqueue **inq);
void func_00000444(void *arg);

/* socket.c */
int func_00000D3C(void);
void func_00000D84(void);
struct adhoc_socket *func_00000DFC(int type, int id);
int func_00000E44(void);
int func_00000ED0(u_char type, struct adhoc_socket **sop);
void func_00000F74(struct adhoc_socket *so);
int func_00000FBC(void);
void func_00000FF0(struct adhoc_socket *so, int events);

int func_0000092C(struct pollent *pe, int n);

/* pdp.c */
void func_00002B38(struct adhoc_socket *so);
int func_00002C00(struct adhoc_socket *so, int events);
int func_000029AC(void);
void func_00002A18(void);
void func_000023C4(struct mbuf *m);
void func_00002B90(void *pcb);

/* ptp.c */
void func_0000483C(void);
void func_00004B18(struct adhoc_socket *so);
int func_000050F8(struct adhoc_socket *so, int events);
int func_00005374(void);

/* gamemode.c */
int func_00006880(void);
void func_00006898(void);

void func_0000578C(struct mbuf *m);

#endif
