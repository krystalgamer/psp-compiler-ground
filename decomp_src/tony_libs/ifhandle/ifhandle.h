#ifndef IFHANDLE_H
#define IFHANDLE_H

#define K1_SAVE(old) asm volatile(".set noreorder\n\tmove %0, $27\n\tsrl $27, $27, 16\n\t.set reorder" : "=r"(old))
#define K1_RESTORE(old) asm volatile("move $27, %0" : : "r"(old))
#define K1_USER() ({ unsigned int _u; asm volatile("andi %0, $27, 0x18" : "=r"(_u)); _u; })

typedef struct {
	int size;
	char name[32];
	unsigned int attr;
	int poolSize;
	int freeSize;
	int numWaitThreads;
} SceKernelVplInfo;

int sceKernelCreateVpl(const char *name, int part, unsigned int attr, unsigned int size, void *opt);
int sceKernelDeleteVpl(int uid);
int sceKernelTryAllocateVpl(int uid, unsigned int size, void **data);
int sceKernelFreeVpl(int uid, void *data);
int sceKernelReferVplStatus(int uid, SceKernelVplInfo *info);
int Kprintf(const char *fmt, ...);

extern int D_00003B28;
extern int D_00003B2C;


#define MSIZE 256
#define MLEN (MSIZE - sizeof(struct m_hdr))
#define MHLEN (MLEN - sizeof(struct pkthdr))

#define M_EXT 0x0001
#define M_PKTHDR 0x0002
#define M_EOR 0x0004
#define M_CLUSTER 0x0008

#define M_DONTWAIT 1
#define M_WAIT 0

struct mbuf;

struct pkthdr {
	void *rcvif;
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

struct m_hdr {
	struct mbuf *mh_next;
	struct mbuf *mh_nextpkt;
	char *mh_data;
	int mh_len;
	short mh_type;
	unsigned short mh_flags;
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

#define m_pkthdr M_dat.MH.MH_pkthdr
#define m_ext M_dat.MH.MH_dat.MH_ext
#define m_pktdat M_dat.MH.MH_dat.MH_databuf
#define m_dat M_dat.M_databuf

#define mtod(m, t) ((t)((m)->m_data))

#define MGET(m, how, type) \
	do { \
		(m) = sceNetMallocInternal(MSIZE); \
		if (m) { \
			(m)->m_type = (type); \
			(m)->m_data = (m)->m_dat; \
			(m)->m_next = 0; \
			(m)->m_nextpkt = 0; \
			(m)->m_flags = 0; \
		} \
	} while (0)

#define M_COPYFLAGS (~(M_EXT | M_CLUSTER))

#define M_COPY_PKTHDR(to, from) \
	do { \
		(to)->m_pkthdr = (from)->m_pkthdr; \
		(from)->m_pkthdr.aux = 0; \
		(to)->m_flags = (from)->m_flags & M_COPYFLAGS; \
		(to)->m_data = (to)->m_pktdat; \
	} while (0)

#define MH_ALIGN(m, len) \
	do { \
		(m)->m_data += (MHLEN - (len)) & ~(sizeof(long) - 1); \
	} while (0)

#define MGETHDR(m, how, type) \
	do { \
		(m) = sceNetMallocInternal(MSIZE); \
		if (m) { \
			(m)->m_type = (type); \
			(m)->m_next = 0; \
			(m)->m_nextpkt = 0; \
			(m)->m_data = (m)->m_pktdat; \
			(m)->m_flags = M_PKTHDR; \
			(m)->m_pkthdr.aux = 0; \
		} \
	} while (0)

#define M_ALIGN(m, len) \
	do { \
		(m)->m_data += (MLEN - (len)) & ~(sizeof(long) - 1); \
	} while (0)

#define MCLADDREFERENCE(o, n) \
	do { \
		(n)->m_flags |= ((o)->m_flags & (M_EXT | M_CLUSTER)); \
		(n)->m_ext.ext_nextref = (o)->m_ext.ext_nextref; \
		(n)->m_ext.ext_prevref = (o); \
		(o)->m_ext.ext_nextref = (n); \
		(n)->m_ext.ext_nextref->m_ext.ext_prevref = (n); \
	} while (0)

static inline unsigned int max(unsigned int a, unsigned int b)
{
	return a > b ? a : b;
}

static inline struct mbuf *m_get(int how, int type)
{
	struct mbuf *m;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	MGET(m, how, type);
	K1_RESTORE(oldk1);
	return m;
}

static inline int k1ok(const void *p)
{
	if (!K1_USER())
		return 1;
	return ((unsigned int)p >> 31) ^ 1;
}

void *sceNetMallocInternal(unsigned int size);
void sceNetFreeInternal(void *p);
void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned int);
struct mbuf *sceNetMFree(struct mbuf *m);
struct mbuf *sceNetMGetclr(int how, int type);
void sceNetMFreem(struct mbuf *m);
struct mbuf *func_00002C58(struct mbuf *m, int off, int len, int wait, int deep);
struct mbuf *func_00002434(struct mbuf *m0, int len0, int wait);

extern const char D_00003A44[];
extern const char D_00003A50[];

#define MBUF_PANIC_FN(fn) \
	do { \
		Kprintf(D_00003A44, D_00003A50, fn); \
		for (;;) \
			; \
	} while (0)
#define MBUF_PANIC() MBUF_PANIC_FN(__FUNCTION__)

#define M_COPYALL 1000000000
#define MCLBYTES 2048

#define M_TRAILINGSPACE(m) \
	((m)->m_flags & M_EXT ? (m)->m_ext.ext_buf + (m)->m_ext.ext_size - \
	    ((m)->m_data + (m)->m_len) : \
	    &(m)->m_dat[MLEN] - ((m)->m_data + (m)->m_len))

#define MCLGET(m, how) \
	do { \
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

static inline unsigned int min(unsigned int a, unsigned int b)
{
	return a < b ? a : b;
}

extern int D_000043C8;
extern int D_000043CC;
extern int D_000043D0;
extern int D_000043D4;
extern int D_000043D8;
extern int D_000043DC;

struct ifqueue {
	struct mbuf *ifq_head;
	struct mbuf *ifq_tail;
	int ifq_len;
	int ifq_maxlen;
	int ifq_drops;
};

#define IF_DEQUEUE(ifq, m) \
	do { \
		(m) = (ifq)->ifq_head; \
		if (m) { \
			if (((ifq)->ifq_head = (m)->m_nextpkt) == 0) \
				(ifq)->ifq_tail = 0; \
			(m)->m_nextpkt = 0; \
			(ifq)->ifq_len--; \
		} \
	} while (0)

#define IF_ENQUEUE(ifq, m) \
	do { \
		(m)->m_nextpkt = 0; \
		if ((ifq)->ifq_tail == 0) \
			(ifq)->ifq_head = m; \
		else \
			(ifq)->ifq_tail->m_nextpkt = m; \
		(ifq)->ifq_tail = m; \
		(ifq)->ifq_len++; \
	} while (0)

#define IF_PREPEND(ifq, m) \
	do { \
		(m)->m_nextpkt = (ifq)->ifq_head; \
		if ((ifq)->ifq_tail == 0) \
			(ifq)->ifq_tail = (m); \
		(ifq)->ifq_head = (m); \
		(ifq)->ifq_len++; \
	} while (0)

struct evnode {
	struct evnode *next;
	struct evnode **prev;
	int a;
	int b;
};

struct ifinternal {
	char unk0[0x14];
	char name[0x10];
	char unk24[0xEC - 0x24];
	unsigned char mac[6];
	char unkF2[0x100 - 0xF2];
	int ioctlSema;
	int ioctlOkSema;
	int unk108;
	int unk10C;
	struct evnode *evFirst;
	struct evnode **evLast;
	int evf;
	int evBits;
	char unk120[0x140 - 0x120];
};

typedef struct SceNetIfHandle {
	struct ifinternal *ifp;
	int unk4;
	void (*up)(struct SceNetIfHandle *);
	void (*down)(struct SceNetIfHandle *);
	void (*start)(struct SceNetIfHandle *);
	void (*ioctl)(struct SceNetIfHandle *, int, void *);
	struct ifqueue snd;
} SceNetIfHandle;

int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
int sceKernelSignalSema(int id, int n);
int sceKernelWaitSema(int id, int n, unsigned int *timeout);
int sceKernelPollSema(int id, int n);
int sceKernelSetEventFlag(int id, unsigned int bits);
unsigned int sceKernelGetSystemTimeLow(void);
int sceKernelCpuSuspendIntr(void);
int sceKernelCpuResumeIntr(int s);
char *strncpy(char *, const char *, unsigned int);
void func_000012BC(unsigned int seed);
int func_00001478(void);

extern SceNetIfHandle *D_00003B54[8];
extern struct ifqueue D_00003B74;
extern int D_00003B30;
extern struct ifinternal *D_00003B34;
extern int D_00003B38;
extern struct ifinternal *D_00003B3C;
extern int D_00003B40;
extern int D_00003B44;
extern int (*D_00003B4C)(struct mbuf *);
extern int D_00003B88;
extern int D_00003B8C;
extern int D_00003B90;
extern int D_00003B94;
extern int D_00003B98;

#endif
