#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x10 */
    short unsigned int type;
    short unsigned int unused;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef struct _anon1 SceGimChunk;



_Bool sceGimPictureCheckFileHeader(const void *buf, int size);
int sceGimPictureGetChunkCount(const void *buf, int size);
const SceGimChunk *sceGimPictureGetChunk(const void *buf, int size, int idx);


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_format", sceGimPictureCheckFileHeader);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_format", sceGimPictureGetChunkCount);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_format", sceGimPictureGetChunk);
