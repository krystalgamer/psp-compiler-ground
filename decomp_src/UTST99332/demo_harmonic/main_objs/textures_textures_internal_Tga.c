/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#define DEMO_LINKONCE_Tga 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN8textures17textures_internal3Tga4loadEPKc");
__asm__(".globl _GLOBAL__D__ZN8textures17textures_internal3Tga4loadEPKc");

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN8textures17textures_internal3TgaD1Ev)
    DEMO_LINKONCE(_ZN8textures17textures_internal3TgaD0Ev)
    DEMO_LINKONCE(_ZN10byte_array4readIhEEvjRT_)
    DEMO_LINKONCE(_ZN10byte_array5writeIhEEvjT_)
);

/* the strings stay in the module's .rodata (asm) */
extern const char D_001744C4[];     /* " *** error " */
extern const char D_00174500[];     /* " " */
extern const char D_00174584[];     /* "_Offset + sizeof(T) <= _size" */
extern const char D_001745A4[];     /* "../lib/textures/byte_array.h" */
#define TGA_ASSERT(c, s, file, fn, line) \
    do if (!(c)) { \
        common::common_internal::assert_display(D_001744C4, s, file, fn, line, D_00174500); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    } while (0)

/* lib/textures/byte_array.h */
template<class T> struct ByteArrayNames {
    static const char read[], write[];
};
template<> const char ByteArrayNames<unsigned char>::read[] __asm__("_ZZN10byte_array4readIhEEvjRT_E19__PRETTY_FUNCTION__");
template<> const char ByteArrayNames<unsigned short>::read[] __asm__("_ZZN10byte_array4readItEEvjRT_E19__PRETTY_FUNCTION___1745C4");
template<> const char ByteArrayNames<unsigned char>::write[] __asm__("_ZZN10byte_array5writeIhEEvjT_E19__PRETTY_FUNCTION__");
class byte_array {
public:
    byte_array(unsigned char *_Data, unsigned int _Size) : _data(_Data), _size(_Size) {}
    template<class T> void read(unsigned int _Offset, T &_Value);
    template<class T> void write(unsigned int _Offset, T _Value);
    unsigned char *_data;
    unsigned int _size;
};

int textures::textures_internal::Tga::load(const char *name)
{
    blocking(false);
    if (common::FileDump::load(name) < 0)
        return load_error(CANT_OPEN, name);
    byte_array b((unsigned char *)_ptr, 0);
    b.read(0, _id_length);
    b.read(1, _colormap_type);
    b.read(2, _image_type);
    b.read(3, _cmap_first);
    b.read(5, _cmap_length);
    b.read(7, _cmap_depth);
    b.read(8, _x_origin);
    b.read(10, _y_origin);
    b.read(12, _width);
    b.read(14, _height);
    b.read(16, _pixel_depth);
    b.read(17, _descriptor);
    _alpha_bits = _descriptor & 0xF;
    _origin = (_descriptor >> 4) & 3;
    int offset = 18;
    if (_id_length) {
        offset = _id_length + 18;
        _id = _ptr + 18;
    }
    if (_colormap_type) {
        _colormap = _ptr + offset;
        offset += (_cmap_length * _cmap_depth) >> 3;
        if (_cmap_depth != 8 && _cmap_depth != 16 && _cmap_depth != 24 && _cmap_depth != 32)
            return load_error(WRONG_FORMAT, name);
    }
    if (_pixel_depth != 8 && _pixel_depth != 16 && _pixel_depth != 24 && _pixel_depth != 32)
        return load_error(WRONG_FORMAT, name);
    if (_image_type == 1 && _colormap_type != 1)
        return load_error(WRONG_FORMAT_COLOR_MAPPED, name);
    if (_image_type == 2 && _colormap_type != 0)
        return load_error(WRONG_FORMAT_TRUE_COLOR, name);
    if (_image_type == 3 && _colormap_type != 0)
        return load_error(WRONG_FORMAT_BLACK_AND_WHITE, name);
    if (_image_type == 9) {
        if (_colormap_type != 1)
            return load_error(WRONG_FORMAT_RLE_COLOR_MAPPED, name);
        return load_error(NON_IMPLEMENTED_RLE_COLOR_MAPPED, name);
    }
    if (_image_type == 10) {
        if (_colormap_type != 0)
            return load_error(WRONG_FORMAT_RLE_TRUE_COLOR, name);
        return load_error(NON_IMPLEMENTED_RLE_TRUE_COLOR, name);
    }
    if (_image_type == 11) {
        if (_colormap_type != 0)
            return load_error(WRONG_FORMAT_RLE_BLACK_AND_WHITE, name);
        return load_error(NON_IMPLEMENTED_RLE_BLACK_AND_WHITE, name);
    }
    _pixels = _ptr + offset;
    return 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures17textures_internal3Tga10load_errorENS1_5ErrorEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures7SaveTgaEPKciiPKhi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures12SaveGlBufferEPKci);

void textures::TgaSnapshot(const char *name)
{
    SaveGlBuffer(name, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN8textures20TgaAutoNamedSnapshotEPKc);

template<class T> void byte_array::read(unsigned int _Offset, T &_Value)
{
    TGA_ASSERT(_size == 0 || _Offset + sizeof(T) <= _size, D_00174584, D_001745A4, ByteArrayNames<T>::read, 41);
    __builtin_memcpy(&_Value, _data + _Offset, sizeof(T));
}

template<class T> void byte_array::write(unsigned int _Offset, T _Value)
{
    TGA_ASSERT(_size == 0 || _Offset + sizeof(T) <= _size, D_00174584, D_001745A4, ByteArrayNames<T>::write, 30);
    __builtin_memcpy(_data + _Offset, &_Value, sizeof(T));
}

/* out-of-line instances that stay asm: write<unsigned char> is a near-miss (the original zero-extends
   the parameter (andi 0xff) before spilling it for the memcpy) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/textures_textures_internal_Tga", _ZN10byte_array5writeIhEEvjT_);
