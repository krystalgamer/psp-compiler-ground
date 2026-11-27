/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_00173544[];     /* "BVTRee max depth=" */
extern const char D_00173558[];     /* "\n" */
extern const char D_0017355C[];     /* "Model num vertices=" */
extern const char D_001735D8[];     /* "../lib/sh/RT.cpp" */
extern const char D_001735EC[];     /* " *** error " */
extern const char D_001737E0[];     /* "you must call start() before using the raytracer" */
extern const char D_00173814[];     /* "_ready" */
extern const char trace_name[] __asm__("_ZZN3sgl2RT5traceERNS0_3RayEE19__PRETTY_FUNCTION__");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _Z41__static_initialization_and_destruction_0ii_E999C);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT3addERKNS_4MeshEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT3RayC2EN4math11vector_xyzwES3_NS1_4TypeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT3RayC1EN4math11vector_xyzwES3_NS1_4TypeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZNK3sgl2RT17barycentricCoordsERKNS0_3RayERfS4_S4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT5shadeERNS0_3RayE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT6renderEN4math6matrixEfiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC2ENS_8PositionES2_S2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT8TriangleC1ENS_8PositionES2_S2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZNK3sgl2RT8Triangle9intersectERNS0_3RayE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT13build_bv_treeEPN3BVH4NodeEbj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT13build_bv_treeEbj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN3sgl2RT12bvtree_traceEPN3BVH4NodeERNS0_3RayE);

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

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_E999C");
void _GLOBAL__I__ZN3sgl2RTC2Ev(void);
void _GLOBAL__D__ZN3sgl2RTC2Ev(void);
}

void _GLOBAL__I__ZN3sgl2RTC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl2RTC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN4math4min_IfEET_S1_S1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZN4math4max_IfEET_S1_S1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZNSt6vectorIN3sgl2RT8TriangleESaIS2_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS2_S4_EERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_RT", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl2RT8TriangleESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);
