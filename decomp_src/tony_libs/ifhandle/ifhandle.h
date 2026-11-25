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
#define MLEN (MSIZE - 0x14)
#define MHLEN (MLEN - 0x1C)

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

struct mbuf {
	struct mbuf *m_next;
	struct mbuf *m_nextpkt;
	char *m_data;
	int m_len;
	short m_type;
	unsigned short m_flags;
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

void *sceNetMallocInternal(unsigned int size);
void sceNetFreeInternal(void *p);
void *memset(void *, int, unsigned int);
void *memcpy(void *, const void *, unsigned int);
struct mbuf *sceNetMFree(struct mbuf *m);
void sceNetMFreem(struct mbuf *m);
struct mbuf *func_00002C58(struct mbuf *m, int off, int len, int wait, int deep);

extern int D_000043C8;
extern int D_000043CC;
extern int D_000043D0;
extern int D_000043D4;
extern int D_000043D8;

#endif
