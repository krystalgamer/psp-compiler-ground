/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#define DEMO_TEMPLATE_DEFS
#define SCENE_GRAPH_TEMPLATE_DEFS
#define SGL_TEMPLATE_DEFS 1
#define SCENE_LINKONCE_GraphParser 1
extern const float D_00166FB8;
#define SGL_POSITION_ONE D_00166FB8
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor; cc1plus keys them to the
   first public symbol, the deferred-asm wrapper of the (still asm) first function */
__asm__(".globl _GLOBAL__I__ZN5scene11GraphParserC2ERNS_5GraphESsj\n_GLOBAL__I__ZN5scene11GraphParserC2ERNS_5GraphESsj = _GLOBAL__I__ZN5scene11GraphParserC2ERNS_5GraphESsj__asm");
__asm__(".globl _GLOBAL__D__ZN5scene11GraphParserC2ERNS_5GraphESsj\n_GLOBAL__D__ZN5scene11GraphParserC2ERNS_5GraphESsj = _GLOBAL__D__ZN5scene11GraphParserC2ERNS_5GraphESsj__asm");
SCENE_ALLOC_FIRST_USE
/* linkonce order: this object's .gnu.linkonce.t sections in Sony's link order */
SCENE_LINKONCE_ORDER(
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_6SwitchEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_5GroupEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN6common6handleIN5scene6ObjectEEaSERKS3_)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_5ShapeEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_15StaticTransformEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN11FieldParser16step_xxxx_vectorIN3sgl8PositionEEEvRSt6vectorIT_SaIS4_EEjRKNS_5FieldE)
    SCENE_LINKONCE(_ZN11FieldParser16step_xxxx_vectorIN3sgl6NormalEEEvRSt6vectorIT_SaIS4_EEjRKNS_5FieldE)
    SCENE_LINKONCE(_ZN11FieldParser16step_xxxx_vectorIN3sgl8TexCoordEEEvRSt6vectorIT_SaIS4_EEjRKNS_5FieldE)
    SCENE_LINKONCE(_ZN11FieldParser16step_xxxx_vectorIN3sgl5ColorEEEvRSt6vectorIT_SaIS4_EEjRKNS_5FieldE)
    SCENE_LINKONCE(_ZN3sgl14PrimitiveIndexIiE3triEv)
    SCENE_LINKONCE(_ZN3sgl14PrimitiveIndexIiE6stripsEv)
    SCENE_LINKONCE(_ZN5scene5Graph7newNodeINS_8MaterialEEEN6common6handleIT_EESsb)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_4NodeEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_8MaterialEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_5ShapeEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_5SetupEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZN5scene5Group4findINS_5ShapeEEEvRN6common14handles_vectorINS_4NodeEEEb)
    SCENE_LINKONCE(_ZN5scene5Group4findINS_4MeshEEEvRN6common14handles_vectorINS_4NodeEEEb)
    SCENE_LINKONCE(_ZNSt6vectorIiSaIiEE5eraseEN9__gnu_cxx17__normal_iteratorIPiS1_EES5_)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_6SwitchEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZN5scene5Graph13getMappedNodeINS_15StaticTransformEEEN6common6handleIT_EERKSs)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl6VertexESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
    SCENE_LINKONCE(_ZNSt6vectorIN2sh9VectorRGBESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
    SCENE_LINKONCE(_ZNSt6vectorIiSaIiEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPiS1_EEjRKi)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl8PositionESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl6NormalESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl8TexCoordESaIS1_EE5eraseEN9__gnu_cxx17__normal_iteratorIPS1_S3_EES7_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl6VertexESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    SCENE_LINKONCE(_ZNSt6vectorIN2sh9VectorRGBESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEEiEvT_S7_RKT0_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl8PositionESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl6NormalESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    SCENE_LINKONCE(_ZNSt6vectorIN3sgl8TexCoordESaIS1_EE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPS1_S3_EEjRKS1_)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl6VertexESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN2sh9VectorRGBESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl8PositionESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl6NormalESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    SCENE_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPN3sgl8TexCoordESt6vectorIS3_SaIS3_EEEES3_EvT_S9_RKT0_)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl6VertexES2_ET0_T_S4_S3_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl6VertexEjS1_ET_S3_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl6VertexESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl6VertexESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl6VertexESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIPN2sh9VectorRGBES2_ET0_T_S4_S3_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN2sh9VectorRGBEjS1_ET_S3_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh9VectorRGBESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN2sh9VectorRGBESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN2sh9VectorRGBESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt6fill_nIPijiET_S1_T0_RKT1_)
    SCENE_LINKONCE(_ZSt6fill_nIN9__gnu_cxx17__normal_iteratorIPiSt6vectorIiSaIiEEEEjiET_S7_T0_RKT1_)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl8PositionES2_ET0_T_S4_S3_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl8PositionEjS1_ET_S3_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8PositionESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8PositionESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8PositionESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl6NormalES2_ET0_T_S4_S3_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl6NormalEjS1_ET_S3_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl6NormalESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl6NormalESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl6NormalESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIPN3sgl8TexCoordES2_ET0_T_S4_S3_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIPN3sgl8TexCoordEjS1_ET_S3_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TexCoordESt6vectorIS3_SaIS3_EEEES4_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TexCoordESt6vectorIS3_SaIS3_EEEES8_ET0_T_SA_S9_12__false_type)
    SCENE_LINKONCE(_ZSt26__uninitialized_fill_n_auxIN9__gnu_cxx17__normal_iteratorIPN3sgl8TexCoordESt6vectorIS3_SaIS3_EEEEjS3_ET_S9_T0_RKT1_12__false_type)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_5ShapeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4NodeEEC1INS1_15StaticTransformEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN11FieldParserD0Ev)
    SCENE_LINKONCE(_ZN11FieldParserD1Ev)
    SCENE_LINKONCE(_ZN5scene11GraphParserD0Ev)
    SCENE_LINKONCE(_ZN5scene11GraphParserD1Ev)
    SCENE_LINKONCE(_ZN5scene11GraphParser11step_matrixERN4math6matrixE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5SetupEEC1INS1_4NodeEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene5ShapeEEC1INS1_5GroupEEERKNS0_IT_EE)
    SCENE_LINKONCE(_ZN6common6handleIN5scene4MeshEEC1INS1_5GroupEEERKNS0_IT_EE)
);

/* Graph.h's asserts (getMappedNode<T>) */
extern const char scene_graph_h_err[] __asm__("D_00167064");        /* " *** error " */
extern const char scene_graph_h_name_expr[] __asm__("D_00167B68");  /* "_Name != \"\"" */
extern const char scene_graph_h_file[] __asm__("D_00167B74");       /* "../lib/scene/Graph.h" */
extern const char scene_graph_h_sp[] __asm__("D_00167070");         /* " " */
extern const char scene_graph_h_empty[] __asm__("D_0016701C");      /* "" */
extern const char scene_graph_h_us[] __asm__("D_00167B04");         /* "_" */
extern const char gmn_Node_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_4NodeEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION__");
extern const char gmn_Material_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_8MaterialEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION__");
extern const char gmn_Shape_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_5ShapeEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION__");
extern const char gmn_Setup_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_5SetupEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION__");
extern const char gmn_Switch_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_6SwitchEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION__");
extern const char gmn_StaticTransform_name[] __asm__("_ZZN5scene5Graph13getMappedNodeINS_15StaticTransformEEEN6common6handleIT_EERKSsE19__PRETTY_FUNCTION__");
namespace scene {
inline const char *scene_pf_getMappedNode(Node *) { return gmn_Node_name; }
inline const char *scene_pf_getMappedNode(Material *) { return gmn_Material_name; }
inline const char *scene_pf_getMappedNode(Shape *) { return gmn_Shape_name; }
inline const char *scene_pf_getMappedNode(Setup *) { return gmn_Setup_name; }
inline const char *scene_pf_getMappedNode(Switch *) { return gmn_Switch_name; }
inline const char *scene_pf_getMappedNode(StaticTransform *) { return gmn_StaticTransform_name; }
}

/* Graph.load.cpp's asserts */
extern const char gl_braces_expr[] __asm__("D_00167074");     /* "is_equal(\"}\")" */
extern const char gl_file[] __asm__("D_00167084");            /* "../lib/scene/Graph.load.cpp" */
extern const char gl_lbrace[] __asm__("D_00167018");          /* "{" */
extern const char gl_rbrace[] __asm__("D_00167060");          /* "}" */
extern const char gl_unknown[] __asm__("D_00167608");         /* "unknown node type " */
extern const char gl_nl[] __asm__("D_0016761C");              /* "\n" */
extern const char gl_yes[] __asm__("D_00167658");
extern const char gl_mapped[] __asm__("D_0016765C");
extern const char gl_no[] __asm__("D_00167664");
extern const char gl_Texture[] __asm__("D_00167668");
extern const char gl_Switch[] __asm__("D_00167670");
extern const char gl_Group[] __asm__("D_00167678");
extern const char gl_Object[] __asm__("D_00167680");
extern const char gl_Scene[] __asm__("D_00167688");
extern const char gl_Shape[] __asm__("D_00167690");
extern const char gl_DefaultShader[] __asm__("D_00167698");
extern const char gl_Transform[] __asm__("D_001676A8");
extern const char gl_StaticTransform[] __asm__("D_001676B4");
extern const char gl_Mesh[] __asm__("D_001676C4");
extern const char gl_Material[] __asm__("D_001676CC");
extern const char gl_yesno_expr[] __asm__("D_001676D8");
extern const char pf_parse_new_group[] __asm__("_ZZN5scene11GraphParser15parse_new_groupERN11FieldParser5FieldERKSsbE19__PRETTY_FUNCTION__");
extern const char pf_parse_new_unknown[] __asm__("_ZZN5scene11GraphParser17parse_new_unknownERN11FieldParser5FieldERKSsbS5_E19__PRETTY_FUNCTION__");
extern const char pf_parse_new_shape[] __asm__("_ZZN5scene11GraphParser15parse_new_shapeERN11FieldParser5FieldERKSsbE19__PRETTY_FUNCTION__");
extern const char pf_parse_new_default_shader[] __asm__("_ZZN5scene11GraphParser24parse_new_default_shaderERN11FieldParser5FieldERKSsbE19__PRETTY_FUNCTION__");
extern const char pf_parse_new[] __asm__("_ZZN5scene11GraphParser9parse_newERN11FieldParser5FieldEE19__PRETTY_FUNCTION__");

template common::handle<scene::Object>::~handle();
extern template common::handle<scene::Group> scene::Graph::newNode<scene::Group>(std::string, bool);
extern template void std::vector<common::handle<scene::Node> >::_M_insert_aux(std::vector<common::handle<scene::Node> >::iterator,
                                                                              const common::handle<scene::Node> &);
extern template common::handle<scene::Shape> scene::Graph::newNode<scene::Shape>(std::string, bool);
extern template common::handle<scene::DefaultShader> scene::Graph::newNode<scene::DefaultShader>(std::string, bool);
extern template common::handle<scene::Switch> scene::Graph::newNode<scene::Switch>(std::string, bool);
extern template common::handle<scene::StaticTransform> scene::Graph::newNode<scene::StaticTransform>(std::string, bool);
extern template common::handle<scene::Material> scene::Graph::newNode<scene::Material>(std::string, bool);
extern template common::handle<scene::Transform> scene::Graph::newNode<scene::Transform>(std::string, bool);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParserC2ERNS_5GraphESsj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParserC1ERNS_5GraphESsj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser17parse_new_textureERN11FieldParser5FieldERKSsb);

extern template common::handle<scene::Switch> scene::Graph::newNode<scene::Switch>(std::string, bool);
extern const char gl_select[] __asm__("D_00167100");
extern const char pf_parse_new_switch[] __asm__("_ZZN5scene11GraphParser16parse_new_switchERN11FieldParser5FieldERKSsbE19__PRETTY_FUNCTION__");
namespace scene {
void GraphParser::parse_new_switch(FieldParser::Field &f, const std::string &name, bool mapped)
{
    common::handle<Switch> s = _graph.newNode<Switch>(name.c_str(), mapped);
    step_assert(gl_lbrace);
    while (step_field(f)) {
        if (is_equal(gl_select)) {
            step();
            s->select(get<int>());
        } else
            skip(f);
    }
    SCENE_ASSERT(is_equal(gl_rbrace), scene_graph_h_err, gl_braces_expr, gl_file, pf_parse_new_switch, 223, scene_graph_h_sp);
}
}


namespace scene {
void GraphParser::parse_new_group(FieldParser::Field &f, const std::string &name, bool mapped)
{
    _graph.newNode<Group>(name.c_str(), mapped);
    step_assert(gl_lbrace);
    while (step_field(f))
        skip(f);
    SCENE_ASSERT(is_equal(gl_rbrace), scene_graph_h_err, gl_braces_expr, gl_file, pf_parse_new_group, 243, scene_graph_h_sp);
}
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser16parse_new_objectERN11FieldParser5FieldERKSsb);

namespace scene {
void GraphParser::parse_new_shape(FieldParser::Field &f, const std::string &name, bool mapped)
{
    _graph.newNode<Shape>(name.c_str(), mapped);
    step_assert(gl_lbrace);
    while (step_field(f))
        skip(f);
    SCENE_ASSERT(is_equal(gl_rbrace), scene_graph_h_err, gl_braces_expr, gl_file, pf_parse_new_shape, 285, scene_graph_h_sp);
}
}

namespace scene {
void GraphParser::parse_new_default_shader(FieldParser::Field &f, const std::string &name, bool mapped)
{
    _graph.newNode<DefaultShader>(name.c_str(), mapped);
    step_assert(gl_lbrace);
    while (step_field(f))
        skip(f);
    SCENE_ASSERT(is_equal(gl_rbrace), scene_graph_h_err, gl_braces_expr, gl_file, pf_parse_new_default_shader, 305, scene_graph_h_sp);
}
}

extern const char gl_translation[] __asm__("D_00167320");
extern const char gl_rotation[] __asm__("D_0016732C");
extern const char gl_scale[] __asm__("D_00167338");
extern const float D_00166FB4;
extern const char pf_parse_new_transform[] __asm__("_ZZN5scene11GraphParser19parse_new_transformERN11FieldParser5FieldERKSsbE19__PRETTY_FUNCTION__");
namespace scene {
void GraphParser::parse_new_transform(FieldParser::Field &f, const std::string &name, bool mapped)
{
    common::handle<Transform> t = _graph.newNode<Transform>(name.c_str(), mapped);
    step_assert(gl_lbrace);
    while (step_field(f)) {
        math::vector_xyz tr(0, 0, 0), rot(0, 0, 0), sc(D_00166FB4, D_00166FB4, D_00166FB4);
        if (is_equal(gl_translation)) {
            float *p = &tr.x;
            for (int i = 0; i != 3; i++) {
                step();
                p[i] = get<float>();
            }
        } else if (is_equal(gl_rotation)) {
            float *p = &rot.x;
            for (int i = 0; i != 3; i++) {
                step();
                p[i] = get<float>();
            }
        } else if (is_equal(gl_scale)) {
            float *p = &sc.x;
            for (int i = 0; i != 3; i++) {
                step();
                p[i] = get<float>();
            }
        } else
            skip(f);
    }
    SCENE_ASSERT(is_equal(gl_rbrace), scene_graph_h_err, gl_braces_expr, gl_file, pf_parse_new_transform, 341, scene_graph_h_sp);
}
}


extern const char gl_matrix[] __asm__("D_001673A4");
extern const char pf_parse_new_static_transform[] __asm__("_ZZN5scene11GraphParser26parse_new_static_transformERN11FieldParser5FieldERKSsbE19__PRETTY_FUNCTION__");
namespace scene {
void GraphParser::parse_new_static_transform(FieldParser::Field &f, const std::string &name, bool mapped)
{
    common::handle<StaticTransform> t = _graph.newNode<StaticTransform>(name.c_str(), mapped);
    step_assert(gl_lbrace);
    while (step_field(f)) {
        if (is_equal(gl_matrix)) {
            math::matrix m;
            step_matrix(m);
            t->setMatrix(m);
        } else
            skip(f);
    }
    SCENE_ASSERT(is_equal(gl_rbrace), scene_graph_h_err, gl_braces_expr, gl_file, pf_parse_new_static_transform, 371, scene_graph_h_sp);
}
}


INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser14parse_new_meshERN11FieldParser5FieldERKSsb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser18parse_new_materialERN11FieldParser5FieldERKSsb);

namespace scene {
void GraphParser::parse_new_unknown(FieldParser::Field &f, const std::string &name, bool mapped, const std::string &type)
{
    common::Log() << gl_unknown << type << gl_nl;
    step_assert(gl_lbrace);
    while (step_field(f))
        skip(f);
    SCENE_ASSERT(is_equal(gl_rbrace), scene_graph_h_err, gl_braces_expr, gl_file, pf_parse_new_unknown, 583, scene_graph_h_sp);
}

void GraphParser::parse_new(FieldParser::Field &f)
{
    step();
    std::string type = c_str();
    step();
    std::string name = c_str();
    step_assert(gl_mapped);
    step();
    SCENE_ASSERT(is_equal(gl_yes) || is_equal(gl_no), scene_graph_h_err, gl_yesno_expr, gl_file, pf_parse_new, 605, scene_graph_h_sp);
    bool mapped = is_equal(gl_yes);
    if (type == gl_Texture)
        parse_new_texture(f, name, mapped);
    else if (type == gl_Switch)
        parse_new_switch(f, name, mapped);
    else if (type == gl_Group)
        parse_new_group(f, name, mapped);
    else if (type == gl_Object || type == gl_Scene)
        parse_new_object(f, name, mapped);
    else if (type == gl_Shape)
        parse_new_shape(f, name, mapped);
    else if (type == gl_DefaultShader)
        parse_new_default_shader(f, name, mapped);
    else if (type == gl_Transform)
        parse_new_transform(f, name, mapped);
    else if (type == gl_StaticTransform)
        parse_new_static_transform(f, name, mapped);
    else if (type == gl_Mesh)
        parse_new_mesh(f, name, mapped);
    else if (type == gl_Material)
        parse_new_material(f, name, mapped);
    else
        parse_new_unknown(f, name, mapped, type);
}
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser20parse_push_child_cmdEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser24parse_attach_texture_cmdEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser25parse_attach_material_cmdEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser22parse_attach_setup_cmdEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene11GraphParser5parseERN11FieldParser5FieldE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Graph4loadESsjSs);

template<class T> void FieldParser::step_xxxx_vector(std::vector<T> &v, unsigned int n, const Field &f)
{
    v.resize(f.count / n);
    for (typename std::vector<T>::iterator i = v.begin(); i != v.end(); ++i) {
        float *p = (float *)&*i;
        for (unsigned int k = 0; k != n; k++) {
            step();
            p[k] = get<float>();
        }
    }
}

/* instances that the (asm) methods above use, referenced from a discarded function so that cc1plus
   instantiates them at the end of the unit (see scene_Graph.c) */
template<class V> static inline void scene_GraphParser_vec(V *v)
{
    v->erase(v->begin(), v->end());
    v->insert(v->begin(), 0, *(typename V::value_type *)0);
}
extern "C" void scene_GraphParser_uses(scene::Graph *g, common::handle<scene::Node> *hn, common::handle<scene::Group> *hg)
    __attribute__((section(".discard.asm")));
extern "C" void scene_GraphParser_uses(scene::Graph *g, common::handle<scene::Node> *hn, common::handle<scene::Group> *hg)
{
    const std::string &s = *(std::string *)0;
    ((FieldParser *)0)->step_xxxx_vector(*(std::vector<sgl::Position> *)0, 0, *(FieldParser::Field *)0);
    ((FieldParser *)0)->step_xxxx_vector(*(std::vector<sgl::Normal> *)0, 0, *(FieldParser::Field *)0);
    ((FieldParser *)0)->step_xxxx_vector(*(std::vector<sgl::TexCoord> *)0, 0, *(FieldParser::Field *)0);
    ((FieldParser *)0)->step_xxxx_vector(*(std::vector<sgl::Color> *)0, 0, *(FieldParser::Field *)0);
    *(common::handle<scene::Object> *)0 = *(common::handle<scene::Object> *)0;
    g->getMappedNode<scene::Node>(s);
    g->getMappedNode<scene::Material>(s);
    g->getMappedNode<scene::Shape>(s);
    g->getMappedNode<scene::Setup>(s);
    g->getMappedNode<scene::Switch>(s);
    g->getMappedNode<scene::StaticTransform>(s);
    scene_GraphParser_vec((std::vector<int> *)0);
    scene_GraphParser_vec((std::vector<sgl::Vertex> *)0);
    scene_GraphParser_vec((std::vector<sh::VectorRGB> *)0);
    scene_GraphParser_vec((std::vector<sgl::Position> *)0);
    scene_GraphParser_vec((std::vector<sgl::Normal> *)0);
    scene_GraphParser_vec((std::vector<sgl::TexCoord> *)0);
    common::handle<scene::Node> a(*(common::handle<scene::Shape> *)0);
    common::handle<scene::Node> c(*(common::handle<scene::StaticTransform> *)0);
    common::handle<scene::Setup> d(*hn);
    common::handle<scene::Shape> e(*hg);
    common::handle<scene::Mesh> f(*hg);
}

/* sgl::PrimitiveIndex<int> members that the (asm) methods above call (nothing in C++ calls them) */
template std::vector<int> &sgl::PrimitiveIndex<int>::tri();
template std::vector<int> &sgl::PrimitiveIndex<int>::strips();

/* from here on INCLUDE_ASM puts the asm in its own .gnu.linkonce.t section (written as
   INCLUDE_ASM so that splat keeps these functions as asm) */
#undef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME) INCLUDE_ASM_LINKONCE(FOLDER, NAME)

/* the object's weak tail (linkonce copies), still asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Graph7newNodeINS_6SwitchEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Graph7newNodeINS_5GroupEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Graph7newNodeINS_5ShapeEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Graph7newNodeINS_15StaticTransformEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Graph7newNodeINS_8MaterialEEEN6common6handleIT_EESsb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Group4findINS_5ShapeEEEvRN6common14handles_vectorINS_4NodeEEEb);
INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/scene_GraphParser", _ZN5scene5Group4findINS_4MeshEEEvRN6common14handles_vectorINS_4NodeEEEb);
/* an inline member in the original (its .gnu.linkonce.t copy); written as a plain function in that section so
   that the callers above don't inline it (they call it in the original) */
__attribute__((section(".gnu.linkonce.t._ZN5scene11GraphParser11step_matrixERN4math6matrixE")))
void scene::GraphParser::step_matrix(math::matrix &m)
{
    math::matrix t;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            step();
            t.r[i][j] = get<float>();
        }
    m = math::matrix(t.r[0], t.r[1], t.r[2], t.r[3]);
}
