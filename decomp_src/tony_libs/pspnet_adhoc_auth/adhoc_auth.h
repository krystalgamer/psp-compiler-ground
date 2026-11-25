#ifndef ADHOC_AUTH_H
#define ADHOC_AUTH_H

#define K1_SAVE(old) asm volatile(".set noreorder\n\tmove %0, $27\n\tsrl $27, $27, 16\n\t.set reorder" : "=r"(old))
#define K1_RESTORE(old) asm volatile("move $27, %0" : : "r"(old))
#define K1_USER() ({ unsigned int _u; asm volatile("andi %0, $27, 0x18" : "=r"(_u)); _u; })

static inline int k1ok(const void *p)
{
	if (!K1_USER())
		return 1;
	return ((unsigned int)p >> 31) ^ 1;
}

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

struct mbuf {
	struct mbuf *m_next;
	struct mbuf *m_nextpkt;
	char *m_data;
	int m_len;
	short m_type;
	unsigned short m_flags;
	struct pkthdr m_pkthdr;
};

#define M_BCAST 0x0100
#define M_MCAST 0x0200

struct ifqueue {
	struct mbuf *ifq_head;
	struct mbuf *ifq_tail;
	int ifq_len;
	int ifq_maxlen;
	int ifq_drops;
};

#define IF_QFULL(ifq) ((ifq)->ifq_len >= (ifq)->ifq_maxlen)

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

typedef struct {
	unsigned char data[6];
} EtherAddr;

typedef struct {
	unsigned char data[0x80];
} AuthKey;

/* security association, hashed by the last MAC byte */
struct sa {
	char unk0[0xC0];
	struct sa *next;
	struct sa **prev;
	EtherAddr mac;
};

typedef struct AuthPeerInfo {
	struct AuthPeerInfo *next;
	AuthKey key;
	EtherAddr mac;
} AuthPeerInfo;

struct sahead {
	struct sa *first;
	struct sa **last;
};

struct Peer;
struct AuthCtx;

struct authmsg {
	int hdr[2];
	int type;
	struct Peer *peer;
};

struct alarmarg {
	struct AuthCtx *ctx;
	struct Peer *peer;
	struct authmsg msg;
};

typedef struct Peer {
	struct Peer *next;
	struct Peer **prev;
	int state;
	struct sa sa;
	AuthKey key;
	char pad15C[0x48C - 0x15C];
	struct alarmarg arg[3];
	int alarm[3];
	int unk4E0;
	int flags;
	int unk4E8;
	int unk4EC;
} Peer;

typedef struct AuthCtx {
	int unk0;
	int mbx;
	int thid;
	int flags;
	Peer *first;
	Peer **last;
	int npeers;
	void *ifh;
	EtherAddr mac;
	AuthKey key;
	char padA6[2];
	int unkA8;
	struct authmsg msg;
	unsigned int alarmTime;
	int alarm;
	struct alarmarg arg;
	int unkDC;
	int unkE0;
	int unkE4;
	int unkE8;
} AuthCtx;

void *memcpy(void *, const void *, unsigned int);
void *memset(void *, int, unsigned int);
int memcmp(const void *, const void *, unsigned int);
int sceKernelCpuSuspendIntr(void);
int sceKernelCpuResumeIntr(int s);
int sceKernelCreateSema(const char *name, unsigned int attr, int init, int max, void *opt);
int sceKernelDeleteSema(int id);
int sceKernelSignalSema(int id, int n);
int sceKernelWaitSema(int id, int n, unsigned int *timeout);
int sceKernelGetThreadId(void);
int sceKernelSendMbx(int id, void *msg);
int sceKernelReceiveMbx(int id, void **msg, unsigned int *timeout);
int sceKernelCancelAlarm(int id);
int sceKernelSetAlarm(unsigned int clock, unsigned int (*handler)(void *), void *common);
int sceKernelWaitThreadEnd(int thid, unsigned int *timeout);
int sceKernelTerminateThread(int thid);
int sceKernelDeleteThread(int thid);
int sceKernelDeleteMbx(int id);
void sceNetMFreem(struct mbuf *m);
void func_0000392C(void);
unsigned int func_00003424(void *common);
void func_00001664(AuthCtx *ctx);
void func_00001758(AuthCtx *ctx, Peer *peer);
void func_000019FC(AuthCtx *ctx);
void func_00001BA4(AuthCtx *ctx, Peer *peer);
void func_00001DA0(AuthCtx *ctx, Peer *peer);
void func_00001F2C(AuthCtx *ctx);
void func_00002224(AuthCtx *ctx, char *buf, int len);
unsigned int func_000034D0(void *common);
unsigned int func_00003528(void *common);
void *sceNetMallocInternal(unsigned int size);
void sceNetFreeInternal(void *p);
void sceNetMCopydata(struct mbuf *m, int off, int len, void *cp);
void sceNetMCopyback(struct mbuf *m, int off, int len, void *cp);
int sceMemab_driver_01FD1BA0(void);
int sceMemab_driver_0C134D3F(void);
int sceMemab_driver_4DF566D3(struct sa *sa, void *data, int len, void *hdr, int a, int b);
int sceMemab_driver_B54E1AA7(struct sa *sa, void *data, int len, void *hdr, int a, int b);
int sceMemab_driver_E6D3ACE2(struct sa *sa, void *data, int len, void *hdr, int a);
int sceMemab_driver_F1D2B9B0(void *data, int len, void *hdr, int a);
int sceNetIfhandle_driver_0542835F(int (*a)(struct mbuf *), int (*b)(struct mbuf *), int (*c)(struct mbuf *));
int sceNetIfhandle_driver_773FC77C(void);

int func_00000000(struct mbuf *m);
int func_00000288(struct mbuf *m);
int func_00001110(struct mbuf *m);
int func_000011F0(void);
void func_000011F8(void);
int func_00001214(void);
void func_00001290(void);
struct sa *func_0000147C(const unsigned char *mac);
int sceNetAdhocAuth_lib_2E6AA271(void);
void func_000038D0(int *p, int v);
int func_00003968(void);
void func_000039C4(int locked);
int func_000012C4(struct sa *sa);
int func_000013A4(struct sa *sa);

static inline void cancelAlarm(int *alarm)
{
	int s;

	s = sceKernelCpuSuspendIntr();
	if (*alarm > 0) {
		sceKernelCancelAlarm(*alarm);
		*alarm = 0;
	}
	sceKernelCpuResumeIntr(s);
}

extern int D_00003ED0;
extern int D_00003ED4;
extern int D_00003EE0;
extern AuthCtx *D_00003EE4;
extern AuthCtx D_00003EE8;
extern int D_00003FD4;
extern struct sahead D_00003FD8[16];
extern struct ifqueue D_00004058;

static inline struct sa *sa_lookup(const unsigned char *mac)
{
	struct sa *p;

	for (p = D_00003FD8[mac[5] & 0xF].first; p; p = p->next)
		if (memcmp(p->mac.data, mac, 6) == 0)
			break;
	return p;
}

#endif
