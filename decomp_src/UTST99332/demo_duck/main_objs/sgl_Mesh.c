/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
extern const float D_0016E22C;
#define SGL_POSITION_ONE D_0016E22C
#define SGL_TEMPLATE_DEFS 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sgl4Mesh10use_purpleE\n_GLOBAL__I__ZN3sgl4Mesh10use_purpleE = _GLOBAL__I__ZN3sgl4Mesh7OffsetsC2Ev");
__asm__(".globl _GLOBAL__D__ZN3sgl4Mesh10use_purpleE\n_GLOBAL__D__ZN3sgl4Mesh10use_purpleE = _GLOBAL__D__ZN3sgl4Mesh7OffsetsC2Ev");

/* setAt<vector<Position>, Position> stays asm (linkonce, below): its Position() 1.0f is a pool of its own
   (this unit's SGL_POSITION_ONE is another function's) */
extern template void sgl::Mesh::setAt<std::vector<sgl::Position>, sgl::Position>(unsigned int, std::vector<sgl::Position> &,
                                                                                 sgl::Position);
/* vector<Edge>/vector<Triangle>::_M_fill_insert (and the helpers they inline) are sgl_Mesh_4's instances:
   this object must not emit them (the link keeps the first .gnu.linkonce copy) */
namespace std {
extern template void vector<sgl::Edge>::_M_fill_insert(vector<sgl::Edge>::iterator, vector<sgl::Edge>::size_type, const sgl::Edge &);
extern template void vector<sgl::Triangle>::_M_fill_insert(vector<sgl::Triangle>::iterator, vector<sgl::Triangle>::size_type,
                                                           const sgl::Triangle &);
}

extern const char D_0016E24C[];     /* " = " */
extern const char D_0016E250[];     /* "position at " */
extern const char D_0016E260[];     /* "vertex at " */
extern const char D_0016E26C[];     /* "triangle at " */

extern const char D_0016E248[];     /* " " */
extern const char D_0016E2D4[];     /* "../lib/sgl/Mesh.cpp" */
extern const char D_0016E2E8[];     /* " *** error " */
extern const char D_0016E3B4[];     /* "0 <= ti && ti < (int)_triangles.size()" */
extern const char D_0016E6C8[];
extern const char D_0016E7F0[];
extern const char D_0016E85C[];
extern const char D_0016E2A8[];
extern const char D_0016E334[];
extern const char D_0016E360[];
extern const float D_0016E22C;
extern const float D_0016E230;
extern const float D_0016E234;
extern const int triangleEdgeLenght_NEXT[3] __asm__("_ZZNK3sgl4Mesh18triangleEdgeLenghtEiiE4NEXT");
#define MESH_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016E2E8, text, D_0016E2D4, fn, line, D_0016E248)
#define PRETTY(n, s) extern const char n[] __asm__("_ZZNK3sgl4Mesh" s "E19__PRETTY_FUNCTION__")
PRETTY(triangleArea_name, "12triangleAreaEi");
PRETTY(triangleEdgeLenght_name, "18triangleEdgeLenghtEii");
PRETTY(getTriangleEdgeIndex3_name, "20getTriangleEdgeIndexEiRiS1_S1_");
PRETTY(getTriangleEdgeIndex_name, "20getTriangleEdgeIndexEii");
PRETTY(getTriangleVertexIndex3_name, "22getTriangleVertexIndexEiRiS1_S1_");
PRETTY(getTriangleVertexIndex_name, "22getTriangleVertexIndexEii");
PRETTY(getTriangleVertexAttributeIndex_name, "31getTriangleVertexAttributeIndexEiNS_14VertexAttrEnumERiS2_S2_");
PRETTY(getTriangleVertexPosition3_name, "25getTriangleVertexPositionEiRNS_8PositionES2_S2_");
PRETTY(getTriangleVertexColor3_name, "22getTriangleVertexColorEiRNS_5ColorES2_S2_");
PRETTY(getTriangleVertexNormal3_name, "23getTriangleVertexNormalEiRNS_6NormalES2_S2_");
PRETTY(getTriangleVertexTexCoord3_name, "25getTriangleVertexTexCoordEiRNS_8TexCoordES2_S2_");
PRETTY(getTriangleVertexPosition_name, "25getTriangleVertexPositionEii");
PRETTY(getTriangleVertexNormal_name, "23getTriangleVertexNormalEii");
PRETTY(getTriangleVertexColor_name, "22getTriangleVertexColorEii");
PRETTY(getTriangleVertexTexCoord_name, "25getTriangleVertexTexCoordEii");
PRETTY(getTriangleNormal_name, "17getTriangleNormalEi");
PRETTY(getEdgePositionIndex_name, "20getEdgePositionIndexEii");
PRETTY(getEdgeVertexIndex_name, "18getEdgeVertexIndexEii");
PRETTY(getEdgeVertexIndex2_name, "18getEdgeVertexIndexEiRiS1_");
PRETTY(getEdgeTriangleIndex_name, "20getEdgeTriangleIndexEii");
PRETTY(getEdgeVertexPosition_name, "21getEdgeVertexPositionEiRNS_8PositionES2_");
#define CHECK_TI(fn, line) MESH_ASSERT(0 <= ti && ti < (int)_triangles.size(), D_0016E3B4, fn, line)
#define CHECK_EI(fn, line) MESH_ASSERT(0 <= ei && ei < (int)_edges.size(), D_0016E85C, fn, line)

sgl::Mesh::Offsets::Offsets() : position(0), normal(0), color(0), texcoord(0), vertex(0)
{
}

sgl::Mesh::~Mesh()
{
}

void sgl::Mesh::unlock()
{
    _locked = false;
}

void sgl::Mesh::lock()
{
    _locked = true;
}

bool sgl::Mesh::locked() const
{
    return _locked;
}

int sgl::Mesh::internal_position_index(int i) const
{
    if (i >= 0)
        i += _offsets.position;
    return i;
}

int sgl::Mesh::internal_normal_index(int i) const
{
    if (i >= 0)
        i += _offsets.normal;
    return i;
}

int sgl::Mesh::internal_color_index(int i) const
{
    if (i >= 0)
        i += _offsets.color;
    return i;
}

int sgl::Mesh::internal_texcoord_index(int i) const
{
    if (i >= 0)
        i += _offsets.texcoord;
    return i;
}

int sgl::Mesh::internal_vertex_index(int i) const
{
    if (i >= 0)
        i += _offsets.vertex;
    return i;
}

sgl::Mesh::Mesh(bool b) : _locked(b), _finish(0)
{
}

void sgl::Mesh::snap_offsets()
{
    _offsets.position = _positions.size();
    _offsets.normal = _normals.size();
    _offsets.color = _colors.size();
    _offsets.texcoord = _texcoords.size();
    _offsets.vertex = _vertices.size();
}

void sgl::Mesh::normalAt(int i, Normal n)
{
    setAt(internal_normal_index(i), _normals, n);
}

void sgl::Mesh::colorAt(int i, Color c)
{
    setAt(internal_color_index(i), _colors, c);
}

void sgl::Mesh::texcoordAt(int i, TexCoord t)
{
    setAt(internal_texcoord_index(i), _texcoords, t);
}

void sgl::Mesh::positionAt(int i, Position p)
{
    setAt(internal_position_index(i), _positions, p);
}

void sgl::Mesh::vertexAt(int v, int p, int n, int c, int t)
{
    setAt(internal_vertex_index(v), _vertices, Vertex(internal_position_index(p), internal_normal_index(n), internal_color_index(c), internal_texcoord_index(t)));
}

void sgl::Mesh::pushBackTriangle(Triangle t)
{
    _triangles.push_back(t);
}

void sgl::Mesh::print_positions()
{
    int i = 0;
    for (std::vector<Position>::iterator it = _positions.begin(); it != _positions.end(); ++it, ++i)
        std::cout << D_0016E250 << i << D_0016E24C << it->x << D_0016E248 << it->y << D_0016E248 << it->z << std::endl;
}

void sgl::Mesh::print_vertices()
{
    int i = 0;
    for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it, ++i)
        std::cout << D_0016E260 << i << D_0016E24C << it->_attr[POS] << D_0016E248 << it->_attr[NOR] << D_0016E248 << it->_attr[COL]
                  << D_0016E248 << it->_attr[TEX] << D_0016E248 << std::endl;
}

void sgl::Mesh::print_triangles()
{
    int i = 0;
    for (std::vector<Triangle>::iterator it = _triangles.begin(); it != _triangles.end(); ++it, ++i)
        std::cout << D_0016E26C << i << D_0016E24C << it->v[0] << D_0016E248 << it->v[1] << D_0016E248 << it->v[2] << std::endl;
}

const std::vector<sgl::Triangle> &sgl::Mesh::getTriangles() const
{
    return _triangles;
}

const std::vector<sgl::Edge> &sgl::Mesh::getEdges() const
{
    return _edges;
}

const std::vector<sgl::Normal> &sgl::Mesh::getTrianglesNormals() const
{
    return _tnormals;
}

float sgl::Mesh::triangleArea(int i) const
{
    MESH_ASSERT(i >= 0 && i < (int)getTriangles().size(), D_0016E2A8, triangleArea_name, 226);
    Position a, b, c;
    getTriangleVertexPosition(i, a, b, c);
    return sgl_math_area(a, b, c);
}

float sgl::Mesh::triangleEdgeLenght(int t, int e) const
{
    MESH_ASSERT(t >= 0 && t < (int)getTriangles().size(), D_0016E334, triangleEdgeLenght_name, 237);
    MESH_ASSERT(e >= 0 && e < 3, D_0016E360, triangleEdgeLenght_name, 238);
    math::vector_xyzw d = getTriangleVertexPosition(t, e) - getTriangleVertexPosition(t, triangleEdgeLenght_NEXT[e]);
    return sqrtf(math::dot(d, d));
}

void sgl::Mesh::getTriangleEdgeIndex(int ti, int &a, int &b, int &c) const
{
    CHECK_TI(getTriangleEdgeIndex3_name, 254);
    a = _triangles[ti].e[0];
    b = _triangles[ti].e[1];
    c = _triangles[ti].e[2];
}

int sgl::Mesh::getTriangleEdgeIndex(int ti, int e) const
{
    CHECK_TI(getTriangleEdgeIndex_name, 265);
    return _triangles[ti].edge(e);
}

void sgl::Mesh::getTriangleVertexIndex(int ti, int &a, int &b, int &c) const
{
    CHECK_TI(getTriangleVertexIndex3_name, 277);
    a = _triangles[ti].v[0];
    b = _triangles[ti].v[1];
    c = _triangles[ti].v[2];
}

int sgl::Mesh::getTriangleVertexIndex(int ti, int v) const
{
    CHECK_TI(getTriangleVertexIndex_name, 288);
    return _triangles[ti][v];
}

void sgl::Mesh::getTriangleVertexAttributeIndex(int ti, VertexAttrEnum attr, int &a, int &b, int &c) const
{
    CHECK_TI(getTriangleVertexAttributeIndex_name, 297);
    const Triangle &t = _triangles[ti];
    a = getVertexAttributeIndex(t[0], attr);
    b = getVertexAttributeIndex(t[1], attr);
    c = getVertexAttributeIndex(t[2], attr);
}

void sgl::Mesh::getTriangleVertexPosition(int ti, Position &a, Position &b, Position &c) const
{
    CHECK_TI(getTriangleVertexPosition3_name, 311);
    const Triangle &t = _triangles[ti];
    a = getVertexPosition(t[0]);
    b = getVertexPosition(t[1]);
    c = getVertexPosition(t[2]);
}

void sgl::Mesh::getTriangleVertexColor(int ti, Color &a, Color &b, Color &c) const
{
    CHECK_TI(getTriangleVertexColor3_name, 325);
    const Triangle &t = _triangles[ti];
    a = getVertexColor(t[0]);
    b = getVertexColor(t[1]);
    c = getVertexColor(t[2]);
}

void sgl::Mesh::getTriangleVertexNormal(int ti, Normal &a, Normal &b, Normal &c) const
{
    CHECK_TI(getTriangleVertexNormal3_name, 339);
    const Triangle &t = _triangles[ti];
    a = getVertexNormal(t[0]);
    b = getVertexNormal(t[1]);
    c = getVertexNormal(t[2]);
}

void sgl::Mesh::getTriangleVertexTexCoord(int ti, TexCoord &a, TexCoord &b, TexCoord &c) const
{
    CHECK_TI(getTriangleVertexTexCoord3_name, 353);
    const Triangle &t = _triangles[ti];
    a = getVertexTexCoord(t[0]);
    b = getVertexTexCoord(t[1]);
    c = getVertexTexCoord(t[2]);
}

sgl::Position sgl::Mesh::getTriangleVertexPosition(int ti, int tv) const
{
    MESH_ASSERT(0 <= tv && tv <= 2, D_0016E6C8, getTriangleVertexPosition_name, 364);
    CHECK_TI(getTriangleVertexPosition_name, 365);
    return getVertexPosition(_triangles[ti][tv]);
}

sgl::Normal sgl::Mesh::getTriangleVertexNormal(int ti, int tv) const
{
    MESH_ASSERT(0 <= tv && tv <= 2, D_0016E6C8, getTriangleVertexNormal_name, 374);
    CHECK_TI(getTriangleVertexNormal_name, 375);
    return getVertexNormal(_triangles[ti][tv]);
}

sgl::Color sgl::Mesh::getTriangleVertexColor(int ti, int tv) const
{
    MESH_ASSERT(0 <= tv && tv <= 2, D_0016E6C8, getTriangleVertexColor_name, 384);
    CHECK_TI(getTriangleVertexColor_name, 385);
    return getVertexColor(_triangles[ti][tv]);
}

sgl::TexCoord sgl::Mesh::getTriangleVertexTexCoord(int ti, int tv) const
{
    MESH_ASSERT(0 <= tv && tv <= 2, D_0016E6C8, getTriangleVertexTexCoord_name, 394);
    CHECK_TI(getTriangleVertexTexCoord_name, 395);
    return getVertexTexCoord(_triangles[ti][tv]);
}

sgl::Normal sgl::Mesh::getTriangleNormal(int ti) const
{
    MESH_ASSERT(0 <= ti && ti < (int)_tnormals.size(), D_0016E7F0, getTriangleNormal_name, 467);
    return _tnormals[ti];
}

int sgl::Mesh::getEdgePositionIndex(int ei, int v) const
{
    CHECK_EI(getEdgePositionIndex_name, 474);
    return getVertexPositionIndex(_edges[ei].vertex(v));
}

int sgl::Mesh::getEdgeVertexIndex(int ei, int v) const
{
    CHECK_EI(getEdgeVertexIndex_name, 485);
    return _edges[ei].vertex(v);
}

void sgl::Mesh::getEdgeVertexIndex(int ei, int &a, int &b) const
{
    CHECK_EI(getEdgeVertexIndex2_name, 492);
    a = _edges[ei].vertex(0);
    b = _edges[ei].vertex(1);
}

int sgl::Mesh::getEdgeTriangleIndex(int ei, int t) const
{
    CHECK_EI(getEdgeTriangleIndex_name, 502);
    return _edges[ei].triangle(t);
}

int sgl::Mesh::getEdgeVertexAttributeIndex(int e, int v, VertexAttrEnum a) const
{
    return getVertexAttributeIndex(getEdgeVertexIndex(e, v), a);
}

void sgl::Mesh::getEdgeVertexPosition(int ei, Position &a, Position &b) const
{
    CHECK_EI(getEdgeVertexPosition_name, 517);
    const Edge &e = _edges[ei];
    a = getVertexPosition(e.vertex(0));
    b = getVertexPosition(e.vertex(1));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh", _ZNK3sgl4Mesh18calcTriangleCenterEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh", _ZN3sgl4Mesh5mergeERKS0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh", _ZN3sgl4Mesh28sync_positions_with_verticesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh", _ZN3sgl4Mesh21calcStencilShadowDataERNS_17StencilShadowDataERKNS_8CoreMeshE);

/* inline members / instances kept as asm: .gnu.linkonce.t (splat only sees `INCLUDE_ASM(`) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh", _ZN3sgl4Mesh5setAtISt6vectorINS_8PositionESaIS3_EES3_EEvjRT_T0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh", _ZN3sgl14PrimitiveIndexIiE7flattenEv);

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZN3sgl4Mesh5setAtISt6vectorINS_6NormalESaIS3_EES3_EEvjRT_T0_)
                    DEMO_LINKONCE(_ZN3sgl4Mesh5setAtISt6vectorINS_5ColorESaIS3_EES3_EEvjRT_T0_)
                    DEMO_LINKONCE(_ZN3sgl4Mesh5setAtISt6vectorINS_8TexCoordESaIS3_EES3_EEvjRT_T0_)
                    DEMO_LINKONCE(_ZN3sgl4Mesh5setAtISt6vectorINS_8PositionESaIS3_EES3_EEvjRT_T0_)
                    DEMO_LINKONCE(_ZN3sgl4Mesh5setAtISt6vectorINS_6VertexESaIS3_EES3_EEvjRT_T0_)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIiE6offsetEj)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8TriangleESaIS1_EEaSERKS3_)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIiE7flattenEv)
                    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIiE5clearEv)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8TriangleESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl4EdgeESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8TriangleESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8PositionESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIbSaIbEE14_M_fill_insertESt13_Bit_iteratorjb)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl6NormalESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl5ColorESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8TexCoordESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl6VertexESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt14__simple_allocIiSt24__default_alloc_templateILb1ELi0EEE8allocateEj)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl8TriangleESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl6VertexESaIS1_EE15_M_range_insertIN9__gnu_cxx17__normal_iteratorIPS1_S3_EEEEvS8_T_S9_St20forward_iterator_tag)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8PositionESaIS1_EE15_M_range_insertIN9__gnu_cxx17__normal_iteratorIPS1_S3_EEEEvS8_T_S9_St20forward_iterator_tag)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl6NormalESaIS1_EE15_M_range_insertIN9__gnu_cxx17__normal_iteratorIPS1_S3_EEEEvS8_T_S9_St20forward_iterator_tag)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl5ColorESaIS1_EE15_M_range_insertIN9__gnu_cxx17__normal_iteratorIPS1_S3_EEEEvS8_T_S9_St20forward_iterator_tag)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8TexCoordESaIS1_EE15_M_range_insertIN9__gnu_cxx17__normal_iteratorIPS1_S3_EEEEvS8_T_S9_St20forward_iterator_tag)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8TriangleESaIS1_EE15_M_range_insertIN9__gnu_cxx17__normal_iteratorIPS1_S3_EEEEvS8_T_S9_St20forward_iterator_tag)
                    DEMO_LINKONCE(_ZNSt6vectorIiSaIiEE15_M_range_insertIN9__gnu_cxx17__normal_iteratorIPiS1_EEEEvS6_T_S7_St20forward_iterator_tag)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZSt4fillISt13_Bit_iteratorbEvT_S1_RKT0_)
                    DEMO_LINKONCE(_ZSt6fill_nISt13_Bit_iteratorjbET_S1_T0_RKT1_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl8TriangleES2_ET0_T_S4_S3_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZSt6__copyISt13_Bit_iteratorS0_ET0_T_S2_S1_St26random_access_iterator_tag));

extern "C" void sgl_Mesh_instances(sgl::Mesh *m, sgl::PrimitiveIndex<int> *pi, std::vector<sgl::Normal> *vn, std::vector<sgl::Color> *vc, std::vector<sgl::TexCoord> *vt, std::vector<sgl::Position> *vp, std::vector<sgl::Vertex> *vv, std::vector<sgl::Triangle> *vtr, std::vector<sgl::Edge> *ve, std::vector<bool> *vb, std::vector<int> *vi, unsigned int n, const sgl::Position *pp) __attribute__((section(".discard.asm")));
extern "C" void sgl_Mesh_instances(sgl::Mesh *m, sgl::PrimitiveIndex<int> *pi, std::vector<sgl::Normal> *vn, std::vector<sgl::Color> *vc, std::vector<sgl::TexCoord> *vt, std::vector<sgl::Position> *vp, std::vector<sgl::Vertex> *vv, std::vector<sgl::Triangle> *vtr, std::vector<sgl::Edge> *ve, std::vector<bool> *vb, std::vector<int> *vi, unsigned int n, const sgl::Position *pp)
{
    m->setAt(n, *vn, sgl::Normal());
    m->setAt(n, *vc, sgl::Color());
    m->setAt(n, *vt, sgl::TexCoord());
    vp->push_back(*pp);
    m->setAt(n, *vv, sgl::Vertex());
    pi->offset(n);
    pi->flatten();
    *vtr = *vtr;
    pi->clear();
    vtr->push_back(sgl::Triangle());
    ve->resize(n);
    vtr->resize(n);
    vb->resize(n);
    vv->insert(vv->end(), vv->begin(), vv->end());
    vp->insert(vp->end(), vp->begin(), vp->end());
    vn->insert(vn->end(), vn->begin(), vn->end());
    vc->insert(vc->end(), vc->begin(), vc->end());
    vt->insert(vt->end(), vt->begin(), vt->end());
    vtr->insert(vtr->end(), vtr->begin(), vtr->end());
    vi->insert(vi->end(), vi->begin(), vi->end());
    /* the out-of-line copy that PrimitiveIndex<int>::flatten (asm) calls */
    int *(*volatile alloc)(std::size_t) = &std::__simple_alloc<int, std::__default_alloc_template<true, 0> >::allocate;
    (void)alloc;
}

template<class V, class T> void sgl::Mesh::setAt(unsigned int i, V &v, T t)
{
    if (_locked)
        return;
    if (i == v.size())
        v.push_back(t);
    else {
        if (i > v.size())
            v.resize(i + 1);
        v[i] = t;
    }
}
