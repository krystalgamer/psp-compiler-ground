/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_TEMPLATE_DEFS 1
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
extern const char D_0016E66C[];     /* "k >=0 && k<3" */
extern const char D_0016E67C[];     /* "t0 == i || t1 == i" */
extern const char D_0016E770[];
extern const char D_0016E880[];     /* "triangles indexes and strip indexes mismatch" */
extern const char D_0016E8B0[];     /* "i != 3" */
ST_PRETTY(gat_name, "21get_adjacent_triangleEii");
ST_PRETTY(add_index_name, "9add_indexEPiii");
ST_PRETTY(cmp_name, "15cmp_orientationEPiS1_");
#define ST_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016E2CC, text, D_0016E2B0, fn, line, D_0016E2C8)

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Stripper", _Z41__static_initialization_and_destruction_0ii_CCF18);

extern const char D_0016E2D8[];     /* "get_common_edge( ti, ati ) != -1" */
ST_PRETTY(adjc_name, "14adjacent_checkEPKc");
void sgl::Stripper::adjacent_check(const char *msg)
{
    for (unsigned int ti = 0; ti < _mesh.getTriangles().size(); ti++) {
        stripper_triangle &t = _tris[ti];
        for (int i = 0; i != 3; i++) {
            int ati = t._adj[i & 3];
            if (ati != -1)
                ST_ASSERT(get_common_edge(ti, ati) != -1, D_0016E2D8, adjc_name, 37);
        }
    }
}

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

int sgl::Stripper::get_common_edge(int t1, int t2)
{
    if (t1 == -1)
        return -1;
    if (t2 == -1)
        return -1;
    int e[3];
    _mesh.getTriangleEdgeIndex(t1, e[0], e[1], e[2]);
    for (int i = 0; i != 3; i++) {
        int ei = e[i];
        ST_ASSERT(ei != -1, D_0016E630, gce_name, 419);
        if (ei != -1 && (t2 == _mesh.getEdgeTriangleIndex(ei, 0) || t2 == _mesh.getEdgeTriangleIndex(ei, 1)))
            return ei;
    }
    return -1;
}

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
    ST_ASSERT(k >= 0 && k < 3, D_0016E66C, gat_name, 466);
    int e = _mesh.getTriangleEdgeIndex(i, k);
    if (e == -1)
        return -1;
    assert_valid_edge_index(e);
    int t0 = _mesh.getEdgeTriangleIndex(e, 0);
    int t1 = _mesh.getEdgeTriangleIndex(e, 1);
    ST_ASSERT(t0 == i || t1 == i, D_0016E67C, gat_name, 479);
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

extern const char D_0016E6C8[];     /* "next_edge != -1" */
extern const char D_0016E6D8[];     /* "get_common_edge( next_triangle, current_triangle ) != -1" */
extern const char D_0016E714[];     /* "! _triangles_info[next_triangle].istagged()" */
ST_PRETTY(build_path_name, "10build_pathEiiPKi");
void sgl::Stripper::build_path(int current_triangle, int prev_edge, const int *edges)
{
    if (current_triangle == -1)
        return;
    assert_valid_triangle_index(current_triangle);
    path_tag_triangle(current_triangle);
    _tris[current_triangle]._flags |= 4;
    for (int i = 0; i < 3; i++) {
        int next_edge = _mesh.getTriangleEdgeIndex(current_triangle, i);
        ST_ASSERT(next_edge != -1, D_0016E6C8, build_path_name, 575);
        if (next_edge == prev_edge)
            continue;
        int next_triangle = _tris[current_triangle]._adj[i & 3];
        if (next_triangle == -1)
            continue;
        ST_ASSERT(get_common_edge(next_triangle, current_triangle) != -1, D_0016E6D8, build_path_name, 584);
        if (_tris[next_triangle]._flags & 1)
            continue;
        assert_valid_triangle_index(next_triangle);
        int a = _mesh.getEdgeVertexIndex(next_edge, 0);
        int b = _mesh.getEdgeVertexIndex(next_edge, 1);
        int count = 0;
        for (int j = 0; j < 3; j++) {
            int e = edges[j];
            if (e != -1) {
                int c = _mesh.getEdgeVertexIndex(e, 0);
                int d = _mesh.getEdgeVertexIndex(e, 1);
                if (a == c)
                    count++;
                else if (a == d)
                    count++;
                if (b == c)
                    count++;
                else if (b == d)
                    count++;
            }
        }
        if (count >= 3)
            continue;
        ST_ASSERT(!(_tris[next_triangle]._flags & 1), D_0016E714, build_path_name, 617);
        _tris[next_triangle]._f14 = current_triangle;
        _tris[next_triangle]._f10 = _tris[current_triangle]._f10 + 1;
        ST_ASSERT(get_common_edge(next_triangle, current_triangle) != -1, D_0016E6D8, build_path_name, 625);
        _tris[current_triangle]._flags &= 3;
        int ne[3] = { edges[2], prev_edge, next_edge };
        build_path(next_triangle, next_edge, ne);
    }
}

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
        ST_ASSERT(vertex_index == v[0] || vertex_index == v[1] || vertex_index == v[2], D_0016E770, add_index_name, 671);
        for (int i = 0; i != 3; i++)
            if (vertex_index == v[i]) {
                r = _mesh.getTriangleVertexIndex(t, i);
                break;
            }
    }
    _prims.strips()[*pos] = r;
    (*pos)++;
}

extern const char D_0016E7E4[];     /* "edge != -1" */
ST_PRETTY(read_path_name, "9read_pathEiPi");
void sgl::Stripper::read_path(int t, int *pos)
{
    bool first = true;
    int reverse = 0;
    if (((_tris[t]._flags >> 2) & 1) == 0)
        return;
    while (t != -1) {
        _tris[t]._flags |= 1;
        int next = _tris[t]._f14;
        int edge = get_common_edge(t, next);
        int ov = get_opposite_vertex(next, edge);
        if (next != -1)
            ST_ASSERT(edge != -1, D_0016E7E4, read_path_name, 711);
        if (first) {
            if (next == -1) {
                add_index(pos, _mesh.getTriangleVertexIndex(t, 0), t);
                add_index(pos, _mesh.getTriangleVertexIndex(t, 1), t);
                add_index(pos, _mesh.getTriangleVertexIndex(t, 2), t);
                add_index(pos, -1, t);
                return;
            }
            int nn = _tris[next]._f14;
            int v[3] = { get_opposite_vertex(t, edge), _mesh.getEdgeVertexIndex(edge, 0), _mesh.getEdgeVertexIndex(edge, 1) };
            if (v[1] == _mesh.getTriangleVertexIndex(nn, 0) || v[1] == _mesh.getTriangleVertexIndex(nn, 1) || v[1] == _mesh.getTriangleVertexIndex(nn, 2)) {
                v[1] ^= v[2];
                v[2] ^= v[1];
                v[1] ^= v[2];
            }
            add_index(pos, v[0], t);
            add_index(pos, v[1], t);
            add_index(pos, v[2], t);
            int w[3];
            _mesh.getTriangleVertexIndex(t, w[0], w[1], w[2]);
            reverse = cmp_orientation(v, w);
            first = false;
                    }
        add_index(pos, ov, next);
        t = next;
    }
    if (reverse)
        reverse_strip(*pos);
}

void sgl::Stripper::feed_strips()
{
    int scan = 0;
    for (int i = 0; i < (int)_mesh.getTriangles().size(); i++)
        read_path(i, &scan);
    SGL_ASSERT(scan == (int)_size, D_0016E2CC, D_0016E814, D_0016E2B0, feed_name, 826, D_0016E828);
}

int sgl::Stripper::cmp_orientation(int *a, int *b)
{
    int i = 0;
    while (i < 3 && a[0] != b[i])
        i++;
    SGL_ASSERT(i != 3, D_0016E2CC, D_0016E8B0, D_0016E2B0, cmp_name, 839, D_0016E880);
    if (++i == 3)
        i = 0;
    return a[1] != b[i];
}

extern const char D_0016E8E0[], D_0016E904[], D_0016E924[], D_0016E940[];
ST_PRETTY(rs_name, "13reverse_stripEi");
void sgl::Stripper::reverse_strip(int end)
{
    SGL_ASSERT(end >= 4, D_0016E2CC, D_0016E940, D_0016E2B0, rs_name, 878, D_0016E924);
    SGL_ASSERT(_prims.strips()[end - 1] == -1, D_0016E2CC, D_0016E904, D_0016E2B0, rs_name, 880, D_0016E8E0);
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

extern const char D_0016EAE8[];     /* "_triangles_info[index].isleaf()" */
extern const char D_0016EBB8[];
extern const char D_0016EB94[];
extern const char D_0016E970[];
extern const char D_0016E990[];
extern const char D_0016E9CC[];
extern const char D_0016E9F0[];
extern const char D_0016EA14[];
extern const char D_0016EB24[];
extern const char D_0016EB58[];
extern const char D_0016EB08[];
extern const char D_0016EA98[];
extern const char D_0016EA74[];
extern const char D_0016EA4C[];
ST_PRETTY(scan_back_name, "9scan_backEi");
#define ST_ASSERT_MSG(c, text, line, msg) SGL_ASSERT(c, D_0016E2CC, text, D_0016E2B0, scan_back_name, line, msg)
static inline bool st_isleaf(const sgl::Stripper::stripper_triangle &t) { return (t._flags >> 2) & 1; }
static inline bool st_istagged(const sgl::Stripper::stripper_triangle &t) { return t._flags & 1; }
int sgl::Stripper::scan_back(int leaf)
{
    int scan = 0;
    int index = leaf;
    int len = 0;
    ST_ASSERT_MSG(st_isleaf(_tris[index]), D_0016EAE8, 910, D_0016EBB8);
    ST_ASSERT_MSG(!st_istagged(_tris[index]), D_0016EB94, 912, D_0016E970);
    while (index != -1) {
        len++;
        scan++;
        ST_ASSERT_MSG(!(index != leaf && st_istagged(_tris[index])), D_0016E990, 924, D_0016E9CC);
        _tris[index]._flags |= 1;
        int father = _tris[index]._f14;
        if (father != -1) {
        ST_ASSERT_MSG(!st_isleaf(_tris[father]), D_0016E9F0, 935, D_0016EA14);
        if (st_istagged(_tris[father])) {
            _tris[index]._f14 = -1;
            index = leaf;
            ST_ASSERT_MSG(_tris[index]._heap_id != -1, D_0016EB24, 953, D_0016EB58);
            ST_ASSERT_MSG(st_isleaf(_tris[index]), D_0016EAE8, 958, D_0016EB08);
            while (index != -1) {
                stripper_triangle &tr = _tris[index];
                index = tr._f14;
                tr._f10 = len;
                len--;
            }
            ST_ASSERT_MSG(_heap._e[0].id == (unsigned int)_tris[leaf]._heap_id, D_0016EA98, 972, D_0016E2C8);
            _heap.pop();
            return scan;
        }
        }
        index = father;
    }
    ST_ASSERT_MSG(scan == _tris[leaf]._f10, D_0016EA74, 987, D_0016EA4C);
    _heap.remove(_heap._index[_tris[leaf]._heap_id]);
    return scan;
}

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


extern "C" void sgl_Stripper_instances(std::vector<int> *vi, sgl::PrimitiveIndex<int> *p, std::vector<sgl::Stripper::stripper_triangle> *vt, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sgl_Stripper_instances(std::vector<int> *vi, sgl::PrimitiveIndex<int> *p, std::vector<sgl::Stripper::stripper_triangle> *vt, unsigned int n)
{
    vi->reserve(n);
    p->swap(*p);
    vt->resize(n);
}
