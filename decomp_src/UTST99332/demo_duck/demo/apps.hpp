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
private:
    char _pad[0x11EC - 0xEE8];
    ControledObject _control;   /* 0x11EC */
    char _pad11f0[0x1244 - 0x11F0];
    sh::TestEnvSet _env;        /* 0x1244 */
    char _pad1245[0x1258 - 0x1245];
    float _anim_time;           /* 0x1258 */
};

class TestApp : public app3d::Callbacks {
public:
    TestApp();
    void print_help();
    void control();
};

#endif
