/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _Z41__static_initialization_and_destruction_0ii_29F98);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap4Face7TextureC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap4Face7TextureC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap4Face7TextureD2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap4Face7TextureD1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMapC2Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMapC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap11setBasenameEPKc);

const std::string &CubeMap::getBasename() const
{
    return basename;
}

void CubeMap::init_face(FaceEnum f)
{
    faces[f].init(f);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap12init_textureERNS_4Face7TextureE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap17load_face_textureENS_8FaceEnumE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap16face_setup_debugENS_8FaceEnumE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap10face_setupENS_8FaceEnumE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap9draw_faceENS_8FaceEnumE);

void CubeMap::draw_face_w(FaceEnum) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap4loadEv);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap9draw_cubeEv);

void CubeMap::draw_cube_w() {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap4drawEb);

void CubeMap::setLinear(bool l)
{
    linear = l;
}

void CubeMap::setResize(int r)
{
    resize = r;
}

void CubeMap::setCubeSize(float s)
{
    cube_size = s;
}

void CubeMap::toggleTextures()
{
    textures = !textures;
}

void CubeMap::toggleWireframe()
{
    wireframe = !wireframe;
}

void CubeMap::toggleFiltering()
{
    linear = !linear;
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap11GetFaceNameEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap16GetFaceTransformEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_harmonic/nonmatchings/main_objs/CubeMap_Face_Texture", __tcf_0_2C99C);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_29F98");
void _GLOBAL__I__ZN7CubeMap4Face7TextureC2Ev(void);
void _GLOBAL__D__ZN7CubeMap4Face7TextureC2Ev(void);
}

void _GLOBAL__I__ZN7CubeMap4Face7TextureC2Ev(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN7CubeMap4Face7TextureC2Ev(void)
{
    static_init(0, 0xFFFF);
}
