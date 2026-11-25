#include "common.h"

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", count_array);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", find_array);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", get_file_pointer);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", load_file);

INCLUDE_RODATA("tmp/asm/flowars/flowars/nonmatchings/utils", D_0002F57C);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", load_image);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", delete_image);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", compact_array);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", quick_sort);

void *memalign(unsigned int align, unsigned int size);
void *malloc16(unsigned int size) {
    return memalign(0x10, size);
}

void free(void *p);
void free16(void *addr) {
    free(addr);
}

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", shuffle);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", ttyprintf2);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", make_num_format);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", activateUmd);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", evaluated_rand);

INCLUDE_ASM("tmp/asm/flowars/flowars/nonmatchings/utils", get_tick);

void print_nothing(void) {
}

void check_callback(void) {
}
