/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_TEMPLATE_DEFS 1
#include "../main.hpp"

extern const char D_001711D8[];     /* "../lib/sgl/Stripper.cpp" */
extern const char D_001711F0[];     /* " " */
extern const char D_001711F4[];     /* " *** error " */
extern const char D_0017128C[];
extern const char D_001712FC[];
extern const char D_0017136C[];
extern const char D_001713DC[];
extern const char D_00171558[];     /* "e != -1" */
extern const char D_0017173C[];     /* "scan == (int)_size" */
extern const char D_00171750[];     /* "strip length doesn't match prevision" */
#define ST_PRETTY(n, s) extern const char n[] __asm__("_ZZN3sgl8Stripper" s "E19__PRETTY_FUNCTION__")
ST_PRETTY(avv_name, "25assert_valid_vertex_indexEi");
ST_PRETTY(ave_name, "23assert_valid_edge_indexEi");
ST_PRETTY(avt_name, "27assert_valid_triangle_indexEi");
ST_PRETTY(avs_name, "24assert_valid_strip_indexEi");
ST_PRETTY(gce_name, "15get_common_edgeEii");
ST_PRETTY(feed_name, "11feed_stripsEv");
extern const char D_00171594[];     /* "k >=0 && k<3" */
extern const char D_001715A4[];     /* "t0 == i || t1 == i" */
extern const char D_00171698[];
extern const char D_001717A8[];     /* "triangles indexes and strip indexes mismatch" */
extern const char D_001717D8[];     /* "i != 3" */
ST_PRETTY(gat_name, "21get_adjacent_triangleEii");
ST_PRETTY(add_index_name, "9add_indexEPiii");
ST_PRETTY(cmp_name, "15cmp_orientationEPiS1_");
#define ST_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_001711F4, text, D_001711D8, fn, line, D_001711F0)

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _Z41__static_initialization_and_destruction_0ii_CF2FC);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper14adjacent_checkEPKc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper3runEv);

void sgl::Stripper::undo()
{
    int l = _max_length;
    _max_length = 0x7FFFFFFF;
    collect_triangles();
    _max_length = l;
}

void sgl::Stripper::assert_valid_vertex_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getVertices().size()) || i == -1, D_0017128C, avv_name, 206);
}

void sgl::Stripper::assert_valid_edge_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getEdges().size()) || i == -1, D_001712FC, ave_name, 213);
}

void sgl::Stripper::assert_valid_triangle_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getTriangles().size()) || i == -1, D_0017136C, avt_name, 220);
}

void sgl::Stripper::assert_valid_strip_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_prims.strips().capacity()) || i == -1, D_001713DC, avs_name, 227);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper17collect_trianglesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper15get_common_edgeEii);

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

int sgl::Stripper::get_adjacent_triangle(int i, int k)
{
    ST_ASSERT(k >= 0 && k < 3, D_00171594, gat_name, 466);
    int e = _mesh.getTriangleEdgeIndex(i, k);
    if (e == -1)
        return -1;
    assert_valid_edge_index(e);
    int t0 = _mesh.getEdgeTriangleIndex(e, 0);
    int t1 = _mesh.getEdgeTriangleIndex(e, 1);
    ST_ASSERT(t0 == i || t1 == i, D_001715A4, gat_name, 479);
    if (t0 == i)
        return t1;
    return t0;
}

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper10build_pathEiiPKi);

void sgl::Stripper::reset_flags()
{
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++)
        _tris[i]._flags &= 6;
}

void sgl::Stripper::add_index(int *pos, int vertex_index, int t)
{
    int r = -1;
    assert_valid_strip_index(*pos);
    assert_valid_vertex_index(vertex_index);
    if (vertex_index != -1) {
        int v[3];
        _mesh.getTriangleVertexIndex(t, v[0], v[1], v[2]);
        ST_ASSERT(vertex_index == v[0] || vertex_index == v[1] || vertex_index == v[2], D_00171698, add_index_name, 671);
        for (int i = 0; i != 3; i++)
            if (vertex_index == v[i]) {
                r = _mesh.getTriangleVertexIndex(t, i);
                break;
            }
    }
    _prims.strips()[*pos] = r;
    (*pos)++;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper9read_pathEiPi);

void sgl::Stripper::feed_strips()
{
    int scan = 0;
    for (int i = 0; i < (int)_mesh.getTriangles().size(); i++)
        read_path(i, &scan);
    SGL_ASSERT(scan == (int)_size, D_001711F4, D_0017173C, D_001711D8, feed_name, 826, D_00171750);
}

int sgl::Stripper::cmp_orientation(int *a, int *b)
{
    int i = 0;
    while (i < 3 && a[0] != b[i])
        i++;
    SGL_ASSERT(i != 3, D_001711F4, D_001717D8, D_001711D8, cmp_name, 839, D_001717A8);
    if (++i == 3)
        i = 0;
    return a[1] != b[i];
}

extern const char D_00171808[], D_0017182C[], D_0017184C[], D_00171868[];
ST_PRETTY(rs_name, "13reverse_stripEi");
void sgl::Stripper::reverse_strip(int end)
{
    SGL_ASSERT(end >= 4, D_001711F4, D_00171868, D_001711D8, rs_name, 878, D_0017184C);
    SGL_ASSERT(_prims.strips()[end - 1] == -1, D_001711F4, D_0017182C, D_001711D8, rs_name, 880, D_00171808);
    int last = end - 2;
    int i = last;
    for (;;) {
        if (i < 0) {
            i = 0;
            break;
        }
        if (_prims.strips()[i] == -1) {
            i++;
            break;
        }
        i--;
    }
    for (int j = last; i < j; i++, j--) {
        _prims.strips()[i] ^= _prims.strips()[j];
        _prims.strips()[j] ^= _prims.strips()[i];
        _prims.strips()[i] ^= _prims.strips()[j];
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Stripper", _ZN3sgl8Stripper9scan_backEi);

void sgl::Stripper::fix_cullface()
{
    if (!_f18)
        return;
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++) {
        stripper_triangle &t = _tris[i];
        if (t._flags >> 2 & 1) {
            if ((t._f10 & 1) == 0) {
                int n = t._f14;
                if (n != -1)
                    _tris[n]._flags |= 4;
                _tris[i]._f14 = -1;
                _tris[i]._f10 = 1;
                _size += 3;
            }
        }
    }
}

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

void sgl::Stripper::convert_to_new_format()
{
    int *s = &_prims.strips()[0];
    if (s == 0)
        return;
    if (_size == 0)
        return;
    _prims.n = 0;
    int i;
    for (i = 0; i < (int)_size; i++)
        if (s[i] == -1)
            _prims.n++;
    for (i = 0; i < (int)_size;) {
        int first = s[i];
        int &cnt = s[i];
        cnt = 0;
        int j = i;
        while (s[++j] != -1)
            ;
        int next = j + 1;
        for (; i < j; j--) {
            s[j] = s[j - 1];
            cnt++;
        }
        s[j + 1] = first;
        i = next;
    }
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_CF2FC");
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


extern "C" void sgl_Stripper_instances(std::vector<int> *vi, sgl::PrimitiveIndex<int> *p, std::vector<sgl::Stripper::stripper_triangle> *vt, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sgl_Stripper_instances(std::vector<int> *vi, sgl::PrimitiveIndex<int> *p, std::vector<sgl::Stripper::stripper_triangle> *vt, unsigned int n)
{
    vi->reserve(n);
    p->swap(*p);
    vt->resize(n);
}
