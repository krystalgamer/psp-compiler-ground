#include "common.h"

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_create);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_init);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_end);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_decode_sleep);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_isEnd);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_isFull);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_setDemuxEnd);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_getCapacity);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/fileread", read_func);
