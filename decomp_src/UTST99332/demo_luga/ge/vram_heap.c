/* cflags: -O2 -frename-registers */
#include "common.h"
#define g_alloc_count g_alloc_count_402A50
#define g_total_free g_total_free_402A4C
#define g_total_size g_total_size_402A48
#define g_top g_top_402A40

/* declarations recovered from DWARF */
enum _anon1 {
    VRAM_HEAP_16 = 0,
    VRAM_HEAP_32 = 1,
};
typedef enum _anon1 VramHeap;
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

void vram_heap__init(VramHeap mode);
void *vram_heap__alloc(size_t size);
void vram_heap__free(void *addr);
void vram_heap__draw_status(unsigned char *pixels, int width, int col0, int col1);
void vram_heap__term();
int vram_heap__get_total_size();
int vram_heap__get_total_free();
int vram_heap__get_max_free();
int vram_heap__get_alloc_count();


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__init);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__alloc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__free);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__draw_status);


void vram_heap__term(void) {
    g_top = 0;
}


int vram_heap__get_total_size(void) {
    return g_total_size * 0x10;
}


int vram_heap__get_total_free(void) {
    return g_total_free * 0x10;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/vram_heap", vram_heap__get_max_free);


int vram_heap__get_alloc_count(void) {
    return g_alloc_count;
}
