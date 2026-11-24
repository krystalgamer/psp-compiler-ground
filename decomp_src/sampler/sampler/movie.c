#include "common.h"

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", pad_read);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", thumb_load);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", ringbufferCallBack);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", startCheck);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", playMovie);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", readHeader);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", skip_data);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", init_pinfo);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieInit);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieMain);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieTerm);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieStat);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieStart);

INCLUDE_ASM("tmp/asm/sampler/sampler/nonmatchings/movie", MovieEnd);
