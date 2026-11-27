/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_0017641C[];     /* "" */
extern const char D_0017645C[];     /* " *** error " */
extern const char D_00176468[];     /* "_Value == ALPHA_BLEND || _Value == ALPHA_TEST || _Value == 0" */
extern const char D_001764A8[];     /* "../lib/textures/Texture.cpp" */
extern const char D_001764C4[];     /* " " */
extern const char D_00176504[];     /* "value == GetBitField( reg, start_bit, bit_size )" */
extern const char SetBitField_name[] __asm__("_ZZN8textures11SetBitFieldERjiiiE19__PRETTY_FUNCTION__");
extern const char setAlphaFlags_name[] __asm__("_ZZN8textures7Texture13setAlphaFlagsENS_9AlphaMaskEE19__PRETTY_FUNCTION__");
#define TEX_ASSERT(c, s, fn, line) \
    do if (!(c)) { \
        common::common_internal::assert_display(D_0017645C, s, D_001764A8, fn, line, D_001764C4); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    } while (0)

namespace textures {
inline int GetBitField(unsigned int reg, int start_bit, int bit_size)
{
    return (reg >> start_bit) & ((1 << bit_size) - 1);
}

inline void SetBitField(unsigned int &reg, int value, int start_bit, int bit_size)
{
    unsigned int mask = (1 << bit_size) - 1;
    unsigned int v = value & mask;
    reg &= ~(mask << start_bit);
    reg |= v << start_bit;
    TEX_ASSERT(value == GetBitField(reg, start_bit, bit_size), D_00176504, SetBitField_name, 229);
}
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _Z41__static_initialization_and_destruction_0ii_101494);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureaSERKS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC2EiiNS_6FormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC1EiiNS_6FormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC2EiiRKS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC1EiiRKS0_);

textures::Texture::~Texture()
{
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture5resetEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC2ERKS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC1ERKS0_);

int textures::Texture::width() const
{
    return m.info.width;
}

int textures::Texture::height() const
{
    return m.info.height;
}

textures::Format textures::Texture::format() const
{
    return m.info.format;
}

const char *textures::Texture::path() const
{
    return m.path.c_str();
}

textures::AlphaMask textures::Texture::alpha_flags() const
{
    return m.alpha_flags;
}

const unsigned char *textures::Texture::imagedata() const
{
    return image.addr();
}

const unsigned char *textures::Texture::clutdata() const
{
    return clut.addr();
}

int textures::Texture::getLoadedWidth() const
{
    return m.load.width ? m.load.width : m.info.width;
}

int textures::Texture::getLoadedHeight() const
{
    return m.load.height ? m.load.height : m.info.height;
}

int textures::Texture::getLoadedAlphaflags() const
{
    return m.load.alpha_flags;
}

void textures::Texture::setAlphaFlags(AlphaMask _Value)
{
    TEX_ASSERT(_Value == ALPHA_BLEND || _Value == ALPHA_TEST || _Value == 0, D_00176468, setAlphaFlags_name, 201);
    m.alpha_flags = _Value;
    if (_Value == ALPHA_BLEND || _Value == ALPHA_TEST)
        m.alpha_flags = (AlphaMask)(_Value | 1);
}

void textures::Texture::setTextureFunc(TextureFunction f)
{
    SetBitField(m.info.flags, f, 1, 2);
}

textures::TextureFunction textures::Texture::getTextureFunc() const
{
    return (TextureFunction)GetBitField(m.info.flags, 1, 2);
}

void textures::Texture::setFiltering(Filtering f)
{
    SetBitField(m.info.flags, f, 0, 1);
}

textures::Filtering textures::Texture::getFiltering() const
{
    return (Filtering)GetBitField(m.info.flags, 0, 1);
}

void textures::Texture::setWrapS(Wrapping w)
{
    SetBitField(m.info.flags, w, 3, 1);
}

textures::Wrapping textures::Texture::getWrapS() const
{
    return (Wrapping)GetBitField(m.info.flags, 3, 1);
}

void textures::Texture::setWrapT(Wrapping w)
{
    SetBitField(m.info.flags, w, 4, 1);
}

textures::Wrapping textures::Texture::getWrapT() const
{
    return (Wrapping)GetBitField(m.info.flags, 4, 1);
}

void textures::Texture::linear()
{
    setFiltering((Filtering)0);
}

void textures::Texture::nearest()
{
    setFiltering((Filtering)1);
}

bool textures::Texture::valid() const
{
    return image.addr() != 0;
}

bool textures::Texture::invalid() const
{
    return image.addr() == 0;
}

void textures::Texture::setPath(std::string p)
{
    m.path = p;
}

void textures::Texture::OverrideAlpha(int a)
{
    if (a == -1)
        override_alpha_on = false;
    else if (a == -2)
        override_alpha_on = true;
    else
        override_alpha_value = a;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture14set_4idx_pixelEiih);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture13make_from_bmpERKNS_17textures_internal3BmpE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture13make_from_tgaERKNS_17textures_internal3TgaE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture14make_from_argbEiPKh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture9makeDummyEii);

void textures::Texture::make(int w, int h, Format f)
{
    reset(false);
    m.info.width = w;
    m.info.height = h;
    m.info.format = f;
    allocate_for(f);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture5printERSo);

void textures::Texture::swap(Texture &t)
{
    common::Swap(m, t.m);
    image.swap(t.image);
    clut.swap(t.clut);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture4loadEPKc);

bool textures::Texture::is32() const
{
    return m.info.format == FORMAT_1 || m.info.format == FORMAT_2;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture9convert32Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture13alphaHalfBiasEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture11finish_loadEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures3psp13SwizzleBitmapEPhS1_NS_6FormatEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture11psp_reorderEv);

void textures::Texture::makeImportForDirectX(int w, int h)
{
    m.load.width = w;
    m.load.height = h;
    setAlphaCount(0, 0, 0, 0, 0xFF);
    m.load.alpha_flags = m.alpha_flags;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture12flipVerticalEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture22resize_channel_nearestERS0_NS_7ChannelE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture22resize_channel_bicubicERS0_NS_7ChannelERN4math7bspline7surfaceE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture14resize_nearestEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture14resize_bicubicEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture6resizeEiib);

int textures::closestPow2(int x, bool up)
{
    float f;
    int e;
    int lo;
    int hi;
    f = x;
    e = *(int *)&f >> 23;
    lo = 1 << (e - 127);
    hi = 1 << (e - 126);
    if (x == lo)
        return lo;
    if (x == hi)
        return hi;
    if (up)
        return hi;
    return lo;
}

void textures::Texture::resizePow2(bool up_x, bool up_y, bool filter)
{
    resize(closestPow2(m.info.width, up_x), closestPow2(m.info.height, up_y), filter);
}

bool textures::Texture::isPow2()
{
    return IsPow2(m.info.width) && IsPow2(m.info.height);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures10FormatNameENS_6FormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture10setChannelENS_7ChannelEh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture13invertChannelENS_7ChannelE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture11copyChannelENS_7ChannelEPh);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture11copyChannelENS_7ChannelES1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNK8textures7Texture11saveChannelENS_7ChannelEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture4copyERKS0_iiiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNK8textures7Texture4saveERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNK8textures7Texture7saveTgaERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNK8textures7Texture7saveBmpERKSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture4blurEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNK8textures7Texture4saveERKSsiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture13setAlphaCountEPiS1_S1_hh);

void textures::Texture::allocate(unsigned int n, unsigned int nclut)
{
    image.resize(n);
    clut.resize(nclut);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture12allocate_forENS_6FormatE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_101494");
void _GLOBAL__I__ZN8textures7TextureaSERKS0_(void);
void _GLOBAL__D__ZN8textures7TextureaSERKS0_(void);
}

void _GLOBAL__I__ZN8textures7TextureaSERKS0_(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN8textures7TextureaSERKS0_(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN6common7t_arrayIhEaSERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNK6common7t_arrayIhE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN6common4SwapIN8textures7Texture15CopiableMembersEEEvRT_S5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture7convertINS_4ABGRENS_4ARGBEEEvv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNSt6vectorIhSaIhEE7reserveEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNSt6vectorIhSaIhEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPhS1_EERKh);
