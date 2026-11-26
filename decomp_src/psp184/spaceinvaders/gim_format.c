#include "common.h"

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_format", sceGimPictureCheckFileHeader);

int sceGimPictureGetChunkCount(void *buf, int size) {
    int var_v1;

    var_v1 = 0;
    if (buf != NULL) {
        var_v1 = sceGimPictureCountChunk(buf + 0x10, 3);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gim_format", sceGimPictureGetChunk);
