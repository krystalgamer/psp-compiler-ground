#include "common.h"

/* declarations recovered from DWARF */
typedef void (*terminate_handler)();
typedef void (*unexpected_handler)();
typedef long long unsigned int _Unwind_Exception_Class;

extern const _Unwind_Exception_Class __gxx_exception_class;

void __terminate(terminate_handler handler);
void terminate();
void __unexpected(unexpected_handler handler);
void unexpected();
terminate_handler set_terminate(terminate_handler func);
unexpected_handler set_unexpected(unexpected_handler func);


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/eh_terminate", _ZN10__cxxabiv111__terminateEPFvvE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/eh_terminate", _ZSt9terminatev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/eh_terminate", _ZN10__cxxabiv112__unexpectedEPFvvE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/gcc-3.3.3/libstdc__-v3/libsupc__/eh_terminate", _ZSt10unexpectedv);

extern int _ZN10__cxxabiv119__terminate_handlerE;

int _ZSt13set_terminatePFvvE(int arg0) {
    int temp_v0;

    temp_v0 = _ZN10__cxxabiv119__terminate_handlerE;
    _ZN10__cxxabiv119__terminate_handlerE = arg0;
    return temp_v0;
}

extern int _ZN10__cxxabiv120__unexpected_handlerE;

int _ZSt14set_unexpectedPFvvE(int arg0) {
    int temp_v0;

    temp_v0 = _ZN10__cxxabiv120__unexpected_handlerE;
    _ZN10__cxxabiv120__unexpected_handlerE = arg0;
    return temp_v0;
}
