/* sgl:: and sh:: */
#ifndef DEMO_DUCK_DEMO_SGL_HPP
#define DEMO_DUCK_DEMO_SGL_HPP

/* Weak instances (inline virtual destructors, templates) that stay asm in a unit whose static
   initializer is C++: cc1plus emits them after _GLOBAL__I/D, so their asm goes to .text's
   subsection 1 (see WaterPatch.c), from top-level asm (no wrapper function: a function in another
   section makes cc1plus put the float constants in .rodata instead of .rodata.cst4). */
#if defined(M2CTX) || defined(PERMUTER)
#define INCLUDE_ASM_WEAK(FOLDER, NAME)
#else
#define INCLUDE_ASM_WEAK(FOLDER, NAME) \
    __asm__(".text 1\n" \
            "    .set noat\n" \
            "    .set noreorder\n" \
            "    .include \"" FOLDER "/" #NAME ".s\"\n" \
            "    .set reorder\n" \
            "    .set at\n" \
            ".text\n")
#endif

namespace sh {
class TestEnvSet {
public:
    void load();
};
}

/* assert macro of the demo's library (common/assert): __PRETTY_FUNCTION__ is an extern label */
#define SGL_ASSERT(c, err, text, file, fn, line, sep) \
    if (!(c)) { \
        common::common_internal::assert_display(err, text, file, fn, line, sep); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

namespace sgl {
class Heap {
public:
    struct Element {
        float value;
        int id;
        int data;
    };
    Heap();
    ~Heap();
    void clear();
    void resize(int);
    void set_element(unsigned int, int, float);
    void change_value(unsigned int, float);
    void swap(int, int);
    void downheap(int, int);
    void upheap(int);
    float value(int) const;
    void update(int);
    void remove(int);
    void pop();
    void heapify();
    void sort();
    int check_heapify();
    void dump();
    int check_sort();
    static void Test();
    int *_index;
    Element *_e;
    int _n;
    bool _heap;
};
enum VertexAttrEnum { };
enum InputMode { };
enum BeginMode { };
enum LineMode { };
struct Position : math::vector_xyzw {
    Position() {}
    Position(float x, float y, float z, float w) : math::vector_xyzw(x, y, z, w) {}
};
struct Normal : math::vector_xyzw {
    Normal() {}
    Normal(float x, float y, float z) : math::vector_xyzw(x, y, z, 0) {}
};
/* sgl::Color: demo/math.hpp */
struct TexCoord : math::vector_xyzw {
    TexCoord() {}
    TexCoord(float u, float v)
    {
        x = u;
        y = v;
    }
};
struct Triangle {
    int v[3];
    int e[3];
};
struct Vertex {
    int position, normal, color, texcoord;
    bool operator<(const Vertex &) const;
};
struct Edge {
    Edge(int, int, int, int);
    int numAdjacentTriangles() const;
    void order();
    int t0, t1;
    int v0, v1;
};
/* an attribute value and whether it was given */
template<class T> struct Attr {
    Attr() {}
    Attr(float a, float b) : value(a, b), valid(false) {}
    Attr(float a, float b, float c) : value(a, b, c), valid(false) {}
    Attr(float a, float b, float c, float d) : value(a, b, c, d), valid(false) {}
    void set(const T &v)
    {
        value = v;
        valid = true;
    }
    T value;
    bool valid;
};

template<class T> class PrimitiveIndex {
public:
    PrimitiveIndex();
    void clear();
    std::vector<T> a;
    std::vector<T> b;
    int n;
};

class CoreMesh {
public:
    CoreMesh();
    virtual ~CoreMesh();
    const std::vector<Position> &getPositions() const;
    const std::vector<Normal> &getNormals() const;
    const std::vector<Color> &getColors() const;
    const std::vector<TexCoord> &getTexCoords() const;
    const std::vector<Vertex> &getVertices() const;
    const PrimitiveIndex<int> &getPrims() const;
    std::vector<Position> &getPositions();
    std::vector<Normal> &getNormals();
    std::vector<Color> &getColors();
    std::vector<TexCoord> &getTexCoords();
    std::vector<Vertex> &getVertices();
    PrimitiveIndex<int> &getPrims();
    void clear();
    int getVertexAttributeIndex(int, VertexAttrEnum) const;
    void setVertexAttributeIndex(int, VertexAttrEnum, int);
    int getVertexPositionIndex(int) const;
    std::vector<Position> _positions;   /* 0x04 */
    std::vector<Normal> _normals;       /* 0x10 */
    std::vector<Color> _colors;         /* 0x1C */
    std::vector<TexCoord> _texcoords;   /* 0x28 */
    std::vector<Vertex> _vertices;      /* 0x34 */
    PrimitiveIndex<int> _prims;         /* 0x40 */
};

enum ParamsBool { };
enum ParamsInt { };
enum ParamsFloat { };
enum ParamsFloat4 { };
class MeshParams {
public:
    MeshParams();
    void reset();
    void set0(float);
    void set(ParamsBool, bool);
    bool get(ParamsBool) const;
    void set(ParamsInt, int);
    int get(ParamsInt) const;
    void set(ParamsFloat, float);
    float get(ParamsFloat) const;
    void set(ParamsFloat4, math::vector_xyzw);
    void set(ParamsFloat4, float, float, float, float);
    math::vector_xyzw get(ParamsFloat4) const;
    std::vector<bool> _bools;
    std::vector<int> _ints;                 /* 0x14 */
    std::vector<float> _floats;             /* 0x20 */
    std::vector<math::vector_xyzw> _float4s; /* 0x2C */
};
class Mesh : public CoreMesh {
public:
    struct Offsets {
        Offsets();
        int _f0;
        int position, normal, color, texcoord, vertex;
    };
    Mesh(bool);
    virtual ~Mesh();
    virtual void normalAt(int, Normal);
    virtual void colorAt(int, Color);
    virtual void texcoordAt(int, TexCoord);
    virtual void positionAt(int, Position);
    virtual void vertexAt(int, int, int, int, int);
    virtual void pushBackTriangle(Triangle);
    virtual void finish(const MeshParams &);
    void unlock();
    void lock();
    bool locked() const;
    int internal_position_index(int) const;
    int internal_normal_index(int) const;
    int internal_color_index(int) const;
    int internal_texcoord_index(int) const;
    int internal_vertex_index(int) const;
    void snap_offsets();
    template<class V, class T> void setAt(unsigned int, V &, T);
    const std::vector<Triangle> &getTriangles() const;
    const std::vector<Edge> &getEdges() const;
    const std::vector<Normal> &getTrianglesNormals() const;
    int getEdgeVertexIndex(int, int) const;
    int getEdgeVertexAttributeIndex(int, int, VertexAttrEnum) const;
    void removeUsusedPositions();
    void removeUsusedNormals();
    void removeUsusedColors();
    void removeUsusedTexCoords();
    template<class V, class T> void removeUsusedAttributes(VertexAttrEnum, V &);
    template<class V, class T> void quantizeVertexAttribute(VertexAttrEnum, V &, unsigned int, bool, float);
    void quantizePositions(bool, float);
    void quantizeTexCoords(bool, float);
    void quantizeColors(bool, float);
    void quantizeNormals(bool, float);
    void discardColors();
    void discardNormals();
    void discardTexCoords();
    void reverseTrianglesVertices();
    Offsets _offsets;                   /* 0x5C */
    bool _locked;                       /* 0x74 */
    std::vector<Triangle> _triangles;   /* 0x78 */
    std::vector<Edge> _edges;           /* 0x84 */
    std::vector<Normal> _tnormals;      /* 0x90 */
    int _f9C;
};

class LineSet {
public:
    LineSet();
    void end();
    bool ready() const;
    void set_negate_normals(bool);
    void set_crease(float);
    char _p0[0x75];
    bool _negate_normals;   /* 0x75 */
    float _crease;          /* 0x78 */
    char _p7C[0xC];
    int _state;             /* 0x88 */
};

class TransformSet {
public:
    class Transform {
    public:
        Transform();
        Transform(math::matrix);
        math::matrix m;
    };
    TransformSet();
    void add(math::matrix);
    void clear();
    void set_crease(float);
    std::vector<Transform> _transforms;
    bool _closed;           /* 0x0C */
    float _crease;          /* 0x10 */
};

class MeshBuilder {
public:
    struct begin_var {
        begin_var(InputMode, BeginMode);
        void reset();
        int _write_primitive;       /* BeginMode */
        int _input_mode;            /* InputMode */
        int _f8, _fC, _f10;
        struct Indices {
            Indices() : a(-1), b(-1), c(-1), d(-1), e(-1), f(-1) {}
            int a, b, c, d, e, f;
        } _indices;                 /* 0x14 */
        Attr<Color> _color;         /* 0x2C */
        Attr<Normal> _normal;       /* 0x40 */
        Attr<TexCoord> _texcoord;   /* 0x54 */
    };
    struct extruded_var {
        extruded_var();
        void reset();
        LineSet _lineset;
        TransformSet _tset;         /* 0x8C */
        int _slices;                /* 0xA0 */
        float _start_angle;         /* 0xA4 */
        float _end_angle;           /* 0xA8 */
    };
    struct spline_var {
        spline_var();
        void reset();
        common::t_array2d<Position> _ctrl;
        int _count;                 /* 0x28 */
        unsigned int _tessU, _tessV;
        bool _closeU, _closeV, _flipS, _flipT;
        bool _texcoord;             /* 0x38 */
        bool _normals;              /* 0x39 */
    };
    virtual ~MeshBuilder();
    void grey(float);
    void normal(Normal);
    void normal(float, float, float);
    void color(Color);
    void color(float, float, float, float);
    void color(float, float);
    void color(float);
    void colorG(Color);
    void colorG(float, float, float, float);
    void colorG(float, float);
    void colorG(float);
    void texcoord(TexCoord);
    void texcoord(float, float);
    void vertex(Position);
    void vertex(float, float, float);
    void vertex(int);
    void triangle(int, int, int);
    Normal transform_normal(const Normal &) const;
    Position transform_position(const Position &) const;
    Color transform_color(const Color &) const;
    TexCoord transform_texcoord(const TexCoord &) const;
    void revolutionSlices(int);
    void revolutionStartAngle(float);
    void revolutionEndAngle(float);
    void extrusionEnd();
    void extrusionReverseNormals(bool);
    void extrusionCreaseAngle(float);
    void transformListSetCreaseAngle(float);
    void transformListBegin();
    void transformListEnd();
    void transformListClose(bool);
    void end_revolution();
    void end_sweep();
    void revolve(const extruded_var &);
    void sweep(const extruded_var &);
    void splineControlPoint(float, float, float);
    void splineControlPoint(Position);
    void splineControlPoint(float, float, float, unsigned int, unsigned int);
    void splineControlPoint(Position, unsigned int, unsigned int);
    void splineEnableTexCoord(bool);
    void splineEnableNormals(bool);
    void normalAt(int, float, float, float);
    void normalAt(int, Normal);
    void colorAt(int, float, float, float, float);
    void colorAt(int, Color);
    void texcoordAt(int, float, float);
    void texcoordAt(int, TexCoord);
    void positionAt(int, float, float, float);
    void positionAt(int, Position);
    void vertexAt(int, int);
    void vertexAt(int, Position);
    void vertexAt(int, float, float, float);
    void vertexAt(int, int, int, int, int);
    char _p4[0xB0 - 4];
    Mesh *_mesh;                /* 0xB0 */
    char _pB4[4];
    begin_var _var;             /* 0xB8 */
    extruded_var _ext;          /* 0x120 */
    spline_var _spline;         /* 0x1CC */
    Attr<Color> _colorG;        /* 0x208 */
};
}

/* <iostream> would add an ios_base::Init to every unit's static initializer */
namespace std {
extern ostream cout;
}

/* math::SH::Eval (stand-in until demo/math.hpp declares it) */
namespace sh {
float SH_Eval(int l, int m, float theta, float phi) __asm__("_ZN4math2SH4EvalEiiff");
enum { BANDS = 2, COEFFS = 4 };
class Vector {
public:
    Vector()
    {
        v[0] = 0;
        v[1] = 0;
        v[2] = 0;
        v[3] = 0;
    }
    float &operator[](int i) { return v[i]; }
    const float &operator[](int i) const { return v[i]; }
    void print(const char *) const;
    float eval(float, float, int) const;
    float v[COEFFS];
};
class VectorRGB {
public:
    VectorRGB() {}
    VectorRGB(const Vector &r_, const Vector &g_, const Vector &b_) : r(r_), g(g_), b(b_) {}
    void print(const char *) const;
    void eval(float, float, float &, float &, float &) const;
    void save(const char *);
    void load(const char *);
    Vector r, g, b;
};
class Matrix {
public:
    Matrix();
    static const Matrix &Identity();
    Vector operator*(const Vector &) const;
    Matrix transpose() const;
    bool equal(Matrix, float) const;
    void print(bool) const;
    float m[COEFFS][COEFFS];
};
class RotMatrix : public Matrix {
public:
    RotMatrix();
    RotMatrix(math::matrix);
    static RotMatrix TwoBands(math::matrix);
    float at(int l, int m, int n) const __attribute__((noinline));
    RotMatrix &operator=(const Matrix &);
    Vector operator*(const Vector &) const;
    VectorRGB operator*(const VectorRGB &) const;
    int _f40, _f44, _f48;
};
namespace sh_rot {
extern float Rmn[3][3];
void setRmn(math::matrix);
float R(int, int);
float P(int, int, int, int, RotMatrix &);
float U(int, int, int, RotMatrix &);
float V(int, int, int, RotMatrix &);
float W(int, int, int, RotMatrix &);
void uvw(float &, float &, float &, int, int, int);
float M(int, int, int, RotMatrix &);
}
class SphericalRGBFn {
public:
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const = 0;
    virtual ~SphericalRGBFn() {}
};
/* stand-ins until demo/base.hpp / demo/math.hpp declare them */
common::common_internal::Log &Log_float(common::common_internal::Log &, float) __asm__("_ZN6common15common_internal3LoglsEf");
float math_wrap(float, float, float) __asm__("_ZN4math4wrapEfff");
int math_min_i(int, int) __asm__("_ZN4math4min_IiEET_S1_S1_");
class SquareMap : public SphericalRGBFn {
public:
    SquareMap(const char *, float);
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~SquareMap() {}
    void load(const char *);
    mutable textures::Texture _tex;     /* 0x04 */
    char _p54[4];
    float _exposure;                    /* 0x58 */
};
class PolarFunction : public SphericalRGBFn {
public:
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~PolarFunction() {}
    virtual float eval(float theta, float phi) const = 0;
};
class PRT {
public:
    void import_model();
};
}

/* accessors (generated from the asm; members named by offset) */
class Icosahedron {
public:
    class Bin {
    public:
        void setBinIndex(unsigned int);
        int getBinIndex() const;
        void setLeafIndex(unsigned int);
        /* data */
        char _p0[0x90];
        int _f90;
        int _f94;
    };
    bool getDepth() const;
    /* data */
    bool _f0;
};

/* accessors (generated from the asm; members named by offset) */
namespace sgl {
class Box {
public:
    Box();
    Box(math::vector_xyzw, math::vector_xyzw);
    void first(math::vector_xyzw);
    void add(math::vector_xyzw);
    void finish();
    float volume() const;
    void draw(int) const;
    void draw() const;
    char _p0[0x80];
};
class BV : public Box {
public:
    enum Type { };
    BV();
    void setType(sgl::BV::Type);
    void start();
    void add(math::vector_xyzw);
    void add(const BV &, const math::matrix &);
    void add(float, float, float);
    void add(const BV &);
    void finish();
    void draw() const;
    void draw(int) const;
    int _type;              /* 0x80 */
    char _p84[0xE4 - 0x84];
    bool _started;          /* 0xE4 */
};
class Frustum {
public:
    void enable();
    void disable();
    void get(float &, float &, float &, float &, float &, float &) const;
    float getFov() const;
    float getZnear() const;
    float getZfar() const;
    float getZmin() const;
    float getZmax() const;
    float getWidth() const;
    float getHeight() const;
    float getLeft() const;
    float getRight() const;
    float getBottom() const;
    float getTop() const;
    /* data */
    char _p0[0x8];
    bool _f8;
    char _p9[0x3];
    float _fC;
    float _f10;
    float _f14;
    float _f18;
    float _f1C;
    float _f20;
    float _f24;
    float _f28;
    float _f2C;
    float _f30;
    float _f34;
};
class RT : public Mesh {
public:
    RT();
    const void *getBVTree() const;
    const void *getMesh() const;
    void *getMesh();
    const math::vector_xyzw &getTestLight() const;
    void setTestLight(math::vector_xyzw);
    math::vector_xyzw _testLight;   /* 0xA0 */
    char _pB0[0xC];
    char _fBC;                      /* BVH */
};
}

#endif
