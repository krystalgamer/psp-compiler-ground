#include "common.h"
#include "rb/rs4_main/scert/scert.h"

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_allocate);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_reallocate);

void *memset(void *s, int c, unsigned int n);
int rt_memory_allocate_init_zero(void **arg0, unsigned int arg1) {
    int temp_v0;
    int var_v1;
    void *temp_v0_2;

    var_v1 = 0x64;
    if (arg0 != NULL) {
        *arg0 = NULL;
        temp_v0 = rt_memory_allocate();
        var_v1 = temp_v0;
        if (temp_v0 == 0) {
            temp_v0_2 = *arg0;
            var_v1 = 0x64;
            if (temp_v0_2 != NULL) {
                memset(temp_v0_2, 0, arg1);
                var_v1 = 0;
            }
        }
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_free);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_align_alloc);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_align_alloc_init_zero);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rt_memory_align_free);

int rt_memory_register_callbacks(int arg0, int arg1) {
    gpfMallocCallback = arg0;
    gpfFreeCallback = arg1;
    return 0;
}

int rt_memory_register_another_callback(int arg0) {
    gpfReallocCallback = arg0;
    return 0;
}

int rt_memory_get_aligned_address(unsigned int *arg0, unsigned int arg1, int arg2) {
    int var_a3;
    unsigned int temp_hi;
    unsigned int temp_v1;

    temp_v1 = arg2 & 0xFFFF;
    var_a3 = 0x64;
    if (((arg0 == NULL) | (arg1 == 0)) == 0) {
        *arg0 = arg1;
        var_a3 = 0;
        if (temp_v1 >= 2U) {
            temp_hi = arg1 % temp_v1;
            if (temp_hi != 0) {
                *arg0 = arg1 + (temp_v1 - temp_hi);
            }
        }
    }
    return var_a3;
}

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", rcsid_10E994);

INCLUDE_RODATA("tmp/asm/rb/rs4_main/nonmatchings/scert/rt_util/rt_memory", header_rcsid_10E9F0);
