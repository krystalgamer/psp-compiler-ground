/* scene:: (scene graph).  No DWARF: classes, methods and vtable order from the
   symbol table (tools/dwarf2cpp.py UTST99332 demo_duck main_objs/scene_*);
   layouts from the asm. */
#ifndef DEMO_DUCK_DEMO_SCENE_HPP
#define DEMO_DUCK_DEMO_SCENE_HPP

#include <list>
#include <deque>

namespace common {
/* flag set indexed by an enum (only scene::Node uses it) */
template<class E, class V> class VarSetFunc {
public:
    unsigned char bits;
};
}

namespace glutils {
/* scene::Material's member (glutils::Material::setup is in the base library) */
class Material {
public:
    void setup();
    math::vector_xyzw ambient, diffuse, specular, emission;
    float shininess;
    int f44;
};
}

/* the library's assert (common/assert.h): message, expression, file, function, line, " " */
#define SCENE_ASSERT(c, err, expr, file, func, line, sp) \
    do { \
        if (!(c)) { \
            common::common_internal::assert_display(err, expr, file, func, line, sp); \
            common::common_internal::on_error(); \
            common::common_internal::clash(); \
        } \
    } while (0)

#ifndef GL_COLOR_MATERIAL
#define GL_COLOR_MATERIAL 0x0B57
#endif
#ifndef GL_TEXTURE_2D
#define GL_TEXTURE_2D 0x0DE1
#endif

/* Strings of the asserts in the inline functions below: each object has its
   own copies, so a unit that inlines one declares these names with its asm
   labels (extern const char x[] __asm__("D_...");) before including main.hpp. */
extern const char scene_bvdata_err[], scene_bvdata_valid[], scene_bvdata_file[], scene_bvdata_sp[];
extern const char scene_bvdata_get_name[];
extern const char scene_mesh_err[], scene_mesh_expr[], scene_mesh_file[], scene_mesh_sp[];
extern const char scene_mesh_getData_name[];

namespace sgl {
struct StencilShadowData;
}

namespace scene {
enum NodeFlags { };
enum TraversalType { };
enum Pass { };
class TraversalVarStack;
class Node;
class Group;
class Setup;
class Material;
class Texture;


/* handle<T>'s pointer: the object through a dynamic_cast */
template<class T> inline T *hget(const common::handle<T> &h)
{
    return h.d ? dynamic_cast<T *>(h.d->obj) : 0;
}

template<class T> inline T *hptr(const common::handle<T> &h)
{
    return dynamic_cast<T *>(h.d->obj);
}
template<class T> inline bool hvalid(const common::handle<T> &h)
{
    return h.d && dynamic_cast<T *>(h.d->obj);
}

template<class T> inline bool hnull(const common::handle<T> &h)
{
    return !hvalid(h);
}

extern "C" {
void glLoadMatrixf(const float *);
void sceGumSetCurMatrix(void);
}

/* methods of other parts' classes not declared in their headers yet (same
   calls: `this` is the first argument) */
void sgl_Mesh_calcStencilShadowData(sgl::StencilShadowData &, const sgl::CoreMesh &)
    __asm__("_ZN3sgl4Mesh21calcStencilShadowDataERNS_17StencilShadowDataERKNS_8CoreMeshE");
void math_TransformStack_push(math::TransformStack &) __asm__("_ZN4math14TransformStack4pushEv");
void math_TransformStack_pop(math::TransformStack &) __asm__("_ZN4math14TransformStack3popEv");
void math_TransformStack_mult(math::TransformStack &, const math::matrix &)
    __asm__("_ZN4math14TransformStack4multERKNS_6matrixE");
bool sgl_Frustum_intersect(sgl::Frustum *, sgl::BV &) __asm__("_ZN3sgl7Frustum9intersectERNS_2BVE");

class BVdata {
public:
    BVdata() : _bv(0) {}
    ~BVdata() {
        if (_bv) {
            delete _bv;
            _bv = 0;
        }
    }
    bool valid() const { return _bv != 0; }
    sgl::BV &get() {
        SCENE_ASSERT(valid(), scene_bvdata_err, scene_bvdata_valid, scene_bvdata_file, scene_bvdata_get_name, 62,
                     scene_bvdata_sp);
        return *_bv;
    }
    sgl::BV *_bv;
};

class HasBVdata {
public:
    bool frustumTest(sgl::Frustum &);
    static bool enabled;
    BVdata _bvdata;
};

class Node : public common::shared_object_base, public common::VarSetFunc<NodeFlags, bool> {
public:
    struct Members {
        Members(std::string, bool);
        std::string _name;      /* 0xC */
        bool _mapped;           /* 0x10 */
        int _parent_count;      /* 0x14 */
        int _create_count;      /* 0x18 */
        unsigned int _tmp;      /* 0x1C */
        unsigned int _magic;    /* 0x20 */
        int _f24;               /* 0x24 */
    };
    Node(std::string, bool);
    virtual ~Node();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual void dot_output(std::ostream &);
    virtual bool isGroup() const;
    virtual bool isClonable() const;
    void set_default_name();
    bool isMapped() const;
    const std::string &getName() const;
    std::string getBasename() const;
    void setName(std::string);
    void incrParentCount();
    void decrParentCount();
    int getParentCount() const;
    int getCreateCount() const;
    void setTmp(unsigned int);
    unsigned int getTmp() const;
    void setMagic(unsigned int);
    unsigned int getMagic() const;
    void output_string(std::ostream &);
    static int constructor_counter;
    Members _m;
};

class Group : public Node, public HasBVdata {
public:
    Group(std::string, bool);
    virtual ~Group();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual void dot_output(std::ostream &);
    virtual bool isGroup() const;
    virtual bool isClonable() const;
    void calcbv();
    void traverse_children(math::TransformStack &, sgl::BV &);
    void traverse_children(TraversalVarStack &);
    void clearChildren(bool);
    std::list<common::handle<Node> > &children();
    const std::list<common::handle<Node> > &children() const;
    static unsigned int _magic_number;
    std::list<common::handle<Node> > _children;   /* 0x2C */
};

class Object : public Group {
public:
    Object(std::string, bool);
    virtual ~Object();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
};

class Setup : public Node {
public:
    Setup(std::string, bool);
    virtual ~Setup();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual void enter();
    virtual void leave();
};

class Material : public Setup {
public:
    Material(std::string, bool);
    virtual ~Material();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual void dot_output(std::ostream &);
    virtual void enter();
    virtual void leave();
    glutils::Material &getMaterial();
    const glutils::Material &getMaterial() const;
    glutils::Material _material;    /* 0x28 */
};

class Texture : public Setup {
public:
    Texture(std::string, bool);
    virtual ~Texture();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual void dot_output(std::ostream &);
    virtual void enter();
    virtual void leave();
    void setPath(std::string);
    const std::string &getPath() const;
    void invalidate();
    void load();
    void setHint(std::string);
    void setOverrideAlpha(bool, unsigned char);
    static bool debug_output;
    char _p28[0x80 - 0x28];
    std::string _path;              /* 0x80 */
    std::string _hint;              /* 0x84 */
    bool _override_alpha;           /* 0x88 */
    unsigned char _alpha;           /* 0x89 */
    bool _invalid;                  /* 0x8A */
    bool _loaded;                   /* 0x8B */
};

class DefaultShader : public Setup {
public:
    DefaultShader(std::string, bool);
    virtual ~DefaultShader();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual void dot_output(std::ostream &);
    virtual void enter();
    virtual void leave();
    void attachMaterial(common::handle<Material> &);
    void detachMaterial();
    void attachTexture(common::handle<Texture> &);
    common::handle<Material> &getMaterial();
    const common::handle<Material> &getMaterial() const;
    common::handle<Texture> &getTexture();
    const common::handle<Texture> &getTexture() const;
    common::handle<Material> _material;    /* 0x28 */
    common::handle<Texture> _texture;      /* 0x30 */
};

class Shape : public Group {
public:
    Shape(std::string, bool);
    virtual ~Shape();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual void dot_output(std::ostream &);
    virtual void enter(Pass);
    virtual void leave(Pass);
    const common::handle<Setup> &getSetup(Pass) const;
    void attachSetup(common::handle<Setup>, Pass);
    void detachSetup(Pass);
    common::handle<Setup> _setup[2];       /* 0x30 */
};

class Switch : public Group {
public:
    Switch(std::string, bool);
    virtual ~Switch();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    void select(int);
    int getSelected() const;
    common::handle<Node> getChild();
    int _selected;                  /* 0x30 */
};

class StaticTransform : public Group {
public:
    StaticTransform(std::string, bool);
    virtual ~StaticTransform();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    void setMatrix(math::matrix);
    math::matrix getMatrix() const;
    void setIdentity();
    math::matrix _matrix;           /* 0x30 */
    bool _identity;                 /* 0x70 */
};

class Transform : public Group {
public:
    Transform(std::string, bool);
    virtual ~Transform();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    void flushCache();
    void invalidate_cached_mat();
    const math::matrix &getMatrix() const;
    math::vector_xyzw getTranslation() const;
    math::vector_xyzw getScale() const;
    math::matrix _matrix;           /* 0x30 (cache) */
    bool _dirty;                    /* 0x70 */
    bool _identity;                 /* 0x71 */
    math::vector_xyzw _translation; /* 0x74 */
    math::vector_xyzw _scale;       /* 0x84 */
    math::vector_xyz _euler;        /* 0x94 */
};

class MeshData : public sgl::CoreMesh {
public:
    MeshData();
    virtual ~MeshData();
    void finish();
    void draw(const TraversalVarStack &);
};

class MeshDataInterleaved {
public:
    void draw(const TraversalVarStack &);
    void convert(const MeshData &);
};

class Mesh : public Node, public HasBVdata {
public:
    Mesh(std::string, bool);
    virtual ~Mesh();
    virtual const char *getTypeName() const;
    virtual void save(std::ostream &);
    virtual void flatten(math::TransformStack &);
    virtual void traverse(TraversalVarStack &);
    virtual bool calcbv(math::TransformStack &, sgl::BV &);
    virtual common::handle<Node> clone(std::string) const;
    virtual bool isClonable() const;
    void destroy_mesh_data();
    void draw(const TraversalVarStack &);
    void calcbv();
    void format(unsigned int);
    MeshData &getData() {
        SCENE_ASSERT(_mesh, scene_mesh_err, scene_mesh_expr, scene_mesh_file, scene_mesh_getData_name, 94,
                     scene_mesh_sp);
        return *_mesh;
    }
    MeshData *_mesh;                        /* 0x2C */
    sgl::StencilShadowData *_stencil;       /* 0x30 */
    MeshDataInterleaved _interleaved;       /* 0x34 */
};

class TraversalVarStack {
public:
    enum Enabled { };
    struct StackElement {
        void clear() {
            f0 = 0; f4 = 0; f8 = 0; fC = 0; f10 = 0; f14 = 0;
            f18 = 0; f1C = 0; f20 = 0; f24 = 0; f28 = 0; f2C = 0;
        }
        int f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
        math::matrix m30;           /* 0x30 */
        math::matrix m70;           /* 0x70: loaded by internal_pop */
        math::matrix mB0;           /* 0xB0 */
        math::matrix mF0;           /* 0xF0 */
        math::vector_xyzw v130;     /* 0x130 */
    };
    void push();
    void pop();
    void internal_push();
    void internal_pop();
    void enable(Enabled, bool);
    void mult(const math::matrix &, bool, bool);
    char _p0[4];
    std::deque<StackElement> _stack;    /* 0x4 */
    char _p2C[0x54 - 0x2C];
    int _pass;                      /* 0x54 */
    char _p58[0x15C - 0x58];
    unsigned int _enabled;          /* 0x15C */
    sgl::Frustum *_frustum;         /* 0x160 */
    int _depth;                     /* 0x164 */
};

class Graph {
public:
    static bool disable_pass0;
    static bool disable_reflection_mapping;
    void calcbv();
    void printMapA();
    void printMapU();
    void printMapO();
    void save_vrml(std::string);
};
}

#endif
