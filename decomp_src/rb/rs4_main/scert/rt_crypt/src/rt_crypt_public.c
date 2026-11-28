#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int IsNullRSAKey(int *arg0);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt_public", KM_Initialize);

int IsNullRSAKey(int *arg0) {
    int *var_a0;
    int temp_v0;
    int var_a2;
    unsigned int var_a1;

    var_a0 = arg0;
    var_a2 = 1;
    if (var_a0 != NULL) {
        var_a1 = 0;
loop_2:
        temp_v0 = *var_a0;
        var_a1 += 1;
        var_a0 += 1;
        var_a2 = 0;
        if (temp_v0 == 0) {
            if (var_a1 >= 0x10U) {
                var_a2 = 1;
            } else {
                goto loop_2;
            }
        }
    }
    return var_a2;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt_public", KM_GetLocalPublicKey);

extern char **gCryptGlobals;
void *GetKeyMaster(int id)
{
    char *k = *gCryptGlobals;

    while (k != NULL) {
        if (*(int *)(k + 0x10) == id) break;
        k = *(char **)(k + 4);
        if (k == *gCryptGlobals) k = NULL;
    }
    return k;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_crypt/src/rt_crypt_public", rcsid_10E888);
