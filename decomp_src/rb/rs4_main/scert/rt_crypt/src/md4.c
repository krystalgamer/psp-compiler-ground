#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", KM_MD4);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", md4Init);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", md4Update);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", md4Final);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", md4Transform);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", Encode);

void Decode(int *arg0, int arg1, unsigned int arg2) {
    int *var_a3;
    int temp_a2;
    int temp_v1;
    unsigned int var_a4;
    void *temp_v0;

    var_a4 = 0;
    if (arg2 != 0) {
        var_a3 = arg0;
        do {
            temp_v0 = arg1 + var_a4;
            temp_v1 = M2C_FIELD(temp_v0, unsigned char *, 0) | (M2C_FIELD(temp_v0, unsigned char *, 1) << 8) | (M2C_FIELD(temp_v0, unsigned char *, 2) << 0x10);
            temp_a2 = M2C_FIELD(temp_v0, unsigned char *, 3) << 0x18;
            var_a4 += 4;
            *var_a3 = temp_v1 | temp_a2;
            var_a3 += 1;
        } while (var_a4 < arg2);
    }
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", rcsid_10D96C);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/md4", md4_header_rcsid);
