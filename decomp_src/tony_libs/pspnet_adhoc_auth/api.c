/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

int sceNetAdhocAuth_lib_89F2A732(const char *ifname, int prio, int stack, int *params, int maxpeers, const unsigned char *key)
{
	int ret;
	int s;
	AuthCtx *ctx;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (ifname == 0 || !k1ok(ifname) || params == 0 || !k1ok(params) || key == 0 || (K1_USER() && (int)key < 0)) {
		K1_RESTORE(oldk1);
		return 0x80410687;
	}
	if (D_00003EE0 <= 0) {
		ret = 0x80410681;
		goto end;
	}
	if (D_00003EE4 != 0) {
		ret = 0x80410683;
		goto end;
	}
	auth_reset(50);
	ret = func_000038D8();
	if (ret < 0)
		goto clr;
	ctx = D_00003EE4;
	ret = 0x80410687;
	ctx->unk0 = 0;
	ctx->first = 0;
	ctx->last = &ctx->first;
	ctx->ifh = sceNetIfhandle_driver_9CBA24D4(ifname);
	if (D_00003EE4->ifh == 0)
		goto err;
	ret = sceNetIfhandle_driver_C5623112(D_00003EE4->ifh, D_00003EE4->mac.data);
	if (ret < 0)
		goto err;
	memcpy(D_00003EE4->key.data, key, 0x80);
	ctx = D_00003EE4;
	ctx->unkA8 = maxpeers;
	ctx->alarmTime = params[0];
	ctx->arg.msg.type = 3;
	ctx->unkDC = params[1];
	ctx->msg.type = 0;
	ctx->unkE0 = params[2];
	ctx->msg.peer = 0;
	ctx->unkE4 = params[3];
	ctx->arg.ctx = ctx;
	ctx->unkE8 = params[4];
	ctx->arg.peer = 0;
	ctx->arg.msg.peer = 0;
	ctx->mbx = sceKernelCreateMbx("SceNetAdhocAuth", 0, 0);
	if (D_00003EE4->mbx < 0) {
		ret = D_00003EE4->mbx;
		goto err;
	}
	D_00003EE4->thid = sceKernelCreateThread("SceNetAdhocAuth", func_000014F0, prio, stack, 0x200001, 0);
	if (D_00003EE4->thid < 0) {
		ret = D_00003EE4->thid;
		goto err_mbx;
	}
	ret = sceKernelStartThread(D_00003EE4->thid, 4, &D_00003EE4);
	if (ret < 0)
		goto err_thread;
	s = sceKernelCpuSuspendIntr();
	if (D_00003EE4->alarm > 0) {
		sceKernelCancelAlarm(D_00003EE4->alarm);
		D_00003EE4->alarm = 0;
	}
	D_00003EE4->alarm = sceKernelSetAlarm(D_00003EE4->alarmTime, func_00003424, &D_00003EE4->arg);
	sceKernelCpuResumeIntr(s);
	func_000038D0(&D_00003EE4->unk0, 1);
	K1_RESTORE(oldk1);
	return 0;
err_thread:
	sceKernelDeleteThread(D_00003EE4->thid);
err_mbx:
	sceKernelDeleteMbx(D_00003EE4->mbx);
err:
	func_0000392C();
clr:
	D_00003EE4 = 0;
end:
	K1_RESTORE(oldk1);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_2E6AA271);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_6CE209A3);

int sceNetAdhocAuth_lib_2AD8C677(void)
{
	int ret = 0;
	int s;
	Peer *p;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (D_00003EE0 <= 0) {
		ret = 0x80410681;
		goto end;
	}
	if (D_00003EE4 == 0) {
		ret = 0x80410682;
		goto end;
	}
	if (D_00003EE4->unk0 == 1)
		goto end;
	s = sceKernelCpuSuspendIntr();
	if (D_00003EE4->alarm > 0) {
		sceKernelCancelAlarm(D_00003EE4->alarm);
		D_00003EE4->alarm = 0;
	}
	D_00003EE4->alarm = sceKernelSetAlarm(D_00003EE4->alarmTime, func_00003424, &D_00003EE4->arg);
	sceKernelCpuResumeIntr(s);
	for (p = D_00003EE4->first; p; p = p->next) {
		if (p->state == 4) {
			s = sceKernelCpuSuspendIntr();
			if (p->alarm[2] > 0) {
				sceKernelCancelAlarm(p->alarm[2]);
				p->alarm[2] = 0;
			}
			p->alarm[2] = sceKernelSetAlarm(D_00003EE4->unkE8, func_000034D0, &p->arg[2]);
			sceKernelCpuResumeIntr(s);
			s = sceKernelCpuSuspendIntr();
			if (p->alarm[1] > 0) {
				sceKernelCancelAlarm(p->alarm[1]);
				p->alarm[1] = 0;
			}
			p->alarm[1] = sceKernelSetAlarm(D_00003EE4->unkE4, func_00003528, &p->arg[1]);
			sceKernelCpuResumeIntr(s);
		}
	}
	func_000038D0(&D_00003EE4->unk0, 1);
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetAdhocAuth_lib_BD144DA6(unsigned int *plen, char *buf)
{
	AuthPeerInfo *ent, *prev = 0;
	unsigned int len = 0;
	int ret = 0;
	int locked;
	Peer *p;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (plen == 0 || !k1ok(plen) || (buf != 0 && !k1ok(buf))) {
		K1_RESTORE(oldk1);
		return 0x80410687;
	}
	if (D_00003EE0 <= 0) {
		ret = 0x80410681;
		goto end;
	}
	if (D_00003EE4 == 0) {
		ret = 0x80410682;
		goto end;
	}
	locked = func_00003968();
	for (p = D_00003EE4->first; p; p = p->next) {
		if (p->state != 4)
			continue;
		if (buf) {
			if (*plen < len + sizeof(AuthPeerInfo))
				break;
			ent = (AuthPeerInfo *)(buf + len);
			ent->next = 0;
			ent->mac = p->sa.mac;
			ent->key = p->key;
			if (prev)
				prev->next = ent;
			prev = ent;
		}
		len += sizeof(AuthPeerInfo);
	}
	func_000039C4(locked);
	*plen = len;
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetAdhocAuth_lib_1F9A90B8(const unsigned char *key, unsigned int *plen, char *buf)
{
	int locked;
	AuthPeerInfo *ent, *prev = 0;
	unsigned int len = 0;
	int ret = 0;
	int found = 0;
	Peer *p;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (key == 0 || !k1ok(key) || plen == 0 || !k1ok(plen) || (buf != 0 && !k1ok(buf))) {
		K1_RESTORE(oldk1);
		return 0x80410687;
	}
	if (D_00003EE0 <= 0) {
		ret = 0x80410681;
		goto end;
	}
	if (D_00003EE4 == 0) {
		ret = 0x80410682;
		goto end;
	}
	locked = func_00003968();
	for (p = D_00003EE4->first; p; p = p->next) {
		if (p->state != 4)
			continue;
		if (memcmp(p->key.data, key, 0x80) != 0)
			continue;
		found++;
		if (buf) {
			if (*plen < len + sizeof(AuthPeerInfo))
				break;
			ent = (AuthPeerInfo *)(buf + len);
			ent->next = 0;
			ent->mac = p->sa.mac;
			ent->key = p->key;
			if (prev)
				prev->next = ent;
			prev = ent;
		}
		len += sizeof(AuthPeerInfo);
	}
	func_000039C4(locked);
	*plen = len;
	if (found == 0)
		ret = 0x80410716;
end:
	K1_RESTORE(oldk1);
	return ret;
}

int sceNetAdhocAuth_lib_76F26AB0(const unsigned char *mac, unsigned char *key)
{
	int ret = 0;
	int locked;
	Peer *p;
	unsigned int oldk1;

	K1_SAVE(oldk1);
	if (mac == 0 || !k1ok(mac) || key == 0 || !k1ok(key)) {
		K1_RESTORE(oldk1);
		return 0x80410687;
	}
	if (D_00003EE0 <= 0) {
		ret = 0x80410681;
		goto end;
	}
	if (D_00003EE4 == 0) {
		ret = 0x80410682;
		goto end;
	}
	locked = func_00003968();
	for (p = D_00003EE4->first; p; p = p->next)
		if (p->state == 4 && memcmp(p->sa.mac.data, mac, 6) == 0)
			break;
	func_000039C4(locked);
	if (p == 0)
		ret = 0x80410716;
	else
		memcpy(key, p->key.data, 0x80);
end:
	K1_RESTORE(oldk1);
	return ret;
}
