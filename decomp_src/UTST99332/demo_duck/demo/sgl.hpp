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

/* Out-of-line (.gnu.linkonce.t) copies of inline members: main.hpp's `#pragma interface` makes
   every inline function defined under it external.  The unit that held Sony's copy defines
   SGL_LINKONCE_<name> 1 before main.hpp; the definition (after its class) is then wrapped in
   SGL_LINKONCE_BEGIN/END: `#pragma implementation`+`#pragma interface` of a dummy name turn the
   interface off (inline functions defined there are emitted as linkonce copies, unused clones
   too: the link discards those), a plain `#pragma interface` turns it on again. */
#define SGL_LINKONCE_BEGIN _Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#define SGL_LINKONCE_END _Pragma("interface")

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
    size_t unfold(std::vector<T> &);
    template<class U> PrimitiveIndex &operator=(const PrimitiveIndex<U> &);
    std::vector<T> &strips();
    const std::vector<T> &strips() const;
    std::vector<T> &tri();
    const std::vector<T> &tri() const;
    int countVertices() const;
    int countVerticesInStrips() const;
    int countTriangles() const;
    size_t countTrianglesInStrips() const;
    void range(int &, int &) const;
    void check() const;
    std::vector<T> _strips;     /* 0x00 */
    std::vector<T> _tri;        /* 0x0C */
    int n;                      /* 0x18 */
};
/* template bodies: only in units that hold (or emit) the instances (SGL_TEMPLATE_DEFS), the
   others still have them as asm */
/* the strings of the instances' asserts (__PRETTY_FUNCTION__ and the module's other labels differ per
   instance/module): the holder unit declares the specializations it uses with the module's labels
   (template<> const char sgl::PrimitiveIndexNames<short>::unfold[] __asm__("...");) */
template<class T> struct PrimitiveIndexNames {
    static const char unfold[], check[], assign[];
    static const char err[], sep[], file[];
    static const char val_ge_0[], retval_size[], tri_size[], count_n[];
};
#define SGL_PI_ASSERT(c, text, fn, line) \
    SGL_ASSERT(c, PrimitiveIndexNames<T>::err, PrimitiveIndexNames<T>::text, PrimitiveIndexNames<T>::file, \
               PrimitiveIndexNames<T>::fn, line, PrimitiveIndexNames<T>::sep)
#if SGL_TEMPLATE_DEFS
template<class T> PrimitiveIndex<T>::PrimitiveIndex() : n(0)
{
    clear();
}
template<class T> void PrimitiveIndex<T>::clear()
{
    _strips.clear();
    _tri.clear();
    n = 0;
}
template<class T> std::vector<T> &PrimitiveIndex<T>::strips() { return _strips; }
template<class T> const std::vector<T> &PrimitiveIndex<T>::strips() const { return _strips; }
template<class T> std::vector<T> &PrimitiveIndex<T>::tri() { return _tri; }
template<class T> const std::vector<T> &PrimitiveIndex<T>::tri() const { return _tri; }
template<class T> void PrimitiveIndex<T>::offset(unsigned int o)
{
    for (unsigned int i = 0; i != _tri.size(); i++)
        _tri[i] += o;
    for (int s = 0, j = 0; s != n; s++) {
        int len = _strips[j++];
        for (int l = 0; l != len; l++)
            _strips[j + l] += o;
        j += len;
    }
}
template<class T> int PrimitiveIndex<T>::countVerticesInStrips() const
{
    int count = 0;
    for (int i = 0, k = 0; i != n; i++) {
        int len = _strips[k++];
        count += len;
        k += len;
    }
    return count;
}
template<class T> int PrimitiveIndex<T>::countVertices() const
{
    return countVerticesInStrips() + _tri.size();
}
template<class T> template<class U> PrimitiveIndex<T> &PrimitiveIndex<T>::operator=(const PrimitiveIndex<U> &o)
{
    n = o.n;
    _strips.resize(o.strips().size());
    _tri.resize(o.tri().size());
    for (unsigned int i = 0; i != _strips.size(); i++) {
        T val = o.strips()[i];
        SGL_PI_ASSERT(val >= 0, val_ge_0, assign, 48);
        _strips[i] = val;
    }
    for (unsigned int i = 0; i != _tri.size(); i++) {
        T val = o.tri()[i];
        SGL_PI_ASSERT(val >= 0, val_ge_0, assign, 58);
        _tri[i] = val;
    }
    return *this;
}
template<class T> size_t PrimitiveIndex<T>::unfold(std::vector<T> &_Retval)
{
    size_t num_vertices = countVertices();
    _Retval.clear();
    _Retval.reserve(num_vertices);
    int k = 0;
    for (unsigned int i = 0; i != tri().size(); i++) {
        _Retval.push_back(tri()[i]);
        tri()[i] = k++;
    }
    for (int s = 0, j = 0; s != n; s++) {
        int len = strips()[j++];
        for (int l = 0; l != len; l++) {
            _Retval.push_back(strips()[j + l]);
            strips()[j + l] = k++;
        }
        j += len;
    }
    SGL_PI_ASSERT(_Retval.size() == num_vertices, retval_size, unfold, 369);
    return num_vertices;
}
template<class T> void PrimitiveIndex<T>::check() const
{
    SGL_PI_ASSERT(3 * (_tri.size() / 3) == _tri.size(), tri_size, check, 202);
    unsigned int i = 0;
    int count = 0;
    for (; i < _strips.size(); i += _strips[i] + 1)
        count++;
    SGL_PI_ASSERT(count == n, count_n, check, 218);
}
template<class T> void PrimitiveIndex<T>::swap(PrimitiveIndex &o)
{
    o._strips.swap(_strips);
    o._tri.swap(_tri);
    std::swap(n, o.n);
}
#endif

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
    const int getVertexAttributeIndex(int, VertexAttrEnum) const;
    void setVertexAttributeIndex(int, VertexAttrEnum, int);
    int getVertexPositionIndex(int) const;
    const Position getVertexPosition(int) const;
    const Normal getVertexNormal(int) const;
    const Color getVertexColor(int) const;
    const TexCoord getVertexTexCoord(int) const;
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
/* lib/sgl/KdTree.h (member bodies: sgl_Mesh_4.c, the holder of most instances) */
struct KdTreeNode {
    KdTreeNode() : _size(0), _start(0), _longest_axis(-1), _split(0), _leaf(true), _f14(0), _left(0), _right(0) {}
    ~KdTreeNode();
    unsigned int _size;
    unsigned int _start;
    short _longest_axis;
    float _split;
    bool _leaf;
    int _f14;
    KdTreeNode *_left;
    KdTreeNode *_right;
};
/* the out-of-line copy (it deletes its children recursively): sgl_BV defines SGL_LINKONCE_KdTreeNode */
#if SGL_LINKONCE_KdTreeNode
SGL_LINKONCE_BEGIN
#endif
inline KdTreeNode::~KdTreeNode()
{
    delete _left;
    delete _right;
}
#if SGL_LINKONCE_KdTreeNode
SGL_LINKONCE_END
#endif
template<class T> class KdTree {
public:
    KdTree(std::vector<T> &, int, float);
    int find(const T &);
    KdTreeNode *find(const T &, int &);
    unsigned int getNodeSize(KdTreeNode *) const;
    unsigned int getNodeElement(KdTreeNode *, unsigned int);
    void build(KdTreeNode *, unsigned int);
    bool compute_longest_box(KdTreeNode *);
    T &node_element(KdTreeNode *, unsigned int);
    void merge_node_elements(KdTreeNode *);
    KdTreeNode *find_rec(KdTreeNode *, const T &);
    int _dim;
    float _threshold;
    unsigned int _max_depth;
    int _num_nodes;
    int _num_leaves;
    std::vector<T> &_items;                     /* 0x14 */
    std::vector<unsigned int> _partitioned_items; /* 0x18 */
    KdTreeNode _root;                           /* 0x24 */
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
    void draw_triangles(float) const;
    void draw_vertex(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, float, bool) const;
    static bool use_purple;
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
    void reverse_strip(int);
    int scan_back(int);
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
    /* noinline: the original calls these where cc1plus-1.6.1 would inline them (the three resets, begin(),
       vertexAt(int, float, float, float)); cause unknown */
    struct begin_var {
        begin_var(InputMode, BeginMode) __attribute__((noinline));
        void reset();
        int _write_primitive;       /* BeginMode */
        int _input_mode;            /* InputMode */
        int _f8, _fC, _f10;
        struct Indices : Triangle {
            Indices()
            {
                v[0] = -1;
                v[1] = -1;
                v[2] = -1;
                e[0] = -1;
                e[1] = -1;
                e[2] = -1;
            }
        } _indices;                 /* 0x14 */
        Attr<Color> _color;         /* 0x2C */
        Attr<Normal> _normal;       /* 0x40 */
        Attr<TexCoord> _texcoord;   /* 0x54 */
    };
    struct extruded_var {
        extruded_var() __attribute__((noinline));
        void reset();
        LineSet _lineset;
        TransformSet _tset;         /* 0x8C */
        int _slices;                /* 0xA0 */
        float _start_angle;         /* 0xA4 */
        float _end_angle;           /* 0xA8 */
    };
    struct spline_var {
        spline_var() __attribute__((noinline));
        void reset();
        common::t_array2d<Position> _ctrl;
        unsigned int _count;                /* 0x28 */
        unsigned int _tessU, _tessV;
        bool _closeU, _closeV, _flipS, _flipT;
        bool _texcoord;             /* 0x38 */
        bool _normals;              /* 0x39 */
    };
    MeshBuilder(Mesh &, bool);
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
    void color_i(unsigned int);
    void colorG(Color);
    void colorG(float, float, float, float);
    void colorG(float, float);
    void colorG(float);
    void colorGi(unsigned int);
    void texcoord(TexCoord);
    void texcoord(float, float);
    void vertex(Position);
    void vertex(float, float, float);
    void vertex(int);
    void triangle(int, int, int);
    void quad_t(int, int, int, int, bool);
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
    void end_spline();
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
    void positionAt(int, float, float, float) __attribute__((noinline));
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
    void sphere(float, int, int, float, float);
    void cylinder(float, float, int, int);
    void cone(float, float, int, int);
    void arrow(float, float, float, float);
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
    bool equal(const Vector &, float) const;
    float v[COEFFS];
};
class VectorRGB {
public:
    VectorRGB() {}
    VectorRGB(const Vector &r_, const Vector &g_, const Vector &b_) : r(r_), g(g_), b(b_) {}
    VectorRGB operator+(const VectorRGB &o) const { return VectorRGB(r + o.r, g + o.g, b + o.b); }
    VectorRGB operator-(const VectorRGB &o) const { return VectorRGB(r - o.r, g - o.g, b - o.b); }
    VectorRGB &operator+=(const VectorRGB &o)
    {
        r += o.r;
        g += o.g;
        b += o.b;
        return *this;
    }
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
    float _f40, _f44, _f48;     /* the band-1 rotation's Euler angles (TwoBands) */
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
    virtual ~SphericalRGBFn();
    void saveCubeMap(const char *, textures::Texture **, unsigned int, int, float) const;
};
/* sh_DebugMap holds the out-of-line copies, after DebugMap's own: defined there below */
#if !SGL_LINKONCE_SphericalRGBFn
inline SphericalRGBFn::~SphericalRGBFn() {}
#endif
/* stand-ins until demo/base.hpp / demo/math.hpp declare them */
common::common_internal::Log &Log_float(common::common_internal::Log &, float) __asm__("_ZN6common15common_internal3LoglsEf");
float math_wrap(float, float, float) __asm__("_ZN4math4wrapEfff");
int math_min_i(int, int) __asm__("_ZN4math4min_IiEET_S1_S1_");
class SquareMap : public SphericalRGBFn {
public:
    SquareMap(const char *, float);
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~SquareMap();
    void load(const char *);
    mutable textures::Texture _tex;     /* 0x04 */
    char _p54[4];
    float _exposure;                    /* 0x58 */
};
#if SGL_LINKONCE_SquareMap
SGL_LINKONCE_BEGIN
#endif
inline SquareMap::~SquareMap() {}
#if SGL_LINKONCE_SquareMap
SGL_LINKONCE_END
#endif
class PolarFunction : public SphericalRGBFn {
public:
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~PolarFunction();
    virtual float eval(float theta, float phi) const = 0;
};
#if SGL_LINKONCE_PolarFunction
SGL_LINKONCE_BEGIN
#endif
inline PolarFunction::~PolarFunction() {}
#if SGL_LINKONCE_PolarFunction
SGL_LINKONCE_END
#endif
class DebugMap : public SphericalRGBFn {
public:
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~DebugMap();
    sgl::Color _colors[6];              /* 0x04 */
};
#if SGL_LINKONCE_DebugMap
SGL_LINKONCE_BEGIN
#endif
inline DebugMap::~DebugMap() {}
#if SGL_LINKONCE_DebugMap
SGL_LINKONCE_END
#endif
#if SGL_LINKONCE_SphericalRGBFn
SGL_LINKONCE_BEGIN
inline SphericalRGBFn::~SphericalRGBFn() {}
SGL_LINKONCE_END
#endif
}

namespace icosahedron {
struct Face {
    int a, b, c;
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
        void setChildren(Bin *, Bin *, Bin *, Bin *);
        void setBinIndex(unsigned int);
        int getBinIndex() const;
        void setLeafIndex(unsigned int);
        int getLeafIndex() const;
        /* data */
        math::vector_xyzw _v[3];    /* 0x00 corners */
        math::vector_xyzw _edge[3]; /* 0x30 edge planes */
        math::vector_xyzw _face;    /* 0x60 face plane */
        char _p70[0x1C];
        bool _leaf;                 /* 0x8C */
        int _f90;
        int _f94;
        Bin *_children[4];          /* 0x98 */
        Bin *_parent;               /* 0xA8 */
        std::vector<unsigned int> _vAC;
        unsigned char _depth;       /* 0xB8 */
    };
    Icosahedron(unsigned char);
    ~Icosahedron();
    math::vector_xyzw on_sphere(math::vector_xyzw);
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
    bool intersect(float &, const math::vector_xyzw &, const math::vector_xyzw &) const;
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
    Frustum(float, float, float, float, float, float, float, float);
    virtual ~Frustum();
    bool intersect(BV &);
    void print() const;
    void setFov(float);
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
    float _f38;
    float _f3C;
    struct Data40 {
        int w[0x1C8 / 4];
    } _f40;
};
#if SGL_LINKONCE_Frustum
SGL_LINKONCE_BEGIN
#endif
inline Frustum::~Frustum() {}
#if SGL_LINKONCE_Frustum
SGL_LINKONCE_END
#endif
}
class BVH {
public:
    struct Node {
        enum ChildEnum { };
        Node() : _leaf(true), _depth(0) { _child[0] = 0; _child[1] = 0; }
        ~Node();
        void draw() const;
        sgl::BV _bv;
        bool _leaf;                     /* 0x14C */
        Node *_child[2];                /* 0x150 */
        unsigned int _depth;            /* 0x158 */
        std::vector<unsigned int> _items;   /* 0x15C */
    };
    BVH();
    void draw() const;
    void setChild(Node::ChildEnum, Node *, Node *);
    void print();
    void print(Node *);
    Node _root;
    unsigned int _depth;                /* 0x168: deepest node */
};
namespace sgl {
void FindBestAlignedDiagonal(math::vector_xyzw, Box::Vertex &, Box::Vertex &);
class RT {
public:
    struct Ray {
        enum Type { };
        Ray(math::vector_xyzw, math::vector_xyzw, Type);
        math::vector_xyzw _origin;  /* 0x0 */
        math::vector_xyzw _dir;     /* 0x10 */
        Type _type;                 /* 0x20 */
        math::vector_xyzw _hit;     /* 0x24 */
        int _triangle;              /* 0x34: index of the hit triangle */
        char _p38[0x3C - 0x38];
        bool _f3C;                  /* 0x3C */
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
    void build_bv_tree(BVH::Node *, bool, unsigned int);
    void add(const Mesh &, unsigned int);
    void barycentricCoords(const Ray &, float &, float &, float &) const;
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
/* 0x6C bytes of floats, bitwise-copied (vector<sh::Vertex> instances in sh_PRT) */
struct Vertex {
    Vertex();
    float _p0[3];
    VectorRGB _sh;                      /* 0x0C */
    float _p3C[(0x6C - 0x3C) / 4];
};
class VerticesVector {
public:
    VerticesVector() : _fC(0), _f10(0), _f14(0), _f18(0), _f1C(0), _f20(0), _f24(0), _f28(0) {}
    bool load(std::string);
    void save(std::string);
    std::vector<Vertex> _v;
    int _fC, _f10, _f14, _f18, _f1C, _f20, _f24, _f28;
};
/* evaluates a VectorRGB (sh_Env) */
class FunctionEvaluator : public SphericalRGBFn {
public:
    FunctionEvaluator(const VectorRGB &f) : _f(&f) {}
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~FunctionEvaluator();
    const VectorRGB *_f;
};
#if SGL_LINKONCE_FunctionEvaluator
SGL_LINKONCE_BEGIN
#endif
inline void FunctionEvaluator::eval(float theta, float phi, float &r, float &g, float &b) const
{
    _f->eval(theta, phi, r, g, b);
}
inline FunctionEvaluator::~FunctionEvaluator() {}
#if SGL_LINKONCE_FunctionEvaluator
SGL_LINKONCE_END
#endif
/* sh::Env's sky model (its eval is still asm, an inline member held by sh_Env) */
class CIEClearSky : public SphericalRGBFn {
public:
    virtual void eval(float theta, float phi, float &r, float &g, float &b) const;
    virtual ~CIEClearSky();
};
#if SGL_LINKONCE_FunctionEvaluator
SGL_LINKONCE_BEGIN
#endif
inline CIEClearSky::~CIEClearSky() {}
#if SGL_LINKONCE_FunctionEvaluator
SGL_LINKONCE_END
#endif
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
    struct VertexData : VerticesVector {
        std::vector<PerVertexData> _pvd;    /* 0x2C */
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
    void sum_bounces(VertexData &);
    void save();
    void load();
    void saveVertexSHAsCubeMap(const char *, unsigned int, unsigned int);
    sgl::RT _rt;
    char _p22C[0x2FC - 0x22C];
    SphereSampling _sampling;           /* 0x2FC */
    bool _processed;                    /* 0x334 */
    VertexData _vdata;                  /* 0x338 */
    char _p370[0x3C8 - 0x370];
    std::string _name;                  /* 0x3C8 */
};
#if SGL_LINKONCE_PerVertexData
SGL_LINKONCE_BEGIN
#endif
inline PRT::PerVertexData::PerVertexData() : _fA0(false), _fA1(false), _fA2(false)
{
    for (int i = 0; i != 10; i++)
        _fA4[i] = 0;
}
#if SGL_LINKONCE_PerVertexData
SGL_LINKONCE_END
#endif
}

/* sh::Args::Env, sh::Env, sh::TestEnvSet (declarations maintained by cxx-apps3) */
namespace sh {
namespace Args {
struct Env {
    enum Type { };
    static Type GetEnvType(std::string s);
    void getArgs(common::CmdLine &cl);
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
        virtual ~TestEnv();
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
#if SGL_LINKONCE_TestEnv
SGL_LINKONCE_BEGIN
#endif
inline TestEnvSet::TestEnv::~TestEnv() {}
#if SGL_LINKONCE_TestEnv
SGL_LINKONCE_END
#endif
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
    virtual ~HDRMap();
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
#if SGL_LINKONCE_HDRMap
SGL_LINKONCE_BEGIN
#endif
inline HDRMap::~HDRMap() {}
#if SGL_LINKONCE_HDRMap
SGL_LINKONCE_END
#endif
}
#endif
