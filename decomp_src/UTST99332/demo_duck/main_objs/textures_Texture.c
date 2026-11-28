/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
/* the "" of Texture::CopiableMembers() stays in the module's .rodata (asm) */
extern const char D_0017641C[];
#define TEXTURE_EMPTY_PATH D_0017641C
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6common7t_arrayIhEaSERKS1_)
    DEMO_LINKONCE(_ZNK6common7t_arrayIhE4addrEv)
    DEMO_LINKONCE(_ZN6common4SwapIN8textures7Texture15CopiableMembersEEEvRT_S5_)
    DEMO_LINKONCE(_ZN8textures7Texture7convertINS_4ABGRENS_4ARGBEEEvv)
    DEMO_LINKONCE(_ZNSt6vectorIhSaIhEE7reserveEj)
    DEMO_LINKONCE(_ZNSt6vectorIhSaIhEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPhS1_EERKh)
);

/* the strings stay in the module's .rodata (asm) */
extern const char D_0017641C[];     /* "" */
extern const char D_0017645C[];     /* " *** error " */
extern const char D_00176468[];     /* "_Value == ALPHA_BLEND || _Value == ALPHA_TEST || _Value == 0" */
extern const char D_001764A8[];     /* "../lib/textures/Texture.cpp" */
extern const char D_001764C4[];     /* " " */
extern const char D_00176504[];     /* "value == GetBitField( reg, start_bit, bit_size )" */
extern const char SetBitField_name[] __asm__("_ZZN8textures11SetBitFieldERjiiiE19__PRETTY_FUNCTION__");
extern const char setAlphaFlags_name[] __asm__("_ZZN8textures7Texture13setAlphaFlagsENS_9AlphaMaskEE19__PRETTY_FUNCTION__");
extern const char D_0017693C[];     /* "\n" */
extern const char D_00176A88[];     /* "_m._format == ABGR32 || _m._format == BGR24" */
extern const char psp_reorder_name[] __asm__("_ZZN8textures7Texture11psp_reorderEvE19__PRETTY_FUNCTION__");
extern const char invertChannel_name[] __asm__("_ZZN8textures7Texture13invertChannelENS_7ChannelEE19__PRETTY_FUNCTION__");
namespace textures { namespace psp { void SwizzleBitmap(unsigned char *, unsigned char *, Format, int, int); } }
extern const char D_00176940[];     /* "valid()" */
extern const char D_00176CC4[];     /* "_Src" */
extern const char D_00176D18[];     /* "copyChannel " */
extern const char D_00176D28[];     /* " <- " */
extern const char D_00176C28[];     /* "setChannel " */
extern const char D_00176C34[];     /* " <- val=" */
extern const char setAlphaCount_name[] __asm__("_ZZN8textures7Texture13setAlphaCountEPiS1_S1_hhE19__PRETTY_FUNCTION__");
extern const char copyChannelP_name[] __asm__("_ZZN8textures7Texture11copyChannelENS_7ChannelEPhE19__PRETTY_FUNCTION__");
extern const char copyChannelC_name[] __asm__("_ZZN8textures7Texture11copyChannelENS_7ChannelES1_E19__PRETTY_FUNCTION__");
extern const char setChannel_name[] __asm__("_ZZN8textures7Texture10setChannelENS_7ChannelEhE19__PRETTY_FUNCTION__");
extern const char D_00176DD4[];     /* "_m._format == _Src._m._format" */
extern const char copy_name[] __asm__("_ZZN8textures7Texture4copyERKS0_iiiiiiE19__PRETTY_FUNCTION__");
extern const char resize_nearest_name[] __asm__("_ZZN8textures7Texture14resize_nearestEiiE19__PRETTY_FUNCTION__");
extern const char D_001767DC[];     /* ".tga" */
extern const char D_001767E4[];     /* ".bmp" */
extern const char D_00176E30[];     /* "bitsize != 0" */
extern const char saveChannel_name[] __asm__("_ZZNK8textures7Texture11saveChannelENS_7ChannelEPKcE19__PRETTY_FUNCTION__");
extern const char saveTga_name[] __asm__("_ZZNK8textures7Texture7saveTgaERKSsE19__PRETTY_FUNCTION__");
extern const char saveBmp_name[] __asm__("_ZZNK8textures7Texture7saveBmpERKSsE19__PRETTY_FUNCTION__");
namespace common { std::string GetFileExtension(std::string, bool); }
extern const char D_00176B54[];     /* "(" */
extern const char D_00176B58[];     /* "," */
extern const char D_00176B5C[];     /* ")->(" */
extern const char D_00176B64[];     /* ")\n" */
extern const char D_00176B68[];     /* " bicubic\n" */
extern const char D_00176B74[];     /* " nearest\n" */
extern const char resize_name[] __asm__("_ZZN8textures7Texture6resizeEiibE19__PRETTY_FUNCTION__");
extern const char resize_func[] __asm__("_ZZN8textures7Texture6resizeEiibE12__FUNCTION__");
extern const char D_001766AC[];     /* "-------------------------[texture info]-------------------------" */
extern const char D_001766F0[];     /* "path " */
extern const char D_001766F8[];     /* "x" */
extern const char D_001766FC[];     /* "image add:" */
extern const char D_00176708[];     /* " clut add:" */
extern const char D_00176714[];     /* "filtering: " */
extern const char D_00176720[];     /* "NEAREST" */
extern const char D_00176728[];     /* "LINEAR" */
extern const char D_00176730[];     /* "alpha flags:" */
extern const char D_00176740[];     /* " alpha ON " */
extern const char D_0017674C[];     /* " alpha OFF" */
extern const char D_00176758[];     /* "ALPHA_BLEND " */
extern const char D_00176768[];     /* "ALPHA_TEST " */
extern const char D_00176774[];     /* "HAS_0x00 " */
extern const char D_00176780[];     /* "HAS_0xFF " */
extern const char D_0017678C[];     /* "HAS_0x7E " */
extern const char D_00176798[];     /* "----------------------------------------------------------------" */
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

textures::Texture &textures::Texture::operator=(const Texture &t)
{
    reset(true);
    m = t.m;
    image = t.image;
    clut = t.clut;
    return *this;
}

textures::Texture::Texture()
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC2EiiNS_6FormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC1EiiNS_6FormatE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC2EiiRKS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC1EiiRKS0_);

textures::Texture::~Texture()
{
}

void textures::Texture::reset(bool all)
{
    if (!all) {
        std::string p = m.path;
        m = CopiableMembers();
        m.path = p;
    } else {
        m = CopiableMembers();
    }
    image.release();
    clut.release();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC2ERKS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7TextureC1ERKS0_);

int textures::Texture::width() const
{
    return m.width;
}

int textures::Texture::height() const
{
    return m.height;
}

textures::Format textures::Texture::format() const
{
    return m.format;
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
    return m.load.width ? m.load.width : m.width;
}

int textures::Texture::getLoadedHeight() const
{
    return m.load.height ? m.load.height : m.height;
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
    SetBitField(m.flags, f, 1, 2);
}

textures::TextureFunction textures::Texture::getTextureFunc() const
{
    return (TextureFunction)GetBitField(m.flags, 1, 2);
}

void textures::Texture::setFiltering(Filtering f)
{
    SetBitField(m.flags, f, 0, 1);
}

textures::Filtering textures::Texture::getFiltering() const
{
    return (Filtering)GetBitField(m.flags, 0, 1);
}

void textures::Texture::setWrapS(Wrapping w)
{
    SetBitField(m.flags, w, 3, 1);
}

textures::Wrapping textures::Texture::getWrapS() const
{
    return (Wrapping)GetBitField(m.flags, 3, 1);
}

void textures::Texture::setWrapT(Wrapping w)
{
    SetBitField(m.flags, w, 4, 1);
}

textures::Wrapping textures::Texture::getWrapT() const
{
    return (Wrapping)GetBitField(m.flags, 4, 1);
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

void textures::Texture::make_from_argb(int n, const unsigned char *src)
{
    allocate_for(FORMAT_1);
    unsigned char *dst = image.addr();
    for (int i = 0; i < n; i++) {
        dst[0] = src[2];
        dst[1] = src[1];
        dst[2] = src[0];
        dst[3] = override_alpha_on ? override_alpha_value : src[3];
        src += 4;
        dst += 4;
    }
}

void textures::Texture::makeDummy(int w, int h)
{
    make(w, h, (Format)1);
    setFiltering((Filtering)1);
    unsigned char *p = image.addr();
    for (int y = 0; y < m.height; y++)
        for (int x = 0; x < m.width; x++) {
            float c = (x + y) & 1;
            float r, g, b;
            r = g = b = c;
            if ((int)c == 0) {
                r = x / (m.width - 1.0f);
                g = y / (m.height - 1.0f);
                b = 1.0f;
            }
            p[0] = (unsigned char)(r * 255);
            p[1] = (unsigned char)(g * 255);
            p[2] = (unsigned char)(b * 255);
            p[3] = override_alpha_value;
            p += 4;
        }
}

void textures::Texture::make(int w, int h, Format f)
{
    reset(false);
    m.width = w;
    m.height = h;
    m.format = f;
    allocate_for(f);
}

void textures::Texture::print(std::ostream &o)
{
    unsigned char *img = image.addr();
    unsigned char *cl = clut.addr();
    o << D_001766AC << std::endl
      << D_001766F0 << m.path << D_001764C4 << m.width << D_001766F8 << m.height << D_001764C4
      << FormatName(m.format) << std::endl
      << D_001766FC << (void *)img << D_00176708 << (void *)cl << std::endl
      << D_00176714 << (getFiltering() == 1 ? D_00176720 : D_00176728) << std::endl
      << D_00176730 << (m.alpha_flags & 1 ? D_00176740 : D_0017674C);
    if (m.alpha_flags & 1) {
        o << (m.alpha_flags & ALPHA_BLEND ? D_00176758 : D_0017641C)
          << (m.alpha_flags & ALPHA_TEST ? D_00176768 : D_0017641C)
          << (m.alpha_flags & 8 ? D_00176774 : D_0017641C)
          << (m.alpha_flags & 0x10 ? D_00176780 : D_0017641C)
          << (m.alpha_flags & 0x20 ? D_0017678C : D_0017641C);
    }
    o << std::endl;
    o << D_00176798 << std::endl;
}

void textures::Texture::swap(Texture &t)
{
    common::Swap(m, t.m);
    image.swap(t.image);
    clut.swap(t.clut);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture4loadEPKc);

bool textures::Texture::is32() const
{
    return m.format == FORMAT_1 || m.format == FORMAT_2;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture9convert32Ev);

void textures::Texture::alphaHalfBias()
{
    if (m.format == FORMAT_1) {
        unsigned char *p = image.addr();
        for (unsigned i = 3; i < image.bytesize(); i += 4)
            p[i] >>= 1;
    }
}

extern const char D_00176960[];     /* "width or height or both are non power of 2\n" */

void textures::Texture::finish_load()
{
    if (!isPow2())
        common::Log() << D_00176960;
    m.load.width = m.width;
    m.load.height = m.height;
    if (m.format == FORMAT_1 || m.format == FORMAT_2)
        setAlphaCount(0, 0, 0, 0, 0xFF);
    m.load.alpha_flags = m.alpha_flags;
    psp_reorder();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures3psp13SwizzleBitmapEPhS1_NS_6FormatEii);

void textures::Texture::psp_reorder()
{
    Texture copy(*this);
    int unused[4];      /* the original's frame has 16 more bytes after copy */
    (void)unused;
    common::Log() << psp_reorder_name << D_001764C4 << m.path << D_0017693C;
    psp::SwizzleBitmap(image.addr(), copy.image.addr(), m.format, m.width, m.height);
    m.loaded = true;
}

void textures::Texture::makeImportForDirectX(int w, int h)
{
    m.load.width = w;
    m.load.height = h;
    setAlphaCount(0, 0, 0, 0, 0xFF);
    m.load.alpha_flags = m.alpha_flags;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture12flipVerticalEv);

void textures::Texture::resize_channel_nearest(Texture &dst, Channel c)
{
    if (m.width == 0 || m.height == 0)
        return;
    unsigned char *src = image.addr();
    unsigned char *d = dst.image.addr();
    int w = m.width;
    float fx = (float)(w - 1) / (float)(dst.m.width - 1);
    float fy = (float)(m.height - 1) / (float)(dst.m.height - 1);
    for (int y = 0; y < dst.m.height; y++) {
        int row = (int)(y * fy) * w;
        for (int x = 0; x < dst.m.width; x++) {
            int sx = (int)(x * fx);
            d[c] = (src + (sx + row) * 4)[c];
            d += 4;
        }
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture22resize_channel_bicubicERS0_NS_7ChannelERN4math7bspline7surfaceE);

void textures::Texture::resize_nearest(int w, int h)
{
    if (m.width == 0 || m.height == 0)
        return;
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, resize_nearest_name, 1295);
    Texture tmp(w, h, *this);
    int unused[4];      /* the original's frame has 16 more bytes after tmp */
    (void)unused;
    unsigned int *src = (unsigned int *)image.addr();
    unsigned int *d = (unsigned int *)tmp.image.addr();
    int sw = m.width;
    float fx = (float)(sw - 1) / (float)(tmp.m.width - 1);
    float fy = (float)(m.height - 1) / (float)(tmp.m.height - 1);
    for (int y = 0; y < tmp.m.height; y++) {
        int row = (int)(y * fy) * sw;
        for (int x = 0; x < tmp.m.width; x++) {
            int sx = (int)(x * fx);
            *d = src[sx + row];
            d++;
        }
    }
    swap(tmp);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures7Texture14resize_bicubicEii);

bool textures::Texture::resize(int w, int h, bool bicubic)
{
    if (m.width == 0 || m.height == 0)
        return false;
    if (w == m.width && h == m.height)
        return false;
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, resize_name, 1386);
    common::Log() << resize_func << D_00176B54 << m.width << D_00176B58 << m.height << D_00176B5C << w << D_00176B58 << h << D_00176B64;
    if (bicubic) {
        common::Log() << D_00176B68;
        resize_bicubic(w, h);
    } else {
        common::Log() << D_00176B74;
        resize_nearest(w, h);
    }
    return true;
}

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
    resize(closestPow2(m.width, up_x), closestPow2(m.height, up_y), filter);
}

bool textures::Texture::isPow2()
{
    return IsPow2(m.width) && IsPow2(m.height);
}

/* FormatName matches as tmp/cxx/drafts/s32/fn3.v (cases 2,1,3,4,5,0), but its jump table (0x176BC8) is outside the unit's carved .rodata */
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZN8textures10FormatNameENS_6FormatE);

void textures::Texture::setChannel(Channel c, unsigned char v)
{
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, setChannel_name, 1482);
    unsigned char *p = image.addr();
    p += c;
    for (unsigned int i = 0; i < (unsigned int)(m.width * m.height); i++) {
        *p = v;
        p += 4;
    }
    common::Log() << D_00176C28 << (int)c << D_00176C34 << (int)v << D_0017693C;
}

void textures::Texture::invertChannel(Channel c)
{
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, invertChannel_name, 1504);
    unsigned char *p = image.addr() + c;
    for (int i = 0; i < m.width * m.height; i++) {
        *p = ~*p;
        p += 4;
    }
}

void textures::Texture::copyChannel(Channel c, unsigned char *_Src)
{
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, copyChannelP_name, 1524);
    TEX_ASSERT(_Src, D_00176CC4, copyChannelP_name, 1525);
    unsigned char *dst = image.addr();
    unsigned char *src = _Src;
    dst += c;
    for (int i = 0; i < m.width * m.height; i++) {
        *dst = *src;
        src += 4;
        dst += 4;
    }
}

void textures::Texture::copyChannel(Channel dst_c, Channel src_c)
{
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, copyChannelC_name, 1544);
    if (src_c != dst_c) {
        unsigned char *dst = image.addr();
        unsigned char *src = image.addr();
        dst += dst_c;
        src += src_c;
        for (unsigned int i = 0; i < (unsigned int)(m.width * m.height); i++) {
            *dst = *src;
            src += 4;
            dst += 4;
        }
        common::Log() << D_00176D18 << (int)dst_c << D_00176D28 << (int)src_c << D_0017693C;
    }
}

int textures::Texture::saveChannel(Channel c, const char *filename) const
{
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, saveChannel_name, 1578);
    Texture tmp(*this);
    int unused[4];      /* the original's frame has 16 more bytes after tmp */
    (void)unused;
    tmp.copyChannel((Channel)0, c);
    tmp.copyChannel((Channel)1, c);
    tmp.copyChannel((Channel)2, c);
    tmp.copyChannel((Channel)3, c);
    return tmp.save(filename);
}

void textures::Texture::copy(const Texture &_Src, int sx, int sy, int w, int h, int dx, int dy)
{
    TEX_ASSERT(m.format == FORMAT_1 || m.format == FORMAT_2, D_00176A88, copy_name, 1598);
    TEX_ASSERT(m.format == _Src.m.format, D_00176DD4, copy_name, 1600);
    unsigned int *src = (unsigned int *)const_cast<Texture &>(_Src).image.addr();
    unsigned int *dst = (unsigned int *)image.addr();
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            int x0 = sx + i;
            int y0 = sy + j;
            int x1 = dx + i;
            int y1 = dy + j;
            if (x0 >= 0)
                if (x0 < _Src.m.width)
                    if (y0 >= 0)
                        if (y0 < _Src.m.height)
                            if (x1 >= 0)
                                if (x1 < m.width)
                                    if (y1 >= 0)
                                        if (y1 < m.height)
                                            {
                                                unsigned int *d = dst + (x1 + y1 * m.width);
                                                *d = src[x0 + y0 * _Src.m.width];
                                            }
        }
    }
}

int textures::Texture::save(const std::string &path) const
{
    std::string ext = common::GetFileExtension(path.c_str(), true);
    if (ext == D_001767DC)
        return saveTga(path);
    if (ext == D_001767E4)
        return saveBmp(path);
    return -1;
}

int textures::Texture::saveTga(const std::string &path) const
{
    TEX_ASSERT(valid(), D_00176940, saveTga_name, 1648);
    Texture tmp(*this);
    int unused[4];      /* the original's frame has 16 more bytes after tmp */
    (void)unused;
    if (!(tmp.m.format == FORMAT_1 || tmp.m.format == FORMAT_2 || tmp.m.format == FORMAT_3))
        tmp.convert32();
    int bitsize = 0;
    if (tmp.m.format == FORMAT_1)
        bitsize = 32;
    else if (tmp.m.format == FORMAT_2)
        bitsize = 24;
    else if (tmp.m.format == FORMAT_3)
        bitsize = 16;
    TEX_ASSERT(bitsize != 0, D_00176E30, saveTga_name, 1667);
    SaveTga(path.c_str(), tmp.width(), tmp.height(), tmp.imagedata(), bitsize);
    return 0;
}

int textures::Texture::saveBmp(const std::string &path) const
{
    TEX_ASSERT(valid(), D_00176940, saveBmp_name, 1682);
    Texture tmp(*this);
    int unused[4];      /* the original's frame has 16 more bytes after tmp */
    (void)unused;
    if (!(tmp.m.format == FORMAT_1 || tmp.m.format == FORMAT_2 || tmp.m.format == FORMAT_3 ||
          tmp.m.format == FORMAT_4 || tmp.m.format == FORMAT_5))
        tmp.convert32();
    int bitsize = 0;
    if (tmp.m.format == FORMAT_1)
        bitsize = 24;
    else if (tmp.m.format == FORMAT_2)
        bitsize = 24;
    else if (tmp.m.format == FORMAT_3)
        bitsize = 16;
    else if (tmp.m.format == FORMAT_4)
        bitsize = 8;
    else if (tmp.m.format == FORMAT_5)
        bitsize = 4;
    TEX_ASSERT(bitsize != 0, D_00176E30, saveBmp_name, 1703);
    SaveBmp(path.c_str(), tmp.width(), tmp.height(), tmp.imagedata(), tmp.clutdata(), bitsize);
    return 0;
}

void textures::Texture::blur(int radius, float sigma)
{
    if (radius) {
        FloatImage f(*this);
        f.blur(radius, sigma);
        f.copy(*this);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/textures_Texture", _ZNK8textures7Texture4saveERKSsiiii);

int textures::Texture::setAlphaCount(int *n_lo, int *n_hi, int *n_mid, unsigned char lo, unsigned char hi)
{
    TEX_ASSERT(valid(), D_00176940, setAlphaCount_name, 1807);
    int c_lo = 0;
    int c_hi = 0;
    int c_mid = 0;
    unsigned char *p = 0;
    unsigned int n = 0;
    if (m.format == FORMAT_1 || m.format == FORMAT_2) {
        p = image.addr() + 3;
        n = m.width * m.height;
    } else if (m.format == FORMAT_4) {
        p = clut.addr() + 3;
        n = 256;
    } else if (m.format == FORMAT_5) {
        p = clut.addr() + 3;
        n = 16;
    }
    for (unsigned int i = 0; i < n; i++) {
        if (*p <= lo)
            c_lo++;
        else if (*p >= hi)
            c_hi++;
        else
            c_mid++;
        p += 4;
    }
    if (n_lo)
        *n_lo = c_lo;
    if (n_hi)
        *n_hi = c_hi;
    if (n_mid)
        *n_mid = c_mid;
    m.alpha_flags = (AlphaMask)0;
    if (c_lo)
        m.alpha_flags = (AlphaMask)8;
    if (c_hi)
        m.alpha_flags = (AlphaMask)(m.alpha_flags | 0x10);
    if (c_mid)
        m.alpha_flags = (AlphaMask)(m.alpha_flags | 0x20);
    bool ret;
    if (c_lo && !c_hi && !c_mid)
        ret = false;
    else if (!c_lo && c_hi && !c_mid)
        ret = false;
    else {
        m.alpha_flags = (AlphaMask)(m.alpha_flags | (c_mid ? ALPHA_BLEND : ALPHA_TEST));
        m.alpha_flags = (AlphaMask)(m.alpha_flags | 1);
        ret = true;
    }
    return ret;
}

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

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

namespace textures {
inline void ConvertPixel(ABGR &d, const ARGB &s)
{
    unsigned int c = s.c;
    d.a = c >> 24;
    d.r = c >> 16;
    d.g = c >> 8;
    d.b = c;
}
}

template<class D, class S> void textures::Texture::convert()
{
    if (format() == FORMAT_1 || format() == FORMAT_2) {
        D *dst = (D *)image.addr();
        S *src = (S *)image.addr();
        for (int i = 0; i < m.width * m.height; i++) {
            ConvertPixel(*dst, *src);
            dst++;
            src++;
        }
    }
}

/* asm functions use these instances */
void textures_Texture_uses() __attribute__((section(".discard.instances")));
void textures_Texture_uses()
{
    std::vector<unsigned char> v;
    v.reserve(0);
    v.push_back(0);
    ((textures::Texture *)0)->convert<textures::ABGR, textures::ARGB>();
}
