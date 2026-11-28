/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define SGL_LINKONCE_KdTreeNode 1
#include "../main.hpp"

extern const char D_0016A764[];     /* " " */
extern const char D_0016A768[];     /* " *** error " */
extern const char D_0016A774[];
extern const char D_0016A7B8[];     /* file */
extern const char longestAxis_name[] __asm__("_ZZNK3sgl2BV11longestAxisEvE19__PRETTY_FUNCTION__");


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _Z41__static_initialization_and_destruction_0ii_9F58C);

sgl::BV::BV()
{
    _type = 0;
    _m84 = math::matrix::Identity();
    _started = true;
}

void sgl::BV::setType(sgl::BV::Type v)
{
    _type = v;
}

void sgl::BV::start()
{
    Box::first(math::vector_xyzw(0, 0, 0, 1));
    Box::add(math::vector_xyzw(0, 0, 0, 1));
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BV3addERKS0_RKN4math6matrixE);

void sgl::BV::add(float x, float y, float z)
{
    add(math::vector_xyzw(x, y, z, 1));
}

void sgl::BV::add(const BV &o)
{
    for (int i = 0; i != 8; i++)
        add(o._c[i]);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BV6finishEv);

void sgl::BV::draw() const
{
    Box::draw();
}

void sgl::BV::draw(int n) const
{
    Box::draw(n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _ZN3sgl2BV8calc_obbEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _ZNK3sgl2BV9intersectERfRKN4math11vector_xyzwES5_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _ZNK3sgl2BV11longestAxisEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_9F58C");
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

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEEC1ERSt6vectorIS2_SaIS2_EEif)
                    DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEE4findERKS2_)
                    DEMO_LINKONCE(_ZN4math3sqrIfEET_S1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN4math11vector_xyzwESaIS1_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS1_S3_EERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN4math11vector_xyzwESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
                    DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEE5buildEPNS_10KdTreeNodeEj)
                    DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEE4findERKS2_Ri)
                    DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEE19compute_longest_boxEPNS_10KdTreeNodeE)
                    DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEE12node_elementEPNS_10KdTreeNodeEj)
                    DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEE19merge_node_elementsEPNS_10KdTreeNodeE)
                    DEMO_LINKONCE(_ZN3sgl6KdTreeIN4math11vector_xyzwEE8find_recEPNS_10KdTreeNodeERKS2_)
                    DEMO_LINKONCE(_ZNSt6vectorIN4math11vector_xyzwESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIPN4math11vector_xyzwES2_ET0_T_S4_S3_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN4math11vector_xyzwEjS1_ET_S3_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
                    DEMO_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
                    DEMO_LINKONCE(_ZN3sgl10KdTreeNodeD1Ev));

/* lib/sgl/KdTree.h (this object's copies of its strings) */
extern const char KD_err[] __asm__("D_0016A768");          /* " *** error " */
extern const char KD_warn[] __asm__("D_0016A99C");         /* " *** warning " */
extern const char KD_sep[] __asm__("D_0016A764");          /* " " */
extern const char KD_file[] __asm__("D_0016A86C");         /* "../lib/sgl/KdTree.h" */
extern const char KD_node[] __asm__("D_0016AA48");         /* "node != 0" */
extern const char KD_node_size[] __asm__("D_0016AA54");    /* "node->_size != 0" */
extern const char KD_size[] __asm__("D_0016AAC0");         /* "_Node->_size != 0" */
extern const char KD_equal[] __asm__("D_0016AB2C");        /* "node_element(_Node,i).equal( node_element(_Node,0), _threshold * 100.f )" */
extern const char KD_children[] __asm__("D_0016ABDC");     /* "_Node->_left != 0 && _Node->_right != 0" */
extern const char KD_axis[] __asm__("D_0016AC04");         /* "_Node->_longest_axis != -1" */
extern const char KD_Node[] __asm__("D_0016AC20");         /* "_Node != 0" */
namespace sgl {
template<class T> struct KdTreeNames {
    static const char find[], find_rec[], compute_longest_box[], merge_node_elements[];
    static const float hundred;
};
template<> const char KdTreeNames<math::vector_xyzw>::find[] __asm__("_ZZN3sgl6KdTreeIN4math11vector_xyzwEE4findERKS2_RiE19__PRETTY_FUNCTION__");
template<> const char KdTreeNames<math::vector_xyzw>::find_rec[] __asm__("_ZZN3sgl6KdTreeIN4math11vector_xyzwEE8find_recEPNS_10KdTreeNodeERKS2_E19__PRETTY_FUNCTION__");
template<> const char KdTreeNames<math::vector_xyzw>::compute_longest_box[] __asm__("_ZZN3sgl6KdTreeIN4math11vector_xyzwEE19compute_longest_boxEPNS_10KdTreeNodeEE19__PRETTY_FUNCTION__");
template<> const char KdTreeNames<math::vector_xyzw>::merge_node_elements[] __asm__("_ZZN3sgl6KdTreeIN4math11vector_xyzwEE19merge_node_elementsEPNS_10KdTreeNodeEE19__PRETTY_FUNCTION__");
template<> const float KdTreeNames<math::vector_xyzw>::hundred __asm__("D_0016A734");
}
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
template<class T> int KdTree<T>::find(const T &p)
{
    int retval;
    find(p, retval);
    return retval;
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

/* KdTree<vector_xyzw>::KdTree / build stay asm (sgl_Mesh_4's instances of them are near-misses) */
extern template void sgl::KdTree<math::vector_xyzw>::build(sgl::KdTreeNode *, unsigned int);
extern template sgl::KdTree<math::vector_xyzw>::KdTree(std::vector<math::vector_xyzw> &, int, float);

/* this object's KdTree instances (not linked: they are emitted by the uses here) */
void sgl_BV_instances(void *p) __attribute__((section(".discard.instances")));
void sgl_BV_instances(void *p)
{
    ((sgl::KdTree<math::vector_xyzw> *)p)->find(*(const math::vector_xyzw *)p);
    ((sgl::KdTree<math::vector_xyzw> *)p)->compute_longest_box((sgl::KdTreeNode *)p);
    ((sgl::KdTree<math::vector_xyzw> *)p)->merge_node_elements((sgl::KdTreeNode *)p);
}

/* the object's math::sqr<float> instance (KdTree<vector_xyzw>::build, still asm, uses it) */
namespace math {
template<class T> T sqr(T x)
{
    return x * x;
}
}
template float math::sqr<float>(float);

/* the instances / inline members that stay asm (.gnu.linkonce.t) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEEC1ERSt6vectorIS2_SaIS2_EEif);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_BV", _ZN3sgl6KdTreeIN4math11vector_xyzwEE5buildEPNS_10KdTreeNodeEj);


