/* the applications: CityApp (demo_harmonic), TestApp (demo_duck) */
#ifndef DEMO_DUCK_DEMO_APPS_HPP
#define DEMO_DUCK_DEMO_APPS_HPP

extern "C" void menuInit(void);

void run_city();
void run_ahiru();

/* demo_harmonic's animations (CityApp.o holds the instances / linkonce copies: DEMO_LINKONCE_CityApp) */
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
#if DEMO_LINKONCE_CityApp
SGL_LINKONCE_BEGIN
#endif
inline VirtualQuickAnim::~VirtualQuickAnim() {}
#if DEMO_LINKONCE_CityApp
SGL_LINKONCE_END
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
class SHLAnimation : public HasPathInterface<VectorRGBAnim, sh::VectorRGB> {
public:
    virtual ~SHLAnimation();
    virtual void set(sh::VectorRGB v);
    virtual sh::VectorRGB get() const;
    VectorRGBAnim _anim;                /* 0x1BC */
    sh::VectorRGB _value;               /* 0x374 */
};
#if DEMO_LINKONCE_CityApp
SGL_LINKONCE_BEGIN
#endif
inline SHLAnimation::~SHLAnimation() {}
inline void SHLAnimation::set(sh::VectorRGB v)
{
    _value = v;
}
inline sh::VectorRGB SHLAnimation::get() const
{
    return _value;
}
#if DEMO_LINKONCE_CityApp
SGL_LINKONCE_END
#endif
}

namespace glutils {
/* a trackball whose transform can be recorded/played back as a path */
class AnimableTrackball : public interp::HasPathInterface<interp::Path, math::Frame>, public math::Trackball {
public:
    AnimableTrackball(const math::matrix &);
    virtual ~AnimableTrackball();
    virtual void set(math::Frame);
    virtual math::Frame get() const;
};
#if DEMO_LINKONCE_CityApp
SGL_LINKONCE_BEGIN
#endif
inline AnimableTrackball::~AnimableTrackball() {}
#if DEMO_LINKONCE_CityApp
SGL_LINKONCE_END
#endif
}

/* demo_harmonic's application */
class CityApp : public app3d::Callbacks {
public:
    enum ControledObject { };
    class Car;
    CityApp();
    void init_lights();
    void camera_idle();
    void envChange();
    float get_anim_time() const;
    void all_modes_idle();
    void set_control(ControledObject);
    void zrange_idle();
    void depthblur_idle();
    void cycle_depth_settings();
    /* cycle_depth_settings()'s SETTINGS[] */
    struct DepthSetting {
        DepthSetting(float f, int r) : focus(f), range(r) {}
        float focus;
        int range;
    };
    void light_source_idle();
    math::matrix get_light_transform() const;
    void draw_scene_graph();
private:
    char _pad[0xF14 - 0xEE8];
    scene::Graph _graph;                /* 0xF14 */
    char _pad100c[0x10C4 - 0xF14 - sizeof(scene::Graph)];
    math::Trackball _light_trackball;   /* 0x10C4 */
    math::Trackball _light_trackball2;  /* 0x1158 */
    char _pad11ec[0x11EC - 0x10C4 - 2 * sizeof(math::Trackball)];
    ControledObject _control;   /* 0x11EC */
    char _pad11f0[0x1230 - 0x11F0];
    float _f1230;               /* 0x1230 */
    char _pad1234[0x1244 - 0x1234];
    sh::TestEnvSet _env;        /* 0x1244 */
    char _pad1254[0x1258 - 0x1254];
    float _anim_time;           /* 0x1258 */
};

/* its destructor (implicit or inline: D1/D0 call handle<Transform>'s D1 and inline ~shared_object_base) stays asm */
class CityApp::Car : public common::shared_object_base {
public:
    common::handle<scene::Transform> _transform;    /* 0x8 */
};

class VertexColorEnv {
public:
    struct Vertex : math::SphericalCoord {
        Vertex(float theta, float phi) : math::SphericalCoord(theta, phi), _col(_dir) {}
        math::vector_xyzw _col;         /* 0x18 */
    };
    VertexColorEnv(bool, int);
    void eval(const sh::SphericalRGBFn *);
    void draw(float);
    int _n;                             /* 0x0 */
    std::vector<Vertex> _vertices;      /* 0x4 */
};

namespace sh {
namespace Args {
struct Common;
}
}

extern bool draw_objects_enabled;
extern bool draw_water_enabled;

/* demo_duck's application */
class TestApp : public app3d::Callbacks {
public:
    TestApp(sh::Args::Common);
    virtual void init();
    virtual ~TestApp();
    virtual void draw();
    sh::VectorRGB local_water_shl();
    void draw_all();
    void draw_sink_background();
    void draw_objects(bool);
    void draw_environment();
    void print_help();
    void control();
    void envChange();
    void control_object();
    void switch_object();
    void dealWithMenu();
    void turn(float);
private:
    char _pad[0xF08 - 0xEE8];
    scene::Graph _graph;                                /* 0xF08 */
    common::handle<scene::Group> _kitchen;              /* 0x1000 */
    common::handle<scene::Group> _sink_background;      /* 0x1008 */
    common::handle<scene::Group> _sink_objects;         /* 0x1010 */
    common::handle<scene::Switch> _obj_switch;          /* 0x1018 */
    common::handle<scene::Group> _f1020;                /* 0x1020 */
    common::handle<scene::Group> _object;               /* 0x1028 */
    common::handle<scene::Texture> _default_shader_pass_1_tex; /* 0x1030 */
    std::string _f1038;                                 /* 0x1038 */
    char _pad103c[0x1041 - 0x103C];
    bool _vertex_color_env;                             /* 0x1041 */
    math::Trackball _trackball;                         /* 0x1044 */
    char _pad10d8[0x14E4 - 0x1044 - sizeof(math::Trackball)];
    VertexColorEnv _vce;                                /* 0x14E4 */
    char _pad14f4[0x1538 - 0x14F4];
    float _f1538;                                       /* 0x1538 */
    bool _f153C;                                        /* 0x153C */
    bool _f153D;                                        /* 0x153D: sh projection envmap */
    char _pad153e[0x1550 - 0x153E];
    WaterPatch _water;                                  /* 0x1550 */
    bool _f1638;                                        /* 0x1638 */
    sh::TestEnvSet _env;                                /* 0x163C */
    char _pad164c[0x167C - 0x164C];
    sh::VectorRGB _f167C;                               /* 0x167C */
    sh::VectorRGB _f16AC;                               /* 0x16AC */
    std::string _f16DC;                                 /* 0x16DC */
};

#endif
