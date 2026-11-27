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

/* assert macro of the demo's library (common/assert): __PRETTY_FUNCTION__ is an extern label */
#define SGL_ASSERT(c, err, text, file, fn, line, sep) \
    if (!(c)) { \
        common::common_internal::assert_display(err, text, file, fn, line, sep); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    }

namespace sgl {
/* stand-in until demo/math.hpp declares math::area */
float sgl_math_area(math::vector_xyzw, math::vector_xyzw, math::vector_xyzw) __asm__("_ZN4math4areaENS_11vector_xyzwES0_S0_");
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
enum VertexAttrEnum { POS, NOR, COL, TEX };
enum InputMode { };
enum BeginMode { };
enum LineMode { };
/* units whose .rodata can't be C define SGL_POSITION_ONE as an extern 1.0f */
#ifndef SGL_POSITION_ONE
#define SGL_POSITION_ONE 1
#endif
struct Position : math::vector_xyzw {
    Position() : math::vector_xyzw(0, 0, 0, SGL_POSITION_ONE) {}
    Position(float x, float y, float z, float w) : math::vector_xyzw(x, y, z, w) {}
};
struct Normal : math::vector_xyzw {
    Normal() : math::vector_xyzw(0, 0, 0, 0) {}
    Normal(float x, float y, float z) : math::vector_xyzw(x, y, z, 0) {}
};
/* sgl::Color: demo/math.hpp */
struct TexCoord : math::vector_xyzw {
    TexCoord()
    {
        x = 0;
        y = 0;
    }
    TexCoord(float u, float v)
    {
        x = u;
        y = v;
    }
};
struct Triangle {
    int operator[](int i) const { return v[i & 3]; }
    int edge(int i) const { return e[i & 3]; }
    int v[3];
    int e[3];
};
struct Vertex {
    Vertex()
    {
        _attr[POS] = -1;
        _attr[NOR] = -1;
        _attr[COL] = -1;
        _attr[TEX] = -1;
    }
    Vertex(int p, int n, int c, int t)
    {
        _attr[POS] = p;
        _attr[NOR] = n;
        _attr[COL] = c;
        _attr[TEX] = t;
    }
    int _attr[4];
    bool operator<(const Vertex &) const;
};
struct Edge {
    Edge(int, int, int, int);
    int numAdjacentTriangles() const;
    void order();
    int vertex(int i) const { return v[i & 1]; }
    int triangle(int i) const { return t[i & 1]; }
    int t[2];
    int v[2];
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
    Position getVertexPosition(int) const;
    Normal getVertexNormal(int) const;
    Color getVertexColor(int) const;
    TexCoord getVertexTexCoord(int) const;
    void print(std::string) const;
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
/* lib/sgl/VarlenListsList.h */
class VarlenListsList {
public:
    struct List {
        unsigned int _head;
        unsigned int _size;
        unsigned int _cur;
    };
    void reset();
    void freeze();
    void clear(unsigned int _List);
    void add(unsigned int _List, int);
    unsigned int _n;
    std::vector<List> _lists;   /* 0x04 */
    std::vector<int> _data;     /* 0x10 */
};
math::vector_xyzw ProjectOnPlane(const math::vector_xyzw &, const math::vector_xyzw &, const math::vector_xyzw &);
struct StencilShadowData;
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
    void print_positions();
    void print_vertices();
    void print_triangles();
    template<class V, class T> void setAt(unsigned int, V &, T);
    const std::vector<Triangle> &getTriangles() const;
    const std::vector<Edge> &getEdges() const;
    const std::vector<Normal> &getTrianglesNormals() const;
    float triangleArea(int) const;
    float triangleEdgeLenght(int, int) const;
    void getTriangleEdgeIndex(int, int &, int &, int &) const;
    int getTriangleEdgeIndex(int, int) const;
    void getTriangleVertexIndex(int, int &, int &, int &) const;
    int getTriangleVertexIndex(int, int) const;
    void getTriangleVertexAttributeIndex(int, VertexAttrEnum, int &, int &, int &) const;
    void getTriangleVertexPosition(int, Position &, Position &, Position &) const;
    void getTriangleVertexColor(int, Color &, Color &, Color &) const;
    void getTriangleVertexNormal(int, Normal &, Normal &, Normal &) const;
    void getTriangleVertexTexCoord(int, TexCoord &, TexCoord &, TexCoord &) const;
    Position getTriangleVertexPosition(int, int) const;
    Normal getTriangleVertexNormal(int, int) const;
    Color getTriangleVertexColor(int, int) const;
    TexCoord getTriangleVertexTexCoord(int, int) const;
    Normal getTriangleNormal(int) const;
    int getEdgePositionIndex(int, int) const;
    int getEdgeVertexIndex(int, int) const;
    void getEdgeVertexIndex(int, int &, int &) const;
    int getEdgeTriangleIndex(int, int) const;
    void getEdgeVertexPosition(int, Position &, Position &) const;
    Position calcTriangleCenter(int) const;
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
    void reverseVerticesNormals();
    static void calcStencilShadowData(StencilShadowData &, const CoreMesh &);
    Offsets _offsets;                   /* 0x5C */
    bool _locked;                       /* 0x74 */
    std::vector<Triangle> _triangles;   /* 0x78 */
    std::vector<Edge> _edges;           /* 0x84 */
    std::vector<Normal> _tnormals;      /* 0x90 */
    bool _f9C;
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
    Icosahedron(unsigned char);
    ~Icosahedron();
    bool getDepth() const;
    /* data */
    bool _f0;
    char _p1[0x2C - 1];
};

namespace sh {
common::common_internal::Log &Log_uint(common::common_internal::Log &, unsigned int) __asm__("_ZN6common15common_internal3LoglsEj");
class SphereSampling : public Icosahedron {
public:
    struct Sample : public math::SphericalCoord {
        Sample();
        Vector sh;                      /* 0x18 */
    };
    SphereSampling(unsigned int);
    void swap(SphereSampling &);
    void create_samples(int);
    void partition();
    void precalc_sh_coeffs();
    std::vector<Sample> _samples;       /* 0x2C */
};
}

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
    char _pE5[0x14C - 0xE5];
};
class BV;
class Frustum {
public:
    bool intersect(BV &);
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

/* sh::Args::Env, sh::Env, sh::TestEnvSet (declarations maintained by cxx-apps3) */
namespace sh {
namespace Args {
struct Env {
    enum Type { };
    Type type;                  /* 0x00 */
    std::string name;           /* 0x04 */
    float exposure;             /* 0x08 */
    int _fC;
    int _f10;
    float _f14;
    int _f18;
    int _f1C;
    float _f20;
    std::string dir;            /* 0x24 */
    bool _f28;
    float cube_size;            /* 0x2C */
    float _f30;
    float _f34;
    float _f38;
};
}
class Env {
public:
    Env(Args::Env);
    ~Env();
    void draw(bool);
    bool load(bool);
    Args::Env _args;            /* 0x000 */
    VectorRGB _sh;              /* 0x03C */
    CubeMap _cube;              /* 0x06C */
    CubeMap _cube_blur;         /* 0x2D8 */
};
class TestEnvSet {
public:
    enum EnvEnum { };
    enum { MAX_ENV = 7 };
    class TestEnv : public common::shared_object_base {
    public:
        TestEnv(EnvEnum, Args::Env);
        virtual ~TestEnv() {}
        void load();
        Env _env;               /* 0x008 */
        EnvEnum _type;          /* 0x54C */
        bool _loaded;           /* 0x550 */
    };
    TestEnvSet(Args::Env, EnvEnum);
    void load();
    void next();
    void draw(bool);
    std::vector<common::handle<TestEnv> > _lights;  /* 0x0 */
    int _current_light;                             /* 0xC */
};
}

#endif
