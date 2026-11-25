#include "common.h"

/* declarations recovered from DWARF */
typedef void (*new_handler)();
struct __class_type_info_pseudo;
struct __class_type_info_pseudo { /* size 0x8 */

};
struct __si_class_type_info_pseudo;
struct __si_class_type_info_pseudo { /* size 0xc */

};

extern const struct __class_type_info_pseudo _ZTISt9exception;
extern const struct __si_class_type_info_pseudo _ZTISt9bad_alloc;
extern new_handler __new_handler;
extern const char _ZTSSt9bad_alloc[13];

new_handler set_new_handler(new_handler handler);


void (*_ZSt15set_new_handlerPFvvE(void (*arg0)()))() {
    void (*temp_v0)();

    temp_v0 = __new_handler;
    __new_handler = arg0;
    return temp_v0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/new_handler", _ZNSt9bad_allocD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/new_handler", _ZNSt9bad_allocD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/new_handler", _ZNSt9bad_allocD0Ev);
