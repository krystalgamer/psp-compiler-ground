/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* before main.hpp's `#pragma interface`: std::dec/std::hex (used by address) are emitted here */
#include <ios>
#include "../main.hpp"

extern const char D_00162498[], D_001624A8[], D_00161D40[], D_001614E0[], D_001614A4[];
#define NOT_IMPLEMENTED 0
extern const char D_00161444[], D_001614A8[], D_001614C0[], D_00161760[], D_001617F0[], D_00161988[], D_00161994[];
extern const char D_001619F0[], D_00161A3C[], D_00161A58[], D_00161A7C[], D_00161AA4[];
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
extern const char D_00162AF4[], D_00162B04[];
extern const char D_00161528[], D_0016153C[];
extern const char PF_format[] __asm__("_ZZN3psp15VertexArrayEdit6formatEjE19__PRETTY_FUNCTION__");
extern const char D_0016131C[], D_00161328[], D_00161330[], D_00161340[], D_00161350[], D_00161360[], D_0016136C[], D_0016137C[], D_0016138C[], D_0016139C[], D_001613AC[], D_001613BC[], D_001613C8[], D_001613D4[], D_001613E0[], D_001613EC[], D_001613F8[], D_00161404[], D_00161414[], D_00161424[], D_00161434[];
extern const char D_00161B74[], D_00161B98[], D_00161BA8[];
extern const char PF_import[] __asm__("_ZZN3psp15VertexArrayEdit6importERKS0_E19__PRETTY_FUNCTION__");
extern const char PF_ConvertMaskInternal2Gu[] __asm__("_ZZN3psp22ConvertMaskInternal2GuEjE19__PRETTY_FUNCTION__");
extern const char PF_on_format_change[] __asm__("_ZZN3psp15VertexArrayEdit10Descriptor16on_format_changeEvE19__PRETTY_FUNCTION__");

/* common/assert: " *** error ", expression, file, __PRETTY_FUNCTION__, line, message */
#define VA_ASSERT(c, text, file, pf, line, msg) \
    if (!(c)) { \
        common::common_internal::assert_display(D_001614E0, text, file, pf, line, msg); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }
#define VA_CPP D_001614C0
#define VA_H D_00161D40

using namespace psp;

/* VertexArray.h */
inline void VertexArrayEdit::check_size()
{
    VA_ASSERT(_va != 0, D_00161AA4, VA_H, PF_check_size, 483, D_001614A4);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _Z41__static_initialization_and_destruction_0ii_155EC);

std::string psp::GetPixelFormatBitMaskName(PixelFormatBitMask _Mask)
{
    if (_Mask == 0x1)
        return D_00161434;
    if (_Mask == 0x2)
        return D_00161424;
    if (_Mask == 0x4)
        return D_00161414;
    if (_Mask == 0x8)
        return D_00161404;
    if (_Mask == 0x10)
        return D_001613F8;
    if (_Mask == 0x20)
        return D_001613EC;
    if (_Mask == 0x40)
        return D_001613E0;
    if (_Mask == 0x80)
        return D_001613D4;
    if (_Mask == 0x100)
        return D_001613C8;
    if (_Mask == 0x200)
        return D_0016131C;
    if (_Mask == 0x400)
        return D_001613BC;
    if (_Mask == 0x800)
        return D_001613AC;
    if (_Mask == 0x1000)
        return D_0016139C;
    if (_Mask == 0x2000)
        return D_0016138C;
    if (_Mask == 0x4000)
        return D_0016137C;
    if (_Mask == 0x8000)
        return D_0016136C;
    if (_Mask == 0x10000)
        return D_00161360;
    if (_Mask == 0x20000)
        return D_00161350;
    if (_Mask == 0x40000)
        return D_00161340;
    if (_Mask == 0x80000)
        return D_00161330;
    return D_00161328;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp29GetPixelFormatBitMaskNameFillENS_18PixelFormatBitMaskEb);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit6SizeofENS0_7BitTypeE);

void VertexArray::set_mask(unsigned int _Mask)
{
    VA_ASSERT(IsValidMask(_Mask), D_001614A8, VA_CPP, PF_set_mask, 299, D_001614A4);
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
            VA_ASSERT(offset < INFO_SIZE, D_00161528, VA_CPP, PF_on_format_change, 372, D_001614A4);
            _info[offset++] = PAD1;
        }
        bit._offset = offset;
        for (unsigned int j = offset; j != offset + bit._size; j++) {
            VA_ASSERT(j < INFO_SIZE, D_0016153C, VA_CPP, PF_on_format_change, 382, D_001614A4);
            _info[j] = bit._enum;
        }
        offset += bit._size;
    }
    while (offset % max_size != 0) {
        VA_ASSERT(offset < INFO_SIZE, D_00161528, VA_CPP, PF_on_format_change, 392, D_001614A4);
        _info[offset++] = PAD2;
    }
    _bytesize = offset;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit10Descriptor12set_bit_typeENS0_12BitGroupEnumENS0_7BitTypeE);

const VertexArrayEdit::Bit &VertexArrayEdit::Descriptor::getBit(BitEnum _Enum) const
{
    VA_ASSERT(_Enum < MAX_BITS, D_00161760, VA_CPP, PF_getBit, 453, D_001614A4);
    return _bits[_Enum];
}

VertexArrayEdit::Descriptor::Descriptor(unsigned int _Format) : _format(0)
{
    for (int i = 0; i != MAX_BITS; i++)
        _bits[i]._enum = (BitEnum)i;
    VA_ASSERT(IsValidMask(_Format), D_001614A8, VA_CPP, PF_Descriptor, 466, D_001614A4);
    setFormat(_Format);
}


bool VertexArrayEdit::Descriptor::setFormat(unsigned int _Format)
{
    VA_ASSERT(IsValidMask(_Format), D_001614A8, VA_CPP, PF_setFormat, 473, D_001614A4);
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
        VA_ASSERT(0, D_00161444, VA_CPP, PF_setFormat, 506, D_001617F0);
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
        VA_ASSERT(0, D_00161444, VA_CPP, PF_ConvertMaskInternal2Gu, 553, D_001617F0);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZNK3psp15VertexArrayEdit10Descriptor11printFormatEv);

VertexArrayEdit::VertexArrayEdit(unsigned int _Format) : _desc(_Format), _n(0), _va(0)
{
}


VertexArrayEdit::~VertexArrayEdit()
{
    VA_ASSERT(_va == 0, D_00161988, VA_CPP, PF_dtor, 685, D_00161994);
}


void VertexArrayEdit::begin(VertexArray &_Value, unsigned int _Mask)
{
    VA_ASSERT(IsValidMask(_Mask), D_001614A8, VA_CPP, PF_begin, 692, D_001614A4);
    VA_ASSERT(_va == 0, D_00161988, VA_CPP, PF_begin, 694, D_001619F0);
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
    VA_ASSERT(_va != 0, D_00161AA4, VA_CPP, PF_end, 718, D_00161A7C);
    VA_ASSERT(IsValidMask(_va->_mask), D_00161A3C, VA_CPP, PF_end, 720, D_00161A58);
    VA_ASSERT(IsValidMask(_va->_mask), D_00161A3C, VA_CPP, PF_end, 722, D_001614A4);
    if (_n != _va->_num_vertices)
        resize(_n);
    VA_ASSERT(IsValidMask(_va->_mask), D_00161A3C, VA_CPP, PF_end, 727, D_001614A4);
    _va = 0;
}

void VertexArrayEdit::format(unsigned int _Mask)
{
    VA_ASSERT(_va != 0, D_00161AA4, VA_CPP, PF_format, 738, D_001614A4);
    VA_ASSERT(IsValidMask(_Mask), D_001614A8, VA_CPP, PF_format, 739, D_001614A4);
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
    VA_ASSERT(_va != 0, D_00161AA4, VA_CPP, PF_clear, 774, D_001614A4);
    _va->clear();
    _n = 0;
}

void VertexArrayEdit::resize(unsigned int _Size)
{
    VA_ASSERT(_va != 0, D_00161AA4, VA_CPP, PF_resize, 785, D_001614A4);
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
    VA_ASSERT(_Value._va != _va, D_00161BA8, VA_CPP, PF_import, 805, D_001614A4);
    VA_ASSERT(_Value._va != 0, D_00161B98, VA_CPP, PF_import, 806, D_001614A4);
    VA_ASSERT(_va != 0, D_00161AA4, VA_CPP, PF_import, 807, D_001614A4);
    VA_ASSERT(IsValidMask(_Value._va->_mask), D_00161B74, VA_CPP, PF_import, 808, D_001614A4);
    VA_ASSERT(IsValidMask(_va->_mask), D_00161A3C, VA_CPP, PF_import, 809, D_001614A4);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit10import_bitENS0_7BitEnumEjRKS0_);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit5colorEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit8color4ubEhhhh);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit15DEBUG_print_bitENS0_7BitEnumEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit17DEBUG_printVertexEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit11DEBUG_printESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZNK3psp15VertexArrayEdit17DEBUG_printFormatEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit4saveERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp11VertexArray17DEBUG_printFormatEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_155EC");
void _GLOBAL__I__ZN3psp15VertexArrayEdit9BIT_NAMESE(void);
void _GLOBAL__D__ZN3psp15VertexArrayEdit9BIT_NAMESE(void);
}

void _GLOBAL__I__ZN3psp15VertexArrayEdit9BIT_NAMESE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3psp15VertexArrayEdit9BIT_NAMESE(void)
{
    static_init(0, 0xFFFF);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit3setIhEEvNS0_5ValueIT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit3setItEEvNS0_5ValueIT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit3setIcEEvNS0_5ValueIT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit3setIsEEvNS0_5ValueIT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit3setIfEEvNS0_5ValueIT_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/psp_VertexArrayEdit", _ZN3psp15VertexArrayEdit3setIjEEvNS0_5ValueIT_EE);

template<class OutputType, class InputType> OutputType psp::convert(const InputType &)
{
    std::cout << ConvertNames<OutputType, InputType>::pretty_function << D_00162498;
    if (!NOT_IMPLEMENTED) {
        common::common_internal::assert_display(D_001614E0, D_001624A8, D_00161D40,
                                                ConvertNames<OutputType, InputType>::pretty_function, 118, D_001614A4);
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
        VA_ASSERT(_data.empty(), D_00162AF4, VA_H, PF_VA_clear, 204, D_001614A4);
        VA_ASSERT(_vram_addr == 0, D_00162B04, VA_H, PF_VA_clear, 205, D_001614A4);
    } else {
        _data.clear();
        _num_vertices = 0;
        _vram_addr = 0;
        _mask = 0;
        _gu_mask = 0;
    }
}
SGL_LINKONCE_END

