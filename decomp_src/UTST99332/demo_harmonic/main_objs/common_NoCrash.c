/* lang: c++ */
/* cflags: -O2 -frename-registers */
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _Z41__static_initialization_and_destruction_0ii_19860);

void common::NoCrash(bool b)
{
    no_crash = b;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LogC2EPKcbbbb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LogC1EPKcbbbb);

common::common_internal::Log::~Log() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3Log3putEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3Log3getENS1_7ChannelE);

common::common_internal::Log &common::Log(const char *)
{
    return common_internal::Log::get((common_internal::Log::Channel)1);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal14assert_displayEPKcS2_S2_S2_iS2_z);

void common::common_internal::on_error() {
}

void common::common_internal::on_warning() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal5clashEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LoglsEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LoglsEPKh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LoglsERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LoglsEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LoglsEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LoglsEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _ZN6common15common_internal3LoglsEb);

void common::common_internal::Log::useHexa(bool b)
{
    hexa = b;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", __tcf_0_1A7F0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _GLOBAL__I__ZN6common7NoCrashEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _GLOBAL__D__ZN6common7NoCrashEb);
