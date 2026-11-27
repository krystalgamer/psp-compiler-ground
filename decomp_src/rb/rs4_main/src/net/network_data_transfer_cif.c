/* lang: c++ */
/* cflags: -Os */
#include "common.h"

extern "C" const char D_001059B4[];

struct NetDataTransferInfo {
	const char *name;
	int f4;
	int f8;
};

extern "C" NetDataTransferInfo *NetDataTransferInfo__Reset(NetDataTransferInfo *info)
{
	info->name = D_001059B4;
	info->f4 = 0;
	info->f8 = 0;
	return info;
}

extern "C" {
INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/src/net/network_data_transfer_cif", D_001059B4);
}
