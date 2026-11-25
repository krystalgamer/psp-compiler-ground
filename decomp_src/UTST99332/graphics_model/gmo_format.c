#include "common.h"

/* declarations recovered from DWARF */
struct SceGmoHeader;
struct SceGmoHeader { /* size 0x10 */
    unsigned int signature;
    unsigned int version;
    unsigned int style;
    unsigned int option;
};
typedef struct SceGmoHeader SceGmoHeader;
struct SceGmoChunk;
struct SceGmoChunk { /* size 0x10 */
    short unsigned int type;
    short unsigned int args_offs;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef struct SceGmoChunk SceGmoChunk;



_Bool sceGmoModelCheckFileHeader(const void *buf, int size);


INCLUDE_ASM("tmp/asm/UTST99332/graphics_model/nonmatchings/gmo_format", sceGmoModelCheckFileHeader);

int sceGmoModelGetChunkCount(void *buf, int size) {
    int var_v1;

    var_v1 = 0;
    if (buf != NULL) {
        var_v1 = sceGmoModelCountChunk(buf + 0x10, 3);
    }
    return var_v1;
}

SceGmoChunk *sceGmoModelGetChunk(void *buf, int size, int idx) {
    SceGmoChunk *var_v1;

    var_v1 = NULL;
    if (buf != NULL) {
        var_v1 = sceGmoModelFindChunk(buf + 0x10, 3);
    }
    return var_v1;
}
