/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"
#include "UTST99332/demo_duck/gl.hpp"
extern "C" void glColor3fv(const GLfloat *);
extern "C" void glVertex3fv(const GLfloat *);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _Z41__static_initialization_and_destruction_0ii_A0A18);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZN14VertexColorEnvC2Ebi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZN14VertexColorEnvC1Ebi);

void VertexColorEnv::eval(const sh::SphericalRGBFn *fn)
{
    if (fn)
        for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
            fn->eval(it->theta, it->phi, it->r, it->g, it->b);
}

void VertexColorEnv::draw(float scale)
{
    glPushMatrix();
    glScalef(scale, scale, scale);
    glPushAttrib(0x2000);
    glDisable(0xB50);
    for (int i = 0; i < _n - 1; i++) {
        glBegin(5);
        Vertex *a = &_vertices[i * _n + _n - 1];
        Vertex *b = &_vertices[i * _n + _n + _n - 1];
        for (int j = 0; j < _n; j++) {
            glColor3fv(&a->r);
            glVertex3fv(a->pos);
            glColor3fv(&b->r);
            glVertex3fv(b->pos);
            a--;
            b--;
        }
        glEnd();
    }
    glPopMatrix();
    glPopAttrib();
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_A0A18");
void _GLOBAL__I__ZN14VertexColorEnvC2Ebi(void);
void _GLOBAL__D__ZN14VertexColorEnvC2Ebi(void);
}

void _GLOBAL__I__ZN14VertexColorEnvC2Ebi(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN14VertexColorEnvC2Ebi(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZNSt6vectorIN14VertexColorEnv6VertexESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZNSt6vectorIN14VertexColorEnv6VertexESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN14VertexColorEnv6VertexESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZSt24__uninitialized_copy_auxIPN14VertexColorEnv6VertexES2_ET0_T_S4_S3_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZSt26__uninitialized_fill_n_auxIPN14VertexColorEnv6VertexEjS1_ET_S3_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN14VertexColorEnv6VertexESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN14VertexColorEnv6VertexESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/VertexColorEnv", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN14VertexColorEnv6VertexESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type);

