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
void sceNetMFreem(struct mbuf *m);
struct mbuf *func_00002C58(struct mbuf *m, int off, int len, int wait, int deep);

extern const char D_00003A44[];
extern const char D_00003A50[];

#define MBUF_PANIC() \
	do { \
		Kprintf(D_00003A44, D_00003A50, __FUNCTION__); \
		for (;;) \
			; \
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

#endif
