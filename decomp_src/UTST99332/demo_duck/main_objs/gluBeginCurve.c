/* lang: c++ */
/* cflags: -O3 -fno-exceptions */
#undef __EXCEPTIONS
#include "cxx/defer_asm.h"
#include "../main.hpp"

extern "C" void gluBeginCurve(void) {
}

extern "C" void gluBeginPolygon(void) {
}

extern "C" void gluBeginSurface(void) {
}

extern "C" void gluBeginTrim(void) {
}

extern "C" int gluBuild1DMipmaps(void)
{
    return 0;
}

extern "C" int gluBuild2DMipmaps(void)
{
    return 0;
}

extern "C" void gluCylinder(void) {
}

extern "C" void gluDeleteNurbsRenderer(void) {
}

extern "C" void gluDeleteQuadric(void) {
}

extern "C" void gluDeleteTess(void) {
}

extern "C" void gluDisk(void) {
}

extern "C" void gluEndCurve(void) {
}

extern "C" void gluEndPolygon(void) {
}

extern "C" void gluEndSurface(void) {
}

extern "C" void gluEndTrim(void) {
}

extern "C" int gluErrorString(void)
{
    return 0;
}

extern "C" int gluErrorUnicodeStringEXT(void)
{
    return 0;
}

extern "C" void gluGetNurbsProperty(void) {
}

extern "C" int gluGetString(void)
{
    return 0;
}

extern "C" void gluGetTessProperty(void) {
}

extern "C" void gluLoadSamplingMatrices(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gluBeginCurve", gluLookAt);

extern "C" int gluNewNurbsRenderer(void)
{
    return 0;
}

extern "C" int gluNewQuadric(void)
{
    return 0;
}

extern "C" int gluNewTess(void)
{
    return 0;
}

extern "C" void gluNextContour(void) {
}

extern "C" void gluNurbsCallback(void) {
}

extern "C" void gluNurbsCurve(void) {
}

extern "C" void gluNurbsProperty(void) {
}

extern "C" void gluNurbsSurface(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gluBeginCurve", gluOrtho2D);

extern "C" void gluPartialDisk(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gluBeginCurve", gluPerspective);

extern "C" void gluPickMatrix(void) {
}

extern "C" int gluProject(void)
{
    return 0;
}

extern "C" void gluPwlCurve(void) {
}

extern "C" void gluQuadricCallback(void) {
}

extern "C" void gluQuadricDrawStyle(void) {
}

extern "C" void gluQuadricNormals(void) {
}

extern "C" void gluQuadricOrientation(void) {
}

extern "C" void gluQuadricTexture(void) {
}

extern "C" int gluScaleImage(void)
{
    return 0;
}

extern "C" void gluSphere(void) {
}

extern "C" void gluTessBeginContour(void) {
}

extern "C" void gluTessBeginPolygon(void) {
}

extern "C" void gluTessCallback(void) {
}

extern "C" void gluTessEndContour(void) {
}

extern "C" void gluTessEndPolygon(void) {
}

extern "C" void gluTessNormal(void) {
}

extern "C" void gluTessProperty(void) {
}

extern "C" void gluTessVertex(void) {
}

extern "C" int gluUnProject(void)
{
    return 0;
}

extern "C" int gluUnProject4(void)
{
    return 0;
}

extern "C" void glutInit(void) {
}

extern "C" void glutInitDisplayMode(void) {
}

extern "C" void glutInitDisplayString(void) {
}

extern "C" void glutInitWindowPosition(void) {
}

extern "C" void glutInitWindowSize(void) {
}

extern "C" void glutMainLoop(void) {
}

extern "C" int glutCreateWindow(void)
{
    return 0;
}

extern "C" int glutCreateSubWindow(void)
{
    return 0;
}

extern "C" void glutDestroyWindow(void) {
}

extern "C" void glutPostRedisplay(void) {
}

extern "C" void glutPostWindowRedisplay(void) {
}

extern "C" void glutSwapBuffers(void)
{
    extern void sceGuSwapBuffers_(void) __asm__("sceGuSwapBuffers");
    sceGuSwapBuffers_();
}

extern "C" int glutGetWindow(void)
{
    return 0;
}

extern "C" void glutSetWindow(void) {
}

extern "C" void glutSetWindowTitle(void) {
}

extern "C" void glutSetIconTitle(void) {
}

extern "C" void glutPositionWindow(void) {
}

extern "C" void glutReshapeWindow(void) {
}

extern "C" void glutPopWindow(void) {
}

extern "C" void glutPushWindow(void) {
}

extern "C" void glutIconifyWindow(void) {
}

extern "C" void glutShowWindow(void) {
}

extern "C" void glutHideWindow(void) {
}

extern "C" void glutFullScreen(void) {
}

extern "C" void glutSetCursor(void) {
}

extern "C" void glutWarpPointer(void) {
}

extern "C" void glutEstablishOverlay(void) {
}

extern "C" void glutRemoveOverlay(void) {
}

extern "C" void glutUseLayer(void) {
}

extern "C" void glutPostOverlayRedisplay(void) {
}

extern "C" void glutPostWindowOverlayRedisplay(void) {
}

extern "C" void glutShowOverlay(void) {
}

extern "C" void glutHideOverlay(void) {
}

extern "C" int glutCreateMenu(void)
{
    return 0;
}

extern "C" void glutDestroyMenu(void) {
}

extern "C" int glutGetMenu(void)
{
    return 0;
}

extern "C" void glutSetMenu(void) {
}

extern "C" void glutAddMenuEntry(void) {
}

extern "C" void glutAddSubMenu(void) {
}

extern "C" void glutChangeToMenuEntry(void) {
}

extern "C" void glutChangeToSubMenu(void) {
}

extern "C" void glutRemoveMenuItem(void) {
}

extern "C" void glutAttachMenu(void) {
}

extern "C" void glutDetachMenu(void) {
}

extern "C" void glutDisplayFunc(void) {
}

extern "C" void glutReshapeFunc(void) {
}

extern "C" void glutKeyboardFunc(void) {
}

extern "C" void glutMouseFunc(void) {
}

extern "C" void glutMotionFunc(void) {
}

extern "C" void glutPassiveMotionFunc(void) {
}

extern "C" void glutEntryFunc(void) {
}

extern "C" void glutVisibilityFunc(void) {
}

extern "C" void glutIdleFunc(void) {
}

extern "C" void glutTimerFunc(void) {
}

extern "C" void glutMenuStateFunc(void) {
}

extern "C" void glutSpecialFunc(void) {
}

extern "C" void glutSpaceballMotionFunc(void) {
}

extern "C" void glutSpaceballRotateFunc(void) {
}

extern "C" void glutSpaceballButtonFunc(void) {
}

extern "C" void glutButtonBoxFunc(void) {
}

extern "C" void glutDialsFunc(void) {
}

extern "C" void glutTabletMotionFunc(void) {
}

extern "C" void glutTabletButtonFunc(void) {
}

extern "C" void glutMenuStatusFunc(void) {
}

extern "C" void glutOverlayDisplayFunc(void) {
}

extern "C" void glutWindowStatusFunc(void) {
}

extern "C" void glutKeyboardUpFunc(void) {
}

extern "C" void glutSpecialUpFunc(void) {
}

extern "C" void glutJoystickFunc(void) {
}

extern "C" void glutSetColor(void) {
}

INCLUDE_ASM("tmp/asm/UTST99332/demo_duck/nonmatchings/main_objs/gluBeginCurve", glutGetColor);

extern "C" void glutCopyColormap(void) {
}

extern "C" int glutGet(void)
{
    return 0;
}

extern "C" int glutDeviceGet(void)
{
    return 0;
}

extern "C" int glutExtensionSupported(void)
{
    return 0;
}

extern "C" int glutGetModifiers(void)
{
    return 0;
}

extern "C" int glutLayerGet(void)
{
    return 0;
}

extern "C" void glutBitmapCharacter(void) {
}

extern "C" int glutBitmapWidth(void)
{
    return 0;
}

extern "C" void glutStrokeCharacter(void) {
}

extern "C" int glutStrokeWidth(void)
{
    return 0;
}

extern "C" int glutBitmapLength(void)
{
    return 0;
}

extern "C" int glutStrokeLength(void)
{
    return 0;
}

extern "C" void glutWireSphere(void) {
}

extern "C" void glutSolidSphere(void) {
}

extern "C" void glutWireCone(void) {
}

extern "C" void glutSolidCone(void) {
}

extern "C" void glutWireCube(void) {
}

extern "C" void glutSolidCube(void) {
}

extern "C" void glutWireTorus(void) {
}

extern "C" void glutSolidTorus(void) {
}

extern "C" void glutWireDodecahedron(void) {
}

extern "C" void glutSolidDodecahedron(void) {
}

extern "C" void glutWireTeapot(void) {
}

extern "C" void glutSolidTeapot(void) {
}

extern "C" void glutWireOctahedron(void) {
}

extern "C" void glutSolidOctahedron(void) {
}

extern "C" void glutWireTetrahedron(void) {
}

extern "C" void glutSolidTetrahedron(void) {
}

extern "C" void glutWireIcosahedron(void) {
}

extern "C" void glutSolidIcosahedron(void) {
}

extern "C" int glutVideoResizeGet(void)
{
    return 0;
}

extern "C" void glutSetupVideoResizing(void) {
}

extern "C" void glutStopVideoResizing(void) {
}

extern "C" void glutVideoResize(void) {
}

extern "C" void glutVideoPan(void) {
}

extern "C" void glutReportErrors(void) {
}

extern "C" void glutIgnoreKeyRepeat(void) {
}

extern "C" void glutSetKeyRepeat(void) {
}

extern "C" void glutForceJoystickFunc(void) {
}

extern "C" void glutGameModeString(void) {
}

extern "C" int glutEnterGameMode(void)
{
    return 0;
}

extern "C" void glutLeaveGameMode(void) {
}

extern "C" int glutGameModeGet(void)
{
    return 0;
}

