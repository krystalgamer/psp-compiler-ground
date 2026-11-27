/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_HEADER_STATICS
#include "main.hpp"
#include "gl.hpp"

/* the module's .ctors/.dtors (asm) refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN10WaterPatchC2Ejjfiff");
__asm__(".globl _GLOBAL__D__ZN10WaterPatchC2Ejjfiff");

static unsigned int mipmap_offset[5];

/* the strings stay in the module's .rodata (asm) */
extern const char D_0015DB64[];     /* " *** error " */
extern const char D_0015DB70[];     /* " " */
extern const char D_0015DB74[];     /* "k == _indices.size()" */
extern const char D_0015DB8C[];     /* "WaterPatch.cpp" */
extern const char D_0015DB9C[];     /* "_ny!=0" */
extern const char D_0015DBA4[];     /* "_nx!=0" */
extern const char WaterPatch_ctor_name[] __asm__("_ZZN10WaterPatchC1EjjfiffE19__PRETTY_FUNCTION__");
#define WP_ASSERT(c, s, line) \
    if (!(c)) { \
        common::common_internal::assert_display(D_0015DB64, s, D_0015DB8C, WaterPatch_ctor_name, line, D_0015DB70); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

WaterPatch::WaterPatch(unsigned int nx, unsigned int ny, float size, int mode, float damping, float speed)
    : _nx(nx), _ny(ny), _size(size), _pos(nx * ny), _normal(nx * ny), _vtx0(nx * ny), _vtx1(nx * ny),
      _indices((ny * 2 - 2) * nx), _damping(damping), _mode(mode), _count(0), _last(0), _speed(speed), _accum(0),
      _fa4(true), _fa5(false), _fa6(true), _transform(math::matrix::Identity())
{
    WP_ASSERT(_nx != 0, D_0015DBA4, 54);
    WP_ASSERT(_ny != 0, D_0015DB9C, 55);
    _h0 = new float[_nx * _ny];
    _h1 = new float[_nx * _ny];
    unsigned int k = 0;
    for (unsigned int j = 0; j < _ny - 1; j++)
        for (unsigned int i = 0; i != _nx; i++) {
            _indices[k++] = j * _nx + i;
            _indices[k++] = (j + 1) * _nx + i;
        }
    WP_ASSERT(k == _indices.size(), D_0015DB74, 72);
    reset();
}

WaterPatch::~WaterPatch()
{
    delete[] _h0;
    delete[] _h1;
}


void WaterPatch::reset()
{
    vertex_formats::T2UB_V3F *v = &_vtx0[0];
    math::vector_xyzw *pos = &_pos[0];
    math::vector_xyzw *normal = &_normal[0];
    unsigned int k = 0;
    for (unsigned int j = 0; j < _ny; j++)
        for (unsigned int i = 0; i < _nx; i++) {
            v->p.x = _size * i - (_nx - 1) * _size * 0.5f;
            v->p.y = _size * j - (_ny - 1) * _size * 0.5f;
            v->p.z = 0;
            *pos = math::vector_xyzw(v->p.x, v->p.y, 0, 1);
            *normal = math::vector_xyzw(0, 0, 0, 0);
            math::vector_xyz uv(i / (float)(_nx - 1), j / (float)(_ny - 1), 0);
            pos++;
            normal++;
            v++;
            k++;
        }
    _min = _vtx0.front();
    _max = _vtx0.back();
    for (k = 0; k < _nx * _ny; k++) {
        _h0[k] = 0;
        _h1[k] = 0;
    }
    _h = _h0;
    _hprev = _h1;
}

bool WaterPatch::setf(float x, float y, float v)
{
    return set((int)(x * _nx), (int)(y * _ny), v);
}

float WaterPatch::set_disk(math::vector_xyzw c, float radius, float, float height)
{
    if (radius <= 0)
        return 0;
    int r = (int)(radius / _size);
    if (r == 0)
        r = 1;
    int cx = (int)(c.x / _size + ((float)_nx - 1) * 0.5f);
    int cy = (int)(c.y / _size + ((float)_ny - 1) * 0.5f);
    static int seed;
    seed++;
    for (int i = -r; i <= r; i++)
        for (int j = -r; j <= r; j++)
            if (i * i + j * j <= r * r)
                set(cx + i, cy + j, height);
    return 0;
}

bool WaterPatch::set(unsigned int x, unsigned int y, float v)
{
    bool ret = false;
    if (x < _nx && y < _ny) {
        _h[x + y * _nx] = v;
        ret = true;
    }
    return ret;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatch4idleEf);

void WaterPatch::drawAsPlane(bool big) const
{
    glPushMatrix();
    glMultMatrixf(&_transform.r[0].x);
    if (big)
        glScalef(1000, 1000, 1000);
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glNormal3f(0, 0, 1);
    glVertex3f(_min.p.x, _min.p.y, 0);
    glVertex3f(_max.p.x, _min.p.y, 0);
    glVertex3f(_max.p.x, _max.p.y, 0);
    glVertex3f(_min.p.x, _max.p.y, 0);
    glEnd();
    glPopMatrix();
}

void WaterPatch::drawW(bool) const
{
    glPushMatrix();
    glMultMatrixf(&_transform.r[0].x);
    glDisable(GL_LIGHTING);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 1);
    glNormal3f(0, 0, 1);
    glVertex3f(_min.p.x, _min.p.y, 0);
    glVertex3f(_max.p.x, _min.p.y, 0);
    glVertex3f(_max.p.x, _max.p.y, 0);
    glVertex3f(_min.p.x, _max.p.y, 0);
    glEnd();
    glPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatch7reflectEv);

void WaterPatch::prepareRefraction() const
{
    unsigned int base = psp::vram.f68;
    mipmap_offset[0] = base;
    mipmap_offset[1] = base + 0x20000;
    mipmap_offset[2] = mipmap_offset[1] + 0x8000;
    mipmap_offset[3] = mipmap_offset[2] + 0x2000;
    mipmap_offset[4] = mipmap_offset[2] + 0x2800;
    if (!_fa4)
        return;
    psp::vram.copyImageBegin(_fa6);
    psp::vram.copyImageSrcPf((psp::PixelFormat)3);
    psp::vram.copyImageDstPf((psp::PixelFormat)1);
    if (!_fa5) {
        psp::vram.copyImage(0x1E0, 0x110, 0x80, 0x80, psp::vram.displayBuffer(), (void *)mipmap_offset[0]);
    } else {
        char *edram = (char *)sceGeEdramGetAddr();
        psp::vram.copyImage(0x1E0, 0x110, 0x100, 0x100, psp::vram.displayBuffer(), (void *)mipmap_offset[0]);
        psp::vram.copyImageSrcPf((psp::PixelFormat)1);
        psp::vram.copyImage(0x100, 0x100, 0x80, 0x80, edram + mipmap_offset[0], (void *)mipmap_offset[1]);
        psp::vram.copyImage(0x80, 0x80, 0x40, 0x40, edram + mipmap_offset[1], (void *)mipmap_offset[2]);
        psp::vram.copyImage(0x40, 0x40, 0x20, 0x20, edram + mipmap_offset[2], (void *)mipmap_offset[3]);
        psp::vram.copyImage(0x20, 0x20, 0x10, 0x10, edram + mipmap_offset[3], (void *)mipmap_offset[4]);
    }
    psp::vram.copyImageEnd();
}

void WaterPatch::draw(Pass) const
{
    glPushMatrix();
    glMultMatrixf(&_transform.r[0].x);
    if (_ny < 2 || _nx < 2)
        return;
    sceGuDisable(5);
    sceGuTexFlush();
    glPushAttrib(0x2000);
    if (_fa4) {
        sceGuDisable(10);
        glEnable(0x0DE1);
        glEnable(0x0BE2);
        glBlendFunc(0x302, 0x303);
        char *edram = (char *)sceGeEdramGetAddr();
        sceGuTexFilter(7, 1);
        if (!_fa5) {
            sceGuTexImage(0, 0x80, 0x80, 0x80, edram + mipmap_offset[0]);
            sceGuTexMode(1, 0, 0, 0);
        } else {
            sceGuTexImage(0, 0x100, 0x100, 0x100, edram + mipmap_offset[0]);
            sceGuTexImage(1, 0x80, 0x80, 0x80, edram + mipmap_offset[1]);
            sceGuTexImage(2, 0x40, 0x40, 0x40, edram + mipmap_offset[2]);
            sceGuTexImage(3, 0x20, 0x20, 0x20, edram + mipmap_offset[3]);
            sceGuTexImage(4, 0x10, 0x10, 0x10, edram + mipmap_offset[4]);
            sceGuTexMode(1, 4, 0, 0);
            sceGuTexLevelMode(0, 0);
        }
        sceGuTexFunc(0, 0);
        sceGuTexWrap(1, 1);
    } else {
        glDisable(0x0DE1);
    }
    const vertex_formats::T2UB_V3F *vtx = &_vtx0[0];
    sceGuColor(0xC0FFFF40);
    const unsigned short *idx = &_indices[0];
    unsigned int n = _nx * 2;
    for (unsigned int j = 0; j != _ny - 1; j++) {
        sceGumDrawArray(4, 0x1181, n, idx, vtx);
        idx += n;
    }
    sceGuTexFlush();
    glPopAttrib();
    sceGuTexFilter(1, 1);
    sceGuEnable(5);
    glPopMatrix();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatch6updateEv);
