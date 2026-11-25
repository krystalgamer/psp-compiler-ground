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


_Bool sceGmoModelCheckFileHeader(const void *buf, int size)
{
	const SceGmoHeader *header;

	header = (const SceGmoHeader *)buf;
	if (header == NULL)
		return 0;
	if (size > 0 && size < 32)
		return 0;
	if (header->signature != 0x2E474D4F)
		return 0;
	if (header->version != 0x312E3030)
		return 0;
	return header->style == 0x505350;
}

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
