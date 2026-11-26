/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _Z41__static_initialization_and_destruction_0ii_11DB0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN3psp16GetKernelErrNameEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4FileC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4FileC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4FileD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4FileD1Ev);

bool common::File::is_open() const
{
    return handle->fd >= 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File5writeEPKvjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File4readEPvjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File4openEPKcS2_);

int common::File::flush()
{
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File5closeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File4putsEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File4getcERc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File8bytesizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File4tellEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_GetKernelErrName", _ZN6common4File4seekElNS0_3PosE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_11DB0");
void _GLOBAL__I__ZN3psp16GetKernelErrNameEj(void);
void _GLOBAL__D__ZN3psp16GetKernelErrNameEj(void);
}

void _GLOBAL__I__ZN3psp16GetKernelErrNameEj(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3psp16GetKernelErrNameEj(void)
{
    static_init(0, 0xFFFF);
}

