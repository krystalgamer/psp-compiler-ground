/* lang: c++ */
/* cflags: -O3 -fno-exceptions -fno-merge-constants */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

#include <deque>
#include "UTST99332/demo_duck/gl.hpp"

extern "C" {
void glInitNames(void);
void glLoadMatrixf(const float *);
void glMatrixMode(unsigned int);
void glPushName(unsigned int);
void glLoadName(unsigned int);
void glPopName(void);
}

/* weak instances stay asm */
extern template class std::deque<unsigned int>;
extern template class std::_Deque_base<unsigned int, std::allocator<unsigned int> >;
extern template class std::deque<math::matrix>;
extern template class std::_Deque_base<math::matrix, std::allocator<math::matrix> >;

extern "C" const char D_00167728[], D_001676F0[], D_00167708[], D_00167724[];
extern const char gl_PopName_fn[] __asm__("_ZZN2gl7PopNameEvE19__PRETTY_FUNCTION__");
extern const char gl_GetNameStackTop_fn[] __asm__("_ZZN2gl15GetNameStackTopEvE19__PRETTY_FUNCTION__");

namespace gl {
enum MatrixModeEnum { };
extern std::deque<unsigned int> _name_stack;
extern MatrixModeEnum _matrix_mode;
extern std::deque<math::matrix> _matrix_stacks[];
void InitNames();
void sync();
void PushMatrix();
void PopMatrix();
void MatrixMode(MatrixModeEnum);
void LoadIdentity();
void PushName(unsigned int);
void LoadName(unsigned int);
void PopName();
unsigned int GetNameStackTop();
void GenTextures(int, unsigned int *);
void DeleteTextures(int, const unsigned int *);
bool IsNameStackEmpty();
std::deque<math::matrix> &mstack();
void Translatefv(const float *);
void Translatefv(const math::vector_xyzw &);
void ClearColorv(const math::vector_xyzw &);
void Colorv(const math::vector_xyzw &);
void Vertexv(const math::vector_xyzw &);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _Z41__static_initialization_and_destruction_0ii_485D8);

void gl::GenTextures(int n, unsigned int *names)
{
    if (names)
        glGenTextures(n, names);
}

void gl::DeleteTextures(int n, const unsigned int *names)
{
    if (names)
        glDeleteTextures(n, names);
}

bool gl::find_texture(unsigned int)
{
    return true;
}

bool gl::CheckTextures()
{
    return true;
}

void gl::InitNames()
{
    while (!_name_stack.empty())
        _name_stack.pop_back();
    glInitNames();
}

void gl::PushName(unsigned int name)
{
    _name_stack.push_back(name);
    glPushName(name);
}

void gl::LoadName(unsigned int name)
{
    if (!_name_stack.empty()) {
        _name_stack.back() = name;
        glLoadName(name);
    }
}

void gl::PopName()
{
    SGL_ASSERT(!_name_stack.empty(), D_00167728, D_001676F0, D_00167708, gl_PopName_fn, 0xA2, D_00167724);
    _name_stack.pop_back();
    glPopName();
}

unsigned int gl::GetNameStackTop()
{
    SGL_ASSERT(!_name_stack.empty(), D_00167728, D_001676F0, D_00167708, gl_GetNameStackTop_fn, 0xAB, D_00167724);
    return _name_stack.back();
}

bool gl::IsNameStackEmpty()
{
    return _name_stack.empty();
}

std::deque<math::matrix> &gl::mstack()
{
    return _matrix_stacks[_matrix_mode];
}

void gl::sync()
{
    glLoadMatrixf(&mstack().back().r[0].x);
}

void gl::PushMatrix()
{
    std::deque<math::matrix> &st = mstack();
    st.push_back(st.empty() ? math::matrix::Identity() : st.back());
    sync();
}

void gl::PopMatrix()
{
    mstack().pop_back();
    sync();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZN2gl11MultMatrixfEPKf);

void gl::MatrixMode(MatrixModeEnum m)
{
    _matrix_mode = m;
    switch (m) {
    case 0:
        glMatrixMode(0x1701);
        break;
    case 1:
        glMatrixMode(0x1700);
        break;
    }
}

void gl::LoadIdentity()
{
    mstack().back() = math::matrix::Identity();
    sync();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZN2gl7RotatefEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZN2gl6ScalefEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZN2gl10TranslatefEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZN2gl7FrustumEffffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZN2gl5OrthoEffffff);

void gl::PickMatrix(float, float, float, float, int *) {
}

void gl::Translatefv(const float *v)
{
    glTranslatef(v[0], v[1], v[2]);
}

void gl::Translatefv(const math::vector_xyzw &v)
{
    glTranslatef(v.x, v.y, v.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZN2gl14ScalefCanceledEv);

void gl::ClearColorv(const math::vector_xyzw &v)
{
    glClearColor(v.x, v.y, v.z, v.w);
}

void gl::Colorv(const math::vector_xyzw &v)
{
    glColor3f(v.x, v.y, v.z);
}

void gl::Vertexv(const math::vector_xyzw &v)
{
    glVertex3f(v.x, v.y, v.z);
}

void gl::ErrorCheck(const char *, int) {
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_485D8");
void _GLOBAL__I__ZN2gl11_name_stackE(void);
void _GLOBAL__D__ZN2gl11_name_stackE(void);
}

void _GLOBAL__I__ZN2gl11_name_stackE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN2gl11_name_stackE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZNSt11_Deque_baseIN4math6matrixESaIS1_EED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZNSt11_Deque_baseIN4math6matrixESaIS1_EE17_M_initialize_mapEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZNSt11_Deque_baseIN4math6matrixESaIS1_EE16_M_destroy_nodesEPPS1_S5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZNSt5dequeIN4math6matrixESaIS1_EE16_M_push_back_auxERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZNSt5dequeIN4math6matrixESaIS1_EE15_M_pop_back_auxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZNSt11_Deque_baseIN4math6matrixESaIS1_EE15_M_create_nodesEPPS1_S5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN4math6matrixERKS2_PS3_ES0_IS2_RS2_PS2_EET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gl__name_stack", _ZNSt5dequeIN4math6matrixESaIS1_EE17_M_reallocate_mapEjb);
