/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_STATICS_MATH
#define DEMO_STATICS_IOSTREAM
#include "../main.hpp"

__asm__(".globl _GLOBAL__I__ZN7glutils8Material5setupEv");
__asm__(".globl _GLOBAL__D__ZN7glutils8Material5setupEv");

extern "C" void glMaterialfv(unsigned int, unsigned int, const float *);
extern "C" void glMaterialf(unsigned int, unsigned int, float);
void glutils::Material::setup()
{
    glMaterialfv(0x408, 0x1200, &ambient.x);
    glMaterialfv(0x408, 0x1201, &diffuse.x);
    glMaterialfv(0x408, 0x1600, &emission.x);
    if ((specular.x > 0 || specular.y > 0 || specular.z > 0) && shininess != 0) {
        glMaterialfv(0x408, 0x1202, &specular.x);
        glMaterialf(0x408, 0x1601, shininess);
    } else {
        float *s = &specular.x;
        s[0] = 0; s[1] = 0; s[2] = 0; s[3] = 1;
        glMaterialfv(0x408, 0x1202, s);
        glMaterialf(0x408, 0x1601, 0);
    }
}

void glutils::Material::print(std::ostream &os)
{
    os << "\n_ambient   " << ambient.x << "\t" << ambient.y << "\t" << ambient.z << "\t" << ambient.w << std::endl;
    os << "\n_diffuse   " << diffuse.x << "\t" << diffuse.y << "\t" << diffuse.z << "\t" << diffuse.w << std::endl;
    os << "\n_specular  " << specular.x << "\t" << specular.y << "\t" << specular.z << "\t" << specular.w << std::endl;
    os << "\n_emission  " << emission.x << "\t" << emission.y << "\t" << emission.z << "\t" << emission.w << std::endl;
    os << "\n_shininess " << shininess << std::endl;
}
