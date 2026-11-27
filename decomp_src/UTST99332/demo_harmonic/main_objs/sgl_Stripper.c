/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_0016E2B0[];     /* "../lib/sgl/Stripper.cpp" */
extern const char D_0016E2C8[];     /* " " */
extern const char D_0016E2CC[];     /* " *** error " */
extern const char D_0016E364[];
extern const char D_0016E3D4[];
extern const char D_0016E444[];
extern const char D_0016E4B4[];
extern const char D_0016E630[];     /* "e != -1" */
extern const char D_0016E814[];     /* "scan == (int)_size" */
extern const char D_0016E828[];     /* "strip length doesn't match prevision" */
#define ST_PRETTY(n, s) extern const char n[] __asm__("_ZZN3sgl8Stripper" s "E19__PRETTY_FUNCTION__")
ST_PRETTY(avv_name, "25assert_valid_vertex_indexEi");
ST_PRETTY(ave_name, "23assert_valid_edge_indexEi");
ST_PRETTY(avt_name, "27assert_valid_triangle_indexEi");
ST_PRETTY(avs_name, "24assert_valid_strip_indexEi");
ST_PRETTY(gce_name, "15get_common_edgeEii");
ST_PRETTY(feed_name, "11feed_stripsEv");
#define ST_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016E2CC, text, D_0016E2B0, fn, line, D_0016E2C8)

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _Z41__static_initialization_and_destruction_0ii_CCF18);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper14adjacent_checkEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper3runEv);

void sgl::Stripper::undo()
{
    int l = _max_length;
    _max_length = 0x7FFFFFFF;
    collect_triangles();
    _max_length = l;
}

void sgl::Stripper::assert_valid_vertex_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getVertices().size()) || i == -1, D_0016E364, avv_name, 206);
}

void sgl::Stripper::assert_valid_edge_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getEdges().size()) || i == -1, D_0016E3D4, ave_name, 213);
}

void sgl::Stripper::assert_valid_triangle_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getTriangles().size()) || i == -1, D_0016E444, avt_name, 220);
}

void sgl::Stripper::assert_valid_strip_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_prims.strips().capacity()) || i == -1, D_0016E4B4, avs_name, 227);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper17collect_trianglesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper15get_common_edgeEii);

int sgl::Stripper::get_opposite_vertex(int t, int e)
{
    if (e == -1 || t == -1)
        return -1;
    int ev[2];
    _mesh.getEdgeVertexIndex(e, ev[0], ev[1]);
    int tv[3];
    _mesh.getTriangleVertexIndex(t, tv[0], tv[1], tv[2]);
    for (int i = 0; i != 3; i++)
        if (ev[0] != tv[i] && ev[1] != tv[i]) {
            assert_valid_vertex_index(tv[i]);
            return tv[i];
        }
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper21get_adjacent_triangleEii);

int sgl::Stripper::count_untagged_neighbors(int t)
{
    int n = 0;
    for (int i = 0; i < 3; i++) {
        int a = _tris[t]._adj[i & 3];
        if (a != -1 && (_tris[a]._flags & 1) == 0)
            n++;
    }
    _tris[t]._untagged = n;
    return n;
}

void sgl::Stripper::path_tag_triangle(int t)
{
    _tris[t]._flags |= 1;
    count_untagged_neighbors(t);
    stripper_triangle &tr = _tris[t];
    _heap.change_value(tr._heap_id, -(float)tr._untagged);
    for (int i = 0; i < 3; i++) {
        int a = tr._adj[i & 3];
        if (a == -1)
            continue;
        stripper_triangle &nb = _tris[a];
        if ((nb._flags & 1) == 0) {
            count_untagged_neighbors(a);
            _heap.change_value(nb._heap_id, -(float)nb._untagged);
        }
    }
    _heap.remove(_heap._index[tr._heap_id]);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper10build_pathEiiPKi);

void sgl::Stripper::reset_flags()
{
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++)
        _tris[i]._flags &= 6;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper9add_indexEPiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper9read_pathEiPi);

void sgl::Stripper::feed_strips()
{
    int scan = 0;
    for (int i = 0; i < (int)_mesh.getTriangles().size(); i++)
        read_path(i, &scan);
    SGL_ASSERT(scan == (int)_size, D_0016E2CC, D_0016E814, D_0016E2B0, feed_name, 826, D_0016E828);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper15cmp_orientationEPiS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper13reverse_stripEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper9scan_backEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper12fix_cullfaceEv);

int sgl::Stripper::count_strips()
{
    int n = 0;
    _size = 0;
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++)
        if (_tris[i]._flags >> 2 & 1) {
            n++;
            _size += _tris[i]._f10 + 3;
        }
    return n;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper21convert_to_new_formatEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_CCF18");
void _GLOBAL__I__ZN3sgl8Stripper14adjacent_checkEPKc(void);
void _GLOBAL__D__ZN3sgl8Stripper14adjacent_checkEPKc(void);
}

void _GLOBAL__I__ZN3sgl8Stripper14adjacent_checkEPKc(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl8Stripper14adjacent_checkEPKc(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZNSt6vectorIiSaIiEE7reserveEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl14PrimitiveIndexIiE4swapERS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZNSt6vectorIN3sgl8Stripper17stripper_triangleESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZNSt6vectorIN3sgl8Stripper17stripper_triangleESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl8Stripper17stripper_triangleESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZSt24__uninitialized_copy_auxIPN3sgl8Stripper17stripper_triangleES3_ET0_T_S5_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZSt26__uninitialized_fill_n_auxIPN3sgl8Stripper17stripper_triangleEjS2_ET_S4_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8Stripper17stripper_triangleESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8Stripper17stripper_triangleESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8Stripper17stripper_triangleESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type);

