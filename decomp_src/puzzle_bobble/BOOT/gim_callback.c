#include "common.h"
#include "m2c_macros.h"

extern unsigned char free;
extern M2C_UNK *g_alloc_memory;
extern M2C_UNK *g_alloc_memory2;
extern M2C_UNK *g_free_memory;
extern M2C_UNK *g_free_memory2;
extern unsigned char malloc;


INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_callback", sceGimPictureSetMemoryManager);

void sceGimPictureSetMemoryManager2(M2C_UNK *arg0, M2C_UNK *arg1) {
    M2C_UNK *var_a0;
    M2C_UNK *var_a1;

    var_a0 = arg0;
    var_a1 = arg1;
    if (var_a0 == NULL) {
        var_a0 = &malloc;
    }
    if (var_a1 == NULL) {
        var_a1 = &free;
    }
    g_alloc_memory2 = var_a0;
    g_free_memory2 = var_a1;
}

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_callback", sceGimPictureAllocMemory);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_callback", sceGimPictureAllocMemory2);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_callback", sceGimPictureFreeMemory);

INCLUDE_ASM("tmp/asm/puzzle_bobble/BOOT/nonmatchings/gim_callback", sceGimPictureFreeMemory2);
