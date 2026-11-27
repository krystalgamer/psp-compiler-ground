/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN6common8FileDumpC2Ej");
__asm__(".globl _GLOBAL__D__ZN6common8FileDumpC2Ej");


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
        failed(name, "load", "filename string points to 0");
        return -1;
    }
    if (!__builtin_strcmp(name, "")) {
        failed(name, "load", "filename string is the empty string");
        return -1;
    }
    File f;
    f.open(name, _f20 ? "rb" : "r");
    if (!f.is_open()) {
        failed(name, "load", "fopen() failed");
        return -1;
    }
    unsigned int n = f.bytesize();
    if (!n) {
        failed(name, "load", "file has been opened but it's empty");
        return -1;
    }
    _data.resize(_f20 ? n : n + 1);
    common::Log() << "reading file \"" << name << "\" in " << (_f20 ? "binary" : "text") << " "
                  << _data.bytesize() << " bytes...\n";
    if (_f20) {
        f.read(_data.addr(), _data.bytesize(), 1);
    } else {
        f.read(_data.addr(), _data.bytesize() - 1, 1);
        _data.addr()[_data.bytesize() - 1] = 0;
    }
    f.close();
    common::Log() << "opened file \"" << name << "\" in " << (_f20 ? "binary" : "text") << " mode,"
                  << " read " << _data.bytesize() << " bytes\n";
    reference_owned_data();
    return 0;
}

int common::FileDump::save(const char *name)
{
    if (!name) {
        failed(name, "save", "filename string points to 0");
        return -1;
    }
    if (!__builtin_strcmp(name, "")) {
        failed(name, "save", "filename string is the empty string");
        return -1;
    }
    File f;
    f.open(name, _f20 ? "wb+" : "w+");
    if (!f.is_open()) {
        failed(name, "save", "fopen() failed");
        return -1;
    }
    if (_f20)
        f.write(_data.addr(), _data.bytesize(), 1);
    else
        f.puts((const char *)_data.addr());
    f.flush();
    f.close();
    common::Log() << "saved file \"" << name << "\" in " << (_f20 ? "binary" : "text") << " mode,"
                  << " wrote " << _data.bytesize() << " bytes\n";
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
    common::Log("assert") << "could not " << op << " file \"" << name << "\"" << "; cause: " << cause << "\n";
    SGL_ASSERT(!_f21, " *** error ", "", "../lib/system/FileDump.cpp", __PRETTY_FUNCTION__, 0xE2, "");
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
