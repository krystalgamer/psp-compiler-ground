/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* weak instances stay asm */
extern template class common::t_array<unsigned char>;

extern "C" const char D_0017597C[], D_00175984[], D_00175990[], D_00175998[], D_0017599C[], D_001759A8[];
extern "C" const char D_001759AC[], D_001759B0[], D_001759BC[];
extern "C" const char D_00175828[], D_00175830[], D_00175834[], D_00175838[], D_00175848[], D_00175850[], D_00175858[];
extern "C" const char D_00175860[], D_00175864[], D_00175870[], D_00175880[], D_00175888[], D_00175890[], D_00175898[];
extern "C" const char D_001758BC[], D_001758CC[], D_001758F0[], D_0017590C[], D_00175914[], D_00175918[], D_0017591C[];
extern "C" const char D_0017592C[];
extern const char FileDump_failed_fn[] __asm__("_ZZN6common8FileDump6failedEPKcS2_S2_E19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _Z41__static_initialization_and_destruction_0ii_F8B54);

common::FileDump::FileDump(unsigned int n) : _data(n), _f20(true), _f21(true)
{
    reference_owned_data();
}

common::FileDump::~FileDump()
{
}

int common::FileDump::load(const char *name)
{
    if (!name) {
        failed(name, D_00175828, D_001758F0);
        return -1;
    }
    if (!__builtin_strcmp(name, "")) {
        failed(name, D_00175828, D_001758CC);
        return -1;
    }
    File f;
    f.open(name, _f20 ? D_00175830 : D_00175834);
    if (!f.is_open()) {
        failed(name, D_00175828, D_001758BC);
        return -1;
    }
    unsigned int n = f.bytesize();
    if (!n) {
        failed(name, D_00175828, D_00175898);
        return -1;
    }
    _data.resize(_f20 ? n : n + 1);
    common::Log() << D_00175838 << name << D_00175848 << (_f20 ? D_00175850 : D_00175858) << D_00175860
                  << _data.bytesize() << D_00175864;
    if (_f20) {
        f.read(_data.addr(), _data.bytesize(), 1);
    } else {
        f.read(_data.addr(), _data.bytesize() - 1, 1);
        _data.addr()[_data.bytesize() - 1] = 0;
    }
    f.close();
    common::Log() << D_00175870 << name << D_00175848 << (_f20 ? D_00175850 : D_00175858) << D_00175880
                  << D_00175888 << _data.bytesize() << D_00175890;
    reference_owned_data();
    return 0;
}

int common::FileDump::save(const char *name)
{
    if (!name) {
        failed(name, D_0017590C, D_001758F0);
        return -1;
    }
    if (!__builtin_strcmp(name, "")) {
        failed(name, D_0017590C, D_001758CC);
        return -1;
    }
    File f;
    f.open(name, _f20 ? D_00175914 : D_00175918);
    if (!f.is_open()) {
        failed(name, D_0017590C, D_001758BC);
        return -1;
    }
    if (_f20)
        f.write(_data.addr(), _data.bytesize(), 1);
    else
        f.puts((const char *)_data.addr());
    f.flush();
    f.close();
    common::Log() << D_0017591C << name << D_00175848 << (_f20 ? D_00175850 : D_00175858) << D_00175880
                  << D_0017592C << _data.bytesize() << D_00175890;
    return 0;
}

void common::FileDump::binary()
{
    _f20 = true;
}

void common::FileDump::text()
{
    _f20 = false;
}

void common::FileDump::blocking(bool v)
{
    _f21 = v;
}

void common::FileDump::failed(const char *name, const char *op, const char *cause)
{
    common::Log(D_0017597C) << D_00175984 << op << D_00175990 << name << D_00175998 << D_0017599C << cause << D_001759A8;
    SGL_ASSERT(!_f21, D_001759B0, D_001759AC, D_001759BC, FileDump_failed_fn, 0xE2, D_001759AC);
}

void common::FileDump::reference_owned_data()
{
    _ptr = _data.addr();
    _size = _data.bytesize();
}

void common::FileDump::setArray(const unsigned char *p, unsigned int n)
{
    _data.resize(n);
    for (unsigned int i = 0; i < n; i++)
        _data.addr()[i] = p[i];
    reference_owned_data();
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F8B54");
void _GLOBAL__I__ZN6common8FileDumpC2Ej(void);
void _GLOBAL__D__ZN6common8FileDumpC2Ej(void);
}

void _GLOBAL__I__ZN6common8FileDumpC2Ej(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN6common8FileDumpC2Ej(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhEC1Ej);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhE6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZNK6common7t_arrayIhE8bytesizeEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhE8allocateEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhE4swapERS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common7t_arrayIhE4fillERKh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/common_FileDump", _ZN6common4SwapINS_7t_arrayIhE7MembersEEEvRT_S5_);

