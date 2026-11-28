#include "common.h"
#include "m2c_macros.h"
#ifndef NULL
#define NULL ((void *)0)
#endif
int IsNullRSAKey(int *arg0);

void *memcpy(void *, const void *, unsigned long); void *memset(void *, int, unsigned int);
extern char **gCryptGlobals;
void KM_Initialize(int id, void *key)
{
    if (id == -1) {
        if (key != NULL) memcpy((char *)gCryptGlobals + 0x104, key, 0x80);
        else memset((char *)gCryptGlobals + 0x104, 0, 0x80);
    } else if (id == 0x80000000) {
        if (key != NULL) memcpy((char *)gCryptGlobals + 4, key, 0x80);
        else memset((char *)gCryptGlobals + 4, 0, 0x80);
    } else {
        if (key != NULL) memcpy((char *)gCryptGlobals + 0x84, key, 0x80);
        else memset((char *)gCryptGlobals + 0x84, 0, 0x80);
    }
}

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

void *memcpy(void *, const void *, unsigned long); void *memset(void *, int, unsigned int);
extern char **gCryptGlobals;
int KM_GetLocalPublicKey(int id, void *out)
{
    int ret;

    if (id == 0x80000000) {
        ret = -3;
        if (!IsNullRSAKey((int *)((char *)gCryptGlobals + 4))) ret = 0;
        if (out != NULL) memcpy(out, (char *)gCryptGlobals + 4, 0x40);
    } else if (id == -1) {
        ret = -3;
        if (!IsNullRSAKey((int *)((char *)gCryptGlobals + 0x104))) ret = 0;
        if (out != NULL) memcpy(out, (char *)gCryptGlobals + 0x104, 0x40);
    } else {
        ret = -3;
        if (!IsNullRSAKey((int *)((char *)gCryptGlobals + 0x84))) ret = 0;
        if (out != NULL) memcpy(out, (char *)gCryptGlobals + 0x84, 0x40);
    }
    if (out != NULL && ret != 0) memset(out, 0, 0x40);
    return ret;
}

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
