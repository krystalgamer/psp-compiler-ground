/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

int func_000014F0(unsigned int args, void *argp)
{
	AuthCtx *ctx = *(AuthCtx **)argp;
	struct authmsg *msg;
	Peer *peer;
	int s;

	for (;;) {
		if (sceKernelReceiveMbx(ctx->mbx, (void **)&msg, 0) < 0)
			break;
		peer = msg->peer;
		switch (msg->type) {
		case 0:
			s = sceKernelCpuSuspendIntr();
			ctx->flags &= ~1;
			sceKernelCpuResumeIntr(s);
			func_00001664(ctx);
			break;
		case 3:
			s = sceKernelCpuSuspendIntr();
			ctx->flags &= ~2;
			sceKernelCpuResumeIntr(s);
			func_000019FC(ctx);
			break;
		case 1:
			s = sceKernelCpuSuspendIntr();
			peer->flags &= ~0x10;
			sceKernelCpuResumeIntr(s);
			func_00001758(ctx, peer);
			break;
		case 4:
			s = sceKernelCpuSuspendIntr();
			peer->flags &= ~0x80;
			sceKernelCpuResumeIntr(s);
			func_00001BA4(ctx, peer);
			break;
		case 5:
			s = sceKernelCpuSuspendIntr();
			peer->flags &= ~0x40;
			sceKernelCpuResumeIntr(s);
			func_00001DA0(ctx, peer);
			break;
		case 6:
			func_00001F2C(ctx);
			return 0;
		}
	}
	return 0;
}

void func_00001664(AuthCtx *ctx)
{
	struct mbuf *m;
	char *buf;
	int s;

	for (;;) {
		s = sceKernelCpuSuspendIntr();
		IF_DEQUEUE(&D_00004058, m);
		sceKernelCpuResumeIntr(s);
		if (m == 0)
			break;
		if (m->m_pkthdr.len != m->m_len) {
			buf = sceNetMallocInternal(m->m_pkthdr.len);
			if (buf == 0)
				goto next;
			sceNetMCopydata(m, 0, m->m_pkthdr.len, buf);
		} else
			buf = m->m_data;
		func_00002224(ctx, buf, m->m_pkthdr.len);
		if (m->m_pkthdr.len != m->m_len)
			sceNetFreeInternal(buf);
next:
		sceNetMFreem(m);
	}
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", func_00001758);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", func_000019FC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", func_00001BA4);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", func_00001DA0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", func_00001F2C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", func_000020B8);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", D_00003E70);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", D_00003E74);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", D_00003E78);

INCLUDE_RODATA("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", D_00003E80);
