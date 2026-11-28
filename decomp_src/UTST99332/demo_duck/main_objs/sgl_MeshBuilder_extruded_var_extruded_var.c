/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
extern const float D_00170B5C;
#define SGL_POSITION_ONE D_00170B5C
#define DEMO_TEMPLATE_DEFS 1
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN3sgl11MeshBuilder12extruded_varC2Ev");
__asm__(".globl _GLOBAL__D__ZN3sgl11MeshBuilder12extruded_varC2Ev");

extern const char D_00170B8C[];     /* " *** error " */
extern const char D_00170BB8[];     /* "../lib/sgl/MeshBuilder.cpp" */
extern const char D_00170C60[];     /* " " */
extern const char D_00170D88[];     /* "_var._write_primitive == BSPLINE" */
extern const char D_0017100C[];     /* "! _finished_called" */
#define MB_ASSERT(c, text, fn, line) SGL_ASSERT(c, D_00170B8C, text, D_00170BB8, fn, line, D_00170C60)
#define MB_PRETTY(n, s) extern const char n[] __asm__("_ZZN3sgl11MeshBuilder" s "E19__PRETTY_FUNCTION__")
MB_PRETTY(splineControlPoint_name, "18splineControlPointENS_8PositionEjj");
MB_PRETTY(end_name, "3endEv");
MB_PRETTY(vertex3_name, "6vertexEfff");
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
extern const char D_00170C10[];
extern const char D_00170C84[];     /* "_var._local_vertex_count % 3 == 0" */
extern const char D_00170CA8[];     /* "! _mesh.locked()" */
extern const char D_00170CF0[];     /* "can't call vertex( ... ) in INDEXED mode" */
extern const char D_00170D44[];     /* "" */
extern const char D_00170B98[];     /* "_finished_called || _no_finish" */
extern const char D_00170BD4[];     /* "call to MeshBuilder::finish() forgotten" */
extern const char D_00170BFC[];     /* "missing end() call?" */
extern const char dtor_name[] __asm__("_ZZN3sgl11MeshBuilderD1EvE19__PRETTY_FUNCTION__");     /* "_mesh.locked()" */
extern const char D_00170F94[];     /* "_var._input_mode == INDEXED" */
#define CHECK_BSPLINE(fn, line) MB_ASSERT(_var._write_primitive == 4, D_00170D88, fn, line)
unsigned int math_max_u(unsigned int, unsigned int) __asm__("_ZN4math4max_IjEET_S1_S1_");

sgl::MeshBuilder::extruded_var::extruded_var() : _slices(32), _start_angle(0), _end_angle(6.28318548f)
{
}

void sgl::MeshBuilder::extruded_var::reset()
{
    *this = extruded_var();
}

sgl::MeshBuilder::begin_var::begin_var(InputMode im, BeginMode bm)
    : _write_primitive(bm), _input_mode(im), _f8(0), _fC(0), _f10(0), _color(0, 0, 0, 0), _normal(0, 0, 0), _texcoord(0, 0)
{
}

void sgl::MeshBuilder::begin_var::reset()
{
    *this = begin_var(InputMode(0), BeginMode(0));
}

sgl::MeshBuilder::MeshBuilder(Mesh &mesh, bool no_finish)
    : _fAC(0), _mesh(mesh), _fB4(no_finish), _finished_called(false), _var(InputMode(0), BeginMode(0)),
      _colorG(0, 0, 0, 0)
{
    _mesh.lock();
}

sgl::MeshBuilder::~MeshBuilder()
{
    SGL_ASSERT(_mesh.locked(), D_00170B8C, D_00170C10, D_00170BB8, dtor_name, 82, D_00170BFC);
    SGL_ASSERT(_finished_called || _fB4, D_00170B8C, D_00170B98, D_00170BB8, dtor_name, 85, D_00170BD4);
}

void sgl::MeshBuilder::grey(float g)
{
    color(g, g, g, 0);
}

void sgl::MeshBuilder::begin(InputMode im, BeginMode bm)
{
    MB_ASSERT(_mesh.locked(), D_00170C10, begin_name, 106);
    _var = begin_var(im, bm);
    _mesh.unlock();
    _mesh.snap_offsets();
}

void sgl::MeshBuilder::begin(BeginMode bm)
{
    begin(InputMode(1), bm);
}

void sgl::MeshBuilder::end()
{
    MB_ASSERT(!_mesh.locked(), D_00170CA8, end_name, 122);
    if (_var._write_primitive == 1)
        MB_ASSERT(_var._f8 % 3 == 0, D_00170C84, end_name, 126);
    _var._input_mode = InputMode(0);
    _mesh.lock();
    if (_var._write_primitive == 2)
        end_revolution();
    if (_var._write_primitive == 3)
        end_sweep();
    if (_var._write_primitive == 4)
        end_spline();
}

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

void sgl::MeshBuilder::color_i(unsigned int i)
{
    color(Color(0.2f + 0.2f * ((i >> 2) & 1) + 0.2f * ((i >> 3) & 1) + 0.2f * ((i >> 6) & 1),
                0.2f + 0.2f * ((i >> 1) & 1) + 0.2f * ((i >> 4) & 1) + 0.2f * ((i >> 7) & 1),
                0.2f + 0.2f * (i & 1) + 0.2f * ((i >> 5) & 1) + 0.2f * ((i >> 8) & 1), 0));
}

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

void sgl::MeshBuilder::colorGi(unsigned int i)
{
    colorG(Color(0.2f + 0.2f * ((i >> 2) & 1) + 0.2f * ((i >> 3) & 1) + 0.2f * ((i >> 6) & 1),
                 0.2f + 0.2f * ((i >> 1) & 1) + 0.2f * ((i >> 4) & 1) + 0.2f * ((i >> 7) & 1),
                 0.2f + 0.2f * (i & 1) + 0.2f * ((i >> 5) & 1) + 0.2f * ((i >> 8) & 1), 0));
}

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

void sgl::MeshBuilder::vertex(float x, float y, float z)
{
    if (_mesh.locked())
        return;
    switch (_var._write_primitive) {
    case 1:
        switch (_var._input_mode) {
        case 1: {
            int i = _var._f8;
            vertex(i);
            if (_var._normal.valid)
                normalAt(i, _var._normal.value);
            if (_var._color.valid)
                colorAt(i, _var._color.value);
            if (_var._texcoord.valid)
                texcoordAt(i, _var._texcoord.value);
            positionAt(i, x, y, z);
            break;
        }
        case 2:
            SGL_ASSERT(0, D_00170B8C, D_00170D44, D_00170BB8, vertex3_name, 317, D_00170CF0);
            break;
        }
        break;
    case 2:
    case 3:
        _ext._lineset.vertex(transform_position(Position(x, y, z, 1.0f)));
        break;
    }
}

void sgl::MeshBuilder::vertex(int i)
{
    if (_mesh.locked())
        return;
    switch (_var._write_primitive) {
    case 1: {
        int *tri = _var._indices.v;
        if (_var._input_mode == 1)
            vertexAt(i, i, _var._normal.valid ? i : -1, _var._color.valid ? i : -1, _var._texcoord.valid ? i : -1);
    {
        int k = _var._f10++;
        tri[k & 3] = _mesh.internal_vertex_index(i);
    }
        if (_var._f10 == 3) {
            _mesh.pushBackTriangle(_var._indices);
            _var._f10 = 0;
        }
        _fAC++;
        _var._f8++;
        break;
    }
    }
}

void sgl::MeshBuilder::triangle(int a, int b, int c)
{
    vertex(a);
    vertex(b);
    vertex(c);
}

void sgl::MeshBuilder::quad_t(int a, int b, int c, int d, bool flip)
{
    if (flip) {
        triangle(d, a, b);
        triangle(d, b, c);
    } else {
        triangle(a, b, c);
        triangle(a, c, d);
    }
}

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
    _ext._lineset.set_crease(a * 0.0174532924f);
}

void sgl::MeshBuilder::transformListSetCreaseAngle(float a)
{
    _ext._tset.set_crease(a * 0.0174532924f);
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

void sgl::MeshBuilder::revolve(const extruded_var &e)
{
    int n = e._slices;
    if (e._start_angle == e._end_angle || n < 1)
        return;
    float step = (e._end_angle - e._start_angle) / n;
    pushTransform();
    loadIdentity();
    transformListBegin();
    for (int i = 0; i < n + 1; i++) {
        transformListSnap();
        rotate(step, 0, 0, 1);
    }
    popTransform();
    sweep(e);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder5sweepERKNS0_12extruded_varE);

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
    splineControlPoint(Position(x, y, z, 1.0f));
}

void sgl::MeshBuilder::splineControlPoint(Position p)
{
    unsigned int v = _spline._count / _spline._ctrl.nx();
    unsigned int u = _spline._count - v * _spline._ctrl.nx();
    splineControlPoint(p, u, v);
    _spline._count++;
}

void sgl::MeshBuilder::splineControlPoint(float x, float y, float z, unsigned int u, unsigned int v)
{
    splineControlPoint(Position(x, y, z, 1.0f), u, v);
}

void sgl::MeshBuilder::splineControlPoint(Position p, unsigned int u, unsigned int v)
{
    CHECK_BSPLINE(splineControlPoint_name, 788);
    if (u >= _spline._ctrl.nx() || v >= _spline._ctrl.ny())
        _spline._ctrl.resize(math_max_u(_spline._ctrl.nx(), u + 1),
                             math_max_u(_spline._ctrl.ny(), v + 1));
    _spline._ctrl.at(u, v) = p;
}

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

void sgl::MeshBuilder::spline_var::reset()
{
    *this = spline_var();
}

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10end_splineEv);

void sgl::MeshBuilder::arrow(float len, float head, float r, float hr)
{
    begin(BeginMode(2));
    revolutionSlices(12);
    revolutionStartAngle(0);
    revolutionEndAngle(6.28318548f);
    extrusionBegin(LineMode(1));
    vertex(0, 0, len);
    float z = len - head;
    vertex(hr, 0, z);
    vertex(r, 0, z);
    vertex(r, 0, 0);
    vertex(0, 0, 0);
    extrusionEnd();
    pushTransform();
    translate(0, 0, 4);
    extrusionBegin(LineMode(1));
    vertex(0, 0, len);
    vertex(hr, 0, z);
    vertex(r, 0, z);
    vertex(r, 0, 0);
    vertex(0, 0, 0);
    extrusionEnd();
    popTransform();
    end();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder10cubeDirectEb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder11cubeIndexedEv);

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
    positionAt(i, Position(x, y, z, 1.0f));
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
    MB_ASSERT(_var._input_mode == 2, D_00170F94, vertexAt_name, 1328);
    positionAt(i, p);
    vertexAt(i, i, -1, -1, -1);
}

void sgl::MeshBuilder::vertexAt(int i, float x, float y, float z)
{
    MB_ASSERT(_var._input_mode == 2, D_00170F94, vertexAt3_name, 1337);
    positionAt(i, x, y, z);
    vertexAt(i, i, -1, -1, -1);
}

void sgl::MeshBuilder::vertexAt(int i, int p, int n, int c, int t)
{
    _mesh.vertexAt(i, p, n, c, t);
}

int math_max_i(int, int) __asm__("_ZN4math4max_IiEET_S1_S1_");
void sgl::MeshBuilder::sphere(float r, int slices, int stacks, float start, float stop)
{
    begin(BeginMode(2));
    if (_colorG.valid)
        color(_colorG.value);
    stacks = math_max_i(1, stacks);
    slices = math_max_i(1, slices);
    extrusionBegin(LineMode(1));
    extrusionReverseNormals(false);
    revolutionStartAngle(start);
    revolutionEndAngle(stop);
    revolutionSlices(slices);
    extrusionCreaseAngle(180);
    float a = 1.57079637f;
    float step = 180 * 0.0174532924f / stacks;
    for (int i = 0; i < stacks + 1; i++) {
        vertex(r * cosf(a), 0, r * sinf(a));
        a -= step;
    }
    extrusionEnd();
    end();
}

void sgl::MeshBuilder::cylinder(float r, float h, int slices, int stacks)
{
    begin(BeginMode(2));
    if (_colorG.valid)
        color(_colorG.value);
    stacks = math_max_i(1, stacks);
    slices = math_max_i(1, slices);
    extrusionBegin(LineMode(1));
    extrusionReverseNormals(false);
    revolutionStartAngle(0);
    revolutionEndAngle(6.28318548f);
    revolutionSlices(slices);
    extrusionCreaseAngle(60);
    float step = h / stacks;
    float d = 0;
    vertex(d, d, h * 0.5f);
    for (int i = 0; i < stacks + 1; i++) {
        vertex(r, 0, h * 0.5f + d);
        d -= step;
    }
    vertex(0, 0, -h * 0.5f);
    extrusionEnd();
    end();
}

void sgl::MeshBuilder::cone(float r, float h, int slices, int stacks)
{
    begin(BeginMode(2));
    if (_colorG.valid)
        color(_colorG.value);
    stacks = math_max_i(1, stacks);
    slices = math_max_i(1, slices);
    extrusionBegin(LineMode(1));
    extrusionReverseNormals(true);
    revolutionStartAngle(0);
    revolutionEndAngle(6.28318548f);
    revolutionSlices(slices);
    extrusionCreaseAngle(60);
    float d = 0;
    vertex(d, d, -h * 0.5f);
    for (int i = 0; i < stacks + 1; i++) {
        float t = (float)i / stacks;
        vertex((1 - t) * r, 0, -h * 0.5f + t * h);
    }
    extrusionEnd();
    end();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder3boxEfffb);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN3sgl11MeshBuilder4gridEjjffffb);

void sgl::MeshBuilder::setParams(const MeshParams &p)
{
    static_cast<MeshParams &>(*this) = p;
}

void sgl::MeshBuilder::finish()
{
    MB_ASSERT(!_finished_called, D_0017100C, finish_name, 1652);
    _finished_called = true;
    if (!_fB4)
        _mesh.finish(*this);
}

/* inline members / instances kept as asm: .gnu.linkonce.t (splat only sees `INCLUDE_ASM(`) */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/sgl_MeshBuilder_extruded_var_extruded_var", _ZN6common7t_arrayIN3sgl8PositionEEC2Ev);

/* the original's .gnu.linkonce.t order */
DEMO_LINKONCE_ORDER(DEMO_LINKONCE(_ZNSt6vectorIN3sgl7LineSet4LineESaIS2_EEaSERKS4_)
                    DEMO_LINKONCE(_ZNSt6vectorIN3sgl12TransformSet9TransformESaIS2_EEaSERKS4_)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEED1Ev)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEEC1Ev)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEE6resizeEjj)
                    DEMO_LINKONCE(_ZNK6common9t_array2dIN3sgl8PositionEE2nxEv)
                    DEMO_LINKONCE(_ZNK6common9t_array2dIN3sgl8PositionEE2nyEv)
                    DEMO_LINKONCE(_ZN4math4max_IjEET_S1_S1_)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEE2atEii)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEEaSERKS3_)
                    DEMO_LINKONCE(_ZN4math4max_IiEET_S1_S1_)
                    DEMO_LINKONCE(_ZNSt6vectorIbSaIbEEaSERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIfSaIfEEaSERKS1_)
                    DEMO_LINKONCE(_ZNSt6vectorIN4math11vector_xyzwESaIS1_EEaSERKS3_)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEED2Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEEC2Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEE6resizeEj)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEE4addrEv)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEEaSERKS3_)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl7LineSet4LineESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN3sgl12TransformSet9TransformESt6vectorIS4_SaIS4_EEEEPS4_ET0_T_SD_SC_12__false_type)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEE7releaseEv)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEE8allocateEj)
                    DEMO_LINKONCE(_ZSt24__uninitialized_copy_auxIN9__gnu_cxx17__normal_iteratorIPKN4math11vector_xyzwESt6vectorIS3_SaIS3_EEEEPS3_ET0_T_SC_SB_12__false_type)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEED0Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEED1Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEED0Ev)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEE4swapERS3_)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEE7releaseEv)
                    DEMO_LINKONCE(_ZN6common7t_arrayIN3sgl8PositionEE4fillERKS2_)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEE4swapERS3_)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEE7resizexEj)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEE7resizeyEj)
                    DEMO_LINKONCE(_ZN6common9t_array2dIN3sgl8PositionEE4copyERKS3_iiiiii)
                    DEMO_LINKONCE(_ZN6common4SwapINS_7t_arrayIN3sgl8PositionEE7MembersEEEvRT_S7_)
                    DEMO_LINKONCE(_ZN6common4SwapINS_9t_array2dIN3sgl8PositionEE3DimEEEvRT_S7_)
                    DEMO_LINKONCE(_ZNK6common9t_array2dIN3sgl8PositionEE2atEii)
                    DEMO_LINKONCE(_ZNK6common7t_arrayIN3sgl8PositionEE4addrEv));
namespace math {
template<class T> T max_(T, T);
}
extern "C" void t_array_Position_D0(void *) __asm__("_ZN6common7t_arrayIN3sgl8PositionEED0Ev");
extern "C" void t_array2d_Position_D0(void *) __asm__("_ZN6common9t_array2dIN3sgl8PositionEED0Ev");
/* t_array<Position>() stays asm (Position's default constructor schedules differently) */
namespace common {
extern template t_array<sgl::Position>::t_array();
}

extern "C" void sgl_MeshBuilder_extruded_var_extruded_var_instances(common::t_array2d<sgl::Position> *img, const sgl::Position *p, std::vector<sgl::LineSet::Line> *vl, std::vector<sgl::TransformSet::Transform> *vt, std::vector<bool> *vb, std::vector<float> *vf, std::vector<math::vector_xyzw> *vv, unsigned int n) __attribute__((section(".discard.asm")));
extern "C" void sgl_MeshBuilder_extruded_var_extruded_var_instances(common::t_array2d<sgl::Position> *img, const sgl::Position *p, std::vector<sgl::LineSet::Line> *vl, std::vector<sgl::TransformSet::Transform> *vt, std::vector<bool> *vb, std::vector<float> *vf, std::vector<math::vector_xyzw> *vv, unsigned int n)
{
    typedef common::t_array<sgl::Position> A;
    typedef common::t_array2d<sgl::Position> A2;
    const A2 *ci = img;
    *vl = *vl;
    *vt = *vt;
    A2 tmp;
    img->A2::resize(n, n);
    img->nx();
    img->ny();
    math::max_(n, n);
    img->at(n, n);
    *img = *img;
    math::max_((int)n, (int)n);
    *vb = *vb;
    *vf = *vf;
    *vv = *vv;
    img->A::resize(n);
    img->addr();
    img->A::operator=(*img);
    img->A::release();
    img->allocate(n);
    img->A2::~A2();
    t_array2d_Position_D0(img);
    img->A::~A();
    t_array_Position_D0(img);
    img->A::swap(*img);
    img->A2::release();
    img->A::fill(*p);
    img->A2::swap(*img);
    img->A2::resizex(n);
    img->A2::resizey(n);
    img->A2::copy(*img, n, n, n, n, n, n);
    ci->at(n, n);
    ci->addr();
}

namespace math {
template<class T> T max_(T a, T b)
{
    return a < b ? b : a;
}
}

/* the asm functions refer to the header statics by their module names */
__asm__("_ZN3sgl3REDE_190ABC = _ZN3sgl3REDE\n"
        "_ZN3sgl4BLUEE_190ADC = _ZN3sgl4BLUEE\n"
        "_ZN3sgl4CYANE_190B2C = _ZN3sgl4CYANE\n"
        "_ZN3sgl5BLACKE_190AEC = _ZN3sgl5BLACKE\n"
        "_ZN3sgl5GREENE_190ACC = _ZN3sgl5GREENE\n"
        "_ZN3sgl5WHITEE_190AFC = _ZN3sgl5WHITEE\n"
        "_ZN3sgl6YELLOWE_190B0C = _ZN3sgl6YELLOWE\n"
        "_ZN3sgl7MAGENTAE_190B1C = _ZN3sgl7MAGENTAE\n");
