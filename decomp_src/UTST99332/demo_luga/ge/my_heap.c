/* cflags: -O2 -frename-registers */
#include "common.h"
#define g_alloc_count g_alloc_count_402A3C
#define g_total_free g_total_free_402A38
#define g_total_size g_total_size_402A34
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


INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/my_heap", my_heap__alloc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/my_heap", my_heap__free);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/my_heap", my_heap__draw_status);

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/my_heap", my_heap__init);


void my_heap__term(void) {
    g_top = 0;
}


int my_heap__get_total_size(void) {
    return g_total_size * 0x10;
}


int my_heap__get_total_free(void) {
    return g_total_free * 0x10;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_luga/nonmatchings/ge/my_heap", my_heap__get_max_free);


int my_heap__get_alloc_count(void) {
    return g_alloc_count;
}
