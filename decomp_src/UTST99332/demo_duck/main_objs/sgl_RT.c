/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
extern const float D_00173504;
#define SGL_POSITION_ONE D_00173504
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sgl2RTC2Ev");
__asm__(".globl _GLOBAL__D__ZN3sgl2RTC2Ev");

extern const char D_00173544[];     /* "BVTRee max depth=" */
extern const char D_00173558[];     /* "\n" */
extern const char D_0017355C[];     /* "Model num vertices=" */
extern const char D_001735D8[];     /* "../lib/sh/RT.cpp" */
extern const char D_001735EC[];     /* " *** error " */
extern const char D_001737E0[];     /* "you must call start() before using the raytracer" */
extern const char D_00173814[];     /* "_ready" */
extern const char trace_name[] __asm__("_ZZN3sgl2RT5traceERNS0_3RayEE19__PRETTY_FUNCTION__");

sgl::RT::RT() : _mesh(false), _ready(false)
{
}

void sgl::RT::start()
{
    build_bv_tree(true, 1);
    common::Log() << D_00173544 << *(const unsigned int *)((const char *)&_bvh + 0x168) << D_00173558;
    common::Log() << D_0017355C << (unsigned int)_mesh.getVertices().size() << D_00173558;
    _ready = true;
}

void sgl::RT::add(const Mesh &m, unsigned int)
{
    int i = 0;
    for (std::vector<sgl::Triangle>::const_iterator it = m.getTriangles().begin(); it != m.getTriangles().end(); ++it, ++i)
        _triangles.push_back(Triangle(m.getTriangleVertexPosition(i, 0), m.getTriangleVertexPosition(i, 1), m.getTriangleVertexPosition(i, 2)));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT3RayC2EN4math11vector_xyzwES3_NS1_4TypeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT3RayC1EN4math11vector_xyzwES3_NS1_4TypeE);


void sgl::RT::barycentricCoords(const Ray &r, float &u, float &v, float &w) const
{
    if (r._triangle == -1)
        return;
    Position a, b, c;
    _mesh.getTriangleVertexPosition(r._triangle, a, b, c);
    float A = math::area(a, r._hit, c);
    float B = math::area(b, r._hit, a);
    v = A * _triangles[r._triangle]._f34;
    w = B * _triangles[r._triangle]._f34;
    u = D_00173504 - w - v;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT5shadeERNS0_3RayE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT6renderEN4math6matrixEfiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC2ENS_8PositionES2_S2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC1ENS_8PositionES2_S2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZNK3sgl2RT8Triangle9intersectERNS0_3RayE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT13build_bv_treeEPN3BVH4NodeEbj);

extern const char D_00173608[], D_001737A8[];
extern const char bbt_name[] __asm__("_ZZN3sgl2RT13build_bv_treeEbjE19__PRETTY_FUNCTION__");
void sgl::RT::build_bv_tree(bool b, unsigned int n)
{
    SGL_ASSERT(n != 0, D_001735EC, D_001737A8, D_001735D8, bbt_name, 467, D_00173608);
    if (_triangles.empty())
        return;
    std::vector<unsigned int> &v = _bvh._root._items;
    v.resize(0);
    for (unsigned int i = 0; i != _triangles.size(); i++)
        v.push_back(i);
    build_bv_tree(&_bvh._root, b, n);
}

void sgl::RT::bvtree_trace(BVH::Node *n, Ray &r)
{
    if (!n)
        return;
    if (r._any && r._triangle != -1)
        return;
    float t;
    if (!n->_bv.intersect(t, r._origin, r._dir))
        return;
    if (!n->_items.empty())
        for (std::vector<unsigned int>::iterator it = n->_items.begin(); it != n->_items.end(); ++it)
            if (_triangles[*it].intersect(r))
                r._triangle = *it;
    if (n->_leaf)
        return;
    BVH::Node *c0 = n->_child[0];
    bvtree_trace(c0, r);
    BVH::Node *c1 = n->_child[1];
    bvtree_trace(c1, r);
}

void sgl::RT::dumb_trace(Ray &r)
{
    int i = 0;
    for (std::vector<Triangle>::iterator it = _triangles.begin(); it != _triangles.end(); ++it, ++i)
        if (it->intersect(r)) {
            r._triangle = i;
            if (r._any)
                break;
        }
}

void sgl::RT::trace(Ray &r)
{
    SGL_ASSERT(_ready, D_001735EC, D_00173814, D_001735D8, trace_name, 530, D_001737E0);
    bvtree_trace(&_bvh._root, r);
}

const void *sgl::RT::getBVTree() const
{
    return &_bvh;
}

const sgl::Mesh *sgl::RT::getMesh() const
{
    return &_mesh;
}

sgl::Mesh *sgl::RT::getMesh()
{
    return &_mesh;
}

void sgl::RT::setTestLight(math::vector_xyzw v)
{
    _testLight = v;
}

const math::vector_xyzw &sgl::RT::getTestLight() const
{
    return _testLight;
}

/* template instances used by the asm above (add, render, build_bv_tree): referenced from a discarded
   function, before math::min_/max_ are defined (no inlining), in Sony's instantiation order */
namespace math {
template<class T> T min_(T, T, T);
template<class T> T max_(T, T, T);
}
extern "C" void sgl_RT_instances(std::vector<sgl::RT::Triangle> *v, const sgl::RT::Triangle *t)
    __attribute__((section(".discard.asm")));
extern "C" void sgl_RT_instances(std::vector<sgl::RT::Triangle> *v, const sgl::RT::Triangle *t)
{
    math::min_(0.0f, 0.0f, 0.0f);
    math::max_(0.0f, 0.0f, 0.0f);
    v->push_back(*t);
}

namespace math {
template<class T> T min_(T a, T b, T c)
{
    return a <= b ? (a <= c ? a : c) : (b <= c ? b : c);
}
template<class T> T max_(T a, T b, T c)
{
    return b <= a ? (c <= a ? a : c) : (c <= b ? b : c);
}
}
