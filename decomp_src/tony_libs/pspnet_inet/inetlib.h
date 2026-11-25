#ifndef INETLIB_H
#define INETLIB_H

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
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef char *caddr_t;
typedef unsigned long long SceUInt64;
typedef long long quad_t;

static __inline int imax(int a, int b) { return (a > b ? a : b); }
static __inline int imin(int a, int b) { return (a < b ? a : b); }
static __inline long lmax(long a, long b) { return (a > b ? a : b); }
static __inline long lmin(long a, long b) { return (a < b ? a : b); }
static __inline u_int max(u_int a, u_int b) { return (a > b ? a : b); }
static __inline u_int min(u_int a, u_int b) { return (a < b ? a : b); }
static __inline u_long ulmax(u_long a, u_long b) { return (a > b ? a : b); }
static __inline u_long ulmin(u_long a, u_long b) { return (a < b ? a : b); }
typedef unsigned long long u_quad_t;

/* errno numbers are newlib's */
#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EAGAIN 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define ENOTBLK 15
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define EINVAL 22
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define ETXTBSY 26
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32
#define EDOM 33
#define ERANGE 34
#define ENOMSG 35
#define EIDRM 36
#define ECHRNG 37
#define EL2NSYNC 38
#define EL3HLT 39
#define EL3RST 40
#define ELNRNG 41
#define EUNATCH 42
#define ENOCSI 43
#define EL2HLT 44
#define EDEADLK 45
#define ENOLCK 46
#define EBADE 50
#define EBADR 51
#define EXFULL 52
#define ENOANO 53
#define EBADRQC 54
#define EBADSLT 55
#define EDEADLOCK 56
#define EBFONT 57
#define ENOSTR 60
#define ENODATA 61
#define ETIME 62
#define ENOSR 63
#define ENONET 64
#define ENOPKG 65
#define EREMOTE 66
#define ENOLINK 67
#define EADV 68
#define ESRMNT 69
#define ECOMM 70
#define EPROTO 71
#define EMULTIHOP 74
#define ELBIN 75
#define EDOTDOT 76
#define EBADMSG 77
#define EFTYPE 79
#define ENOTUNIQ 80
#define EBADFD 81
#define EREMCHG 82
#define ELIBACC 83
#define ELIBBAD 84
#define ELIBSCN 85
#define ELIBMAX 86
#define ELIBEXEC 87
#define ENOSYS 88
#define ENMFILE 89
#define ENOTEMPTY 90
#define ENAMETOOLONG 91
#define ELOOP 92
#define EOPNOTSUPP 95
#define EPFNOSUPPORT 96
#define ECONNRESET 104
#define ENOBUFS 105
#define EAFNOSUPPORT 106
#define EPROTOTYPE 107
#define ENOTSOCK 108
#define ENOPROTOOPT 109
#define ESHUTDOWN 110
#define ECONNREFUSED 111
#define EADDRINUSE 112
#define ECONNABORTED 113
#define ENETUNREACH 114
#define ENETDOWN 115
#define ETIMEDOUT 116
#define EHOSTDOWN 117
#define EHOSTUNREACH 118
#define EINPROGRESS 119
#define EALREADY 120
#define EDESTADDRREQ 121
#define EMSGSIZE 122
#define EPROTONOSUPPORT 123
#define ESOCKTNOSUPPORT 124
#define EADDRNOTAVAIL 125
#define ENETRESET 126
#define EISCONN 127
#define ENOTCONN 128
#define ETOOMANYREFS 129
#define EPROCLIM 130
#define EUSERS 131
#define EDQUOT 132
#define ESTALE 133
#define ENOTSUP 134
#define ENOMEDIUM 135
#define ENOSHARE 136
#define ECASECLASH 137
#define EILSEQ 138
#define EOVERFLOW 139
#define EWOULDBLOCK EAGAIN

/* libc (static copies inside the module) */
#define toupper func_0002C7B4
#define tolower func_0002C7E0
#define __ctype_flags func_0002C80C
#define __ctype_ptr func_0002C820
#define memchr func_0002C82C
#define memmove func_0002C864
#define memcmp func_0002C8D8
#define bcmp func_0002C978
#define bcopy func_0002C9B8
#define bzero func_0002C9DC
#define strcmp func_0002CA04
#define index func_0002CA84
#define strrchr func_0002CAB4
#define strncmp func_0002CAFC
#define strncpy func_0002CB94
#define strchr func_0002CC10
#define strcpy func_0002CC40
#define strlen func_0002CC78
#define sprintf func_0002CCAC
#define vsnprintf func_0002CCF8

extern const char D_0002EAB0[];

char toupper(char c);
char tolower(char c);
char __ctype_flags(int c);
const char *__ctype_ptr(void);
void *memchr(const void *s, int c, int n);
void *memmove(void *dst, const void *src, int n);
int memcmp(const void *a, const void *b, int n);
void *func_0002C918(void *dst, const void *src, int n) __asm__("memcpy");
void *func_0002C94C(void *dst, int c, int n) __asm__("memset");
#define memcpy __builtin_memcpy
#define memset __builtin_memset
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
int vsnprintf(void (*put)(char **, int), char **arg, const char *fmt, va_list ap);
void func_0002D420(char **pp, int c);


struct in_addr {
	u_int32_t s_addr;
};

#define ntohl(x) __builtin_allegrex_wsbw(x)
#define htonl(x) __builtin_allegrex_wsbw(x)
#define ntohs(x) ((u_short)__builtin_allegrex_wsbh(x))
#define htons(x) ((u_short)__builtin_allegrex_wsbh(x))
#define NTOHL(x) (x) = ntohl(x)
#define HTONL(x) (x) = htonl(x)
#define NTOHS(x) (x) = ntohs(x)
#define HTONS(x) (x) = htons(x)

extern char D_0002EB69[];
extern char D_0002F288[18] __attribute__((aligned(4)));

/* pspnet imports */
#define TAILQ_HEAD(name, type) struct name { struct type *tqh_first; struct type **tqh_last; }
#define TAILQ_ENTRY(type) struct { struct type *tqe_next; struct type **tqe_prev; }
#define TAILQ_FIRST(head) ((head)->tqh_first)
#define TAILQ_NEXT(elm, field) ((elm)->field.tqe_next)
#define TAILQ_INIT(head) do { (head)->tqh_first = NULL; (head)->tqh_last = &(head)->tqh_first; } while (0)
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

struct uio;
struct thread_info {
	struct thread_info *ti_next;
	struct thread_info **ti_prev;
	SceUID thid;
	short refcnt;
	int error;
	int unk14;
	void *slpq[2];
	void *wchan;
	void *co[9];
	int slpflags;
	SceUID sema;
	short semacnt;
	short unk52;
	struct socket *socks;
	char unk58[0x64 - 0x58];
};

struct thread_info *_sce_pspnet_thread_enter(void);
int _sce_pspnet_thread_leave(struct thread_info *ti, int error);
int _sce_pspnet_get_thread_errno(void);
void _sce_pspnet_set_thread_errno(int error);
int _sce_pspnet_spllock(void);
void _sce_pspnet_splunlock(int s);
void *sceNetMallocInternal(u_int size);
void sceNetFreeInternal(void *p);

#define AF_UNSPEC 0
#define AF_LOCAL 1
#define AF_INET 2
#define AF_LINK 18
#define AF_ROUTE 17

typedef u_int socklen_t;

#define _U 01
#define _L 02
#define _N 04
#define _S 010
#define _P 020
#define _C 040
#define _X 0100
#define _B 0200
#define _ctype_ (D_0002EAB0 + 1)
#define isdigit(c) (_ctype_[(int)(c)] & _N)
#define isxdigit(c) (_ctype_[(int)(c)] & (_X | _N))
#define isspace(c) (_ctype_[(int)(c)] & _S)
#define islower(c) (_ctype_[(int)(c)] & _L)
#define isupper(c) (_ctype_[(int)(c)] & _U)

const char *sceNetInetInetNtop(int af, const void *src, char *dst, socklen_t size);
int func_0002C4CC(const char *cp, void *addr, int strict);

/* radix.h */
struct radix_node {
	struct radix_mask *rn_mklist;
	struct radix_node *rn_p;
	short rn_b;
	char rn_bmask;
	u_char rn_flags;
#define RNF_NORMAL 1
#define RNF_ROOT 2
#define RNF_ACTIVE 4
	union {
		struct {
			caddr_t rn_Key;
			caddr_t rn_Mask;
			struct radix_node *rn_Dupedkey;
		} rn_leaf;
		struct {
			int rn_Off;
			struct radix_node *rn_L;
			struct radix_node *rn_R;
		} rn_node;
	} rn_u;
};

#define rn_dupedkey rn_u.rn_leaf.rn_Dupedkey
#define rn_key rn_u.rn_leaf.rn_Key
#define rn_mask rn_u.rn_leaf.rn_Mask
#define rn_off rn_u.rn_node.rn_Off
#define rn_l rn_u.rn_node.rn_L
#define rn_r rn_u.rn_node.rn_R

struct radix_mask {
	short rm_b;
	char rm_unused;
	u_char rm_flags;
	struct radix_mask *rm_mklist;
	union {
		caddr_t rmu_mask;
		struct radix_node *rmu_leaf;
	} rm_rmu;
	int rm_refs;
};

#define rm_mask rm_rmu.rmu_mask
#define rm_leaf rm_rmu.rmu_leaf

struct radix_node_head {
	struct radix_node *rnh_treetop;
	int rnh_addrsize;
	int rnh_pktsize;
	struct radix_node *(*rnh_addaddr)(void *v, void *mask, struct radix_node_head *head, struct radix_node nodes[]);
	struct radix_node *(*rnh_addpkt)(void *v, void *mask, struct radix_node_head *head, struct radix_node nodes[]);
	struct radix_node *(*rnh_deladdr)(void *v, void *mask, struct radix_node_head *head);
	struct radix_node *(*rnh_delpkt)(void *v, void *mask, struct radix_node_head *head);
	struct radix_node *(*rnh_matchaddr)(void *v, struct radix_node_head *head);
	struct radix_node *(*rnh_lookup)(void *v, void *mask, struct radix_node_head *head);
	struct radix_node *(*rnh_matchpkt)(void *v, struct radix_node_head *head);
	int (*rnh_walktree)(struct radix_node_head *head, int (*f)(struct radix_node *, void *), void *w);
	struct radix_node rnh_nodes[3];
};

#define rn_search func_0000B3FC
#define rn_search_m func_0000B440
#define rn_refines func_0000B4A0
#define rn_lookup func_0000B588
#define rn_match func_00009FB8
#define rn_newpair func_0000B63C
#define rn_insert func_0000A310
#define rn_addmask func_0000A4BC
#define rn_addroute func_0000A804
#define rn_delete func_0000AE9C
#define rn_walktree func_0000B2DC
#define rn_inithead func_0000B684
#define rn_init func_0000B7E8

struct radix_node *rn_search(void *v_arg, struct radix_node *head);
struct radix_node *rn_search_m(void *v_arg, struct radix_node *head, void *m_arg);
int rn_refines(void *m_arg, void *n_arg);
struct radix_node *rn_lookup(void *v_arg, void *m_arg, struct radix_node_head *head);
struct radix_node *rn_match(void *v_arg, struct radix_node_head *head);
struct radix_node *rn_newpair(void *v, int b, struct radix_node nodes[2]);
struct radix_node *rn_insert(void *v_arg, struct radix_node_head *head, int *dupentry, struct radix_node nodes[2]);
struct radix_node *rn_addmask(void *n_arg, int search, int skip);
struct radix_node *rn_addroute(void *v_arg, void *n_arg, struct radix_node_head *head, struct radix_node treenodes[2]);
struct radix_node *rn_delete(void *v_arg, void *netmask_arg, struct radix_node_head *head);
int rn_walktree(struct radix_node_head *h, int (*f)(struct radix_node *, void *), void *w);
int rn_inithead(void **head, int off);
void rn_init(void);

/* domain.h / protosw.h */
struct mbuf;
struct socket;
struct sockaddr;

struct domain {
	int dom_family;
	char *dom_name;
	void (*dom_init)(void);
	int (*dom_externalize)(struct mbuf *);
	void (*dom_dispose)(struct mbuf *);
	struct protosw *dom_protosw;
	struct protosw *dom_protoswNPROTOSW;
	struct domain *dom_next;
	int (*dom_rtattach)(void **, int);
	int dom_rtoffset;
	int dom_maxrtkey;
};

struct protosw {
	int pr_type;
	struct domain *pr_domain;
	short pr_protocol;
	short pr_flags;
	void (*pr_input)();
	int (*pr_output)();
	void *(*pr_ctlinput)(int, struct sockaddr *, void *);
	int (*pr_ctloutput)(int, struct socket *, int, int, struct mbuf **);
	int (*pr_usrreq)(struct socket *, int, struct mbuf *, struct mbuf *, struct mbuf *);
	void (*pr_init)(void);
	void (*pr_fasttimo)(void);
	void (*pr_slowtimo)(void);
	void (*pr_drain)(void);
	int (*pr_sysctl)(int *, u_int, void *, size_t *, void *, size_t);
};

#define domains D_0002EB50
extern struct domain *domains;

/* callouts (pspnet) */
struct callout {
	void *c_link[4];
	void (*c_func)(void *);
	void *c_arg;
	u_int c_time;
	int c_flags;
	SceUID c_alarm;
};

void _sce_pspnet_callout_init(struct callout *c);
void _sce_pspnet_callout_reset(struct callout *c, int ticks, void (*func)(void *), void *arg);
void _sce_pspnet_callout_stop(struct callout *c);
#define callout_init _sce_pspnet_callout_init
#define callout_reset _sce_pspnet_callout_reset
#define callout_stop _sce_pspnet_callout_stop
#define hz 100

void sceNetIfhandle_lib_5FB31C72(int *max_linkhdr, int *max_protohdr, int *max_hdr, int *max_datalen);
void sceNetIfhandle_lib_62B20015(int max_linkhdr, int max_protohdr, int max_hdr, int max_datalen);

/* uipc_domain.c */
#define ADDDOMAIN(x) { (x).dom_next = domains; domains = &(x); }
#define SOCK_STREAM 1
#define SOCK_DGRAM 2
#define SOCK_RAW 3
extern struct domain D_0002E50C, D_0002E59C, D_0002E768;
extern int D_0002F29C, D_0002F2E8;
extern struct callout D_0002F2A0, D_0002F2C4;
struct domain *func_00001FAC(int family);
void func_0000227C(void *arg);
void func_00002320(void *arg);

/* mbuf.h (Sony) */
#define MSIZE 256
#define MLEN (MSIZE - sizeof(struct m_hdr))
#define MHLEN (MLEN - sizeof(struct pkthdr))
#define MINCLSIZE (MHLEN + MLEN + 1)
#define MCLBYTES 2048
#define M_COPYALL 1000000000

#define M_EXT 0x0001
#define M_PKTHDR 0x0002
#define M_EOR 0x0004
#define M_CLUSTER 0x0008
#define M_BCAST 0x0100
#define M_MCAST 0x0200
#define M_COPYFLAGS (M_PKTHDR | M_EOR | M_BCAST | M_MCAST)

#define MT_FREE 0
#define MT_DATA 1
#define MT_HEADER 2
#define MT_SONAME 3
#define MT_SOOPTS 4
#define MT_FTABLE 5
#define MT_CONTROL 6
#define MT_OOBDATA 7

#define M_DONTWAIT 1
#define M_WAIT 0

struct ifnet;

struct m_hdr {
	struct mbuf *mh_next;
	struct mbuf *mh_nextpkt;
	caddr_t mh_data;
	int mh_len;
	short mh_type;
	u_short mh_flags;
};

struct pkthdr {
	struct ifnet *rcvif;
	int len;
	struct mbuf *aux;
	int csum_flags;
	int csum_data;
	int unk28;
	int unk2C;
};

struct m_ext {
	caddr_t ext_buf;
	void (*ext_free)(caddr_t, u_int, void *);
	void *ext_arg;
	u_int ext_size;
	int ext_type;
	struct mbuf *ext_nextref;
	struct mbuf *ext_prevref;
};

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

#define m_next m_hdr.mh_next
#define m_len m_hdr.mh_len
#define m_data m_hdr.mh_data
#define m_type m_hdr.mh_type
#define m_flags m_hdr.mh_flags
#define m_nextpkt m_hdr.mh_nextpkt
#define m_act m_nextpkt
#define m_pkthdr M_dat.MH.MH_pkthdr
#define m_ext M_dat.MH.MH_dat.MH_ext
#define m_pktdat M_dat.MH.MH_dat.MH_databuf
#define m_dat M_dat.M_databuf

#define mtod(m, t) ((t)((m)->m_data))
#define dtom(x) ((struct mbuf *)((u_long)(x) & ~(MSIZE - 1)))

#define MGET(m, how, type) do { \
	(m) = sceNetMallocInternal(MSIZE); \
	if (m) { \
		(m)->m_type = (type); \
		(m)->m_data = (m)->m_dat; \
		(m)->m_next = (struct mbuf *)NULL; \
		(m)->m_nextpkt = (struct mbuf *)NULL; \
		(m)->m_flags = 0; \
	} \
} while (0)

#define MGETHDR(m, how, type) do { \
	(m) = sceNetMallocInternal(MSIZE); \
	if (m) { \
		(m)->m_type = (type); \
		(m)->m_next = (struct mbuf *)NULL; \
		(m)->m_nextpkt = (struct mbuf *)NULL; \
		(m)->m_data = (m)->m_pktdat; \
		(m)->m_flags = M_PKTHDR; \
		(m)->m_pkthdr.aux = (struct mbuf *)NULL; \
	} \
} while (0)

#define MCLINITREFERENCE(m) do { \
	(m)->m_ext.ext_nextref = (m)->m_ext.ext_prevref = (m); \
} while (0)

#define MCLGET(m, how) do { \
	(m)->m_ext.ext_buf = sceNetMallocInternal(MCLBYTES); \
	if ((m)->m_ext.ext_buf == NULL) \
		(m)->m_ext.ext_buf = sceNetMallocInternal(MCLBYTES); \
	if ((m)->m_ext.ext_buf != NULL) { \
		(m)->m_data = (m)->m_ext.ext_buf; \
		(m)->m_flags |= M_EXT | M_CLUSTER; \
		(m)->m_ext.ext_size = MCLBYTES; \
		(m)->m_ext.ext_free = NULL; \
		(m)->m_ext.ext_arg = NULL; \
		MCLINITREFERENCE(m); \
	} \
} while (0)

#define MEXTMALLOC(m, size, how) do { \
	(m)->m_ext.ext_buf = sceNetMallocInternal(size); \
	if ((m)->m_ext.ext_buf != NULL) { \
		(m)->m_data = (m)->m_ext.ext_buf; \
		(m)->m_flags = ((m)->m_flags | M_EXT) & ~M_CLUSTER; \
		(m)->m_ext.ext_size = (size); \
		(m)->m_ext.ext_free = NULL; \
		(m)->m_ext.ext_arg = NULL; \
		(m)->m_ext.ext_type = (m)->m_type; \
		MCLINITREFERENCE(m); \
	} \
} while (0)

#define MCLISREFERENCED(m) ((m)->m_ext.ext_nextref != (m))
#define _MCLDEREFERENCE(m) do { \
	(m)->m_ext.ext_nextref->m_ext.ext_prevref = (m)->m_ext.ext_prevref; \
	(m)->m_ext.ext_prevref->m_ext.ext_nextref = (m)->m_ext.ext_nextref; \
} while (0)

#define MFREE(m, n) do { \
	if (((m)->m_flags & M_PKTHDR) && (m)->m_pkthdr.aux) { \
		m_freem((m)->m_pkthdr.aux); \
		(m)->m_pkthdr.aux = NULL; \
	} \
	if ((m)->m_flags & M_EXT) { \
		if (MCLISREFERENCED(m)) \
			_MCLDEREFERENCE(m); \
		else if ((m)->m_flags & M_CLUSTER) \
			sceNetFreeInternal((m)->m_ext.ext_buf); \
		else if ((m)->m_ext.ext_free) \
			(*((m)->m_ext.ext_free))((m)->m_ext.ext_buf, (m)->m_ext.ext_size, (m)->m_ext.ext_arg); \
		else \
			sceNetFreeInternal((m)->m_ext.ext_buf); \
		(m)->m_flags &= ~(M_EXT | M_CLUSTER); \
		(m)->m_ext.ext_size = 0; \
	} \
	(n) = (m)->m_next; \
	sceNetFreeInternal(m); \
} while (0)

#define M_COPY_PKTHDR(to, from) do { \
	(to)->m_pkthdr = (from)->m_pkthdr; \
	(from)->m_pkthdr.aux = NULL; \
	(to)->m_flags = (from)->m_flags & M_COPYFLAGS; \
	(to)->m_data = (to)->m_pktdat; \
} while (0)

#define M_ALIGN(m, len) do { \
	(m)->m_data += (MLEN - (len)) & ~(sizeof(long) - 1); \
} while (0)

#define MH_ALIGN(m, len) do { \
	(m)->m_data += (MHLEN - (len)) & ~(sizeof(long) - 1); \
} while (0)

#define M_LEADINGSPACE(m) \
	((m)->m_flags & M_EXT ? 0 : \
	    (m)->m_flags & M_PKTHDR ? (m)->m_data - (m)->m_pktdat : \
	    (m)->m_data - (m)->m_dat)

#define M_TRAILINGSPACE(m) \
	((m)->m_flags & M_EXT ? (m)->m_ext.ext_buf + (m)->m_ext.ext_size - \
	    ((m)->m_data + (m)->m_len) : \
	    &(m)->m_dat[MLEN] - ((m)->m_data + (m)->m_len))

#define M_PREPEND(m, plen, how) do { \
	if (M_LEADINGSPACE(m) >= (plen)) { \
		(m)->m_data -= (plen); \
		(m)->m_len += (plen); \
	} else \
		(m) = m_prepend((m), (plen), (how)); \
	if ((m) && (m)->m_flags & M_PKTHDR) \
		(m)->m_pkthdr.len += (plen); \
} while (0)

#define m_adj sceNetMAdj
#define m_cat sceNetMCat
#define m_copyback sceNetMCopyback
#define m_copydata sceNetMCopydata
#define m_copym sceNetMCopym
#define m_copy(m, o, l) m_copym((m), (o), (l), M_DONTWAIT)
#define m_free sceNetMFree
#define m_freem sceNetMFreem
#define m_get sceNetMGet
#define m_getclr sceNetMGetclr
#define m_gethdr sceNetMGethdr
#define m_prepend sceNetMPrepend
#define m_pulldown sceNetMPulldown
#define m_pullup sceNetMPullup

void sceNetMAdj(struct mbuf *mp, int req_len);
void sceNetMCat(struct mbuf *m, struct mbuf *n);
void sceNetMCopyback(struct mbuf *m0, int off, int len, caddr_t cp);
void sceNetMCopydata(struct mbuf *m, int off, int len, caddr_t cp);
struct mbuf *sceNetMCopym(struct mbuf *m, int off0, int len, int wait);
struct mbuf *sceNetMFree(struct mbuf *m);
void sceNetMFreem(struct mbuf *m);
struct mbuf *sceNetMGet(int nowait, int type);
struct mbuf *sceNetMGetclr(int nowait, int type);
struct mbuf *sceNetMGethdr(int nowait, int type);
struct mbuf *sceNetMPrepend(struct mbuf *m, int len, int how);
struct mbuf *sceNetMPulldown(struct mbuf *m, int off, int len, int *offp);
struct mbuf *sceNetMPullup(struct mbuf *n, int len);

/* socket.h */
struct sockaddr {
	u_char sa_len;
	u_char sa_family;
	char sa_data[14];
};

#define SCM_RIGHTS 0x01

struct cmsghdr {
	socklen_t cmsg_len;
	int cmsg_level;
	int cmsg_type;
};

#define __cmsg_alignbytes func_00005D70
#define __CMSG_ALIGN(n) (((n) + __cmsg_alignbytes()) & ~__cmsg_alignbytes())
#define CMSG_DATA(cmsg) ((u_char *)(void *)(cmsg) + __CMSG_ALIGN(sizeof(struct cmsghdr)))
#define CMSG_SPACE(l) (__CMSG_ALIGN(sizeof(struct cmsghdr)) + __CMSG_ALIGN(l))
#define CMSG_LEN(l) (__CMSG_ALIGN(sizeof(struct cmsghdr)) + (l))

#define SO_DEBUG 0x0001
#define SO_ACCEPTCONN 0x0002
#define SO_REUSEADDR 0x0004
#define SO_KEEPALIVE 0x0008
#define SO_DONTROUTE 0x0010
#define SO_BROADCAST 0x0020
#define SO_USELOOPBACK 0x0040
#define SO_LINGER 0x0080
#define SO_OOBINLINE 0x0100
#define SO_REUSEPORT 0x0200
#define SO_TIMESTAMP 0x0400

/* socketvar.h (Sony layout) */
struct selinfo {
	SceUID si_pid;
	short si_flags;
};

struct sockbuf {
	u_long sb_cc;
	u_long sb_hiwat;
	u_long sb_mbcnt;
	u_long sb_mbmax;
	long sb_lowat;
	struct mbuf *sb_mb;
	struct selinfo sb_sel;
	short sb_flags;
	short sb_unk22;
	int sb_timeo;
};

#define SB_MAX (256 * 1024)
#define SB_LOCK 0x01
#define SB_WANT 0x02
#define SB_WAIT 0x04
#define SB_SEL 0x08
#define SB_ASYNC 0x10
#define SB_UPCALL 0x20
#define SB_NOINTR 0x40

TAILQ_HEAD(soqhead, socket);
struct socket {
	short so_type;
	short so_options;
	int so_linger;
	short so_state;
	short so_unkA;
	void *so_pcb;
	struct protosw *so_proto;
	struct socket *so_head;
	struct soqhead *so_onq;
	struct soqhead so_q0;
	struct soqhead so_q;
	TAILQ_ENTRY(socket) so_qe;
	short so_q0len;
	short so_qlen;
	short so_qlimit;
	short so_timeo;
	u_short so_error;
	u_long so_oobmark;
	struct sockbuf so_rcv;
	struct sockbuf so_snd;
	int so_unk94;
	void (*so_upcall)(struct socket *so, caddr_t arg, int waitf);
	caddr_t so_upcallarg;
	int (*so_send)(struct socket *, struct mbuf *, struct uio *, struct mbuf *, struct mbuf *, int);
	int (*so_receive)(struct socket *, struct mbuf **, struct uio *, struct mbuf **, struct mbuf **, int *);
	int so_fd;
	TAILQ_ENTRY(socket) so_list;
	struct thread_info *so_thread;
	struct socket *so_tnext;
};
TAILQ_HEAD(socklist_head, socket);

#define SS_NOFDREF 0x001
#define SS_ISCONNECTED 0x002
#define SS_ISCONNECTING 0x004
#define SS_ISDISCONNECTING 0x008
#define SS_CANTSENDMORE 0x010
#define SS_CANTRCVMORE 0x020
#define SS_RCVATMARK 0x040
#define SS_PRIV 0x080
#define SS_NBIO 0x080
#define SS_ISCONFIRMING 0x200
#define SS_MORETOCOME 0x400
#define SS_ISDISCONNECTED 0x800

#define sbspace(sb) \
	(lmin((long)((sb)->sb_hiwat - (sb)->sb_cc), (long)((sb)->sb_mbmax - (sb)->sb_mbcnt)))

#define sballoc(sb, m) do { \
	(sb)->sb_cc += (m)->m_len; \
	(sb)->sb_mbcnt += MSIZE; \
	if ((m)->m_flags & M_EXT) \
		(sb)->sb_mbcnt += (m)->m_ext.ext_size; \
} while (0)

#define sbfree(sb, m) do { \
	(sb)->sb_cc -= (m)->m_len; \
	(sb)->sb_mbcnt -= MSIZE; \
	if ((m)->m_flags & M_EXT) \
		(sb)->sb_mbcnt -= (m)->m_ext.ext_size; \
} while (0)

#define sb_notify(sb) (((sb)->sb_flags & (SB_WAIT | SB_SEL | SB_ASYNC | SB_UPCALL)) != 0)
#define sorwakeup(so) do { if (sb_notify(&(so)->so_rcv)) sowakeup((so), &(so)->so_rcv); } while (0)
#define sowwakeup(so) do { if (sb_notify(&(so)->so_snd)) sowakeup((so), &(so)->so_snd); } while (0)

#define PRU_ATTACH 0
#define PRU_DETACH 1
#define PRU_BIND 2
#define PRU_LISTEN 3
#define PRU_CONNECT 4
#define PRU_ACCEPT 5
#define PRU_DISCONNECT 6
#define PRU_SHUTDOWN 7
#define PRU_RCVD 8
#define PRU_SEND 9
#define PRU_ABORT 10
#define PRU_CONTROL 11
#define PRU_SENSE 12
#define PRU_RCVOOB 13
#define PRU_SENDOOB 14
#define PRU_SOCKADDR 15
#define PRU_PEERADDR 16
#define PRU_CONNECT2 17
#define PRU_FASTTIMO 18
#define PRU_SLOWTIMO 19
#define PRU_PROTORCV 20
#define PRU_PROTOSEND 21

#define PR_ATOMIC 0x01
#define PR_ADDR 0x02
#define PR_CONNREQUIRED 0x04
#define PR_WANTRCVD 0x08
#define PR_RIGHTS 0x10

void _sce_pspnet_wakeup(void *chan);
int _sce_pspnet_tsleep(void *chan, int timo);
#define tsleep _sce_pspnet_tsleep
void _sce_pspnet_selwakeup(struct selinfo *sip);
void _sce_pspnet_selrecord(struct thread_info *selector, struct selinfo *sip);
#define wakeup _sce_pspnet_wakeup
#define selwakeup _sce_pspnet_selwakeup
#define selrecord _sce_pspnet_selrecord

/* uipc_socket2.c */
#define soisconnected func_0000473C
#define sonewconn func_00004820
#define soqinsque func_000049DC
#define soqremque func_00004A38
#define sowakeup func_00004AB8
#define soreserve func_00004B44
#define sbreserve func_00004BEC
#define sbrelease func_00004C3C
#define sbinsertoob func_00004C68
#define sbappendaddr func_00004D3C
#define sbappendcontrol func_00004F38
#define sbcompress func_00005024
#define sbflush func_000051F8
#define sbdrop func_00005240
#define sbdroprecord func_000054EC
#define sbcreatecontrol func_00005624
#define sofdalloc func_00005810
#define getsock func_000058EC
#define soisconnecting func_00005964
#define soisdisconnecting func_00005978
#define soisdisconnected func_000059F8
#define socantsendmore func_00005A78
#define socantrcvmore func_00005AB8
#define sbwait func_00005AF8
#define sb_lock func_00005B20
#define sbappend func_00005B98
#define sbappendrecord func_00005CB8

void soisconnected(struct socket *so);
struct socket *sonewconn(struct socket *head, int connstatus);
void soqinsque(struct socket *head, struct socket *so, int q);
int soqremque(struct socket *so, int q);
void sowakeup(struct socket *so, struct sockbuf *sb);
int soreserve(struct socket *so, u_long sndcc, u_long rcvcc);
int sbreserve(struct sockbuf *sb, u_long cc);
void sbrelease(struct sockbuf *sb);
void sbinsertoob(struct sockbuf *sb, struct mbuf *m0);
int sbappendaddr(struct sockbuf *sb, struct sockaddr *asa, struct mbuf *m0, struct mbuf *control);
int sbappendcontrol(struct sockbuf *sb, struct mbuf *m0, struct mbuf *control);
void sbcompress(struct sockbuf *sb, struct mbuf *m, struct mbuf *n);
void sbflush(struct sockbuf *sb);
void sbdrop(struct sockbuf *sb, int len);
void sbdroprecord(struct sockbuf *sb);
struct mbuf *sbcreatecontrol(caddr_t p, int size, int type, int level);
int sofdalloc(void) __attribute__((noinline));
struct socket *getsock(int fd);
void soisconnecting(struct socket *so);
void soisdisconnecting(struct socket *so);
void soisdisconnected(struct socket *so);
void socantsendmore(struct socket *so);
void socantrcvmore(struct socket *so);
int sbwait(struct sockbuf *sb);
int sb_lock(struct sockbuf *sb);
void sbappend(struct sockbuf *sb, struct mbuf *m);
void sbappendrecord(struct sockbuf *sb, struct mbuf *m0);
int __cmsg_alignbytes(void);

#define socklist D_0002F2EC
#define lastfd D_0002EB54
extern struct socklist_head socklist;
extern int lastfd;

/* uipc_socket.c */
struct iovec {
	void *iov_base;
	size_t iov_len;
};

struct uio {
	struct iovec *uio_iov;
	int uio_iovcnt;
	long uio_offset;
	size_t uio_resid;
	int uio_segflg;
	int uio_rw;
	void *uio_procp;
	int uio_unk1C;
};

struct linger {
	int l_onoff;
	int l_linger;
};

#define SOL_SOCKET 0xffff
#define SO_SNDBUF 0x1001
#define SO_RCVBUF 0x1002
#define SO_SNDLOWAT 0x1003
#define SO_RCVLOWAT 0x1004
#define SO_SNDTIMEO 0x1005
#define SO_RCVTIMEO 0x1006
#define SO_ERROR 0x1007
#define SO_TYPE 0x1008
#define SO_NBIO 0x1009

#define MSG_OOB 0x1
#define MSG_PEEK 0x2
#define MSG_DONTROUTE 0x4
#define MSG_EOR 0x8
#define MSG_TRUNC 0x10
#define MSG_CTRUNC 0x20
#define MSG_WAITALL 0x40
#define MSG_DONTWAIT 0x80

#define PRCO_GETOPT 0
#define PRCO_SETOPT 1

#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2

#define POLLIN 0x0001
#define POLLPRI 0x0002
#define POLLOUT 0x0004
#define POLLRDNORM 0x0040
#define POLLWRNORM POLLOUT
#define POLLRDBAND 0x0080

#define SBLOCKWAIT(f) (((f) & MSG_DONTWAIT) ? M_DONTWAIT : M_WAIT)
#define sblock(sb, wf) ((sb)->sb_flags & SB_LOCK ? \
	(((wf) == M_WAIT) ? sb_lock(sb) : EWOULDBLOCK) : \
	((sb)->sb_flags |= SB_LOCK), 0)
#define sbunlock(sb) do { \
	(sb)->sb_flags &= ~SB_LOCK; \
	if ((sb)->sb_flags & SB_WANT) { \
		(sb)->sb_flags &= ~SB_WANT; \
		wakeup((caddr_t)&(sb)->sb_flags); \
	} \
} while (0)
#define sosendallatonce(so) ((so)->so_proto->pr_flags & PR_ATOMIC)
#define soreadable(so) \
	((so)->so_rcv.sb_cc >= (so)->so_rcv.sb_lowat || \
	    ((so)->so_state & SS_CANTRCVMORE) || \
	    (so)->so_qlen || (so)->so_error)
#define sowriteable(so) \
	((sbspace(&(so)->so_snd) >= (so)->so_snd.sb_lowat && \
	    (((so)->so_state&SS_ISCONNECTED) || \
	      ((so)->so_proto->pr_flags&PR_CONNREQUIRED)==0)) || \
	((so)->so_state & SS_CANTSENDMORE) || \
	(so)->so_error)

#define pffinddomain func_00001FAC
#define pffindtype func_00001FDC
#define pffindproto func_00002058
#define net_sysctl func_0000211C
#define pfctlinput func_000021E0
struct protosw *pffindtype(int family, int type);
struct protosw *pffindproto(int family, int protocol, int type);
void pfctlinput(int cmd, struct sockaddr *sa);

#define socreate func_000023C4
#define sofree func_00002560
#define soclose func_000025F4
#define soabort func_0000278C
#define sodisconnect func_000027BC
#define sosend func_00002844
#define soreceive func_00002E98
#define sorflush func_00003ABC
#define sosetopt func_00003C18
#define sogetopt func_00003F44
#define sopoll func_00004160
#define soinit func_000042F4
#define sobind func_0000431C
#define solisten func_00004388
#define soaccept func_00004444
#define soconnect func_000044D0
#define soconnect2 func_00004594
#define soshutdown func_00004600
#define sohasoutofband func_000046A8
#define soioctl func_000046C4
#define somaxconn D_0002E480
extern int somaxconn;

int socreate(int dom, struct socket **aso, int type, int proto);
void sofree(struct socket *so) __attribute__((noinline)); /* XXX socreate (asm) calls it first */
int soclose(struct socket *so);
int soabort(struct socket *so);
int sodisconnect(struct socket *so);
int sosend(struct socket *so, struct mbuf *addr, struct uio *uio, struct mbuf *top, struct mbuf *control, int flags);
int soreceive(struct socket *so, struct mbuf **paddr, struct uio *uio, struct mbuf **mp0, struct mbuf **controlp, int *flagsp);
void sorflush(struct socket *so);
int sosetopt(struct socket *so, int level, int optname, struct mbuf *m0);
int sogetopt(struct socket *so, int level, int optname, struct mbuf **mp);
int sopoll(struct socket *so, int events, struct thread_info *p);
void soinit(void);
int sobind(struct socket *so, struct mbuf *nam);
int solisten(struct socket *so, int backlog);
int soaccept(struct socket *so, struct mbuf *nam);
int soconnect(struct socket *so, struct mbuf *nam);
int soconnect2(struct socket *so1, struct socket *so2);
int soshutdown(struct socket *so, int how);
void sohasoutofband(struct socket *so);
int soioctl(struct socket *so, u_long cmd, caddr_t data);

int _sce_pspnet_uiomove(caddr_t cp, int n, struct uio *uio);
#define uiomove _sce_pspnet_uiomove
SceUID sceKernelGetThreadId(void);
int _sce_pspnet_ifioctl(struct socket *so, u_long cmd, caddr_t data, int wait);
#define ifioctl _sce_pspnet_ifioctl
#define rtioctl func_0000D128
int rtioctl(u_long req, caddr_t data);
#define IOCGROUP(x) (((x) >> 8) & 0xff)

/* inet_sched.c */
int _sce_pspnet_start_of_inet_module_in_sched(void (*f1)(struct thread_info *), void (*f2)(struct socket *));
void _sce_pspnet_stop_of_inet_module_in_sched(void);
int sceKernelSignalSema(SceUID semaid, int signal);
void func_00001D94(struct thread_info *ti);
void func_00001DD8(struct socket *so);

#endif
