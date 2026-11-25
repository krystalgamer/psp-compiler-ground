/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

int func_00000000(struct mbuf *m)
{
	char *buf = 0;
	char *p;
	struct sa *sa;
	int r;

	if (m->m_pkthdr.len != m->m_len) {
		buf = sceNetMallocInternal(m->m_pkthdr.len - 0x10);
		if (buf == 0)
			return -1;
		sceNetMCopydata(m, 0x10, m->m_pkthdr.len - 0x10, buf);
		p = buf;
	} else
		p = m->m_data + 0x10;
	sceKernelWaitSema(D_00003FD4, 1, 0);
	sa = func_0000147C((unsigned char *)m->m_data + 6);
	if (sa == 0)
		goto fail;
	if (m->m_flags & M_BCAST)
		r = sceMemab_driver_4DF566D3(sa, p + 0x20, m->m_pkthdr.len - 0x30, p, 1, 1);
	else if (m->m_flags & M_MCAST)
		goto fail;
	else
		r = sceMemab_driver_B54E1AA7(sa, p + 0x20, m->m_pkthdr.len - 0x30, p, 1, 1);
	if (r < 0)
		goto fail;
	if (buf) {
		sceNetMCopyback(m, 0x30, m->m_pkthdr.len - 0x30, p);
		sceNetFreeInternal(buf);
	}
	sceKernelSignalSema(D_00003FD4, 1);
	return 0;
fail:
	sceKernelSignalSema(D_00003FD4, 1);
	if (buf)
		sceNetFreeInternal(buf);
	return -1;
}

int sceNetAdhocAuthInit(void)
{
	int ret;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	ret = 0x80410601;
	if (D_00003EE0 > 0)
		goto end;
	ret = func_00001214();
	if (ret < 0)
		goto end;
	ret = func_000011F0();
	if (ret < 0)
		goto err1;
	ret = sceNetIfhandle_driver_0542835F(func_00000000, func_00000288, func_00001110);
	if (ret < 0)
		goto err2;
	D_00003EE0 = 1;
	K1_RESTORE(oldk1);
	return 0;
err2:
	func_000011F8();
err1:
	func_00001290();
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetAdhocAuthTerm(void)
{
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (D_00003EE0 > 0) {
		sceNetIfhandle_driver_773FC77C();
		func_000011F8();
		func_00001290();
		D_00003EE0 = 0;
	}
	K1_RESTORE(oldk1);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/auth", func_00000288);
