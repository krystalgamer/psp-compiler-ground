/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
extern const char scene_mesh_err[] __asm__("D_0016BB38");     /* " *** error " */
extern const char scene_mesh_expr[] __asm__("D_0016BB60");    /* "_mesh" */
extern const char scene_mesh_file[] __asm__("D_0016BB68");    /* "../lib/scene/Mesh.h" */
extern const char scene_mesh_sp[] __asm__("D_0016BB7C");      /* " " */
extern const char scene_mesh_getData_name[] __asm__("_ZZN5scene4Mesh7getDataEvE19__PRETTY_FUNCTION___16BAAC");
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10SharedDataEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10VertexDataEE10invalidateEv)
    SCENE_LINKONCE(_ZSt13__destroy_auxIPN3sgl8PositionEEvT_S3_12__false_type)
    SCENE_LINKONCE(_ZNSt19_Bvector_alloc_baseISaIbELb1EE13_M_deallocateEv)
    SCENE_LINKONCE(_ZNSt6vectorIiSaIiEED1Ev)
    SCENE_LINKONCE(_ZN3sgl17StencilShadowDataC1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10SharedDataEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10VertexDataEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10SharedDataEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene19MeshDataInterleaved10VertexDataEED0Ev)
);

extern const char D_0016BA24[];
/* called, not inlined, by format() in the original */
void Mesh_destroy_mesh_data(scene::Mesh *) __asm__("_ZN5scene4Mesh17destroy_mesh_dataEv");

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _Z41__static_initialization_and_destruction_0ii_8798C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshC2ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshC1ESsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD0Ev);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN5scene4Mesh7flattenERN4math14TransformStackE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN5scene4Mesh6calcbvEv);

void scene::Mesh::format(unsigned int f)
{
    calcbv();
    if (f & 2)
        sgl::Mesh::calcStencilShadowData(*_stencil, getData());
    getData().finish();
    if (f & 1) {
        _interleaved.convert(getData());
        Mesh_destroy_mesh_data(this);
    }
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_8798C");
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
    return D_0016BA24;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZNK5scene4Mesh5cloneESs);

bool scene::Mesh::isClonable() const
{
    return true;
}

/* instances used by the (asm) methods above */
template void common::handle<scene::MeshDataInterleaved::SharedData>::invalidate();
template void common::handle<scene::MeshDataInterleaved::VertexData>::invalidate();
template void std::__destroy_aux<sgl::Position *>(sgl::Position *, sgl::Position *, __false_type);
template void std::_Bvector_alloc_base<std::allocator<bool>, true>::_M_deallocate();
template std::vector<int>::~vector();
template common::handle<scene::MeshDataInterleaved::SharedData>::~handle();
template common::handle<scene::MeshDataInterleaved::VertexData>::~handle();

/* from here on INCLUDE_ASM puts the asm in its own .gnu.linkonce.t section (written as
   INCLUDE_ASM so that splat keeps these functions as asm) */
#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Mesh", _ZN3sgl17StencilShadowDataC1Ev);
