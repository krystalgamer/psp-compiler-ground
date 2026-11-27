/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern const char D_0016DC64[];     /* " *** error " */
extern const char D_0016DC90[];     /* "../lib/sgl/MeshBuilder.cpp" */
extern const char D_0016DD38[];     /* " " */
extern const char D_0016DE60[];     /* "_var._write_primitive == BSPLINE" */
extern const char D_0016E0E4[];     /* "! _finished_called" */
#define MB_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_0016DC64, text, D_0016DC90, fn, line, D_0016DD38)
#define MB_PRETTY(n, s) extern const char n[] __asm__("_ZZN3sgl11MeshBuilder" s "E19__PRETTY_FUNCTION__")
MB_PRETTY(splineSetDim_name, "12splineSetDimEjj");
MB_PRETTY(splineTesselateU_name, "16splineTesselateUEj");
MB_PRETTY(splineTesselateV_name, "16splineTesselateVEj");
MB_PRETTY(splineCloseU_name, "12splineCloseUEb");
MB_PRETTY(splineCloseV_name, "12splineCloseVEb");
MB_PRETTY(splineFlipS_name, "11splineFlipSEb");
MB_PRETTY(splineFlipT_name, "11splineFlipTEb");
MB_PRETTY(finish_name, "6finishEv");
MB_PRETTY(begin_name, "5beginENS_9InputModeENS_9BeginModeE");
MB_PRETTY(vertexAt_name, "8vertexAtEiNS_8PositionE");
MB_PRETTY(vertexAt3_name, "8vertexAtEifff");
extern const char D_0016DCE8[];     /* "_mesh.locked()" */
extern const char D_0016E06C[];     /* "_var._input_mode == INDEXED" */
#define CHECK_BSPLINE(fn, line) MB_ASSERT(_var._write_primitive == 4, D_0016DE60, fn, line)
unsigned int math_max_u(unsigned int, unsigned int) __asm__("_ZN4math4max_IjEET_S1_S1_");

extern const float D_0016DB84;
namespace std {
extern template vector<bool> &vector<bool>::operator=(const vector<bool> &);
extern template vector<float> &vector<float>::operator=(const vector<float> &);
extern template vector<math::vector_xyzw> &vector<math::vector_xyzw>::operator=(const vector<math::vector_xyzw> &);
}
namespace common {
extern template class t_array<sgl::Position>;
extern template class t_array2d<sgl::Position>;
}
extern const float D_0016DBB0;      /* 1.0f */
extern const float D_0016DBB4;      /* 1.0f */

extern const float D_0016DBA0;      /* degrees -> radians */
extern const float D_0016DBA4;      /* degrees -> radians */
extern const float D_0016DBE8;      /* 1.0f */

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _Z41__static_initialization_and_destruction_0ii_C17C4);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12extruded_varC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12extruded_varC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder12extruded_var5resetEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder9begin_varC2ENS_9InputModeENS_9BeginModeE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder9begin_varC1ENS_9InputModeENS_9BeginModeE);

void sgl::MeshBuilder::begin_var::reset()
{
    *this = begin_var(InputMode(0), BeginMode(0));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderC2ERNS_4MeshEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderC1ERNS_4MeshEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilderD0Ev);

void sgl::MeshBuilder::grey(float g)
{
    color(g, g, g, 0);
}

void sgl::MeshBuilder::begin(InputMode im, BeginMode bm)
{
    MB_ASSERT(_mesh.locked(), D_0016DCE8, begin_name, 106);
    _var = begin_var(im, bm);
    _mesh.unlock();
    _mesh.snap_offsets();
}

void sgl::MeshBuilder::begin(BeginMode bm)
{
    begin(InputMode(1), bm);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder3endEv);

void sgl::MeshBuilder::normal(Normal n)
{
    switch (_var._write_primitive) {
    case 0:
        break;
    case 1:
        _var._normal.set(n);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void sgl::MeshBuilder::normal(float x, float y, float z)
{
    normal(Normal(x, y, z));
}

void sgl::MeshBuilder::color(Color c)
{
    switch (_var._write_primitive) {
    case 1:
        _var._color.set(c);
        break;
    case 2:
    case 3:
        _var._color.set(c);
        _ext._lineset.color(c);
        break;
    }
}

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder7color_iEj);

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder7colorGiEj);

void sgl::MeshBuilder::texcoord(TexCoord t)
{
    switch (_var._write_primitive) {
    case 0:
        break;
    case 1:
        _var._texcoord.set(t);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void sgl::MeshBuilder::texcoord(float u, float v)
{
    texcoord(TexCoord(u, v));
}

void sgl::MeshBuilder::vertex(Position p)
{
    vertex(p.x, p.y, p.z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6vertexEfff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6vertexEi);

void sgl::MeshBuilder::triangle(int a, int b, int c)
{
    vertex(a);
    vertex(b);
    vertex(c);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6quad_tEiiiib);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK3sgl11MeshBuilder16transform_normalERKNS_6NormalE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK3sgl11MeshBuilder18transform_positionERKNS_8PositionE);

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

void sgl::MeshBuilder::extrusionBegin(LineMode m)
{
    _ext._lineset.begin(m);
    if (_colorG.valid)
        _ext._lineset.color(_colorG.value);
}

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
    _ext._lineset.set_crease(a * D_0016DBA0);
}

void sgl::MeshBuilder::transformListSetCreaseAngle(float a)
{
    _ext._tset.set_crease(a * D_0016DBA4);
}

void sgl::MeshBuilder::transformListBegin()
{
    _ext._tset.clear();
}

void sgl::MeshBuilder::transformListSnap()
{
    _ext._tset.add(getTransform());
}

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder7revolveERKNS0_12extruded_varE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5sweepERKNS0_12extruded_varE);

sgl::MeshBuilder::spline_var::spline_var()
    : _count(0), _tessU(16), _tessV(16), _closeU(false), _closeV(false), _flipS(false), _flipT(false),
      _texcoord(true), _normals(true)
{
}

void sgl::MeshBuilder::splineSetDim(unsigned int nx, unsigned int ny)
{
    CHECK_BSPLINE(splineSetDim_name, 761);
    _spline._ctrl.resize(nx, ny);
}

void sgl::MeshBuilder::splineControlPoint(float x, float y, float z)
{
    splineControlPoint(Position(x, y, z, D_0016DBB0));
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder18splineControlPointENS_8PositionE);

void sgl::MeshBuilder::splineControlPoint(float x, float y, float z, unsigned int u, unsigned int v)
{
    splineControlPoint(Position(x, y, z, D_0016DBB4), u, v);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder18splineControlPointENS_8PositionEjj);

void sgl::MeshBuilder::splineTesselateU(unsigned int n)
{
    CHECK_BSPLINE(splineTesselateU_name, 802);
    _spline._tessU = math_max_u(1, n);
}

void sgl::MeshBuilder::splineTesselateV(unsigned int n)
{
    CHECK_BSPLINE(splineTesselateV_name, 809);
    _spline._tessV = math_max_u(1, n);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10spline_var5resetEv);

void sgl::MeshBuilder::splineCloseU(bool b)
{
    CHECK_BSPLINE(splineCloseU_name, 821);
    _spline._closeU = b;
}

void sgl::MeshBuilder::splineCloseV(bool b)
{
    CHECK_BSPLINE(splineCloseV_name, 828);
    _spline._closeV = b;
}

void sgl::MeshBuilder::splineFlipS(bool b)
{
    CHECK_BSPLINE(splineFlipS_name, 835);
    _spline._flipS = b;
}

void sgl::MeshBuilder::splineFlipT(bool b)
{
    CHECK_BSPLINE(splineFlipT_name, 842);
    _spline._flipT = b;
}

void sgl::MeshBuilder::splineEnableTexCoord(bool b)
{
    _spline._texcoord = b;
}

void sgl::MeshBuilder::splineEnableNormals(bool b)
{
    _spline._normals = b;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10end_splineEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5arrowEffff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10cubeDirectEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder11cubeIndexedEv);

void sgl::MeshBuilder::normalAt(int i, float x, float y, float z)
{
    normalAt(i, Normal(x, y, z));
}

void sgl::MeshBuilder::normalAt(int i, Normal n)
{
    _mesh.normalAt(i, transform_normal(n));
}

void sgl::MeshBuilder::colorAt(int i, float r, float g, float b, float a)
{
    colorAt(i, Color(r, g, b, a));
}

void sgl::MeshBuilder::colorAt(int i, Color c)
{
    _mesh.colorAt(i, transform_color(c));
}

void sgl::MeshBuilder::texcoordAt(int i, float u, float v)
{
    texcoordAt(i, TexCoord(u, v));
}

void sgl::MeshBuilder::texcoordAt(int i, TexCoord t)
{
    _mesh.texcoordAt(i, transform_texcoord(t));
}

void sgl::MeshBuilder::positionAt(int i, float x, float y, float z)
{
    positionAt(i, Position(x, y, z, D_0016DBE8));
}

void sgl::MeshBuilder::positionAt(int i, Position p)
{
    _mesh.positionAt(i, transform_position(p));
}

void sgl::MeshBuilder::vertexAt(int i, int p)
{
    vertexAt(i, p, -1, -1, -1);
}

void sgl::MeshBuilder::vertexAt(int i, Position p)
{
    MB_ASSERT(_var._input_mode == 2, D_0016E06C, vertexAt_name, 1328);
    positionAt(i, p);
    vertexAt(i, i, -1, -1, -1);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder8vertexAtEifff);

void sgl::MeshBuilder::vertexAt(int i, int p, int n, int c, int t)
{
    _mesh.vertexAt(i, p, n, c, t);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder6sphereEfiiff);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder8cylinderEffii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder4coneEffii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder3boxEfffb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder4gridEjjffffb);

void sgl::MeshBuilder::setParams(const MeshParams &p)
{
    static_cast<MeshParams &>(*this) = p;
}

void sgl::MeshBuilder::finish()
{
    MB_ASSERT(!_finished_called, D_0016E0E4, finish_name, 1652);
    _finished_called = true;
    if (!_fB4)
        _mesh.finish(*this);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_C17C4");
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

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIN3sgl7LineSet4LineESaIS2_EEaSERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EEaSERKS4_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEEC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE6resizeEjj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common9t_array2dIN3sgl8PositionEE2nxEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common9t_array2dIN3sgl8PositionEE2nyEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN4math4max_IjEET_S1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE2atEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN4math4max_IiEET_S1_S1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIbSaIbEEaSERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIfSaIfEEaSERKS1_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNSt6vectorIN4math11vector_xyzwESaIS1_EEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEED2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEEC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE6resizeEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE4addrEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEEaSERKS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl7LineSet4LineESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl12TransformSet9TransformESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE8allocateEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEED1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEED0Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE4swapERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE7releaseEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEE4fillERKS2_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE4swapERS3_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE7resizexEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE7resizeyEj);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common9t_array2dIN3sgl8PositionEE4copyERKS3_iiiiii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common4SwapINS_7t_arrayIN3sgl8PositionEE7MembersEEEvRT_S7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common4SwapINS_9t_array2dIN3sgl8PositionEE3DimEEEvRT_S7_);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common9t_array2dIN3sgl8PositionEE2atEii);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZNK6common7t_arrayIN3sgl8PositionEE4addrEv);

