/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "netlib.h"

SceUInt func_00002D48(void *common);

int func_00002C74(SceSize args, void *argp);
/* --- end declarations --- */

char *func_000069D4(const u_char *ap)
{
	int i;
	char *cp = D_0000B098;

	for (i = 0; i < 6; i++) {
		*cp++ = D_0000A0B8[*ap >> 4];
		*cp++ = D_0000A0B8[*ap++ & 0xf];
		*cp++ = ':';
	}
	*--cp = 0;
	return D_0000B098;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if_ethersubr", func_00006A40);

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if_ethersubr", func_00006B10);

u_int func_00006BBC(const u_char *buf, u_int len)
{
	static const u_int crctab[] = {
		0x00000000, 0x1db71064, 0x3b6e20c8, 0x26d930ac,
		0x76dc4190, 0x6b6b51f4, 0x4db26158, 0x5005713c,
		0xedb88320, 0xf00f9344, 0xd6d6a3e8, 0xcb61b38c,
		0x9b64c2b0, 0x86d3d2d4, 0xa00ae278, 0xbdbdf21c
	};
	u_int crc;
	u_int i;

	crc = 0xffffffffU;
	for (i = 0; i < len; i++) {
		crc ^= buf[i];
		crc = (crc >> 4) ^ crctab[crc & 0xf];
		crc = (crc >> 4) ^ crctab[crc & 0xf];
	}
	return crc;
}

u_int func_00006C28(const u_char *buf, u_int len)
{
	u_int c, crc, carry;
	u_int i, j;

	crc = 0xffffffffU;
	for (i = 0; i < len; i++) {
		c = buf[i];
		for (j = 0; j < 8; j++) {
			carry = ((crc & 0x80000000U) ? 1 : 0) ^ (c & 0x01);
			crc <<= 1;
			c >>= 1;
			if (carry)
				crc = (crc ^ 0x04c11db6) | carry;
		}
	}
	return crc;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if_ethersubr", func_00006C90);

struct ifnet *_sce_pspnet_ifplookup_lladdr(const u_char *lla)
{
	struct ifnet *ifp;

	for (ifp = D_0000BB24.tqh_first; ifp != NULL; ifp = ifp->if_list.tqe_next) {
		if (memcmp(ifp->if_sadl->sdl_data + ifp->if_sadl->sdl_nlen, lla, 6) == 0)
			break;
	}
	return ifp;
}

int _sce_pspnet_start_of_inet_module_in_if_ethersubr_core(int (*a)(struct ifnet *, struct mbuf *, void *, void *), void *b, void *c, void *d)
{
	D_0000B07C = a;
	D_0000B080 = b;
	D_0000B084 = c;
	D_0000B088 = d;
	D_0000B090 = 1;
	return 0;
}

int _sce_pspnet_stop_of_inet_module_in_if_ethersubr_core(void)
{
	D_0000B090 = 0;
	D_0000B07C = NULL;
	D_0000B080 = NULL;
	D_0000B084 = NULL;
	D_0000B088 = NULL;
	return 0;
}

int _sce_pspnet_start_of_adhoc_module_in_if_ethersubr_core(void *a)
{
	D_0000B08C = a;
	D_0000B094 = 1;
	return 0;
}

int _sce_pspnet_stop_of_adhoc_module_in_if_ethersubr_core(void)
{
	D_0000B094 = 0;
	D_0000B08C = NULL;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/pspnet/nonmatchings/if_ethersubr", func_00006E34);

int func_000071C8(struct ifnet *ifp, struct mbuf *m, void *dst, void *rt)
{
	int ret = 0;

	if (D_0000B090 > 0)
		ret = D_0000B07C(ifp, m, dst, rt);
	return ret;
}

