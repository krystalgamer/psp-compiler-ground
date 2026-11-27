/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

extern "C" const char D_0015F2E0[], D_0015F2E4[], D_0015F2E8[], D_0015F2EC[], D_0015F2F0[], D_0015F2F4[], D_0015F30C[],
    D_0015F310[], D_0015F328[], D_0015F340[], D_0015F358[];
namespace common {
std::string GetFileExtension(std::string, bool);
std::string GetPathLessSuffix(std::string);
std::string GetPathLessFilename(std::string);
std::string GetBasename(std::string);
std::string GetFileLessPath(std::string);
std::string ReplaceExtension(std::string, std::string);
void FilePathTest(std::string);
}

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN6common16GetFileExtensionESsb\n_GLOBAL__I__ZN6common16GetFileExtensionESsb = _GLOBAL__I__ZN6common16GetFileExtensionESsb__asm");
__asm__(".globl _GLOBAL__D__ZN6common16GetFileExtensionESsb\n_GLOBAL__D__ZN6common16GetFileExtensionESsb = _GLOBAL__D__ZN6common16GetFileExtensionESsb__asm");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common16GetFileExtensionESsb);

std::string common::GetPathLessSuffix(std::string s)
{
    std::string::size_type p = s.find_last_of(D_0015F2E0);
    if (p == std::string::npos)
        return s;
    return std::string(s, 0, p);
}

static inline std::string::size_type LastSlash(const std::string &s)
{
    std::string::size_type a = s.find_last_of(D_0015F2E4);
    std::string::size_type b = s.find_last_of(D_0015F2E8);
    if (a == std::string::npos && b == std::string::npos)
        return std::string::npos;
    if (a != std::string::npos && b == std::string::npos)
        return a;
    if (a == std::string::npos && b != std::string::npos)
        return b;
    return a < b ? b : a;
}

std::string common::GetPathLessFilename(std::string s)
{
    std::string::size_type p = LastSlash(s);
    if (p == std::string::npos)
        return std::string(D_0015F2EC);
    return std::string(s, 0, p);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common11GetBasenameESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common15GetFileLessPathESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZN6common16ReplaceExtensionESsSs);

void common::FilePathTest(std::string f)
{
    std::cout << f << D_0015F2F0;
    std::cout << D_0015F2F4 << GetFileExtension(f, true) << D_0015F30C;
    std::cout << D_0015F310 << GetPathLessSuffix(f) << D_0015F30C;
    std::cout << D_0015F328 << GetPathLessFilename(f) << D_0015F30C;
    std::cout << D_0015F340 << GetBasename(f) << D_0015F30C;
    std::cout << D_0015F358 << GetFileLessPath(f) << D_0015F30C;
}

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_GetFileExtension", _ZStplIcSt11char_traitsIcESaIcEESbIT_T0_T1_ERKS6_S8_);
