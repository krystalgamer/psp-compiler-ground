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
/* a 7-word buffer descriptor (zeroed by Vram()) */
struct VramBuffer {
    VramBuffer() : p0(0), p1(0), f8(0), fC(0), f10(0), f14(0), f18(0) {}
    void *p0, *p1;
    int f8, fC, f10, f14, f18;
};
class Vram {
public:
    Vram();
    void copyImageBegin(bool);
    void copyImageSrcPf(PixelFormat);
    void copyImageDstPf(PixelFormat);
    void copyImageEnd();
    void copyImage(int, int, int, int, void *, void *);
    void *displayBuffer() const { return f14 ? b40.p0 : b40.p1; }
    void *drawBuffer() const { return f14 ? b5C.p0 : b5C.p1; }
    int f0;
    bool f4;                /* 0x4 */
    int f8, fC, f10;        /* 0x8 */
    int f14;                /* 0x14 */
    /* a linear allocator over a VRAM range (Vram.h: load() copies data in, asserts `_cur + _Bytesize < _end`) */
    struct Area {
        unsigned int load(void *data, unsigned int _Bytesize);
        unsigned int _cur;      /* 0x00 */
        int _f4;
        unsigned int _end;      /* 0x08 */
        unsigned int _base;     /* 0x0C */
        std::string _name;      /* 0x10 */
    };
    Area a18;               /* 0x18 */
    Area a2C;               /* 0x2C */
    VramBuffer b40;         /* 0x40 */
    VramBuffer b5C;         /* 0x5C */
    PixelFormat src_pf;     /* 0x78 */
    PixelFormat dst_pf;     /* 0x7C */
    bool f80;               /* 0x80 */
    bool _copy_mode;        /* 0x81 */
};
extern Vram vram;
}

namespace psp {
void StartMainThread();
const char *GetKernelErrName(unsigned int);
}
/* app::init_glut, glut::app_ptr are file statics of glut_ReshapeFunc (it defines GLUT_STATICS) */
namespace app {
class Callbacks;
#ifndef GLUT_STATICS
extern bool init_glut;
#endif
}
namespace glut {
#ifndef GLUT_STATICS
extern app::Callbacks *app_ptr;
#endif
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

/* A unit whose tail (template instances, out-of-line inline functions: .gnu.linkonce.t sections, linked
   in the object's section order) mixes C++ and asm creates those sections up front in the original's
   order: DEMO_LINKONCE_ORDER(DEMO_LINKONCE(name) ...); (cc1plus emits implicit instances after every
   deferred function, the INCLUDE_ASM_LINKONCE asm in definition order, explicit instantiations first). */
#define DEMO_LINKONCE(n) "\t.section .gnu.linkonce.t." #n ",\"ax\",@progbits\n"
#define DEMO_LINKONCE_ORDER(s) __asm__(s "\t.text\n")
/* the rest of a function whose start splat put at the end of PREV's .s (a func_XXXXXXXX piece): it continues
   PREV's .gnu.linkonce.t section (the line still contains "INCLUDE_ASM(" for splat) */
#if defined(M2CTX) || defined(PERMUTER)
#define CONT_INCLUDE_ASM(FOLDER, NAME, PREV)
#else
#define CONT_INCLUDE_ASM(FOLDER, NAME, PREV) \
    DEFER_ASM_IN(".section .gnu.linkonce.t." #PREV ",\"ax\",@progbits", FOLDER, NAME)
#endif

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
    virtual ~data_owner();
    virtual void set_data(data *p);
    data *d;
};
/* linkonce copies: main.o (duck) / CityApp.o (harmonic) defines DEMO_LINKONCE_data_owner */
#if DEMO_LINKONCE_data_owner
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline data_owner::~data_owner() {}
inline void data_owner::set_data(data *p) { d = p; }
#if DEMO_LINKONCE_data_owner
_Pragma("interface")
#endif
}

class shared_object_base : public handle_internal::data_owner {
public:
    shared_object_base() { d = new handle_internal::data(this); }
    virtual ~shared_object_base();
    /* the data block is the object's identity: assignment keeps it (Frustum's operator= copies from 0x8) */
    shared_object_base &operator=(const shared_object_base &) { return *this; }
};
/* linkonce copies: app3d_Callbacks.o (duck) / CityApp.o (harmonic) defines DEMO_LINKONCE_shared_object_base */
#if DEMO_LINKONCE_shared_object_base
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline shared_object_base::~shared_object_base()
{
    d->obj = 0;
    if (d->count == 0)
        delete d;
}
#if DEMO_LINKONCE_shared_object_base
_Pragma("interface")
#endif

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
#ifdef DEMO_TEMPLATE_DEFS
template<class T> void Swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}
#endif
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
class CmdLine {
public:
    typedef std::vector<std::string>::const_iterator const_iterator;
    /* an option defined by defArg (names split by Token) */
    struct Option {
        Option(std::string name, unsigned int n, const char *help);
        std::string name;               /* 0x0 */
        unsigned int n;                 /* 0x4 */
        std::string help;               /* 0x8 */
        int _fC;                        /* 0xC */
    };
    CmdLine(std::string, std::string, std::string, std::string, std::string);
    static void Token(std::vector<std::string> &, std::string);
    const_iterator find_arg(const char *) const;
    bool inList(const char *) const;
    void defArg(std::string, unsigned int, const char *);
    const_iterator end() const { return _args.end(); }
    std::vector<std::string> _args;     /* 0x0 */
    std::vector<Option> _options;       /* 0xC */
};
/* linkonce copies: main.o (duck) / CityApp.o (harmonic) define DEMO_LINKONCE_CmdLine */
#if DEMO_LINKONCE_CmdLine
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline CmdLine::Option::Option(std::string name_, unsigned int n_, const char *help_) : name(name_), n(n_), help(help_), _fC(0)
{
}
#if DEMO_LINKONCE_CmdLine
_Pragma("interface")
#endif

template<class T> class safe_ptr {
public:
    safe_ptr(T q = 0) : p(q) {}
    T operator->() const { return p; }
    void destroy()
    {
        if (p) {
            delete p;
            p = 0;
        }
    }
    bool valid() const { return p != 0; }
    bool invalid() const { return p == 0; }
    T p;
};
class StateMachine {
public:
    class VirtualState {
    public:
        VirtualState(const char *);
        virtual ~VirtualState();
        virtual void update() = 0;
        virtual void draw() = 0;
        virtual void enter() = 0;
        virtual void exit() = 0;
        void pop();
        void pushChild(safe_ptr<VirtualState *>);
        void popChild();
        void change(safe_ptr<VirtualState *>);
        void update_internal();
        const char *getName();
        safe_ptr<VirtualState *> _child;    /* 0x4 */
        safe_ptr<VirtualState *> _next;     /* 0x8 */
        VirtualState *_machine;             /* 0xC: parent */
        bool _pop;                          /* 0x10 */
        std::string _name;                  /* 0x14 */
    };
    StateMachine(safe_ptr<VirtualState *>);
    virtual ~StateMachine();
    void destroy_top();
    void process();
    void setTop(safe_ptr<VirtualState *>);
    safe_ptr<VirtualState *> _top;      /* 0x4 */
    VirtualState *_f8;                  /* 0x8 */
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
    Log(const char *, bool, bool, bool, bool);
    void put(const char *);
    bool flags[3];
    bool hexa;
    char _name[256];
    bool _f104, _f105;
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
int FtoA(float, char *);
void ItoA(char *, unsigned int, int);
int ItoA(int, char *, int);
void ItoAX(char *, unsigned int, int);
int AtoI(const char *);
}

namespace psp {
template<class T, class F> T convert(const F &);
template<class T> const T Clamped(T, T, T);
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

/* interp's path interface (apps.hpp's animations, glutils::PositioningInterface); linkonce copies of
   ~VirtualQuickAnim: CityApp.o (harmonic, DEMO_LINKONCE_CityApp) / glutils_PositioningInterface.o (duck) */
namespace interp {
class VirtualQuickAnim {
public:
    virtual ~VirtualQuickAnim();
    virtual void startRecordingPath() = 0;
    virtual void addRecord() = 0;
    virtual void deleteLastRecord() = 0;
    virtual void finishRecordingPath() = 0;
    virtual bool isRecordingPath() const = 0;
    virtual void loadPath(std::string) = 0;
    virtual void savePath(std::string) = 0;
    virtual void evaluate(float) = 0;
    virtual int pathSize() const = 0;
};
#if DEMO_LINKONCE_CityApp || DEMO_LINKONCE_VirtualQuickAnim
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline VirtualQuickAnim::~VirtualQuickAnim() {}
#if DEMO_LINKONCE_CityApp || DEMO_LINKONCE_VirtualQuickAnim
_Pragma("interface")
#endif
/* P: the path (Path, VectorRGBAnim), T: its value */
template<class P, class T> class HasPathInterface : public VirtualQuickAnim {
public:
    virtual ~HasPathInterface() {}
    virtual void startRecordingPath();
    virtual void addRecord();
    virtual void deleteLastRecord();
    virtual void finishRecordingPath();
    virtual bool isRecordingPath() const;
    virtual void loadPath(std::string);
    virtual void savePath(std::string);
    virtual void evaluate(float);
    virtual int pathSize() const;
    virtual void set(T) = 0;
    virtual T get() const = 0;
    P _path;                            /* 0x4 */
};
#ifdef DEMO_TEMPLATE_DEFS
template<class P, class T> void HasPathInterface<P, T>::startRecordingPath()
{
    _path.startRecording();
}
template<class P, class T> void HasPathInterface<P, T>::addRecord()
{
    _path.addRecord(get());
}
template<class P, class T> void HasPathInterface<P, T>::deleteLastRecord()
{
    std::pair<bool, T> r = _path.deleteLastRecord();
    if (r.first)
        set(r.second);
}
template<class P, class T> void HasPathInterface<P, T>::finishRecordingPath()
{
    _path.finishRecording();
}
template<class P, class T> bool HasPathInterface<P, T>::isRecordingPath() const
{
    return _path.isRecording();
}
template<class P, class T> void HasPathInterface<P, T>::loadPath(std::string name)
{
    _path.load(name);
}
template<class P, class T> void HasPathInterface<P, T>::savePath(std::string name)
{
    _path.save(name);
}
template<class P, class T> void HasPathInterface<P, T>::evaluate(float t)
{
    set(_path.evaluate(t));
}
template<class P, class T> int HasPathInterface<P, T>::pathSize() const
{
    return _path.size();
}
#endif
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
    static void reset();
private:
    static textures::Texture _checker_texture;
    static unsigned int _name;
    static bool _init;
};
class PositioningInterface : public common::shared_object_base, public interp::HasPathInterface<interp::Path, math::Frame> {
public:
    PositioningInterface();
    virtual ~PositioningInterface();
    virtual void set_callback();
    virtual void track();               /* pure (vtable) */
    virtual void reset();               /* pure (vtable) */
    virtual void print(std::ostream &);
    virtual void save(std::string);
    virtual void load(std::string);
    virtual void set(math::Frame);
    virtual math::Frame get() const;
    const math::matrix &getTransform() const;
    const math::matrix &get_transform() const;
    const math::matrix &getTransformInverse() const;
    const math::matrix &get_inverse_transform() const;
    void set_transform(math::matrix);
    void set_inverse_transform(math::matrix);
    math::Frame _frame;                 /* 0xB0 */
    math::matrix _transform;            /* 0xD0 */
    math::matrix _inverse;              /* 0x110 */
};
namespace Params {
struct Point;
struct Arrow;
struct UnitFrame;
struct CircularArrow;
}
template<class T> class ParamsStack;
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
    TrackballInterface();
    void set_callback();
    void track();
    void reset();
    virtual ~TrackballInterface();
    math::Trackball _trackball;         /* 0x150 */
    math::vector_xyz _center;           /* 0x1E4 */
    math::matrix _m1F4;                 /* 0x1F4 */
    math::vector_xyzw _p234;            /* 0x234 */
};
/* linkonce copies: glutils_TrackballInterface.o defines DEMO_LINKONCE_TrackballInterface */
#if DEMO_LINKONCE_TrackballInterface
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline TrackballInterface::~TrackballInterface() {}
#if DEMO_LINKONCE_TrackballInterface
_Pragma("interface")
#endif
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
    void setCameraFilename(const char *);
    void setFrustum(const sgl::Frustum &);
    void resetCamera();
protected:
    /* the view frustum (0x34; sgl::Frustum is declared after base.hpp) */
    sgl::Frustum &frustum() { return *(sgl::Frustum *)((char *)this + 0x34); }
private:
    std::string _camera_filename;                           /* 0x8 */
    common::handle<glutils::PositioningInterface> _camera;  /* 0xC */
    math::Frame _initial_frame;                             /* 0x14 */
    char _pad34[0xEE1 - 0x34];
    bool grid;          /* 0xEE1 */
    bool pivot;         /* 0xEE2 */
    float scene_scale;  /* 0xEE4 */
};
}

namespace gl {
void PickMatrix(float, float, float, float, int *);
void ErrorCheck(const char *, int);
void GenTextures(int, unsigned int *);
void DeleteTextures(int, const unsigned int *);
}

struct hc_node_t {
    unsigned char type;         /* 0x0: 1 root, 2 leaf */
    hc_node_t *parent;          /* 0x4 */
    hc_node_t *child[2];        /* 0x8 */
    unsigned long item;         /* 0x10 */
    int weight;                 /* 0x14 */
};
struct hc_item_t {
    unsigned long item;         /* 0x0 */
    unsigned char nbits;        /* 0x4 */
    unsigned long code;         /* 0x8 */
};
class CCmpr {
public:
    struct PoolEntry {
        bool used;              /* 0x0 */
        hc_node_t node;         /* 0x4 */
    };
    CCmpr();
    ~CCmpr();
    void SetInputData(const void *, int);
    void *GetOutputData();
    int GetOutputSize();
    bool CreateItemList();
    bool InitNodePool();
    void FreeNodePool();
    hc_node_t *AllocateNode();
    void FreeNode(hc_node_t *);
    hc_node_t *FindLeafByItem(unsigned long);
    hc_node_t *FindRootByLeaf(hc_node_t *);
    hc_node_t *FindLeastImportantRoot(hc_node_t *);
    int CountRoots();
    int CountLeaves();
    bool AnalyzeItems();
    bool CreateHuffmanTree();
    void EncodeItem(hc_item_t *, hc_node_t *);
    bool HuffmanEncode();
    bool Compress();
    bool Uncompress();
    int input_size;             /* 0x0 */
    const void *input;          /* 0x4 */
    int output_size;            /* 0x8 */
    void *output;               /* 0xC */
    int item_count;             /* 0x10 */
    void *items;                /* 0x14 */
    int pool_size;              /* 0x18 */
    PoolEntry *pool;            /* 0x1C */
};

class BVH;   /* in sgl.hpp (its nodes hold an sgl::BV) */

namespace gl_ext {
extern bool use_extensions;
bool Enabled();
void Toggle();
void VAIOBugCheck();
}

/* accessors (generated from the asm; members named by offset) */
/* accessors (generated from the asm; members named by offset) */
namespace common {
class FileDump {
public:
    FileDump(unsigned int);
    virtual ~FileDump();
    virtual int load(const char *);     /* vtable: D1, D0, load, save (textures_internal::Bmp/Tga override load) */
    virtual int save(const char *);
    void reference_owned_data();
    void setArray(const unsigned char *, unsigned int);
    void failed(const char *, const char *, const char *);
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
class RectanglePicking : public PickingBase {
public:
    RectanglePicking();
    virtual ~RectanglePicking();
    void setStart(math::vector_xy);
    void setCurrent(math::vector_xy);
    math::vector_xy getStart() const;
    math::vector_xy getCurrent() const;
    void activate();
    void push_back(unsigned int);
    void resize(unsigned int);
    math::vector_xy _start;             /* 0x10 */
    math::vector_xy _current;           /* 0x20 */
    bool _f30;                          /* 0x30 */
    bool _f31;                          /* 0x31 */
};
/* linkonce copies: glutils_RectanglePicking.o defines DEMO_LINKONCE_RectanglePicking */
#if DEMO_LINKONCE_RectanglePicking
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline RectanglePicking::~RectanglePicking() {}
#if DEMO_LINKONCE_RectanglePicking
_Pragma("interface")
#endif
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
    void diagonal(unsigned char, bool);
    unsigned char _mask[ROWS][ROW_BYTES];
};
class TurnTable : public PositioningInterface {
public:
    enum Speed { NUM_SPEEDS = 3 };
    TurnTable();
    virtual ~TurnTable();
    void track();
    void track(bool, bool, bool, int, int);
    void setIsYUp(bool);
    bool isYUp() const;
    void speed(Speed, float);
    void setPivot(math::vector_xyzw);
    void setPivot(float, float, float);
    void setPivot(float);
    math::vector_xyzw getPivot() const;
    math::matrix getPivotFrame() const;
    /* data */
    math::vector_xyzw _pivot;   /* 0x150 */
    math::matrix _pivot_frame;  /* 0x160 */
    bool _f1A0;
    float _speed[NUM_SPEEDS];   /* 0x1A4 */
};
/* linkonce copies: glutils_TurnTable.o defines DEMO_LINKONCE_TurnTable */
#if DEMO_LINKONCE_TurnTable
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline TurnTable::~TurnTable() {}
#if DEMO_LINKONCE_TurnTable
_Pragma("interface")
#endif
}

/* accessors (generated from the asm; members named by offset) */
/* lib/gl_psp/VertexArray.h (psp_VertexArrayEdit) */
namespace psp {
typedef unsigned int u_int;
enum PixelFormatBitMask { };
std::string GetPixelFormatBitMaskName(PixelFormatBitMask);
std::string GetPixelFormatBitMaskNameFill(PixelFormatBitMask, bool);
u_int ConvertMaskInternal2Gu(unsigned int);
inline bool IsValidMask(unsigned int _Mask) { return (_Mask & 0xE000) != 0; }
class VertexArray {
public:
    void set_mask(unsigned int);
    void format(unsigned int);
    void import(VertexArray &);
    void DEBUG_printFormat();
    void clear();                       /* inline: defined after its callers in psp_VertexArrayEdit.c */
    /* data */
    std::vector<unsigned char> _data;   /* 0x00 */
    unsigned int _num_vertices;         /* 0x0C */
    unsigned int _vram_addr;            /* 0x10 */
    unsigned int _mask;                 /* 0x14 */
    u_int _gu_mask;                     /* 0x18 */
};
class VertexArrayEdit {
public:
    enum BitEnum { WA, WB, WC, WD, S, T, C, NX, NY, NZ, PX, PY, PZ, MAX_BITS, PAD1, PAD2, INVALID_BIT };
    enum BitType { NONE, UBYTE, USHORT, USHORT_5650, USHORT_5551, USHORT_4444, UINT_8888, BYTE, SHORT, FLOAT };
    enum BitGroupEnum { WEIGHT, TEXCOORD, COLOR, NORMAL, POSITION };
    enum { INFO_SIZE = 52 };
    struct Bit {
        Bit() : _enum(INVALID_BIT), _type(NONE), _size(0), _offset(-1) {}
        BitEnum _enum;
        BitType _type;
        unsigned int _size;
        int _offset;
    };
    template<class T> struct Value {
        Value(BitEnum bit, T value, unsigned int index) : _bit(bit), _value(value), _index(index) {}
        BitEnum _bit;
        T _value;
        unsigned int _index;
    };
    class Descriptor {
    public:
        Descriptor(unsigned int);
        void on_format_change();
        void set_bit_type(BitGroupEnum, BitType);
        const Bit &getBit(BitEnum) const;
        bool setFormat(unsigned int);
        int getFormat() const;
        int getBytesize() const;
        void printFormat() const;
        /* data */
        unsigned int _format;           /* 0x00 */
        Bit _bits[MAX_BITS];            /* 0x04 */
        unsigned int _bytesize;         /* 0xD4 */
        BitEnum _info[INFO_SIZE];       /* 0xD8 */
    };
    static unsigned int Sizeof(BitType);
    VertexArrayEdit(unsigned int);
    ~VertexArrayEdit();
    void begin(VertexArray &, unsigned int);
    void begin(VertexArray &);
    void end();
    void format(unsigned int);
    void clear();
    void resize(unsigned int);
    void import(const VertexArrayEdit &);
    static unsigned char map_to_255(unsigned char, unsigned int);
    void import_bit(BitEnum, unsigned int, const VertexArrayEdit &);
    void position(float, float, float);
    void normal(float, float, float);
    void texcoord(float, float);
    void color(float, float, float, float);
    void color4ub(unsigned char, unsigned char, unsigned char, unsigned char);
    void set_index(unsigned int);
    void vertex(float, float, float);
    void DEBUG_print_bit(BitEnum, unsigned int);
    void DEBUG_printVertex(unsigned int);
    void DEBUG_print(std::string);
    void DEBUG_printFormat() const;
    void save(const std::string &);
    template<class T> void set(Value<T>);
    void check_size();                  /* inline: defined in psp_VertexArrayEdit.c */
    static std::string BIT_NAMES[];
    static std::string TYPE_NAMES[];
    static bool smart_color_map;
    static unsigned char current_color[4];
    static float current_normal[3];
    static float current_texcoord[2];
    /* data */
    Descriptor _desc;                   /* 0x000 */
    unsigned int _n;                    /* 0x1A8 */
    VertexArray *_va;                   /* 0x1AC */
};
}

namespace psp {
class DisplayList {
public:
    static bool _wflag;
    void resize(unsigned int);
    void set_name(const char *);
    void finish(bool);
    char *_buf_mem;             /* 0x0 */
    char *_buf;                 /* 0x4 */
    unsigned int _capacity;     /* 0x8 */
    unsigned int _size;         /* 0xC */
    char _p10[4];
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
/* pixel formats (textures/Texture.h) */
struct ARGB {
    unsigned int c;
};
struct ABGR {
    unsigned char r, g, b, a;
};
extern bool override_alpha_on;
extern unsigned char override_alpha_value;
namespace textures_internal {
/* lib/textures/Bmp.h */
class Bmp : public common::FileDump {
public:
    Bmp() : common::FileDump(0) {}
    virtual ~Bmp();
    virtual int load(const char *);
    int num_palette_entries() const;
    static int Get4idxPixel(const unsigned char *, int, int, int);
    int _width;                         /* 0x24 */
    int _height;                        /* 0x28 */
    unsigned short _bpp;                /* 0x2C */
    char _p2e[0x38 - 0x2E];
    const unsigned char *_palette;      /* 0x38 */
    const unsigned char *_pixels;       /* 0x3C */
    int _data_offset;                   /* 0x40 */
};
/* linkonce copies: textures_textures_internal_Bmp.o defines DEMO_LINKONCE_Bmp */
#if DEMO_LINKONCE_Bmp
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline Bmp::~Bmp()
{
    _width = 0;
    _height = 0;
}
#if DEMO_LINKONCE_Bmp
_Pragma("interface")
#endif
/* lib/textures/Tga.h */
class Tga : public common::FileDump {
public:
    enum Error {
        NON_IMPLEMENTED_RLE_BLACK_AND_WHITE = -11, NON_IMPLEMENTED_RLE_TRUE_COLOR, NON_IMPLEMENTED_RLE_COLOR_MAPPED,
        WRONG_FORMAT_RLE_BLACK_AND_WHITE, WRONG_FORMAT_RLE_TRUE_COLOR, WRONG_FORMAT_RLE_COLOR_MAPPED,
        WRONG_FORMAT_BLACK_AND_WHITE, WRONG_FORMAT_TRUE_COLOR, WRONG_FORMAT_COLOR_MAPPED, WRONG_FORMAT, CANT_OPEN
    };
    Tga() : common::FileDump(0) {}
    virtual ~Tga();
    virtual int load(const char *);
    int load_error(Error, const char *);
    const unsigned char *_pixels;       /* 0x24 */
    unsigned char _id_length;           /* 0x28 */
    unsigned char _colormap_type;       /* 0x29 */
    unsigned char _image_type;          /* 0x2A */
    const unsigned char *_id;           /* 0x2C */
    const unsigned char *_colormap;     /* 0x30 */
    unsigned short _cmap_first;         /* 0x34 */
    unsigned short _cmap_length;        /* 0x36 */
    unsigned char _cmap_depth;          /* 0x38 */
    unsigned short _x_origin;           /* 0x3A */
    unsigned short _y_origin;           /* 0x3C */
    unsigned short _width;              /* 0x3E */
    unsigned short _height;             /* 0x40 */
    unsigned char _pixel_depth;         /* 0x42 */
    unsigned char _descriptor;          /* 0x43 */
    unsigned char _alpha_bits;          /* 0x44 */
    unsigned char _origin;              /* 0x45 */
};
/* linkonce copies: textures_textures_internal_Tga.o defines DEMO_LINKONCE_Tga */
#if DEMO_LINKONCE_Tga
_Pragma("implementation \"sgl_linkonce\"") _Pragma("interface \"sgl_linkonce\"")
#endif
inline Tga::~Tga()
{
}
#if DEMO_LINKONCE_Tga
_Pragma("interface")
#endif
}

/* units that keep the module's "" (asm .rodata) define this to an extern label */
#ifndef TEXTURE_EMPTY_PATH
#define TEXTURE_EMPTY_PATH ""
#endif
class Texture {
public:
    struct LoadedInfo {
        LoadedInfo() : width(0), height(0), alpha_flags((AlphaMask)0) {}
        int width;
        int height;
        AlphaMask alpha_flags;
    };
    struct CopiableMembers {
        CopiableMembers() : width(0), height(0), format((Format)0), flags(0), path(TEXTURE_EMPTY_PATH),
            alpha_flags((AlphaMask)0), loaded(false) {}
        /* separate members, not a nested struct: operator= loads all four before storing them */
        int width;                  /* 0x00 */
        int height;                 /* 0x04 */
        Format format;              /* 0x08 */
        unsigned int flags;         /* 0x0C: bit 0 filtering, 1-2 texture function, 3 wrap s, 4 wrap t */
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
    void initGl(int);
    bool setupGl(int, bool);
    void setGlFiltering(int);
    void setGlWrapS(int);
    void setGlWrapT(int);
    void setGlTextureFunc();
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
    bool make_from_bmp(const textures_internal::Bmp &);
    bool make_from_tga(const textures_internal::Tga &);
    void make_from_argb(int, const unsigned char *);
    void makeDummy(int, int);
    void make(int, int, Format);
    void print(std::ostream &);
    void swap(Texture &);
    int load(const char *);
    bool is32() const;
    void drawGL();
    void convert32();
    void alphaHalfBias();
    void finish_load();
    void psp_reorder();
    void makeImportForDirectX(int, int);
    void flipVertical();
    void resize_channel_nearest(Texture &, Channel);
    void resize_channel_bicubic(Texture &, Channel, math::bspline::surface &);
    void resize_nearest(int, int);
    void resize_bicubic(int, int);
    bool resize(int, int, bool);
    void resizePow2(bool, bool, bool);
    bool isPow2();
    static bool IsPow2(int x) { return ((x | 0x80000000) & (x - 1)) == 0; }
    void setChannel(Channel, unsigned char);
    void invertChannel(Channel);
    void copyChannel(Channel, unsigned char *);
    void copyChannel(Channel, Channel);
    void copy(const Texture &, int, int, int, int, int, int);
    int saveChannel(Channel, const char *) const;
    int save(const std::string &) const;
    int save(const std::string &, int, int, int, int) const;
    int saveTga(const std::string &) const;
    int saveBmp(const std::string &) const;
    void blur(int, float);
    void allocate(unsigned int, unsigned int);
    int setAlphaCount(int *, int *, int *, unsigned char, unsigned char);
    void allocate_for(Format);
    template<class D, class S> void convert();
    CopiableMembers m;              /* 0x00 */
    common::t_array<unsigned char> image;   /* 0x28 */
    common::t_array<unsigned char> clut;    /* 0x3C */
};
const char *FormatName(Format);
void SaveBmp(const char *, int, int, const unsigned char *, const unsigned char *, int);
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
        /* holds the texture as a member (its ctor/dtor call textures::Texture's C1/D1) */
        class Texture {
        public:
            Texture();
            ~Texture();
            ::textures::Texture t;  /* 0x00 */
            int _f50;           /* 0x50: textures::Texture's own last word (initGl), see textures_Texture.c */
            unsigned int _id;   /* 0x54: GL texture name */
        };
        Face() : tc_min(0), tc_max(1) {}
        void init(FaceEnum f) { id = f; }
        Texture tex;            /* 0x00 */
        FaceEnum id;            /* 0x58 */
        float tc_min;           /* 0x5C: texture coordinates of the face's edges (half a texel inside) */
        float tc_max;           /* 0x60 */
    };
    CubeMap();
    void setBasename(const char *);
    void load();
    void draw(bool);
    void draw_face_w(FaceEnum);
    void draw_cube_w();
    void init_face(FaceEnum);
    void init_texture(Face::Texture &);
    void load_face_texture(FaceEnum);
    void face_setup_debug(FaceEnum);
    void face_setup(FaceEnum);
    void draw_face(FaceEnum);
    void draw_cube();
    static const std::string &GetFaceName(int);
    static const float *GetFaceTransform(int);
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

/* cxx-math3's parser/image classes (basic_parser, basic_file_parser, FieldParser, FloatImage, ...) */
#include <stack>
#include "parser.hpp"

#endif
