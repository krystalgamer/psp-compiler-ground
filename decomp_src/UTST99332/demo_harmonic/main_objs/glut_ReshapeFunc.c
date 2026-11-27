/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_IOSTREAM
#define GLUT_STATICS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN4glut11ReshapeFuncEii");
__asm__(".globl _GLOBAL__D__ZN4glut11ReshapeFuncEii");

extern "C" {
int sceCtrlSetSamplingMode(int);
int sceCtrlSetSamplingCycle(int);
void sceGuInit(void);
int sceGuDisplay(int);
void sceGuTerm(void);
extern const char D_0015C510[], D_0015C51C[];
extern const char D_0015C1AC[], D_0015C1B4[], D_0015C1F8[], D_0015C20C[], D_0015C218[], D_0015C25C[], D_0015C294[], D_0015C2C8[];
extern const char D_0015C2F4[], D_0015C31C[], D_0015C320[], D_0015C358[], D_0015C390[], D_0015C3B8[], D_0015C3F8[], D_0015C440[];
extern const char D_0015C484[], D_0015C4CC[];
int sceKernelCreateThread(const char *, int (*)(unsigned int, void *), int, int, unsigned int, void *);
int sceKernelStartThread(int, unsigned int, void *);
int sceKernelSleepThread(void);
int printf(const char *, ...);
int puts(const char *);
extern const float D_0015C524;
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

/* file statics (local symbols): the static constructor is keyed to ReshapeFunc, the first public symbol */
namespace glut {
static app::Callbacks *app_ptr;
}

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

psp::Pad &psp::pad()
{
    static Pad single_pad;
    return single_pad;
}
namespace app {
static bool init_glut;
}

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

#define APP_CHECK(c, text, line) SGL_ASSERT(c, D_0015C20C, text, D_0015C1F8, StartMainThread_name, line, D_0015C31C)
void psp::StartMainThread()
{
    int main_thread_tid = sceKernelCreateThread(D_0015C1AC, MainThread, 0x6F, 0x4000, 0x4000, 0);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020190, D_0015C4CC, 268);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020191, D_0015C1B4, 269);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020194, D_0015C484, 270);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020064, D_0015C440, 271);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020193, D_0015C3F8, 272);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x80020192, D_0015C218, 273);
    APP_CHECK(((unsigned int)main_thread_tid) != 0x800201B9, D_0015C3B8, 274);
    if (main_thread_tid <= 0) {
        printf(D_0015C390);
        return;
    }
    {
        int err = sceKernelStartThread(main_thread_tid, 0, 0);
        APP_CHECK(((unsigned int)err) != 0x80020198, D_0015C358, 285);
        APP_CHECK(((unsigned int)err) != 0x80020197, D_0015C25C, 286);
        APP_CHECK(((unsigned int)err) != 0x80020064, D_0015C320, 287);
        APP_CHECK(((unsigned int)err) != 0x800201A4, D_0015C294, 288);
        if (err != 0)
            printf(D_0015C2F4);
        else {
            puts(D_0015C2C8);
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
        std::cout << D_0015C510 << i * D_0015C524 << D_0015C51C;
    } while (p);
}

