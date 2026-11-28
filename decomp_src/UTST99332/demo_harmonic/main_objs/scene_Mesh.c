/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
extern const char scene_mesh_err[] __asm__("D_00168C10");     /* " *** error " */
extern const char scene_mesh_expr[] __asm__("D_00168C38");    /* "_mesh" */
extern const char scene_mesh_file[] __asm__("D_00168C40");    /* "../lib/scene/Mesh.h" */
extern const char scene_mesh_sp[] __asm__("D_00168C54");      /* " " */
extern const char scene_mesh_getData_name[] __asm__("_ZZN5scene4Mesh7getDataEvE19__PRETTY_FUNCTION___168B84");
/* BVdata::create's strings in this object */
extern const char scene_bvdata_warn[] __asm__("D_00168B74");         /* " *** warning " */
extern const char scene_bvdata_notvalid[] __asm__("D_00168B30");     /* "! valid()" */
extern const char scene_bvdata_file[] __asm__("D_00168B3C");         /* "../lib/scene/BVdata.h" */
extern const char scene_bvdata_created[] __asm__("D_00168B54");      /* "bounding box already created" */
extern const char scene_bvdata_create_name[] __asm__("_ZZN5scene6BVdata6createEN3sgl2BV4TypeEE19__PRETTY_FUNCTION___168B04");
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene4MeshC2ESsb\n_GLOBAL__I__ZN5scene4MeshC2ESsb = _GLOBAL__I__ZN5scene4MeshC2ESsb__asm");
__asm__(".globl _GLOBAL__D__ZN5scene4MeshC2ESsb\n_GLOBAL__D__ZN5scene4MeshC2ESsb = _GLOBAL__D__ZN5scene4MeshC2ESsb__asm");
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZNK5scene4Mesh11getTypeNameEv)
    SCENE_LINKONCE(_ZNK5scene4Mesh5cloneESs)
    SCENE_LINKONCE(_ZNK5scene4Mesh10isClonableEv)
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

extern const char D_00168AFC[];
/* called, not inlined, by format() in the original */
void Mesh_destroy_mesh_data(scene::Mesh *) __asm__("_ZN5scene4Mesh17destroy_mesh_dataEv");

scene::Mesh::Mesh(std::string name, bool b) : Node(name, b), _mesh(new MeshData), _stencil(new sgl::StencilShadowData)
{
    set_default_name();
    _bvdata.create(sgl::BV::Type(0));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZN5scene4MeshD0Ev);

/* inline in the class (weak copies emitted with the vtable, in the object's tail) */
SGL_LINKONCE_BEGIN
inline const char *scene::Mesh::getTypeName() const
{
    return D_00168AFC;
}

inline bool scene::Mesh::isClonable() const
{
    return true;
}
SGL_LINKONCE_END

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

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Mesh", _ZNK5scene4Mesh5cloneESs);
/* an implicit constructor the (asm) Mesh constructors call: emitted through a discarded user */
void scene_Mesh_StencilShadowData_ref(void *p) __attribute__((section(".discard.instances")));
void scene_Mesh_StencilShadowData_ref(void *p)
{
    new (p) sgl::StencilShadowData;
}
