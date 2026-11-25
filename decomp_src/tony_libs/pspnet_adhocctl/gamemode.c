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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/gamemode", func_00002F7C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/gamemode", func_0000378C);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/gamemode", func_000042A0);

int func_000046B0(int value)
{
	struct wlan_conf conf;
	int old;
	int ret;

	memset(&conf, 0, sizeof(conf));
	ret = sceNetConfig80211GetConf(D_000067B8, &conf);
	if (ret < 0)
		return ret;
	old = conf.unk11;
	conf.unk11 = value;
	ret = sceNetConfig80211SetConf(D_000067B8, &conf);
	if (ret < 0)
		return ret;
	return old;
}

void func_00004730(struct adhocctl_ctx *p, struct gm_request *gm)
{
	int unk;

	unk = 0;
	sceNetConfig80211LeaveRequest(D_000067B8, &unk);
	sceNetAdhocAuth_lib_2E6AA271();
	sceNetConfigSetIfEventFlag(D_000067B8, 0, 0);
	unk = 0;
	sceNetConfig80211LeaveRequest(D_000067B8, &unk);
	if (gm->flags & 2) {
		sceWlanDrv_lib_5BAA1FE5(0);
		if (D_00007090 >= 0)
			func_000046B0(D_00007090);
	}
	sceNetConfigDownInterface(D_000067B8);
	sceWlanDevDetach();
	p->unk24 = 0;
	p->state = 0;
}
