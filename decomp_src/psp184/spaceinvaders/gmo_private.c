#include "common.h"

/* declarations recovered from DWARF (UTST99332 graphics_model gmo_private) */
typedef struct SceGmoChunk SceGmoChunk;
struct SceGmoChunk;
struct SceGmoChunk { /* size 0x10 */
    short unsigned int type;
    short unsigned int args_offs;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef unsigned int size_t;



int sceGmoModelCountChunk(const SceGmoChunk *chunk, int type);
static SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk);
static SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk);
static int SCEGMO_CHUNK_TYPE(SceGmoChunk *chunk);
const SceGmoChunk *sceGmoModelFindChunk(const SceGmoChunk *chunk, int type, int idx);
_Bool sceGmoModelAllocPtr(void *ptr_ptr, size_t size);
_Bool sceGmoModelAllocPtr2(void *ptr_ptr, size_t size);
_Bool sceGmoModelCopyPtr(void *ptr_ptr, const void *src, size_t size);
_Bool sceGmoModelCopyPtr2(void *ptr_ptr, const void *src, size_t size);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_private", sceGmoModelCountChunk);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_private", sceGmoModelFindChunk);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_private", sceGmoModelAllocPtr);

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_private", sceGmoModelAllocPtr2);

void *memcpy(void *d, const void *s, unsigned int n);
_Bool sceGmoModelCopyPtr(void *ptr_ptr, const void *src, size_t size)
{
	if (!sceGmoModelAllocPtr(ptr_ptr, size)) {
		return 0;
	}
	memcpy(*(void **)ptr_ptr, src, size);
	return 1;
}

_Bool sceGmoModelCopyPtr2(void *ptr_ptr, const void *src, size_t size)
{
	if (!sceGmoModelAllocPtr2(ptr_ptr, size)) {
		return 0;
	}
	memcpy(*(void **)ptr_ptr, src, size);
	return 1;
}

INCLUDE_ASM("tmp/asm/psp184/spaceinvaders/nonmatchings/gmo_private", sceGmoModelAllocUncachedBuffer);
