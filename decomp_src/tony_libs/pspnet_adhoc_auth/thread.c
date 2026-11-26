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

const unsigned char D_00003E70[2] = { 0x88, 0xC8 };
const unsigned char D_00003E74[2] = { 0x00, 0x01 };
const unsigned char D_00003E78[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
const unsigned short D_00003E80[10] = { 0, 0, 0x80, 0x120, 0x110, 0x100, 0x60, 0x20, 0x30, 0 };

void func_00001758(AuthCtx *ctx, Peer *peer)
{
	int locked;
	struct mbuf *m;
	char *eh;
	int s;

	locked = func_00003968();
	if (peer == 0)
		goto out;
	if (peer->state < 1 || peer->state > 3)
		goto out;
	if (peer->unk4E0 >= ctx->unkE0 || ctx->unk0 == 2) {
		func_00003818(ctx, peer, 0);
		func_00003580(ctx, peer);
		goto out;
	}
	switch (peer->state) {
	case 1:
		m = func_000020B8(ctx, 3, &peer->unk15C);
		if (m) {
			int s1;

			send_pkt(ctx, m, peer->sa.mac.data);
		}
		break;
	case 2:
		m = func_000020B8(ctx, 5, &peer->unk38C);
		if (m) {
			int s1;

			send_pkt(ctx, m, peer->sa.mac.data);
		}
		break;
	}
	peer->unk4E0++;
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[0] > 0) {
		sceKernelCancelAlarm(peer->alarm[0]);
		peer->alarm[0] = 0;
	}
	peer->alarm[0] = sceKernelSetAlarm(ctx->unkDC, func_00003478, &peer->arg[0]);
	sceKernelCpuResumeIntr(s);
out:
	func_000039C4(locked);
}

void func_000019FC(AuthCtx *ctx)
{
	int locked;
	struct mbuf *m;
	char *eh;
	int s;

	locked = func_00003968();
	if (ctx->unk0 != 1)
		goto out;
	if (ctx->npeers >= ctx->unkA8)
		goto alarm;
	m = func_000020B8(ctx, 2, ctx->key.data);
	if (m) {
		int s1;

		m->m_flags |= M_BCAST;
		send_pkt(ctx, m, D_00003E78);
	}
alarm:
	s = sceKernelCpuSuspendIntr();
	if (ctx->alarm > 0) {
		sceKernelCancelAlarm(ctx->alarm);
		ctx->alarm = 0;
	}
	ctx->alarm = sceKernelSetAlarm(ctx->alarmTime, func_00003424, &ctx->arg);
	sceKernelCpuResumeIntr(s);
out:
	func_000039C4(locked);
}

void func_00001BA4(AuthCtx *ctx, Peer *peer)
{
	int locked;
	struct mbuf *m;
	char *eh;
	int s;
	struct {
		char hdr[0x20];
		unsigned int seq;
		char pad[0xC];
	} pkt;

	locked = func_00003968();
	if (peer == 0 || peer->state != 4 || ctx->unk0 == 2)
		goto out;
	memset(&pkt, 0, sizeof(pkt));
	pkt.seq = htonl(++peer->unk4E8);
	if (sceMemab_driver_E6D3ACE2(&peer->sa, &pkt.seq, 16, pkt.hdr, 1) < 0)
		goto out;
	m = func_000020B8(ctx, 8, &pkt);
	if (m) {
		int s1;

		send_pkt(ctx, m, peer->sa.mac.data);
	}
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[1] > 0) {
		sceKernelCancelAlarm(peer->alarm[1]);
		peer->alarm[1] = 0;
	}
	peer->alarm[1] = sceKernelSetAlarm(ctx->unkE4, func_00003528, &peer->arg[1]);
	sceKernelCpuResumeIntr(s);
out:
	func_000039C4(locked);
}

void func_00001DA0(AuthCtx *ctx, Peer *peer)
{
	int locked;
	struct mbuf *m;
	char *eh;
	struct ifnet *ifp;
	int s;
	char hdr[0x20];

	locked = func_00003968();
	if (peer == 0 || ctx->unk0 == 2)
		goto out;
	if (sceMemab_driver_E6D3ACE2(&peer->sa, 0, 0, hdr, 0) < 0)
		goto out;
	m = func_000020B8(ctx, 7, hdr);
	if (m) {
		eh = m->m_data;
		memcpy(eh, peer->sa.mac.data, 6);
		memcpy(eh + 6, ctx->mac.data, 6);
		memcpy(eh + 12, D_00003E70, 2);
		memcpy(eh + 14, D_00003E74, 2);
		s = sceKernelCpuSuspendIntr();
		ifp = ctx->ifh;
		IF_ENQUEUE(&ifp->if_snd, m);
		sceKernelCpuResumeIntr(s);
		ctx->ifh->if_start(ctx->ifh);
	}
	func_00003818(ctx, peer, 0);
	func_00003580(ctx, peer);
out:
	func_000039C4(locked);
}

void func_00001F2C(AuthCtx *ctx)
{
	int locked;
	struct mbuf *m;
	char *eh;
	int s;
	Peer *p;
	char hdr[0x20];

	locked = func_00003968();
	if (sceMemab_driver_F1D2B9B0(0, 0, hdr, 0) < 0)
		goto out;
	m = func_000020B8(ctx, 7, hdr);
	if (m) {
		m->m_flags |= M_BCAST;
		send_pkt(ctx, m, D_00003E78);
	}
	while ((p = ctx->first) != 0) {
		func_00003818(ctx, p, 0);
		func_00003580(ctx, p);
	}
out:
	func_000039C4(locked);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/thread", func_000020B8);
