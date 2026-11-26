/* the applications: CityApp (demo_harmonic), TestApp (demo_duck) */
#ifndef DEMO_DUCK_DEMO_APPS_HPP
#define DEMO_DUCK_DEMO_APPS_HPP

extern "C" void menuInit(void);
void run_city();
void run_ahiru();

/* demo_harmonic's application */
class CityApp : public app3d::Callbacks {
public:
    enum ControledObject { };
    CityApp();
    void init_lights();
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
private:
    char _pad[0x11EC - 0xEE8];
    ControledObject _control;   /* 0x11EC */
    char _pad11f0[0x1244 - 0x11F0];
    sh::TestEnvSet _env;        /* 0x1244 */
    char _pad1245[0x1258 - 0x1245];
    float _anim_time;           /* 0x1258 */
};

/* stand-ins until the owners' headers declare them (asm-labelled) */
namespace apps_ext {
void Group_traverse(scene::Group *, scene::TraversalType, sgl::Frustum &, const math::matrix &, const math::matrix &,
                    const math::matrix &, const sh::VectorRGB &, float)
    __asm__("_ZN5scene5Group8traverseENS_13TraversalTypeERN3sgl7FrustumERKN4math6matrixES8_S8_RKN2sh9VectorRGBEf");
void TestEnvSet_draw(sh::TestEnvSet *, bool) __asm__("_ZN2sh10TestEnvSet4drawEb");
}

class VertexColorEnv {
public:
    struct Vertex {
        char _p0[0x28];
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
    void local_water_shl();
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
    /* app3d::Callbacks' view frustum (0x34; sgl::Frustum is declared after base.hpp) */
    sgl::Frustum &frustum() { return *(sgl::Frustum *)((char *)this + 0x34); }
    char _pad[0xF08 - 0xEE8];
    char _graph[0xF78 - 0xF08];                         /* 0xF08 scene::Graph */
    sh::VectorRGB _graph_light;                         /* 0xF78 (in the Graph) */
    char _pad_fa8[0x1000 - 0xFA8];
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
    char _pad153c[0x1550 - 0x153C];
    WaterPatch _water;                                  /* 0x1550 */
    bool _f1638;                                        /* 0x1638 */
    sh::TestEnvSet _env __attribute__((aligned(4)));    /* 0x163C */
};

#endif
