/* scene:: (scene graph).  No DWARF: classes, methods and vtable order from the
   symbol table (tools/dwarf2cpp.py UTST99332 demo_duck main_objs/scene_*);
   layouts from the asm. */
#ifndef DEMO_DUCK_DEMO_SCENE_HPP
#define DEMO_DUCK_DEMO_SCENE_HPP

#include <list>
#include <deque>
#include <map>
#include <sstream>

/* Template instances / out-of-line inline functions of a scene unit's tail are
   .gnu.linkonce.t sections, linked in the object's section order.  The tail
   mixes C++ instances with INCLUDE_ASM_LINKONCE ones (and our headers differ
   from Sony's in which members are inline, which changes cc1plus's deferral
   order), so the unit creates those sections up front, in Sony's link order
   (tmp/cxx/scene4/tailconv.py); cc1plus's code for each function is unchanged. */
#define SCENE_LINKONCE(n) "\t.section .gnu.linkonce.t." #n ",\"ax\",@progbits\n"
#define SCENE_LINKONCE_ORDER(s) __asm__(s "\t.text\n")

/* std::__default_alloc_template<true,0>::allocate/deallocate are never inlined in the demos (only
   their own out-of-line copies call getenv/_S_refill), but cc1plus inlines each of them into the
   first function of a unit that calls it (e.g. a vector<T>::operator= instance), and never again in
   that unit afterwards.  In Sony's objects that first caller was among the functions that are
   still asm here, so a unit whose instances call the allocator first instantiates this function
   (its dead code inlines both and is then dropped with the "GLIBCPP_FORCE_NEW" string; the function
   itself is discarded at link: it is not in the unit's linkonce list). */
template<int N> void scene_alloc_first_use(unsigned int n)
{
    if (0)
        std::__default_alloc_template<true, 0>::deallocate(std::__default_alloc_template<true, 0>::allocate(n), n);
}
#define SCENE_ALLOC_FIRST_USE template void scene_alloc_first_use<0>(unsigned int);

namespace common {
/* std::map comparator on strings (scene::Graph's multimap) */
struct LessStr {
    bool operator()(const std::string &a, const std::string &b) const
    {
        return strcmp(a.c_str(), b.c_str()) < 0;
    }
};
template<class T> class handles_list : public std::list<handle<T> > {
};
template<class T> class handles_vector : public std::vector<handle<T> > {
};
/* flag set indexed by an enum (only scene::Node uses it) */
template<class E, class V> class VarSetFunc {
public:
    V bits;
};
}

namespace glutils {
/* scene::Material's member (glutils::Material::setup is in the base library) */
class Material {
public:
    void setup();
    void print(std::ostream &);
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

/* the library's warning (common/assert.h): message, expression, file, function, line, text */
#define SCENE_WARN(c, warn, expr, file, func, line, text) \
    do { \
        if (!(c)) { \
            common::common_internal::assert_display(warn, expr, file, func, line, text); \
            common::common_internal::on_warning(); \
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
   labels (extern const char x[] __asm__("D_...");) before including main.hpp.  A unit whose .rodata
   is carved defines SCENE_BVDATA_LITERALS instead (the original's literals and __PRETTY_FUNCTION__). */
#ifdef SCENE_BVDATA_LITERALS
#define scene_bvdata_err " *** error "
#define scene_bvdata_valid "valid()"
#define scene_bvdata_file "../lib/scene/BVdata.h"
#define scene_bvdata_sp " "
#define scene_bvdata_get_name __PRETTY_FUNCTION__
#define scene_bvdata_warn " *** warning "
#define scene_bvdata_notvalid "! valid()"
#define scene_bvdata_create_name __PRETTY_FUNCTION__
#define scene_bvdata_created "bounding box already created"
#else
extern const char scene_bvdata_err[], scene_bvdata_valid[], scene_bvdata_file[], scene_bvdata_sp[];
extern const char scene_bvdata_get_name[];
/* BVdata::create: " *** warning ", "! valid()", __PRETTY_FUNCTION__, "bounding box already created" */
extern const char scene_bvdata_warn[], scene_bvdata_notvalid[], scene_bvdata_create_name[], scene_bvdata_created[];
#endif
extern const char scene_mesh_err[], scene_mesh_expr[], scene_mesh_file[], scene_mesh_sp[];
extern const char scene_mesh_getData_name[];

namespace sgl {
struct StencilShadowData;
}

namespace vertex_formats {
/* scene::VertexArray's interleaved vertex (36 bytes) */
struct T2F_C4UB_N3F_V3F {
    float t[2];
    unsigned char c[4];
    float n[3];
    float v[3];
};
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


/* handle<T>::get() and the tests as the original inlines them: get() returns
   early on a null d (base.hpp's ternary threads the null-object path
   differently: Shape::enter/leave), valid is `d && get()` (d tested twice),
   null its negation kept as a bool (Group::traverse_children) */
template<class T> inline T *hget(const common::handle<T> &h)
{
    if (!h.d)
        return 0;
    return dynamic_cast<T *>(h.d->obj);
}
template<class T> inline bool hvalid(const common::handle<T> &h)
{
    return h.d && hget(h);
}
template<class T> inline bool hnull(const common::handle<T> &h)
{
    return !hvalid(h);
}
/* deletes the object (Graph::deleteNode): set_data is called virtually */
template<class T> inline void hdelete(common::handle<T> &h)
{
    if (hget(h)) {
        common::shared_object_base *o = h.d->obj;
        h.d->count--;
        delete o;
        h.set_data(0);
    }
}

/* GL calls (HouseKeeping_AttribStack.c defines them as C stubs `(void)`) */
void scene_glPushAttrib(unsigned int) __asm__("glPushAttrib");
void scene_glPopAttrib() __asm__("glPopAttrib");
#ifndef GL_LIGHTING_BIT
#define GL_LIGHTING_BIT 0x00000040
#endif
#ifndef GL_ENABLE_BIT
#define GL_ENABLE_BIT 0x00002000
#endif

extern "C" {
void glLoadMatrixf(const float *);
void sceGumSetCurMatrix(void);
void sceGuEnable(int state);
void sceGuDisable(int state);
void sceGuLight(int light, int type, int components, const ScePspFVector3 *position);
void sceGuTexMapMode(int mode, unsigned int a1, unsigned int a2);
void sceGuBlendFunc(int op, int src, int dest, unsigned int srcfix, unsigned int destfix);
}

/* methods of other parts' classes not declared in their headers yet (same
   calls: `this` is the first argument) */
void sgl_Mesh_calcStencilShadowData(sgl::StencilShadowData &, const sgl::CoreMesh &)
    __asm__("_ZN3sgl4Mesh21calcStencilShadowDataERNS_17StencilShadowDataERKNS_8CoreMeshE");
void math_TransformStack_push(math::TransformStack &) __asm__("_ZN4math14TransformStack4pushEv");
void math_TransformStack_pop(math::TransformStack &) __asm__("_ZN4math14TransformStack3popEv");
void math_TransformStack_mult(math::TransformStack &, const math::matrix &)
    __asm__("_ZN4math14TransformStack4multERKNS_6matrixE");
int sgl_PrimitiveIndex_countTriangles(const sgl::PrimitiveIndex<int> &)
    __asm__("_ZNK3sgl14PrimitiveIndexIiE14countTrianglesEv");
/* math::matrix members not declared in demo/math.hpp yet */
math::vector_xyz math_matrix_eulerAnglesXYZ(const math::matrix &) __asm__("_ZNK4math6matrix14eulerAnglesXYZEv");
math::vector_xyz math_matrix_eulerAngles(const math::matrix &, math::RotationOrder)
    __asm__("_ZNK4math6matrix11eulerAnglesENS_13RotationOrderE");
math::matrix math_matrix_EulerRotation(float, float, float, math::RotationOrder)
    __asm__("_ZN4math6matrix13EulerRotationEfffNS_13RotationOrderE");
void textures_Texture_setupGl(textures::Texture &, int, bool) __asm__("_ZN8textures7Texture7setupGlEib");
int textures_Texture_load(textures::Texture &, const char *) __asm__("_ZN8textures7Texture4loadEPKc");
void textures_Texture_resizePow2(textures::Texture &, bool, bool, bool) __asm__("_ZN8textures7Texture10resizePow2Ebbb");
void textures_Texture_initGl(textures::Texture &, int) __asm__("_ZN8textures7Texture6initGlEi");
void gl_GenTextures(int, unsigned int *) __asm__("_ZN2gl11GenTexturesEiPj");
void gl_DeleteTextures(int, const unsigned int *) __asm__("_ZN2gl14DeleteTexturesEiPKj");
extern "C" void sceGuTexFunc(int tfx, int tcc);
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
    void operator=(const BVdata &o)
    {
        if (o._bv) {
#ifdef SCENE_BVDATA_CREATE
            if (!_bv)
                create(sgl::BV::Type(0));
#else
            if (!_bv && !valid())
                _bv = new sgl::BV, _bv->setType(sgl::BV::Type(0));
#endif
            *_bv = *o._bv;
        } else if (_bv)
            delete _bv, _bv = 0;
    }
    void create(sgl::BV::Type t) {
        SCENE_WARN(!valid(), scene_bvdata_warn, scene_bvdata_notvalid, scene_bvdata_file, scene_bvdata_create_name, 83,
                   scene_bvdata_created);
        if (!valid()) {
            _bv = new sgl::BV;
            _bv->setType(t);
        }
    }
    sgl::BV &get() {
        SCENE_ASSERT(valid(), scene_bvdata_err, scene_bvdata_valid, scene_bvdata_file, scene_bvdata_get_name, 62,
                     scene_bvdata_sp);
        return *_bv;
    }
    sgl::BV *_bv;
};

class HasBVdata {
public:
    HasBVdata &operator=(const HasBVdata &o)
    {
        _bvdata = o._bvdata;
        return *this;
    }
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
    /* clone(): `*copy = *this` copies the flags and Members, not the
       shared_object_base (its handle data) */
    Node &operator=(const Node &o)
    {
        common::VarSetFunc<NodeFlags, bool>::operator=(o);
        _m = o._m;
        return *this;
    }
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
    unsigned int getCreateCount() const;
    void setTmp(unsigned int);
    unsigned int getTmp() const;
    void setMagic(unsigned int);
    unsigned int getMagic() const;
    void output_string(std::ostream &, const std::string &, bool);
    static int constructor_counter;
    static std::string NULL_COLOR;
    static std::string DEFAULT_COLOR;
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
    void traverse(TraversalType, sgl::Frustum &, const math::matrix &, const math::matrix &, const math::matrix &,
                  const sh::VectorRGB &, float);
    bool traverse_children(math::TransformStack &, sgl::BV &);
    void traverse_children(TraversalVarStack &);
    void addChild(common::handle<Node>);
    void addChild(common::handle<Group>, common::handle<Node>);
    void addChild(common::handle<Group>, common::handle<Group>, common::handle<Node>);
    void removeChild(common::handle<Node>);
    void clearChildren(bool);
    std::list<common::handle<Node> > &children();
    const std::list<common::handle<Node> > &children() const;
    template<class T> void find(common::handles_vector<Node> &, bool);
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
    /* textures::Texture is 0x54 bytes (its operator= copies 0x50; demo/base.hpp declares 0x50) */
    struct Tex {
        Tex &operator=(const Tex &o)
        {
            t = o.t;
            return *this;
        }
        textures::Texture t;
        int _f50;
    };
    Tex _tex;                       /* 0x28 */
    unsigned int _texid;            /* 0x7C: GL texture name */
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
    void attachMaterial(common::handle<Material> &, Pass);
    void detachMaterial(Pass);
    void attachTexture(common::handle<Texture> &, Pass);
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
    enum Space { };
    void flushCache();
    void invalidate_cached_mat();
    void setIdentity();
    void setFromMatrix(math::matrix);
    math::vector_xyz getEulerAngles(math::RotationOrder) const;
    void setEulerRotation(const math::vector_xyz &, math::RotationOrder);
    void setRotation(const math::quaternion &);
    void setRotation(math::vector_xyz);
    void set_rotation(const math::matrix &);
    void preTransform(math::matrix, math::matrix, math::matrix, bool);
    static void SetViewerTransform(const math::matrix &);
    static void SetParentTransform(const math::matrix &);
    void translate(Space, float, float, float);
    void rotate(Space, float, float, float, math::RotationOrder);
    void rotateX(Space, float);
    void rotateY(Space, float);
    void rotateZ(Space, float);
    void transform(Space, const math::matrix &);
    static float set_angle(float);
    static bool use_angle_range;
    static float angle_range;
    static math::matrix tmp_viewer_transform;
    static math::matrix tmp_parent_transform;
    const math::matrix &getMatrix() const;
    math::vector_xyz getTranslation() const;
    math::vector_xyz getScale() const;
    math::quaternion getRotation() const;
    void setTranslation(math::vector_xyz);
    void setScale(math::vector_xyz);
    math::matrix _matrix;           /* 0x30 (cache) */
    bool _dirty;                    /* 0x70 */
    bool _identity;                 /* 0x71 */
    math::vector_xyz _translation;  /* 0x74 */
    math::vector_xyz _scale;        /* 0x84 */
    math::vector_xyz _euler;        /* 0x94 */
};

class MeshData : public sgl::CoreMesh {
public:
    MeshData();
    virtual ~MeshData();
    void copy(const sgl::Mesh &);
    void finish();
    void draw(const TraversalVarStack &);
};

/* ../lib/scene/VertexArray.cpp (main_objs/scene_VertexArray) */
class VertexArray {
public:
    VertexArray();
    void use(Pass);
    struct Channel {
        Channel() : _fC(0) {}
        std::vector<math::vector_xyzw> _v;
        int _fC;
    };
    bool _f0;
    Channel _c4;                            /* 0x4 */
    Channel _c14;                           /* 0x14 */
    Channel _c24;                           /* 0x24 */
    bool _f34;
    std::vector<vertex_formats::T2F_C4UB_N3F_V3F> _v38;     /* 0x38 */
    std::vector<vertex_formats::T2F_C4UB_N3F_V3F> _v44;     /* 0x44 */
    std::vector<vertex_formats::T2F_C4UB_N3F_V3F> *_v_ptr;  /* 0x50 */
};

class MeshDataInterleaved {
public:
    struct SharedData;
    struct VertexData;
    void draw(const TraversalVarStack &);
    void convert(const MeshData &);
    MeshDataInterleaved();
    MeshDataInterleaved(const MeshDataInterleaved &);
    MeshDataInterleaved &operator=(const MeshDataInterleaved &);
    std::vector<sh::VectorRGB> &getRadianceTransfers();
    const std::vector<sh::VectorRGB> &getRadianceTransfers() const;
    common::handle<SharedData> _shared;     /* 0x0 (sizeof(scene::Mesh) is 0x44) */
    common::handle<VertexData> _vertex;     /* 0x8 */
};

/* (SharedData's dtor: a PrimitiveIndex<short> at 0x48, a deleted pointer at 0x6C) */
struct MeshDataInterleaved::SharedData : common::shared_object_base {
    struct Block {
        Block() : _f0(0), _f4(0), _f8(0), _fC(0) {}
        int _f0, _f4, _f8, _fC;
    };
    SharedData() : _f14(false), _f64(false), _f65(false), _f66(false), _f67(false), _p6C(0) {}
    std::vector<sh::VectorRGB> _radiance;   /* 0x8 */
    bool _f14;                              /* 0x14 */
    Block _b18, _b28, _b38;                 /* 0x18 */
    sgl::PrimitiveIndex<short> _index;      /* 0x48 */
    bool _f64, _f65, _f66, _f67;            /* 0x64 */
    int _f68;
    void *_p6C;                             /* 0x6C (deleted by the dtor) */
};
struct MeshDataInterleaved::VertexData : common::shared_object_base {
    VertexArray _va;                        /* 0x8 */
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
    TraversalVarStack(TraversalType, sgl::Frustum &, math::matrix, math::matrix, math::matrix, sh::VectorRGB, float);
    ~TraversalVarStack();
    void push();
    void pop();
    void internal_push();
    void internal_pop();
    void enable(Enabled, bool);
    void mult(const math::matrix &, bool, bool);
    char _p0[4];
    std::stack<StackElement> _stack;    /* 0x4 */
    char _p2C[0x54 - 0x2C];
    int _pass;                      /* 0x54 */
    char _p58[0x15C - 0x58];
    unsigned int _enabled;          /* 0x15C */
    sgl::Frustum *_frustum;         /* 0x160 */
    int _depth;                     /* 0x164 */
    char _p168[0x170 - 0x168];
};

/* sizeof 0xF8 (TestApp holds one at 0xF08, the next member is at 0x1000) */
class Graph {
public:
    typedef std::map<const std::string, common::handle<Node> > NodeMap;
    typedef std::multimap<const std::string, common::handle<Node>, common::LessStr> NodeMultiMap;
    Graph();
    ~Graph();
    static bool disable_pass0;
    static bool disable_reflection_mapping;
    static bool disable_sh_calculation;
    void clear();
    void deleteNode(common::handle<Node>);
    void deleteBranch(common::handle<Node>);
    common::handle<Node> cloneNode(common::handle<Node>, std::string);
    common::handle<Group> cloneBranch(common::handle<Group>, std::string);
    common::handle<Group> cloneGroup(std::string, std::string);
    common::handle<Group> cloneObject(std::string, std::string);
    common::handle<Object> newObject(std::string);
    common::handle<Mesh> newMesh(std::string, const sgl::Mesh &, unsigned int);
    common::handle<Object> getObject(std::string);
    common::handle<Texture> newTexture(std::string, bool, std::string);
    void flattenTransforms(common::handle<Group>);
    void flattenMaterials(bool);
    void cleanUp();
    void tag_identity_transforms();
    void attachPass1ToAll();
    void assertFlat();
    void finish();
    sgl::BV &getBV();
    void add_node(common::handle<Node>);
    void pushNamespace(std::string);
    void popNamespace();
    void loadNamespace(std::string);
    const std::string &getNamespace() const;
    std::string translatedName(std::string) const;
    template<class T> common::handle<T> newNode(std::string, bool);
    template<class T> common::handle<T> getMappedNode(const std::string &);
    template<class T> void getSublist(common::handles_list<T> &);
    void load(std::string, unsigned int, std::string);
    void save(const char *);
    void dot_output(std::string);
    void calcbv();
    void printMapA();
    void printMapU();
    void printMapO();
    void save_vrml(std::string);
    void traverse(TraversalType, sgl::Frustum &, const math::matrix &, const math::matrix &, const math::matrix &,
                  float);
    math::TransformStack _ts;           /* 0x0 */
    sh::VectorRGB _light;               /* 0x70 */
    common::handle<Group> _root;        /* 0xA0 */
    NodeMap _mapA;                      /* 0xA8 */
    NodeMap _mapU;                      /* 0xB4 */
    NodeMultiMap _mapO;                 /* 0xC0 */
    std::stack<std::string> _namespace_stack;   /* 0xCC */
    bool _finish_called;                /* 0xF4 */
};
}

/* Graph::load's parser (../lib/scene/Graph.load.cpp, main_objs/scene_GraphParser) */
namespace common {
std::string GetPathLessFilename(std::string);
std::string GetBasename(std::string);
std::string GetFileLessPath(std::string);
}
namespace scene {
class GraphParser : public FieldParser {
public:
    GraphParser(Graph &, std::string, unsigned int);
    virtual ~GraphParser();
    void parse_new_texture(FieldParser::Field &, const std::string &, bool);
    void parse_new_switch(FieldParser::Field &, const std::string &, bool);
    void parse_new_group(FieldParser::Field &, const std::string &, bool);
    void parse_new_object(FieldParser::Field &, const std::string &, bool);
    void parse_new_shape(FieldParser::Field &, const std::string &, bool);
    void parse_new_default_shader(FieldParser::Field &, const std::string &, bool);
    void parse_new_transform(FieldParser::Field &, const std::string &, bool);
    void parse_new_static_transform(FieldParser::Field &, const std::string &, bool);
    void parse_new_mesh(FieldParser::Field &, const std::string &, bool);
    void parse_new_material(FieldParser::Field &, const std::string &, bool);
    void parse_new_unknown(FieldParser::Field &, const std::string &, bool, const std::string &);
    void parse_new(FieldParser::Field &);
    void parse_push_child_cmd();
    void parse_attach_texture_cmd();
    void parse_attach_material_cmd();
    void parse_attach_setup_cmd();
    void parse(FieldParser::Field &);
    void step_matrix(math::matrix &);
    Graph &_graph;                      /* 0x54 */
    std::string _path;                  /* 0x58 */
    common::handle<Object> _object;     /* 0x5C */
};
}
/* the destructors are inline (linkonce copies in scene_GraphParser.o, which defines SCENE_LINKONCE_GraphParser) */
#if SCENE_LINKONCE_GraphParser
SGL_LINKONCE_BEGIN
inline FieldParser::~FieldParser() {}
inline scene::GraphParser::~GraphParser() {}
SGL_LINKONCE_END
#endif

/* scene::Graph's member templates (instances in scene_Graph*, scene_GraphParser) */
#ifdef SCENE_GRAPH_TEMPLATE_DEFS
namespace scene {
/* the unit defines the assert strings scene_graph_h_err/_name_expr/_file/_sp/_empty (labels) and
   inline scene::scene_pf_getMappedNode(T *) returning the instance's __PRETTY_FUNCTION__ label */
template<class T> common::handle<T> Graph::getMappedNode(const std::string &_Name)
{
    SCENE_ASSERT(_Name != scene_graph_h_empty, scene_graph_h_err, scene_graph_h_name_expr, scene_graph_h_file,
                 scene_pf_getMappedNode((T *)0), 91, scene_graph_h_sp);
    std::string n = translatedName(_Name.c_str());
    {
        NodeMap::iterator i = _mapU.find(n.c_str());
        if (i != _mapU.end())
            return common::handle<T>(i->second);
    }
    {
        NodeMultiMap::iterator i = _mapO.find(n.c_str());
        if (i != _mapO.end())
            return common::handle<T>(i->second);
    }
    return common::handle<T>();
}
/* also scene_graph_h_us ("_") */
template<class T> common::handle<T> Graph::newNode(std::string name, bool mapped)
{
    std::string n = translatedName(name);
    if (n != scene_graph_h_empty) {
        common::handle<T> h = getMappedNode<T>(n);
        if (hvalid(h))
            return h;
    }
    common::handle<T> h(new T(n.c_str(), mapped));
    if (name.empty()) {
        std::ostringstream os;
        os << h->getTypeName() << scene_graph_h_us << h->getCreateCount();
        std::string nm = translatedName(os.str());
        h->setName(nm);
    }
    add_node(h);
    return h;
}
template<class T> void Graph::getSublist(common::handles_list<T> &l)
{
    l.clear();
    for (NodeMultiMap::iterator i = _mapO.begin(); i != _mapO.end(); ++i) {
        common::handle<T> h(i->second);
        if (hnull(h))
            continue;
        l.push_back(h);
    }
}
}
#endif

#endif
