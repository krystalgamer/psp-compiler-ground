/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* this object's .gnu.linkonce.t sections in the original's order */
DEMO_LINKONCE_ORDER(
    DEMO_LINKONCE(_ZN12HouseKeeping11AttribStackC1Ev)
    DEMO_LINKONCE(_ZNSt5dequeIjSaIjEE8pop_backEv)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIjSaIjEED2Ev)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIjSaIjEE17_M_initialize_mapEj)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIjSaIjEE16_M_destroy_nodesEPPjS3_)
    DEMO_LINKONCE(_ZNSt5dequeIjSaIjEE16_M_push_back_auxERKj)
    DEMO_LINKONCE(_ZNSt5dequeIjSaIjEE16_M_pop_front_auxEv)
    DEMO_LINKONCE(_ZNSt5dequeIjSaIjEE15_M_pop_back_auxEv)
    DEMO_LINKONCE(_ZNSt11_Deque_baseIjSaIjEE15_M_create_nodesEPPjS3_)
    DEMO_LINKONCE(_ZNSt5dequeIjSaIjEE17_M_reallocate_mapEjb)
    DEMO_LINKONCE(_ZSt6__copyISt15_Deque_iteratorIjRKjPS1_ES0_IjRjPjEET0_T_S9_S8_St26random_access_iterator_tag)
    DEMO_LINKONCE(_ZN12HouseKeeping11AttribStack3getERNS_10EnableMaskEj)
);
#include <deque>

/* the GL emulation's state (only the members used so far) */
struct HouseKeepingState {
    std::deque<unsigned int> free_textures;     /* 0x00 */
    unsigned int last_texture;  /* 0x28 */
    char _pad2c[0x34 - 0x2C];
    int wrap_s;                 /* 0x34 */
    int wrap_t;                 /* 0x38 */
    int min_filter;             /* 0x3C */
    int mag_filter;             /* 0x40 */
    int viewport_x;             /* 0x44 (+2048) */
    int viewport_y;             /* 0x48 (+2048) */
    int viewport_w;             /* 0x4C */
    int viewport_h;             /* 0x50 */
    unsigned int array_format;  /* 0x54 */
    const void *array_pointer;  /* 0x58 */
    int array_stride;           /* 0x5C */
};
extern HouseKeepingState hk;
bool GL2SCEGU(unsigned int, int *);
extern "C" {
void sceGuFrontFace(int);
void sceGumMatrixMode(int);
void sceGumMultMatrix(const ScePspFMatrix4 *);
void sceGumTranslate(const ScePspFVector3 *);
void sceGumStoreMatrix(ScePspFMatrix4 *);
void sceGumOrtho(float, float, float, float, float, float);
void glRotatef(float, float, float, float);
}
extern "C" const char D_001634A0[], D_001634C0[], D_001635F8[], D_0016360C[], D_00163654[], D_00163690[];
extern const char glClearDepth_fn[] __asm__("_ZZ12glClearDepthE19__PRETTY_FUNCTION__");
extern const char glDepthRange_fn[] __asm__("_ZZ12glDepthRangeE19__PRETTY_FUNCTION__");
extern const char glLoadMatrixd_fn[] __asm__("_ZZ13glLoadMatrixdE19__PRETTY_FUNCTION__");
#define GL_ASSERT(c, fn, line, msg) SGL_ASSERT(c, D_001634A0, D_0016360C, D_001634C0, fn, line, msg)
extern unsigned int D_0018DE1C;     /* glBindTexture's current texture */

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", _Z41__static_initialization_and_destruction_0ii_1F6B0);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", _Z16PspLogEnableBitsPKc);

extern "C" void glClearIndex(void) {
}

extern "C" void glClearColor(float r, float g, float b, float a)
{
    union { struct { unsigned int r : 8, g : 8, b : 8, a : 8; } s; unsigned int u; } c;
    c.s.a = (unsigned int)(a * 255.0f);
    c.s.r = (unsigned int)(r * 255.0f);
    c.s.g = (unsigned int)(g * 255.0f);
    c.s.b = (unsigned int)(b * 255.0f);
    sceGuClearColor(c.u);
}

extern "C" void glClear(unsigned int mask)
{
    sceGuClear(((mask & 0x4000) ? 1 : 0) | ((mask & 0x100) ? 4 : 0) | ((mask & 0x400) ? 2 : 0));
}

extern "C" void glIndexMask(void) {
}

extern "C" void glColorMask(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glAlphaFunc);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glBlendFunc);

extern "C" void glLogicOp(void) {
}

extern "C" void glCullFace(void) {
}

extern "C" void glFrontFace(unsigned int mode)
{
    int v;
    if (GL2SCEGU(mode, &v))
        sceGuFrontFace(v);
}

extern "C" void glPointSize(void) {
}

extern "C" void glLineWidth(void) {
}

extern "C" void glLineStipple(void) {
}

extern "C" void glPolygonMode(void) {
}

extern "C" void glPolygonOffset(void) {
}

extern "C" void glPolygonStipple(void) {
}

extern "C" void glGetPolygonStipple(void) {
}

extern "C" void glEdgeFlag(void) {
}

extern "C" void glEdgeFlagv(void) {
}

extern "C" void glScissor(void) {
}

extern "C" void glClipPlane(void) {
}

extern "C" void glGetClipPlane(void) {
}

extern "C" void glDrawBuffer(void) {
}

extern "C" void glReadBuffer(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glEnable);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glDisable);

extern "C" int glIsEnabled(void)
{
    return 0;
}

extern "C" void glEnableClientState(void) {
}

extern "C" void glDisableClientState(void) {
}

extern "C" void glGetBooleanv(void) {
}

extern "C" void glGetDoublev(void) {
}

extern "C" void glGetFloatv(unsigned int pname, float *params)
{
    ScePspFMatrix4 m;
    switch (pname) {
    case 0xBA6:
        sceGumStoreMatrix(&m);
        for (int i = 0; i < 16; i++)
            params[i] = ((float *)&m)[i];
        break;
    case 0xBA7:
        sceGumMatrixMode(0);
        sceGumStoreMatrix(&m);
        for (int i = 0; i < 16; i++)
            params[i] = ((float *)&m)[i];
        sceGumMatrixMode(2);
        break;
    }
}

extern "C" void glGetIntegerv(unsigned int pname, int *params)
{
    if (pname == 0xBA2) {
        params[0] = hk.viewport_x - 2048;
        params[1] = hk.viewport_y - 2048;
        params[2] = hk.viewport_w;
        params[3] = hk.viewport_h;
    }
}

extern "C" void glPushAttrib(void) {
}

extern "C" void glPopAttrib(void) {
}

extern "C" void glPushClientAttrib(void) {
}

extern "C" void glPopClientAttrib(void) {
}

extern "C" int glRenderMode(void)
{
    return 0;
}

extern "C" int glGetError(void)
{
    return 0;
}

extern "C" int glGetString(void)
{
    return 0;
}

extern "C" void glFinish(void) {
}

extern "C" void glFlush(void) {
}

extern "C" void glHint(void) {
}

extern "C" void glClearDepth(double)
{
    GL_ASSERT(false, glClearDepth_fn, 0x46D, D_001635F8);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glDepthFunc);

extern "C" void glDepthMask(unsigned char flag)
{
    sceGuDepthMask(flag);
}

extern "C" void glDepthRange(double, double)
{
    GL_ASSERT(false, glDepthRange_fn, 0x497, D_00163654);
}

extern "C" void glClearAccum(void) {
}

extern "C" void glAccum(void) {
}

extern "C" void glMatrixMode(unsigned int mode)
{
    switch (mode) {
    case 0x1701:
        sceGumMatrixMode(0);
        break;
    case 0x1700:
        sceGumMatrixMode(2);
        break;
    case 0x1702:
        sceGumMatrixMode(3);
        break;
    }
}

extern "C" void glOrtho(double l, double r, double b, double t, double n, double f)
{
    sceGumOrtho(l, r, t, b, n, f);
}

extern "C" void sceGumPerspective(float, float, float, float);
extern "C" void sceGumSetCurMatrix(void);
extern "C" void glFrustum(double l, double r, double b, double t, double n, double f)
{
    float h = fabsf((float)(t - b)) * 0.5f;
    float w = fabsf((float)(r - l)) * 0.5f;
    float fovy = fabsf(2 * atanf(h / n));
    sceGumPerspective(fovy, w / h, n, f);
    sceGumSetCurMatrix();
}

extern "C" void glViewport(int x, int y, int w, int h)
{
    hk.viewport_x = x + 2048;
    hk.viewport_y = y + 2048;
    hk.viewport_w = w;
    hk.viewport_h = h;
    sceGuViewport(hk.viewport_x, hk.viewport_y, w, h);
}

extern "C" void glPushMatrix(void)
{
    extern void sceGumPushMatrix_(void) __asm__("sceGumPushMatrix");
    sceGumPushMatrix_();
}

extern "C" void glPopMatrix(void)
{
    extern void sceGumPopMatrix_(void) __asm__("sceGumPopMatrix");
    sceGumPopMatrix_();
}

extern "C" void glLoadIdentity(void)
{
    extern void sceGumLoadIdentity_(void) __asm__("sceGumLoadIdentity");
    sceGumLoadIdentity_();
}

extern "C" void glLoadMatrixd(const double *)
{
    GL_ASSERT(false, glLoadMatrixd_fn, 0x4F1, D_00163690);
}

extern "C" void glLoadMatrixf(void)
{
    extern void sceGumLoadMatrix_(void) __asm__("sceGumLoadMatrix");
    sceGumLoadMatrix_();
}

extern "C" void glMultMatrixd(const double *m)
{
    float f[16];
    for (int i = 0; i != 16; i++)
        f[i] = m[i];
    sceGumMultMatrix((const ScePspFMatrix4 *)f);
}

extern "C" void glMultMatrixf(void)
{
    extern void sceGumMultMatrix_(void) __asm__("sceGumMultMatrix");
    sceGumMultMatrix_();
}

extern "C" void glRotated(double a, double x, double y, double z)
{
    glRotatef(a, x, y, z);
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glRotatef);

extern "C" void glScaled(double x, double y, double z)
{
    ScePspFVector3 v = { x, y, z };
    sceGumScale(&v);
}

extern "C" void glScalef(float x, float y, float z)
{
    ScePspFVector3 v = { x, y, z };
    sceGumScale(&v);
}

extern "C" void glTranslated(double x, double y, double z)
{
    ScePspFVector3 v = { x, y, z };
    sceGumTranslate(&v);
}

extern "C" void glTranslatef(float x, float y, float z)
{
    ScePspFVector3 v = { x, y, z };
    sceGumTranslate(&v);
}

extern "C" int glIsList(void)
{
    return 0;
}

extern "C" void glDeleteLists(void) {
}

extern "C" int glGenLists(void)
{
    return 0;
}

extern "C" void glNewList(void) {
}

extern "C" void glEndList(void) {
}

extern "C" void glCallList(void) {
}

extern "C" void glCallLists(void) {
}

extern "C" void glListBase(void) {
}

extern "C" void glBegin(void) {
}

extern "C" void glEnd(void) {
}

extern "C" void glVertex2d(void) {
}

extern "C" void glVertex2f(void) {
}

extern "C" void glVertex2i(void) {
}

extern "C" void glVertex2s(void) {
}

extern "C" void glVertex3d(void) {
}

extern "C" void glVertex3f(void) {
}

extern "C" void glVertex3i(void) {
}

extern "C" void glVertex3s(void) {
}

extern "C" void glVertex4d(void) {
}

extern "C" void glVertex4f(void) {
}

extern "C" void glVertex4i(void) {
}

extern "C" void glVertex4s(void) {
}

extern "C" void glVertex2dv(void) {
}

extern "C" void glVertex2fv(void) {
}

extern "C" void glVertex2iv(void) {
}

extern "C" void glVertex2sv(void) {
}

extern "C" void glVertex3dv(void) {
}

extern "C" void glVertex3fv(void) {
}

extern "C" void glVertex3iv(void) {
}

extern "C" void glVertex3sv(void) {
}

extern "C" void glVertex4dv(void) {
}

extern "C" void glVertex4fv(void) {
}

extern "C" void glVertex4iv(void) {
}

extern "C" void glVertex4sv(void) {
}

extern "C" void glNormal3b(void) {
}

extern "C" void glNormal3d(void) {
}

extern "C" void glNormal3f(void) {
}

extern "C" void glNormal3i(void) {
}

extern "C" void glNormal3s(void) {
}

extern "C" void glNormal3bv(void) {
}

extern "C" void glNormal3dv(void) {
}

extern "C" void glNormal3fv(void) {
}

extern "C" void glNormal3iv(void) {
}

extern "C" void glNormal3sv(void) {
}

extern "C" void glIndexd(void) {
}

extern "C" void glIndexf(void) {
}

extern "C" void glIndexi(void) {
}

extern "C" void glIndexs(void) {
}

extern "C" void glIndexub(void) {
}

extern "C" void glIndexdv(void) {
}

extern "C" void glIndexfv(void) {
}

extern "C" void glIndexiv(void) {
}

extern "C" void glIndexsv(void) {
}

extern "C" void glIndexubv(void) {
}

extern "C" void glColor3b(void) {
}

extern "C" void glColor3d(void) {
}

extern "C" void glColor3f(void) {
}

extern "C" void glColor3i(void) {
}

extern "C" void glColor3s(void) {
}

extern "C" void glColor3ub(void) {
}

extern "C" void glColor3ui(void) {
}

extern "C" void glColor3us(void) {
}

extern "C" void glColor4b(void) {
}

extern "C" void glColor4d(void) {
}

extern "C" void glColor4f(void) {
}

extern "C" void glColor4i(void) {
}

extern "C" void glColor4s(void) {
}

extern "C" void glColor4ub(void) {
}

extern "C" void glColor4ui(void) {
}

extern "C" void glColor4us(void) {
}

extern "C" void glColor3bv(void) {
}

extern "C" void glColor3dv(void) {
}

extern "C" void glColor3fv(void) {
}

extern "C" void glColor3iv(void) {
}

extern "C" void glColor3sv(void) {
}

extern "C" void glColor3ubv(void) {
}

extern "C" void glColor3uiv(void) {
}

extern "C" void glColor3usv(void) {
}

extern "C" void glColor4bv(void) {
}

extern "C" void glColor4dv(void) {
}

extern "C" void glColor4fv(void) {
}

extern "C" void glColor4iv(void) {
}

extern "C" void glColor4sv(void) {
}

extern "C" void glColor4ubv(void) {
}

extern "C" void glColor4uiv(void) {
}

extern "C" void glColor4usv(void) {
}

extern "C" void glTexCoord1d(void) {
}

extern "C" void glTexCoord1f(void) {
}

extern "C" void glTexCoord1i(void) {
}

extern "C" void glTexCoord1s(void) {
}

extern "C" void glTexCoord2d(void) {
}

extern "C" void glTexCoord2f(void) {
}

extern "C" void glTexCoord2i(void) {
}

extern "C" void glTexCoord2s(void) {
}

extern "C" void glTexCoord3d(void) {
}

extern "C" void glTexCoord3f(void) {
}

extern "C" void glTexCoord3i(void) {
}

extern "C" void glTexCoord3s(void) {
}

extern "C" void glTexCoord4d(void) {
}

extern "C" void glTexCoord4f(void) {
}

extern "C" void glTexCoord4i(void) {
}

extern "C" void glTexCoord4s(void) {
}

extern "C" void glTexCoord1dv(void) {
}

extern "C" void glTexCoord1fv(void) {
}

extern "C" void glTexCoord1iv(void) {
}

extern "C" void glTexCoord1sv(void) {
}

extern "C" void glTexCoord2dv(void) {
}

extern "C" void glTexCoord2fv(void) {
}

extern "C" void glTexCoord2iv(void) {
}

extern "C" void glTexCoord2sv(void) {
}

extern "C" void glTexCoord3dv(void) {
}

extern "C" void glTexCoord3fv(void) {
}

extern "C" void glTexCoord3iv(void) {
}

extern "C" void glTexCoord3sv(void) {
}

extern "C" void glTexCoord4dv(void) {
}

extern "C" void glTexCoord4fv(void) {
}

extern "C" void glTexCoord4iv(void) {
}

extern "C" void glTexCoord4sv(void) {
}

extern "C" void glRasterPos2d(void) {
}

extern "C" void glRasterPos2f(void) {
}

extern "C" void glRasterPos2i(void) {
}

extern "C" void glRasterPos2s(void) {
}

extern "C" void glRasterPos3d(void) {
}

extern "C" void glRasterPos3f(void) {
}

extern "C" void glRasterPos3i(void) {
}

extern "C" void glRasterPos3s(void) {
}

extern "C" void glRasterPos4d(void) {
}

extern "C" void glRasterPos4f(void) {
}

extern "C" void glRasterPos4i(void) {
}

extern "C" void glRasterPos4s(void) {
}

extern "C" void glRasterPos2dv(void) {
}

extern "C" void glRasterPos2fv(void) {
}

extern "C" void glRasterPos2iv(void) {
}

extern "C" void glRasterPos2sv(void) {
}

extern "C" void glRasterPos3dv(void) {
}

extern "C" void glRasterPos3fv(void) {
}

extern "C" void glRasterPos3iv(void) {
}

extern "C" void glRasterPos3sv(void) {
}

extern "C" void glRasterPos4dv(void) {
}

extern "C" void glRasterPos4fv(void) {
}

extern "C" void glRasterPos4iv(void) {
}

extern "C" void glRasterPos4sv(void) {
}

extern "C" void glRectd(void) {
}

extern "C" void glRectf(void) {
}

extern "C" void glRecti(void) {
}

extern "C" void glRects(void) {
}

extern "C" void glRectdv(void) {
}

extern "C" void glRectfv(void) {
}

extern "C" void glRectiv(void) {
}

extern "C" void glRectsv(void) {
}

extern "C" void glShadeModel(unsigned int mode)
{
    sceGuShadeModel(mode == 0x1D01);
}

extern "C" void glLightf(void) {
}

extern "C" void glLighti(void) {
}

extern "C" void glLightfv(void) {
}

extern "C" void glLightiv(void) {
}

extern "C" void glGetLightfv(void) {
}

extern "C" void glGetLightiv(void) {
}

extern "C" void glLightModelf(void) {
}

extern "C" void glLightModeli(void) {
}

extern "C" void glLightModelfv(void) {
}

extern "C" void glLightModeliv(void) {
}

extern "C" void glMaterialf(void) {
}

extern "C" void glMateriali(void) {
}

extern "C" void glMaterialfv(void) {
}

extern "C" void glMaterialiv(void) {
}

extern "C" void glGetMaterialfv(void) {
}

extern "C" void glGetMaterialiv(void) {
}

extern "C" void glColorMaterial(void) {
}

extern "C" void glPixelZoom(void) {
}

extern "C" void glPixelStoref(void) {
}

extern "C" void glPixelStorei(void) {
}

extern "C" void glPixelTransferf(void) {
}

extern "C" void glPixelTransferi(void) {
}

extern "C" void glPixelMapfv(void) {
}

extern "C" void glPixelMapuiv(void) {
}

extern "C" void glPixelMapusv(void) {
}

extern "C" void glGetPixelMapfv(void) {
}

extern "C" void glGetPixelMapuiv(void) {
}

extern "C" void glGetPixelMapusv(void) {
}

extern "C" void glBitmap(void) {
}

extern "C" void glReadPixels(void) {
}

extern "C" void glDrawPixels(void) {
}

extern "C" void glCopyPixels(void) {
}

extern "C" void glStencilFunc(void) {
}

extern "C" void glStencilMask(void) {
}

extern "C" void glStencilOp(void) {
}

extern "C" void glClearStencil(void)
{
    extern void sceGuClearStencil_(void) __asm__("sceGuClearStencil");
    sceGuClearStencil_();
}

extern "C" void glTexGend(void) {
}

extern "C" void glTexGenf(void) {
}

extern "C" void glTexGeni(void) {
}

extern "C" void glTexGendv(void) {
}

extern "C" void glTexGenfv(void) {
}

extern "C" void glTexGeniv(void) {
}

extern "C" void glGetTexGendv(void) {
}

extern "C" void glGetTexGenfv(void) {
}

extern "C" void glGetTexGeniv(void) {
}

extern "C" void glTexEnvf(void) {
}

extern "C" void glTexEnvi(unsigned int, unsigned int pname, int param)
{
    if (pname == 0x2200) {
        int v;
        if (GL2SCEGU(param, &v))
            sceGuTexFunc(v, 1);
    }
}

extern "C" void glTexEnvfv(void) {
}

extern "C" void glTexEnviv(void) {
}

extern "C" void glGetTexEnvfv(void) {
}

extern "C" void glGetTexEnviv(void) {
}

extern "C" void glTexParameterf(void) {
}

extern "C" void glTexParameteri(unsigned int, unsigned int pname, int param)
{
    switch (pname) {
    case 0x2802:
        hk.wrap_s = param == 0x2900;
        sceGuTexWrap(hk.wrap_s, hk.wrap_t);
        break;
    case 0x2803:
        hk.wrap_t = param == 0x2900;
        sceGuTexWrap(hk.wrap_s, hk.wrap_t);
        break;
    case 0x2800:
        hk.mag_filter = param == 0x2601;
        sceGuTexFilter(hk.min_filter, hk.mag_filter);
        break;
    case 0x2801:
        hk.min_filter = param == 0x2601;
        sceGuTexFilter(hk.min_filter, hk.mag_filter);
        break;
    }
}

extern "C" void glTexParameterfv(void) {
}

extern "C" void glTexParameteriv(void) {
}

extern "C" void glGetTexParameterfv(void) {
}

extern "C" void glGetTexParameteriv(void) {
}

extern "C" void glGetTexLevelParameterfv(void) {
}

extern "C" void glGetTexLevelParameteriv(void) {
}

extern "C" void glTexImage1D(void) {
}

extern "C" void glTexImage2D(void) {
}

extern "C" void glGetTexImage(void) {
}

extern "C" void glMap1d(void) {
}

extern "C" void glMap1f(void) {
}

extern "C" void glMap2d(void) {
}

extern "C" void glMap2f(void) {
}

extern "C" void glGetMapdv(void) {
}

extern "C" void glGetMapfv(void) {
}

extern "C" void glGetMapiv(void) {
}

extern "C" void glEvalCoord1d(void) {
}

extern "C" void glEvalCoord1f(void) {
}

extern "C" void glEvalCoord1dv(void) {
}

extern "C" void glEvalCoord1fv(void) {
}

extern "C" void glEvalCoord2d(void) {
}

extern "C" void glEvalCoord2f(void) {
}

extern "C" void glEvalCoord2dv(void) {
}

extern "C" void glEvalCoord2fv(void) {
}

extern "C" void glMapGrid1d(void) {
}

extern "C" void glMapGrid1f(void) {
}

extern "C" void glMapGrid2d(void) {
}

extern "C" void glMapGrid2f(void) {
}

extern "C" void glEvalPoint1(void) {
}

extern "C" void glEvalPoint2(void) {
}

extern "C" void glEvalMesh1(void) {
}

extern "C" void glEvalMesh2(void) {
}

extern "C" void glFogf(void) {
}

extern "C" void glFogi(void) {
}

extern "C" void glFogfv(void) {
}

extern "C" void glFogiv(void) {
}

extern "C" void glFeedbackBuffer(void) {
}

extern "C" void glPassThrough(void) {
}

extern "C" void glSelectBuffer(void) {
}

extern "C" void glInitNames(void) {
}

extern "C" void glLoadName(void) {
}

extern "C" void glPushName(void) {
}

extern "C" void glPopName(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glGenTextures);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glDeleteTextures);

extern "C" void glBindTexture(unsigned int, unsigned int texture)
{
    D_0018DE1C = texture;
}

extern "C" void glPrioritizeTextures(void) {
}

extern "C" int glAreTexturesResident(void)
{
    return 0;
}

extern "C" int glIsTexture(void)
{
    return 0;
}

extern "C" void glTexSubImage1D(void) {
}

extern "C" void glTexSubImage2D(void) {
}

extern "C" void glCopyTexImage1D(void) {
}

extern "C" void glCopyTexImage2D(void) {
}

extern "C" void glCopyTexSubImage1D(void) {
}

extern "C" void glCopyTexSubImage2D(void) {
}

extern "C" void glVertexPointer(void) {
}

extern "C" void glNormalPointer(void) {
}

extern "C" void glColorPointer(void) {
}

extern "C" void glIndexPointer(void) {
}

extern "C" void glTexCoordPointer(void) {
}

extern "C" void glEdgeFlagPointer(void) {
}

extern "C" void glGetPointerv(void) {
}

extern "C" void glArrayElement(void) {
}

extern "C" void glDrawArrays(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", glDrawElements);

extern "C" void glInterleavedArrays(unsigned int format, int stride, const void *pointer)
{
    hk.array_format = format;
    hk.array_pointer = pointer;
    hk.array_stride = stride;
}

extern "C" void glDrawRangeElements(void) {
}

extern "C" void glTexImage3D(void) {
}

extern "C" void glTexSubImage3D(void) {
}

extern "C" void glCopyTexSubImage3D(void) {
}

extern "C" void glColorTable(void) {
}

extern "C" void glColorSubTable(void) {
}

extern "C" void glColorTableParameteriv(void) {
}

extern "C" void glColorTableParameterfv(void) {
}

extern "C" void glCopyColorSubTable(void) {
}

extern "C" void glCopyColorTable(void) {
}

extern "C" void glGetColorTable(void) {
}

extern "C" void glGetColorTableParameterfv(void) {
}

extern "C" void glGetColorTableParameteriv(void) {
}

extern "C" void glBlendEquation(void) {
}

extern "C" void glBlendColor(void) {
}

extern "C" void glHistogram(void) {
}

extern "C" void glResetHistogram(void) {
}

extern "C" void glGetHistogram(void) {
}

extern "C" void glGetHistogramParameterfv(void) {
}

extern "C" void glGetHistogramParameteriv(void) {
}

extern "C" void glMinmax(void) {
}

extern "C" void glResetMinmax(void) {
}

extern "C" void glGetMinmax(void) {
}

extern "C" void glGetMinmaxParameterfv(void) {
}

extern "C" void glGetMinmaxParameteriv(void) {
}

extern "C" void glConvolutionFilter1D(void) {
}

extern "C" void glConvolutionFilter2D(void) {
}

extern "C" void glConvolutionParameterf(void) {
}

extern "C" void glConvolutionParameterfv(void) {
}

extern "C" void glConvolutionParameteri(void) {
}

extern "C" void glConvolutionParameteriv(void) {
}

extern "C" void glCopyConvolutionFilter1D(void) {
}

extern "C" void glCopyConvolutionFilter2D(void) {
}

extern "C" void glGetConvolutionFilter(void) {
}

extern "C" void glGetConvolutionParameterfv(void) {
}

extern "C" void glGetConvolutionParameteriv(void) {
}

extern "C" void glSeparableFilter2D(void) {
}

extern "C" void glGetSeparableFilter(void) {
}

extern "C" void glActiveTexture(void) {
}

extern "C" void glClientActiveTexture(void) {
}

extern "C" void glCompressedTexImage1D(void) {
}

extern "C" void glCompressedTexImage2D(void) {
}

extern "C" void glCompressedTexImage3D(void) {
}

extern "C" void glCompressedTexSubImage1D(void) {
}

extern "C" void glCompressedTexSubImage2D(void) {
}

extern "C" void glCompressedTexSubImage3D(void) {
}

extern "C" void glGetCompressedTexImage(void) {
}

extern "C" void glMultiTexCoord1d(void) {
}

extern "C" void glMultiTexCoord1dv(void) {
}

extern "C" void glMultiTexCoord1f(void) {
}

extern "C" void glMultiTexCoord1fv(void) {
}

extern "C" void glMultiTexCoord1i(void) {
}

extern "C" void glMultiTexCoord1iv(void) {
}

extern "C" void glMultiTexCoord1s(void) {
}

extern "C" void glMultiTexCoord1sv(void) {
}

extern "C" void glMultiTexCoord2d(void) {
}

extern "C" void glMultiTexCoord2dv(void) {
}

extern "C" void glMultiTexCoord2f(void) {
}

extern "C" void glMultiTexCoord2fv(void) {
}

extern "C" void glMultiTexCoord2i(void) {
}

extern "C" void glMultiTexCoord2iv(void) {
}

extern "C" void glMultiTexCoord2s(void) {
}

extern "C" void glMultiTexCoord2sv(void) {
}

extern "C" void glMultiTexCoord3d(void) {
}

extern "C" void glMultiTexCoord3dv(void) {
}

extern "C" void glMultiTexCoord3f(void) {
}

extern "C" void glMultiTexCoord3fv(void) {
}

extern "C" void glMultiTexCoord3i(void) {
}

extern "C" void glMultiTexCoord3iv(void) {
}

extern "C" void glMultiTexCoord3s(void) {
}

extern "C" void glMultiTexCoord3sv(void) {
}

extern "C" void glMultiTexCoord4d(void) {
}

extern "C" void glMultiTexCoord4dv(void) {
}

extern "C" void glMultiTexCoord4f(void) {
}

extern "C" void glMultiTexCoord4fv(void) {
}

extern "C" void glMultiTexCoord4i(void) {
}

extern "C" void glMultiTexCoord4iv(void) {
}

extern "C" void glMultiTexCoord4s(void) {
}

extern "C" void glMultiTexCoord4sv(void) {
}

extern "C" void glLoadTransposeMatrixd(void) {
}

extern "C" void glLoadTransposeMatrixf(void) {
}

extern "C" void glMultTransposeMatrixd(void) {
}

extern "C" void glMultTransposeMatrixf(void) {
}

extern "C" void glSampleCoverage(void) {
}

extern "C" void glSamplePass(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", _Z8GL2SCEGUjPi);

extern "C" {
void static_init(int, int) __asm__("_Z41__static_initialization_and_destruction_0ii_1F6B0");
void _GLOBAL__I__ZN12HouseKeeping11AttribStack5tableE(void);
void _GLOBAL__D__ZN12HouseKeeping11AttribStack5tableE(void);
}

void _GLOBAL__I__ZN12HouseKeeping11AttribStack5tableE(void)
{
    static_init(1, 0xFFFF);
}

void _GLOBAL__D__ZN12HouseKeeping11AttribStack5tableE(void)
{
    static_init(0, 0xFFFF);
}

/* deque<unsigned> instances of this object that only its asm functions use: called from here (a discarded
   function) so that cc1plus emits them (their order is DEMO_LINKONCE_ORDER's) */
extern "C" void HouseKeeping_instance_refs(std::deque<unsigned int> &d, std::deque<unsigned int> &e)
    __attribute__((section(".discard.asm")));
extern "C" void HouseKeeping_instance_refs(std::deque<unsigned int> &d, std::deque<unsigned int> &e)
{
    std::deque<unsigned int> t(e);
    d.push_back(0);
    d.pop_back();
    d.pop_front();
    d = e;
    /* deque<unsigned>::pop_back's out-of-line copy (static pointer in a discarded section: no .rodata) */
    static void (std::deque<unsigned int>::*pop_back)() __attribute__((section(".discard.data"))) = &std::deque<unsigned int>::pop_back;
    __asm__ volatile("" : : "m"(pop_back));
}

/* out-of-line inline members / instances that stay asm */
#undef INCLUDE_ASM
#define INCLUDE_ASM INCLUDE_ASM_LINKONCE

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", _ZN12HouseKeeping11AttribStackC1Ev);

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/HouseKeeping_AttribStack", _ZN12HouseKeeping11AttribStack3getERNS_10EnableMaskEj);
