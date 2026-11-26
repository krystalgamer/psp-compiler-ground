/* math::, vertex_formats::, interp:: */
#ifndef DEMO_DUCK_DEMO_MATH_HPP
#define DEMO_DUCK_DEMO_MATH_HPP

namespace math {
struct TransformStack;
struct vector_xyz {
    float x, y, z;
    vector_xyz() {}
    vector_xyz(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
};
struct vector_xyzw {
    float x, y, z, w;
    vector_xyzw() {}
    vector_xyzw(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
};
struct matrix {
    vector_xyzw r0, r1, r2, r3;
    matrix() {}
    matrix(const vector_xyzw &a, const vector_xyzw &b, const vector_xyzw &c, const vector_xyzw &d)
        : r0(a), r1(b), r2(c), r3(d) {}
    static const matrix &Identity()
    {
        static const matrix IDENTITY(vector_xyzw(1, 0, 0, 0), vector_xyzw(0, 1, 0, 0),
                                     vector_xyzw(0, 0, 1, 0), vector_xyzw(0, 0, 0, 1));
        return IDENTITY;
    }
};
}

namespace vertex_formats {
struct T2UB_V3F {
    unsigned char u, v;
    math::vector_xyz p;
    T2UB_V3F() : u(0), v(0), p(0, 0, 1) {}
};
}

namespace interp {
template<class T> class KeyFrameSequence {
public:
    void typed_fix();
    void dump(const char *) const;
};
}

namespace math {
struct quaternion;
}

/* accessors (generated from the asm; members named by offset) */
namespace interp {
class Path {
public:
    bool isRecording() const;
    int size() const;
    /* data */
    int _f0;
    bool _f4;
};
class VectorRGBAnim {
public:
    bool isRecording() const;
    int size() const;
    /* data */
    char _p0[0x1B0];
    int _f1B0;
    bool _f1B4;
};
}

/* accessors (generated from the asm; members named by offset) */
namespace math {
class Trackball {
public:
    enum Mode { };
    void mode(math::Trackball::Mode);
    const void *getTransform() const;
    const void *getDeltaRot() const;
    /* data */
    char _p0[0x50];
    char _f50;
    char _p51[0x3F];
    int _f90;
};
namespace bspline {
class surface {
public:
    int net();
    void *ctrlnet();
    /* data */
    int _f0;
    char _f4;
};
}
}

#endif
