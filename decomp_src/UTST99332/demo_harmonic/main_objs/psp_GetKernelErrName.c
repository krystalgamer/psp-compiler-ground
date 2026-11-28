/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3psp16GetKernelErrNameEj");
__asm__(".globl _GLOBAL__D__ZN3psp16GetKernelErrNameEj");

extern "C" long long sceIoLseek(int fd, long long offset, int whence);
extern "C" int sceIoClose(int fd);
extern "C" int sceIoRead(int fd, void *data, unsigned int size);
extern "C" int sceIoWrite(int fd, const void *data, unsigned int size);
extern "C" int sceKernelDcacheWritebackAll(void);
extern "C" int puts(const char *);
extern "C" const char D_0015E124[], D_0015E14C[], D_0015E15C[], D_0015E180[], D_0015E190[], D_0015E204[], D_0015E228[];
extern "C" const char D_0015E230[], D_0015E238[];
extern const char File_write_fn[] __asm__("_ZZN6common4File5writeEPKvjjE19__PRETTY_FUNCTION__");
extern const char File_read_fn[] __asm__("_ZZN6common4File4readEPvjjE19__PRETTY_FUNCTION__");
extern "C" const char D_0015E120[], D_0015E148[], D_0015E1A8[], D_0015E2BC[], D_0015E2F0[], D_0015E33C[], D_0015E380[];
extern "C" const char D_0015E3C4[], D_0015E40C[], D_0015E470[];
extern const char File_close_fn[] __asm__("_ZZN6common4File5closeEvE19__PRETTY_FUNCTION__");
extern const char File_puts_fn[] __asm__("_ZZN6common4File4putsEPKcE19__PRETTY_FUNCTION__");
extern const char File_getc_fn[] __asm__("_ZZN6common4File4getcERcE19__PRETTY_FUNCTION__");
extern const char File_bytesize_fn[] __asm__("_ZZN6common4File8bytesizeEvE19__PRETTY_FUNCTION__");
extern const char File_tell_fn[] __asm__("_ZZN6common4File4tellEvE19__PRETTY_FUNCTION__");
extern const char File_seek_fn[] __asm__("_ZZN6common4File4seekElNS0_3PosEE19__PRETTY_FUNCTION__");
extern const int File_seek_POS_TAB[] __asm__("_ZZN6common4File4seekElNS0_3PosEE7POS_TAB");
extern "C" const char D_0015C8CC[], D_0015C8E0[], D_0015C8F8[], D_0015C910[], D_0015C934[], D_0015C958[], D_0015C97C[], D_0015C9A0[], D_0015C9C4[], D_0015C9EC[], D_0015CA1C[], D_0015CA4C[], D_0015CA70[], D_0015CA94[], D_0015CAAC[], D_0015CACC[], D_0015CAF0[], D_0015CB14[], D_0015CB38[], D_0015CB5C[], D_0015CB84[], D_0015CBA8[], D_0015CBC4[], D_0015CBE8[], D_0015CC08[], D_0015CC2C[], D_0015CC48[], D_0015CC6C[], D_0015CC90[], D_0015CCAC[], D_0015CCC8[], D_0015CCE4[], D_0015CD04[], D_0015CD28[], D_0015CD4C[], D_0015CD6C[], D_0015CD90[], D_0015CDB0[], D_0015CDD4[], D_0015CDF8[], D_0015CE18[], D_0015CE38[], D_0015CE5C[], D_0015CE7C[], D_0015CE9C[], D_0015CEC0[], D_0015CEE4[], D_0015CF08[], D_0015CF30[], D_0015CF58[], D_0015CF80[], D_0015CFA8[], D_0015CFD0[], D_0015CFF4[], D_0015D010[], D_0015D030[], D_0015D050[], D_0015D068[], D_0015D084[], D_0015D0A0[], D_0015D0C4[], D_0015D0E8[], D_0015D108[], D_0015D12C[], D_0015D14C[], D_0015D16C[], D_0015D18C[], D_0015D1B4[], D_0015D1D4[], D_0015D1F8[], D_0015D21C[], D_0015D23C[], D_0015D260[], D_0015D280[], D_0015D2A4[], D_0015D2C4[], D_0015D2E8[], D_0015D308[], D_0015D334[], D_0015D360[], D_0015D37C[], D_0015D39C[], D_0015D3BC[], D_0015D3E0[], D_0015D404[], D_0015D424[], D_0015D444[], D_0015D464[], D_0015D484[], D_0015D4A4[], D_0015D4C4[], D_0015D4E4[], D_0015D504[], D_0015D524[], D_0015D544[], D_0015D564[], D_0015D584[], D_0015D5A4[], D_0015D5C0[], D_0015D5DC[], D_0015D5FC[], D_0015D61C[], D_0015D638[], D_0015D658[], D_0015D678[], D_0015D698[], D_0015D6B8[], D_0015D6DC[], D_0015D700[], D_0015D71C[], D_0015D738[], D_0015D754[], D_0015D770[], D_0015D78C[], D_0015D7A8[], D_0015D7C4[], D_0015D7E0[], D_0015D800[], D_0015D824[], D_0015D848[], D_0015D86C[], D_0015D888[], D_0015D8A8[], D_0015D8C8[], D_0015D8E8[], D_0015D908[], D_0015D928[], D_0015D948[], D_0015D968[], D_0015D984[], D_0015D9A0[], D_0015D9C8[], D_0015D9EC[], D_0015DA10[], D_0015DA38[], D_0015DA60[], D_0015DA88[], D_0015DAAC[], D_0015DAD0[], D_0015DAF4[], D_0015DB18[], D_0015DB3C[], D_0015DB64[], D_0015DB90[], D_0015DBBC[], D_0015DBEC[], D_0015DC18[], D_0015DC40[], D_0015DC68[], D_0015DC88[], D_0015DCAC[], D_0015DCD0[], D_0015DCF8[], D_0015DD1C[], D_0015DD3C[], D_0015DD5C[], D_0015DD7C[], D_0015DDA0[], D_0015DDC0[], D_0015DDE8[], D_0015DE10[], D_0015DE38[], D_0015DE60[], D_0015DE8C[], D_0015DEB4[], D_0015DED8[], D_0015DEF0[], D_0015DF08[], D_0015DF20[], D_0015DF38[], D_0015DF50[], D_0015DF68[], D_0015DF84[], D_0015DFA4[], D_0015DFC4[], D_0015DFE0[], D_0015DFFC[], D_0015E014[], D_0015E02C[], D_0015E04C[], D_0015E064[], D_0015E078[], D_0015E090[], D_0015E0B4[], D_0015E0D8[];
#define FILE_ERROR(fn, msg) std::cout << fn << D_0015E120 << msg << D_0015E148; std::cout.flush()

const char *psp::GetKernelErrName(unsigned int code)
{
    if (code == 0)
        return D_0015C8CC;
    if (code == 0x80020001)
        return D_0015C8E0;
    if (code == 0x80020002)
        return D_0015C8F8;
    if (code == 0x80020032)
        return D_0015C910;
    if (code == 0x80020033)
        return D_0015C934;
    if (code == 0x80020034)
        return D_0015C958;
    if (code == 0x80020035)
        return D_0015C97C;
    if (code == 0x80020036)
        return D_0015C9A0;
    if (code == 0x80020037)
        return D_0015C9C4;
    if (code == 0x80020038)
        return D_0015C9EC;
    if (code == 0x80020039)
        return D_0015CA1C;
    if (code == 0x80020064)
        return D_0015CA4C;
    if (code == 0x80020065)
        return D_0015CA70;
    if (code == 0x80020066)
        return D_0015CA94;
    if (code == 0x80020067)
        return D_0015CAAC;
    if (code == 0x80020068)
        return D_0015CACC;
    if (code == 0x80020069)
        return D_0015CAF0;
    if (code == 0x8002006A)
        return D_0015CB14;
    if (code == 0x8002006B)
        return D_0015CB38;
    if (code == 0x8002006C)
        return D_0015CB5C;
    if (code == 0x8002006D)
        return D_0015CB84;
    if (code == 0x80020096)
        return D_0015CBA8;
    if (code == 0x80020097)
        return D_0015CBC4;
    if (code == 0x80020098)
        return D_0015CBE8;
    if (code == 0x80020099)
        return D_0015CC08;
    if (code == 0x8002009A)
        return D_0015CC2C;
    if (code == 0x8002009B)
        return D_0015CC48;
    if (code == 0x8002009C)
        return D_0015CC6C;
    if (code == 0x800200A0)
        return D_0015CC90;
    if (code == 0x800200A1)
        return D_0015CCAC;
    if (code == 0x800200A2)
        return D_0015CCC8;
    if (code == 0x800200C8)
        return D_0015CCE4;
    if (code == 0x800200C9)
        return D_0015CD04;
    if (code == 0x800200CA)
        return D_0015CD28;
    if (code == 0x800200CB)
        return D_0015CD4C;
    if (code == 0x800200CC)
        return D_0015CD6C;
    if (code == 0x800200CD)
        return D_0015CD90;
    if (code == 0x800200CE)
        return D_0015CDB0;
    if (code == 0x800200CF)
        return D_0015CDD4;
    if (code == 0x800200D0)
        return D_0015CDF8;
    if (code == 0x800200D1)
        return D_0015CE18;
    if (code == 0x800200D2)
        return D_0015CE38;
    if (code == 0x800200D3)
        return D_0015CE5C;
    if (code == 0x800200D4)
        return D_0015CE7C;
    if (code == 0x800200D5)
        return D_0015CE9C;
    if (code == 0x800200D6)
        return D_0015CEC0;
    if (code == 0x800200D7)
        return D_0015CEE4;
    if (code == 0x800200D8)
        return D_0015CF08;
    if (code == 0x800200D9)
        return D_0015CF30;
    if (code == 0x800200DA)
        return D_0015CF58;
    if (code == 0x800200DB)
        return D_0015CF80;
    if (code == 0x800200DC)
        return D_0015CFA8;
    if (code == 0x800200DD)
        return D_0015CFD0;
    if (code == 0x8002012C)
        return D_0015CFF4;
    if (code == 0x8002012D)
        return D_0015D010;
    if (code == 0x8002012E)
        return D_0015D030;
    if (code == 0x8002012F)
        return D_0015D050;
    if (code == 0x80020130)
        return D_0015D068;
    if (code == 0x80020131)
        return D_0015D084;
    if (code == 0x80020132)
        return D_0015D0A0;
    if (code == 0x80020133)
        return D_0015D0C4;
    if (code == 0x80020134)
        return D_0015D0E8;
    if (code == 0x80020135)
        return D_0015D108;
    if (code == 0x80020136)
        return D_0015D12C;
    if (code == 0x80020137)
        return D_0015D14C;
    if (code == 0x80020138)
        return D_0015D16C;
    if (code == 0x8002013A)
        return D_0015D18C;
    if (code == 0x8002013B)
        return D_0015D1B4;
    if (code == 0x8002013C)
        return D_0015D1D4;
    if (code == 0x8002013D)
        return D_0015D1F8;
    if (code == 0x8002013E)
        return D_0015D21C;
    if (code == 0x8002013F)
        return D_0015D23C;
    if (code == 0x80020140)
        return D_0015D260;
    if (code == 0x80020141)
        return D_0015D280;
    if (code == 0x80020142)
        return D_0015D2A4;
    if (code == 0x80020143)
        return D_0015D2C4;
    if (code == 0x80020144)
        return D_0015D2E8;
    if (code == 0x8002014B)
        return D_0015D308;
    if (code == 0x8002014C)
        return D_0015D334;
    if (code == 0x80020190)
        return D_0015D360;
    if (code == 0x80020191)
        return D_0015D37C;
    if (code == 0x80020192)
        return D_0015D39C;
    if (code == 0x80020193)
        return D_0015D3BC;
    if (code == 0x80020194)
        return D_0015D3E0;
    if (code == 0x80020195)
        return D_0015D404;
    if (code == 0x80020196)
        return D_0015D424;
    if (code == 0x80020197)
        return D_0015D444;
    if (code == 0x80020198)
        return D_0015D464;
    if (code == 0x80020199)
        return D_0015D484;
    if (code == 0x8002019A)
        return D_0015D4A4;
    if (code == 0x8002019B)
        return D_0015D4C4;
    if (code == 0x8002019C)
        return D_0015D4E4;
    if (code == 0x8002019D)
        return D_0015D504;
    if (code == 0x8002019E)
        return D_0015D524;
    if (code == 0x8002019F)
        return D_0015D544;
    if (code == 0x800201A0)
        return D_0015D564;
    if (code == 0x800201A1)
        return D_0015D584;
    if (code == 0x800201A2)
        return D_0015D5A4;
    if (code == 0x800201A3)
        return D_0015D5C0;
    if (code == 0x800201A4)
        return D_0015D5DC;
    if (code == 0x800201A5)
        return D_0015D5FC;
    if (code == 0x800201A6)
        return D_0015D61C;
    if (code == 0x800201A7)
        return D_0015D638;
    if (code == 0x800201A8)
        return D_0015D658;
    if (code == 0x800201A9)
        return D_0015D678;
    if (code == 0x800201AA)
        return D_0015D698;
    if (code == 0x800201AB)
        return D_0015D6B8;
    if (code == 0x800201AC)
        return D_0015D6DC;
    if (code == 0x800201AD)
        return D_0015D700;
    if (code == 0x800201AE)
        return D_0015D71C;
    if (code == 0x800201AF)
        return D_0015D738;
    if (code == 0x800201B0)
        return D_0015D754;
    if (code == 0x800201B1)
        return D_0015D770;
    if (code == 0x800201B2)
        return D_0015D78C;
    if (code == 0x800201B3)
        return D_0015D7A8;
    if (code == 0x800201B4)
        return D_0015D7C4;
    if (code == 0x800201B5)
        return D_0015D7E0;
    if (code == 0x800201B6)
        return D_0015D800;
    if (code == 0x800201B7)
        return D_0015D824;
    if (code == 0x800201B8)
        return D_0015D848;
    if (code == 0x800201B9)
        return D_0015D86C;
    if (code == 0x800201BA)
        return D_0015D888;
    if (code == 0x800201BB)
        return D_0015D8A8;
    if (code == 0x800201BC)
        return D_0015D8C8;
    if (code == 0x800201BD)
        return D_0015D8E8;
    if (code == 0x800201BE)
        return D_0015D908;
    if (code == 0x800201BF)
        return D_0015D928;
    if (code == 0x800201C0)
        return D_0015D948;
    if (code == 0x800201C1)
        return D_0015D968;
    if (code == 0x800201C2)
        return D_0015D984;
    if (code == 0x80020258)
        return D_0015D9A0;
    if (code == 0x80020259)
        return D_0015D9C8;
    if (code == 0x8002025A)
        return D_0015D9EC;
    if (code == 0x8002025B)
        return D_0015DA10;
    if (code == 0x8002025C)
        return D_0015DA38;
    if (code == 0x8002025D)
        return D_0015DA60;
    if (code == 0x8002025E)
        return D_0015DA88;
    if (code == 0x8002025F)
        return D_0015DAAC;
    if (code == 0x80020260)
        return D_0015DAD0;
    if (code == 0x80020261)
        return D_0015DAF4;
    if (code == 0x80020262)
        return D_0015DB18;
    if (code == 0x80020263)
        return D_0015DB3C;
    if (code == 0x80020264)
        return D_0015DB64;
    if (code == 0x80020265)
        return D_0015DB90;
    if (code == 0x80020266)
        return D_0015DBBC;
    if (code == 0x80020267)
        return D_0015DBEC;
    if (code == 0x800202BC)
        return D_0015DC18;
    if (code == 0x800202BD)
        return D_0015DC40;
    if (code == 0x800202BE)
        return D_0015DC68;
    if (code == 0x800202BF)
        return D_0015DC88;
    if (code == 0x800202C0)
        return D_0015DCAC;
    if (code == 0x800202C1)
        return D_0015DCD0;
    if (code == 0x800202C2)
        return D_0015DCF8;
    if (code == 0x800202C3)
        return D_0015DD1C;
    if (code == 0x800202C4)
        return D_0015DD3C;
    if (code == 0x800202C5)
        return D_0015DD5C;
    if (code == 0x800202C6)
        return D_0015DD7C;
    if (code == 0x800202C7)
        return D_0015DDA0;
    if (code == 0x800202C8)
        return D_0015DDC0;
    if (code == 0x800202C9)
        return D_0015DDE8;
    if (code == 0x800202CA)
        return D_0015DE10;
    if (code == 0x800202CB)
        return D_0015DE38;
    if (code == 0x800202CC)
        return D_0015DE60;
    if (code == 0x800202CD)
        return D_0015DE8C;
    if (code == 0x800202CE)
        return D_0015DEB4;
    if (code == 0x80020320)
        return D_0015DED8;
    if (code == 0x80020321)
        return D_0015DEF0;
    if (code == 0x80020322)
        return D_0015DF08;
    if (code == 0x80020323)
        return D_0015DF20;
    if (code == 0x80020324)
        return D_0015DF38;
    if (code == 0x80020325)
        return D_0015DF50;
    if (code == 0x80020326)
        return D_0015DF68;
    if (code == 0x80020327)
        return D_0015DF84;
    if (code == 0x80020328)
        return D_0015DFA4;
    if (code == 0x80020329)
        return D_0015DFC4;
    if (code == 0x8002032A)
        return D_0015DFE0;
    if (code == 0x8002032B)
        return D_0015DFFC;
    if (code == 0x8002032C)
        return D_0015E014;
    if (code == 0x8002032D)
        return D_0015E02C;
    if (code == 0x800203E8)
        return D_0015E04C;
    if (code == 0x800203E9)
        return D_0015E064;
    if (code == 0x800203EA)
        return D_0015E078;
    if (code == 0x800203EB)
        return D_0015E090;
    if (code == 0x8002044C)
        return D_0015E0B4;
    return D_0015E0D8;
}

common::File::File()
{
    handle = new Handle;
}

common::File::~File()
{
    if (is_open())
        close();
    delete handle;
}

bool common::File::is_open() const
{
    return handle->fd >= 0;
}

unsigned int common::File::write(const void *p, unsigned int size, unsigned int n)
{
    if (!is_open()) {
        FILE_ERROR(File_write_fn, D_0015E124);
        return 0;
    }
    int r = sceIoWrite(handle->fd, p, size * n);
    if (r >= 0)
        return r;
    if (r == (int)0x80020323) {
        FILE_ERROR(File_write_fn, D_0015E1A8);
    } else if (r == -22) {
        FILE_ERROR(File_write_fn, D_0015E190);
    } else if (r == -5) {
        FILE_ERROR(File_write_fn, D_0015E180);
    } else if (r == -28) {
        FILE_ERROR(File_write_fn, D_0015E15C);
    } else {
        FILE_ERROR(File_write_fn, D_0015E14C);
    }
    return 0;
}

unsigned int common::File::read(void *p, unsigned int size, unsigned int n)
{
    if (!is_open()) {
        FILE_ERROR(File_read_fn, D_0015E204);
        return 0;
    }
    int r = sceIoRead(handle->fd, p, n * size);
    sceKernelDcacheWritebackAll();
    if (r >= 0) {
        handle->pos += r;
        return r;
    }
    if (r == (int)0x80020323) {
        FILE_ERROR(File_read_fn, D_0015E238);
    } else if (r == -22) {
        FILE_ERROR(File_read_fn, D_0015E190);
    } else {
        FILE_ERROR(File_read_fn, D_0015E14C);
        std::cout << D_0015E228 << r << D_0015E148;
    }
    ::puts(D_0015E230);
    return 0;
}

extern "C" int sceIoOpen(const char *file, int flags, int mode);
extern "C" const char D_0015E28C[], D_0015E2AC[], D_0015E2B0[], D_0015E2B4[], D_0015E2B8[];
extern const char File_open_fn[] __asm__("_ZZN6common4File4openEPKcS2_E19__PRETTY_FUNCTION__");
bool common::File::open(const char *name, const char *mode)
{
    int flags = 0;
    std::string path(D_0015E28C);
    path += name;
    std::string m(mode);
    bool r = m.find_first_of(D_0015E2AC) != std::string::npos;
    bool a = m.find_first_of(D_0015E2B0) != std::string::npos;
    bool w = m.find_first_of(D_0015E2B4) != std::string::npos || a;
    bool plus = m.find_first_of(D_0015E2B8) != std::string::npos;
    if (r && !w)
        flags = 1;
    else if (!r && w)
        flags = 2;
    else if (r && w)
        flags = 3;
    if (plus)
        flags |= a ? 0x300 : 0x600;
    *handle = Handle();
    handle->fd = sceIoOpen(path.c_str(), flags, 0);
    if (handle->fd < 0) {
        const char *e = psp::GetKernelErrName(handle->fd);
        if (*e) {
            FILE_ERROR(File_open_fn, e);
        } else {
            FILE_ERROR(File_open_fn, D_0015E2BC);
        }
    }
    return is_open();
}

int common::File::flush()
{
    return 0;
}

bool common::File::close()
{
    if (!is_open()) {
        FILE_ERROR(File_close_fn, D_0015E2F0);
        return false;
    }
    if (sceIoClose(handle->fd) == (int)0x80020323) {
        FILE_ERROR(File_close_fn, D_0015E1A8);
        return false;
    }
    *handle = Handle();
    return true;
}

bool common::File::puts(const char *s)
{
    if (!is_open()) {
        FILE_ERROR(File_puts_fn, D_0015E33C);
        return false;
    }
    return write(s, 1, __builtin_strlen(s)) != 0;
}

bool common::File::getc(char &c)
{
    if (!is_open()) {
        FILE_ERROR(File_getc_fn, D_0015E380);
        return false;
    }
    seek(handle->pos, (Pos)1);
    return read(&c, 1, 1) != 0;
}

long common::File::bytesize()
{
    if (!is_open()) {
        FILE_ERROR(File_bytesize_fn, D_0015E3C4);
        return 0;
    }
    long pos = handle->pos;
    seek(0, (Pos)0);
    long size = tell();
    seek(pos, (Pos)1);
    return size;
}

long common::File::tell()
{
    if (!is_open()) {
        FILE_ERROR(File_tell_fn, D_0015E40C);
        return 0;
    }
    return handle->pos;
}

bool common::File::seek(long off, Pos p)
{
    if (!is_open()) {
        FILE_ERROR(File_seek_fn, D_0015E470);
        return false;
    }
    long long r = sceIoLseek(handle->fd, off, File_seek_POS_TAB[p]);
    if (r >= 0) {
        handle->pos = r;
        return true;
    }
    const char *e = psp::GetKernelErrName(r);
    if (*e) {
        FILE_ERROR(File_seek_fn, e);
    } else {
        FILE_ERROR(File_seek_fn, D_0015E2BC);
    }
    return false;
}
