/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const float D_00170AAC;
namespace common {
extern template class t_array<sgl::Position>;
extern template class t_array2d<sgl::Position>;
}
extern const float D_00170AD8;      /* 1.0f */
extern const float D_00170ADC;      /* 1.0f */

extern const float D_00170AC8;      /* degrees -> radians */
extern const float D_00170ACC;      /* degrees -> radians */
extern const float D_00170B10;      /* 1.0f */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _Z41__static_initialization_and_destruction_0ii_C3BA8);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12extruded_varC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12extruded_varC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12extruded_var5resetEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder9begin_varC2ENS_9InputModeENS_9BeginModeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder9begin_varC1ENS_9InputModeENS_9BeginModeE);

void sgl::MeshBuilder::begin_var::reset()
{
    *this = begin_var(InputMode(0), BeginMode(0));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderC2ERNS_4MeshEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderC1ERNS_4MeshEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderD0Ev);

void sgl::MeshBuilder::grey(float g)
{
    color(g, g, g, 0);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5beginENS_9InputModeENS_9BeginModeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5beginENS_9BeginModeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder3endEv);

void sgl::MeshBuilder::normal(Normal n)
{
    if (_var._write_primitive == 1)
        _var._normal.set(n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6normalEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5colorENS_5ColorE);

void sgl::MeshBuilder::color(float r, float g, float b, float a)
{
    color(Color(r, g, b, a));
}

void sgl::MeshBuilder::color(float g, float a)
{
    color(Color(g, g, g, a));
}

void sgl::MeshBuilder::color(float g)
{
    color(Color(g, g, g, g));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder7color_iEj);

void sgl::MeshBuilder::colorG(Color c)
{
    _colorG.set(c);
}

void sgl::MeshBuilder::colorG(float r, float g, float b, float a)
{
    _colorG.set(Color(r, g, b, a));
}

void sgl::MeshBuilder::colorG(float g, float a)
{
    _colorG.set(Color(g, g, g, a));
}

void sgl::MeshBuilder::colorG(float g)
{
    _colorG.set(Color(g, g, g, g));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder7colorGiEj);

void sgl::MeshBuilder::texcoord(TexCoord t)
{
    if (_var._write_primitive == 1)
        _var._texcoord.set(t);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder8texcoordEff);

void sgl::MeshBuilder::vertex(Position p)
{
    vertex(p.x, p.y, p.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6vertexEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6vertexEi);

void sgl::MeshBuilder::triangle(int a, int b, int c)
{
    vertex(a);
    vertex(b);
    vertex(c);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6quad_tEiiiib);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK3sgl11MeshBuilder16transform_normalERKNS_6NormalE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK3sgl11MeshBuilder18transform_positionERKNS_8PositionE);

sgl::Color sgl::MeshBuilder::transform_color(const Color &c) const
{
    return c;
}

sgl::TexCoord sgl::MeshBuilder::transform_texcoord(const TexCoord &t) const
{
    return t;
}

void sgl::MeshBuilder::revolutionSlices(int n)
{
    _ext._slices = n > 0 ? n : 0;
}

void sgl::MeshBuilder::revolutionStartAngle(float a)
{
    _ext._start_angle = a;
}

void sgl::MeshBuilder::revolutionEndAngle(float a)
{
    _ext._end_angle = a;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder14extrusionBeginENS_8LineModeE);

void sgl::MeshBuilder::extrusionEnd()
{
    _ext._lineset.end();
}

void sgl::MeshBuilder::extrusionReverseNormals(bool b)
{
    _ext._lineset.set_negate_normals(b);
}

void sgl::MeshBuilder::extrusionCreaseAngle(float a)
{
    _ext._lineset.set_crease(a * D_00170AC8);
}

void sgl::MeshBuilder::transformListSetCreaseAngle(float a)
{
    _ext._tset.set_crease(a * D_00170ACC);
}

void sgl::MeshBuilder::transformListBegin()
{
    _ext._tset.clear();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder17transformListSnapEv);

void sgl::MeshBuilder::transformListEnd() {
}

void sgl::MeshBuilder::transformListClose(bool b)
{
    _ext._tset._closed = b;
}

void sgl::MeshBuilder::end_revolution()
{
    if (_var._write_primitive == 2) {
        revolve(_ext);
        _ext.reset();
    }
}

void sgl::MeshBuilder::end_sweep()
{
    if (_var._write_primitive == 3) {
        sweep(_ext);
        _ext.reset();
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder7revolveERKNS0_12extruded_varE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5sweepERKNS0_12extruded_varE);

sgl::MeshBuilder::spline_var::spline_var()
    : _count(0), _tessU(16), _tessV(16), _closeU(false), _closeV(false), _flipS(false), _flipT(false),
      _texcoord(true), _normals(true)
{
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12splineSetDimEjj);

void sgl::MeshBuilder::splineControlPoint(float x, float y, float z)
{
    splineControlPoint(Position(x, y, z, D_00170AD8));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder18splineControlPointENS_8PositionE);

void sgl::MeshBuilder::splineControlPoint(float x, float y, float z, unsigned int u, unsigned int v)
{
    splineControlPoint(Position(x, y, z, D_00170ADC), u, v);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder18splineControlPointENS_8PositionEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder16splineTesselateUEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder16splineTesselateVEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10spline_var5resetEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12splineCloseUEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12splineCloseVEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder11splineFlipSEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder11splineFlipTEb);

void sgl::MeshBuilder::splineEnableTexCoord(bool b)
{
    _spline._texcoord = b;
}

void sgl::MeshBuilder::splineEnableNormals(bool b)
{
    _spline._normals = b;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10end_splineEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5arrowEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10cubeDirectEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder11cubeIndexedEv);

void sgl::MeshBuilder::normalAt(int i, float x, float y, float z)
{
    normalAt(i, Normal(x, y, z));
}

void sgl::MeshBuilder::normalAt(int i, Normal n)
{
    _mesh->normalAt(i, transform_normal(n));
}

void sgl::MeshBuilder::colorAt(int i, float r, float g, float b, float a)
{
    colorAt(i, Color(r, g, b, a));
}

void sgl::MeshBuilder::colorAt(int i, Color c)
{
    _mesh->colorAt(i, transform_color(c));
}

void sgl::MeshBuilder::texcoordAt(int i, float u, float v)
{
    texcoordAt(i, TexCoord(u, v));
}

void sgl::MeshBuilder::texcoordAt(int i, TexCoord t)
{
    _mesh->texcoordAt(i, transform_texcoord(t));
}

void sgl::MeshBuilder::positionAt(int i, float x, float y, float z)
{
    positionAt(i, Position(x, y, z, D_00170B10));
}

void sgl::MeshBuilder::positionAt(int i, Position p)
{
    _mesh->positionAt(i, transform_position(p));
}

void sgl::MeshBuilder::vertexAt(int i, int p)
{
    vertexAt(i, p, -1, -1, -1);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder8vertexAtEiNS_8PositionE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder8vertexAtEifff);

void sgl::MeshBuilder::vertexAt(int i, int p, int n, int c, int t)
{
    _mesh->vertexAt(i, p, n, c, t);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6sphereEfiiff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder8cylinderEffii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder4coneEffii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder3boxEfffb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder4gridEjjffffb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder9setParamsERKNS_10MeshParamsE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6finishEv);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_C3BA8");
void _GLOBAL__I__ZN3sgl11MeshBuilder12extruded_varC2Ev(void);
void _GLOBAL__D__ZN3sgl11MeshBuilder12extruded_varC2Ev(void);
}

void _GLOBAL__I__ZN3sgl11MeshBuilder12extruded_varC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN3sgl11MeshBuilder12extruded_varC2Ev(void)
{
    static_init(0, 0xFFFF);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIN3sgl7LineSet4LineESaIS2_EEaSERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EEaSERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE6resizeEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common9t_array2dIN3sgl8PositionEE2nxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common9t_array2dIN3sgl8PositionEE2nyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN4math4max_IjEET_S1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE2atEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN4math4max_IiEET_S1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIbSaIbEEaSERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIfSaIfEEaSERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIN4math11vector_xyzwESaIS1_EEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl7LineSet4LineESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl12TransformSet9TransformESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE8allocateEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE4swapERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE4fillERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE4swapERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE7resizexEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE7resizeyEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE4copyERKS3_iiiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common4SwapINS_7t_arrayIN3sgl8PositionEE7MembersEEEvRT_S7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common4SwapINS_9t_array2dIN3sgl8PositionEE3DimEEEvRT_S7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common9t_array2dIN3sgl8PositionEE2atEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common7t_arrayIN3sgl8PositionEE4addrEv);

