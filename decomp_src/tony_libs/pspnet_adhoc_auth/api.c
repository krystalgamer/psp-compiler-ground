/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "adhoc_auth.h"
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_89F2A732);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_2E6AA271);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_6CE209A3);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_2AD8C677);

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

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_1F9A90B8);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet_adhoc_auth/nonmatchings/api", sceNetAdhocAuth_lib_76F26AB0);
