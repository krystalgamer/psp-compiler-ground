/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "main.hpp"

/* these template instances are still asm below */
namespace std {
extern template math::vector_xyzw *__uninitialized_fill_n_aux(math::vector_xyzw *, unsigned int,
                                                              const math::vector_xyzw &, __false_type);
extern template vertex_formats::T2UB_V3F *__uninitialized_fill_n_aux(vertex_formats::T2UB_V3F *, unsigned int,
                                                                     const vertex_formats::T2UB_V3F &, __false_type);
extern template unsigned short *fill_n(unsigned short *, unsigned int, const unsigned short &);
}

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

/* emitted first, like the static constructors -O3 puts before the deferred functions */
__asm__(".set noat\n.set noreorder\n"
        ".include \"tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch/_Z41__static_initialization_and_destruction_0ii_3E8.s\"\n"
        ".set reorder\n.set at\n");

WaterPatch::WaterPatch(unsigned int nx, unsigned int ny, float size, int mode, float damping, float speed)
    : _nx(nx), _ny(ny), _size(size), _pos(nx * ny), _normal(nx * ny), _vtx0(nx * ny), _vtx1(nx * ny),
      _indices((ny * 2 - 2) * nx), _damping(damping), _mode(mode), _f80(0), _f84(0), _speed(speed), _f8c(0),
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatchD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatchD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatch5resetEv);

bool WaterPatch::setf(float x, float y, float v)
{
    return set((int)(x * _nx), (int)(y * _ny), v);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatch8set_diskEN4math11vector_xyzwEfff);

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
    glMultMatrixf(&_transform.r0.x);
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
    glMultMatrixf(&_transform.r0.x);
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZNK10WaterPatch17prepareRefractionEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZNK10WaterPatch4drawENS_4PassE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZN10WaterPatch6updateEv);

#ifndef NULL
#define NULL ((void *)0)
#endif

extern "C" {
void static_init_3E8(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_3E8");
void _GLOBAL__I__ZN10WaterPatchC2Ejjfiff(void);
void _GLOBAL__D__ZN10WaterPatchC2Ejjfiff(void);
}

void _GLOBAL__I__ZN10WaterPatchC2Ejjfiff(void)
{
    static_init_3E8(1, 0xFFFF);
}

void _GLOBAL__D__ZN10WaterPatchC2Ejjfiff(void)
{
    static_init_3E8(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZSt26__uninitialized_fill_n_auxIPN4math11vector_xyzwEjS1_ET_S3_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZSt26__uninitialized_fill_n_auxIPN14vertex_formats8T2UB_V3FEjS1_ET_S3_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/WaterPatch", _ZSt6fill_nIPtjtET_S1_T0_RKT1_);
