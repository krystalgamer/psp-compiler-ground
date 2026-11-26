/* cflags: -O2 -frename-registers */
#include "common.h"
#define g_alloc_count g_alloc_count_402A3C
#define g_total_free g_total_free_402A38
#define g_total_size g_total_size_402A34
#define g_end g_end_402A30
#define g_top g_top_402A2C

/* declarations recovered from DWARF */
typedef unsigned int size_t;
typedef struct block block;
struct block;
struct block { /* size 0x10 */
    struct block *next;
    int size;
    int dummy[2];
};

extern block *g_top;
extern block *g_end;
extern int g_total_size;
extern int g_total_free;
extern int g_alloc_count;

void *my_heap__alloc(size_t size);
void my_heap__free(void *addr);
void my_heap__draw_status(unsigned char *pixels, int width, int col0, int col1);
void my_heap__init(void *addr, size_t size);
void my_heap__term();
int my_heap__get_total_size();
int my_heap__get_total_free();
int my_heap__get_max_free();
int my_heap__get_alloc_count();


void *my_heap__alloc(size_t size)
{
	block *p, *prev;
	int nunits;

	if (size == 0) {
		return NULL;
	}
	nunits = (size + sizeof(block)) / sizeof(block) + 1;

	prev = g_top;
	for (;;) {
		p = prev->next;
		if (p->size >= nunits) {
			if (p->size == nunits) {
				prev->next = p->next;
			} else {
				p->size -= nunits;
				p += p->size;
				p->size = nunits;
			}
			g_top = prev;
			g_total_free -= nunits;
			g_alloc_count++;
			return (void *)(p + 1);
		}
		if (p == g_top) {
			return NULL;
		}
		prev = p;
	}
}

void my_heap__free(void *addr)
{
	block *bp, *p;

	if (addr == NULL) {
		return;
	}

	bp = (block *)addr - 1;
	for (p = g_top; !(bp > p && bp < p->next); p = p->next) {
		if (p >= p->next && (bp > p || bp < p->next)) {
			break;
		}
	}

	g_total_free += bp->size;
	g_alloc_count--;

	if (bp + bp->size == p->next && p->next->size != 0) {
		bp->size += p->next->size;
		bp->next = p->next->next;
	} else {
		bp->next = p->next;
	}

	if (p + p->size == bp) {
		p->size += bp->size;
		p->next = bp->next;
	} else {
		p->next = bp;
	}

	g_top = p;
}

void my_heap__draw_status(unsigned char *pixels, int width, int col0, int col1)
{
	block *top, *p;
	int total, i, s, e;

	if (pixels == NULL) {
		return;
	}
	for (i = 0; i < width; i++) {
		pixels[i] = col1;
	}
	top = g_end->next;
	total = g_end - top;
	for (p = top; p != g_end; p = p->next) {
		s = (p - top) * width / total;
		e = (p + p->size - top) * width / total;
		for (; s < e; s++) {
			pixels[s] = col0;
		}
	}
}

void my_heap__init(void *addr, size_t size)
{
	if (addr == NULL || size == 0) {
		return;
	}
	size = size / sizeof(block) * sizeof(block);

	g_top = (block *)addr;
	g_end = (block *)((char *)addr + size) - 1;
	g_end->next = g_top;
	g_end->size = 0;
	g_top->next = g_end;
	g_top->size = size / sizeof(block) - 2;

	g_total_size = g_top->size;
	g_total_free = g_top->size;
	g_alloc_count = 0;
}


void my_heap__term(void) {
    g_top = 0;
}


int my_heap__get_total_size(void) {
    return g_total_size * 0x10;
}


int my_heap__get_total_free(void) {
    return g_total_free * 0x10;
}

int my_heap__get_max_free()
{
	block *p;
	int max = 0;

	p = g_top;
	do {
		if (p->size > max) {
			max = p->size;
		}
		p = p->next;
	} while (p != g_top);

	return max * sizeof(block);
}


int my_heap__get_alloc_count(void) {
    return g_alloc_count;
}
