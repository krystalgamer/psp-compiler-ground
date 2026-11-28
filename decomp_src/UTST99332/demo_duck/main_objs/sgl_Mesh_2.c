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

extern "C" void glNormal3fv(const GLfloat *);
extern const float ssd_one __asm__("D_0016EBB8");
extern const char ssd_err[] __asm__("D_0016EC14");
extern const char ssd_file[] __asm__("D_0016EC38");
extern const char ssd_sp[] __asm__("D_0016EC54");
extern const char ssd_expr[] __asm__("D_0016ECF0");
extern const char ssd_draw_pf[] __asm__("_ZZN3sgl17StencilShadowData4drawEjE19__PRETTY_FUNCTION__");
void sgl::StencilShadowData::draw(unsigned int)
{
    glCullFace(0x405);
    glEnable(0xB44);
    glBegin(7);
    glColor3f(0, ssd_one, ssd_one);
    for (unsigned int i = 0; i != _edges.size(); i++) {
        if (_f48[i]) {
            const Edge &e = _edges[i];
            Position a = _f0c[e.vertex(0)];
            Position b = _f0c[e.vertex(1)];
            Position c = _f18[e.vertex(0)];
            Position d = _f18[e.vertex(1)];
            glNormal3fv(&_f24[i].x);
            glVertex3fv(&a.x);
            glVertex3fv(&c.x);
            glVertex3fv(&d.x);
            glVertex3fv(&b.x);
        }
    }
    glEnd();
    SGL_ASSERT(_triangles_centers.size() == _triangles_normals.size(), ssd_err, ssd_expr, ssd_file, ssd_draw_pf, 0x1DA, ssd_sp);
}
