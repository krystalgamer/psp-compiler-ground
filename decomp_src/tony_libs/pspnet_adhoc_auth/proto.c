/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/proto", func_00002224);

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
		if (memcmp(p->sa.mac, mac, 6) == 0)
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
