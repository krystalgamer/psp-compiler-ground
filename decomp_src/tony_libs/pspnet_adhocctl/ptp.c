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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/ptp", func_000047FC);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhocctl/nonmatchings/ptp", func_00004BB4);

unsigned char *func_00004CC4(int type, unsigned char *buf, int len, int *outlen)
{
	unsigned char *end;
	unsigned short l;
	int t;
	unsigned char tp = type;

	end = buf + len;
	while (buf < end) {
		t = *buf++;
		if ((unsigned int)(end - buf) < 2)
			return NULL;
		memcpy(&l, buf, 2);
		buf += 2;
		l = ntohs16(l);
		if (end - buf < l)
			return NULL;
		if (t == tp) {
			*outlen = l;
			return buf;
		}
		buf += l;
	}
	return NULL;
}
