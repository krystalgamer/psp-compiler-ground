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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_00002458);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_000026F8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_00002C44);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_00002EE0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_00003188);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_00003330);

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
