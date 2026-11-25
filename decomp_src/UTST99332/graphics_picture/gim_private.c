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



int sceGimPictureCountChunk(const SceGimChunk *chunk, int type);
static SceGimChunk *SCEGIM_CHUNK_NEXT(SceGimChunk *chunk);
static SceGimChunk *SCEGIM_CHUNK_CHILD(SceGimChunk *chunk);
static int SCEGIM_CHUNK_TYPE(SceGimChunk *chunk);
const SceGimChunk *sceGimPictureFindChunk(const SceGimChunk *chunk, int type, int idx);

static __inline__ SceGimChunk *SCEGIM_CHUNK_NEXT(SceGimChunk *chunk)
{
	return (SceGimChunk *)((char *)chunk + chunk->next_offs);
}

static __inline__ SceGimChunk *SCEGIM_CHUNK_CHILD(SceGimChunk *chunk)
{
	return (SceGimChunk *)((char *)chunk + chunk->child_offs);
}

static __inline__ int SCEGIM_CHUNK_TYPE(SceGimChunk *chunk)
{
	return chunk->type;
}

int sceGimPictureCountChunk(const SceGimChunk *chunk, int type)
{
	int count;
	SceGimChunk *end;

	count = 0;
	end = SCEGIM_CHUNK_NEXT((SceGimChunk *)chunk);
	for (chunk = SCEGIM_CHUNK_CHILD((SceGimChunk *)chunk); chunk < end; chunk = SCEGIM_CHUNK_NEXT((SceGimChunk *)chunk)) {
		if (type == 0 || SCEGIM_CHUNK_TYPE((SceGimChunk *)chunk) == type)
			count++;
	}
	return count;
}

const SceGimChunk *sceGimPictureFindChunk(const SceGimChunk *chunk, int type, int idx)
{
	SceGimChunk *end;

	end = SCEGIM_CHUNK_NEXT((SceGimChunk *)chunk);
	for (chunk = SCEGIM_CHUNK_CHILD((SceGimChunk *)chunk); chunk < end; chunk = SCEGIM_CHUNK_NEXT((SceGimChunk *)chunk)) {
		if (type == 0 || SCEGIM_CHUNK_TYPE((SceGimChunk *)chunk) == type) {
			if (--idx == -1)
				return chunk;
		}
	}
	return NULL;
}
