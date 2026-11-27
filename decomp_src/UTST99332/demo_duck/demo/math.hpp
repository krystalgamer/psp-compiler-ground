/* math::, vertex_formats::, interp:: */
#ifndef DEMO_DUCK_DEMO_MATH_HPP
#define DEMO_DUCK_DEMO_MATH_HPP

#include <stack>

namespace common {
template<class T> class t_array2d;
}

/* Identity()'s 1.0f: a unit whose .rodata stays asm defines it as its D_ label before main.hpp */
#ifndef MATH_IDENTITY_ONE
#define MATH_IDENTITY_ONE 1
#endif
/* quaternion()'s 1.0f, likewise */
#ifndef MATH_QUAT_ONE
#define MATH_QUAT_ONE 1
#endif

namespace math {
struct TransformStack;
/* 16 bytes (by-value copies move 4 words) */
struct vector_xyz {
    float x, y, z, _pad;
    vector_xyz() {}
    vector_xyz(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    vector_xyz operator*(float s) const { return vector_xyz(x * s, y * s, z * s); }
};
struct vector_xyzw {
    float x, y, z, w;
    vector_xyzw() {}
    vector_xyzw(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
    float &operator[](int i) { return (&x)[i]; }
    const float &operator[](int i) const { return (&x)[i]; }
    vector_xyzw operator+(const vector_xyzw &b) const { return vector_xyzw(x + b.x, y + b.y, z + b.z, w + b.w); }
    vector_xyzw operator-(vector_xyzw b) const { return vector_xyzw(x - b.x, y - b.y, z - b.z, w - b.w); }
    vector_xyzw operator-() const { return vector_xyzw(-x, -y, -z, -w); }
    vector_xyzw operator*(float s) const { return vector_xyzw(x * s, y * s, z * s, w * s); }
    vector_xyzw operator*(const vector_xyzw &b) const { return vector_xyzw(x * b.x, y * b.y, z * b.z, w * b.w); }
    vector_xyzw operator/(vector_xyzw b) const { return vector_xyzw(x / b.x, y / b.y, z / b.z, w / b.w); }
};
inline float dot(const vector_xyzw &a, const vector_xyzw &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}
struct matrix;
inline vector_xyzw operator*(const vector_xyzw &v, const matrix &m);
inline vector_xyzw cross(const vector_xyzw &a, const vector_xyzw &b)
{
    return vector_xyzw(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0);
}
inline float length(const vector_xyzw &v)
{
    return sqrtf(dot(v, v));
}
struct vector_xy {
    float x, y;
    vector_xy() {}
    vector_xy(float x_, float y_) : x(x_), y(y_) {}
};
struct quaternion;
enum RotationOrder { };
struct matrix {
    vector_xyzw r[4];
    matrix() {}
    matrix(const quaternion &q);
    static matrix Translation(float x, float y, float z);
    static matrix Translation(const vector_xyz &v);
    static matrix Translation(const vector_xyzw &v);
    static matrix Scale(float x, float y, float z);
    static matrix Scale(const vector_xyz &v);
    static matrix Rotation(float a, float x, float y, float z);
    static matrix Rotation(float a, const vector_xyzw &v);
    static matrix Rotation(float a, const vector_xyz &v);
    static matrix RotationX(float a);
    static matrix RotationY(float a);
    static matrix RotationZ(float a);
    static matrix PointNormal(vector_xyzw p, vector_xyzw n);
    static matrix Perspective(float fovy, float aspect, float n, float f);
    static matrix Frustum(float l, float r, float b, float t, float n, float f);
    static matrix ShadowMatrix(vector_xyzw plane, vector_xyzw light);
    static matrix trackball(float, float, bool, bool, float, float, vector_xyzw &);
    static matrix EulerRotation(float a, float b, float c, RotationOrder o);
    static matrix EulerRotation(vector_xyz v, RotationOrder o);
    matrix inverse3() const;
    matrix inverseON() const;
    matrix inverse() const;
    matrix transpose() const;
    vector_xyz eulerAngles(RotationOrder o) const;
    vector_xyz eulerAnglesXYZ() const;
    vector_xyz eulerAnglesXZY() const;
    vector_xyz eulerAnglesYXZ() const;
    vector_xyz eulerAnglesYZX() const;
    vector_xyz eulerAnglesZXY() const;
    vector_xyz eulerAnglesZYX() const;
    bool isCoordSys(float eps) const;
    matrix fixedCoordSys() const;
    void print(std::string, std::string) const;
    float determinant3() const;
    matrix(vector_xyzw a, vector_xyzw b, vector_xyzw c, vector_xyzw d)
    {
        r[0] = a;
        r[1] = b;
        r[2] = c;
        r[3] = d;
    }
    static const matrix &Identity()
    {
        static const matrix IDENTITY(vector_xyzw(MATH_IDENTITY_ONE, 0, 0, 0), vector_xyzw(0, MATH_IDENTITY_ONE, 0, 0),
                                     vector_xyzw(0, 0, MATH_IDENTITY_ONE, 0), vector_xyzw(0, 0, 0, MATH_IDENTITY_ONE));
        return IDENTITY;
    }
};
}

namespace math {
/* row vector times matrix */
inline vector_xyzw operator*(const vector_xyzw &v, const matrix &m)
{
    return m.r[0] * v.x + m.r[1] * v.y + m.r[2] * v.z + m.r[3] * v.w;
}
}

namespace vertex_formats {
struct V3F {
    float x, y, z;
    V3F(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
};
struct T2UB_V3F {
    unsigned char u, v;
    V3F p;
    T2UB_V3F() : u(0), v(0), p(0, 0, 1) {}
};
}


namespace math {
struct quaternion {
    quaternion() : x(0), y(0), z(0), w(MATH_QUAT_ONE) {}
    quaternion(const matrix &);
    quaternion(float x, float y, float z, float w);
    quaternion(vector_xyzw v);
    quaternion(vector_xyz v, float w);
    quaternion operator+(const quaternion &q) const;
    quaternion operator-(const quaternion &q) const;
    quaternion operator*(const quaternion &q) const;
    quaternion operator*(float s) const;
    quaternion operator/(float s) const;
    bool operator==(const quaternion &q) const;
    bool operator!=(const quaternion &q) const;
    quaternion &operator-=(const quaternion &q);
    quaternion &operator*=(const quaternion &q);
    quaternion &operator+=(const quaternion &q);
    quaternion &operator*=(float s);
    quaternion &operator/=(float s);
    float dot(const quaternion &q) const;
    float norm() const;
    quaternion conj() const;
    matrix toMatrix() const;
    static void Shortest(quaternion &a, quaternion &b);
    static quaternion FromEulerAngles(vector_xyz v, RotationOrder o);
    static quaternion FromEulerAngles(float a, float b, float c, RotationOrder o);
    static quaternion FromAxisAngle(vector_xyz axis, float angle);
    void toAxisAngle(vector_xyz &axis, float &angle);
    quaternion log() const;
    quaternion exp() const;
    static quaternion Slerp(quaternion a, quaternion b, float t);
    float x, y, z, w;
};
float safe_atan2f(float y, float x);
float safe_sqrtf(float x);
float safe_acosf(float x);
float safe_asinf(float x);
namespace angle {
float BetweenTwoVectors(const vector_xy &a, const vector_xy &b);
float BetweenTwoVectors2(const vector_xyzw &a, const vector_xyzw &b);
float SmartUpdate(float a, float b);
float Relative(float a, float b);
}
int factorial(int n);
float wrap(float x, float lo, float range);
float FastNoise(unsigned int n);
int double_factorial(int n);
float area(vector_xyzw a, vector_xyzw b, vector_xyzw c);
/* spherical harmonics helpers */
struct SH {
    static int N(unsigned int l);
    static float P(int l, int m, float x);
    static float K(int l, int m);
    static float Eval(int l, int m, float theta, float phi);
};
}

namespace interp {
namespace keyframe_tangent {
enum Type { };
enum Side { };
}
template<class T> class KeyFrame {
public:
    KeyFrame();
    KeyFrame(float, T, bool);
    bool isClosingKey() const;
    T value() const;
    void setValue(T);
    float time() const;
    void setTime(float);
    void setTangentType(keyframe_tangent::Type, int);
    keyframe_tangent::Type getTangentType(keyframe_tangent::Side) const;
    float _time;
    int _type[2];
    bool _closing;
    T _value;
    T _tangent[2];
};
class VirtualKeyFrameSequence {
public:
    virtual ~VirtualKeyFrameSequence() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual int sizeLessClosingKey() const = 0;
    virtual void clear() = 0;
    virtual void remove(unsigned int) = 0;
    virtual void dump(const char *) const = 0;
    virtual float getLastTime() const = 0;
    virtual float getKeyTime(int) const = 0;
    virtual void setKeyTime(int, float) = 0;
    virtual bool isClosingKey(int) const = 0;
    virtual void setCloseDt(float) = 0;
    virtual float getCloseDt() const = 0;
    virtual void setClose(bool) = 0;
    virtual bool isClosed() const = 0;
    virtual void setLoop(bool) = 0;
    virtual bool isLoop() const = 0;
    virtual void setRelative(bool) = 0;
    virtual bool isRelative() const = 0;
    virtual void finish() = 0;
    virtual void setTangentType(int, keyframe_tangent::Type, int) = 0;
    virtual keyframe_tangent::Type getTangentType(int, keyframe_tangent::Side) const = 0;
};
/* members out of class (their instances stay asm where they are) */
template<class T> class KeyFrameSequenceBase : public VirtualKeyFrameSequence {
public:
    KeyFrameSequenceBase();
    virtual ~KeyFrameSequenceBase();
    virtual bool empty() const;
    virtual int size() const;
    virtual int sizeLessClosingKey() const;
    virtual void clear();
    virtual void remove(unsigned int);
    virtual float getLastTime() const;
    virtual float getKeyTime(int) const;
    virtual void setKeyTime(int, float);
    virtual bool isClosingKey(int) const;
    virtual void setCloseDt(float);
    virtual float getCloseDt() const;
    virtual void setClose(bool);
    virtual bool isClosed() const;
    virtual void setLoop(bool);
    virtual bool isLoop() const;
    virtual void setRelative(bool);
    virtual bool isRelative() const;
    virtual void finish();
    virtual void setTangentType(int, keyframe_tangent::Type, int);
    virtual keyframe_tangent::Type getTangentType(int, keyframe_tangent::Side) const;
    virtual int wrap_key_index(int) const;
    virtual void invalidate_cached_key_interval();
    virtual bool calc_tangent_setup(int, T &, T &, T &, float &, float &);
    virtual void calc_tangent(int) = 0;
    virtual T calc_gradient(T, T, float) const = 0;
    virtual void calc_all_tangent();
    virtual int find_key_interval(float);
    virtual bool evaluate_setup(float, float &, T &, KeyFrame<T> *&, KeyFrame<T> *&);
    virtual void push_closing_key();
    virtual void update_closing_key();
    virtual void on_set_key_value(int);
    virtual T get_key_abs_rel_value(int);
    virtual void set_key_abs_rel_value(int, T);
    virtual T op(T, T) = 0;
    virtual T op_inv(T, T) = 0;
    virtual T op_identity() const = 0;
    virtual void setDefault(T);
    virtual T getDefault() const;
    virtual int insert(float, T);
    virtual int insert(float);
    virtual const std::vector<KeyFrame<T> > &getKeyList() const;
    virtual KeyFrame<T> &operator[](unsigned int);
    virtual T evaluate(float) = 0;
    virtual void makeRelative();
    virtual void makeAbsolute();
    virtual void typed_fix() = 0;
    virtual void makeConsistantWith(const VirtualKeyFrameSequence *);
    void setKeyValue(int, T);
    T getKeyAbsRelValue(int);
    T _default;
    std::vector<KeyFrame<T> > _keys;
    bool _closed;
    float _closeDt;
    bool _loop;
    bool _relative;
    int _cached;
};
/* the sequences the demo uses are explicit specializations here: the template vtables must not be emitted */
template<class T> class KeyFrameSequence : public KeyFrameSequenceBase<T> {
public:
    KeyFrameSequence() {}
    virtual ~KeyFrameSequence();
    virtual void dump(const char *) const;
    virtual void calc_tangent(int);
    virtual T calc_gradient(T, T, float) const;
    virtual T evaluate(float);
    virtual void typed_fix();
};
template<class T> class KeyFrameSequenceA;
template<> class KeyFrameSequenceA<float> : public KeyFrameSequence<float> {
public:
    KeyFrameSequenceA() {}
    virtual ~KeyFrameSequenceA();
    virtual float op(float, float);
    virtual float op_inv(float, float);
    virtual float op_identity() const;
};
template<> class KeyFrameSequence<math::quaternion> : public KeyFrameSequenceBase<math::quaternion> {
public:
    KeyFrameSequence() {}
    virtual ~KeyFrameSequence();
    virtual void dump(const char *) const;
    virtual void calc_tangent(int);
    virtual math::quaternion calc_gradient(math::quaternion, math::quaternion, float) const;
    virtual math::quaternion op(math::quaternion, math::quaternion);
    virtual math::quaternion op_inv(math::quaternion, math::quaternion);
    virtual math::quaternion op_identity() const;
    virtual math::quaternion evaluate(float);
    virtual void typed_fix();
};
}

/* accessors (generated from the asm; members named by offset) */
namespace math {
struct Frame {
    Frame() {}
    Frame(const vector_xyz &p, const quaternion &q) : pos(p), rot(q) {}
    vector_xyz pos;
    quaternion rot;
};
}
namespace interp {
class Path {
public:
    Path();
    void startRecording();
    void addRecord(math::Frame);
    std::pair<bool, math::Frame> deleteLastRecord();
    void finishRecording();
    bool isRecording() const;
    void load(std::string);
    void save(std::string);
    math::Frame evaluate(float);
    int size() const;
    unsigned int _count;                                /* 0x0 */
    bool _recording;                                    /* 0x4 */
    KeyFrameSequenceA<float> _x, _y, _z;                /* 0x8, 0x2C, 0x50 */
    KeyFrameSequence<math::quaternion> _rot;            /* 0x74 */
};
}

namespace math {
class SphericalCoord {
public:
    SphericalCoord();
    SphericalCoord(float theta, float phi);
    void setThetaD(float);
    void setPhiD(float);
    void setTheta(float);
    void setPhi(float);
    void incrTheta(float);
    void incrPhi(float);
    void set(float, float);
    void reset();
    matrix transformMatrix() const;
    void sync_direction();
    float _theta, _phi;                                 /* 0x0 */
    vector_xyzw _dir;                                   /* 0x8 */
};
}

namespace math {
struct TransformStack {
    TransformStack();
    virtual ~TransformStack();
    void push();
    void pop();
    void mult(const matrix &);
    void load(const matrix &);
    void identity();
    void rotate(float, float, float, float);
    void rotateX(float);
    void rotateY(float);
    void rotateZ(float);
    void scale(float, float, float);
    void scale(float);
    void translate(float, float, float);
    const matrix &top() const;
    matrix &top();
    const matrix &top_inv() const;
    matrix &top_inv();
    std::stack<matrix> _stack;                          /* 0x4 */
    mutable matrix _inv;                                /* 0x2C */
    mutable bool _dirty;                                /* 0x6C */
};
/* a non-polymorphic base of sgl::MeshBuilder (typeinfo without bases) */
class TransformStackFunc {
public:
    void pushTransform();
    void popTransform();
    void multTransform(const matrix &);
    void loadTransform(const matrix &);
    void loadIdentity();
    void rotate(float, float, float, float);
    void rotateX(float);
    void rotateY(float);
    void rotateZ(float);
    void scale(float, float, float);
    void scale(float);
    void translate(float, float, float);
    const matrix &getTransform() const;
    matrix &getTransform();
    const matrix &getTransformInverse() const;
    matrix &getTransformInverse();
    TransformStack _stack;                              /* 0x0 */
};
}

/* accessors (generated from the asm; members named by offset) */
namespace math {
class Trackball {
public:
    enum Mode { };
    void mode(math::Trackball::Mode);
    Trackball(const matrix &);
    void track(matrix &, float, float, bool, bool);
    void track(float, float, bool, bool);
    void track(float dx, float dy, bool, bool, matrix);
    void reset();
    const matrix &getTransform() const;
    const matrix &getDeltaRot() const;
    /* data */
    matrix _transform;                                  /* 0x0 */
    quaternion _rot;                                    /* 0x40 */
    matrix _deltaRot;                                   /* 0x50 */
    int _f90;
};
namespace bspline {
class curve {
public:
    curve();
    void setCtrl(vector_xyzw *ctrl, int n);
    void localEval(vector_xyzw &, float);
    int _Num;                                           /* 0x0 */
    vector_xyzw *_Ctrl;                                 /* 0x4 */
};
class surface {
public:
    common::t_array2d<vector_xyzw> *net();
    void *ctrlnet();
    void setNet(common::t_array2d<vector_xyzw> *);
    /* data */
    common::t_array2d<vector_xyzw> *_f0;
    char _f4;
};
}
}

namespace sgl {
/* sgl::RED etc. (an array: the static initializer's store order needs it) */
struct Color {
    float c[4];
    Color()
    {
        c[0] = 0;
        c[1] = 0;
        c[2] = 0;
        c[3] = 0;
    }
    Color(float r, float g, float b, float a)
    {
        c[0] = r;
        c[1] = g;
        c[2] = b;
        c[3] = a;
    }
};
}

/* The headers' static objects: every object of the demo constructs those of
   the headers it includes in its static initializer, in this order (math,
   <iostream>, sgl colours, interp).  A unit whose static initializer is C++
   selects them before including main.hpp: DEMO_STATICS_MATH (HERMITE_BASIS,
   BEZIER_BASIS), DEMO_STATICS_IOSTREAM (std::__ioinit), DEMO_STATICS_SGL (RED..
   CYAN), DEMO_STATICS_INTERP (CUMULATIVE_BERNSTIEN_BASIS); DEMO_HEADER_STATICS
   selects all four. */
#ifdef DEMO_HEADER_STATICS
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#define DEMO_STATICS_SGL
#define DEMO_STATICS_INTERP
#endif
#ifdef DEMO_STATICS_MATH
namespace math {
static const matrix HERMITE_BASIS(vector_xyzw(2, -2, 1, 1), vector_xyzw(-3, 3, -2, -1),
                                  vector_xyzw(0, 0, 1, 0), vector_xyzw(1, 0, 0, 0));
static const matrix BEZIER_BASIS(vector_xyzw(-1, 3, -3, 1), vector_xyzw(3, -6, 3, 0),
                                 vector_xyzw(-3, 3, 0, 0), vector_xyzw(1, 0, 0, 0));
}
#endif
#ifdef DEMO_STATICS_IOSTREAM
#include <iostream>
#endif
#ifdef DEMO_STATICS_SGL
namespace sgl {
static const Color RED = Color(1, 0, 0, 0);
static const Color GREEN = Color(0, 1, 0, 0);
static const Color BLUE = Color(0, 0, 1, 0);
static const Color BLACK = Color(0, 0, 0, 0);
static const Color WHITE = Color(1, 1, 1, 0);
static const Color YELLOW = Color(1, 1, 0, 0);
static const Color MAGENTA = Color(1, 0, 1, 0);
static const Color CYAN = Color(0, 1, 1, 0);
}
#endif
#ifdef DEMO_STATICS_INTERP
namespace interp {
static const math::matrix CUMULATIVE_BERNSTIEN_BASIS(math::vector_xyzw(1, -2, 1, 0), math::vector_xyzw(-3, 3, 0, 0),
                                                     math::vector_xyzw(3, 0, 0, 0), math::vector_xyzw(0, 0, 0, 0));
}
#endif

#endif
