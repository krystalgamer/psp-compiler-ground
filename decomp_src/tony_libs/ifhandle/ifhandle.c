/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "ifhandle.h"

static inline void *mallocSub(unsigned int size)
{
	void *p;
	int used;
	SceKernelVplInfo info;

	if (sceKernelTryAllocateVpl(D_00003B28, size, &p) < 0)
		return 0;
	info.size = sizeof(info);
	if (sceKernelReferVplStatus(D_00003B28, &info) == 0) {
		used = info.poolSize - info.freeSize;
		if (D_00003B2C < used)
			D_00003B2C = used;
	}
	return p;
}

static inline int k1PtrOk(const void *p)
{
	if (p == 0)
		return 0;
	if (K1_USER() && (int)p < 0)
		return 0;
	return 1;
}

#define MFREE(m, n) \
	do { \
		if (((m)->m_flags & M_PKTHDR) && (m)->m_pkthdr.aux) { \
			sceNetMFreem((m)->m_pkthdr.aux); \
			(m)->m_pkthdr.aux = 0; \
		} \
		if ((m)->m_flags & M_EXT) { \
			if ((m)->m_ext.ext_nextref != (m)) { \
				(m)->m_ext.ext_nextref->m_ext.ext_prevref = (m)->m_ext.ext_prevref; \
				(m)->m_ext.ext_prevref->m_ext.ext_nextref = (m)->m_ext.ext_nextref; \
			} else if ((m)->m_flags & M_CLUSTER) \
				sceNetFreeInternal((m)->m_ext.ext_buf); \
			else if ((m)->m_ext.ext_free) \
				(*(m)->m_ext.ext_free)((m)->m_ext.ext_buf, (m)->m_ext.ext_size, (m)->m_ext.ext_arg); \
			else \
				sceNetFreeInternal((m)->m_ext.ext_buf); \
			(m)->m_flags &= ~(M_EXT | M_CLUSTER); \
			(m)->m_ext.ext_size = 0; \
		} \
		(n) = (m)->m_next; \
		sceNetFreeInternal(m); \
	} while (0)
/* --- end declarations --- */

void sceNetIfhandleTerm(void)
{
	struct mbuf *m;
	int i;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	for (;;) {
		IF_DEQUEUE(&D_00003B74, m);
		if (m == 0)
			break;
		sceNetMFreem(m);
	}
	for (i = 0; i < 8; i++)
		D_00003B54[i] = 0;
	D_00003B30 = 0;
	K1_RESTORE(oldk1);
}

void sceNetIfhandleIfStart(struct ifinternal *ifp, struct mbuf *m)
{
	SceNetIfHandle *h;
	int i;
	int s;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (ifp == 0 || !k1ok(ifp))
		goto end;
	for (i = 0; i < 8; i++) {
		h = D_00003B54[i];
		if (h && h->ifp == ifp)
			break;
	}
	if (i == 8)
		goto end;
	if (m == 0)
		goto end;
	s = sceKernelCpuSuspendIntr();
	IF_ENQUEUE(&h->snd, m);
	sceKernelCpuResumeIntr(s);
	h->start(h);
end:
	K1_RESTORE(oldk1);
}

int sceNetIfhandle_driver_16042084(SceNetIfHandle *h)
{
	struct ifinternal *ifp;
	int i;
	int ret;

	if (h == 0)
		return 0x80000103;
	for (i = 0; i < 8; i++) {
		if (D_00003B54[i] == 0)
			break;
	}
	if (i == 8)
		return 0x80000022;
	h->ifp = sceNetMallocInternal(sizeof(struct ifinternal));
	if (h->ifp == 0)
		return 0x80000022;
	memset(h->ifp, 0, sizeof(struct ifinternal));
	ifp = h->ifp;
	ret = sceKernelCreateSema("SceNetIoctlSema", 1, 0, 0xFF, 0);
	if (ret < 0)
		goto err1;
	ifp->ioctlSema = ret;
	ret = sceKernelCreateSema("SceNetIoctlOKSema", 1, 1, 1, 0);
	if (ret < 0)
		goto err2;
	ifp->ioctlOkSema = ret;
	D_00003B54[i] = h;
	return 0;
err2:
	sceKernelDeleteSema(ifp->ioctlSema);
err1:
	sceNetFreeInternal(h->ifp);
	return ret;
}

int sceNetIfhandle_driver_AE81C0CB(SceNetIfHandle *h, const char *mac, const char *name)
{
	struct ifinternal *ifp;
	int i;
	int sema;
	int ret;

	if (h == 0 || mac == 0 || name == 0)
		return 0x80000103;
	if (D_00003B34 != 0)
		return 0x80000021;
	for (i = 0; i < 8; i++) {
		if (D_00003B54[i] == h)
			break;
	}
	if (i == 8)
		return 0x80000025;
	ifp = h->ifp;
	h->snd.ifq_tail = 0;
	h->snd.ifq_len = 0;
	h->snd.ifq_maxlen = 0;
	h->snd.ifq_drops = 0;
	h->snd.ifq_head = 0;
	strncpy(ifp->name, name, sizeof(ifp->name));
	memcpy(ifp->mac, mac, 6);
	ret = sceKernelCreateSema("SceNetAttachIfhandleEther", 1, 0, 1, 0);
	if (ret >= 0) {
		sema = ret;
		D_00003B34 = ifp;
		D_00003B38 = sema;
		ret = sceKernelSetEventFlag(D_00003B30, 1);
		if (ret >= 0)
			ret = sceKernelWaitSema(sema, 1, 0);
		sceKernelDeleteSema(sema);
	}
	return ret;
}

int sceNetIfhandle_driver_54D1AEA1(SceNetIfHandle *h)
{
	struct ifinternal *ifp;
	struct ifqueue q;
	struct mbuf *m;
	int i;
	int s;
	int sema;
	int ret;

	if (h == 0)
		return 0x80000103;
	if (D_00003B3C != 0)
		return 0x80000021;
	for (i = 0; i < 8; i++) {
		if (D_00003B54[i] == h)
			break;
	}
	if (i == 8)
		return 0x80000025;
	q.ifq_head = 0;
	q.ifq_tail = 0;
	q.ifq_len = 0;
	q.ifq_maxlen = 0;
	q.ifq_drops = 0;
	ifp = h->ifp;
	for (;;) {
		s = sceKernelCpuSuspendIntr();
		IF_DEQUEUE(&D_00003B74, m);
		sceKernelCpuResumeIntr(s);
		if (m == 0)
			break;
		if (m->m_pkthdr.rcvif != ifp)
			IF_ENQUEUE(&q, m);
		else
			sceNetMFreem(m);
	}
	for (;;) {
		IF_DEQUEUE(&q, m);
		if (m == 0)
			break;
		s = sceKernelCpuSuspendIntr();
		IF_ENQUEUE(&D_00003B74, m);
		sceKernelCpuResumeIntr(s);
	}
	ret = sceKernelCreateSema("SceNetDetachIfhandleEther", 1, 0, 1, 0);
	if (ret >= 0) {
		sema = ret;
		D_00003B3C = ifp;
		D_00003B40 = sema;
		ret = sceKernelSetEventFlag(D_00003B30, 2);
		if (ret >= 0) {
			ret = sceKernelWaitSema(sema, 1, 0);
			for (;;) {
				IF_DEQUEUE(&h->snd, m);
				if (m == 0)
					break;
				sceNetMFreem(m);
			}
		}
		sceKernelDeleteSema(sema);
	}
	return ret;
}

void sceNetIfhandle_driver_263767F6(SceNetIfHandle *h, int a, int b)
{
	struct ifinternal *ifp;
	struct evnode *n = 0;
	int s;

	if (h == 0)
		return;
	ifp = h->ifp;
	s = sceKernelCpuSuspendIntr();
	if (ifp->evf != 0 && ifp->evBits != 0) {
		n = sceNetMallocInternal(sizeof(struct evnode));
		if (n) {
			n->a = a;
			n->prev = ifp->evLast;
			n->next = 0;
			n->b = b;
			*ifp->evLast = n;
			ifp->evLast = &n->next;
		}
	}
	sceKernelCpuResumeIntr(s);
	if (n)
		sceKernelSetEventFlag(ifp->evf, ifp->evBits);
}

struct mbuf *sceNetIfDequeue(SceNetIfHandle *h)
{
	struct mbuf *m;
	int s;

	if (h == 0)
		return 0;
again:
	s = sceKernelCpuSuspendIntr();
	IF_DEQUEUE(&h->snd, m);
	sceKernelCpuResumeIntr(s);
	sceKernelSetEventFlag(D_00003B30, 8);
	if (m && (short)m->m_flags < 0) {
		if (D_00003B44 <= 0 || D_00003B4C(m) < 0) {
			sceNetMFreem(m);
			goto again;
		}
	}
	if (func_00001478() > 0) {
		sceNetMFreem(m);
		m = 0;
	}
	return m;
}

void sceNetIfEnqueue(SceNetIfHandle *h, struct mbuf *m)
{
	struct ether_header *eh;
	unsigned short type;
	unsigned short sub;
	int s;

	if (h == 0)
		return;
	if (func_00001478() > 0)
		goto drop;
	m->m_pkthdr.rcvif = h->ifp;
	eh = mtod(m, struct ether_header *);
	type = ntohs(eh->ether_type);
	if (eh->ether_dhost[0] & 1) {
		if (memcmp(D_00003B20, eh->ether_dhost, 6) == 0)
			m->m_flags |= M_BCAST;
		else
			m->m_flags |= M_MCAST;
	}
	if (type == 0x88C8) {
		if (m->m_pkthdr.len < 16)
			goto drop;
		sceNetMCopydata(m, 14, 2, (char *)&sub);
		switch (ntohs(sub)) {
		case 1:
			if (D_00003B44 > 0 && D_00003B50(m) >= 0)
				return;
			goto drop;
		case 2:
			if (m->m_pkthdr.len < 0x30)
				goto drop;
			if (D_00003B44 <= 0)
				goto drop;
			if (D_00003B48(m) < 0)
				goto drop;
			break;
		default:
			goto drop;
		}
	}
	s = sceKernelCpuSuspendIntr();
	IF_ENQUEUE(&D_00003B74, m);
	sceKernelCpuResumeIntr(s);
	sceKernelSetEventFlag(D_00003B30, 4);
	return;
drop:
	sceNetMFreem(m);
}

int sceNetIfhandleInit(int evf)
{
	int i;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	D_00003B30 = evf;
	for (i = 0; i < 8; i++)
		D_00003B54[i] = 0;
	D_00003B74.ifq_head = 0;
	D_00003B74.ifq_tail = 0;
	D_00003B74.ifq_len = 0;
	D_00003B74.ifq_maxlen = 0;
	D_00003B74.ifq_drops = 0;
	func_000012BC(sceKernelGetSystemTimeLow());
	D_00003B88 = 0;
	D_00003B8C = 0;
	D_00003B90 = 0;
	D_00003B94 = 0;
	D_00003B98 = 0;
	K1_RESTORE(oldk1);
	return 0;
}

int sceNetIfhandle_lib_B8188F96(struct ifinternal **pifp, int *psema)
{
	int ret;
	unsigned int oldk1;

	ret = 0;
	K1_SAVE(oldk1);
	if (pifp == 0 || !k1ok(pifp) || psema == 0 || !k1ok(psema)) {
		ret = 0x80410003;
		goto end;
	}
	if (D_00003B34 == 0) {
		ret = 0x80410004;
		goto end;
	}
	*pifp = D_00003B34;
	*psema = D_00003B38;
	D_00003B34 = 0;
	D_00003B38 = 0;
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetIfhandle_lib_4FB43BCE(struct ifinternal **pifp, int *psema)
{
	int ret;
	unsigned int oldk1;

	ret = 0;
	K1_SAVE(oldk1);
	if (pifp == 0 || !k1ok(pifp) || psema == 0 || !k1ok(psema)) {
		ret = 0x80410003;
		goto end;
	}
	if (D_00003B3C == 0) {
		ret = 0x80410004;
		goto end;
	}
	*pifp = D_00003B3C;
	*psema = D_00003B40;
	D_00003B3C = 0;
	D_00003B40 = 0;
end:
	K1_RESTORE(oldk1);
	return ret;
}

void sceNetIfhandleIfUp(struct ifinternal *ifp)
{
	SceNetIfHandle *h;
	int i;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (ifp == 0 || !k1ok(ifp))
		goto end;
	for (i = 0; i < 8; i++) {
		h = D_00003B54[i];
		if (h && h->ifp == ifp)
			break;
	}
	if (i == 8)
		goto end;
	h->up(h);
end:
	K1_RESTORE(oldk1);
}

void sceNetIfhandleIfDown(struct ifinternal *ifp)
{
	SceNetIfHandle *h;
	int i;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (ifp == 0 || !k1ok(ifp))
		goto end;
	for (i = 0; i < 8; i++) {
		h = D_00003B54[i];
		if (h && h->ifp == ifp)
			break;
	}
	if (i == 8)
		goto end;
	h->down(h);
end:
	K1_RESTORE(oldk1);
}

void sceNetIfhandleIfIoctl(struct ifinternal *ifp, int cmd, void *data)
{
	SceNetIfHandle *h;
	int i;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (ifp == 0 || !k1ok(ifp))
		goto end;
	if (data == 0 || !k1ok(data))
		goto end;
	for (i = 0; i < 8; i++) {
		h = D_00003B54[i];
		if (h && h->ifp == ifp)
			break;
	}
	if (i == 8)
		goto end;
	h->ioctl(h, cmd, data);
end:
	K1_RESTORE(oldk1);
}

struct mbuf *sceNetIfhandleIfDequeue(void)
{
	struct mbuf *m;
	int s;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	s = sceKernelCpuSuspendIntr();
	IF_DEQUEUE(&D_00003B74, m);
	sceKernelCpuResumeIntr(s);
	K1_RESTORE(oldk1);
	return m;
}

int sceNetIfhandleSignalSema(int id, int n)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = sceKernelSignalSema(id, n);
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetIfhandleWaitSema(int id, int n, unsigned int *timeout)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (!k1ok(timeout))
		ret = 0x80410003;
	else
		ret = sceKernelWaitSema(id, n, timeout);
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetIfhandlePollSema(int id, int n)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = sceKernelPollSema(id, n);
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetIfhandle_driver_C9344A59(SceNetIfHandle *h)
{
	struct ifinternal *ifp;
	int i;

	if (h == 0)
		return 0x80000103;
	for (i = 0; i < 8; i++) {
		if (D_00003B54[i] == h)
			break;
	}
	if (i == 8)
		return 0x80000025;
	ifp = h->ifp;
	sceKernelDeleteSema(ifp->ioctlSema);
	sceKernelDeleteSema(ifp->ioctlOkSema);
	sceNetFreeInternal(h->ifp);
	D_00003B54[i] = 0;
	return 0;
}

void sceNetIfhandle_driver_F94BAF52(SceNetIfHandle *h, int unused, int val)
{
	struct ifinternal *ifp;

	if (h == 0)
		return;
	ifp = h->ifp;
	ifp->unk10C = val;
	sceKernelSignalSema(ifp->ioctlSema, 1);
}

void sceNetIfPrepend(SceNetIfHandle *h, struct mbuf *m)
{
	int s;

	if (h == 0)
		return;
	s = sceKernelCpuSuspendIntr();
	IF_PREPEND(&h->snd, m);
	sceKernelCpuResumeIntr(s);
}

int sceNetIfhandle_driver_C6D14282(SceNetIfHandle *h, int val)
{
	if (h == 0)
		return 0x80000103;
	h->unk4 = val;
	return 0;
}

int sceNetIfhandle_driver_D5AD6DEA(SceNetIfHandle *h)
{
	if (h == 0)
		return 0;
	return h->unk4;
}

int sceNetIfhandle_driver_0542835F(int (*a)(struct mbuf *), int (*fn)(struct mbuf *), int (*c)(struct mbuf *))
{
	int s;

	s = sceKernelCpuSuspendIntr();
	D_00003B48 = a;
	D_00003B4C = fn;
	D_00003B50 = c;
	D_00003B44 = 1;
	sceKernelCpuResumeIntr(s);
	return 0;
}

int sceNetIfhandle_driver_773FC77C(void)
{
	int s;

	s = sceKernelCpuSuspendIntr();
	D_00003B44 = 0;
	D_00003B48 = 0;
	D_00003B4C = 0;
	D_00003B50 = 0;
	sceKernelCpuResumeIntr(s);
	return 0;
}

SceNetIfHandle *sceNetIfhandle_driver_9CBA24D4(const char *name)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (D_00003B54[i] && D_00003B54[i]->ifp &&
		    strcmp(D_00003B54[i]->ifp->name, name) == 0)
			return D_00003B54[i];
	}
	return 0;
}

int sceNetIfhandle_driver_C5623112(SceNetIfHandle *h, char *mac)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (D_00003B54[i] == h) {
			memcpy(mac, D_00003B54[i]->ifp->mac, 6);
			return 0;
		}
	}
	return 0x80000025;
}

int sceNetGetDropRate(int *rate, int *duration)
{
	int ret;
	unsigned int oldk1;

	ret = 0;
	K1_SAVE(oldk1);
	if (rate == 0 || duration == 0 || !k1ok(rate) || !k1ok(duration)) {
		ret = 0x80410003;
		goto end;
	}
	*rate = D_00003B88;
	*duration = D_00003B8C;
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetSetDropRate(unsigned int rate, int duration)
{
	int ret;
	int s;
	unsigned int oldk1;

	ret = 0;
	K1_SAVE(oldk1);
	if (rate > 100) {
		ret = 0x80410003;
		goto end;
	}
	s = sceKernelCpuSuspendIntr();
	D_00003B88 = rate;
	D_00003B8C = duration;
	D_00003B98 = 0;
	D_00003B9C = 0;
	D_00003B94 = 0;
	sceKernelCpuResumeIntr(s);
end:
	K1_RESTORE(oldk1);
	return ret;
}

void func_000012BC(unsigned int seed)
{
	int i, j;
	unsigned int u;

	u = 0;
	for (i = 0; i <= 16; i++) {
		for (j = 0; j < 32; j++) {
			seed = seed * 1566083941UL + 1;
			u = (u >> 1) | (seed & (1UL << 31));
		}
		D_00003BA0[i] = u;
	}
	D_00003BA0[16] = (D_00003BA0[16] << 23) ^ (D_00003BA0[0] >> 9) ^ D_00003BA0[15];
	for (i = 17; i <= 520; i++)
		D_00003BA0[i] = (D_00003BA0[i - 17] << 23) ^ (D_00003BA0[i - 16] >> 9) ^ D_00003BA0[i - 1];
	rnd521_refresh();
	rnd521_refresh();
	rnd521_refresh();
	D_000043C4 = 520;
}

int func_00001478(void)
{
	int drop = 0;
	unsigned int now;
	int s;

	if (D_00003B88 == 0 || D_00003B8C == 0)
		return 0;
	now = sceKernelGetSystemTimeLow() / 1000000;
	s = sceKernelCpuSuspendIntr();
	if (D_00003B98 == 0) {
		if (D_00003B94 < now) {
			if (D_00003B88 == 100) {
				if (D_00003B9C == 0) {
					D_00003B90 = now + D_00003B8C;
					D_00003B98 = 1;
					D_00003B9C = 1;
					drop = 1;
				}
			} else if (irnd() / 42949673 < D_00003B88) {
				D_00003B90 = now + D_00003B8C;
				D_00003B98 = 1;
				drop = 1;
			} else
				D_00003B94 = now;
		}
	} else {
		if (now < D_00003B90) {
			drop = 1;
			goto out;
		}
		D_00003B94 = now;
		D_00003B98 = 0;
		D_00003B90 = 0;
	}
out:
	sceKernelCpuResumeIntr(s);
	return drop;
}
