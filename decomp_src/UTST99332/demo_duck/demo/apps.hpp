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
