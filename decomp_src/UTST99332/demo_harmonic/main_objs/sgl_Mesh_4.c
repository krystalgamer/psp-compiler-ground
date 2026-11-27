/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* these template instances are still asm below */
namespace std {
extern template void vector<sgl::Edge>::reserve(vector<sgl::Edge>::size_type);
extern template void vector<sgl::Edge>::_M_insert_aux(vector<sgl::Edge>::iterator, const sgl::Edge &);
extern template void vector<sgl::Edge>::_M_fill_insert(vector<sgl::Edge>::iterator, vector<sgl::Edge>::size_type, const sgl::Edge &);
extern template void vector<sgl::VarlenListsList::List>::_M_fill_insert(vector<sgl::VarlenListsList::List>::iterator,
                                                                        vector<sgl::VarlenListsList::List>::size_type,
                                                                        const sgl::VarlenListsList::List &);
extern template vector<sgl::VarlenListsList::List>::iterator
vector<sgl::VarlenListsList::List>::erase(vector<sgl::VarlenListsList::List>::iterator, vector<sgl::VarlenListsList::List>::iterator);
}
extern const char D_0016C198[];     /* " *** error " */
extern const char D_0016C238[];     /* " " */
extern const char D_0016C398[];     /* "../lib/sgl/VarlenListsList.h" */
extern const char D_0016C414[];     /* "_List < _n" */
extern const char D_0016DA68[];     /* "_lists.size() == 0" */
extern const char D_0016DA7C[];     /* "_data.size() == 0" */
extern const char D_0016DB18[];
extern const char VLL_reset_name[] __asm__("_ZZN3sgl15VarlenListsList5resetEvE19__PRETTY_FUNCTION___16DA44");
extern const char VLL_clear_name[] __asm__("_ZZN3sgl15VarlenListsList5clearEjE19__PRETTY_FUNCTION___16DAB4");
extern const char VLL_freeze_name[] __asm__("_ZZN3sgl15VarlenListsList6freezeEvE19__PRETTY_FUNCTION___16DA90");
extern const char VLL_add_name[] __asm__("_ZZN3sgl15VarlenListsList3addEjiE19__PRETTY_FUNCTION___16DAE4");
extern const char D_0016C1B0[];     /* "../lib/sgl/Mesh.finish.cpp" */
extern const char D_0016C1E4[];     /* "\n" */
extern const char D_0016C54C[];
extern const char D_0016C574[];
extern const char D_0016C5A8[];     /* "didn't find edge p" */
extern const char D_0016C5BC[];     /* " p" */
extern const char D_0016C5C0[];     /* " in triangle " */
extern const char findTriangleEdge_name[] __asm__("_ZZNK3sgl4Mesh16findTriangleEdgeEiiiE19__PRETTY_FUNCTION__");
extern const char D_0016C23C[];     /* "_finish" */
extern const char explodeTriangleVertices_name[] __asm__("_ZZN3sgl4Mesh23explodeTriangleVerticesEvE19__PRETTY_FUNCTION__");
extern const char D_0016C134[];     /* "" */
extern const char D_0016C1CC[];     /* "num (graph) edges     " */
extern const char D_0016C1E8[];     /* "num (graph) triangles " */
extern const char D_0016C7B0[];
extern const char D_0016C7EC[];     /* "num < 9" */
extern const char D_0016C7F4[];
extern const char searchCommonPosPair_name[] __asm__("_ZZN3sgl4Mesh19searchCommonPosPairEiiRiS1_E19__PRETTY_FUNCTION__");
#define FINISH_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016C198, text, D_0016C1B0, fn, line, D_0016C238)
#define VLL_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016C198, text, D_0016C398, fn, line, D_0016C238)
inline void sgl::VarlenListsList::clear(unsigned int _List)
{
    VLL_ASSERT(_List < _n, D_0016C414, VLL_clear_name, 85);
    _lists[_List]._cur = 0;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _Z41__static_initialization_and_destruction_0ii_B3EAC);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh6finishERKNS_10MeshParamsE);

void sgl::Mesh::print(std::string name)
{
    if (name != D_0016C134)
        common::Log() << name;
    CoreMesh::print(name);
    if (!getTriangles().empty())
        common::Log() << D_0016C1E8 << (unsigned int)getTriangles().size() << D_0016C1E4;
    if (!getEdges().empty())
        common::Log() << D_0016C1CC << (unsigned int)getEdges().size() << D_0016C1E4;
}

void sgl::Mesh::removeUsusedPositions()
{
    removeUsusedAttributes<std::vector<Position>, Position>(VertexAttrEnum(0), _positions);
}

void sgl::Mesh::removeUsusedNormals()
{
    removeUsusedAttributes<std::vector<Normal>, Normal>(VertexAttrEnum(1), _normals);
}

void sgl::Mesh::removeUsusedColors()
{
    removeUsusedAttributes<std::vector<Color>, Color>(VertexAttrEnum(2), _colors);
}

void sgl::Mesh::removeUsusedTexCoords()
{
    removeUsusedAttributes<std::vector<TexCoord>, TexCoord>(VertexAttrEnum(3), _texcoords);
}

void sgl::Mesh::quantizePositions(bool b, float eps)
{
    quantizeVertexAttribute<std::vector<Position>, Position>(VertexAttrEnum(0), _positions, 3, b, eps);
}

void sgl::Mesh::quantizeTexCoords(bool b, float eps)
{
    quantizeVertexAttribute<std::vector<TexCoord>, TexCoord>(VertexAttrEnum(3), _texcoords, 2, b, eps);
}

void sgl::Mesh::quantizeColors(bool b, float eps)
{
    quantizeVertexAttribute<std::vector<Color>, Color>(VertexAttrEnum(2), _colors, 4, b, eps);
}

void sgl::Mesh::quantizeNormals(bool b, float eps)
{
    quantizeVertexAttribute<std::vector<Normal>, Normal>(VertexAttrEnum(1), _normals, 3, b, eps);
}

void sgl::Mesh::discardColors()
{
    _colors.clear();
    for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
        it->_attr[COL] = -1;
}

void sgl::Mesh::discardNormals()
{
    _normals.clear();
    for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
        it->_attr[NOR] = -1;
}

void sgl::Mesh::discardTexCoords()
{
    _texcoords.clear();
    for (std::vector<Vertex>::iterator it = _vertices.begin(); it != _vertices.end(); ++it)
        it->_attr[TEX] = -1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh15calcHardNormalsERSt6vectorINS_6NormalESaIS2_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh14setHardNormalsENS0_9LocalAttrE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23explodeTriangleVerticesEv);

math::vector_xyzw sgl::ProjectOnPlane(const math::vector_xyzw &p, const math::vector_xyzw &q, const math::vector_xyzw &n)
{
    return p + n * math::dot(q - p, n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh11calcNormalsEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh16quantizeVerticesEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh20removeUsusedVerticesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh19removeFlatTrianglesEf);

extern const char VLL_incrSize_name[] __asm__("_ZZN3sgl15VarlenListsList8incrSizeEjjE19__PRETTY_FUNCTION___16C4D4");
inline void sgl::VarlenListsList::incrSize(unsigned int _List, unsigned int n)
{
    VLL_ASSERT(_List < _n, D_0016C414, VLL_incrSize_name, 76);
    _lists[_List]._size += n;
}
void sgl::Mesh::makePositionsAdjacentTrianglesLists(VarlenListsList &l)
{
    l.reset();
    l.setSize(getPositions().size());
    for (std::vector<Triangle>::const_iterator it = getTriangles().begin(); it != getTriangles().end(); ++it)
        for (int i = 0; i != 3; i++)
            l.incrSize(getVertexAttributeIndex((*it)[i], POS), 1);
    l.freeze();
    int t = 0;
    for (std::vector<Triangle>::const_iterator it = getTriangles().begin(); it != getTriangles().end(); ++it, ++t)
        for (int i = 0; i != 3; i++)
            l.add(getVertexAttributeIndex((*it)[i], POS), t);
}

int sgl::Mesh::findTriangleEdge(int ti, int p0, int p1) const
{
    FINISH_ASSERT(ti >= 0 && ti < (int)_triangles.size(), D_0016C54C, findTriangleEdge_name, 761);
    const Triangle &t = _triangles[ti];
    for (int i = 0; i != 3; i++) {
        int edge_index = t.edge(i);
        FINISH_ASSERT(edge_index >= 0 && edge_index < (int)_edges.size(), D_0016C574, findTriangleEdge_name, 769);
        const Edge &e = _edges[edge_index];
        int a = getVertexAttributeIndex(e.vertex(0), POS);
        int b = getVertexAttributeIndex(e.vertex(1), POS);
        if ((a == p0 && b == p1) || (a == p1 && b == p0))
            return edge_index;
    }
    common::Log() << D_0016C5A8 << p0 << D_0016C5BC << p1 << D_0016C5C0 << ti << D_0016C1E4;
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh17check_connectionsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh25check_duplicate_pos_indexEv);

bool sgl::Mesh::searchCommonPosPair(int ti, int tj, int &a, int &b)
{
    int tip[3], tjp[3];
    getTriangleVertexAttributeIndex(ti, POS, tip[0], tip[1], tip[2]);
    getTriangleVertexAttributeIndex(tj, POS, tjp[0], tjp[1], tjp[2]);
    FINISH_ASSERT(tip[0] != tip[1] && tip[1] != tip[2] && tip[2] != tip[0], D_0016C7F4, searchCommonPosPair_name, 936);
    FINISH_ASSERT(tjp[0] != tjp[1] && tjp[1] != tjp[2] && tjp[2] != tjp[0], D_0016C7B0, searchCommonPosPair_name, 937);
    int common[9];
    int num = 0;
    for (int i = 0; i != 3; i++)
        for (int j = 0; j != 3; j++)
            if (tip[i] == tjp[j]) {
                FINISH_ASSERT(num < 9, D_0016C7EC, searchCommonPosPair_name, 949);
                common[num++] = tip[i];
            }
    if (num == 0)
        return false;
    if (num == 2) {
        a = common[0];
        b = common[1];
        return true;
    }
    return false;
}

/* the local arrays' initializers stay in the module's .rodata */
struct CmpEdgesMasks {
    unsigned int m[4];
};
struct CmpEdgesAttrs {
    sgl::VertexAttrEnum a[4];
};
extern const CmpEdgesMasks D_0016C830;  /* {1, 2, 4, 8} */
extern const CmpEdgesAttrs D_0016C840;  /* {POS, NOR, COL, TEX} */
bool sgl::Mesh::cmpEdges(int e1, int e2, unsigned int mask)
{
    CmpEdgesMasks masks = D_0016C830;
    CmpEdgesAttrs attrs = D_0016C840;
    for (int i = 0; i != 4; i++) {
        if (!(mask & masks.m[i]))
            continue;
        int a0 = getEdgeVertexAttributeIndex(e1, 0, attrs.a[i]);
        int a1 = getEdgeVertexAttributeIndex(e1, 1, attrs.a[i]);
        int b0 = getEdgeVertexAttributeIndex(e2, 0, attrs.a[i]);
        int b1 = getEdgeVertexAttributeIndex(e2, 1, attrs.a[i]);
        if (!((a0 == b0 && a1 == b1) || (a0 == b1 && a1 == b0)))
            return false;
    }
    return true;
}

void sgl::Mesh::calc_initial_edges()
{
    _edges.resize(0);
    _edges.reserve(_triangles.size() * 3);
    int ti = 0;
    int e = 0;
    for (std::vector<Triangle>::iterator it = _triangles.begin(); it != _triangles.end(); ++it, ++ti, e += 3) {
        int a, b, c;
        getTriangleVertexIndex(ti, a, b, c);
        _edges.push_back(Edge(ti, -1, a, b));
        it->e[0] = e;
        _edges.push_back(Edge(ti, -1, b, c));
        it->e[1] = e + 1;
        _edges.push_back(Edge(ti, -1, c, a));
        it->e[2] = e + 2;
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh9calcEdgesEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh17removeUnusedEdgesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh4dumpEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl9SubdivideERNS_11MeshBuilderEiPNS_8PositionEPNS_6NormalEbPNS_5ColorEbPNS_8TexCoordEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh24reverseTrianglesVerticesEv);

static inline sgl::Normal ToNormal(const math::vector_xyzw &v)
{
    return sgl::Normal(v.x, v.y, v.z);
}
void sgl::Mesh::reverseVerticesNormals()
{
    for (std::vector<Normal>::iterator it = _normals.begin(); it != _normals.end(); ++it)
        *it = ToNormal(-*it);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh14calcPrimitivesERKNS_10MeshParamsE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_B3EAC");
void _GLOBAL__I__ZN3sgl4Mesh6finishERKNS_10MeshParamsE(void);
void _GLOBAL__D__ZN3sgl4Mesh6finishERKNS_10MeshParamsE(void);
}

void _GLOBAL__I__ZN3sgl4Mesh6finishERKNS_10MeshParamsE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl4Mesh6finishERKNS_10MeshParamsE(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl14PrimitiveIndexIiEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_8PositionESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_6NormalESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_5ColorESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_8TexCoordESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_8PositionESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_8TexCoordESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_5ColorESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_6NormalESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl4EdgeESaIS1_EE7reserveEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl15VarlenListsList4ListESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEE4findERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE4findERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE4findERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE4findERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl4EdgeESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIiSaIiEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPiS1_EERKi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE4findERKS1_Ri);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE4findERKS1_Ri);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE4findERKS1_Ri);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE8_M_eraseEPSt13_Rb_tree_nodeIS4_E);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE11lower_boundERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE13insert_uniqueESt17_Rb_tree_iteratorIS4_RS4_PS4_ERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl15VarlenListsList4ListESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEE19compute_longest_boxEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEE12node_elementEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEE19merge_node_elementsEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE19compute_longest_boxEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE12node_elementEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE19merge_node_elementsEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE8find_recEPNS_10KdTreeNodeERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE19compute_longest_boxEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE12node_elementEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE19merge_node_elementsEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE8find_recEPNS_10KdTreeNodeERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE19compute_longest_boxEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE12node_elementEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE19merge_node_elementsEPNS_10KdTreeNodeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE8find_recEPNS_10KdTreeNodeERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE9_M_insertEPSt18_Rb_tree_node_baseSC_RKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE13insert_uniqueERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl8TriangleESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl4EdgeESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIPN3sgl4EdgeES2_ET0_T_S4_S3_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIPN3sgl15VarlenListsList4ListES3_ET0_T_S5_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIPN3sgl15VarlenListsList4ListEjS2_ET_S4_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIPN3sgl8TriangleEjS1_ET_S3_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIPN3sgl4EdgeEjS1_ET_S3_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type);

bool sgl::Vertex::operator<(const Vertex &o) const
{
    if (_attr[POS] < o._attr[POS])
        return true;
    if (o._attr[POS] < _attr[POS])
        return false;
    if (_attr[NOR] < o._attr[NOR])
        return true;
    if (o._attr[NOR] < _attr[NOR])
        return false;
    if (_attr[COL] < o._attr[COL])
        return true;
    if (o._attr[COL] < _attr[COL])
        return false;
    if (_attr[TEX] < o._attr[TEX])
        return true;
    if (o._attr[TEX] < _attr[TEX])
        return false;
    return false;
}

void sgl::VarlenListsList::reset()
{
    _n = 0;
    _lists.clear();
    _data.clear();
    VLL_ASSERT(_lists.size() == 0, D_0016DA68, VLL_reset_name, 97);
    VLL_ASSERT(_data.size() == 0, D_0016DA7C, VLL_reset_name, 98);
}

void sgl::VarlenListsList::freeze()
{
    if (_n == 0)
        return;
    _lists[0]._head = 0;
    unsigned int total = _lists[0]._size;
    for (unsigned int i = 1; i != _n; i++) {
        _lists[i]._head = _lists[i - 1]._head + _lists[i - 1]._size;
        total += _lists[i]._size;
    }
    for (unsigned int i = 0; i != _n; i++)
        clear(i);
    if (total == 0) {
        _data.clear();
        VLL_ASSERT(_data.size() == 0, D_0016DA7C, VLL_freeze_name, 135);
    } else
        _data.resize(total);
}

void sgl::VarlenListsList::add(unsigned int _List, int v)
{
    VLL_ASSERT(_List < _n, D_0016C414, VLL_add_name, 147);
    List &l = _lists[_List];
    VLL_ASSERT(l._head + l._cur >= 0 && l._head + l._cur < l._head + l._size, D_0016DB18, VLL_add_name, 153);
    _data[l._head + l._cur] = v;
    l._cur++;
}
