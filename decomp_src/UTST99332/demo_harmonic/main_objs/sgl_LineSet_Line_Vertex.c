/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN3sgl7LineSet4Line6VertexC2Ev\n_GLOBAL__I__ZN3sgl7LineSet4Line6VertexC2Ev = _GLOBAL__I__ZN3sgl7LineSet4Line6VertexC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN3sgl7LineSet4Line6VertexC2Ev\n_GLOBAL__D__ZN3sgl7LineSet4Line6VertexC2Ev = _GLOBAL__D__ZN3sgl7LineSet4Line6VertexC2Ev__asm");

extern const char D_0016B148[];     /* "../lib/sgl/LineSet.cpp" */
extern const char D_0016B1E0[];     /* " *** error " */
extern const char D_0016B1EC[];     /* "! ready()" */
extern const char D_0016B1F8[];     /* "forgot a call to LineSet::end()" */
extern const char D_0016B240[];     /* "ready()" */
extern const char D_0016B248[];     /* "forgot a call to LineSet::begin()" */
extern const char begin_name[] __asm__("_ZZN3sgl7LineSet5beginENS_8LineModeEE19__PRETTY_FUNCTION__");
extern const char color_name[] __asm__("_ZZN3sgl7LineSet5colorENS_5ColorEE19__PRETTY_FUNCTION__");
extern const char end_name[] __asm__("_ZZN3sgl7LineSet3endEvE19__PRETTY_FUNCTION__");
#define LS_ASSERT(c, text, fn, line, msg) SGL_ASSERT(c, D_0016B1E0, text, D_0016B148, fn, line, msg)

sgl::LineSet::Line::Vertex::Vertex()
{
}

bool sgl::LineSet::Line::zero_length() const
{
    math::vector_xyzw d = a.p - b.p;
    return sqrtf(math::dot(d, d)) < 0.000001f;
}

/* STAND-IN: float pointer views: the original orders each first component's load/store before the other loads
   (its vector_xyzw has x()/y()/w() accessors over an array, cf. the "_p.y()"/"light.w()" assert texts) */
static inline void ls_scale(math::vector_xyzw &v, float s) { float *p = &v.x; p[0] *= s; p[1] *= s; p[2] *= s; p[3] *= s; }
static inline void ls_neg(math::vector_xyzw &v) { float *p = &v.x; p[0] = -p[0]; p[1] = -p[1]; p[2] = -p[2]; p[3] = -p[3]; }
void sgl::LineSet::invert_normal_vectors()
{
    for (std::vector<Line>::iterator i = _lines.begin(); i != _lines.end(); ++i) {
        ls_scale(i->c, -11.0f);
        ls_neg(i->b.m);
        ls_neg(i->a.m);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet19calc_normal_vectorsEf);

sgl::LineSet::LineSet() : _f0(0), _color(0, 0, 0, 0)
{
    float a = 30;   /* the original multiplies at run time */
    _state = 3;
    _crease = a * 0.0174532924f;
    _negate_normals = false;
}

void sgl::LineSet::begin(LineMode m)
{
    LS_ASSERT(!ready(), D_0016B1EC, begin_name, 138, D_0016B1F8);
    _state = m;
}

void sgl::LineSet::color(Color c)
{
    LS_ASSERT(ready(), D_0016B240, color_name, 145, D_0016B248);
    _color = c;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet6vertexENS_8PositionE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_LineSet_Line_Vertex", _ZN3sgl7LineSet3endEv);

bool sgl::LineSet::ready() const
{
    return _state != 3;
}

void sgl::LineSet::set_negate_normals(bool v)
{
    _negate_normals = v;
}

void sgl::LineSet::set_crease(float v)
{
    _crease = v;
}

extern "C" void sgl_LineSet_Line_Vertex_instances(std::vector<sgl::LineSet::Line> *v, const sgl::LineSet::Line *l, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sgl_LineSet_Line_Vertex_instances(std::vector<sgl::LineSet::Line> *v, const sgl::LineSet::Line *l, unsigned int n)
{
    v->resize(n);
    v->push_back(*l);
}
