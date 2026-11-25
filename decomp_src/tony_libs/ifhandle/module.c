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

int module_start(void)
{
	return 0;
}

int module_stop(void)
{
	return 0;
}
