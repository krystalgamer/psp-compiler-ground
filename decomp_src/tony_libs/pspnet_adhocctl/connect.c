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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/connect", func_000008C0);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/connect", func_00000B40);

int func_00000D58(struct adhocctl_ctx *p)
{
	struct scan_req req;
	struct scan_entry buf;
	int size;
	int unk;
	int ret;
	int r;
	int i;

	ret = sceWlanGetSwitchState();
	if (ret == 0)
		return 0x80410B03;
	memset(&req, 0, sizeof(req));
	memset(&buf, 0, sizeof(buf));
	req.type = 2;
	req.channels[0] = 1;
	for (i = 1; i < 14; i++)
		req.channels[i] = 0;
	req.unk3C = 1;
	req.unk44 = 6;
	req.unk48 = 100;
	size = sizeof(buf);
	req.unk40 = 0;
	unk = 0;
	ret = sceNetConfig80211ScanRequest(D_000066E8, &req, &size, &buf, &unk);
	r = func_00002D84(p);
	if (ERROR_FACILITY(r) == 0x41)
		return r;
	return ret < 0 ? ret : 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/connect", func_00000E50);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/connect", func_00001154);

void func_000014B4(struct adhocctl_ctx *p)
{
	int unk;

	sceNetAdhocAuth_lib_2E6AA271();
	sceNetConfigSetIfEventFlag(D_000066E8, 0, 0);
	unk = 0;
	sceNetConfig80211LeaveRequest(D_000066E8, &unk);
	sceNetConfigDownInterface(D_000066E8);
	sceWlanDevDetach();
	p->unk24 = 0;
	p->state = 0;
}

int func_00001520(struct adhocctl_ctx *p, char *ssid, int *channel)
{
	int ch;
	int ret;

	memset(ssid, 0, 33);
	ret = sceUtilityGetSystemParamInt(2, &ch);
	if (ret < 0)
		return ret;
	if (ch == 11 || ch == 6)
		*channel = ch;
	else if (ch == 1)
		*channel = ch;
	else
		*channel = 11;
	if (*channel < 1 || *channel > 14)
		return 0x80410B81;
	return func_00001634(p, ssid, 'L', p->group_name.data);
}

int func_000015E4(struct adhocctl_ctx *p, char *ssid)
{
	memset(ssid, 0, 33);
	return func_00001634(p, ssid, 'G', p->group_name.data);
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/connect", func_00001634);
