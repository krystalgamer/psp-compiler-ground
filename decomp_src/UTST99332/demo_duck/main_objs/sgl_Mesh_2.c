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
__asm__(".globl _GLOBAL__I__ZNK3sgl4Mesh4drawEj\n_GLOBAL__I__ZNK3sgl4Mesh4drawEj = _GLOBAL__I__ZNK3sgl4Mesh4drawEj__asm");
__asm__(".globl _GLOBAL__D__ZNK3sgl4Mesh4drawEj\n_GLOBAL__D__ZNK3sgl4Mesh4drawEj = _GLOBAL__D__ZNK3sgl4Mesh4drawEj__asm");

#include "UTST99332/demo_duck/gl.hpp"
extern "C" {
void glColor4f(float, float, float, float);
void glTexCoord2f(float, float);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh4drawEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh11draw_vertexEjjjjjjfb);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZNK3sgl4Mesh15draw_primitivesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZN3sgl17StencilShadowData6updateEN4math11vector_xyzwERKNS1_6matrixEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_2", _ZN3sgl17StencilShadowData4drawEj);
