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
    void check_sort();
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
    int &operator[](int i) { return v[i & 3]; }
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
    Edge(int = -1, int = -1, int = -1, int = -1);
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
    void swap(PrimitiveIndex &);
    void offset(unsigned int);
    void flatten();
    void unfold(std::vector<T> &);
    template<class U> PrimitiveIndex &operator=(const PrimitiveIndex<U> &);
    std::vector<T> &strips();
    const std::vector<T> &strips() const;
    std::vector<T> &tri();
    const std::vector<T> &tri() const;
    int countVertices() const;
    int countVerticesInStrips() const;
    int countTriangles() const;
    int countTrianglesInStrips() const;
    void range(int &, int &) const;
    bool check() const;
    std::vector<T> _strips;     /* 0x00 */
    std::vector<T> _tri;        /* 0x0C */
    int n;                      /* 0x18 */
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
    void setSize(unsigned int n)
    {
        _n = n;
        if (n)
            _lists.resize(n);
        else
            reset();
    }
    void incrSize(unsigned int _List, unsigned int n);
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
    void makePositionsAdjacentTrianglesLists(VarlenListsList &);
    int findTriangleEdge(int, int, int) const;
    bool cmpEdges(int, int, unsigned int);
    void print(std::string);
    bool searchCommonPosPair(int, int, int &, int &);
    void explodeTriangleVertices();
    void calc_initial_edges();
    static void calcStencilShadowData(StencilShadowData &, const CoreMesh &);
    void draw(unsigned int) const;
    Offsets _offsets;                   /* 0x5C */
    bool _locked;                       /* 0x74 */
    std::vector<Triangle> _triangles;   /* 0x78 */
    std::vector<Edge> _edges;           /* 0x84 */
    std::vector<Normal> _tnormals;      /* 0x90 */
    bool _finish;                       /* 0x9C */
};

class Stripper {
public:
    struct stripper_triangle {
        int _adj[3];                /* neighbour triangles */
        unsigned char _flags;       /* 0x0C */
        int _f10, _f14;
        int _untagged;              /* 0x18 */
        int _heap_id;               /* 0x1C */
    };
    void undo();
    void collect_triangles();
    void assert_valid_vertex_index(int);
    void assert_valid_edge_index(int);
    void assert_valid_triangle_index(int);
    void assert_valid_strip_index(int);
    int get_opposite_vertex(int, int);
    int get_common_edge(int, int);
    int count_untagged_neighbors(int);
    void path_tag_triangle(int);
    void reset_flags();
    void read_path(int, int *);
    void feed_strips();
    int count_strips();
    int get_adjacent_triangle(int, int);
    void add_index(int *, int, int);
    int cmp_orientation(int *, int *);
    void fix_cullface();
    void convert_to_new_format();
    Mesh &_mesh;
    std::vector<stripper_triangle> _tris;   /* 0x04 */
    unsigned int _size;                     /* 0x10 */
    int _max_length;                        /* 0x14 */
    bool _f18;
    Heap _heap;                             /* 0x1C */
    PrimitiveIndex<int> _prims;             /* 0x2C */
};

class LineSet {
public:
    struct Line {
        struct Vertex {
            Vertex();
            Position p;
            Normal n;               /* 0x10 */
            Normal m;               /* 0x20 */
        };
        bool zero_length() const;
        Vertex a;
        Vertex b;                   /* 0x30 */
        math::vector_xyzw c;        /* 0x60 */
    };
    LineSet();
    void begin(LineMode);
    void color(Color);
    void vertex(Position);
    void end();
    bool ready() const;
    void set_negate_normals(bool);
    void set_crease(float);
    void invert_normal_vectors();
    void calc_normal_vectors(float);
    int _f0;
    Color _color;           /* 0x04 */
    Line::Vertex _v0;       /* 0x14 */
    Line::Vertex _v1;       /* 0x44 */
    bool _f74;
    bool _negate_normals;   /* 0x75 */
    float _crease;          /* 0x78 */
    std::vector<Line> _lines;   /* 0x7C */
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

class MeshBuilder : public math::TransformStackFunc /* @0x4 */, public MeshParams /* @0x74 */ {
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
    void begin(InputMode, BeginMode);
    void begin(BeginMode);
    void end();
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
    void setParams(const MeshParams &);
    void transformListSnap();
    void extrusionBegin(LineMode);
    void finish();
    void splineSetDim(unsigned int, unsigned int);
    void splineTesselateU(unsigned int);
    void splineTesselateV(unsigned int);
    void splineCloseU(bool);
    void splineCloseV(bool);
    void splineFlipS(bool);
    void splineFlipT(bool);
    int _fAC;
    Mesh &_mesh;                /* 0xB0 */
    bool _fB4;
    bool _finished_called;      /* 0xB5 */
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
    Vector &operator+=(const Vector &o)
    {
        v[0] += o.v[0];
        v[1] += o.v[1];
        v[2] += o.v[2];
        v[3] += o.v[3];
        return *this;
    }
    Vector &operator-=(const Vector &o)
    {
        v[0] -= o.v[0];
        v[1] -= o.v[1];
        v[2] -= o.v[2];
        v[3] -= o.v[3];
        return *this;
    }
    Vector operator+(const Vector &o) const
    {
        Vector t(*this);
        t += o;
        return t;
    }
    Vector operator-(const Vector &o) const
    {
        Vector t(*this);
        t -= o;
        return t;
    }
    void print(const char *) const;
    float eval(float, float, int) const;
    float v[COEFFS];
};
class VectorRGB {
public:
    VectorRGB() {}
    VectorRGB(const Vector &r_, const Vector &g_, const Vector &b_) : r(r_), g(g_), b(b_) {}
    VectorRGB operator+(const VectorRGB &o) const { return VectorRGB(r + o.r, g + o.g, b + o.b); }
    VectorRGB operator-(const VectorRGB &o) const { return VectorRGB(r - o.r, g - o.g, b - o.b); }
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
}

/* accessors (generated from the asm; members named by offset) */
class Icosahedron {
public:
    class Bin {
    public:
        ~Bin();
        Bin *searchLeaf(math::vector_xyzw);
        bool intersect(math::vector_xyzw) const;
        bool in_negative_half_space(math::vector_xyzw) const;
        void setBinIndex(unsigned int);
        int getBinIndex() const;
        void setLeafIndex(unsigned int);
        int getLeafIndex() const;
        /* data */
        char _p0[0x8C];
        bool _leaf;                 /* 0x8C */
        int _f90;
        int _f94;
        Bin *_children[4];          /* 0x98 */
        int _fA8;
        std::vector<unsigned int> _vAC;
        unsigned char _depth;       /* 0xB8 */
    };
    Icosahedron(unsigned char);
    ~Icosahedron();
    bool getDepth() const;
    void draw();
    void draw(unsigned char);
    void draw_bin(Bin &, unsigned char);
    Bin *searchLeaf(math::vector_xyzw);
    void listAllBins(std::vector<Bin *> &);
    void listAllBinsRec(std::vector<Bin *> &, Bin *);
    void listBins(std::vector<Bin *> &, unsigned char);
    void listBinsRec(std::vector<Bin *> &, Bin *, unsigned char);
    void listPosHalfSpaceLeafBins(std::vector<Bin *> &, const math::vector_xyzw &);
    void listPosHalfSpaceLeafBinsRec(std::vector<Bin *> &, Bin *, const math::vector_xyzw &);
    /* data */
    bool _f0;
    int _f4;
    std::vector<Bin *> _bins;       /* 0x08 */
    std::vector<Bin *> _v14;
    std::vector<Bin *> _v20;
};

namespace sh {
common::common_internal::Log &Log_uint(common::common_internal::Log &, unsigned int) __asm__("_ZN6common15common_internal3LoglsEj");
class SphereSampling : public Icosahedron {
public:
    struct Sample : public math::SphericalCoord {
        Sample();
        Vector sh;                      /* 0x18 */
        float _value;                   /* 0x28 */
        float _r, _g, _b;               /* 0x2C */
    };
    SphereSampling(unsigned int);
    float canonical_random_var(unsigned int);
    Vector project(float (*)(float, float));
    VectorRGB project(const SphericalRGBFn *);
    VectorRGB project();
    Vector project1() const;
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
    enum Vertex { };
    Box();
    Box(math::vector_xyzw, math::vector_xyzw);
    void first(math::vector_xyzw);
    void add(math::vector_xyzw);
    void finish();
    float volume() const;
    void draw(int) const;
    void draw() const;
    math::vector_xyzw _c[8];    /* corners: _c[0] min, _c[7] max */
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
    int longestAxis() const;
    static std::vector<math::vector_xyzw> _points;
    int _type;              /* 0x80 */
    char _p84[0xC4 - 0x84];
    float _h[3];            /* 0xC4: half extents */
    char _pD0[0xE4 - 0xD0];
    bool _started;          /* 0xE4 */
    char _pE5[0x14C - 0xE5];
};
class BV;
class Frustum : public common::shared_object_base {
public:
    Frustum();
    virtual ~Frustum();
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
void FindBestAlignedDiagonal(math::vector_xyzw, Box::Vertex &, Box::Vertex &);
class RT {
public:
    struct Ray {
        enum Type { };
        Ray(math::vector_xyzw, math::vector_xyzw, Type);
        char _p0[0x34];
        int _triangle;              /* 0x34: index of the hit triangle */
        char _p38[0x3D - 0x38];
        bool _any;                  /* 0x3D: stop at the first hit */
    };
    struct Triangle {
        Triangle();
        Triangle(Position, Position, Position);
        bool intersect(Ray &) const;
        Position _v[3];
        float _f30, _f34, _f38;
        Normal _n;                  /* 0x3C */
    };
    RT();
    const void *getBVTree() const;
    const Mesh *getMesh() const;
    Mesh *getMesh();
    const math::vector_xyzw &getTestLight() const;
    void setTestLight(math::vector_xyzw);
    void start();
    void build_bv_tree(bool, unsigned int);
    void bvtree_trace(BVH::Node *, Ray &);
    void dumb_trace(Ray &);
    void trace(Ray &);
    Mesh _mesh;
    math::vector_xyzw _testLight;   /* 0xA0 */
    std::vector<Triangle> _triangles;   /* 0xB0 */
    BVH _bvh;                       /* 0xBC */
    bool _ready;                    /* 0x228 */
};
}

namespace sh {
class PRT {
public:
    enum DrawFlag { DRAW_NORMAL, DRAW_SH, FULL_HEMISPHERE_VTX, DRAW_METRICS };
    struct PerVertexData {
        PerVertexData();
        VectorRGB _sh[3];
        Vector _f90;                    /* 0x90 */
        bool _fA0, _fA1, _fA2;
        int _fA4[10];                   /* 0xA4 */
    };
    struct VertexData {
        std::vector<PerVertexData> _v;
    };
    void import_model();
    static const char *DrawFlagName(DrawFlag);
    void draw_samples(int, const VectorRGB &);
    void draw(int, DrawFlag, const math::matrix &, int);
    void draw_with_sh(DrawFlag, const math::matrix &, int);
    void draw_averaged_normals();
    void draw_triangles_normals();
    void process();
    void process(VertexData &);
    void save_if_doesnt_exit();
    sgl::RT _rt;
    char _p22C[0x2FC - 0x22C];
    SphereSampling _sampling;           /* 0x2FC */
    bool _processed;                    /* 0x334 */
    VertexData _vdata;                  /* 0x338 */
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
    const std::string &getName() const { return _args.name; }
    VectorRGB getSH() const { return _sh; }
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
    /* TestEnvSet.h's asserts: a unit that inlines getEnv defines TESTENVSET_H_STRINGS and the TES_H_*
       string labels of its object */
    const Env &getEnv(EnvEnum _Enum) const
#ifdef TESTENVSET_H_STRINGS
    {
        SGL_ASSERT(_Enum < MAX_ENV, TES_H_ERROR, TES_H_ENUM_TEXT, TES_H_FILE, TES_H_GETENV_FN, 77, TES_H_SEP);
        SGL_ASSERT(_lights[_Enum].valid(), TES_H_ERROR, TES_H_VALID_TEXT, TES_H_FILE, TES_H_GETENV_FN, 78, TES_H_SEP);
        return _lights[_Enum]->_env;
    }
#else
    ;
#endif
    std::vector<common::handle<TestEnv> > _lights;  /* 0x0 */
    int _current_light;                             /* 0xC */
};
}

#endif

/* sh::HDRMap needs FloatImage (demo/parser.hpp): units include parser.hpp, then this header again */
#if defined(DEMO_DUCK_DEMO_PARSER_HPP) && !defined(DEMO_DUCK_DEMO_SGL_HDRMAP)
#define DEMO_DUCK_DEMO_SGL_HDRMAP
namespace sh {
class HDRMap : public SphericalRGBFn {
public:
    HDRMap(const char *, float);
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~HDRMap() {}
    float convert01f(float) const;
    unsigned int convert0i(float, unsigned int) const;
    unsigned int convert255(float) const;
    void load();
    void save_vert_distribution();
    void save(const char *);
    void getUVf(float, float, float &, float &, float &) const;
    void getUVuc(float, float, unsigned char &, unsigned char &, unsigned char &) const;
    void getThetaPhif(float, float, float &, float &, float &) const;
    void getThetaPhiuc(float, float, unsigned char &, unsigned char &, unsigned char &) const;
    void getDf(math::vector_xyzw, float &, float &, float &) const;
    void getDuc(math::vector_xyzw, unsigned char &, unsigned char &, unsigned char &) const;
    FloatImage _img;                    /* 0x04 */
    float _exposure;                    /* 0x2C */
    float _min, _max;                   /* 0x30 */
    std::string _name;                  /* 0x38 */
};
}
#endif
