/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
/* stl_tree.h before main.hpp (outside its #pragma interface): its out-of-line inline functions are this object's */
#include <bits/stl_tree.h>
extern const char scene_bvdata_warn[] __asm__("D_00169204");         /* " *** warning " */
extern const char scene_bvdata_notvalid[] __asm__("D_001691BC");     /* "! valid()" */
extern const char scene_bvdata_file[] __asm__("D_001691CC");         /* "../lib/scene/BVdata.h" */
extern const char scene_bvdata_created[] __asm__("D_001691E4");      /* "bounding box already created" */
extern const char scene_bvdata_err[] __asm__("D_00169304");          /* " *** error " */
extern const char scene_bvdata_valid[] __asm__("D_001697C0");        /* "valid()" */
extern const char scene_bvdata_sp[] __asm__("D_001694B8");           /* " " */
extern const char scene_bvdata_get_name[] __asm__("_ZZN5scene6BVdata3getEvE19__PRETTY_FUNCTION___1697A0");
extern const char scene_mesh_err[] __asm__("D_00169304");
extern const char scene_mesh_expr[] __asm__("D_0016949C");
extern const char scene_mesh_file[] __asm__("D_001694A4");
extern const char scene_mesh_sp[] __asm__("D_001694B8");
extern const char scene_mesh_getData_name[] __asm__("_ZZN5scene4Mesh7getDataEvE19__PRETTY_FUNCTION___169474");
extern const char scene_bvdata_create_name[] __asm__("_ZZN5scene6BVdata6createEN3sgl2BV4TypeEE19__PRETTY_FUNCTION___169188");
#define DEMO_TEMPLATE_DEFS
#define SCENE_GRAPH_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN5scene5Graph26disable_reflection_mappingE\n_GLOBAL__I__ZN5scene5Graph26disable_reflection_mappingE = _GLOBAL__I__ZN5scene5GraphC2Ev__asm");
__asm__(".globl _GLOBAL__D__ZN5scene5Graph26disable_reflection_mappingE\n_GLOBAL__D__ZN5scene5Graph26disable_reflection_mappingE = _GLOBAL__D__ZN5scene5GraphC2Ev__asm");
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZN6common6handleIN5scene5SetupEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5ShapeEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4MeshEE10invalidateEv)
    SCENE_LINKONCE(_ZN5scene5Group4findINS_4NodeEEEvRN6common14handles_vectorIS2_EEb)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_5GroupEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_6ObjectEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEaSINS1_6ObjectEEERS3_RKNS0_IT_EE)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_4MeshEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE14countTrianglesEv)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_7TextureEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN5scene5Graph10getSublistINS_9TransformEEEvRN6common12handles_listIT_EE)
    SCENE_LINKONCE(_ZN5scene5Graph10getSublistINS_15StaticTransformEEEvRN6common12handles_listIT_EE)
    SCENE_LINKONCE(_ZN5scene5Graph10getSublistINS_5GroupEEEvRN6common12handles_listIT_EE)
    SCENE_LINKONCE(_ZN5scene5Graph10getSublistINS_5ShapeEEEvRN6common12handles_listIT_EE)
    SCENE_LINKONCE(_ZN5scene5Graph10getSublistINS_8MaterialEEEvRN6common12handles_listIT_EE)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_13DefaultShaderEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN6common6handleIKN5scene4NodeEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEaSERKS3_)
    SCENE_LINKONCE(_ZNSt5dequeIN4math6matrixESaIS1_EEaSERKS3_)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEEaSERKS1_)
    SCENE_LINKONCE(_ZN6common6handleIN5scene9TransformEE10invalidateEv)
    SCENE_LINKONCE(_ZN6common6handleIN5scene15StaticTransformEE10invalidateEv)
    SCENE_LINKONCE(_ZNSt11_Deque_baseISsSaISsEED2Ev)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE5eraseESt17_Rb_tree_iteratorIS7_RS7_PS7_ESG_)
    SCENE_LINKONCE(_ZNSt6vectorIN6common6handleIN5scene4NodeEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_6ObjectEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_4MeshEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZNK3sgl14PrimitiveIndexIiE22countTrianglesInStripsEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene4NodeEEESaIS4_EE6insertESt14_List_iteratorIS4_RS4_PS4_ERKS4_)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_13DefaultShaderEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZNSt5dequeIN4math6matrixESaIS1_EE5eraseESt15_Deque_iteratorIS1_RS1_PS1_ES7_)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EEaSERKSD_)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EEaSERKSC_)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE5eraseESt15_Deque_iteratorISsRSsPSsES5_)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE8_M_eraseEPSt13_Rb_tree_nodeIS7_E)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE8_M_eraseEPSt13_Rb_tree_nodeIS7_E)
    SCENE_LINKONCE(_ZNSt11_Deque_baseISsSaISsEE17_M_initialize_mapEj)
    SCENE_LINKONCE(_ZNSt11_Deque_baseISsSaISsEE16_M_destroy_nodesEPPSsS3_)
    SCENE_LINKONCE(_ZNSt10_List_baseIN6common6handleIN5scene4NodeEEESaIS4_EE7__clearEv)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE11lower_boundERS0_)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE13insert_uniqueESt17_Rb_tree_iteratorIS7_RS7_PS7_ERKS7_)
    SCENE_LINKONCE(_ZNSt10_List_baseIN6common6handleIN5scene9TransformEEESaIS4_EE7__clearEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene9TransformEEESaIS4_EE6insertESt14_List_iteratorIS4_RS4_PS4_ERKS4_)
    SCENE_LINKONCE(_ZNSt10_List_baseIN6common6handleIN5scene15StaticTransformEEESaIS4_EE7__clearEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene15StaticTransformEEESaIS4_EE6insertESt14_List_iteratorIS4_RS4_PS4_ERKS4_)
    SCENE_LINKONCE(_ZNSt10_List_baseIN6common6handleIN5scene5GroupEEESaIS4_EE7__clearEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene5GroupEEESaIS4_EE6insertESt14_List_iteratorIS4_RS4_PS4_ERKS4_)
    SCENE_LINKONCE(_ZNSt10_List_baseIN6common6handleIN5scene5ShapeEEESaIS4_EE7__clearEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene5ShapeEEESaIS4_EE6insertESt14_List_iteratorIS4_RS4_PS4_ERKS4_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl5ColorESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
    SCENE_LINKONCE(_ZNSt10_List_baseIN6common6handleIN5scene8MaterialEEESaIS4_EE7__clearEv)
    SCENE_LINKONCE(_ZNSt4listIN6common6handleIN5scene8MaterialEEESaIS4_EE6insertESt14_List_iteratorIS4_RS4_PS4_ERKS4_)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE16_M_push_back_auxERKSs)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE15_M_pop_back_auxEv)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE12insert_equalERKS7_)
    SCENE_LINKONCE(_ZNSt5dequeIN4math6matrixESaIS1_EE5clearEv)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE7_M_copyEPSt13_Rb_tree_nodeIS7_ESG_)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE7_M_copyEPSt13_Rb_tree_nodeIS7_ESF_)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE5clearEv)
    SCENE_LINKONCE(_ZNSt11_Deque_baseISsSaISsEE15_M_create_nodesEPPSsS3_)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorISsRKSsPS1_ES0_ISsRSsPSsEET0_T_S9_S8_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN6common6handleIN5scene4NodeEEESt6vectorIS6_SaIS6_EEEESB_ET0_T_SD_SC_12__false_type)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE9_M_insertEPSt18_Rb_tree_node_baseSF_RKS7_)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ESt4lessIS0_ESaIS7_EE13insert_uniqueERKS7_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl5ColorESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    SCENE_LINKONCE(_ZNSt8_Rb_treeIKSsSt4pairIS0_N6common6handleIN5scene4NodeEEEESt10_Select1stIS7_ENS2_7LessStrESaIS7_EE9_M_insertEPSt18_Rb_tree_node_baseSE_RKS7_)
    SCENE_LINKONCE(_ZNSt5dequeIN4math6matrixESaIS1_EE19_M_range_insert_auxISt15_Deque_iteratorIS1_RKS1_PS6_EEEvS5_IS1_RS1_PS1_ET_SD_St20forward_iterator_tag)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE19_M_range_insert_auxISt15_Deque_iteratorISsRKSsPS4_EEEvS3_ISsRSsPSsET_SB_St20forward_iterator_tag)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl5ColorESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE17_M_reallocate_mapEjb)
    SCENE_LINKONCE(_ZNSt5dequeIN4math6matrixESaIS1_EE13_M_insert_auxISt15_Deque_iteratorIS1_RKS1_PS6_EEEvS5_IS1_RS1_PS1_ET_SD_j)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE13_M_insert_auxISt15_Deque_iteratorISsRKSsPS4_EEEvS3_ISsRSsPSsET_SB_j)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl5ColorES2_ET0_T_S4_S3_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl5ColorEjS1_ET_S3_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl5ColorESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl5ColorESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl5ColorESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZNSt5dequeIN4math6matrixESaIS1_EE24_M_new_elements_at_frontEj)
    SCENE_LINKONCE(_ZNSt5dequeIN4math6matrixESaIS1_EE23_M_new_elements_at_backEj)
    SCENE_LINKONCE(_ZSt25__uninitialized_copy_copyISt15_Deque_iteratorIN4math6matrixERS2_PS2_ES0_IS2_RKS2_PS6_ES5_ET1_T_SB_T0_SC_SA_)
    SCENE_LINKONCE(_ZSt25__uninitialized_copy_copyISt15_Deque_iteratorIN4math6matrixERKS2_PS3_ES0_IS2_RS2_PS2_ES9_ET1_T_SB_T0_SC_SA_)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE24_M_new_elements_at_frontEj)
    SCENE_LINKONCE(_ZNSt5dequeISsSaISsEE23_M_new_elements_at_backEj)
    SCENE_LINKONCE(_ZSt25__uninitialized_copy_copyISt15_Deque_iteratorISsRSsPSsES0_ISsRKSsPS4_ES3_ET1_T_S9_T0_SA_S8_)
    SCENE_LINKONCE(_ZSt25__uninitialized_copy_copyISt15_Deque_iteratorISsRKSsPS1_ES0_ISsRSsPSsES7_ET1_T_S9_T0_SA_S8_)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorIN4math6matrixERS2_PS2_ES5_ET0_T_S7_S6_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxISt15_Deque_iteratorISsRSsPSsES3_ET0_T_S5_S4_12__false_type)
    SCENE_LINKONCE(_ZNK4math6matrix5equalERKS0_f)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1EPS2_)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1ERKS3_)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_6ObjectEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5SetupEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_7TextureEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_8MaterialEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5ShapeEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4MeshEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_4MeshEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene9TransformEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene15StaticTransformEED1Ev)
    SCENE_LINKONCE(_ZNSt22_Rb_tree_base_iterator12_M_incrementEv)
    SCENE_LINKONCE(_ZNSt22_Rb_tree_base_iterator12_M_decrementEv)
    SCENE_LINKONCE(_ZSt18_Rb_tree_rebalancePSt18_Rb_tree_node_baseRS0_)
    SCENE_LINKONCE(_ZSt28_Rb_tree_rebalance_for_erasePSt18_Rb_tree_node_baseRS0_S1_S1_)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5GroupEEC1INS1_6ObjectEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene6ObjectEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5ShapeEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEEC1INS1_5SetupEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4MeshEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5SetupEEC1INS1_13DefaultShaderEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIKN5scene4NodeEEC1IS2_EERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIKN5scene4NodeEED1Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5SetupEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5ShapeEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4MeshEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene9TransformEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene15StaticTransformEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene9TransformEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene15StaticTransformEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene8MaterialEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIKN5scene4NodeEED0Ev)
    SCENE_LINKONCE(_ZN6common6handleIN5scene13DefaultShaderEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZNSt15_Deque_iteratorIN4math6matrixERS1_PS1_EpLEi)
    SCENE_LINKONCE(_ZNSt15_Deque_iteratorISsRSsPSsEpLEi)
    SCENE_LINKONCE(_ZSt20_Rb_tree_rotate_leftPSt18_Rb_tree_node_baseRS0_)
    SCENE_LINKONCE(_ZSt21_Rb_tree_rotate_rightPSt18_Rb_tree_node_baseRS0_)
);
extern const char D_00169304[];     /* " *** error " */
extern const char D_001692EC[];     /* "../lib/scene/Graph.cpp" */
extern const char D_001694B8[];     /* " " */
extern const char D_00169520[];     /* "::" */
extern const char D_00169640[];     /* "! _namespace_stack.empty()" */
extern const char D_001697E4[];     /* "\n" */
extern const char Graph_finish_name[] __asm__("_ZZN5scene5Graph6finishEvE19__PRETTY_FUNCTION__");
extern const char Graph_popNamespace_name[] __asm__("_ZZN5scene5Graph12popNamespaceEvE19__PRETTY_FUNCTION__");
extern const char Graph_getNamespace_name[] __asm__("_ZZNK5scene5Graph12getNamespaceEvE19__PRETTY_FUNCTION__");
extern const char Graph_loadNamespace_name[] __asm__("_ZZN5scene5Graph13loadNamespaceESsE19__PRETTY_FUNCTION__");
extern const char D_001694BC[];
extern const char D_001694F8[];
extern const char Graph_newMesh_name[] __asm__("_ZZN5scene5Graph7newMeshESsRKN3sgl4MeshEjE19__PRETTY_FUNCTION__");
extern const char D_001692DC[];     /* "object.valid()" */
extern const char Graph_cloneGroup_name[] __asm__("_ZZN5scene5Graph10cloneGroupESsSsE19__PRETTY_FUNCTION__");
extern const char Graph_cloneObject_name[] __asm__("_ZZN5scene5Graph11cloneObjectESsSsE19__PRETTY_FUNCTION__");

extern const char D_001691B4[];     /* "root" */

/* Graph.h's asserts (getMappedNode<T>, newNode<T>) */
extern const char scene_graph_h_err[] __asm__("D_00169304");        /* " *** error " */
extern const char scene_graph_h_name_expr[] __asm__("D_00169848");  /* "_Name != \"\"" */
extern const char scene_graph_h_file[] __asm__("D_00169854");       /* "../lib/scene/Graph.h" */
extern const char scene_graph_h_sp[] __asm__("D_001694B8");         /* " " */
extern const char scene_graph_h_empty[] __asm__("D_001691C8");      /* "" */
extern const char scene_graph_h_us[] __asm__("D_0016986C");         /* "_" */
extern const char gmn_Group_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_5GroupEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION___1697E8");
extern const char gmn_Object_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_6ObjectEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION__");
extern const char gmn_Mesh_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_4MeshEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION___1698D0");
extern const char gmn_DefaultShader_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_13DefaultShaderEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION___169A08");
namespace scene {
inline const char *scene_pf_getMappedNode(Group *) { return gmn_Group_name; }
inline const char *scene_pf_getMappedNode(Object *) { return gmn_Object_name; }
inline const char *scene_pf_getMappedNode(Mesh *) { return gmn_Mesh_name; }
inline const char *scene_pf_getMappedNode(DefaultShader *) { return gmn_DefaultShader_name; }
}
extern const char D_001691C8[];     /* "" */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5GraphC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5GraphC1Ev);

namespace scene {
Graph::~Graph()
{
    popNamespace();
}
}

void scene::Graph::deleteNode(common::handle<Node> n)
{
    if (hnull(n))
        return;
    hdelete(n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph12deleteBranchEN6common6handleINS_4NodeEEE);

common::handle<scene::Node> scene::Graph::cloneNode(common::handle<Node> n, std::string name)
{
    common::handle<Node> c = n->clone(name);
    add_node(c);
    return c;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph11cloneBranchEN6common6handleINS_5GroupEEESs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph10cloneGroupESsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph11cloneObjectESsSs);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph9newObjectESs);

common::handle<scene::Mesh> scene::Graph::newMesh(std::string name, const sgl::Mesh &m, unsigned int fmt)
{
    common::handle<Mesh> h = newNode<Mesh>(name, true);
    SCENE_ASSERT(sgl_PrimitiveIndex_countTriangles(m.getPrims()), D_00169304, D_001694F8, D_001692EC, Graph_newMesh_name, 231,
                 D_001694BC);
    h->getData().copy(m);
    h->format(fmt);
    return h;
}

common::handle<scene::Object> scene::Graph::getObject(std::string name)
{
    std::string key = name;
    key += D_00169520;
    key += name;
    NodeMap::iterator i = _mapA.find(key);
    return common::handle<Object>(i != _mapA.end() ? i->second : common::handle<Node>());
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph10newTextureESsbSs);

void scene::Graph::flattenTransforms(common::handle<Group> g)
{
    math::TransformStack ts;
    ts.push();
    ts.identity();
    g->flatten(ts);
    ts.pop();
    {
        common::handles_list<Transform> l;
        getSublist<Transform>(l);
        for (common::handles_list<Transform>::iterator i = l.begin(); i != l.end(); ++i)
            (*i)->setIdentity();
    }
    {
        common::handles_list<StaticTransform> l;
        getSublist<StaticTransform>(l);
        for (common::handles_list<StaticTransform>::iterator i = l.begin(); i != l.end(); ++i)
            (*i)->setIdentity();
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph7cleanUpEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph16flattenMaterialsEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph16attachPass1ToAllEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph10assertFlatEv);

void scene::Graph::loadNamespace(std::string ns)
{
    SCENE_ASSERT(!_namespace_stack.empty(), D_00169304, D_00169640, D_001692EC, Graph_loadNamespace_name, 593, D_001694B8);
    _namespace_stack.top() = ns;
}

void scene::Graph::pushNamespace(std::string ns)
{
    _namespace_stack.push(ns);
}

void scene::Graph::popNamespace()
{
    SCENE_ASSERT(!_namespace_stack.empty(), D_00169304, D_00169640, D_001692EC, Graph_popNamespace_name, 607, D_001694B8);
    _namespace_stack.pop();
}

const std::string &scene::Graph::getNamespace() const
{
    SCENE_ASSERT(!_namespace_stack.empty(), D_00169304, D_00169640, D_001692EC, Graph_getNamespace_name, 613, D_001694B8);
    return _namespace_stack.top();
}

std::string scene::Graph::translatedName(std::string name) const
{
    std::string r;
    r = getNamespace();
    if (r == D_001691C8)
        r = name;
    else {
        r += D_00169520;
        r += name;
    }
    return r;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph8add_nodeEN6common6handleINS_4NodeEEE);

void scene::Graph::printMapA() {
}

void scene::Graph::printMapU() {
}

void scene::Graph::printMapO() {
}

void scene::Graph::clear()
{
    *this = Graph();
}

sgl::BV &scene::Graph::getBV()
{
    return _root->_bvdata.get();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph23tag_identity_transformsEv);

void scene::Graph::finish()
{
    common::Log() << Graph_finish_name << D_001697E4;
    tag_identity_transforms();
    calcbv();
    _finish_called = true;
}

/* Instances that the (asm) methods above use: called from a function that the link discards
   (.discard.asm), so cc1plus instantiates them implicitly at the end of the unit like Sony's
   object did (explicit instantiations would be compiled before the deferred functions and change
   e.g. cloneNode's code) */
namespace scene_graph_uses {
typedef common::handle<scene::Node> HN;
typedef std::pair<const std::string, HN> Pair;
typedef std::_Rb_tree<const std::string, Pair, std::_Select1st<Pair>, common::LessStr, std::allocator<Pair> > TreeO;
typedef std::_Rb_tree<const std::string, Pair, std::_Select1st<Pair>, std::less<const std::string>, std::allocator<Pair> > TreeA;
}
namespace sgl {
template<class T> int PrimitiveIndex<T>::countTriangles() const
{
    return countTrianglesInStrips() + _tri.size() / 3;
}
}
/* asm: near-miss (tmp/cxx/drafts/scene4/NOTES.md) */
extern "C" const char D_00169304[], D_00169980[], D_0016998C[], D_001694B8[];
extern const char cts_name[] __asm__("_ZZNK3sgl14PrimitiveIndexIiE22countTrianglesInStripsEvE19__PRETTY_FUNCTION___169930");
#define CTS_ASSERT(c) SGL_ASSERT(c, D_00169304, D_00169980, D_0016998C, cts_name, 0xE7, D_001694B8)
namespace sgl {
template<class T> size_t PrimitiveIndex<T>::countTrianglesInStrips() const
{
    size_t count = 0;
    for (int i = 0, k = 0; i != n; i++) {
        size_t num = _strips[k++];
        CTS_ASSERT(num >= 3);
        k += num;
        count += num - 2;
    }
    return count;
}
}
template size_t sgl::PrimitiveIndex<int>::countTrianglesInStrips() const;
template int sgl::PrimitiveIndex<int>::countTriangles() const;
/* asm: near-miss (Graph.h newNode<T>, scene.hpp: one delay slot filled from the other path) */
extern template common::handle<scene::Mesh> scene::Graph::newNode<scene::Mesh>(std::string, bool);
/* asm (near-miss: v1/a2 swapped in the copy of the new element) */
extern template void std::vector<common::handle<scene::Node> >::_M_insert_aux(std::vector<common::handle<scene::Node> >::iterator,
                                                                               const common::handle<scene::Node> &);
extern "C" void scene_Graph_uses(scene::Graph *g, scene_graph_uses::TreeO *to, scene_graph_uses::TreeA *ta,
                                 std::vector<common::handle<scene::Node> > *vn, std::list<common::handle<scene::Node> > *ln,
                                 std::vector<sgl::Color> *vc, common::handle<scene::Node> *hn, common::handle<const scene::Node> *hc,
                                 common::handle<scene::Setup> *hs, common::handle<scene::Shape> *hsh, common::handle<scene::Mesh> *hm,
                                 common::handle<scene::Object> *ho, common::handle<scene::DefaultShader> *hd)
    __attribute__((section(".discard.asm")));
extern "C" void scene_Graph_uses(scene::Graph *g, scene_graph_uses::TreeO *to, scene_graph_uses::TreeA *ta,
                                 std::vector<common::handle<scene::Node> > *vn, std::list<common::handle<scene::Node> > *ln,
                                 std::vector<sgl::Color> *vc, common::handle<scene::Node> *hn, common::handle<const scene::Node> *hc,
                                 common::handle<scene::Setup> *hs, common::handle<scene::Shape> *hsh, common::handle<scene::Mesh> *hm,
                                 common::handle<scene::Object> *ho, common::handle<scene::DefaultShader> *hd)
{
    using namespace scene_graph_uses;
    g->getSublist(*(common::handles_list<scene::Group> *)0);
    g->getSublist(*(common::handles_list<scene::Shape> *)0);
    g->getSublist(*(common::handles_list<scene::Material> *)0);
    hs->invalidate();
    hsh->invalidate();
    hm->invalidate();
    hc->invalidate();
    *hn = *hn;
    common::handle<scene::Node> n1(*ho);
    common::handle<scene::Node> n2(*(common::handle<scene::Texture> *)0);
    common::handle<scene::Node> n3(*(common::handle<scene::Material> *)0);
    common::handle<scene::Node> n4(*hm);
    *hn = *ho;
    common::handle<scene::Group> a(*ho);
    common::handle<scene::Shape> b(*hn);
    common::handle<scene::DefaultShader> c(*hs);
    common::handle<scene::Mesh> d(*hn);
    common::handle<scene::Setup> e(*hd);
    common::handle<const scene::Node> f(*hn);
    common::handle<scene::Material> h(*hn);
    common::handle<scene::DefaultShader> i(*hn);
    ln->insert(ln->begin(), *hn);
    ln->clear();
    std::uninitialized_copy(vn->begin(), vn->end(), vn->begin());
    g->getMappedNode<scene::Group>(*(std::string *)0);
    g->getMappedNode<scene::Object>(*(std::string *)0);
    g->getMappedNode<scene::Mesh>(*(std::string *)0);
    g->getMappedNode<scene::DefaultShader>(*(std::string *)0);
    std::deque<std::string> q;
    vc->erase(vc->begin(), vc->end());
    vc->insert(vc->begin(), 0, sgl::Color());
    to->erase(to->begin(), to->end());
    to->insert_equal(*(Pair *)0);
    ta->lower_bound(*(std::string *)0);
    ta->insert_unique(ta->begin(), *(Pair *)0);
    ta->insert_unique(*(Pair *)0);
    /* stl_tree.h's out-of-line inline functions (static pointers in a discarded section: no .rodata) */
    static void (std::_Rb_tree_base_iterator::*incr)() __attribute__((section(".discard.data"))) = &std::_Rb_tree_base_iterator::_M_increment;
    static void (std::_Rb_tree_base_iterator::*decr)() __attribute__((section(".discard.data"))) = &std::_Rb_tree_base_iterator::_M_decrement;
    static void (*rebalance)(std::_Rb_tree_node_base *, std::_Rb_tree_node_base *&) __attribute__((section(".discard.data"))) = &std::_Rb_tree_rebalance;
    static std::_Rb_tree_node_base *(*rebalance_for_erase)(std::_Rb_tree_node_base *, std::_Rb_tree_node_base *&, std::_Rb_tree_node_base *&,
                                                           std::_Rb_tree_node_base *&) __attribute__((section(".discard.data"))) = &std::_Rb_tree_rebalance_for_erase;
    static void (*rotate_left)(std::_Rb_tree_node_base *, std::_Rb_tree_node_base *&) __attribute__((section(".discard.data"))) = &std::_Rb_tree_rotate_left;
    static void (*rotate_right)(std::_Rb_tree_node_base *, std::_Rb_tree_node_base *&) __attribute__((section(".discard.data"))) = &std::_Rb_tree_rotate_right;
    __asm__ volatile("" : : "m"(incr), "m"(decr), "m"(rebalance), "m"(rebalance_for_erase), "m"(rotate_left), "m"(rotate_right));
}

/* from here on INCLUDE_ASM puts the asm in its own .gnu.linkonce.t section (written as
   INCLUDE_ASM so that splat keeps these functions as asm) */
#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Group4findINS_4NodeEEEvRN6common14handles_vectorIS2_EEb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph7newNodeINS_6ObjectEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph7newNodeINS_4MeshEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph7newNodeINS_7TextureEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN5scene5Graph7newNodeINS_13DefaultShaderEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZNSt6vectorIN6common6handleIN5scene4NodeEEESaIS4_EE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPS4_S6_EERKS4_);
/* STAND-IN: float pointer views (row y/z/w through a row base register, as in the original) */
static inline bool matrix_row_equal(const math::vector_xyzw &a, const math::vector_xyzw &b, float e)
{
    const float *p = &a.x, *q = &b.x;
    return fabsf(p[0] - q[0]) < e && fabsf(p[1] - q[1]) < e && fabsf(p[2] - q[2]) < e && fabsf(p[3] - q[3]) < e;
}
/* the (asm) callers' inline copy: emitted through a discarded user defined before it */
extern "C" void scene_Graph_matrix_equal_ref(const math::matrix &a, const math::matrix &b) __attribute__((section(".discard.asm")));
extern "C" void scene_Graph_matrix_equal_ref(const math::matrix &a, const math::matrix &b)
{
    a.equal(b, 0);
}
SGL_LINKONCE_BEGIN
inline bool math::matrix::equal(const matrix &m, float e) const
{
    if (!matrix_row_equal(r[0], m.r[0], e))
        return false;
    if (!matrix_row_equal(r[1], m.r[1], e))
        return false;
    if (!matrix_row_equal(r[2], m.r[2], e))
        return false;
    if (!matrix_row_equal(r[3], m.r[3], e))
        return false;
    return true;
}
SGL_LINKONCE_END
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN6common6handleIN5scene4NodeEEC1EPS2_);
INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/scene_Graph", _ZN6common6handleIN5scene4NodeEEC1ERKS3_);
