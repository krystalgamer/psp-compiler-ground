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

int sceNetAdhocctlInit(SceSize stacksize, int prio, const struct SceNetAdhocctlAdhocId *adhoc_id)
{
	int ret;
	int i;

	ret = ERR_ALREADY_INITIALIZED;
	if (D_000068A0 <= 0) {
		if (stacksize == 0 || prio < 0)
			goto inval;
		if (adhoc_id == NULL)
			goto inval;
		ret = ERR_INVALID_ARG;
		if ((unsigned int)adhoc_id->type >= 3)
			goto error;
		for (i = 0; i < 9; i++) {
			if (adhoc_id->data[i] == '\0')
				goto inval;
		}
		ret = func_000017A8(stacksize, prio, adhoc_id);
		if (ret >= 0) {
			D_000068A0 = 1;
			return ret;
		}
	}
error:
	func_00001978();
	D_000068A0 = 0;
	return ret;
inval:
	ret = ERR_INVALID_ARG;
	goto error;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/adhocctl", sceNetAdhocctlCreateEnterGameMode);

int sceNetAdhocctlTerm(void)
{
	int ret;

	if (D_000068A0 == 0)
		return 0;
	ret = func_00001978();
	if (ret >= 0)
		D_000068A0 = 0;
	return ret;
}

int sceNetAdhocctlConnect(const struct SceNetAdhocctlGroupName *group_name)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		if (group_name == NULL || (ret = check_group_name(group_name)) >= 0)
			ret = func_00001C68(group_name);
	}
	return ret;
}

int sceNetAdhocctlCreate(const struct SceNetAdhocctlGroupName *group_name)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		if (group_name == NULL || (ret = check_group_name(group_name)) >= 0)
			ret = func_00001CDC(group_name);
	}
	return ret;
}

int sceNetAdhocctlJoin(const struct SceNetAdhocctlScanInfo *scan_info)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		ret = ERR_INVALID_ARG;
		if (scan_info != NULL) {
			if (&scan_info->group_name == NULL || (ret = check_group_name(&scan_info->group_name)) >= 0)
				ret = func_00001D50(scan_info);
		}
	}
	return ret;
}

int sceNetAdhocctlJoinEnterGameMode(const struct SceNetAdhocctlGroupName *group_name, const struct SceNetEtherAddr *host, int timeout, int flags)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		if (group_name == NULL || host == NULL)
			ret = ERR_INVALID_ARG;
		else if ((ret = check_group_name(group_name)) >= 0)
			ret = func_00001F78(group_name, host, D_00006718, timeout, flags);
	}
	return ret;
}

int sceNetAdhocctlScan(void)
{
	if (D_000068A0 == 0)
		return ERR_NOT_INITIALIZED;
	return func_000020C8();
}

int sceNetAdhocctlDisconnect(void)
{
	if (D_000068A0 == 0)
		return ERR_NOT_INITIALIZED;
	return func_00002128();
}

int sceNetAdhocctlExitGameMode(void)
{
	if (D_000068A0 == 0)
		return ERR_NOT_INITIALIZED;
	return func_00002184();
}

int sceNetAdhocctlAddHandler(sceNetAdhocctlHandler handler, void *arg)
{
	int ret;
	int id;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		ret = ERR_INVALID_ARG;
		if (handler != NULL) {
			ret = func_000021DC(handler, arg, &id);
			if (ret >= 0)
				ret = id;
		}
	}
	return ret;
}

int sceNetAdhocctlDelHandler(int id)
{
	if (D_000068A0 == 0)
		return ERR_NOT_INITIALIZED;
	return func_000022B0(id);
}

int sceNetAdhocctlGetState(int *state)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		ret = ERR_INVALID_ARG;
		if (state != NULL)
			ret = func_00002334(state);
	}
	return ret;
}

int sceNetAdhocctlGetAdhocId(struct SceNetAdhocctlAdhocId *adhoc_id)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		ret = ERR_INVALID_ARG;
		if (adhoc_id != NULL)
			ret = func_00002348(adhoc_id);
	}
	return ret;
}

int sceNetAdhocctlGetPeerList(int *buflen, void *buf)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		if (buflen == NULL)
			ret = ERR_INVALID_ARG;
		else if (*buflen < 0)
			ret = ERR_INVALID_ARG;
		else
			ret = sceNetAdhocAuth_lib_BD144DA6(buflen, buf);
	}
	return ret;
}

int sceNetAdhocctlGetAddrByName(const struct SceNetAdhocctlNickname *nickname, int *buflen, void *buf)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		if (nickname == NULL || buflen == NULL)
			ret = ERR_INVALID_ARG;
		else if (*buflen < 0)
			ret = ERR_INVALID_ARG;
		else
			ret = sceNetAdhocAuth_lib_1F9A90B8(nickname, buflen, buf);
	}
	return ret;
}

int sceNetAdhocctlGetNameByAddr(const struct SceNetEtherAddr *addr, struct SceNetAdhocctlNickname *nickname)
{
	if (D_000068A0 == 0)
		return ERR_NOT_INITIALIZED;
	if (addr == NULL || nickname == NULL)
		return ERR_INVALID_ARG;
	return sceNetAdhocAuth_lib_76F26AB0(addr, nickname);
}

int sceNetAdhocctlGetParameter(struct SceNetAdhocctlParameter *param)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		ret = ERR_INVALID_ARG;
		if (param != NULL)
			ret = func_00002378(param);
	}
	return ret;
}

int sceNetAdhocctlGetScanInfo(int *buflen, void *buf)
{
	if (D_000068A0 == 0)
		return ERR_NOT_INITIALIZED;
	return func_00001A38(buflen, buf);
}

int sceNetAdhocctlGetGameModeInfo(void *info)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		ret = ERR_INVALID_ARG;
		if (info != NULL)
			ret = func_00002408(info);
	}
	return ret;
}

int sceNetAdhocctl_lib_EFA6AEAF(const struct gm_param *param, int num, const struct SceNetEtherAddr *macs, int timeout, int flags)
{
	int ret;

	ret = 0;
	if (D_000068A0 == 0) {
		ret = ERR_NOT_INITIALIZED;
		goto end;
	}
	if (param == NULL) {
		ret = ERR_INVALID_ARG;
		goto end;
	}
	func_00001E04(NULL, num, macs, param, timeout, flags | 1);
end:
	return ret;
}

int sceNetAdhocctl_lib_1593C05D(const struct gm_param *param, const struct SceNetEtherAddr *host, int timeout, int flags)
{
	int ret;

	ret = 0;
	if (D_000068A0 == 0) {
		ret = ERR_NOT_INITIALIZED;
		goto end;
	}
	if (param == NULL) {
		ret = ERR_INVALID_ARG;
		goto end;
	}
	func_00001F78(NULL, host, param, timeout, flags | 1);
end:
	return ret;
}

int sceNetAdhocctl_lib_F8BABD85(sceNetAdhocctlHandler handler, void *arg)
{
	int ret;

	ret = ERR_NOT_INITIALIZED;
	if (D_000068A0 != 0) {
		ret = ERR_INVALID_ARG;
		if (handler != NULL)
			ret = func_0000247C(handler, arg);
	}
	return ret;
}

int sceNetAdhocctl_lib_1C679240(void)
{
	if (D_000068A0 == 0)
		return ERR_NOT_INITIALIZED;
	return func_00002520();
}
