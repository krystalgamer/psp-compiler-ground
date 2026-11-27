/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#define SCENE_GRAPH_TEMPLATE_DEFS
#define SGL_TEMPLATE_DEFS 1
#include "../main.hpp"
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZN5scene5Graph10getSublistINS_4MeshEEEvRN6common12handles_listIT_EE)
    SCENE_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE13countVerticesEv)
    SCENE_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE21countVerticesInStripsEv)
    SCENE_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE5rangeERiS2_)
    SCENE_LINKONCE(_ZSt4fillIPmiEvT_S1_RKT0_)
    SCENE_LINKONCE(_ZNSt10_List_baseIN6common6handleIN5scene4MeshEEESaIS4_EE7__clearEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene4MeshEEESaIS4_EE6insertESt14_List_iteratorIS4_RS4_PS4_ERKS4_)
);

extern const char D_001680F8[];
extern const char D_0016812C[];
extern const char D_00168380[];
extern const char D_00168400[];
extern const char D_00168414[];

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _Z41__static_initialization_and_destruction_0ii_7D97C);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene5Graph4saveEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene8Material4saveERSo);

void scene::Group::save(std::ostream &) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene4Mesh4saveERSo);

void scene::Node::save(std::ostream &) {
}

void scene::Object::save(std::ostream &) {
}

void scene::Setup::save(std::ostream &) {
}

void scene::Shape::save(std::ostream &) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene15StaticTransform4saveERSo);

void scene::Switch::save(std::ostream &os)
{
    os << D_00168414 << _selected << std::endl;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene7Texture4saveERSo);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene9Transform4saveERSo);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene10SaveVectorIN3sgl8PositionEEEvRSoRKSt6vectorIT_SaIS5_EEjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene10SaveVectorIN3sgl6NormalEEEvRSoRKSt6vectorIT_SaIS5_EEjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene10SaveVectorIN3sgl8TexCoordEEEvRSoRKSt6vectorIT_SaIS5_EEjPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZN5scene10SaveVectorIN3sgl5ColorEEEvRSoRKSt6vectorIT_SaIS5_EEjPKc);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_7D97C");
void _GLOBAL__I__ZN5scene5Graph4saveEPKc(void);
void _GLOBAL__D__ZN5scene5Graph4saveEPKc(void);
}

void _GLOBAL__I__ZN5scene5Graph4saveEPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN5scene5Graph4saveEPKc(void)
{
    static_init(0, 0xFFFF);
}

/* instances that the (asm) methods above use, referenced from a discarded function (see scene_Graph.c) */
extern "C" void scene_Graph_3_uses(scene::Graph *g, unsigned long *p) __attribute__((section(".discard.asm")));
extern "C" void scene_Graph_3_uses(scene::Graph *g, unsigned long *p)
{
    g->getSublist(*(common::handles_list<scene::Mesh> *)0);
    std::fill(p, p, 0);
}

/* sgl::PrimitiveIndex<int> members that the (asm) methods above call (nothing in C++ calls them) */
template int sgl::PrimitiveIndex<int>::countVertices() const;
template int sgl::PrimitiveIndex<int>::countVerticesInStrips() const;

/* from here on INCLUDE_ASM puts the asm in its own .gnu.linkonce.t section (written as
   INCLUDE_ASM so that splat keeps these functions as asm) */
#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_Graph_3", _ZNK3sgl14PrimitiveIndexIiE5rangeERiS2_);
