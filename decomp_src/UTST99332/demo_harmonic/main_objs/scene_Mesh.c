/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
extern const char scene_mesh_err[] __asm__("D_00168C10");     /* " *** error " */
extern const char scene_mesh_expr[] __asm__("D_00168C38");    /* "_mesh" */
extern const char scene_mesh_file[] __asm__("D_00168C40");    /* "../lib/scene/Mesh.h" */
extern const char scene_mesh_sp[] __asm__("D_00168C54");      /* " " */
extern const char scene_mesh_getData_name[] __asm__("_ZZN5scene4Mesh7getDataEvE19__PRETTY_FUNCTION___168B84");
#include "../main.hpp"

extern const char D_00168AFC[];

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _Z41__static_initialization_and_destruction_0ii_85568);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshC1ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD0Ev);

void scene::Mesh::destroy_mesh_data()
{
    if (_mesh) {
        delete _mesh;
        _mesh = 0;
    }
}

void scene::Mesh::draw(const TraversalVarStack &tvs)
{
    if (_mesh)
        _mesh->draw(tvs);
    else
        _interleaved.draw(tvs);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4Mesh7flattenERN4math14TransformStackE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4Mesh6calcbvEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4Mesh6formatEj);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_85568");
void _GLOBAL__I__ZN5scene4MeshC2ESsb(void);
void _GLOBAL__D__ZN5scene4MeshC2ESsb(void);
}

void _GLOBAL__I__ZN5scene4MeshC2ESsb(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene4MeshC2ESsb(void)
{
    static_init(0, 0xFFFF);
}

const char *scene::Mesh::getTypeName() const
{
    return D_00168AFC;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZNK5scene4Mesh5cloneESs);

bool scene::Mesh::isClonable() const
{
    return true;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN6common6handleIN5scene19MeshDataInterleaved10SharedDataEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN6common6handleIN5scene19MeshDataInterleaved10VertexDataEE10invalidateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZSt13__destroy_auxIPN3sgl8PositionEEvT_S3_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZNSt19_Bvector_alloc_baseISaIbELb1EE13_M_deallocateEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZNSt6vectorIiSaIiEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN3sgl17StencilShadowDataC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN6common6handleIN5scene19MeshDataInterleaved10SharedDataEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN6common6handleIN5scene19MeshDataInterleaved10VertexDataEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN6common6handleIN5scene19MeshDataInterleaved10SharedDataEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN6common6handleIN5scene19MeshDataInterleaved10VertexDataEED0Ev);

