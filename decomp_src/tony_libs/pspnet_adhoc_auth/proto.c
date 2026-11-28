/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

void func_00002224(AuthCtx *ctx, char *buf, int len)
{
	struct authhdr *h;
	unsigned short l;
	int locked;
	Peer *peer;
	int r;

	if (memcmp(ctx->mac.data, buf + 6, 6) == 0)
		return;
	h = (struct authhdr *)(buf + 0x10);
	if (h->ver != 1)
		return;
	if (h->type == 0 || h->type > 8)
		return;
	memcpy(&l, h->len, 2);
	l = ntohs16(l);
	if (l != D_00003E80[h->type])
		return;
	if (len < l + 0x14)
		return;
	locked = func_00003968();
	peer = func_000037C0(ctx, (unsigned char *)buf + 6);
	switch (h->type) {
	case 2:
		func_00002458(ctx, peer, buf);
		break;
	case 3:
		func_000026F8(ctx, peer, buf);
		break;
	case 4:
		func_00002C44(ctx, peer, buf);
		break;
	case 5:
		func_00002EE0(ctx, peer, buf);
		break;
	case 6:
		func_00003188(ctx, peer, buf);
		break;
	case 7:
		if (peer == 0)
			break;
		if (memcmp(buf, D_00003E78, 6) == 0)
			r = sceMemab_driver_4DF566D3(&peer->sa, 0, 0, buf + 0x14, 0, 0);
		else
			r = sceMemab_driver_B54E1AA7(&peer->sa, 0, 0, buf + 0x14, 0, 0);
		if (r < 0)
			break;
		func_00003818(ctx, peer, 0);
		func_00003580(ctx, peer);
		break;
	case 8:
		func_00003330(ctx, peer, buf);
		break;
	}
	func_000039C4(locked);
}

void func_00002458(AuthCtx *ctx, Peer *peer, char *pkt)
{
	AuthBuf buf;
	struct mbuf *m;
	char *eh;
	int s;

	if (ctx->unk0 != 1)
		return;
	if (ctx->npeers >= ctx->unkA8)
		return;
	if (peer != 0)
		return;
	peer = sceNetMallocInternal(sizeof(Peer));
	if (peer == 0)
		return;
	func_00003664(ctx, peer, (unsigned char *)pkt + 6, (unsigned char *)pkt + 0x14);
	if (sceMemab_driver_A4720EED(&peer->sa, &buf) < 0) {
		func_00003580(ctx, peer);
		return;
	}
	buf.key = ctx->key;
	m = func_000020B8(ctx, 3, &buf);
	peer->unk15C = buf;
	if (m) {
		int s1;

		send_pkt(ctx, m, peer->sa.mac.data);
	}
	peer->unk4E0 = 0;
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[0] > 0) {
		sceKernelCancelAlarm(peer->alarm[0]);
		peer->alarm[0] = 0;
	}
	peer->alarm[0] = sceKernelSetAlarm(ctx->unkDC, func_00003478, &peer->arg[0]);
	sceKernelCpuResumeIntr(s);
	func_00003818(ctx, peer, 1);
}

void func_000026F8(AuthCtx *ctx, Peer *peer, char *pkt)
{
	SaKey key;
	AuthBuf3 buf;
	struct mbuf *m;
	int s;
	int i;

	if (ctx->unk0 != 1)
		return;
	if (ctx->npeers >= ctx->unkA8)
		return;
	if (sceMemab_driver_DC598EF3(&key, pkt + 0x14, &buf) < 0)
		return;
	if (peer == 0) {
		peer = sceNetMallocInternal(sizeof(Peer));
		if (peer == 0)
			return;
		func_00003664(ctx, peer, (unsigned char *)pkt + 6, (unsigned char *)pkt + 0xB4);
	} else {
		if (peer->state == 3 && memcmp(&peer->unk15C, pkt + 0x14, 0x120) != 0)
			goto reset;
		if (peer->state == 1) {
			for (i = 0; i < 6; i++) {
				if (ctx->mac.data[i] < peer->sa.mac.data[i])
					break;
				if (ctx->mac.data[i] > peer->sa.mac.data[i])
					goto reset;
			}
		}
		if (peer->state == 2) {
reset:
			cancelAlarm(&peer->alarm[0]);
			func_00003818(ctx, peer, 0);
		} else if (peer->state == 4) {
			cancelAlarm(&peer->alarm[2]);
			cancelAlarm(&peer->alarm[1]);
			func_00003818(ctx, peer, 0);
		}
	}
	if (peer->state == 0) {
		peer->sa.key = key;
		m = func_000020B8(ctx, 4, &buf);
		if (m)
			send_pkt(ctx, m, peer->sa.mac.data);
		peer->unk4E0 = 0;
		s = sceKernelCpuSuspendIntr();
		if (peer->alarm[0] > 0) {
			sceKernelCancelAlarm(peer->alarm[0]);
			peer->alarm[0] = 0;
		}
		peer->alarm[0] = sceKernelSetAlarm(ctx->unkDC, func_00003478, &peer->arg[0]);
		sceKernelCpuResumeIntr(s);
		memcpy(&peer->unk15C, pkt + 0x14, 0x120);
		peer->unk27C = buf;
		func_00003818(ctx, peer, 3);
	} else if (peer->state == 3) {
		m = func_000020B8(ctx, 4, &peer->unk27C);
		if (m)
			send_pkt(ctx, m, peer->sa.mac.data);
		peer->unk4E0 = 0;
		s = sceKernelCpuSuspendIntr();
		if (peer->alarm[0] > 0) {
			sceKernelCancelAlarm(peer->alarm[0]);
			peer->alarm[0] = 0;
		}
		peer->alarm[0] = sceKernelSetAlarm(ctx->unkDC, func_00003478, &peer->arg[0]);
		sceKernelCpuResumeIntr(s);
	}
}

void func_00002C44(AuthCtx *ctx, Peer *peer, char *pkt)
{
	SaKey key;
	AuthBuf2 buf;
	struct mbuf *m;
	char *eh;
	int s;

	if (ctx->unk0 != 1)
		return;
	if (peer == 0 || peer->state != 1)
		return;
	key = peer->sa.key;
	if (sceMemab_driver_8DAC2343(&key, pkt + 0x14, &buf) < 0)
		return;
	cancelAlarm(&peer->alarm[0]);
	peer->sa.key = key;
	m = func_000020B8(ctx, 5, &buf);
	peer->unk38C = buf;
	if (m) {
		int s1;

		send_pkt(ctx, m, peer->sa.mac.data);
	}
	peer->unk4E0 = 0;
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[0] > 0) {
		sceKernelCancelAlarm(peer->alarm[0]);
		peer->alarm[0] = 0;
	}
	peer->alarm[0] = sceKernelSetAlarm(ctx->unkDC, func_00003478, &peer->arg[0]);
	sceKernelCpuResumeIntr(s);
	func_00003818(ctx, peer, 2);
}

void func_00002EE0(AuthCtx *ctx, Peer *peer, char *pkt)
{
	SaKey key;
	char buf[0x60];
	struct mbuf *m;
	char *eh;
	int s;

	if (ctx->unk0 != 1)
		return;
	if (peer == 0 || peer->state != 3)
		return;
	key = peer->sa.key;
	if (sceMemab_driver_DAE8A629(&key, pkt + 0x14, buf) < 0)
		return;
	cancelAlarm(&peer->alarm[0]);
	peer->sa.key = key;
	m = func_000020B8(ctx, 6, buf);
	peer->unk4E8 = 0;
	peer->seq = 0;
	if (m) {
		int s1;

		send_pkt(ctx, m, peer->sa.mac.data);
	}
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[2] > 0) {
		sceKernelCancelAlarm(peer->alarm[2]);
		peer->alarm[2] = 0;
	}
	peer->alarm[2] = sceKernelSetAlarm(ctx->unkE8, func_000034D0, &peer->arg[2]);
	sceKernelCpuResumeIntr(s);
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[1] > 0) {
		sceKernelCancelAlarm(peer->alarm[1]);
		peer->alarm[1] = 0;
	}
	peer->alarm[1] = sceKernelSetAlarm(ctx->unkE4, func_00003528, &peer->arg[1]);
	sceKernelCpuResumeIntr(s);
	func_00003818(ctx, peer, 4);
}

void func_00003188(AuthCtx *ctx, Peer *peer, char *pkt)
{
	SaKey key;
	int s;

	if (ctx->unk0 != 1)
		return;
	if (peer == 0 || peer->state != 2)
		return;
	key = peer->sa.key;
	if (sceMemab_driver_CF49BCBB(&key, pkt + 0x14) < 0)
		return;
	cancelAlarm(&peer->alarm[0]);
	peer->sa.key = key;
	peer->unk4E8 = 0;
	peer->seq = 0;
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[2] > 0) {
		sceKernelCancelAlarm(peer->alarm[2]);
		peer->alarm[2] = 0;
	}
	peer->alarm[2] = sceKernelSetAlarm(ctx->unkE8, func_000034D0, &peer->arg[2]);
	sceKernelCpuResumeIntr(s);
	s = sceKernelCpuSuspendIntr();
	if (peer->alarm[1] > 0) {
		sceKernelCancelAlarm(peer->alarm[1]);
		peer->alarm[1] = 0;
	}
	peer->alarm[1] = sceKernelSetAlarm(ctx->unkE4, func_00003528, &peer->arg[1]);
	sceKernelCpuResumeIntr(s);
	func_00003818(ctx, peer, 4);
}

void func_00003330(AuthCtx *ctx, Peer *peer, char *pkt)
{
	unsigned int seq;
	int s;

	if (peer == 0 || peer->state != 4)
		return;
	char *hdr = pkt + 0x14;

	if (sceMemab_driver_B54E1AA7(&peer->sa, pkt + 0x34, 16, hdr, 1, 0) < 0)
		return;
	memcpy(&seq, ((struct authpkt *)pkt)->seq, 4);
	seq = ntohl(seq);
	if (peer->seq < seq) {
		peer->seq = seq;
		s = sceKernelCpuSuspendIntr();
		if (peer->alarm[2] > 0) {
			sceKernelCancelAlarm(peer->alarm[2]);
			peer->alarm[2] = 0;
		}
		peer->alarm[2] = sceKernelSetAlarm(ctx->unkE8, func_000034D0, &peer->arg[2]);
		sceKernelCpuResumeIntr(s);
	}
}


unsigned int func_00003424(void *common)
{
	struct alarmarg *arg = common;
	AuthCtx *ctx = arg->ctx;

	if (!(ctx->flags & 2)) {
		ctx->flags |= 2;
		sceKernelSendMbx(ctx->mbx, &ctx->arg.msg);
	}
	arg->ctx->alarm = 0;
	return 0;
}

unsigned int func_00003478(void *common)
{
	struct alarmarg *arg = common;
	Peer *peer = arg->peer;

	if (!(peer->flags & 0x10)) {
		peer->flags |= 0x10;
		sceKernelSendMbx(arg->ctx->mbx, &peer->arg[0].msg);
	}
	arg->peer->alarm[0] = 0;
	return 0;
}

unsigned int func_000034D0(void *common)
{
	struct alarmarg *arg = common;
	Peer *peer = arg->peer;

	if (!(peer->flags & 0x40)) {
		peer->flags |= 0x40;
		sceKernelSendMbx(arg->ctx->mbx, &peer->arg[2].msg);
	}
	arg->peer->alarm[2] = 0;
	return 0;
}

unsigned int func_00003528(void *common)
{
	struct alarmarg *arg = common;
	Peer *peer = arg->peer;

	if (!(peer->flags & 0x80)) {
		peer->flags |= 0x80;
		sceKernelSendMbx(arg->ctx->mbx, &peer->arg[1].msg);
	}
	arg->peer->alarm[1] = 0;
	return 0;
}

void func_00003580(AuthCtx *ctx, Peer *peer)
{
	if (peer == 0)
		return;
	cancelAlarm(&peer->alarm[1]);
	cancelAlarm(&peer->alarm[0]);
	cancelAlarm(&peer->alarm[2]);
	if (peer->next != 0)
		peer->next->prev = peer->prev;
	else
		ctx->last = peer->prev;
	*peer->prev = peer->next;
	ctx->npeers--;
	sceNetFreeInternal(peer);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_00003664);

Peer *func_000037C0(AuthCtx *ctx, const unsigned char *mac)
{
	Peer *p;

	for (p = ctx->first; p; p = p->next)
		if (memcmp(p->sa.mac.data, mac, 6) == 0)
			break;
	return p;
}

void func_00003818(AuthCtx *ctx, Peer *peer, int state)
{
	sceKernelWaitSema(D_00003FD4, 1, 0);
	if (peer->state != 4 && state == 4)
		func_000012C4(&peer->sa);
	if (peer->state == 4 && state != 4)
		func_000013A4(&peer->sa);
	sceKernelSignalSema(D_00003FD4, 1);
	peer->state = state;
}
