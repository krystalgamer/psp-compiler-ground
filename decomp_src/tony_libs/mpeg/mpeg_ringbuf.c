/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_ringbuf", sceMpegRingbufferPut);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_ringbuf", func_00003A88);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_ringbuf", sceMpegRingbufferAvailableSize);

int sceMpegRingbufferQueryMemSize(int packNum)
{
	return (packNum << 11) + packNum * 0x68;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_ringbuf", sceMpegRingbufferConstruct);

int sceMpegRingbufferDestruct(SceMpegRingbuffer *rb)
{
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_ringbuf", func_00003E28);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_ringbuf", func_00003E90);

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_ringbuf", func_00003F4C);
