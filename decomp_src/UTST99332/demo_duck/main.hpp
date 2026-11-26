/* C++ declarations for main.cpp (the demo's own objects; no DWARF: class
   names, methods and vtable order from the symbol table, see
   tools/dwarf2cpp.py UTST99332 demo_duck main).  Layouts are only filled in
   as far as decompiled code needs them. */
#ifndef DEMO_DUCK_MAIN_HPP
#define DEMO_DUCK_MAIN_HPP

/* vtables and typeinfo stay in the module's data: never emit them here */
#pragma interface

#include <iosfwd>
#include <string>

extern "C" {
#include "common.h"
}

namespace math {
struct TransformStack;
}

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
        int year, month, day, hour, minute, second;
    };
    Date();
    Date(const char *);
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
