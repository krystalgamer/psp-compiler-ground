/* lang: c++ */
/* cflags: -O3 -fno-exceptions -fmerge-constants */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#include <iostream>
#define SGL_TEMPLATE_DEFS 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sgl8Stripper14adjacent_checkEPKc");
__asm__(".globl _GLOBAL__D__ZN3sgl8Stripper14adjacent_checkEPKc");

#define ST_ASSERT(c, text, fn, line) SGL_ASSERT(c, " *** error ", text, "../lib/sgl/Stripper.cpp", fn, line, " ")

void sgl::Stripper::adjacent_check(const char *msg)
{
    for (unsigned int ti = 0; ti < _mesh.getTriangles().size(); ti++) {
        stripper_triangle &t = _tris[ti];
        for (int i = 0; i != 3; i++) {
            int ati = t._adj[i & 3];
            if (ati != -1)
                ST_ASSERT(get_common_edge(ti, ati) != -1, "get_common_edge( ti, ati ) != -1", __PRETTY_FUNCTION__, 37);
        }
    }
}

void sgl::Stripper::run()
{
    _prims.clear();
    if (_mesh.getTriangles().empty()) {
        common::Log() << "no triangles, can't compute strips\n";
        return;
    }
    _size = 0;
    _tris.resize(_mesh.getTriangles().size());
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++) {
        stripper_triangle &t = _tris[i];
        for (int j = 0; j != 3; j++) {
            int a = get_adjacent_triangle(i, j);
            t._adj[j & 3] = a;
        }
    }
    adjacent_check("");
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++)
        count_untagged_neighbors(i);
    reset_flags();
    _heap.resize(_mesh.getTriangles().size());
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++) {
        _heap.set_element(i, i, -(float)_tris[i]._untagged);
        _tris[i]._heap_id = i;
    }
    _heap.heapify();
    while (_heap._n > 0) {
        int t = _heap._e[0].data;
        _tris[t]._f14 = -1;
        _tris[t]._flags |= 2;
        int edges[3] = { -1, -1, -1 };
        build_path(t, -1, edges);
    }
    _heap.clear();
    reset_flags();
    int n = 0;
    for (unsigned int i = 0; i < _mesh.getTriangles().size(); i++)
        n += (_tris[i]._flags >> 2) & 1;
    _heap.resize(n);
    unsigned int i = 0;
    int k = 0;
    for (; i < _mesh.getTriangles().size(); i++) {
        if ((_tris[i]._flags >> 2) & 1) {
            _heap.set_element(k, i, (float)_tris[i]._f10);
            _tris[i]._heap_id = k;
            k++;
        } else
            _tris[i]._heap_id = -1;
    }
    _heap.heapify();
    reset_flags();
    while (_heap._n > 0)
        scan_back(_heap._e[0].data);
    _heap.clear();
    count_strips();
    fix_cullface();
    _prims.strips().reserve(_size);
    for (unsigned int i = 0; i < _size; i++)
        _prims.strips().push_back(-2);
    feed_strips();
    convert_to_new_format();
    collect_triangles();
    _prims.check();
    _mesh._prims.swap(_prims);
}

void sgl::Stripper::undo()
{
    int l = _max_length;
    _max_length = 0x7FFFFFFF;
    collect_triangles();
    _max_length = l;
}

void sgl::Stripper::assert_valid_vertex_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getVertices().size()) || i == -1, "( i>=0 && i < (int)_mesh.getVertices().size() ) || i == -1", __PRETTY_FUNCTION__, 206);
}

void sgl::Stripper::assert_valid_edge_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getEdges().size()) || i == -1, "( i>=0 && i < (int)_mesh.getEdges().size() ) || i == -1", __PRETTY_FUNCTION__, 213);
}

void sgl::Stripper::assert_valid_triangle_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_mesh.getTriangles().size()) || i == -1, "( i>=0 && i < (int)_mesh.getTriangles().size() ) || i == -1", __PRETTY_FUNCTION__, 220);
}

void sgl::Stripper::assert_valid_strip_index(int i)
{
    ST_ASSERT((i >= 0 && i < (int)_prims.strips().capacity()) || i == -1, "( i>=0 && i < (int)_prims.strips().capacity() ) || i == -1", __PRETTY_FUNCTION__, 227);
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
        ST_ASSERT(ei != -1, "e != -1", __PRETTY_FUNCTION__, 419);
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
    ST_ASSERT(k >= 0 && k < 3, "k >=0 && k<3", __PRETTY_FUNCTION__, 466);
    int e = _mesh.getTriangleEdgeIndex(i, k);
    if (e == -1)
        return -1;
    assert_valid_edge_index(e);
    int t0 = _mesh.getEdgeTriangleIndex(e, 0);
    int t1 = _mesh.getEdgeTriangleIndex(e, 1);
    ST_ASSERT(t0 == i || t1 == i, "t0 == i || t1 == i", __PRETTY_FUNCTION__, 479);
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

void sgl::Stripper::build_path(int current_triangle, int prev_edge, const int *edges)
{
    if (current_triangle == -1)
        return;
    assert_valid_triangle_index(current_triangle);
    path_tag_triangle(current_triangle);
    _tris[current_triangle]._flags |= 4;
    for (int i = 0; i < 3; i++) {
        int next_edge = _mesh.getTriangleEdgeIndex(current_triangle, i);
        ST_ASSERT(next_edge != -1, "next_edge != -1", __PRETTY_FUNCTION__, 575);
        if (next_edge == prev_edge)
            continue;
        int next_triangle = _tris[current_triangle]._adj[i & 3];
        if (next_triangle == -1)
            continue;
        ST_ASSERT(get_common_edge(next_triangle, current_triangle) != -1, "get_common_edge( next_triangle, current_triangle ) != -1", __PRETTY_FUNCTION__, 584);
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
        ST_ASSERT(!(_tris[next_triangle]._flags & 1), "! _triangles_info[next_triangle].istagged()", __PRETTY_FUNCTION__, 617);
        _tris[next_triangle]._f14 = current_triangle;
        _tris[next_triangle]._f10 = _tris[current_triangle]._f10 + 1;
        ST_ASSERT(get_common_edge(next_triangle, current_triangle) != -1, "get_common_edge( next_triangle, current_triangle ) != -1", __PRETTY_FUNCTION__, 625);
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
        ST_ASSERT(vertex_index == v[0] || vertex_index == v[1] || vertex_index == v[2], "vertex_index == v[0] || vertex_index == v[1] || vertex_index == v[2]", __PRETTY_FUNCTION__, 671);
        for (int i = 0; i != 3; i++)
            if (vertex_index == v[i]) {
                r = _mesh.getTriangleVertexIndex(t, i);
                break;
            }
    }
    _prims.strips()[*pos] = r;
    (*pos)++;
}

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
            ST_ASSERT(edge != -1, "edge != -1", __PRETTY_FUNCTION__, 711);
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
    SGL_ASSERT(scan == (int)_size, " *** error ", "scan == (int)_size", "../lib/sgl/Stripper.cpp", __PRETTY_FUNCTION__, 826, "strip length doesn't match prevision");
}

bool sgl::Stripper::cmp_orientation(int *a, int *b)
{
    int i = 0;
    while (i < 3 && a[0] != b[i])
        i++;
    SGL_ASSERT(i != 3, " *** error ", "i != 3", "../lib/sgl/Stripper.cpp", __PRETTY_FUNCTION__, 839, "triangles indexes and strip indexes mismatch");
    if (++i == 3)
        i = 0;
    return a[1] != b[i];
}

void sgl::Stripper::reverse_strip(int end)
{
    SGL_ASSERT(end >= 4, " *** error ", "scan >= 4", "../lib/sgl/Stripper.cpp", __PRETTY_FUNCTION__, 878, "strips has a zero length");
    SGL_ASSERT(_prims.strips()[end - 1] == -1, " *** error ", "_prims.strips()[scan-1] == -1", "../lib/sgl/Stripper.cpp", __PRETTY_FUNCTION__, 880, "strips is not terminated by a -1");
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

#define ST_ASSERT_MSG(c, text, line, msg) SGL_ASSERT(c, " *** error ", text, "../lib/sgl/Stripper.cpp", __PRETTY_FUNCTION__, line, msg)
static inline bool st_isleaf(const sgl::Stripper::stripper_triangle &t) { return (t._flags >> 2) & 1; }
static inline bool st_istagged(const sgl::Stripper::stripper_triangle &t) { return t._flags & 1; }
int sgl::Stripper::scan_back(int leaf)
{
    int scan = 0;
    int index = leaf;
    int len = 0;
    ST_ASSERT_MSG(st_isleaf(_tris[index]), "_triangles_info[index].isleaf()", 910, "scan_back() leaf is not a leaf...");
    ST_ASSERT_MSG(!st_istagged(_tris[index]), "! _triangles_info[index].istagged()", 912, "scan_back() leaf already tagged");
    while (index != -1) {
        len++;
        scan++;
        ST_ASSERT_MSG(!(index != leaf && st_istagged(_tris[index])), "! ( index != leaf && _triangles_info[index].istagged() )", 924, "that one has already been scanned");
        _tris[index]._flags |= 1;
        int father = _tris[index]._f14;
        if (father != -1) {
        ST_ASSERT_MSG(!st_isleaf(_tris[father]), "! _triangles_info[father].isleaf()", 935, "a path goes from a leaf to a leaf, the graph is wrong");
        if (st_istagged(_tris[father])) {
            _tris[index]._f14 = -1;
            index = leaf;
            ST_ASSERT_MSG(_tris[index]._heap_id != -1, "_triangles_info[index]._heap_initial_index != -1", 953, "triangle is supposed to be a leaf, but its backlink is -1");
            ST_ASSERT_MSG(st_isleaf(_tris[index]), "_triangles_info[index].isleaf()", 958, "shouldn't index  be a leaf?");
            while (index != -1) {
                stripper_triangle &tr = _tris[index];
                index = tr._f14;
                tr._f10 = len;
                len--;
            }
            ST_ASSERT_MSG(_heap._e[0].id == (unsigned int)_tris[leaf]._heap_id, "_heap._a[0]._initial_index == (size_t)_triangles_info[leaf]._heap_initial_index", 972, " ");
            _heap.pop();
            return scan;
        }
        }
        index = father;
    }
    ST_ASSERT_MSG(scan == _tris[leaf]._f10, "scan == _triangles_info[leaf]._len", 987, "path length/scanned length don't match");
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

extern "C" void sgl_Stripper_instances(std::vector<int> *vi, sgl::PrimitiveIndex<int> *p, std::vector<sgl::Stripper::stripper_triangle> *vt, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sgl_Stripper_instances(std::vector<int> *vi, sgl::PrimitiveIndex<int> *p, std::vector<sgl::Stripper::stripper_triangle> *vt, unsigned int n)
{
    vi->reserve(n);
    p->swap(*p);
    vt->resize(n);
}

/* collect_triangles (asm) uses strings that adjacent_check emits first: their labels (the original layout) */
__asm__("D_0016E2B0 = _ZZN3sgl8Stripper14adjacent_checkEPKcE19__PRETTY_FUNCTION__ + 0x30\n"
        "D_0016E2C8 = _ZZN3sgl8Stripper14adjacent_checkEPKcE19__PRETTY_FUNCTION__ + 0x48\n"
        "D_0016E2CC = _ZZN3sgl8Stripper14adjacent_checkEPKcE19__PRETTY_FUNCTION__ + 0x4C\n");
