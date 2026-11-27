/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* these template instances are still asm below */
namespace std {
extern template void vector<math::vector_xyzw>::_M_insert_aux(vector<math::vector_xyzw>::iterator, const math::vector_xyzw &);
extern template vector<math::vector_xyzw>::iterator vector<math::vector_xyzw>::erase(vector<math::vector_xyzw>::iterator,
                                                                                    vector<math::vector_xyzw>::iterator);
extern template void vector<math::vector_xyzw>::_M_fill_insert(vector<math::vector_xyzw>::iterator, vector<math::vector_xyzw>::size_type,
                                                              const math::vector_xyzw &);
}

extern const char D_0016D68C[];     /* " " */
extern const char D_0016D690[];     /* " *** error " */
extern const char D_0016D69C[];
extern const char D_0016D6E0[];     /* file */
extern const char longestAxis_name[] __asm__("_ZZNK3sgl2BV11longestAxisEvE19__PRETTY_FUNCTION__");

extern const float D_0016D630;      /* 1.0f */
extern const float D_0016D634;      /* 1.0f */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _Z41__static_initialization_and_destruction_0ii_A19B0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BVC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BVC1Ev);

void sgl::BV::setType(sgl::BV::Type v)
{
    _type = v;
}

void sgl::BV::start()
{
    Box::first(math::vector_xyzw(0, 0, 0, D_0016D630));
    Box::add(math::vector_xyzw(0, 0, 0, D_0016D630));
    _started = true;
}

void sgl::BV::add(math::vector_xyzw v)
{
    if (_started) {
        Box::first(v);
        if (_type == 1)
            _points.resize(0);
        _started = false;
    } else
        Box::add(v);
    if (_type == 1)
        _points.push_back(v);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BV3addERKS0_RKN4math6matrixE);

void sgl::BV::add(float x, float y, float z)
{
    add(math::vector_xyzw(x, y, z, D_0016D634));
}

void sgl::BV::add(const BV &o)
{
    for (int i = 0; i != 8; i++)
        add(o._c[i]);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BV6finishEv);

void sgl::BV::draw() const
{
    Box::draw();
}

void sgl::BV::draw(int n) const
{
    Box::draw(n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BV8calc_obbEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZNK3sgl2BV9intersectERfRKN4math11vector_xyzwES5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZNK3sgl2BV11longestAxisEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_A19B0");
void _GLOBAL__I__ZN3sgl2BV7_pointsE(void);
void _GLOBAL__D__ZN3sgl2BV7_pointsE(void);
}

void _GLOBAL__I__ZN3sgl2BV7_pointsE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl2BV7_pointsE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEEC1ERSt6vectorIS2_SaIS2_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE4findERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN4math3sqrIfEET_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZNSt6vectorIN4math11vector_xyzwESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZNSt6vectorIN4math11vector_xyzwESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE4findERKS2_Ri);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE19compute_longest_boxEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE12node_elementEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE19merge_node_elementsEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE8find_recEPNS_10KdTreeNodeERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZNSt6vectorIN4math11vector_xyzwESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZSt24__uninitialized_copy_auxIPN4math11vector_xyzwES2_ET0_T_S4_S3_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_BV", _ZN3sgl10KdTreeNodeD1Ev);
