/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN3sgl14PrimitiveIndexIiEC1Ev)
    DEMO_LINKONCE(_ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_8PositionESaIS3_EES3_EEvNS_14VertexAttrEnumERT_)
    DEMO_LINKONCE(_ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_6NormalESaIS3_EES3_EEvNS_14VertexAttrEnumERT_)
    DEMO_LINKONCE(_ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_5ColorESaIS3_EES3_EEvNS_14VertexAttrEnumERT_)
    DEMO_LINKONCE(_ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_8TexCoordESaIS3_EES3_EEvNS_14VertexAttrEnumERT_)
    DEMO_LINKONCE(_ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_8PositionESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf)
    DEMO_LINKONCE(_ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_8TexCoordESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf)
    DEMO_LINKONCE(_ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_5ColorESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf)
    DEMO_LINKONCE(_ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_6NormalESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf)
    DEMO_LINKONCE(_ZNSt6vectorIN3sgl4EdgeESaIS1_EE7reserveEj)
    DEMO_LINKONCE(_ZNSt6vectorIN3sgl15VarlenListsList4ListESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEEC1ERSt6vectorIS1_SaIS1_EEif)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE4findERKS1_)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEEC1ERSt6vectorIS1_SaIS1_EEif)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEE4findERKS1_)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEEC1ERSt6vectorIS1_SaIS1_EEif)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEE4findERKS1_)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEEC1ERSt6vectorIS1_SaIS1_EEif)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEE4findERKS1_)
    DEMO_LINKONCE(_ZNSt6vectorIN3sgl4EdgeESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
    DEMO_LINKONCE(_ZNSt6vectorIiSaIiEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPiS1_EERKi)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE5buildEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEE5buildEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEE4findERKS1_Ri)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEE5buildEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEE4findERKS1_Ri)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEE5buildEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEE4findERKS1_Ri)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE8_M_eraseEPSt13_Rb_tree_nodeIS4_E)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE11lower_boundERS3_)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE13insert_uniqueESt17_Rb_tree_iteratorIS4_RS4_PS4_ERKS4_)
    DEMO_LINKONCE(_ZNSt6vectorIN3sgl15VarlenListsList4ListESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE19compute_longest_boxEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE12node_elementEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE19merge_node_elementsEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEE19compute_longest_boxEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEE12node_elementEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEE19merge_node_elementsEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_8TexCoordEE8find_recEPNS_10KdTreeNodeERKS1_)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEE19compute_longest_boxEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEE12node_elementEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEE19merge_node_elementsEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_5ColorEE8find_recEPNS_10KdTreeNodeERKS1_)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEE19compute_longest_boxEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEE12node_elementEPNS_10KdTreeNodeEj)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEE19merge_node_elementsEPNS_10KdTreeNodeE)
    DEMO_LINKONCE(_ZN3sgl6KdTreeINS_6NormalEE8find_recEPNS_10KdTreeNodeERKS1_)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE9_M_insertEPSt18_Rb_tree_node_baseSC_RKS4_)
    DEMO_LINKONCE(_ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE13insert_uniqueERKS4_)
    DEMO_LINKONCE(_ZNSt6vectorIN3sgl8TriangleESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    DEMO_LINKONCE(_ZNSt6vectorIN3sgl4EdgeESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl4EdgeES2_ET0_T_S4_S3_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl15VarlenListsList4ListES3_ET0_T_S5_S4_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl15VarlenListsList4ListEjS2_ET_S4_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl8TriangleEjS1_ET_S3_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl4EdgeEjS1_ET_S3_T0_RKT1_12__false_type)
    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
);

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
extern const char D_0016F0C0[];     /* " *** error " */
extern const char D_0016F160[];     /* " " */
extern const char D_0016F2C0[];     /* "../lib/sgl/VarlenListsList.h" */
extern const char D_0016F33C[];     /* "_List < _n" */
extern const char D_0016F0D8[];     /* "../lib/sgl/Mesh.finish.cpp" */
extern const char D_0016F10C[];     /* "\n" */
extern const char D_0016F474[];
extern const char D_0016F49C[];
extern const char D_0016F4D0[];     /* "didn't find edge p" */
extern const char D_0016F4E4[];     /* " p" */
extern const char D_0016F4E8[];     /* " in triangle " */
extern const char findTriangleEdge_name[] __asm__("_ZZNK3sgl4Mesh16findTriangleEdgeEiiiE19__PRETTY_FUNCTION__");
extern const char D_0016F164[];     /* "_finish" */
extern const char explodeTriangleVertices_name[] __asm__("_ZZN3sgl4Mesh23explodeTriangleVerticesEvE19__PRETTY_FUNCTION__");
extern const char D_0016F05C[];     /* "" */
extern const char D_0016F0F4[];     /* "num (graph) edges     " */
extern const char D_0016F110[];     /* "num (graph) triangles " */
extern const char D_0016F6D8[];
extern const char D_0016F714[];     /* "num < 9" */
extern const char D_0016F71C[];
extern const char searchCommonPosPair_name[] __asm__("_ZZN3sgl4Mesh19searchCommonPosPairEiiRiS1_E19__PRETTY_FUNCTION__");
#define FINISH_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016F0C0, text, D_0016F0D8, fn, line, D_0016F160)
#define VLL_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016F0C0, text, D_0016F2C0, fn, line, D_0016F160)

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _Z41__static_initialization_and_destruction_0ii_B6290);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh6finishERKNS_10MeshParamsE);

void sgl::Mesh::print(std::string name)
{
    if (name != D_0016F05C)
        common::Log() << name;
    CoreMesh::print(name);
    if (!getTriangles().empty())
        common::Log() << D_0016F110 << (unsigned int)getTriangles().size() << D_0016F10C;
    if (!getEdges().empty())
        common::Log() << D_0016F0F4 << (unsigned int)getEdges().size() << D_0016F10C;
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh15calcHardNormalsERSt6vectorINS_6NormalESaIS2_EE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh14setHardNormalsENS0_9LocalAttrE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23explodeTriangleVerticesEv);

math::vector_xyzw sgl::ProjectOnPlane(const math::vector_xyzw &p, const math::vector_xyzw &q, const math::vector_xyzw &n)
{
    return p + n * math::dot(q - p, n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh11calcNormalsEf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh16quantizeVerticesEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh20removeUsusedVerticesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh19removeFlatTrianglesEf);

extern const char VLL_incrSize_name[] __asm__("_ZZN3sgl15VarlenListsList8incrSizeEjjE19__PRETTY_FUNCTION___16F3FC");
inline void sgl::VarlenListsList::incrSize(unsigned int _List, unsigned int n)
{
    VLL_ASSERT(_List < _n, D_0016F33C, VLL_incrSize_name, 76);
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
    FINISH_ASSERT(ti >= 0 && ti < (int)_triangles.size(), D_0016F474, findTriangleEdge_name, 761);
    const Triangle &t = _triangles[ti];
    for (int i = 0; i != 3; i++) {
        int edge_index = t.edge(i);
        FINISH_ASSERT(edge_index >= 0 && edge_index < (int)_edges.size(), D_0016F49C, findTriangleEdge_name, 769);
        const Edge &e = _edges[edge_index];
        int a = getVertexAttributeIndex(e.vertex(0), POS);
        int b = getVertexAttributeIndex(e.vertex(1), POS);
        if ((a == p0 && b == p1) || (a == p1 && b == p0))
            return edge_index;
    }
    common::Log() << D_0016F4D0 << p0 << D_0016F4E4 << p1 << D_0016F4E8 << ti << D_0016F10C;
    return -1;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh17check_connectionsEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh25check_duplicate_pos_indexEv);

bool sgl::Mesh::searchCommonPosPair(int ti, int tj, int &a, int &b)
{
    int tip[3], tjp[3];
    getTriangleVertexAttributeIndex(ti, POS, tip[0], tip[1], tip[2]);
    getTriangleVertexAttributeIndex(tj, POS, tjp[0], tjp[1], tjp[2]);
    FINISH_ASSERT(tip[0] != tip[1] && tip[1] != tip[2] && tip[2] != tip[0], D_0016F71C, searchCommonPosPair_name, 936);
    FINISH_ASSERT(tjp[0] != tjp[1] && tjp[1] != tjp[2] && tjp[2] != tjp[0], D_0016F6D8, searchCommonPosPair_name, 937);
    int common[9];
    int num = 0;
    for (int i = 0; i != 3; i++)
        for (int j = 0; j != 3; j++)
            if (tip[i] == tjp[j]) {
                FINISH_ASSERT(num < 9, D_0016F714, searchCommonPosPair_name, 949);
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
extern const CmpEdgesMasks D_0016F758;  /* {1, 2, 4, 8} */
extern const CmpEdgesAttrs D_0016F768;  /* {POS, NOR, COL, TEX} */
bool sgl::Mesh::cmpEdges(int e1, int e2, unsigned int mask)
{
    CmpEdgesMasks masks = D_0016F758;
    CmpEdgesAttrs attrs = D_0016F768;
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh9calcEdgesEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh17removeUnusedEdgesEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh4dumpEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl9SubdivideERNS_11MeshBuilderEiPNS_8PositionEPNS_6NormalEbPNS_5ColorEbPNS_8TexCoordEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh24reverseTrianglesVerticesEv);

static inline sgl::Normal ToNormal(const math::vector_xyzw &v)
{
    return sgl::Normal(v.x, v.y, v.z);
}
void sgl::Mesh::reverseVerticesNormals()
{
    for (std::vector<Normal>::iterator it = _normals.begin(); it != _normals.end(); ++it)
        *it = ToNormal(-*it);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh14calcPrimitivesERKNS_10MeshParamsE);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_B6290");
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

/* lib/sgl/KdTree.h; its strings and float constants stay in the module's .rodata */
extern const char KD_err[] __asm__("D_0016F0C0");          /* " *** error " */
extern const char KD_warn[] __asm__("D_001701F0");         /* " *** warning " */
extern const char KD_sep[] __asm__("D_0016F160");          /* " " */
extern const char KD_file[] __asm__("D_0016FF94");         /* "../lib/sgl/KdTree.h" */
extern const char KD_dim[] __asm__("D_0016FFD0");          /* "_dim == 2 || _dim == 3 || _dim == 4" */
extern const char KD_dim_msg[] __asm__("D_0016FFA8");      /* "supported values for k are 2, 3 or 4" */
extern const char KD_partitioned[] __asm__("D_0016FF60");  /* "_partitioned_items[i] == _partitioned_items[retval]" */
extern const char KD_depth[] __asm__("D_00170200");        /* "_Depth != 80" */
extern const char KD_depth_msg[] __asm__("D_00170210");    /* "stack overflow might occur, might beed bigger threshold" */
extern const char KD_axis_range[] __asm__("D_00170178");   /* "_Node->_longest_axis >= 0 && _Node->_longest_axis < _dim" */
extern const char KD_rl[] __asm__("D_001701B4");           /* "r == 1 || l == 1" */
extern const char KD_no_children[] __asm__("D_001701C8");  /* "_Node->_left == 0 && _Node->_right == 0" */
extern const char KD_node[] __asm__("D_00170298");         /* "node != 0" */
extern const char KD_node_size[] __asm__("D_001702A4");    /* "node->_size != 0" */
extern const char KD_Node[] __asm__("D_0017064C");         /* "_Node != 0" */
extern const char KD_children[] __asm__("D_00170608");     /* "_Node->_left != 0 && _Node->_right != 0" */
extern const char KD_axis[] __asm__("D_00170630");         /* "_Node->_longest_axis != -1" */
extern const char KD_size[] __asm__("D_001704F4");         /* "_Node->_size != 0" */
extern const char KD_equal[] __asm__("D_0017055C");        /* "node_element(_Node,i).equal( node_element(_Node,0), _threshold * 100.f )" */
namespace sgl {
template<class T> struct KdTreeNames {
    static const char ctor[], build[], find[], find_rec[], compute_longest_box[], merge_node_elements[];
    static const float hundred;
};
}
#define KDTREE_NAMES(T, M, HUNDRED, FIND, FIND_REC) \
    template<> const char sgl::KdTreeNames<sgl::T>::ctor[] __asm__("_ZZN3sgl6KdTreeI" M "EC1ERSt6vectorIS1_SaIS1_EEifE19__PRETTY_FUNCTION__"); \
    template<> const char sgl::KdTreeNames<sgl::T>::build[] __asm__("_ZZN3sgl6KdTreeI" M "E5buildEPNS_10KdTreeNodeEjE19__PRETTY_FUNCTION__"); \
    template<> const char sgl::KdTreeNames<sgl::T>::find[] __asm__("_ZZN3sgl6KdTreeI" M "E4findERKS1_RiE19__PRETTY_FUNCTION__" FIND); \
    template<> const char sgl::KdTreeNames<sgl::T>::find_rec[] __asm__("_ZZN3sgl6KdTreeI" M "E8find_recEPNS_10KdTreeNodeERKS1_E19__PRETTY_FUNCTION__" FIND_REC); \
    template<> const char sgl::KdTreeNames<sgl::T>::compute_longest_box[] __asm__("_ZZN3sgl6KdTreeI" M "E19compute_longest_boxEPNS_10KdTreeNodeEE19__PRETTY_FUNCTION__"); \
    template<> const char sgl::KdTreeNames<sgl::T>::merge_node_elements[] __asm__("_ZZN3sgl6KdTreeI" M "E19merge_node_elementsEPNS_10KdTreeNodeEE19__PRETTY_FUNCTION__"); \
    template<> const float sgl::KdTreeNames<sgl::T>::hundred __asm__(HUNDRED)
/* (KdTree<Position>::find(const Position &, int &) and find_rec are scene_MeshData's instances: this
   object's copies of their names are the suffixed labels) */
KDTREE_NAMES(Position, "NS_8PositionE", "D_0016F014", "_170248", "_1705A8");
KDTREE_NAMES(TexCoord, "NS_8TexCoordE", "D_0016F018", "", "");
KDTREE_NAMES(Color, "NS_5ColorE", "D_0016F01C", "", "");
KDTREE_NAMES(Normal, "NS_6NormalE", "D_0016F020", "", "");
#define KD_ASSERT(c, text, fn, line) SGL_ASSERT(c, KD_err, text, KD_file, KdTreeNames<T>::fn, line, KD_sep)
#define KD_ASSERT_MSG(c, text, msg, fn, line) SGL_ASSERT(c, KD_err, text, KD_file, KdTreeNames<T>::fn, line, msg)
#define KD_WARN(c, text, msg, fn, line) \
    if (!(c)) { \
        common::common_internal::assert_display(KD_warn, text, KD_file, KdTreeNames<T>::fn, line, msg); \
        common::common_internal::on_warning(); \
    }
namespace sgl {
/* T's coordinates and T::equal (Color has no operator[]) */
template<class T> inline float &kd_coord(T &v, int i) { return ((float *)&v)[i]; }
template<class T> inline float kd_coord_value(T v, int i) { return kd_coord(v, i); }
inline bool kd_equal(const math::vector_xyzw &a, const math::vector_xyzw &b, float eps)
{
    return fabsf(a.x - b.x) < eps && fabsf(a.y - b.y) < eps && fabsf(a.z - b.z) < eps && fabsf(a.w - b.w) < eps;
}
inline bool kd_equal(const TexCoord &a, const TexCoord &b, float eps)
{
    return fabsf(a.x - b.x) < eps && fabsf(a.y - b.y) < eps;
}
inline bool kd_equal(const Color &a, const Color &b, float eps)
{
    return fabsf(a.c[0] - b.c[0]) < eps && fabsf(a.c[1] - b.c[1]) < eps && fabsf(a.c[2] - b.c[2]) < eps &&
           fabsf(a.c[3] - b.c[3]) < eps;
}
inline bool kd_same(const math::vector_xyzw &a, const math::vector_xyzw &b)
{
    return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}
inline bool kd_same(const TexCoord &a, const TexCoord &b)
{
    return a.x == b.x && a.y == b.y;
}
inline bool kd_same(const Color &a, const Color &b)
{
    return a.c[0] == b.c[0] && a.c[1] == b.c[1] && a.c[2] == b.c[2] && a.c[3] == b.c[3];
}

template<class T> KdTree<T>::KdTree(std::vector<T> &items, int dim, float threshold)
    : _dim(dim), _threshold(threshold), _max_depth(0), _num_nodes(1), _num_leaves(0), _items(items)
{
    KD_ASSERT_MSG(_dim == 2 || _dim == 3 || _dim == 4, KD_dim, KD_dim_msg, ctor, 110);
    if (items.empty())
        return;
    _partitioned_items.resize(items.size());
    for (unsigned int i = 0; i < items.size(); i++)
        _partitioned_items[i] = i;
    _root._size = items.size();
    _root._start = 0;
    build(&_root, 0);
    _num_leaves = _num_nodes - _num_leaves;
    for (unsigned int i = 0; i < items.size(); i++) {
        int retval = find(items[i]);
        KD_ASSERT(kd_same(_items[i], _items[retval]), KD_partitioned, ctor, 164);
    }
}

template<class T> int KdTree<T>::find(const T &p)
{
    int retval;
    find(p, retval);
    return retval;
}

template<class T> void KdTree<T>::build(KdTreeNode *_Node, unsigned int _Depth)
{
    KD_WARN(_Depth != 80, KD_depth, KD_depth_msg, build, 229);
    if (!compute_longest_box(_Node))
        return;
    KD_ASSERT(_Node->_longest_axis >= 0 && _Node->_longest_axis < _dim, KD_axis_range, build, 240);
    if (_max_depth < _Depth)
        _max_depth = _Depth;
    int l = 0;
    int r = _Node->_size - 1;
    for (;;) {
        while (kd_coord(node_element(_Node, l), _Node->_longest_axis) <= _Node->_split)
            if (++l >= (int)_Node->_size)
                break;
        while (kd_coord(node_element(_Node, r), _Node->_longest_axis) > _Node->_split)
            if (--r < 0)
                break;
        if (!(l < r))
            break;
        unsigned int t = _partitioned_items[_Node->_start + l];
        _partitioned_items[_Node->_start + l] = _partitioned_items[_Node->_start + r];
        _partitioned_items[_Node->_start + r] = t;
    }
    if (r >= 0 && l < (int)_Node->_size) {
        r = _Node->_size - l;
        if (r == 0 || l == 0) {
            KD_ASSERT(r == 1 || l == 1, KD_rl, build, 334);
        } else {
            _num_nodes += 2;
            _num_leaves++;
            _Node->_leaf = false;
            KD_ASSERT(_Node->_left == 0 && _Node->_right == 0, KD_no_children, build, 344);
            _Node->_left = new KdTreeNode;
            _Node->_right = new KdTreeNode;
            _Node->_left->_start = _Node->_start;
            _Node->_left->_size = l;
            _Node->_right->_start = _Node->_start + l;
            _Node->_right->_size = r;
            build(_Node->_right, _Depth + 1);
            build(_Node->_left, _Depth + 1);
        }
    } else
        merge_node_elements(_Node);
}

template<class T> KdTreeNode *KdTree<T>::find(const T &p, int &retval)
{
    KdTreeNode *node = find_rec(&_root, p);
    KD_ASSERT(node != 0, KD_node, find, 532);
    KD_ASSERT(node->_size != 0, KD_node_size, find, 533);
    retval = _partitioned_items[node->_start];
    return node;
}

template<class T> bool KdTree<T>::compute_longest_box(KdTreeNode *_Node)
{
    KD_ASSERT(_Node->_size != 0, KD_size, compute_longest_box, 367);
    _Node->_longest_axis = -1;
    if (_Node->_size == 1)
        return false;
    float min[_dim], max[_dim], len[_dim];
    for (int i = 0; i < _dim; i++)
        max[i] = min[i] = kd_coord(node_element(_Node, 0), i);
    for (unsigned int j = 1; j < _Node->_size; j++)
        for (int i = 0; i < _dim; i++) {
            float v = kd_coord(node_element(_Node, j), i);
            if (v < min[i])
                min[i] = v;
            if (max[i] < v)
                max[i] = v;
        }
    for (int i = 0; i < _dim; i++)
        len[i] = fabsf(max[i] - min[i]);
    bool zero = true;
    for (int i = 0; i < _dim; i++)
        if (len[i] != 0) {
            zero = false;
            break;
        }
    if (zero)
        return false;
    bool small = true;
    for (int i = 0; i < _dim; i++)
        if (_threshold < len[i]) {
            small = false;
            break;
        }
    if (small) {
        merge_node_elements(_Node);
        return false;
    }
    _Node->_longest_axis = 0;
    for (int i = 1; i < _dim; i++)
        if (len[i] > len[_Node->_longest_axis])
            _Node->_longest_axis = i;
    _Node->_split = 0;
    int axis = _Node->_longest_axis;
    for (unsigned int j = 0; j < _Node->_size; j++)
        _Node->_split += kd_coord(node_element(_Node, j), axis);
    _Node->_split /= _Node->_size;
    return true;
}

template<class T> T &KdTree<T>::node_element(KdTreeNode *_Node, unsigned int i)
{
    return _items[_partitioned_items[_Node->_start + i]];
}

template<class T> void KdTree<T>::merge_node_elements(KdTreeNode *_Node)
{
    for (unsigned int i = 1; i < _Node->_size; i++) {
        KD_WARN(kd_equal(node_element(_Node, i), node_element(_Node, 0), _threshold * KdTreeNames<T>::hundred), KD_equal,
                KD_sep, merge_node_elements, 219);
        node_element(_Node, i) = node_element(_Node, 0);
    }
}

template<class T> KdTreeNode *KdTree<T>::find_rec(KdTreeNode *_Node, const T &p)
{
    KD_ASSERT(_Node != 0, KD_Node, find_rec, 491);
    if (_Node->_leaf)
        return _Node;
    KD_ASSERT(_Node->_left != 0 && _Node->_right != 0, KD_children, find_rec, 495);
    KD_ASSERT(_Node->_longest_axis != -1, KD_axis, find_rec, 497);
    if (kd_coord_value(p, _Node->_longest_axis) <= _Node->_split)
        return find_rec(_Node->_left, p);
    return find_rec(_Node->_right, p);
}
}

/* KdTree<T>::KdTree / build: near-misses (some stores are scheduled in another order), asm */
extern template void sgl::KdTree<sgl::Position>::build(sgl::KdTreeNode *, unsigned int);
extern template void sgl::KdTree<sgl::TexCoord>::build(sgl::KdTreeNode *, unsigned int);
extern template void sgl::KdTree<sgl::Color>::build(sgl::KdTreeNode *, unsigned int);
extern template void sgl::KdTree<sgl::Normal>::build(sgl::KdTreeNode *, unsigned int);
extern template sgl::KdTree<sgl::Position>::KdTree(std::vector<sgl::Position> &, int, float);
extern template sgl::KdTree<sgl::TexCoord>::KdTree(std::vector<sgl::TexCoord> &, int, float);
extern template sgl::KdTree<sgl::Color>::KdTree(std::vector<sgl::Color> &, int, float);
extern template sgl::KdTree<sgl::Normal>::KdTree(std::vector<sgl::Normal> &, int, float);

/* this object's instances (not linked: they are emitted by the uses here) */
void sgl_Mesh_4_instances(void *p) __attribute__((section(".discard.instances")));
void sgl_Mesh_4_instances(void *p)
{
    ((sgl::KdTree<sgl::Position> *)p)->find(*(const sgl::Position *)p);
    ((sgl::KdTree<sgl::Position> *)p)->compute_longest_box((sgl::KdTreeNode *)p);
    ((sgl::KdTree<sgl::Position> *)p)->merge_node_elements((sgl::KdTreeNode *)p);
    ((sgl::KdTree<sgl::TexCoord> *)p)->find(*(const sgl::TexCoord *)p);
    ((sgl::KdTree<sgl::TexCoord> *)p)->compute_longest_box((sgl::KdTreeNode *)p);
    ((sgl::KdTree<sgl::TexCoord> *)p)->merge_node_elements((sgl::KdTreeNode *)p);
    ((sgl::KdTree<sgl::Color> *)p)->find(*(const sgl::Color *)p);
    ((sgl::KdTree<sgl::Color> *)p)->compute_longest_box((sgl::KdTreeNode *)p);
    ((sgl::KdTree<sgl::Color> *)p)->merge_node_elements((sgl::KdTreeNode *)p);
    ((sgl::KdTree<sgl::Normal> *)p)->find(*(const sgl::Normal *)p);
    ((sgl::KdTree<sgl::Normal> *)p)->compute_longest_box((sgl::KdTreeNode *)p);
    ((sgl::KdTree<sgl::Normal> *)p)->merge_node_elements((sgl::KdTreeNode *)p);
}

/* the template instances / out-of-line inline members that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl14PrimitiveIndexIiEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_8PositionESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_6NormalESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_5ColorESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh22removeUsusedAttributesISt6vectorINS_8TexCoordESaIS3_EES3_EEvNS_14VertexAttrEnumERT_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_8PositionESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_8TexCoordESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_5ColorESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl4Mesh23quantizeVertexAttributeISt6vectorINS_6NormalESaIS3_EES3_EEvNS_14VertexAttrEnumERT_jbf);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl4EdgeESaIS1_EE7reserveEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl15VarlenListsList4ListESaIS2_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS2_S4_EES8_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEEC1ERSt6vectorIS1_SaIS1_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl4EdgeESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIiSaIiEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPiS1_EERKi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8PositionEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_8TexCoordEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_5ColorEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZN3sgl6KdTreeINS_6NormalEE5buildEPNS_10KdTreeNodeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE8_M_eraseEPSt13_Rb_tree_nodeIS4_E);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE11lower_boundERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE13insert_uniqueESt17_Rb_tree_iteratorIS4_RS4_PS4_ERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl15VarlenListsList4ListESaIS2_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS2_S4_EEjRKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE9_M_insertEPSt18_Rb_tree_node_baseSC_RKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt8_Rb_treeIN3sgl6VertexESt4pairIKS1_jESt10_Select1stIS4_ESt4lessIS1_ESaIS4_EE13insert_uniqueERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl8TriangleESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZNSt6vectorIN3sgl4EdgeESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIPN3sgl4EdgeES2_ET0_T_S4_S3_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES4_EvT_SA_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIPN3sgl15VarlenListsList4ListES3_ET0_T_S5_S4_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIPN3sgl15VarlenListsList4ListEjS2_ET_S4_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES5_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEES9_ET0_T_SB_SA_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl15VarlenListsList4ListESt6vectorIS4_SaIS4_EEEEjS4_ET_SA_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIPN3sgl8TriangleEjS1_ET_S3_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TriangleESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIPN3sgl4EdgeEjS1_ET_S3_T0_RKT1_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_Mesh_4", _ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl4EdgeESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type);
