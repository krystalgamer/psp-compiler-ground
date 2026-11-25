#include "common.h"
#include "m2c_macros.h"



int sceGimPictureCheckFileHeader(void *arg0, int arg1) {
    int var_a2;

    var_a2 = 0;
    if ((arg0 != NULL) && ((unsigned int) (arg1 - 1) >= 0x1FU) && (M2C_FIELD(arg0, int *, 0) == 0x2E47494D)) {
        if (M2C_FIELD(arg0, int *, 4) == 0x312E3030) {
            var_a2 = M2C_FIELD(arg0, int *, 8) == 0x505350;
        }
    }
    return var_a2;
}

int sceGimPictureGetChunkCount(void *buf, int size) {
    int var_v1;

    var_v1 = 0;
    if (buf != NULL) {
        var_v1 = sceGimPictureCountChunk(buf + 0x10, 3);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_format", sceGimPictureGetChunk);

int sceGimPictureCountChunk(void *arg0, int arg1) {
    int var_a2;
    void *temp_a3;
    void *var_a0;

    temp_a3 = arg0 + M2C_FIELD(arg0, int *, 4);
    var_a0 = arg0 + M2C_FIELD(arg0, int *, 8);
    var_a2 = 0;
    if ((unsigned int) var_a0 < (unsigned int) temp_a3) {
        do {
            if ((arg1 == 0) || (M2C_FIELD(var_a0, unsigned short *, 0) == arg1)) {
                var_a2 += 1;
            }
            var_a0 += M2C_FIELD(var_a0, int *, 4);
        } while ((unsigned int) var_a0 < (unsigned int) temp_a3);
    }
    return var_a2;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_format", sceGimPictureFindChunk);
