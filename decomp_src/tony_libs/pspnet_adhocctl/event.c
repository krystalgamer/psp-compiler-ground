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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/event", func_00002C84);

int func_00002D64(struct adhocctl_ctx *p)
{
	int event;
	int data;

	return func_00002E0C(p, &event, &data);
}

int func_00002D84(struct adhocctl_ctx *p)
{
	unsigned int bits;
	int event;
	int data;
	int ret;

	ret = sceKernelPollEventFlag(p->evf, 0x8, 1, &bits);
	if (ret == 0x800201AF)
		return 0;
	if (ret < 0)
		return ret;
	if (bits & 0x8) {
		sceKernelClearEventFlag(p->evf, ~0x8);
		ret = func_00002E0C(p, &event, &data);
	}
	return ret;
}

int func_00002E0C(struct adhocctl_ctx *p, int *event, int *data)
{
	int ret;

	ret = 0;
	for (;;) {
		int r = sceNetConfigGetIfEvent(D_0000670C, event, data);
		if (r == 0x80410184)
			break;
		if (r < 0) {
			ret = r;
			goto out;
		}
		switch (*event) {
		case 4:
			if (p->state == 1)
				p->unk24 = 0x80410B83;
			ret = 0x80410B03;
			break;
		case 5:
			if (p->unk18 == 0) {
				ret = 0x80410B0E;
				p->unk18 = 1;
			}
			break;
		case 7:
			if (p->state == 1)
				p->unk24 = 0x80410B84;
			func_00002590(5, 0);
			ret = func_00002C84(p);
			if (ret < 0)
				goto out;
			ret = 0x80410B0F;
			break;
		}
	}
	if (sceKernelPollEventFlag(p->evf, 0x42, 1, NULL) == 0)
		ret = 0;
out:
	return ret;
}
