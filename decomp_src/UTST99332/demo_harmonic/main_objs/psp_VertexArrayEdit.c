/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* before main.hpp's `#pragma interface`: std::dec/std::hex (used by address) are emitted here */
#include <ios>
#include <iostream>
#include "../main.hpp"

extern const char D_0015F9F8[], D_0015FA08[], D_0015F2A0[], D_0015EA40[], D_0015EA04[];
#define NOT_IMPLEMENTED 0
extern const char D_0015E9A4[], D_0015EA08[], D_0015EA20[], D_0015ECC0[], D_0015ED50[], D_0015EEE8[], D_0015EEF4[];
extern const char D_0015EF50[], D_0015EF9C[], D_0015EFB8[], D_0015EFDC[], D_0015F004[];
extern const char PF_set_mask[] __asm__("_ZZN3psp11VertexArray8set_maskEjE19__PRETTY_FUNCTION__");
extern const char PF_getBit[] __asm__("_ZZNK3psp15VertexArrayEdit10Descriptor6getBitENS0_7BitEnumEE19__PRETTY_FUNCTION__");
extern const char PF_Descriptor[] __asm__("_ZZN3psp15VertexArrayEdit10DescriptorC1EjE19__PRETTY_FUNCTION__");
extern const char PF_setFormat[] __asm__("_ZZN3psp15VertexArrayEdit10Descriptor9setFormatEjE19__PRETTY_FUNCTION__");
extern const char PF_dtor[] __asm__("_ZZN3psp15VertexArrayEditD1EvE19__PRETTY_FUNCTION__");
extern const char PF_begin[] __asm__("_ZZN3psp15VertexArrayEdit5beginERNS_11VertexArrayEjE19__PRETTY_FUNCTION__");
extern const char PF_end[] __asm__("_ZZN3psp15VertexArrayEdit3endEvE19__PRETTY_FUNCTION__");
extern const char PF_clear[] __asm__("_ZZN3psp15VertexArrayEdit5clearEvE19__PRETTY_FUNCTION__");
extern const char PF_resize[] __asm__("_ZZN3psp15VertexArrayEdit6resizeEjE19__PRETTY_FUNCTION__");
extern const char PF_check_size[] __asm__("_ZZN3psp15VertexArrayEdit10check_sizeEvE19__PRETTY_FUNCTION__");
extern const char PF_VA_clear[] __asm__("_ZZN3psp11VertexArray5clearEvE19__PRETTY_FUNCTION__");
extern const char D_00160054[], D_00160064[];
extern const char D_0015EA88[], D_0015EA9C[];
extern const char PF_format[] __asm__("_ZZN3psp15VertexArrayEdit6formatEjE19__PRETTY_FUNCTION__");
extern const char D_0015E87C[], D_0015E888[], D_0015E890[], D_0015E8A0[], D_0015E8B0[], D_0015E8C0[], D_0015E8CC[], D_0015E8DC[], D_0015E8EC[], D_0015E8FC[], D_0015E90C[], D_0015E91C[], D_0015E928[], D_0015E934[], D_0015E940[], D_0015E94C[], D_0015E958[], D_0015E964[], D_0015E974[], D_0015E984[], D_0015E994[];
extern const char D_0015EE48[], D_0015F314[], D_0015F320[], D_0015F324[], D_0015F360[], D_0015F5D8[];
extern const char PF_VA_DEBUG_printFormat[] __asm__("_ZZN3psp11VertexArray17DEBUG_printFormatEvE19__PRETTY_FUNCTION__");
extern const char D_0015EE54[], D_0015F310[];
extern const char D_0015F0D4[], D_0015F0F8[], D_0015F108[];
extern const char PF_import[] __asm__("_ZZN3psp15VertexArrayEdit6importERKS0_E19__PRETTY_FUNCTION__");
extern const char PF_ConvertMaskInternal2Gu[] __asm__("_ZZN3psp22ConvertMaskInternal2GuEjE19__PRETTY_FUNCTION__");
extern const char PF_on_format_change[] __asm__("_ZZN3psp15VertexArrayEdit10Descriptor16on_format_changeEvE19__PRETTY_FUNCTION__");

/* common/assert: " *** error ", expression, file, __PRETTY_FUNCTION__, line, message */
#define VA_ASSERT(c, text, file, pf, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_0015EA40, text, file, pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
#define VA_CPP D_0015EA20
#define VA_H D_0015F2A0

using namespace psp;

/* VertexArray.h: a view of the vertex data */
template<class T> struct ByteArrayNames {
    static const char read[], write[];
};
#define BYTE_ARRAY_NAMES(T, M) \
    template<> const char ByteArrayNames<T>::read[] __asm__("_ZZN3psp10byte_array4readI" M "EEvjRT_E19__PRETTY_FUNCTION__"); \
    template<> const char ByteArrayNames<T>::write[] __asm__("_ZZN3psp10byte_array5writeI" M "EEvjT_E19__PRETTY_FUNCTION__");
BYTE_ARRAY_NAMES(unsigned char, "h")
BYTE_ARRAY_NAMES(unsigned short, "t")
BYTE_ARRAY_NAMES(unsigned int, "j")
BYTE_ARRAY_NAMES(char, "c")
BYTE_ARRAY_NAMES(short, "s")
BYTE_ARRAY_NAMES(float, "f")
extern const char D_0015F2BC[];
/* __PRETTY_FUNCTION__ of the set<T> instances */
template<class T> struct SetNames {
    static const char pretty_function[];
};
template<> const char SetNames<unsigned char>::pretty_function[] __asm__("_ZZN3psp15VertexArrayEdit3setIhEEvNS0_5ValueIT_EEE19__PRETTY_FUNCTION__");
template<> const char SetNames<unsigned short>::pretty_function[] __asm__("_ZZN3psp15VertexArrayEdit3setItEEvNS0_5ValueIT_EEE19__PRETTY_FUNCTION__");
template<> const char SetNames<char>::pretty_function[] __asm__("_ZZN3psp15VertexArrayEdit3setIcEEvNS0_5ValueIT_EEE19__PRETTY_FUNCTION__");
template<> const char SetNames<short>::pretty_function[] __asm__("_ZZN3psp15VertexArrayEdit3setIsEEvNS0_5ValueIT_EEE19__PRETTY_FUNCTION__");
template<> const char SetNames<float>::pretty_function[] __asm__("_ZZN3psp15VertexArrayEdit3setIfEEvNS0_5ValueIT_EEE19__PRETTY_FUNCTION__");
template<> const char SetNames<unsigned int>::pretty_function[] __asm__("_ZZN3psp15VertexArrayEdit3setIjEEvNS0_5ValueIT_EEE19__PRETTY_FUNCTION__");
extern const char D_0015F7E4[];
namespace psp {
class byte_array {
public:
    byte_array(unsigned char *_Data, unsigned int _Size) : _data(_Data), _size(_Size) {}
    template<class T> void read(unsigned int _Offset, T &_Value) const
    {
        VA_ASSERT(_size == 0 || _Offset + sizeof(T) <= _size, D_0015F2BC, VA_H, ByteArrayNames<T>::read, 107, D_0015EA04);
        __builtin_memcpy(&_Value, _data + _Offset, sizeof(T));
    }
    template<class T> void write(unsigned int _Offset, T _Value)
    {
        VA_ASSERT(_size == 0 || _Offset + sizeof(T) <= _size, D_0015F2BC, VA_H, ByteArrayNames<T>::write, 100, D_0015EA04);
        __builtin_memcpy(_data + _Offset, &_Value, sizeof(T));
    }
    unsigned char *_data;
    unsigned int _size;
};
}

/* VertexArray.h */
inline void VertexArrayEdit::check_size()
{
    VA_ASSERT(_va != 0, D_0015F004, VA_H, PF_check_size, 483, D_0015EA04);
    if (_n >= _va->_num_vertices)
        resize(_n + _va->_num_vertices * 2 / 3 + 1);
}
/* the __PRETTY_FUNCTION__ labels of the primary psp::convert<> instances */
template<class OutputType, class InputType> struct ConvertNames {
    static const char pretty_function[];
};
template<> const char ConvertNames<unsigned int, unsigned char>::pretty_function[] __asm__("_ZZN3psp7convertIjhEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<char, unsigned char>::pretty_function[] __asm__("_ZZN3psp7convertIchEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<short, unsigned char>::pretty_function[] __asm__("_ZZN3psp7convertIshEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned int, unsigned short>::pretty_function[] __asm__("_ZZN3psp7convertIjtEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<char, unsigned short>::pretty_function[] __asm__("_ZZN3psp7convertIctEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<short, unsigned short>::pretty_function[] __asm__("_ZZN3psp7convertIstEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned char, char>::pretty_function[] __asm__("_ZZN3psp7convertIhcEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned short, char>::pretty_function[] __asm__("_ZZN3psp7convertItcEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned int, char>::pretty_function[] __asm__("_ZZN3psp7convertIjcEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned char, short>::pretty_function[] __asm__("_ZZN3psp7convertIhsEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned short, short>::pretty_function[] __asm__("_ZZN3psp7convertItsEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned int, short>::pretty_function[] __asm__("_ZZN3psp7convertIjsEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned int, float>::pretty_function[] __asm__("_ZZN3psp7convertIjfEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned char, unsigned int>::pretty_function[] __asm__("_ZZN3psp7convertIhjEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<unsigned short, unsigned int>::pretty_function[] __asm__("_ZZN3psp7convertItjEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<char, unsigned int>::pretty_function[] __asm__("_ZZN3psp7convertIcjEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<short, unsigned int>::pretty_function[] __asm__("_ZZN3psp7convertIsjEET_RKT0_E19__PRETTY_FUNCTION__");
template<> const char ConvertNames<float, unsigned int>::pretty_function[] __asm__("_ZZN3psp7convertIfjEET_RKT0_E19__PRETTY_FUNCTION__");

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3psp15VertexArrayEdit9BIT_NAMESE");
__asm__(".globl _GLOBAL__D__ZN3psp15VertexArrayEdit9BIT_NAMESE");

extern const char D_0015E78C[], D_0015E794[], D_0015E79C[], D_0015E7A4[], D_0015E7AC[], D_0015E7B4[], D_0015E7BC[], D_0015E7C4[], D_0015E7CC[], D_0015E7D4[], D_0015E7DC[], D_0015E7E4[], D_0015E7EC[], D_0015E7F4[], D_0015E800[], D_0015E808[], D_0015E810[], D_0015E81C[], D_0015E824[], D_0015E82C[], D_0015E834[], D_0015E840[], D_0015E84C[], D_0015E858[], D_0015E864[], D_0015E86C[], D_0015E874[];
std::string VertexArrayEdit::BIT_NAMES[] = {
    D_0015E78C, D_0015E794, D_0015E79C, D_0015E7A4, D_0015E7AC, D_0015E7B4, D_0015E7BC, D_0015E7C4, D_0015E7CC, D_0015E7D4, D_0015E7DC, D_0015E7E4, D_0015E7EC, D_0015E7F4, D_0015E800, D_0015E808, D_0015E810
};
std::string VertexArrayEdit::TYPE_NAMES[] = {
    D_0015E81C, D_0015E824, D_0015E82C, D_0015E834, D_0015E840, D_0015E84C, D_0015E858, D_0015E864, D_0015E86C, D_0015E874
};
bool VertexArrayEdit::smart_color_map;
unsigned char VertexArrayEdit::current_color[4];
float VertexArrayEdit::current_normal[3];
float VertexArrayEdit::current_texcoord[2];

std::string psp::GetPixelFormatBitMaskName(PixelFormatBitMask _Mask)
{
    if (_Mask == 0x1)
        return D_0015E994;
    if (_Mask == 0x2)
        return D_0015E984;
    if (_Mask == 0x4)
        return D_0015E974;
    if (_Mask == 0x8)
        return D_0015E964;
    if (_Mask == 0x10)
        return D_0015E958;
    if (_Mask == 0x20)
        return D_0015E94C;
    if (_Mask == 0x40)
        return D_0015E940;
    if (_Mask == 0x80)
        return D_0015E934;
    if (_Mask == 0x100)
        return D_0015E928;
    if (_Mask == 0x200)
        return D_0015E87C;
    if (_Mask == 0x400)
        return D_0015E91C;
    if (_Mask == 0x800)
        return D_0015E90C;
    if (_Mask == 0x1000)
        return D_0015E8FC;
    if (_Mask == 0x2000)
        return D_0015E8EC;
    if (_Mask == 0x4000)
        return D_0015E8DC;
    if (_Mask == 0x8000)
        return D_0015E8CC;
    if (_Mask == 0x10000)
        return D_0015E8C0;
    if (_Mask == 0x20000)
        return D_0015E8B0;
    if (_Mask == 0x40000)
        return D_0015E8A0;
    if (_Mask == 0x80000)
        return D_0015E890;
    return D_0015E888;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp29GetPixelFormatBitMaskNameFillENS_18PixelFormatBitMaskEb);

template<> float psp::convert<float, float>(const float &x)
{
    return x;
}

template<> unsigned int psp::convert<unsigned int, unsigned int>(const unsigned int &x)
{
    return x;
}

template<> unsigned short psp::convert<unsigned short, unsigned short>(const unsigned short &x)
{
    return x;
}

template<> short psp::convert<short, short>(const short &x)
{
    return x;
}

template<> unsigned char psp::convert<unsigned char, unsigned char>(const unsigned char &x)
{
    return x;
}

template<> char psp::convert<char, char>(const char &x)
{
    return x;
}

template<> unsigned char psp::convert<unsigned char, unsigned short>(const unsigned short &x)
{
    return x >> 8;
}

template<> unsigned short psp::convert<unsigned short, unsigned char>(const unsigned char &x)
{
    return x << 8;
}

template<> unsigned char psp::convert<unsigned char, float>(const float &x)
{
    return (unsigned int)(psp::Clamped<float>(x, 0.0f, 2.0f) * 128.0f);
}

template<> float psp::convert<float, unsigned char>(const unsigned char &x)
{
    return x * 0.0078125f;
}

template<> unsigned short psp::convert<unsigned short, float>(const float &x)
{
    return (unsigned int)(psp::Clamped<float>(x, 0.0f, 2.0f) * 32768.0f);
}

template<> float psp::convert<float, unsigned short>(const unsigned short &x)
{
    return x * 3.051757812e-05f;
}

template<> char psp::convert<char, short>(const short &x)
{
    return x >> 8;
}

template<> short psp::convert<short, char>(const char &x)
{
    return x << 8;
}

template<> char psp::convert<char, float>(const float &x)
{
    char c = (int)((psp::Clamped<float>(x, -1.0f, 1.0f) + 1.0f) * 255.0f * 0.5f);
    return c - 128;
}

template<> float psp::convert<float, char>(const char &x)
{
    return (x + 128.0f) * 2 * 0.003921568859f + -1.0f;
}

template<> short psp::convert<short, float>(const float &x)
{
    return (int)((psp::Clamped<float>(x, -1.0f, 1.0f) + 1.0f) * 65535.0f * 0.5f) - 32768;
}

template<> float psp::convert<float, short>(const short &x)
{
    return (x + 32768.0f) * 2 * 1.525902189e-05f + -1.0f;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit6SizeofENS0_7BitTypeE);

void VertexArray::set_mask(unsigned int _Mask)
{
    VA_ASSERT(IsValidMask(_Mask), D_0015EA08, VA_CPP, PF_set_mask, 299, D_0015EA04);
    _mask = _Mask;
    _gu_mask = ConvertMaskInternal2Gu(_Mask);
}

void VertexArray::format(unsigned int _Mask)
{
    VertexArrayEdit e(0x8500);
    e.begin(*this);
    e.format(_Mask);
    e.end();
}

void VertexArray::import(VertexArray &_Value)
{
    VertexArrayEdit src(0x8500);
    VertexArrayEdit dst(0x8500);
    dst.begin(*this);
    src.begin(_Value);
    dst.import(src);
    src.end();
    dst.end();
}

void VertexArrayEdit::Descriptor::on_format_change()
{
    for (int i = 0; i != INFO_SIZE; i++)
        _info[i] = INVALID_BIT;
    unsigned int max_size = 0;
    for (int i = 0; i != MAX_BITS; i++) {
        Bit &bit = _bits[i];
        bit._size = Sizeof(bit._type);
        if (max_size < bit._size)
            max_size = bit._size;
    }
    if (max_size == 0)
        return;
    unsigned int offset = 0;
    for (int i = 0; i != MAX_BITS; i++) {
        Bit &bit = _bits[i];
        if (bit._size == 0) {
            bit._offset = -1;
            continue;
        }
        while (offset % bit._size != 0) {
            VA_ASSERT(offset < INFO_SIZE, D_0015EA88, VA_CPP, PF_on_format_change, 372, D_0015EA04);
            _info[offset++] = PAD1;
        }
        bit._offset = offset;
        for (unsigned int j = offset; j != offset + bit._size; j++) {
            VA_ASSERT(j < INFO_SIZE, D_0015EA9C, VA_CPP, PF_on_format_change, 382, D_0015EA04);
            _info[j] = bit._enum;
        }
        offset += bit._size;
    }
    while (offset % max_size != 0) {
        VA_ASSERT(offset < INFO_SIZE, D_0015EA88, VA_CPP, PF_on_format_change, 392, D_0015EA04);
        _info[offset++] = PAD2;
    }
    _bytesize = offset;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit10Descriptor12set_bit_typeENS0_12BitGroupEnumENS0_7BitTypeE);

const VertexArrayEdit::Bit &VertexArrayEdit::Descriptor::getBit(BitEnum _Enum) const
{
    VA_ASSERT(_Enum < MAX_BITS, D_0015ECC0, VA_CPP, PF_getBit, 453, D_0015EA04);
    return _bits[_Enum];
}

VertexArrayEdit::Descriptor::Descriptor(unsigned int _Format) : _format(0)
{
    for (int i = 0; i != MAX_BITS; i++)
        _bits[i]._enum = (BitEnum)i;
    VA_ASSERT(IsValidMask(_Format), D_0015EA08, VA_CPP, PF_Descriptor, 466, D_0015EA04);
    setFormat(_Format);
}

bool VertexArrayEdit::Descriptor::setFormat(unsigned int _Format)
{
    VA_ASSERT(IsValidMask(_Format), D_0015EA08, VA_CPP, PF_setFormat, 473, D_0015EA04);
    if (_format == _Format)
        return false;
    if (_Format & 0x20000)
        set_bit_type(WEIGHT, UBYTE);
    else if (_Format & 0x40000)
        set_bit_type(WEIGHT, USHORT);
    else if (_Format & 0x80000)
        set_bit_type(WEIGHT, FLOAT);
    else
        set_bit_type(WEIGHT, NONE);
    if (_Format & 2)
        set_bit_type(TEXCOORD, UBYTE);
    else if (_Format & 4)
        set_bit_type(TEXCOORD, USHORT);
    else if (_Format & 8)
        set_bit_type(TEXCOORD, FLOAT);
    else
        set_bit_type(TEXCOORD, NONE);
    if (_Format & 0x20)
        set_bit_type(COLOR, USHORT_5650);
    else if (_Format & 0x40)
        set_bit_type(COLOR, USHORT_5551);
    else if (_Format & 0x80)
        set_bit_type(COLOR, USHORT_4444);
    else if (_Format & 0x100)
        set_bit_type(COLOR, UINT_8888);
    else
        set_bit_type(COLOR, NONE);
    if (_Format & 0x400)
        set_bit_type(NORMAL, BYTE);
    else if (_Format & 0x800)
        set_bit_type(NORMAL, SHORT);
    else if (_Format & 0x1000)
        set_bit_type(NORMAL, FLOAT);
    else
        set_bit_type(NORMAL, NONE);
    if (_Format & 0x2000)
        set_bit_type(POSITION, BYTE);
    else if (_Format & 0x4000)
        set_bit_type(POSITION, SHORT);
    else if (_Format & 0x8000)
        set_bit_type(POSITION, FLOAT);
    else
        VA_ASSERT(0, D_0015E9A4, VA_CPP, PF_setFormat, 506, D_0015ED50);
    _format = _Format;
    on_format_change();
    return true;
}

unsigned int psp::ConvertMaskInternal2Gu(unsigned int _Mask)
{
    unsigned int gu = 0;
    if (_Mask & 0x20000)
        gu |= 0x200;
    else if (_Mask & 0x40000)
        gu |= 0x400;
    else if (_Mask & 0x80000)
        gu |= 0x600;
    if (_Mask & 2)
        gu |= 1;
    else if (_Mask & 4)
        gu |= 2;
    else if (_Mask & 8)
        gu |= 3;
    if (_Mask & 0x20)
        gu |= 0x10;
    else if (_Mask & 0x40)
        gu |= 0x14;
    else if (_Mask & 0x80)
        gu |= 0x18;
    else if (_Mask & 0x100)
        gu |= 0x1C;
    if (_Mask & 0x400)
        gu |= 0x20;
    else if (_Mask & 0x800)
        gu |= 0x40;
    else if (_Mask & 0x1000)
        gu |= 0x60;
    if (_Mask & 0x2000)
        gu |= 0x80;
    else if (_Mask & 0x4000)
        gu |= 0x100;
    else if (_Mask & 0x8000)
        gu |= 0x180;
    else
        VA_ASSERT(0, D_0015E9A4, VA_CPP, PF_ConvertMaskInternal2Gu, 553, D_0015ED50);
    return gu;
}

int VertexArrayEdit::Descriptor::getFormat() const
{
    return _format;
}

int VertexArrayEdit::Descriptor::getBytesize() const
{
    return _bytesize;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZNK3psp15VertexArrayEdit10Descriptor11printFormatEv);

VertexArrayEdit::VertexArrayEdit(unsigned int _Format) : _desc(_Format), _n(0), _va(0)
{
}

VertexArrayEdit::~VertexArrayEdit()
{
    VA_ASSERT(_va == 0, D_0015EEE8, VA_CPP, PF_dtor, 685, D_0015EEF4);
}

void VertexArrayEdit::begin(VertexArray &_Value, unsigned int _Mask)
{
    VA_ASSERT(IsValidMask(_Mask), D_0015EA08, VA_CPP, PF_begin, 692, D_0015EA04);
    VA_ASSERT(_va == 0, D_0015EEE8, VA_CPP, PF_begin, 694, D_0015EF50);
    _va = &_Value;
    _n = _Mask == _Value._mask ? _Value._num_vertices : 0;
    _desc.setFormat(_Mask);
    _va->set_mask(_Mask);
}

void VertexArrayEdit::begin(VertexArray &_Value)
{
    begin(_Value, IsValidMask(_Value._mask) ? _Value._mask : _desc.getFormat());
}

void VertexArrayEdit::end()
{
    VA_ASSERT(_va != 0, D_0015F004, VA_CPP, PF_end, 718, D_0015EFDC);
    VA_ASSERT(IsValidMask(_va->_mask), D_0015EF9C, VA_CPP, PF_end, 720, D_0015EFB8);
    VA_ASSERT(IsValidMask(_va->_mask), D_0015EF9C, VA_CPP, PF_end, 722, D_0015EA04);
    if (_n != _va->_num_vertices)
        resize(_n);
    VA_ASSERT(IsValidMask(_va->_mask), D_0015EF9C, VA_CPP, PF_end, 727, D_0015EA04);
    _va = 0;
}

void VertexArrayEdit::format(unsigned int _Mask)
{
    VA_ASSERT(_va != 0, D_0015F004, VA_CPP, PF_format, 738, D_0015EA04);
    VA_ASSERT(IsValidMask(_Mask), D_0015EA08, VA_CPP, PF_format, 739, D_0015EA04);
    VertexArray old = *_va;
    clear();
    _desc.setFormat(_Mask);
    _va->set_mask(_Mask);
    if (IsValidMask(old._mask)) {
        resize(old._num_vertices);
        for (std::vector<unsigned char>::iterator i = _va->_data.begin(); i != _va->_data.end(); ++i)
            *i = 0;
        _va->import(old);
    }
}

void VertexArrayEdit::clear()
{
    VA_ASSERT(_va != 0, D_0015F004, VA_CPP, PF_clear, 774, D_0015EA04);
    _va->clear();
    _n = 0;
}

void VertexArrayEdit::resize(unsigned int _Size)
{
    VA_ASSERT(_va != 0, D_0015F004, VA_CPP, PF_resize, 785, D_0015EA04);
    if (_va->_num_vertices == _Size)
        return;
    if (_Size == 0) {
        _va->_num_vertices = 0;
        _va->_data.clear();
        _n = 0;
    } else {
        _va->_num_vertices = _Size;
        _va->_data.resize(_Size * _desc._bytesize);
    }
}

void VertexArrayEdit::import(const VertexArrayEdit &_Value)
{
    VA_ASSERT(_Value._va != _va, D_0015F108, VA_CPP, PF_import, 805, D_0015EA04);
    VA_ASSERT(_Value._va != 0, D_0015F0F8, VA_CPP, PF_import, 806, D_0015EA04);
    VA_ASSERT(_va != 0, D_0015F004, VA_CPP, PF_import, 807, D_0015EA04);
    VA_ASSERT(IsValidMask(_Value._va->_mask), D_0015F0D4, VA_CPP, PF_import, 808, D_0015EA04);
    VA_ASSERT(IsValidMask(_va->_mask), D_0015EF9C, VA_CPP, PF_import, 809, D_0015EA04);
    unsigned int n = _va->_num_vertices < _Value._va->_num_vertices ? _va->_num_vertices : _Value._va->_num_vertices;
    for (unsigned int i = 0; i != n; i++)
        for (int bit = 0; bit != MAX_BITS; bit++)
            import_bit((BitEnum)bit, i, _Value);
    set_index(0);
}

unsigned char VertexArrayEdit::map_to_255(unsigned char _Value, unsigned int _Bits)
{
    if (smart_color_map)
        return (unsigned int)(_Value * 255.0f / ((1 << _Bits) - 1));
    return _Value << (8 - _Bits);
}

/* the asm import_bit uses set<unsigned char>, <unsigned short>, <char>, <short>, <float>, <unsigned int> first, in this
   order: the instances (and their float pools) are emitted in the order of their first use */
extern "C" void psp_VertexArrayEdit_set_order() __attribute__((section(".discard.instances")));
extern "C" void psp_VertexArrayEdit_set_order()
{
    ((VertexArrayEdit *)0)->set(VertexArrayEdit::Value<unsigned char>(VertexArrayEdit::WA, 0, 0));
    ((VertexArrayEdit *)0)->set(VertexArrayEdit::Value<unsigned short>(VertexArrayEdit::WA, 0, 0));
    ((VertexArrayEdit *)0)->set(VertexArrayEdit::Value<char>(VertexArrayEdit::WA, 0, 0));
    ((VertexArrayEdit *)0)->set(VertexArrayEdit::Value<short>(VertexArrayEdit::WA, 0, 0));
    ((VertexArrayEdit *)0)->set(VertexArrayEdit::Value<float>(VertexArrayEdit::WA, 0, 0));
    ((VertexArrayEdit *)0)->set(VertexArrayEdit::Value<unsigned int>(VertexArrayEdit::WA, 0, 0));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit10import_bitENS0_7BitEnumEjRKS0_);

void VertexArrayEdit::position(float x, float y, float z)
{
    check_size();
    set(Value<float>(PX, x, _n));
    set(Value<float>(PY, y, _n));
    set(Value<float>(PZ, z, _n));
}

void VertexArrayEdit::normal(float x, float y, float z)
{
    check_size();
    current_normal[0] = x;
    current_normal[1] = y;
    current_normal[2] = z;
    set(Value<float>(NX, x, _n));
    set(Value<float>(NY, y, _n));
    set(Value<float>(NZ, z, _n));
}

void VertexArrayEdit::texcoord(float s, float t)
{
    check_size();
    current_texcoord[0] = s;
    current_texcoord[1] = t;
    set(Value<float>(S, s, _n));
    set(Value<float>(T, t, _n));
}

#define VAE_F2UB(x) ((x) > 1 ? 255 : (x) < 0 ? 0 : (unsigned char)(unsigned int)((x) * 255))
void VertexArrayEdit::color(float r, float g, float b, float a)
{
    color4ub(VAE_F2UB(r), VAE_F2UB(g), VAE_F2UB(b), VAE_F2UB(a));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit8color4ubEhhhh);

void VertexArrayEdit::set_index(unsigned int _Index)
{
    _n = _Index;
    check_size();
}

void VertexArrayEdit::vertex(float x, float y, float z)
{
    normal(current_normal[0], current_normal[1], current_normal[2]);
    color4ub(current_color[0], current_color[1], current_color[2], current_color[3]);
    texcoord(current_texcoord[0], current_texcoord[1]);
    position(x, y, z);
    _n++;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit15DEBUG_print_bitENS0_7BitEnumEj);

void VertexArrayEdit::DEBUG_printVertex(unsigned int _Index)
{
    DEBUG_print_bit(WA, _Index);
    DEBUG_print_bit(WB, _Index);
    DEBUG_print_bit(WC, _Index);
    DEBUG_print_bit(WD, _Index);
    DEBUG_print_bit(S, _Index);
    DEBUG_print_bit(T, _Index);
    DEBUG_print_bit(C, _Index);
    DEBUG_print_bit(NX, _Index);
    DEBUG_print_bit(NY, _Index);
    DEBUG_print_bit(NZ, _Index);
    DEBUG_print_bit(PX, _Index);
    DEBUG_print_bit(PY, _Index);
    DEBUG_print_bit(PZ, _Index);
    std::cout << D_0015EE48;
}

void VertexArrayEdit::DEBUG_print(std::string _Name)
{
    std::cout << _Name;
    for (unsigned int i = 0; i != _va->_num_vertices; i++) {
        std::cout << D_0015F314 << i << D_0015F320;
        DEBUG_printVertex(i);
    }
}

void VertexArrayEdit::DEBUG_printFormat() const
{
    std::cout << D_0015F324;
    _desc.printFormat();
    std::cout << D_0015F360;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit4saveERKSs);

void VertexArray::DEBUG_printFormat()
{
    VA_ASSERT(IsValidMask(_mask), D_0015F5D8, VA_CPP, PF_VA_DEBUG_printFormat, 1338, D_0015EA04);
    VertexArrayEdit::Descriptor d(_mask);
    d.printFormat();
}

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN3psp7ClampedIfEEKT_S1_S1_S1_)
    DEMO_LINKONCE(_ZN3psp15VertexArrayEdit3setIhEEvNS0_5ValueIT_EE)
    DEMO_LINKONCE(_ZN3psp15VertexArrayEdit3setItEEvNS0_5ValueIT_EE)
    DEMO_LINKONCE(_ZN3psp15VertexArrayEdit3setIcEEvNS0_5ValueIT_EE)
    DEMO_LINKONCE(_ZN3psp15VertexArrayEdit3setIsEEvNS0_5ValueIT_EE)
    DEMO_LINKONCE(_ZN3psp15VertexArrayEdit3setIfEEvNS0_5ValueIT_EE)
    DEMO_LINKONCE(_ZN3psp15VertexArrayEdit3setIjEEvNS0_5ValueIT_EE)
    DEMO_LINKONCE(_ZNSt6vectorIhSaIhEE5eraseEN9__gnu_cxx17__normal_iteratorIPhS1_EES5_)
    DEMO_LINKONCE(_ZN3psp7convertIjhEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIchEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIshEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIjtEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIctEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIstEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIhcEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertItcEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIjcEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIhsEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertItsEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIjsEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIjfEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIhjEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertItjEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIcjEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIsjEET_RKT0_)
    DEMO_LINKONCE(_ZN3psp7convertIfjEET_RKT0_)
    DEMO_LINKONCE(_ZNSt6vectorIhSaIhEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPhS1_EEjRKh)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEEhEvT_S7_RKT0_)
    DEMO_LINKONCE(_ZSt6fill_nIN9__gnu_cxx17__normal_iteratorIPhSt6vectorIhSaIhEEEEjhET_S7_T0_RKT1_)
    DEMO_LINKONCE(_ZN3psp11VertexArray5clearEv)
    DEMO_LINKONCE(_ZSt3decRSt8ios_base)
    DEMO_LINKONCE(_ZSt3hexRSt8ios_base)
);

#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

/* the instances only the asm callers (set<T>) use: implicit instantiation from a function that is not linked */
extern "C" void psp_VertexArrayEdit_manip(std::ios_base &(*)(std::ios_base &));
extern "C" void psp_VertexArrayEdit_instances(std::vector<unsigned char> &, unsigned int) __attribute__((section(".discard.instances")));
extern "C" void psp_VertexArrayEdit_instances(std::vector<unsigned char> &v, unsigned int n)
{
    v.resize(n);
    psp_VertexArrayEdit_manip(std::dec);
    psp_VertexArrayEdit_manip(std::hex);
    psp::convert<unsigned int, unsigned char>(*(const unsigned char *)0);
    psp::convert<char, unsigned char>(*(const unsigned char *)0);
    psp::convert<short, unsigned char>(*(const unsigned char *)0);
    psp::convert<unsigned int, unsigned short>(*(const unsigned short *)0);
    psp::convert<char, unsigned short>(*(const unsigned short *)0);
    psp::convert<short, unsigned short>(*(const unsigned short *)0);
    psp::convert<unsigned char, char>(*(const char *)0);
    psp::convert<unsigned short, char>(*(const char *)0);
    psp::convert<unsigned int, char>(*(const char *)0);
    psp::convert<unsigned char, short>(*(const short *)0);
    psp::convert<unsigned short, short>(*(const short *)0);
    psp::convert<unsigned int, short>(*(const short *)0);
    psp::convert<unsigned int, float>(*(const float *)0);
    psp::convert<unsigned char, unsigned int>(*(const unsigned int *)0);
    psp::convert<unsigned short, unsigned int>(*(const unsigned int *)0);
    psp::convert<char, unsigned int>(*(const unsigned int *)0);
    psp::convert<short, unsigned int>(*(const unsigned int *)0);
    psp::convert<float, unsigned int>(*(const unsigned int *)0);
}

template<class T> const T psp::Clamped(T x, T lo, T hi)
{
    if (x < lo)
        return lo;
    if (hi < x)
        return hi;
    return x;
}

template<class Type> void VertexArrayEdit::set(Value<Type> _Val)
{
    VA_ASSERT(_Val._index < _va->_num_vertices, D_0015F7E4, VA_H, SetNames<Type>::pretty_function, 424, D_0015EA04);
    const Bit &bit = _desc.getBit(_Val._bit);
    if (bit._type == NONE)
        return;
    unsigned int offset = _desc._bytesize * _Val._index + bit._offset;
    byte_array data(&_va->_data[0], _va->_data.size());
    if (bit._type == UBYTE)
        data.write(offset, convert<unsigned char>(_Val._value));
    else if (bit._type >= USHORT && bit._type <= USHORT_4444)
        data.write(offset, convert<unsigned short>(_Val._value));
    else if (bit._type == UINT_8888)
        data.write(offset, convert<unsigned int>(_Val._value));
    else if (bit._type == BYTE)
        data.write(offset, convert<char>(_Val._value));
    else if (bit._type == SHORT)
        data.write(offset, convert<short>(_Val._value));
    else if (bit._type == FLOAT)
        data.write(offset, convert<float>(_Val._value));
}

template<class OutputType, class InputType> OutputType psp::convert(const InputType &)
{
    std::cout << ConvertNames<OutputType, InputType>::pretty_function << D_0015F9F8;
    if (!NOT_IMPLEMENTED) {
        common::common_internal::assert_display(D_0015EA40, D_0015FA08, D_0015F2A0,
                                                ConvertNames<OutputType, InputType>::pretty_function, 118, D_0015EA04);
        common::common_internal::on_error();
        common::common_internal::clash();
    }
    return 0;
}

/* an inline member of a class of main.hpp: emitted (linkonce) only outside the interface */
SGL_LINKONCE_BEGIN
inline void VertexArray::clear()
{
    if (_num_vertices == 0) {
        VA_ASSERT(_data.empty(), D_00160054, VA_H, PF_VA_clear, 204, D_0015EA04);
        VA_ASSERT(_vram_addr == 0, D_00160064, VA_H, PF_VA_clear, 205, D_0015EA04);
    } else {
        _data.clear();
        _num_vertices = 0;
        _vram_addr = 0;
        _mask = 0;
        _gu_mask = 0;
    }
}
SGL_LINKONCE_END

