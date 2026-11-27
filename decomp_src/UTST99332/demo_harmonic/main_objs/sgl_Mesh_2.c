/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

#include "UTST99332/demo_duck/gl.hpp"
extern "C" {
void glColor4f(float, float, float, float);
void glTexCoord2f(float, float);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_2", _Z41__static_initialization_and_destruction_0ii_B06D8);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh4drawEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh11draw_vertexEjjjjjjfb);

void sgl::Mesh::draw_triangles(float s) const
{
    unsigned int nn = _normals.size();
    unsigned int nc = _colors.size();
    unsigned int nt = _texcoords.size();
    unsigned int np = _positions.size();
    unsigned int nv = _vertices.size();
    if (use_purple)
        glColor3f(s, 0, s);
    glBegin(4);
    const std::vector<Triangle> &tris = _triangles;
    for (std::vector<Triangle>::const_iterator it = tris.begin(); it != tris.end(); ++it)
        for (int i = 0; i != 3; i++)
            draw_vertex((*it)[i], nn, nc, nt, np, nv, s, true);
    glEnd();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh15draw_primitivesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_2", _ZN3sgl17StencilShadowData6updateEN4math11vector_xyzwERKNS1_6matrixEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_2", _ZN3sgl17StencilShadowData4drawEj);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_B06D8");
void _GLOBAL__I__ZNK3sgl4Mesh4drawEj(void);
void _GLOBAL__D__ZNK3sgl4Mesh4drawEj(void);
}

void _GLOBAL__I__ZNK3sgl4Mesh4drawEj(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZNK3sgl4Mesh4drawEj(void)
{
    static_init(0, 0xFFFF);
}

