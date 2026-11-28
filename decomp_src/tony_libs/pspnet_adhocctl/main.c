/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhocctl.h"

static inline int check_group_name(const struct SceNetAdhocctlGroupName *group_name)
{
	int i;

	for (i = 0; i < 8; i++) {
		if (group_name->data[i] == '\0')
			break;
		if (!isalnum(group_name->data[i]))
			return ERR_INVALID_ARG;
	}
	return i;
}
/* --- end declarations --- */

int func_000017A8(SceSize stacksize, int prio, const struct SceNetAdhocctlAdhocId *adhoc_id)
{
	struct adhocctl_ctx *p;
	int ret;

	p = &D_000068A4;
	memset(p, 0, sizeof(*p));
	memset(D_00007048, 0, sizeof(D_00007048));
	p->state = 0;
	p->unk24 = 0;
	D_00007060.func = NULL;
	ret = sceNetAdhocAuthInit();
	if (ret < 0)
		return ret;
	memcpy(&p->adhoc_id, adhoc_id, sizeof(p->adhoc_id));
	p->sema = sceKernelCreateSema(D_000066F4, 0, 1, 1, NULL);
	if (p->sema < 0) {
		ret = p->sema;
		goto err_sema;
	}
	p->evf = sceKernelCreateEventFlag(D_000066F4, 0, 0, NULL);
	if (p->evf < 0) {
		ret = p->evf;
		goto err_evf;
	}
	p->thid = sceKernelCreateThread(D_000066F4, func_00002614, prio, stacksize, 0, NULL);
	if (p->thid < 0) {
		ret = p->thid;
		goto err_thread;
	}
	ret = sceKernelStartThread(p->thid, sizeof(p), &p);
	if (ret < 0)
		goto err_start;
	p->unk20 = 5;
	p->busy = 0;
	p->unk18 = 0;
	return ret;

err_start:
	sceKernelTerminateThread(p->thid);
	sceKernelDeleteThread(p->thid);
err_thread:
	sceKernelDeleteEventFlag(p->evf);
err_evf:
	sceKernelDeleteSema(p->sema);
err_sema:
	sceNetAdhocAuthTerm();
	return ret;
}

int func_00001978(void)
{
	struct adhocctl_ctx *p = &D_000068A4;
	int ret;

	ret = 0;
	if (p->state != 0 || p->busy > 0) {
		ret = ERR_ALREADY_CONNECTED;
		goto end;
	}
	if (p->thid >= 0) {
		sceKernelTerminateThread(p->thid);
		sceKernelDeleteThread(p->thid);
		p->thid = -1;
	}
	if (p->evf >= 0) {
		sceKernelDeleteEventFlag(p->evf);
		p->evf = -1;
	}
	if (p->sema >= 0) {
		sceKernelDeleteSema(p->sema);
		p->sema = -1;
	}
	sceNetAdhocAuthTerm();
end:
	return ret;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/main", func_00001A38);

int func_00001C68(const struct SceNetAdhocctlGroupName *group_name)
{
	struct adhocctl_ctx *p = &D_000068A4;

	if (p->busy != 0)
		return ERR_BUSY;
	p->busy = 1;
	memset(&p->group_name, 0, sizeof(p->group_name));
	if (group_name != NULL)
		strncpy(p->group_name.data, group_name->data, sizeof(p->group_name));
	sceKernelSetEventFlag(p->evf, 0x1);
	return 0;
}

int func_00001CDC(const struct SceNetAdhocctlGroupName *group_name)
{
	struct adhocctl_ctx *p = &D_000068A4;

	if (p->busy != 0)
		return ERR_BUSY;
	p->busy = 1;
	memset(&p->group_name, 0, sizeof(p->group_name));
	if (group_name != NULL)
		strncpy(p->group_name.data, group_name->data, sizeof(p->group_name));
	sceKernelSetEventFlag(p->evf, 0x80);
	return 0;
}

int func_00001D50(const struct SceNetAdhocctlScanInfo *scan_info)
{
	struct adhocctl_ctx *p = &D_000068A4;

	if (p->busy != 0)
		return ERR_BUSY;
	p->busy = 1;
	if (scan_info == NULL)
		return ERR_INVALID_ARG;
	p->join_info = *scan_info;
	memset(&p->group_name, 0, sizeof(p->group_name));
	if (&scan_info->group_name != NULL)
		strncpy(p->group_name.data, scan_info->group_name.data, sizeof(p->group_name));
	sceKernelSetEventFlag(p->evf, 0x100);
	return 0;
}

int func_00001E04(const struct SceNetAdhocctlGroupName *group_name, int num, const struct SceNetEtherAddr *macs, const struct gm_param *param, int timeout, int flags)
{
	struct adhocctl_ctx *p = &D_000068A4;
	struct gm_request *gm = &D_00006F8C;
	int ret;

	if (p->busy != 0)
		return ERR_BUSY;
	p->busy = 1;
	if (group_name != NULL)
		p->group_name = *group_name;
	else
		memset(&p->group_name, 0, sizeof(p->group_name));
	gm->num = num;
	memcpy(gm->macs, macs, num * sizeof(struct SceNetEtherAddr));
	gm->param = *param;
	gm->timeout = timeout;
	gm->flags = flags;
	sceKernelSetEventFlag(p->evf, 0x10);
	ret = 0;
	return ret;
}

int func_00001F78(const struct SceNetAdhocctlGroupName *group_name, const struct SceNetEtherAddr *host, const struct gm_param *param, int timeout, int flags)
{
	struct adhocctl_ctx *p = &D_000068A4;
	struct gm_request *gm = &D_00006F8C;
	int ret;

	ret = ERR_BUSY;
	if (p->busy != 0)
		goto end;
	p->busy = 1;
	if (group_name != NULL)
		p->group_name = *group_name;
	else
		memset(&p->group_name, 0, sizeof(p->group_name));
	gm->num = 0;
	gm->macs[0] = *host;
	gm->param = *param;
	gm->timeout = timeout;
	gm->flags = flags;
	sceKernelSetEventFlag(p->evf, 0x20);
	ret = 0;
end:
	return ret;
}

int func_000020C8(void)
{
	struct adhocctl_ctx *p = &D_000068A4;

	if (p->busy != 0)
		return ERR_BUSY;
	p->busy = 1;
	memset(p->scan, 0, sizeof(p->scan));
	sceKernelSetEventFlag(p->evf, 0x4);
	return 0;
}

int func_00002128(void)
{
	struct adhocctl_ctx *p = &D_000068A4;

	if (p->state == 3)
		return 0x80410B0B;
	if (p->busy != 0)
		return ERR_BUSY;
	p->busy = 1;
	sceKernelSetEventFlag(p->evf, 0x2);
	return 0;
}

int func_00002184(void)
{
	struct adhocctl_ctx *p = &D_000068A4;

	if (p->state == 1)
		return 0x80410B0B;
	if (p->busy != 0)
		return ERR_BUSY;
	p->busy = 1;
	sceKernelSetEventFlag(p->evf, 0x40);
	return 0;
}

int func_000021DC(sceNetAdhocctlHandler handler, void *arg, int *id)
{
	struct adhocctl_ctx *p = &D_000068A4;
	int ret;
	int i;

	ret = 0;
	sceKernelWaitSema(p->sema, 1, NULL);
	for (i = 0; i < 2; i++) {
		if (D_00007048[i].func == NULL)
			break;
	}
	if (i == 2) {
		ret = ERR_HANDLER_MAX;
		goto end;
	}
	D_00007048[i].func = handler;
	D_00007048[i].arg = arg;
	D_00007048[i].id = i;
	*id = i;
end:
	sceKernelSignalSema(p->sema, 1);
	return ret;
}

int func_000022B0(int id)
{
	struct adhocctl_ctx *p = &D_000068A4;
	int ret;

	ret = 0;
	sceKernelWaitSema(p->sema, 1, NULL);
	if (D_00007048[id].func != NULL)
		D_00007048[id].func = NULL;
	else
		ret = ERR_ID_NOT_FOUND;
	sceKernelSignalSema(p->sema, 1);
	return ret;
}

int func_00002334(int *state)
{
	struct adhocctl_ctx *p = &D_000068A4;

	*state = p->state;
	return 0;
}

int func_00002348(struct SceNetAdhocctlAdhocId *adhoc_id)
{
	struct adhocctl_ctx *p = &D_000068A4;

	*adhoc_id = p->adhoc_id;
	return 0;
}

int func_00002378(struct SceNetAdhocctlParameter *param)
{
	struct adhocctl_ctx *p = &D_000068A4;
	struct bss_desc desc;
	int ret;

	ret = ERR_DISCONNECTED;
	if (p->state == 0)
		goto end;
	ret = sceNetConfig80211GetBssDesc(D_00006704, &desc);
	if (ret < 0)
		goto end;
	param->bssid = desc.bssid;
	param->channel = p->channel;
	param->group_name = p->group_name;
	ret = sceUtilityGetSystemParamString(1, param->nickname.data, sizeof(param->nickname));
end:
	return ret;
}

int func_00002408(struct gm_info *info)
{
	int ret;
	struct gm_request *gm = &D_00006F8C;

	ret = 0;
	if (D_000068A4.state != 3) {
		ret = ERR_NOT_ENTER_GAMEMODE;
	} else {
		info->num = gm->num;
		memcpy(info->macs, gm->macs, gm->num * sizeof(struct SceNetEtherAddr));
	}
	return ret;
}

int func_0000247C(sceNetAdhocctlHandler handler, void *arg)
{
	struct adhocctl_ctx *p = &D_000068A4;
	int ret;

	ret = 0;
	sceKernelWaitSema(p->sema, 1, NULL);
	if (p->unk24 != 0) {
		ret = p->unk24;
		goto end;
	}
	if (D_00007060.func != NULL) {
		ret = ERR_HANDLER_MAX;
		goto end;
	}
	D_00007060.func = handler;
	D_00007060.arg = arg;
	D_00007060.id = -1;
end:
	sceKernelSignalSema(p->sema, 1);
	return ret;
}

int func_00002520(void)
{
	struct adhocctl_ctx *p = &D_000068A4;
	int ret;

	ret = 0;
	sceKernelWaitSema(p->sema, 1, NULL);
	if (D_00007060.func != NULL)
		D_00007060.func = NULL;
	else
		ret = ERR_ID_NOT_FOUND;
	sceKernelSignalSema(p->sema, 1);
	return ret;
}

int func_00002590(int event, int error)
{
	struct adhocctl_ctx *p = &D_000068A4;

	sceKernelWaitSema(p->sema, 1, NULL);
	if (D_00007060.func != NULL)
		D_00007060.func(event, error, D_00007060.arg);
	sceKernelSignalSema(p->sema, 1);
	return 0;
}

int func_00002614(SceSize args, void *argp)
{
	struct gm_request *gm = &D_00006F8C;
	struct adhocctl_ctx *p = *(struct adhocctl_ctx **)argp;
	unsigned int bits;
	int ret;
	int r;

	for (;;) {
		bits = 0;
		sceKernelWaitEventFlag(p->evf, 0x1FF, 1, &bits, NULL);
		if (bits & 0x8) {
			sceKernelClearEventFlag(p->evf, ~0x8);
			if (p->state == 1 || p->state == 3) {
				ret = func_00002D64(p);
				if (ret < 0)
					goto notify_error;
			}
		}
		if (bits & 0x1) {
			sceKernelClearEventFlag(p->evf, ~0x1);
			ret = func_000008C0(p);
			if (ret < 0)
				goto error;
			notify(1, 0);
		}
		if (bits & 0x2) {
			sceKernelClearEventFlag(p->evf, ~0x2);
			func_000014B4(p);
			notify(2, 0);
		}
		if (bits & 0x4) {
			sceKernelClearEventFlag(p->evf, ~0x4);
			ret = func_00000B40(p);
			if (ret < 0)
				goto error;
			notify(3, 0);
		}
		if (bits & 0x10) {
			sceKernelClearEventFlag(p->evf, ~0x10);
			ret = func_00002F7C(p, gm);
			if (ret < 0)
				goto error;
			notify(4, 0);
		}
		if (bits & 0x20) {
			sceKernelClearEventFlag(p->evf, ~0x20);
			ret = func_0000378C(p, gm);
			if (ret < 0)
				goto error;
			notify(4, 0);
		}
		if (bits & 0x40) {
			sceKernelClearEventFlag(p->evf, ~0x40);
			func_00004730(p, gm);
			notify(2, 0);
		}
		if (bits & 0x80) {
			sceKernelClearEventFlag(p->evf, ~0x80);
			ret = func_00000E50(p);
			if (ret < 0)
				goto error;
			notify(1, 0);
		}
		if (bits & 0x100) {
			sceKernelClearEventFlag(p->evf, ~0x100);
			ret = func_00001154(p);
			if (ret < 0)
				goto error;
			notify(1, 0);
		}
		p->busy = 0;
		continue;

error:
		r = func_00002D84(p);
		if (r < 0)
			ret = r;
notify_error:
		p->busy = 0;
		notify(0, ret);
	}
	return 0;
}
