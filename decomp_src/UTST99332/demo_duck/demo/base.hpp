/* the demo's support library: psp::, app/app3d::Callbacks, common::, glutils::, gl::, textures::, vector_font::, CubeMap, parsers, DepthBlur */
#ifndef DEMO_DUCK_DEMO_BASE_HPP
#define DEMO_DUCK_DEMO_BASE_HPP

extern "C" {
#include "psptypes.h"
#include "libgu.h"
#include "libgum.h"
void *sceGeEdramGetAddr(void);
void sceGuTexLevelMode(unsigned int mode, float bias);
void sceGuShadeModel(int mode);
void sceGumTranslate(const ScePspFVector3 *v);
}

namespace psp {
enum PixelFormat { };
class Vram {
public:
    void copyImageBegin(bool);
    void copyImageSrcPf(PixelFormat);
    void copyImageDstPf(PixelFormat);
    void copyImageEnd();
    void copyImage(int, int, int, int, void *, void *);
    void *displayBuffer() const { return f14 ? f40 : f44; }
    char _pad0[0x14];
    int f14;                /* 0x14 */
    char _pad18[0x28];
    void *f40, *f44;        /* 0x40 */
    char _pad48[0x20];
    unsigned int f68;       /* 0x68 */
    char _pad6c[0xC];
    PixelFormat src_pf;     /* 0x78 */
    PixelFormat dst_pf;     /* 0x7C */
};
extern Vram vram;
}

namespace psp {
void StartMainThread();
const char *GetKernelErrName(unsigned int);
}
namespace app {
class Callbacks;
extern bool init_glut;
}
namespace glut {
extern app::Callbacks *app_ptr;
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


/* buttons: 12 x {down, ?, ?, press, ?} (psp::pad()'s static Pad is zeroed
   button by button); down()/press() assert(i < 12), folded away for the
   constant indices the demos use */
namespace psp {
enum PadB { };
}
namespace input {
template<class T> class ButtonSet {
public:
    enum { N = 12 };
    struct Button {
        Button() : down(false), f1(false), f2(false), press(false), f4(false) {}
        bool down, f1, f2, press, f4;
    };
    void set(unsigned int, bool);
    bool down(unsigned int i) const { return b[i].down; }
    bool press(unsigned int i) const { return b[i].press; }
    Button b[N];
};
}
namespace psp {
class Pad : public input::ButtonSet<PadB> {
};
Pad &pad();
}

/* Template members defined out of class (handle<>, t_array<>, t_array2d<>):
   the compiler never auto-inlines them (weak instances don't bind locally), so
   callers only need the declarations.  Their definitions are compiled only with
   DEMO_TEMPLATE_DEFS defined (in a unit whose object holds the instances; add
   `extern template` for the instances that object doesn't have), since an
   object that implicitly instantiated them in the original had its copies
   discarded by the linker (.gnu.linkonce). */

/* reference-counted handles: a shared_object_base owns a handle_internal::data
   {count, object}; handle<T> points to it and counts; the object nulls
   data::obj when it dies, the last handle frees the data. */
namespace common {
class shared_object_base;
namespace handle_internal {
struct data {
    data(shared_object_base *o) : count(0), obj(o) {}
    int count;
    shared_object_base *obj;
};
class data_owner {
public:
    data_owner() : d(0) {}
    virtual ~data_owner() {}
    virtual void set_data(data *p) { d = p; }
    data *d;
};
}

class shared_object_base : public handle_internal::data_owner {
public:
    shared_object_base() { d = new handle_internal::data(this); }
    virtual ~shared_object_base() {
        d->obj = 0;
        if (d->count == 0)
            delete d;
    }
};

template<class T> class handle : public handle_internal::data_owner {
public:
    handle() { d = 0; }
    handle(T *p) {
        if (p) {
            d = p->d;
            d->count++;
        }
    }
    handle(const handle &o) {
        d = o.d;
        if (d)
            d->count++;
    }
    template<class U> handle(const handle<U> &o);
    virtual ~handle() { invalidate(); }
    void invalidate();
    handle &operator=(const handle &o);
    template<class U> handle &operator=(const handle<U> &o);
    T *get() const { return d ? dynamic_cast<T *>(d->obj) : 0; }
    T *operator->() const { return dynamic_cast<T *>(d->obj); }
    T &operator*() const { return *dynamic_cast<T *>(d->obj); }
    bool valid() const { return d && get(); }
};

#ifdef DEMO_TEMPLATE_DEFS
template<class T> template<class U> handle<T>::handle(const handle<U> &o)
{
    d = o.d;
    if (d) {
        if (operator->())
            d->count++;
        else
            d = 0;
    }
}
template<class T> void handle<T>::invalidate()
{
    if (d) {
        if (--d->count == 0) {
            if (d->obj)
                delete d->obj;
            else
                delete d;
        }
        set_data(0);
    }
}
template<class T> handle<T> &handle<T>::operator=(const handle &o)
{
    if (d != o.d) {
        invalidate();
        set_data(o.d);
        if (d)
            d->count++;
    }
    return *this;
}
template<class T> template<class U> handle<T> &handle<T>::operator=(const handle<U> &o)
{
    if (d != o.d) {
        invalidate();
        handle_internal::data *n;
        if (T *t = dynamic_cast<T *>(o.d->obj))
            n = t->d;
        else
            n = 0;
        set_data(n);
        if (d)
            d->count++;
    }
    return *this;
}
#endif
}

/* arrays: t_array<T> {vptr; Members {size, data, owner}; T dummy (at()'s
   out-of-range result)}, t_array2d<T> adds Dim {nx, ny} */
namespace common {
/* defined as { T t = a; a = b; b = t; } (byte-exact); only declared while
   units still have its instances as asm (else: duplicate symbols) */
template<class T> void Swap(T &a, T &b);
/* v[i] = x, growing v as needed */
template<class V, class T> void setAt(unsigned int i, V &v, T x);
#ifdef DEMO_TEMPLATE_DEFS
template<class V, class T> void setAt(unsigned int i, V &v, T x)
{
    /* near-miss (sh_TestEnvSet_TestEnv's instance: register allocation differs) */
    unsigned int n = i + 1;
    if (i >= v.size())
        v.resize(n);
    v[i] = x;
}
#endif

template<class T> class t_array {
public:
    struct Members {
        Members() : size(0), data(0), owner(true) {}
        unsigned int size;
        T *data;
        bool owner;
    };
    t_array();
    t_array(unsigned int n);
    virtual void swap(t_array &o);
    virtual void release();
    virtual void resize(unsigned int n);
    virtual void fill(const T &v);
    virtual ~t_array();
    t_array &operator=(const t_array &o);
    void allocate(unsigned int n);
    T *addr();
    const T *addr() const;
    unsigned int size() const;
    unsigned int bytesize() const;
    bool empty() const;
    Members m;
    T dummy;
};

#ifdef DEMO_TEMPLATE_DEFS
template<class T> t_array<T>::t_array() {}
template<class T> t_array<T>::t_array(unsigned int n) { allocate(n); }
template<class T> void t_array<T>::swap(t_array &o) { Swap(m, o.m); }
template<class T> void t_array<T>::release()
{
    if (m.owner && m.data)
        delete[] m.data;
    m = Members();
}
template<class T> void t_array<T>::resize(unsigned int n) { allocate(n); }
template<class T> void t_array<T>::fill(const T &v)
{
    for (unsigned int i = 0; i != m.size; i++)
        m.data[i] = v;
}
template<class T> t_array<T>::~t_array() { release(); }
template<class T> t_array<T> &t_array<T>::operator=(const t_array &o)
{
    allocate(o.m.size);
    for (unsigned int i = 0; i != m.size; i++)
        m.data[i] = o.m.data[i];
    return *this;
}
template<class T> void t_array<T>::allocate(unsigned int n)
{
    if (n == m.size && m.owner)
        return;
    release();
    if (n) {
        m.data = new T[n];
        m.size = n;
        m.owner = true;
    }
}
template<class T> T *t_array<T>::addr() { return m.data; }
template<class T> const T *t_array<T>::addr() const { return m.data; }
template<class T> unsigned int t_array<T>::size() const { return m.size; }
template<class T> unsigned int t_array<T>::bytesize() const { return m.size * sizeof(T); }
template<class T> bool t_array<T>::empty() const { return m.size == 0; }
#endif

template<class T> class t_array2d : public t_array<T> {
public:
    struct Dim {
        Dim() : nx(0), ny(0) {}
        Dim(int x, int y) : nx(x), ny(y) {}
        int nx, ny;
    };
    t_array2d();
    t_array2d(unsigned int nx, unsigned int ny);
    virtual void release();
    virtual ~t_array2d();
    virtual void swap(t_array2d &o);
    virtual void resize(unsigned int nx, unsigned int ny);
    virtual void resizex(unsigned int nx);
    virtual void resizey(unsigned int ny);
    virtual void copy(const t_array2d &src, int x, int y, int sx, int sy, int w, int h);
    t_array2d &operator=(const t_array2d &o);
    int nx() const;
    int ny() const;
    T &at(int x, int y);
    const T &at(int x, int y) const;
    Dim dim;
};

#ifdef DEMO_TEMPLATE_DEFS
template<class T> t_array2d<T>::t_array2d() {}
template<class T> t_array2d<T>::t_array2d(unsigned int nx, unsigned int ny) : t_array<T>(nx * ny), dim(nx, ny) {}
template<class T> void t_array2d<T>::release()
{
    t_array<T>::release();
    dim = Dim();
}
template<class T> t_array2d<T>::~t_array2d() {}
template<class T> void t_array2d<T>::swap(t_array2d &o)
{
    Swap(dim, o.dim);
    t_array<T>::swap(o);
}
template<class T> void t_array2d<T>::resize(unsigned int nx, unsigned int ny)
{
    t_array<T>::resize(nx * ny);
    dim.nx = nx;
    dim.ny = ny;
}
template<class T> void t_array2d<T>::resizex(unsigned int nx)
{
    t_array<T>::resize(nx * dim.ny);
    dim.nx = nx;
}
template<class T> void t_array2d<T>::resizey(unsigned int ny)
{
    t_array<T>::resize(dim.nx * ny);
    dim.ny = ny;
}
template<class T> void t_array2d<T>::copy(const t_array2d &src, int x, int y, int sx, int sy, int w, int h)
{
    for (int j = 0; j != h; j++)
        for (int i = 0; i != w; i++)
            at(x + i, y + j) = src.at(sx + i, sy + j);
}
template<class T> t_array2d<T> &t_array2d<T>::operator=(const t_array2d &o)
{
    t_array<T>::operator=(o);
    dim = o.dim;
    return *this;
}
template<class T> int t_array2d<T>::nx() const { return dim.nx; }
template<class T> int t_array2d<T>::ny() const { return dim.ny; }
template<class T> T &t_array2d<T>::at(int x, int y)
{
    if (x < 0 || x >= dim.nx || y < 0 || y >= dim.ny)
        return this->dummy;
    return this->addr()[x + y * dim.nx];
}
template<class T> const T &t_array2d<T>::at(int x, int y) const
{
    if (x < 0 || x >= dim.nx || y < 0 || y >= dim.ny)
        return this->dummy;
    return this->addr()[x + y * dim.nx];
}
#endif
}

namespace common {
template<class T> class safe_ptr {
public:
    T p;
};
class StateMachine {
public:
    class VirtualState {
    public:
        VirtualState(const char *);
        virtual ~VirtualState();
        void pop();
        void pushChild(safe_ptr<VirtualState *>);
        void popChild();
        void change(safe_ptr<VirtualState *>);
        void update_internal();
        const char *getName();
        char _p4[0xC - 4];
        StateMachine *_machine;         /* 0xC */
        char _p10[0x14 - 0x10];
        std::string _name;              /* 0x14 */
    };
    StateMachine(safe_ptr<VirtualState *>);
    virtual ~StateMachine();
    void destroy_top();
    void process();
    void setTop(safe_ptr<VirtualState *>);
    char _p4[8 - 4];
    safe_ptr<VirtualState *> _next;     /* 0x8 */
    char _pc[0x10 - 0xC];
    bool _pop;                          /* 0x10 */
};

extern bool no_crash;
void NoCrash(bool);
class File {
public:
    enum Pos { };
    File();
    ~File();
    unsigned int write(const void *, unsigned int, unsigned int);
    unsigned int read(void *, unsigned int, unsigned int);
    bool open(const char *, const char *);
    int flush();
    bool close();
    bool puts(const char *);
    bool getc(char &);
    long bytesize();
    long tell();
    bool seek(long, Pos);
    bool is_open() const;
private:
    struct Handle {
        Handle() : fd(-1), pos(0) {}
        int fd;
        int pos;
    } *handle;
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
    Log &operator<<(const char *);
    Log &operator<<(const unsigned char *);
    Log &operator<<(const std::string &);
    Log &operator<<(bool);
    Log &operator<<(int);
    Log &operator<<(unsigned int);
    Log &operator<<(float);
    void useHexa(bool);
private:
    bool flags[3];
    bool hexa;
};
}
common_internal::Log &Log(const char * = 0);
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
void DepthBlurIncrFocus();
void DepthBlurDecrFocus();
float DepthBlurGetFocus();
void DepthBlurPrint();
void DepthBlurUpdate();
void DepthBlurDraw();
void DepthBlurIdle();
void DepthBlurCycleDebugMode();
int DepthBlurGetDebugMode();
void DepthBlurNextMode();
void DepthBlurSetMode(int);
void DepthBlurToggleSpread();

namespace libc_fix {
float AtoF(const char *);
void FtoA(float, char *);
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
    struct Line {
        bool full() const { return _pos >= _text.size(); }
        void put(char c)
        {
            if (!full()) {
                _text[_pos] = c;
                _pos++;
            }
        }
        std::string _text;
        unsigned int _pos;
    };
    Console(unsigned int, unsigned int);
    void resize(unsigned int, unsigned int);
    void enable(bool e);
    void clear();
    Console &operator<<(float);
    Console &operator<<(int);
    Console &operator<<(unsigned int);
    Console &operator<<(const char *);
    Console &operator<<(const std::string);
    Console &operator<<(char);
    void put(char);
    void draw() const;
    void setViewport(float, float);
    void setColor(float, float, float);
private:
    unsigned int _num_columns;          /* 0x00 */
    unsigned int _num_lines;            /* 0x04 */
    std::vector<Line> _lines;           /* 0x08 */
    std::vector<Line>::iterator _cur;   /* 0x14 */
    float vx, vy;                       /* 0x18 */
    float sx, sy;                       /* 0x20 */
    float r, g, b;                      /* 0x28 */
    bool enabled;                       /* 0x34 */
};
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
class PositioningInterface : public common::shared_object_base {
public:
    virtual void set_callback();
    virtual void track();
    virtual void reset();
    const math::matrix &getTransform() const;
    const math::matrix &get_transform() const;
    const math::matrix &getTransformInverse() const;
    const math::matrix &get_inverse_transform() const;
    char _p8[0xD0 - 8];                 /* 0x8: interp::HasPathInterface<Path, Frame> base, ... */
    math::matrix _transform;            /* 0xD0 */
    math::matrix _inverse;              /* 0x110 */
};
namespace Params {
struct Point;
struct Arrow;
struct UnitFrame;
struct CircularArrow;
}
template<class T> class ParamsStack {
public:
    void pop();
};
extern ParamsStack<Params::Point> _point_pstack;
extern ParamsStack<Params::Arrow> _arrow_pstack;
extern ParamsStack<Params::UnitFrame> _unit_frame_pstack;
extern ParamsStack<Params::CircularArrow> _circular_arrow_pstack;
void PushPointParams();
void PopPointParams();
void PushArrowParams();
void PopArrowParams();
void PushUnitFrameParams();
void PopUnitFrameParams();
void PushCircularArrowParams();
void PopCircularArrowParams();
void DrawCube(float);
void DrawCube(float, float, float);
class TrackballInterface : public PositioningInterface {
public:
    void track();
};
}

namespace sgl {
class Frustum;
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
    common::handle<glutils::PositioningInterface> getCamera();
    const common::handle<glutils::PositioningInterface> &getCamera() const;
    void replaceCamera(common::handle<glutils::PositioningInterface>);
protected:
    /* the view frustum (0x34; sgl::Frustum is declared after base.hpp) */
    sgl::Frustum &frustum() { return *(sgl::Frustum *)((char *)this + 0x34); }
private:
    char _pad5[0xC - 5];
    common::handle<glutils::PositioningInterface> _camera;  /* 0xC */
    char _pad14[0xEE1 - 0x14];
    bool grid;          /* 0xEE1 */
    bool pivot;         /* 0xEE2 */
    float scene_scale;  /* 0xEE4 */
};
}

namespace gl {
void PickMatrix(float, float, float, float, int *);
void ErrorCheck(const char *, int);
}

class basic_parser {
public:
    void watch_tp(unsigned int);
    void expect_eof(bool);
    void clear_c_str();
    char _pad0[0x30];
    common::t_array<char> _c_str;   /* 0x30 */
    bool _c_str_cleared;            /* 0x44 */
    bool _expect_eof;               /* 0x45 */
};

class CCmpr {
public:
    CCmpr();
    ~CCmpr();
    void SetInputData(const void *, int);
    void *GetOutputData();
    int GetOutputSize();
    int input_size;             /* 0x0 */
    const void *input;          /* 0x4 */
    int output_size;            /* 0x8 */
    void *output;               /* 0xC */
};

class BVH {
public:
    struct Node {
        ~Node();
        void draw() const;
        char _p0[0x16C];
    };
    BVH();
    void draw() const;
    void print();
    void print(Node *);
    Node _root;
};

namespace gl_ext {
extern bool use_extensions;
bool Enabled();
void Toggle();
void VAIOBugCheck();
}

/* accessors (generated from the asm; members named by offset) */
class basic_file_parser {
public:
    bool ready() const;
    /* data */
    char _p0[0x50];
    bool _f50;
};

/* accessors (generated from the asm; members named by offset) */
namespace common {
class FileDump {
public:
    FileDump(unsigned int);
    virtual ~FileDump();
    void reference_owned_data();
    void setArray(const unsigned char *, unsigned int);
    void failed(const char *, const char *, const char *);
    int save(const char *);
    int load(const char *);
    void binary();
    void text();
    void blocking(bool);
    /* data */
    t_array<unsigned char> _data;       /* 0x04 */
    const unsigned char *_ptr;          /* 0x18 */
    unsigned int _size;                 /* 0x1C */
    bool _f20;                          /* 0x20: binary */
    bool _f21;                          /* 0x21: blocking (assert on failure) */
};
}

/* accessors (generated from the asm; members named by offset) */
namespace gl {
bool find_texture(unsigned int);
bool CheckTextures();
}

/* accessors (generated from the asm; members named by offset) */
namespace glutils {
class PickingBase {
public:
    PickingBase();
    virtual ~PickingBase() {}
    const std::vector<unsigned int> &getHits() const;
    std::vector<unsigned int> _hits;    /* 0x4 */
};
class Picking : public PickingBase {
public:
    static float THRESHOLD;
    Picking(int);
    Picking(const Picking &);
    Picking operator=(const Picking &);
    virtual ~Picking();
    unsigned int processHits(int, bool);
    void begin(float, float, float, float);
    void begin_internal(float, float, float, float);
    void end();
    int _size;                          /* 0x10 */
    unsigned int *_buffer;              /* 0x14 */
};
class StippleMask {
public:
    enum { ROWS = 32, ROW_BYTES = 4 };
    StippleMask();
    void clear();
    void setPixel(unsigned int, unsigned int, bool);
    void *mask();
    void sparse(unsigned char, unsigned char);
    void sparse(unsigned char);
    void checker(unsigned char, unsigned char);
    void checker(unsigned char);
    unsigned char _mask[ROWS][ROW_BYTES];
};
class TurnTable : public PositioningInterface {
public:
    enum Speed { NUM_SPEEDS = 3 };
    void track(bool, bool, bool, int, int);
    void setIsYUp(bool);
    bool isYUp() const;
    void speed(Speed, float);
    math::vector_xyzw getPivot() const;
    /* data */
    math::vector_xyzw _pivot;   /* 0x150 */
    char _p160[0x1A0 - 0x160];
    bool _f1A0;
    float _speed[NUM_SPEEDS];   /* 0x1A4 */
};
}

/* accessors (generated from the asm; members named by offset) */
namespace psp {
class VertexArrayEdit {
public:
    class Descriptor {
    public:
        int getFormat() const;
        int getBytesize() const;
        /* data */
        int _f0;
        char _p4[0xD0];
        int _fD4;
    };
};
}

namespace psp {
class DisplayList {
public:
    static bool _wflag;
    void resize(unsigned int);
    void set_name(const char *);
    void finish(bool);
    char _p0[0x14];
    char _name[32];             /* 0x14 */
};
}

namespace textures {
enum Format { FORMAT_0, FORMAT_1, FORMAT_2, FORMAT_3, FORMAT_4, FORMAT_5 };
enum AlphaMask { ALPHA_BLEND = 2, ALPHA_TEST = 4 };
enum TextureFunction { };
enum Filtering { };
enum Wrapping { };
enum Channel { };
extern bool override_alpha_on;
extern unsigned char override_alpha_value;
namespace textures_internal {
class Bmp;
class Tga;
}

class Texture {
public:
    struct Info {
        Info() : width(0), height(0), format((Format)0), flags(0) {}
        int width;                  /* 0x00 */
        int height;                 /* 0x04 */
        Format format;              /* 0x08 */
        unsigned int flags;         /* 0x0C: bit 0 filtering, 1-2 texture function, 3 wrap s, 4 wrap t */
    };
    struct LoadedInfo {
        LoadedInfo() : width(0), height(0), alpha_flags(0) {}
        int width;
        int height;
        int alpha_flags;
    };
    struct CopiableMembers {
        CopiableMembers() : path(""), alpha_flags((AlphaMask)0), loaded(false) {}
        Info info;                  /* 0x00 */
        std::string path;           /* 0x10 */
        AlphaMask alpha_flags;      /* 0x14 */
        bool loaded;                /* 0x18 */
        LoadedInfo load;            /* 0x1C */
    };
    Texture &operator=(const Texture &);
    Texture();
    Texture(int, int, Format);
    Texture(int, int, const Texture &);
    ~Texture();
    void reset(bool);
    Texture(const Texture &);
    int width() const;
    int height() const;
    Format format() const;
    const char *path() const;
    AlphaMask alpha_flags() const;
    const unsigned char *imagedata() const;
    const unsigned char *clutdata() const;
    int getLoadedWidth() const;
    int getLoadedHeight() const;
    int getLoadedAlphaflags() const;
    void setAlphaFlags(AlphaMask);
    void setTextureFunc(TextureFunction);
    TextureFunction getTextureFunc() const;
    void setFiltering(Filtering);
    Filtering getFiltering() const;
    void setWrapS(Wrapping);
    Wrapping getWrapS() const;
    void setWrapT(Wrapping);
    Wrapping getWrapT() const;
    void linear();
    void nearest();
    bool valid() const;
    bool invalid() const;
    void setPath(std::string);
    static void OverrideAlpha(int);
    void set_4idx_pixel(int, int, unsigned char);
    void make_from_bmp(const textures_internal::Bmp &);
    void make_from_tga(const textures_internal::Tga &);
    void make_from_argb(int, const unsigned char *);
    void makeDummy(int, int);
    void make(int, int, Format);
    void print(std::ostream &);
    void swap(Texture &);
    bool load(const char *);
    bool is32() const;
    void convert32();
    void alphaHalfBias();
    void finish_load();
    void psp_reorder();
    void makeImportForDirectX(int, int);
    void flipVertical();
    void resize(int, int, bool);
    bool isPow2();
    static bool IsPow2(int x) { return ((x | 0x80000000) & (x - 1)) == 0; }
    void setChannel(Channel, unsigned char);
    void invertChannel(Channel);
    void copyChannel(Channel, unsigned char *);
    void copyChannel(Channel, Channel);
    void copy(const Texture &, int, int, int, int, int, int);
    bool save(const std::string &) const;
    bool saveTga(const std::string &) const;
    bool saveBmp(const std::string &) const;
    void blur(int, float);
    void allocate(unsigned int, unsigned int);
    void allocate_for(Format);
    CopiableMembers m;              /* 0x00 */
    common::t_array<unsigned char> image;   /* 0x28 */
    common::t_array<unsigned char> clut;    /* 0x3C */
};
const char *FormatName(Format);
void SaveTga(const char *, int, int, const unsigned char *, int);
void SaveGlBuffer(const char *, int);
void TgaSnapshot(const char *);
void TgaAutoNamedSnapshot(const char *);
int closestPow2(int, bool);
}

class CubeMap {
public:
    enum FaceEnum { };
    struct Face {
        class Texture : public ::textures::Texture {
        public:
            Texture();
            ~Texture();
            int _f50;
            unsigned int name;  /* 0x54: GL texture name */
        };
        void init(FaceEnum f) { id = f; }
        Texture tex;            /* 0x00 */
        FaceEnum id;            /* 0x58 */
        char _pad5c[0x8];
    };
    CubeMap();
    void setBasename(const char *);
    void load();
    void draw(bool);
    void draw_face_w(FaceEnum);
    void draw_cube_w();
    void init_face(FaceEnum);
    void setCubeSize(float);
    void setLinear(bool);
    void setResize(int);
    const std::string &getBasename() const;
    void toggleTextures();
    void toggleFiltering();
    void toggleWireframe();
    Face faces[6];              /* 0x000 */
    std::string basename;       /* 0x258 */
    bool linear;                /* 0x25C */
    float cube_size;            /* 0x260 */
    int resize;                 /* 0x264 */
    bool textures;              /* 0x268 */
    bool wireframe;             /* 0x269 */
};

#endif
