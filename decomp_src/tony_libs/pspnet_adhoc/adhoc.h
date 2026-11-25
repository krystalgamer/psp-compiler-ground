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
#define bcmp func_00006EB8
#define bcopy func_00006EF8
#define bzero func_00006F1C

void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
/* memcpy/memset keep their real names: gcc expands them as builtins */
void *func_00006E58(void *dst, const void *src, int n) __asm__("memcpy");
void *func_00006E8C(void *dst, int c, int n) __asm__("memset");
void *memcpy(void *dst, const void *src, unsigned int n);
void *memset(void *dst, int c, unsigned int n);
int bcmp(const void *a, const void *b, int n);
void bcopy(const void *src, void *dst, int n);
void bzero(void *p, int n);

extern int D_00007448;

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
	void *polllist;
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
	short unk20;
	short unk22;
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
#define MGETHDR(m, how, type) do { \
	(m) = sceNetMallocInternal(MSIZE); \
	if (m) { \
		(m)->m_type = (type); \
		(m)->m_next = 0; \
		(m)->m_nextpkt = 0; \
		(m)->m_data = (m)->m_pktdat; \
		(m)->m_flags = 2; \
		(m)->m_pkthdr.aux = 0; \
	} \
} while (0)
#define M_DONTWAIT 1
#define MCLGET(m, how) do { \
	(m)->m_ext.ext_buf = sceNetMallocInternal(MCLBYTES); \
	if ((m)->m_ext.ext_buf == 0) \
		(m)->m_ext.ext_buf = sceNetMallocInternal(MCLBYTES); \
	if ((m)->m_ext.ext_buf != 0) { \
		(m)->m_data = (m)->m_ext.ext_buf; \
		(m)->m_flags |= M_EXT | M_CLUSTER; \
		(m)->m_ext.ext_size = MCLBYTES; \
		(m)->m_ext.ext_free = 0; \
		(m)->m_ext.ext_arg = 0; \
		(m)->m_ext.ext_nextref = (m)->m_ext.ext_prevref = (m); \
	} \
} while (0)
#define MCLBYTES 2048
#define M_EXT 0x0001
#define M_CLUSTER 0x0008
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
	char unkE4[0x120 - 0xE4];
	int if_adhocflags;
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

#define ntohs(x) ((u_short)__builtin_allegrex_wsbh(x))
#define htons(x) ((u_short)__builtin_allegrex_wsbh(x))
#define ntohl(x) ((u_int)__builtin_allegrex_wsbw(x))
#define htonl(x) ((u_int)__builtin_allegrex_wsbw(x))

#define POLL_LINK(so, ti) do { \
	(so)->pollnext = (ti)->polllist; \
	(ti)->polllist = (so); \
	(ti)->pollnext = (so)->pollq; \
	(so)->pollq = (ti); \
} while (0)

#define POLL_UNLINK(so, ti) do { \
	struct adhoc_socket *_q; \
	struct thread_info *_t; \
	if ((struct adhoc_socket *)(ti)->polllist == (so)) { \
		(ti)->polllist = (so)->pollnext; \
	} else { \
		for (_q = (ti)->polllist; _q->pollnext != (so); _q = _q->pollnext) \
			; \
		_q->pollnext = _q->pollnext->pollnext; \
	} \
	if ((so)->pollq == (ti)) { \
		(so)->pollq = (ti)->pollnext; \
	} else { \
		for (_t = (so)->pollq; _t->pollnext != (ti); _t = _t->pollnext) \
			; \
		_t->pollnext = _t->pollnext->pollnext; \
	} \
} while (0)

struct sockbuf {
	struct mbuf *sb_head;
	struct mbuf *sb_tail;
	u_int sb_cc;
	u_int sb_hiwat;
	u_int sb_lowat;
	int sb_flags;
};

/* ptp.c */
struct ptpcb {
	TAILQ_ENTRY(ptpcb) link;
	TAILQ_ENTRY(ptpcb) clink;
	TAILQ_HEAD(, ptpcb) children;
	struct ifnet *ifp;
	struct SceNetEtherAddr laddr;
	struct SceNetEtherAddr faddr;
	u_short lport;
	u_short fport;
	struct sockbuf snd;
	struct sockbuf rcv;
	struct adhoc_socket *so;
	int state;
	int unk64;
	int mss;
	u_int iss;
	int unk70;
	u_int snd_una;
	u_int snd_nxt;
	u_int rcv_nxt;
	int snd_wnd;
	int snd_inflight;
	struct callout co;
	u_int rexmt_int;
	int rexmt_cnt;
	int rexmt_left;
	int nchildren;
	int backlog;
	struct ptpcb *parent;
};
TAILQ_HEAD(ptpcb_list, ptpcb);

struct SceNetAdhocPtpStat {
	struct SceNetAdhocPtpStat *next;
	int id;
	struct SceNetEtherAddr laddr;
	struct SceNetEtherAddr paddr;
	u_short lport;
	u_short pport;
	unsigned int snd_sb_cc;
	unsigned int rcv_sb_cc;
	int state;
};

extern struct ptpcb_list D_00007430;

struct ptpstat {
	int unk0;
	int unk4;
	int unk8;
	int unkC;
	int unk10;
	int unk14;
	int unk18;
	int unk1C;
	int unk20;
	int unk24;
	int unk28;
	int unk2C;
};
extern struct ptpstat D_00007450;
extern u_short D_00007438;
extern u_int D_0000743C;

void _sce_pspnet_wakeup(void *wchan);

static inline u_short ptp_newport(struct SceNetEtherAddr *addr)
{
	struct ptpcb *p;
	u_short port;

	port = (D_00007438 == 0x7FFF) ? 0x4000 : D_00007438 + 1;
	while (port != D_00007438) {
		for (p = D_00007430.tqh_first; p != NULL; p = p->link.tqe_next) {
			if (memcmp(&p->laddr, addr, 6) == 0 && p->lport == port)
				break;
		}
		if (p == NULL) {
			D_00007438 = port;
			return port;
		}
		port = (port == 0x7FFF) ? 0x4000 : port + 1;
	}
	return 0;
}

#define SBWAKEUP(sb) do { \
	if ((sb).sb_flags & 1) { \
		(sb).sb_flags &= ~1; \
		_sce_pspnet_wakeup(&(sb)); \
	} \
	if ((sb).sb_flags & 2) { \
		(sb).sb_flags &= ~2; \
		_sce_pspnet_wakeup(&D_00007448); \
	} \
} while (0)

/* pdp.c */
struct pdpcb;

struct pdp_frag {
	TAILQ_ENTRY(pdp_frag) link;
	u_short len;
	u_short pad;
	struct mbuf *m;
	struct callout co;
	struct pdpcb *pcb;
};

struct pdpcb {
	TAILQ_ENTRY(pdpcb) link;
	struct ifnet *ifp;
	struct SceNetEtherAddr laddr;
	u_short lport;
	struct mbuf *rcv_head;
	struct mbuf *rcv_tail;
	u_int rcv_cc;
	u_int rcv_hiwat;
	int unk24;
	int flags;
	struct adhoc_socket *so;
	TAILQ_HEAD(, pdp_frag) fragq;
};
TAILQ_HEAD(pdpcb_list, pdpcb);

struct SceNetAdhocPdpStat {
	struct SceNetAdhocPdpStat *next;
	int id;
	struct SceNetEtherAddr laddr;
	u_short lport;
	unsigned int rcv_sb_cc;
};

extern struct pdpcb_list D_00007424;
extern u_short D_0000742C;
extern u_short D_0000744C;
extern const u_short D_0000733C;
extern const u_short D_00007340;
extern const struct SceNetEtherAddr D_00007344;
extern const struct SceNetEtherAddr D_0000734C;

static inline u_short pdp_newport(struct SceNetEtherAddr *addr)
{
	struct pdpcb *p;
	u_short port;

	port = (D_0000742C == 0x7FFF) ? 0x4000 : D_0000742C + 1;
	while (port != D_0000742C) {
		for (p = D_00007424.tqh_first; p != NULL; p = p->link.tqe_next) {
			if (memcmp(&p->laddr, addr, 6) == 0 && p->lport == port)
				break;
		}
		if (p == NULL) {
			D_0000742C = port;
			return port;
		}
		port = (port == 0x7FFF) ? 0x4000 : port + 1;
	}
	return 0;
}

/* gamemode.c */
struct gamemode {
	TAILQ_ENTRY(gamemode) link;
	int id;
	struct SceNetEtherAddr mac;
	void *ptr;
	unsigned int size;
};
TAILQ_HEAD(gamemode_list, gamemode);

struct gpinfo {
	unsigned int size;
	unsigned int val;
};

extern int D_000073F0;
extern struct gamemode_list D_00007440;

int func_00006AB8(struct SceNetEtherAddr *mac, void *ptr, unsigned int size);
int func_00006BB8(int id);
int func_00006C3C(int id, struct gpinfo *info, int flag);

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
int sceWlanGPPrevEstablishActive(struct SceNetEtherAddr *mac, void *ptr, unsigned int size);
int sceWlanGPSend(int a, void *ptr, unsigned int size);
int sceWlanGPRecv(int id, void *ptr, unsigned int size, struct gpinfo *info);
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
int _sce_pspnet_start_of_adhoc_module_in_netintr(void (*intr)(void), void (*drain)(struct ifnet *));
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
void func_00000444(struct ifnet *ifp);

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

/* pdp_api.c */
int func_00001530(struct adhoc_socket *so, struct SceNetEtherAddr *daddr, u_short dport, void *data, int len, unsigned int timeout, int flag);
int func_00001B90(struct adhoc_socket *so, struct SceNetEtherAddr *saddr, u_short *sport, void *buf, int *len, unsigned int timeout, int flag, int *x);
int func_00001F20(int id, struct SceNetEtherAddr *saddr, u_short *sport, void *buf, int *len, unsigned int timeout, int flag, int *x);

/* pdp.c */
int func_00002108(struct pdpcb *pcb, struct SceNetEtherAddr *addr, u_short port);
void func_00002304(struct pdpcb *pcb);
int func_00002A9C(struct adhoc_socket *so);
int func_00002B84(struct pdpcb *pcb, u_int size);
void func_00002C7C(void *arg);
void func_00002B38(struct adhoc_socket *so);
int func_00002C00(struct adhoc_socket *so, int events);
int func_000029AC(void);
void func_00002A18(void);
void func_000023C4(struct mbuf *m);
void func_00002B90(struct ifnet *ifp);

/* ptp_api.c */
int func_000038C4(struct SceNetEtherAddr *saddr, u_short sport, u_int sndbuf, u_int rcvbuf, u_int rexmt_int, int rexmt_cnt, struct adhoc_socket **sop);
void func_000039FC(struct adhoc_socket *so);
int func_00003A34(struct adhoc_socket *so, unsigned int timeout, int flag);
int func_00003C00(struct adhoc_socket *so, struct SceNetEtherAddr *addr, u_short *port, unsigned int timeout, int flag);
int func_00003EF4(struct adhoc_socket *so, void *data, int *len, unsigned int timeout, int flag);
int func_000042B0(struct adhoc_socket *so, void *buf, int *len, unsigned int timeout, int flag);
int func_000045E4(struct adhoc_socket *so, unsigned int timeout, int flag);

/* ptp.c */
void func_0000483C(void);
int func_00004918(struct ptpcb *pcb, struct SceNetEtherAddr *addr, u_short port);
void func_00004B64(struct ptpcb *pcb);
struct ptpcb *func_00004C0C(struct ptpcb *lpcb, struct SceNetEtherAddr *faddr, u_short fport, u_int seq);
void func_00004E60(struct ptpcb *pcb);
void func_00004F50(struct ptpcb *pcb);
struct ptpcb *func_000053CC(struct SceNetEtherAddr *laddr, u_short lport, struct SceNetEtherAddr *faddr, u_short fport);
int func_0000548C(struct adhoc_socket *so);
void func_00005528(struct ptpcb *pcb);
int func_00005544(struct ptpcb *pcb, u_int sndbuf, u_int rcvbuf);
void func_00005560(struct ptpcb *pcb, u_int rexmt_int, int rexmt_cnt);
int func_0000556C(struct ptpcb *pcb, struct SceNetEtherAddr *faddr, u_short fport);
int func_000056B0(struct ptpcb *pcb, int backlog);
void func_000056D4(struct ptpcb *pcb);
void func_00005FF8(struct ifnet *ifp, struct SceNetEtherAddr *laddr, u_short lport, struct SceNetEtherAddr *faddr, u_short fport, u_char type, u_int seq, struct mbuf *m);
void func_00006340(struct ptpcb *pcb, u_char type);
void func_0000648C(struct ptpcb *pcb, int flag);
void func_00006624(void *arg);
void func_00004B18(struct adhoc_socket *so);
int func_000050F8(struct adhoc_socket *so, int events);
int func_00005374(void);

/* gamemode.c */
int func_00006880(void);
void func_00006898(void);

void func_0000578C(struct mbuf *m);

#endif
