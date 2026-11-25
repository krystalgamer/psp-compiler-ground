#include "common.h"

/* declarations recovered from DWARF */
struct SceGmoChunk;
struct SceGmoChunk { /* size 0x10 */
    short unsigned int type;
    short unsigned int args_offs;
    unsigned int next_offs;
    unsigned int child_offs;
    unsigned int data_offs;
};
typedef struct SceGmoChunk SceGmoChunk;
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

/* SDK functions */
void *memcpy(void *d, const void *s, unsigned int n);

static __inline__ SceGmoChunk *SCEGMO_CHUNK_NEXT(SceGmoChunk *chunk)
{
	return (SceGmoChunk *)((char *)chunk + chunk->next_offs);
}

static __inline__ SceGmoChunk *SCEGMO_CHUNK_CHILD(SceGmoChunk *chunk)
{
	if (chunk->type & 0x8000)
		return SCEGMO_CHUNK_NEXT(chunk);
	return (SceGmoChunk *)((char *)chunk + chunk->child_offs);
}

static __inline__ int SCEGMO_CHUNK_TYPE(SceGmoChunk *chunk)
{
	return chunk->type & ~0x8000;
}

int sceGmoModelCountChunk(const SceGmoChunk *chunk, int type)
{
	int count;
	SceGmoChunk *end;

	count = 0;
	end = SCEGMO_CHUNK_NEXT((SceGmoChunk *)chunk);
	for (chunk = SCEGMO_CHUNK_CHILD((SceGmoChunk *)chunk); chunk < end; chunk = SCEGMO_CHUNK_NEXT((SceGmoChunk *)chunk)) {
		if (type == 0 || SCEGMO_CHUNK_TYPE((SceGmoChunk *)chunk) == type)
			count++;
	}
	return count;
}

const SceGmoChunk *sceGmoModelFindChunk(const SceGmoChunk *chunk, int type, int idx)
{
	SceGmoChunk *end;

	end = SCEGMO_CHUNK_NEXT((SceGmoChunk *)chunk);
	for (chunk = SCEGMO_CHUNK_CHILD((SceGmoChunk *)chunk); chunk < end; chunk = SCEGMO_CHUNK_NEXT((SceGmoChunk *)chunk)) {
		if (type == 0 || SCEGMO_CHUNK_TYPE((SceGmoChunk *)chunk) == type) {
			if (--idx == -1)
				return chunk;
		}
	}
	return NULL;
}

_Bool sceGmoModelAllocPtr(void *ptr_ptr, size_t size)
{
	void *ptr = *(void **)ptr_ptr;
	if (ptr != NULL) {
		sceGmoModelFreeMemory(ptr);
	}
	if (size == 0) {
		*(void **)ptr_ptr = NULL;
		return 1;
	}
	ptr = sceGmoModelAllocMemory(size);
	*(void **)ptr_ptr = ptr;
	return ptr != NULL;
}

_Bool sceGmoModelAllocPtr2(void *ptr_ptr, size_t size)
{
	void *ptr = *(void **)ptr_ptr;
	if (ptr != NULL) {
		sceGmoModelFreeMemory2(ptr);
	}
	if (size == 0) {
		*(void **)ptr_ptr = NULL;
		return 1;
	}
	ptr = sceGmoModelAllocMemory2(size);
	*(void **)ptr_ptr = ptr;
	return ptr != NULL;
}

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
