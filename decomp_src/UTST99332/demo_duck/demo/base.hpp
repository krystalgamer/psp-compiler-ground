/* the demo's support library: psp::, app/app3d::Callbacks, common::, glutils::, gl::, textures::, vector_font::, CubeMap, parsers, DepthBlur */
#ifndef DEMO_DUCK_DEMO_BASE_HPP
#define DEMO_DUCK_DEMO_BASE_HPP

extern "C" {
#include "psptypes.h"
#include "libgu.h"
#include "libgum.h"
void *sceGeEdramGetAddr(void);
void sceGuTexLevelMode(unsigned int mode, float bias);
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
};
}

class CubeMap {
public:
    enum FaceEnum { };
    void draw_face_w(FaceEnum);
    void draw_cube_w();
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
};

class CCmpr {
public:
    CCmpr();
    ~CCmpr();
};

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

/* accessors (generated from the asm; members named by offset) */
namespace textures {
class Texture {
public:
    int width() const;
    int height() const;
    int format() const;
    int alpha_flags() const;
    int getLoadedAlphaflags() const;
    /* data */
    int _f0;
    int _f4;
    int _f8;
    char _pC[0x8];
    int _f14;
    char _p18[0xC];
    int _f24;
};
}

#endif
