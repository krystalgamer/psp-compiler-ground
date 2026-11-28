/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#define DEMO_TEMPLATE_DEFS
#define SCENE_GRAPH_TEMPLATE_DEFS
#define SGL_TEMPLATE_DEFS 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene5Graph4saveEPKc\n_GLOBAL__I__ZN5scene5Graph4saveEPKc = _GLOBAL__I__ZN5scene5Graph4saveEPKc__asm");
__asm__(".globl _GLOBAL__D__ZN5scene5Graph4saveEPKc\n_GLOBAL__D__ZN5scene5Graph4saveEPKc = _GLOBAL__D__ZN5scene5Graph4saveEPKc__asm");
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
extern const char D_001683C4[];
extern const char D_00168580[];
extern const char D_001684CC[], D_001684E4[], D_001684F4[];
extern const char D_00168428[], D_0016843C[], D_001680CC[], D_00168440[], D_00168454[], D_00168474[], D_0016816C[],
    D_00168170[], D_0016848C[], D_001684AC[];
extern const char D_00168380[];
extern const char D_00168400[];
extern const char D_00168414[];

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

void scene::StaticTransform::save(std::ostream &os)
{
    os << D_00168400;
    const math::vector_xyzw *r = _matrix.r;
    for (int i = 0; i < 4; i++) {
        os << D_00168380;
        for (int j = 0; j < 4; j++)
            os << r[i][j] << D_001680F8;
    }
    os << D_0016812C;
}

void scene::Switch::save(std::ostream &os)
{
    os << D_00168414 << _selected << std::endl;
}

void scene::Texture::save(std::ostream &os)
{
    os << D_00168428 << common::GetFileLessPath(_path.c_str()) << D_0016843C;
    if (_hint != D_001680CC)
        os << D_00168440 << _hint << D_0016843C;
    if (_override_alpha) {
        os << D_00168474 << (_override_alpha ? D_0016816C : D_00168170) << D_0016812C;
        os << D_0016848C << (int)_alpha << D_0016812C;
    } else {
        os << D_00168454;
        os << D_001684AC;
    }
}

void scene::Transform::save(std::ostream &os)
{
    os << D_001684CC << getTranslation().x << D_001680F8 << getTranslation().y << D_001680F8 << getTranslation().z
       << D_001680F8 << std::endl;
    os << D_001684E4 << getScale().x << D_001680F8 << getScale().y << D_001680F8 << getScale().z << D_001680F8
       << std::endl;
    math::vector_xyz e = getEulerAngles(math::RotationOrder(0));
    os << D_001684F4 << e.x << D_001680F8 << e.y << D_001680F8 << e.z << D_001680F8 << std::endl;
}

/* used by Mesh::save (asm): explicit instances, in the original's order */
namespace scene {
template<class T> static void SaveVector(std::ostream &, const std::vector<T> &, unsigned int, const char *);
}
/* referencing the instances from a (discarded) function deferred before them gets them emitted
   in their place, before the static constructor wrappers below */
extern "C" void scene_Graph_3_SaveVector_refs(void) __attribute__((section(".discard.asm")));
extern "C" void scene_Graph_3_SaveVector_refs(void)
{
    void (*p)(std::ostream &, const std::vector<sgl::Position> &, unsigned int, const char *) = &scene::SaveVector<sgl::Position>;
    void (*n)(std::ostream &, const std::vector<sgl::Normal> &, unsigned int, const char *) = &scene::SaveVector<sgl::Normal>;
    void (*t)(std::ostream &, const std::vector<sgl::TexCoord> &, unsigned int, const char *) = &scene::SaveVector<sgl::TexCoord>;
    void (*c)(std::ostream &, const std::vector<sgl::Color> &, unsigned int, const char *) = &scene::SaveVector<sgl::Color>;
    __asm__ volatile("" : : "r"(p), "r"(n), "r"(t), "r"(c));
}
namespace scene {
template<class T> static void SaveVector(std::ostream &os, const std::vector<T> &v, unsigned int n, const char *name)
{
    os << D_001683C4 << v.size() * n << D_001680F8 << name << D_00168580;
    int k = 0;
    for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
        const float *f = (const float *)&*it;
        for (unsigned int i = 0; i != n; i++)
            os << f[i] << D_001680F8;
        if (++k == 20) {
            os << D_00168380;
            k = 0;
        }
    }
    os << D_0016812C;
}
template void SaveVector<sgl::Position>(std::ostream &, const std::vector<sgl::Position> &, unsigned int, const char *);
template void SaveVector<sgl::Normal>(std::ostream &, const std::vector<sgl::Normal> &, unsigned int, const char *);
template void SaveVector<sgl::TexCoord>(std::ostream &, const std::vector<sgl::TexCoord> &, unsigned int, const char *);
template void SaveVector<sgl::Color>(std::ostream &, const std::vector<sgl::Color> &, unsigned int, const char *);
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

template<class T> void sgl::PrimitiveIndex<T>::range(int &mn, int &mx) const
{
    bool found = false;
    for (unsigned int i = 0; i != _tri.size(); i++)
        {
        const T &v = _tri[i];
        if (!found) {
            mn = mx = v;
            found = true;
        }
        if (v > mx)
            mx = v;
        if (v < mn)
            mn = v;
    }
    for (int s = 0, k = 0; s != n; s++) {
        int len = _strips[k++];
        for (int j = 0; j != len; j++)
            {
            const T &v = _strips[k + j];
            if (!found) {
                mn = mx = v;
                found = true;
            }
            if (v > mx)
                mx = v;
            if (v < mn)
                mn = v;
        }
        k += len;
    }
}
template void sgl::PrimitiveIndex<int>::range(int &, int &) const;
