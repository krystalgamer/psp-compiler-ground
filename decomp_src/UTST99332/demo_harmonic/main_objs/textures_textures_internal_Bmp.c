/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_LINKONCE_Bmp 1
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN8textures17textures_internal3BmpD1Ev)
    DEMO_LINKONCE(_ZN8textures17textures_internal3BmpD0Ev)
    DEMO_LINKONCE(_ZN10byte_array4readIiEEvjRT_)
    DEMO_LINKONCE(_ZN10byte_array4readItEEvjRT_)
    DEMO_LINKONCE(_ZN6common7t_arrayIhEC1Ev)
    DEMO_LINKONCE(_ZN10byte_array5writeIcEEvjT_)
    DEMO_LINKONCE(_ZN10byte_array5writeIiEEvjT_)
    DEMO_LINKONCE(_ZN10byte_array5writeIsEEvjT_)
);

/* the strings stay in the module's .rodata (asm) */
extern const char D_00172FC4[];     /* " *** error " */
extern const char D_00172FD0[];     /* "_data_offset - 54 == 0" */
extern const char D_00172FE8[];     /* "../lib/textures/Bmp.cpp" */
extern const char D_00173000[];     /* " " */
extern const char D_00173048[];     /* "( ( retval / 4 ) * 4 ) == retval" */
extern const char D_0017306C[];     /* "retval >= 0" */
extern const char D_001730B0[];     /* "_Offset + sizeof(T) <= _size" */
extern const char D_001730D0[];     /* "../lib/textures/byte_array.h" */
extern const char Bmp_load_name[] __asm__("_ZZN8textures17textures_internal3Bmp4loadEPKcE19__PRETTY_FUNCTION__");
extern const char Bmp_npe_name[] __asm__("_ZZNK8textures17textures_internal3Bmp19num_palette_entriesEvE19__PRETTY_FUNCTION__");
#define BMP_ASSERT(c, s, file, fn, line) \
    do if (!(c)) { \
        common::common_internal::assert_display(D_00172FC4, s, file, fn, line, D_00173000); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    } while (0)

/* lib/textures/byte_array.h */
template<class T> struct ByteArrayNames {
    static const char read[], write[];
};
template<> const char ByteArrayNames<int>::read[] __asm__("_ZZN10byte_array4readIiEEvjRT_E19__PRETTY_FUNCTION__");
template<> const char ByteArrayNames<unsigned short>::read[] __asm__("_ZZN10byte_array4readItEEvjRT_E19__PRETTY_FUNCTION___1730F0");
template<> const char ByteArrayNames<char>::write[] __asm__("_ZZN10byte_array5writeIcEEvjT_E19__PRETTY_FUNCTION__");
template<> const char ByteArrayNames<int>::write[] __asm__("_ZZN10byte_array5writeIiEEvjT_E19__PRETTY_FUNCTION__");
template<> const char ByteArrayNames<short>::write[] __asm__("_ZZN10byte_array5writeIsEEvjT_E19__PRETTY_FUNCTION___1731A8");
class byte_array {
public:
    byte_array(unsigned char *_Data, unsigned int _Size) : _data(_Data), _size(_Size) {}
    template<class T> void read(unsigned int _Offset, T &_Value);
    template<class T> void write(unsigned int _Offset, T _Value);
    unsigned char *_data;
    unsigned int _size;
};

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Bmp", _Z41__static_initialization_and_destruction_0ii_FB674);

int textures::textures_internal::Bmp::load(const char *name)
{
    blocking(false);
    if (common::FileDump::load(name) < 0)
        return -1;
    byte_array b((unsigned char *)_ptr, 0);
    b.read(10, _data_offset);
    b.read(18, _width);
    b.read(22, _height);
    b.read(28, _bpp);
    switch (_bpp) {
    case 16:
    case 24:
        BMP_ASSERT(_data_offset - 54 == 0, D_00172FD0, D_00172FE8, Bmp_load_name, 62);
        break;
    }
    _palette = _ptr + 54;
    _pixels = _ptr + _data_offset;
    return 0;
}

int textures::textures_internal::Bmp::num_palette_entries() const
{
    int retval = _data_offset - 54;
    BMP_ASSERT(((retval / 4) * 4) == retval, D_00173048, D_00172FE8, Bmp_npe_name, 76);
    BMP_ASSERT(retval >= 0, D_0017306C, D_00172FE8, Bmp_npe_name, 77);
    return retval / 4;
}

int textures::textures_internal::Bmp::Get4idxPixel(const unsigned char *data, int stride, int x, int y)
{
    unsigned char c = data[stride * y + x / 2];
    return (x & 1) ? c & 0xF : c >> 4;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Bmp", _ZN8textures7SaveBmpEPKciiPKhS3_i);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_FB674");
void _GLOBAL__I__ZN8textures17textures_internal3Bmp4loadEPKc(void);
void _GLOBAL__D__ZN8textures17textures_internal3Bmp4loadEPKc(void);
}

void _GLOBAL__I__ZN8textures17textures_internal3Bmp4loadEPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN8textures17textures_internal3Bmp4loadEPKc(void)
{
    static_init(0, 0xFFFF);
}

template<class T> void byte_array::read(unsigned int _Offset, T &_Value)
{
    BMP_ASSERT(_size == 0 || _Offset + sizeof(T) <= _size, D_001730B0, D_001730D0, ByteArrayNames<T>::read, 41);
    __builtin_memcpy(&_Value, _data + _Offset, sizeof(T));
}

template<class T> void byte_array::write(unsigned int _Offset, T _Value)
{
    BMP_ASSERT(_size == 0 || _Offset + sizeof(T) <= _size, D_001730B0, D_001730D0, ByteArrayNames<T>::write, 30);
    __builtin_memcpy(_data + _Offset, &_Value, sizeof(T));
}

/* SaveBmp (asm) uses these instances; write<char>/write<short> stay asm (near-miss: the original
   sign-extends the char/short parameter (seb/seh) before spilling it for the memcpy) */
void textures_internal_Bmp_uses() __attribute__((section(".discard.instances")));
void textures_internal_Bmp_uses()
{
    byte_array b(0, 0);
    b.write(0, (int)0);
}

/* out-of-line instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

/* common::t_array<unsigned char>'s default ctor (SaveBmp, still asm, is its user) */
template common::t_array<unsigned char>::t_array();

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Bmp", _ZN10byte_array5writeIcEEvjT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Bmp", _ZN10byte_array5writeIsEEvjT_);
