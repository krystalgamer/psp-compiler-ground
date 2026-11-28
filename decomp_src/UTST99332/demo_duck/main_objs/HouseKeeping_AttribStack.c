/* lang: c++ */
/* cflags: -O3 -fno-exceptions -fmerge-constants */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#define DEMO_TEMPLATE_DEFS
#include "../main.hpp"

/* the module's .ctors/.dtors refer to the static constructor/destructor */
__asm__(".globl _GLOBAL__I__ZN12HouseKeeping11AttribStack5tableE");
__asm__(".globl _GLOBAL__D__ZN12HouseKeeping11AttribStack5tableE");

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
#include <queue>
#include <stack>

typedef void GLvoid;
typedef double GLdouble;

#define GL_ASSERT(c, fn, line, msg) SGL_ASSERT(c, " *** error ", #c, "../lib/gl_psp/gl.cpp", fn, line, msg)

namespace HouseKeeping {
enum EnableMask {
    ALPHA_TEST, DEPTH_TEST, STENCIL_TEST, BLEND, CULL_FACE, DITHER, FOG, TEXTURE, LIGHTING,
    LIGHT0, LIGHT1, LIGHT2, LIGHT3, AALINE, N_ENABLE
};
class AttribStack {
    std::stack<unsigned int> _stack;
public:
    static const unsigned int table[N_ENABLE];
    static const char *names[N_ENABLE];
    AttribStack();
    ~AttribStack()
    {
        pop();
        GL_ASSERT(_stack.empty(), __PRETTY_FUNCTION__, 543, " ");
    }
    bool get(EnableMask &m, unsigned int cap);
    unsigned int bits() { return _stack.top(); }
    void enable(unsigned int cap)
    {
        EnableMask m;
        if (!get(m, cap))
            return;
        GL_ASSERT(! _stack.empty(), __PRETTY_FUNCTION__, 586, " ");
        unsigned int b = 1 << m;
        _stack.top() |= b;
        sceGuEnable(table[m]);
    }
    void disable(unsigned int cap)
    {
        EnableMask m;
        if (!get(m, cap))
            return;
        GL_ASSERT(! _stack.empty(), __PRETTY_FUNCTION__, 608, " ");
        unsigned int b = 1 << m;
        _stack.top() &= ~b;
        sceGuDisable(table[m]);
    }
    void push()
    {
        _stack.push(_stack.empty() ? 0 : _stack.top());
    }
    void pop()
    {
        GL_ASSERT(_stack.size() > 1, __PRETTY_FUNCTION__, 629, " ");
        _stack.pop();
    }
};
}

/* inline members defined in gl.h that the object calls (weak copies in its tail) */
SGL_LINKONCE_BEGIN
inline HouseKeeping::AttribStack::AttribStack()
{
    GL_ASSERT(sizeof(table) / sizeof(table[0]) == sizeof(names) / sizeof(names[0]), __PRETTY_FUNCTION__, 0, " ");
    push();
}
SGL_LINKONCE_END

/* the GL emulation's state */
struct GLArrays {
    unsigned int format;        /* 0x54 */
    const void *pointer;        /* 0x58 */
    int stride;                 /* 0x5C */
    GLArrays() : pointer(0), stride(0) {}
};
struct GLState {
    std::queue<unsigned int> free_textures;     /* 0x00 */
    unsigned int last_texture;  /* 0x28 */
    unsigned int texture;       /* 0x2C */
    int _30;
    int wrap_s;                 /* 0x34 */
    int wrap_t;                 /* 0x38 */
    int min_filter;             /* 0x3C */
    int mag_filter;             /* 0x40 */
    int viewport_x;             /* 0x44 (+2048) */
    int viewport_y;             /* 0x48 (+2048) */
    int viewport_w;             /* 0x4C */
    int viewport_h;             /* 0x50 */
    GLArrays array;             /* 0x54 */
    HouseKeeping::AttribStack attribs;  /* 0x60 */
    GLState() : last_texture(0), texture(0), wrap_s(0), wrap_t(0), min_filter(1), mag_filter(1) {}
};
static GLState hk;

const unsigned int HouseKeeping::AttribStack::table[HouseKeeping::N_ENABLE] = {
    0, 1, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15
};
/* AttribStack::names stays in the module's asm .data: a same-shaped stand-in in a section the link
   discards keeps its strings in this object's .rodata (right after table) */
const char *HouseKeeping_AttribStack_names[HouseKeeping::N_ENABLE] __attribute__((section(".discard"))) = {
    "SCEGU_ALPHA_TEST", "SCEGU_DEPTH_TEST", "SCEGU_STENCIL_TEST", "SCEGU_BLEND", "SCEGU_CULL_FACE",
    "SCEGU_DITHER", "SCEGU_FOG", "SCEGU_TEXTURE", "SCEGU_LIGHTING", "SCEGU_LIGHT0", "SCEGU_LIGHT1",
    "SCEGU_LIGHT2", "SCEGU_LIGHT3", "SCEGU_AALINE"
};
/* the asm .data (AttribStack::names) points at these strings */
__asm__(".globl D_00163368\nD_00163368 = _ZN12HouseKeeping11AttribStack5tableE + 0x38");
__asm__(".globl D_0016337C\nD_0016337C = _ZN12HouseKeeping11AttribStack5tableE + 0x4C");
__asm__(".globl D_00163390\nD_00163390 = _ZN12HouseKeeping11AttribStack5tableE + 0x60");
__asm__(".globl D_001633A4\nD_001633A4 = _ZN12HouseKeeping11AttribStack5tableE + 0x74");
__asm__(".globl D_001633B0\nD_001633B0 = _ZN12HouseKeeping11AttribStack5tableE + 0x80");
__asm__(".globl D_001633C0\nD_001633C0 = _ZN12HouseKeeping11AttribStack5tableE + 0x90");
__asm__(".globl D_001633D0\nD_001633D0 = _ZN12HouseKeeping11AttribStack5tableE + 0xA0");
__asm__(".globl D_001633DC\nD_001633DC = _ZN12HouseKeeping11AttribStack5tableE + 0xAC");
__asm__(".globl D_001633EC\nD_001633EC = _ZN12HouseKeeping11AttribStack5tableE + 0xBC");
__asm__(".globl D_001633FC\nD_001633FC = _ZN12HouseKeeping11AttribStack5tableE + 0xCC");
__asm__(".globl D_0016340C\nD_0016340C = _ZN12HouseKeeping11AttribStack5tableE + 0xDC");
__asm__(".globl D_0016341C\nD_0016341C = _ZN12HouseKeeping11AttribStack5tableE + 0xEC");
__asm__(".globl D_0016342C\nD_0016342C = _ZN12HouseKeeping11AttribStack5tableE + 0xFC");
__asm__(".globl D_0016343C\nD_0016343C = _ZN12HouseKeeping11AttribStack5tableE + 0x10C");
int GL2SCEGU(unsigned int, int *);
void PspLogEnableBits(const char *);
extern "C" {
void sceGuFrontFace(int);
void sceGumMatrixMode(int);
void sceGumMultMatrix(const ScePspFMatrix4 *);
void sceGumTranslate(const ScePspFVector3 *);
void sceGumStoreMatrix(ScePspFMatrix4 *);
void sceGumOrtho(float, float, float, float, float, float);
void glRotatef(float, float, float, float);
}
#define GL_FAIL(fn, line, msg) SGL_ASSERT(false, " *** error ", "", "../lib/gl_psp/gl.cpp", fn, line, msg)


void PspLogEnableBits(const char *s)
{
    common::Log() << s;
    common::Log() << "enablebits: \n";
    for (int i = 0; i != HouseKeeping::N_ENABLE; i++) {
        bool on = hk.attribs.bits() & (1 << i);
        common::Log() << HouseKeeping::AttribStack::names[i] << "\t" << (on ? "on" : "off") << "\n";
    }
}

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

extern "C" void glAlphaFunc(unsigned int func, float ref)
{
    int r = (int)(ref * 255.0f);
    int f = 1;
    switch (func) {
    case 0x200: f = 0; break;
    case 0x201: f = 4; break;
    case 0x202: f = 2; break;
    case 0x203: f = 5; break;
    case 0x204: f = 6; break;
    case 0x205: f = 3; break;
    case 0x206: f = 7; break;
    case 0x207: f = 1; break;
    }
    sceGuAlphaFunc(f, r, 0xFF);
}

extern "C" void glBlendFunc(unsigned int sfactor, unsigned int dfactor)
{
    int src = 0, dst = 0;
    unsigned int fixa = 0, fixb = 0;
    switch (sfactor) {
    case 0: src = 10; fixa = 0; break;
    case 1: src = 10; fixa = 0xFFFFFFFF; break;
    case 0x306: src = 0; break;
    case 0x307: src = 1; break;
    case 0x302: src = 2; break;
    case 0x303: src = 3; break;
    case 0x304: case 0x305: case 0x308: return;
    }
    switch (dfactor) {
    case 0: dst = 10; fixb = 0; break;
    case 1: dst = 10; fixb = 0xFFFFFFFF; break;
    case 0x301: dst = 1; break;
    case 0x302: dst = 2; break;
    case 0x303: dst = 3; break;
    case 0x304: case 0x305: return;
    }
    sceGuBlendFunc(0, src, dst, fixa, fixb);
}

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

extern "C" void glEnable(unsigned int cap)
{
    hk.attribs.enable(cap);
}

extern "C" void glDisable(unsigned int cap)
{
    hk.attribs.disable(cap);
}

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
    GL_FAIL(__PRETTY_FUNCTION__, 0x46D, "function disabled");
}

extern "C" void glDepthFunc(unsigned int func)
{
    int f = 1;
    switch (func) {
    case 0x200: f = 0; break;
    case 0x201: f = 4; break;
    case 0x202: f = 2; break;
    case 0x203: f = 5; break;
    case 0x204: f = 6; break;
    case 0x205: f = 3; break;
    case 0x206: f = 7; break;
    case 0x207: f = 1; break;
    }
    sceGuDepthFunc(f);
}

extern "C" void glDepthMask(unsigned char flag)
{
    sceGuDepthMask(flag);
}

extern "C" void glDepthRange(double, double)
{
    GL_FAIL(__PRETTY_FUNCTION__, 0x497, "mapping not implemented");
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

extern "C" void glLoadMatrixd(const GLdouble *)
{
    GL_FAIL(__PRETTY_FUNCTION__, 0x4F1, "glLoadMatrixd unsupported");
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

extern "C" void glRotatef(float angle, float x, float y, float z)
{
    float a = angle * 0.01745329238f;
    float s = sinf(a);
    float c = cosf(a);
    float t = 1.0f - c;
    float tx = t * x, ty = t * y, tz = t * z;
    float sx = s * x, sy = s * y, sz = s * z;
    ScePspFMatrix4 m;
    m.x.x = tx * x + c;
    m.x.y = ty * x + sz;
    m.x.z = tz * x - sy;
    m.y.x = tx * y - sz;
    m.y.y = ty * y + c;
    m.y.z = tz * y + sx;
    m.z.x = tx * z + sy;
    m.z.y = ty * z - sx;
    m.z.z = tz * z + c;
    m.x.w = 0;
    m.y.w = 0;
    m.z.w = 0;
    m.w.x = 0;
    m.w.y = 0;
    m.w.z = 0;
    m.w.w = 1.0f;
    sceGumMultMatrix(&m);
}

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

static inline unsigned int gen_texture()
{
    if (!hk.free_textures.empty()) {
        unsigned int t = hk.free_textures.front();
        hk.free_textures.pop();
        return t;
    }
    return ++hk.last_texture;
}

extern "C" void glGenTextures(int n, unsigned int *textures)
{
    if (textures == 0)
        return;
    for (int i = 0; i != n; i++)
        textures[i] = gen_texture();
}

extern "C" void glDeleteTextures(int n, const unsigned int *textures)
{
    if (textures == 0)
        return;
    for (int i = 0; i != n; i++) {
        std::queue<unsigned int> &q = hk.free_textures;
        unsigned int t = textures[i];
        q.push(t);
    }
}

extern "C" void glBindTexture(unsigned int, unsigned int texture)
{
    hk.texture = texture;
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

extern "C" void glDrawElements(unsigned int mode, int count, unsigned int, const GLvoid *)
{
    int guprim = -1;
    GL2SCEGU(mode, &guprim);
    GL_ASSERT(guprim != -1, __PRETTY_FUNCTION__, 0xA6F, " ");
    sceGumDrawArray(guprim, 0x1FF, count, 0, hk.array.pointer);
}

extern "C" void glInterleavedArrays(unsigned int format, int stride, const void *pointer)
{
    hk.array.format = format;
    hk.array.pointer = pointer;
    hk.array.stride = stride;
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



/* (weak copy in the tail) */
SGL_LINKONCE_BEGIN
inline bool HouseKeeping::AttribStack::get(EnableMask &m, unsigned int cap)
{
    switch (cap) {
    case 0x0BC0: m = ALPHA_TEST; break;
    case 0x0B71: m = DEPTH_TEST; break;
    case 0x0B90: m = STENCIL_TEST; break;
    case 0x0BE2: m = BLEND; break;
    case 0x0B44: m = CULL_FACE; break;
    case 0x0BD0: m = DITHER; break;
    case 0x0B60: m = FOG; break;
    case 0x0DE1: m = TEXTURE; break;
    case 0x0B50: m = LIGHTING; break;
    case 0x4000: m = LIGHT0; break;
    case 0x4001: m = LIGHT1; break;
    case 0x4002: m = LIGHT2; break;
    case 0x4003: m = LIGHT3; break;
    case 0x0B20: m = AALINE; break;
    default: return false;
    }
    return true;
}
SGL_LINKONCE_END
