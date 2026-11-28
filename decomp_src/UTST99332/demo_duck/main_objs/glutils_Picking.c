/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include <iostream>
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor (the original keyed them to
   Picking::THRESHOLD, defined in this object's .data, which stays asm) */
__asm__(".globl _GLOBAL__I__ZN7glutils7Picking9THRESHOLDE\n_GLOBAL__I__ZN7glutils7Picking9THRESHOLDE = _GLOBAL__I__ZN7glutils7PickingC2ERKS0_");
__asm__(".globl _GLOBAL__D__ZN7glutils7Picking9THRESHOLDE\n_GLOBAL__D__ZN7glutils7Picking9THRESHOLDE = _GLOBAL__D__ZN7glutils7PickingC2ERKS0_");

extern "C" {
void glPopMatrix(void);
void glMatrixMode(unsigned int);
void glFlush(void);
int glRenderMode(unsigned int);
float fabsf(float);
}

extern "C" const float D_001653F4;

/* the object's linkonce sections in the original's order (cc1plus emits the vector instances after
   the asm of PickingBase's inline dtors, which only its vtable references) */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZNSt6vectorIjSaIjEEaSERKS1_)
    DEMO_LINKONCE(_ZNSt6vectorIjSaIjEE13_M_insert_auxEN9__gnu_cxx17__normal_iteratorIPjS1_EERKj)
    DEMO_LINKONCE(_ZNSt6vectorIjSaIjEE5eraseEN9__gnu_cxx17__normal_iteratorIPjS1_EES5_)
    DEMO_LINKONCE(_ZNSt6vectorIjSaIjEE14_M_fill_insertEN9__gnu_cxx17__normal_iteratorIPjS1_EEjRKj)
    DEMO_LINKONCE(_ZSt4fillIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEEjEvT_S7_RKT0_)
    DEMO_LINKONCE(_ZSt6fill_nIPjjjET_S1_T0_RKT1_)
    DEMO_LINKONCE(_ZSt6fill_nIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEEjjET_S7_T0_RKT1_)
    DEMO_LINKONCE(_ZN7glutils11PickingBaseD1Ev)
    DEMO_LINKONCE(_ZN7glutils11PickingBaseD0Ev)
);

glutils::Picking::Picking(const Picking &o)
{
    *this = o;
}

glutils::Picking glutils::Picking::operator=(const Picking &o)
{
    _size = o._size;
    if (_buffer) {
        delete[] _buffer;
        _buffer = 0;
    }
    if (_size)
        _buffer = new unsigned int[_size];
    _hits = o._hits;
    return *this;
}

glutils::Picking::Picking(int n) : _size(n)
{
    if (n > 0) {
        _buffer = new unsigned int[n];
    } else {
        _size = 0;
        _buffer = 0;
    }
}

glutils::Picking::~Picking()
{
    if (_buffer)
        delete[] _buffer;
}

unsigned int glutils::Picking::processHits(int hits, bool nearest)
{
    _hits.resize(0);
    unsigned int near_name = ~0u;
    unsigned int far_name = ~0u;
    unsigned int zmin = 0;
    unsigned int zmax = 0;
    bool found = false;
    unsigned int *p = _buffer;
    for (int i = 0; i < hits; i++) {
        unsigned int n = *p++;
        if (n) {
            unsigned int z1 = *p++;
            unsigned int z2 = *p++;
            if (!found) {
                near_name = far_name = *p;
                found = true;
                zmin = z1;
                zmax = z2;
            }
            if (z1 < zmin) {
                zmin = z1;
                near_name = *p;
            }
            if (zmax < z2) {
                far_name = *p;
                zmax = z2;
            }
        }
        for (unsigned int j = 0; j < n; j++, p++) {
            unsigned int name = *p;
            _hits.push_back(name);
        }
    }
    unsigned int sel = nearest ? near_name : far_name;
    if (!_hits.empty() && _hits[0] != sel) {
        for (unsigned int k = 1; k < _hits.size(); k++) {
            if (_hits[k] == sel) {
                std::swap(_hits[0], _hits[k]);
                break;
            }
        }
    }
    return sel;
}

void glutils::Picking::begin(float x0, float y0, float x1, float y1)
{
    begin_internal((x0 + x1) * D_001653F4, (y0 + y1) * D_001653F4, fabsf(x0 - x1), fabsf(y0 - y1));
}

extern "C" {
void glPushMatrix(void);
void glSelectBuffer(int, unsigned int *);
void glGetFloatv(unsigned int, float *);
void glGetIntegerv(unsigned int, int *);
void glLoadIdentity(void);
void glMultMatrixf(const float *);
void gluPickMatrix(double, double, double, double, int *);
}
extern "C" const float D_001653F8;
extern "C" const double D_00165400;
extern "C" const char D_0016537C[], D_00165380[], D_0016538C[], D_0016539C[], D_001653B8[];
extern const char begin_internal_PRETTY[] __asm__("_ZZN7glutils7Picking14begin_internalEffffE19__PRETTY_FUNCTION__");

void glutils::Picking::begin_internal(float x, float y, float size_x, float size_y)
{
    int viewport[4];
    float proj[16];
    glPushMatrix();
    glSelectBuffer(_size, _buffer);
    glRenderMode(0x1C02);
    glMatrixMode(0x1701);
    glPushMatrix();
    glGetFloatv(0xBA7, proj);
    glLoadIdentity();
    glGetIntegerv(0xBA2, viewport);
    size_x = fabsf(size_x) < D_00165400 ? D_001653F8 : fabsf(size_x);
    size_y = fabsf(size_y) < D_00165400 ? D_001653F8 : fabsf(size_y);
    SGL_ASSERT(size_x > 0.f, D_00165380, D_001653B8, D_0016539C, begin_internal_PRETTY, 305, D_0016537C);
    SGL_ASSERT(size_y > 0.f, D_00165380, D_0016538C, D_0016539C, begin_internal_PRETTY, 306, D_0016537C);
    gluPickMatrix(x, y, size_x, size_y, viewport);
    glMultMatrixf(proj);
    glMatrixMode(0x1700);
}

void glutils::Picking::end()
{
    glFlush();
    processHits(glRenderMode(0x1C00), true);
    glMatrixMode(0x1701);
    glPopMatrix();
    glMatrixMode(0x1700);
    glPopMatrix();
}

/* PickingBase's inline virtual dtor: only its vtable (asm data) refers to it */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_Picking", _ZN7glutils11PickingBaseD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/glutils_Picking", _ZN7glutils11PickingBaseD0Ev);
