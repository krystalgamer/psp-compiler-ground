/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

extern "C" const char D_00172A54[], D_00172A5C[], D_00172A68[], D_00172A70[], D_00172A74[], D_00172A80[];
extern "C" const char D_00172A84[], D_00172A88[], D_00172A94[];
extern "C" const char D_00172900[], D_00172908[], D_0017290C[], D_00172910[], D_00172920[], D_00172928[], D_00172930[];
extern "C" const char D_00172938[], D_0017293C[], D_00172948[], D_00172958[], D_00172960[], D_00172968[], D_00172970[];
extern "C" const char D_00172994[], D_001729A4[], D_001729C8[], D_001729E4[], D_001729EC[], D_001729F0[], D_001729F4[];
extern "C" const char D_00172A04[];
extern const char FileDump_failed_fn[] __asm__("_ZZN6common8FileDump6failedEPKcS2_S2_E19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/common_FileDump", _Z41__static_initialization_and_destruction_0ii_F6770);

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
        failed(name, D_00172900, D_001729C8);
        return -1;
    }
    if (!__builtin_strcmp(name, "")) {
        failed(name, D_00172900, D_001729A4);
        return -1;
    }
    File f;
    f.open(name, _f20 ? D_00172908 : D_0017290C);
    if (!f.is_open()) {
        failed(name, D_00172900, D_00172994);
        return -1;
    }
    unsigned int n = f.bytesize();
    if (!n) {
        failed(name, D_00172900, D_00172970);
        return -1;
    }
    _data.resize(_f20 ? n : n + 1);
    common::Log() << D_00172910 << name << D_00172920 << (_f20 ? D_00172928 : D_00172930) << D_00172938
                  << _data.bytesize() << D_0017293C;
    if (_f20) {
        f.read(_data.addr(), _data.bytesize(), 1);
    } else {
        f.read(_data.addr(), _data.bytesize() - 1, 1);
        _data.addr()[_data.bytesize() - 1] = 0;
    }
    f.close();
    common::Log() << D_00172948 << name << D_00172920 << (_f20 ? D_00172928 : D_00172930) << D_00172958
                  << D_00172960 << _data.bytesize() << D_00172968;
    reference_owned_data();
    return 0;
}

int common::FileDump::save(const char *name)
{
    if (!name) {
        failed(name, D_001729E4, D_001729C8);
        return -1;
    }
    if (!__builtin_strcmp(name, "")) {
        failed(name, D_001729E4, D_001729A4);
        return -1;
    }
    File f;
    f.open(name, _f20 ? D_001729EC : D_001729F0);
    if (!f.is_open()) {
        failed(name, D_001729E4, D_00172994);
        return -1;
    }
    if (_f20)
        f.write(_data.addr(), _data.bytesize(), 1);
    else
        f.puts((const char *)_data.addr());
    f.flush();
    f.close();
    common::Log() << D_001729F4 << name << D_00172920 << (_f20 ? D_00172928 : D_00172930) << D_00172958
                  << D_00172A04 << _data.bytesize() << D_00172968;
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
    common::Log(D_00172A54) << D_00172A5C << op << D_00172A68 << name << D_00172A70 << D_00172A74 << cause << D_00172A80;
    SGL_ASSERT(!_f21, D_00172A88, D_00172A84, D_00172A94, FileDump_failed_fn, 0xE2, D_00172A84);
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
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_F6770");
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
