/* cflags: -O2 -frename-registers -fno-merge-constants */
#include "common.h"

/* --- declarations --- */
#include "mpeg.h"

extern char *D_00007D80;

static __inline__ int __strtok_find(const char *d, char c)
{
	int sc;

	while ((sc = *d++) != '\0') {
		if (sc == c)
			return sc;
	}
	return 0;
}
int __tolower_i(int c) __asm__("func_0000720C");
extern const char D_00007994[];

extern const StreamTypeInfo D_000078F4[];
/* --- end declarations --- */

void *func_00001208(unsigned int id, MpegSys *sys, int kind)
{
	int ch;

	if ((id & 0xFFFFE000) == 0xBF01E000) {
		ch = ((id & ~0xBF01E000) << 16) >> 24;
		if (kind == 1)
			return &sys->streams[ch];
		return &sys->streams64[ch];
	}
	if ((id & 0xE0000000) == 0xE0000000) {
		ch = (id & ~0xE0000000) >> 24;
		if (kind == 1)
			return &sys->streams[0x10 + ch];
		return &sys->streams64[0x10 + ch];
	}
	if ((id & 0xFFF00000) == 0xBD000000) {
		ch = (id & ~0xBD000000) >> 16;
		if (kind == 1)
			return &sys->streams[0x20 + ch];
		return &sys->streams64[0x20 + ch];
	}
	if ((id & 0xFFE00000) == 0xBD800000) {
		ch = (id & ~0xBD800000) >> 16;
		if (kind == 1)
			return &sys->streams[0x40 + ch];
		return &sys->streams64[0x40 + ch];
	}
	if ((id & 0xFFF00000) == 0xBD100000) {
		ch = (id & ~0xBD100000) >> 16;
		if (kind == 1)
			return &sys->streams[0x30 + ch];
		return &sys->streams64[0x30 + ch];
	}
	if ((id & 0xFFF00000) == 0xBD200000) {
		ch = (id & ~0xBD200000) >> 16;
		if (kind == 1)
			return &sys->streams[0x60 + ch];
		return &sys->streams64[0x60 + ch];
	}
	return (void *)-1;
}

int func_000013AC(AuList2 *l, int start, int count, SceMpegAuInfo *dst, int *out)
{
	AuNode2 *node;
	int i;
	int n;

	*out = 0;
	if (l->head == (AuNode2 *)-1)
		return SCE_MPEG_ERROR_INVALID_VALUE;
	if (start >= l->num)
		return 0;
	node = l->head;
	for (i = 0; i < start; i++)
		node = node->next;
	n = l->num - start;
	n = (count < n) ? count : n;
	for (i = 0; i < n; i++) {
		__builtin_memcpy(&dst[i], &node->info, sizeof(SceMpegAuInfo));
		node = node->next;
	}
	*out = n;
	return 0;
}

INCLUDE_ASM("tmp/asm/tony_libs/mpeg/nonmatchings/mpeg_stream", func_00001474);
