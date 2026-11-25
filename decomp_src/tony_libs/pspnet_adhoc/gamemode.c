/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc.h"
/* --- end declarations --- */

int sceNetAdhocGameModeCreateMaster(void *ptr, unsigned int size)
{
	struct SceNetEtherAddr mac;
	int s;
	int ret;

	if (ptr == NULL)
		return 0x80410711;
	ret = 0x80410712;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0)
		goto out;
	ret = 0x8041071B;
	if (!sceWlanDevIsGameMode())
		goto out;
	if ((ret = sceNetGetLocalEtherAddr(&mac)) < 0)
		goto out;
	if ((ret = func_00006AB8(&mac, ptr, size)) < 0)
		goto out;
	D_000073F0 = ret;
	ret = 0;
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int sceNetAdhocGameModeUpdateMaster(void)
{
	struct gamemode *g;
	int s;
	int ret;

	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	ret = 0x8041071B;
	if (!sceWlanDevIsGameMode())
		goto out;
	ret = 0x8041071C;
	if (D_000073F0 < 0)
		goto out;
	for (g = D_00007440.tqh_first; g != NULL; g = g->link.tqe_next) {
		if (g->id == D_000073F0)
			break;
	}
	if (g == NULL) {
		ret = 0x8041071C;
		goto out;
	}
	ret = sceWlanGPSend(0x10, g->ptr, g->size);
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int func_00006880(void)
{
	TAILQ_INIT(&D_00007440);
	return 0;
}

void func_00006898(void)
{
	struct gamemode *g;

	while ((g = D_00007440.tqh_first) != NULL) {
		TAILQ_REMOVE(&D_00007440, g, link);
		sceNetFreeInternal(g);
	}
}

int sceNetAdhocGameModeCreateReplica(struct SceNetEtherAddr *mac, void *ptr, unsigned int size)
{
	int s;
	int ret;

	if (mac == NULL || ptr == NULL)
		return 0x80410711;
	ret = 0x80410712;
	s = _sce_pspnet_spllock();
	if (D_00007400 == 0)
		goto out;
	ret = 0x8041071B;
	if (!sceWlanDevIsGameMode())
		goto out;
	ret = func_00006AB8(mac, ptr, size);
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int sceNetAdhocGameModeUpdateReplica(int id, struct gpinfo *info)
{
	return func_00006C3C(id, info, 0);
}

int sceNetAdhoc_lib_AF6DFB15(int id, struct gpinfo *info)
{
	return func_00006C3C(id, info, 1);
}

int sceNetAdhocGameModeDeleteMaster(void)
{
	int s;
	int ret;

	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	ret = 0x8041071C;
	if (D_000073F0 < 0)
		goto out;
	ret = func_00006BB8(D_000073F0);
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

int sceNetAdhocGameModeDeleteReplica(int id)
{
	int s;
	int ret;

	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	ret = func_00006BB8(id);
out:
	_sce_pspnet_splunlock(s);
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc/nonmatchings/gamemode", func_00006AB8);

int func_00006BB8(int id)
{
	struct gamemode *g;

	for (g = D_00007440.tqh_first; g != NULL; g = g->link.tqe_next) {
		if (g->id == id)
			break;
	}
	if (g == NULL)
		return 0x8041071C;
	TAILQ_REMOVE(&D_00007440, g, link);
	sceNetFreeInternal(g);
	return 0;
}

int func_00006C3C(int id, struct gpinfo *info, int flag)
{
	struct gamemode *g;
	struct gpinfo tmp;
	struct gpinfo *p;
	int s;
	int ret;

	p = NULL;
	s = _sce_pspnet_spllock();
	ret = 0x80410712;
	if (D_00007400 == 0)
		goto out;
	ret = 0x8041071B;
	if (!sceWlanDevIsGameMode())
		goto out;
	for (g = D_00007440.tqh_first; g != NULL; g = g->link.tqe_next) {
		if (g->id == id)
			break;
	}
	if (g == NULL) {
		ret = 0x8041071C;
		goto out;
	}
	if (info != NULL) {
		tmp.size = 8;
		p = &tmp;
	}
	ret = sceWlanGPRecv(id, g->ptr, g->size, p);
	if (info != NULL) {
		if (info->size >= 8)
			info->val = p->val;
		if (flag == 0)
			info->val = (u_short)info->val;
	}
out:
	_sce_pspnet_splunlock(s);
	return ret;
}
