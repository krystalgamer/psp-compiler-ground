#include "common.h"

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tm2", copy_pixels_EBDC);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tm2", sort_clut);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tm2", sceGimPictureCheckFileHeader);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tm2", sceGimPictureGetChunkCount);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tm2", sceGimPictureGetChunk);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tm2", sceGimPictureCountChunk);

INCLUDE_ASM("tmp/asm/umdt/graphics_model/nonmatchings/load_tm2", sceGimPictureFindChunk);
