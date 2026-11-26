/* C++ declarations for main.cpp (the demo's own objects; no DWARF: class
   names, methods and vtable order from the symbol table, see
   tools/dwarf2cpp.py UTST99332 demo_duck main).  Layouts are only filled in
   as far as decompiled code needs them. */
#ifndef DEMO_DUCK_MAIN_HPP
#define DEMO_DUCK_MAIN_HPP

/* vtables and typeinfo stay in the module's data: never emit them here */
#pragma interface

#include <ostream>
#include <string>
#include <stdlib.h>

extern "C" {
#include "common.h"
}

#include <vector>

/* the demo's OpenGL emulation (C linkage) */
extern "C" {
typedef unsigned int GLenum;
typedef float GLfloat;
void glPushMatrix(void);
void glPopMatrix(void);
void glMultMatrixf(const GLfloat *);
void glScalef(GLfloat, GLfloat, GLfloat);
void glDisable(GLenum);
void glEnable(GLenum);
void glBegin(GLenum);
void glEnd(void);
void glColor3f(GLfloat, GLfloat, GLfloat);
void glNormal3f(GLfloat, GLfloat, GLfloat);
void glVertex3f(GLfloat, GLfloat, GLfloat);
}
#define GL_LINE_LOOP 0x0002
#define GL_QUADS 0x0007
#define GL_LIGHTING 0x0B50

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

class WaterPatch {
public:
    enum Pass { };
    WaterPatch(unsigned int, unsigned int, float, int, float, float);
    ~WaterPatch();
    void reset();
    bool setf(float, float, float);
    void set_disk(math::vector_xyzw, float, float, float);
    bool set(unsigned int, unsigned int, float);
    void idle(float);
    void drawAsPlane(bool) const;
    void drawW(bool) const;
    void reflect();
    void prepareRefraction() const;
    void draw(Pass) const;
    void update();
private:
    unsigned int _nx, _ny;                              /* 0x0 */
    float _size;                                        /* 0x8 */
    std::vector<math::vector_xyzw> _pos;                /* 0xC */
    std::vector<math::vector_xyzw> _normal;             /* 0x18 */
    std::vector<vertex_formats::T2UB_V3F> _vtx0;        /* 0x24 */
    std::vector<vertex_formats::T2UB_V3F> _vtx1;        /* 0x30 */
    std::vector<unsigned short> _indices;               /* 0x3C */
    vertex_formats::T2UB_V3F _min, _max;                /* 0x48 */
    float *_h0, *_h1, *_h;                              /* 0x68 */
    float _f74;                                         /* 0x74 */
    float _damping;                                     /* 0x78 */
    int _mode;                                          /* 0x7C */
    int _f80, _f84;                                     /* 0x80 */
    float _speed;                                       /* 0x88 */
    int _f8c;                                           /* 0x8C */
    math::vector_xyzw _f90;                             /* 0x90 */
    float _fa0;                                         /* 0xA0 */
    bool _fa4, _fa5, _fa6;                              /* 0xA4 */
    math::matrix _transform;                            /* 0xA8 */
};

namespace glut {
extern int screen_width;
extern int screen_height;
}

namespace app {
void set_initial_res(int, int);
int width();
int height();
float ratio();
class Callbacks {
public:
    Callbacks();
    virtual void init();
    virtual void idle();
    virtual void reshape(int, int);
    virtual void display();
    virtual ~Callbacks();
    void run();
    bool exitRequested() const;
    void exit();
private:
    bool exit_requested;
};
}

namespace app3d {
class Callbacks : public app::Callbacks {
public:
    Callbacks(unsigned int);
    virtual void init();
    virtual void idle();
    virtual ~Callbacks();
    virtual void draw();
    virtual void before_vsync();
    void reset_camera();
    void toggleGrid();
    void displayGrid(bool);
    void setSceneScale(float);
    void togglePivot();
private:
    char _pad5[0xEE1 - 5];
    bool grid;          /* 0xEE1 */
    bool pivot;         /* 0xEE2 */
    float scene_scale;  /* 0xEE4 */
};
}

class TestApp : public app3d::Callbacks {
public:
    TestApp();
    void print_help();
    void control();
};

namespace common {
extern bool no_crash;
void NoCrash(bool);
class File {
public:
    bool is_open() const;
    int flush();
private:
    struct Handle { int fd; } *handle;
};
class Date {
public:
    struct CopiableMembers {
        CopiableMembers();
        bool operator==(const CopiableMembers &) const;
        int year, month, day, hour, minute, second;
    };
    Date();
    Date(const char *);
    bool operator==(const Date &) const;
    bool operator!=(const Date &) const;
    void output(std::ostream &) const;
    void set_from_time_t(long *);
    void get_date();
    void get_file_date(const char *);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
private:
    CopiableMembers m;
};

namespace common_internal {
void on_error();
void on_warning();
void assert_display(const char *, const char *, const char *, const char *, int, const char *, ...);
void clash();
class Log {
public:
    enum Channel { };
    static Log &get(Channel);
    ~Log();
    void useHexa(bool);
private:
    bool flags[3];
    bool hexa;
};
}
common_internal::Log &Log(const char *);
}

/* depth blur (C++ linkage) */
extern int _depthrange;
extern float _focus;
extern int _depthblur_debug;
extern int depthblur_mode;
extern bool depthspread;
void DepthBlurSetRange(int);
void DepthBlurIncrRange();
void DepthBlurDecrRange();
int DepthBlurGetRange();
void DepthBlurSetFocus(float);
float DepthBlurGetFocus();
void DepthBlurCycleDebugMode();
int DepthBlurGetDebugMode();
void DepthBlurNextMode();
void DepthBlurSetMode(int);
void DepthBlurToggleSpread();

namespace libc_fix {
float AtoF(const char *);
void ItoA(char *, unsigned int, int);
void ItoAX(char *, unsigned int, int);
int AtoI(const char *);
}

namespace psp {
template<class T, class F> T convert(const F &);
}

namespace vector_font {
class Console {
public:
    void setViewport(float, float);
    void setColor(float, float, float);
private:
    char _pad0[0x18];
    float vx, vy;       /* 0x18 */
    char _pad20[8];
    float r, g, b;      /* 0x28 */
};
}

class CubeMap {
public:
    enum FaceEnum { };
    void draw_face_w(FaceEnum);
    void draw_cube_w();
};

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

namespace textures {
class Texture;
}

namespace glutils {
class CheckerTexture {
public:
    static void check_init();
    static textures::Texture *get();
    static unsigned int name();
private:
    static textures::Texture _checker_texture;
    static unsigned int _name;
};
class PositioningInterface {
public:
    void set_callback();
};
class TrackballInterface : public PositioningInterface {
public:
    void track();
};
}

namespace gl {
void PickMatrix(float, float, float, float, int *);
void ErrorCheck(const char *, int);
}

namespace scene {
class TraversalVarStack;
class Node {
public:
    void save(std::ostream &);
    void traverse(TraversalVarStack &);
    void set_default_name();
    void flatten(math::TransformStack &);
};
class Group : public Node {
public:
    void save(std::ostream &);
};
class Object : public Node {
public:
    void save(std::ostream &);
};
class Shape : public Node {
public:
    void save(std::ostream &);
};
class Setup : public Node {
public:
    void save(std::ostream &);
    void traverse(TraversalVarStack &);
    void flatten(math::TransformStack &);
    void enter();
    void leave();
};
class DefaultShader : public Node {
public:
    void flatten(math::TransformStack &);
    void save(std::ostream &);
    void traverse(TraversalVarStack &);
};
class Material : public Node {
public:
    void traverse(TraversalVarStack &);
    void flatten(math::TransformStack &);
};
class Texture : public Node {
public:
    void traverse(TraversalVarStack &);
    void flatten(math::TransformStack &);
};
class Graph {
public:
    void printMapA();
    void printMapU();
    void printMapO();
    void save_vrml(std::string);
};
}

namespace sgl {
class Heap {
public:
    void dump();
};
class MeshBuilder {
public:
    void transformListEnd();
};
class TransformSet {
public:
    class Transform {
    public:
        Transform();
    };
};
}

namespace sh {
class Matrix {
public:
    Matrix();
};
class PRT {
public:
    void import_model();
};
class VectorRGB {
public:
    void print(const char *) const;
};
}

class basic_parser {
public:
    void watch_tp(unsigned int);
};

class CCmpr {
public:
    CCmpr();
    ~CCmpr();
};

#endif
