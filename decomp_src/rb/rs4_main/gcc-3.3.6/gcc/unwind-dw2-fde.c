#include "common.h"

/* declarations recovered from DWARF */
typedef unsigned int _Unwind_Word;
typedef int _Unwind_Sword;
typedef unsigned int _Unwind_Ptr;
union unaligned;
union unaligned { /* size 0x8 */
    void *ptr;
    short unsigned int u2;
    unsigned int u4;
    long long unsigned int u8;
    short int s2;
    int s4;
    long long int s8;
};
typedef unsigned int _Unwind_Internal_Ptr;
struct object;
union _anon1;
struct dwarf_fde;
typedef unsigned int uword;
typedef int sword;
struct dwarf_fde { /* size 0x8 */
    uword length;
    sword CIE_delta;
    unsigned char pc_begin[];
};
struct fde_vector;
typedef unsigned int size_t;
struct fde_vector { /* size 0x8 */
    void *orig_data;
    size_t count;
    struct dwarf_fde *array[];
};
union _anon1 { /* size 0x4 */
    struct dwarf_fde *single;
    struct dwarf_fde **array;
    struct fde_vector *sort;
};
union _anon2;
struct _anon3;
struct _anon3 { /* size 0x4 */
    long unsigned int sorted : 1;
    long unsigned int from_array : 1;
    long unsigned int mixed_encoding : 1;
    long unsigned int encoding : 8;
    long unsigned int count : 21;
};
union _anon2 { /* size 0x4 */
    struct _anon3 b;
    size_t i;
};
struct object { /* size 0x18 */
    void *pc_begin;
    void *tbase;
    void *dbase;
    union _anon1 u;
    union _anon2 s;
    struct object *next;
};
typedef struct __gthread_mutex __gthread_mutex_t;
struct __gthread_mutex;
struct __gthread_mutex { /* size 0x4 */
    int status;
};
struct dwarf_cie;
typedef unsigned char ubyte;
struct dwarf_cie { /* size 0xc */
    uword length;
    sword CIE_id;
    ubyte version;
    unsigned char augmentation[];
};
typedef struct dwarf_fde fde;
typedef int (*fde_compare_t)(struct object *, fde *, fde *);
struct fde_accumulator;
struct fde_accumulator { /* size 0x8 */
    struct fde_vector *linear;
    struct fde_vector *erratic;
};
struct dwarf_eh_bases;
struct dwarf_eh_bases { /* size 0xc */
    void *tbase;
    void *dbase;
    void *func;
};

extern struct object *unseen_objects;
extern struct object *seen_objects;
extern __gthread_mutex_t object_mutex;

static unsigned int size_of_encoded_value(unsigned char encoding);
static const unsigned char *read_uleb128(const unsigned char *p, _Unwind_Word *val);
static const unsigned char *read_sleb128(const unsigned char *p, _Unwind_Sword *val);
static const unsigned char *read_encoded_value_with_base(unsigned char encoding, _Unwind_Ptr base, const unsigned char *p, _Unwind_Ptr *val);
void __register_frame_info_bases(void *begin, struct object *ob, void *tbase, void *dbase);
static int __gthread_mutex_lock(__gthread_mutex_t *mutex);
static int __gthread_mutex_unlock(__gthread_mutex_t *mutex);
void __register_frame_info(void *begin, struct object *ob);
void __register_frame(void *begin);
void __register_frame_info_table_bases(void *begin, struct object *ob, void *tbase, void *dbase);
void __register_frame_info_table(void *begin, struct object *ob);
void __register_frame_table(void *begin);
void *__deregister_frame_info_bases(void *begin);
void *__deregister_frame_info(void *begin);
void __deregister_frame(void *begin);
static _Unwind_Ptr base_from_object(unsigned char encoding, struct object *ob);
static int get_cie_encoding(struct dwarf_cie *cie);
static int fde_unencoded_compare(struct object *ob, fde *x, fde *y);
static int fde_single_encoding_compare(struct object *ob, fde *x, fde *y);
static int fde_mixed_encoding_compare(struct object *ob, fde *x, fde *y);
static int get_fde_encoding(struct dwarf_fde *f);
static struct dwarf_cie *get_cie(struct dwarf_fde *f);
static void frame_heapsort(struct object *ob, fde_compare_t fde_compare, struct fde_vector *erratic);
static size_t classify_object_over_fdes(struct object *ob, fde *this_fde);
static int last_fde(struct object *obj, fde *f);
static fde *next_fde(fde *f);
static void add_fdes(struct object *ob, struct fde_accumulator *accu, fde *this_fde);
static void fde_insert(struct fde_accumulator *accu, fde *this_fde);
static fde *linear_search_fdes(struct object *ob, fde *this_fde, void *pc);
static fde *search_object(struct object *ob, void *pc);
static fde *binary_search_mixed_encoding_fdes(struct object *ob, void *pc);
static fde *binary_search_single_encoding_fdes(struct object *ob, void *pc);
static fde *binary_search_unencoded_fdes(struct object *ob, void *pc);
fde *_Unwind_Find_FDE(void *pc, struct dwarf_eh_bases *bases);
static void init_object(struct object *ob);
static int start_fde_sort(struct fde_accumulator *accu, size_t count);
static void end_fde_sort(struct object *ob, struct fde_accumulator *accu, size_t count);
static void fde_merge(struct object *ob, fde_compare_t fde_compare, struct fde_vector *v1, struct fde_vector *v2);
static void fde_split(struct object *ob, fde_compare_t fde_compare, struct fde_vector *linear, struct fde_vector *erratic);


INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", size_of_encoded_value_E6C68);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", read_uleb128_E6CD8);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", read_sleb128_E6D0C);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", read_encoded_value_with_base_E6D64);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", __register_frame_info_bases);

void __register_frame_info(void *begin, struct object *ob) {
    __register_frame_info_bases(begin, ob, NULL, NULL);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", __register_frame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", __register_frame_info_table_bases);

void __register_frame_info_table(void *begin, struct object *ob) {
    __register_frame_info_table_bases(begin, ob, NULL, NULL);
}

void *malloc(unsigned int size);
void __register_frame_table(void *begin) {
    __register_frame_info_table(begin, malloc(0x18));
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", __deregister_frame_info_bases);

void *__deregister_frame_info(void *begin) {
    return __deregister_frame_info_bases(begin);
}

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", __deregister_frame);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", base_from_object);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", get_cie_encoding);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", fde_unencoded_compare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", fde_single_encoding_compare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", fde_mixed_encoding_compare);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", frame_heapsort);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", classify_object_over_fdes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", add_fdes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", linear_search_fdes);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", search_object);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", _Unwind_Find_FDE);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", init_object);

INCLUDE_ASM("tmp/asm/rb/rs4_main/nonmatchings/gcc-3.3.6/gcc/unwind-dw2-fde", fde_split);
