#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_string", rt_string_strncpy);

int rt_strlen(signed char *arg0) {
    int var_v0;
    signed char *var_v1;

    var_v0 = 0;
    if (arg0 != NULL) {
        var_v1 = arg0;
        if (*arg0 != 0) {
            do {
                var_v1 += 1;
            } while (*var_v1 != 0);
        }
        var_v0 = var_v1 - arg0;
    }
    return var_v0;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_string", rt_strnlen);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_string", rcsid_10EEF8);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_string", rt_string_header_rcsid);
