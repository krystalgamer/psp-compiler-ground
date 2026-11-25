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

int func_000018BC(void)
{
	return 0;
}

struct mbuf *sceNetMGetclr(int nowait, int type)
{
	struct mbuf *m;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	m = sceNetMallocInternal(MSIZE);
	if (m == 0) {
		K1_RESTORE(oldk1);
		return 0;
	}
	m->m_type = type;
	m->m_next = 0;
	m->m_nextpkt = 0;
	m->m_data = m->m_dat;
	m->m_flags = 0;
	memset(m->m_dat, 0, MLEN);
	K1_RESTORE(oldk1);
	return m;
}

struct mbuf *sceNetMFree(struct mbuf *m)
{
	struct mbuf *n;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (m == 0 || (K1_USER() && (int)m < 0)) {
		K1_RESTORE(oldk1);
		return 0;
	}
	if ((m->m_flags & M_PKTHDR) && m->m_pkthdr.aux) {
		sceNetMFreem(m->m_pkthdr.aux);
		m->m_pkthdr.aux = 0;
	}
	if (m->m_flags & M_EXT) {
		if (m->m_ext.ext_nextref != m) {
			m->m_ext.ext_nextref->m_ext.ext_prevref = m->m_ext.ext_prevref;
			m->m_ext.ext_prevref->m_ext.ext_nextref = m->m_ext.ext_nextref;
		} else if (m->m_flags & M_CLUSTER)
			sceNetFreeInternal(m->m_ext.ext_buf);
		else if (m->m_ext.ext_free)
			(*m->m_ext.ext_free)(m->m_ext.ext_buf, m->m_ext.ext_size, m->m_ext.ext_arg);
		else
			sceNetFreeInternal(m->m_ext.ext_buf);
		m->m_flags &= ~(M_EXT | M_CLUSTER);
		m->m_ext.ext_size = 0;
	}
	n = m->m_next;
	sceNetFreeInternal(m);
	K1_RESTORE(oldk1);
	return n;
}

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", sceNetMFreem);

struct mbuf *sceNetMPrepend(struct mbuf *m, int len, int how)
{
	struct mbuf *mn;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (m == 0 || (K1_USER() && (int)m < 0))
		goto fail;
	MGET(mn, how, m->m_type);
	if (mn == 0) {
		sceNetMFreem(m);
		goto fail;
	}
	if (m->m_flags & M_PKTHDR) {
		M_COPY_PKTHDR(mn, m);
		m->m_flags &= ~M_PKTHDR;
	}
	mn->m_next = m;
	m = mn;
	if (len < MHLEN)
		MH_ALIGN(m, len);
	m->m_len = len;
	K1_RESTORE(oldk1);
	return m;
fail:
	K1_RESTORE(oldk1);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", sceNetMCopypacket);

INCLUDE_RODATA("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", D_00003A44);

INCLUDE_RODATA("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", D_00003A50);

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", sceNetMCopydata);

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", sceNetMAdj);

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", sceNetMPullup);

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", func_00002434);

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", sceNetMCopyback);

void sceNetIfhandle_lib_0FB8AE0D(void)
{
	unsigned int oldk1;

	K1_SAVE(oldk1);
	D_000043C8 = 0;
	D_000043CC = 0;
	D_000043D0 = 0;
	D_000043D4 = 0;
	K1_RESTORE(oldk1);
}

struct mbuf *sceNetMGet(int nowait, int type)
{
	struct mbuf *m;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	m = sceNetMallocInternal(MSIZE);
	if (m) {
		m->m_type = type;
		m->m_data = m->m_dat;
		m->m_next = 0;
		m->m_nextpkt = 0;
		m->m_flags = 0;
	}
	K1_RESTORE(oldk1);
	return m;
}

struct mbuf *sceNetMGethdr(int nowait, int type)
{
	struct mbuf *m;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	m = sceNetMallocInternal(MSIZE);
	if (m) {
		m->m_type = type;
		m->m_data = m->m_pktdat;
		m->m_flags = M_PKTHDR;
		m->m_next = 0;
		m->m_nextpkt = 0;
		m->m_pkthdr.aux = 0;
	}
	K1_RESTORE(oldk1);
	return m;
}

struct mbuf *sceNetMCopym(struct mbuf *m, int off, int len, int wait)
{
	struct mbuf *n;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (m == 0 || (K1_USER() && (int)m < 0)) {
		K1_RESTORE(oldk1);
		return 0;
	}
	n = func_00002C58(m, off, len, wait, 0);
	K1_RESTORE(oldk1);
	return n;
}

struct mbuf *sceNetMDup(struct mbuf *m, int off, int len, int wait)
{
	struct mbuf *n;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (m == 0 || (K1_USER() && (int)m < 0)) {
		K1_RESTORE(oldk1);
		return 0;
	}
	n = func_00002C58(m, off, len, wait, 1);
	K1_RESTORE(oldk1);
	return n;
}

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", sceNetMCat);

int sceNetIfhandle_lib_5FB31C72(int *a, int *b, int *c, int *d)
{
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if ((a && !k1ok(a)) || (b && !k1ok(b)) || (c && !k1ok(c)) || (d && !k1ok(d))) {
		K1_RESTORE(oldk1);
		return 0x80410003;
	}
	if (a)
		*a = D_000043C8;
	if (b)
		*b = D_000043CC;
	if (c)
		*c = D_000043D0;
	if (d)
		*d = D_000043D4;
	K1_RESTORE(oldk1);
	return 0;
}

int sceNetIfhandle_lib_62B20015(int a, int b, int c, int d)
{
	unsigned int oldk1;

	K1_SAVE(oldk1);
	D_000043C8 = a;
	D_000043CC = b;
	D_000043D0 = c;
	D_000043D4 = d;
	K1_RESTORE(oldk1);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/ifhandle/nonmatchings/mbuf", func_00002C58);
