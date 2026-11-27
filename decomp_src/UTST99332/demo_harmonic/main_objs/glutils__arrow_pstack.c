/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"
#include "UTST99332/demo_duck/gl.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN7glutils6Params9UnitFrameC1Ev)
    DEMO_LINKONCE(_ZN7glutils6Params13CircularArrowC1Ev)
    DEMO_LINKONCE(_ZN7glutils11ParamsStackINS_6Params5PointEE3popEv)
    DEMO_LINKONCE(_ZN7glutils11ParamsStackINS_6Params5ArrowEE3popEv)
    DEMO_LINKONCE(_ZN7glutils11ParamsStackINS_6Params9UnitFrameEE3popEv)
    DEMO_LINKONCE(_ZN7glutils11ParamsStackINS_6Params13CircularArrowEE3popEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5PointESaIS2_EE4backEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5PointESaIS2_EE9push_backERKS2_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE4backEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE9push_backERKS2_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE4backEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE9push_backERKS2_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE4backEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE9push_backERKS2_)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EED2Ev)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EED2Ev)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EED2Ev)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EED2Ev)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EE17_M_initialize_mapEj)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EE16_M_destroy_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EE17_M_initialize_mapEj)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EE16_M_destroy_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EE17_M_initialize_mapEj)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EE16_M_destroy_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EE17_M_initialize_mapEj)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EE16_M_destroy_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5PointESaIS2_EE16_M_push_back_auxERKS2_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5PointESaIS2_EE15_M_pop_back_auxEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE16_M_push_back_auxERKS2_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE15_M_pop_back_auxEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE16_M_push_back_auxERKS2_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE15_M_pop_back_auxEv)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE16_M_push_back_auxERKS2_)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE15_M_pop_back_auxEv)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5ArrowESaIS2_EE15_M_create_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params5ArrowERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params13CircularArrowESaIS2_EE15_M_create_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params13CircularArrowERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params9UnitFrameESaIS2_EE15_M_create_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params9UnitFrameERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIN7glutils6Params5PointESaIS2_EE15_M_create_nodesEPPS2_S6_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN7glutils6Params5PointERKS3_PS4_ES0_IS3_RS3_PS3_EET0_T_SC_SB_12__false_type)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5PointESaIS2_EE17_M_reallocate_mapEjb)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params5ArrowESaIS2_EE17_M_reallocate_mapEjb)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params9UnitFrameESaIS2_EE17_M_reallocate_mapEjb)
    DEMO_LINKONCE(_ZNSt5dequeIN7glutils6Params13CircularArrowESaIS2_EE17_M_reallocate_mapEjb)
);

/* glutils.hpp's drawing parameter stacks.  The module's .rodata stays asm (only the jump tables are
   this unit's): the inline constructors take their float pools (the caller's) as arguments. */
extern "C" const char D_001644D4[], D_001644E0[], D_001644F4[], D_00164510[];
#define GLUTILS_PSTACK_FN(F, T) \
    extern const char glutils_##F##_##T##_fn[] __asm__("_ZZN7glutils11ParamsStackINS_6Params" #T "EE" #F "EvE19__PRETTY_FUNCTION__");
GLUTILS_PSTACK_FN(3top, 5Point)
GLUTILS_PSTACK_FN(3top, 5Arrow)
GLUTILS_PSTACK_FN(3top, 9UnitFrame)
GLUTILS_PSTACK_FN(3top, 13CircularArrow)
GLUTILS_PSTACK_FN(3pop, 5Point)
GLUTILS_PSTACK_FN(3pop, 5Arrow)
GLUTILS_PSTACK_FN(3pop, 9UnitFrame)
GLUTILS_PSTACK_FN(3pop, 13CircularArrow)

namespace glutils {
namespace Params {
struct Point {
    float size;                         /* 0x0 */
    unsigned int slices, stacks;        /* 0x4 */
    Point(const float *k) : size(k[0]), slices(8), stacks(8) {}     /* 0.01f */
    static const char *top_fn() { return glutils_3top_5Point_fn; }
    static const char *pop_fn() { return glutils_3pop_5Point_fn; }
};
struct Arrow {
    float a, b, c;                      /* 0x0 */
    int d, e;                           /* 0xC */
    float f;                            /* 0x14 */
    Arrow(const float *k) : a(k[0]), b(k[1]), c(k[2]), d(12), e(8), f(k[3]) {}  /* 0.03f, 0.22f, 0.013f, 1.0f */
    static const char *top_fn() { return glutils_3top_5Arrow_fn; }
    static const char *pop_fn() { return glutils_3pop_5Arrow_fn; }
};
struct UnitFrame {
    float f0, f4, f8, fC;               /* 0x0 */
    int i10, i14;                       /* 0x10 */
    unsigned char c18;                  /* 0x18 */
    math::vector_xyzw v1C, v2C, v3C;    /* 0x1C */
    float f4C;                          /* 0x4C */
    /* 1.0f, 0.03f, 0.22f, 0.013f, 12, 8, 7, (0, 0, 1, 0), (0, 1, 0, 0), (1, 0, 0, 0), 1.0f; not inlined */
    UnitFrame();
    static const char *top_fn() { return glutils_3top_9UnitFrame_fn; }
    static const char *pop_fn() { return glutils_3pop_9UnitFrame_fn; }
};
struct CircularArrow {
    math::vector_xyzw center;           /* 0x0 */
    float f10, f14, f18, f1C;           /* 0x10 */
    int i20, i24;                       /* 0x20 */
    float f28, f2C;                     /* 0x28 */
    int i30;                            /* 0x30 */
    float f34;                          /* 0x34 */
    /* (0, 0, 0, 1.0f), 0.3f, 0.02f, 0, 4.712389f, 8, 32, 0.05f, 0.2f, 8, 1.0f */
    CircularArrow(const float *k)
        : center(0, 0, 0, k[0]), f10(k[1]), f14(k[2]), f18(0), f1C(k[3]), i20(8), i24(32),
          f28(k[4]), f2C(k[5]), i30(8), f34(k[0]) {}
    static const char *top_fn() { return glutils_3top_13CircularArrow_fn; }
    static const char *pop_fn() { return glutils_3pop_13CircularArrow_fn; }
};
}
template<class T> class ParamsStack {
public:
    void push() { _stack.push(_stack.empty() ? T() : _stack.top()); }
    void push(const float *k) { _stack.push(_stack.empty() ? T(k) : _stack.top()); }
    T &top()
    {
        if (!(!_stack.empty())) {
            common::common_internal::assert_display(D_001644D4, D_001644E0, D_001644F4, T::top_fn(), 145, D_00164510);
            common::common_internal::on_error();
            common::common_internal::clash();
        }
        return _stack.top();
    }
    void pop();
    std::stack<T> _stack;
};
template<class T> void ParamsStack<T>::pop()
{
    if (!(!_stack.empty())) {
        common::common_internal::assert_display(D_001644D4, D_001644E0, D_001644F4, T::pop_fn(), 152, D_00164510);
        common::common_internal::on_error();
        common::common_internal::clash();
    }
    _stack.pop();
}
}

extern "C" {
void glBegin(GLenum);
void glVertex3fv(const GLfloat *);
void glColor3fv(const GLfloat *);
void glRotatef(GLfloat, GLfloat, GLfloat, GLfloat);
void glLineWidth(GLfloat);
}

namespace gl {
void Translatefv(const math::vector_xyzw &);
}

namespace glutils {
enum FloatParams { };
enum IntParams { };
enum UnsignedCharParams { };
enum VectorParams { };
void SetParam(FloatParams, float);
void SetParam(IntParams, int);
void SetParam(UnsignedCharParams, unsigned char);
void SetParam(VectorParams, math::vector_xyzw);
void DrawCoordinateSystem();
void DrawCoordinateSystem(float, float, float, float, int, int, unsigned char, math::vector_xyzw, math::vector_xyzw, math::vector_xyzw);
void DrawPoint(math::vector_xyzw, float, unsigned int, unsigned int);
void DrawPoint(math::vector_xyzw);
void DrawArrow(const math::vector_xyzw &from, const math::vector_xyzw &to);
void DrawArrow(const math::vector_xyzw &from, const math::vector_xyzw &to, float, float, float, int, int);
void DrawCircularArrow();
void DrawCircularArrow(math::vector_xyzw, float, float, float, float, int, int, float, float, int);
void DrawCircularArrow2d(math::vector_xyzw, float, float, float, float, int, float, float);
void DrawCircularArrow2d();
void DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v);
void DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v, float a, float b, float c, int d, int e);
void DrawMayaGroundPlane(bool);
void SolidCylinder(float, float, int, bool);
void DrawRectangle(float x, float y, float z, float w, float h, bool fill);
void DrawRectangleC(float x, float y, float z, float w, float h, bool fill);
void PreTransform(math::matrix &, math::matrix &, math::matrix &, math::matrix &, bool);
void DrawLocalRotateWidget(float, bool, bool);
void DrawSphere(float, int, int, float, float);
void DrawCone(float, float, int, int);
void DrawCircle(float, int, float, float);
void DrawTorus(float, float, int, int, float, float, bool);
void DrawFlatTorus(float, float, int, float, float);
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _Z41__static_initialization_and_destruction_0ii_3AD98);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils15PushPointParamsEv);

void glutils::PopPointParams()
{
    _point_pstack.pop();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils15PushArrowParamsEv);

void glutils::PopArrowParams()
{
    _arrow_pstack.pop();
}

void glutils::PushUnitFrameParams()
{
    _unit_frame_pstack.push();
}

void glutils::PopUnitFrameParams()
{
    _unit_frame_pstack.pop();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils23PushCircularArrowParamsEv);

void glutils::PopCircularArrowParams()
{
    _circular_arrow_pstack.pop();
}

void glutils::SetParam(FloatParams p, float v)
{
    switch (p) {
    case 0: _unit_frame_pstack.top().f0 = v; break;
    case 1: _unit_frame_pstack.top().f4 = v; break;
    case 2: _unit_frame_pstack.top().f8 = v; break;
    case 3: _unit_frame_pstack.top().fC = v; break;
    case 4: _unit_frame_pstack.top().f4C = v; break;
    case 5: _circular_arrow_pstack.top().f10 = v; break;
    case 6: _circular_arrow_pstack.top().f14 = v; break;
    case 7: _circular_arrow_pstack.top().f18 = v; break;
    case 8: _circular_arrow_pstack.top().f1C = v; break;
    case 9: _circular_arrow_pstack.top().f28 = v; break;
    case 10: _circular_arrow_pstack.top().f2C = v; break;
    case 11: _circular_arrow_pstack.top().f34 = v; break;
    case 12: _arrow_pstack.top().a = v; break;
    case 13: _arrow_pstack.top().b = v; break;
    case 14: _arrow_pstack.top().c = v; break;
    case 15: _arrow_pstack.top().f = v; break;
    case 16: _point_pstack.top().size = v; break;
    }
}

void glutils::SetParam(IntParams p, int v)
{
    switch (p) {
    case 0: _unit_frame_pstack.top().i10 = v; break;
    case 1: _unit_frame_pstack.top().i14 = v; break;
    case 2: _circular_arrow_pstack.top().i20 = v; break;
    case 3: _circular_arrow_pstack.top().i24 = v; break;
    case 4: _circular_arrow_pstack.top().i30 = v; break;
    case 5: _unit_frame_pstack.top().i10 = v; break;
    case 6: _unit_frame_pstack.top().i14 = v; break;
    case 7: _point_pstack.top().slices = v; break;
    case 8: _point_pstack.top().stacks = v; break;
    }
}

void glutils::SetParam(UnsignedCharParams p, unsigned char v)
{
    switch (p) {
    case 0: _unit_frame_pstack.top().c18 = v; break;
    }
}

void glutils::SetParam(VectorParams p, math::vector_xyzw v)
{
    switch (p) {
    case 0: _unit_frame_pstack.top().v1C = v; break;
    case 1: _unit_frame_pstack.top().v2C = v; break;
    case 2: _unit_frame_pstack.top().v3C = v; break;
    case 3: _circular_arrow_pstack.top().center = v; break;
    }
}

void glutils::DrawCoordinateSystem()
{
    float s = _unit_frame_pstack.top().f4C;
    DrawCoordinateSystem(_unit_frame_pstack.top().f0 * s, _unit_frame_pstack.top().f4 * s,
                         _unit_frame_pstack.top().f8 * s, _unit_frame_pstack.top().fC * s,
                         _unit_frame_pstack.top().i10, _unit_frame_pstack.top().i14,
                         _unit_frame_pstack.top().c18, _unit_frame_pstack.top().v1C, _unit_frame_pstack.top().v2C,
                         _unit_frame_pstack.top().v3C);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils20DrawCoordinateSystemEffffiihN4math11vector_xyzwES1_S1_);


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils9DrawPointEN4math11vector_xyzwEfjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils9DrawPointEN4math11vector_xyzwE);

void glutils::DrawArrow(const math::vector_xyzw &from, const math::vector_xyzw &to)
{
    float s = _arrow_pstack.top().f;
    DrawArrow(from, to, _arrow_pstack.top().a * s, _arrow_pstack.top().b * s, _arrow_pstack.top().c * s,
              _arrow_pstack.top().d, _arrow_pstack.top().e);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils9DrawArrowERKN4math11vector_xyzwES3_fffii);

void glutils::DrawCircularArrow()
{
    float s = _circular_arrow_pstack.top().f34;
    DrawCircularArrow(_circular_arrow_pstack.top().center, _circular_arrow_pstack.top().f10 * s,
                      _circular_arrow_pstack.top().f14 * s, _circular_arrow_pstack.top().f18,
                      _circular_arrow_pstack.top().f1C, _circular_arrow_pstack.top().i20,
                      _circular_arrow_pstack.top().i24, _circular_arrow_pstack.top().f28 * s,
                      _circular_arrow_pstack.top().f2C * s, _circular_arrow_pstack.top().i30);
}

extern "C" const float D_00164424; /* -90.0f */

void glutils::DrawCircularArrow(math::vector_xyzw c, float radius, float width, float start, float end, int slices,
                                int rings, float cone_radius, float cone_height, int cone_slices)
{
    glPushMatrix();
    gl::Translatefv(c);
    if (width == 0)
        DrawCircle(radius, slices, start, end);
    else
        DrawTorus(radius - width, radius, slices, rings, start, end, false);
    float cs = cosf(end), sn = sinf(end);
    glPushMatrix();
    glTranslatef(cs * radius, sn * radius, 0);
    glRotatef(D_00164424, cs, sn, 0);
    DrawCone(cone_radius, cone_height, cone_slices, 1);
    glPopMatrix();
    glPopMatrix();
}

extern "C" const float D_00164428, D_0016442C; /* 1.0f, 180 / pi */

void glutils::DrawCircularArrow2d(math::vector_xyzw c, float radius, float width, float start, float end, int slices,
                                  float w, float h)
{
    glPushMatrix();
    gl::Translatefv(c);
    glNormal3f(0, 0, D_00164428);
    if (width == 0)
        DrawCircle(radius, slices, start, end);
    else
        DrawFlatTorus(radius - width, radius, slices, start, end);
    float cs = cosf(end), sn = sinf(end);
    glPushMatrix();
    float x = cs * radius;
    float y = sn * radius;
    glTranslatef(x, y, 0);
    glRotatef(end * D_0016442C, 0, 0, D_00164428);
    glBegin(4);
    glVertex3f(-w, 0, 0);
    glVertex3f(w, 0, 0);
    glVertex3f(0, h, 0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void glutils::DrawCircularArrow2d()
{
    float s = _circular_arrow_pstack.top().f34;
    DrawCircularArrow2d(_circular_arrow_pstack.top().center, _circular_arrow_pstack.top().f10 * s,
                        _circular_arrow_pstack.top().f14 * s, _circular_arrow_pstack.top().f18,
                        _circular_arrow_pstack.top().f1C, _circular_arrow_pstack.top().i24,
                        _circular_arrow_pstack.top().f28 * s, _circular_arrow_pstack.top().f2C * s);
}

void glutils::DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v)
{
    DrawArrow(from, from + v);
}

void glutils::DrawVector(const math::vector_xyzw &from, const math::vector_xyzw &v, float a, float b, float c, int d, int e)
{
    DrawArrow(from, from + v, a, b, c, d, e);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils19DrawMayaGroundPlaneEb);

extern "C" const float D_00164448, D_0016444C, D_00164450; /* 2 pi, 1, -1 */

void glutils::SolidCylinder(float radius, float height, int slices, bool caps)
{
    if (slices < 2)
        slices = 16;
    float step = D_00164448 / slices;
    glBegin(5);
    for (int i = 0; i < slices + 1; i++) {
        int j = (i == slices) ? 0 : i;
        float a = j * step;
        float c = cosf(a);
        float s = sinf(a);
        float x = radius * c;
        float y = radius * s;
        glNormal3f(c, s, 0);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0);
    }
    glEnd();
    if (caps) {
        glBegin(6);
        for (int i = 0; i < slices; i++) {
            int j = (i == slices) ? 0 : i;
        float a = j * step;
            float x = radius * cosf(a), y = radius * sinf(a);
            glNormal3f(0, 0, D_0016444C);
            glVertex3f(x, y, height);
            glVertex3f(x, y, height);
        }
        glEnd();
        glBegin(6);
        for (int i = slices - 1; i >= 0; i--) {
            int j = (i == slices - 1) ? 0 : i;
        float a = j * step;
            float x = radius * cosf(a), y = radius * sinf(a);
            glNormal3f(0, 0, D_00164450);
            glVertex3f(x, y, 0);
            glVertex3f(x, y, 0);
        }
        glEnd();
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils13DrawRectangleEfffffb);

extern "C" const float D_00164458; /* 0.5f */

void glutils::DrawRectangleC(float x, float y, float z, float w, float h, bool fill)
{
    DrawRectangle(x - w * D_00164458, y - h * D_00164458, z, w, h, fill);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils12PreTransformERN4math6matrixES1_S1_S1_b);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils21DrawLocalRotateWidgetEfbb);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_3AD98");
void _GLOBAL__I__ZN7glutils13_arrow_pstackE(void);
void _GLOBAL__D__ZN7glutils13_arrow_pstackE(void);
}

void _GLOBAL__I__ZN7glutils13_arrow_pstackE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils13_arrow_pstackE(void)
{
    static_init(0, 0xFFFF);
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils6Params9UnitFrameC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils__arrow_pstack", _ZN7glutils6Params13CircularArrowC1Ev);

/* deque<T>::back/push_back: the static initializer (asm) calls them (its size keeps them from being
   inlined there) */

/* the other deque instances that only the (asm) static initializer uses: referenced from here (a discarded function)
   so that cc1plus emits them (their order is DEMO_LINKONCE_ORDER's) */
extern "C" void glutils__arrow_pstack_instance_refs(std::deque<glutils::Params::Point> &p,
                                                    std::deque<glutils::Params::Arrow> &a,
                                                    std::deque<glutils::Params::UnitFrame> &u,
                                                    std::deque<glutils::Params::CircularArrow> &c)
    __attribute__((section(".discard.asm")));
extern "C" void glutils__arrow_pstack_instance_refs(std::deque<glutils::Params::Point> &p,
                                                    std::deque<glutils::Params::Arrow> &a,
                                                    std::deque<glutils::Params::UnitFrame> &u,
                                                    std::deque<glutils::Params::CircularArrow> &c)
{
    std::deque<glutils::Params::Point> p2(p);
    std::deque<glutils::Params::Arrow> a2(a);
    std::deque<glutils::Params::UnitFrame> u2(u);
    std::deque<glutils::Params::CircularArrow> c2(c);
    p.push_back(p.back());
    a.push_back(a.back());
    u.push_back(u.back());
    c.push_back(c.back());
    /* pointers to deque<T>::back/push_back (static, in a discarded section: no .rodata constants) make
       cc1plus emit their out-of-line copies; taken here, after their callers were compiled */
    static std::deque<glutils::Params::Point>::reference (std::deque<glutils::Params::Point>::*back_Point)() __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::Point>::back;
    static void (std::deque<glutils::Params::Point>::*push_back_Point)(const glutils::Params::Point &) __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::Point>::push_back;
    __asm__ volatile("" : : "m"(back_Point), "m"(push_back_Point));
    static std::deque<glutils::Params::Arrow>::reference (std::deque<glutils::Params::Arrow>::*back_Arrow)() __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::Arrow>::back;
    static void (std::deque<glutils::Params::Arrow>::*push_back_Arrow)(const glutils::Params::Arrow &) __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::Arrow>::push_back;
    __asm__ volatile("" : : "m"(back_Arrow), "m"(push_back_Arrow));
    static std::deque<glutils::Params::UnitFrame>::reference (std::deque<glutils::Params::UnitFrame>::*back_UnitFrame)() __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::UnitFrame>::back;
    static void (std::deque<glutils::Params::UnitFrame>::*push_back_UnitFrame)(const glutils::Params::UnitFrame &) __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::UnitFrame>::push_back;
    __asm__ volatile("" : : "m"(back_UnitFrame), "m"(push_back_UnitFrame));
    static std::deque<glutils::Params::CircularArrow>::reference (std::deque<glutils::Params::CircularArrow>::*back_CircularArrow)() __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::CircularArrow>::back;
    static void (std::deque<glutils::Params::CircularArrow>::*push_back_CircularArrow)(const glutils::Params::CircularArrow &) __attribute__((section(".discard.data"))) = &std::deque<glutils::Params::CircularArrow>::push_back;
    __asm__ volatile("" : : "m"(back_CircularArrow), "m"(push_back_CircularArrow));
}
