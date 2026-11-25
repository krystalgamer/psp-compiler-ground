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
struct thread_info {
	struct thread_info *ti_next;
	struct thread_info **ti_prev;
	SceUID thid;
	short refcnt;
	int error;
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
	short pr_type;
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

#endif
