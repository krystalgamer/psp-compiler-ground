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
} __attribute__((__packed__));

#define ntohl(x) __builtin_allegrex_wsbw(x)
#define htonl(x) __builtin_allegrex_wsbw(x)
#define ntohs(x) ((u_short)__builtin_allegrex_wsbh((u_short)(x)))
#define htons(x) ((u_short)__builtin_allegrex_wsbh((u_short)(x)))
#define NTOHL(x) (x) = ntohl(x)
#define HTONL(x) (x) = htonl(x)
#define NTOHS(x) (x) = ntohs(x)
#define HTONS(x) (x) = htons(x)

extern char D_0002EB69[];
extern char D_0002F288[18] __attribute__((aligned(4)));

/* pspnet imports */
#define LIST_HEAD(name, type) struct name { struct type *lh_first; }
#define LIST_ENTRY(type) struct { struct type *le_next; struct type **le_prev; }
#define LIST_FIRST(head) ((head)->lh_first)
#define LIST_NEXT(elm, field) ((elm)->field.le_next)
#define LIST_INIT(head) do { (head)->lh_first = NULL; } while (0)
#define LIST_INSERT_AFTER(listelm, elm, field) do { \
	if (((elm)->field.le_next = (listelm)->field.le_next) != NULL) \
		(listelm)->field.le_next->field.le_prev = &(elm)->field.le_next; \
	(listelm)->field.le_next = (elm); \
	(elm)->field.le_prev = &(listelm)->field.le_next; \
} while (0)
#define LIST_INSERT_HEAD(head, elm, field) do { \
	if (((elm)->field.le_next = (head)->lh_first) != NULL) \
		(head)->lh_first->field.le_prev = &(elm)->field.le_next; \
	(head)->lh_first = (elm); \
	(elm)->field.le_prev = &(head)->lh_first; \
} while (0)
#define LIST_REMOVE(elm, field) do { \
	if ((elm)->field.le_next != NULL) \
		(elm)->field.le_next->field.le_prev = (elm)->field.le_prev; \
	*(elm)->field.le_prev = (elm)->field.le_next; \
} while (0)
#define CIRCLEQ_HEAD(name, type) struct name { struct type *cqh_first; struct type *cqh_last; }
#define CIRCLEQ_ENTRY(type) struct { struct type *cqe_next; struct type *cqe_prev; }
#define CIRCLEQ_INIT(head) do { \
	(head)->cqh_first = (void *)(head); \
	(head)->cqh_last = (void *)(head); \
} while (0)
#define CIRCLEQ_INSERT_HEAD(head, elm, field) do { \
	(elm)->field.cqe_next = (head)->cqh_first; \
	(elm)->field.cqe_prev = (void *)(head); \
	if ((head)->cqh_last == (void *)(head)) \
		(head)->cqh_last = (elm); \
	else \
		(head)->cqh_first->field.cqe_prev = (elm); \
	(head)->cqh_first = (elm); \
} while (0)
#define CIRCLEQ_INSERT_TAIL(head, elm, field) do { \
	(elm)->field.cqe_next = (void *)(head); \
	(elm)->field.cqe_prev = (head)->cqh_last; \
	if ((head)->cqh_first == (void *)(head)) \
		(head)->cqh_first = (elm); \
	else \
		(head)->cqh_last->field.cqe_next = (elm); \
	(head)->cqh_last = (elm); \
} while (0)
#define CIRCLEQ_REMOVE(head, elm, field) do { \
	if ((elm)->field.cqe_next == (void *)(head)) \
		(head)->cqh_last = (elm)->field.cqe_prev; \
	else \
		(elm)->field.cqe_next->field.cqe_prev = (elm)->field.cqe_prev; \
	if ((elm)->field.cqe_prev == (void *)(head)) \
		(head)->cqh_first = (elm)->field.cqe_next; \
	else \
		(elm)->field.cqe_prev->field.cqe_next = (elm)->field.cqe_next; \
} while (0)
#define CIRCLEQ_FIRST(head) ((head)->cqh_first)
#define CIRCLEQ_NEXT(elm, field) ((elm)->field.cqe_next)
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
#define PF_INET AF_INET
#define AF_IMPLINK 3
#define AF_NS 6
#define AF_ISO 7
#define AF_IPX 23
#define AF_INET6 24
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
extern struct domain D_0002E50C, D_0002E59C, inetdomain;
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
#define M_COPYFLAGS (~(M_EXT | M_CLUSTER))

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
	short mh_flags;
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
#define roundup(x, y) ((((x)+((y)-1))/(y))*(y))
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
#define PR_LISTEN 0x20

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

/* ip.h */
struct ip {
	u_int8_t ip_hl:4,
		ip_v:4;
	u_int8_t ip_tos;
	u_int16_t ip_len;
	u_int16_t ip_id;
	u_int16_t ip_off;
	u_int8_t ip_ttl;
	u_int8_t ip_p;
	u_int16_t ip_sum;
	struct in_addr ip_src, ip_dst;
} __attribute__((__packed__));

struct ipovly {
	u_int8_t ih_x1[9];
	u_int8_t ih_pr;
	u_int16_t ih_len;
	struct in_addr ih_src;
	struct in_addr ih_dst;
} __attribute__((__packed__));

#define in4_cksum func_00012D84
#define in_cksum func_00013130
int in4_cksum(struct mbuf *m, u_int8_t nxt, int off, int len);
int in_cksum(struct mbuf *m, int len);

/* in.h */
#define __IPADDR(x) ((u_int32_t)htonl((u_int32_t)(x)))
#define INADDR_ANY __IPADDR(0x00000000)
#define INADDR_LOOPBACK __IPADDR(0x7f000001)
#define INADDR_BROADCAST __IPADDR(0xffffffff)
#define INADDR_NONE __IPADDR(0xffffffff)
#define INADDR_UNSPEC_GROUP __IPADDR(0xe0000000)
#define INADDR_ALLHOSTS_GROUP __IPADDR(0xe0000001)
#define IN_CLASSA(i) (((u_int32_t)(i) & __IPADDR(0x80000000)) == __IPADDR(0x00000000))
#define IN_CLASSB(i) (((u_int32_t)(i) & __IPADDR(0xc0000000)) == __IPADDR(0x80000000))
#define IN_CLASSC(i) (((u_int32_t)(i) & __IPADDR(0xe0000000)) == __IPADDR(0xc0000000))
#define IN_CLASSD(i) (((u_int32_t)(i) & __IPADDR(0xf0000000)) == __IPADDR(0xe0000000))
#define IN_MULTICAST(i) IN_CLASSD(i)
#define IN_EXPERIMENTAL(i) (((u_int32_t)(i) & __IPADDR(0xf0000000)) == __IPADDR(0xf0000000))
#define IN_BADCLASS(i) (((u_int32_t)(i) & __IPADDR(0xf0000000)) == __IPADDR(0xf0000000))
#define IN_CLASSA_NET __IPADDR(0xff000000)
#define IN_CLASSB_NET __IPADDR(0xffff0000)
#define IN_CLASSC_NET __IPADDR(0xffffff00)
#define IN_LOOPBACKNET 127
#define IN_LOCAL_GROUP(i) (((u_int32_t)(i) & __IPADDR(0xffffff00)) == __IPADDR(0xe0000000))
#define IN_CLASSA_NSHIFT 24
#define in_nullhost(x) ((x).s_addr == INADDR_ANY)
#define in_hosteq(s, t) ((s).s_addr == (t).s_addr)

struct sockaddr_in {
	u_int8_t sin_len;
	u_int8_t sin_family;
	u_int16_t sin_port;
	struct in_addr sin_addr;
	int8_t sin_zero[8];
};
#define satosin(sa) ((struct sockaddr_in *)(sa))
#define sintosa(sin) ((struct sockaddr *)(sin))

/* route.h */
struct route {
	struct rtentry *ro_rt;
	struct sockaddr ro_dst;
};

struct rt_metrics {
	u_long rmx_locks;
	u_long rmx_mtu;
	u_long rmx_hopcount;
	u_long rmx_expire;
	u_long rmx_recvpipe;
	u_long rmx_sendpipe;
	u_long rmx_ssthresh;
	u_long rmx_rtt;
	u_long rmx_rttvar;
	u_long rmx_pksent;
};

struct rtentry {
	struct radix_node rt_nodes[2];
	struct sockaddr *rt_gateway;
	int rt_flags;
	int rt_refcnt;
	u_long rt_use;
	struct ifnet *rt_ifp;
	struct ifaddr *rt_ifa;
	struct sockaddr *rt_genmask;
	caddr_t rt_llinfo;
	struct rt_metrics rt_rmx;
	struct rtentry *rt_gwroute;
	LIST_HEAD(, rttimer) rt_timer;
	struct rtentry *rt_parent;
};
#define rt_key(r) ((struct sockaddr *)((r)->rt_nodes->rn_key))
#define rt_mask(r) ((struct sockaddr *)((r)->rt_nodes->rn_mask))

#define RTF_UP 0x1
#define RTF_GATEWAY 0x2
#define RTF_HOST 0x4
#define RTF_REJECT 0x8
#define RTF_DYNAMIC 0x10
#define RTF_MODIFIED 0x20
#define RTF_DONE 0x40
#define RTF_MASK 0x80
#define RTF_CLONING 0x100
#define RTF_XRESOLVE 0x200
#define RTF_LLINFO 0x400
#define RTF_STATIC 0x800
#define RTF_BLACKHOLE 0x1000
#define RTF_PROTO2 0x4000
#define RTF_PROTO1 0x8000
#define RTF_CLONED 0x2000
#define RTV_MTU 0x1

#define RTM_ADD 0x1
#define RTM_DELETE 0x2
#define RTM_CHANGE 0x3
#define RTM_GET 0x4
#define RTM_LOSING 0x5
#define RTM_REDIRECT 0x6
#define RTM_MISS 0x7
#define RTM_LOCK 0x8
#define RTM_OLDADD 0x9
#define RTM_OLDDEL 0xa
#define RTM_RESOLVE 0xb
#define RTM_NEWADDR 0xc
#define RTM_DELADDR 0xd
#define RTM_OIFINFO 0xe
#define RTM_IFINFO 0xf
#define RTM_IFANNOUNCE 0x10

#define RTAX_DST 0
#define RTAX_GATEWAY 1
#define RTAX_NETMASK 2
#define RTAX_GENMASK 3
#define RTAX_IFP 4
#define RTAX_IFA 5
#define RTAX_AUTHOR 6
#define RTAX_BRD 7
#define RTAX_MAX 8

struct rt_addrinfo {
	int rti_addrs;
	struct sockaddr *rti_info[RTAX_MAX];
};

#define RTFREE(rt) do { \
	if ((rt)->rt_refcnt <= 1) \
		rtfree(rt); \
	else \
		(rt)->rt_refcnt--; \
} while (0)

#define rtalloc1 func_0000B8E0
#define rtredirect func_0000BA60
#define ifa_ifwithroute func_0000BCF0
#define rtrequest func_0000BDD8
#define rt_setgate func_0000C5F0
#define rt_maskedcopy func_0000C818
#define rtinit func_0000C8BC
#define route_init func_0000CF68
#define rtalloc func_0000D038
#define rtfree func_0000D090
#define rt_missmsg func_0000E268
#define rt_ifmsg func_0000E344
struct rtentry *rtalloc1(struct sockaddr *dst, int report);
void rtalloc(struct route *ro);
void rtfree(struct rtentry *rt);
int rtrequest(int req, struct sockaddr *dst, struct sockaddr *gateway, struct sockaddr *netmask, int flags, struct rtentry **ret_nrt);
void rt_missmsg(int type, struct rt_addrinfo *rtinfo, int flags, int error);
void rt_maskedcopy(struct sockaddr *src, struct sockaddr *dst, struct sockaddr *netmask);
int rt_setgate(struct rtentry *rt0, struct sockaddr *dst, struct sockaddr *gate);
void rtredirect(struct sockaddr *dst, struct sockaddr *gateway, struct sockaddr *netmask, int flags, struct sockaddr *src, struct rtentry **rtp);
int rtinit(struct ifaddr *ifa, int cmd, int flags);
void route_init(void);

/* if.h (Sony layout, from pspnet) */
struct ifaddr {
	struct sockaddr *ifa_addr;
	struct sockaddr *ifa_dstaddr;
	struct sockaddr *ifa_netmask;
	struct ifnet *ifa_ifp;
	TAILQ_ENTRY(ifaddr) ifa_list;
	char ifa_unk18[0x28 - 0x18];
	void (*ifa_rtrequest)(int, struct rtentry *, struct sockaddr *);
	int ifa_flags;
	int ifa_refcnt;
	int ifa_metric;
};
#define ifa_broadaddr ifa_dstaddr

struct if_data {
	u_char ifi_type;
	u_char ifi_addrlen;
	u_char ifi_hdrlen;
	char ifi_unk3;
	int ifi_link_state;
	unsigned long long ifi_mtu;
	unsigned long long ifi_metric;
	unsigned long long ifi_baudrate;
	unsigned long long ifi_ipackets;
	unsigned long long ifi_ierrors;
	unsigned long long ifi_opackets;
	unsigned long long ifi_oerrors;
	unsigned long long ifi_collisions;
	unsigned long long ifi_ibytes;
	unsigned long long ifi_obytes;
	unsigned long long ifi_imcasts;
	unsigned long long ifi_omcasts;
	unsigned long long ifi_iqdrops;
	unsigned long long ifi_noproto;
};
#define if_type if_data.ifi_type
#define if_addrlen if_data.ifi_addrlen
#define if_hdrlen if_data.ifi_hdrlen
#define if_link_state if_data.ifi_link_state
#define if_mtu if_data.ifi_mtu
#define if_metric if_data.ifi_metric
#define if_baudrate if_data.ifi_baudrate
#define if_ipackets if_data.ifi_ipackets
#define if_ierrors if_data.ifi_ierrors
#define if_opackets if_data.ifi_opackets
#define if_oerrors if_data.ifi_oerrors
#define if_collisions if_data.ifi_collisions
#define if_ibytes if_data.ifi_ibytes
#define if_obytes if_data.ifi_obytes
#define if_imcasts if_data.ifi_imcasts
#define if_omcasts if_data.ifi_omcasts
#define if_iqdrops if_data.ifi_iqdrops
#define if_noproto if_data.ifi_noproto

struct ifnet {
	void *if_softc;
	TAILQ_ENTRY(ifnet) if_list;
	TAILQ_HEAD(ifaddrhead, ifaddr) if_addrlist;
	char if_xname[16];
	int if_pcount;
	void *if_bpf;
	u_short if_index;
	short if_timer;
	short if_flags;
	char if_unk32[0x38 - 0x32];
	struct if_data if_data;
	int (*if_output)(struct ifnet *, struct mbuf *, struct sockaddr *, struct rtentry *);
	void (*if_input)(struct ifnet *, struct mbuf *);
	void (*if_start)(struct ifnet *);
	int (*if_ioctl)(struct ifnet *, u_long, caddr_t);
	int (*if_init)(struct ifnet *);
	void (*if_watchdog)(struct ifnet *);
	void (*if_drain)(struct ifnet *);
	struct ifqueue_ {
		struct mbuf *ifq_head;
		struct mbuf *ifq_tail;
		int ifq_len;
		int ifq_maxlen;
		int ifq_drops;
	} if_snd;
	struct sockaddr_dl *if_sadl;
	u_int8_t *if_broadcastaddr;
};
#define ifqueue ifqueue_

#define IFF_UP 0x1
#define IFF_BROADCAST 0x2
#define IFF_DEBUG 0x4
#define IFF_LOOPBACK 0x8
#define IFF_POINTOPOINT 0x10
#define IFF_NOTRAILERS 0x20
#define IFF_RUNNING 0x40
#define IFF_NOARP 0x80
#define IFF_PROMISC 0x100
#define IFF_ALLMULTI 0x200
#define IFF_OACTIVE 0x400
#define IFF_SIMPLEX 0x800
#define IFF_LINK0 0x1000
#define IFF_LINK1 0x2000
#define IFF_LINK2 0x4000
#define IFF_MULTICAST 0x8000

/* in_var.h */
struct in_ifaddr {
	struct ifaddr ia_ifa;
	u_int32_t ia_net;
	u_int32_t ia_netmask;
	u_int32_t ia_subnet;
	u_int32_t ia_subnetmask;
	struct in_addr ia_netbroadcast;
	LIST_ENTRY(in_ifaddr) ia_hash;
	TAILQ_ENTRY(in_ifaddr) ia_list;
	struct sockaddr_in ia_addr;
	struct sockaddr_in ia_dstaddr;
	struct sockaddr_in ia_sockmask;
	LIST_HEAD(, in_multi) ia_multiaddrs;
	struct in_multi *ia_allhosts;
	int ia_unk94;
};
#define ia_ifp ia_ifa.ifa_ifp
#define ia_flags ia_ifa.ifa_flags
#define ia_broadaddr ia_dstaddr
#define ifatoia(ifa) ((struct in_ifaddr *)(ifa))
TAILQ_HEAD(in_ifaddrhead_t, in_ifaddr);
extern struct in_ifaddrhead_t in_ifaddrhead;

#define IFP_TO_IA(ifp, ia) { \
	struct ifaddr *ifa; \
	for (ifa = (ifp)->if_addrlist.tqh_first; \
	    ifa != NULL && ifa->ifa_addr->sa_family != AF_INET; \
	    ifa = ifa->ifa_list.tqe_next) \
		continue; \
	(ia) = ifatoia(ifa); \
}

struct in_multi {
	struct in_addr inm_addr;
	struct ifnet *inm_ifp;
	struct in_ifaddr *inm_ia;
	u_int inm_refcount;
	u_int inm_timer;
	LIST_ENTRY(in_multi) inm_list;
	u_int inm_state;
	struct router_info *inm_rti;
};

#define IP_MAX_MEMBERSHIPS 20
struct ip_moptions {
	struct ifnet *imo_multicast_ifp;
	u_int8_t imo_multicast_ttl;
	u_int8_t imo_multicast_loop;
	u_int16_t imo_num_memberships;
	struct in_multi *imo_membership[IP_MAX_MEMBERSHIPS];
};

#define ifa_ifwithaddr func_00008FC4
#define ifa_ifwithladdr func_0000919C
#define in_delmulti func_0001273C
#define ip_freemoptions func_00018DB0
struct ifaddr *ifa_ifwithaddr(struct sockaddr *addr);
struct ifaddr *ifa_ifwithladdr(struct sockaddr *addr);
void in_delmulti(struct in_multi *inm);
void ip_freemoptions(struct ip_moptions *imo);

/* in_pcb.h */
struct inpcb {
	LIST_ENTRY(inpcb) inp_hash;
	CIRCLEQ_ENTRY(inpcb) inp_queue;
	caddr_t inp_ppcb;
	int inp_state;
	u_int16_t inp_fport;
	u_int16_t inp_lport;
	struct socket *inp_socket;
	struct route inp_route;
	int inp_flags;
	struct ip inp_ip;
	struct mbuf *inp_options;
	struct ip_moptions *inp_moptions;
	int inp_errormtu;
	struct inpcbtable *inp_table;
};
#define inp_faddr inp_ip.ip_dst
#define inp_laddr inp_ip.ip_src

LIST_HEAD(inpcbhead, inpcb);
CIRCLEQ_HEAD(inpcbqueue, inpcb);

struct inpcbtable {
	struct inpcbqueue inpt_queue;
	struct inpcbhead *inpt_bindhashtbl;
	struct inpcbhead *inpt_connecthashtbl;
	u_long inpt_bindhash;
	u_long inpt_connecthash;
	u_int16_t inpt_lastport;
	u_int16_t inpt_lastlow;
};

#define INP_ATTACHED 0
#define INP_BOUND 1
#define INP_CONNECTED 2

#define INP_RECVOPTS 0x01
#define INP_RECVRETOPTS 0x02
#define INP_RECVDSTADDR 0x04
#define INP_HDRINCL 0x08
#define INP_HIGHPORT 0x10
#define INP_LOWPORT 0x20
#define INP_ANONPORT 0x40

#define INPLOOKUP_WILDCARD 1
#define sotoinpcb(so) ((struct inpcb *)(so)->so_pcb)

#define INPCBHASH_BIND(table, laddr, lport) \
	&(table)->inpt_bindhashtbl[ \
	    ((ntohl((laddr).s_addr) + ntohs(lport))) & (table)->inpt_bindhash]
#define INPCBHASH_CONNECT(table, faddr, fport, laddr, lport) \
	&(table)->inpt_connecthashtbl[ \
	    ((ntohl((faddr).s_addr) + ntohs(fport)) + \
	     (ntohl((laddr).s_addr) + ntohs(lport))) & (table)->inpt_connecthash]

#define in_pcbbind func_000133CC
#define in_pcbconnect func_00013640
#define in_pcbpurgeif func_00013860
#define in_rtchange func_00013968
#define in_pcblookup_port func_000139A4
#define in_pcblookup_connect func_00013A88
#define in_pcblookup_bind func_00013BC0
#define in_pcbstate func_00013D3C
#define in_selectsrc func_00013E54
#define ip_srcroute func_00016D78
struct mbuf *ip_srcroute(void);
#define in_pcbinit func_0001407C
#define in_pcballoc func_00014110
#define in_pcbdisconnect func_000141C4
#define in_pcbdetach func_000142DC
#define in_setsockaddr func_000143A8
#define in_setpeeraddr func_000143FC
#define in_pcbnotify func_00014450
#define in_pcbnotifyall func_00014614
#define in_losing func_00014710
#define in_pcbrtentry func_000147C0
extern int anonportmin, anonportmax, lowportmin, lowportmax;
extern struct in_addr zeroin_addr;

void in_pcbinit(struct inpcbtable *table, int bindhashsize, int connecthashsize);
int in_pcballoc(struct socket *so, void *v);
int in_pcbbind(void *v, struct mbuf *nam);
int in_pcbconnect(void *v, struct mbuf *nam);
void in_pcbdisconnect(void *v);
void in_pcbdetach(void *v);
void in_setsockaddr(struct inpcb *inp, struct mbuf *nam);
void in_setpeeraddr(struct inpcb *inp, struct mbuf *nam);
int in_pcbnotify(struct inpcbtable *table, struct in_addr faddr, u_int fport_arg, struct in_addr laddr, u_int lport_arg, int errno, void (*notify)(struct inpcb *, int));
void in_pcbnotifyall(struct inpcbtable *table, struct in_addr faddr, int errno, void (*notify)(struct inpcb *, int));
void in_pcbpurgeif(struct inpcbtable *table, struct ifnet *ifp);
void in_losing(struct inpcb *inp);
void in_rtchange(struct inpcb *inp, int errno);
struct inpcb *in_pcblookup_port(struct inpcbtable *table, struct in_addr laddr, u_int lport_arg, int flags);
struct inpcb *in_pcblookup_connect(struct inpcbtable *table, struct in_addr faddr, u_int fport_arg, struct in_addr laddr, u_int lport_arg);
struct inpcb *in_pcblookup_bind(struct inpcbtable *table, struct in_addr laddr, u_int lport_arg);
void in_pcbstate(struct inpcb *inp, int state);
struct rtentry *in_pcbrtentry(struct inpcb *inp);
struct sockaddr_in *in_selectsrc(struct sockaddr_in *sin, struct route *ro, int soopts, struct ip_moptions *mopts, int *errorp);

void *_sce_pspnet_hashinit(int elements, u_long *hashmask);
#define hashinit _sce_pspnet_hashinit
u_int32_t sceNetRand(void);

/* route.c */
struct rttimer {
	TAILQ_ENTRY(rttimer) rtt_next;
	LIST_ENTRY(rttimer) rtt_link;
	struct rttimer_queue *rtt_queue;
	struct rtentry *rtt_rt;
	void (*rtt_func)(struct rtentry *, struct rttimer *);
	long rtt_time;
};

struct rttimer_queue {
	long rtq_timeout;
	TAILQ_HEAD(, rttimer) rtq_head;
	LIST_ENTRY(rttimer_queue) rtq_link;
};

struct route_cb_t {
	int ip_count;
	int ip6_count;
	int ipx_count;
	int ns_count;
	int iso_count;
	int any_count;
};

struct rtstat_t {
	u_short rts_badredirect;
	u_short rts_dynamic;
	u_short rts_newgateway;
	u_short rts_unreach;
	u_short rts_wildcard;
};

extern struct radix_node_head *rt_tables[32];
extern struct rtstat_t rtstat;
extern struct route_cb_t route_cb;
extern int rttrash;
extern int rt_init_done;
extern LIST_HEAD(, rttimer_queue) rttimer_queue_head;
extern struct callout rt_timer_ch;

#define rtable_init func_0000CF04
#define rt_timer_queue_destroy func_0000CB28
#define rt_timer_remove_all func_0000CC10
#define rt_timer_add func_0000CC8C
#define rt_timer_timer func_0000CDB8
#define rt_timer_init func_0000D130
#define rt_timer_queue_create func_0000D188
#define rt_timer_queue_change func_0000D25C
#define rtflushclone1 func_0000D264
#define rtdeletemsg func_0000D2A4
#define ifa_ifwithnet func_00008CC0
#define ifaof_ifpforaddr func_00008E48
#define ifa_ifwithdstaddr func_000090C0
struct ifaddr *ifa_ifwithnet(struct sockaddr *addr);
struct ifaddr *ifaof_ifpforaddr(struct sockaddr *addr, struct ifnet *ifp);
struct ifaddr *ifa_ifwithdstaddr(struct sockaddr *addr);
struct ifaddr *ifa_ifwithroute(int flags, struct sockaddr *dst, struct sockaddr *gateway);
void rt_newaddrmsg(int cmd, struct ifaddr *ifa, int error, struct rtentry *rt);
#define rt_newaddrmsg func_0000E02C
void rt_timer_remove_all(struct rtentry *rt);
void rt_timer_timer(void *arg);
void _sce_pspnet_ifafree(struct ifaddr *ifa);
#define ifafree _sce_pspnet_ifafree
#define IFAFREE(ifa) do { if (--(ifa)->ifa_refcnt == 0) ifafree(ifa); } while (0)
#define IFAREF(ifa) ((ifa)->ifa_refcnt++)
long sceNetGetSystemClockSec(void);

/* raw_cb.h */
struct sockproto {
	u_short sp_family;
	u_short sp_protocol;
};
struct rawcb {
	LIST_ENTRY(rawcb) rcb_list;
	struct socket *rcb_socket;
	struct sockaddr *rcb_faddr;
	struct sockaddr *rcb_laddr;
	struct sockproto rcb_proto;
};
#define sotorawcb(so) ((struct rawcb *)(so)->so_pcb)
LIST_HEAD(rawcbhead, rawcb);
extern struct rawcbhead rawcb;
extern u_long raw_sendspace, raw_recvspace;
#define raw_attach func_0000ECA8
#define raw_detach func_0000ED48
#define raw_disconnect func_0000ED94
#define raw_input func_0000EDF8
#define raw_usrreq func_0000EFD0
#define raw_init func_0000F1F8
#define raw_ctlinput func_0000F204
#define raw_setsockaddr func_0000F20C
#define raw_setpeeraddr func_0000F238
int raw_attach(struct socket *so, int proto);
void raw_detach(struct rawcb *rp);
void raw_disconnect(struct rawcb *rp);
void raw_input(struct mbuf *m0, ...);
int raw_usrreq(struct socket *so, int req, struct mbuf *m, struct mbuf *nam, struct mbuf *control);
void raw_init(void);
void *raw_ctlinput(int cmd, struct sockaddr *arg, void *d);
void raw_setsockaddr(struct rawcb *rp, struct mbuf *nam);
void raw_setpeeraddr(struct rawcb *rp, struct mbuf *nam);

/* if.h queue macros / netisr */
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
#define NETISR_IP 2
void _sce_pspnet_schednetintr_with_evf(int isr);
#define schednetisr(isr) _sce_pspnet_schednetintr_with_evf(isr)
extern struct ifqueue ipintrq;
void _sce_pspnet_if_attach(struct ifnet *ifp);
#define if_attach _sce_pspnet_if_attach
struct ifreq {
	char ifr_name[16];
	union {
		struct sockaddr ifru_addr;
		struct sockaddr ifru_dstaddr;
		struct sockaddr ifru_broadaddr;
		short ifru_flags;
		int ifru_metric;
		int ifru_mtu;
		caddr_t ifru_data;
	} ifr_ifru;
};
#define ifr_addr ifr_ifru.ifru_addr
#define ifr_dstaddr ifr_ifru.ifru_dstaddr
#define ifr_broadaddr ifr_ifru.ifru_broadaddr
#define ifr_flags ifr_ifru.ifru_flags
#define ifr_metric ifr_ifru.ifru_metric
#define ifr_mtu ifr_ifru.ifru_mtu
#define ifr_data ifr_ifru.ifru_data
#define SIOCSIFADDR 0x8020690C
#define SIOCADDMULTI 0x80206931
#define SIOCDELMULTI 0x80206932
#define IFT_LOOP 0x18

/* if_loop.c */
extern struct ifnet loif;
#define looutput func_0000F264
#define loioctl func_0000F5B4
#define loopattach func_0000F628
#define lortrequest func_0000F6B4
int looutput(struct ifnet *ifp, struct mbuf *m, struct sockaddr *dst, struct rtentry *rt);
int loioctl(struct ifnet *ifp, u_long cmd, caddr_t data);
void loopattach(int n);
void lortrequest(int cmd, struct rtentry *rt, struct sockaddr *sa);

/* rtsock.c */
struct rt_msghdr {
	u_short rtm_msglen;
	u_char rtm_version;
	u_char rtm_type;
	u_short rtm_index;
	int rtm_flags;
	int rtm_addrs;
	int rtm_pid;
	int rtm_seq;
	int rtm_errno;
	int rtm_use;
	u_long rtm_inits;
	struct rt_metrics rtm_rmx;
};
struct if_msghdr {
	u_short ifm_msglen;
	u_char ifm_version;
	u_char ifm_type;
	int ifm_addrs;
	int ifm_flags;
	u_short ifm_index;
	struct if_data ifm_data;
};
struct ifa_msghdr {
	u_short ifam_msglen;
	u_char ifam_version;
	u_char ifam_type;
	int ifam_addrs;
	int ifam_flags;
	u_short ifam_index;
	int ifam_metric;
};
struct if_announcemsghdr {
	u_short ifan_msglen;
	u_char ifan_version;
	u_char ifan_type;
	u_short ifan_index;
	char ifan_name[16];
	u_short ifan_what;
};
struct walkarg {
	int w_op;
	int w_arg;
	int w_given;
	int w_needed;
	caddr_t w_where;
	int w_tmemsize;
	int w_tmemneeded;
	caddr_t w_tmem;
};
#define RTM_VERSION 3
#define RTA_IFP 0x10
#define RTA_IFA 0x20
#define RTV_RPIPE 0x8
#define RTV_SPIPE 0x10
#define RTV_SSTHRESH 0x20
#define RTV_RTT 0x40
#define RTV_RTTVAR 0x80
#define RTV_HOPCOUNT 0x2
#define RTV_EXPIRE 0x4
#define NET_RT_DUMP 1
#define NET_RT_FLAGS 2
#define NET_RT_IFLIST 4
#define AF_MAX 31
#define PF_ROUTE 17
extern struct sockaddr route_dst, route_src;
extern struct sockproto route_proto;
#define route_usrreq func_0000D3C8
#define route_output func_0000D618
#define rt_setmetrics func_0000DD34
#define rt_xaddrs func_0000DDC0
#define rt_msg2 func_0000DE48
#define rt_missmsg func_0000E268
#define rt_ifmsg func_0000E344
#define rt_ifannouncemsg func_0000E448
#define rt_msg1 func_0000E518
#define sysctl_rtable func_0000E678
#define sysctl_dumpentry func_0000E89C
#define sysctl_iflist func_0000EA48
void rt_ifmsg(struct ifnet *ifp);
void rt_ifannouncemsg(struct ifnet *ifp, int what);
TAILQ_HEAD(ifnet_head, ifnet);
int _sce_pspnet_get_if_core_variables(int *a, int *b, int *c, struct ifnet_head *d);

/* if.c (inet side) */
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
#define PRU_PURGEIF 22
#define PRC_IFDOWN 0
#define IFAN_ARRIVAL 0
#define IFAN_DEPARTURE 1
int _sce_pspnet_if_nulloutput(struct ifnet *, struct mbuf *, struct sockaddr *, struct rtentry *);
#define if_nulloutput _sce_pspnet_if_nulloutput
void _sce_pspnet_link_rtrequest(int, struct rtentry *, struct sockaddr *);
int _sce_pspnet_start_of_inet_module_in_if_core(void (*a)(int, struct rtentry *, struct sockaddr *), void (*b)(void),
	void (*c)(struct ifnet *), void (*d)(struct ifaddr *), void (*e)(struct ifnet *, int),
	void (*f)(struct ifnet *), void (*g)(struct ifnet *), void (*h)(struct ifnet *),
	void (*i)(struct ifnet *), void (*j)(struct ifnet *), int (*k)(void), int (*l)(struct socket *, int *),
	int (*m)(struct socket *, u_long, caddr_t, struct ifnet *));
void _sce_pspnet_stop_of_inet_module_in_if_core(void);
#define if_rt_walktree func_00008F7C
#define ifa_ifwithladdr func_0000919C
#define ifa_ifwithaf func_00009364
#define link_rtrequest func_000096EC
int if_rt_walktree(struct radix_node *rn, void *v);
struct ifaddr *ifa_ifwithladdr(struct sockaddr *addr);
struct ifaddr *ifa_ifwithaf(int af);
void link_rtrequest(int cmd, struct rtentry *rt, struct sockaddr *sa);

/* if_ether.h */
#define ETHER_ADDR_LEN 6
struct ether_header {
	u_int8_t ether_dhost[ETHER_ADDR_LEN];
	u_int8_t ether_shost[ETHER_ADDR_LEN];
	u_int16_t ether_type;
} __attribute__((__packed__));
#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_ARP 0x0806
#define ETHERTYPE_REVARP 0x8035
#define ETHER_MAP_IP_MULTICAST(ipaddr, enaddr) do { \
	(enaddr)[0] = 0x01; \
	(enaddr)[1] = 0x00; \
	(enaddr)[2] = 0x5e; \
	(enaddr)[3] = ((u_int8_t *)ipaddr)[1] & 0x7f; \
	(enaddr)[4] = ((u_int8_t *)ipaddr)[2]; \
	(enaddr)[5] = ((u_int8_t *)ipaddr)[3]; \
} while (0)
struct arphdr {
	u_int16_t ar_hrd;
	u_int16_t ar_pro;
	u_int8_t ar_hln;
	u_int8_t ar_pln;
	u_int16_t ar_op;
} __attribute__((__packed__));
#define ARPHRD_ETHER 1
#define ARPOP_REQUEST 1
#define ARPOP_REPLY 2
#define ARPOP_REVREQUEST 3
#define ARPOP_REVREPLY 4
#define ar_sha(ap) (((caddr_t)((ap) + 1)) + 0)
#define ar_spa(ap) (((caddr_t)((ap) + 1)) + (ap)->ar_hln)
#define ar_tha(ap) (((caddr_t)((ap) + 1)) + (ap)->ar_hln + (ap)->ar_pln)
#define ar_tpa(ap) (((caddr_t)((ap) + 1)) + 2 * (ap)->ar_hln + (ap)->ar_pln)
#define AF_ARP 28
#define PF_ARP AF_ARP
#define pseudo_AF_HDRCMPLT 30
#define NETISR_ARP 28
#define LLADDR(s) ((caddr_t)((s)->sdl_data + (s)->sdl_nlen))
extern u_int8_t etherbroadcastaddr[ETHER_ADDR_LEN];
extern u_int8_t ether_ipmulticast_min[ETHER_ADDR_LEN];
extern u_int8_t ether_ipmulticast_max[ETHER_ADDR_LEN];
extern struct ifqueue arpintrq;
#define arpresolve func_0000FB90
#define revarpinput func_00010770
int arpresolve(struct ifnet *ifp, struct rtentry *rt, struct mbuf *m, struct sockaddr *dst, u_char *desten);
void revarpinput(struct mbuf *m);
#define ether_multiaddr func_000097C4
#define ether_output func_000099FC
int ether_output(struct ifnet *ifp, struct mbuf *m0, struct sockaddr *dst, struct rtentry *rt0);
int _sce_pspnet_start_of_inet_module_in_if_ethersubr_core(int (*a)(struct ifnet *, struct mbuf *, struct sockaddr *, struct rtentry *),
	void (*b)(struct ifnet *, struct mbuf *, u_short, void *), void (*c)(struct ifnet *, struct mbuf *, u_short, void *, struct ifqueue **, int *, int *),
	int (*d)(struct sockaddr *, u_int8_t *, u_int8_t *));
void _sce_pspnet_stop_of_inet_module_in_if_ethersubr_core(void);
extern void (*D_0002EB6C)(struct mbuf *, u_short, void *);
extern int D_0002EB70;

/* in_var.h: address hash */
#define IN_IFADDR_HASH_SIZE 509
LIST_HEAD(in_ifaddrhashhead, in_ifaddr);
extern struct in_ifaddrhashhead *in_ifaddrhashtbl;
#define IN_IFADDR_HASH(x) in_ifaddrhashtbl[(u_long)(x) % IN_IFADDR_HASH_SIZE]
#define IA_SIN(ia) (&(((struct in_ifaddr *)(ia))->ia_addr))
#define INADDR_TO_IA(addr, ia) { \
	for (ia = IN_IFADDR_HASH((addr).s_addr).lh_first; \
	    ia != NULL; \
	    ia = ia->ia_hash.le_next) { \
		if (in_hosteq(ia->ia_addr.sin_addr, (addr)) && \
		    (ia->ia_ifp->if_flags & IFF_UP) != 0) \
			break; \
	} \
}
#define INADDR_TO_IFP(addr, ifp) { \
	struct in_ifaddr *ia; \
	INADDR_TO_IA(addr, ia); \
	(ifp) = (ia == NULL) ? NULL : ia->ia_ifp; \
}
#define NEXT_IA_WITH_SAME_ADDR(ia) { \
	struct in_addr addr; \
	addr = ia->ia_addr.sin_addr; \
	do { \
		ia = ia->ia_hash.le_next; \
	} while ((ia != NULL) && !in_hosteq(ia->ia_addr.sin_addr, addr)); \
}
#define rt_expire rt_rmx.rmx_expire
#define RTF_ANNOUNCE RTF_PROTO2

/* if_inarp.h / if_arp.c */
struct llinfo_arp {
	LIST_ENTRY(llinfo_arp) la_list;
	struct rtentry *la_rt;
	struct mbuf *la_hold;
	long la_asked;
};
struct sockaddr_inarp {
	u_int8_t sin_len;
	u_int8_t sin_family;
	u_int16_t sin_port;
	struct in_addr sin_addr;
	struct in_addr sin_srcaddr;
	u_int16_t sin_tos;
	u_int16_t sin_other;
};
#define SIN_PROXY 1
#define ETHERTYPE_IPTRAILERS 0x1000
#define arp_rtrequest func_0000F6C8
#define arpintr func_0000FD8C
#define in_revarpinput func_00010508
#define arp_drain func_00010648
#define arpioctl func_000106E0
#define arp_ifinit func_000106E8
#define revarprequest func_000107F8
#define revarpwhoarewe func_00010938
void arp_rtrequest(int req, struct rtentry *rt, struct sockaddr *sa);
void arpintr(void);
void in_revarpinput(struct mbuf *m);
void arp_drain(void);
int arpioctl(u_long cmd, caddr_t data);
void arp_ifinit(struct ifnet *ifp, struct ifaddr *ifa);
void revarprequest(struct ifnet *ifp);
int revarpwhoarewe(struct ifnet *ifp, struct in_addr *serv_in, struct in_addr *clnt_in);

/* in.c */
#define SIOCSIFDSTADDR 0x8020690E
#define SIOCSIFBRDADDR 0x80206913
#define SIOCSIFNETMASK 0x80206916
#define SIOCDIFADDR 0x80206919
#define SIOCAIFADDR 0x8040691A
#define SIOCGIFALIAS 0xC040691B
#define SIOCALIFADDR 0x8118691C
#define SIOCGLIFADDR 0xC118691D
#define SIOCDLIFADDR 0x8118691E
#define SIOCGIFADDR 0xC0206921
#define SIOCGIFDSTADDR 0xC0206922
#define SIOCGIFBRDADDR 0xC0206923
#define SIOCGIFNETMASK 0xC0206925
#define IFA_ROUTE RTF_UP
struct sockaddr_storage {
	u_char ss_len;
	u_char ss_family;
	char __ss_pad1[6];
	long long __ss_align;
	char __ss_pad2[112];
};
struct if_laddrreq {
	char iflr_name[16];
	unsigned int flags;
#define IFLR_PREFIX 0x8000
	unsigned int prefixlen;
	struct sockaddr_storage addr;
	struct sockaddr_storage dstaddr;
};
struct in_aliasreq {
	char ifra_name[16];
	struct sockaddr_in ifra_addr;
	struct sockaddr_in ifra_dstaddr;
#define ifra_broadaddr ifra_dstaddr
	struct sockaddr_in ifra_mask;
};
#define IN_LOOKUP_MULTI(addr, ifp, inm) { \
	struct in_ifaddr *ia; \
	IFP_TO_IA((ifp), ia); \
	if (ia == NULL) \
		(inm) = NULL; \
	else \
		for ((inm) = ia->ia_multiaddrs.lh_first; \
		    (inm) != NULL && !in_hosteq((inm)->inm_addr, (addr)); \
		     (inm) = inm->inm_list.le_next) \
			 continue; \
}
#define in_control func_00010C04
#define in_purgeaddr func_000116A4
#define in_ifscrub func_00011D5C
#define in_ifinit func_00011DC8
#define in_savemkludge func_0001229C
#define in_restoremkludge func_000123C0
#define in_addmulti func_000124E4
#define in_delmulti func_0001273C
#define in_localaddr func_00012818
#define in_canforward func_000128EC
#define in_socktrim func_0001298C
#define in_fmtaddr func_000129D0
#define in_setmaxmtu func_00012A90
#define in_purgeif func_00012B10
#define in_broadcast func_00012BE8
#define in_purgemkludge func_00012CD8
#define in_lifaddr_ioctl func_0001184C
int in_control(struct socket *so, u_long cmd, caddr_t data, struct ifnet *ifp);
void in_purgeaddr(struct ifaddr *ifa, struct ifnet *ifp);
void in_ifscrub(struct ifnet *ifp, struct in_ifaddr *ia);
int in_ifinit(struct ifnet *ifp, struct in_ifaddr *ia, struct sockaddr_in *sin, int scrub);
void in_savemkludge(struct in_ifaddr *oia);
void in_restoremkludge(struct in_ifaddr *ia, struct ifnet *ifp);
struct in_multi *in_addmulti(struct in_addr *ap, struct ifnet *ifp);
void in_delmulti(struct in_multi *inm);
int in_localaddr(struct in_addr in);
int in_canforward(struct in_addr in);
void in_socktrim(struct sockaddr_in *ap);
const char *in_fmtaddr(struct in_addr addr);
void in_setmaxmtu(void);
void in_purgeif(struct ifnet *ifp);
int in_broadcast(struct in_addr in, struct ifnet *ifp);
void in_purgemkludge(struct ifnet *ifp);
#define igmp_joingroup func_0001B3D0
#define igmp_leavegroup func_0001B50C
void igmp_joingroup(struct in_multi *inm);
void igmp_leavegroup(struct in_multi *inm);

/* igmp.h / igmp_var.h */
struct igmp {
	u_int8_t igmp_type;
	u_int8_t igmp_code;
	u_int16_t igmp_cksum;
	struct in_addr igmp_group;
} __attribute__((__packed__));
#define IGMP_MINLEN 8
#define IGMP_HOST_MEMBERSHIP_QUERY 0x11
#define IGMP_v1_HOST_MEMBERSHIP_REPORT 0x12
#define IGMP_DVMRP 0x13
#define IGMP_PIM 0x14
#define IGMP_v2_HOST_MEMBERSHIP_REPORT 0x16
#define IGMP_HOST_LEAVE_MESSAGE 0x17
#define IGMP_MTRACE_REPLY 0x1e
#define IGMP_MTRACE_QUERY 0x1f
#define IGMP_MAX_HOST_REPORT_DELAY 10
#define IGMP_TIMER_SCALE 10
#define IGMP_DELAYING_MEMBER 1
#define IGMP_IDLE_MEMBER 2
#define IGMP_LAZY_MEMBER 3
#define IGMP_SLEEPING_MEMBER 4
#define IGMP_AWAKENING_MEMBER 5
#define IGMP_v1_ROUTER 1
#define IGMP_v2_ROUTER 2
#define IGMP_AGE_THRESHOLD 540
struct igmpstat_t {
	u_quad_t igps_rcv_total;
	u_quad_t igps_rcv_tooshort;
	u_quad_t igps_rcv_badsum;
	u_quad_t igps_rcv_queries;
	u_quad_t igps_rcv_badqueries;
	u_quad_t igps_rcv_reports;
	u_quad_t igps_rcv_badreports;
	u_quad_t igps_rcv_ourreports;
	u_quad_t igps_snd_reports;
};
#define IGMP_RANDOM_DELAY(X) (sceNetRand() % (X) + 1)
struct router_info {
	struct ifnet *rti_ifp;
	int rti_type;
	int rti_age;
	struct router_info *rti_next;
};
struct in_multistep {
	struct in_ifaddr *i_ia;
	struct in_multi *i_inm;
};
#define IN_NEXT_MULTI(step, inm) { \
	if (((inm) = (step).i_inm) != NULL) \
		(step).i_inm = (inm)->inm_list.le_next; \
	else \
		while ((step).i_ia != NULL) { \
			(inm) = (step).i_ia->ia_multiaddrs.lh_first; \
			(step).i_ia = (step).i_ia->ia_list.tqe_next; \
			if ((inm) != NULL) { \
				(step).i_inm = (inm)->inm_list.le_next; \
				break; \
			} \
		} \
}
#define PR_SLOWHZ 2
#define PR_FASTHZ 5
#define IN_FIRST_MULTI(step, inm) { \
	(step).i_ia = in_ifaddrhead.tqh_first; \
	(step).i_inm = NULL; \
	IN_NEXT_MULTI((step), (inm)); \
}
#define IPPROTO_IGMP 2
#define IP_MULTICASTOPTS 0
#define igmp_input func_0001A5A4
#define igmp_fasttimo func_0001B084
#define igmp_sendpkt func_0001B1D0
#define igmp_init func_0001B398
#define igmp_slowtimo func_0001B57C
#define rip_input func_0001B5E8
#define ip_output func_00016F60
int ip_output(struct mbuf *m0, ...);
void rip_input(struct mbuf *m, ...);

/* ip_var.h */
struct ipstat_t {
	u_quad_t ips_total;
	u_quad_t ips_badsum;
	u_quad_t ips_tooshort;
	u_quad_t ips_toosmall;
	u_quad_t ips_badhlen;
	u_quad_t ips_badlen;
	u_quad_t ips_fragments;
	u_quad_t ips_fragdropped;
	u_quad_t ips_fragtimeout;
	u_quad_t ips_forward;
	u_quad_t ips_fastforward;
	u_quad_t ips_cantforward;
	u_quad_t ips_redirectsent;
	u_quad_t ips_noproto;
	u_quad_t ips_delivered;
	u_quad_t ips_localout;
	u_quad_t ips_odropped;
	u_quad_t ips_reassembled;
	u_quad_t ips_fragmented;
	u_quad_t ips_ofragments;
	u_quad_t ips_cantfrag;
	u_quad_t ips_badoptions;
	u_quad_t ips_noroute;
	u_quad_t ips_badvers;
	u_quad_t ips_rawout;
	u_quad_t ips_badfrags;
	u_quad_t ips_rcvmemdrop;
	u_quad_t ips_toolong;
	u_quad_t ips_nogif;
};
extern struct ipstat_t ipstat;
extern u_int16_t ip_id;
extern struct protosw inetsw[];
extern u_char ip_protox[];
#define IP_FORWARDING 0x1
#define IP_RAWOUTPUT 0x2
#define IP_RETURNMTU 0x4
#define IP_MTUDISC 0x0400
#define IP_ROUTETOIF SO_DONTROUTE
#define IP_ALLOWBROADCAST SO_BROADCAST
#define IP_MAXPACKET 65535
#define MAXTTL 255
#define IPDEFTTL 64
#define IPPROTO_IP 0
#define IPPROTO_ICMP 1
#define IPPROTO_TCP 6
#define IPPROTO_UDP 17
#define IPPROTO_RAW 255
#define IP_OPTIONS 1
#define IP_HDRINCL 2
#define IP_TOS 3
#define IP_TTL 4
#define IP_RECVOPTS 5
#define IP_RECVRETOPTS 6
#define IP_RECVDSTADDR 7
#define IP_RETOPTS 8
#define IP_MULTICAST_IF 9
#define IP_MULTICAST_TTL 10
#define IP_MULTICAST_LOOP 11
#define IP_ADD_MEMBERSHIP 12
#define IP_DROP_MEMBERSHIP 13
#define IP_PORTRANGE 19
#define IP_RECVIF 20
#define IP_ERRORMTU 21
#define INP_RECVIF 0x80
#define M_SOOPTS 10
typedef u_int32_t n_long;
#define ip_savecontrol func_00016628
#define ip_ctloutput func_00017F60
void ip_savecontrol(struct inpcb *inp, struct mbuf **mp, struct ip *ip, struct mbuf *m);
int ip_ctloutput(int op, struct socket *so, int level, int optname, struct mbuf **mp);
#define INP_CONTROLOPTS (INP_RECVOPTS | INP_RECVRETOPTS | INP_RECVDSTADDR | INP_RECVIF)
#define icmp_error func_00018E1C
void icmp_error(struct mbuf *n, int type, int code, n_long dest, struct ifnet *destifp);
#define rip_output func_0001B99C
#define rip_ctloutput func_0001BBE8
#define rip_usrreq func_0001BD0C
#define rip_init func_0001C144
#define rip_bind func_0001C180
#define rip_connect func_0001C248
#define rip_disconnect func_0001C2E0
extern struct inpcbtable rawcbtable;

/* udp.h / udp_var.h */
struct udphdr {
	u_int16_t uh_sport;
	u_int16_t uh_dport;
	u_int16_t uh_ulen;
	u_int16_t uh_sum;
} __attribute__((__packed__));
struct udpiphdr {
	struct ipovly ui_i;
	struct udphdr ui_u;
} __attribute__((__packed__));
#define ui_x1 ui_i.ih_x1
#define ui_pr ui_i.ih_pr
#define ui_len ui_i.ih_len
#define ui_src ui_i.ih_src
#define ui_dst ui_i.ih_dst
#define ui_sport ui_u.uh_sport
#define ui_dport ui_u.uh_dport
#define ui_ulen ui_u.uh_ulen
#define ui_sum ui_u.uh_sum
struct udpstat_t {
	u_quad_t udps_ipackets;
	u_quad_t udps_hdrops;
	u_quad_t udps_badsum;
	u_quad_t udps_badlen;
	u_quad_t udps_noport;
	u_quad_t udps_noportbcast;
	u_quad_t udps_fullsock;
	u_quad_t udps_pcbhashmiss;
	u_quad_t udps_opackets;
};
#define UDPCTL_CHECKSUM 1
#define UDPCTL_SENDSPACE 2
#define UDPCTL_RECVSPACE 3
#define UDPCTL_STATS 4
#define ENOTDIR 20
#define sysctl_int func_000087F0
#define sysctl_rdstruct func_00008BB4
int sysctl_int(void *oldp, size_t *oldlenp, void *newp, size_t newlen, int *valp);
int sysctl_rdstruct(void *oldp, size_t *oldlenp, void *newp, const void *sp, int len);
#define sysctl_rdint func_000088AC
int sysctl_rdint(void *oldp, size_t *oldlenp, void *newp, int val);
#define ip_stripoptions func_00016EAC
void ip_stripoptions(struct mbuf *m, struct mbuf *mopt);
#define udp_input func_0001C30C
#define udp4_realinput func_0001C60C
#define udp_output func_0001C880
#define udp_usrreq func_0001CAFC
#define udp_init func_0001CE38
#define udp_ctlinput func_0001CE9C
#define udp_sysctl func_0001CFDC
#define udp4_sendup func_0001D0B0
#define udp_notify func_0001D1E4
#define PRC_NCMDS 21
#define PRC_REDIRECT_NET 14
#define PRC_REDIRECT_HOST 15
#define PRC_REDIRECT_TOSNET 16
#define PRC_REDIRECT_TOSHOST 17
#define PRC_HOSTDEAD 6
#define PRC_MSGSIZE 5
#define PRC_IS_REDIRECT(cmd) ((cmd) >= PRC_REDIRECT_NET && (cmd) <= PRC_REDIRECT_TOSHOST)
extern int ip_defttl;
extern int inetctlerrmap[];

/* ip_icmp.h / icmp_var.h */
typedef u_int16_t n_short;
typedef u_int32_t n_time;
struct icmp_ra_addr {
	u_int32_t ira_addr;
	u_int32_t ira_preference;
} __attribute__((__packed__));

struct icmp {
	u_int8_t  icmp_type;
	u_int8_t  icmp_code;
	u_int16_t icmp_cksum;
	union {
		u_int8_t  ih_pptr;
		struct in_addr ih_gwaddr;
		struct ih_idseq {
			  n_short icd_id;
			  n_short icd_seq;
		} ih_idseq __attribute__((__packed__));
		int32_t   ih_void;


		struct ih_pmtu {
			  n_short ipm_void;
			  n_short ipm_nextmtu;
		} ih_pmtu __attribute__((__packed__));
		struct ih_rtradv {
			u_int8_t irt_num_addrs;
			u_int8_t irt_wpa;
			u_int16_t irt_lifetime;
		} ih_rtradv __attribute__((__packed__));
	} icmp_hun ;
#define	icmp_pptr	  icmp_hun.ih_pptr
#define	icmp_gwaddr	  icmp_hun.ih_gwaddr
#define	icmp_id		  icmp_hun.ih_idseq.icd_id
#define	icmp_seq	  icmp_hun.ih_idseq.icd_seq
#define	icmp_void	  icmp_hun.ih_void
#define	icmp_pmvoid	  icmp_hun.ih_pmtu.ipm_void
#define	icmp_nextmtu	  icmp_hun.ih_pmtu.ipm_nextmtu
#define icmp_num_addrs    icmp_hun.ih_rtradv.irt_num_addrs
#define icmp_wpa	  icmp_hun.ih_rtradv.irt_wpa
#define icmp_lifetime	  icmp_hun.ih_rtradv.irt_lifetime
	union {
		struct id_ts {
			  n_time its_otime;
			  n_time its_rtime;
			  n_time its_ttime;
		} id_ts __attribute__((__packed__));
		struct id_ip  {
			  struct ip idi_ip;

		} id_ip __attribute__((__packed__));
		struct icmp_ra_addr id_radv;
		u_int32_t id_mask;
		int8_t	  id_data[1];
	} icmp_dun ;
#define	icmp_otime	  icmp_dun.id_ts.its_otime
#define	icmp_rtime	  icmp_dun.id_ts.its_rtime
#define	icmp_ttime	  icmp_dun.id_ts.its_ttime
#define	icmp_ip		  icmp_dun.id_ip.idi_ip
#define icmp_radv	  icmp_dun.id_mask
#define	icmp_mask	  icmp_dun.id_mask
#define	icmp_data	  icmp_dun.id_data
};

#define	ICMP_MINLEN	8
#define	ICMP_TSLEN	(8 + 3 * sizeof (n_time))
#define	ICMP_MASKLEN	12
#define	ICMP_ADVLENMIN	(8 + sizeof (struct ip) + 8)
#define	ICMP_ADVLEN(p)	(8 + ((p)->icmp_ip.ip_hl << 2) + 8)


#define	ICMP_ECHOREPLY		0
#define	ICMP_UNREACH		3
#define		ICMP_UNREACH_NET	0
#define		ICMP_UNREACH_HOST	1
#define		ICMP_UNREACH_PROTOCOL	2
#define		ICMP_UNREACH_PORT	3
#define		ICMP_UNREACH_NEEDFRAG	4
#define		ICMP_UNREACH_SRCFAIL	5
#define		ICMP_UNREACH_NET_UNKNOWN 6
#define		ICMP_UNREACH_HOST_UNKNOWN 7
#define		ICMP_UNREACH_ISOLATED	8
#define		ICMP_UNREACH_NET_PROHIB	9
#define		ICMP_UNREACH_HOST_PROHIB 10
#define		ICMP_UNREACH_TOSNET	11
#define		ICMP_UNREACH_TOSHOST	12
#define		ICMP_UNREACH_ADMIN_PROHIBIT 13
#define	ICMP_SOURCEQUENCH	4
#define	ICMP_REDIRECT		5
#define		ICMP_REDIRECT_NET	0
#define		ICMP_REDIRECT_HOST	1
#define		ICMP_REDIRECT_TOSNET	2
#define		ICMP_REDIRECT_TOSHOST	3
#define	ICMP_ECHO		8
#define	ICMP_ROUTERADVERT	9
#define	ICMP_ROUTERSOLICIT	10
#define	ICMP_TIMXCEED		11
#define		ICMP_TIMXCEED_INTRANS	0
#define		ICMP_TIMXCEED_REASS	1
#define	ICMP_PARAMPROB		12
#define		ICMP_PARAMPROB_OPTABSENT 1
#define	ICMP_TSTAMP		13
#define	ICMP_TSTAMPREPLY	14
#define	ICMP_IREQ		15
#define	ICMP_IREQREPLY		16
#define	ICMP_MASKREQ		17
#define	ICMP_MASKREPLY		18

#define	ICMP_MAXTYPE		18

struct icmpstat_t {
	u_quad_t icps_error;
	u_quad_t icps_oldshort;
	u_quad_t icps_oldicmp;
	u_quad_t icps_outhist[ICMP_MAXTYPE + 1];
	u_quad_t icps_badcode;
	u_quad_t icps_tooshort;
	u_quad_t icps_checksum;
	u_quad_t icps_badlen;
	u_quad_t icps_reflect;
	u_quad_t icps_inhist[ICMP_MAXTYPE + 1];
};
#define ICMPCTL_MASKREPL 1
#define ICMPCTL_RETURNDATABYTES 3
#define ICMPCTL_ERRPPSLIMIT 4
#define ICMPCTL_STATS 5
#define ICMP_INFOTYPE(type) \
	((type) == ICMP_ECHOREPLY || (type) == ICMP_ECHO || \
	(type) == ICMP_ROUTERADVERT || (type) == ICMP_ROUTERSOLICIT || \
	(type) == ICMP_TSTAMP || (type) == ICMP_TSTAMPREPLY || \
	(type) == ICMP_IREQ || (type) == ICMP_IREQREPLY || \
	(type) == ICMP_MASKREQ || (type) == ICMP_MASKREPLY)
#define icmp_input func_000192B8
#define icmp_reflect func_000198F4
#define icmp_send func_00019F0C
#define iptime func_00019FBC
#define icmp_sysctl func_0001A030
#define icmp_mtudisc func_0001A128
#define ip_next_mtu func_0001A398
#define icmp_ratelimit func_0001A410
#define icmp_mtudisc_callback_register func_0001A418
#define icmp_init func_0001A49C
#define icmp_mtudisc_timeout func_0001A548
void icmp_reflect(struct mbuf *m);
void icmp_send(struct mbuf *m, struct mbuf *opts);
n_time iptime(void);
int ip_next_mtu(int mtu, int dir);
struct timeval;
void _sce_pspnet_microtime(struct timeval *tv);
#define microtime _sce_pspnet_microtime

#define PRC_IFUP 2
#define PRC_ROUTEDEAD 1
#define PRC_QUENCH2 3
#define PRC_QUENCH 4
#define PRC_HOSTUNREACH 7
#define PRC_UNREACH_NET 8
#define PRC_UNREACH_HOST 9
#define PRC_UNREACH_PROTOCOL 10
#define PRC_UNREACH_PORT 11
#define PRC_UNREACH_SRCFAIL 13
#define PRC_TIMXCEED_INTRANS 18
#define PRC_TIMXCEED_REASS 19
#define PRC_PARAMPROB 20
#define IPOPT_EOL 0
#define IPOPT_NOP 1
#define IPOPT_RR 7
#define IPOPT_TS 68
#define IPOPT_SECURITY 130
#define IPOPT_LSRR 131
#define IPOPT_SATID 136
#define IPOPT_SSRR 137
#define IPOPT_RA 148
#define IPOPT_OPTVAL 0
#define IPOPT_OLEN 1
#define IPOPT_OFFSET 2
#define IPOPT_MINOFF 4
#define IPOPT_COPIED(o) ((o) & 0x80)
#define IPOPT_TS_TSONLY 0
#define IPOPT_TS_TSANDADDR 1
#define IPOPT_TS_PRESPEC 3
#define M_AUTHIPHDR 0x0010
#define M_DECRYPTED 0x0020
#define M_LOOP 0x0040
#define M_AUTHIPDGM 0x0080
#define M_CANFASTFWD 0x0400
#define IP_RF 0x8000
#define IP_DF 0x4000
#define IP_MF 0x2000
#define IP_OFFMASK 0x1fff
#define IPVERSION 4
struct timeval {
	u_long tv_sec;
	u_long tv_usec;
};

/* ip_output.c */
#define MAX_IPOPTLEN 40
#ifndef offsetof
#define offsetof(t, m) ((size_t)&((t *)0)->m)
#endif
struct ipoption {
	struct in_addr ipopt_dst;
	int8_t ipopt_list[MAX_IPOPTLEN];
};
struct ip_mreq {
	struct in_addr imr_multiaddr;
	struct in_addr imr_interface;
};
#define IP_DEFAULT_MULTICAST_TTL 1
#define IP_DEFAULT_MULTICAST_LOOP 1
#define IP_PORTRANGE_DEFAULT 0
#define IP_PORTRANGE_HIGH 1
#define IP_PORTRANGE_LOW 2
#define ip_insertoptions func_00017C80
#define ip_optcopy func_00017E78
#define ip_pcbopts func_000182C8
#define ip_setmoptions func_00018480
#define ip_getmoptions func_00018B00
#define ip_mloopback func_00018C70
#define ip_optlen func_00018D8C
int ip_optcopy(struct ip *ip, struct ip *jp);
int ip_setmoptions(int optname, struct ip_moptions **imop, struct mbuf *m);
int ip_getmoptions(int optname, struct ip_moptions *imo, struct mbuf **mp);
u_int ip_optlen(struct inpcb *inp);
void ip_freemoptions(struct ip_moptions *imo);

/* ip_input.c */
struct ipqent {
	LIST_ENTRY(ipqent) ipqe_q;
	union {
		struct ip *_ip;
		struct tcpiphdr *_tcp;
	} _ipqe_u1;
	struct mbuf *ipqe_m;
	u_int8_t ipqe_mff;
	LIST_ENTRY(ipqent) ipqe_timeq;
	u_int32_t ipqe_seq;
	u_int32_t ipqe_len;
	u_int32_t ipqe_flags;
};
#define ipqe_ip _ipqe_u1._ip
#define ipqe_tcp _ipqe_u1._tcp
LIST_HEAD(ipqehead, ipqent);
struct ipq {
	LIST_ENTRY(ipq) ipq_q;
	u_int8_t ipq_ttl;
	u_int8_t ipq_p;
	u_int16_t ipq_id;
	struct ipqehead ipq_fragq;
	struct in_addr ipq_src, ipq_dst;
};
struct ip_timestamp {
	u_int8_t ipt_code;
	u_int8_t ipt_len;
	u_int8_t ipt_ptr;
	u_int8_t ipt_flg:4,
		ipt_oflw:4;
	union ipt_timestamp {
		n_time ipt_time[1];
		struct ipt_ta {
			struct in_addr ipt_addr;
			n_time ipt_time;
		} ipt_ta[1] __attribute__((__packed__));
	} ipt_timestamp __attribute__((__packed__));
};
LIST_HEAD(ipqhead, ipq);
#define IPFRAGTTL 60
#define IFQ_MAXLEN 50
#define IPPROTO_MAX 256
#define IPPORT_ANONMIN 49152
#define IPPORT_ANONMAX 65535
#define IPPORT_RESERVEDMIN 600
#define IPPORT_RESERVEDMAX 1023
#define in_init func_00012D54
void in_init(void);
#define in_proto_init func_00014824
void in_proto_init(void);
#define pffindproto func_00002058
struct protosw *pffindproto(int family, int protocol, int type);
extern struct domain inetdomain;
#define ip_init func_00014890
#define ip_input func_00014B18
#define ip_reass func_0001546C
#define ip_freef func_00015A38
#define ip_dooptions func_00015ADC
#define ip_rtaddr func_00016030
#define save_rte func_00016120
#define ip_forward func_000161A0
#define ip_sysctl func_00016738
#define ipintr func_00016B04
#define ip_slowtimo func_00016B8C
#define ip_drain func_00016CD0
void ip_input(struct mbuf *m);
struct mbuf *ip_reass(struct ipqent *ipqe, struct ipq *fp);
void ip_freef(struct ipq *fp);
int ip_dooptions(struct mbuf *m);
struct in_ifaddr *ip_rtaddr(struct in_addr dst);
void ip_forward(struct mbuf *m, int srcrt);
#define rt_timer_queue_create func_0000D188
struct rttimer_queue *rt_timer_queue_create(u_int timeout);
#define IPTTLDEC 1
#define TRUE 1
#define FALSE 0
#define IPPORT_RESERVED 1024
#define IPCTL_FORWARDING 1
#define IPCTL_SENDREDIRECTS 2
#define IPCTL_DEFTTL 3
#define IPCTL_DEFMTU 4
#define IPCTL_FORWSRCRT 5
#define IPCTL_DIRECTEDBCAST 6
#define IPCTL_ALLOWSRCRT 7
#define IPCTL_SUBNETSARELOCAL 8
#define IPCTL_MTUDISC 9
#define IPCTL_ANONPORTMIN 10
#define IPCTL_ANONPORTMAX 11
#define IPCTL_MTUDISCTIMEOUT 12
#define IPCTL_MAXFLOWS 13
#define IPCTL_HOSTZEROBROADCAST 14
#define IPCTL_GIF_TTL 15
#define IPCTL_LOWPORTMIN 16
#define IPCTL_LOWPORTMAX 17
#define IPCTL_MAXFRAGPACKETS 18
#define IPCTL_STATS 19
#define SCM_TIMESTAMP 0x02
#define rt_timer_queue_destroy func_0000CB28
#define rt_timer_queue_change func_0000D25C
void rt_timer_queue_destroy(struct rttimer_queue *q, int destroy);
void rt_timer_queue_change(struct rttimer_queue *q, long timeout);

extern int subnetsarelocal, hostzeroisbroadcast;

/* tcp */

#ifndef PR_SLOWHZ
#define PR_SLOWHZ 2
#endif
#define pfslowtimo_now ((u_int)D_0002F29C)
#define PRT_SLOW_ARM(t, nticks) ((t) = pfslowtimo_now + (nticks))
#define PRT_SLOW_DISARM(t) ((t) = 0)
#define PRT_SLOW_ISARMED(t) ((t) != 0)
#define PRT_SLOW_ISEXPIRED(t) (PRT_SLOW_ISARMED(t) && (t) <= pfslowtimo_now)

typedef u_int32_t tcp_seq;
struct tcphdr {
	u_int16_t th_sport;		/* source port */
	u_int16_t th_dport;		/* destination port */
	tcp_seq	  th_seq;		/* sequence number */
	tcp_seq	  th_ack;		/* acknowledgement number */
	u_int8_t  th_x2:4,		/* (unused) */
		  th_off:4;		/* data offset */
	u_int8_t  th_flags;
#define	TH_FIN	  0x01
#define	TH_SYN	  0x02
#define	TH_RST	  0x04
#define	TH_PUSH	  0x08
#define	TH_ACK	  0x10
#define	TH_URG	  0x20
	u_int16_t th_win;			/* window */
	u_int16_t th_sum;			/* checksum */
	u_int16_t th_urp;			/* urgent pointer */
} __attribute__((__packed__));

#define	TCPOPT_EOL		0
#define	TCPOPT_NOP		1
#define	TCPOPT_MAXSEG		2
#define	   TCPOLEN_MAXSEG		4
#define	TCPOPT_WINDOW		3
#define	   TCPOLEN_WINDOW		3
#define	TCPOPT_SACK_PERMITTED	4		/* Experimental */
#define	   TCPOLEN_SACK_PERMITTED	2
#define	TCPOPT_SACK		5		/* Experimental */
#define	TCPOPT_TIMESTAMP	8
#define	   TCPOLEN_TIMESTAMP		10
#define	   TCPOLEN_TSTAMP_APPA		(TCPOLEN_TIMESTAMP+2) /* appendix A */

#define TCPOPT_TSTAMP_HDR	\
    (TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_TIMESTAMP<<8|TCPOLEN_TIMESTAMP)

#define	TCP_MSS		512

#define	TCP_MAXWIN	65535	/* largest value for (unscaled) window */

#define	TCP_MAX_WINSHIFT	14	/* maximum window shift */

#define	TCP_MAXBURST	4	/* maximum segments in a burst */

#define	TCP_NODELAY	0x01	/* don't delay send to coalesce packets */
#define	TCP_MAXSEG	0x02	/* set maximum segment size */

#define	TCP_NSTATES	11

#define	TCPS_CLOSED		0	/* closed */
#define	TCPS_LISTEN		1	/* listening for connection */
#define	TCPS_SYN_SENT		2	/* active, have sent syn */
#define	TCPS_SYN_RECEIVED	3	/* have send and received syn */
/* states < TCPS_ESTABLISHED are those where connections not established */
#define	TCPS_ESTABLISHED	4	/* established */
#define	TCPS_CLOSE_WAIT		5	/* rcvd fin, waiting for close */
/* states > TCPS_CLOSE_WAIT are those where user has closed */
#define	TCPS_FIN_WAIT_1		6	/* have closed, sent fin */
#define	TCPS_CLOSING		7	/* closed xchd FIN; await ACK */
#define	TCPS_LAST_ACK		8	/* had fin and close; await FIN ACK */
/* states > TCPS_CLOSE_WAIT && < TCPS_FIN_WAIT_2 await ACK of FIN */
#define	TCPS_FIN_WAIT_2		9	/* have closed, fin is acked */
#define	TCPS_TIME_WAIT		10	/* in 2*msl quiet wait after close */

#define	TCPS_HAVERCVDSYN(s)	((s) >= TCPS_SYN_RECEIVED)
#define	TCPS_HAVEESTABLISHED(s)	((s) >= TCPS_ESTABLISHED)
#define	TCPS_HAVERCVDFIN(s) \
    ((s) == TCPS_CLOSE_WAIT || ((s) >= TCPS_CLOSING && (s) != TCPS_FIN_WAIT_2))

#define	SEQ_LT(a,b)	((int)((a)-(b)) < 0)
#define	SEQ_LEQ(a,b)	((int)((a)-(b)) <= 0)
#define	SEQ_GT(a,b)	((int)((a)-(b)) > 0)
#define	SEQ_GEQ(a,b)	((int)((a)-(b)) >= 0)

#define	SEQ_SUB(a,b)	((long)((a)-(b)))

#define	tcp_rcvseqinit(tp) \
	(tp)->rcv_adv = (tp)->rcv_nxt = (tp)->irs + 1

#define	tcp_sendseqinit(tp) \
	(tp)->snd_una = (tp)->snd_nxt = (tp)->snd_max = (tp)->snd_up = \
	    (tp)->snd_recover = (tp)->iss

#define TCP_ISS_RANDOM_MASK 0x00ffffff /* bits of randomness in a TCP ISS */
#define TCP_ISSINCR         0x01000000 /* increment per time and per conn */

#define	TCPT_NTIMERS	4

#define	TCPT_REXMT	0		/* retransmit */
#define	TCPT_PERSIST	1		/* retransmit persistance */
#define	TCPT_KEEP	2		/* keep alive */
#define	TCPT_2MSL	3		/* 2*msl quiet time timer */

#define	TCPTV_MSL	( 30*PR_SLOWHZ)		/* max seg lifetime (hah!) */
#define	TCPTV_SRTTBASE	0			/* base roundtrip time;
						   if 0, no idea yet */
#define	TCPTV_SRTTDFLT	(  3*PR_SLOWHZ)		/* assumed RTT if no info */

#define	TCPTV_PERSMIN	(  5*PR_SLOWHZ)		/* retransmit persistance */
#define	TCPTV_PERSMAX	( 60*PR_SLOWHZ)		/* maximum persist interval */

#define	TCPTV_KEEP_INIT	( 75*PR_SLOWHZ)		/* initial connect keep alive */
#define	TCPTV_KEEP_IDLE	(120*60*PR_SLOWHZ)	/* dflt time before probing */
#define	TCPTV_KEEPINTVL	( 75*PR_SLOWHZ)		/* default probe interval */
#define	TCPTV_KEEPCNT	8			/* max probes before drop */

#define	TCPTV_MIN	(  1*PR_SLOWHZ)		/* minimum allowable value */
#define	TCPTV_REXMTMAX	( 64*PR_SLOWHZ)		/* max allowable REXMT value */

#define	TCP_LINGERTIME	120			/* linger at most 2 minutes */

#define	TCP_MAXRXTSHIFT	12			/* maximum retransmits */

#define	TCP_TIMER_ARM(tp, timer, nticks) \
	PRT_SLOW_ARM((tp)->t_timer[(timer)], (nticks))

#define	TCP_TIMER_DISARM(tp, timer) \
	PRT_SLOW_DISARM((tp)->t_timer[(timer)])

#define	TCP_TIMER_ISARMED(tp, timer) \
	PRT_SLOW_ISARMED((tp)->t_timer[(timer)])

#define	TCP_TIMER_ISEXPIRED(tp, timer) \
	PRT_SLOW_ISEXPIRED((tp)->t_timer[(timer)])

#define	TCPT_RANGESET(tv, value, tvmin, tvmax) { \
	(tv) = (value); \
	if ((tv) < (tvmin)) \
		(tv) = (tvmin); \
	else if ((tv) > (tvmax)) \
		(tv) = (tvmax); \
}

struct tcpiphdr {
	struct 	ipovly ti_i;		/* overlaid ip structure */
	struct	tcphdr ti_t;		/* tcp header */
} __attribute__((__packed__));
#define	ti_x1		ti_i.ih_x1
#define	ti_pr		ti_i.ih_pr
#define	ti_len		ti_i.ih_len
#define	ti_src		ti_i.ih_src
#define	ti_dst		ti_i.ih_dst
#define	ti_sport	ti_t.th_sport
#define	ti_dport	ti_t.th_dport
#define	ti_seq		ti_t.th_seq
#define	ti_ack		ti_t.th_ack
#define	ti_x2		ti_t.th_x2
#define	ti_off		ti_t.th_off
#define	ti_flags	ti_t.th_flags
#define	ti_win		ti_t.th_win
#define	ti_sum		ti_t.th_sum
#define	ti_urp		ti_t.th_urp

struct tcpcb {
	int	t_family;		/* address family on the wire */
	struct ipqehead segq;		/* sequencing queue */
	u_int	t_timer[TCPT_NTIMERS];	/* tcp timers */
	short	t_state;		/* state of this connection */
	short	t_rxtshift;		/* log(2) of rexmt exp. backoff */
	short	t_rxtcur;		/* current retransmit value */
	short	t_dupacks;		/* consecutive dup acks recd */
	u_short	t_peermss;		/* peer's maximum segment size */
	u_short	t_ourmss;		/* our's maximum segment size */
	u_short t_segsz;		/* current segment size in use */
	char	t_force;		/* 1 if forcing out a byte */
	u_short	t_flags;
#define	TF_ACKNOW	0x0001		/* ack peer immediately */
#define	TF_DELACK	0x0002		/* ack, but try to delay it */
#define	TF_NODELAY	0x0004		/* don't delay packets to coalesce */
#define	TF_NOOPT	0x0008		/* don't use tcp options */
#define	TF_REQ_SCALE	0x0020		/* have/will request window scaling */
#define	TF_RCVD_SCALE	0x0040		/* other side has requested scaling */
#define	TF_REQ_TSTMP	0x0080		/* have/will request timestamps */
#define	TF_RCVD_TSTMP	0x0100		/* a timestamp was received in SYN */
#define	TF_SACK_PERMIT	0x0200		/* other side said I could SACK */
#define	TF_SYN_REXMT	0x0400		/* rexmit timer fired on SYN */
#define	TF_WILL_SACK	0x0800		/* try to use SACK */
#define	TF_CANT_TXSACK	0x1000		/* other side said I could not SACK */
#define	TF_IGNR_RXSACK	0x2000		/* ignore received SACK blocks */
#define	TF_REASSEMBLING	0x4000		/* we're busy reassembling */

	struct	mbuf *t_template;	/* skeletal packet for transmit */
	struct	inpcb *t_inpcb;		/* back pointer to internet pcb */
	struct	in6pcb *t_in6pcb;	/* back pointer to internet pcb */
	LIST_ENTRY(tcpcb) t_delack;	/* delayed ACK queue */
/* send sequence variables */
	tcp_seq	snd_una;		/* send unacknowledged */
	tcp_seq	snd_nxt;		/* send next */
	tcp_seq	snd_up;			/* send urgent pointer */
	tcp_seq	snd_wl1;		/* window update seg seq number */
	tcp_seq	snd_wl2;		/* window update seg ack number */
	tcp_seq	iss;			/* initial send sequence number */
	u_long	snd_wnd;		/* send window */
	tcp_seq snd_recover;		/* for use in fast recovery */
/* receive sequence variables */
	u_long	rcv_wnd;		/* receive window */
	tcp_seq	rcv_nxt;		/* receive next */
	tcp_seq	rcv_up;			/* receive urgent pointer */
	tcp_seq	irs;			/* initial receive sequence number */
/* receive variables */
	tcp_seq	rcv_adv;		/* advertised window */
/* retransmit variables */
	tcp_seq	snd_max;		/* highest sequence number sent;
					 * used to recognize retransmits
					 */
/* congestion control (for slow start, source quench, retransmit after loss) */
	u_long	snd_cwnd;		/* congestion-controlled window */
	u_long	snd_ssthresh;		/* snd_cwnd size threshhold for
					 * for slow start exponential to
					 * linear switch
					 */
	short	t_idle;			/* inactivity time */
	short	t_rtt;			/* round trip time */
	tcp_seq	t_rtseq;		/* sequence number being timed */
	short	t_srtt;			/* smoothed round-trip time */
	short	t_rttvar;		/* variance in round-trip time */
	short	t_rttmin;		/* minimum rtt allowed */
	u_long	max_sndwnd;		/* largest window peer has offered */

/* out-of-band data */
	char	t_oobflags;		/* have some */
	char	t_iobc;			/* input character */
#define	TCPOOB_HAVEDATA	0x01
#define	TCPOOB_HADDATA	0x02
	short	t_softerror;		/* possible error not yet reported */

/* RFC 1323 variables */
	u_char	snd_scale;		/* window scaling for send window */
	u_char	rcv_scale;		/* window scaling for recv window */
	u_char	request_r_scale;	/* pending window scaling */
	u_char	requested_s_scale;
	u_int32_t ts_recent;		/* timestamp echo data */
	u_int32_t ts_recent_age;	/* when last updated */
	tcp_seq	last_ack_sent;

/* SACK stuff */
	struct ipqehead timeq;		/* time sequenced queue (for SACK) */
	int	t_mtudisc;

/* pointer for syn cache entries*/
	LIST_HEAD(, syn_cache) t_sc;	/* list of entries by this tcb */
};

static __inline int
tcp_reass_lock_try(struct tcpcb *tp)
{
	int s;

	s = _sce_pspnet_spllock();
	if (tp->t_flags & TF_REASSEMBLING) {
		_sce_pspnet_splunlock(s);
		return (0);
	}
	tp->t_flags |= TF_REASSEMBLING;
	_sce_pspnet_splunlock(s);
	return (1);
}

static __inline void
tcp_reass_unlock(struct tcpcb *tp)
{
	int s;

	s = _sce_pspnet_spllock();
	tp->t_flags &= ~TF_REASSEMBLING;
	_sce_pspnet_splunlock(s);
}

#define	TCP_REASS_LOCK(tp)	(void) tcp_reass_lock_try((tp))
#define	TCP_REASS_LOCK_CHECK(tp) /* nothing */

#define	TCP_REASS_UNLOCK(tp)	tcp_reass_unlock((tp))

LIST_HEAD(tcp_delack_head, tcpcb);

#define	TCP_SET_DELACK(tp) \
do { \
	if (((tp)->t_flags & TF_DELACK) == 0) { \
		(tp)->t_flags |= TF_DELACK; \
		LIST_INSERT_HEAD(&tcp_delacks, (tp), t_delack); \
	} \
} while (0)

#define	TCP_CLEAR_DELACK(tp) \
do { \
	if ((tp)->t_flags & TF_DELACK) { \
		(tp)->t_flags &= ~TF_DELACK; \
		LIST_REMOVE((tp), t_delack); \
	} \
} while (0)

struct tcp_opt_info {
	int		ts_present;
	u_int32_t	ts_val;
	u_int32_t	ts_ecr;
	u_int16_t	maxseg;
};

union syn_cache_sa {
	struct sockaddr sa;
	struct sockaddr_in sin;
};

struct syn_cache {
	LIST_ENTRY(syn_cache) sc_bucketq;	/* link on bucket list */
	TAILQ_ENTRY(syn_cache) sc_timeq;	/* link on timer queue */
	union {					/* cached route */
		struct route route4;
	} sc_route_u;
#define sc_route4	sc_route_u.route4
	long sc_win;				/* advertised window */
	int sc_bucketidx;			/* our bucket index */
	u_int32_t sc_hash;
	u_int32_t sc_timestamp;			/* timestamp from SYN */
	union syn_cache_sa sc_src;
	union syn_cache_sa sc_dst;
	tcp_seq sc_irs;
	tcp_seq sc_iss;
	u_int sc_rexmt;				/* retransmit timer */
	u_int sc_rxtcur;			/* current rxt timeout */
	u_int sc_rxttot;			/* total time spend on queues */
	u_short sc_rxtshift;			/* for computing backoff */
	u_short sc_flags;

#define	SCF_UNREACH		0x0001		/* we've had an unreach error */
#define	SCF_TIMESTAMP		0x0002		/* peer will do timestamps */

	struct mbuf *sc_ipopts;			/* IP options */
	u_int16_t sc_peermaxseg;
	u_int16_t sc_ourmaxseg;
	u_int8_t sc_request_r_scale	: 4,
		 sc_requested_s_scale	: 4;

	struct tcpcb *sc_tp;			/* tcb for listening socket */
	LIST_ENTRY(syn_cache) sc_tpq;		/* list of entries by same tp */
};

struct syn_cache_head {
	LIST_HEAD(, syn_cache) sch_bucket;	/* bucket entries */
	u_short sch_length;			/* # entries in bucket */
};

#define	intotcpcb(ip)	((struct tcpcb *)(ip)->inp_ppcb)
#define	sototcpcb(so)	(intotcpcb(sotoinpcb(so)))

#define	TCP_RTT_SHIFT		3	/* shift for srtt; 3 bits frac. */
#define	TCP_RTTVAR_SHIFT	2	/* multiplier for rttvar; 2 bits */

#define	TCP_REXMTVAL(tp) \
	((((tp)->t_srtt >> TCP_RTT_SHIFT) + (tp)->t_rttvar) >> 2)

#define	TCP_INITIAL_WINDOW(iw, segsz) \
	(((iw) == 0) ? (min(4 * (segsz), max(2 * (segsz), 4380))) : \
	 ((segsz) * (iw)))

struct	tcpstat_s {
	u_quad_t tcps_connattempt;	/* connections initiated */
	u_quad_t tcps_accepts;		/* connections accepted */
	u_quad_t tcps_connects;		/* connections established */
	u_quad_t tcps_drops;		/* connections dropped */
	u_quad_t tcps_conndrops;	/* embryonic connections dropped */
	u_quad_t tcps_closed;		/* conn. closed (includes drops) */
	u_quad_t tcps_segstimed;	/* segs where we tried to get rtt */
	u_quad_t tcps_rttupdated;	/* times we succeeded */
	u_quad_t tcps_delack;		/* delayed acks sent */
	u_quad_t tcps_timeoutdrop;	/* conn. dropped in rxmt timeout */
	u_quad_t tcps_rexmttimeo;	/* retransmit timeouts */
	u_quad_t tcps_persisttimeo;	/* persist timeouts */
	u_quad_t tcps_keeptimeo;	/* keepalive timeouts */
	u_quad_t tcps_keepprobe;	/* keepalive probes sent */
	u_quad_t tcps_keepdrops;	/* connections dropped in keepalive */
	u_quad_t tcps_persistdrops;	/* connections dropped in persist */
	u_quad_t tcps_connsdrained;	/* connections drained due to memory
					   shortage */
	u_quad_t tcps_pmtublackhole;

	u_quad_t tcps_sndtotal;		/* total packets sent */
	u_quad_t tcps_sndpack;		/* data packets sent */
	u_quad_t tcps_sndbyte;		/* data bytes sent */
	u_quad_t tcps_sndrexmitpack;	/* data packets retransmitted */
	u_quad_t tcps_sndrexmitbyte;	/* data bytes retransmitted */
	u_quad_t tcps_sndacks;		/* ack-only packets sent */
	u_quad_t tcps_sndprobe;		/* window probes sent */
	u_quad_t tcps_sndurg;		/* packets sent with URG only */
	u_quad_t tcps_sndwinup;		/* window update-only packets sent */
	u_quad_t tcps_sndctrl;		/* control (SYN|FIN|RST) packets sent */

	u_quad_t tcps_rcvtotal;		/* total packets received */
	u_quad_t tcps_rcvpack;		/* packets received in sequence */
	u_quad_t tcps_rcvbyte;		/* bytes received in sequence */
	u_quad_t tcps_rcvbadsum;	/* packets received with ccksum errs */
	u_quad_t tcps_rcvbadoff;	/* packets received with bad offset */
	u_quad_t tcps_rcvmemdrop;	/* packets dropped for lack of memory */
	u_quad_t tcps_rcvshort;		/* packets received too short */
	u_quad_t tcps_rcvduppack;	/* duplicate-only packets received */
	u_quad_t tcps_rcvdupbyte;	/* duplicate-only bytes received */
	u_quad_t tcps_rcvpartduppack;	/* packets with some duplicate data */
	u_quad_t tcps_rcvpartdupbyte;	/* dup. bytes in part-dup. packets */
	u_quad_t tcps_rcvoopack;	/* out-of-order packets received */
	u_quad_t tcps_rcvoobyte;	/* out-of-order bytes received */
	u_quad_t tcps_rcvpackafterwin;	/* packets with data after window */
	u_quad_t tcps_rcvbyteafterwin;	/* bytes rcvd after window */
	u_quad_t tcps_rcvafterclose;	/* packets rcvd after "close" */
	u_quad_t tcps_rcvwinprobe;	/* rcvd window probe packets */
	u_quad_t tcps_rcvdupack;	/* rcvd duplicate acks */
	u_quad_t tcps_rcvacktoomuch;	/* rcvd acks for unsent data */
	u_quad_t tcps_rcvackpack;	/* rcvd ack packets */
	u_quad_t tcps_rcvackbyte;	/* bytes acked by rcvd acks */
	u_quad_t tcps_rcvwinupd;	/* rcvd window update packets */
	u_quad_t tcps_pawsdrop;		/* segments dropped due to PAWS */
	u_quad_t tcps_predack;		/* times hdr predict ok for acks */
	u_quad_t tcps_preddat;		/* times hdr predict ok for data pkts */

	u_quad_t tcps_pcbhashmiss;	/* input packets missing pcb hash */
	u_quad_t tcps_noport;		/* no socket on port */
	u_quad_t tcps_badsyn;		/* received ack for which we have
					   no SYN in compressed state */

	/* These statistics deal with the SYN cache. */
	u_quad_t tcps_sc_added;		/* # of entries added */
	u_quad_t tcps_sc_completed;	/* # of connections completed */
	u_quad_t tcps_sc_timed_out;	/* # of entries timed out */
	u_quad_t tcps_sc_overflowed;	/* # dropped due to overflow */
	u_quad_t tcps_sc_reset;		/* # dropped due to RST */
	u_quad_t tcps_sc_unreach;	/* # dropped due to ICMP unreach */
	u_quad_t tcps_sc_bucketoverflow;/* # dropped due to bucket overflow */
	u_quad_t tcps_sc_aborted;	/* # of entries aborted (no mem) */
	u_quad_t tcps_sc_dupesyn;	/* # of duplicate SYNs received */
	u_quad_t tcps_sc_dropped;	/* # of SYNs dropped (no route/mem) */
	u_quad_t tcps_sc_collisions;	/* # of hash collisions */
	u_quad_t tcps_sc_retransmitted;	/* # of retransmissions */
};

#define	TCPCTL_RFC1323		1	/* RFC1323 timestamps/scaling */
#define	TCPCTL_SENDSPACE	2	/* default send buffer */
#define	TCPCTL_RECVSPACE	3	/* default recv buffer */
#define	TCPCTL_MSSDFLT		4	/* default seg size */
#define	TCPCTL_SYN_CACHE_LIMIT	5	/* max size of comp. state engine */
#define	TCPCTL_SYN_BUCKET_LIMIT	6	/* max size of hash bucket */
#define	TCPCTL_SYN_CACHE_INTER	7	/* interval of comp. state timer */
#define	TCPCTL_INIT_WIN		8	/* initial window */
#define	TCPCTL_MSS_IFMTU	9	/* mss from interface, not in_maxmtu */
#define	TCPCTL_SACK		10	/* RFC2018 selective acknowledgement */
#define	TCPCTL_WSCALE		11	/* RFC1323 window scaling */
#define	TCPCTL_TSTAMP		12	/* RFC1323 timestamps */
#define	TCPCTL_COMPAT_42	13	/* 4.2BSD TCP bug work-arounds */
#define	TCPCTL_CWM		14	/* Congestion Window Monitoring */
#define	TCPCTL_CWM_BURSTSIZE	15	/* burst size allowed by CWM */
#define	TCPCTL_ACK_ON_PUSH	16	/* ACK immediately on PUSH */
#define	TCPCTL_KEEPIDLE		17	/* keepalive idle time */
#define	TCPCTL_KEEPINTVL	18	/* keepalive probe interval */
#define	TCPCTL_KEEPCNT		19	/* keepalive count */
#define	TCPCTL_SLOWHZ		20	/* PR_SLOWHZ (read-only) */
#define	TCPCTL_NEWRENO		21	/* NewReno Congestion Control */
#define TCPCTL_LOG_REFUSED	22	/* Log refused connections */
#define	TCPCTL_RSTPPSLIMIT	24	/* RST pps limit */
#define	TCPCTL_ACKDROPRATELIMIT	28	/* SYN/RST -> ACK rate limit */
#define	TCPCTL_MAXID		29


/* tcp globals */
extern int tcprexmtthresh, tcp_cwm_burstsize, tcp_mssdflt, tcp_rttdflt;
extern u_char tcp_outflags[TCP_NSTATES];
extern int tcp_do_rfc1323, tcp_do_sack, tcp_do_win_scale, tcp_do_timestamps;
extern int tcp_init_win, tcbhashsize, tcp_keepidle, tcp_keepintvl, tcp_keepcnt;
extern int tcp_maxpersistidle, tcp_backoff[TCP_MAXRXTSHIFT + 1], tcp_totbackoff;
extern u_long tcp_sendspace, tcp_recvspace;
extern int tcp_cwm, tcp_do_newreno, tcp_ack_on_push, tcp_mss_ifmtu, tcp_compat_42;
extern tcp_seq tcp_iss_seq;
extern int tcp_log_refused;
extern struct inpcbtable tcbtable;
extern u_int32_t tcp_now;
extern struct tcpstat_s tcpstat;
extern int ip_mtudisc;
extern int tcp_maxidle;
extern struct tcp_delack_head tcp_delacks;
extern int tcp_syn_cache_size, tcp_syn_cache_limit, tcp_syn_bucket_limit;
extern int tcp_syn_cache_interval, tcp_rst_ppslim;

extern unsigned long in_maxmtu;

#endif
