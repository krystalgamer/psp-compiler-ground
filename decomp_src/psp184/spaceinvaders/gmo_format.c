#include "common.h"

/* declarations recovered from DWARF (UTST99332 graphics_model gmo_format) */
typedef struct SceGmoHeader SceGmoHeader;
struct SceGmoHeader;
struct SceGmoHeader { /* size 0x10 */
    unsigned int signature;
    unsigned int version;
    unsigned int style;
    unsigned int option;
};
typedef struct SceGmoChunk SceGmoChunk;
struct SceGmoChunk;
struct SceGmoChunk { /* size 0x10 */
    short unsigned int type;
    short unsigned int args_offs;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};



_Bool sceGmoModelCheckFileHeader(const void *buf, int size);
int sceGmoModelGetChunkCount(const void *buf, int size);
const SceGmoChunk *sceGmoModelGetChunk(const void *buf, int size, int idx);

_Bool sceGmoModelCheckFileHeader(const void *buf, int size);
int sceGmoModelCountChunk(const SceGmoChunk *chunk, int type);
const SceGmoChunk *sceGmoModelFindChunk(const SceGmoChunk *chunk, int type, int idx);
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

int sceGmoModelGetChunkCount(const void *buf, int size)
{
	const SceGmoHeader *header;
	const SceGmoChunk *chunk;

	header = (const SceGmoHeader *)buf;
	if (header == NULL)
		return 0;
	chunk = (const SceGmoChunk *)(header + 1);
	return sceGmoModelCountChunk(chunk, 3);
}

const SceGmoChunk *sceGmoModelGetChunk(const void *buf, int size, int idx)
{
	const SceGmoHeader *header;
	const SceGmoChunk *chunk;

	header = (const SceGmoHeader *)buf;
	if (header == NULL)
		return NULL;
	chunk = (const SceGmoChunk *)(header + 1);
	return sceGmoModelFindChunk(chunk, 3, idx);
}
