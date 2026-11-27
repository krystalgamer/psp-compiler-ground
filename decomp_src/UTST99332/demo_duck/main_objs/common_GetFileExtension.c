/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN6common16GetFileExtensionESsb\n_GLOBAL__I__ZN6common16GetFileExtensionESsb = _GLOBAL__I__ZN6common16GetFileExtensionESsb__asm");
__asm__(".globl _GLOBAL__D__ZN6common16GetFileExtensionESsb\n_GLOBAL__D__ZN6common16GetFileExtensionESsb = _GLOBAL__D__ZN6common16GetFileExtensionESsb__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common16GetFileExtensionESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common17GetPathLessSuffixESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common19GetPathLessFilenameESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common11GetBasenameESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common15GetFileLessPathESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common16ReplaceExtensionESsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common12FilePathTestESs);

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_);
