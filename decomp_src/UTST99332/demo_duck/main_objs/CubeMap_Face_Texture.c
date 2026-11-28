/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"
#include "../gl.hpp"

/* the strings stay in the module's .rodata (asm) */
extern const char D_00163874[];     /* "../lib/glutils/CubeMap.cpp" */
extern const char D_00163890[];     /* "_T._id == 0" */
extern const char D_0016389C[];     /* " *** error " */
extern const char D_001638A8[];     /* " " */
extern const char init_texture_name[] __asm__("_ZZN7CubeMap12init_textureERNS_4Face7TextureEE19__PRETTY_FUNCTION__");
#define CM_ASSERT(c, s, fn, line) \
    do if (!(c)) { \
        common::common_internal::assert_display(D_0016389C, s, D_00163874, fn, line, D_001638A8); \
        common::common_internal::on_error(); \
        common::common_internal::clash(); \
    } while (0)

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CubeMap_Face_Texture", _Z41__static_initialization_and_destruction_0ii_248C0);

CubeMap::Face::Texture::Texture() : _id(0)
{
}

CubeMap::Face::Texture::~Texture()
{
    if (_id) {
        gl::DeleteTextures(1, &_id);
        _id = 0;
    }
}

extern const char D_0016383C[];
CubeMap::CubeMap()
{
    cube_size = 2000.0f;
    linear = true;
    resize = 0;
    textures = false;
    wireframe = false;
    basename = D_0016383C;
    init_face((FaceEnum)0);
    init_face((FaceEnum)1);
    init_face((FaceEnum)2);
    init_face((FaceEnum)3);
    init_face((FaceEnum)4);
    init_face((FaceEnum)5);
}


void CubeMap::setBasename(const char *name)
{
    basename = name;
}

const std::string &CubeMap::getBasename() const
{
    return basename;
}

void CubeMap::init_face(FaceEnum f)
{
    faces[f].init(f);
}

void CubeMap::init_texture(Face::Texture &_T)
{
    CM_ASSERT(_T._id == 0, D_00163890, init_texture_name, 158);
    gl::GenTextures(1, &_T._id);
    if (_T._id != 0) {
        _T.t.setFiltering(linear ? (textures::Filtering)0 : (textures::Filtering)1);
        _T.t.setTextureFunc((textures::TextureFunction)3);
        _T.t.setWrapS((textures::Wrapping)0);
        _T.t.setWrapT((textures::Wrapping)0);
        _T.t.initGl(_T._id);
    }
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap17load_face_textureENS_8FaceEnumE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap16face_setup_debugENS_8FaceEnumE);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap10face_setupENS_8FaceEnumE);

void CubeMap::draw_face(FaceEnum f)
{
    Face &face = faces[f];
    face_setup(f);
    glPushMatrix();
    glMultMatrixf(GetFaceTransform(f));
    glBegin(GL_QUADS);
    glNormal3f(-1.0f, 0, 0);
    glTexCoord2f(face.tc_min, face.tc_max);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(face.tc_max, face.tc_max);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(face.tc_max, face.tc_min);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(face.tc_min, face.tc_min);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glEnd();
    glPopMatrix();
}

void CubeMap::draw_face_w(FaceEnum) {
(void)0;
(void)0;
(void)0;
(void)0;
(void)0;
(void)0;
}

void CubeMap::load()
{
    load_face_texture((FaceEnum)0);
    load_face_texture((FaceEnum)1);
    load_face_texture((FaceEnum)2);
    load_face_texture((FaceEnum)3);
    load_face_texture((FaceEnum)4);
    load_face_texture((FaceEnum)5);
}

void CubeMap::draw_cube()
{
    draw_face((FaceEnum)0);
    draw_face((FaceEnum)1);
    draw_face((FaceEnum)2);
    draw_face((FaceEnum)3);
    draw_face((FaceEnum)4);
    draw_face((FaceEnum)5);
}

void CubeMap::draw_cube_w() {
    draw_face_w((FaceEnum)0);
    draw_face_w((FaceEnum)1);
    draw_face_w((FaceEnum)2);
    draw_face_w((FaceEnum)3);
    draw_face_w((FaceEnum)4);
    draw_face_w((FaceEnum)5);
}

void CubeMap::draw(bool unit)
{
    if (cube_size == 0)
        return;
    glPushAttrib(0x2000);
    glShadeModel(0x1D00);
    glDisable(0xBD0);
    glCullFace(0x405);
    glEnable(0xB44);
    glEnable(0xB71);
    glEnable(0xB57);
    glDisable(0xB50);
    glDepthFunc(0x203);
    glDisable(0xBE2);
    glDisable(0xBC0);
    glColor3ub(0xFF, 0xFF, 0xFF);
    glPushMatrix();
    float s = unit ? 1.0f : cube_size;
    glScalef(s, s, s);
    draw_cube();
    if (wireframe)
        draw_cube_w();
    glPopMatrix();
    glPopAttrib();
    glShadeModel(0x1D01);
}

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

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap11GetFaceNameEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CubeMap_Face_Texture", _ZN7CubeMap16GetFaceTransformEi);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/CubeMap_Face_Texture", __tcf_0_272C4);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_248C0");
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
