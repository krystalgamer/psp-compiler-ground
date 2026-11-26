/* cflags: -O2 -frename-registers -fmerge-constants */
#include "common.h"

/* declarations recovered from DWARF */
struct _anon1;
struct _anon1 { /* size 0x10 */
    unsigned int signature;
    unsigned int version;
    unsigned int style;
    unsigned int option;
};
typedef struct _anon1 SceGimHeader;
struct _anon2;
struct _anon2 { /* size 0x10 */
    short unsigned int type;
    short unsigned int unused;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef struct _anon2 SceGimChunk;



_Bool sceGimPictureCheckFileHeader(const void *buf, int size);


_Bool sceGimPictureCheckFileHeader(const void *buf, int size)
{
	const SceGimHeader *header;

	header = (const SceGimHeader *)buf;
	if (header == NULL)
		return 0;
	if (size > 0 && size < 32)
		return 0;
	if (header->signature != 0x2E47494D)
		return 0;
	if (header->version != 0x312E3030)
		return 0;
	return header->style == 0x505350;
}

int sceGimPictureGetChunkCount(void *buf, int size) {
    int var_v1;

    var_v1 = 0;
    if (buf != NULL) {
        var_v1 = sceGimPictureCountChunk(buf + 0x10, 3);
    }
    return var_v1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/gim_picture/gim_format", sceGimPictureGetChunk);
