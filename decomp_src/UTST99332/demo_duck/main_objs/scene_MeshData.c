/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene8MeshDataC2Ev\n_GLOBAL__I__ZN5scene8MeshDataC2Ev = _GLOBAL__I__ZN5scene8MeshDataC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN5scene8MeshDataC2Ev\n_GLOBAL__D__ZN5scene8MeshDataC2Ev = _GLOBAL__D__ZN5scene8MeshDataC2Ev__asm");
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZN4math4max_IfEET_S1_S1_)
    SCENE_LINKONCE(_ZN4math4min_IfEET_S1_S1_)
    SCENE_LINKONCE(_ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl8TexCoordESaIS4_EEEEbNS3_14VertexAttrEnumERT_)
    SCENE_LINKONCE(_ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl8PositionESaIS4_EEEEbNS3_14VertexAttrEnumERT_)
    SCENE_LINKONCE(_ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl5ColorESaIS4_EEEEbNS3_14VertexAttrEnumERT_)
    SCENE_LINKONCE(_ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl6NormalESaIS4_EEEEbNS3_14VertexAttrEnumERT_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl8TexCoordESaIS1_EEaSERKS3_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl8PositionESaIS1_EEaSERKS3_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl6NormalESaIS1_EEaSERKS3_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl5ColorESaIS1_EEaSERKS3_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl6VertexESaIS1_EEaSERKS3_)
    SCENE_LINKONCE(_ZNSt6vectorIiSaIiEEaSERKS1_)
    SCENE_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE4findERKS1_Ri)
    SCENE_LINKONCE(_ZNK3sgl6KdTreeINS_8PositionEE11getNodeSizeEPNS_10KdTreeNodeE)
    SCENE_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE14getNodeElementEPNS_10KdTreeNodeEj)
    SCENE_LINKONCE(_ZNSt6vectorIN2sh9VectorRGBESaIS1_EEaSERKS3_)
    SCENE_LINKONCE(_ZN3sgl6KdTreeINS_8PositionEE8find_recEPNS_10KdTreeNodeERKS1_)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl8TexCoordESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl8PositionESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl6NormalESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl5ColorESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl6VertexESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN2sh9VectorRGBESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
    SCENE_LINKONCE(_ZNK2sh6Vector5equalERKS0_f)
);

scene::MeshData::MeshData() : _fB5(false), _fB6(false), _fB7(false)
{
}

scene::MeshData::~MeshData()
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData6finishEv);

void scene::MeshData::copy(const sgl::Mesh &m)
{
    _positions = m._positions;
    _normals = m._normals;
    _colors = m._colors;
    _texcoords = m._texcoords;
    _vertices = m._vertices;
    _prims = m._prims;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData14recoverShldataERKN2sh14VerticesVectorERN3sgl6KdTreeINS5_8PositionEEE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData28calc_vertex_refmap_texcoordsERKNS_17TraversalVarStackE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData22calc_vertex_shl_colorsERKN2sh9VectorRGBE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData4drawERKNS_17TraversalVarStackE);

extern const char MD_err[] __asm__("D_0016BDDC");
extern const char MD_sp[] __asm__("D_0016BE34");
extern const char MD_file[] __asm__("D_0016BE18");           /* "../lib/scene/MeshData.cpp" */
extern const char MD_ctc_expr[] __asm__("D_0016C1E8");
extern const char MD_ctc_name[] __asm__("_ZZN5scene8MeshData13copy_texcoordERKSt6vectorIN3sgl8TexCoordESaIS3_EEE19__PRETTY_FUNCTION__");
void scene::MeshData::copy_texcoord(const std::vector<sgl::TexCoord> &t)
{
    std::vector<sgl::TexCoord>::const_iterator s = t.begin();
    SGL_ASSERT(getTexCoords().size() == t.size(), MD_err, MD_ctc_expr, MD_file, MD_ctc_name, 514, MD_sp);
    std::vector<sgl::TexCoord>::iterator d = getTexCoords().begin();
    for (; s != t.end(); ++s, ++d)
        *d = *s;
}

void scene::MeshData::clear()
{
    *this = MeshData();
}

/* instances used by the (asm) methods above */
namespace math {
template<class T> T max_(T a, T b)
{
    return a < b ? b : a;
}
template<class T> T min_(T a, T b)
{
    return a < b ? a : b;
}
template float max_<float>(float, float);
template float min_<float>(float, float);
}
namespace std {
template vector<sgl::TexCoord> &vector<sgl::TexCoord>::operator=(const vector<sgl::TexCoord> &);
template vector<sgl::Position> &vector<sgl::Position>::operator=(const vector<sgl::Position> &);
template vector<sgl::Normal> &vector<sgl::Normal>::operator=(const vector<sgl::Normal> &);
template vector<sgl::Color> &vector<sgl::Color>::operator=(const vector<sgl::Color> &);
template vector<sgl::Vertex> &vector<sgl::Vertex>::operator=(const vector<sgl::Vertex> &);
template vector<int> &vector<int>::operator=(const vector<int> &);
template vector<sh::VectorRGB> &vector<sh::VectorRGB>::operator=(const vector<sh::VectorRGB> &);
}

/* KdTree<Position> members held by this object (lib/sgl/KdTree.h; this object's copies of the strings) */
extern const char MD_KD_err[] __asm__("D_0016BDDC");         /* " *** error " */
extern const char MD_KD_sep[] __asm__("D_0016BE34");         /* " " */
extern const char MD_KD_file[] __asm__("D_0016C270");        /* "../lib/sgl/KdTree.h" */
extern const char MD_KD_i[] __asm__("D_0016C300");           /* "i >=0 && i < _Node->_size" */
extern const char MD_KD_begin[] __asm__("D_0016C31C");       /* "_Node->_begin + i < _reindex.size()" */
extern const char MD_KD_node[] __asm__("D_0016C264");        /* "node != 0" */
extern const char MD_KD_node_size[] __asm__("D_0016C284");   /* "node->_size != 0" */
extern const char MD_KD_children[] __asm__("D_0016C3A0");    /* "_Node->_left != 0 && _Node->_right != 0" */
extern const char MD_KD_axis[] __asm__("D_0016C3C8");        /* "_Node->_longest_axis != -1" */
extern const char MD_KD_Node[] __asm__("D_0016C3E4");        /* "_Node != 0" */
extern const char MD_KD_find_name[] __asm__("_ZZN3sgl6KdTreeINS_8PositionEE4findERKS1_RiE19__PRETTY_FUNCTION___16C214");
extern const char MD_KD_find_rec_name[] __asm__("_ZZN3sgl6KdTreeINS_8PositionEE8find_recEPNS_10KdTreeNodeERKS1_E19__PRETTY_FUNCTION___16C340");
extern const char MD_KD_getNodeElement_name[] __asm__("_ZZN3sgl6KdTreeINS_8PositionEE14getNodeElementEPNS_10KdTreeNodeEjE19__PRETTY_FUNCTION__");
#define MD_KD_ASSERT(c, text, fn, line) SGL_ASSERT(c, MD_KD_err, text, MD_KD_file, fn, line, MD_KD_sep)
namespace sgl {
/* T's coordinate i (T by value, as in KdTree.h) */
template<class T> inline float &kd_coord(T &v, int i) { return ((float *)&v)[i]; }
template<class T> inline float kd_coord_value(T v, int i) { return kd_coord(v, i); }

template<class T> KdTreeNode *KdTree<T>::find(const T &p, int &retval)
{
    KdTreeNode *node = find_rec(&_root, p);
    MD_KD_ASSERT(node != 0, MD_KD_node, MD_KD_find_name, 532);
    MD_KD_ASSERT(node->_size != 0, MD_KD_node_size, MD_KD_find_name, 533);
    retval = _partitioned_items[node->_start];
    return node;
}

template<class T> unsigned int KdTree<T>::getNodeSize(KdTreeNode *_Node) const
{
    return _Node->_size;
}

template<class T> unsigned int KdTree<T>::getNodeElement(KdTreeNode *_Node, unsigned int i)
{
    MD_KD_ASSERT(i >= 0 && i < _Node->_size, MD_KD_i, MD_KD_getNodeElement_name, 181);
    MD_KD_ASSERT(_Node->_start + i < _partitioned_items.size(), MD_KD_begin, MD_KD_getNodeElement_name, 182);
    return _partitioned_items[_Node->_start + i];
}

template<class T> KdTreeNode *KdTree<T>::find_rec(KdTreeNode *_Node, const T &p)
{
    MD_KD_ASSERT(_Node != 0, MD_KD_Node, MD_KD_find_rec_name, 491);
    if (_Node->_leaf)
        return _Node;
    MD_KD_ASSERT(_Node->_left != 0 && _Node->_right != 0, MD_KD_children, MD_KD_find_rec_name, 495);
    MD_KD_ASSERT(_Node->_longest_axis != -1, MD_KD_axis, MD_KD_find_rec_name, 497);
    if (kd_coord_value(p, _Node->_longest_axis) <= _Node->_split)
        return find_rec(_Node->_left, p);
    return find_rec(_Node->_right, p);
}

template KdTreeNode *KdTree<Position>::find(const Position &, int &);
template unsigned int KdTree<Position>::getNodeSize(KdTreeNode *) const;
template unsigned int KdTree<Position>::getNodeElement(KdTreeNode *, unsigned int);
template KdTreeNode *KdTree<Position>::find_rec(KdTreeNode *, const Position &);
}

/* from here on INCLUDE_ASM puts the asm in its own .gnu.linkonce.t section (written as
   INCLUDE_ASM so that splat keeps these functions as asm) */
#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl8TexCoordESaIS4_EEEEbNS3_14VertexAttrEnumERT_);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl8PositionESaIS4_EEEEbNS3_14VertexAttrEnumERT_);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl5ColorESaIS4_EEEEbNS3_14VertexAttrEnumERT_);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZN5scene8MeshData26unfold_vertices_attributesISt6vectorIN3sgl6NormalESaIS4_EEEEbNS3_14VertexAttrEnumERT_);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_MeshData", _ZNK2sh6Vector5equalERKS0_f);
