/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN17basic_file_parserC2ESsjPKc");
__asm__(".globl _GLOBAL__D__ZN17basic_file_parserC2ESsjPKc");

/* stand-in for common::FileDump's ctor/dtor/load (demo/base.hpp doesn't declare them yet) */

#define FILEDUMP_SIZE 0x24
namespace {
struct FileDumpX {
    void *_vp;
    char _p4[0x18 - 4];
    char *_data;                            /* 0x18 */
    char _p1c[FILEDUMP_SIZE - 0x1C];
};
}
void FileDumpX_ctor(FileDumpX *, unsigned int) __asm__("_ZN6common8FileDumpC1Ej");
void FileDumpX_dtor(FileDumpX *) __asm__("_ZN6common8FileDumpD1Ev");
void FileDumpX_text(FileDumpX *) __asm__("_ZN6common8FileDump4textEv");
void FileDumpX_blocking(FileDumpX *, bool) __asm__("_ZN6common8FileDump8blockingEb");
int FileDumpX_load(FileDumpX *, const char *) __asm__("_ZN6common8FileDump4loadEPKc");

basic_file_parser::basic_file_parser(std::string file, unsigned int size, const char *seps)
    : basic_parser(0, size, seps), _ready(false)
{
    FileDumpX fd;
    FileDumpX_ctor(&fd, 0);
    FileDumpX_text(&fd);
    FileDumpX_blocking(&fd, false);
    if (FileDumpX_load(&fd, file.c_str()) >= 0) {
        _ready = true;
        copy_text(fd._data);
    }
    FileDumpX_dtor(&fd);
}

basic_file_parser::~basic_file_parser()
{
}

bool basic_file_parser::ready() const
{
    return _ready;
}

void basic_file_parser::preprocess()
{
    std::string text;
    swap(text);
    for (std::string::iterator it = text.begin(); it != text.end(); ++it)
        if (*it == '#')
            for (std::string::iterator j = it; *j != 0 && *j != '\n' && j != text.end(); ++j)
                *j = ' ';
    swap(text);
}
