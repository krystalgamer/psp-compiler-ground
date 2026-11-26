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

namespace psp {
class Pad;
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
    virtual ~shared_object_base() {
        d->obj = 0;
        if (d->count == 0)
            delete d;
    }
};

template<class T> class handle : public handle_internal::data_owner {
public:
    handle() {}
    handle(const handle &o);
    template<class U> handle(const handle<U> &o);
    virtual ~handle();
    void invalidate();
    handle &operator=(const handle &o);
    template<class U> handle &operator=(const handle<U> &o);
    T *get() const { return d ? static_cast<T *>(d->obj) : 0; }
    T *operator->() const { return static_cast<T *>(d->obj); }
    T &operator*() const { return *static_cast<T *>(d->obj); }
    bool valid() const { return d && d->obj; }
};

#ifdef DEMO_TEMPLATE_DEFS
template<class T> handle<T>::handle(const handle &o)
{
    d = o.d;
    if (d)
        d->count++;
}
template<class T> template<class U> handle<T>::handle(const handle<U> &o)
{
    d = o.d;
    if (d) {
        T *t = dynamic_cast<T *>(d->obj);
        if (t)
            d->count++;
        else
            d = 0;
    }
}
template<class T> handle<T>::~handle() { invalidate(); }
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
        T *t = dynamic_cast<T *>(o.d->obj);
        set_data(t ? t->d : 0);
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
    Log &operator<<(const char *);
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
    bool enabled;       /* 0x34 */
public:
    void enable(bool e);
};
}

class CubeMap {
public:
    enum FaceEnum { };
    struct Face {
        char _pad0[0x58];
        void init(FaceEnum f) { id = f; }
        FaceEnum id;            /* 0x58 */
        char _pad5c[0x8];
    };
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

class basic_parser {
public:
    void watch_tp(unsigned int);
    void expect_eof(bool);
    char _pad0[0x45];
    bool _expect_eof;           /* 0x45 */
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

namespace gl_ext {
extern bool use_extensions;
bool Enabled();
void Toggle();
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
    void text();
    void blocking(bool);
    /* data */
    char _p0[0x20];
    bool _f20;
    bool _f21;
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
    const void *getHits() const;
    /* data */
    char _p0[0x4];
    char _f4;
};
class StippleMask {
public:
    void *mask();
};
class TurnTable {
public:
    void setIsYUp(bool);
    bool isYUp() const;
    /* data */
    char _p0[0x1A0];
    bool _f1A0;
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
int closestPow2(int, bool);
}

#endif
