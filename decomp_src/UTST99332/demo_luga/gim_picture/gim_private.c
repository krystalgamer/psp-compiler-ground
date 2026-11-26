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



const SceGimChunk *sceGimPictureFindChunk(const SceGimChunk *chunk, int type, int idx);
static SceGimChunk *SCEGIM_CHUNK_NEXT(SceGimChunk *chunk);
static SceGimChunk *SCEGIM_CHUNK_CHILD(SceGimChunk *chunk);
static int SCEGIM_CHUNK_TYPE(SceGimChunk *chunk);
int sceGimPictureCountChunk(const SceGimChunk *chunk, int type);


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_private", sceGimPictureFindChunk);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_private", sceGimPictureCountChunk);
