/* cflags: -O2 -frename-registers -fno-strict-aliasing -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "atrac.h"
/* --- end declarations --- */

int func_00002838(AtracInfo *info)
{
	func_00002884(info);
	if ((unsigned int)(info->state - 1) >= 2)
		func_00002938(info);
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002884);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002938);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_000029E4);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002AC0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002BA0);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002C5C);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002CC8);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002D18);

INCLUDE_ASM("tmp/asm/tony_libs/libatrac3plus/nonmatchings/decode", func_00002DD0);
