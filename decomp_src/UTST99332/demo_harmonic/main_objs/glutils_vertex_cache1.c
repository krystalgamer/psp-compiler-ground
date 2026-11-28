/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"
#include "UTST99332/demo_duck/gl.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN6common9tmp_arrayIN7glutils6vertexEEC1Ej)
    DEMO_LINKONCE(_ZN6common9tmp_arrayIN7glutils6vertexEE3getEj)
);

extern "C" const char D_00164038[], D_00164044[], D_0016404C[], D_00164068[], D_001640B4[];
extern const char tmp_array_get_name[] __asm__("_ZZN6common9tmp_arrayIN7glutils6vertexEE3getEjE19__PRETTY_FUNCTION__");
extern const char tmp_array_release_name[] __asm__("_ZZN6common9tmp_arrayIN7glutils6vertexEE7releaseEvE19__PRETTY_FUNCTION__");
namespace common {
template<class T> class tmp_array {
public:
    tmp_array(unsigned int n);
    ~tmp_array()
    {
        if (_data)
            delete[] _data;
        _size = 0;
        _busy = false;
    }
    T *get(unsigned int n);
    void release()
    {
        SGL_ASSERT(_busy, D_00164038, D_00164044, D_0016404C, tmp_array_release_name, 83, D_00164068);
        _busy = false;
    }
    T *_data;
    unsigned int _size;
    bool _busy;
};
}
namespace glutils {
enum DrawMode { };
struct vertex {
    math::vector_xyzw pos;
    char _pad10[0x20];
    math::vector_xyzw f30;
    vertex() {}
};
extern bool false_colors, triangle_strips, wireframe, quads;
void DrawPrimMode(DrawMode, bool);
void sample_unit_circle(vertex *, int, float);
void DrawRevolution(vertex *, int, int);
void DrawCircle(float, int, float, float);
void DrawFlatTorus(float, float, int, float, float);
void DrawDisk(float, int, float, float);
void draw_cube(float, float, float);
void solid_revolution(const vertex *, int, int, float, float);
void wire_revolution(const vertex *, int, int, float, float);
void DrawCylinder(float, float, int, int);
extern common::tmp_array<vertex> vertex_cache1, vertex_cache2;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _Z41__static_initialization_and_destruction_0ii_37A20);

void glutils::DrawPrimMode(DrawMode m, bool b)
{
    switch (m) {
    case 1:
        false_colors = b;
        break;
    case 2:
        triangle_strips = b;
        break;
    case 3:
        wireframe = b;
        break;
    case 4:
        quads = b;
        break;
    }
}

void glutils::sample_unit_circle(vertex *v, int n, float a)
{
    float c = cosf(a);
    float s = sinf(a);
    float x = 1.0f, y = 0;
    v[0].pos.x = x;
    v[0].pos.y = y;
    v[0].pos.z = 0;
    v[0].pos.w = 1.0f;
    for (int i = 1; i < n; i++) {
        float nx = x * c - y * s;
        float ny = y * c + x * s;
        v[i].pos.x = nx;
        v[i].pos.y = ny;
        v[i].pos.z = 0;
        v[i].pos.w = 1.0f;
        x = nx;
        y = ny;
    }
}

void glutils::DrawRevolution(vertex *v, int n, int m)
{
    if (!wireframe)
        solid_revolution(v, n, m, 0, 6.28318548f);
    else
        wire_revolution(v, n, m, 0, 6.28318548f);
}

void glutils::DrawCircle(float r, int n, float a0, float a1)
{
    float step = (a1 - a0) / (float)(n - 1);
    float t = 0;
    glBegin(3);
    for (int i = 0; i < n; i++) {
        float a = a0 + t;
        t += step;
        glVertex3f(r * cosf(a), r * sinf(a), 0);
    }
    glEnd();
}

void glutils::DrawFlatTorus(float r1, float r2, int n, float a0, float a1)
{
    float step = (a1 - a0) / (float)(n - 1);
    float t = 0;
    float c = cosf(step);
    float s = sinf(step);
    glBegin(7);
    for (int i = 0; i < n - 1; i++) {
        float a = a0 + t;
        t += step;
        float ca = cosf(a);
        float sa = sinf(a);
        float nx = ca * c - sa * s;
        float ny = ca * s + sa * c;
        glVertex3f(r1 * ca, r1 * sa, 0);
        glVertex3f(r1 * nx, r1 * ny, 0);
        glVertex3f(r2 * nx, r2 * ny, 0);
        glVertex3f(r2 * ca, r2 * sa, 0);
    }
    glEnd();
}

void glutils::DrawDisk(float r, int n, float a0, float a1)
{
    float step = (a1 - a0) / (float)(n - 1);
    float t = 0;
    glBegin(9);
    for (int i = 0; i < n; i++) {
        float a = a0 + t;
        t += step;
        glVertex3f(r * cosf(a), r * sinf(a), 0);
    }
    glEnd();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _ZN7glutils10DrawSphereEfiiff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _ZN7glutils9DrawTorusEffiiffb);

void glutils::DrawCylinder(float h, float r, int n, int m)
{
    vertex *v = vertex_cache1.get(m + 1);
    for (int i = m; i >= 0; i--) {
        v[i].pos.x = r;
        v[i].pos.y = 0;
        v[i].pos.z = -h * 0.5f + h * (i / (float)m);
        v[i].pos.w = 1.0f;
        v[i].f30.x = 1.0f;
        v[i].f30.y = 0;
        v[i].f30.z = 0;
        v[i].f30.w = 0;
    }
    if (!wireframe)
        solid_revolution(v, m + 1, n, 0, 6.2831855f);
    else
        wire_revolution(v, m + 1, n, 0, 6.2831855f);
    vertex_cache1.release();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _ZN7glutils8DrawConeEffii);

void glutils::DrawCube(float s)
{
    DrawCube(s, s, s);
}

void glutils::DrawCube(float x, float y, float z)
{
    if (!wireframe)
        draw_cube(x, y, z);
    else {
        glEnable(0x2A02);
        glPolygonMode(0x408, 0x1B01);
        draw_cube(x, y, z);
        glPolygonMode(0x408, 0x1B02);
        glDisable(0x2A02);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _ZN7glutils9DrawFrameEN4math11vector_xyzwES1_S1_S1_f);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _ZN7glutils9draw_cubeEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _ZN7glutils16solid_revolutionEPKNS_6vertexEiiff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/glutils_vertex_cache1", _ZN7glutils15wire_revolutionEPKNS_6vertexEiiff);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_37A20");
void _GLOBAL__I__ZN7glutils13vertex_cache1E(void);
void _GLOBAL__D__ZN7glutils13vertex_cache1E(void);
}

void _GLOBAL__I__ZN7glutils13vertex_cache1E(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7glutils13vertex_cache1E(void)
{
    static_init(0, 0xFFFF);
}

template<class T> common::tmp_array<T>::tmp_array(unsigned int n)
{
    _data = 0;
    _busy = false;
    _size = n;
    if (n)
        _data = new T[n];
}

template<class T> T *common::tmp_array<T>::get(unsigned int n)
{
    SGL_ASSERT(!_busy, D_00164038, D_001640B4, D_0016404C, tmp_array_get_name, 59, D_00164068);
    if (_size >= n && _data) {
        _busy = true;
        return _data;
    }
    if (_data)
        delete[] _data;
    _busy = false;
    _size = n;
    _data = new T[n];
    _busy = true;
    return _data;
}
extern "C" void glutils_vertex_cache1_refs(void) __attribute__((section(".discard.asm")));
extern "C" void glutils_vertex_cache1_refs(void)
{
    common::tmp_array<glutils::vertex> a(0);
    a.get(0);
}

