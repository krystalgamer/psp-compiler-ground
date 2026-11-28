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
extern "C" const char D_00160BC8[], D_00160BF0[], D_00160C00[], D_00160C24[], D_00160C34[], D_00160CA8[], D_00160CCC[];
extern "C" const char D_00160CD4[], D_00160CDC[];
extern const char File_write_fn[] __asm__("_ZZN6common4File5writeEPKvjjE19__PRETTY_FUNCTION__");
extern const char File_read_fn[] __asm__("_ZZN6common4File4readEPvjjE19__PRETTY_FUNCTION__");
extern "C" const char D_00160BC4[], D_00160BEC[], D_00160C4C[], D_00160D60[], D_00160D94[], D_00160DE0[], D_00160E24[];
extern "C" const char D_00160E68[], D_00160EB0[], D_00160F14[];
extern const char File_close_fn[] __asm__("_ZZN6common4File5closeEvE19__PRETTY_FUNCTION__");
extern const char File_puts_fn[] __asm__("_ZZN6common4File4putsEPKcE19__PRETTY_FUNCTION__");
extern const char File_getc_fn[] __asm__("_ZZN6common4File4getcERcE19__PRETTY_FUNCTION__");
extern const char File_bytesize_fn[] __asm__("_ZZN6common4File8bytesizeEvE19__PRETTY_FUNCTION__");
extern const char File_tell_fn[] __asm__("_ZZN6common4File4tellEvE19__PRETTY_FUNCTION__");
extern const char File_seek_fn[] __asm__("_ZZN6common4File4seekElNS0_3PosEE19__PRETTY_FUNCTION__");
extern const int File_seek_POS_TAB[] __asm__("_ZZN6common4File4seekElNS0_3PosEE7POS_TAB");
extern "C" const char D_0015F370[], D_0015F384[], D_0015F39C[], D_0015F3B4[], D_0015F3D8[], D_0015F3FC[], D_0015F420[], D_0015F444[], D_0015F468[], D_0015F490[], D_0015F4C0[], D_0015F4F0[], D_0015F514[], D_0015F538[], D_0015F550[], D_0015F570[], D_0015F594[], D_0015F5B8[], D_0015F5DC[], D_0015F600[], D_0015F628[], D_0015F64C[], D_0015F668[], D_0015F68C[], D_0015F6AC[], D_0015F6D0[], D_0015F6EC[], D_0015F710[], D_0015F734[], D_0015F750[], D_0015F76C[], D_0015F788[], D_0015F7A8[], D_0015F7CC[], D_0015F7F0[], D_0015F810[], D_0015F834[], D_0015F854[], D_0015F878[], D_0015F89C[], D_0015F8BC[], D_0015F8DC[], D_0015F900[], D_0015F920[], D_0015F940[], D_0015F964[], D_0015F988[], D_0015F9AC[], D_0015F9D4[], D_0015F9FC[], D_0015FA24[], D_0015FA4C[], D_0015FA74[], D_0015FA98[], D_0015FAB4[], D_0015FAD4[], D_0015FAF4[], D_0015FB0C[], D_0015FB28[], D_0015FB44[], D_0015FB68[], D_0015FB8C[], D_0015FBAC[], D_0015FBD0[], D_0015FBF0[], D_0015FC10[], D_0015FC30[], D_0015FC58[], D_0015FC78[], D_0015FC9C[], D_0015FCC0[], D_0015FCE0[], D_0015FD04[], D_0015FD24[], D_0015FD48[], D_0015FD68[], D_0015FD8C[], D_0015FDAC[], D_0015FDD8[], D_0015FE04[], D_0015FE20[], D_0015FE40[], D_0015FE60[], D_0015FE84[], D_0015FEA8[], D_0015FEC8[], D_0015FEE8[], D_0015FF08[], D_0015FF28[], D_0015FF48[], D_0015FF68[], D_0015FF88[], D_0015FFA8[], D_0015FFC8[], D_0015FFE8[], D_00160008[], D_00160028[], D_00160048[], D_00160064[], D_00160080[], D_001600A0[], D_001600C0[], D_001600DC[], D_001600FC[], D_0016011C[], D_0016013C[], D_0016015C[], D_00160180[], D_001601A4[], D_001601C0[], D_001601DC[], D_001601F8[], D_00160214[], D_00160230[], D_0016024C[], D_00160268[], D_00160284[], D_001602A4[], D_001602C8[], D_001602EC[], D_00160310[], D_0016032C[], D_0016034C[], D_0016036C[], D_0016038C[], D_001603AC[], D_001603CC[], D_001603EC[], D_0016040C[], D_00160428[], D_00160444[], D_0016046C[], D_00160490[], D_001604B4[], D_001604DC[], D_00160504[], D_0016052C[], D_00160550[], D_00160574[], D_00160598[], D_001605BC[], D_001605E0[], D_00160608[], D_00160634[], D_00160660[], D_00160690[], D_001606BC[], D_001606E4[], D_0016070C[], D_0016072C[], D_00160750[], D_00160774[], D_0016079C[], D_001607C0[], D_001607E0[], D_00160800[], D_00160820[], D_00160844[], D_00160864[], D_0016088C[], D_001608B4[], D_001608DC[], D_00160904[], D_00160930[], D_00160958[], D_0016097C[], D_00160994[], D_001609AC[], D_001609C4[], D_001609DC[], D_001609F4[], D_00160A0C[], D_00160A28[], D_00160A48[], D_00160A68[], D_00160A84[], D_00160AA0[], D_00160AB8[], D_00160AD0[], D_00160AF0[], D_00160B08[], D_00160B1C[], D_00160B34[], D_00160B58[], D_00160B7C[];
#define FILE_ERROR(fn, msg) std::cout << fn << D_00160BC4 << msg << D_00160BEC; std::cout.flush()

const char *psp::GetKernelErrName(unsigned int code)
{
    if (code == 0)
        return D_0015F370;
    if (code == 0x80020001)
        return D_0015F384;
    if (code == 0x80020002)
        return D_0015F39C;
    if (code == 0x80020032)
        return D_0015F3B4;
    if (code == 0x80020033)
        return D_0015F3D8;
    if (code == 0x80020034)
        return D_0015F3FC;
    if (code == 0x80020035)
        return D_0015F420;
    if (code == 0x80020036)
        return D_0015F444;
    if (code == 0x80020037)
        return D_0015F468;
    if (code == 0x80020038)
        return D_0015F490;
    if (code == 0x80020039)
        return D_0015F4C0;
    if (code == 0x80020064)
        return D_0015F4F0;
    if (code == 0x80020065)
        return D_0015F514;
    if (code == 0x80020066)
        return D_0015F538;
    if (code == 0x80020067)
        return D_0015F550;
    if (code == 0x80020068)
        return D_0015F570;
    if (code == 0x80020069)
        return D_0015F594;
    if (code == 0x8002006A)
        return D_0015F5B8;
    if (code == 0x8002006B)
        return D_0015F5DC;
    if (code == 0x8002006C)
        return D_0015F600;
    if (code == 0x8002006D)
        return D_0015F628;
    if (code == 0x80020096)
        return D_0015F64C;
    if (code == 0x80020097)
        return D_0015F668;
    if (code == 0x80020098)
        return D_0015F68C;
    if (code == 0x80020099)
        return D_0015F6AC;
    if (code == 0x8002009A)
        return D_0015F6D0;
    if (code == 0x8002009B)
        return D_0015F6EC;
    if (code == 0x8002009C)
        return D_0015F710;
    if (code == 0x800200A0)
        return D_0015F734;
    if (code == 0x800200A1)
        return D_0015F750;
    if (code == 0x800200A2)
        return D_0015F76C;
    if (code == 0x800200C8)
        return D_0015F788;
    if (code == 0x800200C9)
        return D_0015F7A8;
    if (code == 0x800200CA)
        return D_0015F7CC;
    if (code == 0x800200CB)
        return D_0015F7F0;
    if (code == 0x800200CC)
        return D_0015F810;
    if (code == 0x800200CD)
        return D_0015F834;
    if (code == 0x800200CE)
        return D_0015F854;
    if (code == 0x800200CF)
        return D_0015F878;
    if (code == 0x800200D0)
        return D_0015F89C;
    if (code == 0x800200D1)
        return D_0015F8BC;
    if (code == 0x800200D2)
        return D_0015F8DC;
    if (code == 0x800200D3)
        return D_0015F900;
    if (code == 0x800200D4)
        return D_0015F920;
    if (code == 0x800200D5)
        return D_0015F940;
    if (code == 0x800200D6)
        return D_0015F964;
    if (code == 0x800200D7)
        return D_0015F988;
    if (code == 0x800200D8)
        return D_0015F9AC;
    if (code == 0x800200D9)
        return D_0015F9D4;
    if (code == 0x800200DA)
        return D_0015F9FC;
    if (code == 0x800200DB)
        return D_0015FA24;
    if (code == 0x800200DC)
        return D_0015FA4C;
    if (code == 0x800200DD)
        return D_0015FA74;
    if (code == 0x8002012C)
        return D_0015FA98;
    if (code == 0x8002012D)
        return D_0015FAB4;
    if (code == 0x8002012E)
        return D_0015FAD4;
    if (code == 0x8002012F)
        return D_0015FAF4;
    if (code == 0x80020130)
        return D_0015FB0C;
    if (code == 0x80020131)
        return D_0015FB28;
    if (code == 0x80020132)
        return D_0015FB44;
    if (code == 0x80020133)
        return D_0015FB68;
    if (code == 0x80020134)
        return D_0015FB8C;
    if (code == 0x80020135)
        return D_0015FBAC;
    if (code == 0x80020136)
        return D_0015FBD0;
    if (code == 0x80020137)
        return D_0015FBF0;
    if (code == 0x80020138)
        return D_0015FC10;
    if (code == 0x8002013A)
        return D_0015FC30;
    if (code == 0x8002013B)
        return D_0015FC58;
    if (code == 0x8002013C)
        return D_0015FC78;
    if (code == 0x8002013D)
        return D_0015FC9C;
    if (code == 0x8002013E)
        return D_0015FCC0;
    if (code == 0x8002013F)
        return D_0015FCE0;
    if (code == 0x80020140)
        return D_0015FD04;
    if (code == 0x80020141)
        return D_0015FD24;
    if (code == 0x80020142)
        return D_0015FD48;
    if (code == 0x80020143)
        return D_0015FD68;
    if (code == 0x80020144)
        return D_0015FD8C;
    if (code == 0x8002014B)
        return D_0015FDAC;
    if (code == 0x8002014C)
        return D_0015FDD8;
    if (code == 0x80020190)
        return D_0015FE04;
    if (code == 0x80020191)
        return D_0015FE20;
    if (code == 0x80020192)
        return D_0015FE40;
    if (code == 0x80020193)
        return D_0015FE60;
    if (code == 0x80020194)
        return D_0015FE84;
    if (code == 0x80020195)
        return D_0015FEA8;
    if (code == 0x80020196)
        return D_0015FEC8;
    if (code == 0x80020197)
        return D_0015FEE8;
    if (code == 0x80020198)
        return D_0015FF08;
    if (code == 0x80020199)
        return D_0015FF28;
    if (code == 0x8002019A)
        return D_0015FF48;
    if (code == 0x8002019B)
        return D_0015FF68;
    if (code == 0x8002019C)
        return D_0015FF88;
    if (code == 0x8002019D)
        return D_0015FFA8;
    if (code == 0x8002019E)
        return D_0015FFC8;
    if (code == 0x8002019F)
        return D_0015FFE8;
    if (code == 0x800201A0)
        return D_00160008;
    if (code == 0x800201A1)
        return D_00160028;
    if (code == 0x800201A2)
        return D_00160048;
    if (code == 0x800201A3)
        return D_00160064;
    if (code == 0x800201A4)
        return D_00160080;
    if (code == 0x800201A5)
        return D_001600A0;
    if (code == 0x800201A6)
        return D_001600C0;
    if (code == 0x800201A7)
        return D_001600DC;
    if (code == 0x800201A8)
        return D_001600FC;
    if (code == 0x800201A9)
        return D_0016011C;
    if (code == 0x800201AA)
        return D_0016013C;
    if (code == 0x800201AB)
        return D_0016015C;
    if (code == 0x800201AC)
        return D_00160180;
    if (code == 0x800201AD)
        return D_001601A4;
    if (code == 0x800201AE)
        return D_001601C0;
    if (code == 0x800201AF)
        return D_001601DC;
    if (code == 0x800201B0)
        return D_001601F8;
    if (code == 0x800201B1)
        return D_00160214;
    if (code == 0x800201B2)
        return D_00160230;
    if (code == 0x800201B3)
        return D_0016024C;
    if (code == 0x800201B4)
        return D_00160268;
    if (code == 0x800201B5)
        return D_00160284;
    if (code == 0x800201B6)
        return D_001602A4;
    if (code == 0x800201B7)
        return D_001602C8;
    if (code == 0x800201B8)
        return D_001602EC;
    if (code == 0x800201B9)
        return D_00160310;
    if (code == 0x800201BA)
        return D_0016032C;
    if (code == 0x800201BB)
        return D_0016034C;
    if (code == 0x800201BC)
        return D_0016036C;
    if (code == 0x800201BD)
        return D_0016038C;
    if (code == 0x800201BE)
        return D_001603AC;
    if (code == 0x800201BF)
        return D_001603CC;
    if (code == 0x800201C0)
        return D_001603EC;
    if (code == 0x800201C1)
        return D_0016040C;
    if (code == 0x800201C2)
        return D_00160428;
    if (code == 0x80020258)
        return D_00160444;
    if (code == 0x80020259)
        return D_0016046C;
    if (code == 0x8002025A)
        return D_00160490;
    if (code == 0x8002025B)
        return D_001604B4;
    if (code == 0x8002025C)
        return D_001604DC;
    if (code == 0x8002025D)
        return D_00160504;
    if (code == 0x8002025E)
        return D_0016052C;
    if (code == 0x8002025F)
        return D_00160550;
    if (code == 0x80020260)
        return D_00160574;
    if (code == 0x80020261)
        return D_00160598;
    if (code == 0x80020262)
        return D_001605BC;
    if (code == 0x80020263)
        return D_001605E0;
    if (code == 0x80020264)
        return D_00160608;
    if (code == 0x80020265)
        return D_00160634;
    if (code == 0x80020266)
        return D_00160660;
    if (code == 0x80020267)
        return D_00160690;
    if (code == 0x800202BC)
        return D_001606BC;
    if (code == 0x800202BD)
        return D_001606E4;
    if (code == 0x800202BE)
        return D_0016070C;
    if (code == 0x800202BF)
        return D_0016072C;
    if (code == 0x800202C0)
        return D_00160750;
    if (code == 0x800202C1)
        return D_00160774;
    if (code == 0x800202C2)
        return D_0016079C;
    if (code == 0x800202C3)
        return D_001607C0;
    if (code == 0x800202C4)
        return D_001607E0;
    if (code == 0x800202C5)
        return D_00160800;
    if (code == 0x800202C6)
        return D_00160820;
    if (code == 0x800202C7)
        return D_00160844;
    if (code == 0x800202C8)
        return D_00160864;
    if (code == 0x800202C9)
        return D_0016088C;
    if (code == 0x800202CA)
        return D_001608B4;
    if (code == 0x800202CB)
        return D_001608DC;
    if (code == 0x800202CC)
        return D_00160904;
    if (code == 0x800202CD)
        return D_00160930;
    if (code == 0x800202CE)
        return D_00160958;
    if (code == 0x80020320)
        return D_0016097C;
    if (code == 0x80020321)
        return D_00160994;
    if (code == 0x80020322)
        return D_001609AC;
    if (code == 0x80020323)
        return D_001609C4;
    if (code == 0x80020324)
        return D_001609DC;
    if (code == 0x80020325)
        return D_001609F4;
    if (code == 0x80020326)
        return D_00160A0C;
    if (code == 0x80020327)
        return D_00160A28;
    if (code == 0x80020328)
        return D_00160A48;
    if (code == 0x80020329)
        return D_00160A68;
    if (code == 0x8002032A)
        return D_00160A84;
    if (code == 0x8002032B)
        return D_00160AA0;
    if (code == 0x8002032C)
        return D_00160AB8;
    if (code == 0x8002032D)
        return D_00160AD0;
    if (code == 0x800203E8)
        return D_00160AF0;
    if (code == 0x800203E9)
        return D_00160B08;
    if (code == 0x800203EA)
        return D_00160B1C;
    if (code == 0x800203EB)
        return D_00160B34;
    if (code == 0x8002044C)
        return D_00160B58;
    return D_00160B7C;
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
        FILE_ERROR(File_write_fn, D_00160BC8);
        return 0;
    }
    int r = sceIoWrite(handle->fd, p, size * n);
    if (r >= 0)
        return r;
    if (r == (int)0x80020323) {
        FILE_ERROR(File_write_fn, D_00160C4C);
    } else if (r == -22) {
        FILE_ERROR(File_write_fn, D_00160C34);
    } else if (r == -5) {
        FILE_ERROR(File_write_fn, D_00160C24);
    } else if (r == -28) {
        FILE_ERROR(File_write_fn, D_00160C00);
    } else {
        FILE_ERROR(File_write_fn, D_00160BF0);
    }
    return 0;
}

unsigned int common::File::read(void *p, unsigned int size, unsigned int n)
{
    if (!is_open()) {
        FILE_ERROR(File_read_fn, D_00160CA8);
        return 0;
    }
    int r = sceIoRead(handle->fd, p, n * size);
    sceKernelDcacheWritebackAll();
    if (r >= 0) {
        handle->pos += r;
        return r;
    }
    if (r == (int)0x80020323) {
        FILE_ERROR(File_read_fn, D_00160CDC);
    } else if (r == -22) {
        FILE_ERROR(File_read_fn, D_00160C34);
    } else {
        FILE_ERROR(File_read_fn, D_00160BF0);
        std::cout << D_00160CCC << r << D_00160BEC;
    }
    ::puts(D_00160CD4);
    return 0;
}

extern "C" int sceIoOpen(const char *file, int flags, int mode);
extern "C" const char D_00160D30[], D_00160D50[], D_00160D54[], D_00160D58[], D_00160D5C[];
extern const char File_open_fn[] __asm__("_ZZN6common4File4openEPKcS2_E19__PRETTY_FUNCTION__");
bool common::File::open(const char *name, const char *mode)
{
    int flags = 0;
    std::string path(D_00160D30);
    path += name;
    std::string m(mode);
    bool r = m.find_first_of(D_00160D50) != std::string::npos;
    bool a = m.find_first_of(D_00160D54) != std::string::npos;
    bool w = m.find_first_of(D_00160D58) != std::string::npos || a;
    bool plus = m.find_first_of(D_00160D5C) != std::string::npos;
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
            FILE_ERROR(File_open_fn, D_00160D60);
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
        FILE_ERROR(File_close_fn, D_00160D94);
        return false;
    }
    if (sceIoClose(handle->fd) == (int)0x80020323) {
        FILE_ERROR(File_close_fn, D_00160C4C);
        return false;
    }
    *handle = Handle();
    return true;
}

bool common::File::puts(const char *s)
{
    if (!is_open()) {
        FILE_ERROR(File_puts_fn, D_00160DE0);
        return false;
    }
    return write(s, 1, __builtin_strlen(s)) != 0;
}

bool common::File::getc(char &c)
{
    if (!is_open()) {
        FILE_ERROR(File_getc_fn, D_00160E24);
        return false;
    }
    seek(handle->pos, (Pos)1);
    return read(&c, 1, 1) != 0;
}

long common::File::bytesize()
{
    if (!is_open()) {
        FILE_ERROR(File_bytesize_fn, D_00160E68);
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
        FILE_ERROR(File_tell_fn, D_00160EB0);
        return 0;
    }
    return handle->pos;
}

bool common::File::seek(long off, Pos p)
{
    if (!is_open()) {
        FILE_ERROR(File_seek_fn, D_00160F14);
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
        FILE_ERROR(File_seek_fn, D_00160D60);
    }
    return false;
}
