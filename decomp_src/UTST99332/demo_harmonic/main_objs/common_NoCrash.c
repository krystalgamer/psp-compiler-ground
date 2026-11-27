/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" {
void sceKernelDcacheWritebackAll(void);
void sceGuBreak(int);
void sceGuStart(int, void *, int);
void sceGuClearColor(unsigned int);
void sceGuClear(int);
int sceGuFinish(void);
void sceGuDebugPrint(int, int, unsigned int, const char *);
int sceDisplayWaitVblankStart(void);
void *sceGuSwapBuffers(void);
void sceGuTerm(void);
extern const char D_0015E610[], D_0015E61C[], D_0015E64C[], D_0015E66C[], D_0015E690[], D_0015E6B4[], D_0015E6BC[];
}
extern const char Log_ctor_name[] __asm__("_ZZN6common15common_internal3LogC1EPKcbbbbE19__PRETTY_FUNCTION__");
extern unsigned int clash_dlist[] __asm__("_ZZN6common15common_internal5clashEvE5dlist");
namespace common { namespace common_internal { extern std::string last_str[6]; } }
namespace logchannel_internal { enum { FILENAME_MAX_SIZE = 256 }; }

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", _Z41__static_initialization_and_destruction_0ii_19860);

void common::NoCrash(bool b)
{
    no_crash = b;
}

common::common_internal::Log::Log(const char *name, bool a, bool b, bool c, bool d)
{
    flags[0] = a;
    flags[1] = b;
    flags[2] = c;
    _f104 = true;
    _f105 = d;
    hexa = false;
    unsigned int len = strlen(name) + 1;
    SGL_ASSERT(len < logchannel_internal::FILENAME_MAX_SIZE, D_0015E610, D_0015E61C, D_0015E64C, Log_ctor_name, 108, D_0015E66C);
    strcpy(_name, name);
}



common::common_internal::Log::~Log() {
}

void common::common_internal::Log::put(const char *s)
{
    if (!s)
        return;
    if (flags[1]) {
        std::cout.flush();
        std::cout << s;
        std::cout.flush();
    }
    sceKernelDcacheWritebackAll();
}

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

void common::common_internal::clash()
{
    if (no_crash)
        return;
    sceGuBreak(0);
    sceGuStart(0, clash_dlist, 64);
    sceGuClearColor(0xFF0000);
    sceGuClear(7);
    sceGuFinish();
    sceGuDebugPrint(0, 220, 0xFFFFFF, last_str[1].c_str());
    sceGuDebugPrint(0, 230, 0xFFFFFF, last_str[3].c_str());
    sceGuDebugPrint(0, 240, 0xFFFFFF, last_str[4].c_str());
    if (last_str[5] != D_0015E690)
        sceGuDebugPrint(0, 250, 0xFFFFFF, last_str[5].c_str());
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
    sceGuTerm();
    *(int *)0 = 0;
}

common::common_internal::Log &common::common_internal::Log::operator<<(const char *s)
{
    put(s);
    return *this;
}

common::common_internal::Log &common::common_internal::Log::operator<<(const unsigned char *s)
{
    put((const char *)s);
    return *this;
}

common::common_internal::Log &common::common_internal::Log::operator<<(const std::string &s)
{
    put(s.c_str());
    return *this;
}

common::common_internal::Log &common::common_internal::Log::operator<<(int i)
{
    char buf[64];
    if (!hexa)
        libc_fix::ItoA(buf, 64, i);
    else
        libc_fix::ItoAX(buf, 64, i);
    put(buf);
    return *this;
}

common::common_internal::Log &common::common_internal::Log::operator<<(unsigned int i)
{
    char buf[64];
    if (!hexa)
        libc_fix::ItoA(buf, 64, i);
    else
        libc_fix::ItoAX(buf, 64, i);
    put(buf);
    return *this;
}

common::common_internal::Log &common::common_internal::Log::operator<<(float f)
{
    char buf[64];
    libc_fix::FtoA(f, buf);
    put(buf);
    return *this;
}

common::common_internal::Log &common::common_internal::Log::operator<<(bool b)
{
    put(b ? D_0015E6B4 : D_0015E6BC);
    return *this;
}

void common::common_internal::Log::useHexa(bool b)
{
    hexa = b;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_NoCrash", __tcf_0_1A7F0);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_19860");
void _GLOBAL__I__ZN6common7NoCrashEb(void);
void _GLOBAL__D__ZN6common7NoCrashEb(void);
}

void _GLOBAL__I__ZN6common7NoCrashEb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN6common7NoCrashEb(void)
{
    static_init(0, 0xFFFF);
}
