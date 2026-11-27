/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" {
int sceCtrlSetSamplingMode(int);
int sceCtrlSetSamplingCycle(int);
void sceGuInit(void);
int sceGuDisplay(int);
void sceGuTerm(void);
extern const char D_0015EF50[], D_0015EF5C[];
extern const char D_0015EBEC[], D_0015EBF4[], D_0015EC38[], D_0015EC4C[], D_0015EC58[], D_0015EC9C[], D_0015ECD4[], D_0015ED08[];
extern const char D_0015ED34[], D_0015ED5C[], D_0015ED60[], D_0015ED98[], D_0015EDD0[], D_0015EDF8[], D_0015EE38[], D_0015EE80[];
extern const char D_0015EEC4[], D_0015EF0C[];
int sceKernelCreateThread(const char *, int (*)(unsigned int, void *), int, int, unsigned int, void *);
int sceKernelStartThread(int, unsigned int, void *);
int sceKernelSleepThread(void);
int printf(const char *, ...);
int puts(const char *);
extern const float D_0015EF64;
}
namespace psp {
int MainThread(unsigned int, void *);
}
namespace app {
void CheckMemory();
}
extern const char StartMainThread_name[] __asm__("_ZZN3psp15StartMainThreadEvE19__PRETTY_FUNCTION__");
namespace glut {
void ReshapeFunc(int, int);
void DisplayFunc();
void IdleFunc();
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _Z41__static_initialization_and_destruction_0ii_DC98);

void glut::ReshapeFunc(int w, int h)
{
    if (app_ptr)
        app_ptr->reshape(w, h);
}

void glut::DisplayFunc()
{
    if (app_ptr)
        app_ptr->display();
}

void glut::IdleFunc()
{
    if (app_ptr) {
        if (app_ptr->exitRequested())
            exit(0);
        app_ptr->idle();
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glut_ReshapeFunc", _ZN3psp3padEv);

int psp::MainThread(unsigned int, void *)
{
    if (!glut::app_ptr)
        return -1;
    sceCtrlSetSamplingMode(1);
    sceCtrlSetSamplingCycle(0);
    sceGuInit();
    glut::app_ptr->init();
    sceGuDisplay(1);
    while (!glut::app_ptr->exitRequested())
        glut::app_ptr->idle();
    sceGuTerm();
    return 0;
}

#define APP_CHECK(c, text, line) SGL_ASSERT(c, D_0015EC4C, text, D_0015EC38, StartMainThread_name, line, D_0015ED5C)
void psp::StartMainThread()
{
    int main_thread_tid = sceKernelCreateThread(D_0015EBEC, MainThread, 0x6F, 0x4000, 0x4000, 0);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020190, D_0015EF0C, 268);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020191, D_0015EBF4, 269);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020194, D_0015EEC4, 270);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020064, D_0015EE80, 271);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020193, D_0015EE38, 272);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020192, D_0015EC58, 273);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x800201B9, D_0015EDF8, 274);
    if (main_thread_tid <= 0) {
        printf(D_0015EDD0);
        return;
    }
    {
        int err = sceKernelStartThread(main_thread_tid, 0, 0);
        APP_CHECK(((unsigned int)err) != 0x80020198, D_0015ED98, 285);
        APP_CHECK(((unsigned int)err) != 0x80020197, D_0015EC9C, 286);
        APP_CHECK(((unsigned int)err) != 0x80020064, D_0015ED60, 287);
        APP_CHECK(((unsigned int)err) != 0x800201A4, D_0015ECD4, 288);
        if (err != 0)
            printf(D_0015ED34);
        else {
            puts(D_0015ED08);
            sceKernelSleepThread();
        }
    }
}

int app::width()
{
    return glut::screen_width;
}

int app::height()
{
    return glut::screen_height;
}

float app::ratio()
{
    return (float)glut::screen_width / (float)glut::screen_height;
}

void app::set_initial_res(int, int) {
}

app::Callbacks::Callbacks() : exit_requested(false)
{
}

app::Callbacks::~Callbacks()
{
}

void app::Callbacks::run()
{
    glut::app_ptr = this;
    if (!init_glut) {
        init_glut = true;
        psp::StartMainThread();
    }
}

void app::Callbacks::init() {
}

void app::Callbacks::idle() {
}

void app::Callbacks::reshape(int, int) {
}

void app::Callbacks::display() {
}

bool app::Callbacks::exitRequested() const
{
    return exit_requested;
}

void app::Callbacks::exit()
{
    exit_requested = true;
}

void app::CheckMemory()
{
    unsigned int i = 0;
    char *p;
    do {
        p = new char[0x80000];
        i++;
        std::cout << D_0015EF50 << i * D_0015EF64 << D_0015EF5C;
    } while (p);
}

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_DC98");
void _GLOBAL__I__ZN4glut11ReshapeFuncEii(void);
void _GLOBAL__D__ZN4glut11ReshapeFuncEii(void);
}

void _GLOBAL__I__ZN4glut11ReshapeFuncEii(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN4glut11ReshapeFuncEii(void)
{
    static_init(0, 0xFFFF);
}
