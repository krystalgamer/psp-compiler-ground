#include "common.h"

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", ResetAllPositioning);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", PositioningMultMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", PositioningStoreMatrix);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", draw_dragon_with_camera_transform);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", draw_frame);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", init_all);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", pad_read);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", MainThread);

INCLUDE_RODATA("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", D_000133D0);

INCLUDE_ASM("tmp/asm/UTST99332/graphics_stainglass/nonmatchings/main", StartMainThread);

int main(void) {
    StartMainThread();
    return 0;
}
